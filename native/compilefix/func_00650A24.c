/* compilefix: USA 00650A24 (EU 006509FC), Ghidra-derived (build/ghidra_analyzed4).
 * Failed to compile: operand of type 'float' cannot be cast to a pointer type
 * Fixed (each an exact C form of the ARM operation; the rest is the converted Ghidra text):
 *  - (T *)<float expr> -> (T *)CF_FBITS(expr): 32-bit copy of the float (vmov/vstr), never a conversion [49]
 *  - (float)<pointer> -> ALBW_AS_F32(pointer): 32-bit copy [1]
 *  - explicit (T)(uintptr_t) casts at int<->pointer mismatches (identity on the 32-bit ARM) [1]
 *  - implicit float<->int conversions (Ghidra COPY between a float and an int-typed variable or
 *    pool word, e.g. `fVar = _DAT_xxx;`, `puVar[3] = fVar;`) made bit copies [3]
 * Confidence: high for the fixes (each class checked against the EU disassembly on sample sites);
 * the function body otherwise has the fidelity of the Ghidra output (bare `return;` exits of
 * functions retyped non-void return 0, as the converter does). */
#include "ghidra_types.h"
#include "../include/ghidra_concat44.h"
#include "compilefix.h"

extern float func_0010F1F8(int *param_1,float fparam_0);
extern int func_00115B68(float *param_1,float *param_2,float *param_3);
extern int func_00115C54(float *param_1,float *param_2,float *param_3);
extern int func_00115C70(float *param_1,float *param_2,float *param_3);
extern int func_00115CE4(float *param_1,float *param_2,float *param_3);
extern int func_00115D70(float *param_1,float *param_2,float fparam_0);
extern float func_00115DC8(float *param_1);
extern int func_00115E10(float *param_1,float *param_2,float *param_3);
extern int func_001EA738(undefined4 param_1,int *param_2,int param_3,float *param_4,float fparam_0);
extern int func_0048C258(int *param_1,undefined *param_2);
extern int func_00491404(float *param_1,float *param_2);
extern int func_00688AB0(undefined4 *param_1);
extern undefined4 *DAT_00650e14;
extern float *DAT_00650e18;
extern float DAT_00650e1c;
extern float DAT_00650e20;
extern float DAT_00650e24;
extern uint DAT_00650e28;
extern float * * * * * * *DAT_00650e2c;
extern float * * * * * * *DAT_00650e30;
extern int DAT_00650e34;
extern float DAT_00650e38;
extern float DAT_00650e3c;
extern float DAT_00651214;
extern float DAT_00651acc;
extern float DAT_00651ad0;
extern float *DAT_00651ad4;
extern float DAT_00651ad8;
extern int DAT_00652134;
extern undefined *DAT_00652138;
extern float * * * * * * *DAT_0065213c;
extern uint DAT_00652140;
extern int DAT_00652144;
extern float * * * * * * *DAT_00652148;
extern int DAT_0065214c;

// USA 00650A24 <- EU 006509FC (Ghidra, non-matching)
// GLOBAL DAT_00650e14 undefined4 *
// GLOBAL DAT_00650e18 float *
// GLOBAL DAT_00650e1c float
// GLOBAL DAT_00650e20 float
// GLOBAL DAT_00650e24 float
// GLOBAL DAT_00650e28 uint
// GLOBAL DAT_00650e2c float * * * * * * *
// GLOBAL DAT_00650e30 float * * * * * * *
// GLOBAL DAT_00650e34 int
// GLOBAL DAT_00650e38 float
// GLOBAL DAT_00650e3c float
// GLOBAL DAT_00651214 float
// GLOBAL DAT_00651acc float
// GLOBAL DAT_00651ad0 float
// GLOBAL DAT_00651ad4 float *
// GLOBAL DAT_00651ad8 float
// GLOBAL DAT_00652134 int
// GLOBAL DAT_00652138 undefined *
// GLOBAL DAT_0065213c float * * * * * * *
// GLOBAL DAT_00652140 uint
// GLOBAL DAT_00652144 int
// GLOBAL DAT_00652148 float * * * * * * *
// GLOBAL DAT_0065214c int

/* WARNING: Type propagation algorithm not settling */

undefined4 func_00650A24(int param_1,float *param_2,float *param_3)

{
  int exit_found = 0;   /* PORT: set when the edge loop below accepts an exit edge (see LAB_00651248) */
  uint uVar1;
  float ******ppppppfVar2;
  float *pfVar3;
  undefined4 *puVar4;
  float fVar5;
  int iVar6;
  float fVar7;
  int *piVar8;
  int extraout_r1;
  int extraout_r1_00;
  int extraout_r1_01;
  float *pfVar9;
  uint uVar10;
  float *pfVar11;
  uint *puVar12;
  float *******pppppppfVar13;
  int iVar14;
  bool bVar15;
  bool bVar16;
  float fVar17;
  float *******pppppppfVar18;
  float fVar19;
  float *****pppppfVar20;
  float fVar21;
  float *****pppppfVar22;
  float fVar23;
  float fVar24;
  float *******pppppppfVar25;
  float *******pppppppfVar26;
  float *******pppppppfVar27;
  longlong lVar28;
  ulonglong uVar29;
  longlong lVar30;
  float *******pppppppfVar31;
  float *******pppppppfVar32;
  float *******pppppppfVar33;
  float *******pppppppfVar34;
  float *******pppppppfVar35;
  float *******pppppppfVar36;
  float fVar37;
  _Alignas(8) unsigned char albw_frame[0x430];
  #define local_42c (*(float ******* *)(albw_frame + 0x4))
  #define local_428 (*(float ******* *)(albw_frame + 0x8))
  #define local_424 (*(float ******* *)(albw_frame + 0xc))
  #define local_420 (*(float ******* *)(albw_frame + 0x10))
  #define local_41c (*(float ******* *)(albw_frame + 0x14))
  #define local_418 (*(float ******* *)(albw_frame + 0x18))
  #define pppppppfStack_414 (*(float ******* *)(albw_frame + 0x1c))
  #define local_410 (*(uint *)(albw_frame + 0x20))
  #define iStack_40c (*(int *)(albw_frame + 0x24))
  #define local_408 (*(int *)(albw_frame + 0x28))
  #define local_404 (*(float * *)(albw_frame + 0x2c))
  #define local_1fc ((float ******* *)(albw_frame + 0x234))
  #define local_1f0 (*(float *)(albw_frame + 0x240))
  #define local_1ec (*(float ******* *)(albw_frame + 0x244))
  #define local_1e8 (*(float ****** *)(albw_frame + 0x248))
  #define local_1e4 (*(float ******* *)(albw_frame + 0x24c))
  #define local_1e0 (*(float ******* *)(albw_frame + 0x250))
  #define local_1dc (*(float ****** *)(albw_frame + 0x254))
  #define local_1d8 (*(float ******* *)(albw_frame + 0x258))
  #define local_1d4 (*(float ******* *)(albw_frame + 0x25c))
  #define local_1d0 (*(float ******* *)(albw_frame + 0x260))
  #define local_1cc (*(float ******* *)(albw_frame + 0x264))
  #define local_1c8 (*(float ******* *)(albw_frame + 0x268))
  #define local_1c4 (*(float *)(albw_frame + 0x26c))
  #define local_1c0 (*(float ******* *)(albw_frame + 0x270))
  #define local_1bc (*(float ******* *)(albw_frame + 0x274))
  #define local_1b8 (*(float ******* *)(albw_frame + 0x278))
  #define local_1b4 (*(float *)(albw_frame + 0x27c))
  #define local_1b0 (*(float *)(albw_frame + 0x280))
  #define local_1ac (*(float *)(albw_frame + 0x284))
  #define local_1a8 ((float ****** *)(albw_frame + 0x288))
  #define local_198 (*(float ****** *)(albw_frame + 0x298))
  #define local_194 (*(float ****** *)(albw_frame + 0x29c))
  #define local_190 (*(float ****** *)(albw_frame + 0x2a0))
  #define local_18c (*(float ****** *)(albw_frame + 0x2a4))
  #define local_188 (*(float ****** *)(albw_frame + 0x2a8))
  #define local_184 ((float ****** *)(albw_frame + 0x2ac))
  #define local_174 (*(float ****** *)(albw_frame + 0x2bc))
  #define local_170 (*(float ****** *)(albw_frame + 0x2c0))
  #define local_16c (*(float ****** *)(albw_frame + 0x2c4))
  #define local_168 (*(float ****** *)(albw_frame + 0x2c8))
  #define local_164 (*(float ****** *)(albw_frame + 0x2cc))
  #define local_160 (*(float ***** *)(albw_frame + 0x2d0))
  #define local_15c (*(float *)(albw_frame + 0x2d4))
  #define local_158 (*(float *)(albw_frame + 0x2d8))
  #define local_154 (*(float ******* *)(albw_frame + 0x2dc))
  #define pppppppfStack_150 (*(float ******* *)(albw_frame + 0x2e0))
  #define pppppppfStack_14c (*(float ******* *)(albw_frame + 0x2e4))
  #define local_148 (*(float ******* *)(albw_frame + 0x2e8))
  #define pppppppfStack_144 (*(float ******* *)(albw_frame + 0x2ec))
  #define pppppppfStack_140 (*(float ******* *)(albw_frame + 0x2f0))
  #define local_13c (*(float ******* *)(albw_frame + 0x2f4))
  #define pppppppfStack_138 (*(float ******* *)(albw_frame + 0x2f8))
  #define pppppppfStack_134 (*(float ******* *)(albw_frame + 0x2fc))
  #define local_130 (*(float ***** *)(albw_frame + 0x300))
  #define local_12c (*(float *)(albw_frame + 0x304))
  #define local_128 (*(float *)(albw_frame + 0x308))
  #define local_124 (*(float *)(albw_frame + 0x30c))
  #define local_120 (*(float *)(albw_frame + 0x310))
  #define local_11c (*(float *)(albw_frame + 0x314))
  #define local_118 (*(float ******* *)(albw_frame + 0x318))
  #define local_114 (*(float ******* *)(albw_frame + 0x31c))
  #define local_110 (*(float ******* *)(albw_frame + 0x320))
  #define local_10c (*(float ******* *)(albw_frame + 0x324))
  #define local_108 (*(float *)(albw_frame + 0x328))
  #define local_104 (*(float ****** *)(albw_frame + 0x32c))
  #define local_100 (*(float ******* *)(albw_frame + 0x330))
  #define local_fc (*(float ******* *)(albw_frame + 0x334))
  #define local_f8 (*(float ******* *)(albw_frame + 0x338))
  #define local_f4 (*(float ******* *)(albw_frame + 0x33c))
  #define local_f0 (*(float ******* *)(albw_frame + 0x340))
  #define local_ec (*(float ******* *)(albw_frame + 0x344))
  #define local_e8 (*(float ******* *)(albw_frame + 0x348))
  #define local_e4 (*(float ******* *)(albw_frame + 0x34c))
  #define local_e0 (*(float ******* *)(albw_frame + 0x350))
  #define pppppppfStack_dc (*(float ******* *)(albw_frame + 0x354))
  #define pppppppfStack_d8 (*(float ******* *)(albw_frame + 0x358))
  #define local_d4 (*(float ******* *)(albw_frame + 0x35c))
  #define local_d0 (*(float ******* *)(albw_frame + 0x360))
  #define local_cc (*(float ******* *)(albw_frame + 0x364))
  #define local_c8 (*(float ******* *)(albw_frame + 0x368))
  #define pppppppfStack_c4 (*(float ******* *)(albw_frame + 0x36c))
  #define pppppppfStack_c0 (*(float ******* *)(albw_frame + 0x370))
  #define local_b8 ((float ******* *)(albw_frame + 0x378))
  #define local_a8 (*(float *)(albw_frame + 0x388))
  #define local_a4 (*(float *)(albw_frame + 0x38c))
  #define local_a0 (*(float *)(albw_frame + 0x390))
  #define afStack_98 ((float *)(albw_frame + 0x398))
  #define local_88 (*(float *)(albw_frame + 0x3a8))
  #define local_84 (*(float ******* *)(albw_frame + 0x3ac))
  #define local_80 (*(float *)(albw_frame + 0x3b0))
  #define local_7c ((float *)(albw_frame + 0x3b4))
  #define local_30 (*(int *)(albw_frame + 0x400))
  #define pfStack_2c (*(float * *)(albw_frame + 0x404))
  #define pfStack_28 (*(float * *)(albw_frame + 0x408))
  if (param_2 != (float *)0x0) {
    param_2[10] = ALBW_AS_F32(((int)ALBW_AS_U32(param_2[10]) + 1));
  }
  pfVar11 = (float *)0x0;
  local_1bc = (float *******)DAT_00650e14[1];
  local_1c0 = (float *******)*DAT_00650e14;
  local_1b8 = (float *******)DAT_00650e14[2];
  local_1b0 = DAT_00650e18[1];
  local_1b4 = *DAT_00650e18;
  local_1ac = DAT_00650e18[2];
  local_130 = (float *****)CF_FBITS(param_3[1]);
  local_12c = param_3[2];
  local_128 = param_3[3];
  local_124 = param_3[4];
  local_120 = param_3[5];
  local_11c = param_3[6];
  fVar5 = DAT_00650e1c;
  local_30 = param_1;
  pfStack_2c = param_2;
  pfStack_28 = param_3;
  func_00688AB0(&local_410);
  fVar37 = DAT_00650e20;
  func_00115D70((float *)&local_424,param_3 + 7,DAT_00650e20);
  local_148 = local_424;
  pppppppfStack_144 = local_420;
  pppppppfStack_140 = local_41c;
  func_00115C54((float *)&local_424,param_3 + 1,(float *)&local_148);
  local_154 = local_424;
  pppppppfStack_150 = local_420;
  pppppppfStack_14c = local_41c;
  func_00115D70((float *)&local_428,(float *)(local_30 + 0x54),fVar37);
  local_13c = local_428;
  pppppppfStack_138 = local_424;
  pppppppfStack_134 = local_420;
  func_00115C54((float *)&local_42c,(float *)&local_154,(float *)&local_13c);
  iVar14 = DAT_00650e34;
  lVar28 = CONCAT44(DAT_00650e28,DAT_00650e24);
  local_1c0 = local_42c;
  local_1bc = local_428;
  local_1b8 = local_424;
  local_1b4 = param_3[4];
  local_1b0 = param_3[5];
  uVar10 = 0;
  local_1ac = param_3[6];
  fVar24 = param_3[0xb];
  puVar12 = *(uint **)(local_30 + 4);
  uVar1 = *puVar12;
  pppppppfVar34 = DAT_00650e2c;
  pppppppfVar35 = DAT_00650e30;
  if (0 < (int)uVar1) {
    uVar29 = (ulonglong)DAT_00650e28;
    fVar7 = DAT_00650e24;
    do {
      if (uVar10 < uVar1) {
        iVar6 = *(int *)(puVar12[2] + uVar10 * 4);
      }
      else {
        iVar6 = 0;
      }
      if ((1 << (*(uint *)(iVar6 + 4) & 0xff) & 5U) != 0) {
        if (uVar10 < uVar1) {
          iVar6 = *(int *)(puVar12[2] + uVar10 * 4);
        }
        else {
          iVar6 = 0;
        }
        fVar17 = *(float *)(iVar6 + 0x30);
        fVar19 = *(float *)(iVar6 + 0x34);
        fVar21 = *(float *)(iVar6 + 0x38);
        fVar23 = local_1b4 * fVar17 + local_1b0 * fVar19 + local_1ac * fVar21;
        if ((fVar23 <= ALBW_AS_F32(pppppppfVar35)) && (iVar14 <= (int)ALBW_AS_U32(-fVar23))) {
          local_424 = (float *******)(iVar6 + 0x24);
          fVar23 = local_1b4 * fVar17 + local_1b0 * fVar19 + local_1ac * fVar21;
          if (((fVar23 < ALBW_AS_F32(uVar29)) || (fVar7 < fVar23)) &&
             ((pppppppfVar32 =
                    (float *******)
                    CF_FBITS((((fVar17 * ALBW_AS_F32(*local_424) + fVar19 * *(float *)(iVar6 + 0x28) +
                      fVar21 * *(float *)(iVar6 + 0x2c)) -
                     (fVar17 * ALBW_AS_F32(local_1c0) + fVar19 * ALBW_AS_F32(local_1bc) +
                     fVar21 * ALBW_AS_F32(local_1b8))) / fVar23)),
              (int)ALBW_AS_U32((ALBW_AS_F32(pppppppfVar32) - fVar24)) <= iVar14 &&
              (ALBW_AS_F32(pppppppfVar35) <= ALBW_AS_F32(pppppppfVar32))))) {
            local_1fc[2] = (float *******)&local_1c0;
            func_00115D70((float *)&local_1e4,&local_1b4,ALBW_AS_F32(pppppppfVar32));
            local_1f0 = ALBW_AS_F32(local_1e4);
            local_1ec = local_1e0;
            local_1e8 = local_1dc;
            func_00115C54((float *)&local_1d8,(float *)local_1fc[2],&local_1f0);
            local_420 = local_1d8;
            local_41c = local_1d4;
            local_418 = local_1d0;
            func_00115C70((float *)&local_1cc,(float *)&local_420,(float *)local_424);
            if (((int)ALBW_AS_U32((ALBW_AS_F32(local_1cc) * *(float *)(iVar6 + 0x3c) +
                       ALBW_AS_F32(local_1c8) * *(float *)(iVar6 + 0x40) +
                      local_1c4 * *(float *)(iVar6 + 0x44))) <= iVar14) &&
               ((((int)ALBW_AS_U32((ALBW_AS_F32(local_1cc) * *(float *)(iVar6 + 0x48) +
                        ALBW_AS_F32(local_1c8) * *(float *)(iVar6 + 0x4c) +
                       local_1c4 * *(float *)(iVar6 + 0x50))) <= iVar14 &&
                 (ALBW_AS_F32(local_1cc) * *(float *)(iVar6 + 0x54) +
                  ALBW_AS_F32(local_1c8) * *(float *)(iVar6 + 0x58) + local_1c4 * *(float *)(iVar6 + 0x5c)
                  <= *(float *)(iVar6 + 0x68) + fVar7)) &&
                (pppppppfVar32 != (float *******)0xff7fffff)))) {
              if ((uVar10 < *puVar12) && (local_1f0 = 0.0, *(int *)(puVar12[2] + uVar10 * 4) != 0))
              {
                func_00115D70((float *)&local_41c,&local_124,ALBW_AS_F32(pppppppfVar32));
                local_428 = local_41c;
                local_424 = local_418;
                local_420 = pppppppfStack_414;
                func_00115C54((float *)&local_160,(float *)&local_130,(float *)&local_428);
                local_1f0 = 1.4013e-45;
                goto LAB_00650ddc;
              }
              break;
            }
          }
        }
      }
      uVar1 = *puVar12;
      uVar10 = uVar10 + 1;
    } while ((int)uVar10 < (int)uVar1);
  }
  iVar14 = 0;
  local_1f0 = 0.0;
  fVar24 = fVar37;
  func_00115D70((float *)&local_424,param_3 + 7,fVar37);
  local_114 = local_424;
  local_110 = local_420;
  local_10c = local_41c;
  func_00115C54((float *)&local_424,param_3 + 1,(float *)&local_114);
  local_1c0 = local_424;
  local_1bc = local_420;
  local_1b8 = local_41c;
  local_1b4 = param_3[4];
  local_1b0 = param_3[5];
  local_1ac = param_3[6];
  fVar7 = *param_3;
  pppppppfVar32 = (float *******)CF_FBITS(param_3[0xb]);
  local_420 = (float *******)0x1;
  local_428 = (float *******)((int)ALBW_AS_U32(fVar7) + 0x24);
  fVar19 = *(float *)((int)ALBW_AS_U32(fVar7) + 0x30);
  fVar21 = *(float *)((int)ALBW_AS_U32(fVar7) + 0x34);
  fVar23 = *(float *)((int)ALBW_AS_U32(fVar7) + 0x38);
  fVar17 = local_124 * fVar19 + local_120 * fVar21 + local_11c * fVar23;
  local_104 = &local_130;
  if ((fVar17 < DAT_00651214) || (fVar24 < fVar17)) {
    pppppppfVar13 =
         (float *******)
         CF_FBITS((((fVar19 * ALBW_AS_F32(*local_428) + fVar21 * *(float *)((int)ALBW_AS_U32(fVar7) + 0x28) +
           fVar23 * *(float *)((int)ALBW_AS_U32(fVar7) + 0x2c)) -
          (fVar19 * ALBW_AS_F32(local_130) + fVar21 * local_12c + fVar23 * local_128)) / fVar17));
    pppppppfVar18 = (float *******)CF_FBITS((ALBW_AS_F32(pppppppfVar13) - ALBW_AS_F32(pppppppfVar32)));
    if ((ALBW_AS_F32(pppppppfVar18) <= fVar24) && (DAT_00651214 <= ALBW_AS_F32(pppppppfVar13))) {
      func_00115D70((float *)&local_1d0,&local_124,ALBW_AS_F32(pppppppfVar13));
      local_100 = local_1d0;
      local_fc = local_1cc;
      local_f8 = local_1c8;
      func_00115C54((float *)&local_1d0,(float *)&local_130,(float *)&local_100);
      local_1fc[0] = local_1d0;
      local_1fc[1] = local_1cc;
      local_1fc[2] = local_1c8;
      func_00115C70((float *)&local_1d0,(float *)local_1fc,(float *)local_428);
      pppppppfVar18 = local_1d0;
      if (((ALBW_AS_F32(local_1d0) * *(float *)((int)ALBW_AS_U32(fVar7) + 0x3c) +
            ALBW_AS_F32(local_1cc) * *(float *)((int)ALBW_AS_U32(fVar7) + 0x40) +
            ALBW_AS_F32(local_1c8) * *(float *)((int)ALBW_AS_U32(fVar7) + 0x44) <= fVar24) &&
          (ALBW_AS_F32(local_1d0) * *(float *)((int)ALBW_AS_U32(fVar7) + 0x48) +
           ALBW_AS_F32(local_1cc) * *(float *)((int)ALBW_AS_U32(fVar7) + 0x4c) +
           ALBW_AS_F32(local_1c8) * *(float *)((int)ALBW_AS_U32(fVar7) + 0x50) <= fVar24)) &&
         (pppppppfVar18 =
               (float *******)
               CF_FBITS((ALBW_AS_F32(local_1d0) * *(float *)((int)ALBW_AS_U32(fVar7) + 0x54) +
                ALBW_AS_F32(local_1cc) * *(float *)((int)ALBW_AS_U32(fVar7) + 0x58) +
               ALBW_AS_F32(local_1c8) * *(float *)((int)ALBW_AS_U32(fVar7) + 0x5c))),
         ALBW_AS_F32(pppppppfVar18) <= *(float *)((int)ALBW_AS_U32(fVar7) + 0x68) + fVar24)) goto LAB_00651248;
    }
LAB_00651244:
    pppppppfVar13 = pppppppfVar34;
  }
  else {
    func_00115C70((float *)&local_1cc,(float *)&local_130,(float *)local_428);
    pppppppfVar18 =
         (float *******)
         CF_FBITS((ALBW_AS_F32(local_1cc) * *(float *)((int)ALBW_AS_U32(fVar7) + 0x30) +
          ALBW_AS_F32(local_1c8) * *(float *)((int)ALBW_AS_U32(fVar7) + 0x34) +
         local_1c4 * *(float *)((int)ALBW_AS_U32(fVar7) + 0x38)));
    if (fVar24 < ALBW_AS_F32(pppppppfVar18)) goto LAB_00651244;
    fVar19 = -fVar24;
    local_1fc[0] = (float *******)((int)ALBW_AS_U32(fVar7) + 0x3c);
    local_1fc[1] = (float *******)((int)ALBW_AS_U32(fVar7) + 0x48);
    local_1fc[2] = (float *******)((int)ALBW_AS_U32(fVar7) + 0x54);
    iVar6 = 0;
    fVar17 = local_1c4;
    pppppppfVar13 = pppppppfVar35;
    pppppppfVar33 = local_1c8;
    pppppppfVar36 = local_1cc;
    do {
      ppppppfVar2 = (float ******)local_1fc[iVar6];
      pppppfVar22 = ppppppfVar2[1];
      pppppfVar20 = ppppppfVar2[2];
      pppppppfVar18 =
           (float *******)
           CF_FBITS((local_124 * ALBW_AS_F32(*ppppppfVar2) + local_120 * ALBW_AS_F32(pppppfVar22) +
           local_11c * ALBW_AS_F32(pppppfVar20)));
      bVar16 = fVar19 == ALBW_AS_F32(pppppppfVar18);
      bVar15 = ALBW_AS_F32(pppppppfVar18) <= fVar19;
      if (!bVar15 || bVar16) {
        bVar16 = ALBW_AS_F32(pppppppfVar18) == fVar24;
        bVar15 = fVar24 <= ALBW_AS_F32(pppppppfVar18);
      }
      if (bVar15 && !bVar16) {
        fVar21 = ALBW_AS_F32(*ppppppfVar2) * ALBW_AS_F32(pppppppfVar36);
        if (iVar6 == 2) {
          fVar21 = *(float *)((int)ALBW_AS_U32(fVar7) + 0x68) -
                   (fVar21 + ALBW_AS_F32(pppppfVar22) * ALBW_AS_F32(pppppppfVar33) + ALBW_AS_F32(pppppfVar20) * fVar17
                   );
        }
        else {
          fVar21 = -(fVar21 + ALBW_AS_F32(pppppfVar22) * ALBW_AS_F32(pppppppfVar33) +
                    ALBW_AS_F32(pppppfVar20) * fVar17);
        }
        pppppppfVar26 = (float *******)CF_FBITS((fVar21 / ALBW_AS_F32(pppppppfVar18)));
        /* PORT (160bi): a start point a hair outside this edge (distance -0.001 .. 0) is ON the edge */
        if (ALBW_AS_F32(pppppppfVar26) < 0.0f && -ALBW_AS_F32(pppppppfVar26) < ALBW_AS_F32(DAT_00650e34))
          pppppppfVar26 = (float *******)0;
        if (ALBW_AS_F32(pppppppfVar35) <= ALBW_AS_F32(pppppppfVar26) &&
            ALBW_AS_F32(pppppppfVar13) <= ALBW_AS_F32(pppppppfVar26)) {
          bVar16 = ALBW_AS_F32(pppppppfVar32) <= ALBW_AS_F32(pppppppfVar26);
          pppppppfVar25 = pppppppfVar32;
          if (!bVar16) {
            pppppppfVar25 = pppppppfVar26;
          }
          func_00115D70((float *)&local_d4,&local_124,ALBW_AS_F32(pppppppfVar25));
          local_f4 = local_d4;
          local_f0 = local_d0;
          local_ec = local_cc;
          func_00115C54((float *)&local_e0,(float *)local_104,(float *)&local_f4);
          local_100 = local_e0;
          local_fc = pppppppfStack_dc;
          local_f8 = pppppppfStack_d8;
          func_00115C70((float *)&local_1dc,(float *)&local_100,(float *)local_428);
          pppppppfVar18 = local_1d8;
          if (((ALBW_AS_F32(local_1dc) * ALBW_AS_F32(*local_1fc[0]) + ALBW_AS_F32(local_1d8) * ALBW_AS_F32(local_1fc[0][1])
                + ALBW_AS_F32(local_1d4) * ALBW_AS_F32(local_1fc[0][2]) <= fVar24) &&
              (ALBW_AS_F32(local_1dc) * ALBW_AS_F32(*local_1fc[1]) + ALBW_AS_F32(local_1d8) * ALBW_AS_F32(local_1fc[1][1]) +
               ALBW_AS_F32(local_1d4) * ALBW_AS_F32(local_1fc[1][2]) <= fVar24)) &&
             ((ALBW_AS_F32(local_1dc) * ALBW_AS_F32(*local_1fc[2]) + ALBW_AS_F32(local_1d8) * ALBW_AS_F32(local_1fc[2][1]) +
               ALBW_AS_F32(local_1d4) * ALBW_AS_F32(local_1fc[2][2]) <= *(float *)((int)ALBW_AS_U32(fVar7) + 0x68) + fVar24
              && (pppppppfVar13 = pppppppfVar25, exit_found = 1, bVar16)))) break;
        }
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < 3);
    if (ALBW_AS_F32(pppppppfVar13) == ALBW_AS_F32(pppppppfVar35) && !exit_found) goto LAB_00651244;
  }
LAB_00651248:
  /* PORT (160bi): the start point lies ON the exit edge (distance 0 .. 0.001). The walker clamps a
   * step to end exactly at a triangle edge, and from there the "how much wall is above" ray leaves
   * the triangle at once; with distance < 0.001 the code below reports "no wall" and merged Link
   * stops for good (slot 1: an edge between two triangles of one flat cliff face). Count such an
   * exit as crossing the edge at 0.001, so the ray carries on into the neighbouring triangle as it
   * does from any other point. Only the edge loop's own exits are affected (exit_found). */
  if (exit_found && (int)pppppppfVar13 >= 0 && (int)pppppppfVar13 < DAT_00650e34)
    pppppppfVar13 = (float *******)(uintptr_t)(uint)DAT_00650e34;
  if ((pppppppfVar13 == (float *******)0xff7fffff) || ((int)pppppppfVar13 < DAT_00650e34)) {
    local_420 = (float *******)0x0;
    pppppppfVar13 = pppppppfVar35;
  }
  lVar30 = lVar28;
  pppppppfVar33 = pppppppfVar13;
  if (*(char *)(local_30 + 0x3dc2) == '\0') {
    iVar14 = func_001EA738(local_30,(int *)&local_1e4,(int)ALBW_AS_U32(param_3[0xc]),(float *)&local_1c0,
                           ALBW_AS_F32(pppppppfVar13));
    pppppppfVar18 = pppppppfVar13;
    lVar30 = lVar28;
  }
  iVar6 = DAT_00650e34;
  if (local_420 == (float *******)0x0 && iVar14 == 0) {
    if ((param_2 == (float *)0x0) || (param_2[10] != 1.4013e-45)) {
      return 3;
    }
    local_160 = local_130;
    local_15c = local_12c;
    local_158 = local_128;
    pppppppfVar32 = pppppppfVar35;
  }
  else {
    bVar16 = iVar14 < 0;
    bVar15 = iVar14 != 0;
    if (bVar15) {
      bVar16 = ALBW_AS_F32(pppppppfVar33) < ALBW_AS_F32(local_1e4);
      pppppppfVar18 = local_1e4;
    }
    pppppppfVar32 = pppppppfVar33;
    if (((((bVar15 && ALBW_AS_F32(pppppppfVar33) != ALBW_AS_F32(local_1e4)) &&
           bVar16 == (bVar15 && (NAN(ALBW_AS_F32(pppppppfVar33)) || NAN(ALBW_AS_F32(local_1e4))))) &&
         (pppppppfVar32 = pppppppfVar18, local_420 != (float *******)0x0)) &&
        (ALBW_AS_F32(pppppppfVar18) == ALBW_AS_F32(pppppppfVar35))) && (1 < (int)ALBW_AS_U32(param_2[10]))) {
      pppppppfVar32 = pppppppfVar33;
      local_1e4 = pppppppfVar33;
    }
    uVar10 = 0;
    puVar12 = *(uint **)(local_30 + 4);
    uVar1 = *puVar12;
    lVar28 = lVar30;
    pppppppfVar18 = pppppppfVar32;
    if (0 < (int)uVar1) {
      do {
        if (uVar10 < uVar1) {
          iVar14 = *(int *)(puVar12[2] + uVar10 * 4);
        }
        else {
          iVar14 = 0;
        }
        if ((1 << (*(uint *)(iVar14 + 4) & 0xff) & 5U) != 0) {
          if (uVar10 < uVar1) {
            iVar14 = *(int *)(puVar12[2] + uVar10 * 4);
          }
          else {
            iVar14 = 0;
          }
          fVar17 = *(float *)(iVar14 + 0x30);
          fVar24 = *(float *)(iVar14 + 0x34);
          fVar7 = *(float *)(iVar14 + 0x38);
          fVar19 = local_1b4 * fVar17 + local_1b0 * fVar24 + local_1ac * fVar7;
          if ((fVar19 <= ALBW_AS_F32(pppppppfVar35)) && (iVar6 <= (int)ALBW_AS_U32(-fVar19))) {
            local_41c = (float *******)(iVar14 + 0x24);
            fVar19 = local_1b4 * fVar17 + local_1b0 * fVar24 + local_1ac * fVar7;
            if (((fVar19 < ALBW_AS_F32(((ulonglong)lVar30 >> 0x20))) || (ALBW_AS_F32(lVar30) < fVar19)) &&
               ((pppppppfVar13 =
                      (float *******)
                      CF_FBITS((((fVar17 * ALBW_AS_F32(*local_41c) + fVar24 * *(float *)(iVar14 + 0x28) +
                        fVar7 * *(float *)(iVar14 + 0x2c)) -
                       (fVar17 * ALBW_AS_F32(local_1c0) + fVar24 * ALBW_AS_F32(local_1bc) +
                       fVar7 * ALBW_AS_F32(local_1b8))) / fVar19)),
                (int)ALBW_AS_U32((ALBW_AS_F32(pppppppfVar13) - ALBW_AS_F32(pppppppfVar18))) <= iVar6 &&
                (ALBW_AS_F32(pppppppfVar35) <= ALBW_AS_F32(pppppppfVar13))))) {
              local_418 = (float *******)&local_1c0;
              func_00115D70((float *)&local_104,&local_1b4,ALBW_AS_F32(pppppppfVar13));
              local_1dc = local_104;
              local_1d8 = local_100;
              local_1d4 = local_fc;
              func_00115C54((float *)&local_f8,(float *)local_418,(float *)&local_1dc);
              local_1fc[0] = local_f8;
              local_1fc[1] = local_f4;
              local_1fc[2] = local_f0;
              func_00115C70((float *)&local_ec,(float *)local_1fc,(float *)local_41c);
              if (((int)ALBW_AS_U32((ALBW_AS_F32(local_ec) * *(float *)(iVar14 + 0x3c) +
                         ALBW_AS_F32(local_e8) * *(float *)(iVar14 + 0x40) +
                        ALBW_AS_F32(local_e4) * *(float *)(iVar14 + 0x44))) <= iVar6) &&
                 ((((int)ALBW_AS_U32((ALBW_AS_F32(local_ec) * *(float *)(iVar14 + 0x48) +
                          ALBW_AS_F32(local_e8) * *(float *)(iVar14 + 0x4c) +
                         ALBW_AS_F32(local_e4) * *(float *)(iVar14 + 0x50))) <= iVar6 &&
                   (ALBW_AS_F32(local_ec) * *(float *)(iVar14 + 0x54) +
                    ALBW_AS_F32(local_e8) * *(float *)(iVar14 + 0x58) +
                    ALBW_AS_F32(local_e4) * *(float *)(iVar14 + 0x5c) <=
                    *(float *)(iVar14 + 0x68) + ALBW_AS_F32(lVar30))) &&
                  (pppppppfVar13 != (float *******)0xff7fffff)))) {
                local_1e4 = pppppppfVar13;
                if ((uVar10 < *puVar12) && (*(int *)(puVar12[2] + uVar10 * 4) != 0)) {
                  local_1f0 = 1.4013e-45;
                  pppppppfVar32 = pppppppfVar13;
                }
                break;
              }
            }
          }
        }
        uVar1 = *puVar12;
        uVar10 = uVar10 + 1;
      } while ((int)uVar10 < (int)uVar1);
    }
    func_00115D70((float *)&local_428,&local_124,ALBW_AS_F32(pppppppfVar32));
    local_114 = local_428;
    local_110 = local_424;
    local_10c = local_420;
    func_00115C54((float *)&local_160,(float *)&local_130,(float *)&local_114);
LAB_00650ddc:
    pppppppfVar18 = (float *******)CF_FBITS((ALBW_AS_F32(pppppppfVar32) - param_3[0xb]));
    bVar16 = DAT_00650e3c == ALBW_AS_F32(pppppppfVar18);
    bVar15 = ALBW_AS_F32(pppppppfVar18) <= DAT_00650e3c;
    if (!bVar15 || bVar16) {
      bVar16 = ALBW_AS_F32(pppppppfVar18) == DAT_00650e38;
      bVar15 = DAT_00650e38 <= ALBW_AS_F32(pppppppfVar18);
    }
    if (((uint)ALBW_AS_U32(local_1f0) & ~(uint)(!bVar15 || bVar16)) != 0) goto LAB_00652290;
    lVar30 = lVar28;
    if ((!bVar15 || bVar16) != 0) {
      param_2[4] = param_3[4];
      param_2[5] = param_3[5];
      param_2[6] = param_3[6];
      param_2[1] = ALBW_AS_F32(local_160);
      param_2[2] = local_15c;
      param_2[3] = local_158;
      *param_2 = ALBW_AS_F32(pppppppfVar35);
      param_2[8] = *param_3;
      return 0;
    }
  }
  fVar24 = param_3[0xc];
  func_0010F1F8((int *)((int)ALBW_AS_U32(*param_3) + *(int *)((int)ALBW_AS_U32(fVar24) + 0xc)),ALBW_AS_F32(pppppppfVar18));
  *(int *)((int)ALBW_AS_U32(fVar24) + 8) = *(int *)((int)ALBW_AS_U32(fVar24) + 8) + -1;
  pppppppfVar18 = (float *******)CF_FBITS(param_3[0xb]);
  pppppppfVar33 = (float *******)CF_FBITS((ALBW_AS_F32(pppppppfVar18) - ALBW_AS_F32(pppppppfVar32)));
  local_1e0 = (float *******)((int)ALBW_AS_U32(param_3[0xc]) - *(int *)((int)ALBW_AS_U32(param_3[0xc]) + 0xc));
  iVar14 = *(int *)((int)ALBW_AS_U32(param_3[0xc]) + 0xc);
  pppppppfVar13 = (float *******)(*(int *)((int)ALBW_AS_U32(param_3[0xc]) + 4) - iVar14);
  if (pppppppfVar13 != local_1e0) {
    lVar28 = ZEXT48(pppppppfVar35) << 0x20;
    do {
      pppppppfVar18 = (float *******)pppppppfVar13[0xd];
      fVar24 = fVar37;
      if ((((uint)ALBW_AS_U32((ALBW_AS_F32(pppppppfVar13[0xc]) * param_3[7] + ALBW_AS_F32(pppppppfVar13[0xd]) * param_3[8] +
                  ALBW_AS_F32(pppppppfVar13[0xe]) * param_3[9])) <= (uint)ALBW_AS_U32(DAT_00651acc)) &&
          (func_00115C70(&local_88,(float *)&local_160,(float *)(pppppppfVar13 + 9)),
          pppppppfVar18 = local_84,
          local_88 * ALBW_AS_F32(pppppppfVar13[0xf]) + ALBW_AS_F32(local_84) * ALBW_AS_F32(pppppppfVar13[0x10]) +
          local_80 * ALBW_AS_F32(pppppppfVar13[0x11]) <= fVar37)) &&
         ((local_88 * ALBW_AS_F32(pppppppfVar13[0x12]) + ALBW_AS_F32(local_84) * ALBW_AS_F32(pppppppfVar13[0x13]) +
           local_80 * ALBW_AS_F32(pppppppfVar13[0x14]) <= fVar37 &&
          (local_88 * ALBW_AS_F32(pppppppfVar13[0x15]) + ALBW_AS_F32(local_84) * ALBW_AS_F32(pppppppfVar13[0x16]) +
           local_80 * ALBW_AS_F32(pppppppfVar13[0x17]) <= ALBW_AS_F32(pppppppfVar13[0x1a]) + fVar37)))) {
        pppppppfVar36 =
             (float *******)
             CF_FBITS(-(local_88 * ALBW_AS_F32(pppppppfVar13[0xc]) + ALBW_AS_F32(local_84) * ALBW_AS_F32(pppppppfVar13[0xd]) +
              local_80 * ALBW_AS_F32(pppppppfVar13[0xe])));
        if ((ALBW_AS_F32(pppppppfVar36) < DAT_00651ad0) || (fVar37 < ALBW_AS_F32(pppppppfVar36))) {
          pppppppfVar36 = pppppppfVar34;
        }
        if (pppppppfVar36 != (float *******)0xff7fffff) {
          pppppppfVar18 = (float *******)CF_FBITS(param_3[6]);
          fVar37 = ALBW_AS_F32(pppppppfVar13[0xc]) * param_3[4] + ALBW_AS_F32(pppppppfVar13[0xd]) * param_3[5] +
                   ALBW_AS_F32(pppppppfVar13[0xe]) * ALBW_AS_F32(pppppppfVar18);
          if (pfVar11 == (float *)0x0) {
            func_00115E10((float *)&local_1d0,DAT_00651ad4,param_3 + 7);
            pfVar11 = local_7c;
            func_00115E10(pfVar11,(float *)&local_1d0,DAT_00651ad4);
          }
          fVar7 = ALBW_AS_F32(((ulonglong)lVar28 >> 0x20));
          if ((uint)ALBW_AS_U32(DAT_00651ad8) < (uint)ALBW_AS_U32(fVar37)) {
            local_1a8[0] = pppppppfVar13[9];
            local_1a8[1] = pppppppfVar13[10];
            local_1a8[2] = pppppppfVar13[0xb];
            pppppppfVar18 = pppppppfVar13 + 9;
            fVar17 = ALBW_AS_F32(pppppppfVar13[0xe]) * ALBW_AS_F32(pppppppfVar13[0x10]) -
                     ALBW_AS_F32(pppppppfVar13[0xd]) * ALBW_AS_F32(pppppppfVar13[0x11]);
            fVar19 = ALBW_AS_F32(pppppppfVar13[0xc]) * ALBW_AS_F32(pppppppfVar13[0x11]) -
                     ALBW_AS_F32(pppppppfVar13[0xe]) * ALBW_AS_F32(pppppppfVar13[0xf]);
            fVar21 = ALBW_AS_F32(pppppppfVar13[0xd]) * ALBW_AS_F32(pppppppfVar13[0xf]) -
                     ALBW_AS_F32(pppppppfVar13[0xc]) * ALBW_AS_F32(pppppppfVar13[0x10]);
            fVar23 = fVar17 * ALBW_AS_F32(pppppppfVar13[0x15]) + fVar19 * ALBW_AS_F32(pppppppfVar13[0x16]) +
                     fVar21 * ALBW_AS_F32(pppppppfVar13[0x17]);
            if (fVar23 <= fVar7) {
              local_1a8[3] = *pppppppfVar18;
              local_198 = pppppppfVar13[10];
              local_194 = pppppppfVar13[0xb];
            }
            else {
              fVar23 = ALBW_AS_F32(pppppppfVar13[0x1a]) / fVar23;
              local_1a8[3] = (float ******)CF_FBITS((ALBW_AS_F32(*pppppppfVar18) + fVar17 * fVar23));
              local_198 = (float ******)CF_FBITS((ALBW_AS_F32(pppppppfVar13[10]) + fVar19 * fVar23));
              local_194 = (float ******)CF_FBITS((ALBW_AS_F32(pppppppfVar13[0xb]) + fVar21 * fVar23));
            }
            fVar19 = ALBW_AS_F32(pppppppfVar13[0x14]) * ALBW_AS_F32(pppppppfVar13[0xd]) -
                     ALBW_AS_F32(pppppppfVar13[0x13]) * ALBW_AS_F32(pppppppfVar13[0xe]);
            fVar21 = ALBW_AS_F32(pppppppfVar13[0x12]) * ALBW_AS_F32(pppppppfVar13[0xe]) -
                     ALBW_AS_F32(pppppppfVar13[0x14]) * ALBW_AS_F32(pppppppfVar13[0xc]);
            fVar23 = ALBW_AS_F32(pppppppfVar13[0x13]) * ALBW_AS_F32(pppppppfVar13[0xc]) -
                     ALBW_AS_F32(pppppppfVar13[0x12]) * ALBW_AS_F32(pppppppfVar13[0xd]);
            fVar17 = fVar19 * ALBW_AS_F32(pppppppfVar13[0x15]) + fVar21 * ALBW_AS_F32(pppppppfVar13[0x16]) +
                     fVar23 * ALBW_AS_F32(pppppppfVar13[0x17]);
            if (fVar17 <= fVar7) {
              local_190 = *pppppppfVar18;
              local_18c = pppppppfVar13[10];
              local_188 = pppppppfVar13[0xb];
            }
            else {
              fVar17 = ALBW_AS_F32(pppppppfVar13[0x1a]) / fVar17;
              local_190 = (float ******)CF_FBITS((ALBW_AS_F32(*pppppppfVar18) + fVar19 * fVar17));
              local_18c = (float ******)CF_FBITS((ALBW_AS_F32(pppppppfVar13[10]) + fVar21 * fVar17));
              local_188 = (float ******)CF_FBITS((ALBW_AS_F32(pppppppfVar13[0xb]) + fVar23 * fVar17));
            }
            func_00115C70((float *)&local_1dc,(float *)local_1a8,param_3 + 1);
            iVar6 = 0;
            pppppppfVar26 =
                 (float *******)
                 CF_FBITS((*pfVar11 * ALBW_AS_F32(local_1dc) + pfVar11[1] * ALBW_AS_F32(local_1d8) +
                 pfVar11[2] * ALBW_AS_F32(local_1d4)));
            pppppppfVar25 = pppppppfVar26;
            do {
              pppppppfVar18 = pppppppfVar25;
              pppppppfVar25 = pppppppfVar18;
              if (iVar6 != 2) {
                func_00115C70((float *)&local_1dc,(float *)(local_1a8 + (iVar6 + 1) * 3),param_3 + 1
                             );
                pppppppfVar18 =
                     (float *******)
                     CF_FBITS((*pfVar11 * ALBW_AS_F32(local_1dc) + pfVar11[1] * ALBW_AS_F32(local_1d8) +
                     pfVar11[2] * ALBW_AS_F32(local_1d4)));
              }
              fVar7 = ALBW_AS_F32(((ulonglong)lVar28 >> 0x20));
              bVar16 = ALBW_AS_F32(pppppppfVar26) == fVar7;
              bVar15 = fVar7 <= ALBW_AS_F32(pppppppfVar26);
              if (!bVar15 || bVar16) {
                bVar16 = ALBW_AS_F32(pppppppfVar18) == fVar7;
                bVar15 = fVar7 <= ALBW_AS_F32(pppppppfVar18);
              }
              if (bVar15 && !bVar16) goto LAB_00651c1c;
              iVar6 = iVar6 + 1;
              pppppppfVar26 = pppppppfVar18;
            } while (iVar6 < 3);
          }
          else if (DAT_00650e34 < (int)ALBW_AS_U32(fVar37)) {
            func_00115D70((float *)(local_1fc + 2),pfVar11,fVar5);
            local_184[0] = pppppppfVar13[9];
            local_184[1] = pppppppfVar13[10];
            local_184[2] = pppppppfVar13[0xb];
            pppppppfVar18 = pppppppfVar13 + 9;
            fVar17 = ALBW_AS_F32(pppppppfVar13[0xe]) * ALBW_AS_F32(pppppppfVar13[0x10]) -
                     ALBW_AS_F32(pppppppfVar13[0xd]) * ALBW_AS_F32(pppppppfVar13[0x11]);
            fVar19 = ALBW_AS_F32(pppppppfVar13[0xc]) * ALBW_AS_F32(pppppppfVar13[0x11]) -
                     ALBW_AS_F32(pppppppfVar13[0xe]) * ALBW_AS_F32(pppppppfVar13[0xf]);
            fVar21 = ALBW_AS_F32(pppppppfVar13[0xd]) * ALBW_AS_F32(pppppppfVar13[0xf]) -
                     ALBW_AS_F32(pppppppfVar13[0xc]) * ALBW_AS_F32(pppppppfVar13[0x10]);
            fVar23 = fVar17 * ALBW_AS_F32(pppppppfVar13[0x15]) + fVar19 * ALBW_AS_F32(pppppppfVar13[0x16]) +
                     fVar21 * ALBW_AS_F32(pppppppfVar13[0x17]);
            if (fVar23 <= fVar7) {
              local_184[3] = *pppppppfVar18;
              local_174 = pppppppfVar13[10];
              local_170 = pppppppfVar13[0xb];
            }
            else {
              fVar23 = ALBW_AS_F32(pppppppfVar13[0x1a]) / fVar23;
              local_184[3] = (float ******)CF_FBITS((ALBW_AS_F32(*pppppppfVar18) + fVar17 * fVar23));
              local_174 = (float ******)CF_FBITS((ALBW_AS_F32(pppppppfVar13[10]) + fVar19 * fVar23));
              local_170 = (float ******)CF_FBITS((ALBW_AS_F32(pppppppfVar13[0xb]) + fVar21 * fVar23));
            }
            fVar17 = ALBW_AS_F32(pppppppfVar13[0x14]) * ALBW_AS_F32(pppppppfVar13[0xd]) -
                     ALBW_AS_F32(pppppppfVar13[0x13]) * ALBW_AS_F32(pppppppfVar13[0xe]);
            fVar19 = ALBW_AS_F32(pppppppfVar13[0x12]) * ALBW_AS_F32(pppppppfVar13[0xe]) -
                     ALBW_AS_F32(pppppppfVar13[0x14]) * ALBW_AS_F32(pppppppfVar13[0xc]);
            fVar21 = ALBW_AS_F32(pppppppfVar13[0x13]) * ALBW_AS_F32(pppppppfVar13[0xc]) -
                     ALBW_AS_F32(pppppppfVar13[0x12]) * ALBW_AS_F32(pppppppfVar13[0xd]);
            fVar23 = fVar17 * ALBW_AS_F32(pppppppfVar13[0x15]) + fVar19 * ALBW_AS_F32(pppppppfVar13[0x16]) +
                     fVar21 * ALBW_AS_F32(pppppppfVar13[0x17]);
            if (fVar23 <= fVar7) {
              local_16c = *pppppppfVar18;
              local_168 = pppppppfVar13[10];
              local_164 = pppppppfVar13[0xb];
            }
            else {
              fVar23 = ALBW_AS_F32(pppppppfVar13[0x1a]) / fVar23;
              local_16c = (float ******)CF_FBITS((ALBW_AS_F32(*pppppppfVar18) + fVar17 * fVar23));
              local_168 = (float ******)CF_FBITS((ALBW_AS_F32(pppppppfVar13[10]) + fVar19 * fVar23));
              local_164 = (float ******)CF_FBITS((ALBW_AS_F32(pppppppfVar13[0xb]) + fVar21 * fVar23));
            }
            pppppppfVar26 = local_1ec;
            pppppppfVar25 = (float *******)CF_FBITS(local_1f0);
            pppppppfVar31 = local_1fc[2];
            func_00115C70((float *)&local_1ec,(float *)local_184,param_3 + 1);
            iVar6 = 0;
            pppppppfVar27 =
                 (float *******)
                 CF_FBITS((ALBW_AS_F32(pppppppfVar31) * ALBW_AS_F32(local_1ec) + ALBW_AS_F32(pppppppfVar25) * ALBW_AS_F32(local_1e8)
                 + ALBW_AS_F32(pppppppfVar26) * ALBW_AS_F32(local_1e4)));
            lVar28 = CONCAT44(fVar7,pppppppfVar27);
            do {
              if (iVar6 == 2) {
                pppppppfVar18 = (float *******)lVar28;
              }
              else {
                func_00115C70((float *)&local_1ec,(float *)(local_184 + (iVar6 + 1) * 3),param_3 + 1
                             );
                pppppppfVar18 =
                     (float *******)
                     CF_FBITS((ALBW_AS_F32(pppppppfVar31) * ALBW_AS_F32(local_1ec) +
                      ALBW_AS_F32(pppppppfVar25) * ALBW_AS_F32(local_1e8) +
                     ALBW_AS_F32(pppppppfVar26) * ALBW_AS_F32(local_1e4)));
              }
              fVar7 = ALBW_AS_F32(((ulonglong)lVar28 >> 0x20));
              bVar16 = ALBW_AS_F32(pppppppfVar27) == fVar7;
              bVar15 = fVar7 <= ALBW_AS_F32(pppppppfVar27);
              if (!bVar15 || bVar16) {
                bVar16 = ALBW_AS_F32(pppppppfVar18) == fVar7;
                bVar15 = fVar7 <= ALBW_AS_F32(pppppppfVar18);
              }
              if (bVar15 && !bVar16) goto LAB_00651c1c;
              iVar6 = iVar6 + 1;
              pppppppfVar27 = pppppppfVar18;
            } while (iVar6 < 3);
          }
          else {
LAB_00651c1c:
            pfVar9 = local_404;
            if ((int)local_410 < iStack_40c) {
              if (local_404 != (float *)0x0) {
                pfVar3 = (float *)CF_FBITS(*local_404);
                *local_404 = 0.0;
                local_404[1] = 0.0;
                local_404[2] = 0.0;
                local_404 = pfVar3;
              }
              if ((int)local_410 < iStack_40c) {
                *(float **)(local_408 + local_410 * 4) = pfVar9;
                local_410 = local_410 + 1;
              }
            }
            else {
              pfVar9 = (float *)0x0;
            }
            iVar6 = DAT_00652134;
            fVar7 = ALBW_AS_F32(((ulonglong)lVar28 >> 0x20));
            *pfVar9 = ALBW_AS_F32(pppppppfVar13);
            pfVar9[1] = fVar37;
            if (ALBW_AS_F32(pppppppfVar36) <= fVar7) {
              pppppppfVar36 = (float *******)CF_FBITS(-ALBW_AS_F32(pppppppfVar36));
            }
            pfVar9[2] = ALBW_AS_F32(pppppppfVar36);
            if ((int)pppppppfVar36 < iVar6) {
              pfVar9[2] = fVar7;
            }
          }
        }
      }
      pppppppfVar13 = (float *******)(*(int *)((int)pppppppfVar13 + iVar14 + 4) - iVar14);
      fVar37 = fVar24;
    } while (pppppppfVar13 != local_1e0);
  }
  *param_2 = ALBW_AS_F32(pppppppfVar33);
  param_2[8] = *param_3;
  param_2[1] = ALBW_AS_F32(local_160);
  param_2[2] = local_15c;
  param_2[3] = local_158;
  param_2[4] = param_3[4];
  param_2[5] = param_3[5];
  param_2[6] = param_3[6];
  if (local_410 != 0) {
    piVar8 = (int *)CF_FBITS(param_2[0xb]);
    if (piVar8 != (int *)0x0) {
      iVar14 = *piVar8;
      if (iVar14 < piVar8[1]) {
        *piVar8 = iVar14 + 1;
        puVar4 = (undefined4 *)(piVar8[2] + iVar14 * 0x10);
      }
      else {
        puVar4 = (undefined4 *)0x0;
      }
      *puVar4 = (undefined4)(uintptr_t)(pppppppfVar32);
      puVar4[1] = ALBW_AS_U32(param_3[7]);
      puVar4[2] = ALBW_AS_U32(param_3[8]);
      puVar4[3] = ALBW_AS_U32(param_3[9]);
    }
    func_0048C258((int *)&local_410,DAT_00652138);
    local_1d0 = (float *******)CF_FBITS(param_3[10]);
    uVar1 = 0;
    local_1c8 = (float *******)CF_FBITS(param_3[0xc]);
    local_1cc = pppppppfVar33;
    if (0 < (int)local_410) {
      lVar28 = lVar30 << 0x20;
      fVar37 = ALBW_AS_F32(((ulonglong)lVar30 >> 0x20));
      uVar29 = (ulonglong)DAT_00652140;
      iVar14 = extraout_r1;
      pppppppfVar32 = DAT_0065213c;
      do {
        if (uVar1 < local_410) {
          iVar14 = local_408;
        }
        if (uVar1 < local_410) {
          pfVar11 = *(float **)(iVar14 + uVar1 * 4);
        }
        else {
          pfVar11 = (float *)0x0;
        }
        pppppppfVar33 = (float *******)CF_FBITS(*pfVar11);
        piVar8 = (int *)(*(int *)((int)ALBW_AS_U32(param_3[0xc]) + 0xc) + (int)pppppppfVar33);
        iVar14 = piVar8[1];
        if (iVar14 == 0) {
          piVar8 = (int *)*piVar8;
        }
        if (iVar14 != 0 || piVar8 != (int *)0x0) {
          local_1dc = pppppppfVar33[0xc];
          local_1d8 = (float *******)pppppppfVar33[0xd];
          local_1d4 = (float *******)pppppppfVar33[0xe];
          local_1fc[1] = pppppppfVar33;
          func_00115C70((float *)&local_118,(float *)&local_160,(float *)(pppppppfVar33 + 9));
          local_d4 = local_118;
          local_d0 = local_114;
          local_cc = local_110;
          func_00115D70((float *)&local_428,(float *)&local_1dc,
                        ALBW_AS_F32(local_1dc) * ALBW_AS_F32(local_118) + ALBW_AS_F32(local_1d8) * ALBW_AS_F32(local_114) +
                        ALBW_AS_F32(local_1d4) * ALBW_AS_F32(local_110));
          local_c8 = local_428;
          pppppppfStack_c4 = local_424;
          pppppppfStack_c0 = local_420;
          func_00115C70((float *)&local_42c,(float *)&local_160,(float *)&local_c8);
          local_1fc[2] = local_42c;
          local_1f0 = ALBW_AS_F32(local_428);
          local_1ec = local_424;
          if (param_2[7] == 0.0) {
            func_00115E10((float *)&local_41c,param_3 + 4,(float *)&local_1dc);
            func_00115E10((float *)&local_1e8,(float *)&local_1dc,(float *)&local_41c);
            pppppppfVar18 = (float *******)CF_FBITS(func_00115DC8((float *)&local_1e8));
          }
          else {
            lVar28 = CONCAT44((int)((ulonglong)lVar28 >> 0x20),pppppppfVar35);
            pppppppfVar18 =
                 (float *******)
                 CF_FBITS((param_3[7] * ALBW_AS_F32(local_1dc) + param_3[8] * ALBW_AS_F32(local_1d8) +
                 param_3[9] * ALBW_AS_F32(local_1d4)));
            if (ALBW_AS_F32(pppppppfVar18) <= ALBW_AS_F32(pppppppfVar35)) {
              pppppppfVar18 = (float *******)CF_FBITS(-ALBW_AS_F32(pppppppfVar18));
            }
            if ((int)pppppppfVar18 < DAT_00652144) {
              iVar14 = func_00115B68(afStack_98,param_3 + 7,(float *)&local_1dc);
              if (iVar14 == 0) {
                local_fc = (float *******)lVar28;
                local_100 = pppppppfVar32;
                local_f8 = local_fc;
                local_f4 = local_fc;
                local_f0 = pppppppfVar32;
                local_ec = local_fc;
                local_e8 = local_fc;
                local_e4 = local_fc;
                local_e0 = pppppppfVar32;
              }
              else {
                func_00491404((float *)&local_100,afStack_98);
              }
              func_00115CE4((float *)&local_110,(float *)&local_100,param_3 + 4);
              fVar5 = *param_3;
              func_00115C70(&local_a8,(float *)&local_160,(float *)((int)ALBW_AS_U32(fVar5) + 0x24));
              fVar24 = local_a8 * *(float *)((int)ALBW_AS_U32(fVar5) + 0x30) +
                       local_a4 * *(float *)((int)ALBW_AS_U32(fVar5) + 0x34) +
                       local_a0 * *(float *)((int)ALBW_AS_U32(fVar5) + 0x38);
              bVar16 = fVar37 == fVar24;
              bVar15 = fVar24 <= fVar37;
              if (!bVar15 || bVar16) {
                fVar7 = ALBW_AS_F32(((ulonglong)lVar28 >> 0x20));
                bVar16 = fVar24 == fVar7;
                bVar15 = fVar7 <= fVar24;
              }
              pppppppfVar18 = pppppppfVar34;
              if (!bVar15 || bVar16) {
                local_b8[2] = (float *******)((int)ALBW_AS_U32(fVar5) + 0x54);
                pppppppfVar18 = (float *******)uVar29;
                local_b8[0] = (float *******)((int)ALBW_AS_U32(fVar5) + 0x3c);
                pppppppfVar36 = (float *******)0x0;
                local_b8[1] = (float *******)((int)ALBW_AS_U32(fVar5) + 0x48);
                pppppppfVar26 = local_b8[0];
                do {
                  pppppppfVar26 =
                       (float *******)
                       CF_FBITS((local_a8 * ALBW_AS_F32(*pppppppfVar26) + local_a4 * ALBW_AS_F32(pppppppfVar26[1]) +
                       local_a0 * ALBW_AS_F32(pppppppfVar26[2])));
                  while( true ) {
                    if (ALBW_AS_F32(pppppppfVar26) <= ALBW_AS_F32(lVar28)) {
                      pppppppfVar26 = (float *******)CF_FBITS(-ALBW_AS_F32(pppppppfVar26));
                    }
                    if (ALBW_AS_F32(pppppppfVar26) < ALBW_AS_F32(pppppppfVar18)) {
                      pppppppfVar13 = pppppppfVar36;
                      pppppppfVar18 = pppppppfVar26;
                    }
                    pppppppfVar36 = (float *******)((int)pppppppfVar36 + 1);
                    if (2 < (int)pppppppfVar36) {
                      if (pppppppfVar18 != DAT_00652148) goto LAB_00651fe0;
                      goto LAB_006520d0;
                    }
                    pppppppfVar26 = local_b8[(int)pppppppfVar36];
                    if (pppppppfVar36 != (float *******)0x2) break;
                    pppppppfVar26 =
                         (float *******)
                         CF_FBITS(((local_a8 * ALBW_AS_F32(*pppppppfVar26) + local_a4 * ALBW_AS_F32(pppppppfVar26[1]) +
                          local_a0 * ALBW_AS_F32(pppppppfVar26[2])) - *(float *)((int)ALBW_AS_U32(fVar5) + 0x68)));
                  }
                } while( true );
              }
LAB_00651fe0:
              if (pppppppfVar18 == (float *******)0xff7fffff) {
LAB_006520d0:
                func_00115E10((float *)&local_41c,param_3 + 4,(float *)&local_1dc);
                func_00115E10((float *)&local_1e8,(float *)&local_1dc,(float *)&local_41c);
                func_00115DC8((float *)&local_1e8);
              }
              else {
                pfVar11 = (float *)0x0;
                if (pppppppfVar13 == (float *******)0x0) {
                  pfVar11 = (float *)((int)ALBW_AS_U32(fVar5) + 0x3c);
                }
                else if (pppppppfVar13 == (float *******)0x1) {
                  pfVar11 = (float *)((int)ALBW_AS_U32(fVar5) + 0x48);
                }
                else if (pppppppfVar13 == (float *******)0x2) {
                  pfVar11 = (float *)((int)ALBW_AS_U32(fVar5) + 0x54);
                }
                func_00115E10((float *)&local_1e8,(float *)((int)ALBW_AS_U32(fVar5) + 0x30),pfVar11);
                if (ALBW_AS_F32(local_1e8) * param_3[4] + ALBW_AS_F32(local_1e4) * param_3[5] +
                    ALBW_AS_F32(local_1e0) * param_3[6] < ALBW_AS_F32(lVar28)) {
                  func_00115E10((float *)&local_1e8,pfVar11,(float *)((int)ALBW_AS_U32(fVar5) + 0x30));
                }
                func_00115D70((float *)&local_428,(float *)&local_1dc,
                              ALBW_AS_F32(local_1e8) * ALBW_AS_F32(local_1dc) +
                              ALBW_AS_F32(local_1e4) * ALBW_AS_F32(local_1d8) +
                              ALBW_AS_F32(local_1e0) * ALBW_AS_F32(local_1d4));
                local_b8[0] = local_428;
                local_b8[1] = local_424;
                local_b8[2] = local_420;
                func_00115C70((float *)&local_1e8,(float *)&local_1e8,(float *)local_b8);
                fVar5 = func_00115DC8((float *)&local_1e8);
                if ((int)ALBW_AS_U32(fVar5) < DAT_0065214c) goto LAB_006520d0;
              }
              pppppppfVar18 =
                   (float *******)
                   CF_FBITS(((ALBW_AS_F32(local_1e8) * ALBW_AS_F32(local_110) + ALBW_AS_F32(local_1e4) * ALBW_AS_F32(local_10c) +
                    ALBW_AS_F32(local_1e0) * local_108) * ALBW_AS_F32(local_1cc)));
              local_1cc = pppppppfVar18;
            }
            else {
              local_1e8 = (float ******)CF_FBITS(param_3[4]);
              local_1e4 = (float *******)CF_FBITS(param_3[5]);
              local_1e0 = (float *******)CF_FBITS(param_3[6]);
            }
          }
          func_00115C54((float *)&local_118,(float *)(local_1fc + 2),(float *)&local_1e8);
          local_d4 = local_118;
          local_d0 = local_114;
          local_cc = local_110;
          fVar5 = ALBW_AS_F32(func_00115C70((float *)&local_41c,(float *)&local_d4,param_3 + 1));
          if (param_2 != (float *)0x0) {
            fVar5 = param_2[9];
          }
          if (param_2 != (float *)0x0 && fVar5 != 0.0) {
            local_1c4 = param_3[0xd];
          }
          uVar10 = func_00650A24(local_30,param_2,(float *)(local_1fc + 1));
          pppppppfVar36 = local_1c8;
          if (uVar10 < 2) {
            return 0;
          }
          iVar14 = extraout_r1_00;
          if (uVar10 == 2) {
            piVar8 = (int *)((int)local_1c8[3] + (int)pppppppfVar33);
            iVar14 = piVar8[1];
            bVar16 = iVar14 == 0;
            if (bVar16) {
              iVar14 = *piVar8;
            }
            if (!bVar16 || iVar14 != 0) {
              func_0010F1F8(piVar8,ALBW_AS_F32(pppppppfVar18));
              pppppppfVar36[2] = (float ******)((int)pppppppfVar36[2] + -1);
              iVar14 = extraout_r1_01;
            }
          }
        }
        uVar1 = uVar1 + 1;
      } while ((int)uVar1 < (int)local_410);
    }
  }
LAB_00652290:
  fVar37 = param_3[0xc];
  piVar8 = (int *)((int)ALBW_AS_U32(*param_3) + *(int *)((int)ALBW_AS_U32(fVar37) + 0xc));
  iVar14 = piVar8[1];
  bVar16 = iVar14 == 0;
  if (bVar16) {
    iVar14 = *piVar8;
  }
  if (!bVar16 || iVar14 != 0) {
    func_0010F1F8(piVar8,ALBW_AS_F32(pppppppfVar18));
    *(int *)((int)ALBW_AS_U32(fVar37) + 8) = *(int *)((int)ALBW_AS_U32(fVar37) + 8) + -1;
  }
  return 2;
}

