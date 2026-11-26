/* compilefix: USA 003EC6A4 (EU 003EC684), the converted stage-2 text.
 * Fixed (BOOT_LOG 184): the ARM copies this word between a float and an integer (no vcvt), which the
 * converted text wrote as a conversion of the value. */
#include "ghidra_types.h"

extern undefined8 func_00114608(uint param_1,uint param_2);
extern int func_00115074(float *param_1,float *param_2,float *param_3);
extern int func_003E728C(int param_1,undefined4 *param_2);
extern int func_003E8730(int param_1,undefined4 *param_2);
extern int func_003F856C(int param_1,undefined4 param_2);
extern float DAT_003eca78;
extern int DAT_003eca7c;
extern int DAT_003eca80;
extern float DAT_003eca84;
extern float DAT_003eca88;
extern undefined4 DAT_003eca8c;
extern undefined4 DAT_003eca90;
extern undefined4 DAT_003eca94;
extern int DAT_003eca98;
extern int DAT_003eca9c;
extern int *DAT_003ecaa0;
extern int DAT_003ecaa4;

// USA 003EC6A4 <- EU 003EC684 (Ghidra, non-matching)
// GLOBAL DAT_003eca78 float
// GLOBAL DAT_003eca7c int
// GLOBAL DAT_003eca80 int
// GLOBAL DAT_003eca84 float
// GLOBAL DAT_003eca88 float
// GLOBAL DAT_003eca8c undefined4
// GLOBAL DAT_003eca90 undefined4
// GLOBAL DAT_003eca94 undefined4
// GLOBAL DAT_003eca98 int
// GLOBAL DAT_003eca9c int
// GLOBAL DAT_003ecaa0 int *
// GLOBAL DAT_003ecaa4 int

undefined4 * func_003EC6A4(int *param_1)

{
  uint uVar1;
  char cVar2;
  byte bVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  int iVar8;
  float fVar9;
  float *pfVar10;
  int iVar11;
  int iVar12;
  bool bVar13;
  bool bVar14;
  uint in_fpscr;
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
  undefined8 uVar27;
  undefined8 uVar28;
  undefined8 uVar29;
  float fVar30;
  undefined8 uVar31;
  undefined8 uVar32;
  _Alignas(8) unsigned char albw_frame[0xa0];
  #define local_a0 (*(float *)(albw_frame + 0x0))
  #define local_9c (*(float *)(albw_frame + 0x4))
  #define local_98 (*(float *)(albw_frame + 0x8))
  #define local_90 (*(float *)(albw_frame + 0x10))
  #define local_8c (*(float *)(albw_frame + 0x14))
  #define local_88 (*(float *)(albw_frame + 0x18))
  #define local_84 (*(float *)(albw_frame + 0x1c))
  #define local_80 (*(float *)(albw_frame + 0x20))
  #define local_7c (*(float *)(albw_frame + 0x24))
  #define local_78 (*(float *)(albw_frame + 0x28))
  #define local_74 (*(float *)(albw_frame + 0x2c))
  #define local_70 (*(float *)(albw_frame + 0x30))
  #define local_6c (*(float *)(albw_frame + 0x34))
  #define local_68 (*(float *)(albw_frame + 0x38))
  #define local_64 (*(float *)(albw_frame + 0x3c))
  #define local_60 (*(float *)(albw_frame + 0x40))
  #define fStack_5c (*(float *)(albw_frame + 0x44))
  #define fStack_58 (*(float *)(albw_frame + 0x48))
  iVar5 = DAT_003eca7c;
  fVar30 = DAT_003eca78;
  fVar22 = *(float *)param_1[7];
  iVar8 = param_1[6];
  iVar11 = param_1[0x36];
  fVar19 = ALBW_AS_F32(param_1[0x8b]) + ALBW_AS_F32(param_1[0x5a]) * fVar22;
  param_1[0x8b] = (int)ALBW_AS_U32(fVar19);
  if ((*param_1 == 0) && ((int)ALBW_AS_U32(fVar19) < 0x3f800000)) {
    in_fpscr = in_fpscr & 0xfffffff | (uint)(ALBW_AS_F32(param_1[0x5a]) * fVar22 == fVar30) << 0x1e;
    if (!SUB41(in_fpscr >> 0x1e,0)) {
      param_1[0x8b] = iVar5;
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
  fVar19 = (float)VectorSignedToFloat(iVar15,(byte)(in_fpscr >> 0x15) & 3);
  param_1[0x8b] = (int)ALBW_AS_U32(ALBW_AS_F32(param_1[0x8b]) - fVar19);
  if (iVar15 != 0) {
    pfVar10 = *(float **)(DAT_003eca80 + (uint)*(byte *)(iVar11 + 0x17e) * 4);
    puVar4 = (undefined4 *)0x0;
    iVar12 = 0;
    uVar27 = CONCAT44(*(float *)(iVar11 + 0x254) * *(float *)(iVar8 + 0x220) * ALBW_AS_F32(param_1[0x70]),
                      ALBW_AS_F32(param_1[0x69]) * *(float *)(iVar8 + 0x23c));
    fVar19 = *(float *)(iVar11 + 600) * *(float *)(iVar8 + 0x224) * ALBW_AS_F32(param_1[0x71]);
    uVar28 = CONCAT44(fVar30,*(float *)(iVar11 + 0x25c) * *(float *)(iVar8 + 0x228) *
                             ALBW_AS_F32(param_1[0x72]));
    if (0 < iVar15) {
      uVar29 = CONCAT44(DAT_003eca90,iVar5);
      uVar31 = CONCAT44(DAT_003eca8c,DAT_003eca94);
      fVar30 = DAT_003eca84;
      fVar22 = DAT_003eca88;
      do {
        local_a0 = *pfVar10;
        fVar16 = pfVar10[1];
        local_98 = pfVar10[2];
        pfVar10 = pfVar10 + 3;
        local_9c = fVar16;
        if ((*(char *)(iVar11 + 0x182) == '\0') ||
           (fVar9 = *(float *)(iVar11 + 0x270), DAT_003eca98 < (int)ALBW_AS_U32(fVar9))) {
LAB_003ec80c:
          uVar6 = (**(code **)(*(int *)param_1[0x35] + 0xc))((int *)param_1[0x35]);
          puVar7 = (undefined4 *)func_003F856C(*DAT_003ecaa0,uVar6);
          if (puVar4 == (undefined4 *)0x0) {
            puVar4 = puVar7;
          }
          if (puVar7 == (undefined4 *)0x0) break;
          cVar2 = *(char *)(iVar11 + 0x182);
          puVar7[0x4e] = iVar11;
          puVar7[0x52] = 0;
          if (cVar2 != '\0') {
            fVar16 = ALBW_AS_F32(((ulonglong)uVar28 >> 0x20));
            uVar1 = in_fpscr & 0xfffffff;
            in_fpscr = uVar1 | (uint)(*(float *)(iVar11 + 0x274) == fVar16) << 0x1e;
            bVar14 = false;
            if (SUB41(in_fpscr >> 0x1e,0)) {
              bVar14 = *(int *)(iVar11 + 0x278) == 0x3f800000;
            }
            bVar13 = false;
            if (bVar14) {
              in_fpscr = uVar1 | (uint)(*(float *)(iVar11 + 0x27c) == fVar16) << 0x1e;
              bVar13 = SUB41(in_fpscr >> 0x1e,0);
            }
            if (!bVar13) {
              fVar25 = *(float *)(iVar11 + 0x274);
              fVar26 = *(float *)(iVar11 + 0x278);
              fVar20 = *(float *)(iVar11 + 0x27c);
              local_68 = ALBW_AS_F32(uVar29);
              fVar17 = fVar16 * fVar25 + local_68 * fVar26 + fVar16 * fVar20 + local_68;
              fVar24 = ALBW_AS_F32(((ulonglong)uVar29 >> 0x20));
              fVar9 = fVar16;
              fVar18 = fVar16;
              fVar23 = local_68;
              fVar21 = fVar16;
              if (0x34000000 < (int)ALBW_AS_U32(fVar17)) {
                fVar9 = SQRT(fVar17 * fVar24);
                fVar21 = local_68 / fVar9;
                fVar9 = fVar9 * ALBW_AS_F32(((ulonglong)uVar31 >> 0x20));
                fVar18 = (fVar16 * fVar25 - fVar16 * fVar20) * fVar21;
                fVar23 = (local_68 * fVar20 - fVar16 * fVar26) * fVar21;
                fVar21 = (fVar16 * fVar26 - local_68 * fVar25) * fVar21;
              }
              fVar24 = fVar24 / (fVar23 * fVar23 + fVar18 * fVar18 + fVar21 * fVar21 + fVar9 * fVar9
                                );
              fVar20 = fVar18 * fVar24;
              fVar17 = fVar21 * fVar24;
              fVar25 = fVar23 * fVar23 * fVar24;
              local_6c = fVar9 * fVar23 * fVar24;
              local_8c = fVar23 * fVar20 - fVar9 * fVar17;
              local_80 = fVar23 * fVar20 + fVar9 * fVar17;
              local_88 = fVar23 * fVar17 + fVar9 * fVar20;
              local_70 = fVar23 * fVar17 - fVar9 * fVar20;
              local_78 = fVar18 * fVar17 - local_6c;
              local_6c = fVar18 * fVar17 + local_6c;
              local_90 = local_68 - (fVar18 * fVar20 + fVar21 * fVar17);
              local_7c = local_68 - (fVar25 + fVar21 * fVar17);
              local_68 = local_68 - (fVar25 + fVar18 * fVar20);
              local_60 = local_a0;
              fStack_5c = local_9c;
              fStack_58 = local_98;
              local_84 = fVar16;
              local_74 = fVar16;
              local_64 = fVar16;
              func_00115074(&local_a0,&local_90,&local_60);
            }
          }
          fVar16 = ALBW_AS_F32(((ulonglong)uVar28 >> 0x20));
          fVar9 = local_a0 * ALBW_AS_F32(((ulonglong)uVar27 >> 0x20));
          uVar1 = in_fpscr & 0xfffffff;
          in_fpscr = uVar1 | (uint)(*(float *)(iVar11 + 0x310) == fVar16) << 0x1e;
          puVar7[2] = ALBW_AS_U32(fVar9);
          puVar7[3] = ALBW_AS_U32(local_9c * fVar19);
          puVar7[4] = ALBW_AS_U32(local_98 * ALBW_AS_F32(uVar28));
          fVar18 = ALBW_AS_F32(uVar27);
          puVar7[8] = ALBW_AS_U32(local_a0 * fVar18);
          puVar7[9] = ALBW_AS_U32(local_9c * fVar18);
          puVar7[10] = ALBW_AS_U32(local_98 * fVar18);
          if (!SUB41(in_fpscr >> 0x1e,0)) {
            fVar23 = ALBW_AS_F32(puVar7[4]);
            fVar18 = ALBW_AS_F32(uVar29);
            if ((int)ALBW_AS_U32((fVar9 * fVar9 + fVar16 * fVar16 + fVar23 * fVar23)) < 0x800001) {
              fVar9 = (float)VectorUnsignedToFloat(param_1[0x22],(byte)(in_fpscr >> 0x15) & 3);
              iVar5 = param_1[0x22] * DAT_003ecaa4 + 0x3039;
              fVar23 = (float)VectorUnsignedToFloat(iVar5,(byte)(in_fpscr >> 0x15) & 3);
              fVar21 = ALBW_AS_F32(((ulonglong)uVar29 >> 0x20));
              fVar9 = fVar9 * ALBW_AS_F32(uVar31) * fVar21 - fVar18;
              fVar23 = fVar23 * ALBW_AS_F32(uVar31) * fVar21 - fVar18;
              param_1[0x22] = iVar5 * DAT_003ecaa4 + 0x3039;
            }
            fVar20 = fVar9 * fVar9 + fVar16 * fVar16 + fVar23 * fVar23;
            in_fpscr = uVar1 | (uint)(fVar20 == fVar16) << 0x1e;
            fVar21 = fVar16;
            fVar17 = fVar16;
            if (!SUB41(in_fpscr >> 0x1e,0)) {
              fVar18 = fVar18 / SQRT(fVar20);
              fVar21 = fVar16 * fVar18;
              fVar16 = fVar23 * fVar18;
              fVar17 = fVar9 * fVar18;
            }
            fVar9 = *(float *)(iVar11 + 0x310);
            puVar7[8] = ALBW_AS_U32(ALBW_AS_F32(puVar7[8]) + fVar17 * fVar9);
            puVar7[9] = ALBW_AS_U32(ALBW_AS_F32(puVar7[9]) + fVar21 * fVar9);
            puVar7[10] = ALBW_AS_U32(ALBW_AS_F32(puVar7[10]) + fVar16 * fVar9);
          }
          if ((*(uint *)(param_1[0x36] + 4) & 0x400000) == 0) {
            func_003E728C((int)param_1,puVar7);
          }
          else {
            func_003E8730((int)param_1,puVar7);
          }
        }
        else {
          uVar32 = func_00114608((uint)ALBW_AS_U32((fVar9 * fVar30)),(uint)ALBW_AS_U32(fVar9));
          iVar5 = DAT_003eca9c + ((uint)uVar32 >> 0x18) * 0x10;
          fVar9 = (float)VectorUnsignedToFloat((uint)uVar32 & 0xffffff,(byte)(in_fpscr >> 0x15) & 3)
          ;
          fVar9 = *(float *)(iVar5 + 8) + *(float *)(iVar5 + 0xc) * fVar9 * fVar22;
          uVar1 = in_fpscr & 0xfffffff | (uint)(fVar16 < fVar9) << 0x1f |
                  (uint)(fVar16 == fVar9) << 0x1e;
          in_fpscr = uVar1 | (uint)(NAN(fVar16) || NAN(fVar9)) << 0x1c;
          bVar3 = (byte)(uVar1 >> 0x18);
          if (!(bool)(bVar3 >> 6 & 1) && bVar3 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1))
          goto LAB_003ec80c;
        }
        iVar12 = iVar12 + 1;
      } while (iVar12 < iVar15);
    }
    param_1[2] = param_1[2] | 8;
  }
  return puVar4;
}

