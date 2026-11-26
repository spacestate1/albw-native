/* compilefix: USA 003EEC6C (EU 003EEC4C), the converted stage-2 text.
 * Fixed (BOOT_LOG 184): the ARM copies this word between a float and an integer (no vcvt), which the
 * converted text wrote as a conversion of the value. */
#include "ghidra_types.h"

extern int func_003E728C(int param_1,undefined4 *param_2);
extern int func_003E8730(int param_1,undefined4 *param_2);
extern int func_003F856C(int param_1,undefined4 param_2);
extern float DAT_003eeee8;
extern float DAT_003eeeec;
extern int *DAT_003eeef0;
extern float DAT_003eeef4;
extern float DAT_003eeef8;
extern float DAT_003eeefc;
extern int DAT_003eef00;

// USA 003EEC6C <- EU 003EEC4C (Ghidra, non-matching)
// GLOBAL DAT_003eeee8 float
// GLOBAL DAT_003eeeec float
// GLOBAL DAT_003eeef0 int *
// GLOBAL DAT_003eeef4 float
// GLOBAL DAT_003eeef8 float
// GLOBAL DAT_003eeefc float
// GLOBAL DAT_003eef00 int

undefined4 * func_003EEC6C(int *param_1)

{
  uint uVar1;
  float *pfVar2;
  float *pfVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint in_fpscr;
  float fVar12;
  int iVar13;
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
  float fVar26;
  
  fVar25 = DAT_003eeeec;
  fVar24 = DAT_003eeee8;
  fVar15 = *(float *)param_1[7];
  puVar5 = (undefined4 *)param_1[6];
  iVar11 = param_1[0x36];
  fVar12 = ALBW_AS_F32(param_1[0x8b]) + ALBW_AS_F32(param_1[0x5a]) * fVar15;
  param_1[0x8b] = (int)ALBW_AS_U32(fVar12);
  if ((*param_1 == 0) && ((int)ALBW_AS_U32(fVar12) < 0x3f800000)) {
    in_fpscr = in_fpscr & 0xfffffff | (uint)(ALBW_AS_F32(param_1[0x5a]) * fVar15 == fVar24) << 0x1e;
    if (!SUB41(in_fpscr >> 0x1e,0)) {
      param_1[0x8b] = (int)ALBW_AS_U32(fVar25);
    }
  }
  iVar13 = (int)ALBW_AS_F32(param_1[0x8b]);
  if (*(char *)(iVar11 + 0x181) != '\0') {
    iVar13 = 1;
  }
  if (iVar13 == 0) {
    puVar5 = (undefined4 *)0x0;
  }
  fVar12 = (float)VectorSignedToFloat(iVar13,(byte)(in_fpscr >> 0x15) & 3);
  param_1[0x8b] = (int)ALBW_AS_U32(ALBW_AS_F32(param_1[0x8b]) - fVar12);
  piVar4 = DAT_003eeef0;
  if (iVar13 != 0) {
    pfVar2 = (float *)(puVar5 + 0x8a);
    pfVar3 = (float *)(puVar5 + 0x8f);
    puVar5 = (undefined4 *)0x0;
    fVar22 = ALBW_AS_F32(param_1[0x69]) * *pfVar3;
    iVar10 = 0;
    fVar21 = *(float *)(iVar11 + 0x25c) * *pfVar2 * ALBW_AS_F32(param_1[0x70]);
    fVar23 = *(float *)(iVar11 + 0x280) * fVar21;
    fVar12 = DAT_003eeef8;
    fVar15 = DAT_003eeef4;
    fVar26 = DAT_003eeefc;
    if (0 < iVar13) {
      do {
        uVar6 = (**(code **)(*(int *)param_1[0x35] + 0xc))((int *)param_1[0x35]);
        puVar7 = (undefined4 *)func_003F856C(*piVar4,uVar6);
        iVar9 = DAT_003eef00;
        if (puVar7 != (undefined4 *)0x0) {
          if (puVar5 == (undefined4 *)0x0) {
            puVar5 = puVar7;
          }
          iVar8 = param_1[0x22];
          fVar16 = *(float *)(iVar11 + 0x310);
          puVar7[0x4e] = iVar11;
          uVar1 = in_fpscr & 0xfffffff;
          in_fpscr = uVar1 | (uint)(fVar16 == fVar24) << 0x1e;
          puVar7[0x52] = 0;
          fVar16 = (float)VectorUnsignedToFloat(iVar8,(byte)(in_fpscr >> 0x15) & 3);
          puVar7[10] = ALBW_AS_U32(fVar22);
          puVar7[2] = ALBW_AS_U32(fVar24);
          puVar7[3] = ALBW_AS_U32(fVar24);
          puVar7[8] = ALBW_AS_U32(fVar24);
          puVar7[9] = ALBW_AS_U32(fVar24);
          param_1[0x22] = iVar8 * iVar9 + 0x3039;
          puVar7[4] = ALBW_AS_U32(fVar16 * fVar12 * fVar21 - (fVar21 + fVar23) * fVar15);
          if (!SUB41(in_fpscr >> 0x1e,0)) {
            fVar17 = ALBW_AS_F32(puVar7[2]);
            fVar16 = ALBW_AS_F32(puVar7[4]);
            if ((int)ALBW_AS_U32((fVar17 * fVar17 + fVar24 * fVar24 + fVar16 * fVar16)) < 0x800001) {
              iVar9 = param_1[0x22] * iVar9 + 0x3039;
              fVar17 = (float)VectorUnsignedToFloat(param_1[0x22],(byte)(in_fpscr >> 0x15) & 3);
              fVar16 = (float)VectorUnsignedToFloat(iVar9,(byte)(in_fpscr >> 0x15) & 3);
              param_1[0x22] = iVar9 * DAT_003eef00 + 0x3039;
              fVar17 = fVar17 * fVar12 * fVar26 - fVar25;
              fVar16 = fVar16 * fVar12 * fVar26 - fVar25;
            }
            fVar19 = fVar17 * fVar17 + fVar24 * fVar24 + fVar16 * fVar16;
            in_fpscr = uVar1 | (uint)(fVar19 == fVar24) << 0x1e;
            fVar14 = fVar24;
            fVar18 = fVar24;
            fVar20 = fVar24;
            if (!SUB41(in_fpscr >> 0x1e,0)) {
              fVar20 = fVar25 / SQRT(fVar19);
              fVar14 = fVar17 * fVar20;
              fVar18 = fVar24 * fVar20;
              fVar20 = fVar16 * fVar20;
            }
            fVar16 = *(float *)(iVar11 + 0x310);
            puVar7[8] = ALBW_AS_U32(ALBW_AS_F32(puVar7[8]) + fVar14 * fVar16);
            puVar7[9] = ALBW_AS_U32(ALBW_AS_F32(puVar7[9]) + fVar18 * fVar16);
            puVar7[10] = ALBW_AS_U32(ALBW_AS_F32(puVar7[10]) + fVar20 * fVar16);
          }
          if ((*(uint *)(param_1[0x36] + 4) & 0x400000) == 0) {
            func_003E728C((int)param_1,puVar7);
          }
          else {
            func_003E8730((int)param_1,puVar7);
          }
        }
        iVar10 = iVar10 + 1;
      } while (iVar10 < iVar13);
    }
    param_1[2] = param_1[2] | 8;
  }
  return puVar5;
}

