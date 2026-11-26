/* compilefix: USA 004A71C4 (EU 004A719C), the converted stage-2 text with the position argument of
 * its tail call restored (BOOT_LOG 172): `bx r2` at EU 4A7250 passes r1 = *(*(this+0x1C)+0x18),
 * the position; the call "treated as indirect jump" had `this` only, so 0040878C read a stray
 * word (crash in Lorule field / Hyrule indoor rooms and with spawned Moblins). */
#include "ghidra_types.h"


// USA 004A71C4 <- EU 004A719C (Ghidra, non-matching)

undefined4 func_004A71C4(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  _Alignas(8) unsigned char albw_frame[0x20];
  #define local_20 (*(undefined4 *)(albw_frame + 0x0))
  #define local_1c (*(undefined4 *)(albw_frame + 0x4))
  #define local_18 (*(undefined4 *)(albw_frame + 0x8))
  piVar3 = *(int **)(param_1 + 0x20);
  if (piVar3 == (int *)0x0) {
    return 0;
  }
  if (*(int **)(param_1 + 0xc) != (int *)0x0) {
    iVar2 = *(int *)(*(int *)(param_1 + 0x1c) + 0x2c);
    if (iVar2 != 0) {
      for (iVar1 = 0; iVar1 < *(int *)(*(int *)(param_1 + 0x1c) + 0x30); iVar1 = iVar1 + 1) {
        if (*(int *)(iVar2 + iVar1 * 8) == **(int **)(param_1 + 0xc)) {
          iVar2 = *(int *)(iVar2 + iVar1 * 8 + 4);
          local_20 = *(undefined4 *)(iVar2 + 0xc);
          local_1c = *(undefined4 *)(iVar2 + 0x1c);
          local_18 = *(undefined4 *)(iVar2 + 0x2c);
          return (**(code **)(**(int **)(param_1 + 0x20) + 8))(*(int **)(param_1 + 0x20),&local_20);
        }
      }
    }
  }
  if (*(int *)(*(int *)(param_1 + 0x1c) + 0x18) != 0) {
                    /* WARNING: Could not recover jumptable at 0x004a7250. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    return (**(code **)(*piVar3 + 8))(piVar3,*(int *)(*(int *)(param_1 + 0x1c) + 0x18));
  }
  iVar2 = *(int *)(*(int *)(param_1 + 0x1c) + 0x14);
  local_20 = *(undefined4 *)(iVar2 + 0xc);
  local_1c = *(undefined4 *)(iVar2 + 0x1c);
  local_18 = *(undefined4 *)(iVar2 + 0x2c);
  return (**(code **)(**(int **)(param_1 + 0x20) + 8))(*(int **)(param_1 + 0x20),&local_20);
}

