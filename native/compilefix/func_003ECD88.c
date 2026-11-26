/* compilefix: USA 003ECD88 (EU 003ECD68), the converted stage-2 text.
 * Fixed (BOOT_LOG 184): the ARM copies this word between a float and an integer (no vcvt), which the
 * converted text wrote as a conversion of the value. */
#include "ghidra_types.h"

extern undefined8 func_00114608(uint param_1,uint param_2);
extern int func_00115074(float *param_1,float *param_2,float *param_3);
extern int func_003E728C(int param_1,undefined4 *param_2);
extern int func_003E8730(int param_1,undefined4 *param_2);
extern int func_003F856C(int param_1,undefined4 param_2);
extern float DAT_003ed160;
extern int DAT_003ed164;
extern int DAT_003ed168;
extern float DAT_003ed16c;
extern float DAT_003ed170;
extern undefined4 DAT_003ed174;
extern undefined4 DAT_003ed178;
extern undefined4 DAT_003ed17c;
extern int DAT_003ed180;
extern int DAT_003ed184;
extern int *DAT_003ed188;
extern int DAT_003ed18c;

// USA 003ECD88 <- EU 003ECD68 (Ghidra, non-matching)
// GLOBAL DAT_003ed160 float
// GLOBAL DAT_003ed164 int
// GLOBAL DAT_003ed168 int
// GLOBAL DAT_003ed16c float
// GLOBAL DAT_003ed170 float
// GLOBAL DAT_003ed174 undefined4
// GLOBAL DAT_003ed178 undefined4
// GLOBAL DAT_003ed17c undefined4
// GLOBAL DAT_003ed180 int
// GLOBAL DAT_003ed184 int
// GLOBAL DAT_003ed188 int *
// GLOBAL DAT_003ed18c int

undefined4 * func_003ECD88(int *param_1)

{
  uint uVar1;
  float *pfVar2;
  float *pfVar3;
  float *pfVar4;
  float *pfVar5;
  char cVar6;
  byte bVar7;
  undefined4 *puVar8;
  int iVar9;
  undefined4 uVar10;
  undefined4 *puVar11;
  float fVar12;
  float *pfVar13;
  int iVar14;
  int iVar15;
  bool bVar16;
  bool bVar17;
  uint in_fpscr;
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
  undefined8 uVar30;
  undefined8 uVar31;
  undefined8 uVar32;
  float fVar33;
  undefined8 uVar34;
  undefined8 uVar35;
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
  iVar9 = DAT_003ed164;
  fVar33 = DAT_003ed160;
  fVar24 = *(float *)param_1[7];
  puVar8 = (undefined4 *)param_1[6];
  iVar14 = param_1[0x36];
  fVar22 = ALBW_AS_F32(param_1[0x8b]) + ALBW_AS_F32(param_1[0x5a]) * fVar24;
  param_1[0x8b] = (int)ALBW_AS_U32(fVar22);
  if ((*param_1 == 0) && ((int)ALBW_AS_U32(fVar22) < 0x3f800000)) {
    in_fpscr = in_fpscr & 0xfffffff | (uint)(ALBW_AS_F32(param_1[0x5a]) * fVar24 == fVar33) << 0x1e;
    if (!SUB41(in_fpscr >> 0x1e,0)) {
      param_1[0x8b] = iVar9;
    }
  }
  iVar18 = (int)ALBW_AS_F32(param_1[0x8b]);
  if (*(char *)(iVar14 + 0x181) != '\0') {
    iVar18 = 1;
  }
  if (iVar18 == 0) {
    puVar8 = (undefined4 *)0x0;
  }
  fVar22 = (float)VectorSignedToFloat(iVar18,(byte)(in_fpscr >> 0x15) & 3);
  param_1[0x8b] = (int)ALBW_AS_U32(ALBW_AS_F32(param_1[0x8b]) - fVar22);
  if (iVar18 != 0) {
    pfVar2 = (float *)(puVar8 + 0x89);
    pfVar3 = (float *)(puVar8 + 0x88);
    pfVar4 = (float *)(puVar8 + 0x8a);
    pfVar5 = (float *)(puVar8 + 0x8f);
    pfVar13 = *(float **)(DAT_003ed168 + (uint)*(byte *)(iVar14 + 0x17e) * 4 + 8);
    puVar8 = (undefined4 *)0x0;
    iVar15 = 0;
    uVar30 = CONCAT44(*(float *)(iVar14 + 0x254) * *pfVar3 * ALBW_AS_F32(param_1[0x70]),
                      ALBW_AS_F32(param_1[0x69]) * *pfVar5);
    fVar22 = *(float *)(iVar14 + 600) * *pfVar2 * ALBW_AS_F32(param_1[0x71]);
    uVar31 = CONCAT44(fVar33,*(float *)(iVar14 + 0x25c) * *pfVar4 * ALBW_AS_F32(param_1[0x72]));
    if (0 < iVar18) {
      uVar32 = CONCAT44(DAT_003ed178,iVar9);
      uVar34 = CONCAT44(DAT_003ed174,DAT_003ed17c);
      fVar33 = DAT_003ed16c;
      fVar24 = DAT_003ed170;
      do {
        local_a0 = *pfVar13;
        fVar19 = pfVar13[1];
        local_98 = pfVar13[2];
        pfVar13 = pfVar13 + 3;
        local_9c = fVar19;
        if ((*(char *)(iVar14 + 0x182) == '\0') ||
           (fVar12 = *(float *)(iVar14 + 0x270), DAT_003ed180 < (int)ALBW_AS_U32(fVar12))) {
LAB_003ecef4:
          uVar10 = (**(code **)(*(int *)param_1[0x35] + 0xc))((int *)param_1[0x35]);
          puVar11 = (undefined4 *)func_003F856C(*DAT_003ed188,uVar10);
          if (puVar8 == (undefined4 *)0x0) {
            puVar8 = puVar11;
          }
          if (puVar11 == (undefined4 *)0x0) break;
          cVar6 = *(char *)(iVar14 + 0x182);
          puVar11[0x4e] = iVar14;
          puVar11[0x52] = 0;
          if (cVar6 != '\0') {
            fVar19 = ALBW_AS_F32(((ulonglong)uVar31 >> 0x20));
            uVar1 = in_fpscr & 0xfffffff;
            in_fpscr = uVar1 | (uint)(*(float *)(iVar14 + 0x274) == fVar19) << 0x1e;
            bVar17 = false;
            if (SUB41(in_fpscr >> 0x1e,0)) {
              bVar17 = *(int *)(iVar14 + 0x278) == 0x3f800000;
            }
            bVar16 = false;
            if (bVar17) {
              in_fpscr = uVar1 | (uint)(*(float *)(iVar14 + 0x27c) == fVar19) << 0x1e;
              bVar16 = SUB41(in_fpscr >> 0x1e,0);
            }
            if (!bVar16) {
              fVar28 = *(float *)(iVar14 + 0x274);
              fVar29 = *(float *)(iVar14 + 0x278);
              fVar23 = *(float *)(iVar14 + 0x27c);
              local_68 = ALBW_AS_F32(uVar32);
              fVar20 = fVar19 * fVar28 + local_68 * fVar29 + fVar19 * fVar23 + local_68;
              fVar27 = ALBW_AS_F32(((ulonglong)uVar32 >> 0x20));
              fVar12 = fVar19;
              fVar21 = fVar19;
              fVar25 = local_68;
              fVar26 = fVar19;
              if (0x34000000 < (int)ALBW_AS_U32(fVar20)) {
                fVar12 = SQRT(fVar20 * fVar27);
                fVar26 = local_68 / fVar12;
                fVar12 = fVar12 * ALBW_AS_F32(((ulonglong)uVar34 >> 0x20));
                fVar21 = (fVar19 * fVar28 - fVar19 * fVar23) * fVar26;
                fVar25 = (local_68 * fVar23 - fVar19 * fVar29) * fVar26;
                fVar26 = (fVar19 * fVar29 - local_68 * fVar28) * fVar26;
              }
              fVar27 = fVar27 / (fVar25 * fVar25 + fVar21 * fVar21 + fVar26 * fVar26 +
                                fVar12 * fVar12);
              fVar23 = fVar21 * fVar27;
              fVar20 = fVar26 * fVar27;
              fVar28 = fVar25 * fVar25 * fVar27;
              local_6c = fVar12 * fVar25 * fVar27;
              local_8c = fVar25 * fVar23 - fVar12 * fVar20;
              local_80 = fVar25 * fVar23 + fVar12 * fVar20;
              local_88 = fVar25 * fVar20 + fVar12 * fVar23;
              local_70 = fVar25 * fVar20 - fVar12 * fVar23;
              local_78 = fVar21 * fVar20 - local_6c;
              local_6c = fVar21 * fVar20 + local_6c;
              local_90 = local_68 - (fVar21 * fVar23 + fVar26 * fVar20);
              local_7c = local_68 - (fVar28 + fVar26 * fVar20);
              local_68 = local_68 - (fVar28 + fVar21 * fVar23);
              local_60 = local_a0;
              fStack_5c = local_9c;
              fStack_58 = local_98;
              local_84 = fVar19;
              local_74 = fVar19;
              local_64 = fVar19;
              func_00115074(&local_a0,&local_90,&local_60);
            }
          }
          fVar12 = ALBW_AS_F32(((ulonglong)uVar31 >> 0x20));
          fVar19 = local_a0 * ALBW_AS_F32(((ulonglong)uVar30 >> 0x20));
          uVar1 = in_fpscr & 0xfffffff;
          in_fpscr = uVar1 | (uint)(*(float *)(iVar14 + 0x310) == fVar12) << 0x1e;
          puVar11[2] = ALBW_AS_U32(fVar19);
          puVar11[3] = ALBW_AS_U32(local_9c * fVar22);
          puVar11[4] = ALBW_AS_U32(local_98 * ALBW_AS_F32(uVar31));
          fVar21 = ALBW_AS_F32(uVar30);
          puVar11[8] = ALBW_AS_U32(local_a0 * fVar21);
          puVar11[9] = ALBW_AS_U32(local_9c * fVar21);
          puVar11[10] = ALBW_AS_U32(local_98 * fVar21);
          if (!SUB41(in_fpscr >> 0x1e,0)) {
            fVar25 = ALBW_AS_F32(puVar11[4]);
            fVar21 = ALBW_AS_F32(uVar32);
            if ((int)ALBW_AS_U32((fVar19 * fVar19 + fVar12 * fVar12 + fVar25 * fVar25)) < 0x800001) {
              fVar19 = (float)VectorUnsignedToFloat(param_1[0x22],(byte)(in_fpscr >> 0x15) & 3);
              iVar9 = param_1[0x22] * DAT_003ed18c + 0x3039;
              fVar25 = (float)VectorUnsignedToFloat(iVar9,(byte)(in_fpscr >> 0x15) & 3);
              fVar26 = ALBW_AS_F32(((ulonglong)uVar32 >> 0x20));
              fVar19 = fVar19 * ALBW_AS_F32(uVar34) * fVar26 - fVar21;
              fVar25 = fVar25 * ALBW_AS_F32(uVar34) * fVar26 - fVar21;
              param_1[0x22] = iVar9 * DAT_003ed18c + 0x3039;
            }
            fVar23 = fVar19 * fVar19 + fVar12 * fVar12 + fVar25 * fVar25;
            in_fpscr = uVar1 | (uint)(fVar23 == fVar12) << 0x1e;
            fVar26 = fVar12;
            fVar20 = fVar12;
            if (!SUB41(in_fpscr >> 0x1e,0)) {
              fVar21 = fVar21 / SQRT(fVar23);
              fVar26 = fVar12 * fVar21;
              fVar12 = fVar25 * fVar21;
              fVar20 = fVar19 * fVar21;
            }
            fVar19 = *(float *)(iVar14 + 0x310);
            puVar11[8] = ALBW_AS_U32(ALBW_AS_F32(puVar11[8]) + fVar20 * fVar19);
            puVar11[9] = ALBW_AS_U32(ALBW_AS_F32(puVar11[9]) + fVar26 * fVar19);
            puVar11[10] = ALBW_AS_U32(ALBW_AS_F32(puVar11[10]) + fVar12 * fVar19);
          }
          if ((*(uint *)(param_1[0x36] + 4) & 0x400000) == 0) {
            func_003E728C((int)param_1,puVar11);
          }
          else {
            func_003E8730((int)param_1,puVar11);
          }
        }
        else {
          uVar35 = func_00114608((uint)ALBW_AS_U32((fVar12 * fVar33)),(uint)ALBW_AS_U32(fVar12));
          iVar9 = DAT_003ed184 + ((uint)uVar35 >> 0x18) * 0x10;
          fVar12 = (float)VectorUnsignedToFloat
                                    ((uint)uVar35 & 0xffffff,(byte)(in_fpscr >> 0x15) & 3);
          fVar12 = *(float *)(iVar9 + 8) + *(float *)(iVar9 + 0xc) * fVar12 * fVar24;
          uVar1 = in_fpscr & 0xfffffff | (uint)(fVar19 < fVar12) << 0x1f |
                  (uint)(fVar19 == fVar12) << 0x1e;
          in_fpscr = uVar1 | (uint)(NAN(fVar19) || NAN(fVar12)) << 0x1c;
          bVar7 = (byte)(uVar1 >> 0x18);
          if (!(bool)(bVar7 >> 6 & 1) && bVar7 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1))
          goto LAB_003ecef4;
        }
        iVar15 = iVar15 + 1;
      } while (iVar15 < iVar18);
    }
    param_1[2] = param_1[2] | 8;
  }
  return puVar8;
}

