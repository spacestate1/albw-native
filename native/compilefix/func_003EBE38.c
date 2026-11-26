/* compilefix: USA 003EBE38 (EU 003EBE18), the converted stage-2 text.
 * Fixed (BOOT_LOG 184): the ARM copies this word between a float and an integer (no vcvt), which the
 * converted text wrote as a conversion of the value. */
#include "ghidra_types.h"

extern int func_003E728C(int param_1,undefined4 *param_2);
extern int func_003E8730(int param_1,undefined4 *param_2);
extern int func_003F856C(int param_1,undefined4 param_2);
extern float DAT_003ec0c4;
extern float DAT_003ec0c8;
extern float DAT_003ec0cc;
extern int *DAT_003ec0d0;
extern float DAT_003ec0d4;
extern float DAT_003ec0d8;
extern int DAT_003ec0dc;

// USA 003EBE38 <- EU 003EBE18 (Ghidra, non-matching)
// GLOBAL DAT_003ec0c4 float
// GLOBAL DAT_003ec0c8 float
// GLOBAL DAT_003ec0cc float
// GLOBAL DAT_003ec0d0 int *
// GLOBAL DAT_003ec0d4 float
// GLOBAL DAT_003ec0d8 float
// GLOBAL DAT_003ec0dc int

undefined4 * func_003EBE38(int *param_1)

{
  uint uVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint in_fpscr;
  float fVar9;
  float fVar10;
  float fVar11;
  int iVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  undefined8 in_d8;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  
  fVar23 = DAT_003ec0c8;
  fVar21 = DAT_003ec0c4;
  fVar14 = *(float *)param_1[7];
  iVar8 = param_1[0x36];
  fVar11 = ALBW_AS_F32(param_1[0x8b]) + ALBW_AS_F32(param_1[0x5a]) * fVar14;
  param_1[0x8b] = (int)ALBW_AS_U32(fVar11);
  if ((*param_1 == 0) && ((int)ALBW_AS_U32(fVar11) < 0x3f800000)) {
    in_fpscr = in_fpscr & 0xfffffff | (uint)(ALBW_AS_F32(param_1[0x5a]) * fVar14 == fVar21) << 0x1e;
    if (!SUB41(in_fpscr >> 0x1e,0)) {
      param_1[0x8b] = (int)ALBW_AS_U32(fVar23);
    }
  }
  puVar3 = (undefined4 *)(uint)*(byte *)(iVar8 + 0x181);
  iVar12 = (int)ALBW_AS_F32(param_1[0x8b]);
  if (puVar3 != (undefined4 *)0x0) {
    iVar12 = 1;
  }
  if (iVar12 == 0) {
    puVar3 = (undefined4 *)0x0;
  }
  fVar11 = (float)VectorSignedToFloat(iVar12,(byte)(in_fpscr >> 0x15) & 3);
  param_1[0x8b] = (int)ALBW_AS_U32(ALBW_AS_F32(param_1[0x8b]) - fVar11);
  piVar2 = DAT_003ec0d0;
  if (iVar12 != 0) {
    fVar19 = ALBW_AS_F32(param_1[0x69]) * *(float *)(param_1[6] + 0x23c);
    fVar11 = ALBW_AS_F32(((ulonglong)in_d8 >> 0x20));
    fVar14 = fVar21;
    if (iVar12 == 1) {
      fVar11 = fVar21;
      fVar14 = DAT_003ec0cc;
    }
    fVar18 = *(float *)(iVar8 + 0x25c) * *(float *)(param_1[6] + 0x228) * ALBW_AS_F32(param_1[0x70]);
    fVar20 = *(float *)(iVar8 + 0x280) * fVar18;
    if (iVar12 != 1) {
      fVar11 = (float)VectorSignedToFloat(iVar12 + -1,(byte)(in_fpscr >> 0x15) & 3);
      fVar11 = fVar23 / fVar11;
    }
    puVar3 = (undefined4 *)0x0;
    iVar7 = 0;
    fVar22 = DAT_003ec0cc;
    fVar24 = DAT_003ec0d4;
    fVar25 = DAT_003ec0d8;
    if (0 < iVar12) {
      do {
        uVar4 = (**(code **)(*(int *)param_1[0x35] + 0xc))((int *)param_1[0x35]);
        puVar5 = (undefined4 *)func_003F856C(*piVar2,uVar4);
        if (puVar5 != (undefined4 *)0x0) {
          fVar15 = fVar14 * fVar18;
          fVar14 = fVar14 + fVar11;
          fVar9 = *(float *)(iVar8 + 0x310);
          puVar5[0x4e] = iVar8;
          puVar5[0x52] = 0;
          puVar5[10] = ALBW_AS_U32(fVar19);
          uVar1 = in_fpscr & 0xfffffff;
          in_fpscr = uVar1 | (uint)(fVar9 == fVar21) << 0x1e;
          puVar5[2] = ALBW_AS_U32(fVar21);
          if (puVar3 == (undefined4 *)0x0) {
            puVar3 = puVar5;
          }
          puVar5[3] = ALBW_AS_U32(fVar21);
          puVar5[8] = ALBW_AS_U32(fVar21);
          puVar5[9] = ALBW_AS_U32(fVar21);
          puVar5[4] = ALBW_AS_U32(fVar15 - (fVar18 + fVar20) * fVar22);
          if (!SUB41(in_fpscr >> 0x1e,0)) {
            fVar15 = ALBW_AS_F32(puVar5[4]);
            fVar9 = fVar21;
            if ((int)ALBW_AS_U32((fVar21 + fVar15 * fVar15)) < 0x800001) {
              iVar6 = param_1[0x22] * DAT_003ec0dc + 0x3039;
              fVar9 = (float)VectorUnsignedToFloat(param_1[0x22],(byte)(in_fpscr >> 0x15) & 3);
              fVar15 = (float)VectorUnsignedToFloat(iVar6,(byte)(in_fpscr >> 0x15) & 3);
              param_1[0x22] = iVar6 * DAT_003ec0dc + 0x3039;
              fVar9 = fVar9 * fVar24 * fVar25 - fVar23;
              fVar15 = fVar15 * fVar24 * fVar25 - fVar23;
            }
            fVar17 = fVar9 * fVar9 + fVar21 * fVar21 + fVar15 * fVar15;
            in_fpscr = uVar1 | (uint)(fVar17 == fVar21) << 0x1e;
            fVar13 = fVar21;
            fVar16 = fVar21;
            fVar10 = fVar21;
            if (!SUB41(in_fpscr >> 0x1e,0)) {
              fVar10 = fVar23 / SQRT(fVar17);
              fVar13 = fVar9 * fVar10;
              fVar16 = fVar15 * fVar10;
              fVar10 = fVar21 * fVar10;
            }
            fVar9 = *(float *)(iVar8 + 0x310);
            puVar5[8] = ALBW_AS_U32(ALBW_AS_F32(puVar5[8]) + fVar13 * fVar9);
            puVar5[9] = ALBW_AS_U32(ALBW_AS_F32(puVar5[9]) + fVar10 * fVar9);
            puVar5[10] = ALBW_AS_U32(ALBW_AS_F32(puVar5[10]) + fVar16 * fVar9);
          }
          if ((*(uint *)(param_1[0x36] + 4) & 0x400000) == 0) {
            func_003E728C((int)param_1,puVar5);
          }
          else {
            func_003E8730((int)param_1,puVar5);
          }
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 < iVar12);
    }
    param_1[2] = param_1[2] | 8;
  }
  return puVar3;
}

