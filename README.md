# A Link Between Worlds – native PC port

A native build of *The Legend of Zelda: A Link Between Worlds* (Nintendo 3DS) for Linux, made from
decompiled game code (based on [albw-decomp-ai](https://github.com/7akeem0/albw-decomp-ai): see
[Credits](#credits)). The game logic runs as real C on your PC; graphics, sound, input and files
are rewritten with SDL3 + OpenGL. No emulator.

<p align="center"><img src="docs/screenshots/title.png" alt="Title screen running in the port (top and bottom screen)" width="400"></p>

**Work in progress.** Playable through large parts of the story; expect bugs. See [Status](#status).

## You need your own game

No game data is included: no ROM, keys, assets or saves. You need a **decrypted dump of the
European release** that you made yourself:

```
0487 - Legend of Zelda, The - A Link Between Worlds (Europe) (En,Fr,De,Es,It) Decrypted.3ds
```

| | |
|---|---|
| Size | 748,580,864 bytes |
| SHA-1 | `4d2da91fa0edef9eef07e471527461396cc3faf2` |
| `.code` SHA-1 (what the build checks) | `2aeee593a695f2ce1196b844026567f227472f0b` |

The file name itself does not matter (a renamed file works); the contents must match. The USA and
Japanese releases do not work: the decompiled code is tied to the European release's addresses.

## Play

### Linux: download (easiest)

1. Download `ALBW-native-v<version>-x86_64.AppImage` from the [latest release](https://github.com/spacestate1/albw-native/releases/latest).
2. `chmod +x ALBW-native-*.AppImage`
3. `./ALBW-native-*.AppImage --rom /path/to/your/game.3ds` (the path is remembered; started
   from a file manager, it asks with a file dialog).

Runs on Ubuntu 22.04 / 24.04, Debian 12+, Fedora, Arch, SteamOS and similar (x86-64). It needs the
system's 32-bit C library and OpenGL driver; if they are missing, it tells you what to install.
No FUSE? Add `--appimage-extract-and-run`.

### Linux: build from source

```
git clone https://github.com/spacestate1/albw-native.git
cd albw-native
./build.sh /path/to/your/game.3ds
./run.sh
```

`build.sh` installs what it needs (asks for sudo), reads the game code from your ROM and compiles
(the first build takes a while: about 26,000 files). Fedora, Ubuntu, Mint, Debian, Arch (enable
`[multilib]`), openSUSE; it needs clang 19 or newer (installed automatically where the distribution
has it; Ubuntu 22.04 / Mint 21: get one from [apt.llvm.org](https://apt.llvm.org)). Rebuild later
with `./build.sh`.

### Steam Deck

In desktop mode, `./build.sh /path/to/game.3ds` builds inside distrobox and makes
`build/ALBW-native-x86_64.AppImage` (or copy the release AppImage over). Add it to Steam as a
non-Steam game to play in Game Mode (needs release v0.2.19 or newer: older AppImages could not start under
X11/XWayland, or inside the container of a "Steam Linux Runtime" compatibility setting, where they said
"Cannot mount AppImage"; if a v0.2.19 download says that, download it again). With an older one, set the
shortcut's Launch Options to `APPIMAGE_EXTRACT_AND_RUN=1 %command%` or turn the compatibility tool off.
L3+R3 opens the game's menu.

### ARM Linux (32-bit ARM build, AYN Thor)

The game code keeps the 3DS's 32-bit memory layout, so on ARM it is built as a 32-bit ARM program
(ARMv8 in AArch32). It runs on 64-bit ARM Linux systems whose CPU and kernel run 32-bit programs (the
AYN Thor under Armada: cores 0-2 and 5-6, `allow_mismatched_32bit_el0`). Build it on a 32-bit ARM
system or container (Arch Linux ARM armv7: `clang lld llvm python sdl3 mesa libglvnd`), then
`python3 tools/build_decomp.py --snapshot decomp --arch armhf` and `ALBW_ARCH=armhf tools/link.sh`.
`tools/make_armhf_bundle.sh` packs the program with its own loader and libraries
(`build/albw-armhf.tar.gz`). Start it with `albw.sh --rom /path/to/game.3ds`.

In Armada's Game Mode the top screen fills the display and the bottom screen goes on the Thor's
bottom panel (leased from gamescope), with its touchscreen. `ALBW_DRM_LEASE=<connector>|auto` and
`ALBW_TOUCH_DEVICE=/dev/input/eventN` set this by hand. `albw.sh` sets both from Armada's device
profile.

### Windows (experimental)

`windows/build_windows.sh`, run on Linux after a normal build, makes `build/ALBW-windows.zip`:
unzip it on Windows, start `ALBW.exe` and choose your `.3ds`. It reaches the title and file select
under Wine but is not tested on real Windows hardware yet. How it works: [windows/README.md](windows/README.md).

## Controls

Keyboard (rebind anything in Esc > Controls); controllers work too, with the buttons where they
are on a 3DS.

| 3DS | Key | | 3DS | Key |
|---|---|---|---|---|
| Circle pad | arrow keys | | L / R | Q / W |
| A | X | | Start | Enter |
| B | Z | | Select | Backspace |
| X | S | | D-pad | I J K L |
| Y | A | | Touch screen | mouse on the bottom screen |

| Key | Action |
|---|---|
| Esc (controller: L3+R3 or Guide) | menu: window, layout, controls, save states, reset game, quit |
| F5 | one window or two windows |
| F6 / F7 | save state / load state |
| F9 | single-screen mode on / off |
| F10 | widescreen top screen (a wider view, not stretched) |
| PageDown / PageUp | zoom out / back in: the top screen shows more of the world (also Ctrl + mouse wheel, and the slider in Esc > Video) |
| F12 | screenshot |

### Single-screen mode

One window shows one screen at a time – handy on a laptop, TV or the Steam Deck. Turn it on with
**F9** (or Esc > Video).

- The top screen (the game) is shown; **Tab** (controller: right-stick click) flips to the bottom
  screen and back.
- **Start** brings up the bottom screen (map, Gear, Items); **Select** opens the game's pause menu.
- On the bottom screen the **D-pad** moves a selector between buttons and items and **A** taps the
  selected one – no mouse needed.
- At the file select the save list (bottom screen) is shown by itself; the game switches back to
  the top screen when you start playing.

Saves and save states live in `~/.local/share/albw-port/`, settings in `~/.config/albw-port/`.

### Language

The European game has English, French, German, Italian and Spanish text, all in your ROM. By default the game follows
your computer's language (English for any other). To choose: Esc > **File** > **Language**, then File > **Reset game**
(the text loads at start-up). The same setting is the `language` line in `layout.cfg` (`system`, `en`, `fr`, `de`, `it`,
`es`); `ALBW_LANGUAGE=<fr|de|it|es|en or a 3DS code 0-11>` overrides it.

**Portable mode:** create a folder named `albw-data` next to the AppImage (or the program) and
everything – saves, save states, settings, screenshots, logs – is kept in it. Or start with
`ALBW_DATA_DIR=/any/folder`.

**Laptops with NVIDIA + Intel / AMD graphics:** the game picks the NVIDIA GPU by itself (it needs the
32-bit NVIDIA OpenGL library: Arch `lib32-nvidia-utils`, Ubuntu / Debian `libnvidia-gl-<version>:i386`).
`ALBW_GPU=integrated` keeps the built-in GPU.

## Texture packs

Replacement textures in the Citra / Azahar format work, for example
[Henriko Magnifico's 4K pack](https://www.henrikomagnifico.com/zelda-a-link-between-worlds-4k). Put the pack in
`~/.local/share/albw-port/texture-pack/` (Windows: a `texture-pack` folder next to `ALBW.exe`), or point
`ALBW_TEXTURE_PACK=<folder>` at it. The folder is the one with the `tex1_..._mip0.png` files, or any folder above it
(the pack zip's `user/load/textures/00040000000EC300`). The pack must use the new hash (`"use_new_hash": true` in its
`pack.json`; the 4K pack does). `ALBW_TEXPACK_LOG=1` prints every lookup. A 4K pack needs a lot of video memory; the
1080p version is much lighter. `ALBW_TEXPACK_MAX=2048` (or 1024) shrinks the replacement textures to that size for
GPUs with little memory. Textures drawn by the game at run time are not replaced (as in Citra). Stereoscopic 3D
(issue 1) is not part of this.

## Save sets (speed runs)

Keep several sets of save files and switch between them in the game. Make a folder `save-sets` next
to the game's `save` folder (`~/.local/share/albw-port/save-sets`) and put one folder per set in it
(for example `Hyrule`, `TurtleLCastle`), each holding `Save_0.bin` to `Save_2.bin` and
`SaveCommon.bin`. In the game press Esc > **File** > **Save set** to pick one, then **Load this save
set** (press it twice). The current save files are backed up to `save-backup/<time>/` (only when they
differ from the set), the set is copied in and the game restarts, so every attempt starts from the
same files.

## Debug tools

Esc > **Debug** has the port's own test tools (the retail game has no debug menu):

- **Warp**: pick an area and a room, then **Warp there**. Link appears at the room's first entry point.
- **Enemy**: pick one of the enemies the current room has the data for, then **Spawn it next to Link**.
- Logging, particles, fog, frame rate in the title bar and game speed.

Warping and spawning can leave the story in an odd state: make a save state (F6) first, and do not
save the game afterwards on a file you care about.

## Reporting a problem

Press Esc in the game, then **Help > Copy log to clipboard** and paste it (Ctrl+V) into a new
[issue](https://github.com/spacestate1/albw-native/issues/new). If the game stops with an error
before a window opens, the AppImage shows the end of the log in a dialog (and copies it where
`wl-copy` / `xclip` exist); on Windows the log is copied to the clipboard by itself. The log file:
`~/.local/state/albw-port/last-run.log` (AppImage, when not started from a terminal) or
`albw.log` (Windows). In Steam Game Mode, read the file from Desktop Mode. The log has no ROM data.

## Status

Working: boot, title, file select, saving and loading; the story's first areas, the overworld,
houses, items, enemies, combat; the Eastern Palace and its boss (Yuga, wall merging as a
painting); late-game saves load (Death Mountain, Lorule).

Known problems: the Fire / Tornado Rod effects were drawn wrongly or skipped until v0.2.14 (Fire Rod checked, Tornado Rod not yet); some effects and cutscenes
are still wrong; most dungeons after the Eastern Palace are untested. Full list:
[MISSING.md](MISSING.md). Please report what you find.

## How it works (short)

- `decomp/` – the decompiled game code, converted so it compiles natively.
- `native/` – written by hand: window, input, audio, the renderer, replacements for the 3DS system
  libraries, and fixes for decompiled functions (`native/compilefix/`, each with a note).
- `windows/` – the Windows loader.
- The game's data is read from your ROM at build time and never stored in the repository.

Notes: [native/BOOT_LOG.md](native/BOOT_LOG.md) (every bug and its fix),
[native/PAINTING.md](native/PAINTING.md) (wall merging step by step),
[native/DIDNT_WORK.md](native/DIDNT_WORK.md) (what was tried and failed).

Rules: no emulation (no CPU interpreter or recompiler, no GPU or OS emulation; 3DS library calls are
replaced function by function), hand-written GLSL shaders, no game data in the repository.

## Credits

Built on **[albw-decomp-ai](https://github.com/7akeem0/albw-decomp-ai)** by
**[7akeem0](https://github.com/7akeem0)** and contributors, the matching decompilation of
*A Link Between Worlds*: its matched sources (about 16,000 functions), address map and headers are
the base of the game code here (`decomp/` is a snapshot of them). Thanks also to
**[matthis](https://github.com/mmaupas/albw-decomp-ai)** for the decomp's automation tools, shared
headers and many matches. Unmatched functions come from [Ghidra](https://github.com/NationalSecurityAgency/ghidra)
output. Windowing, input and audio use [SDL3](https://www.libsdl.org/).

## License

The port's own code (`native/`, `tools/`, `windows/`, scripts) is MIT: see [LICENSE](LICENSE). It
does not cover the game or its data. The decompiled sources in `decomp/` come from albw-decomp-ai
(and Ghidra); that project has no license file yet, so the MIT license does not cover them.

## Legal

A fan project for preservation and study, not affiliated with or endorsed by Nintendo. *The Legend
of Zelda* and *A Link Between Worlds* are trademarks of Nintendo. You must own the game and dump it
yourself; do not ask for ROMs or keys.
