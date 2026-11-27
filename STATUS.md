# Where the port stands

Last updated 2026-11-26 (release **v0.2.19**). Details of every fix:
[native/BOOT_LOG.md](native/BOOT_LOG.md).

## Releases

| Version | Date | Downloads | Notes |
|---|---|---|---|
| [v0.2.19](https://github.com/spacestate1/albw-native/releases/tag/v0.2.19) | 2026-11-26 | Linux AppImage, Windows zip (experimental) | **First Linux AppImage since v0.2.10.** **Single-screen mode:** the item selector takes each page's size as soon as the page appears; the Items page is recognised whatever it holds; the cursor stays on the bell button (BOOT_LOG 191) |
| [v0.2.18](https://github.com/spacestate1/albw-native/releases/tag/v0.2.18) | 2026-11-26 | Windows zip (experimental) | **Zoom out** the top screen, 100% to 200% (Esc > Video, PageDown / PageUp, Ctrl + wheel). **Windows: the occasional crash at start-up is fixed** (also in earlier versions; verified in the VM). Crashes fixed: a boss room (camera calls) and a heart pickup; two memory errors; float / integer mix-ups in the converted code; a save folder that cannot be used is reported (BOOT_LOG 182-190). Link's walking code and the projection matrix rewritten with named fields. Save states from earlier versions may not load |
| [v0.2.17](https://github.com/spacestate1/albw-native/releases/tag/v0.2.17) | 2026-11-26 | Windows zip (experimental) | **Windows: a save state loads after restarting the game** (it crashed); portable mode no longer fails with "cannot create the save directory" when started from a prompt at a drive root (both issue 6, verified in the VM). **Enemy and physics fixes**: lost vector and number returns (knockback, damage, velocities, four animation curves; Link could be left at an invalid position). Crashes and a black screen found by testing every room and enemy and by random play (BOOT_LOG 172-179). Esc > Debug: warp to a room, spawn an enemy. AYN Thor bottom panel (pull request #18, Linux ARM) |
| [v0.2.16](https://github.com/spacestate1/albw-native/releases/tag/v0.2.16) | 2026-11-25 | Windows zip (experimental) | **Windows: file reads from several game threads no longer mix up data** (verified in the VM; likely the start-up crash in issue 13). Crashes fixed: hookshot switch in the Swamp Palace, particle-effect sorting, a Swamp Palace enemy, painting strip in a from-scratch build; dropped sound names; pushable objects' height test. A wrong or cut-off ROM is reported and no longer remembered (issue 11). Faster graphics (pull request #17), 32-bit ARM source build (pull request #16, first part), matrix fixes (#15) |
| [v0.2.15](https://github.com/spacestate1/albw-native/releases/tag/v0.2.15) | 2026-11-25 | Windows zip (experimental) | **Fixes the Windows freeze after the file select** (issues 7, 10, 12, 13): the loader ignored thread-end destructors, so a finished game thread kept the scheduler's core for ever (verified in the VM with a self-test); the watchdog now lists who holds the core. Swamp Palace fog from room entry; 13 more literal-pool write crashes removed; **game language** (Esc > File > Language, layout.cfg, follows the computer's language; issue 14). See ISSUES_TRIAGE.md |
| [v0.2.14](https://github.com/spacestate1/albw-native/releases/tag/v0.2.14) | 2026-11-24 | Windows zip (experimental) | Fire / Tornado Rod cones and rings are drawn (they were skipped or came out as huge shards); no more green HUD / pause screen in the Swamp Palace (fog was applied to the layout panes); a crash (write to a read-only table in `func_0046019C`) is fixed. Not fixed: the Swamp Palace fog only appears after the first sword swing |
| [v0.2.13](https://github.com/spacestate1/albw-native/releases/tag/v0.2.13) | 2026-11-24 | Windows zip (experimental) | **Texture packs** (Citra / Azahar format, issues 1 and 4): the pack is found by the game's own texture hash; `ALBW.exe` finds the `texture-pack` folder next to it. Windows: `ALBW.exe` waits for the game it starts and passes its exit code on. Esc > File > Save set lists the sets on Windows. Single-screen mode: "Press A or Enter to start" on the title (the prompt is on the hidden bottom screen), and the file list shows once it is up |
| [v0.2.11](https://github.com/spacestate1/albw-native/releases/tag/v0.2.11) | 2026-11-23 | Windows zip (experimental) | **Windows: the freeze after `audio: SDL3 'wasapi'` (issue 7) found and fixed in a Windows 10 VM.** The game unlocked a C++ static-init lock from a thread that did not hold it; on real Windows that corrupts the loader's SRW lock and every thread waits for ever (Wine tolerates it). Mutexes / condition variables rewritten; boot watchdog in `albw.log`; log next to `ALBW.exe`; a `.3ds` in `roms\` is found by itself. No Linux change (use the v0.2.10 AppImage). Not yet confirmed on a real GPU |
| [v0.2.10](https://github.com/spacestate1/albw-native/releases/tag/v0.2.10) | 2026-11-22 | Linux AppImage, Windows zip (experimental) | **Steam Deck Game Mode now starts (issue 8, reported fixed).** The SDL3 inside the AppImage had been built without its X11 backend (the release container lacked the 32-bit X11 `-dev` packages), so it said `SDL_Init: x11 not available` everywhere except pure Wayland; `tools/make_release_appimage.sh` now installs them and fails if SDL has no X11. Windows zip unchanged |
| [v0.2.9](https://github.com/spacestate1/albw-native/releases/tag/v0.2.9) | 2026-11-22 | Linux AppImage, Windows zip (experimental) | **Windows: v0.2.7 / v0.2.8 did not start** ("needs 5 functions this loader does not provide", issue 10): the loader now provides `setenv putenv freopen setvbuf strncat`; the memory-clash error names the blocker; portable mode keeps saves in `albw-data` too |
| [v0.2.8](https://github.com/spacestate1/albw-native/releases/tag/v0.2.8) | 2026-11-22 | Linux AppImage, Windows zip (experimental) | Esc > File > Save set: switch between folders of save files (speed runs), with a backup |
| [v0.2.7](https://github.com/spacestate1/albw-native/releases/tag/v0.2.7) | 2026-11-22 | Linux AppImage, Windows zip (experimental) | Esc menu: Help (copy log, open log folder, report a problem), About (version, build time), Debug > Logging; version in the AppImage file name (issue 9); error dialogs copy the log |
| [v0.2.6](https://github.com/spacestate1/albw-native/releases/tag/v0.2.6) | 2026-11-21 | Linux AppImage, Windows zip (experimental) | Steam Deck Game Mode launch fixes (issue 8, untested on a Deck); Windows: error and log boxes, software-renderer warning, `--software-gl` / `--console`, retry on memory clash (issue 7, untested on real Windows); NVIDIA hybrid GPU; portable mode |
| [v0.2.5](https://github.com/spacestate1/albw-native/releases/tag/v0.2.5) | 2026-11-21 | Linux AppImage, Windows zip (experimental) | merged Link no longer stuck at corner edges; crash past corners fixed |
| [v0.2.4](https://github.com/spacestate1/albw-native/releases/tag/v0.2.4) | 2026-11-21 | Linux AppImage, Windows zip (experimental) | merged camera at corners, corner wall search, float-bit tests (10 functions) |
| [v0.2.3](https://github.com/spacestate1/albw-native/releases/tag/v0.2.3) | 2026-11-21 | Linux AppImage, Windows zip (experimental) | merged-wall camera and crash at wall ends, dungeon map cursor, effect sort, stub review |
| [v0.2.2](https://github.com/spacestate1/albw-native/releases/tag/v0.2.2) | 2026-11-20 | Linux AppImage, Windows zip (experimental) | bell warp crash, bell selectable in single-screen mode, x87 stack guard |
| [v0.2.1](https://github.com/spacestate1/albw-native/releases/tag/v0.2.1) | 2026-11-20 | Linux AppImage, Windows zip (experimental) | Windows build added; same Linux game as v0.2.0 |
| [v0.2.0](https://github.com/spacestate1/albw-native/releases/tag/v0.2.0) | 2026-11-20 | Linux AppImage | Eastern Palace boss, wall merging, square glows fixed |
| [v0.1.0](https://github.com/spacestate1/albw-native/releases/tag/v0.1.0) | 2026-11-19 | – | first tagged build |

Needs the decrypted European ROM:
`0487 - Legend of Zelda, The - A Link Between Worlds (Europe) (En,Fr,De,Es,It) Decrypted.3ds`
(748,580,864 bytes, SHA-1 `4d2da91fa0edef9eef07e471527461396cc3faf2`). USA / Japan: not supported
(the code is tied to EU addresses; supporting USA would take weeks: a data-address map, the
differing functions and every address in `native/`).

## What works

- Boot, title, file select, in-game saving and loading; save states (F6 / F7) that survive updates.
- The early story, the overworld, houses, items, enemies, combat, game over.
- **Eastern Palace and its boss (Yuga)**: he flies into the walls, travels along them as a
  painting when Link moves around, comes out, raises the frames and barrier, summons soldiers.
- **Wall merging** (Link): the 2D painting is drawn, walks left and right, wraps corners, stops at
  wall ends, steps out with A. How it works: [native/PAINTING.md](native/PAINTING.md).
- Pits: enemies knocked into them fall and die.
- Particle glows are soft again (they were solid squares in states from older builds).
- Single-screen mode (F9): the file select shows the save list; long cutscenes no longer flip to
  the map; Tab / right-stick click flips screens; D-pad + A on the bottom screen.
- Late-game saves load (Death Mountain, Lorule).
- Language: `ALBW_LANGUAGE=1..5` (1 English, 2 French, 3 German, 4 Italian, 5 Spanish; default 1).

## Recent work (2026-11-19 / 20)

| Entry | What |
|---|---|
| 160am | Ubuntu first-frame crash; warp-hole crash (ARM member-function pointers) |
| 160an | Armos stuck mid-fall (a "grounded" test returned its argument) |
| 160ao / 160at | single-screen: save list at the file select; no map flips in cutscenes |
| 160ap / 160aq | save states keep loading after a relink |
| 160ar / 160as | Yuga's fight starts (wall path, walker reads, wall slice, double sqrt cast) |
| 160av | model bounding spheres stored as values (radius 1.3 became 1) |
| 160aw | wall painting drawn: segment-length test, strip reset flag, runtime GPU command blocks, multi-buffer vertex layouts, painting draw item (matrix as uniform op, texture bound after load), left / right direction |
| 160ax | square particle lights: stale effect texture blocks in old states repaired on load |
| 160ay | painting visibility test got its draw-layer argument (stayed hidden in some sessions) |
| 160az | Windows build (below) |
| 160ba | single-screen: the bell (map page) is selectable; x87 stack guard no longer misses a full stack (NaN floats after a leak) |
| 160bb | crash after a bell warp (bone name "Head" passed as an address); same bug fixed for "Melt" |

## Windows build (experimental)

`windows/build_windows.sh` (run on Linux) → `build/ALBW-windows.zip`. `ALBW.exe` loads the Linux
i386 program like Linux's own loader would and gives it Windows versions of the C library, pthread
and POSIX calls; SDL3.dll; a bundled Mesa OpenGL fallback. Details: [windows/README.md](windows/README.md).

- Tested under Wine 11: title, file select, saves, audio (WASAPI), controllers, GPU and Mesa paths.
- **Not tested on real Windows hardware.** Under Wine it gets slow once many objects are drawn
  (1–2 fps at the file select's 3D preview; probably Wine's 32-bit OpenGL bridge). Needs a report
  from a real Windows PC.
- Save states do not move between the Linux and Windows builds; in-game saves do.
- **Tested in a Windows 10 VM (no GPU, KVM)**, which reproduced issue 7 (two "Not Responding" windows).
  Found and fixed in `windows/loader.c` (not yet released):
  - `__cxa_guard_release` unlocks the static-init lock from a thread that does not hold it. On real
    Windows that corrupts an SRWLOCK (a locked lock with no owner, threads wait for ever: the freeze after
    `audio: SDL3 'wasapi'`); Wine tolerates it. Mutexes and condition variables are now a
    WaitOnAddress lock that survives a stray unlock; the first one is logged.
  - A boot watchdog logs every thread's position (game function or DLL+offset) at 4 / 8 / 16 / 32 / 62 / 122 s.
  - The log is `albw.log` next to `ALBW.exe`, unbuffered; a `.3ds` / `.cci` next to `ALBW.exe` or in
    `roms\` is used when no ROM path is saved.
  - Without a GPU driver Mesa picks Direct3D 12 / WARP, whose C++ exceptions end the process; when DXGI
    lists no real adapter (only Microsoft's WARP / Basic Render Driver, vendor 0x1414) the software
    fallback uses softpipe (slow; llvmpipe gave "No matching GL pixel format" there). With a real adapter
    Mesa keeps Direct3D 12 on the GPU (fast; the `--software-gl` workaround for broken OpenGL drivers).
  - Released as v0.2.11. Not confirmed on a real GPU yet. In the VM (softpipe) the game also died once after
    about 9 minutes: 0xc000041d (fatal user callback exception) on a thread running in unmapped memory;
    cause unknown (dump kept in the VM only). Open: the WARP crash itself (`_com_error` while the game runs on
    its own stacks, FAST_FAIL_INVALID_EXCEPTION_CHAIN); a faster software renderer for no-GPU PCs.
  - After v0.2.11 (not released yet): issue 10 reported "cannot reserve memory ... apphelp.dll" on the first start
    and success on the second (Windows loads apphelp.dll, the compatibility shim, into a program it has not seen;
    a system DLL keeps its address until reboot, so the 12 relaunches did not help). Now `ALBW.exe` starts a copy of
    itself suspended, reserves the fixed ranges in it with `VirtualAllocEx` (only ntdll is mapped then), and
    resumes it (`launch_reserved`; log line "memory ranges: reserved by the launcher"); the old in-process path,
    plus unloading `apphelp.dll`, stays as the fallback (`ALBW_NO_LAUNCHER=1` forces it). `NvOptimusEnablement` and
    `AmdPowerXpressRequestHighPerformance` are exported so hybrid-GPU laptops run system OpenGL on the discrete GPU.
    Checked in the VM only. Also reported on #10: black screen after confirming the name, then a crash (RTX 5070 Ti,
    system OpenGL): no log yet.

## Texture packs (issues 1 and 4)

Citra / Azahar-format replacement textures work (`native/render/texpack.c`, `cityhash.c`; hook in `tex_upload`,
`render.c`). A texture is found by `tex1_<w>x<h>_<CityHash64 of its raw bytes>_<PICA format>_mip0.png` (the new hash,
`"use_new_hash": true`; old-hash packs are refused with a log line). Checked against Henriko Magnifico's ALBW 4K pack
(1080p and 4K versions): the hash code matches Azahar's CityHash on random data for every length up to 70000, the
title screen logo and intro paintings are replaced and upright (rows flipped for `flip_png_files`), 54 of the
title/intro textures are found on Linux, the same hashes come out on 32-bit Windows (VM), where the loader finds
the pack folder under `texture-pack\` by itself (`find_pack_dir`). Mip levels are generated; a replacement larger
than `GL_MAX_TEXTURE_SIZE` is skipped. Not done: textures the game draws at run time (as in Citra), old-hash packs,
stereoscopic 3D (issue 1), a memory budget for the 4K pack (about 1.9 GB of RGBA if every texture were loaded),
and PNG decoding is on the render thread (a large texture can hitch the first time it appears). Gameplay beyond the
title and intro not looked at yet.

## Open issues

| # | Issue | Needs |
|---|---|---|
| 1 | Dust effect when Link first leaves his house | a save state at the house door |
| 2 | Graveyard: enemies / meshes visible through gravestones | a save state in the graveyard |
| 4 | Rods (fire, ice, tornado, sand) on bushes | a save state near bushes with the rods |
| 10 | Winning the Yuga fight and the scenes after it (video ref. from 9:00) | a state late in the fight |
| 12 | Slot 4 event close-up shows a magnified quarter view | a state right before the close-up |
| – | The sage's large pink aura (boss cutscene) is faint | – |
| – | (fixed in master, BOOT_LOG 165) Swamp Palace: fog (mint green) was missing until the first sword swing | – |
| – | Fire / Tornado Rod cones and rings: drawn since v0.2.14 (mesh arrays bound; Fire Rod and the Yuga intro checked against the old build, Tornado Rod not seen yet); `ALBW_EFT_PRIM_SKIP=1` skips them as before. The Fire Rod ball is still dark olive instead of orange | a Tornado Rod save |
| – | Windows: speed on real hardware unknown | a Windows tester |
| – | Most dungeons after the Eastern Palace untested | play-testing |
| 14 | Slot 2 Zora's River crash (Shady Guy scene): not reproduced after the x87 fix | a report if it comes back |
| 18 | Merge camera: wall ends (160be) and corners (160bg) fixed; the slot 6 doorway wrap still to re-check | – |
| 19 | Terrain drawn as dark mud with blue tiles (screenshots/world-error.png) | a save state there |
| – | Sanitizer build: runs the castle route clean (160bd); cannot load save states from the normal build | routes from boot to more areas |

Not bugs, but old save states: states saved by older builds can carry stale data (e.g. the
"Nāy" A-button label after merging in slot 6); playing from an in-game save fixes it.

## Working notes

- **Check a release before publishing it.** Two shipped bugs came from never running the real package:
  v0.2.7's Windows loader lacked 5 libc functions the game imports (compare the game's undefined
  symbols with the loader table: `readelf --dyn-syms -W build/win/albw`), and every AppImage up to
  v0.2.9 carried an SDL3 without X11. For the second one, run the extracted AppImage on an X11
  display: `DISPLAY=:1 SDL_VIDEO_DRIVER=x11 LD_LIBRARY_PATH=<extract>/usr/lib <extract>/usr/bin/albw`.
- **Reproducing Steam Deck Game Mode without a Deck:** an Arch Linux container (`podman`, SteamOS is
  Arch) with `[multilib]` enabled, `xorg-xwayland` and `lib32-mesa lib32-libx11 ...`, running the
  extracted AppImage with `GAMESCOPE_WAYLAND_DISPLAY` set against a plain Xwayland. gamescope itself
  crashes in a container without a real GPU, but the SDL failure shows without it.

- **Build:** `./build.sh` (first time with the ROM path). Relink only:
  `ALBW_FCONV_INTERIM=0 ALBW_JOBS=2 tools/link.sh`.
- **Experiments go to a separate binary:** `ALBW_LINK_OUT=build/albw-dbg tools/link.sh`. The player
  runs `build/albw`; relinking it mid-session makes states saved meanwhile depend on a build that
  disappears (slot 5 was lost that way: states taken inside a function whose code changed cannot
  load).
- **Save-state compatibility:** avoid changing functions that threads park in (the thread start `0067628C`, `sdk/h3d.c`
  `dec_finish` / `dec_write`, `platform.c` `plat_end_frame`) unless needed.
- **Machine limits:** 13 GB RAM (about 10 GB free while idle), 8 cores; builds with `ALBW_JOBS=2`; one game or gdb run at a time.
- **Test harness:** `ALBW_ROUTE="at 60;load N;..."` (`load` is 0-based: user slot N = `load N-1`),
  `SDL_VIDEO_DRIVER=offscreen`, `ALBW_SHOT=<frames>` + `ALBW_SHOT_DIR`, `ALBW_KEEP_AFTER_SCANOUT=1`.
  Castle route to a wall merge: `ALBW_PRESS='1800:START,2200:A,2700:A'` and
  `ALBW_ROUTE="at 3300;scene DungeonEast 1 0;wait 300;goto -6 -4.0 0.3;hold CUP 60;wait 10;press A 6"`.
- **Debug switches added recently:** `ALBW_WALK_TRACE`, `ALBW_CALLX_TRACE`, `ALBW_TEXWORD_TRACE`,
  `ALBW_PASS_TRACE`, `ALBW_SKIP_TEX=<hex>`, `ALBW_SKIP_EFT`, `ALBW_SKIP_DRAW`, `ALBW_H3D_CALL_TRACE`.
- **Releases:** `tools/make_release_appimage.sh` (podman, Ubuntu 22.04 container) and
  `windows/build_windows.sh`; tag, then `gh release create`.

## Next steps

1. Get the Windows build run on a real Windows PC; fix what shows up (speed first).
2. The open issues above, as save states for them arrive.
3. Finish and verify the Yuga fight's ending and the scenes after it; then the next dungeons.
