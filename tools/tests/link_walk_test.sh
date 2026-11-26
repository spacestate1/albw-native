#!/usr/bin/env bash
# Old against new for native/gameplay/link_walk.c (see link_walk_test.c). The old versions come from the
# last commit that had them. Needs the decompilation headers of a finished build (build/decomp/shared).
#   tools/tests/link_walk_test.sh [rounds]
set -euo pipefail
cd "$(dirname "$0")/../.."
OLD=fed0c5f3
T=$(mktemp -d)
trap 'rm -rf "$T"' EXIT
git show $OLD:native/gameplay/func_002900EC.c > "$T/old_speed.c"
git show $OLD:native/compilefix/func_002D5ADC.c > "$T/old_walk.c"
# as tools/link.sh builds the decompiled code
CF=(-m32 -std=gnu11 -O2 -w -fno-strict-aliasing -fwrapv -ftrivial-auto-var-init=zero -msse2 -mfpmath=sse -ffp-contract=off
    -DALBW_V4 -Inative/include -Inative/gameplay -Inative/compilefix -include native/albw_native.h -Ibuild/decomp/shared/include
    -Wno-error=int-conversion -Wno-error=incompatible-pointer-types -Wno-error=implicit-function-declaration)
clang "${CF[@]}" -Dfunc_002900EC=old_002900EC -c "$T/old_speed.c" -o "$T/old_speed.o"
clang "${CF[@]}" -Dfunc_002D5ADC=old_002D5ADC -Dfunc_002900EC=old_002900EC -c "$T/old_walk.c" -o "$T/old_walk.o"
clang "${CF[@]}" -c native/gameplay/link_walk.c -o "$T/new.o"
clang -m32 -O1 -Wall -c tools/tests/link_walk_test.c -o "$T/test.o"
clang -m32 -no-pie "$T"/*.o -lm -o "$T/link_walk_test"
"$T/link_walk_test" "$@"
