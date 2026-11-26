/* compilefix: USA 003EA164 (EU 003EA144), the converted stage-2 text.
 * Fixed (BOOT_LOG 184): the ARM copies this word between a float and an integer (no vcvt), which the
 * converted text wrote as a conversion of the value. */
#include "ghidra_types.h"

extern undefined8 func_00114608(uint param_1,uint param_2);
extern int func_003E728C(int param_1,undefined4 *param_2);
extern int func_003E8730(int param_1,undefined4 *param_2);
extern int func_003F856C(int param_1,undefined4 param_2);
extern float DAT_003ea4ac;
extern float DAT_003ea4b0;
extern float DAT_003ea4b4;
extern float DAT_003ea4b8;
extern float DAT_003ea4bc;
extern uint DAT_003ea4c0;
extern float DAT_003ea4c4;
extern undefined4 DAT_003ea4c8;
extern undefined4 DAT_003ea4cc;
extern int *DAT_003ea4d0;
extern int DAT_003ea4d4;

// USA 003EA164 <- EU 003EA144 (Ghidra, non-matching)
// GLOBAL DAT_003ea4ac float
// GLOBAL DAT_003ea4b0 float
// GLOBAL DAT_003ea4b4 float
// GLOBAL DAT_003ea4b8 float
// GLOBAL DAT_003ea4bc float
// GLOBAL DAT_003ea4c0 uint
// GLOBAL DAT_003ea4c4 float
// GLOBAL DAT_003ea4c8 undefined4
// GLOBAL DAT_003ea4cc undefined4
// GLOBAL DAT_003ea4d0 int *
// GLOBAL DAT_003ea4d4 int

undefined4 * func_003EA164(int *param_1)

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
  float fVar9;
  float fVar10;
  int iVar11;
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
  undefined8 in_d13;
  undefined8 uVar26;
  
  fVar25 = DAT_003ea4b0;
  fVar24 = DAT_003ea4ac;
  fVar13 = *(float *)param_1[7];
  puVar2 = (undefined4 *)param_1[6];
  iVar8 = param_1[0x36];
  fVar10 = ALBW_AS_F32(param_1[0x8b]) + ALBW_AS_F32(param_1[0x5a]) * fVar13;
  param_1[0x8b] = (int)ALBW_AS_U32(fVar10);
  if ((*param_1 == 0) && ((int)ALBW_AS_U32(fVar10) < 0x3f800000)) {
    in_fpscr = in_fpscr & 0xfffffff | (uint)(ALBW_AS_F32(param_1[0x5a]) * fVar13 == fVar24) << 0x1e;
    if (!SUB41(in_fpscr >> 0x1e,0)) {
      param_1[0x8b] = (int)ALBW_AS_U32(fVar25);
    }
  }
  iVar11 = (int)ALBW_AS_F32(param_1[0x8b]);
  if (*(char *)(iVar8 + 0x181) != '\0') {
    iVar11 = 1;
  }
  if (iVar11 == 0) {
    puVar2 = (undefined4 *)0x0;
  }
  fVar10 = (float)VectorSignedToFloat(iVar11,(byte)(in_fpscr >> 0x15) & 3);
  param_1[0x8b] = (int)ALBW_AS_U32(ALBW_AS_F32(param_1[0x8b]) - fVar10);
  fVar9 = DAT_003ea4c4;
  fVar13 = DAT_003ea4bc;
  fVar10 = DAT_003ea4b8;
  if (iVar11 != 0) {
    fVar12 = (float)VectorSignedToFloat(*(undefined4 *)(iVar8 + 0x260),(byte)(in_fpscr >> 0x15) & 3)
    ;
    fVar14 = (float)VectorUnsignedToFloat
                              (*(undefined4 *)(iVar8 + 0x264),(byte)(in_fpscr >> 0x15) & 3);
    fVar20 = ALBW_AS_F32(param_1[0x69]) * ALBW_AS_F32(puVar2[0x8f]);
    fVar21 = *(float *)(iVar8 + 0x254) * ALBW_AS_F32(puVar2[0x88]) * ALBW_AS_F32(param_1[0x70]);
    fVar22 = *(float *)(iVar8 + 600) * ALBW_AS_F32(puVar2[0x89]) * ALBW_AS_F32(param_1[0x71]);
    fVar23 = *(float *)(iVar8 + 0x25c) * ALBW_AS_F32(puVar2[0x8a]) * ALBW_AS_F32(param_1[0x72]);
    fVar14 = fVar14 * DAT_003ea4b4;
    fVar12 = fVar12 * DAT_003ea4b4;
    if (*(char *)(iVar8 + 0x17f) != '\0') {
      fVar12 = (float)VectorUnsignedToFloat(param_1[0x22],(byte)(in_fpscr >> 0x15) & 3);
      param_1[0x22] = param_1[0x22] * DAT_003ea4c0 + 0x3039;
      fVar12 = fVar12 * fVar10 * fVar9 * fVar13;
    }
    puVar2 = (undefined4 *)0x0;
    if (0 < iVar11) {
      in_d13 = CONCAT44(DAT_003ea4c8,DAT_003ea4cc);
    }
    iVar7 = 0;
    if (0 < iVar11) {
      do {
        uVar3 = (**(code **)(*(int *)param_1[0x35] + 0xc))((int *)param_1[0x35]);
        puVar4 = (undefined4 *)func_003F856C(*DAT_003ea4d0,uVar3);
        if (puVar4 != (undefined4 *)0x0) {
          if (puVar2 == (undefined4 *)0x0) {
            puVar2 = puVar4;
          }
          puVar4[0x4e] = iVar8;
          uVar1 = DAT_003ea4c0;
          iVar5 = param_1[0x22];
          puVar4[0x52] = 0;
          fVar9 = (float)VectorUnsignedToFloat(iVar5,(byte)(in_fpscr >> 0x15) & 3);
          iVar5 = iVar5 * uVar1 + 0x3039;
          param_1[0x22] = iVar5;
          uVar26 = func_00114608((uint)ALBW_AS_U32(((fVar12 + fVar9 * fVar10 * fVar14) *
                                       ALBW_AS_F32(((ulonglong)in_d13 >> 0x20)))),uVar1);
          fVar15 = (float)VectorUnsignedToFloat(iVar5,(byte)(in_fpscr >> 0x15) & 3);
          uVar1 = in_fpscr & 0xfffffff;
          in_fpscr = uVar1 | (uint)(*(float *)(iVar8 + 0x310) == fVar24) << 0x1e;
          iVar5 = iVar5 * DAT_003ea4c0;
          pfVar6 = (float *)(DAT_003ea4d4 + ((uint)uVar26 >> 0x18) * 0x10);
          fVar17 = (float)VectorUnsignedToFloat
                                    ((uint)uVar26 & 0xffffff,(byte)(in_fpscr >> 0x15) & 3);
          fVar9 = *pfVar6;
          fVar18 = pfVar6[1];
          fVar16 = pfVar6[2];
          fVar19 = pfVar6[3];
          puVar4[9] = ALBW_AS_U32(fVar24);
          param_1[0x22] = iVar5 + 0x3039;
          fVar17 = fVar17 * ALBW_AS_F32(in_d13);
          fVar9 = fVar9 + fVar18 * fVar17;
          fVar16 = fVar16 + fVar19 * fVar17;
          fVar18 = fVar9 * fVar21;
          fVar17 = fVar16 * fVar23;
          puVar4[2] = ALBW_AS_U32(fVar18);
          puVar4[4] = ALBW_AS_U32(fVar17);
          puVar4[3] = ALBW_AS_U32((fVar15 * fVar10 * fVar13 - fVar25) * fVar22);
          puVar4[8] = ALBW_AS_U32(fVar9 * fVar20);
          puVar4[10] = ALBW_AS_U32(fVar16 * fVar20);
          if (!SUB41(in_fpscr >> 0x1e,0)) {
            if ((int)ALBW_AS_U32((fVar18 * fVar18 + fVar24 * fVar24 + fVar17 * fVar17)) < 0x800001) {
              fVar9 = (float)VectorUnsignedToFloat(param_1[0x22],(byte)(in_fpscr >> 0x15) & 3);
              iVar5 = param_1[0x22] * DAT_003ea4c0 + 0x3039;
              fVar17 = (float)VectorUnsignedToFloat(iVar5,(byte)(in_fpscr >> 0x15) & 3);
              param_1[0x22] = iVar5 * DAT_003ea4c0 + 0x3039;
              fVar18 = fVar9 * fVar10 * fVar13 - fVar25;
              fVar17 = fVar17 * fVar10 * fVar13 - fVar25;
            }
            fVar19 = fVar18 * fVar18 + fVar24 * fVar24 + fVar17 * fVar17;
            in_fpscr = uVar1 | (uint)(fVar19 == fVar24) << 0x1e;
            fVar9 = fVar24;
            fVar15 = fVar24;
            fVar16 = fVar24;
            if (!SUB41(in_fpscr >> 0x1e,0)) {
              fVar16 = fVar25 / SQRT(fVar19);
              fVar9 = fVar17 * fVar16;
              fVar15 = fVar18 * fVar16;
              fVar16 = fVar24 * fVar16;
            }
            fVar17 = *(float *)(iVar8 + 0x310);
            puVar4[8] = ALBW_AS_U32(ALBW_AS_F32(puVar4[8]) + fVar15 * fVar17);
            puVar4[9] = ALBW_AS_U32(ALBW_AS_F32(puVar4[9]) + fVar16 * fVar17);
            puVar4[10] = ALBW_AS_U32(ALBW_AS_F32(puVar4[10]) + fVar9 * fVar17);
          }
          if ((*(uint *)(param_1[0x36] + 4) & 0x400000) == 0) {
            func_003E728C((int)param_1,puVar4);
          }
          else {
            func_003E8730((int)param_1,puVar4);
          }
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 < iVar11);
    }
    param_1[2] = param_1[2] | 8;
  }
  return puVar2;
}

