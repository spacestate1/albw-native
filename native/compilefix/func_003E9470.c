/* compilefix: USA 003E9470 (EU 003E9450), the converted stage-2 text.
 * Fixed (BOOT_LOG 184): the ARM copies this word between a float and an integer (no vcvt), which the
 * converted text wrote as a conversion of the value. */
#include "ghidra_types.h"

extern undefined8 func_00114608(uint param_1,uint param_2);
extern int func_00115074(float *param_1,float *param_2,float *param_3);
extern int func_003E728C(int param_1,undefined4 *param_2);
extern int func_003E8730(int param_1,undefined4 *param_2);
extern int func_003F856C(int param_1,undefined4 param_2);
extern float DAT_003e9764;
extern int DAT_003e9768;
extern float DAT_003e976c;
extern float DAT_003e9770;
extern float DAT_003e9774;
extern float DAT_003e9778;
extern uint DAT_003e977c;
extern float DAT_003e9780;
extern undefined4 DAT_003e9784;
extern int DAT_003e9788;
extern undefined4 DAT_003e978c;
extern int *DAT_003e9790;

// USA 003E9470 <- EU 003E9450 (Ghidra, non-matching)
// GLOBAL DAT_003e9764 float
// GLOBAL DAT_003e9768 int
// GLOBAL DAT_003e976c float
// GLOBAL DAT_003e9770 float
// GLOBAL DAT_003e9774 float
// GLOBAL DAT_003e9778 float
// GLOBAL DAT_003e977c uint
// GLOBAL DAT_003e9780 float
// GLOBAL DAT_003e9784 undefined4
// GLOBAL DAT_003e9788 int
// GLOBAL DAT_003e978c undefined4
// GLOBAL DAT_003e9790 int *

undefined4 * func_003E9470(int *param_1)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int iVar7;
  float *pfVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  bool bVar13;
  bool bVar14;
  uint in_fpscr;
  uint uVar15;
  int iVar16;
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
  undefined8 uVar31;
  float fVar32;
  undefined8 uVar33;
  undefined8 uVar34;
  undefined8 uVar35;
  _Alignas(8) unsigned char albw_frame[0x110];
  #define local_104 (*(float *)(albw_frame + 0xc))
  #define local_100 (*(float *)(albw_frame + 0x10))
  #define local_fc (*(float *)(albw_frame + 0x14))
  #define local_c0 (*(float *)(albw_frame + 0x50))
  #define local_bc (*(float *)(albw_frame + 0x54))
  #define local_b8 (*(float *)(albw_frame + 0x58))
  #define local_b4 (*(float *)(albw_frame + 0x5c))
  #define local_b0 (*(float *)(albw_frame + 0x60))
  #define fStack_ac (*(float *)(albw_frame + 0x64))
  #define local_a8 (*(float *)(albw_frame + 0x68))
  #define local_a4 (*(float *)(albw_frame + 0x6c))
  #define local_a0 (*(float *)(albw_frame + 0x70))
  #define local_9c (*(float *)(albw_frame + 0x74))
  #define local_98 (*(float *)(albw_frame + 0x78))
  #define local_94 (*(float *)(albw_frame + 0x7c))
  #define local_88 (*(float *)(albw_frame + 0x88))
  #define local_84 (*(float *)(albw_frame + 0x8c))
  #define local_80 (*(float *)(albw_frame + 0x90))
  iVar3 = DAT_003e9768;
  fVar29 = DAT_003e9764;
  fVar20 = *(float *)param_1[7];
  iVar9 = param_1[6];
  iVar12 = param_1[0x36];
  fVar18 = ALBW_AS_F32(param_1[0x8b]) + ALBW_AS_F32(param_1[0x5a]) * fVar20;
  param_1[0x8b] = (int)ALBW_AS_U32(fVar18);
  if ((*param_1 == 0) && ((int)ALBW_AS_U32(fVar18) < 0x3f800000)) {
    in_fpscr = in_fpscr & 0xfffffff | (uint)(ALBW_AS_F32(param_1[0x5a]) * fVar20 == fVar29) << 0x1e;
    if (!SUB41(in_fpscr >> 0x1e,0)) {
      param_1[0x8b] = iVar3;
    }
  }
  puVar4 = (undefined4 *)(uint)*(byte *)(iVar12 + 0x181);
  iVar16 = (int)ALBW_AS_F32(param_1[0x8b]);
  if (puVar4 != (undefined4 *)0x0) {
    iVar16 = 1;
  }
  if (iVar16 == 0) {
    puVar4 = (undefined4 *)0x0;
  }
  fVar18 = (float)VectorSignedToFloat(iVar16,(byte)(in_fpscr >> 0x15) & 3);
  param_1[0x8b] = (int)ALBW_AS_U32(ALBW_AS_F32(param_1[0x8b]) - fVar18);
  fVar32 = DAT_003e9774;
  fVar20 = DAT_003e9770;
  fVar18 = DAT_003e976c;
  if (iVar16 != 0) {
    bVar14 = *(char *)(iVar12 + 0x182) != '\0';
    if (bVar14) {
      in_d12 = CONCAT44((int)((ulonglong)in_d12 >> 0x20),fVar29);
    }
    uVar28 = CONCAT44(*(float *)(iVar12 + 0x254) * *(float *)(iVar9 + 0x220) * ALBW_AS_F32(param_1[0x70]),
                      ALBW_AS_F32(param_1[0x69]) * *(float *)(iVar9 + 0x23c));
    uVar31 = CONCAT44(iVar3,DAT_003e9770);
    if (bVar14) {
      in_d12 = CONCAT44((int)in_d12,(int)in_d12);
    }
    fVar29 = *(float *)(iVar12 + 600) * *(float *)(iVar9 + 0x224) * ALBW_AS_F32(param_1[0x71]);
    fVar30 = *(float *)(iVar12 + 0x25c) * *(float *)(iVar9 + 0x228) * ALBW_AS_F32(param_1[0x72]);
    if (!bVar14) {
      fVar21 = (float)VectorUnsignedToFloat
                                (*(undefined4 *)(iVar12 + 0x264),(byte)(in_fpscr >> 0x15) & 3);
      fVar21 = fVar21 * DAT_003e9778;
      if (*(char *)(iVar12 + 0x17f) == '\0') {
        fVar18 = (float)VectorSignedToFloat(*(undefined4 *)(iVar12 + 0x260),
                                            (byte)(in_fpscr >> 0x15) & 3);
        in_d12 = CONCAT44(fVar21,fVar18 * DAT_003e9778);
      }
      else {
        fVar17 = (float)VectorUnsignedToFloat(param_1[0x22],(byte)(in_fpscr >> 0x15) & 3);
        param_1[0x22] = param_1[0x22] * DAT_003e977c + 0x3039;
        in_d12 = CONCAT44(fVar21,fVar17 * fVar20 * fVar18 * fVar32);
      }
    }
    iVar3 = DAT_003e9788;
    puVar4 = (undefined4 *)0x0;
    iVar9 = 0;
    if (0 < iVar16) {
      uVar33 = CONCAT44(DAT_003e978c,DAT_003e9784);
      fVar18 = DAT_003e9780;
      do {
        uVar5 = (**(code **)(*(int *)param_1[0x35] + 0xc))((int *)param_1[0x35]);
        puVar6 = (undefined4 *)func_003F856C(*DAT_003e9790,uVar5);
        if (puVar6 != (undefined4 *)0x0) {
          if (puVar4 == (undefined4 *)0x0) {
            puVar4 = puVar6;
          }
          cVar1 = *(char *)(iVar12 + 0x182);
          puVar6[0x52] = 0;
          puVar6[0x4e] = iVar12;
          uVar10 = DAT_003e977c;
          fVar20 = DAT_003e976c;
          iVar7 = param_1[0x22];
          if (cVar1 == '\0') {
            fVar20 = (float)VectorUnsignedToFloat(iVar7,(byte)(in_fpscr >> 0x15) & 3);
            param_1[0x22] = iVar7 * DAT_003e977c + 0x3039;
            uVar34 = func_00114608((uint)ALBW_AS_U32(((ALBW_AS_F32(in_d12) +
                                          fVar20 * ALBW_AS_F32(uVar31) *
                                          ALBW_AS_F32(((ulonglong)in_d12 >> 0x20))) * fVar18)),uVar10);
            uVar10 = (uint)uVar34 & 0xffffff;
            pfVar8 = (float *)(iVar3 + ((uint)uVar34 >> 0x18) * 0x10);
            fVar20 = (float)VectorUnsignedToFloat(uVar10,(byte)(in_fpscr >> 0x15) & 3);
            fVar20 = fVar20 * ALBW_AS_F32(uVar33);
            uVar34 = CONCAT44(pfVar8[2] + pfVar8[3] * fVar20,*pfVar8 + pfVar8[1] * fVar20);
          }
          else {
            fVar21 = (float)VectorUnsignedToFloat(iVar7,(byte)(in_fpscr >> 0x15) & 3);
            param_1[0x22] = iVar7 * DAT_003e977c + 0x3039;
            uVar34 = func_00114608((uint)ALBW_AS_U32((fVar21 * ALBW_AS_F32(uVar31) * fVar20 * fVar32 * fVar18)),uVar10)
            ;
            uVar10 = (uint)uVar34 & 0xffffff;
            pfVar8 = (float *)(iVar3 + ((uint)uVar34 >> 0x18) * 0x10);
            fVar20 = (float)VectorUnsignedToFloat(uVar10,(byte)(in_fpscr >> 0x15) & 3);
            fVar20 = fVar20 * ALBW_AS_F32(uVar33);
            uVar34 = CONCAT44(pfVar8[2] + pfVar8[3] * fVar20,*pfVar8 + pfVar8[1] * fVar20);
          }
          if (*(char *)(iVar12 + 0x182) == '\0') {
            fVar20 = (float)VectorUnsignedToFloat(param_1[0x22],(byte)(in_fpscr >> 0x15) & 3);
            param_1[0x22] = param_1[0x22] * DAT_003e977c + 0x3039;
            local_100 = fVar20 * ALBW_AS_F32(uVar31) * fVar32 - ALBW_AS_F32(((ulonglong)uVar31 >> 0x20));
          }
          else {
            uVar35 = func_00114608((uint)ALBW_AS_U32((*(float *)(iVar12 + 0x270) * fVar18)),uVar10);
            iVar11 = param_1[0x22];
            local_100 = ALBW_AS_F32(((ulonglong)uVar31 >> 0x20));
            iVar7 = iVar3 + ((uint)uVar35 >> 0x18) * 0x10;
            fVar20 = (float)VectorUnsignedToFloat
                                      ((uint)uVar35 & 0xffffff,(byte)(in_fpscr >> 0x15) & 3);
            param_1[0x22] = iVar11 * DAT_003e977c + 0x3039;
            fVar21 = (float)VectorUnsignedToFloat(iVar11,(byte)(in_fpscr >> 0x15) & 3);
            local_100 = local_100 -
                        (local_100 -
                        (*(float *)(iVar7 + 8) + *(float *)(iVar7 + 0xc) * fVar20 * ALBW_AS_F32(uVar33)))
                        * fVar21 * ALBW_AS_F32(uVar31);
          }
          fVar20 = ALBW_AS_F32(((ulonglong)uVar31 >> 0x20));
          fVar21 = fVar20 - local_100 * local_100;
          uVar10 = in_fpscr & 0xfffffff;
          uVar15 = uVar10 | (uint)(fVar21 == DAT_003e9764) << 0x1e |
                   (uint)(DAT_003e9764 <= fVar21) << 0x1d;
          bVar2 = (byte)(uVar15 >> 0x18);
          local_fc = DAT_003e9764;
          if ((bool)(bVar2 >> 5 & 1) && !(bool)(bVar2 >> 6)) {
            local_fc = SQRT(fVar21);
          }
          local_104 = local_fc * ALBW_AS_F32(uVar34);
          local_fc = local_fc * ALBW_AS_F32(((ulonglong)uVar34 >> 0x20));
          fVar21 = DAT_003e9764;
          if (*(char *)(iVar12 + 0x182) != '\0') {
            uVar15 = uVar10 | (uint)(*(float *)(iVar12 + 0x274) == DAT_003e9764) << 0x1e;
            bVar14 = false;
            if (SUB41(uVar15 >> 0x1e,0)) {
              bVar14 = *(int *)(iVar12 + 0x278) == 0x3f800000;
            }
            bVar13 = false;
            if (bVar14) {
              uVar15 = uVar10 | (uint)(*(float *)(iVar12 + 0x27c) == DAT_003e9764) << 0x1e;
              bVar13 = SUB41(uVar15 >> 0x1e,0);
            }
            if (!bVar13) {
              fVar25 = *(float *)(iVar12 + 0x274);
              fVar27 = *(float *)(iVar12 + 0x278);
              fVar26 = *(float *)(iVar12 + 0x27c);
              fVar22 = DAT_003e9764 * fVar25 + fVar20 * fVar27 + DAT_003e9764 * fVar26 + fVar20;
              fVar17 = DAT_003e9764;
              fVar19 = fVar20;
              fVar23 = DAT_003e9764;
              fVar24 = DAT_003e9764;
              if (0x34000000 < (int)ALBW_AS_U32(fVar22)) {
                fVar23 = SQRT(fVar22 * fVar32);
                fVar24 = fVar20 / fVar23;
                fVar17 = (DAT_003e9764 * fVar25 - DAT_003e9764 * fVar26) * fVar24;
                fVar19 = (fVar20 * fVar26 - DAT_003e9764 * fVar27) * fVar24;
                fVar23 = fVar23 * ALBW_AS_F32(((ulonglong)uVar33 >> 0x20));
                fVar24 = (DAT_003e9764 * fVar27 - fVar20 * fVar25) * fVar24;
              }
              local_b4 = DAT_003e9764;
              local_a4 = DAT_003e9764;
              local_94 = DAT_003e9764;
              fVar27 = fVar32 / (fVar19 * fVar19 + fVar17 * fVar17 + fVar24 * fVar24 +
                                fVar23 * fVar23);
              fVar25 = fVar17 * fVar27;
              fVar22 = fVar24 * fVar27;
              fVar26 = fVar19 * fVar19 * fVar27;
              local_9c = fVar23 * fVar19 * fVar27;
              local_a8 = fVar17 * fVar22 - local_9c;
              local_9c = fVar17 * fVar22 + local_9c;
              local_bc = fVar19 * fVar25 - fVar23 * fVar22;
              local_b0 = fVar19 * fVar25 + fVar23 * fVar22;
              local_b8 = fVar19 * fVar22 + fVar23 * fVar25;
              local_a0 = fVar19 * fVar22 - fVar23 * fVar25;
              local_c0 = fVar20 - (fVar17 * fVar25 + fVar24 * fVar22);
              local_98 = fVar20 - (fVar26 + fVar17 * fVar25);
              fStack_ac = fVar20 - (fVar26 + fVar24 * fVar22);
              local_88 = local_104;
              local_84 = local_100;
              local_80 = local_fc;
              func_00115074(&local_104,&local_c0,&local_88);
            }
          }
          fVar17 = local_104 * ALBW_AS_F32(((ulonglong)uVar28 >> 0x20));
          in_fpscr = uVar15 & 0xfffffff | (uint)(*(float *)(iVar12 + 0x310) == fVar21) << 0x1e;
          puVar6[2] = ALBW_AS_U32(fVar17);
          puVar6[3] = ALBW_AS_U32(local_100 * fVar29);
          puVar6[4] = ALBW_AS_U32(local_fc * fVar30);
          fVar19 = ALBW_AS_F32(uVar28);
          puVar6[8] = ALBW_AS_U32(local_104 * fVar19);
          puVar6[9] = ALBW_AS_U32(local_100 * fVar19);
          puVar6[10] = ALBW_AS_U32(local_fc * fVar19);
          if (!SUB41(in_fpscr >> 0x1e,0)) {
            fVar19 = ALBW_AS_F32(puVar6[4]);
            if ((int)ALBW_AS_U32((fVar17 * fVar17 + fVar21 * fVar21 + fVar19 * fVar19)) < 0x800001) {
              iVar7 = param_1[0x22] * DAT_003e977c + 0x3039;
              fVar17 = (float)VectorUnsignedToFloat(param_1[0x22],(byte)(in_fpscr >> 0x15) & 3);
              fVar19 = (float)VectorUnsignedToFloat(iVar7,(byte)(in_fpscr >> 0x15) & 3);
              param_1[0x22] = iVar7 * DAT_003e977c + 0x3039;
              fVar17 = fVar17 * ALBW_AS_F32(uVar31) * fVar32 - fVar20;
              fVar19 = fVar19 * ALBW_AS_F32(uVar31) * fVar32 - fVar20;
            }
            fVar22 = fVar17 * fVar17 + fVar21 * fVar21 + fVar19 * fVar19;
            in_fpscr = uVar15 & 0xfffffff | (uint)(fVar22 == fVar21) << 0x1e;
            fVar23 = fVar21;
            fVar24 = fVar21;
            if (!SUB41(in_fpscr >> 0x1e,0)) {
              fVar20 = fVar20 / SQRT(fVar22);
              fVar24 = fVar21 * fVar20;
              fVar21 = fVar19 * fVar20;
              fVar23 = fVar17 * fVar20;
            }
            fVar20 = *(float *)(iVar12 + 0x310);
            puVar6[8] = ALBW_AS_U32(ALBW_AS_F32(puVar6[8]) + fVar23 * fVar20);
            puVar6[9] = ALBW_AS_U32(ALBW_AS_F32(puVar6[9]) + fVar24 * fVar20);
            puVar6[10] = ALBW_AS_U32(ALBW_AS_F32(puVar6[10]) + fVar21 * fVar20);
          }
          if ((*(uint *)(param_1[0x36] + 4) & 0x400000) == 0) {
            func_003E728C((int)param_1,puVar6);
          }
          else {
            func_003E8730((int)param_1,puVar6);
          }
        }
        iVar9 = iVar9 + 1;
      } while (iVar9 < iVar16);
    }
    param_1[2] = param_1[2] | 8;
  }
  return puVar4;
}

