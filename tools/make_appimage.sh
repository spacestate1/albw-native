#!/usr/bin/env bash
# Package the current build (build/albw, from ./build.sh) as an AppImage.
#
#   tools/make_appimage.sh [output.AppImage]      default: build/ALBW-native-x86_64.AppImage
#
# Contents: the game (32-bit), its save-state map (albw.ssmap), the 32-bit SDL3 and zlib it was
# linked with (+ libgcc_s), a launcher (packaging/appimage/AppRun), desktop file and icon.
# Not inside, by design:
#   - the game itself: the player supplies their own decrypted .3ds (--rom PATH, ALBW_ROM, or a file
#     dialog on first start; remembered in ~/.config/albw-port/rom_path);
#   - 32-bit glibc and the OpenGL driver: they must match the system (the launcher says what to
#     install when they are missing).
# The AppImage holds compiled game code: share it only as far as you would share the build.
#
# appimagetool is downloaded once into build/appimage-tools/ (from github.com/AppImage/appimagetool);
# it needs the `file` command.
# Running the AppImage needs FUSE (libfuse2 or fuse3); without it:
#   ./ALBW-native-x86_64.AppImage --appimage-extract-and-run [--rom ...]
set -euo pipefail
cd "$(dirname "$0")/.."
ROOT=$PWD
OUT=${1:-build/ALBW-native-x86_64.AppImage}
[[ $OUT == /* ]] || OUT=$ROOT/$OUT

[[ -x build/albw ]] || { echo "build/albw not found: run ./build.sh first"; exit 1; }
[[ -f build/albw.ssmap ]] || echo "warning: build/albw.ssmap missing (save states will not load)"

# appimagetool (x86_64 runtime: the launcher runs natively, then starts the 32-bit game)
TOOLS=build/appimage-tools
TOOL=$TOOLS/appimagetool-x86_64.AppImage
if [[ ! -x $TOOL ]]; then
    mkdir -p $TOOLS
    echo "== downloading appimagetool"
    curl -fL --retry 3 -o $TOOL.part \
        https://github.com/AppImage/appimagetool/releases/download/continuous/appimagetool-x86_64.AppImage
    chmod +x $TOOL.part && mv $TOOL.part $TOOL
fi

# the start-up stub: the AppImage runtime that unpacks and runs where it cannot mount, as inside the
# container Steam starts games in (tools/build_appimage_runtime.sh, which builds it with podman / docker).
# Built here: used as it is. Else the published build is downloaded and checked.
RUNTIME=$TOOLS/runtime-x86_64
RUNTIME_URL=https://github.com/spacestate1/albw-native/releases/download/v0.2.19/albw-appimage-runtime-x86_64
RUNTIME_SHA256=7eba6aff6d7f0ffdadeb0c5bf892b2aac1e4f78a423abbead7df66ecd6872b08
RUNTIME_ARGS=()
if [[ ! -f $RUNTIME.key ]] && ! echo "$RUNTIME_SHA256  $RUNTIME" | sha256sum -c --status 2>/dev/null; then
    mkdir -p $TOOLS
    echo "== downloading the AppImage runtime"
    if curl -fL --retry 3 -o $RUNTIME.part "$RUNTIME_URL" && echo "$RUNTIME_SHA256  $RUNTIME.part" | sha256sum -c --status; then
        mv $RUNTIME.part $RUNTIME
    else
        rm -f $RUNTIME.part $RUNTIME
    fi
fi
if [[ -f $RUNTIME ]]; then
    RUNTIME_ARGS=(--runtime-file "$RUNTIME")
else
    echo "warning: using appimagetool's own runtime: the AppImage will not start from Steam without"
    echo "         the launch option APPIMAGE_EXTRACT_AND_RUN=1 %command%"
fi

# AppDir
APPDIR=build/AppDir
rm -rf "${APPDIR:?}"
mkdir -p $APPDIR/usr/bin $APPDIR/usr/lib
cp build/albw $APPDIR/usr/bin/albw
[[ -f build/albw.ssmap ]] && cp build/albw.ssmap $APPDIR/usr/bin/albw.ssmap

# bundled libraries: the exact files the build resolves (ldd), minus what must come from the system
bundle=(libSDL3.so.0 libz.so.1 libgcc_s.so.1)
for lib in "${bundle[@]}"; do
    path=$(ldd build/albw | awk -v l="$lib" '$1 == l {print $3}')
    if [[ -z $path || ! -f $path ]]; then
        echo "warning: $lib not resolved by ldd, not bundled"
        continue
    fi
    cp -L "$path" $APPDIR/usr/lib/$lib
done
# libraries SDL3 itself needs at load time (not dlopen'ed), except system ones
if [[ -f $APPDIR/usr/lib/libSDL3.so.0 ]]; then
    ldd $APPDIR/usr/lib/libSDL3.so.0 | awk '$3 ~ /^\// {print $1, $3}' | while read -r name path; do
        case $name in
            libc.so*|libm.so*|libdl.so*|libpthread.so*|librt.so*|ld-linux*|libgcc_s.so*) ;;
            *) [[ -f $APPDIR/usr/lib/$name ]] || cp -L "$path" $APPDIR/usr/lib/$name ;;
        esac
    done
fi

# fallbacks: 32-bit client libraries SDL3 loads at run time (X11, Wayland, keyboard, PulseAudio) and
# their dependencies. AppRun uses one only when the system has no 32-bit copy of it (SteamOS and other
# minimal systems); the system's own always wins. GPU drivers and glibc are never bundled.
lib32_find() {
    local d dirs=(/usr/lib32 /usr/lib/i386-linux-gnu /lib/i386-linux-gnu)
    [[ -d /usr/lib64 && ! -d /usr/lib32 ]] && dirs+=(/usr/lib)
    for d in "${dirs[@]}"; do [[ -f $d/$1 ]] && { echo "$d/$1"; return 0; }; done
    return 1
}
skip_lib() {
    case $1 in
        libc.so*|libm.so*|libdl.so*|libpthread.so*|librt.so*|ld-linux*|libgcc_s.so*|libresolv.so*) return 0 ;;
        libGL*|libEGL*|libGLX*|libGLdispatch*|libOpenGL*|libdrm*|libgbm*|libnvidia*|libvulkan*|libglapi*) return 0 ;;
        libSDL3.so*|libz.so*) return 0 ;;
    esac
    return 1
}
FB=$APPDIR/usr/lib/fallback
mkdir -p $FB
fallback=(libX11.so.6 libX11-xcb.so.1 libXext.so.6 libXcursor.so.1 libXi.so.6 libXrandr.so.2 libXfixes.so.3
          libXrender.so.1 libXss.so.1 libXinerama.so.1 libxcb.so.1 libXau.so.6 libXdmcp.so.6 libxkbcommon.so.0
          libwayland-client.so.0 libwayland-egl.so.1 libwayland-cursor.so.0 libdecor-0.so.0 libpulse.so.0
          libasound.so.2 libdbus-1.so.3)
nfb=0
for lib in "${fallback[@]}"; do
    path=$(lib32_find "$lib") || { echo "   (no 32-bit $lib here: not bundled)"; continue; }
    for dep in "$lib $path" $(ldd "$path" 2>/dev/null | awk '$3 ~ /^\// {print $1 "|" $3}'); do
        name=${dep%%[ |]*}; file=${dep##*[ |]}
        skip_lib "$name" && continue
        [[ -f $FB/$name ]] || { cp -L "$file" "$FB/$name"; nfb=$((nfb + 1)); }
    done
done
echo "== $nfb fallback libraries (used only where the system lacks them)"

cp packaging/appimage/AppRun $APPDIR/AppRun
[[ -f VERSION ]] && cp VERSION $APPDIR/VERSION
chmod +x $APPDIR/AppRun
cp packaging/appimage/albw-port.desktop $APPDIR/albw-port.desktop
cp packaging/appimage/albw-port.svg $APPDIR/albw-port.svg
ln -sf albw-port.svg $APPDIR/.DirIcon
mkdir -p $APPDIR/usr/share/applications $APPDIR/usr/share/icons/hicolor/scalable/apps
cp packaging/appimage/albw-port.desktop $APPDIR/usr/share/applications/
cp packaging/appimage/albw-port.svg $APPDIR/usr/share/icons/hicolor/scalable/apps/

echo "== bundled:"; ls -la $APPDIR/usr/bin $APPDIR/usr/lib | awk 'NF>=9 && $1 !~ /^d/ {print "   ", $5, $9}'

# appimagetool itself is an AppImage: extract-and-run works without FUSE (containers, CI)
mkdir -p "$(dirname "$OUT")"
ARCH=x86_64 APPIMAGE_EXTRACT_AND_RUN=1 $TOOL --no-appstream "${RUNTIME_ARGS[@]+"${RUNTIME_ARGS[@]}"}" $APPDIR "$OUT"
echo "== done: $OUT"
echo "   run: $OUT --rom /path/to/your/game.3ds   (the path is remembered afterwards)"
