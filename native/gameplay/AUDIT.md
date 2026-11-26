# Gameplay core audit: math, collision, physics/movement, actor update

Scope: the game logic that runs as decompiled C in the native port (no SDK replacement):
the math library, the collision system, the physics/movement core with the player, and the
per-frame actor update. Addresses are USA (EU in the tables where they differ). Rewrites live in
`native/gameplay/func_<USA>.c` (one strong `func_<USA>` per file, `#include "gameplay.h"`).

**Summary:** 97 rewrites (math 29, player/physics/actor 49 incl. wall merge 3, action change 1,
angle chase 1, enemy knock-back 13; collision 19 incl. KCL box walkers, main sweeps, grid cell), 9 test
programs run by `test/run_tests.sh` (all pass -m32 and -m64), float-mode patch `fpmath.patch`
(the build now uses its flags). Section 6 is the round-2 re-audit (what changed, signature check
of every rewrite, link blockers).

**Status: not linked yet** (link blockers: section 6.4). `tools/link.sh` builds `native/game`, `native/sdk`, `native/runtime`,
`native/robust` only. To use these files, add `native/gameplay/*.c` to its `NATIVE` list with
the same `EXTRA` flags as `native/robust` (and drop any duplicate definition: none of the
addresses here is defined in `native/game`, `native/robust` or `native/sdk` today; re-check with
`tools/audit.py`'s `native` column before linking). Every file compiles clean for `-m32` and
`-m64` with `-std=gnu11 -Wall -Wextra -Wno-unused-parameter -Inative/include
-I../albw-decomp-ai/shared/include`.

## Tools (native/gameplay/tools)

| tool | what it does |
|---|---|
| `retreads.py` (capstone) | for every `bl F` call site, which of r0/r1/s0/s1 the caller READS before writing after the call (VFP operands parsed by hand: capstone marks the destination of `vldr`/`vldm` as read). Ghidra-independent evidence of a function's real return registers. -> `retreads.json` (8,870 callees) |
| `audit.py ADDR...` | per-function defect audit: Ghidra signature vs ARM live-in (`native/robust/tools/livein2.json`): missing register args; lost return (callers read r0/s0, Ghidra says void / non-float; notes when the converter already restored r0); `in_`/`unaff_`/`extraout_` reads; `&stack0x`; `UNRECOVERED_JUMPTABLE` (no-arg); float bit-casts (raw Ghidra / still present in the compiled conversion); float->int conversions; `SQRT`; double; static callers; existing native override |
| `callgraph.json` | ARM direct-call graph (USA -> callees), for `audit.py` |
| `sigcheck.py [--all]` | ABI check of every `func_*.c` here against the prototypes the round-2 converted callers declare (`build/decomp/ghidra_fallback/ghidra_analyzed4`): RET (float vs int return: i386 x87 hazard), ARGS (float/int argument sequence differs), M64PTR (pointer parameter where callers pass a 32-bit int: upper half of the register undefined on x86-64), VOIDRET |
| `livein_dregs.py` | float-argument live-in that livein2 misses: `vpush {d0}` / `vmov.f64 d8, d0` saves (capstone reports vpush lists as written, so s0/s1 looked defined). -> `livein_dregs.json`: 20 functions with the pattern, 17 with a really-read s-register missing from the round-2 signature (004A9F98 21 callers, 004A7620 18, 002B0D7C 13, 004AAD4C, 00536CA4, 0066FA50, 004AAF44, ...) |

## Global audit numbers (all 23,529 Ghidra-sourced functions without a native override)

| defect class | functions | sites | note |
|---|---|---|---|
| register read with no source (`in_rN/in_sN/unaff_/extraout_`) | 2,819 | | many benign (see robust/PRIORITY.md filtering) |
| argument registers live-in on ARM but missing from the signature | 796 | | lost implicit args (callers pass too few) |
| r0 return lost (callers read r0, Ghidra `void`) | 131 | | + 82 more already restored by build_decomp `void_tail_returns`/`returns_this` |
| **float return lost** (callers read s0, Ghidra void/int) | **22** | | silent: no `in_s0` marker when the caller reloads a stale variable (e.g. 0013EA58) |
| lost stack objects (`&stack0x`) | 344 | | |
| indirect tail call (`UNRECOVERED_JUMPTABLE`) | 63 | | 51 called with NO arguments |
| unprototyped callee declarations (`extern int f();`) of float-taking functions | 42 callees | 206 caller files | C default promotion passes every float as an 8-byte double: all later arguments shift (e.g. 004FD464 x80 files, 0025B860 x31, 005211F4 x30) |
| float<->int bit-casts printed as value casts | 2,070 (raw) / **525 residual** | 15,104 / **1,148 residual** | residual = still in the compiled round-1 conversion (`ghidra_fallback/ghidra_analyzed3`), e.g. `(float)*(undefined8 *)` vldm pairs in Matrix34 multiply |
| float->int conversions as C casts | 1,402 | 5,682 | x86 `cvttss2si` gives 0x80000000 on NaN/overflow; ARM `vcvt` saturates, NaN -> 0 |

Round 2 (`ghidra_analyzed4` + `systemic2` signature table), same audit over 23,492 functions without
a native override: `in_rN` reads in converted files 1,322 -> 421 files (`in_sN` 328 -> 434), missing
argument registers 796 -> 417, lost r0 return 131 -> 40, lost s0 return 22 -> 4 (all 4 are leaves
that do not touch s0: benign), raw bit-casts 2,091 / converted residual **518 functions / 1,084
sites** (was 525 / 1,148: the `(float)*(undefined8 *)` vldm-pair pattern is still there, e.g.
00115960), float->int sites 1,427 (most now `VectorFloatTo*`, which saturate correctly; the
remaining plain C casts are the hazard), unprototyped `()` declarations 42 callees / 206 files ->
**8 callees / 41 sites**, mixed float/int return declarations of one callee across files -> **0**.
| `SQRT()` (= double `__builtin_sqrt`) | 381 | | exact when stored straight to float (sqrt double-rounding is innocuous), a hazard only inside wider expressions |
| double arithmetic | 6 | | |

### i386 ABI hazard: float return class mismatches (x87 stack)

On i386 a `float` is returned in x87 `st(0)`. A caller that declares the callee `int` never pops
it (8 such calls fill the x87 stack; every later x87 load, i.e. every float return, becomes the
NaN "indefinite"); a caller that declares it `float` while the definition returns in `eax` pops an
empty register (NaN). The 64-bit build returns floats in `xmm0` and is immune. In the active
conversion (`build/decomp/ghidra_fallback/ghidra_analyzed3`) the converter declares every callee
from one Ghidra signature, so the converted sources agree among themselves except:
- 0053EDC8 and 00556CE4: defined `float`, 9 + 2 caller files declare `int` (leak per call);
- native definitions that disagree with the callers' class: `native/robust/func_0065E398.c`
  (`void`; 18 caller files declare it `float`: they read a popped-empty NaN), `native/sdk/memory.c`
  0010E74C memmove (`void *`; 13 caller files declare it `float`, they pop an empty st(0)).
Round 2: no callee has mixed declarations any more; 0053EDC8 and 00556CE4 are now `float`
everywhere; still disagreeing native definitions (not in this folder): `native/sdk/snd.c` 003E1634
(callers float), `native/robust` 0065D120 (12 caller files float), 006640EC (36), 0065F560 (5),
0066E07C (1): each pops an empty x87 st(0) per call on i386.
Rule used for every file here: a `func_<ADDR>` keeps the return class the converted callers
declare (round 2 changed seven of them to float: section 6.1); where the ARM function really returns a float Ghidra lost, the exact version is an
`albw_*` function (`gp_math.h`) and the signature table has to be fixed before func_ changes.

## 1. Math library

Evidence: `native/sdk_areas.json` (area "math", named from the code: table lookups, VFP
patterns, call counts) + the ARM call graph (`tools/callgraph.json`) + `retreads.json` for the
real return registers. There is no reciprocal-sqrt anywhere: the ARM11 VFPv2 has only `vsqrt`
(used inline in ~380 functions and in the normalize/quaternion leaves). Angles are 32-bit
indices (0x40000000 = 90 deg) everywhere in gameplay; sin/cos come from 256-entry interpolated
tables, atan from a 129-entry table. Vectors are sead::Vector3f (3 floats), matrices row-major
3x4 (Matrix34, translation in column 3) and 3x3.

| USA | EU | role | static callers | call sites | sqrt | confidence |
|---|---|---|---|---|---|---|
| 00115C54 | 00115C54 | Vec3 add | 735 | 1414 |  | high |
| 00115C70 | 00115C70 | Vec3 sub | 851 | 1778 |  | high |
| 00115C8C | 00115C8C | Vec3 mul (component) | 9 | 9 |  | high |
| 00115D70 | 00115D70 | Vec3 scale | 362 | 1092 |  | high |
| 00115D88 | 00115D88 | Vec3 / scalar (reciprocal-multiply) | 32 | 88 |  | high |
| 00115DAC | 00115DAC | Vec3 b + a*s | 54 | 78 |  | high |
| 00115DC8 | 00115DC8 | Vec3 normalize, returns length (s0) | 241 | 345 | vsqrt | high |
| 00115C14 | 00115C14 | Vec2 normalize, returns length (s0) | 3 | 4 | vsqrt | high |
| 00115E10 | 00115E10 | Vec3 cross | 46 | 106 |  | high |
| 00115B68 | 00115B68 | quaternion: shortest arc a->b | 6 | 6 | vsqrt | high |
| 0068C690 | 0068C668 | Vec3 yaw = atan2(x, z) (angle idx) | 333 | 435 |  | high |
| 004D80A4 | 004D807C | polar -> XZ (sin*r, cos*r) | 235 | 319 |  | high |
| 00115CA8 | 00115CA8 | Matrix34 * Vec3 (point) | 30 | 48 |  | high |
| 00115074 | 00115074 | Matrix34 * Vec3 (copy of 00115CA8) | 18 | 30 |  | high |
| 00115D18 | 00115D18 | Matrix34 rotate Vec3 | 13 | 19 |  | high |
| 00115CE4 | 00115CE4 | Matrix33 * Vec3 | 44 | 77 |  | high |
| 001157FC | 001157FC | Matrix34 * Matrix34 | 67 | 89 |  | high |
| 00114E74 | 00114E74 | Matrix34 * Matrix34 (copy) | 16 | 37 |  | high |
| 0011549C | 0011549C | Matrix33 * Matrix33 | 23 | 25 |  | high |
| 0011593C | 0011593C | Matrix34 identity | 12 | 12 |  | high |
| 001119F4 | 001119F4 | Matrix34 copy (self-check) | 97 | 134 |  | high |
| 001151EC | 001151EC | Matrix34 copy | 130 | 176 |  | high |
| 00491E80 | 00491E58 | Matrix34 from Euler XYZ (idx) | 78 | 100 |  | high |
| 00491624 | 004915FC | Matrix33 from Euler XYZ (idx) | 62 | 68 |  | high |
| 00491B3C | 00491B14 | Matrix34 from quaternion | 17 | 22 |  | high |
| 00491404 | 004913DC | Matrix33 from quaternion | 15 | 15 |  | high |
| 00115154 | 00115154 | sinCos(angle idx), table 006C3AB8 (256 x {s,ds,c,dc}) | 104 | 148 |  | high |
| 003E183C | 003E181C | sinCos(float idx), table 006A6D54 | 8 | 17 |  | high |
| 004904CC | 004904A4 | atan2(y,x) -> angle idx | 183 | 223 |  | high |
| 004905E0 | 004905B8 | atan(t) table 006C53D8 (129 x {base,slope}) | 77 | 588 |  | high |
| 00490628 | 00490600 | exp(x) approx, table 006C4AC8 | 3 | 3 |  | high |
| 00111A64 | 00111A64 | Random::getU32 (xorshift128) | 530 | 902 |  | high |
| 0049BB30 | 0049BB08 | Random::init(seed) | 4 | 4 |  | high |
| 0068C794 | 0068C76C | chase(value, target, rate, min, max) (native/robust) | 80 | 143 |  | high |
| 00688C34 | 00688C0C | chase/approach (native/robust) | 12 | 18 |  | high |

### Audit (math)

| USA | defects (ARM vs Ghidra C / compiled conversion) | rank reason |
|---|---|---|
| 00115DC8 Vec3 normalize | **returns the length in s0, Ghidra void**: 24 call sites use it (`vcmp s0` / `vmov rX, s0` after the call), e.g. 0013EA58 silently tests a stale variable instead (`if (fVar6 == fVar9)` where the ARM tests length == 0); NaN length: ARM keeps the vector (`bxle` taken when unordered), C writes NaN | 241 callers |
| 001157FC / 00114E74 Matrix34 multiply | rows of b read as 8-byte integers and **value-converted** `(float)*(undefined8 *)` (vldmia pairs): 2 sites per function still in the round-1 conversion -> garbage matrices natively | 67 + 16 callers, every model/bone/camera transform |
| 004905E0 atan table | `(int)(t*128)` C cast (x86: 0x80000000 on NaN/overflow -> table index -2^31: wild read; ARM vcvt saturates, NaN -> 0); unsigned conversion of a possibly negative product (UB in C) | under every atan2 (77 callers) |
| 004904CC atan2, 0068C690 yaw | C comparisons where the ARM uses `blt`/`bhi` (taken on NaN): a NaN direction takes another branch and then feeds NaN into 004905E0 (above) | 183 + 333 callers |
| 00115B68 shortest-arc quaternion | identity constant embedded in the CODE (00115BF8) read via pool word 00115C10: gen_data emits it as the raw number 0x00115BF8 -> native read of unmapped memory whenever a ~ -b; NaN branch | 6 callers, crash |
| 00490628 exp approx | float result in s0, Ghidra `uint` (all 3 call sites read s0); C float->int casts; exponent add printed as value conversion | 3 callers |
| 003E183C sin/cos float idx | s0 (= sin) lost; vcvt.u32 via C cast; the bit-compare loop is fixed in the round-1 conversion | 8 callers |
| 00115C14 Vec2 normalize | as 00115DC8 | 3 callers |
| 00115154 sinCos, 00115C54/C70/C8C/D70/D88/DAC/E10, 00115CA8/5074/5CE4/5D18, 0011549C, 00491624/00491E80, 004D80A4 | no defect in the Ghidra C; rewritten as the exact hot-path versions (aliasing-safe loads-before-stores, ARM operation order: e.g. Matrix34*Vec3 adds the translation FIRST, `((t + m0*x) + m1*y) + m2*z`; Vec3 divide = multiply by one reciprocal; vmla/vmls/vnmls unfused) | thousands of calls per frame |
| 0011593C identity, 001119F4 copy | none; copies done with memcpy (vldm/vstm move bits: no float register round trip) | |
| 0049C154 (Vec4 lerp), 0049EF80 (closest point on segment) | old conversion declared them both `float` and `int` in different caller files; consistent in the active conversion | watch |
| 005211F4 (37 callers, pure float leaf) | 30 caller files declare it unprototyped `()`: float args promoted to double | systemic (see above) |

### Rewritten (math): 28 files

All derived from the EU disassembly instruction by instruction (the Ghidra C only as a hint),
single precision, same operation order, ARM condition-code NaN behaviour (`VCMP_*`), `vcvt`
saturation (`gp_vcvt_*`), loads-before-stores where the ARM does so (callers alias out/in).
`func_` prototypes = the converted callers' prototypes (all `int`); real float results through
the `albw_*` functions declared in `gp_math.h`. Confidence high for all.

| file | role | bug fixed / reason |
|---|---|---|
| func_00115DC8.c | Vec3 normalize | lost float return (albw_vec3_normalize), NaN early-return |
| func_00115C14.c | Vec2 normalize | lost float return (albw_vec2_normalize), NaN |
| func_001157FC.c, func_00114E74.c | Matrix34 multiply | 64-bit value conversions of float pairs; aliasing-safe |
| func_0011549C.c | Matrix33 multiply | exact order, aliasing-safe |
| func_00115B68.c | quaternion shortest arc | code-embedded identity constant (native crash), NaN branch |
| func_004905E0.c | atan table | vcvt.s32/u32 semantics (wild table index on NaN natively) |
| func_004904CC.c | atan2 -> angle idx | ARM NaN branch structure |
| func_0068C690.c | Vec3 yaw (atan2 x,z) | same (inlined atan2) |
| func_00490628.c | exp approx | lost float return (albw_exp_approx), vcvt, bit add |
| func_003E183C.c | sin/cos float idx | lost s0, vcvt.u32, ordered `vneglo` |
| func_00115154.c | sinCos angle idx | exact hot path (albw_sincos_idx) |
| func_004D80A4.c | polar -> XZ | exact hot path |
| func_00491E80.c, func_00491624.c | Matrix34/33 from Euler | exact vmla/vnmls/vmls order |
| func_00115C54/C70/C8C/D70/D88/DAC/E10.c | Vec3 add/sub/mul/scale/div/madd/cross | exact hot path, r0 return as on ARM |
| func_00115CA8.c, func_00115074.c, func_00115CE4.c, func_00115D18.c | matrix * vector | translation-first accumulation order |
| func_0011593C.c, func_001119F4.c | identity, copy | bit-exact (integer/memcpy) |

**Tests**: `native/gameplay/test/test_math.c` + `run_math_tests.sh` (builds -m32 and -m64,
52 checks, all pass). Expected values are derived by hand from the ARM semantics with SYNTHETIC
tables (no game data): reciprocal-multiply divide (5 * (1/3) = 0x3FD55556, not 5/3), translation-
first matrix*vector (1e8 + 3 + 3 + 3 stays 1e8), unfused vmla ((1+2^-12)^2 - (1+2^-11) = 0, an
FMA gives 2^-24), NaN branches of normalize/atan2, the code-constant identity quaternion,
in-place matrix multiply, vcvt saturation, FTZ helper. The same tests FAIL (3 checks) when built
with x87 math (`gcc -m32` default, or `clang -m32 -mno-sse`) and FAIL (1 check) with FMA
contraction (`-march=haswell -ffp-contract=fast`): they double as a float-model regression test.

## 2. Float mode (recommendation; patch: native/gameplay/fpmath.patch, not applied)

What the 3DS does: the only FPSCR write in the game code is 00106314 `vmsr fpscr, 0x03000000`,
called by the sead thread trampoline 0010994C for every game thread: **FZ (flush-to-zero) + DN
(default NaN), round-to-nearest, no traps**. The main thread's initial FPSCR comes from the
kernel (not in the game code). ARM11 VFPv2 has no FMA; `vmla`/`vmls` round the product.

What the native build does today: `build_decomp.py` compiles with `--target=i686-linux-gnu -O1`
and link.sh with `-m32 -O2`. Clang's i686 default CPU is pentium4, so scalar float math is
already SSE2 single precision (verified: `mulss/addss`, `FLT_EVAL_METHOD 0`), and clang does not
contract a*b+c into FMA without an FMA-capable `-march`. But nothing pins this: gcc, or any
`-march`/`-mno-sse` change, silently switches to x87 (80-bit excess precision: 3 of the math
tests fail) or FMA contraction (1 fails). MXCSR is left at the IEEE default (no FTZ/DAZ):
`native/sdk/os.c` defines 00106314 as a no-op.

Recommendation (the patch):
1. `tools/link.sh` CFLAGS and `tools/build_decomp.py` clang command: add
   `-msse2 -mfpmath=sse -ffp-contract=off` (both architectures; on x86-64 the first two are
   defaults, `-ffp-contract=off` still matters if a `-march` with FMA is ever used). Never
   `-ffast-math` (it breaks the NaN branch structure the game relies on).
2. FTZ/DAZ at thread start: `native/sdk/os.c` `func_00106314` (called by the decompiled
   trampoline 0010994C on every game thread, exactly where the 3DS sets FPSCR) sets MXCSR
   FTZ|DAZ (`_mm_setcsr(_mm_getcsr() | 0x8040)`, helper `albw_fp_set_3ds_mode`), and
   `native/runtime/entry.c` calls the same helper for the main thread after `plat_init` (so
   SDL/GL initialise in IEEE mode). FZ on ARM flushes denormal inputs and results, hence both
   DAZ and FTZ. This only affects SSE code, another reason for (1).
3. Not reproducible: DN (ARM returns the default NaN 0x7FC00000 for every NaN result; x86
   propagates the operand NaN and its own default is 0xFFC00000, sign bit set). It matters
   where the game compares float BIT PATTERNS as signed integers (the inlined chase clamps
   `vmov r2,s0; cmp r2, #0x7F7FFFFF`): a negative-signed NaN compares below FLT_MAX on x86.
   Rewrites that need it can canonicalise NaN explicitly.
4. Host libraries (SDL audio thread, GL driver threads) are not game threads and keep IEEE mode.

## 3. Actor update loop, physics/movement, player

There is **no central gravity/velocity integrator**: actors integrate their position (Vec3 at
+0x3D0) inline in their own state handlers (e.g. 00251F00, 0028AC40, 004D0F4C) with the Vec3
helpers above and the chase/approach helpers (0068C794 / 00688C34, native/robust), then update
their model matrix (004CEAF0) and collider (004EDAB0 / 004ED9C8). The player is driven by an
action system (an action id + a table of 178 actions) rather than one movement routine.

| USA | EU | role | evidence | conf | callers |
|---|---|---|---|---|---|
| 001E31E8 / 001E30D0 | same | TaskMainGame creation / its per-frame calc (calls only 004EFB10) | string "TaskMainGame"; 001E30D0 in the task vtable | high | 1 / 2 |
| 004EFB10 | 004EFAE8 | per-frame main-game update: managers in order 001E0AF4?, 004CDBEC, 002CB110, 004B77C4, 004ED740, 004AD81C, 004CD45C, 004C5100, 00260E30, 004C6DD0, 0051C3C8, 001725D0, then 004EF7EC (when +0x68) | disassembly; 4 frame counters | high | 1 |
| 004C5100 | 004C50D8 | ActorMgr::calc: drains the actor-creation ring (0x2C4-byte requests at +0x28..+0x34), picks a heap (004C4884: Player/Mass/Small/Actor heaps), links actors into the list at +0x3DB8C | strings "ActorHeap", "PlayerHeap" | high | 1 |
| 0052FBA0 | 0052FB78 | ActorMgr lookup by handle (`*data_00706E20 + 0x3DBBC`) | 540 callers | high | 540 |
| 004CDBEC | 004CDBC4 | event/pause manager toggling effect groups (002E3608, nw::eft system data_0070A518) | strings | medium | 1 |
| 004CEAF0 | 004CEAC8 | model instance world matrix: scaled base * optional animated rotation (0051E5F8) + skeleton update | disassembly | high | 375 |
| 0051E5F8 | 0051E5D0 | rotation matrix at the current animation time (key quaternion 0048B5D4 -> Mtx33 00491404) | disassembly | high | 11 |
| 0053EDC8 / 0053EDD8 / 0053EE20 / 0053EE30 / 0053EE40 | 0053ED84.. | animation frame controller: end frame / isEnd / rate / frame / isFrame | disassembly | high | 23/73/7/33/16 sites |
| 00520FC0 | 00520F98 | global game-object getter `*(*data_0070FB60 + 0x1C)` (likely the player) | 493 sites read r0 | medium | 652 sites |
| data_007111A8 | - | player action table, 178 x 16 bytes (byte 0 = action class, +4 flags); names from static init 005C88D4 (State_Wait, Move, Jump, Landing, Damage*, Swim*, Dash*, PreWallIn/Out, StageIn/Out...) | 59 readers | high | - |
| player+0x14 | - | action component: current action id +0x42 (s16), action machine +0x48, player +0x10 | wrappers 0028F...-0029... | high | - |
| 002D55D0 | 002D55AC | ActionMachine::request(id): start an action, return its parameter block | 216 sites | high | 202 |
| 002917A4 / 00291A38 / 00291FE0 / 0028F268 / 0028FBF0 | +0x28 | player hit / knock-back entry points -> current action of class 2 (0031EDC4: knock-back reaction), 6 (00346C4C), 0x17 (0038C2E8), 0xB (003776F8 / 00377820) | enemies pass `enemy+0x3D0` and a strength in s0 | high | 39/24/21/1/2 |
| 00290240, 00291518, 002923B0, 002906A4, 0029081C | +0x28 | player action requests with parameters (0x97; 0x17 from 0x45; 0x5F target; 0x1F/0x20; 0x3F placement) | 002D55D0 + parameter writes | high | 1-4 |
| 002900EC | 00290114 | player movement-speed scale (0.0855 / 0.095) x act[0x24] x carried/ridden actor's float virtual (slot 0x60) | disassembly | medium (meaning) | 2 |
| 0038E13C / 0038EA34 / 0038E8C8 | 0038E118.. | **wall merge**: enter (SE_PL_WALL_IN/OUT, WallOut/WallOutGrass), per-frame move along the wall, exit; one slot group of the player item/action vtable data_006E6D08 | strings, vtable | medium | vtable |
| 002B2590 | 002B256C | enemy damage-reaction table cRT_Zero/Small/Normal/Big/Ice/SpecialDieKnockBack | strings | medium | 1 |
| 0051D2F4 | 0051D2CC | integer angle chase (actor turning) | 257 callers | high | 257 |
| 004C1388 | 004C1360 | per-object effect/attention request scaled by +0x834, tail-calls 004C10C4 | disassembly | high | 102 |

### Audit (player/physics), ranked by centrality x defect weight

| # | USA | callers/sites | defects (audit.py + disassembly) | status |
|---|---|---|---|---|
| 1 | 004CEAF0 | 375 | lost stack Vec3 (r2) and s1 in the call to 0051E5F8; `ble` NaN | rewritten |
| 2 | 0053EDC8 | 23 sites (20 read s0) | defined float, all 9 caller files declare `int ()`: one x87 slot leaked per call on i386 | rewritten (int class) |
| 3 | 0053EE30 | 33 sites (32 read s0) | Ghidra body empty (`void f(void)`): every caller's frame value is garbage | rewritten |
| 4 | 004C1388 | 102 (all read r0) | return lost on the early path (`return;` in the converted non-void function = garbage instead of 0); signed bit-compare clamp | rewritten |
| 5 | 002917A4 (+002917AC) | 39 | r1, r2, s0 lost: wild attacker-position pointer, garbage strength | rewritten |
| 6 | 00291A38 (+00291A40) | 24 | r1, s0 lost | rewritten |
| 7 | 00291FE0 (+00291FE8) | 21 | r1, s0 lost; return dropped (6 tail sites) | rewritten |
| 8 | 0053EDD8 | 73 | only a Ghidra-extra source; NaN branch | rewritten |
| 9 | 0051E5F8 | 11 | r2, s1 lost; `(uint)float` of a possibly negative value (UB) | rewritten |
| 10 | 002906A4 (+002906B8) | 4 | s0 lost; r2/r3 swap; 001DD48C's 3rd argument dropped | rewritten |
| 11 | 002917D4, 00291A04, 0028F268, 0028FBF0, 00290240, 00291518, 002923B0, 0029081C (+ inner halves) | 1-8 | s0 or r1-r3 lost | rewritten |
| 12 | 002900EC | 2 | r1 lost (selects the speed constant) | rewritten |
| 13 | 0038E13C (wall merge enter) | vtable | round 2: exit x from `in_stack_ffffff90` (garbage exit position), SafeString vtable never stored, stale ToImageR handle, handle tested as float | rewritten |
| 14 | 0038EA34 (wall merge move) | vtable | round 2: merge target Vec3 never written (slide toward garbage), NaN `ble` branches | rewritten |
| 14b | 002908B8 (apply action change) | 2 | ridden actor's vt[0x60] float lost, speed bit-compare done as float compare, 0010DBBC stack pair never written | rewritten |
| 14c | 0051D2F4 (integer angle chase) | 257 | `(int)` C cast: NaN rate -> maxStep instead of minStep, overflow | rewritten |
| 15 | 0053EE20 | 7 sites | float/int declarations disagree in the old conversion | open (signature table) |
| 16 | 004EFB10, 004C6DD0, 004EF7EC | 1 | `extraout_r1` passed where the callee reads only r0 | benign |
| 17 | 004C0350 | 55 | flagged (s0 "missing") but **false positive**: s0 is written on both paths by vldreq/vldrne | none |

### Rewritten (player/physics): 31 files

- `func_004CEAF0.c` model world matrix: restores the stack Vec3 (base z column) and s1 passed to 0051E5F8; vmul + unfused vmla order. High.
- `func_0051E5F8.c` animation rotation matrix: full ARM signature (self, out, a, f0, f1), saturating conversion, ARM floor/NaN. High. Round 2 regenerated the callers with the 5-argument signature: linkable (section 6.1).
- `func_0053EE30.c`, `func_0053EDC8.c` frame getters: return the float's bits in the int class (no x87 leak) + exact `albw_anim_frame` / `albw_anim_end_frame`. High.
- `func_0053EDD8.c` isEnd with `blt`/`bls`/`bne` NaN semantics. High.
- `func_004C1388.c`: restores the return value (0 on the early path), signed bit-compare clamp, full 004C10C4 prototype. High.
- player hit / knock-back dispatch, wrapper + fall-through body, lost r1/r2/s0 restored: `func_002917A4/002917AC`, `002917D4/002917DC`, `00291A38/00291A40`, `00291A04/00291A0C`, `00291FE0/00291FE8`, `0028F268/0028F270`, `0028FBF0/0028FBF8`. High.
- player action requests, s0 restored: `00290240/00290248`, `00291518/00291520`, `002923B0/002923B8`, `002906A4/002906B8` (keeps the r2/r3 swap), `0029081C/00290824` (float-bits compare with 1.0f kept as integer compare). High.
- `link_walk.c` (was `func_002900EC.c`): player walking speed and velocity, rewritten with named fields (also holds `002D5ADC`); flag argument restored; float virtual at slot 0x60. Checked old against new by `tools/tests/link_walk_test.sh`.

Checked instruction by instruction: 004CEAF0, 0051E5F8, 004C1388, 00290824, 002906B8, 002917AC,
002900EC (002917AC re-checked independently). Test: `native/gameplay/test/player_test.c`
(004CEAF0 product/translation/NaN path, 0053EDD8 incl. NaN rate, 004C1388 clamp for negative /
normal / 1.0 / NaN, 002917AC forwarding).

**Caveat (most player rewrites):** they restore the real ARM parameters (e.g. the attacker
position and strength). The converted callers still pass what Ghidra's signature had (often one
argument fewer), so these definitions become correct only when the converter declares callees
from the ARM live-in set (`livein2.json` 'final': ints in register order, then floats). Until
then, linking them changes which garbage the callee sees, not correctness.

## 4. Collision system

KCL meshes are loaded per map actor (`MapActor/%s.kcl`, `%s/%s.kcl`, `Actor/*.kcl`) into a
KCL collision object (shape type 0xC); actors own a collider component that is registered in a
broad-phase grid and queried with sphere/box/segment sweeps; a narrow-phase dispatcher handles
shape pairs. There is no single "BG check" function: ground/wall/ceiling decisions are made by
the callers from the triangle records (normal, height, thickness) the KCL queries return.

| USA | EU | role | evidence | conf | callers |
|---|---|---|---|---|---|
| 004AB348 | 004AB320 | map collision init ("kcl"): manager, 0043283C id table, 00435920 static shapes | string "kcl" | med | 1 |
| 004A8EB4 / 004A8D80 | 004A8E8C / 004A8D58 | load a collision resource ("World") | string; called by 004EDC5C/004EDB28 | med | 2 / 1 |
| 004EDC5C, 004EDB28 | 004EDC34, 004EDB00 | actor collision component: create the KCL object (ctor 0043227C + 00431F28) | callers = the `%s.kcl` loaders 004D2F20/001BA1EC/004D1114/0027E0C8/001349D4 | high | 7 / 35 |
| 0043227C | 0043225C | KCL collision object ctor (type 0xC, hit buffer +0x88..+0x488, write ptr +0x488) | field init, 0x400 memclr | high | 2 |
| 00431F28 | 00431F08 | KCL: set resource (+0x58); parsed header = res+0xB4 (+0x5C) | `str r1,[r0,#0x58]; ldr r1,[r1,#0xb4]` | high | 2 |
| KCL header (+0x5C) | | +0 positions, +4 normals, +8 prisms (16 bytes: height, pos, face normal, edge normals 1-3, attribute), +0xC octree, +0x10 thickness, +0x14 area min, +0x20..+0x28 x/y/z masks, +0x2C/+0x30/+0x34 coord/y/z shifts, +0x38 sphere radius | field use in 0042E990/0042EFB0/00434F68/005706B0 | high | |
| 00431F44 | 00431F24 | KCL segment (swept sphere) query; context data_007307DC | ctx writes; calls 0042E990/0042EFB0 | high | virtual |
| 0042EFB0 | 0042EF90 | KCL octree box walk (AABB -> cells -> leaves, inlined leaf tests) | masks/shifts; calls 004317D4/0043081C | high | 5 |
| 0043081C | 004307FC | KCL octree partial-box recursion | 8x per node from 0042EFB0 | high | 2 |
| 004317D4 | 004317B4 | KCL subtree walk + leaf prism tests (gather / sphere / dedup) | recursion, prism tests | high | 3 |
| 0042E990 | 0042E970 | KCL point query (descend to one leaf) | vcvt + mask + shift | high | 5 |
| 0042E7F4 | 0042E7D4 | KCL object: run query records (vt+0x14) | ctx+0x6E flag, hit count | high | 1 (every collider) |
| 00434F68 | 00434F48 | prism -> world triangle record (normals, thickness, height; moving-mesh transform) | normals[prism+6..0xC], M33 at +0x3C/+0x84 | high | 3 |
| 00433ABC | 00433A9C | triangle record base (kcl, prism, index, vertex, thickness) | | high | 4 |
| 005706B0 | 00570688 | KCL bounding radius (hdr+0x38), returns s0 | 3 insns | high | 3+ |
| 0042DD38 | 0042DD18 | narrow-phase dispatcher on shape type (+0x54) | switch over type pairs | high | 6 |
| 0042A260-0042DA98 | | shape-pair tests; types 1 point, 5 plane (004323A0), 6 sphere (00432F74), 7 capsule (004336CC), 8/9 box-like, 0xC KCL | ctor type stores | med (names) | 1-4 |
| 0042DA98 / 0042D8F4 / 0042CF00 / 0042D464 | +0x20 | segment-segment closest points / point-segment / ray-plane / capsule vs swept segment | | high | 3/3/3/1 |
| 004A879C | 004A8774 | broad phase: (re)register a collider in a grid cell or the large-object list | 120 callers; cell lists mgr+0x11C | high | 120 |
| 004A7F00, 004A8304, 004A9120, 004A8030, 004A8BFC | | broad phase register/unlink/misc | list link/unlink 0010F1DC/0010F1F8 | med | 59/88/44/58/30 |
| 004A97F8, 00581A18 | | grid: cells of an AABB / cell of a point | | med | 3 / 6 |
| 004A7620, 004A9F98 | 004A75F8, 004A9F70 | main actor-vs-world sweeps (all colliders in the cells, vt+8 each) | s0/s1 bounds | high | 18 / 21 |
| 004AAD4C / 004AAF44 | 004AAD24 / 004AAF1C | grid box query -> 004A9178 / grid sphere query -> 0042DD38 + callback | | high | 3 / 2 |
| 004A9178 | 004A9150 | per-entry KCL query (point or box path by radius) | | high | 1 |
| 004A8334 / 004AA9FC | | per-cell loops -> 004ED9F4 | | high | 2 / 1 |
| 004ED9F4 | 004ED9CC | collider component: sphere/AABB prefilter -> KCL query | | high | 2 |
| 00324AC4, 0043377C, 00433944, 00433B08, 00434AB8, 00434C3C | | collision attributes from byaml ("Collision", "Type", None/Normal/MapObj/Enemy) | strings | med | 1 |

### Audit (collision)

138 functions (0042A000-00436800, 004A7600-004AB4D0, 004ED9C8-004EDD00), 47 with at least one
defect: missing register args 6, lost returns 3, `in_/unaff_/extraout_` 12, lost stack objects 5,
indirect tail calls 0, float bit-casts 34 functions / 257 sites in the raw Ghidra text (many of
them already rewritten as `ALBW_AS_*` by the round-1 conversion that is now compiled, e.g.
0042E7F4), float->int conversions 14, SQRT 21.

| # | USA | callers | defects | status |
|---|---|---|---|---|
| 1 | 0042EFB0 KCL box walk | 5 (hot) | round 2: distance vector still `in_stack_ffffff10..1c` (73 uses), 6 `(uint)` bound casts (box past 2^31 -> no prisms), shift UB, dropped r0 | rewritten |
| 2 | 004317D4 KCL subtree/leaf | 3 (recursive) | radius bit-cast -> every prism "hits" | rewritten |
| 3 | 0042E990 KCL point query | 5 | radius + vertex-z bit-casts, `(uint)` of vcvt.s32 | rewritten |
| 4 | 004A879C grid register | 120 | "size > 2.0" bit compare printed as `(int)` -> big colliders never in the large list | rewritten |
| 5 | 004A9F98 sweep | 21 | round 2: s0/s1 still lost (`vpush {d0}` pattern), fallback call 3 args | rewritten (albw_ + func_ with the constant bounds) |
| 6 | 004A7620 sweep | 18 | round 2: s0/s1 still lost | rewritten (same) |
| 7 | 0043081C KCL partial box | 2 | round 2: distance vector `in_stack` (35 uses), bound via `(int)ALBW_AS_U32` | rewritten |
| 7b | 00581A18 grid cell of a point | 3 | `(int)` casts: far +x/+z -> cell 0 instead of 25 | rewritten |
| 8 | 00434F68 prism -> triangle | 3 | thickness `(float)int` -> garbage radius on every triangle | rewritten |
| 9 | 00431F44 KCL segment query | virtual | endpoint x stored via `(int)` | rewritten |
| 10 | 004ED9F4 prefilter | 2 | AABB read via `(float)int`, stack argument dropped | rewritten |
| 11 | 0042E7F4 run query | 1 (every collider) | sphere centre x via `(int)` (fixed by round-1 too) | rewritten |
| 12 | 004A9178 per-entry KCL | 1 | 005706B0's float return lost (typed `void(void)`): stale compare | rewritten |
| 13 | 004AAD4C grid box query | 3 | s0/s1 lost; extent Vec3 never written | rewritten |
| 14 | 004AAF44 grid sphere query | 2 | radius s0 lost; box Vec3 never written | rewritten |
| 15 | 0042BD5C shape test | 4 | 6 bit-casts | open |
| 16 | 0042DA98 seg/seg | 3 | 3 bit compares as `(int)` | rewritten |
| 17 | 0042D8F4 point/seg | 3 | normalize's length lost (`in_s0`) | rewritten |
| 18 | 0042CF00 ray/plane | 3 | 2 bit compares | rewritten |
| 19 | 0042D464 capsule/seg | 1 | lost stack object, `(float)` store | rewritten |
| 20 | 0042C7B8 / 0042BB2C capsule tests | 1 / 1 | 2 lost stack objects each + bit-casts | open |
| 21 | 004A9BDC | 1 | `unaff_r8`, 8 bit-casts | open |
| 22 | 0043285C | 1 | r1 missing, `in_d8/in_d9` | open |
| - | 004A8564 / 004AACA0 | 1 / 2 | r3 dropped | benign (callers pass 0, 0042E7F4 never reads it) |

Note: livein2 misses s0/s1 for 004A7620/004A9F98 (`vpush {d0}; vmov.f64 d8, d0` pattern), so
the global "missing args" count under-reports the float-argument class.

### Rewritten (collision): 14 files

All with `#pragma STDC FP_CONTRACT OFF`, `VCMP_*`/`gp_*` helpers. Instruction-by-instruction
checks: 0042DA98, 0042CF00, 004ED9F4, 004317D4, 0042E990.

- `func_0042DA98.c` segment/segment closest points: 3 bit compares (`cmp sN, #0x34000000`), float return. High.
- `func_0042D8F4.c` point/segment: uses normalize's length (inlined exactly). High.
- `func_0042D464.c` capsule vs swept segment: lost stack temp, int-value store. High.
- `func_0042CF00.c` ray/plane: vnegle + bit-compare near-zero tests. High.
- `func_0042E7F4.c` KCL run query: sphere centre word copy. High.
- `func_0042E990.c` KCL point query: radius/vertex reads, saturating vcvt, ARM register-shift semantics. High.
- `func_004317D4.c` KCL subtree walk (gather/sphere/dedup): radius bit-cast. High.
- `func_00431F44.c` KCL segment query + context: endpoint word copies, NaN-exact radius tests. High.
- `func_00434F68.c` KCL triangle record: thickness/height stores (static and moving mesh). High.
- `func_004A879C.c` grid register: "> 2.0f" bit compares. High.
- `func_004A9178.c` per-entry KCL query: radius getter inlined, point/box choice, vmls box edges. High.
- `func_004AAD4C.c` grid box query: s0/s1 and the extent box. High (flow), medium (names).
- `func_004AAF44.c` grid sphere query: radius and box, asymmetric y-max test kept. High (flow), medium (names).
- `func_004ED9F4.c` collider AABB prefilter: float AABB reads, extra stack argument. High.

Test: `native/gameplay/test/collision_test.c` (0042DA98, 0042D8F4, 0042CF00; build line in its
header, needs `-lm`), passes -m32 and -m64.

## 5. Enemy damage reaction / knock-back (002B2590)

002B2590 (EU 002B256C) is the CONSTRUCTOR of the enemy damage-reaction state machine, not a
dispatcher: 33 `cRT_*` states, each {enter, exec, exit} delegates at +0x18/+0x1C/+0x20 copied from
data_00698944 (map recovered by emulating the ctor). Knock-back states: 14 Zero (002AF4DC /
002ADDA0 / 002AEE8C), 15 Small (002AF59C / 002ADF78 / 002AF570), 16 KnockBack (002AD8A0 /
002AC268 / 002AD730), 17 Big (002AE9F8 / 002ACE08 / 002AE9B8), 18 Ice (002AEA54 / 002ACF20 /
002AE9E0), 30 SpecialDie (002B0584 / 002AF63C / 002B1638). The work is in shared helpers:
002B0D7C start knock-back, 002AFEF0 per-frame (clean in round 2), 002B193C death/launch, exits
002B0754 / 002B1644 / 002B05F0. Player side 0031EDC4: clean in round 2.

| # | USA | callers | round-2 defects | status |
|---|---|---|---|---|
| 1 | 002B0D7C knock-back start | 12 fn / 14 sites | strength s0 lost (`vpush {d0}` pattern), vt[0x68] float return lost (speed = garbage^2), virtual called without &frames, SafeString for SE_EN_DAMAGE_FAINT never written, "speed == 0" compares unrelated values | rewritten (ARM 5-arg signature) |
| 2 | its 12 enter callers (002AF4DC, 002AF59C, 002AD8A0, 002AE9F8, 002AEA54, 002ADF60, 002ACBAC, 002B1710, 002AEA9C, 002AF624, 002AE1BC, 002AE214) | delegates | strength constant (0 .. 0.35, ice choice on actor+0x895) dropped | rewritten |
| 3 | 002AF168 TornadoFreeze enter (221 insns) | delegate | passes 0.32 (knock-back and death path), dropped | **open: blocks linking 002B0D7C** |
| 4 | 002B193C death/launch | | 7 float->int, 4 SQRT | open |
| 5 | 002AAD94 Launch exec, 002AB978 Fall enter, 002AE274 HammerBreak enter | | lost stack objects, float->int | open |
| 6 | 002AB3DC / 002AB3E0 / 002AB61C | | 2-4 residual bit-casts | open |

## 6. Round-2 re-audit (this pass)

### 6.1 What round 2 changed for the existing rewrites (sigcheck.py)

- Return class now **float** in every converted caller for 00115154 (sinCos: s0 = sin), 00115DC8,
  00115C14 (normalize length), 00490628 (exp), 00491624 (Mtx33 from Euler: s0 = m[1]), 0053EDC8,
  0053EE30 (frame getters). The func_ definitions returned int (bits) to match round 1; on i386
  that would now pop an empty x87 st(0) in every caller. All seven now return the ARM s0 value
  (test_math.c checks the values, incl. sinCos with aliased outputs).
- 0051E5F8: round 2 gives exactly r0, r1, r2, s0, s1 (`extern int (int, float *, undefined4,
  float, float)` in all 12 caller files). The rewrite now takes `(int self, float *out, uint32_t
  a, f0, f1)` and is **linkable**; round 2 still has the `(uint)` frame conversion and the NaN
  floor branch (fixed here, residual_test.c). Its pointer body is `albw_anim_rotation`, used by
  004CEAF0 (whose stack Vec3 address must not go through a 32-bit word on -m64).
- 00431F44: round 2 dropped the dead 4th parameter: definition now `(obj, user, q)`.
- M64PTR: 25 definitions took a native pointer where the callers pass an `int`; on x86-64 the
  upper half of that argument register is undefined. All now take `uint32_t` + `gp_ptr`
  (pointer bodies kept as `albw_kcl_walk` for 004317D4 etc.). 004CEAF0 now returns r0 (flags).
- Remaining sigcheck findings: VOIDRET (void definition, callers declare int, no caller uses the
  value: 0028F268, 0028FBF0, 0042E990, 004317D4, 00434F68, 004A879C, 004A9178) benign; ARGS:
  002B0D7C (sec. 5), 004AAD4C / 004AAF44 (callers lose s0/s1: `vpush {d0}` pattern),
  004ED9F4 (callers drop the stack argument).

### 6.2 Residual bit-casts / float->int casts in the collision/player/math graph (431 functions)

Round 2 leaves 6 functions / 13 sites with residual bit-casts and 16 / 30 with float->int casts
(most `VectorFloatTo*`, exact). Fixed by rewrite: 00115960 (Matrix44 multiply, vldm-pair
`(float)*(undefined8 *)`: rows 2-3 of b garbage), 0051D2F4 (angle chase, 257 callers),
00581A18 (grid cell), 002908B8 (action change), plus the KCL walkers. Left: 004906A8 (log
approx: all conversions are exact intrinsics), 0042BD5C (6 raw casts, 0 residual), 0043285C
(`in_d8/in_d9`), 004A9BDC (`unaff_r8`), 0042C7B8 / 0042BB2C (2 stack objects each).

### 6.3 New rewrites (EU = USA - 0x20/0x24 etc., ranges in each header)

| USA | role | round-2 bug fixed | verification | conf |
|---|---|---|---|---|
| 0042EFB0 | KCL octree box query | distance vector `in_stack` (73 uses), saturating bounds, shift >= 32, r0 | EU 0042EF90-00430294 insn by insn | high |
| 0043081C | KCL partial-box recursion | distance vector `in_stack` (35), bound bit-cast | EU 004307FC-004317B0 | high |
| 004A7620 | world sweep (all layers) | s0/s1 lost: path chosen at random; `albw_collision_sweep` exact, func_ passes (2.0, 4.0) = 26 of 27 ARM sites | EU 004A75F8-004A7ED4 | high flow / med names |
| 004A9F98 | area sweep | same; fallback call; func_ (2.0, 4.0) exact at all 23 sites | EU 004A9F70-004AA9CC | high / med |
| 0038E13C | wall merge enter (vt+0x10 of data_006E6D78) | exit x garbage, SafeString vtable, ToImageR handle, float test of a handle | EU 0038E118-0038E844 | high / med |
| 0038EA34 | wall merge calc (vt+0x14) | merge target never written, NaN branches, 00114608 folded | EU 0038EA10-0038EFB8 | high / med |
| 0038E8C8 | wall merge exit (vt+0x18) | none (prototype only) | EU 0038E8A4-0038E8D8 | high |
| 002908B8 | apply pending player action | vt[0x60] float lost, speed bit-compare (DN NaN), stack pair | EU 002908E0-00290E8C + both jump tables | high |
| 002B0D7C + 12 enters | enemy knock-back start | section 5 | each insn by insn | high (flow) |
| 0051D2F4 | integer angle chase | `(int)` cast NaN/overflow | EU 0051D2CC-0051D350 | high |
| 00581A18 | grid cell of a point | `(int)` cast overflow | EU 005819F0-00581A9C | high |
| 00115960 | Matrix44 multiply | vldm-pair value conversion | EU 00115960-00115A8C | high |

Tests: `test/run_tests.sh` builds and runs test_math (55), player, collision, residual (24),
kcl_box, knockback, sweep (56), wall (68), action, each -m32 and -m64 with the build's float
flags (-no-pie -fno-pic: test stubs are reached through 32-bit vtable words). All pass.
Game objects in tests come from `test/lowmem.h` (MAP_32BIT on -m64).

### 6.4 Link blockers / caveats

1. 002B0D7C: 002AF168 (TornadoFreeze enter, passes 0.32) is still a 4-argument converted caller.
   Rewrite it (or give 002B0D7C r0-r3+s0 in the signature table) before linking 002B0D7C.
2. 004AAD4C / 004AAF44: callers pass no s0/s1; 004ED9F4: callers drop the stack argument. Need
   the signature table (livein_dregs.json for the first two).
3. 004A7620 / 004A9F98 func_ use the constant bounds (2.0, 4.0): exact except the call at
   00341D28 (EU 003422E4: f0 = 1.0). Exact once the table gives them s0/s1 (then define func_
   as the albw_ versions).
4. Matched decomp objects in the -m32 link (`build/objs.txt`) for the same addresses:
   0028FBF0 (r_0028FBF0.cpp), 00290248, 002906B8, 00291A40, 00291FE0, 002AD8A0 (declares
   002B0D7C `void`: an x87 leak per call against the float definition), 0038E8C8, 004D80A4,
   0053EE30, 0068C690. link.sh must keep exactly one per address (the native/gameplay one where
   the matched code calls a changed prototype, e.g. 002AD8A0).
5. -m64: several rewrites (and the round-2 callers) store native stack addresses in 32-bit game
   words (00431F44 ctx+0, sweep query copies, 0051E5F8's `a`): only correct with game threads on
   low stacks. Stubs/callbacks called through 32-bit vtable words need code below 4 GiB
   (-no-pie or the low-4GB arena).

## 7. Biggest remaining risks for gameplay (ranked)

1. **Signature table for the `vpush {d0}` float arguments** (livein_dregs.json: 17 functions incl.
   the sweeps, 002B0D7C, 004AAD4C, 004AAF44): until then those rewrites run with constant or
   dropped floats at some sites (6.4 items 1-3).
2. **Duplicate definitions at link time** (6.4 item 4) and the native robust/sdk definitions
   whose return class disagrees with round-2 callers (003E1634, 0065D120, 006640EC, 0065F560,
   0066E07C): i386 x87 stack corruption -> every later float return NaN.
3. **Enemy reaction states still Ghidra C**: 002AF168, 002B193C (death/launch), 002AAD94,
   002AB978, 002AE274; each enemy class's vt[0x68] direction virtual must return float.
4. **Residual vldm-pair bit-casts** (518 functions / 1,084 sites globally, e.g. any other
   `(float)*(undefined8 *)`): a converter rule (low word bits) is still needed.
5. **Collider vt[2] narrow-phase tests** reached from the sweeps were not audited; 0042BD5C,
   0042C7B8, 0042BB2C, 0043285C, 004A9BDC still Ghidra C.
6. **Float model**: flags now pinned; FTZ/DAZ still not set (fpmath.patch item 2); DN only
   reproduced in 002908B8's bit compare.
7. **64-bit**: native stack addresses in 32-bit words (6.4 item 5); code-embedded constants
   (gen_data) as before.
