#!/usr/bin/env python3
"""Arguments passed straight through to an indirect tail call (BOOT_LOG 172).

Where the ARM ends a function with `bx rX` and has not touched r1..r3 since entry, those registers
still hold the function's own arguments and the callee receives them. Ghidra ("Treating indirect
jump as call") often printed only the arguments it saw being set, so the callee read stray words
(0040878C <- 004A71C4 crashed entering several rooms). For every such linked source this writes
native/compilefix/func_X.c (or edits the override) with the function's remaining parameters
appended to the call. An extra argument the callee does not take is harmless in this ABI.

  tools/tail_args_fix.py <EU disassembly (llvm-objdump of eu_code.bin)> [--dry-run]
The disassembly addresses are file offsets (+0x100000), as in BOOT_LOG's notes.
"""
import bisect, glob, json, os, re, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
WARN = 'Treating indirect jump as call'
NATIVE = ('compilefix', 'game', 'gameplay', 'robust', 'framework', 'core', 'hot', 'sdk', 'route')


def main():
    os.chdir(ROOT)
    dry = '--dry-run' in sys.argv
    m = json.load(open('decomp/eu_usa_map.json'))
    eu = {k: int(v['eu'], 16) for k, v in m.items() if isinstance(v, dict) and 'eu' in v}
    starts = sorted(eu.values())
    ins = {}
    for line in open(sys.argv[1]):
        g = re.match(r'\s*([0-9a-f]+):\s+[0-9a-f]{8}\s+(.*)', line)
        if g:
            ins[int(g.group(1), 16) + 0x100000] = g.group(2).split('@')[0].strip()
    linked = {}
    for o in json.load(open('build/decomp/report.json'))['objects']:
        p = os.path.join('build/decomp', o.split('/obj/')[1].replace('.final.o', ''))
        g = re.match(r'func_([0-9A-F]{8})\.c$', os.path.basename(p))
        if g and os.path.exists(p):
            linked[g.group(1)] = p
    for d in NATIVE:
        for p in glob.glob('native/%s/func_*.c' % d):
            g = re.match(r'func_([0-9A-F]{8})\.c$', os.path.basename(p))
            if g:
                linked[g.group(1)] = p
    done = 0
    for u, path in sorted(linked.items()):
        text = open(path, errors='replace').read()
        if WARN not in text or u not in eu:
            continue
        sig = re.search(r'^[\w \*]*\bfunc_%s(?:__\w+)?\s*\(([^)]*)\)\s*\{' % u, text, re.M)
        if not sig:
            continue
        params = [a.strip() for a in sig.group(1).split(',') if a.strip() and a.strip() != 'void']
        # float parameters travel in VFP registers; 64-bit ones take register pairs
        if any(re.match(r'(undefined8|longlong|ulonglong|double)\b(?![^,]*\*)', a) for a in params):
            continue
        ints = [re.findall(r'\w+', a)[-1] for a in params if not re.match(r'float\b(?![^,]*\*)', a)]
        if len(ints) < 2:
            continue
        # registers still holding the entry arguments at the first indirect tail branch
        e = eu[u]
        k = bisect.bisect_right(starts, e)
        end = starts[k] if k < len(starts) else e + 0x2000
        touched, live = set(), None
        for a in range(e, min(end, e + 0x4000), 4):
            t = ins.get(a)
            if t is None:
                continue
            g = re.match(r'bx(?:eq|ne|gt|lt|ge|le|hi|ls)?\s+(r\d+|r12|ip)$', t)
            if g:
                tr = g.group(1)
                these = {i for i in (1, 2, 3) if i not in touched and tr != 'r%d' % i}
                live = these if live is None else live & these
                continue
            if re.match(r'blx?(eq|ne|gt|lt|ge|le|hi|ls)?\s', t):
                touched |= {1, 2, 3}
                continue
            if t.startswith(('str', 'cmp', 'cmn', 'tst', 'teq', 'vstr', 'stm', 'push', 'vcmp')):
                continue
            g = re.match(r'\S+\s+(r[0-3])\b!?(?:,\s*(r[0-3])\b)?', t)
            if g:
                touched.add(int(g.group(1)[1]))
                if t.startswith(('ldrd', 'umull', 'smull')) and g.group(2):
                    touched.add(int(g.group(2)[1]))
            g = re.match(r'(?:ldm|pop)\S*\s+(?:\S+,\s*)?\{([^}]*)\}', t)
            if g:
                touched |= {int(r) for r in re.findall(r'r(\d+)', g.group(1))}
        if not live:
            continue
        lines = text.split('\n')
        changed = []
        for i, line in enumerate(lines):
            if WARN not in line:
                continue
            j = i + 1
            while j < len(lines) and (not lines[j].strip() or lines[j].strip().startswith('/*')):
                j += 1
            if j >= len(lines):
                continue
            st = lines[j]
            c = re.sub(r'\s*/\*.*?\*/\s*$', '', st)
            tail = st[len(c):]
            if not c.rstrip().endswith(');'):
                continue
            body = c.rstrip()[:-1]
            depth, openp, commas = 0, None, 0
            for x in range(len(body) - 1, -1, -1):
                ch = body[x]
                if ch == ')':
                    depth += 1
                elif ch == '(':
                    depth -= 1
                    if depth == 0:
                        openp = x
                        break
                elif ch == ',' and depth == 1:
                    commas += 1
            if openp is None:
                continue
            inner = body[openp + 1:-1].strip()
            have = 0 if not inner or inner == 'void' else commas + 1
            add = []
            pos = have
            while pos < 4 and pos in live and pos < len(ints) and not re.search(r'\b%s\b' % ints[pos], inner):
                add.append(ints[pos])
                pos += 1
            if not add or have == 0:
                continue
            new = body[:-1] + ''.join(',' + a for a in add) + ');' + tail
            new = new.replace('(int (*)(int *))', '(int (*)())')
            lines[j] = new
            changed.append((add, new.strip()))
        if not changed:
            continue
        done += 1
        print(u, path.split('/')[1], changed[0][0], '|', changed[0][1][:120])
        if not dry:
            out = '\n'.join(lines)
            note = ('/* compilefix: USA %s with the arguments its indirect tail call passes through restored\n'
                    ' * (tools/tail_args_fix.py, BOOT_LOG 172). */\n') % u
            dst = path if path.startswith('native/') else 'native/compilefix/func_%s.c' % u
            open(dst, 'w').write(note + out)
    print('%d sources' % done)


if __name__ == '__main__':
    main()
