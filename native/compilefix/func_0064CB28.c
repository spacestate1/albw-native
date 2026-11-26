/* compilefix: USA 0064CB28 (EU 0064CB00), Ghidra-derived (build/ghidra_analyzed4).
 * Failed to compile: operand of type 'float' cannot be cast to a pointer type
 * Fixed (each an exact C form of the ARM operation; the rest is the converted Ghidra text):
 *  - (T *)<float expr> -> (T *)CF_FBITS(expr): 32-bit copy of the float (vmov/vstr), never a conversion [38]
 *  - implicit float<->int conversions (Ghidra COPY between a float and an int-typed variable or
 *    pool word, e.g. `fVar = _DAT_xxx;`, `puVar[3] = fVar;`) made bit copies [1]
 *  - two edge-direction range tests (EU 0064D6D0 / 0064E690: vmov r2, s10; sub; cmp) work on the
 *    float BITS of a dot product (0.1 <= dot < 0.9: bits - 0x3DCCCCCD < 0x0199999A); the text
 *    converted the dot to an integer (0.3 -> 0), so no edge ever qualified (160bh)
 * Confidence: high for the fixes (each class checked against the EU disassembly on sample sites);
 * the function body otherwise has the fidelity of the Ghidra output (bare `return;` exits of
 * functions retyped non-void return 0, as the converter does). */
/* An edge can be crossed when its direction against the step is between 0.1 and 0.9.
 * The ARM code tests the float BITS: bits(dot) - bits(0.1f) < 0x0199999A (unsigned). */
#define EDGE_DIR_IN_RANGE(dot) ((uint)((int)ALBW_AS_U32(dot) - DAT_0064d804) < DAT_0064d808)
#include "ghidra_types.h"
#include "../include/ghidra_concat44.h"
#include "compilefix.h"

extern int func_0010F1DC(int *param_1,int *param_2);
extern float func_0010F1F8(int *param_1,float fparam_0);
extern int func_00115C54(float *param_1,float *param_2,float *param_3);
extern int func_00115C70(float *param_1,float *param_2,float *param_3);
extern int func_00115D70(float *param_1,float *param_2,float fparam_0);
extern float func_00115DC8(float *param_1);
extern int func_00115E10(float *param_1,float *param_2,float *param_3);
extern int func_001EA738(undefined4 param_1,int *param_2,int param_3,float *param_4,float fparam_0);
extern int func_001FE680(undefined4 *param_1);
extern int func_0048C258(int *param_1,undefined *param_2);
extern int func_0049F5FC(undefined4 *param_1);
extern int func_004A17A4(float *param_1);
extern int func_0063ADF4(int *param_1,undefined4 *param_2,int *param_3);
extern int func_00650A24(int param_1,float *param_2,float *param_3);
extern int func_00688AB0(undefined4 *param_1);
extern undefined4 *DAT_0064cec8;
extern float *DAT_0064cecc;
extern uint DAT_0064ced0;
extern float * * * * * * *DAT_0064ced4;
extern float DAT_0064ced8;
extern float * * * * * * *DAT_0064cedc;
extern float * * * * * * *DAT_0064cee0;
extern int DAT_0064d3d4;
extern undefined4 DAT_0064d3d8;
extern undefined4 DAT_0064d3dc;
extern float DAT_0064d3e0;
extern float DAT_0064d3e4;
extern float DAT_0064d7fc;
extern float DAT_0064d800;
extern int DAT_0064d804;
extern uint DAT_0064d808;
extern float * * * * * *DAT_0064e800;
extern float * * * * * * *DAT_0064e804;
extern float * * * * * * *DAT_0064e808;
extern int DAT_0064e80c;
extern undefined *DAT_0064e810;
extern int DAT_0064e814;

// USA 0064CB28 <- EU 0064CB00 (Ghidra, non-matching)
// GLOBAL DAT_0064cec8 undefined4 *
// GLOBAL DAT_0064cecc float *
// GLOBAL DAT_0064ced0 uint
// GLOBAL DAT_0064ced4 float * * * * * * *
// GLOBAL DAT_0064ced8 float
// GLOBAL DAT_0064cedc float * * * * * * *
// GLOBAL DAT_0064cee0 float * * * * * * *
// GLOBAL DAT_0064d3d4 int
// GLOBAL DAT_0064d3d8 undefined4
// GLOBAL DAT_0064d3dc undefined4
// GLOBAL DAT_0064d3e0 float
// GLOBAL DAT_0064d3e4 float
// GLOBAL DAT_0064d7fc float
// GLOBAL DAT_0064d800 float
// GLOBAL DAT_0064d804 int
// GLOBAL DAT_0064d808 uint
// GLOBAL DAT_0064e800 float * * * * * *
// GLOBAL DAT_0064e804 float * * * * * * *
// GLOBAL DAT_0064e808 float * * * * * * *
// GLOBAL DAT_0064e80c int
// GLOBAL DAT_0064e810 undefined *
// GLOBAL DAT_0064e814 int

/* WARNING: Type propagation algorithm not settling */

undefined4 func_0064CB28(int *param_1,int *param_2,int *param_3)

{
  undefined1 uVar1;
  int iVar2;
  float ******ppppppfVar3;
  uint uVar4;
  int *piVar5;
  float *pfVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  uint *extraout_r1;
  int iVar9;
  uint uVar10;
  float *******pppppppfVar11;
  float *pfVar12;
  uint *puVar13;
  bool bVar14;
  bool bVar15;
  float fVar16;
  float *******pppppppfVar17;
  int *piVar18;
  float fVar19;
  float *****pppppfVar20;
  float fVar21;
  float *****pppppfVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float ******ppppppfVar26;
  float *******pppppppfVar27;
  float *******fparam_0;
  float fVar28;
  float *******pppppppfVar29;
  float *******pppppppfVar30;
  ulonglong uVar31;
  float *******pppppppfVar33;
  undefined8 uVar32;
  float *******pppppppfVar34;
  float *******pppppppfVar35;
  float *******pppppppfVar36;
  undefined8 uVar37;
  longlong lVar38;
  undefined4 uVar40;
  undefined8 uVar39;
  _Alignas(8) unsigned char albw_frame[0x460];
  #define local_460 (*(float ****** *)(albw_frame + 0x0))
  #define local_45c (*(float ******* *)(albw_frame + 0x4))
  #define local_458 (*(float ******* *)(albw_frame + 0x8))
  #define local_454 (*(float ******* *)(albw_frame + 0xc))
  #define local_450 (*(float ****** *)(albw_frame + 0x10))
  #define local_44c (*(float ******* *)(albw_frame + 0x14))
  #define pppppppfStack_448 (*(float ******* *)(albw_frame + 0x18))
  #define ppppppfStack_444 (*(float ****** *)(albw_frame + 0x1c))
  #define local_440 (*(uint *)(albw_frame + 0x20))
  #define iStack_43c (*(int *)(albw_frame + 0x24))
  #define local_438 (*(int *)(albw_frame + 0x28))
  #define local_434 (*(undefined4 * *)(albw_frame + 0x2c))
  #define local_228 (*(float ******* *)(albw_frame + 0x238))
  #define local_224 (*(float ******* *)(albw_frame + 0x23c))
  #define local_220 (*(float ******* *)(albw_frame + 0x240))
  #define local_21c (*(float *)(albw_frame + 0x244))
  #define local_218 (*(float *)(albw_frame + 0x248))
  #define local_214 (*(float *)(albw_frame + 0x24c))
  #define local_210 (*(float ******* *)(albw_frame + 0x250))
  #define local_20c (*(float ******* *)(albw_frame + 0x254))
  #define local_208 (*(float ******* *)(albw_frame + 0x258))
  #define local_204 (*(float *)(albw_frame + 0x25c))
  #define local_200 (*(float *)(albw_frame + 0x260))
  #define local_1fc (*(float *)(albw_frame + 0x264))
  #define local_1f8 ((float ******* *)(albw_frame + 0x268))
  #define local_1e8 (*(float ******* *)(albw_frame + 0x278))
  #define local_1e4 (*(float ******* *)(albw_frame + 0x27c))
  #define local_1e0 (*(float ******* *)(albw_frame + 0x280))
  #define local_1dc (*(float ******* *)(albw_frame + 0x284))
  #define local_1d8 (*(float ******* *)(albw_frame + 0x288))
  #define local_1d4 (*(float ******* *)(albw_frame + 0x28c))
  #define local_1d0 (*(float ******* *)(albw_frame + 0x290))
  #define local_1cc (*(float *)(albw_frame + 0x294))
  #define local_1c8 (*(float *)(albw_frame + 0x298))
  #define local_1c4 (*(int *)(albw_frame + 0x29c))
  #define local_1c0 (*(int *)(albw_frame + 0x2a0))
  #define local_1bc (*(float *)(albw_frame + 0x2a4))
  #define local_1b8 (*(float *)(albw_frame + 0x2a8))
  #define local_1b4 (*(float *)(albw_frame + 0x2ac))
  #define local_1b0 (*(float *)(albw_frame + 0x2b0))
  #define local_1ac (*(float *)(albw_frame + 0x2b4))
  #define local_1a8 (*(float *)(albw_frame + 0x2b8))
  #define local_1a4 (*(float ******* *)(albw_frame + 0x2bc))
  #define pppppppfStack_1a0 (*(float ******* *)(albw_frame + 0x2c0))
  #define ppppppfStack_19c (*(float ****** *)(albw_frame + 0x2c4))
  #define local_198 (*(float ******* *)(albw_frame + 0x2c8))
  #define pppppppfStack_194 (*(float ******* *)(albw_frame + 0x2cc))
  #define pppppppfStack_190 (*(float ******* *)(albw_frame + 0x2d0))
  #define local_18c (*(float ******* *)(albw_frame + 0x2d4))
  #define local_188 (*(float ******* *)(albw_frame + 0x2d8))
  #define local_184 (*(float ******* *)(albw_frame + 0x2dc))
  #define local_180 (*(float *)(albw_frame + 0x2e0))
  #define local_17c (*(int *)(albw_frame + 0x2e4))
  #define local_178 (*(int *)(albw_frame + 0x2e8))
  #define local_174 (*(float *)(albw_frame + 0x2ec))
  #define local_170 (*(float *)(albw_frame + 0x2f0))
  #define local_16c (*(float *)(albw_frame + 0x2f4))
  #define local_168 (*(float *)(albw_frame + 0x2f8))
  #define local_164 (*(float *)(albw_frame + 0x2fc))
  #define local_160 (*(float *)(albw_frame + 0x300))
  #define local_15c (*(float *)(albw_frame + 0x304))
  #define local_158 (*(float ******* *)(albw_frame + 0x308))
  #define local_154 (*(float ******* *)(albw_frame + 0x30c))
  #define local_150 (*(float ******* *)(albw_frame + 0x310))
  #define local_14c (*(float ******* *)(albw_frame + 0x314))
  #define local_148 (*(float ******* *)(albw_frame + 0x318))
  #define local_144 (*(float *)(albw_frame + 0x31c))
  #define local_140 (*(int * *)(albw_frame + 0x320))
  #define local_13c (*(float ******* *)(albw_frame + 0x324))
  #define local_138 (*(float ******* *)(albw_frame + 0x328))
  #define local_134 (*(float ******* *)(albw_frame + 0x32c))
  #define local_130 (*(float ******* *)(albw_frame + 0x330))
  #define local_12c (*(float ******* *)(albw_frame + 0x334))
  #define local_128 (*(float ******* *)(albw_frame + 0x338))
  #define local_124 (*(float ******* *)(albw_frame + 0x33c))
  #define local_120 (*(float ******* *)(albw_frame + 0x340))
  #define local_11c (*(float ******* *)(albw_frame + 0x344))
  #define local_118 (*(float ******* *)(albw_frame + 0x348))
  #define local_114 (*(float ******* *)(albw_frame + 0x34c))
  #define local_110 (*(float ******* *)(albw_frame + 0x350))
  #define local_10c (*(float ******* *)(albw_frame + 0x354))
  #define local_108 (*(float ******* *)(albw_frame + 0x358))
  #define local_104 (*(float ******* *)(albw_frame + 0x35c))
  #define local_100 (*(float ******* *)(albw_frame + 0x360))
  #define local_fc (*(float ******* *)(albw_frame + 0x364))
  #define local_f8 (*(float ******* *)(albw_frame + 0x368))
  #define local_f4 (*(float ******* *)(albw_frame + 0x36c))
  #define local_f0 (*(float ******* *)(albw_frame + 0x370))
  #define local_ec (*(float *)(albw_frame + 0x374))
  #define local_e8 (*(int * *)(albw_frame + 0x378))
  #define local_e4 (*(float ****** *)(albw_frame + 0x37c))
  #define local_e0 (*(float ******* *)(albw_frame + 0x380))
  #define local_dc (*(float ******* *)(albw_frame + 0x384))
  #define local_d8 (*(float ******* *)(albw_frame + 0x388))
  #define local_d0 (*(float ******* *)(albw_frame + 0x390))
  #define local_cc (*(float ******* *)(albw_frame + 0x394))
  #define local_c8 (*(float ******* *)(albw_frame + 0x398))
  #define local_c4 (*(float ******* *)(albw_frame + 0x39c))
  #define local_c0 (*(float ******* *)(albw_frame + 0x3a0))
  #define local_bc (*(float ******* *)(albw_frame + 0x3a4))
  #define local_b8 (*(float ******* *)(albw_frame + 0x3a8))
  #define local_b4 (*(float ****** *)(albw_frame + 0x3ac))
  #define local_b0 (*(float ****** *)(albw_frame + 0x3b0))
  #define local_ac (*(float ******* *)(albw_frame + 0x3b4))
  #define local_a8 (*(float ****** *)(albw_frame + 0x3b8))
  #define local_a4 (*(float *)(albw_frame + 0x3bc))
  #define local_a0 ((float ****** *)(albw_frame + 0x3c0))
  #define local_98 ((float ******* *)(albw_frame + 0x3c8))
  #define local_8c (*(float *)(albw_frame + 0x3d4))
  #define local_88 (*(float ******* *)(albw_frame + 0x3d8))
  #define local_84 (*(float *)(albw_frame + 0x3dc))
  #define local_80 ((float *)(albw_frame + 0x3e0))
  #define local_30 (*(int * *)(albw_frame + 0x430))
  #define piStack_2c (*(int * *)(albw_frame + 0x434))
  #define piStack_28 (*(int * *)(albw_frame + 0x438))
  if (param_2 != (int *)0x0) {
    param_2[10] = param_2[10] + 1;
  }
  lVar38 = (ulonglong)DAT_0064ced0 << 0x20;
  pfVar12 = (float *)0x0;
  local_20c = (float *******)DAT_0064cec8[1];
  local_210 = (float *******)*DAT_0064cec8;
  local_208 = (float *******)DAT_0064cec8[2];
  local_204 = *DAT_0064cecc;
  local_200 = DAT_0064cecc[1];
  local_1fc = DAT_0064cecc[2];
  local_228 = (float *******)param_3[1];
  local_224 = (float *******)param_3[2];
  local_220 = (float *******)param_3[3];
  local_21c = ALBW_AS_F32(param_3[4]);
  local_218 = ALBW_AS_F32(param_3[5]);
  local_214 = ALBW_AS_F32(param_3[6]);
  local_30 = param_1;
  piStack_2c = param_2;
  piStack_28 = param_3;
  func_00688AB0(&local_440);
  local_120 = (float *******)0x0;
  local_15c = 0.0;
  pppppppfVar11 = DAT_0064ced4;
  func_00115D70((float *)&local_458,(float *)(param_3 + 7),ALBW_AS_F32(DAT_0064ced4));
  local_1a4 = local_458;
  pppppppfStack_1a0 = local_454;
  ppppppfStack_19c = local_450;
  func_00115C54((float *)&local_458,(float *)(param_3 + 1),(float *)&local_1a4);
  local_44c = local_458;
  pppppppfStack_448 = local_454;
  ppppppfStack_444 = local_450;
  func_00115D70((float *)&local_45c,(float *)(local_30 + 0x15),ALBW_AS_F32(pppppppfVar11));
  local_198 = local_45c;
  pppppppfStack_194 = local_458;
  pppppppfStack_190 = local_454;
  func_00115C54((float *)&local_460,(float *)&local_44c,(float *)&local_198);
  local_210 = (float *******)local_460;
  local_20c = local_45c;
  local_208 = local_458;
  local_204 = ALBW_AS_F32(param_3[4]);
  local_200 = ALBW_AS_F32(param_3[5]);
  local_1fc = ALBW_AS_F32(param_3[6]);
  local_1dc = (float *******)0x0;
  func_00115D70((float *)&local_458,(float *)(param_3 + 7),ALBW_AS_F32(pppppppfVar11));
  local_13c = local_458;
  local_138 = local_454;
  local_134 = (float *******)local_450;
  func_00115C54((float *)&local_458,(float *)(param_3 + 1),(float *)&local_13c);
  uVar40 = (undefined4)((ulonglong)lVar38 >> 0x20);
  local_210 = local_458;
  local_20c = local_454;
  local_208 = (float *******)local_450;
  local_204 = ALBW_AS_F32(param_3[4]);
  local_200 = ALBW_AS_F32(param_3[5]);
  uVar31 = ZEXT48(DAT_0064cee0);
  local_1fc = ALBW_AS_F32(param_3[6]);
  iVar2 = *param_3;
  pppppppfVar35 = (float *******)param_3[0xb];
  local_1d8 = (float *******)0x1;
  local_454 = (float *******)(iVar2 + 0x24);
  fVar19 = *(float *)(iVar2 + 0x30);
  fVar21 = *(float *)(iVar2 + 0x34);
  fVar23 = *(float *)(iVar2 + 0x38);
  fVar16 = local_21c * fVar19 + local_218 * fVar21 + local_214 * fVar23;
  fVar28 = DAT_0064ced8;
  pppppppfVar36 = DAT_0064cedc;
  local_100 = (float *******)&local_228;
  if ((fVar16 < DAT_0064ced8) || (ALBW_AS_F32(pppppppfVar11) < fVar16)) {
    pppppppfVar34 =
         (float *******)
         CF_FBITS((((fVar19 * ALBW_AS_F32(*local_454) + fVar21 * *(float *)(iVar2 + 0x28) +
           fVar23 * *(float *)(iVar2 + 0x2c)) -
          (fVar19 * ALBW_AS_F32(local_228) + fVar21 * ALBW_AS_F32(local_224) + fVar23 * ALBW_AS_F32(local_220))) /
         fVar16));
    pppppppfVar17 = (float *******)CF_FBITS((ALBW_AS_F32(pppppppfVar34) - ALBW_AS_F32(pppppppfVar35)));
    pppppppfVar27 = DAT_0064cee0;
    if ((ALBW_AS_F32(pppppppfVar17) <= ALBW_AS_F32(pppppppfVar11)) && (DAT_0064ced8 <= ALBW_AS_F32(pppppppfVar34))) {
      pppppppfVar35 = pppppppfVar11;
      func_00115D70((float *)&local_1e8,&local_21c,ALBW_AS_F32(pppppppfVar34));
      local_158 = local_1e8;
      local_154 = local_1e4;
      local_150 = local_1e0;
      func_00115C54((float *)&local_1e8,(float *)&local_228,(float *)&local_158);
      local_1f8[0] = local_1e8;
      local_1f8[1] = local_1e4;
      local_1f8[2] = local_1e0;
      func_00115C70((float *)&local_1e8,(float *)local_1f8,(float *)local_454);
      pppppppfVar17 = local_1e8;
      if (((ALBW_AS_F32(local_1e8) * *(float *)(iVar2 + 0x3c) +
            ALBW_AS_F32(local_1e4) * *(float *)(iVar2 + 0x40) +
            ALBW_AS_F32(local_1e0) * *(float *)(iVar2 + 0x44) <= ALBW_AS_F32(pppppppfVar35)) &&
          (ALBW_AS_F32(local_1e8) * *(float *)(iVar2 + 0x48) + ALBW_AS_F32(local_1e4) * *(float *)(iVar2 + 0x4c)
           + ALBW_AS_F32(local_1e0) * *(float *)(iVar2 + 0x50) <= ALBW_AS_F32(pppppppfVar35))) &&
         (pppppppfVar17 =
               (float *******)
               CF_FBITS((ALBW_AS_F32(local_1e8) * *(float *)(iVar2 + 0x54) +
                ALBW_AS_F32(local_1e4) * *(float *)(iVar2 + 0x58) +
               ALBW_AS_F32(local_1e0) * *(float *)(iVar2 + 0x5c))),
         ALBW_AS_F32(pppppppfVar17) <= *(float *)(iVar2 + 0x68) + ALBW_AS_F32(pppppppfVar35)))
      goto LAB_0064d078;
    }
LAB_0064d098:
    pppppppfVar34 = pppppppfVar36;
    local_1d8 = (float *******)0x0;
    pppppppfVar36 = pppppppfVar34;
  }
  else {
    pppppppfVar30 = pppppppfVar11;
    func_00115C70((float *)&local_1e8,(float *)&local_228,(float *)local_454);
    uVar40 = (undefined4)((ulonglong)lVar38 >> 0x20);
    pppppppfVar34 = (float *******)uVar31;
    pppppppfVar17 =
         (float *******)
         CF_FBITS((ALBW_AS_F32(local_1e8) * *(float *)(iVar2 + 0x30) + ALBW_AS_F32(local_1e4) * *(float *)(iVar2 + 0x34)
         + ALBW_AS_F32(local_1e0) * *(float *)(iVar2 + 0x38)));
    pppppppfVar27 = pppppppfVar34;
    if (ALBW_AS_F32(pppppppfVar17) <= ALBW_AS_F32(pppppppfVar30)) {
      fVar16 = -ALBW_AS_F32(pppppppfVar30);
      iVar9 = 0;
      local_1f8[0] = (float *******)(iVar2 + 0x3c);
      local_1f8[1] = (float *******)(iVar2 + 0x48);
      local_1f8[2] = (float *******)(iVar2 + 0x54);
      pppppppfVar34 = local_1e4;
      pppppppfVar33 = local_1e8;
      pppppppfVar29 = pppppppfVar36;
      do {
        ppppppfVar3 = (float ******)local_1f8[iVar9];
        pppppfVar22 = ppppppfVar3[1];
        pppppfVar20 = ppppppfVar3[2];
        pppppppfVar17 =
             (float *******)
             CF_FBITS((local_21c * ALBW_AS_F32(*ppppppfVar3) + local_218 * ALBW_AS_F32(pppppfVar22) +
             local_214 * ALBW_AS_F32(pppppfVar20)));
        bVar14 = fVar16 == ALBW_AS_F32(pppppppfVar17);
        bVar15 = ALBW_AS_F32(pppppppfVar17) <= fVar16;
        if (!bVar15 || bVar14) {
          bVar14 = ALBW_AS_F32(pppppppfVar17) == ALBW_AS_F32(pppppppfVar30);
          bVar15 = ALBW_AS_F32(pppppppfVar30) <= ALBW_AS_F32(pppppppfVar17);
        }
        if (bVar15 && !bVar14) {
          fVar19 = ALBW_AS_F32(*ppppppfVar3) * ALBW_AS_F32(pppppppfVar33);
          if (iVar9 == 2) {
            fVar19 = *(float *)(iVar2 + 0x68) -
                     (fVar19 + ALBW_AS_F32(pppppfVar22) * ALBW_AS_F32(pppppppfVar34) +
                     ALBW_AS_F32(pppppfVar20) * ALBW_AS_F32(local_1e0));
          }
          else {
            fVar19 = -(fVar19 + ALBW_AS_F32(pppppfVar22) * ALBW_AS_F32(pppppppfVar34) +
                      ALBW_AS_F32(pppppfVar20) * ALBW_AS_F32(local_1e0));
          }
          pppppppfVar27 = (float *******)CF_FBITS((fVar19 / ALBW_AS_F32(pppppppfVar17)));
          if (ALBW_AS_F32(pppppppfVar29) <= ALBW_AS_F32(pppppppfVar27) &&
              ALBW_AS_F32(pppppppfVar36) <= ALBW_AS_F32(pppppppfVar27)) {
            bVar14 = ALBW_AS_F32(pppppppfVar35) <= ALBW_AS_F32(pppppppfVar27);
            fparam_0 = pppppppfVar35;
            if (!bVar14) {
              fparam_0 = pppppppfVar27;
            }
            func_00115D70((float *)&local_11c,&local_21c,ALBW_AS_F32(fparam_0));
            local_130 = local_11c;
            local_12c = local_118;
            local_128 = local_114;
            func_00115C54((float *)&local_110,(float *)local_100,(float *)&local_130);
            local_158 = local_110;
            local_154 = local_10c;
            local_150 = local_108;
            func_00115C70((float *)&local_1d4,(float *)&local_158,(float *)local_454);
            uVar40 = (undefined4)((ulonglong)lVar38 >> 0x20);
            pppppppfVar27 = (float *******)uVar31;
            pppppppfVar17 = local_1d0;
            if (((ALBW_AS_F32(local_1d4) * ALBW_AS_F32(*local_1f8[0]) +
                  ALBW_AS_F32(local_1d0) * ALBW_AS_F32(local_1f8[0][1]) + local_1cc * ALBW_AS_F32(local_1f8[0][2]) <=
                  ALBW_AS_F32(pppppppfVar30)) &&
                (ALBW_AS_F32(local_1d4) * ALBW_AS_F32(*local_1f8[1]) + ALBW_AS_F32(local_1d0) * ALBW_AS_F32(local_1f8[1][1])
                 + local_1cc * ALBW_AS_F32(local_1f8[1][2]) <= ALBW_AS_F32(pppppppfVar30))) &&
               ((ALBW_AS_F32(local_1d4) * ALBW_AS_F32(*local_1f8[2]) + ALBW_AS_F32(local_1d0) * ALBW_AS_F32(local_1f8[2][1])
                 + local_1cc * ALBW_AS_F32(local_1f8[2][2]) <=
                 *(float *)(iVar2 + 0x68) + ALBW_AS_F32(pppppppfVar30) &&
                (pppppppfVar36 = fparam_0, bVar14)))) break;
          }
        }
        uVar40 = (undefined4)((ulonglong)lVar38 >> 0x20);
        pppppppfVar27 = (float *******)uVar31;
        iVar9 = iVar9 + 1;
      } while (iVar9 < 3);
      bVar14 = ALBW_AS_F32(pppppppfVar36) == ALBW_AS_F32(pppppppfVar29);
      pppppppfVar34 = pppppppfVar36;
      pppppppfVar36 = pppppppfVar29;
      if (bVar14) goto LAB_0064d098;
    }
LAB_0064d078:
    if ((pppppppfVar34 == (float *******)0xff7fffff) || ((int)pppppppfVar34 < DAT_0064d3d4))
    goto LAB_0064d098;
  }
  local_1e0 = (float *******)(local_30 + 0xf40);
  if (*(char *)((int)local_30 + 0x3dc2) == '\0') {
    pppppppfVar35 = pppppppfVar34;
    local_15c = ALBW_AS_F32(func_001EA738((undefined4)(uintptr_t)(local_30),(int *)&local_148,param_3[0xc],(float *)&local_210,
                                     ALBW_AS_F32(pppppppfVar34)));
    pppppppfVar17 = pppppppfVar34;
    pppppppfVar34 = pppppppfVar35;
  }
  iVar2 = DAT_0064d3d4;
  uVar37 = CONCAT44(DAT_0064d3d8,pppppppfVar27);
  uVar39 = CONCAT44(uVar40,DAT_0064d3dc);
  if (local_15c == 0.0 && local_1d8 == (float *******)0x0) {
    if ((param_2 == (int *)0x0) || (param_2[10] != 1)) {
      return 3;
    }
    local_18c = local_228;
    local_188 = local_224;
    local_184 = local_220;
    pppppppfVar35 = pppppppfVar36;
LAB_0064da24:
    iVar2 = param_3[0xc];
    pppppppfVar34 = pppppppfVar36;
    func_0010F1F8((int *)(*param_3 + *(int *)(iVar2 + 0xc)),ALBW_AS_F32(pppppppfVar17));
    *(int *)(iVar2 + 8) = *(int *)(iVar2 + 8) + -1;
LAB_0064da44:
    pppppppfVar17 = (float *******)param_3[0xb];
    pppppppfVar36 = (float *******)CF_FBITS((ALBW_AS_F32(pppppppfVar17) - ALBW_AS_F32(pppppppfVar34)));
    local_1e0 = (float *******)(param_3[0xc] - *(int *)(param_3[0xc] + 0xc));
    iVar2 = *(int *)(param_3[0xc] + 0xc);
    piVar5 = (int *)(*(int *)(param_3[0xc] + 4) - iVar2);
    if ((float *******)piVar5 != local_1e0) {
      do {
        pppppppfVar17 =
             (float *******)
             CF_FBITS((ALBW_AS_F32(piVar5[0xc]) * ALBW_AS_F32(param_3[7]) + ALBW_AS_F32(piVar5[0xd]) * ALBW_AS_F32(param_3[8]) +
             ALBW_AS_F32(piVar5[0xe]) * ALBW_AS_F32(param_3[9])));
        if (((pppppppfVar17 <= DAT_0064e804) &&
            (func_00115C70(&local_8c,(float *)&local_18c,(float *)(piVar5 + 9)),
            pppppppfVar17 = local_88,
            local_8c * ALBW_AS_F32(piVar5[0xf]) + ALBW_AS_F32(local_88) * ALBW_AS_F32(piVar5[0x10]) +
            local_84 * ALBW_AS_F32(piVar5[0x11]) <= ALBW_AS_F32(pppppppfVar11))) &&
           ((local_8c * ALBW_AS_F32(piVar5[0x12]) + ALBW_AS_F32(local_88) * ALBW_AS_F32(piVar5[0x13]) +
             local_84 * ALBW_AS_F32(piVar5[0x14]) <= ALBW_AS_F32(pppppppfVar11) &&
            (local_8c * ALBW_AS_F32(piVar5[0x15]) + ALBW_AS_F32(local_88) * ALBW_AS_F32(piVar5[0x16]) +
             local_84 * ALBW_AS_F32(piVar5[0x17]) <= ALBW_AS_F32(piVar5[0x1a]) + ALBW_AS_F32(pppppppfVar11))))) {
          fVar16 = -(local_8c * ALBW_AS_F32(piVar5[0xc]) + ALBW_AS_F32(local_88) * ALBW_AS_F32(piVar5[0xd]) +
                    local_84 * ALBW_AS_F32(piVar5[0xe]));
          if ((fVar16 < fVar28) || (pppppppfVar17 = pppppppfVar11, ALBW_AS_F32(pppppppfVar11) < fVar16)) {
            fVar16 = ALBW_AS_F32(uVar37);
          }
          if (fVar16 != -3.4028235e+38) {
            local_1f8[1] = (float *******)
                           CF_FBITS((ALBW_AS_F32(piVar5[0xc]) * ALBW_AS_F32(param_3[4]) +
                            ALBW_AS_F32(piVar5[0xd]) * ALBW_AS_F32(param_3[5]) +
                           ALBW_AS_F32(piVar5[0xe]) * ALBW_AS_F32(param_3[6])));
            if (pfVar12 == (float *)0x0) {
              func_00115E10((float *)&local_1dc,(float *)DAT_0064e800,(float *)(param_3 + 7));
              pfVar12 = local_80;
              func_00115E10(pfVar12,(float *)&local_1dc,(float *)DAT_0064e800);
            }
            if (DAT_0064e808 < local_1f8[1]) {
              local_1c8 = ALBW_AS_F32(piVar5[9]);
              uVar31 = ZEXT48(pppppppfVar35);
              local_1c4 = piVar5[10];
              local_1c0 = piVar5[0xb];
              pfVar6 = (float *)(piVar5 + 9);
              fVar21 = ALBW_AS_F32(piVar5[0xe]) * ALBW_AS_F32(piVar5[0x10]) -
                       ALBW_AS_F32(piVar5[0xd]) * ALBW_AS_F32(piVar5[0x11]);
              fVar23 = ALBW_AS_F32(piVar5[0xc]) * ALBW_AS_F32(piVar5[0x11]) -
                       ALBW_AS_F32(piVar5[0xe]) * ALBW_AS_F32(piVar5[0xf]);
              fVar24 = ALBW_AS_F32(piVar5[0xd]) * ALBW_AS_F32(piVar5[0xf]) -
                       ALBW_AS_F32(piVar5[0xc]) * ALBW_AS_F32(piVar5[0x10]);
              fVar19 = fVar21 * ALBW_AS_F32(piVar5[0x15]) + fVar23 * ALBW_AS_F32(piVar5[0x16]) +
                       fVar24 * ALBW_AS_F32(piVar5[0x17]);
              if (fVar19 <= ALBW_AS_F32(pppppppfVar35)) {
                local_1bc = *pfVar6;
                local_1b8 = ALBW_AS_F32(piVar5[10]);
                local_1b4 = ALBW_AS_F32(piVar5[0xb]);
              }
              else {
                fVar19 = ALBW_AS_F32(piVar5[0x1a]) / fVar19;
                local_1bc = *pfVar6 + fVar21 * fVar19;
                local_1b8 = ALBW_AS_F32(piVar5[10]) + fVar23 * fVar19;
                local_1b4 = ALBW_AS_F32(piVar5[0xb]) + fVar24 * fVar19;
              }
              fVar23 = ALBW_AS_F32(piVar5[0x14]) * ALBW_AS_F32(piVar5[0xd]) -
                       ALBW_AS_F32(piVar5[0x13]) * ALBW_AS_F32(piVar5[0xe]);
              fVar24 = ALBW_AS_F32(piVar5[0x12]) * ALBW_AS_F32(piVar5[0xe]) -
                       ALBW_AS_F32(piVar5[0x14]) * ALBW_AS_F32(piVar5[0xc]);
              fVar21 = ALBW_AS_F32(piVar5[0x13]) * ALBW_AS_F32(piVar5[0xc]) -
                       ALBW_AS_F32(piVar5[0x12]) * ALBW_AS_F32(piVar5[0xd]);
              fVar19 = fVar23 * ALBW_AS_F32(piVar5[0x15]) + fVar24 * ALBW_AS_F32(piVar5[0x16]) +
                       fVar21 * ALBW_AS_F32(piVar5[0x17]);
              if (fVar19 <= ALBW_AS_F32(pppppppfVar35)) {
                local_1b0 = *pfVar6;
                local_1ac = ALBW_AS_F32(piVar5[10]);
                local_1a8 = ALBW_AS_F32(piVar5[0xb]);
              }
              else {
                fVar19 = ALBW_AS_F32(piVar5[0x1a]) / fVar19;
                local_1b0 = *pfVar6 + fVar23 * fVar19;
                local_1ac = ALBW_AS_F32(piVar5[10]) + fVar24 * fVar19;
                local_1a8 = ALBW_AS_F32(piVar5[0xb]) + fVar21 * fVar19;
              }
              func_00115C70(&local_15c,&local_1c8,(float *)(param_3 + 1));
              iVar9 = 0;
              pppppppfVar27 =
                   (float *******)
                   CF_FBITS((*pfVar12 * local_15c + pfVar12[1] * ALBW_AS_F32(local_158) +
                   pfVar12[2] * ALBW_AS_F32(local_154)));
              pppppppfVar30 = pppppppfVar27;
              do {
                pppppppfVar17 = pppppppfVar30;
                pppppppfVar30 = pppppppfVar17;
                if (iVar9 != 2) {
                  func_00115C70((float *)&local_45c,&local_1c8 + (iVar9 + 1) * 3,
                                (float *)(param_3 + 1));
                  pppppppfVar17 =
                       (float *******)
                       CF_FBITS((*pfVar12 * ALBW_AS_F32(local_45c) + pfVar12[1] * ALBW_AS_F32(local_458) +
                       pfVar12[2] * ALBW_AS_F32(local_454)));
                }
                fVar19 = ALBW_AS_F32(uVar31);
                bVar14 = ALBW_AS_F32(pppppppfVar27) == fVar19;
                bVar15 = fVar19 <= ALBW_AS_F32(pppppppfVar27);
                if (!bVar15 || bVar14) {
                  bVar14 = ALBW_AS_F32(pppppppfVar17) == fVar19;
                  bVar15 = fVar19 <= ALBW_AS_F32(pppppppfVar17);
                }
                if (bVar15 && !bVar14) goto LAB_0064e020;
                iVar9 = iVar9 + 1;
                pppppppfVar27 = pppppppfVar17;
              } while (iVar9 < 3);
            }
            else if (DAT_0064d3d4 < (int)local_1f8[1]) {
              func_00115D70((float *)&local_1dc,pfVar12,ALBW_AS_F32(((ulonglong)uVar39 >> 0x20)));
              local_180 = ALBW_AS_F32(piVar5[9]);
              local_17c = piVar5[10];
              local_178 = piVar5[0xb];
              pfVar6 = (float *)(piVar5 + 9);
              fVar19 = ALBW_AS_F32(piVar5[0xe]) * ALBW_AS_F32(piVar5[0x10]) -
                       ALBW_AS_F32(piVar5[0xd]) * ALBW_AS_F32(piVar5[0x11]);
              fVar21 = ALBW_AS_F32(piVar5[0xc]) * ALBW_AS_F32(piVar5[0x11]) -
                       ALBW_AS_F32(piVar5[0xe]) * ALBW_AS_F32(piVar5[0xf]);
              fVar23 = ALBW_AS_F32(piVar5[0xd]) * ALBW_AS_F32(piVar5[0xf]) -
                       ALBW_AS_F32(piVar5[0xc]) * ALBW_AS_F32(piVar5[0x10]);
              fVar24 = fVar19 * ALBW_AS_F32(piVar5[0x15]) + fVar21 * ALBW_AS_F32(piVar5[0x16]) +
                       fVar23 * ALBW_AS_F32(piVar5[0x17]);
              if (fVar24 <= ALBW_AS_F32(pppppppfVar35)) {
                local_174 = *pfVar6;
                local_170 = ALBW_AS_F32(piVar5[10]);
                local_16c = ALBW_AS_F32(piVar5[0xb]);
              }
              else {
                fVar24 = ALBW_AS_F32(piVar5[0x1a]) / fVar24;
                local_174 = *pfVar6 + fVar19 * fVar24;
                local_170 = ALBW_AS_F32(piVar5[10]) + fVar21 * fVar24;
                local_16c = ALBW_AS_F32(piVar5[0xb]) + fVar23 * fVar24;
              }
              fVar21 = ALBW_AS_F32(piVar5[0x14]) * ALBW_AS_F32(piVar5[0xd]) -
                       ALBW_AS_F32(piVar5[0x13]) * ALBW_AS_F32(piVar5[0xe]);
              fVar23 = ALBW_AS_F32(piVar5[0x12]) * ALBW_AS_F32(piVar5[0xe]) -
                       ALBW_AS_F32(piVar5[0x14]) * ALBW_AS_F32(piVar5[0xc]);
              fVar24 = ALBW_AS_F32(piVar5[0x13]) * ALBW_AS_F32(piVar5[0xc]) -
                       ALBW_AS_F32(piVar5[0x12]) * ALBW_AS_F32(piVar5[0xd]);
              fVar19 = fVar21 * ALBW_AS_F32(piVar5[0x15]) + fVar23 * ALBW_AS_F32(piVar5[0x16]) +
                       fVar24 * ALBW_AS_F32(piVar5[0x17]);
              if (fVar19 <= ALBW_AS_F32(pppppppfVar35)) {
                local_168 = *pfVar6;
                local_164 = ALBW_AS_F32(piVar5[10]);
                local_160 = ALBW_AS_F32(piVar5[0xb]);
              }
              else {
                fVar19 = ALBW_AS_F32(piVar5[0x1a]) / fVar19;
                local_168 = *pfVar6 + fVar21 * fVar19;
                local_164 = ALBW_AS_F32(piVar5[10]) + fVar23 * fVar19;
                local_160 = ALBW_AS_F32(piVar5[0xb]) + fVar24 * fVar19;
              }
              pppppppfVar27 = local_1d4;
              pppppppfVar30 = local_1d8;
              pppppppfVar33 = local_1dc;
              pppppppfVar17 = pppppppfVar35;
              func_00115C70(&local_15c,&local_180,(float *)(param_3 + 1));
              iVar9 = 0;
              pppppppfVar29 =
                   (float *******)
                   CF_FBITS((ALBW_AS_F32(pppppppfVar33) * local_15c + ALBW_AS_F32(pppppppfVar30) * ALBW_AS_F32(local_158) +
                   ALBW_AS_F32(pppppppfVar27) * ALBW_AS_F32(local_154)));
              uVar32 = CONCAT44(pppppppfVar17,pppppppfVar29);
              do {
                if (iVar9 == 2) {
                  pppppppfVar17 = (float *******)uVar32;
                }
                else {
                  func_00115C70(&local_15c,&local_180 + (iVar9 + 1) * 3,(float *)(param_3 + 1));
                  pppppppfVar17 =
                       (float *******)
                       CF_FBITS((ALBW_AS_F32(pppppppfVar33) * local_15c + ALBW_AS_F32(pppppppfVar30) * ALBW_AS_F32(local_158) +
                       ALBW_AS_F32(pppppppfVar27) * ALBW_AS_F32(local_154)));
                }
                fVar19 = ALBW_AS_F32(((ulonglong)uVar32 >> 0x20));
                bVar14 = ALBW_AS_F32(pppppppfVar29) == fVar19;
                bVar15 = fVar19 <= ALBW_AS_F32(pppppppfVar29);
                if (!bVar15 || bVar14) {
                  bVar14 = ALBW_AS_F32(pppppppfVar17) == fVar19;
                  bVar15 = fVar19 <= ALBW_AS_F32(pppppppfVar17);
                }
                if (bVar15 && !bVar14) goto LAB_0064e020;
                iVar9 = iVar9 + 1;
                pppppppfVar29 = pppppppfVar17;
              } while (iVar9 < 3);
            }
            else {
LAB_0064e020:
              puVar8 = local_434;
              if ((int)local_440 < iStack_43c) {
                if (local_434 != (undefined4 *)0x0) {
                  puVar7 = (undefined4 *)*local_434;
                  *local_434 = 0;
                  local_434[1] = 0;
                  local_434[2] = 0;
                  local_434 = puVar7;
                }
                if ((int)local_440 < iStack_43c) {
                  *(undefined4 **)(local_438 + local_440 * 4) = puVar8;
                  local_440 = local_440 + 1;
                }
              }
              else {
                puVar8 = (undefined4 *)0x0;
              }
              *puVar8 = (undefined4)(uintptr_t)(piVar5);
              iVar9 = DAT_0064e80c;
              puVar8[1] = (undefined4)(uintptr_t)(local_1f8[1]);
              if (fVar16 <= ALBW_AS_F32(pppppppfVar35)) {
                fVar16 = -fVar16;
              }
              puVar8[2] = ALBW_AS_U32(fVar16);
              pppppppfVar17 = local_1f8[1];
              if ((int)ALBW_AS_U32(fVar16) < iVar9) {
                puVar8[2] = (undefined4)(uintptr_t)(pppppppfVar35);
              }
            }
          }
        }
        piVar5 = (int *)(*(int *)((int)piVar5 + iVar2 + 4) - iVar2);
      } while ((float *******)piVar5 != local_1e0);
    }
    if (local_440 != 0) {
      piVar5 = (int *)param_2[0xb];
      if (piVar5 == (int *)0x0) {
        puVar13 = (uint *)param_2[9];
        if (puVar13 != (uint *)0x0) {
          if ((uint)param_3[0xd] < *puVar13) {
            uVar4 = puVar13[2] + param_3[0xd] * 0x9c;
          }
          else {
            uVar4 = puVar13[2];
          }
          *(float ********)(uVar4 + 0x30) = local_18c;
          *(float ********)(uVar4 + 0x34) = local_188;
          *(float ********)(uVar4 + 0x38) = local_184;
          *(float ********)(uVar4 + 0x74) = pppppppfVar36;
        }
      }
      else {
        iVar2 = *piVar5;
        if (iVar2 < piVar5[1]) {
          *piVar5 = iVar2 + 1;
          puVar8 = (undefined4 *)(piVar5[2] + iVar2 * 0x10);
        }
        else {
          puVar8 = (undefined4 *)0x0;
        }
        *puVar8 = (undefined4)(uintptr_t)(pppppppfVar34);
        puVar8[1] = param_3[7];
        puVar8[2] = param_3[8];
        puVar8[3] = param_3[9];
      }
      func_0048C258((int *)&local_440,DAT_0064e810);
      local_130 = (float *******)param_3[10];
      uVar4 = 0;
      local_128 = (float *******)param_3[0xc];
      local_12c = pppppppfVar36;
      if (0 < (int)local_440) {
        do {
          iVar2 = param_3[0xc];
          if (uVar4 < local_440) {
            puVar8 = *(undefined4 **)(local_438 + uVar4 * 4);
          }
          else {
            puVar8 = (undefined4 *)0x0;
          }
          pppppppfVar11 = (float *******)*puVar8;
          piVar18 = (int *)(*(int *)(iVar2 + 0xc) + (int)pppppppfVar11);
          piVar5 = piVar18 + 1;
          if (*piVar5 == 0) {
            piVar18 = (int *)*piVar18;
          }
          if (*piVar5 != 0 || piVar18 != (int *)0x0) {
            if ((local_120 == (float *******)0x0) || ((float *******)*param_3 != pppppppfVar11)) {
              local_13c = (float *******)pppppppfVar11[0xc];
              local_138 = (float *******)pppppppfVar11[0xd];
              local_134 = (float *******)pppppppfVar11[0xe];
              local_158 = pppppppfVar11;
              func_00115C70((float *)&local_110,(float *)&local_18c,(float *)(pppppppfVar11 + 9));
              local_1dc = local_110;
              local_1d8 = local_10c;
              local_1d4 = local_108;
              func_00115D70((float *)&local_104,(float *)&local_13c,
                            ALBW_AS_F32(local_13c) * ALBW_AS_F32(local_110) +
                            ALBW_AS_F32(local_138) * ALBW_AS_F32(local_10c) +
                            ALBW_AS_F32(local_134) * ALBW_AS_F32(local_108));
              local_1f8[2] = local_104;
              local_1f8[3] = local_100;
              local_1e8 = local_fc;
              func_00115C70((float *)&local_f8,(float *)&local_18c,(float *)(local_1f8 + 2));
              local_154 = local_f8;
              local_150 = local_f4;
              local_14c = local_f0;
              func_00115E10((float *)&local_148,(float *)param_3[10],(float *)&local_13c);
              func_00115DC8((float *)&local_148);
              func_00115C54((float *)&local_11c,(float *)&local_154,(float *)&local_148);
              pfVar12 = (float *)(param_3 + 1);
              local_1dc = local_11c;
              local_1d8 = local_118;
              local_1d4 = local_114;
              func_00115C70((float *)&local_45c,(float *)&local_1dc,pfVar12);
              pppppppfVar17 =
                   (float *******)
                   CF_FBITS((ALBW_AS_F32(local_134) * ALBW_AS_F32(local_45c) - ALBW_AS_F32(local_13c) * ALBW_AS_F32(local_454)));
              if (ALBW_AS_F32(pppppppfVar35) < ALBW_AS_F32(pppppppfVar17)) {
                if (param_2 != (int *)0x0) {
                  pfVar12 = (float *)param_2[9];
                }
                if (param_2 != (int *)0x0 && pfVar12 != (float *)0x0) {
                  fVar16 = *pfVar12;
                  fVar19 = pfVar12[1];
                  fVar28 = fVar19;
                  if ((int)ALBW_AS_U32(fVar16) < (int)ALBW_AS_U32(fVar19)) {
                    fVar28 = ALBW_AS_F32(((int)ALBW_AS_U32(fVar16) + 1));
                  }
                  uVar1 = *(undefined1 *)((int)ALBW_AS_U32(pfVar12[2]) + (int)ALBW_AS_U32(fVar16) * 0x9c + -0xc);
                  if ((int)ALBW_AS_U32(fVar16) < (int)ALBW_AS_U32(fVar19)) {
                    *pfVar12 = fVar28;
                    pfVar12 = (float *)((int)ALBW_AS_U32(pfVar12[2]) + (int)ALBW_AS_U32(fVar16) * 0x9c);
                  }
                  else {
                    pfVar12 = (float *)0x0;
                  }
                  pfVar12[9] = ALBW_AS_F32(local_154);
                  pfVar12[10] = ALBW_AS_F32(local_150);
                  pfVar12[0xb] = ALBW_AS_F32(local_14c);
                  pfVar12[0x1c] = ALBW_AS_F32(pppppppfVar36);
                  *(undefined1 *)(pfVar12 + 0x24) = uVar1;
                  *pfVar12 = ALBW_AS_F32(local_148);
                  pfVar12[1] = local_144;
                  pfVar12[2] = ALBW_AS_F32(local_140);
                  pfVar12[6] = ALBW_AS_F32(local_13c);
                  pfVar12[7] = ALBW_AS_F32(local_138);
                  pfVar12[8] = ALBW_AS_F32(local_134);
                  func_004A17A4(pfVar12);
                  local_124 = (float *******)(*(int *)param_2[9] + -1);
                }
                uVar10 = func_0064CB28(local_30,param_2,(int *)&local_158);
                pppppppfVar34 = local_128;
                if (uVar10 < 2) {
                  return 0;
                }
                puVar13 = extraout_r1;
                if (param_2 != (int *)0x0) {
                  puVar13 = (uint *)param_2[9];
                }
                if ((param_2 != (int *)0x0 && puVar13 != (uint *)0x0) &&
                   (*puVar13 - 1 <= puVar13[1])) {
                  *puVar13 = *puVar13 - 1;
                }
                if (uVar10 == 2) {
                  piVar5 = (int *)((int)local_128[3] + (int)pppppppfVar11);
                  iVar2 = piVar5[1];
                  bVar14 = iVar2 == 0;
                  if (bVar14) {
                    iVar2 = *piVar5;
                  }
                  if (!bVar14 || iVar2 != 0) {
                    func_0010F1F8(piVar5,ALBW_AS_F32(pppppppfVar17));
                    pppppppfVar34[2] = (float ******)((int)pppppppfVar34[2] + -1);
                  }
                }
                local_120 = (float *******)0x0;
              }
            }
            else {
              piVar5 = (int *)(*(int *)(iVar2 + 0xc) + *param_3);
              iVar9 = piVar5[1];
              bVar14 = iVar9 == 0;
              if (bVar14) {
                iVar9 = *piVar5;
              }
              if (!bVar14 || iVar9 != 0) {
                func_0010F1F8(piVar5,ALBW_AS_F32(pppppppfVar17));
                *(int *)(iVar2 + 8) = *(int *)(iVar2 + 8) + -1;
              }
            }
          }
          uVar4 = uVar4 + 1;
        } while ((int)uVar4 < (int)local_440);
      }
    }
  }
  else {
    bVar14 = (int)ALBW_AS_U32(local_15c) < 0;
    bVar15 = local_15c != 0.0;
    if (bVar15) {
      bVar14 = ALBW_AS_F32(pppppppfVar34) < ALBW_AS_F32(local_148);
      pppppppfVar17 = local_148;
    }
    pppppppfVar35 = local_148;
    if (((bVar15 && ALBW_AS_F32(pppppppfVar34) != ALBW_AS_F32(local_148)) &&
         bVar14 == (bVar15 && (NAN(ALBW_AS_F32(pppppppfVar34)) || NAN(ALBW_AS_F32(local_148))))) &&
       ((((local_1d8 == (float *******)0x0 || (ALBW_AS_F32(pppppppfVar17) != ALBW_AS_F32(pppppppfVar36))) ||
         (pppppppfVar35 = pppppppfVar34, param_2[10] < 2)) &&
        ((pppppppfVar34 = pppppppfVar17, pppppppfVar35 = local_148, (char)local_1e0[0x31] == '\0' &&
         (ALBW_AS_F32(local_30[0x1d]) < ALBW_AS_F32(param_3[0xb]) - ALBW_AS_F32(pppppppfVar17))))))) {
      local_120 = (float *******)0x1;
    }
    local_148 = pppppppfVar35;
    uVar10 = 0;
    puVar13 = (uint *)local_30[1];
    uVar4 = *puVar13;
    fVar16 = DAT_0064d3e4;
    fVar19 = DAT_0064d3e0;
    pppppppfVar35 = pppppppfVar34;
    if (0 < (int)uVar4) {
      do {
        if (uVar10 < uVar4) {
          iVar9 = *(int *)(puVar13[2] + uVar10 * 4);
        }
        else {
          iVar9 = 0;
        }
        pppppppfVar17 = (float *******)(iVar9 + 8);
        fVar21 = *(float *)(iVar9 + 0x30);
        fVar23 = *(float *)(iVar9 + 0x34);
        fVar24 = *(float *)(iVar9 + 0x38);
        fVar25 = local_204 * fVar21 + local_200 * fVar23 + local_1fc * fVar24;
        if ((fVar25 <= ALBW_AS_F32(pppppppfVar36)) && (iVar2 <= (int)ALBW_AS_U32(-fVar25))) {
          fVar25 = local_204 * fVar21 + local_200 * fVar23 + local_1fc * fVar24;
          local_45c = pppppppfVar17;
          if (((fVar25 < fVar19) || (fVar16 < fVar25)) &&
             ((pppppppfVar17 =
                    (float *******)
                    CF_FBITS((((fVar21 * *(float *)(iVar9 + 0x24) + fVar23 * *(float *)(iVar9 + 0x28) +
                      fVar24 * *(float *)(iVar9 + 0x2c)) -
                     (fVar21 * ALBW_AS_F32(local_210) + fVar23 * ALBW_AS_F32(local_20c) +
                     fVar24 * ALBW_AS_F32(local_208))) / fVar25)),
              (int)ALBW_AS_U32((ALBW_AS_F32(pppppppfVar17) - ALBW_AS_F32(pppppppfVar35))) <= iVar2 &&
              (ALBW_AS_F32(pppppppfVar36) <= ALBW_AS_F32(pppppppfVar17))))) {
            local_1e8 = (float *******)&local_210;
            func_00115D70((float *)&local_158,&local_204,ALBW_AS_F32(pppppppfVar17));
            local_1d8 = local_158;
            local_1d4 = local_154;
            local_1d0 = local_150;
            func_00115C54((float *)&local_130,(float *)local_1e8,(float *)&local_1d8);
            local_1f8[0] = local_130;
            local_1f8[1] = local_12c;
            local_1f8[2] = local_128;
            func_00115C70((float *)&local_11c,(float *)local_1f8,(float *)(iVar9 + 0x24));
            if (((int)ALBW_AS_U32((ALBW_AS_F32(local_11c) * ALBW_AS_F32(local_45c[0xd]) +
                       ALBW_AS_F32(local_118) * ALBW_AS_F32(local_45c[0xe]) +
                      ALBW_AS_F32(local_114) * ALBW_AS_F32(local_45c[0xf]))) <= iVar2) &&
               ((((int)ALBW_AS_U32((ALBW_AS_F32(local_11c) * ALBW_AS_F32(local_45c[0x10]) +
                        ALBW_AS_F32(local_118) * ALBW_AS_F32(local_45c[0x11]) +
                       ALBW_AS_F32(local_114) * ALBW_AS_F32(local_45c[0x12]))) <= iVar2 &&
                 (ALBW_AS_F32(local_11c) * ALBW_AS_F32(local_45c[0x13]) +
                  ALBW_AS_F32(local_118) * ALBW_AS_F32(local_45c[0x14]) +
                  ALBW_AS_F32(local_114) * ALBW_AS_F32(local_45c[0x15]) <= ALBW_AS_F32(local_45c[0x18]) + fVar16)) &&
                (pppppppfVar17 != (float *******)0xff7fffff)))) {
              local_148 = pppppppfVar17;
              if (((uVar10 < *puVar13) && (*(int *)(puVar13[2] + uVar10 * 4) != 0)) &&
                 (((char)local_1e0[0x31] != '\0' ||
                  (ALBW_AS_F32(param_3[0xb]) - ALBW_AS_F32(pppppppfVar17) <= ALBW_AS_F32(local_30[0x1d]))))) {
                local_1dc = (float *******)0x1;
                pppppppfVar34 = pppppppfVar17;
              }
              break;
            }
          }
        }
        uVar4 = *puVar13;
        uVar10 = uVar10 + 1;
      } while ((int)uVar10 < (int)uVar4);
    }
    pppppppfVar35 = pppppppfVar36;
    func_00115D70((float *)&local_45c,&local_21c,ALBW_AS_F32(pppppppfVar34));
    local_13c = local_45c;
    local_138 = local_458;
    local_134 = local_454;
    func_00115C54((float *)&local_18c,(float *)&local_228,(float *)&local_13c);
    pppppppfVar36 = (float *******)CF_FBITS((ALBW_AS_F32(param_3[0xb]) - ALBW_AS_F32(pppppppfVar34)));
    pppppppfVar17 = (float *******)CF_FBITS((ALBW_AS_F32(pppppppfVar34) - ALBW_AS_F32(param_3[0xb])));
    bVar14 = DAT_0064d800 == ALBW_AS_F32(pppppppfVar17);
    bVar15 = ALBW_AS_F32(pppppppfVar17) <= DAT_0064d800;
    if (!bVar15 || bVar14) {
      bVar14 = ALBW_AS_F32(pppppppfVar17) == DAT_0064d7fc;
      bVar15 = DAT_0064d7fc <= ALBW_AS_F32(pppppppfVar17);
    }
    if (((uint)local_1dc & ~(uint)(!bVar15 || bVar14)) == 0) {
      if ((!bVar15 || bVar14) != 0) {
        func_001FE680((undefined4 *)(&local_100));
        piVar5 = local_30;
        local_100 = pppppppfVar35;
        if (local_1dc != (float *******)0x0) {
          local_100 = (float *******)CF_FBITS((ALBW_AS_F32(param_3[0xb]) - ALBW_AS_F32(pppppppfVar34)));
        }
        local_e0 = (float *******)*param_3;
        local_fc = local_18c;
        local_f8 = local_188;
        local_f4 = local_184;
        local_f0 = (float *******)param_3[4];
        local_ec = ALBW_AS_F32(param_3[5]);
        local_e8 = (int *)param_3[6];
        local_dc = (float *******)param_2[9];
        local_e4 = (float ******)param_2[7];
        func_001FE680((undefined4 *)(&local_158));
        local_134 = local_dc;
        local_13c = (float *******)local_e4;
        func_00115E10((float *)&local_110,(float *)(local_e0 + 0xc),(float *)&local_f0);
        piVar18 = (int *)CF_FBITS(func_00115DC8((float *)&local_110));
        pppppppfVar36 = local_e0;
        func_0049F5FC(piVar5 + 6);
        uVar4 = 0;
        while( true ) {
          fVar16 = ALBW_AS_F32(uVar39);
          fVar28 = ALBW_AS_F32(((ulonglong)uVar37 >> 0x20));
          uVar10 = *(uint *)*piVar5;
          if ((int)uVar10 <= (int)uVar4) break;
          if (uVar4 < uVar10) {
            iVar2 = *(int *)(((uint *)*piVar5)[2] + uVar4 * 4);
          }
          else {
            iVar2 = 0;
          }
          func_0010F1DC(piVar5 + 6,(int *)(piVar5[9] + iVar2));
          uVar4 = uVar4 + 1;
          piVar5[8] = piVar5[8] + 1;
        }
        local_d0 = pppppppfVar36;
        local_cc = local_fc;
        local_a0[0] = (float ******)(piVar5 + 6);
        local_c8 = local_f8;
        local_c4 = local_f4;
        local_c0 = local_110;
        local_bc = local_10c;
        local_b8 = local_108;
        local_b4 = pppppppfVar36[0xc];
        local_b0 = pppppppfVar36[0xd];
        local_ac = (float *******)pppppppfVar36[0xe];
        local_a8 = (float ******)(piVar5 + 0x12);
        local_a4 = ALBW_AS_F32(piVar5[0x1c]);
        if (local_134 == (float *******)0x0) {
          local_a0[1] = (float ******)0xffffffff;
        }
        else {
          local_a0[1] = (float ******)((int)*local_134 + -1);
        }
        uVar4 = func_00650A24((int)piVar5,(float *)&local_158,(float *)&local_d0);
        pppppppfVar36 = local_138;
        if (uVar4 < 2) {
          if (local_13c != (float *******)0x0) {
            *local_13c = (float ******)local_154;
            local_13c[1] = (float ******)local_150;
            local_13c[2] = (float ******)local_14c;
            piVar5[0xb] = (int)local_138;
          }
          if (local_e4 != (float ******)0x0) {
            *local_e4 = (float *****)local_154;
            local_e4[1] = (float *****)local_150;
            local_e4[2] = (float *****)local_14c;
            piVar5[0xb] = (int)local_138;
          }
LAB_0064d944:
          param_2[4] = (int)local_f0;
          param_2[5] = (int)ALBW_AS_U32(local_ec);
          param_2[6] = (int)local_e8;
          param_2[1] = (int)local_fc;
          param_2[2] = (int)local_f8;
          param_2[3] = (int)local_f4;
          *param_2 = (int)local_100;
          param_2[8] = (int)local_e0;
          puVar13 = (uint *)param_2[9];
          if (puVar13 != (uint *)0x0) {
            uVar4 = puVar13[2];
            if ((uint)param_3[0xd] < *puVar13) {
              uVar4 = uVar4 + param_3[0xd] * 0x9c;
            }
            *(int *)(uVar4 + 0x30) = param_2[1];
            *(int *)(uVar4 + 0x34) = param_2[2];
            *(int *)(uVar4 + 0x38) = param_2[3];
            *(int *)(uVar4 + 0x74) = *param_2;
          }
          return 0;
        }
        if (local_138 != (float *******)0x0) {
          local_98[0] = local_138 + 0xf;
          local_98[1] = local_138 + 0x12;
          local_98[2] = local_138 + 0x15;
          pppppppfVar11 = local_158;
          func_00115C70((float *)local_1f8,(float *)&local_154,(float *)(local_138 + 9));
          local_11c = local_1f8[0];
          local_118 = local_1f8[1];
          local_114 = local_1f8[2];
          iVar2 = -1;
          iVar9 = 0;
          do {
            ppppppfVar3 = (float ******)local_98[iVar9];
            ppppppfVar26 = (float ******)ppppppfVar3[1];
            if (EDGE_DIR_IN_RANGE(ALBW_AS_F32(*ppppppfVar3) * ALBW_AS_F32(local_f0) + ALBW_AS_F32(ppppppfVar26) * local_ec
                            + ALBW_AS_F32(ppppppfVar3[2]) * ALBW_AS_F32(local_e8))) {
              fVar19 = ALBW_AS_F32(local_1f8[1]) * ALBW_AS_F32(ppppppfVar26);
              if (iVar9 == 2) {
                ppppppfVar26 = pppppppfVar36[0x1a];
              }
              fVar19 = ALBW_AS_F32(local_1f8[0]) * ALBW_AS_F32(*ppppppfVar3) + fVar19 +
                       ALBW_AS_F32(local_1f8[2]) * ALBW_AS_F32(ppppppfVar3[2]);
              if (iVar9 == 2) {
                fVar19 = fVar19 - ALBW_AS_F32(ppppppfVar26);
              }
              if (fVar19 < ALBW_AS_F32(pppppppfVar35)) {
                fVar19 = -fVar19;
              }
              if (((int)ALBW_AS_U32(fVar19) < DAT_0064d3d4) && (fVar19 < fVar28)) {
                iVar2 = iVar9;
                fVar28 = fVar19;
              }
            }
            iVar9 = iVar9 + 1;
          } while (iVar9 < 3);
          piVar18 = local_e8;
          if (-1 < iVar2) {
            func_00115E10((float *)&local_11c,(float *)&local_f0,(float *)local_98[iVar2]);
            func_00115E10((float *)&local_128,(float *)&local_11c,(float *)local_98[iVar2]);
            func_00115DC8((float *)&local_128);
            piVar18 = (int *)CF_FBITS((ALBW_AS_F32(local_128) * ALBW_AS_F32(piVar5[0x15]) +
                              ALBW_AS_F32(local_124) * ALBW_AS_F32(piVar5[0x16]) +
                             ALBW_AS_F32(local_120) * ALBW_AS_F32(piVar5[0x17])));
            if (ALBW_AS_F32(pppppppfVar35) < ALBW_AS_F32(piVar18)) {
              piVar18 = (int *)CF_FBITS(((ALBW_AS_F32(pppppppfVar11) / ALBW_AS_F32(piVar18)) *
                                (ALBW_AS_F32(pppppppfVar11) / ALBW_AS_F32(piVar18)) -
                               ALBW_AS_F32(pppppppfVar11) * ALBW_AS_F32(pppppppfVar11)));
              fVar28 = SQRT(ALBW_AS_F32(piVar18));
              if (fVar28 <= ALBW_AS_F32(piVar5[0x1b]) * fVar16) {
                func_001FE680((undefined4 *)(local_1f8));
                local_1d4 = local_dc;
                local_1d0 = local_d8;
                local_1dc = (float *******)local_e4;
                local_d0 = local_e0;
                local_cc = local_fc;
                local_c8 = local_f8;
                local_c4 = local_f4;
                local_c0 = (float *******)CF_FBITS(-ALBW_AS_F32(local_f0));
                local_b8 = (float *******)CF_FBITS(-ALBW_AS_F32(local_e8));
                local_bc = (float *******)CF_FBITS(-local_ec);
                local_b4 = local_e0[0xc];
                local_b0 = local_e0[0xd];
                local_ac = (float *******)local_e0[0xe];
                local_a0[0] = (float ******)(piVar5 + 2);
                local_a8 = DAT_0064e800;
                if (local_dc == (float *******)0x0) {
                  local_a0[1] = (float ******)0xffffffff;
                }
                else {
                  local_a0[1] = (float ******)((int)*local_dc + -1);
                }
                local_a4 = fVar28;
                func_0063ADF4(piVar5,(undefined4 *)(local_1f8),(int *)&local_d0);
                local_e0 = local_1d8;
                local_fc = local_1f8[1];
                local_f8 = local_1f8[2];
                local_f4 = local_1f8[3];
                local_f0 = (float *******)CF_FBITS(-ALBW_AS_F32(local_1e8));
                local_ec = -ALBW_AS_F32(local_1e4);
                local_e8 = (int *)CF_FBITS(-ALBW_AS_F32(local_1e0));
                local_100 = (float *******)CF_FBITS((fVar28 - ALBW_AS_F32(local_1f8[0])));
                goto LAB_0064d944;
              }
            }
          }
        }
        iVar9 = param_3[0xc];
        piVar5 = (int *)(*param_3 + *(int *)(iVar9 + 0xc));
        iVar2 = piVar5[1];
        bVar14 = iVar2 == 0;
        if (bVar14) {
          iVar2 = *piVar5;
        }
        if (bVar14 && iVar2 == 0) {
          return 2;
        }
        goto code_r0x0064da00;
      }
      pppppppfVar36 = pppppppfVar34;
      if (local_120 == (float *******)0x0) goto LAB_0064da24;
      goto LAB_0064da44;
    }
  }
  func_001FE680((undefined4 *)(&local_158));
  piVar5 = local_30;
  local_138 = (float *******)*param_3;
  local_154 = local_18c;
  local_150 = local_188;
  local_14c = local_184;
  local_148 = (float *******)param_3[4];
  local_144 = ALBW_AS_F32(param_3[5]);
  local_140 = (int *)param_3[6];
  local_134 = (float *******)param_2[9];
  local_13c = (float *******)param_2[7];
  local_158 = pppppppfVar36;
  func_001FE680((undefined4 *)(&local_d0));
  local_ac = local_134;
  local_b4 = (float ******)local_13c;
  func_00115E10((float *)&local_128,(float *)(local_138 + 0xc),(float *)&local_148);
  piVar18 = (int *)CF_FBITS(func_00115DC8((float *)&local_128));
  pppppppfVar36 = local_138;
  func_0049F5FC(piVar5 + 6);
  uVar4 = 0;
  while( true ) {
    fVar16 = ALBW_AS_F32(uVar39);
    fVar28 = ALBW_AS_F32(((ulonglong)uVar37 >> 0x20));
    uVar10 = *(uint *)*piVar5;
    if ((int)uVar10 <= (int)uVar4) break;
    if (uVar4 < uVar10) {
      iVar2 = *(int *)(((uint *)*piVar5)[2] + uVar4 * 4);
    }
    else {
      iVar2 = 0;
    }
    func_0010F1DC(piVar5 + 6,(int *)(piVar5[9] + iVar2));
    uVar4 = uVar4 + 1;
    piVar5[8] = piVar5[8] + 1;
  }
  local_118 = pppppppfVar36;
  local_e8 = piVar5 + 6;
  local_114 = local_154;
  local_110 = local_150;
  local_10c = local_14c;
  local_108 = local_128;
  local_104 = local_124;
  local_100 = local_120;
  local_fc = (float *******)pppppppfVar36[0xc];
  local_f8 = (float *******)pppppppfVar36[0xd];
  local_f4 = (float *******)pppppppfVar36[0xe];
  local_f0 = (float *******)(piVar5 + 0x12);
  local_ec = ALBW_AS_F32(piVar5[0x1c]);
  if (local_ac == (float *******)0x0) {
    local_e4 = (float ******)0xffffffff;
  }
  else {
    local_e4 = (float ******)((int)*local_ac + -1);
  }
  uVar4 = func_00650A24((int)piVar5,(float *)&local_d0,(float *)&local_118);
  ppppppfVar3 = local_b0;
  if (1 < uVar4) {
    if (local_b0 != (float ******)0x0) {
      local_a0[0] = local_b0 + 0xf;
      local_a0[1] = local_b0 + 0x12;
      local_98[0] = (float *******)(local_b0 + 0x15);
      pppppppfVar36 = local_d0;
      func_00115C70((float *)local_1f8,(float *)&local_cc,(float *)(local_b0 + 9));
      local_e0 = local_1f8[0];
      local_dc = local_1f8[1];
      local_d8 = local_1f8[2];
      iVar2 = -1;
      iVar9 = 0;
      do {
        pppppfVar20 = (float *****)local_a0[iVar9];
        pppppfVar22 = (float *****)pppppfVar20[1];
        if (EDGE_DIR_IN_RANGE(ALBW_AS_F32(*pppppfVar20) * ALBW_AS_F32(local_148) + ALBW_AS_F32(pppppfVar22) * local_144 +
                        ALBW_AS_F32(pppppfVar20[2]) * ALBW_AS_F32(local_140))) {
          fVar19 = ALBW_AS_F32(local_1f8[1]) * ALBW_AS_F32(pppppfVar22);
          if (iVar9 == 2) {
            pppppfVar22 = ppppppfVar3[0x1a];
          }
          fVar19 = ALBW_AS_F32(local_1f8[0]) * ALBW_AS_F32(*pppppfVar20) + fVar19 +
                   ALBW_AS_F32(local_1f8[2]) * ALBW_AS_F32(pppppfVar20[2]);
          if (iVar9 == 2) {
            fVar19 = fVar19 - ALBW_AS_F32(pppppfVar22);
          }
          if (fVar19 < ALBW_AS_F32(pppppppfVar35)) {
            fVar19 = -fVar19;
          }
          if (((int)ALBW_AS_U32(fVar19) < DAT_0064e814) && (fVar19 < fVar28)) {
            iVar2 = iVar9;
            fVar28 = fVar19;
          }
        }
        iVar9 = iVar9 + 1;
      } while (iVar9 < 3);
      piVar18 = local_140;
      if (-1 < iVar2) {
        func_00115E10((float *)&local_e0,(float *)&local_148,(float *)local_a0[iVar2]);
        func_00115E10((float *)&local_458,(float *)&local_e0,(float *)local_a0[iVar2]);
        func_00115DC8((float *)&local_458);
        piVar18 = (int *)CF_FBITS((ALBW_AS_F32(local_458) * ALBW_AS_F32(piVar5[0x15]) +
                          ALBW_AS_F32(local_454) * ALBW_AS_F32(piVar5[0x16]) +
                         ALBW_AS_F32(local_450) * ALBW_AS_F32(piVar5[0x17])));
        if (ALBW_AS_F32(pppppppfVar35) < ALBW_AS_F32(piVar18)) {
          piVar18 = (int *)CF_FBITS(((ALBW_AS_F32(pppppppfVar36) / ALBW_AS_F32(piVar18)) *
                            (ALBW_AS_F32(pppppppfVar36) / ALBW_AS_F32(piVar18)) -
                           ALBW_AS_F32(pppppppfVar36) * ALBW_AS_F32(pppppppfVar36)));
          fVar28 = SQRT(ALBW_AS_F32(piVar18));
          if (fVar28 <= ALBW_AS_F32(piVar5[0x1b]) * fVar16) {
            func_001FE680((undefined4 *)(local_1f8));
            local_1d4 = local_134;
            local_1d0 = local_130;
            local_1dc = local_13c;
            local_118 = local_138;
            local_114 = local_154;
            local_110 = local_150;
            local_10c = local_14c;
            local_108 = (float *******)CF_FBITS(-ALBW_AS_F32(local_148));
            local_104 = (float *******)CF_FBITS(-local_144);
            local_100 = (float *******)CF_FBITS(-ALBW_AS_F32(local_140));
            local_fc = (float *******)local_138[0xc];
            local_f8 = (float *******)local_138[0xd];
            local_f4 = (float *******)local_138[0xe];
            local_e8 = piVar5 + 2;
            local_f0 = (float *******)DAT_0064e800;
            if (local_134 == (float *******)0x0) {
              local_e4 = (float ******)0xffffffff;
            }
            else {
              local_e4 = (float ******)((int)*local_134 + -1);
            }
            local_ec = fVar28;
            func_0063ADF4(piVar5,(undefined4 *)(local_1f8),(int *)&local_118);
            local_138 = local_1d8;
            local_154 = local_1f8[1];
            local_150 = local_1f8[2];
            local_14c = local_1f8[3];
            local_140 = (int *)CF_FBITS(-ALBW_AS_F32(local_1e0));
            local_148 = (float *******)CF_FBITS(-ALBW_AS_F32(local_1e8));
            local_144 = -ALBW_AS_F32(local_1e4);
            local_158 = (float *******)CF_FBITS((fVar28 - ALBW_AS_F32(local_1f8[0])));
            goto LAB_0064e90c;
          }
        }
      }
    }
    iVar9 = param_3[0xc];
    piVar5 = (int *)(*param_3 + *(int *)(iVar9 + 0xc));
    iVar2 = piVar5[1];
    bVar14 = iVar2 == 0;
    if (bVar14) {
      iVar2 = *piVar5;
    }
    if (bVar14 && iVar2 == 0) {
      return 2;
    }
code_r0x0064da00:
    func_0010F1F8(piVar5,ALBW_AS_F32(piVar18));
    *(int *)(iVar9 + 8) = *(int *)(iVar9 + 8) + -1;
    return 2;
  }
  if (local_b4 != (float ******)0x0) {
    *local_b4 = (float *****)local_cc;
    local_b4[1] = (float *****)local_c8;
    local_b4[2] = (float *****)local_c4;
    piVar5[0xb] = (int)local_b0;
  }
  if (local_13c != (float *******)0x0) {
    *local_13c = (float ******)local_cc;
    local_13c[1] = (float ******)local_c8;
    local_13c[2] = (float ******)local_c4;
    piVar5[0xb] = (int)local_b0;
  }
LAB_0064e90c:
  param_2[4] = (int)local_148;
  param_2[5] = (int)ALBW_AS_U32(local_144);
  param_2[6] = (int)local_140;
  param_2[1] = (int)local_154;
  param_2[2] = (int)local_150;
  param_2[3] = (int)local_14c;
  *param_2 = (int)local_158;
  param_2[8] = (int)local_138;
  puVar13 = (uint *)param_2[9];
  if (puVar13 != (uint *)0x0) {
    if ((uint)param_3[0xd] < *puVar13) {
      uVar4 = puVar13[2] + param_3[0xd] * 0x9c;
    }
    else {
      uVar4 = puVar13[2];
    }
    *(int *)(uVar4 + 0x30) = param_2[1];
    *(int *)(uVar4 + 0x34) = param_2[2];
    *(int *)(uVar4 + 0x38) = param_2[3];
    *(int *)(uVar4 + 0x74) = *param_2;
  }
  return 1;
}

