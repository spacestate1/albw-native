/* compilefix: USA 0040D150 (EU 0040D130), the converted stage-2 text.
 * Fixed (BOOT_LOG 184): the ARM copies this word between a float and an integer (no vcvt), which the
 * converted text wrote as a conversion of the value. */
#include "ghidra_types.h"

extern undefined8 func_00110D44(undefined4 *param_1,byte *param_2,uint param_3);
extern int func_0040CE44(int param_1);
extern float DAT_0040d2b8;

// USA 0040D150 <- EU 0040D130 (Ghidra, non-matching)
// GLOBAL DAT_0040d2b8 float

undefined4 func_0040D150(int param_1,uint *param_2)

{
  char cVar1;
  undefined1 uVar2;
  uint *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 uVar7;
  bool bVar8;
  bool bVar9;
  
  if ((((DAT_0040d2b8 <= ALBW_AS_F32(param_2[3])) && ((int)param_2[3] < 0x3f800001)) &&
      (DAT_0040d2b8 <= ALBW_AS_F32(param_2[4]))) &&
     ((((int)param_2[4] < 0x3f800001 && (DAT_0040d2b8 <= ALBW_AS_F32(param_2[6]))) &&
      (((int)param_2[6] < 0x3f800001 &&
       ((DAT_0040d2b8 <= ALBW_AS_F32(param_2[7]) && ((int)param_2[7] < 0x3f800001)))))))) {
    puVar3 = (uint *)param_2[5];
    if (puVar3 != (uint *)0x0) {
      bVar8 = *puVar3 == 0;
      uVar6 = 0;
      if (!bVar8) {
        uVar6 = puVar3[1];
      }
      bVar9 = uVar6 == 0;
      if (!bVar8 && !bVar9) {
        uVar6 = puVar3[2];
      }
      if ((bVar8 || bVar9) || uVar6 == 0) {
        return 0;
      }
    }
    if (*(char *)(param_1 + 0x10e) != '\x01') {
LAB_0040d250:
      if ((char)param_2[8] == '\0') {
        uVar2 = 2;
      }
      else {
        uVar2 = 4;
      }
      *(undefined1 *)(param_1 + 0x10d) = uVar2;
      func_00110D44((undefined4 *)(param_1 + 0xc),(byte *)param_2,0x22);
      puVar4 = *(undefined4 **)(param_1 + 0x20);
      if (puVar4 != (undefined4 *)0x0) {
        uVar5 = *puVar4;
        uVar7 = puVar4[1];
        *(undefined4 *)(param_1 + 0x40) = puVar4[2];
        *(int *)(param_1 + 0x20) = param_1 + 0x38;
        *(undefined4 *)(param_1 + 0x38) = uVar5;
        *(undefined4 *)(param_1 + 0x3c) = uVar7;
      }
      if (*(char *)(param_1 + 0x10e) == '\x01') {
        func_0040CE44(param_1);
      }
      return 1;
    }
    if (((*param_2 <= *(uint *)(param_1 + 0xf8)) && (param_2[2] <= *(uint *)(param_1 + 0xfc))) &&
       ((puVar3 == (uint *)0x0 ||
        (((*puVar3 <= *(uint *)(param_1 + 0x100) && (puVar3[1] <= *(uint *)(param_1 + 0x104))) &&
         (puVar3[2] <= *(uint *)(param_1 + 0x108))))))) {
      cVar1 = *(char *)(param_1 + 0x10c);
      bVar8 = cVar1 == '\0';
      if (bVar8) {
        cVar1 = (char)param_2[8];
      }
      if (!bVar8 || cVar1 != '\x01') goto LAB_0040d250;
    }
  }
  return 0;
}

