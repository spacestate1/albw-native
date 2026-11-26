#!/usr/bin/env bash
# Build the WINDOWS version from Linux (cross-compile). Read windows/README.md for how it works.
#
#   windows/build_windows.sh            -> build/windows-release/ and build/ALBW-windows.zip
#
# Contents of the package (everything Windows needs; no installer):
#   ALBW.exe       the loader (windows/loader.c): maps the game program and starts it
#   albw           the game program (the Linux i386 build, variant without thread-local %gs data)
#   albw.ssmap     its save-state map
#   SDL3.dll       window, input, audio, OpenGL context (official 32-bit MinGW build)
#   mesa/          software OpenGL (Mesa llvmpipe, mesa-dist-win), used only when the PC has no
#                  real OpenGL 3.3 driver (virtual machine, Remote Desktop, missing GPU driver)
#   HOW TO PLAY.txt
# The player supplies their own decrypted .3ds (a file dialog asks on the first start).
#
# Needs: the normal Linux build (./build.sh) done once, the MinGW-w64 cross compiler
# (i686-w64-mingw32-gcc; Arch: mingw-w64-gcc, Debian/Ubuntu: gcc-mingw-w64-i686, Fedora:
# mingw32-gcc), curl, make, 7z (p7zip) for Mesa. SDL3, zlib and Mesa are downloaded into
# build/win-deps the first time.
set -euo pipefail
cd "$(dirname "$0")/.."
ROOT=$PWD
SDL_VER=3.4.20
ZLIB_VER=1.3.1
MESA_VER=26.2.1
CC=i686-w64-mingw32-gcc
DEPS=$ROOT/build/win-deps
OUT=$ROOT/build/windows-release
command -v $CC >/dev/null || { echo "Install the MinGW-w64 cross compiler first ($CC)."; exit 1; }
mkdir -p "$DEPS" build/win

# --- 1. the game program: the Linux build with native code that does not use %gs ------------------
# (-femulated-tls: thread-local variables through pthread keys; -fno-stack-protector for the native
#  layer; the decompiled objects' canary reads are patched by the loader)
echo "== game program (Windows variant)"
ALBW_LINK_OUT=build/win/albw ALBW_NOBJ=build/nobj-win \
ALBW_EXTRA_CFLAGS="-femulated-tls -fno-stack-protector -DALBW_WINDOWS" \
ALBW_FCONV_INTERIM=${ALBW_FCONV_INTERIM:-0} ALBW_JOBS=${ALBW_JOBS:-2} tools/link.sh | tail -1

# --- 2. SDL3 (official MinGW development package) ------------------------------------------------
SDL=$DEPS/SDL3-$SDL_VER/i686-w64-mingw32
if [[ ! -f $SDL/bin/SDL3.dll ]]; then
    echo "== downloading SDL3 $SDL_VER"
    curl -fsSL -o "$DEPS/sdl3.tgz" \
        "https://github.com/libsdl-org/SDL/releases/download/release-$SDL_VER/SDL3-devel-$SDL_VER-mingw.tar.gz"
    tar -C "$DEPS" -xzf "$DEPS/sdl3.tgz"
fi

# --- 3. zlib (static) ------------------------------------------------------------------------------
ZL=$DEPS/zlib-i686
if [[ ! -f $ZL/lib/libz.a ]]; then
    echo "== building zlib $ZLIB_VER"
    curl -fsSL -o "$DEPS/zlib.tgz" "https://github.com/madler/zlib/releases/download/v$ZLIB_VER/zlib-$ZLIB_VER.tar.gz"
    tar -C "$DEPS" -xzf "$DEPS/zlib.tgz"
    make -s -C "$DEPS/zlib-$ZLIB_VER" -f win32/Makefile.gcc PREFIX=i686-w64-mingw32- libz.a >/dev/null
    mkdir -p "$ZL/include" "$ZL/lib"
    cp "$DEPS/zlib-$ZLIB_VER"/{zlib.h,zconf.h} "$ZL/include/"
    cp "$DEPS/zlib-$ZLIB_VER/libz.a" "$ZL/lib/"
fi

# --- 4. Mesa (software OpenGL fallback) ------------------------------------------------------------
MESA=$DEPS/mesa-$MESA_VER
if [[ ! -f $MESA/x86/opengl32.dll ]] && command -v 7z >/dev/null; then
    echo "== downloading Mesa $MESA_VER (software OpenGL fallback)"
    curl -fsSL -o "$DEPS/mesa.7z" \
        "https://github.com/pal1000/mesa-dist-win/releases/download/$MESA_VER/mesa3d-$MESA_VER-release-mingw.7z"
    mkdir -p "$MESA" && 7z x -y -o"$MESA" "$DEPS/mesa.7z" >/dev/null
fi

# --- 5. the loader ---------------------------------------------------------------------------------
echo "== ALBW.exe"
mkdir -p build/win
# --stack reserve,commit: the game program is Linux code, which takes a large stack frame in one step
# (main: 17 KB) without touching the pages on the way, as Windows code would. With the default 4 KB
# committed, about one start in forty crashed there. Everything up to 128 KB is committed from the start.
$CC -O2 -mstackrealign -Wall -Wno-unused-function -I"$ZL/include" windows/loader.c -o build/win/ALBW.exe \
    -L"$ZL/lib" -lz -lcomdlg32 -lwinmm -lsynchronization -mwindows -static -static-libgcc \
    -Wl,--large-address-aware -Wl,--image-base,0x00400000 -Xlinker --stack=0x200000,0x20000

# --- 6. package ------------------------------------------------------------------------------------
rm -rf "${OUT:?}"
mkdir -p "$OUT"
cp build/win/ALBW.exe build/win/albw build/win/albw.ssmap "$SDL/bin/SDL3.dll" "$OUT/"
if [[ -f $MESA/x86/opengl32.dll ]]; then
    mkdir -p "$OUT/mesa"
    cp "$MESA"/x86/{opengl32.dll,libgallium_wgl.dll} "$OUT/mesa/" 2>/dev/null || cp "$MESA"/x86/*.dll "$OUT/mesa/"
fi
cp windows/HOW_TO_PLAY.txt "$OUT/HOW TO PLAY.txt"
[[ -f VERSION ]] && cp VERSION "$OUT/VERSION"
mkdir -p "$OUT/roms"
printf "Put your decrypted .3ds file (European release) in this folder, then double-click ALBW.exe.\r\n" > "$OUT/roms/PUT YOUR 3DS FILE HERE.txt"
rm -f build/ALBW-windows.zip
(cd "$OUT" && 7z a -tzip -mx=9 "$ROOT/build/ALBW-windows.zip" . >/dev/null 2>&1 || zip -qr "$ROOT/build/ALBW-windows.zip" .)
echo "== done: $OUT/ and build/ALBW-windows.zip"
