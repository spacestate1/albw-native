# Issue triage

What each GitHub issue is, what the evidence says, and what was done. Newest work at the top of each entry.
Updated as issues are worked through. (Status: **fixed in master** = in the repository, not yet in a release.)

Last updated: 2026-11-26. Pull requests: #15 merged; #16 first commit (ARM build) merged, Thor panel commits held (GPL-derived code in an MIT part); #17 (specialised fragment programs) merged; #16 closed by its author and resent without GPL code as #18 (AYN Thor bottom panel), merged (excluded from the Windows build). Issue numbers are those of github.com/spacestate1/albw-native.

## Summary

| # | Title | Kind | Status |
|---|---|---|---|
| 14 | No way to choose the game language | feature | closed 2026-11-26 (in v0.2.15 and later: Esc > File > Language, `language` line in layout.cfg, follows the computer's language) |
| 13 | Game won't start (two reports: crash, freeze) | Windows hang / crash | closed by the reporter 2026-11-26 (their copy of the game); the freeze fix is in v0.2.15 |
| 12 | Crash after file selection screen | Windows hang | closed 2026-11-26: the reporter confirms the fix works (same cause as 13 / 10 / 7, in v0.2.15) |
| 11 | Steam Deck AppImage will not open after failed .3ds import | Linux | **fixed in master**: a file the game cannot use is forgotten, with a clear message |
| 10 | Black screen after naming the file, Windows | Windows hang | same cause; fixed in master (waiting for a confirming log) |
| 9 | Version number in the AppImage | request | closed |
| 8 | Cannot start from Game Mode (SteamOS) | closed | closed |
| 7 | Cannot start the game (Windows, freeze at boot) | Windows | closed 2026-11-26: the reporter can play (boot freeze fixed in v0.2.11, the later freeze in v0.2.15) |
| 6 | Launcher and portable installation | request | portable mode done (v0.2.7); two Windows faults reported with it fixed in v0.2.17 (below); launcher window not built |
| 5 | Port does not use the dGPU on Linux | closed | closed |
| 4 | Texture pack support | request | closed 2026-11-26: done in v0.2.13 (needs a pack with the new hash) |
| 3 | 120+ FPS | request | not started |
| 2 | ARM64 Linux build | request | 32-bit ARM (armhf) build merged from pull request #16 and the AYN Thor panel from #18 (not tested on ARM by us) |
| 1 | Stereoscopic 3D with texture packs | request | not started |

## Old save states after an update

A save state (F6) holds the program's own stacks, so an update that changes those functions cannot load it ("... was
running and changed in this build"). This happened with v0.2.15. Game saves (the in-game save) are not affected. To
recover: start the version that made the state (the previous release; locally `build/albw-oldstates`), load it (F7), save
in the game, then continue from that save in the new version.

v0.2.18 refuses v0.2.17 states in the same way: it builds the hand-fixed decompiled code with other compiler flags
(BOOT_LOG 182), so those functions all changed. Tried on Linux with two states: refused with the message above, and the
game carried on.

## The Windows freeze family (issues 7, 10, 12, 13)

**Reports.** Windows 10/11, NVIDIA RTX 3050/4060/5070 Ti, AMD RX 550/6600/9070 XT: the game starts, shows the title and the
file select, and after a file is chosen (some reports: after about a minute of play) the window goes black / "not
responding". albw.log from #10 (v0.2.13), #12 (v0.2.14) and #13 (v0.2.14) show the same picture at the watchdog sample:

- the window thread is fine until the game stops answering; "NOT RESPONDING" first at 62 s (#10, #13) or 122 s (#12);
- the game's main thread waits in `sched_acquire` (called from `plat_end_frame`): it wants the application core back
  after presenting a frame;
- every other game thread is in `arb_wait` (a CriticalSection / light event), or asleep in `sleep_ns`; none is running.

**Cause (found 2026-11-25).** The game threads are scheduled one at a time per core (native/sdk/os.c, app-core
scheduling): a running thread owns a token, handed on when it blocks or ends. A thread's end runs a pthread key destructor
(`thread_finished`) that gives the token back. The Windows loader's `pthread_key_create` ignored the destructor
(`FlsAlloc(NULL)`), so on Windows a game thread that finished kept the token for ever and all the others waited. This
matches the freeze arriving when the game loads the save (loader threads end), and it is why Linux (glibc runs key
destructors) and Wine under light use looked fine.

**Fix.** `windows/loader.c`: `lx_key_create` now passes an FLS callback per key that calls the game's destructor on thread
exit (24 keys). Also added: `albw_sched_dump` (native/sdk/os.c), printed by the watchdog when a window stops responding:
which game thread holds each core, the ready lists, and every thread's state, so a remaining freeze can be told apart.

**Verified in the Windows 10 VM (2026-11-25).** Self-test `ALBW_SELFTEST_THREAD=1` (native/sdk/os.c: start a game thread that
ends at once, then sleep): with the fixed loader the main thread gets its core back ("OK"); with the old loader (same game
program, `FlsAlloc(NULL)`) the dump shows the ended thread still RUNNING on core 0 and the main thread "ready" for ever,
which is the user logs' picture. (The first fixed build also had a bug of its own, caught in the VM: the new dump needed
`pthread_mutex_trylock`, which the loader lacked; and running the C runtime's own key destructors killed the game at
boot, so only the game's `thread_finished` destructor is run.)

**To confirm.** A user log from the next Windows build. If a freeze remains, the new "albw: sched:" lines show who holds the
core.

## #13 second report: crash in `func_001E06D0` (user vi7ual, v0.2.14, RTX 4060)

`CRASH 0xc0000005 at func_001E06D0+0x317`, eax 0x54, edi 0, right after the audio start-up line (before the renderer is
ready). The code: `edi = func_001E1228(param_1, &local, 0)` returned NULL, then `[edi+0x58]` is read. `func_001E1228` is the
resource-slot allocator used while loading an `Archive/<name>` entry (it fills a record from a pool / heap); NULL means the
pool or heap could not give one. Not reproduced. Possibly the same family (a thread-ordering problem on Windows, where the
scheduler token was never returned) or a memory-range problem on that PC. Open; check again after the thread-exit fix.

## Reports after v0.2.15

- #7 (toxicground, RX 9070 XT): "now finally i can play the game". The thread-exit fix is confirmed on a real PC.
- #13 (NEONZARIN, RX 550): v0.2.15 works with `--system-gl`; saving and loading work. Reports low frame rates and input lag
  at 3x resolution, and unexplained crashes. PR #17 lowers GPU load (below); a log is needed for the crashes.
- #13 (vi7ual, RTX 4060): the same start-up crash in `func_001E06D0` on v0.2.15. Likely cause found: the loader's `pread`
  was lseek + read on the one ROM descriptor, so game threads loading at once could get each other's data (BOOT_LOG 168).
  Now one operation; the failed load also names the archive, and a cut-off dump is reported. **Verified in the Windows VM**
  (`ALBW_SELFTEST_PREAD=1`, four threads reading the ROM at once): old loader 7272 of 16000 reads wrong, new loader 0.
  Not yet confirmed by the user.

## #6: portable mode and save states on Windows (NEONZARIN, 2026-11-26, v0.2.16)

- **Crash loading a save state after a restart** (`ss_park`). Cause: the Windows build emulates thread-local
  variables, whose addresses differ in every run, and a state holds such addresses on the saved stacks. The game
  threads' variables now sit at fixed addresses (native/sdk/os.c `slot_pin_tls`). Verified in the Windows 10 VM:
  v0.2.16 crashes on the load, the fixed build loads the state of the earlier run and saves and loads again. States
  saved with earlier Windows builds still cannot be loaded after a restart.
- **"cannot create the save directory (Permission denied)"** when started from a command prompt (their screenshot).
  Cause: `mkdir` of a drive or a drive root answers "access denied", not "exists" (windows/loader.c `lx_mkdir`).
  Reproduced in the VM from a prompt at `C:\`, and fixed.
- **Lower frame rate after loading a state**: not looked into.
- Seen in the VM, in v0.2.16 and later alike: a crash line is logged after the window closes (a thread of an unloaded
  library at exit). Harmless to saves; not fixed.

## PR #17: specialised fragment programs

Merged. On this PC (AMD Vega 10, scripted new game, 2x) screenshots at five points are identical with and without it
(`ALBW_NO_SPEC=1`), and GPU busy time fell from 68 % to 38 %.

## #12 / #13 (NEONZARIN) details

- #12: `exception 0x406d1388` in the log is the debugger "set thread name" exception: harmless. The freeze is the family above.
- #13 comment (RX 550, v0.2.14): the same freeze; the AMD GPU is not the cause.

## #14 language

The port always reported English (`cfg_block` 0x000A0002). Now (native/sdk/services.c, `cfg_language`): `ALBW_LANGUAGE`
(unchanged, any code 0-11), else a `language <fr|de|it|es|en|0-11>` line in layout.cfg, else the computer's language
(`LC_ALL` / `LC_MESSAGES` / `LANG`; the Windows loader sets `LANG` from the user's locale), else English. The EU game has
English, French, German, Italian and Spanish; anything else becomes English. The setting is read at start-up (restart to
change). Menu entry: Esc > File > Language (saved as the `language` line of layout.cfg, used after File > Reset game); README "Language".

## #11 Steam Deck: AppImage will not open after a failed import

The reporter gave a .3ds and the program crashed; both v0.2.9 and v0.2.10 then fail to open. A commenter asked which ROM
(it has to be the decrypted European dump). The AppImage remembers the chosen path; a bad choice (wrong region, encrypted)
leaves a stored path that fails every time. Needs the log (`~/.local/state/albw-port/last-run.log`) and the file's SHA-1.
**Fixed in master:** the game now names the problem (another game, American / Japanese release, encrypted, not a 3DS image) and forgets the remembered file, so the next start asks again (native/sdk/fs.c `rom_forget`). The reporter's own cause is still unknown.

## Older / request issues

- #7 (Windows, freeze at boot): the boot freeze was the SRW lock bug (v0.2.11); later logs show the thread-exit freeze above.
- #6: portable mode exists (folder `albw-data`); a launcher window is still open.
- #4 / #1: texture packs work since v0.2.13 (Citra/Azahar new-hash format); stereoscopic 3D not started.
- #3: 120 fps interpolation not started. #2: ARM64 not started.
