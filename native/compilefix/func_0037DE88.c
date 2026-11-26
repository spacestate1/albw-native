/* compilefix: USA 0037DE88 (EU 0037DE64), the converted stage-2 text.
 * Fixed (BOOT_LOG 184): the ARM compares the float's bits (vmov rX, sY; cmp), which the converted text
 * wrote as a conversion of the value to an integer. */
#include "ghidra_types.h"

extern float func_00115C14(float *param_1);
extern float func_0049EEDC(float *param_1,float *param_2,float *param_3);
extern float DAT_0037e12c;
extern float DAT_0037e130;
extern float DAT_0037e134;
extern float DAT_0037e138;
extern float DAT_0037e13c;
extern int DAT_0037e140;
extern float DAT_0037e144;

// USA 0037DE88 <- EU 0037DE64 (Ghidra, non-matching)
// GLOBAL DAT_0037e12c float
// GLOBAL DAT_0037e130 float
// GLOBAL DAT_0037e134 float
// GLOBAL DAT_0037e138 float
// GLOBAL DAT_0037e13c float
// GLOBAL DAT_0037e140 int
// GLOBAL DAT_0037e144 float

void func_0037DE88(int param_1,float *param_2,float *param_3,float *param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  undefined8 in_d8;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  _Alignas(8) unsigned char albw_frame[0x80];
  #define local_78 (*(float *)(albw_frame + 0x8))
  #define local_74 (*(float *)(albw_frame + 0xc))
  #define local_5c (*(float *)(albw_frame + 0x24))
  #define local_58 (*(float *)(albw_frame + 0x28))
  #define local_54 (*(float *)(albw_frame + 0x2c))
  #define local_50 (*(float *)(albw_frame + 0x30))
  #define local_4c (*(float *)(albw_frame + 0x34))
  #define local_48 (*(float *)(albw_frame + 0x38))
  #define local_44 (*(float * *)(albw_frame + 0x3c))
  fVar10 = DAT_0037e134;
  iVar4 = 0;
  uVar3 = 0;
  local_44 = &local_50;
  local_50 = *param_4;
  local_4c = param_4[2];
  local_58 = *param_3;
  fVar11 = ALBW_AS_F32(((ulonglong)in_d8 >> 0x20));
  local_54 = param_3[2];
  uVar1 = *(uint *)(param_1 + 0x10);
  fVar12 = DAT_0037e12c;
  if (0 < (int)uVar1) {
    iVar5 = (int)ALBW_AS_U32(DAT_0037e134) + 0x80000000;
    fVar14 = DAT_0037e130;
    fVar13 = DAT_0037e138;
    do {
      if (uVar3 < uVar1) {
        iVar2 = *(int *)(*(int *)(param_1 + 0x18) + uVar3 * 4);
      }
      else {
        iVar2 = 0;
      }
      fVar7 = func_0049EEDC(local_44,(float *)(iVar2 + 0x1c),&local_48);
      if (fVar7 <= fVar14) {
        if (((uint)ALBW_AS_U32(fVar14 - fVar7) <= (uint)ALBW_AS_U32(fVar10)) && ((int)ALBW_AS_U32(fVar14 - fVar7) <= iVar5)) {
          fVar9 = fVar11;
          if (0x3f000000 < (int)ALBW_AS_U32(fVar11)) {
            fVar9 = fVar13 - fVar11;
          }
          fVar8 = local_48;
          if (0x3f000000 < (int)ALBW_AS_U32(local_48)) {
            fVar8 = fVar13 - local_48;
          }
          if (fVar8 < fVar9) goto LAB_0037df64;
        }
        fVar14 = fVar7;
        fVar11 = local_48;
        if (uVar3 < *(uint *)(param_1 + 0x10)) {
          iVar4 = *(int *)(*(int *)(param_1 + 0x18) + uVar3 * 4);
        }
        else {
          iVar4 = 0;
        }
      }
LAB_0037df64:
      uVar1 = *(uint *)(param_1 + 0x10);
      uVar3 = uVar3 + 1;
    } while ((int)uVar3 < (int)uVar1);
  }
  func_0049EEDC(&local_58,(float *)(iVar4 + 0x1c),&local_48);
  fVar10 = *(float *)(*(int *)(iVar4 + 0x14) + 0x18);
  fVar11 = *(float *)(*(int *)(iVar4 + 0x14) + 0x20);
  fVar10 = fVar10 + (*(float *)(*(int *)(iVar4 + 0x18) + 0x18) - fVar10) * local_48;
  local_58 = *param_3;
  fVar11 = fVar11 + (*(float *)(*(int *)(iVar4 + 0x18) + 0x20) - fVar11) * local_48;
  local_54 = param_3[2];
  func_0049EEDC(&local_58,(float *)(iVar4 + 0x1c),&local_5c);
  bVar6 = *(int *)(param_1 + 0x1c) != 0;
  if (!bVar6) {
    *(int *)(param_1 + 0x1c) = iVar4;
    *(float *)(param_1 + 0x20) = local_5c;
    *(float *)(param_1 + 0x28) = fVar10;
    *(float *)(param_1 + 0x2c) = fVar12;
    *(float *)(param_1 + 0x30) = fVar11;
  }
  fVar14 = *(float *)(*(int *)(iVar4 + 0x14) + 0x54);
  local_78 = fVar10 - *param_3;
  fVar14 = fVar14 + (*(float *)(*(int *)(iVar4 + 0x18) + 0x54) - fVar14) * local_5c;
  local_74 = fVar11 - param_3[2];
  fVar11 = func_00115C14(&local_78);
  fVar10 = fVar11 - fVar14;
  if (fVar11 - fVar14 < fVar12) {
    fVar10 = fVar12;
  }
  if (bVar6) {
    fVar11 = ((local_78 * fVar10 + *param_3) - *(float *)(param_1 + 0x28)) * DAT_0037e13c;
    fVar10 = ((local_74 * fVar10 + param_3[2]) - *(float *)(param_1 + 0x30)) * DAT_0037e13c;
    fVar14 = fVar11 * fVar11 + fVar10 * fVar10;
    if (DAT_0037e140 < (int)ALBW_AS_U32(fVar14)) {
      fVar14 = DAT_0037e144 / SQRT(fVar14);
      fVar11 = fVar11 * fVar14;
      fVar10 = fVar10 * fVar14;
    }
  }
  else {
    fVar11 = (local_78 * fVar10 + *param_3) - *(float *)(param_1 + 0x28);
    fVar10 = (local_74 * fVar10 + param_3[2]) - *(float *)(param_1 + 0x30);
  }
  *(float *)(param_1 + 0x20) = local_5c;
  *(int *)(param_1 + 0x1c) = iVar4;
  fVar11 = *(float *)(param_1 + 0x28) + fVar11;
  *(float *)(param_1 + 0x28) = fVar11;
  *(float *)(param_1 + 0x2c) = fVar12;
  *(float *)(param_1 + 0x30) = *(float *)(param_1 + 0x30) + fVar10;
  *param_2 = fVar11 - *param_3;
  param_2[1] = fVar12;
  param_2[2] = *(float *)(param_1 + 0x30) - param_3[2];
  return;
}

