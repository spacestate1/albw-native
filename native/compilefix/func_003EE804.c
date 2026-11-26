/* compilefix: USA 003EE804 (EU 003EE7E4), the converted stage-2 text.
 * Fixed (BOOT_LOG 184): the ARM copies this word between a float and an integer (no vcvt), which the
 * converted text wrote as a conversion of the value. */
#include "ghidra_types.h"

extern int func_003E728C(int param_1,undefined4 *param_2);
extern int func_003E8730(int param_1,undefined4 *param_2);
extern int func_003F856C(int param_1,undefined4 param_2);
extern float DAT_003eeb90;
extern float DAT_003eeb94;
extern uint DAT_003eeb98;
extern float DAT_003eeb9c;
extern float DAT_003eeba0;
extern int *DAT_003eeba4;
extern int DAT_003eeba8;
extern uint DAT_003eebac;

// USA 003EE804 <- EU 003EE7E4 (Ghidra, non-matching)
// GLOBAL DAT_003eeb90 float
// GLOBAL DAT_003eeb94 float
// GLOBAL DAT_003eeb98 uint
// GLOBAL DAT_003eeb9c float
// GLOBAL DAT_003eeba0 float
// GLOBAL DAT_003eeba4 int *
// GLOBAL DAT_003eeba8 int
// GLOBAL DAT_003eebac uint

undefined4 * func_003EE804(int *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  uint uVar4;
  float *pfVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  bool bVar12;
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
  _Alignas(8) unsigned char albw_frame[0x50];
  #define local_50 (*(undefined4 * *)(albw_frame + 0x0))
  fVar29 = DAT_003eeb94;
  fVar28 = DAT_003eeb90;
  fVar17 = *(float *)param_1[7];
  local_50 = (undefined4 *)param_1[6];
  iVar10 = param_1[0x36];
  fVar15 = ALBW_AS_F32(param_1[0x8b]) + ALBW_AS_F32(param_1[0x5a]) * fVar17;
  param_1[0x8b] = (int)ALBW_AS_U32(fVar15);
  if ((*param_1 == 0) && ((int)ALBW_AS_U32(fVar15) < 0x3f800000)) {
    in_fpscr = in_fpscr & 0xfffffff | (uint)(ALBW_AS_F32(param_1[0x5a]) * fVar17 == fVar28) << 0x1e;
    if (!SUB41(in_fpscr >> 0x1e,0)) {
      param_1[0x8b] = (int)ALBW_AS_U32(fVar29);
    }
  }
  iVar14 = (int)ALBW_AS_F32(param_1[0x8b]);
  if (*(char *)(iVar10 + 0x181) != '\0') {
    iVar14 = 1;
  }
  if (iVar14 == 0) {
    local_50 = (undefined4 *)0x0;
  }
  fVar15 = (float)VectorSignedToFloat(iVar14,(byte)(in_fpscr >> 0x15) & 3);
  param_1[0x8b] = (int)ALBW_AS_U32(ALBW_AS_F32(param_1[0x8b]) - fVar15);
  uVar1 = DAT_003eeb98;
  if (iVar14 != 0) {
    fVar15 = *(float *)(iVar10 + 600) * ALBW_AS_F32(local_50[0x89]);
    fVar18 = *(float *)(iVar10 + 0x25c) * ALBW_AS_F32(local_50[0x8a]);
    fVar16 = ALBW_AS_F32(param_1[0x72]);
    fVar23 = ALBW_AS_F32(param_1[0x69]) * ALBW_AS_F32(local_50[0x8f]);
    fVar25 = *(float *)(iVar10 + 0x254) * ALBW_AS_F32(local_50[0x88]) * ALBW_AS_F32(param_1[0x70]);
    local_50 = (undefined4 *)0x0;
    fVar26 = fVar15 * ALBW_AS_F32(param_1[0x71]);
    fVar27 = fVar18 * fVar16;
    iVar9 = 0;
    fVar17 = DAT_003eeba0;
    fVar24 = DAT_003eeb9c;
    if (0 < iVar14) {
      do {
        uVar2 = (**(code **)(*(int *)param_1[0x35] + 0xc))((int *)param_1[0x35]);
        puVar3 = (undefined4 *)func_003F856C(*DAT_003eeba4,uVar2);
        iVar6 = DAT_003eeba8;
        if (puVar3 != (undefined4 *)0x0) {
          if (local_50 == (undefined4 *)0x0) {
            local_50 = puVar3;
          }
          uVar4 = param_1[0x22];
          iVar7 = uVar4 * DAT_003eeba8;
          puVar3[0x4e] = iVar10;
          puVar3[0x52] = 0;
          uVar8 = iVar7 + 0x3039;
          iVar7 = uVar8 * iVar6 + 0x3039;
          iVar11 = iVar7 * iVar6 + 0x3039;
          fVar19 = (float)VectorUnsignedToFloat(iVar7,(byte)(in_fpscr >> 0x15) & 3);
          fVar20 = (float)VectorUnsignedToFloat(iVar11,(byte)(in_fpscr >> 0x15) & 3);
          iVar7 = iVar11 * iVar6 + 0x3039;
          fVar21 = (float)VectorUnsignedToFloat(iVar7,(byte)(in_fpscr >> 0x15) & 3);
          param_1[0x22] = iVar7 * iVar6 + 0x3039;
          fVar22 = fVar19 * fVar24 * fVar17 - fVar29;
          fVar19 = fVar21 * fVar24 * fVar17 - fVar29;
          fVar20 = fVar20 * fVar24 * fVar17 - fVar29;
          if (uVar4 < uVar1) {
            fVar22 = fVar22 * fVar25;
            fVar20 = fVar20 * fVar26;
            if (uVar8 < 0x7fffffff) {
              puVar3[4] = ALBW_AS_U32(fVar27);
              puVar3[2] = ALBW_AS_U32(fVar22);
              puVar3[3] = ALBW_AS_U32(fVar20);
            }
            else {
              puVar3[2] = ALBW_AS_U32(fVar22);
              pfVar5 = (float *)(puVar3 + 3);
              fVar19 = fVar27;
LAB_003eea30:
              *pfVar5 = fVar20;
              pfVar5[1] = -fVar19;
            }
          }
          else {
            if (uVar4 < DAT_003eebac) {
              fVar20 = fVar22 * fVar25;
              if (0x7ffffffe < uVar8) {
                puVar3[4] = ALBW_AS_U32(fVar19 * fVar27);
                pfVar5 = (float *)(puVar3 + 2);
                fVar19 = fVar26;
                goto LAB_003eea30;
              }
              puVar3[3] = ALBW_AS_U32(fVar26);
              puVar3[2] = ALBW_AS_U32(fVar20);
            }
            else {
              fVar20 = fVar20 * fVar26;
              if (0x7ffffffe < uVar8) {
                puVar3[2] = ALBW_AS_U32(-fVar25);
                puVar3[3] = ALBW_AS_U32(fVar20);
                puVar3[4] = ALBW_AS_U32(fVar19 * fVar27);
                goto LAB_003eea68;
              }
              puVar3[2] = ALBW_AS_U32(fVar25);
              puVar3[3] = ALBW_AS_U32(fVar20);
            }
            puVar3[4] = ALBW_AS_U32(fVar19 * fVar27);
          }
LAB_003eea68:
          fVar19 = ALBW_AS_F32(puVar3[2]);
          uVar4 = in_fpscr & 0xfffffff | (uint)(fVar19 == fVar28) << 0x1e;
          bVar12 = false;
          if (SUB41(uVar4 >> 0x1e,0)) {
            uVar4 = in_fpscr & 0xfffffff | (uint)(ALBW_AS_F32(puVar3[3]) == fVar28) << 0x1e;
            bVar12 = SUB41(uVar4 >> 0x1e,0);
          }
          bVar13 = false;
          if (bVar12) {
            uVar4 = uVar4 & 0xfffffff | (uint)(ALBW_AS_F32(puVar3[4]) == fVar28) << 0x1e;
            bVar13 = SUB41(uVar4 >> 0x1e,0);
          }
          if (!bVar13) {
            fVar18 = ALBW_AS_F32(puVar3[3]);
            fVar15 = ALBW_AS_F32(puVar3[4]);
            fVar22 = fVar29 / SQRT(fVar19 * fVar19 + fVar18 * fVar18 + fVar15 * fVar15);
            fVar16 = fVar19 * fVar22;
            fVar18 = fVar18 * fVar22;
            fVar15 = fVar15 * fVar22;
          }
          fVar19 = fVar16 * fVar23;
          fVar22 = fVar18 * fVar23;
          fVar16 = fVar15 * fVar23;
          fVar18 = *(float *)(iVar10 + 0x310);
          in_fpscr = uVar4 & 0xfffffff | (uint)(fVar18 == fVar28) << 0x1e;
          puVar3[10] = ALBW_AS_U32(fVar16);
          puVar3[8] = ALBW_AS_U32(fVar19);
          puVar3[9] = ALBW_AS_U32(fVar22);
          if (!SUB41(in_fpscr >> 0x1e,0)) {
            fVar18 = ALBW_AS_F32(puVar3[2]);
            fVar16 = ALBW_AS_F32(puVar3[4]);
            if ((int)ALBW_AS_U32((fVar18 * fVar18 + fVar28 * fVar28 + fVar16 * fVar16)) < 0x800001) {
              fVar15 = (float)VectorUnsignedToFloat(param_1[0x22],(byte)(in_fpscr >> 0x15) & 3);
              iVar6 = param_1[0x22] * DAT_003eeba8 + 0x3039;
              fVar16 = (float)VectorUnsignedToFloat(iVar6,(byte)(in_fpscr >> 0x15) & 3);
              param_1[0x22] = iVar6 * DAT_003eeba8 + 0x3039;
              fVar18 = fVar15 * fVar24 * fVar17 - fVar29;
              fVar16 = fVar16 * fVar24 * fVar17 - fVar29;
            }
            fVar20 = fVar18 * fVar18 + fVar28 * fVar28 + fVar16 * fVar16;
            in_fpscr = uVar4 & 0xfffffff | (uint)(fVar20 == fVar28) << 0x1e;
            fVar19 = fVar28;
            fVar22 = fVar28;
            fVar15 = fVar28;
            if (!SUB41(in_fpscr >> 0x1e,0)) {
              fVar15 = fVar29 / SQRT(fVar20);
              fVar19 = fVar28 * fVar15;
              fVar22 = fVar16 * fVar15;
              fVar15 = fVar18 * fVar15;
            }
            fVar18 = *(float *)(iVar10 + 0x310);
            fVar15 = fVar15 * fVar18;
            puVar3[8] = ALBW_AS_U32(ALBW_AS_F32(puVar3[8]) + fVar15);
            puVar3[9] = ALBW_AS_U32(ALBW_AS_F32(puVar3[9]) + fVar19 * fVar18);
            fVar16 = ALBW_AS_F32(puVar3[10]);
            puVar3[10] = ALBW_AS_U32(fVar16 + fVar22 * fVar18);
          }
          if ((*(uint *)(param_1[0x36] + 4) & 0x400000) == 0) {
            func_003E728C((int)param_1,puVar3);
          }
          else {
            func_003E8730((int)param_1,puVar3);
          }
        }
        iVar9 = iVar9 + 1;
      } while (iVar9 < iVar14);
    }
    param_1[2] = param_1[2] | 8;
  }
  return local_50;
}

