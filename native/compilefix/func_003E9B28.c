/* compilefix: USA 003E9B28 (EU 003E9B08), the converted stage-2 text.
 * Fixed (BOOT_LOG 184): the ARM copies this word between a float and an integer (no vcvt), which the
 * converted text wrote as a conversion of the value. */
#include "ghidra_types.h"

extern int func_003E728C(int param_1,undefined4 *param_2);
extern int func_003E8730(int param_1,undefined4 *param_2);
extern int func_003F856C(int param_1,undefined4 param_2);
extern float DAT_003e9e30;
extern float DAT_003e9e34;
extern int *DAT_003e9e38;
extern float DAT_003e9e3c;
extern float DAT_003e9e40;
extern float DAT_003e9e44;
extern int DAT_003e9e48;

// USA 003E9B28 <- EU 003E9B08 (Ghidra, non-matching)
// GLOBAL DAT_003e9e30 float
// GLOBAL DAT_003e9e34 float
// GLOBAL DAT_003e9e38 int *
// GLOBAL DAT_003e9e3c float
// GLOBAL DAT_003e9e40 float
// GLOBAL DAT_003e9e44 float
// GLOBAL DAT_003e9e48 int

undefined4 * func_003E9B28(int *param_1)

{
  uint uVar1;
  float *pfVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  float *pfVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  bool bVar13;
  bool bVar14;
  float *pfVar15;
  uint in_fpscr;
  uint uVar16;
  float fVar17;
  int iVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  float fVar29;
  float fVar30;
  float fVar31;
  float fVar32;
  float fVar33;
  float fVar34;
  
  fVar32 = DAT_003e9e34;
  fVar33 = DAT_003e9e30;
  fVar21 = *(float *)param_1[7];
  puVar5 = (undefined4 *)param_1[6];
  iVar12 = param_1[0x36];
  fVar17 = ALBW_AS_F32(param_1[0x8b]) + ALBW_AS_F32(param_1[0x5a]) * fVar21;
  param_1[0x8b] = (int)ALBW_AS_U32(fVar17);
  if ((*param_1 == 0) && ((int)ALBW_AS_U32(fVar17) < 0x3f800000)) {
    in_fpscr = in_fpscr & 0xfffffff | (uint)(ALBW_AS_F32(param_1[0x5a]) * fVar21 == fVar33) << 0x1e;
    if (!SUB41(in_fpscr >> 0x1e,0)) {
      param_1[0x8b] = (int)ALBW_AS_U32(fVar32);
    }
  }
  iVar18 = (int)ALBW_AS_F32(param_1[0x8b]);
  if (*(char *)(iVar12 + 0x181) != '\0') {
    iVar18 = 1;
  }
  if (iVar18 == 0) {
    puVar5 = (undefined4 *)0x0;
  }
  fVar17 = (float)VectorSignedToFloat(iVar18,(byte)(in_fpscr >> 0x15) & 3);
  param_1[0x8b] = (int)ALBW_AS_U32(ALBW_AS_F32(param_1[0x8b]) - fVar17);
  piVar3 = DAT_003e9e38;
  if (iVar18 != 0) {
    pfVar2 = (float *)(puVar5 + 0x8f);
    pfVar6 = (float *)(puVar5 + 0x89);
    fVar22 = *(float *)(iVar12 + 0x254) * ALBW_AS_F32(puVar5[0x88]);
    pfVar15 = (float *)(puVar5 + 0x8a);
    puVar5 = (undefined4 *)0x0;
    fVar20 = ALBW_AS_F32(param_1[0x71]);
    fVar19 = ALBW_AS_F32(param_1[0x72]);
    fVar27 = ALBW_AS_F32(param_1[0x69]) * *pfVar2;
    fVar29 = fVar22 * ALBW_AS_F32(param_1[0x70]);
    iVar11 = 0;
    fVar30 = *(float *)(iVar12 + 600) * *pfVar6 * fVar20;
    fVar31 = *(float *)(iVar12 + 0x25c) * *pfVar15 * fVar19;
    fVar17 = DAT_003e9e44;
    fVar21 = DAT_003e9e3c;
    fVar34 = DAT_003e9e40;
    if (0 < iVar18) {
      do {
        uVar7 = (**(code **)(*(int *)param_1[0x35] + 0xc))((int *)param_1[0x35]);
        puVar8 = (undefined4 *)func_003F856C(*piVar3,uVar7);
        if (puVar8 != (undefined4 *)0x0) {
          if (puVar5 == (undefined4 *)0x0) {
            puVar5 = puVar8;
          }
          fVar28 = fVar32 - *(float *)(iVar12 + 0x26c);
          puVar8[0x4e] = iVar12;
          puVar8[0x52] = 0;
          iVar9 = DAT_003e9e48;
          if (fVar28 == 1.0) {
            fVar28 = fVar21;
          }
          uVar1 = in_fpscr & 0xfffffff;
          if (fVar28 == fVar33) {
            fVar28 = (float)VectorUnsignedToFloat(param_1[0x22],(byte)(uVar1 >> 0x15) & 3);
            iVar9 = param_1[0x22] * DAT_003e9e48 + 0x3039;
            fVar25 = (float)VectorUnsignedToFloat(iVar9,(byte)(uVar1 >> 0x15) & 3);
            iVar9 = iVar9 * DAT_003e9e48 + 0x3039;
            fVar23 = (float)VectorUnsignedToFloat(iVar9,(byte)(uVar1 >> 0x15) & 3);
            param_1[0x22] = iVar9 * DAT_003e9e48 + 0x3039;
            puVar8[2] = ALBW_AS_U32((fVar28 * fVar34 * fVar17 - fVar32) * fVar29);
            puVar8[3] = ALBW_AS_U32((fVar25 * fVar34 * fVar17 - fVar32) * fVar30);
            puVar8[4] = ALBW_AS_U32((fVar23 * fVar34 * fVar17 - fVar32) * fVar31);
            uVar16 = uVar1;
          }
          else {
            fVar25 = (float)VectorUnsignedToFloat(param_1[0x22],(byte)(uVar1 >> 0x15) & 3);
            fVar23 = fVar32 - fVar28;
            iVar10 = param_1[0x22] * DAT_003e9e48 + 0x3039;
            param_1[0x22] = iVar10;
            iVar4 = DAT_003e9e48;
            fVar25 = (fVar32 - fVar28 * fVar28 * fVar28) * fVar25 * fVar34;
            uVar16 = uVar1 | (uint)(fVar23 < fVar25) << 0x1f;
            if (fVar23 == fVar25 || SUB41(uVar16 >> 0x1f,0) != (NAN(fVar23) || NAN(fVar25))) {
              fVar24 = fVar23 + fVar23 * fVar28;
              uVar16 = uVar1 | (uint)(fVar24 < fVar25) << 0x1f;
              if (fVar24 == fVar25 || SUB41(uVar16 >> 0x1f,0) != (NAN(fVar24) || NAN(fVar25))) {
                iVar9 = iVar10 * DAT_003e9e48 + 0x3039;
                fVar24 = (float)VectorUnsignedToFloat(iVar10,(byte)(uVar16 >> 0x15) & 3);
                fVar25 = (float)VectorUnsignedToFloat(iVar9,(byte)(uVar16 >> 0x15) & 3);
                iVar9 = iVar9 * DAT_003e9e48 + 0x3039;
                fVar26 = (float)VectorUnsignedToFloat(iVar9,(byte)(uVar16 >> 0x15) & 3);
                param_1[0x22] = iVar9 * DAT_003e9e48 + 0x3039;
                puVar8[4] = ALBW_AS_U32(fVar28 + fVar26 * fVar34 * fVar23);
                puVar8[2] = ALBW_AS_U32(fVar24 * fVar34 * fVar28);
                puVar8[3] = ALBW_AS_U32(fVar25 * fVar34 * fVar28);
              }
              else {
                fVar24 = (float)VectorUnsignedToFloat(iVar10,(byte)(uVar16 >> 0x15) & 3);
                iVar9 = iVar10 * DAT_003e9e48 + 0x3039;
                fVar26 = (float)VectorUnsignedToFloat(iVar9,(byte)(uVar16 >> 0x15) & 3);
                iVar9 = iVar9 * DAT_003e9e48 + 0x3039;
                fVar25 = (float)VectorUnsignedToFloat(iVar9,(byte)(uVar16 >> 0x15) & 3);
                param_1[0x22] = iVar9 * DAT_003e9e48 + 0x3039;
                puVar8[2] = ALBW_AS_U32(fVar28 + fVar24 * fVar34 * fVar23);
                puVar8[3] = ALBW_AS_U32(fVar26 * fVar34 * fVar28);
                puVar8[4] = ALBW_AS_U32(fVar25 * fVar34);
              }
            }
            else {
              fVar25 = (float)VectorUnsignedToFloat(iVar10,(byte)(uVar16 >> 0x15) & 3);
              iVar10 = iVar10 * iVar9 + 0x3039;
              fVar24 = (float)VectorUnsignedToFloat(iVar10,(byte)(uVar16 >> 0x15) & 3);
              param_1[0x22] = iVar10 * iVar9 + 0x3039;
              puVar8[2] = ALBW_AS_U32(fVar25 * fVar34);
              fVar25 = (float)VectorUnsignedToFloat(param_1[0x22],(byte)(uVar16 >> 0x15) & 3);
              param_1[0x22] = param_1[0x22] * iVar4 + 0x3039;
              puVar8[3] = ALBW_AS_U32(fVar28 + fVar24 * fVar34 * fVar23);
              puVar8[4] = ALBW_AS_U32(fVar25 * fVar34);
            }
            fVar28 = (float)VectorUnsignedToFloat(param_1[0x22],(byte)(uVar16 >> 0x15) & 3);
            param_1[0x22] = param_1[0x22] * DAT_003e9e48 + 0x3039;
            if ((int)ALBW_AS_U32((fVar28 * fVar34)) < 0x3f000000) {
              puVar8[2] = ALBW_AS_U32(-ALBW_AS_F32(puVar8[2]));
            }
            fVar28 = (float)VectorUnsignedToFloat(param_1[0x22],(byte)(uVar16 >> 0x15) & 3);
            param_1[0x22] = param_1[0x22] * DAT_003e9e48 + 0x3039;
            if ((int)ALBW_AS_U32((fVar28 * fVar34)) < 0x3f000000) {
              puVar8[3] = ALBW_AS_U32(-ALBW_AS_F32(puVar8[3]));
            }
            fVar23 = (float)VectorUnsignedToFloat(param_1[0x22],(byte)(uVar16 >> 0x15) & 3);
            param_1[0x22] = param_1[0x22] * DAT_003e9e48 + 0x3039;
            fVar28 = ALBW_AS_F32(puVar8[4]);
            if ((int)ALBW_AS_U32((fVar23 * fVar34)) < 0x3f000000) {
              fVar28 = -fVar28;
              puVar8[4] = ALBW_AS_U32(fVar28);
            }
            puVar8[4] = ALBW_AS_U32(fVar28 * fVar31);
            puVar8[2] = ALBW_AS_U32(ALBW_AS_F32(puVar8[2]) * fVar29);
            puVar8[3] = ALBW_AS_U32(ALBW_AS_F32(puVar8[3]) * fVar30);
          }
          fVar28 = ALBW_AS_F32(puVar8[2]);
          uVar1 = uVar16 & 0xfffffff | (uint)(fVar28 == fVar33) << 0x1e;
          bVar13 = false;
          if (SUB41(uVar1 >> 0x1e,0)) {
            uVar1 = uVar16 & 0xfffffff | (uint)(ALBW_AS_F32(puVar8[3]) == fVar33) << 0x1e;
            bVar13 = SUB41(uVar1 >> 0x1e,0);
          }
          bVar14 = false;
          if (bVar13) {
            uVar1 = uVar1 & 0xfffffff | (uint)(ALBW_AS_F32(puVar8[4]) == fVar33) << 0x1e;
            bVar14 = SUB41(uVar1 >> 0x1e,0);
          }
          if (!bVar14) {
            fVar20 = ALBW_AS_F32(puVar8[3]);
            fVar22 = ALBW_AS_F32(puVar8[4]);
            fVar23 = fVar32 / SQRT(fVar28 * fVar28 + fVar20 * fVar20 + fVar22 * fVar22);
            fVar19 = fVar28 * fVar23;
            fVar20 = fVar20 * fVar23;
            fVar22 = fVar22 * fVar23;
          }
          fVar28 = fVar19 * fVar27;
          fVar20 = fVar20 * fVar27;
          fVar19 = fVar22 * fVar27;
          fVar22 = *(float *)(iVar12 + 0x310);
          in_fpscr = uVar1 & 0xfffffff | (uint)(fVar22 == fVar33) << 0x1e;
          puVar8[8] = ALBW_AS_U32(fVar28);
          puVar8[9] = ALBW_AS_U32(fVar20);
          puVar8[10] = ALBW_AS_U32(fVar19);
          if (!SUB41(in_fpscr >> 0x1e,0)) {
            fVar19 = ALBW_AS_F32(puVar8[2]);
            fVar20 = ALBW_AS_F32(puVar8[4]);
            if ((int)ALBW_AS_U32((fVar19 * fVar19 + fVar33 * fVar33 + fVar20 * fVar20)) < 0x800001) {
              fVar19 = (float)VectorUnsignedToFloat(param_1[0x22],(byte)(in_fpscr >> 0x15) & 3);
              iVar9 = param_1[0x22] * DAT_003e9e48 + 0x3039;
              fVar20 = (float)VectorUnsignedToFloat(iVar9,(byte)(in_fpscr >> 0x15) & 3);
              param_1[0x22] = iVar9 * DAT_003e9e48 + 0x3039;
              fVar19 = fVar19 * fVar34 * fVar17 - fVar32;
              fVar20 = fVar20 * fVar34 * fVar17 - fVar32;
            }
            fVar22 = fVar19 * fVar19 + fVar33 * fVar33 + fVar20 * fVar20;
            in_fpscr = uVar1 & 0xfffffff | (uint)(fVar22 == fVar33) << 0x1e;
            fVar28 = fVar33;
            fVar23 = fVar33;
            fVar25 = fVar33;
            if (!SUB41(in_fpscr >> 0x1e,0)) {
              fVar22 = fVar32 / SQRT(fVar22);
              fVar28 = fVar20 * fVar22;
              fVar23 = fVar19 * fVar22;
              fVar25 = fVar33 * fVar22;
            }
            fVar22 = *(float *)(iVar12 + 0x310);
            puVar8[8] = ALBW_AS_U32(ALBW_AS_F32(puVar8[8]) + fVar23 * fVar22);
            puVar8[9] = ALBW_AS_U32(ALBW_AS_F32(puVar8[9]) + fVar25 * fVar22);
            fVar20 = ALBW_AS_F32(puVar8[10]);
            fVar19 = fVar20 + fVar28 * fVar22;
            puVar8[10] = ALBW_AS_U32(fVar19);
          }
          if ((*(uint *)(param_1[0x36] + 4) & 0x400000) == 0) {
            func_003E728C((int)param_1,puVar8);
          }
          else {
            func_003E8730((int)param_1,puVar8);
          }
        }
        iVar11 = iVar11 + 1;
      } while (iVar11 < iVar18);
    }
    param_1[2] = param_1[2] | 8;
  }
  return puVar5;
}

