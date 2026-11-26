#!/usr/bin/env python3
"""Raw code-address string pointers in the Ghidra text (BOOT_LOG 143).

Ghidra sometimes prints a pointer to a string literal stored among the code as a plain number,
`(char *)0x248bd0` (or `(uint *)0x4f3110`, `(code *)0x2567c0`: BOOT_LOG 172), which the converter leaves as a 3DS address (the Fire Rod crashed reading
"fade" at 0x248bd0). For every linked Ghidra source with `(char *)0xADDR` where ADDR lies in the
code section and holds a printable NUL-terminated string, this writes native/compilefix/func_X.c
with the number replaced by the same string as a C literal. Sources with a native override are
reported, not changed (fix those by hand).

  tools/raw_cstr_fix.py [--dry-run] [--code ../albw-decomp-ai/rom/eu_code.bin]
"""
import glob
import json
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
TEXT = 0x00100000
RAW = re.compile(r'\((?:char|uint|code|undefined4?) \*\)0x([0-9a-f]{5,6})\b')


def cstring(code, addr):
    o = addr - TEXT
    if not 0 <= o < len(code):
        return None
    e = code.find(b'\0', o)
    if e < 0 or e - o < 1 or e - o > 200:
        return None
    s = code[o:e]
    if not all(0x20 <= b < 0x7F for b in s):
        return None
    return s.decode('ascii')


def main():
    dry = '--dry-run' in sys.argv
    cb = os.path.join(ROOT, '../albw-decomp-ai/rom/eu_code.bin')
    if '--code' in sys.argv:
        cb = sys.argv[sys.argv.index('--code') + 1]
    code = open(cb, 'rb').read()
    os.chdir(ROOT)
    r = json.load(open('build/decomp/report.json'))
    native = {os.path.basename(f) for d in ('compilefix', 'robust', 'gameplay', 'game', 'hot', 'route',
                                             'core', 'framework') for f in glob.glob('native/%s/func_*.c' % d)}
    for o in r['objects']:
        p = os.path.join('build/decomp', o.split('/obj/')[1].replace('.final.o', ''))
        if not p.endswith('.c') or 'ghidra_fallback' not in p or not os.path.exists(p):
            continue
        s = open(p, errors='replace').read()
        hits = [(m.group(0), int(m.group(1), 16)) for m in RAW.finditer(s)]
        hits = [(t, a, cstring(code, a)) for t, a in hits]
        hits = [h for h in hits if h[2] is not None]
        if not hits:
            continue
        base = os.path.basename(p)
        desc = ', '.join('%#x "%s"' % (a, v) for _, a, v in hits)
        if base in native:
            print('override exists, fix by hand: %s: %s' % (base, desc))
            continue
        for t, a, v in hits:
            s = s.replace(t, t[:t.index(')') + 1] + '"%s"' % v.replace('\\', '\\\\').replace('"', '\\"'))
        hdr = ('/* compilefix: %s, the converted stage-2 text (%s) with raw code-address string pointers\n'
               ' * replaced by the strings themselves (tools/raw_cstr_fix.py, BOOT_LOG 143): %s */\n') % (base[:-2], p, desc)
        print('%s: %s' % (base, desc))
        if not dry:
            open(os.path.join('native/compilefix', base), 'w').write(hdr + s)


if __name__ == '__main__':
    main()
