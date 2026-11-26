/* compilefix: USA 003EA664 (EU 003EA644), the converted stage-2 text.
 * Fixed (BOOT_LOG 184): the ARM copies this word between a float and an integer (no vcvt), which the
 * converted text wrote as a conversion of the value. */
#include "ghidra_types.h"

extern int func_003E728C(int param_1,undefined4 *param_2);
extern int func_003E8730(int param_1,undefined4 *param_2);
extern int func_003F856C(int param_1,undefined4 param_2);
extern float DAT_003ea9a4;
extern uint DAT_003ea9a8;
extern float DAT_003ea9ac;
extern float DAT_003ea9b0;
extern int *DAT_003ea9b4;
extern int DAT_003ea9b8;

// USA 003EA664 <- EU 003EA644 [EDITED REGION: check by hand] (Ghidra, non-matching)
// GLOBAL DAT_003ea9a4 float
// GLOBAL DAT_003ea9a8 uint
// GLOBAL DAT_003ea9ac float
// GLOBAL DAT_003ea9b0 float
// GLOBAL DAT_003ea9b4 int *
// GLOBAL DAT_003ea9b8 int

undefined4 * func_003EA664(int *param_1)

{
  float *pfVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  bool bVar11;
  uint in_fpscr;
  int iVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  ulonglong uVar26;
  
  uVar5 = DAT_003ea9a8;
  fVar25 = DAT_003ea9a4;
  fVar15 = *(float *)param_1[7];
  puVar2 = (undefined4 *)param_1[6];
  iVar10 = param_1[0x36];
  uVar26 = (ulonglong)DAT_003ea9a8;
  fVar13 = ALBW_AS_F32(param_1[0x8b]) + ALBW_AS_F32(param_1[0x5a]) * fVar15;
  param_1[0x8b] = (int)ALBW_AS_U32(fVar13);
  if ((*param_1 == 0) && ((int)ALBW_AS_U32(fVar13) < 0x3f800000)) {
    in_fpscr = in_fpscr & 0xfffffff | (uint)(ALBW_AS_F32(param_1[0x5a]) * fVar15 == fVar25) << 0x1e;
    if (!SUB41(in_fpscr >> 0x1e,0)) {
      param_1[0x8b] = uVar5;
    }
  }
  iVar12 = (int)ALBW_AS_F32(param_1[0x8b]);
  if (*(char *)(iVar10 + 0x181) != '\0') {
    iVar12 = 1;
  }
  if (iVar12 == 0) {
    puVar2 = (undefined4 *)0x0;
  }
  fVar13 = (float)VectorSignedToFloat(iVar12,(byte)(in_fpscr >> 0x15) & 3);
  param_1[0x8b] = (int)ALBW_AS_U32(ALBW_AS_F32(param_1[0x8b]) - fVar13);
  if (iVar12 != 0) {
    pfVar1 = (float *)(puVar2 + 0x88);
    fVar13 = *(float *)(iVar10 + 0x25c) * ALBW_AS_F32(puVar2[0x8a]);
    fVar16 = ALBW_AS_F32(param_1[0x70]);
    fVar21 = ALBW_AS_F32(param_1[0x69]) * ALBW_AS_F32(puVar2[0x8f]);
    puVar2 = (undefined4 *)0x0;
    iVar9 = 0;
    fVar24 = fVar13 * ALBW_AS_F32(param_1[0x71]);
    fVar23 = *(float *)(iVar10 + 0x254) * *pfVar1 * fVar16;
    fVar15 = DAT_003ea9ac;
    fVar22 = DAT_003ea9b0;
    if (0 < iVar12) {
      do {
        uVar3 = (**(code **)(*(int *)param_1[0x35] + 0xc))((int *)param_1[0x35]);
        puVar4 = (undefined4 *)func_003F856C(*DAT_003ea9b4,uVar3);
        iVar7 = DAT_003ea9b8;
        if (puVar4 != (undefined4 *)0x0) {
          if (puVar2 == (undefined4 *)0x0) {
            puVar2 = puVar4;
          }
          puVar4[0x4e] = iVar10;
          uVar5 = param_1[0x22];
          fVar14 = ALBW_AS_F32(uVar26);
          uVar6 = uVar5 * iVar7 + 0x3039;
          puVar4[0x52] = 0;
          iVar8 = uVar6 * iVar7 + 0x3039;
          fVar17 = (float)VectorUnsignedToFloat(iVar8,(byte)(in_fpscr >> 0x15) & 3);
          iVar8 = iVar8 * iVar7 + 0x3039;
          param_1[0x22] = iVar8 * iVar7 + 0x3039;
          fVar18 = (float)VectorUnsignedToFloat(iVar8,(byte)(in_fpscr >> 0x15) & 3);
          if (uVar5 < 0x7fffffff) {
            fVar17 = fVar23 * (fVar17 * fVar15 * fVar22 - fVar14);
            if (uVar6 < 0x7fffffff) {
              puVar4[4] = ALBW_AS_U32(fVar24);
              puVar4[2] = ALBW_AS_U32(fVar17);
              puVar4[3] = ALBW_AS_U32(fVar25);
            }
            else {
              puVar4[2] = ALBW_AS_U32(fVar17);
              puVar4[3] = ALBW_AS_U32(fVar25);
              puVar4[4] = ALBW_AS_U32(-fVar24);
            }
          }
          else {
            fVar17 = fVar24 * (fVar18 * fVar15 * fVar22 - fVar14);
            if (uVar6 < 0x7fffffff) {
              puVar4[2] = ALBW_AS_U32(fVar23);
              puVar4[3] = ALBW_AS_U32(fVar25);
              puVar4[4] = ALBW_AS_U32(fVar17);
            }
            else {
              puVar4[2] = ALBW_AS_U32(-fVar23);
              puVar4[3] = ALBW_AS_U32(fVar25);
              puVar4[4] = ALBW_AS_U32(fVar17);
            }
          }
          fVar17 = ALBW_AS_F32(puVar4[2]);
          uVar5 = in_fpscr & 0xfffffff | (uint)(fVar17 == fVar25) << 0x1e;
          bVar11 = false;
          if (SUB41(uVar5 >> 0x1e,0)) {
            uVar5 = in_fpscr & 0xfffffff | (uint)(ALBW_AS_F32(puVar4[4]) == fVar25) << 0x1e;
            bVar11 = SUB41(uVar5 >> 0x1e,0);
          }
          if (!bVar11) {
            fVar16 = ALBW_AS_F32(puVar4[4]);
            fVar18 = fVar14 / SQRT(fVar17 * fVar17 + ALBW_AS_F32(puVar4[3]) * ALBW_AS_F32(puVar4[3]) +
                                   fVar16 * fVar16);
            fVar13 = fVar17 * fVar18;
            fVar16 = fVar16 * fVar18;
          }
          fVar17 = *(float *)(iVar10 + 0x310);
          puVar4[9] = ALBW_AS_U32(fVar25);
          in_fpscr = uVar5 & 0xfffffff | (uint)(fVar17 == fVar25) << 0x1e;
          fVar13 = fVar13 * fVar21;
          fVar16 = fVar16 * fVar21;
          puVar4[8] = ALBW_AS_U32(fVar13);
          puVar4[10] = ALBW_AS_U32(fVar16);
          if (!SUB41(in_fpscr >> 0x1e,0)) {
            fVar17 = ALBW_AS_F32(puVar4[2]);
            fVar16 = ALBW_AS_F32(puVar4[4]);
            if ((int)ALBW_AS_U32((fVar17 * fVar17 + fVar25 * fVar25 + fVar16 * fVar16)) < 0x800001) {
              iVar7 = param_1[0x22] * DAT_003ea9b8 + 0x3039;
              fVar16 = (float)VectorUnsignedToFloat(param_1[0x22],(byte)(in_fpscr >> 0x15) & 3);
              fVar13 = (float)VectorUnsignedToFloat(iVar7,(byte)(in_fpscr >> 0x15) & 3);
              param_1[0x22] = iVar7 * DAT_003ea9b8 + 0x3039;
              fVar17 = fVar16 * fVar15 * fVar22 - fVar14;
              fVar16 = fVar13 * fVar15 * fVar22 - fVar14;
            }
            fVar20 = fVar17 * fVar17 + fVar25 * fVar25 + fVar16 * fVar16;
            in_fpscr = uVar5 & 0xfffffff | (uint)(fVar20 == fVar25) << 0x1e;
            fVar18 = fVar25;
            fVar13 = fVar25;
            fVar19 = fVar25;
            if (!SUB41(in_fpscr >> 0x1e,0)) {
              fVar14 = fVar14 / SQRT(fVar20);
              fVar18 = fVar17 * fVar14;
              fVar13 = fVar16 * fVar14;
              fVar19 = fVar25 * fVar14;
            }
            fVar16 = *(float *)(iVar10 + 0x310);
            fVar13 = fVar13 * fVar16;
            puVar4[8] = ALBW_AS_U32(ALBW_AS_F32(puVar4[8]) + fVar18 * fVar16);
            puVar4[9] = ALBW_AS_U32(ALBW_AS_F32(puVar4[9]) + fVar19 * fVar16);
            puVar4[10] = ALBW_AS_U32(ALBW_AS_F32(puVar4[10]) + fVar13);
          }
          if ((*(uint *)(param_1[0x36] + 4) & 0x400000) == 0) {
            func_003E728C((int)param_1,puVar4);
          }
          else {
            func_003E8730((int)param_1,puVar4);
          }
        }
        iVar9 = iVar9 + 1;
      } while (iVar9 < iVar12);
    }
    param_1[2] = param_1[2] | 8;
  }
  return puVar2;
}

