/* compilefix: USA 0064B4A0 (EU 0064B478), Ghidra-derived (build/ghidra_analyzed4).
 * Failed to compile: operand of type 'float' cannot be cast to a pointer type
 * Fixed (each an exact C form of the ARM operation; the rest is the converted Ghidra text):
 *  - (T *)<float expr> -> (T *)CF_FBITS(expr): 32-bit copy of the float (vmov/vstr), never a conversion [29]
 *  - explicit casts at pointer-type mismatches (identity on the ARM) [2]
 * Confidence: high for the fixes (each class checked against the EU disassembly on sample sites);
 * the function body otherwise has the fidelity of the Ghidra output (bare `return;` exits of
 * functions retyped non-void return 0, as the converter does). *
 * 160bj: param_3 is typed float * but holds integers in two places: word 0 (the current face
 * pointer) and word 0xD (the segment index). The text converted them as numbers, (int)*param_3 /
 * (int)param_3[0xd]: the index (a tiny denormal as a float) always became 0, and the face pointer
 * became garbage - a crash at address 0x3564 when merged Link went past a corner (user, slots 1 / 2).
 * Now bit copies (ALBW_AS_U32), as the ARM's plain ldr. */
#include "ghidra_types.h"
#include "../include/ghidra_concat44.h"
#include "compilefix.h"

extern float func_0010F1F8(int *param_1,float fparam_0);
extern int func_00115C54(float *param_1,float *param_2,float *param_3);
extern int func_00115C70(float *param_1,float *param_2,float *param_3);
extern int func_00115D70(float *param_1,float *param_2,float fparam_0);
extern float func_00115DC8(float *param_1);
extern int func_00115E10(float *param_1,float *param_2,float *param_3);
extern int func_001EA738(undefined4 param_1,int *param_2,int param_3,float *param_4,float fparam_0);
extern int func_001FE680(undefined4 *param_1);
extern int func_0048C258(int *param_1,undefined *param_2);
extern int func_004A17A4(float *param_1);
extern int func_00688AB0(undefined4 *param_1);
extern float *DAT_0064b848;
extern float *DAT_0064b84c;
extern undefined4 DAT_0064b850;
extern float DAT_0064b854;
extern float DAT_0064b858;
extern float *DAT_0064b85c;
extern undefined4 DAT_0064b860;
extern int DAT_0064beb8;
extern uint DAT_0064bebc;
extern float DAT_0064bec0;
extern float DAT_0064bec4;
extern float DAT_0064bec8;
extern float DAT_0064caec;
extern float *DAT_0064caf0;
extern float DAT_0064caf4;
extern int DAT_0064caf8;
extern undefined *DAT_0064cafc;

// USA 0064B4A0 <- EU 0064B478 (Ghidra, non-matching)
// GLOBAL DAT_0064b848 float *
// GLOBAL DAT_0064b84c float *
// GLOBAL DAT_0064b850 undefined4
// GLOBAL DAT_0064b854 float
// GLOBAL DAT_0064b858 float
// GLOBAL DAT_0064b85c float *
// GLOBAL DAT_0064b860 undefined4
// GLOBAL DAT_0064beb8 int
// GLOBAL DAT_0064bebc uint
// GLOBAL DAT_0064bec0 float
// GLOBAL DAT_0064bec4 float
// GLOBAL DAT_0064bec8 float
// GLOBAL DAT_0064caec float
// GLOBAL DAT_0064caf0 float *
// GLOBAL DAT_0064caf4 float
// GLOBAL DAT_0064caf8 int
// GLOBAL DAT_0064cafc undefined *

undefined4 func_0064B4A0(int param_1,float *param_2,float *param_3)

{
  undefined1 uVar1;
  float *pfVar2;
  uint uVar3;
  int iVar4;
  float fVar5;
  float fVar6;
  int *piVar7;
  float *pfVar8;
  float fVar9;
  int *piVar10;
  int *extraout_r1;
  float **ppfVar11;
  int iVar12;
  uint uVar13;
  float *pfVar14;
  uint *puVar15;
  bool bVar16;
  bool bVar17;
  float fVar18;
  float *pfVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float *fparam_0;
  float *pfVar24;
  ulonglong uVar25;
  ulonglong uVar26;
  undefined8 uVar27;
  float *pfVar28;
  float *pfVar29;
  float *pfVar30;
  float *pfVar31;
  undefined4 uVar33;
  undefined8 uVar32;
  _Alignas(8) unsigned char albw_frame[0x400];
  #define local_400 (*(float *)(albw_frame + 0x0))
  #define local_3fc (*(float * *)(albw_frame + 0x4))
  #define local_3f8 (*(float * *)(albw_frame + 0x8))
  #define local_3f4 (*(float * *)(albw_frame + 0xc))
  #define uStack_3f0 (*(undefined4 *)(albw_frame + 0x10))
  #define local_3ec (*(float * *)(albw_frame + 0x14))
  #define local_3e8 (*(float * *)(albw_frame + 0x18))
  #define local_3e4 (*(float * *)(albw_frame + 0x1c))
  #define local_3e0 (*(uint *)(albw_frame + 0x20))
  #define iStack_3dc (*(int *)(albw_frame + 0x24))
  #define local_3d8 (*(int *)(albw_frame + 0x28))
  #define local_3d4 (*(float * *)(albw_frame + 0x2c))
  #define local_1cc (*(uint *)(albw_frame + 0x234))
  #define local_1c8 (*(float *)(albw_frame + 0x238))
  #define local_1c4 (*(float *)(albw_frame + 0x23c))
  #define local_1c0 (*(float *)(albw_frame + 0x240))
  #define local_1bc (*(float *)(albw_frame + 0x244))
  #define local_1b8 (*(float *)(albw_frame + 0x248))
  #define local_1b4 (*(float *)(albw_frame + 0x24c))
  #define local_1b0 ((float * *)(albw_frame + 0x250))
  #define local_1a0 (*(float * *)(albw_frame + 0x260))
  #define local_19c (*(float * *)(albw_frame + 0x264))
  #define local_198 (*(float * *)(albw_frame + 0x268))
  #define local_194 (*(float * *)(albw_frame + 0x26c))
  #define local_190 (*(float *)(albw_frame + 0x270))
  #define local_18c (*(float * *)(albw_frame + 0x274))
  #define local_188 (*(float *)(albw_frame + 0x278))
  #define local_184 (*(float * *)(albw_frame + 0x27c))
  #define local_180 (*(float * *)(albw_frame + 0x280))
  #define local_17c (*(float * *)(albw_frame + 0x284))
  #define local_178 (*(float *)(albw_frame + 0x288))
  #define local_174 (*(float *)(albw_frame + 0x28c))
  #define local_170 (*(float *)(albw_frame + 0x290))
  #define local_16c (*(int *)(albw_frame + 0x294))
  #define local_168 (*(float *)(albw_frame + 0x298))
  #define local_164 (*(float * *)(albw_frame + 0x29c))
  #define local_160 (*(float * *)(albw_frame + 0x2a0))
  #define local_15c (*(float *)(albw_frame + 0x2a4))
  #define local_158 (*(float *)(albw_frame + 0x2a8))
  #define local_154 (*(float *)(albw_frame + 0x2ac))
  #define local_150 ((float *)(albw_frame + 0x2b0))
  #define local_140 (*(float *)(albw_frame + 0x2c0))
  #define local_13c (*(float *)(albw_frame + 0x2c4))
  #define local_138 (*(float *)(albw_frame + 0x2c8))
  #define local_134 (*(float *)(albw_frame + 0x2cc))
  #define local_130 (*(float *)(albw_frame + 0x2d0))
  #define local_12c ((float *)(albw_frame + 0x2d4))
  #define local_11c (*(float *)(albw_frame + 0x2e4))
  #define local_118 (*(float *)(albw_frame + 0x2e8))
  #define local_114 (*(float *)(albw_frame + 0x2ec))
  #define local_110 (*(float *)(albw_frame + 0x2f0))
  #define local_10c (*(float *)(albw_frame + 0x2f4))
  #define local_108 (*(float * *)(albw_frame + 0x2f8))
  #define pfStack_104 (*(float * *)(albw_frame + 0x2fc))
  #define uStack_100 (*(undefined4 *)(albw_frame + 0x300))
  #define local_fc (*(float * *)(albw_frame + 0x304))
  #define pfStack_f8 (*(float * *)(albw_frame + 0x308))
  #define uStack_f4 (*(undefined4 *)(albw_frame + 0x30c))
  #define local_f0 (*(float * *)(albw_frame + 0x310))
  #define pfStack_ec (*(float * *)(albw_frame + 0x314))
  #define pfStack_e8 (*(float * *)(albw_frame + 0x318))
  #define local_e4 (*(float * *)(albw_frame + 0x31c))
  #define pfStack_e0 (*(float * *)(albw_frame + 0x320))
  #define local_dc (*(float * *)(albw_frame + 0x324))
  #define local_d8 (*(float * *)(albw_frame + 0x328))
  #define local_d4 (*(float * *)(albw_frame + 0x32c))
  #define local_d0 (*(float * *)(albw_frame + 0x330))
  #define local_cc ((float * *)(albw_frame + 0x334))
  #define local_c4 (*(float *)(albw_frame + 0x33c))
  #define local_c0 ((float *)(albw_frame + 0x340))
  #define local_b4 (*(float * *)(albw_frame + 0x34c))
  #define pfStack_b0 (*(float * *)(albw_frame + 0x350))
  #define local_ac (*(float * *)(albw_frame + 0x354))
  #define local_a8 (*(float *)(albw_frame + 0x358))
  #define local_a4 (*(float *)(albw_frame + 0x35c))
  #define local_a0 (*(float *)(albw_frame + 0x360))
  #define local_9c (*(float * *)(albw_frame + 0x364))
  #define pfStack_98 (*(float * *)(albw_frame + 0x368))
  #define pfStack_94 (*(float * *)(albw_frame + 0x36c))
  #define local_90 (*(int *)(albw_frame + 0x370))
  #define local_8c (*(float * *)(albw_frame + 0x374))
  #define pfStack_88 (*(float * *)(albw_frame + 0x378))
  #define pfStack_84 (*(float * *)(albw_frame + 0x37c))
  #define local_80 (*(float * *)(albw_frame + 0x380))
  #define local_30 (*(int *)(albw_frame + 0x3d0))
  #define pfStack_2c (*(float * *)(albw_frame + 0x3d4))
  #define pfStack_28 (*(float * *)(albw_frame + 0x3d8))
  if (param_2 != (float *)0x0) {
    param_2[10] = ALBW_AS_F32(((int)ALBW_AS_U32(param_2[10]) + 1));
  }
  pfVar14 = (float *)0x0;
  local_164 = (float *)CF_FBITS(DAT_0064b848[1]);
  local_168 = *DAT_0064b848;
  local_160 = (float *)CF_FBITS(DAT_0064b848[2]);
  local_158 = DAT_0064b84c[1];
  local_15c = *DAT_0064b84c;
  local_154 = DAT_0064b84c[2];
  local_1c8 = param_3[1];
  local_1c4 = param_3[2];
  local_1c0 = param_3[3];
  local_1bc = param_3[4];
  local_1b8 = param_3[5];
  local_1b4 = param_3[6];
  uVar33 = DAT_0064b850;
  local_30 = param_1;
  pfStack_2c = param_2;
  pfStack_28 = param_3;
  func_00688AB0(&local_3e0);
  local_90 = 0;
  local_1a0 = (float *)0x0;
  fVar6 = DAT_0064b854;
  func_00115D70((float *)&local_3f8,param_3 + 7,DAT_0064b854);
  local_fc = local_3f8;
  pfStack_f8 = local_3f4;
  uStack_f4 = uStack_3f0;
  func_00115C54((float *)&local_3f8,param_3 + 1,(float *)&local_fc);
  local_108 = local_3f8;
  pfStack_104 = local_3f4;
  uStack_100 = uStack_3f0;
  func_00115D70((float *)&local_3fc,(float *)(local_30 + 0x54),fVar6);
  local_f0 = local_3fc;
  pfStack_ec = local_3f8;
  pfStack_e8 = local_3f4;
  func_00115C54(&local_400,(float *)&local_108,(float *)&local_f0);
  local_168 = local_400;
  local_164 = local_3fc;
  local_160 = local_3f8;
  local_15c = param_3[4];
  local_158 = param_3[5];
  local_154 = param_3[6];
  local_1cc = 0;
  func_00115D70((float *)&local_3fc,param_3 + 7,fVar6);
  local_e4 = local_3fc;
  pfStack_e0 = local_3f8;
  local_dc = local_3f4;
  func_00115C54(&local_400,param_3 + 1,(float *)&local_e4);
  local_168 = local_400;
  local_164 = local_3fc;
  local_160 = local_3f8;
  local_15c = param_3[4];
  uVar32 = CONCAT44(uVar33,DAT_0064b860);
  local_158 = param_3[5];
  local_154 = param_3[6];
  fVar9 = *param_3;
  pfVar29 = (float *)CF_FBITS(param_3[0xb]);
  local_16c = 1;
  local_3e4 = (float *)((int)ALBW_AS_U32(fVar9) + 0x24);
  fVar20 = *(float *)((int)ALBW_AS_U32(fVar9) + 0x30);
  fVar21 = *(float *)((int)ALBW_AS_U32(fVar9) + 0x34);
  fVar22 = *(float *)((int)ALBW_AS_U32(fVar9) + 0x38);
  fVar18 = local_1bc * fVar20 + local_1b8 * fVar21 + local_1b4 * fVar22;
  fVar5 = DAT_0064b858;
  pfVar30 = DAT_0064b85c;
  local_80 = &local_1c8;
  if ((fVar18 < DAT_0064b858) || (fVar6 < fVar18)) {
    pfVar28 = (float *)CF_FBITS((((fVar20 * *local_3e4 + fVar21 * *(float *)((int)ALBW_AS_U32(fVar9) + 0x28) +
                         fVar22 * *(float *)((int)ALBW_AS_U32(fVar9) + 0x2c)) -
                        (fVar20 * local_1c8 + fVar21 * local_1c4 + fVar22 * local_1c0)) / fVar18));
    pfVar19 = (float *)CF_FBITS((ALBW_AS_F32(pfVar28) - ALBW_AS_F32(pfVar29)));
    if ((ALBW_AS_F32(pfVar19) <= fVar6) && (DAT_0064b858 <= ALBW_AS_F32(pfVar28))) {
      fVar18 = fVar6;
      func_00115D70((float *)&local_184,&local_1bc,ALBW_AS_F32(pfVar28));
      local_d4 = local_184;
      local_d0 = local_180;
      local_cc[0] = local_17c;
      func_00115C54((float *)&local_184,&local_1c8,(float *)&local_d4);
      local_1b0[0] = local_184;
      local_1b0[1] = local_180;
      local_1b0[2] = local_17c;
      func_00115C70((float *)&local_3ec,(float *)local_1b0,local_3e4);
      pfVar19 = local_3e8;
      if (((ALBW_AS_F32(local_3ec) * *(float *)((int)ALBW_AS_U32(fVar9) + 0x3c) +
            ALBW_AS_F32(local_3e8) * *(float *)((int)ALBW_AS_U32(fVar9) + 0x40) +
            ALBW_AS_F32(local_3e4) * *(float *)((int)ALBW_AS_U32(fVar9) + 0x44) <= fVar18) &&
          (ALBW_AS_F32(local_3ec) * *(float *)((int)ALBW_AS_U32(fVar9) + 0x48) +
           ALBW_AS_F32(local_3e8) * *(float *)((int)ALBW_AS_U32(fVar9) + 0x4c) +
           ALBW_AS_F32(local_3e4) * *(float *)((int)ALBW_AS_U32(fVar9) + 0x50) <= fVar18)) &&
         (ALBW_AS_F32(local_3ec) * *(float *)((int)ALBW_AS_U32(fVar9) + 0x54) +
          ALBW_AS_F32(local_3e8) * *(float *)((int)ALBW_AS_U32(fVar9) + 0x58) +
          ALBW_AS_F32(local_3e4) * *(float *)((int)ALBW_AS_U32(fVar9) + 0x5c) <= *(float *)((int)ALBW_AS_U32(fVar9) + 0x68) + fVar18
         )) goto LAB_0064b9f8;
    }
LAB_0064ba18:
    pfVar28 = pfVar30;
    local_16c = 0;
    pfVar30 = pfVar28;
  }
  else {
    fVar18 = fVar6;
    func_00115C70((float *)&local_d4,&local_1c8,local_3e4);
    pfVar19 = (float *)CF_FBITS((ALBW_AS_F32(local_d4) * *(float *)((int)ALBW_AS_U32(fVar9) + 0x30) +
                        ALBW_AS_F32(local_d0) * *(float *)((int)ALBW_AS_U32(fVar9) + 0x34) +
                       ALBW_AS_F32(local_cc[0]) * *(float *)((int)ALBW_AS_U32(fVar9) + 0x38)));
    if (fVar18 < ALBW_AS_F32(pfVar19)) {
      pfVar28 = (float *)uVar32;
    }
    else {
      fVar20 = -fVar18;
      iVar12 = 0;
      local_1b0[0] = (float *)((int)ALBW_AS_U32(fVar9) + 0x3c);
      local_1b0[1] = (float *)((int)ALBW_AS_U32(fVar9) + 0x48);
      local_1b0[2] = (float *)((int)ALBW_AS_U32(fVar9) + 0x54);
      pfVar28 = local_d0;
      pfVar24 = local_d4;
      pfVar8 = local_cc[0];
      pfVar31 = pfVar30;
      do {
        pfVar2 = local_1b0[iVar12];
        fVar22 = pfVar2[1];
        fVar21 = pfVar2[2];
        pfVar19 = (float *)CF_FBITS((local_1bc * *pfVar2 + local_1b8 * fVar22 + local_1b4 * fVar21));
        bVar16 = fVar20 == ALBW_AS_F32(pfVar19);
        bVar17 = ALBW_AS_F32(pfVar19) <= fVar20;
        if (!bVar17 || bVar16) {
          bVar16 = ALBW_AS_F32(pfVar19) == fVar18;
          bVar17 = fVar18 <= ALBW_AS_F32(pfVar19);
        }
        if (bVar17 && !bVar16) {
          fVar23 = *pfVar2 * ALBW_AS_F32(pfVar24);
          if (iVar12 == 2) {
            fVar21 = *(float *)((int)ALBW_AS_U32(fVar9) + 0x68) -
                     (fVar23 + fVar22 * ALBW_AS_F32(pfVar28) + fVar21 * ALBW_AS_F32(pfVar8));
          }
          else {
            fVar21 = -(fVar23 + fVar22 * ALBW_AS_F32(pfVar28) + fVar21 * ALBW_AS_F32(pfVar8));
          }
          pfVar2 = (float *)CF_FBITS((fVar21 / ALBW_AS_F32(pfVar19)));
          if (ALBW_AS_F32(pfVar31) <= ALBW_AS_F32(pfVar2) && ALBW_AS_F32(pfVar30) <= ALBW_AS_F32(pfVar2)) {
            bVar16 = ALBW_AS_F32(pfVar29) <= ALBW_AS_F32(pfVar2);
            fparam_0 = pfVar29;
            if (!bVar16) {
              fparam_0 = pfVar2;
            }
            func_00115D70((float *)&local_9c,&local_1bc,ALBW_AS_F32(fparam_0));
            local_d4 = local_9c;
            local_d0 = pfStack_98;
            local_cc[0] = pfStack_94;
            func_00115C54((float *)&local_8c,local_80,(float *)&local_d4);
            local_b4 = local_8c;
            pfStack_b0 = pfStack_88;
            local_ac = pfStack_84;
            func_00115C70(&local_190,(float *)&local_b4,local_3e4);
            pfVar19 = local_18c;
            if (((local_190 * *local_1b0[0] + ALBW_AS_F32(local_18c) * local_1b0[0][1] +
                  local_188 * local_1b0[0][2] <= fVar18) &&
                (local_190 * *local_1b0[1] + ALBW_AS_F32(local_18c) * local_1b0[1][1] +
                 local_188 * local_1b0[1][2] <= fVar18)) &&
               ((local_190 * *local_1b0[2] + ALBW_AS_F32(local_18c) * local_1b0[2][1] +
                 local_188 * local_1b0[2][2] <= *(float *)((int)ALBW_AS_U32(fVar9) + 0x68) + fVar18 &&
                (pfVar30 = fparam_0, bVar16)))) break;
          }
        }
        iVar12 = iVar12 + 1;
      } while (iVar12 < 3);
      bVar16 = ALBW_AS_F32(pfVar30) == ALBW_AS_F32(pfVar31);
      pfVar28 = pfVar30;
      pfVar30 = pfVar31;
      if (bVar16) goto LAB_0064ba18;
    }
LAB_0064b9f8:
    if ((pfVar28 == (float *)0xff7fffff) || ((int)pfVar28 < DAT_0064beb8)) goto LAB_0064ba18;
  }
  local_190 = ALBW_AS_F32((local_30 + 0x3d00));
  if (*(char *)(local_30 + 0x3dc2) == '\0') {
    pfVar29 = pfVar28;
    local_1a0 = (float *)func_001EA738(local_30,(int *)&local_198,(int)ALBW_AS_U32(param_3[0xc]),&local_168,
                                       ALBW_AS_F32(pfVar28));
    pfVar19 = pfVar28;
    pfVar28 = pfVar29;
  }
  iVar12 = DAT_0064beb8;
  pfVar29 = pfVar30;
  if (local_1a0 == (float *)0x0 && local_16c == 0) {
    if ((param_2 == (float *)0x0) || (param_2[10] != 1.4013e-45)) {
      return 3;
    }
    local_178 = local_1c8;
    local_174 = local_1c4;
    local_170 = local_1c0;
LAB_0064bf6c:
    fVar9 = param_3[0xc];
    pfVar28 = pfVar30;
    func_0010F1F8((int *)((int)ALBW_AS_U32(*param_3) + *(int *)((int)ALBW_AS_U32(fVar9) + 0xc)),ALBW_AS_F32(pfVar19));
    *(int *)((int)ALBW_AS_U32(fVar9) + 8) = *(int *)((int)ALBW_AS_U32(fVar9) + 8) + -1;
  }
  else {
    bVar16 = (int)local_1a0 < 0;
    bVar17 = local_1a0 != (float *)0x0;
    if (bVar17) {
      bVar16 = ALBW_AS_F32(pfVar28) < ALBW_AS_F32(local_198);
      pfVar19 = local_198;
    }
    pfVar24 = local_198;
    if (((bVar17 && ALBW_AS_F32(pfVar28) != ALBW_AS_F32(local_198)) &&
         bVar16 == (bVar17 && (NAN(ALBW_AS_F32(pfVar28)) || NAN(ALBW_AS_F32(local_198))))) &&
       ((((local_16c == 0 || (ALBW_AS_F32(pfVar19) != ALBW_AS_F32(pfVar30))) ||
         (pfVar24 = pfVar28, (int)ALBW_AS_U32(param_2[10]) < 2)) &&
        ((pfVar28 = pfVar19, pfVar24 = local_198, *(char *)((int)ALBW_AS_U32(local_190) + 0xc4) == '\0' &&
         (*(float *)(local_30 + 0x74) < param_3[0xb] - ALBW_AS_F32(pfVar19))))))) {
      local_90 = 1;
    }
    local_198 = pfVar24;
    uVar13 = 0;
    puVar15 = *(uint **)(local_30 + 4);
    uVar3 = *puVar15;
    if (0 < (int)uVar3) {
      uVar26 = (ulonglong)DAT_0064bebc;
      fVar9 = DAT_0064bec0;
      pfVar19 = pfVar28;
      do {
        if (uVar13 < uVar3) {
          iVar4 = *(int *)(puVar15[2] + uVar13 * 4);
        }
        else {
          iVar4 = 0;
        }
        fVar18 = ALBW_AS_F32((iVar4 + 8));
        fVar20 = *(float *)(iVar4 + 0x30);
        fVar21 = *(float *)(iVar4 + 0x34);
        fVar22 = *(float *)(iVar4 + 0x38);
        fVar23 = local_15c * fVar20 + local_158 * fVar21 + local_154 * fVar22;
        if ((fVar23 <= ALBW_AS_F32(pfVar30)) && (iVar12 <= (int)ALBW_AS_U32(-fVar23))) {
          fVar23 = local_15c * fVar20 + local_158 * fVar21 + local_154 * fVar22;
          local_400 = fVar18;
          if (((fVar23 < ALBW_AS_F32(uVar26)) || (fVar9 < fVar23)) &&
             ((pfVar24 = (float *)CF_FBITS((((fVar20 * *(float *)(iVar4 + 0x24) +
                                     fVar21 * *(float *)(iVar4 + 0x28) +
                                    fVar22 * *(float *)(iVar4 + 0x2c)) -
                                   (fVar20 * local_168 + fVar21 * ALBW_AS_F32(local_164) +
                                   fVar22 * ALBW_AS_F32(local_160))) / fVar23)),
              (int)ALBW_AS_U32((ALBW_AS_F32(pfVar24) - ALBW_AS_F32(pfVar19))) <= iVar12 && (ALBW_AS_F32(pfVar30) <= ALBW_AS_F32(pfVar24))
              ))) {
            local_194 = &local_168;
            func_00115D70((float *)&local_184,&local_15c,ALBW_AS_F32(pfVar24));
            local_1b0[3] = local_184;
            local_1a0 = local_180;
            local_19c = local_17c;
            func_00115C54((float *)&local_d4,local_194,(float *)(local_1b0 + 3));
            local_1b0[0] = local_d4;
            local_1b0[1] = local_d0;
            local_1b0[2] = local_cc[0];
            func_00115C70((float *)&local_b4,(float *)local_1b0,(float *)(iVar4 + 0x24));
            if (((int)ALBW_AS_U32((ALBW_AS_F32(local_b4) * *(float *)((int)ALBW_AS_U32(local_400) + 0x34) +
                       ALBW_AS_F32(pfStack_b0) * *(float *)((int)ALBW_AS_U32(local_400) + 0x38) +
                      ALBW_AS_F32(local_ac) * *(float *)((int)ALBW_AS_U32(local_400) + 0x3c))) <= iVar12) &&
               ((((int)ALBW_AS_U32((ALBW_AS_F32(local_b4) * *(float *)((int)ALBW_AS_U32(local_400) + 0x40) +
                        ALBW_AS_F32(pfStack_b0) * *(float *)((int)ALBW_AS_U32(local_400) + 0x44) +
                       ALBW_AS_F32(local_ac) * *(float *)((int)ALBW_AS_U32(local_400) + 0x48))) <= iVar12 &&
                 (ALBW_AS_F32(local_b4) * *(float *)((int)ALBW_AS_U32(local_400) + 0x4c) +
                  ALBW_AS_F32(pfStack_b0) * *(float *)((int)ALBW_AS_U32(local_400) + 0x50) +
                  ALBW_AS_F32(local_ac) * *(float *)((int)ALBW_AS_U32(local_400) + 0x54) <=
                  *(float *)((int)ALBW_AS_U32(local_400) + 0x60) + fVar9)) && (pfVar24 != (float *)0xff7fffff))))
            {
              local_198 = pfVar24;
              if (((uVar13 < *puVar15) && (*(int *)(puVar15[2] + uVar13 * 4) != 0)) &&
                 ((*(char *)((int)ALBW_AS_U32(local_190) + 0xc4) != '\0' ||
                  (param_3[0xb] - ALBW_AS_F32(pfVar24) <= *(float *)(local_30 + 0x74))))) {
                local_1cc = 1;
                pfVar28 = pfVar24;
              }
              break;
            }
          }
        }
        uVar3 = *puVar15;
        uVar13 = uVar13 + 1;
      } while ((int)uVar13 < (int)uVar3);
    }
    func_00115D70((float *)&local_3fc,&local_1bc,ALBW_AS_F32(pfVar28));
    local_e4 = local_3fc;
    pfStack_e0 = local_3f8;
    local_dc = local_3f4;
    func_00115C54(&local_178,&local_1c8,(float *)&local_e4);
    pfVar30 = (float *)CF_FBITS((param_3[0xb] - ALBW_AS_F32(pfVar28)));
    pfVar19 = (float *)CF_FBITS((ALBW_AS_F32(pfVar28) - param_3[0xb]));
    bVar16 = DAT_0064bec8 == ALBW_AS_F32(pfVar19);
    bVar17 = ALBW_AS_F32(pfVar19) <= DAT_0064bec8;
    if (!bVar17 || bVar16) {
      bVar16 = ALBW_AS_F32(pfVar19) == DAT_0064bec4;
      bVar17 = DAT_0064bec4 <= ALBW_AS_F32(pfVar19);
    }
    if ((local_1cc & ~(uint)(!bVar17 || bVar16)) != 0) goto LAB_0064c9b4;
    if ((!bVar17 || bVar16) != 0) {
      func_001FE680((undefined4 *)(local_1b0));
      local_1b0[0] = pfVar29;
      if (local_1cc != 0) {
        local_1b0[0] = (float *)CF_FBITS((param_3[0xb] - ALBW_AS_F32(pfVar28)));
      }
      fVar5 = *param_3;
      fVar6 = param_3[5];
      fVar9 = param_3[6];
      piVar7 = (int *)CF_FBITS(param_2[0xb]);
      if (piVar7 == (int *)0x0) {
        param_2[4] = param_3[4];
        param_2[5] = fVar6;
        param_2[6] = fVar9;
        param_2[1] = local_178;
        param_2[2] = local_174;
        param_2[3] = local_170;
        *param_2 = ALBW_AS_F32(local_1b0[0]);
        param_2[8] = fVar5;
        pfVar30 = (float *)CF_FBITS(param_2[9]);
        if (pfVar30 != (float *)0x0) {
          if ((uint)ALBW_AS_U32(param_3[0xd]) < (uint)ALBW_AS_U32(*pfVar30)) {
            fVar5 = ALBW_AS_F32(((int)ALBW_AS_U32(pfVar30[2]) + (int)ALBW_AS_U32(param_3[0xd]) * 0x9c));
          }
          else {
            fVar5 = pfVar30[2];
          }
          *(float *)((int)ALBW_AS_U32(fVar5) + 0x30) = param_2[1];
          *(float *)((int)ALBW_AS_U32(fVar5) + 0x34) = param_2[2];
          *(float *)((int)ALBW_AS_U32(fVar5) + 0x38) = param_2[3];
          *(float *)((int)ALBW_AS_U32(fVar5) + 0x74) = *param_2;
        }
        return 0;
      }
      iVar12 = *piVar7;
      if (iVar12 < piVar7[1]) {
        *piVar7 = iVar12 + 1;
        pfVar30 = (float *)(piVar7[2] + iVar12 * 0x10);
      }
      else {
        pfVar30 = (float *)0x0;
      }
      *pfVar30 = ALBW_AS_F32(pfVar28);
      pfVar30[1] = param_3[7];
      pfVar30[2] = param_3[8];
      pfVar30[3] = param_3[9];
      return 0;
    }
    pfVar30 = pfVar28;
    if (local_90 == 0) goto LAB_0064bf6c;
  }
  fVar9 = param_3[0xb];
  pfVar30 = (float *)CF_FBITS((fVar9 - ALBW_AS_F32(pfVar28)));
  local_1a0 = (float *)((int)ALBW_AS_U32(param_3[0xc]) - *(int *)((int)ALBW_AS_U32(param_3[0xc]) + 0xc));
  iVar12 = *(int *)((int)ALBW_AS_U32(param_3[0xc]) + 0xc);
  pfVar19 = (float *)(*(int *)((int)ALBW_AS_U32(param_3[0xc]) + 4) - iVar12);
  if (pfVar19 != local_1a0) {
    do {
      fVar9 = pfVar19[0xc] * param_3[7] + pfVar19[0xd] * param_3[8] + pfVar19[0xe] * param_3[9];
      if ((((uint)ALBW_AS_U32(fVar9) <= (uint)ALBW_AS_U32(DAT_0064caec)) &&
          (func_00115C70(&local_a8,&local_178,pfVar19 + 9), fVar9 = local_a4,
          local_a8 * pfVar19[0xf] + local_a4 * pfVar19[0x10] + local_a0 * pfVar19[0x11] <= fVar6))
         && ((local_a8 * pfVar19[0x12] + local_a4 * pfVar19[0x13] + local_a0 * pfVar19[0x14] <=
              fVar6 && (local_a8 * pfVar19[0x15] + local_a4 * pfVar19[0x16] +
                        local_a0 * pfVar19[0x17] <= pfVar19[0x1a] + fVar6)))) {
        fVar18 = -(local_a8 * pfVar19[0xc] + local_a4 * pfVar19[0xd] + local_a0 * pfVar19[0xe]);
        if ((fVar18 < fVar5) || (fVar9 = fVar6, fVar6 < fVar18)) {
          fVar18 = ALBW_AS_F32(uVar32);
        }
        if (fVar18 != -3.4028235e+38) {
          uVar26 = (ulonglong)
                   (uint)ALBW_AS_U32((pfVar19[0xc] * param_3[4] + pfVar19[0xd] * param_3[5] +
                         pfVar19[0xe] * param_3[6]));
          if (pfVar14 == (float *)0x0) {
            func_00115E10(&local_190,DAT_0064caf0,param_3 + 7);
            pfVar14 = local_c0;
            func_00115E10(pfVar14,&local_190,DAT_0064caf0);
          }
          fVar20 = ALBW_AS_F32(uVar26);
          if ((uint)ALBW_AS_U32(DAT_0064caf4) < (uint)ALBW_AS_U32(fVar20)) {
            local_150[0] = pfVar19[9];
            local_150[1] = pfVar19[10];
            uVar25 = ZEXT48(pfVar29);
            local_150[2] = pfVar19[0xb];
            pfVar24 = pfVar19 + 9;
            fVar20 = pfVar19[0xe] * pfVar19[0x10] - pfVar19[0xd] * pfVar19[0x11];
            fVar21 = pfVar19[0xc] * pfVar19[0x11] - pfVar19[0xe] * pfVar19[0xf];
            fVar22 = pfVar19[0xd] * pfVar19[0xf] - pfVar19[0xc] * pfVar19[0x10];
            fVar9 = fVar20 * pfVar19[0x15] + fVar21 * pfVar19[0x16] + fVar22 * pfVar19[0x17];
            if (fVar9 <= ALBW_AS_F32(pfVar29)) {
              local_150[3] = *pfVar24;
              local_140 = pfVar19[10];
              local_13c = pfVar19[0xb];
            }
            else {
              fVar9 = pfVar19[0x1a] / fVar9;
              local_150[3] = *pfVar24 + fVar20 * fVar9;
              local_140 = pfVar19[10] + fVar21 * fVar9;
              local_13c = pfVar19[0xb] + fVar22 * fVar9;
            }
            fVar20 = pfVar19[0x14] * pfVar19[0xd] - pfVar19[0x13] * pfVar19[0xe];
            fVar21 = pfVar19[0x12] * pfVar19[0xe] - pfVar19[0x14] * pfVar19[0xc];
            fVar22 = pfVar19[0x13] * pfVar19[0xc] - pfVar19[0x12] * pfVar19[0xd];
            fVar9 = fVar20 * pfVar19[0x15] + fVar21 * pfVar19[0x16] + fVar22 * pfVar19[0x17];
            if (fVar9 <= ALBW_AS_F32(pfVar29)) {
              local_138 = *pfVar24;
              local_134 = pfVar19[10];
              local_130 = pfVar19[0xb];
            }
            else {
              fVar9 = pfVar19[0x1a] / fVar9;
              local_138 = *pfVar24 + fVar20 * fVar9;
              local_134 = pfVar19[10] + fVar21 * fVar9;
              local_130 = pfVar19[0xb] + fVar22 * fVar9;
            }
            func_00115C70(&local_400,local_150,param_3 + 1);
            iVar4 = 0;
            fVar20 = *pfVar14 * local_400 + pfVar14[1] * ALBW_AS_F32(local_3fc) +
                     pfVar14[2] * ALBW_AS_F32(local_3f8);
            fVar21 = fVar20;
            do {
              fVar9 = fVar21;
              fVar21 = fVar9;
              if (iVar4 != 2) {
                func_00115C70((float *)&local_19c,local_150 + (iVar4 + 1) * 3,param_3 + 1);
                fVar9 = *pfVar14 * ALBW_AS_F32(local_19c) + pfVar14[1] * ALBW_AS_F32(local_198) +
                        pfVar14[2] * ALBW_AS_F32(local_194);
              }
              fVar22 = ALBW_AS_F32(uVar25);
              bVar16 = fVar20 == fVar22;
              bVar17 = fVar22 <= fVar20;
              if (!bVar17 || bVar16) {
                bVar16 = fVar9 == fVar22;
                bVar17 = fVar22 <= fVar9;
              }
              fVar20 = ALBW_AS_F32(uVar26);
              if (bVar17 && !bVar16) goto LAB_0064c560;
              iVar4 = iVar4 + 1;
              fVar20 = fVar9;
            } while (iVar4 < 3);
          }
          else if (DAT_0064beb8 < (int)ALBW_AS_U32(fVar20)) {
            func_00115D70((float *)&local_3fc,pfVar14,ALBW_AS_F32(((ulonglong)uVar32 >> 0x20)));
            local_12c[0] = pfVar19[9];
            local_12c[1] = pfVar19[10];
            local_12c[2] = pfVar19[0xb];
            pfVar24 = pfVar19 + 9;
            fVar9 = pfVar19[0xe] * pfVar19[0x10] - pfVar19[0xd] * pfVar19[0x11];
            fVar20 = pfVar19[0xc] * pfVar19[0x11] - pfVar19[0xe] * pfVar19[0xf];
            fVar21 = pfVar19[0xd] * pfVar19[0xf] - pfVar19[0xc] * pfVar19[0x10];
            fVar22 = fVar9 * pfVar19[0x15] + fVar20 * pfVar19[0x16] + fVar21 * pfVar19[0x17];
            if (fVar22 <= ALBW_AS_F32(pfVar29)) {
              local_12c[3] = *pfVar24;
              local_11c = pfVar19[10];
              local_118 = pfVar19[0xb];
            }
            else {
              fVar22 = pfVar19[0x1a] / fVar22;
              local_12c[3] = *pfVar24 + fVar9 * fVar22;
              local_11c = pfVar19[10] + fVar20 * fVar22;
              local_118 = pfVar19[0xb] + fVar21 * fVar22;
            }
            fVar9 = pfVar19[0x14] * pfVar19[0xd] - pfVar19[0x13] * pfVar19[0xe];
            fVar20 = pfVar19[0x12] * pfVar19[0xe] - pfVar19[0x14] * pfVar19[0xc];
            fVar22 = pfVar19[0x13] * pfVar19[0xc] - pfVar19[0x12] * pfVar19[0xd];
            fVar21 = fVar9 * pfVar19[0x15] + fVar20 * pfVar19[0x16] + fVar22 * pfVar19[0x17];
            if (fVar21 <= ALBW_AS_F32(pfVar29)) {
              local_114 = *pfVar24;
              local_110 = pfVar19[10];
              local_10c = pfVar19[0xb];
            }
            else {
              fVar21 = pfVar19[0x1a] / fVar21;
              local_114 = *pfVar24 + fVar9 * fVar21;
              local_110 = pfVar19[10] + fVar20 * fVar21;
              local_10c = pfVar19[0xb] + fVar22 * fVar21;
            }
            pfVar24 = local_3f4;
            pfVar8 = local_3f8;
            pfVar31 = local_3fc;
            pfVar2 = pfVar29;
            func_00115C70(&local_190,local_12c,param_3 + 1);
            iVar4 = 0;
            fVar20 = ALBW_AS_F32(pfVar31) * local_190 + ALBW_AS_F32(pfVar8) * ALBW_AS_F32(local_18c) +
                     ALBW_AS_F32(pfVar24) * local_188;
            uVar27 = CONCAT44(pfVar2,fVar20);
            do {
              if (iVar4 == 2) {
                fVar9 = ALBW_AS_F32(uVar27);
              }
              else {
                func_00115C70(&local_190,local_12c + (iVar4 + 1) * 3,param_3 + 1);
                fVar9 = ALBW_AS_F32(pfVar31) * local_190 + ALBW_AS_F32(pfVar8) * ALBW_AS_F32(local_18c) +
                        ALBW_AS_F32(pfVar24) * local_188;
              }
              fVar21 = ALBW_AS_F32(((ulonglong)uVar27 >> 0x20));
              bVar16 = fVar20 == fVar21;
              bVar17 = fVar21 <= fVar20;
              if (!bVar17 || bVar16) {
                bVar16 = fVar9 == fVar21;
                bVar17 = fVar21 <= fVar9;
              }
              fVar20 = ALBW_AS_F32(uVar26);
              if (bVar17 && !bVar16) goto LAB_0064c560;
              iVar4 = iVar4 + 1;
              fVar20 = fVar9;
            } while (iVar4 < 3);
          }
          else {
LAB_0064c560:
            fVar9 = fVar20;
            pfVar24 = local_3d4;
            if ((int)local_3e0 < iStack_3dc) {
              if (local_3d4 != (float *)0x0) {
                pfVar8 = (float *)CF_FBITS(*local_3d4);
                *local_3d4 = 0.0;
                local_3d4[1] = 0.0;
                local_3d4[2] = 0.0;
                local_3d4 = pfVar8;
              }
              if ((int)local_3e0 < iStack_3dc) {
                *(float **)(local_3d8 + local_3e0 * 4) = pfVar24;
                local_3e0 = local_3e0 + 1;
              }
            }
            else {
              pfVar24 = (float *)0x0;
            }
            iVar4 = DAT_0064caf8;
            *pfVar24 = ALBW_AS_F32(pfVar19);
            pfVar24[1] = fVar9;
            if (fVar18 <= ALBW_AS_F32(pfVar29)) {
              fVar18 = -fVar18;
            }
            pfVar24[2] = fVar18;
            if ((int)ALBW_AS_U32(fVar18) < iVar4) {
              pfVar24[2] = ALBW_AS_F32(pfVar29);
            }
          }
        }
      }
      pfVar19 = (float *)(*(int *)((int)pfVar19 + iVar12 + 4) - iVar12);
    } while (pfVar19 != local_1a0);
  }
  if (local_3e0 != 0) {
    piVar7 = (int *)CF_FBITS(param_2[0xb]);
    if (piVar7 == (int *)0x0) {
      pfVar14 = (float *)CF_FBITS(param_2[9]);
      if (pfVar14 != (float *)0x0) {
        if ((uint)ALBW_AS_U32(param_3[0xd]) < (uint)ALBW_AS_U32(*pfVar14)) {
          fVar5 = ALBW_AS_F32(((int)ALBW_AS_U32(pfVar14[2]) + (int)ALBW_AS_U32(param_3[0xd]) * 0x9c));
        }
        else {
          fVar5 = pfVar14[2];
        }
        *(float *)((int)ALBW_AS_U32(fVar5) + 0x30) = local_178;
        *(float *)((int)ALBW_AS_U32(fVar5) + 0x34) = local_174;
        *(float *)((int)ALBW_AS_U32(fVar5) + 0x38) = local_170;
        *(float **)((int)ALBW_AS_U32(fVar5) + 0x74) = pfVar30;
      }
    }
    else {
      iVar12 = *piVar7;
      if (iVar12 < piVar7[1]) {
        *piVar7 = iVar12 + 1;
        pfVar14 = (float *)(piVar7[2] + iVar12 * 0x10);
      }
      else {
        pfVar14 = (float *)0x0;
      }
      *pfVar14 = ALBW_AS_F32(pfVar28);
      pfVar14[1] = param_3[7];
      pfVar14[2] = param_3[8];
      pfVar14[3] = param_3[9];
    }
    func_0048C258((int *)&local_3e0,DAT_0064cafc);
    local_188 = param_3[10];
    uVar3 = 0;
    local_180 = (float *)CF_FBITS(param_3[0xc]);
    local_184 = pfVar30;
    if (0 < (int)local_3e0) {
      do {
        fVar5 = param_3[0xc];
        if (uVar3 < local_3e0) {
          pfVar14 = *(float **)(local_3d8 + uVar3 * 4);
        }
        else {
          pfVar14 = (float *)0x0;
        }
        pfVar14 = (float *)CF_FBITS(*pfVar14);
        piVar10 = (int *)(*(int *)((int)ALBW_AS_U32(fVar5) + 0xc) + (int)pfVar14);
        piVar7 = piVar10 + 1;
        if (*piVar7 == 0) {
          piVar10 = (int *)*piVar10;
        }
        if (*piVar7 != 0 || piVar10 != (int *)0x0) {
          if ((local_90 == 0) || ((float *)CF_FBITS(*param_3) != pfVar14)) {
            local_194 = (float *)CF_FBITS(pfVar14[0xc]);
            ppfVar11 = local_1b0;
            local_190 = pfVar14[0xd];
            local_18c = (float *)CF_FBITS(pfVar14[0xe]);
            local_1b0[0] = pfVar14;
            func_00115C70((float *)&local_b4,&local_178,pfVar14 + 9);
            local_dc = local_ac;
            local_e4 = local_b4;
            pfStack_e0 = pfStack_b0;
            func_00115D70((float *)&local_9c,(float *)&local_194,
                          ALBW_AS_F32(local_194) * ALBW_AS_F32(local_b4) + local_190 * ALBW_AS_F32(pfStack_b0) +
                          ALBW_AS_F32(local_18c) * ALBW_AS_F32(local_ac));
            local_d8 = local_9c;
            local_d4 = pfStack_98;
            local_d0 = pfStack_94;
            func_00115C70((float *)&local_8c,&local_178,(float *)&local_d8);
            local_1b0[1] = local_8c;
            local_1b0[2] = pfStack_88;
            local_1b0[3] = pfStack_84;
            func_00115E10((float *)&local_1a0,(float *)&local_194,(float *)CF_FBITS(param_3[10]));
            func_00115DC8((float *)&local_1a0);
            func_00115C54((float *)&local_3ec,(float *)(local_1b0 + 1),(float *)&local_1a0);
            local_e4 = local_3ec;
            pfStack_e0 = local_3e8;
            local_dc = local_3e4;
            func_00115C70((float *)local_cc,(float *)&local_e4,param_3 + 1);
            fVar9 = ALBW_AS_F32(local_18c) * ALBW_AS_F32(local_cc[0]) - ALBW_AS_F32(local_194) * local_c4;
            if (fVar9 < ALBW_AS_F32(pfVar29)) {
              piVar7 = extraout_r1;
              if (param_2 != (float *)0x0) {
                piVar7 = (int *)CF_FBITS(param_2[9]);
              }
              if (param_2 != (float *)0x0 && piVar7 != (int *)0x0) {
                iVar12 = *piVar7;
                uVar1 = *(undefined1 *)(piVar7[2] + iVar12 * 0x9c + -0xc);
                if (iVar12 < piVar7[1]) {
                  *piVar7 = iVar12 + 1;
                  pfVar19 = (float *)(piVar7[2] + iVar12 * 0x9c);
                }
                else {
                  pfVar19 = (float *)0x0;
                }
                pfVar19[9] = ALBW_AS_F32(local_1b0[1]);
                pfVar19[10] = ALBW_AS_F32(local_1b0[2]);
                pfVar19[0xb] = ALBW_AS_F32(local_1b0[3]);
                pfVar19[0x1c] = ALBW_AS_F32(pfVar30);
                *(undefined1 *)(pfVar19 + 0x24) = uVar1;
                *pfVar19 = ALBW_AS_F32(local_1a0);
                pfVar19[1] = ALBW_AS_F32(local_19c);
                pfVar19[2] = ALBW_AS_F32(local_198);
                pfVar19[6] = ALBW_AS_F32(local_194);
                pfVar19[7] = local_190;
                pfVar19[8] = ALBW_AS_F32(local_18c);
                func_004A17A4(pfVar19);
                local_17c = (float *)(*(int *)CF_FBITS(param_2[9]) + -1);
              }
              uVar13 = func_0064B4A0(local_30,param_2,(float *)ppfVar11);
              if (uVar13 < 2) {
                return 0;
              }
              if (param_2 != (float *)0x0) {
                ppfVar11 = (float **)CF_FBITS(param_2[9]);
              }
              if ((param_2 != (float *)0x0 && ppfVar11 != (float **)0x0) &&
                 ((float *)((int)*ppfVar11 - 1U) <= ppfVar11[1])) {
                *ppfVar11 = (float *)((int)*ppfVar11 - 1U);
              }
              pfVar19 = local_180;
              if (uVar13 == 2) {
                piVar7 = (int *)((int)ALBW_AS_U32(local_180[3]) + (int)pfVar14);
                iVar12 = piVar7[1];
                bVar16 = iVar12 == 0;
                if (bVar16) {
                  iVar12 = *piVar7;
                }
                if (!bVar16 || iVar12 != 0) {
                  func_0010F1F8(piVar7,fVar9);
                  pfVar19[2] = ALBW_AS_F32(((int)ALBW_AS_U32(pfVar19[2]) + -1));
                }
              }
              local_90 = 0;
            }
          }
          else {
            piVar7 = (int *)(*(int *)((int)ALBW_AS_U32(fVar5) + 0xc) + (int)ALBW_AS_U32(*param_3));
            iVar12 = piVar7[1];
            bVar16 = iVar12 == 0;
            if (bVar16) {
              iVar12 = *piVar7;
            }
            if (!bVar16 || iVar12 != 0) {
              func_0010F1F8(piVar7,fVar9);
              *(int *)((int)ALBW_AS_U32(fVar5) + 8) = *(int *)((int)ALBW_AS_U32(fVar5) + 8) + -1;
            }
          }
        }
        uVar3 = uVar3 + 1;
      } while ((int)uVar3 < (int)local_3e0);
    }
  }
LAB_0064c9b4:
  func_001FE680((undefined4 *)(local_1b0));
  fVar5 = *param_3;
  fVar6 = param_3[5];
  fVar9 = param_3[6];
  piVar7 = (int *)CF_FBITS(param_2[0xb]);
  if (piVar7 == (int *)0x0) {
    param_2[4] = param_3[4];
    param_2[5] = fVar6;
    param_2[6] = fVar9;
    param_2[1] = local_178;
    param_2[2] = local_174;
    param_2[3] = local_170;
    *param_2 = ALBW_AS_F32(pfVar30);
    param_2[8] = fVar5;
    pfVar30 = (float *)CF_FBITS(param_2[9]);
    if (pfVar30 != (float *)0x0) {
      fVar5 = pfVar30[2];
      if ((uint)ALBW_AS_U32(param_3[0xd]) < (uint)ALBW_AS_U32(*pfVar30)) {
        fVar5 = ALBW_AS_F32(((int)ALBW_AS_U32(fVar5) + (int)ALBW_AS_U32(param_3[0xd]) * 0x9c));
      }
      *(float *)((int)ALBW_AS_U32(fVar5) + 0x30) = param_2[1];
      *(float *)((int)ALBW_AS_U32(fVar5) + 0x34) = param_2[2];
      *(float *)((int)ALBW_AS_U32(fVar5) + 0x38) = param_2[3];
      *(float *)((int)ALBW_AS_U32(fVar5) + 0x74) = *param_2;
    }
  }
  else {
    iVar12 = *piVar7;
    if (iVar12 < piVar7[1]) {
      *piVar7 = iVar12 + 1;
      pfVar30 = (float *)(piVar7[2] + iVar12 * 0x10);
    }
    else {
      pfVar30 = (float *)0x0;
    }
    *pfVar30 = ALBW_AS_F32(pfVar28);
    pfVar30[1] = param_3[7];
    pfVar30[2] = param_3[8];
    pfVar30[3] = param_3[9];
  }
  return 1;
}

