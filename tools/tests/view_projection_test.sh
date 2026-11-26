#!/usr/bin/env bash
# native/gameplay/view_projection.c against the version it replaced (see view_projection_test.c). The old
# version comes from the last commit that had it. Needs the decompilation headers of a finished build.
#   tools/tests/view_projection_test.sh [rounds]
set -euo pipefail
cd "$(dirname "$0")/../.."
OLD=fed0c5f3
T=$(mktemp -d)
trap 'rm -rf "$T"' EXIT
git show $OLD:native/compilefix/func_0057F6C0.c > "$T/old.c"
# as tools/link.sh builds the decompiled code
CF=(-m32 -std=gnu11 -O2 -w -fno-strict-aliasing -fwrapv -ftrivial-auto-var-init=zero -msse2 -mfpmath=sse -ffp-contract=off
    -DALBW_V4 -Inative/include -Inative/gameplay -Inative/compilefix -include native/albw_native.h -Ibuild/decomp/shared/include
    -Wno-error=int-conversion -Wno-error=incompatible-pointer-types -Wno-error=implicit-function-declaration)
clang "${CF[@]}" -Dfunc_0057F6C0=old_0057F6C0 -Dalbw_ws_refresh=old_view_refresh -c "$T/old.c" -o "$T/old.o"
clang "${CF[@]}" -c native/gameplay/view_projection.c -o "$T/new.o"
clang -m32 -O1 -msse2 -mfpmath=sse -Wall -c tools/tests/view_projection_test.c -o "$T/test.o"
clang -m32 -no-pie "$T"/*.o -lm -o "$T/view_projection_test"
"$T/view_projection_test" "$@"
