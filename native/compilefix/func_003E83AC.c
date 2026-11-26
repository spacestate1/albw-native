/* compilefix: USA 003E83AC (EU 003E838C), the converted stage-2 text.
 * Fixed (BOOT_LOG 184): the ARM copies this word between a float and an integer (no vcvt), which the
 * converted text wrote as a conversion of the value. */
#include "ghidra_types.h"

extern int func_00100174(int *param_1);
extern int func_003E728C(int param_1,undefined4 *param_2);
extern int func_003E8730(int param_1,undefined4 *param_2);
extern int func_003F856C(int param_1,undefined4 param_2);
extern float DAT_003e8654;
extern int DAT_003e8658;
extern int *DAT_003e865c;
extern undefined4 DAT_003e8660;
extern uint DAT_003e8664;
extern uint *DAT_003e8668;
extern float *DAT_003e866c;
extern int *DAT_003e8670;
extern int DAT_003e8674;

// USA 003E83AC <- EU 003E838C (Ghidra, non-matching)
// GLOBAL DAT_003e8654 float
// GLOBAL DAT_003e8658 int
// GLOBAL DAT_003e865c int *
// GLOBAL DAT_003e8660 undefined4
// GLOBAL DAT_003e8664 uint
// GLOBAL DAT_003e8668 uint *
// GLOBAL DAT_003e866c float *
// GLOBAL DAT_003e8670 int *
// GLOBAL DAT_003e8674 int

undefined4 * func_003E83AC(int *param_1)

{
  ushort uVar1;
  int *piVar2;
  uint *puVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  uint uVar8;
  int iVar9;
  float *pfVar10;
  int iVar11;
  int iVar12;
  uint in_fpscr;
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
  undefined8 uVar23;
  ulonglong uVar24;
  
  iVar9 = DAT_003e8658;
  fVar22 = DAT_003e8654;
  fVar17 = *(float *)param_1[7];
  puVar5 = (undefined4 *)param_1[6];
  iVar12 = param_1[0x36];
  fVar14 = ALBW_AS_F32(param_1[0x8b]) + ALBW_AS_F32(param_1[0x5a]) * fVar17;
  param_1[0x8b] = (int)ALBW_AS_U32(fVar14);
  if ((*param_1 == 0) && ((int)ALBW_AS_U32(fVar14) < 0x3f800000)) {
    in_fpscr = in_fpscr & 0xfffffff | (uint)(ALBW_AS_F32(param_1[0x5a]) * fVar17 == fVar22) << 0x1e;
    if (!SUB41(in_fpscr >> 0x1e,0)) {
      param_1[0x8b] = iVar9;
    }
  }
  iVar13 = (int)ALBW_AS_F32(param_1[0x8b]);
  if (*(char *)(iVar12 + 0x181) != '\0') {
    iVar13 = 1;
  }
  if (iVar13 == 0) {
    puVar5 = (undefined4 *)0x0;
  }
  fVar14 = (float)VectorSignedToFloat(iVar13,(byte)(in_fpscr >> 0x15) & 3);
  param_1[0x8b] = (int)ALBW_AS_U32(ALBW_AS_F32(param_1[0x8b]) - fVar14);
  piVar2 = DAT_003e865c;
  if (iVar13 != 0) {
    pfVar10 = (float *)(puVar5 + 0x8f);
    puVar5 = (undefined4 *)0x0;
    fVar14 = ALBW_AS_F32(param_1[0x69]) * *pfVar10;
    iVar11 = 0;
    if (0 < iVar13) {
      uVar23 = CONCAT44(DAT_003e8660,iVar9);
      uVar24 = (ulonglong)DAT_003e8664;
      do {
        uVar6 = (**(code **)(*(int *)param_1[0x35] + 0xc))((int *)param_1[0x35]);
        puVar7 = (undefined4 *)func_003F856C(*piVar2,uVar6);
        puVar3 = DAT_003e8668;
        if (puVar7 != (undefined4 *)0x0) {
          if (puVar5 == (undefined4 *)0x0) {
            puVar5 = puVar7;
          }
          puVar7[0x4e] = iVar12;
          uVar8 = *puVar3;
          puVar7[0x52] = 0;
          if (((uVar8 & 1) == 0) &&
             (iVar9 = func_00100174((int *)DAT_003e8668), pfVar10 = DAT_003e866c, iVar9 != 0)) {
            *DAT_003e866c = fVar22;
            pfVar10[1] = fVar22;
            pfVar10[2] = fVar22;
          }
          piVar4 = DAT_003e8670;
          fVar17 = DAT_003e866c[1];
          fVar18 = DAT_003e866c[2];
          puVar7[2] = ALBW_AS_U32(*DAT_003e866c);
          puVar7[3] = ALBW_AS_U32(fVar17);
          puVar7[4] = ALBW_AS_U32(fVar18);
          uVar1 = *(ushort *)((int)param_1 + 0x86);
          iVar9 = *piVar4;
          *(ushort *)((int)param_1 + 0x86) = uVar1 + 1;
          pfVar10 = (float *)(iVar9 + (uVar1 & 0xffff01ff) * 0xc);
          fVar17 = pfVar10[1];
          uVar8 = in_fpscr & 0xfffffff;
          in_fpscr = uVar8 | (uint)(*(float *)(iVar12 + 0x310) == fVar22) << 0x1e;
          fVar18 = pfVar10[2];
          puVar7[8] = ALBW_AS_U32(*pfVar10 * fVar14);
          puVar7[9] = ALBW_AS_U32(fVar17 * fVar14);
          puVar7[10] = ALBW_AS_U32(fVar18 * fVar14);
          if (!SUB41(in_fpscr >> 0x1e,0)) {
            fVar19 = ALBW_AS_F32(puVar7[2]);
            fVar18 = ALBW_AS_F32(puVar7[4]);
            fVar17 = ALBW_AS_F32(uVar23);
            if ((int)ALBW_AS_U32((fVar19 * fVar19 + fVar22 * fVar22 + fVar18 * fVar18)) < 0x800001) {
              fVar18 = (float)VectorUnsignedToFloat(param_1[0x22],(byte)(in_fpscr >> 0x15) & 3);
              iVar9 = param_1[0x22] * DAT_003e8674 + 0x3039;
              fVar16 = ALBW_AS_F32(((ulonglong)uVar23 >> 0x20));
              fVar15 = (float)VectorUnsignedToFloat(iVar9,(byte)(in_fpscr >> 0x15) & 3);
              param_1[0x22] = iVar9 * DAT_003e8674 + 0x3039;
              fVar19 = fVar18 * fVar16 * ALBW_AS_F32(uVar24) - fVar17;
              fVar18 = fVar15 * fVar16 * ALBW_AS_F32(uVar24) - fVar17;
            }
            fVar21 = fVar19 * fVar19 + fVar22 * fVar22 + fVar18 * fVar18;
            in_fpscr = uVar8 | (uint)(fVar21 == fVar22) << 0x1e;
            fVar15 = fVar22;
            fVar16 = fVar22;
            fVar20 = fVar22;
            if (!SUB41(in_fpscr >> 0x1e,0)) {
              fVar17 = fVar17 / SQRT(fVar21);
              fVar15 = fVar18 * fVar17;
              fVar16 = fVar19 * fVar17;
              fVar20 = fVar22 * fVar17;
            }
            fVar17 = *(float *)(iVar12 + 0x310);
            puVar7[8] = ALBW_AS_U32(ALBW_AS_F32(puVar7[8]) + fVar16 * fVar17);
            puVar7[9] = ALBW_AS_U32(ALBW_AS_F32(puVar7[9]) + fVar20 * fVar17);
            puVar7[10] = ALBW_AS_U32(ALBW_AS_F32(puVar7[10]) + fVar15 * fVar17);
          }
          if ((*(uint *)(param_1[0x36] + 4) & 0x400000) == 0) {
            func_003E728C((int)param_1,puVar7);
          }
          else {
            func_003E8730((int)param_1,puVar7);
          }
        }
        iVar11 = iVar11 + 1;
      } while (iVar11 < iVar13);
    }
    param_1[2] = param_1[2] | 8;
  }
  return puVar5;
}

