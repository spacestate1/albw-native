/* compilefix: USA 003E90EC (EU 003E90CC), the converted stage-2 text.
 * Fixed (BOOT_LOG 184): the ARM copies this word between a float and an integer (no vcvt), which the
 * converted text wrote as a conversion of the value. */
#include "ghidra_types.h"

extern undefined8 func_00114608(uint param_1,uint param_2);
extern int func_003E728C(int param_1,undefined4 *param_2);
extern int func_003E8730(int param_1,undefined4 *param_2);
extern int func_003F856C(int param_1,undefined4 param_2);
extern float DAT_003e93f8;
extern float DAT_003e93fc;
extern float DAT_003e9400;
extern float DAT_003e9404;
extern float DAT_003e9408;
extern uint DAT_003e940c;
extern float DAT_003e9410;
extern float DAT_003e9414;
extern float DAT_003e9418;
extern int *DAT_003e941c;
extern int DAT_003e9420;

// USA 003E90EC <- EU 003E90CC (Ghidra, non-matching)
// GLOBAL DAT_003e93f8 float
// GLOBAL DAT_003e93fc float
// GLOBAL DAT_003e9400 float
// GLOBAL DAT_003e9404 float
// GLOBAL DAT_003e9408 float
// GLOBAL DAT_003e940c uint
// GLOBAL DAT_003e9410 float
// GLOBAL DAT_003e9414 float
// GLOBAL DAT_003e9418 float
// GLOBAL DAT_003e941c int *
// GLOBAL DAT_003e9420 int

undefined4 * func_003E90EC(int *param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  float *pfVar6;
  int iVar7;
  int iVar8;
  uint in_fpscr;
  int iVar9;
  float fVar10;
  float fVar11;
  float fVar12;
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
  undefined8 uVar27;
  
  fVar25 = DAT_003e93fc;
  fVar23 = DAT_003e93f8;
  fVar14 = *(float *)param_1[7];
  puVar2 = (undefined4 *)param_1[6];
  iVar8 = param_1[0x36];
  fVar13 = ALBW_AS_F32(param_1[0x8b]) + ALBW_AS_F32(param_1[0x5a]) * fVar14;
  param_1[0x8b] = (int)ALBW_AS_U32(fVar13);
  if ((*param_1 == 0) && ((int)ALBW_AS_U32(fVar13) < 0x3f800000)) {
    in_fpscr = in_fpscr & 0xfffffff | (uint)(ALBW_AS_F32(param_1[0x5a]) * fVar14 == fVar23) << 0x1e;
    if (!SUB41(in_fpscr >> 0x1e,0)) {
      param_1[0x8b] = (int)ALBW_AS_U32(fVar25);
    }
  }
  iVar9 = (int)ALBW_AS_F32(param_1[0x8b]);
  if (*(char *)(iVar8 + 0x181) != '\0') {
    iVar9 = 1;
  }
  if (iVar9 == 0) {
    puVar2 = (undefined4 *)0x0;
  }
  fVar13 = (float)VectorSignedToFloat(iVar9,(byte)(in_fpscr >> 0x15) & 3);
  param_1[0x8b] = (int)ALBW_AS_U32(ALBW_AS_F32(param_1[0x8b]) - fVar13);
  fVar24 = DAT_003e9410;
  fVar14 = DAT_003e9408;
  fVar13 = DAT_003e9404;
  if (iVar9 != 0) {
    fVar19 = (float)VectorUnsignedToFloat
                              (*(undefined4 *)(iVar8 + 0x264),(byte)(in_fpscr >> 0x15) & 3);
    fVar10 = (float)VectorSignedToFloat(*(undefined4 *)(iVar8 + 0x260),(byte)(in_fpscr >> 0x15) & 3)
    ;
    fVar20 = ALBW_AS_F32(param_1[0x69]) * ALBW_AS_F32(puVar2[0x8f]);
    fVar19 = fVar19 * DAT_003e9400;
    fVar21 = *(float *)(iVar8 + 0x254) * ALBW_AS_F32(puVar2[0x88]) * ALBW_AS_F32(param_1[0x70]);
    fVar22 = *(float *)(iVar8 + 0x25c) * ALBW_AS_F32(puVar2[0x8a]) * ALBW_AS_F32(param_1[0x71]);
    fVar10 = fVar10 * DAT_003e9400;
    uVar26 = (ulonglong)(uint)ALBW_AS_U32(DAT_003e9408);
    if (*(char *)(iVar8 + 0x17f) != '\0') {
      fVar10 = (float)VectorUnsignedToFloat(param_1[0x22],(byte)(in_fpscr >> 0x15) & 3);
      fVar10 = fVar10 * DAT_003e9404;
      param_1[0x22] = param_1[0x22] * DAT_003e940c + 0x3039;
      fVar10 = fVar10 * fVar24 * fVar14;
    }
    puVar2 = (undefined4 *)0x0;
    iVar7 = 0;
    fVar14 = DAT_003e9414;
    fVar24 = DAT_003e9418;
    if (0 < iVar9) {
      do {
        uVar3 = (**(code **)(*(int *)param_1[0x35] + 0xc))((int *)param_1[0x35]);
        puVar4 = (undefined4 *)func_003F856C(*DAT_003e941c,uVar3);
        if (puVar4 != (undefined4 *)0x0) {
          if (puVar2 == (undefined4 *)0x0) {
            puVar2 = puVar4;
          }
          puVar4[0x4e] = iVar8;
          uVar1 = DAT_003e940c;
          iVar5 = param_1[0x22];
          puVar4[0x52] = 0;
          fVar11 = (float)VectorUnsignedToFloat(iVar5,(byte)(in_fpscr >> 0x15) & 3);
          param_1[0x22] = iVar5 * uVar1 + 0x3039;
          uVar27 = func_00114608((uint)ALBW_AS_U32(((fVar10 + fVar11 * fVar13 * fVar19) * fVar14)),uVar1);
          pfVar6 = (float *)(DAT_003e9420 + ((uint)uVar27 >> 0x18) * 0x10);
          fVar11 = (float)VectorUnsignedToFloat
                                    ((uint)uVar27 & 0xffffff,(byte)(in_fpscr >> 0x15) & 3);
          uVar1 = in_fpscr & 0xfffffff;
          in_fpscr = uVar1 | (uint)(*(float *)(iVar8 + 0x310) == fVar23) << 0x1e;
          fVar18 = pfVar6[1];
          fVar15 = pfVar6[2];
          fVar16 = pfVar6[3];
          fVar12 = *pfVar6;
          puVar4[3] = ALBW_AS_U32(fVar23);
          fVar12 = fVar12 + fVar18 * fVar11 * fVar24;
          fVar15 = fVar15 + fVar16 * fVar11 * fVar24;
          fVar11 = fVar12 * fVar21;
          puVar4[2] = ALBW_AS_U32(fVar11);
          puVar4[4] = ALBW_AS_U32(fVar15 * fVar22);
          puVar4[10] = ALBW_AS_U32(fVar15 * fVar20);
          puVar4[8] = ALBW_AS_U32(fVar12 * fVar20);
          puVar4[9] = ALBW_AS_U32(fVar23);
          if (!SUB41(in_fpscr >> 0x1e,0)) {
            fVar12 = ALBW_AS_F32(puVar4[4]);
            if ((int)ALBW_AS_U32((fVar11 * fVar11 + fVar23 * fVar23 + fVar12 * fVar12)) < 0x800001) {
              iVar5 = param_1[0x22] * DAT_003e940c + 0x3039;
              fVar11 = (float)VectorUnsignedToFloat(param_1[0x22],(byte)(in_fpscr >> 0x15) & 3);
              fVar12 = (float)VectorUnsignedToFloat(iVar5,(byte)(in_fpscr >> 0x15) & 3);
              param_1[0x22] = iVar5 * DAT_003e940c + 0x3039;
              fVar11 = fVar11 * fVar13 * ALBW_AS_F32(uVar26) - fVar25;
              fVar12 = fVar12 * fVar13 * ALBW_AS_F32(uVar26) - fVar25;
            }
            fVar17 = fVar11 * fVar11 + fVar23 * fVar23 + fVar12 * fVar12;
            in_fpscr = uVar1 | (uint)(fVar17 == fVar23) << 0x1e;
            fVar15 = fVar23;
            fVar16 = fVar23;
            fVar18 = fVar23;
            if (!SUB41(in_fpscr >> 0x1e,0)) {
              fVar18 = fVar25 / SQRT(fVar17);
              fVar15 = fVar23 * fVar18;
              fVar16 = fVar12 * fVar18;
              fVar18 = fVar11 * fVar18;
            }
            fVar11 = *(float *)(iVar8 + 0x310);
            puVar4[8] = ALBW_AS_U32(ALBW_AS_F32(puVar4[8]) + fVar18 * fVar11);
            puVar4[9] = ALBW_AS_U32(ALBW_AS_F32(puVar4[9]) + fVar15 * fVar11);
            puVar4[10] = ALBW_AS_U32(ALBW_AS_F32(puVar4[10]) + fVar16 * fVar11);
          }
          if ((*(uint *)(param_1[0x36] + 4) & 0x400000) == 0) {
            func_003E728C((int)param_1,puVar4);
          }
          else {
            func_003E8730((int)param_1,puVar4);
          }
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 < iVar9);
    }
    param_1[2] = param_1[2] | 8;
  }
  return puVar2;
}

