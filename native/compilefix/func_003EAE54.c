/* compilefix: USA 003EAE54 (EU 003EAE34), the converted stage-2 text.
 * Fixed (BOOT_LOG 184): the ARM copies this word between a float and an integer (no vcvt), which the
 * converted text wrote as a conversion of the value. */
#include "ghidra_types.h"

extern undefined8 func_00114608(uint param_1,uint param_2);
extern int func_00115074(float *param_1,float *param_2,float *param_3);
extern int func_003E728C(int param_1,undefined4 *param_2);
extern int func_003E8730(int param_1,undefined4 *param_2);
extern int func_003F856C(int param_1,undefined4 param_2);
extern float DAT_003eb154;
extern float DAT_003eb158;
extern float DAT_003eb15c;
extern float DAT_003eb160;
extern float DAT_003eb164;
extern float DAT_003eb168;
extern uint DAT_003eb16c;
extern float DAT_003eb170;
extern undefined4 DAT_003eb174;
extern undefined4 DAT_003eb178;
extern int *DAT_003eb17c;
extern uint DAT_003eb180;

// USA 003EAE54 <- EU 003EAE34 (Ghidra, non-matching)
// GLOBAL DAT_003eb154 float
// GLOBAL DAT_003eb158 float
// GLOBAL DAT_003eb15c float
// GLOBAL DAT_003eb160 float
// GLOBAL DAT_003eb164 float
// GLOBAL DAT_003eb168 float
// GLOBAL DAT_003eb16c uint
// GLOBAL DAT_003eb170 float
// GLOBAL DAT_003eb174 undefined4
// GLOBAL DAT_003eb178 undefined4
// GLOBAL DAT_003eb17c int *
// GLOBAL DAT_003eb180 uint

undefined4 * func_003EAE54(int *param_1)

{
  uint uVar1;
  char cVar2;
  byte bVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int iVar7;
  float *pfVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  bool bVar12;
  bool bVar13;
  uint in_fpscr;
  uint uVar14;
  int iVar15;
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
  undefined8 uVar28;
  float fVar29;
  float fVar30;
  undefined8 in_d12;
  float in_s26;
  float fVar32;
  float fVar33;
  undefined8 uVar34;
  undefined8 uVar35;
  undefined8 uVar36;
  _Alignas(8) unsigned char albw_frame[0x100];
  #define local_f4 (*(float *)(albw_frame + 0xc))
  #define local_f0 (*(float *)(albw_frame + 0x10))
  #define local_ec (*(float *)(albw_frame + 0x14))
  #define local_c0 (*(float *)(albw_frame + 0x40))
  #define local_bc (*(float *)(albw_frame + 0x44))
  #define local_b8 (*(float *)(albw_frame + 0x48))
  #define local_b4 (*(float *)(albw_frame + 0x4c))
  #define local_b0 (*(float *)(albw_frame + 0x50))
  #define local_ac (*(float *)(albw_frame + 0x54))
  #define local_a8 (*(float *)(albw_frame + 0x58))
  #define local_a4 (*(float *)(albw_frame + 0x5c))
  #define local_a0 (*(float *)(albw_frame + 0x60))
  #define local_9c (*(float *)(albw_frame + 0x64))
  #define local_98 (*(float *)(albw_frame + 0x68))
  #define local_94 (*(float *)(albw_frame + 0x6c))
  #define local_8c (*(float *)(albw_frame + 0x74))
  #define local_88 (*(float *)(albw_frame + 0x78))
  #define local_84 (*(float *)(albw_frame + 0x7c))
  undefined8 uVar31;
  
  fVar32 = DAT_003eb158;
  fVar27 = DAT_003eb154;
  fVar20 = *(float *)param_1[7];
  iVar9 = param_1[6];
  iVar11 = param_1[0x36];
  fVar17 = ALBW_AS_F32(param_1[0x8b]) + ALBW_AS_F32(param_1[0x5a]) * fVar20;
  param_1[0x8b] = (int)ALBW_AS_U32(fVar17);
  if ((*param_1 == 0) && ((int)ALBW_AS_U32(fVar17) < 0x3f800000)) {
    in_fpscr = in_fpscr & 0xfffffff | (uint)(ALBW_AS_F32(param_1[0x5a]) * fVar20 == fVar27) << 0x1e;
    if (!SUB41(in_fpscr >> 0x1e,0)) {
      param_1[0x8b] = (int)ALBW_AS_U32(fVar32);
    }
  }
  puVar4 = (undefined4 *)(uint)*(byte *)(iVar11 + 0x181);
  iVar15 = (int)ALBW_AS_F32(param_1[0x8b]);
  if (puVar4 != (undefined4 *)0x0) {
    iVar15 = 1;
  }
  if (iVar15 == 0) {
    puVar4 = (undefined4 *)0x0;
  }
  fVar17 = (float)VectorSignedToFloat(iVar15,(byte)(in_fpscr >> 0x15) & 3);
  param_1[0x8b] = (int)ALBW_AS_U32(ALBW_AS_F32(param_1[0x8b]) - fVar17);
  fVar33 = DAT_003eb164;
  fVar20 = DAT_003eb160;
  fVar17 = DAT_003eb15c;
  if (iVar15 != 0) {
    bVar13 = *(char *)(iVar11 + 0x182) != '\0';
    fVar21 = ALBW_AS_F32(((ulonglong)in_d12 >> 0x20));
    if (bVar13) {
      fVar21 = fVar27;
    }
    fVar27 = ALBW_AS_F32(param_1[0x69]) * *(float *)(iVar9 + 0x23c);
    fVar29 = *(float *)(iVar11 + 600) * *(float *)(iVar9 + 0x224) * ALBW_AS_F32(param_1[0x71]);
    fVar30 = *(float *)(iVar11 + 0x25c) * *(float *)(iVar9 + 0x228) * ALBW_AS_F32(param_1[0x72]);
    uVar31 = CONCAT44(fVar21,fVar30);
    if (bVar13) {
      in_s26 = fVar21;
    }
    uVar28 = CONCAT44(*(float *)(iVar11 + 0x254) * *(float *)(iVar9 + 0x220) * ALBW_AS_F32(param_1[0x70]),
                      DAT_003eb160);
    if (!bVar13) {
      fVar21 = (float)VectorUnsignedToFloat
                                (*(undefined4 *)(iVar11 + 0x264),(byte)(in_fpscr >> 0x15) & 3);
      in_s26 = fVar21 * DAT_003eb168;
      if (*(char *)(iVar11 + 0x17f) == '\0') {
        fVar17 = (float)VectorSignedToFloat(*(undefined4 *)(iVar11 + 0x260),
                                            (byte)(in_fpscr >> 0x15) & 3);
        uVar31 = CONCAT44(fVar17 * DAT_003eb168,fVar30);
      }
      else {
        fVar21 = (float)VectorUnsignedToFloat(param_1[0x22],(byte)(in_fpscr >> 0x15) & 3);
        param_1[0x22] = param_1[0x22] * DAT_003eb16c + 0x3039;
        uVar31 = CONCAT44(fVar21 * fVar20 * fVar17 * fVar33,fVar30);
      }
    }
    puVar4 = (undefined4 *)0x0;
    iVar9 = 0;
    if (0 < iVar15) {
      uVar34 = CONCAT44(DAT_003eb178,DAT_003eb174);
      fVar17 = DAT_003eb170;
      do {
        uVar5 = (**(code **)(*(int *)param_1[0x35] + 0xc))((int *)param_1[0x35]);
        puVar6 = (undefined4 *)func_003F856C(*DAT_003eb17c,uVar5);
        if (puVar6 != (undefined4 *)0x0) {
          if (puVar4 == (undefined4 *)0x0) {
            puVar4 = puVar6;
          }
          cVar2 = *(char *)(iVar11 + 0x182);
          puVar6[0x4e] = iVar11;
          puVar6[0x52] = 0;
          uVar1 = DAT_003eb16c;
          fVar20 = DAT_003eb15c;
          iVar7 = param_1[0x22];
          if (cVar2 == '\0') {
            fVar20 = (float)VectorUnsignedToFloat(iVar7,(byte)(in_fpscr >> 0x15) & 3);
            param_1[0x22] = iVar7 * DAT_003eb16c + 0x3039;
            uVar35 = func_00114608((uint)ALBW_AS_U32(((ALBW_AS_F32(((ulonglong)uVar31 >> 0x20)) +
                                          fVar20 * ALBW_AS_F32(uVar28) * in_s26) * fVar17)),uVar1);
            pfVar8 = (float *)(DAT_003eb180 + ((uint)uVar35 >> 0x18) * 0x10);
            fVar20 = (float)VectorUnsignedToFloat
                                      ((uint)uVar35 & 0xffffff,(byte)(in_fpscr >> 0x15) & 3);
            fVar20 = fVar20 * ALBW_AS_F32(uVar34);
            uVar35 = CONCAT44(pfVar8[2] + pfVar8[3] * fVar20,*pfVar8 + pfVar8[1] * fVar20);
          }
          else {
            fVar21 = (float)VectorUnsignedToFloat(iVar7,(byte)(in_fpscr >> 0x15) & 3);
            param_1[0x22] = iVar7 * DAT_003eb16c + 0x3039;
            uVar35 = func_00114608((uint)ALBW_AS_U32((fVar21 * ALBW_AS_F32(uVar28) * fVar20 * fVar33 * fVar17)),uVar1);
            pfVar8 = (float *)(DAT_003eb180 + ((uint)uVar35 >> 0x18) * 0x10);
            fVar20 = (float)VectorUnsignedToFloat
                                      ((uint)uVar35 & 0xffffff,(byte)(in_fpscr >> 0x15) & 3);
            fVar20 = fVar20 * ALBW_AS_F32(uVar34);
            uVar35 = CONCAT44(pfVar8[2] + pfVar8[3] * fVar20,*pfVar8 + pfVar8[1] * fVar20);
          }
          if (*(char *)(iVar11 + 0x182) == '\0') {
            fVar20 = (float)VectorUnsignedToFloat(param_1[0x22],(byte)(in_fpscr >> 0x15) & 3);
            param_1[0x22] = param_1[0x22] * DAT_003eb16c + 0x3039;
            local_f0 = fVar20 * ALBW_AS_F32(uVar28) * fVar33 - fVar32;
          }
          else {
            uVar36 = func_00114608((uint)ALBW_AS_U32((*(float *)(iVar11 + 0x270) * fVar17)),DAT_003eb180);
            iVar10 = param_1[0x22];
            fVar20 = (float)VectorUnsignedToFloat
                                      ((uint)uVar36 & 0xffffff,(byte)(in_fpscr >> 0x15) & 3);
            iVar7 = DAT_003eb180 + ((uint)uVar36 >> 0x18) * 0x10;
            param_1[0x22] = iVar10 * DAT_003eb16c + 0x3039;
            fVar21 = (float)VectorUnsignedToFloat(iVar10,(byte)(in_fpscr >> 0x15) & 3);
            local_f0 = fVar32 - (fVar32 - (*(float *)(iVar7 + 8) +
                                          *(float *)(iVar7 + 0xc) * fVar20 * ALBW_AS_F32(uVar34))) *
                                fVar21 * ALBW_AS_F32(uVar28);
          }
          fVar20 = DAT_003eb154;
          fVar21 = fVar32 - local_f0 * local_f0;
          uVar1 = in_fpscr & 0xfffffff;
          uVar14 = uVar1 | (uint)(fVar21 == DAT_003eb154) << 0x1e |
                   (uint)(DAT_003eb154 <= fVar21) << 0x1d;
          bVar3 = (byte)(uVar14 >> 0x18);
          local_ec = DAT_003eb154;
          if ((bool)(bVar3 >> 5 & 1) && !(bool)(bVar3 >> 6)) {
            local_ec = SQRT(fVar21);
          }
          fVar30 = (float)VectorUnsignedToFloat(param_1[0x22],(byte)(uVar14 >> 0x15) & 3);
          param_1[0x22] = param_1[0x22] * DAT_003eb16c + 0x3039;
          fVar30 = fVar30 * ALBW_AS_F32(uVar28);
          uVar14 = uVar1 | (uint)(fVar30 == fVar20) << 0x1e | (uint)(fVar20 <= fVar30) << 0x1d;
          bVar3 = (byte)(uVar14 >> 0x18);
          fVar21 = fVar20;
          if ((bool)(bVar3 >> 5 & 1) && !(bool)(bVar3 >> 6)) {
            fVar21 = SQRT(fVar30);
          }
          local_f4 = local_ec * ALBW_AS_F32(uVar35);
          local_ec = local_ec * ALBW_AS_F32(((ulonglong)uVar35 >> 0x20));
          fVar30 = (fVar32 + fVar21 * *(float *)(iVar11 + 0x26c)) - *(float *)(iVar11 + 0x26c);
          fVar21 = fVar32;
          if (*(char *)(iVar11 + 0x182) != '\0') {
            uVar14 = uVar1 | (uint)(*(float *)(iVar11 + 0x274) == fVar20) << 0x1e;
            bVar13 = false;
            if (SUB41(uVar14 >> 0x1e,0)) {
              bVar13 = *(int *)(iVar11 + 0x278) == 0x3f800000;
            }
            bVar12 = false;
            if (bVar13) {
              uVar14 = uVar1 | (uint)(*(float *)(iVar11 + 0x27c) == fVar20) << 0x1e;
              bVar12 = SUB41(uVar14 >> 0x1e,0);
            }
            if (!bVar12) {
              fVar23 = *(float *)(iVar11 + 0x274);
              fVar26 = *(float *)(iVar11 + 0x278);
              fVar25 = *(float *)(iVar11 + 0x27c);
              fVar22 = fVar20 * fVar23 + fVar32 * fVar26 + fVar20 * fVar25 + fVar32;
              fVar18 = fVar20;
              fVar16 = fVar32;
              fVar19 = fVar20;
              fVar24 = fVar20;
              if (0x34000000 < (int)ALBW_AS_U32(fVar22)) {
                fVar19 = SQRT(fVar22 * fVar33);
                fVar24 = fVar32 / fVar19;
                fVar18 = (fVar20 * fVar23 - fVar20 * fVar25) * fVar24;
                fVar16 = (fVar32 * fVar25 - fVar20 * fVar26) * fVar24;
                fVar19 = fVar19 * ALBW_AS_F32(((ulonglong)uVar34 >> 0x20));
                fVar24 = (fVar20 * fVar26 - fVar32 * fVar23) * fVar24;
              }
              local_b4 = fVar20;
              local_a4 = fVar20;
              local_94 = fVar20;
              fVar26 = fVar33 / (fVar16 * fVar16 + fVar18 * fVar18 + fVar24 * fVar24 +
                                fVar19 * fVar19);
              fVar23 = fVar18 * fVar26;
              fVar22 = fVar24 * fVar26;
              fVar25 = fVar16 * fVar16 * fVar26;
              local_9c = fVar19 * fVar16 * fVar26;
              local_bc = fVar16 * fVar23 - fVar19 * fVar22;
              local_b0 = fVar16 * fVar23 + fVar19 * fVar22;
              local_b8 = fVar16 * fVar22 + fVar19 * fVar23;
              local_a0 = fVar16 * fVar22 - fVar19 * fVar23;
              local_c0 = fVar32 - (fVar18 * fVar23 + fVar24 * fVar22);
              local_ac = fVar32 - (fVar25 + fVar24 * fVar22);
              local_a8 = fVar18 * fVar22 - local_9c;
              local_9c = fVar18 * fVar22 + local_9c;
              local_98 = fVar32 - (fVar25 + fVar18 * fVar23);
              local_8c = local_f4;
              local_88 = local_f0;
              local_84 = local_ec;
              func_00115074(&local_f4,&local_c0,&local_8c);
            }
          }
          in_fpscr = uVar14 & 0xfffffff | (uint)(*(float *)(iVar11 + 0x310) == fVar20) << 0x1e;
          fVar18 = local_f4 * ALBW_AS_F32(((ulonglong)uVar28 >> 0x20)) * fVar30;
          puVar6[2] = ALBW_AS_U32(fVar18);
          puVar6[3] = ALBW_AS_U32(local_f0 * fVar29 * fVar30);
          puVar6[4] = ALBW_AS_U32(local_ec * ALBW_AS_F32(uVar31) * fVar30);
          puVar6[8] = ALBW_AS_U32(local_f4 * fVar27);
          puVar6[9] = ALBW_AS_U32(local_f0 * fVar27);
          puVar6[10] = ALBW_AS_U32(local_ec * fVar27);
          if (!SUB41(in_fpscr >> 0x1e,0)) {
            fVar30 = ALBW_AS_F32(puVar6[4]);
            if ((int)ALBW_AS_U32((fVar18 * fVar18 + fVar20 * fVar20 + fVar30 * fVar30)) < 0x800001) {
              fVar30 = (float)VectorUnsignedToFloat(param_1[0x22],(byte)(in_fpscr >> 0x15) & 3);
              iVar7 = param_1[0x22] * DAT_003eb16c + 0x3039;
              fVar16 = (float)VectorUnsignedToFloat(iVar7,(byte)(in_fpscr >> 0x15) & 3);
              param_1[0x22] = iVar7 * DAT_003eb16c + 0x3039;
              fVar18 = fVar30 * ALBW_AS_F32(uVar28) * fVar33 - fVar21;
              fVar30 = fVar16 * ALBW_AS_F32(uVar28) * fVar33 - fVar21;
            }
            fVar24 = fVar18 * fVar18 + fVar20 * fVar20 + fVar30 * fVar30;
            in_fpscr = uVar14 & 0xfffffff | (uint)(fVar24 == fVar20) << 0x1e;
            fVar16 = fVar20;
            fVar19 = fVar20;
            if (!SUB41(in_fpscr >> 0x1e,0)) {
              fVar21 = fVar21 / SQRT(fVar24);
              fVar19 = fVar20 * fVar21;
              fVar20 = fVar30 * fVar21;
              fVar16 = fVar18 * fVar21;
            }
            fVar21 = *(float *)(iVar11 + 0x310);
            puVar6[8] = ALBW_AS_U32(ALBW_AS_F32(puVar6[8]) + fVar16 * fVar21);
            puVar6[9] = ALBW_AS_U32(ALBW_AS_F32(puVar6[9]) + fVar19 * fVar21);
            puVar6[10] = ALBW_AS_U32(ALBW_AS_F32(puVar6[10]) + fVar20 * fVar21);
          }
          if ((*(uint *)(param_1[0x36] + 4) & 0x400000) == 0) {
            func_003E728C((int)param_1,puVar6);
          }
          else {
            func_003E8730((int)param_1,puVar6);
          }
        }
        iVar9 = iVar9 + 1;
      } while (iVar9 < iVar15);
    }
    param_1[2] = param_1[2] | 8;
  }
  return puVar4;
}

