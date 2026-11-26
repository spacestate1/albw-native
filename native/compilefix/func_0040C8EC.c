/* compilefix: USA 0040C8EC (EU 0040C8CC), the converted stage-2 text.
 * Fixed (BOOT_LOG 184): the ARM copies this word between a float and an integer (no vcvt), which the
 * converted text wrote as a conversion of the value. */
#include "ghidra_types.h"

extern undefined8 func_00110D44(undefined4 *param_1,byte *param_2,uint param_3);
extern float DAT_0040c9dc;
extern uint DAT_0040c9e0;
extern float DAT_0040c9e4;
extern int DAT_0040c9e8;
extern float DAT_0040c9ec;
extern float DAT_0040c9f0;

// USA 0040C8EC <- EU 0040C8CC (Ghidra, non-matching)
// GLOBAL DAT_0040c9dc float
// GLOBAL DAT_0040c9e0 uint
// GLOBAL DAT_0040c9e4 float
// GLOBAL DAT_0040c9e8 int
// GLOBAL DAT_0040c9ec float
// GLOBAL DAT_0040c9f0 float

undefined8 func_0040C8EC(int param_1,uint *param_2)

{
  uint uVar1;
  char cVar2;
  float fVar3;
  int iVar4;
  undefined1 uVar5;
  bool bVar6;
  float fVar7;
  undefined8 uVar8;
  
  iVar4 = DAT_0040c9e8;
  fVar3 = DAT_0040c9e4;
  if ((((DAT_0040c9dc <= ALBW_AS_F32(param_2[2])) && ((int)param_2[2] < 0x3f800001)) &&
      (DAT_0040c9dc <= ALBW_AS_F32(param_2[1]))) && ((int)param_2[1] < 0x3f800001)) {
    if (*(char *)(param_1 + 0x5e) != '\x01') {
LAB_0040c938:
      uVar1 = (uint)((ulonglong)(*param_2 * 1000) * (ulonglong)DAT_0040c9e0 >> 0x2c);
      *(uint *)(param_1 + 0x44) = uVar1;
      if (uVar1 == 0) {
        *(undefined4 *)(param_1 + 0x44) = 1;
      }
      if ((char)param_2[3] == '\0') {
        uVar5 = 2;
      }
      else {
        uVar5 = 4;
      }
      *(undefined1 *)(param_1 + 0x5d) = uVar5;
      *(int *)(param_1 + 0x4c) = (int)(ALBW_AS_F32(param_2[1]) * fVar3);
      fVar7 = ALBW_AS_F32(param_2[2]);
      if (iVar4 < (int)param_2[2]) {
        fVar7 = DAT_0040c9ec;
      }
      *(int *)(param_1 + 0x50) = (int)((DAT_0040c9f0 - fVar7) * fVar3);
      *(int *)(param_1 + 0x54) = (int)(fVar7 * fVar3);
      uVar8 = func_00110D44((undefined4 *)(param_1 + 0xc),(byte *)param_2,0xd);
      return CONCAT44((int)((ulonglong)uVar8 >> 0x20),1);
    }
    if (*param_2 <= *(uint *)(param_1 + 0x58)) {
      cVar2 = *(char *)(param_1 + 0x5c);
      bVar6 = cVar2 == '\0';
      if (bVar6) {
        cVar2 = (char)param_2[3];
      }
      if (!bVar6 || cVar2 != '\x01') goto LAB_0040c938;
    }
  }
  return ZEXT48(param_2) << 0x20;
}

