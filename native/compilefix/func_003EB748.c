/* compilefix: USA 003EB748 (EU 003EB728), the converted stage-2 text.
 * Fixed (BOOT_LOG 184): the ARM copies this word between a float and an integer (no vcvt), which the
 * converted text wrote as a conversion of the value. */
#include "ghidra_types.h"

extern undefined8 func_00114608(uint param_1,uint param_2);
extern int func_003E728C(int param_1,undefined4 *param_2);
extern int func_003E8730(int param_1,undefined4 *param_2);
extern int func_003F856C(int param_1,undefined4 param_2);
extern float DAT_003ebae8;
extern float DAT_003ebaec;
extern float DAT_003ebaf0;
extern float DAT_003ebaf4;
extern float DAT_003ebaf8;
extern uint DAT_003ebafc;
extern float DAT_003ebb00;
extern undefined4 DAT_003ebb04;
extern undefined4 DAT_003ebb08;
extern int *DAT_003ebb0c;
extern int DAT_003ebb10;

// USA 003EB748 <- EU 003EB728 (Ghidra, non-matching)
// GLOBAL DAT_003ebae8 float
// GLOBAL DAT_003ebaec float
// GLOBAL DAT_003ebaf0 float
// GLOBAL DAT_003ebaf4 float
// GLOBAL DAT_003ebaf8 float
// GLOBAL DAT_003ebafc uint
// GLOBAL DAT_003ebb00 float
// GLOBAL DAT_003ebb04 undefined4
// GLOBAL DAT_003ebb08 undefined4
// GLOBAL DAT_003ebb0c int *
// GLOBAL DAT_003ebb10 int

undefined4 * func_003EB748(int *param_1)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  byte bVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  int iVar8;
  float *pfVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  bool bVar13;
  uint in_fpscr;
  int iVar14;
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
  float fVar27;
  float fVar28;
  float fVar29;
  float fVar30;
  float fVar31;
  undefined8 in_d13;
  undefined8 uVar32;
  
  fVar30 = DAT_003ebaec;
  fVar31 = DAT_003ebae8;
  fVar20 = *(float *)param_1[7];
  iVar11 = param_1[6];
  iVar12 = param_1[0x36];
  fVar16 = ALBW_AS_F32(param_1[0x8b]) + ALBW_AS_F32(param_1[0x5a]) * fVar20;
  param_1[0x8b] = (int)ALBW_AS_U32(fVar16);
  if ((*param_1 == 0) && ((int)ALBW_AS_U32(fVar16) < 0x3f800000)) {
    in_fpscr = in_fpscr & 0xfffffff | (uint)(ALBW_AS_F32(param_1[0x5a]) * fVar20 == fVar31) << 0x1e;
    if (!SUB41(in_fpscr >> 0x1e,0)) {
      param_1[0x8b] = (int)ALBW_AS_U32(fVar30);
    }
  }
  puVar5 = (undefined4 *)(uint)*(byte *)(iVar12 + 0x181);
  iVar14 = (int)ALBW_AS_F32(param_1[0x8b]);
  if (puVar5 != (undefined4 *)0x0) {
    iVar14 = 1;
  }
  if (iVar14 == 0) {
    puVar5 = (undefined4 *)0x0;
  }
  fVar16 = (float)VectorSignedToFloat(iVar14,(byte)(in_fpscr >> 0x15) & 3);
  param_1[0x8b] = (int)ALBW_AS_U32(ALBW_AS_F32(param_1[0x8b]) - fVar16);
  fVar15 = DAT_003ebb00;
  fVar20 = DAT_003ebaf8;
  fVar16 = DAT_003ebaf4;
  if (iVar14 != 0) {
    fVar25 = (float)VectorUnsignedToFloat
                              (*(undefined4 *)(iVar12 + 0x264),(byte)(in_fpscr >> 0x15) & 3);
    fVar17 = (float)VectorSignedToFloat(*(undefined4 *)(iVar12 + 0x260),(byte)(in_fpscr >> 0x15) & 3
                                       );
    fVar26 = ALBW_AS_F32(param_1[0x69]) * *(float *)(iVar11 + 0x23c);
    fVar25 = fVar25 * DAT_003ebaf0;
    fVar27 = *(float *)(iVar12 + 0x254) * *(float *)(iVar11 + 0x220) * ALBW_AS_F32(param_1[0x70]);
    fVar28 = *(float *)(iVar12 + 600) * *(float *)(iVar11 + 0x224) * ALBW_AS_F32(param_1[0x71]);
    fVar29 = *(float *)(iVar12 + 0x25c) * *(float *)(iVar11 + 0x228) * ALBW_AS_F32(param_1[0x72]);
    fVar17 = fVar17 * DAT_003ebaf0;
    if (*(char *)(iVar12 + 0x17f) != '\0') {
      fVar17 = (float)VectorUnsignedToFloat(param_1[0x22],(byte)(in_fpscr >> 0x15) & 3);
      param_1[0x22] = param_1[0x22] * DAT_003ebafc + 0x3039;
      fVar17 = fVar17 * fVar16 * fVar15 * fVar20;
    }
    puVar5 = (undefined4 *)0x0;
    if (0 < iVar14) {
      in_d13 = CONCAT44(DAT_003ebb08,DAT_003ebb04);
    }
    iVar11 = 0;
    if (0 < iVar14) {
      do {
        uVar6 = (**(code **)(*(int *)param_1[0x35] + 0xc))((int *)param_1[0x35]);
        puVar7 = (undefined4 *)func_003F856C(*DAT_003ebb0c,uVar6);
        if (puVar7 != (undefined4 *)0x0) {
          if (puVar5 == (undefined4 *)0x0) {
            puVar5 = puVar7;
          }
          puVar7[0x4e] = iVar12;
          uVar1 = DAT_003ebafc;
          iVar8 = param_1[0x22];
          puVar7[0x52] = 0;
          fVar15 = (float)VectorUnsignedToFloat(iVar8,(byte)(in_fpscr >> 0x15) & 3);
          iVar8 = iVar8 * uVar1 + 0x3039;
          param_1[0x22] = iVar8;
          uVar32 = func_00114608((uint)ALBW_AS_U32(((fVar17 + fVar15 * fVar16 * fVar25) * ALBW_AS_F32(in_d13))),uVar1);
          fVar22 = (float)VectorUnsignedToFloat(iVar8,(byte)(in_fpscr >> 0x15) & 3);
          fVar18 = fVar30 - *(float *)(iVar12 + 0x26c);
          pfVar9 = (float *)(DAT_003ebb10 + ((uint)uVar32 >> 0x18) * 0x10);
          fVar23 = pfVar9[1];
          fVar24 = pfVar9[3];
          fVar15 = (float)VectorUnsignedToFloat
                                    ((uint)uVar32 & 0xffffff,(byte)(in_fpscr >> 0x15) & 3);
          fVar19 = *pfVar9;
          fVar21 = pfVar9[2];
          iVar8 = iVar8 * DAT_003ebafc + 0x3039;
          param_1[0x22] = iVar8;
          fVar15 = fVar15 * ALBW_AS_F32(((ulonglong)in_d13 >> 0x20));
          fVar22 = fVar22 * fVar16 + fVar18 * fVar18 * (fVar30 - fVar22 * fVar16);
          fVar19 = fVar19 + fVar23 * fVar15;
          fVar21 = fVar21 + fVar24 * fVar15;
          uVar1 = in_fpscr & 0xfffffff;
          uVar2 = uVar1 | (uint)(fVar22 == fVar31) << 0x1e | (uint)(fVar31 <= fVar22) << 0x1d;
          bVar4 = (byte)(uVar2 >> 0x18);
          bVar3 = (bool)(bVar4 >> 6);
          bVar13 = (bool)(bVar4 >> 5 & 1);
          fVar18 = fVar31;
          if (bVar13 && !bVar3) {
            fVar15 = SQRT(fVar22);
            fVar18 = fVar22;
          }
          iVar10 = iVar8 * DAT_003ebafc;
          fVar22 = *(float *)(iVar12 + 0x310);
          if (bVar13 && !bVar3) {
            fVar18 = fVar15;
          }
          puVar7[8] = ALBW_AS_U32(fVar19 * fVar26);
          puVar7[10] = ALBW_AS_U32(fVar21 * fVar26);
          fVar15 = (float)VectorUnsignedToFloat(iVar8,(byte)(uVar2 >> 0x15) & 3);
          param_1[0x22] = iVar10 + 0x3039;
          puVar7[9] = ALBW_AS_U32(fVar31);
          in_fpscr = uVar1 | (uint)(fVar22 == fVar31) << 0x1e;
          fVar22 = fVar19 * fVar18 * fVar27;
          puVar7[4] = ALBW_AS_U32(fVar21 * fVar18 * fVar29);
          puVar7[2] = ALBW_AS_U32(fVar22);
          puVar7[3] = ALBW_AS_U32((fVar15 * fVar16 * fVar20 - fVar30) * fVar28);
          if (!SUB41(in_fpscr >> 0x1e,0)) {
            fVar15 = ALBW_AS_F32(puVar7[4]);
            if ((int)ALBW_AS_U32((fVar22 * fVar22 + fVar31 * fVar31 + fVar15 * fVar15)) < 0x800001) {
              iVar8 = param_1[0x22] * DAT_003ebafc + 0x3039;
              fVar18 = (float)VectorUnsignedToFloat(param_1[0x22],(byte)(in_fpscr >> 0x15) & 3);
              fVar15 = (float)VectorUnsignedToFloat(iVar8,(byte)(in_fpscr >> 0x15) & 3);
              param_1[0x22] = iVar8 * DAT_003ebafc + 0x3039;
              fVar22 = fVar18 * fVar16 * fVar20 - fVar30;
              fVar15 = fVar15 * fVar16 * fVar20 - fVar30;
            }
            fVar23 = fVar22 * fVar22 + fVar31 * fVar31 + fVar15 * fVar15;
            in_fpscr = uVar1 | (uint)(fVar23 == fVar31) << 0x1e;
            fVar18 = fVar31;
            fVar19 = fVar31;
            fVar21 = fVar31;
            if (!SUB41(in_fpscr >> 0x1e,0)) {
              fVar21 = fVar30 / SQRT(fVar23);
              fVar18 = fVar15 * fVar21;
              fVar19 = fVar22 * fVar21;
              fVar21 = fVar31 * fVar21;
            }
            fVar15 = *(float *)(iVar12 + 0x310);
            puVar7[8] = ALBW_AS_U32(ALBW_AS_F32(puVar7[8]) + fVar19 * fVar15);
            puVar7[9] = ALBW_AS_U32(ALBW_AS_F32(puVar7[9]) + fVar21 * fVar15);
            puVar7[10] = ALBW_AS_U32(ALBW_AS_F32(puVar7[10]) + fVar18 * fVar15);
          }
          if ((*(uint *)(param_1[0x36] + 4) & 0x400000) == 0) {
            func_003E728C((int)param_1,puVar7);
          }
          else {
            func_003E8730((int)param_1,puVar7);
          }
        }
        iVar11 = iVar11 + 1;
      } while (iVar11 < iVar14);
    }
    param_1[2] = param_1[2] | 8;
  }
  return puVar5;
}

