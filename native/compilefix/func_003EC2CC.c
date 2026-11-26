/* compilefix: USA 003EC2CC (EU 003EC2AC), the converted stage-2 text.
 * Fixed (BOOT_LOG 184): the ARM copies this word between a float and an integer (no vcvt), which the
 * converted text wrote as a conversion of the value. */
#include "ghidra_types.h"

extern ulonglong func_00110710(uint param_1,uint param_2);
extern undefined8 func_00114608(uint param_1,uint param_2);
extern int func_003E728C(int param_1,undefined4 *param_2);
extern int func_003E8730(int param_1,undefined4 *param_2);
extern int func_003F856C(int param_1,undefined4 param_2);
extern float DAT_003ec610;
extern float DAT_003ec614;
extern uint DAT_003ec618;
extern float DAT_003ec61c;
extern float DAT_003ec620;
extern float DAT_003ec624;
extern float DAT_003ec628;
extern float DAT_003ec62c;
extern float DAT_003ec630;
extern float DAT_003ec634;
extern uint DAT_003ec638;
extern int *DAT_003ec63c;
extern int DAT_003ec640;

// USA 003EC2CC <- EU 003EC2AC (Ghidra, non-matching)
// GLOBAL DAT_003ec610 float
// GLOBAL DAT_003ec614 float
// GLOBAL DAT_003ec618 uint
// GLOBAL DAT_003ec61c float
// GLOBAL DAT_003ec620 float
// GLOBAL DAT_003ec624 float
// GLOBAL DAT_003ec628 float
// GLOBAL DAT_003ec62c float
// GLOBAL DAT_003ec630 float
// GLOBAL DAT_003ec634 float
// GLOBAL DAT_003ec638 uint
// GLOBAL DAT_003ec63c int *
// GLOBAL DAT_003ec640 int

undefined4 * func_003EC2CC(int *param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  float *pfVar5;
  int iVar6;
  uint extraout_r1;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint in_fpscr;
  uint uVar11;
  float fVar12;
  float fVar13;
  uint uVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  undefined8 uVar21;
  undefined8 uVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  ulonglong uVar29;
  undefined8 uVar30;
  int local_60;
  
  fVar25 = DAT_003ec614;
  fVar26 = DAT_003ec610;
  fVar16 = *(float *)param_1[7];
  puVar2 = (undefined4 *)param_1[6];
  iVar9 = param_1[0x36];
  fVar13 = ALBW_AS_F32(param_1[0x8b]) + ALBW_AS_F32(param_1[0x5a]) * fVar16;
  param_1[0x8b] = (int)ALBW_AS_U32(fVar13);
  if ((*param_1 == 0) && ((int)ALBW_AS_U32(fVar13) < 0x3f800000)) {
    in_fpscr = in_fpscr & 0xfffffff | (uint)(ALBW_AS_F32(param_1[0x5a]) * fVar16 == fVar26) << 0x1e;
    if (!SUB41(in_fpscr >> 0x1e,0)) {
      param_1[0x8b] = (int)ALBW_AS_U32(fVar25);
    }
  }
  uVar14 = (uint)ALBW_AS_F32(param_1[0x8b]);
  if (*(char *)(iVar9 + 0x181) != '\0') {
    uVar14 = 1;
  }
  if (uVar14 == 0) {
    puVar2 = (undefined4 *)0x0;
  }
  fVar13 = (float)VectorSignedToFloat(uVar14,(byte)(in_fpscr >> 0x15) & 3);
  param_1[0x8b] = (int)ALBW_AS_U32(ALBW_AS_F32(param_1[0x8b]) - fVar13);
  if (uVar14 != 0) {
    iVar10 = *(int *)(iVar9 + 0x260);
    uVar21 = CONCAT44(*(float *)(iVar9 + 0x254) * ALBW_AS_F32(puVar2[0x88]) * ALBW_AS_F32(param_1[0x70]),
                      ALBW_AS_F32(param_1[0x69]) * ALBW_AS_F32(puVar2[0x8f]));
    uVar22 = CONCAT44(fVar26,*(float *)(iVar9 + 0x25c) * ALBW_AS_F32(puVar2[0x8a]) * ALBW_AS_F32(param_1[0x71]))
    ;
    if (*(char *)(iVar9 + 0x17f) != '\0') {
      iVar10 = param_1[0x22];
      param_1[0x22] = iVar10 * DAT_003ec618 + 0x3039;
    }
    if ((int)uVar14 < 2) {
      local_60 = 0;
    }
    else if (*(uint *)(iVar9 + 0x264) == 0xffffffff) {
      uVar30 = func_00110710(0xffffffff,uVar14);
      local_60 = (int)uVar30;
    }
    else {
      uVar30 = func_00110710(*(uint *)(iVar9 + 0x264),uVar14 - 1);
      local_60 = (int)uVar30;
    }
    puVar2 = (undefined4 *)0x0;
    iVar8 = 0;
    if (0 < (int)uVar14) {
      uVar29 = (ulonglong)DAT_003ec638;
      fVar26 = DAT_003ec620;
      fVar13 = DAT_003ec630;
      fVar16 = DAT_003ec634;
      fVar27 = DAT_003ec624;
      fVar28 = DAT_003ec628;
      fVar23 = DAT_003ec61c;
      fVar24 = DAT_003ec62c;
      do {
        uVar3 = (**(code **)(*(int *)param_1[0x35] + 0xc))((int *)param_1[0x35]);
        puVar4 = (undefined4 *)func_003F856C(*DAT_003ec63c,uVar3);
        if (puVar4 != (undefined4 *)0x0) {
          if (puVar2 == (undefined4 *)0x0) {
            puVar2 = puVar4;
          }
          uVar11 = in_fpscr & 0xfffffff |
                   (uint)(*(float *)(iVar9 + 0x268) == ALBW_AS_F32(((ulonglong)uVar22 >> 0x20))) << 0x1e;
          fVar12 = (float)VectorSignedToFloat(iVar10,(byte)(uVar11 >> 0x15) & 3);
          puVar4[0x52] = 0;
          puVar4[0x4e] = iVar9;
          uVar1 = DAT_003ec618;
          fVar12 = fVar12 * fVar23;
          uVar7 = extraout_r1;
          if (!SUB41(uVar11 >> 0x1e,0)) {
            fVar15 = *(float *)(iVar9 + 0x268);
            fVar18 = (float)VectorUnsignedToFloat(param_1[0x22],(byte)(uVar11 >> 0x15) & 3);
            param_1[0x22] = param_1[0x22] * DAT_003ec618 + 0x3039;
            fVar12 = fVar12 + fVar15 * (fVar18 * fVar16 - fVar26) * fVar27 * fVar28;
            uVar7 = uVar1;
          }
          uVar30 = func_00114608((uint)ALBW_AS_U32((fVar12 * fVar24)),uVar7);
          fVar12 = ALBW_AS_F32(((ulonglong)uVar22 >> 0x20));
          iVar10 = iVar10 + local_60;
          in_fpscr = uVar11 & 0xfffffff | (uint)(*(float *)(iVar9 + 0x310) == fVar12) << 0x1e;
          pfVar5 = (float *)(DAT_003ec640 + ((uint)uVar30 >> 0x18) * 0x10);
          fVar15 = (float)VectorUnsignedToFloat
                                    ((uint)uVar30 & 0xffffff,(byte)(in_fpscr >> 0x15) & 3);
          fVar20 = pfVar5[1];
          fVar17 = pfVar5[2];
          fVar19 = pfVar5[3];
          fVar18 = *pfVar5;
          puVar4[3] = ALBW_AS_U32(fVar12);
          puVar4[9] = ALBW_AS_U32(fVar12);
          fVar18 = fVar18 + fVar20 * fVar15 * fVar13;
          fVar17 = fVar17 + fVar19 * fVar15 * fVar13;
          fVar19 = fVar18 * ALBW_AS_F32(((ulonglong)uVar21 >> 0x20));
          fVar15 = fVar17 * ALBW_AS_F32(uVar22);
          puVar4[2] = ALBW_AS_U32(fVar19);
          puVar4[4] = ALBW_AS_U32(fVar15);
          puVar4[8] = ALBW_AS_U32(fVar18 * ALBW_AS_F32(uVar21));
          puVar4[10] = ALBW_AS_U32(fVar17 * ALBW_AS_F32(uVar21));
          if (!SUB41(in_fpscr >> 0x1e,0)) {
            if ((int)ALBW_AS_U32((fVar19 * fVar19 + fVar12 * fVar12 + fVar15 * fVar15)) < 0x800001) {
              fVar15 = (float)VectorUnsignedToFloat(param_1[0x22],(byte)(in_fpscr >> 0x15) & 3);
              iVar6 = param_1[0x22] * DAT_003ec618 + 0x3039;
              fVar18 = (float)VectorUnsignedToFloat(iVar6,(byte)(in_fpscr >> 0x15) & 3);
              param_1[0x22] = iVar6 * DAT_003ec618 + 0x3039;
              fVar19 = fVar15 * fVar16 * ALBW_AS_F32(uVar29) - fVar25;
              fVar15 = fVar18 * fVar16 * ALBW_AS_F32(uVar29) - fVar25;
            }
            fVar20 = fVar19 * fVar19 + fVar12 * fVar12 + fVar15 * fVar15;
            in_fpscr = uVar11 & 0xfffffff | (uint)(fVar20 == fVar12) << 0x1e;
            fVar18 = fVar12;
            fVar17 = fVar12;
            if (!SUB41(in_fpscr >> 0x1e,0)) {
              fVar17 = fVar25 / SQRT(fVar20);
              fVar12 = fVar12 * fVar17;
              fVar18 = fVar19 * fVar17;
              fVar17 = fVar15 * fVar17;
            }
            fVar15 = *(float *)(iVar9 + 0x310);
            puVar4[8] = ALBW_AS_U32(ALBW_AS_F32(puVar4[8]) + fVar18 * fVar15);
            puVar4[9] = ALBW_AS_U32(ALBW_AS_F32(puVar4[9]) + fVar12 * fVar15);
            puVar4[10] = ALBW_AS_U32(ALBW_AS_F32(puVar4[10]) + fVar17 * fVar15);
          }
          if ((*(uint *)(param_1[0x36] + 4) & 0x400000) == 0) {
            func_003E728C((int)param_1,puVar4);
          }
          else {
            func_003E8730((int)param_1,puVar4);
          }
        }
        iVar8 = iVar8 + 1;
      } while (iVar8 < (int)uVar14);
    }
    param_1[2] = param_1[2] | 8;
  }
  return puVar2;
}

