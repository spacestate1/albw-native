/* USA 001E4D1C: converted Ghidra text with one fix (160bg): range tests that compare the float
 * BITS of a value with float constants (vmov rX, sY; cmp) were written as (int)(v) / (uint)(v)
 * conversions; on x86 (uint)(-1.0f) is 0xFFFFFFFF. Now the float comparisons they mean.
 * Fixed (BOOT_LOG 184): the ARM compares the float's bits (vmov rX, sY; cmp), which the converted text
 * wrote as a conversion of the value to an integer. */
// MAPFIX-INTEGRATED v1
#include "ghidra_types.h"

extern int func_00115C70(float *param_1,float *param_2,float *param_3);
extern int func_00341220(int param_1);
extern int func_0036172C(int param_1,float fparam_0);
extern int func_004905E0(float fparam_0);
extern int func_0052EB98(int param_1,float *param_2);
extern int func_0052ED28(int param_1,float *param_2);
extern int func_0053ED30(int param_1);
extern int func_00556B54(int param_1);
extern float func_00556CE4(int param_1);
extern int func_00556E40(int param_1);
extern int func_0058E2B8(int *param_1);
extern int *DAT_001e50a4;
extern float DAT_001e50a8;
extern int DAT_001e50ac;
extern float DAT_001e50b0;
extern float DAT_001e50b4;
extern float DAT_001e50b8;
extern float DAT_001e50bc;
extern uint DAT_001e50c0;
extern float DAT_001e50c4;

// USA 001E4D1C <- EU 001E4D1C (Ghidra, non-matching)
// PARAM param_5 Stack[0x0]:4 int
// GLOBAL DAT_001e50a4 int *
// GLOBAL DAT_001e50a8 float
// GLOBAL DAT_001e50ac int
// GLOBAL DAT_001e50b0 float
// GLOBAL DAT_001e50b4 float
// GLOBAL DAT_001e50b8 float
// GLOBAL DAT_001e50bc float
// GLOBAL DAT_001e50c0 uint
// GLOBAL DAT_001e50c4 float

undefined4 func_001E4D1C(ushort *param_1,int param_2,char param_3,float *param_4,int param_5)

{
  ushort uVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  float *pfVar5;
  int iVar6;
  uint in_fpscr;
  float fVar7;
  float fVar8;
  float fVar9;
  _Alignas(8) unsigned char albw_frame[0x50];
  #define local_44 (*(float *)(albw_frame + 0xc))
  #define local_40 (*(float *)(albw_frame + 0x10))
  #define fStack_3c (*(float *)(albw_frame + 0x14))
  #define local_38 (*(float *)(albw_frame + 0x18))
  #define local_34 (*(int *)(albw_frame + 0x1c))
  #define local_30 (*(float *)(albw_frame + 0x20))
  #define local_2c (*(int *)(albw_frame + 0x24))
  #define local_28 ((int *)(albw_frame + 0x28))
  iVar6 = *DAT_001e50a4;
  if (iVar6 != 0) {
    if ((param_5 == 0) || (bVar2 = func_00556B54(iVar6), !bVar2)) {
      if (param_2 == 5) {
        if ((param_3 == '\x02' || param_3 == '\x03') || param_3 == '\x04') {
          return 1;
        }
        fVar8 = func_00556CE4(iVar6);
        fVar9 = *param_4 - **(float **)(iVar6 + 0x1c);
        fVar7 = param_4[2] - (*(float **)(iVar6 + 0x1c))[2];
        fVar7 = fVar9 * fVar9 + fVar7 * fVar7;
        if (param_3 == '\0') {
          if (fVar7 <= fVar8 * fVar8) {
            func_0036172C(iVar6,SQRT(fVar7) + DAT_001e50c4);
            return 1;
          }
        }
        else {
          if (param_3 != '\x01') {
            return 1;
          }
          if ((fVar7 <= fVar8 * fVar8) &&
             (fVar8 = DAT_001e50c4, bVar2 = func_00556E40(iVar6), bVar2)) {
            func_0036172C(iVar6,SQRT(fVar7) + fVar8);
          }
        }
        *(undefined1 *)(param_1 + 1) = 1;
        return 0;
      }
    }
    else {
      pfVar5 = *(float **)(iVar6 + 0x1c);
      local_44 = *pfVar5;
      local_40 = pfVar5[1];
      fStack_3c = pfVar5[2];
      /* below the limit? (ARM: unsigned bit compare with -1.0f) */
      if (((((local_40 - param_4[1]) < ALBW_AS_F32(DAT_001e50a8))) ||
          (0x3f800000 < (int)ALBW_AS_U32(local_40 - param_4[1]))) ||
         (DAT_001e50ac <
          (int)ALBW_AS_U32(((local_44 - *param_4) * (local_44 - *param_4) +
               (fStack_3c - param_4[2]) * (fStack_3c - param_4[2]))))) {
LAB_001e4f9c:
        *param_1 = 0;
        return 0;
      }
      fVar8 = DAT_001e50b0;
      iVar3 = func_0053ED30(iVar6);
      fVar9 = *(float *)(iVar3 + 0xc) - *param_4;
      fVar7 = *(float *)(iVar3 + 0x2c) - param_4[2];
      local_28[0] = **(int **)(iVar6 + 0x24);
      fVar9 = fVar9 * fVar9 + fVar7 * fVar7;
      local_34 = func_0058E2B8(local_28);
      local_34 = local_34 + -0x80000000;
      iVar3 = func_0058E2B8(&local_34);
      fVar7 = (float)VectorUnsignedToFloat(iVar3,(byte)(in_fpscr >> 0x15) & 3);
      fVar7 = DAT_001e50bc + fVar7 * DAT_001e50b4 * DAT_001e50b8;
      if (fVar7 * fVar7 < fVar9) goto LAB_001e4f9c;
      func_00115C70(&local_38,param_4,&local_44);
      iVar3 = **(int **)(iVar6 + 0x24);
      if (local_30 == fVar8 && local_38 == fVar8) {
        local_2c = 0;
      }
      else if (local_30 < fVar8) {
        if (local_38 < fVar8) {
          if (local_38 < local_30) {
            local_2c = func_004905E0(local_30 / local_38);
            local_2c = -0x40000000 - local_2c;
          }
          else {
            local_2c = func_004905E0(local_38 / local_30);
            local_2c = local_2c + -0x80000000;
          }
        }
        else {
          local_30 = -local_30;
          if (local_30 < local_38) {
            local_2c = func_004905E0(local_30 / local_38);
            local_2c = local_2c + 0x40000000;
          }
          else {
            local_2c = func_004905E0(local_38 / local_30);
            local_2c = -0x80000000 - local_2c;
          }
        }
      }
      else if (local_38 < fVar8) {
        local_38 = -local_38;
        if (local_30 < local_38) {
          local_2c = func_004905E0(local_30 / local_38);
          local_2c = local_2c + -0x40000000;
        }
        else {
          local_2c = func_004905E0(local_38 / local_30);
          local_2c = -local_2c;
        }
      }
      else if (local_30 < local_38) {
        local_2c = func_004905E0(local_30 / local_38);
        local_2c = 0x40000000 - local_2c;
      }
      else {
        local_2c = func_004905E0(local_38 / local_30);
      }
      local_2c = iVar3 - local_2c;
      uVar4 = func_0058E2B8(&local_2c);
      if (DAT_001e50c0 < uVar4) goto LAB_001e4f9c;
      bVar2 = func_0052EB98(iVar6,param_4);
      if (bVar2) {
        func_00341220(iVar6);
      }
      iVar6 = func_0052ED28(iVar6,param_4);
      if (iVar6 != 0) {
        uVar1 = *param_1;
        *param_1 = uVar1 + 1;
        if ((ushort)(uVar1 + 1) < 10) {
          return 0;
        }
        return 1;
      }
    }
    *param_1 = 0;
  }
  return 0;
}

