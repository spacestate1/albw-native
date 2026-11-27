#!/usr/bin/env bash
# Build the AppImage's start-up stub, the part that runs before anything of the port does.
#
#   tools/build_appimage_runtime.sh          -> build/appimage-tools/runtime-x86_64
#
# It is the standard AppImage "type2 runtime" with one change (packaging/appimage/runtime-fallback.patch):
# where the AppImage cannot be mounted it unpacks itself and runs, instead of giving up. Steam starts
# games inside a container that has no fusermount, so the standard stub fails there with "Cannot mount
# AppImage" (Steam Deck). Needs git and podman or docker. Releases carry the built file as
# albw-appimage-runtime-x86_64, which tools/make_appimage.sh downloads where it cannot be built.
set -euo pipefail
cd "$(dirname "$0")/.."
COMMIT=fedfad51acc2860b2916a1eef32ba4a500ff31ef   # github.com/AppImage/type2-runtime, 2026-10-19
PATCH=$PWD/packaging/appimage/runtime-fallback.patch
OUT=build/appimage-tools/runtime-x86_64
KEY=$(printf '%s %s' "$COMMIT" "$(sha256sum < "$PATCH")")
if [[ -f $OUT && -f $OUT.key && $(cat $OUT.key) == "$KEY" ]]; then echo "== AppImage runtime: $OUT (up to date)"; exit 0; fi
CT=$(command -v podman || command -v docker || true)
[[ -n $CT ]] || { echo "needs podman or docker"; exit 1; }
mkdir -p build/appimage-tools
WORK=$(mktemp -d -p build/appimage-tools runtime.XXXX)
trap 'rm -rf "${WORK:?}"' EXIT
git clone -q https://github.com/AppImage/type2-runtime "$WORK/src"
git -C "$WORK/src" checkout -q $COMMIT
git -C "$WORK/src" apply "$PATCH"
echo "== building the AppImage runtime (Alpine container)"
"$CT" build -q -t albw-type2-runtime -f "$WORK/src/scripts/docker/Dockerfile" "$WORK/src" >/dev/null
"$CT" run --rm -v "$PWD/$WORK/src":/ws:Z -w /ws albw-type2-runtime bash scripts/build-runtime.sh >"$WORK/build.log" 2>&1 \
    || { tail -30 "$WORK/build.log"; exit 1; }
cp "$WORK/src/out/runtime-x86_64" $OUT
printf '%s' "$KEY" > $OUT.key
echo "== AppImage runtime: $OUT ($(du -h $OUT | cut -f1))"
