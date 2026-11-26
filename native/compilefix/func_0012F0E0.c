/* compilefix: USA 0012F0E0 (EU 0012F0E0), the converted stage-2 text.
 * Fixed (BOOT_LOG 184): the ARM compares the float's bits (vmov rX, sY; cmp), which the converted text
 * wrote as a conversion of the value to an integer. */
#include "ghidra_types.h"

extern float func_00583678(int *param_1,int *param_2,undefined *param_3,float fparam_0);
extern float DAT_0012f1c4;
extern int DAT_0012f1c8;
extern float DAT_0012f1cc;
extern float DAT_0012f1d0;
extern float DAT_0012f1d4;
extern float DAT_0012f1d8;

// USA 0012F0E0 <- EU 0012F0E0 (Ghidra, non-matching)
// GLOBAL DAT_0012f1c4 float
// GLOBAL DAT_0012f1c8 int
// GLOBAL DAT_0012f1cc float
// GLOBAL DAT_0012f1d0 float
// GLOBAL DAT_0012f1d4 float
// GLOBAL DAT_0012f1d8 float

void func_0012F0E0(int param_1,int *param_2,undefined *param_3)

{
  uint uVar1;
  byte bVar2;
  bool bVar3;
  uint in_fpscr;
  float fVar4;
  int iVar5;
  float fVar6;
  float fVar7;
  
  fVar7 = *(float *)(param_1 + 0x10c);
  fVar6 = *(float *)(param_1 + 0x110);
  fVar4 = func_00583678(param_2,*(int **)(param_1 + 0xb4),param_3,
                        *(float *)(param_1 + 0x3c) * *(float *)(param_1 + 0x34));
  if (0x3f800000 < (int)ALBW_AS_U32(fVar4)) {
    fVar7 = DAT_0012f1c4 / fVar4;
    if ((int)ALBW_AS_U32(DAT_0012f1c4 / fVar4) < DAT_0012f1c8) {
      fVar7 = DAT_0012f1cc;
    }
    fVar4 = *(float *)(param_1 + 0x10c) * fVar7 * DAT_0012f1d0;
    iVar5 = (int)fVar4;
    fVar7 = (float)VectorSignedToFloat(iVar5,(byte)(in_fpscr >> 0x15) & 3);
    uVar1 = in_fpscr & 0xfffffff | (uint)(fVar7 == fVar4) << 0x1e | (uint)(fVar4 <= fVar7) << 0x1d;
    bVar2 = (byte)(uVar1 >> 0x18);
    bVar3 = (bool)(bVar2 >> 6);
    if (!bVar3) {
      uVar1 = in_fpscr & 0xfffffff | (uint)(DAT_0012f1d4 == fVar4) << 0x1e |
              (uint)(fVar4 <= DAT_0012f1d4) << 0x1d;
      bVar2 = (byte)(uVar1 >> 0x18);
      bVar3 = (bool)(bVar2 >> 6);
    }
    if ((bool)(bVar2 >> 5 & 1) && !bVar3) {
      iVar5 = iVar5 + -1;
    }
    fVar7 = (float)VectorSignedToFloat(iVar5,(byte)(uVar1 >> 0x15) & 3);
    fVar7 = fVar7 * DAT_0012f1d8;
  }
  bVar3 = false;
  if (*(float *)(param_1 + 0xb8) == fVar7) {
    bVar3 = *(float *)(param_1 + 0xbc) == fVar6;
  }
  *(byte *)(param_1 + 0xf4) = *(byte *)(param_1 + 0xf4) | !bVar3 << 2;
  if (!bVar3) {
    *(float *)(param_1 + 0xb8) = fVar7;
    *(float *)(param_1 + 0xbc) = fVar6;
  }
  return;
}

