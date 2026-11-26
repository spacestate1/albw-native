/* USA 002569FC: converted Ghidra text with one fix (160bg): its range tests compare the float BITS
 * of a value with float constants (vmov rX, sY; cmp - signed against a positive constant,
 * unsigned against a negative one), which Ghidra wrote as (int)(v) / (uint)(v) conversions.
 * On x86 (uint)(-1.0f) is 0xFFFFFFFF, so small negative values passed the test. Now the
 * float comparisons the bit tests mean (5). Confidence: high (EU code bytes).
 * Fixed (BOOT_LOG 184): the ARM compares the float's bits (vmov rX, sY; cmp), which the converted text
 * wrote as a conversion of the value to an integer. */
#include "ghidra_types.h"

extern int func_00100174(int *param_1);
extern int func_00115C54(float *param_1,float *param_2,float *param_3);
extern int func_00115D70(float *param_1,float *param_2,float fparam_0);
extern int func_00409940(int param_1,int param_2,int param_3,float *param_4,int *param_5,float fparam_0);
extern int func_00409A00(int param_1,float *param_2,float *param_3,int param_4,float *param_5,float *param_6);
extern int func_00409A64(int param_1,int param_2,int param_3,float *param_4,float *param_5,float fparam_0);
extern int func_00588174(int param_1,uint param_2);
extern int func_0068B070(float *param_1,float *param_2,float *param_3);
extern float DAT_00256dec;
extern int *DAT_00256df0;
extern int *DAT_00256df4;
extern float DAT_00256df8;
extern uint *DAT_00256dfc;
extern float *DAT_00256e00;
extern float DAT_00256e04;
extern int DAT_00256e08;
extern undefined4 DAT_00256e0c;
extern int DAT_00256e10;
extern float DAT_00256e14;
extern int DAT_00256e18;
extern float DAT_002570c8;
extern float DAT_002570cc;
extern int DAT_002570d0;
extern float DAT_002570d4;
extern int DAT_002570d8;
extern float DAT_002570dc;
extern int DAT_002570e0;
extern float DAT_002570e4;
extern float DAT_002570e8;
extern float DAT_002570ec;
extern float DAT_002570f0;
extern float DAT_002570f4;
extern int DAT_002570f8;
extern float DAT_002570fc;
extern float DAT_00257100;

// USA 002569FC <- EU 00256A24 (Ghidra, non-matching)
// PARAM param_5 Stack[0x0]:4 uint
// PARAM param_6 Stack[0x4]:4 float *
// GLOBAL DAT_00256dec float
// GLOBAL DAT_00256df0 int *
// GLOBAL DAT_00256df4 int *
// GLOBAL DAT_00256df8 float
// GLOBAL DAT_00256dfc uint *
// GLOBAL DAT_00256e00 float *
// GLOBAL DAT_00256e04 float
// GLOBAL DAT_00256e08 int
// GLOBAL DAT_00256e0c undefined4
// GLOBAL DAT_00256e10 int
// GLOBAL DAT_00256e14 float
// GLOBAL DAT_00256e18 int
// GLOBAL DAT_002570c8 float
// GLOBAL DAT_002570cc float
// GLOBAL DAT_002570d0 int
// GLOBAL DAT_002570d4 float
// GLOBAL DAT_002570d8 int
// GLOBAL DAT_002570dc float
// GLOBAL DAT_002570e0 int
// GLOBAL DAT_002570e4 float
// GLOBAL DAT_002570e8 float
// GLOBAL DAT_002570ec float
// GLOBAL DAT_002570f0 float
// GLOBAL DAT_002570f4 float
// GLOBAL DAT_002570f8 int
// GLOBAL DAT_002570fc float
// GLOBAL DAT_00257100 float

void func_002569FC(int param_1,int param_2,float *param_3,undefined4 param_4,uint param_5,
                  float *param_6)

{
  _Alignas(8) unsigned char albw_frame[0xd0]; /* entry_sp - 0xc0 .. entry_sp + 0x10 */
#define stack0xffffff44 (*(undefined4 *)(albw_frame + 0x4))
  __builtin_memcpy(albw_frame + 0xc0, &param_5, 4);
  __builtin_memcpy(albw_frame + 0xc4, &param_6, 4);
#define param_5 (*(uint *)(albw_frame + 0xc0))
#define param_6 (*(float * *)(albw_frame + 0xc4))
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  float *pfVar5;
  uint uVar6;
  bool bVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar16;
  undefined8 uVar15;
  float fVar17;
  float *pfVar18;
  #define in_stack_ffffff44 (*(float * *)(albw_frame + 0x4)) /* V4: frame slot (callee-filled) */
  #define local_b4 (*(float *)(albw_frame + 0xc))
  #define local_b0 (*(float *)(albw_frame + 0x10))
  #define local_ac (*(float *)(albw_frame + 0x14))
  #define fStack_a8 (*(float *)(albw_frame + 0x18))
  #define local_a4 (*(undefined4 *)(albw_frame + 0x1c))
  #define uStack_a0 (*(undefined4 *)(albw_frame + 0x20))
  #define local_9c (*(undefined4 *)(albw_frame + 0x24))
  #define local_94 (*(uint *)(albw_frame + 0x2c))
  #define local_90 (*(float *)(albw_frame + 0x30))
  #define local_8c (*(float *)(albw_frame + 0x34))
  #define local_88 (*(float *)(albw_frame + 0x38))
  #define local_80 (*(float *)(albw_frame + 0x40))
  #define uStack_7c (*(undefined4 *)(albw_frame + 0x44))
  #define uStack_78 (*(undefined4 *)(albw_frame + 0x48))
  #define local_70 (*(uint *)(albw_frame + 0x50))
  #define local_68 (*(float *)(albw_frame + 0x58))
  #define local_64 (*(float *)(albw_frame + 0x5c))
  #define local_60 (*(float *)(albw_frame + 0x60))
  #define local_5c (*(float *)(albw_frame + 0x64))
  #define local_58 (*(float *)(albw_frame + 0x68))
  #define fStack_54 (*(float *)(albw_frame + 0x6c))
  #define local_50 (*(float *)(albw_frame + 0x70))
  #define local_4c (*(float *)(albw_frame + 0x74))
  #define local_48 (*(float *)(albw_frame + 0x78))
  #define uStack_44 (*(undefined4 *)(albw_frame + 0x7c))
  #define uStack_40 (*(undefined4 *)(albw_frame + 0x80))
  fVar12 = DAT_00256dec;
  if ((*DAT_00256df0 == 0) || (*(char *)(*(int *)(param_1 + 0x14) + 0xa2) == '\0'))
  goto LAB_00256ddc;
  bVar7 = (param_5 & 0x1000000) != 0;
  uVar6 = 0;
  local_94 = 0;
  if (bVar7) {
    uVar6 = 1;
  }
  else if (param_6[9] == 0.0) {
    bVar7 = true;
    param_6[9] = 1.4013e-45;
  }
  local_70 = func_00588174(*DAT_00256df4,param_4);
  iVar2 = *(int *)(param_2 + 0x10);
  pfVar5 = (float *)(iVar2 + -100);
  if (uVar6 == 0) {
    local_94 = ~(local_70 >> 0x1e) & 1;
  }
  fVar16 = fVar12;
  if (local_94 != 0 || (param_5 & 0x3f) != 0) {
    local_90 = *param_3 - *(float *)(iVar2 + -0x34);
    local_8c = param_3[1] - *(float *)(iVar2 + -0x30);
    local_88 = param_3[2] - *(float *)(iVar2 + -0x2c);
    fVar16 = SQRT(local_90 * local_90 + local_8c * local_8c + local_88 * local_88);
  }
  fVar13 = fVar12;
  fVar8 = fVar12;
  if (*(char *)(param_1 + 0x48) != '\0' && (param_5 & 7) != 0) {
    fVar8 = *(float *)(param_1 + 0x1c) - param_3[1];
    if (fVar8 <= fVar12) {
      fVar8 = -fVar8;
    }
    fVar13 = *(float *)(param_1 + 0x20) * fVar8;
    fVar8 = *(float *)(param_1 + 0x24) * fVar8;
  }
  fVar17 = DAT_00256df8;
  fVar14 = fVar16;
  if (*(char *)(param_1 + 0x48) != '\0') {
    if (((*DAT_00256dfc & 1) == 0) &&
       (iVar3 = func_00100174((int *)DAT_00256dfc), pfVar18 = DAT_00256e00, iVar3 != 0)) {
      *DAT_00256e00 = fVar12;
      pfVar18[1] = fVar17;
      pfVar18[2] = fVar12;
    }
    local_b0 = *(float *)(iVar2 + -0x34);
    local_ac = *(float *)(iVar2 + -0x30);
    fStack_a8 = *(float *)(iVar2 + -0x2c);
    local_68 = *DAT_00256e00;
    local_64 = DAT_00256e00[1];
    local_60 = DAT_00256e00[2];
    local_5c = local_68 * *param_3 + local_64 * param_3[1] + local_60 * param_3[2];
    puVar4 = *(undefined4 **)(param_1 + 0x18);
    local_a4 = *puVar4;
    uStack_a0 = puVar4[1];
    local_9c = puVar4[2];
    local_58 = local_b0;
    fStack_54 = local_ac;
    local_50 = fStack_a8;
    local_4c = fVar17;
    iVar2 = func_0068B070(&local_b0,&local_68,&local_4c);
    if (iVar2 == 1) {
      pfVar18 = &local_58;
      func_00115D70(&local_48,*(float **)(param_1 + 0x18),local_4c);
      local_80 = local_48;
      uStack_7c = uStack_44;
      uStack_78 = uStack_40;
      func_00115C54(pfVar18,pfVar18,&local_80);
    }
    fVar10 = *param_3 - local_58;
    fVar9 = param_3[2] - local_50;
    fVar14 = fVar9;
    fVar11 = fVar10;
    if ((local_70 & 0x20000000) == 0) {
      fVar11 = fVar12;
      if (fVar12 <= fVar10) {
        if (fVar13 < fVar10) {
          fVar11 = fVar10 - fVar13;
        }
      }
      else if (fVar10 < -fVar13) {
        fVar11 = fVar10 + fVar13;
      }
      fVar14 = fVar12;
      if (fVar12 <= fVar9) {
        if (fVar8 < fVar9) {
          fVar14 = fVar9 - fVar8;
        }
      }
      else if (fVar9 < -fVar8) {
        fVar14 = fVar9 + fVar8;
      }
    }
    fVar8 = fVar12;
    if (local_8c < fVar12) {
      uVar1 = (local_70 & 0x3c0000) >> 0x12;
      fVar8 = DAT_00256e04;
      if (uVar1 != 0) {
        fVar8 = *(float *)(DAT_00256e08 + uVar1 * 4 + -4) * DAT_00256e04;
      }
      fVar8 = local_8c * fVar8;
    }
    fVar14 = SQRT(fVar11 * fVar11 + fVar8 * fVar8 + fVar14 * fVar14);
  }
  uVar15 = CONCAT44(fVar16,DAT_00256e0c);
  if ((param_5 & 3) != 0) {
    func_00409940(param_2,(int)pfVar5,(int)param_3,&local_b4,(int *)&local_b0,fVar14);
    if ((param_5 & 1) != 0) {
      if (bVar7) {
        *param_6 = local_b4;
      }
      else {
        fVar16 = *param_6;
        /* above the limit? (ARM: bit compare with a positive float) */
        if ((ALBW_AS_F32(DAT_00256e10) < (local_b4 - fVar16))) {
          fVar16 = fVar16 + ALBW_AS_F32(uVar15);
        }
        else {
          if ((uint)ALBW_AS_U32(local_b4 - fVar16) <= (uint)ALBW_AS_U32(DAT_00256e14)) {
            *param_6 = local_b4;
            goto LAB_00256dcc;
          }
          fVar16 = fVar16 - ALBW_AS_F32(uVar15);
        }
        *param_6 = fVar16;
      }
LAB_00256dcc:
      if ((int)ALBW_AS_U32(*param_6) < DAT_00256e18) {
LAB_00256ddc:
        *param_6 = fVar12;
        return;
      }
    }
    if ((param_5 & 2) != 0) {
      param_6[8] = local_b0;
    }
  }
  if ((param_5 & 0xc) == 0) goto LAB_00256ff0;
  if (*(char *)(param_1 + 0x48) == '\0') {
    in_stack_ffffff44 = &local_b0;
    func_00409A00(param_2,pfVar5,param_3,param_1 + 4,&local_ac,in_stack_ffffff44);
  }
  else {
    fVar16 = fVar13 * DAT_002570c8;
    local_b0 = fVar12;
    if (local_90 < fVar12) {
      if (-fVar13 < local_90) goto LAB_00256eb8;
      if (local_90 <= -fVar16) {
        local_ac = *(float *)(param_2 + 0x20);
      }
      else {
        local_ac = *(float *)(param_2 + 0x20);
        if (DAT_002570d0 < (int)ALBW_AS_U32(local_ac)) {
          local_ac = ((local_ac - DAT_002570cc) * (local_90 + fVar13)) / (fVar16 - fVar13) -
                     DAT_002570cc;
          goto LAB_00256f3c;
        }
      }
      local_ac = -local_ac;
    }
    else if (local_90 < fVar13) {
LAB_00256eb8:
      local_ac = (local_90 * DAT_002570cc) / fVar13;
    }
    else {
      local_ac = *(float *)(param_2 + 0x20);
      if ((local_90 < fVar16) && (DAT_002570d0 < (int)ALBW_AS_U32(local_ac))) {
        local_ac = ((local_ac - DAT_002570cc) * (local_90 - fVar13)) / (fVar16 - fVar13) +
                   DAT_002570cc;
      }
    }
  }
LAB_00256f3c:
  fVar16 = DAT_002570d4;
  if ((param_5 & 4) != 0) {
    if (bVar7) {
      param_6[2] = local_ac;
    }
    else {
      fVar13 = param_6[2];
      /* above the limit? (ARM: bit compare with a positive float) */
      if ((ALBW_AS_F32(DAT_002570d8) < (local_ac - fVar13))) {
        fVar13 = fVar13 + DAT_002570d4;
      }
      else {
        if ((uint)ALBW_AS_U32(local_ac - fVar13) <= (uint)ALBW_AS_U32(DAT_002570dc)) {
          param_6[2] = local_ac;
          goto LAB_00256f94;
        }
        fVar13 = fVar13 - DAT_002570d4;
      }
      param_6[2] = fVar13;
    }
  }
LAB_00256f94:
  if ((param_5 & 8) == 0) goto LAB_00256ff0;
  local_b0 = local_b0 * fVar16;
  if (bVar7) {
LAB_00256fb0:
    param_6[3] = local_b0;
  }
  else {
    fVar16 = param_6[3];
    /* above the limit? (ARM: bit compare with a positive float) */
    if ((ALBW_AS_F32(DAT_002570e0) < (local_b0 - fVar16))) {
      fVar16 = fVar16 + DAT_002570e4;
    }
    else {
      if ((uint)ALBW_AS_U32(local_b0 - fVar16) <= (uint)ALBW_AS_U32(DAT_002570e8)) goto LAB_00256fb0;
      fVar16 = fVar16 - DAT_002570e4;
    }
    param_6[3] = fVar16;
  }
LAB_00256ff0:
  if ((param_5 & 0x20) != 0) {
    func_00409A64(param_2,(int)pfVar5,(int)param_3,&local_90,(float *)&stack0xffffff44,
                  ALBW_AS_F32(((ulonglong)uVar15 >> 0x20)));
    param_6[1] = ALBW_AS_F32(in_stack_ffffff44);
  }
  if ((local_94 & ~uVar6) == 0) {
    return;
  }
  fVar13 = *(float *)(param_1 + 0x44);
  fVar8 = DAT_002570f4;
  fVar16 = DAT_002570ec;
  if (*(char *)(param_1 + 0x48) != '\0') {
    fVar8 = DAT_002570f0;
    fVar16 = fVar12;
  }
  if (fVar16 < fVar14) {
    if (fVar8 <= fVar14) {
      fVar13 = fVar13 + ALBW_AS_F32(uVar15);
    }
    else {
      fVar13 = ((fVar14 - fVar16) * ALBW_AS_F32(uVar15)) / (fVar8 - fVar16) + fVar13;
    }
  }
  if (0x3f800000 < (int)ALBW_AS_U32(fVar13)) {
    fVar13 = fVar17;
  }
  if (!bVar7) {
    fVar12 = param_6[4];
    /* difference above the upper limit? (ARM: bit compare with a positive float) */
    if ((ALBW_AS_F32(DAT_002570f8) < (fVar13 - fVar12))) {
      fVar13 = fVar12 + DAT_002570fc;
    }
    /* ... or below the lower limit? (ARM: unsigned bit compare with a negative float) */
    else if (((fVar13 - fVar12) < ALBW_AS_F32(DAT_00257100))) {
      fVar13 = fVar12 - DAT_002570fc;
    }
  }
  param_6[4] = fVar13;
  return;
}

