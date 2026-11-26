/* compilefix: USA 0064E9F4 (EU 0064E9CC), Ghidra-derived (build/ghidra_analyzed4).
 * Failed to compile: operand of type 'float' cannot be cast to a pointer type
 * Fixed (each an exact C form of the ARM operation; the rest is the converted Ghidra text):
 *  - (T *)<float expr> -> (T *)CF_FBITS(expr): 32-bit copy of the float (vmov/vstr), never a conversion [46]
 *  - Ghidra NAN(x)/INFINITY -> __builtin_isnan(x) (vcmp unordered) / +inf [1]
 *  - Ghidra -NAN/NAN constant -> the exact words 0xFFFFFFFF/0x7FFFFFFF (mvn in the ARM) [1]
 *  - explicit (T)(uintptr_t) casts at int<->pointer mismatches (identity on the 32-bit ARM) [21]
 *  - explicit casts at pointer-type mismatches (identity on the ARM) [6]
 *  - implicit float<->int conversions (Ghidra COPY between a float and an int-typed variable or
 *    pool word, e.g. `fVar = _DAT_xxx;`, `puVar[3] = fVar;`) made bit copies [1]
 * Confidence: high for the fixes (each class checked against the EU disassembly on sample sites, this function's sites checked);
 * the function body otherwise has the fidelity of the Ghidra output (bare `return;` exits of
 * functions retyped non-void return 0, as the converter does). *
 * 160bh: two edge-direction range tests work on the float BITS of a dot product (0.1 <= dot < 0.9:
 * bits - 0x3DCCCCCD < 0x0199999A, as in 0064CB28); the text converted the dot to an integer
 * (0.3 -> 0), so no edge qualified. Now ALBW_AS_U32 (the vmov the ARM code does). */
/* An edge can be crossed when its direction against the step is between 0.1 and 0.9.
 * The ARM code tests the float BITS: bits(dot) - bits(0.1f) < 0x0199999A (unsigned). */
#define EDGE_DIR_IN_RANGE(dot) ((uint)((int)ALBW_AS_U32(dot) - DAT_0064f6e0) < DAT_0064f6e4)
#include "ghidra_types.h"
#include "../include/ghidra_concat44.h"
#define CF_MATHCONST
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
extern int func_0064CB28(int *param_1,int *param_2,int *param_3);
extern int func_00650A24(int param_1,float *param_2,float *param_3);
extern int func_00688AB0(undefined4 *param_1);
extern undefined4 *DAT_0064eda4;
extern float *DAT_0064eda8;
extern uint DAT_0064edac;
extern float * * * * * *DAT_0064edb0;
extern float DAT_0064edb4;
extern float * * * * * * *DAT_0064edb8;
extern float * * * * * * *DAT_0064edbc;
extern int DAT_0064f2b0;
extern undefined4 DAT_0064f2b4;
extern undefined4 DAT_0064f2b8;
extern float DAT_0064f2bc;
extern float DAT_0064f2c0;
extern float DAT_0064f6d8;
extern float DAT_0064f6dc;
extern int DAT_0064f6e0;
extern uint DAT_0064f6e4;
extern float *DAT_00650720;
extern float * * * * * *DAT_00650724;
extern float * * * * * *DAT_00650728;
extern int DAT_0065072c;
extern undefined *DAT_00650730;
extern int DAT_00650734;

// USA 0064E9F4 <- EU 0064E9CC (Ghidra, non-matching)
// GLOBAL DAT_0064eda4 undefined4 *
// GLOBAL DAT_0064eda8 float *
// GLOBAL DAT_0064edac uint
// GLOBAL DAT_0064edb0 float * * * * * *
// GLOBAL DAT_0064edb4 float
// GLOBAL DAT_0064edb8 float * * * * * * *
// GLOBAL DAT_0064edbc float * * * * * * *
// GLOBAL DAT_0064f2b0 int
// GLOBAL DAT_0064f2b4 undefined4
// GLOBAL DAT_0064f2b8 undefined4
// GLOBAL DAT_0064f2bc float
// GLOBAL DAT_0064f2c0 float
// GLOBAL DAT_0064f6d8 float
// GLOBAL DAT_0064f6dc float
// GLOBAL DAT_0064f6e0 int
// GLOBAL DAT_0064f6e4 uint
// GLOBAL DAT_00650720 float *
// GLOBAL DAT_00650724 float * * * * * *
// GLOBAL DAT_00650728 float * * * * * *
// GLOBAL DAT_0065072c int
// GLOBAL DAT_00650730 undefined *
// GLOBAL DAT_00650734 int

/* WARNING: Type propagation algorithm not settling */

undefined4 func_0064E9F4(int *param_1,undefined4 *param_2,int *param_3)

{
  undefined1 uVar1;
  float ******ppppppfVar2;
  uint uVar3;
  int *piVar4;
  undefined4 *puVar5;
  int iVar6;
  float *pfVar7;
  undefined4 *puVar8;
  int *piVar9;
  uint *extraout_r1;
  uint uVar10;
  float ******ppppppfVar11;
  int iVar12;
  uint uVar13;
  float *pfVar14;
  uint *puVar15;
  float fVar16;
  bool bVar17;
  bool bVar18;
  float fVar19;
  float *******pppppppfVar20;
  float fVar21;
  float *****pppppfVar22;
  float fVar23;
  float *****pppppfVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float ******ppppppfVar28;
  float *******pppppppfVar29;
  float *******fparam_0;
  ulonglong uVar30;
  float *******pppppppfVar31;
  float *******pppppppfVar33;
  undefined8 uVar32;
  float *******pppppppfVar34;
  float *******pppppppfVar35;
  float *******pppppppfVar36;
  float *******pppppppfVar37;
  undefined8 uVar38;
  longlong lVar39;
  undefined4 uVar41;
  undefined8 uVar40;
  _Alignas(8) unsigned char albw_frame[0x470];
  #define local_464 (*(float ******* *)(albw_frame + 0xc))
  #define pppppppfStack_460 (*(float ******* *)(albw_frame + 0x10))
  #define pppppppfStack_45c (*(float ******* *)(albw_frame + 0x14))
  #define local_458 (*(float ******* *)(albw_frame + 0x18))
  #define local_454 (*(float ******* *)(albw_frame + 0x1c))
  #define local_450 (*(float ******* *)(albw_frame + 0x20))
  #define local_44c (*(float ******* *)(albw_frame + 0x24))
  #define local_448 (*(uint *)(albw_frame + 0x28))
  #define iStack_444 (*(int *)(albw_frame + 0x2c))
  #define local_440 (*(int *)(albw_frame + 0x30))
  #define local_43c (*(undefined4 * *)(albw_frame + 0x34))
  #define local_234 ((float ****** *)(albw_frame + 0x23c))
  #define local_224 (*(float ****** *)(albw_frame + 0x24c))
  #define local_220 (*(float ****** *)(albw_frame + 0x250))
  #define local_21c (*(float ****** *)(albw_frame + 0x254))
  #define local_218 (*(float ****** *)(albw_frame + 0x258))
  #define local_214 (*(float ****** *)(albw_frame + 0x25c))
  #define local_210 (*(float ******* *)(albw_frame + 0x260))
  #define local_20c ((float ******* *)(albw_frame + 0x264))
  #define local_200 (*(float ****** *)(albw_frame + 0x270))
  #define local_1fc (*(float ******* *)(albw_frame + 0x274))
  #define local_1f8 (*(float ******* *)(albw_frame + 0x278))
  #define local_1f4 (*(float ******* *)(albw_frame + 0x27c))
  #define local_1f0 (*(float ******* *)(albw_frame + 0x280))
  #define local_1ec (*(float ******* *)(albw_frame + 0x284))
  #define local_1e8 (*(float ******* *)(albw_frame + 0x288))
  #define local_1e4 (*(float ******* *)(albw_frame + 0x28c))
  #define local_1e0 (*(int * *)(albw_frame + 0x290))
  #define local_1dc (*(float *)(albw_frame + 0x294))
  #define local_1d8 (*(float ******* *)(albw_frame + 0x298))
  #define local_1d4 (*(float ******* *)(albw_frame + 0x29c))
  #define local_1d0 (*(float ******* *)(albw_frame + 0x2a0))
  #define local_1cc (*(float *)(albw_frame + 0x2a4))
  #define local_1c8 (*(float *)(albw_frame + 0x2a8))
  #define local_1c4 (*(float *)(albw_frame + 0x2ac))
  #define local_1c0 (*(float ******* *)(albw_frame + 0x2b0))
  #define local_1bc (*(float ******* *)(albw_frame + 0x2b4))
  #define local_1b8 (*(float ******* *)(albw_frame + 0x2b8))
  #define local_1b4 (*(float *)(albw_frame + 0x2bc))
  #define local_1b0 (*(float *)(albw_frame + 0x2c0))
  #define local_1ac (*(float *)(albw_frame + 0x2c4))
  #define local_1a8 (*(float ******* *)(albw_frame + 0x2c8))
  #define pppppppfStack_1a4 (*(float ******* *)(albw_frame + 0x2cc))
  #define pppppppfStack_1a0 (*(float ******* *)(albw_frame + 0x2d0))
  #define local_19c (*(float ******* *)(albw_frame + 0x2d4))
  #define pppppppfStack_198 (*(float ******* *)(albw_frame + 0x2d8))
  #define pppppppfStack_194 (*(float ******* *)(albw_frame + 0x2dc))
  #define local_190 (*(float ******* *)(albw_frame + 0x2e0))
  #define local_18c (*(float ******* *)(albw_frame + 0x2e4))
  #define local_188 (*(float ******* *)(albw_frame + 0x2e8))
  #define local_184 ((float ****** *)(albw_frame + 0x2ec))
  #define local_174 (*(float ****** *)(albw_frame + 0x2fc))
  #define local_170 (*(float ****** *)(albw_frame + 0x300))
  #define local_16c (*(float ****** *)(albw_frame + 0x304))
  #define local_168 (*(float ****** *)(albw_frame + 0x308))
  #define local_164 (*(float ****** *)(albw_frame + 0x30c))
  #define local_160 (*(float ******* *)(albw_frame + 0x310))
  #define local_15c (*(float ******* *)(albw_frame + 0x314))
  #define local_158 (*(float ******* *)(albw_frame + 0x318))
  #define local_154 (*(float ******* *)(albw_frame + 0x31c))
  #define local_150 (*(float ******* *)(albw_frame + 0x320))
  #define local_14c (*(float ******* *)(albw_frame + 0x324))
  #define local_148 (*(float ******* *)(albw_frame + 0x328))
  #define local_144 (*(float ******* *)(albw_frame + 0x32c))
  #define local_140 (*(float ******* *)(albw_frame + 0x330))
  #define local_13c (*(float ******* *)(albw_frame + 0x334))
  #define local_138 (*(int *)(albw_frame + 0x338))
  #define local_134 (*(float ******* *)(albw_frame + 0x33c))
  #define local_130 (*(float ******* *)(albw_frame + 0x340))
  #define local_12c (*(float ******* *)(albw_frame + 0x344))
  #define local_128 (*(float ******* *)(albw_frame + 0x348))
  #define local_124 (*(float ******* *)(albw_frame + 0x34c))
  #define local_120 (*(float ******* *)(albw_frame + 0x350))
  #define local_11c (*(float ******* *)(albw_frame + 0x354))
  #define local_118 (*(float ******* *)(albw_frame + 0x358))
  #define local_114 (*(float ******* *)(albw_frame + 0x35c))
  #define local_110 (*(float ******* *)(albw_frame + 0x360))
  #define local_10c (*(float ******* *)(albw_frame + 0x364))
  #define local_108 (*(float ******* *)(albw_frame + 0x368))
  #define local_104 (*(float ******* *)(albw_frame + 0x36c))
  #define local_100 (*(float ******* *)(albw_frame + 0x370))
  #define local_fc (*(float ****** *)(albw_frame + 0x374))
  #define local_f8 (*(float ******* *)(albw_frame + 0x378))
  #define local_f4 (*(float ***** *)(albw_frame + 0x37c))
  #define local_f0 (*(float ******* *)(albw_frame + 0x380))
  #define local_ec (*(float ******* *)(albw_frame + 0x384))
  #define local_e8 (*(float ******* *)(albw_frame + 0x388))
  #define local_e4 (*(float ******* *)(albw_frame + 0x38c))
  #define local_e0 (*(float ******* *)(albw_frame + 0x390))
  #define local_dc ((float *)(albw_frame + 0x394))
  #define local_d0 (*(float ******* *)(albw_frame + 0x3a0))
  #define local_cc (*(float ******* *)(albw_frame + 0x3a4))
  #define local_c8 (*(float ******* *)(albw_frame + 0x3a8))
  #define local_c4 (*(float ******* *)(albw_frame + 0x3ac))
  #define local_c0 (*(float *)(albw_frame + 0x3b0))
  #define local_bc (*(float *)(albw_frame + 0x3b4))
  #define local_b8 (*(float *)(albw_frame + 0x3b8))
  #define local_b4 (*(float ****** *)(albw_frame + 0x3bc))
  #define local_b0 (*(float ****** *)(albw_frame + 0x3c0))
  #define local_ac (*(float ****** *)(albw_frame + 0x3c4))
  #define local_a8 (*(float * *)(albw_frame + 0x3c8))
  #define local_a4 (*(undefined4 *)(albw_frame + 0x3cc))
  #define local_a0 (*(int * *)(albw_frame + 0x3d0))
  #define local_9c (*(int *)(albw_frame + 0x3d4))
  #define local_98 ((float ******* *)(albw_frame + 0x3d8))
  #define local_8c (*(float *)(albw_frame + 0x3e4))
  #define local_88 (*(float ****** *)(albw_frame + 0x3e8))
  #define local_84 (*(float *)(albw_frame + 0x3ec))
  #define local_30 (*(int * *)(albw_frame + 0x440))
  #define puStack_2c (*(undefined4 * *)(albw_frame + 0x444))
  #define piStack_28 (*(int * *)(albw_frame + 0x448))
  if (param_2 != (undefined4 *)0x0) {
    param_2[10] = param_2[10] + 1;
  }
  lVar39 = (ulonglong)DAT_0064edac << 0x20;
  pfVar14 = (float *)0x0;
  local_1bc = (float *******)DAT_0064eda4[1];
  local_1c0 = (float *******)*DAT_0064eda4;
  local_1b8 = (float *******)DAT_0064eda4[2];
  local_1b0 = DAT_0064eda8[1];
  local_1b4 = *DAT_0064eda8;
  local_1ac = DAT_0064eda8[2];
  local_1d8 = (float *******)param_3[1];
  local_1d4 = (float *******)param_3[2];
  local_1d0 = (float *******)param_3[3];
  local_1cc = ALBW_AS_F32(param_3[4]);
  local_1c8 = ALBW_AS_F32(param_3[5]);
  local_1c4 = ALBW_AS_F32(param_3[6]);
  local_30 = param_1;
  puStack_2c = param_2;
  piStack_28 = param_3;
  func_00688AB0(&local_448);
  local_138 = 0;
  local_160 = (float *******)0x0;
  ppppppfVar11 = DAT_0064edb0;
  func_00115D70((float *)&local_454,(float *)(param_3 + 7),ALBW_AS_F32(DAT_0064edb0));
  local_1a8 = local_454;
  pppppppfStack_1a4 = local_450;
  pppppppfStack_1a0 = local_44c;
  func_00115C54((float *)&local_454,(float *)(param_3 + 1),(float *)&local_1a8);
  local_464 = local_454;
  pppppppfStack_460 = local_450;
  pppppppfStack_45c = local_44c;
  func_00115D70((float *)&local_458,(float *)(local_30 + 0x15),ALBW_AS_F32(ppppppfVar11));
  local_19c = local_458;
  pppppppfStack_198 = local_454;
  pppppppfStack_194 = local_450;
  func_00115C54((float *)&local_458,(float *)&local_464,(float *)&local_19c);
  local_1c0 = local_458;
  local_1bc = local_454;
  local_1b8 = local_450;
  local_1b4 = ALBW_AS_F32(param_3[4]);
  local_1b0 = ALBW_AS_F32(param_3[5]);
  local_1ac = ALBW_AS_F32(param_3[6]);
  local_200 = (float ******)0x0;
  func_00115D70((float *)&local_454,(float *)(param_3 + 7),ALBW_AS_F32(ppppppfVar11));
  local_1ec = local_454;
  local_1e8 = local_450;
  local_1e4 = local_44c;
  func_00115C54((float *)&local_454,(float *)(param_3 + 1),(float *)&local_1ec);
  uVar41 = (undefined4)((ulonglong)lVar39 >> 0x20);
  local_1c0 = local_454;
  local_1bc = local_450;
  local_1b8 = local_44c;
  local_1b4 = ALBW_AS_F32(param_3[4]);
  local_1b0 = ALBW_AS_F32(param_3[5]);
  uVar30 = ZEXT48(DAT_0064edbc);
  local_1ac = ALBW_AS_F32(param_3[6]);
  iVar6 = *param_3;
  pppppppfVar35 = (float *******)param_3[0xb];
  local_15c = (float *******)0x1;
  pfVar7 = (float *)(iVar6 + 0x24);
  fVar21 = *(float *)(iVar6 + 0x30);
  fVar23 = *(float *)(iVar6 + 0x34);
  fVar25 = *(float *)(iVar6 + 0x38);
  fVar19 = local_1cc * fVar21 + local_1c8 * fVar23 + local_1c4 * fVar25;
  fVar16 = DAT_0064edb4;
  pppppppfVar36 = DAT_0064edb8;
  local_108 = (float *******)&local_1d8;
  if ((fVar19 < DAT_0064edb4) || (ALBW_AS_F32(ppppppfVar11) < fVar19)) {
    pppppppfVar34 =
         (float *******)
         CF_FBITS((((fVar21 * *pfVar7 + fVar23 * *(float *)(iVar6 + 0x28) + fVar25 * *(float *)(iVar6 + 0x2c)
           ) - (fVar21 * ALBW_AS_F32(local_1d8) + fVar23 * ALBW_AS_F32(local_1d4) + fVar25 * ALBW_AS_F32(local_1d0)))
         / fVar19));
    pppppppfVar20 = (float *******)CF_FBITS((ALBW_AS_F32(pppppppfVar34) - ALBW_AS_F32(pppppppfVar35)));
    pppppppfVar29 = DAT_0064edbc;
    if ((ALBW_AS_F32(pppppppfVar20) <= ALBW_AS_F32(ppppppfVar11)) && (DAT_0064edb4 <= ALBW_AS_F32(pppppppfVar34))) {
      ppppppfVar28 = ppppppfVar11;
      func_00115D70((float *)&local_148,&local_1cc,ALBW_AS_F32(pppppppfVar34));
      local_154 = local_148;
      local_150 = local_144;
      local_14c = local_140;
      func_00115C54((float *)&local_148,(float *)&local_1d8,(float *)&local_154);
      local_20c[0] = local_148;
      local_20c[1] = local_144;
      local_20c[2] = local_140;
      func_00115C70((float *)&local_148,(float *)local_20c,pfVar7);
      pppppppfVar20 = local_148;
      if (((ALBW_AS_F32(local_148) * *(float *)(iVar6 + 0x3c) +
            ALBW_AS_F32(local_144) * *(float *)(iVar6 + 0x40) +
            ALBW_AS_F32(local_140) * *(float *)(iVar6 + 0x44) <= ALBW_AS_F32(ppppppfVar28)) &&
          (ALBW_AS_F32(local_148) * *(float *)(iVar6 + 0x48) + ALBW_AS_F32(local_144) * *(float *)(iVar6 + 0x4c)
           + ALBW_AS_F32(local_140) * *(float *)(iVar6 + 0x50) <= ALBW_AS_F32(ppppppfVar28))) &&
         (pppppppfVar20 =
               (float *******)
               CF_FBITS((ALBW_AS_F32(local_148) * *(float *)(iVar6 + 0x54) +
                ALBW_AS_F32(local_144) * *(float *)(iVar6 + 0x58) +
               ALBW_AS_F32(local_140) * *(float *)(iVar6 + 0x5c))),
         ALBW_AS_F32(pppppppfVar20) <= *(float *)(iVar6 + 0x68) + ALBW_AS_F32(ppppppfVar28))) goto LAB_0064ef54;
    }
LAB_0064ef74:
    pppppppfVar34 = pppppppfVar36;
    local_15c = (float *******)0x0;
    pppppppfVar36 = pppppppfVar34;
  }
  else {
    ppppppfVar28 = ppppppfVar11;
    func_00115C70((float *)&local_154,(float *)&local_1d8,pfVar7);
    uVar41 = (undefined4)((ulonglong)lVar39 >> 0x20);
    pppppppfVar34 = (float *******)uVar30;
    pppppppfVar20 =
         (float *******)
         CF_FBITS((ALBW_AS_F32(local_154) * *(float *)(iVar6 + 0x30) + ALBW_AS_F32(local_150) * *(float *)(iVar6 + 0x34)
         + ALBW_AS_F32(local_14c) * *(float *)(iVar6 + 0x38)));
    pppppppfVar29 = pppppppfVar34;
    if (ALBW_AS_F32(pppppppfVar20) <= ALBW_AS_F32(ppppppfVar28)) {
      fVar19 = -ALBW_AS_F32(ppppppfVar28);
      iVar12 = 0;
      local_20c[0] = (float *******)(iVar6 + 0x3c);
      local_20c[1] = (float *******)(iVar6 + 0x48);
      local_20c[2] = (float *******)(iVar6 + 0x54);
      pppppppfVar34 = local_150;
      pppppppfVar33 = local_154;
      pppppppfVar31 = local_14c;
      pppppppfVar37 = pppppppfVar36;
      do {
        ppppppfVar2 = (float ******)local_20c[iVar12];
        pppppfVar24 = ppppppfVar2[1];
        pppppfVar22 = ppppppfVar2[2];
        pppppppfVar20 =
             (float *******)
             CF_FBITS((local_1cc * ALBW_AS_F32(*ppppppfVar2) + local_1c8 * ALBW_AS_F32(pppppfVar24) +
             local_1c4 * ALBW_AS_F32(pppppfVar22)));
        bVar17 = fVar19 == ALBW_AS_F32(pppppppfVar20);
        bVar18 = ALBW_AS_F32(pppppppfVar20) <= fVar19;
        if (!bVar18 || bVar17) {
          bVar17 = ALBW_AS_F32(pppppppfVar20) == ALBW_AS_F32(ppppppfVar28);
          bVar18 = ALBW_AS_F32(ppppppfVar28) <= ALBW_AS_F32(pppppppfVar20);
        }
        if (bVar18 && !bVar17) {
          fVar21 = ALBW_AS_F32(*ppppppfVar2) * ALBW_AS_F32(pppppppfVar33);
          if (iVar12 == 2) {
            fVar21 = *(float *)(iVar6 + 0x68) -
                     (fVar21 + ALBW_AS_F32(pppppfVar24) * ALBW_AS_F32(pppppppfVar34) +
                     ALBW_AS_F32(pppppfVar22) * ALBW_AS_F32(pppppppfVar31));
          }
          else {
            fVar21 = -(fVar21 + ALBW_AS_F32(pppppfVar24) * ALBW_AS_F32(pppppppfVar34) +
                      ALBW_AS_F32(pppppfVar22) * ALBW_AS_F32(pppppppfVar31));
          }
          pppppppfVar29 = (float *******)CF_FBITS((fVar21 / ALBW_AS_F32(pppppppfVar20)));
          if (ALBW_AS_F32(pppppppfVar37) <= ALBW_AS_F32(pppppppfVar29) &&
              ALBW_AS_F32(pppppppfVar36) <= ALBW_AS_F32(pppppppfVar29)) {
            bVar17 = ALBW_AS_F32(pppppppfVar35) <= ALBW_AS_F32(pppppppfVar29);
            fparam_0 = pppppppfVar35;
            if (!bVar17) {
              fparam_0 = pppppppfVar29;
            }
            func_00115D70((float *)&local_124,&local_1cc,ALBW_AS_F32(fparam_0));
            local_148 = local_124;
            local_144 = local_120;
            local_140 = local_11c;
            func_00115C54((float *)&local_118,(float *)local_108,(float *)&local_148);
            local_130 = local_118;
            local_12c = local_114;
            local_128 = local_110;
            func_00115C70((float *)&local_1fc,(float *)&local_130,pfVar7);
            uVar41 = (undefined4)((ulonglong)lVar39 >> 0x20);
            pppppppfVar29 = (float *******)uVar30;
            pppppppfVar20 = local_1f8;
            if (((ALBW_AS_F32(local_1fc) * ALBW_AS_F32(*local_20c[0]) +
                  ALBW_AS_F32(local_1f8) * ALBW_AS_F32(local_20c[0][1]) +
                  ALBW_AS_F32(local_1f4) * ALBW_AS_F32(local_20c[0][2]) <= ALBW_AS_F32(ppppppfVar28)) &&
                (ALBW_AS_F32(local_1fc) * ALBW_AS_F32(*local_20c[1]) + ALBW_AS_F32(local_1f8) * ALBW_AS_F32(local_20c[1][1])
                 + ALBW_AS_F32(local_1f4) * ALBW_AS_F32(local_20c[1][2]) <= ALBW_AS_F32(ppppppfVar28))) &&
               ((ALBW_AS_F32(local_1fc) * ALBW_AS_F32(*local_20c[2]) + ALBW_AS_F32(local_1f8) * ALBW_AS_F32(local_20c[2][1])
                 + ALBW_AS_F32(local_1f4) * ALBW_AS_F32(local_20c[2][2]) <=
                 *(float *)(iVar6 + 0x68) + ALBW_AS_F32(ppppppfVar28) &&
                (pppppppfVar36 = fparam_0, bVar17)))) break;
          }
        }
        uVar41 = (undefined4)((ulonglong)lVar39 >> 0x20);
        pppppppfVar29 = (float *******)uVar30;
        iVar12 = iVar12 + 1;
      } while (iVar12 < 3);
      bVar17 = ALBW_AS_F32(pppppppfVar36) == ALBW_AS_F32(pppppppfVar37);
      pppppppfVar34 = pppppppfVar36;
      pppppppfVar36 = pppppppfVar37;
      if (bVar17) goto LAB_0064ef74;
    }
LAB_0064ef54:
    if ((pppppppfVar34 == (float *******)0xff7fffff) || ((int)pppppppfVar34 < DAT_0064f2b0))
    goto LAB_0064ef74;
  }
  local_1f4 = (float *******)(local_30 + 0xf40);
  if (*(char *)((int)local_30 + 0x3dc2) == '\0') {
    pppppppfVar35 = pppppppfVar34;
    local_160 = (float *******)
                func_001EA738((undefined4)(uintptr_t)(local_30),(int *)&local_134,param_3[0xc],(float *)&local_1c0,
                              ALBW_AS_F32(pppppppfVar34));
    pppppppfVar20 = pppppppfVar34;
    pppppppfVar34 = pppppppfVar35;
  }
  iVar6 = DAT_0064f2b0;
  uVar38 = CONCAT44(DAT_0064f2b4,pppppppfVar29);
  uVar40 = CONCAT44(uVar41,DAT_0064f2b8);
  if (local_160 == (float *******)0x0 && local_15c == (float *******)0x0) {
    if ((param_2 == (undefined4 *)0x0) || (param_2[10] != 1)) {
      return 3;
    }
    local_190 = local_1d8;
    local_18c = local_1d4;
    local_188 = local_1d0;
    pppppppfVar35 = pppppppfVar36;
LAB_0064f9a4:
    iVar6 = param_3[0xc];
    pppppppfVar34 = pppppppfVar36;
    func_0010F1F8((int *)(*param_3 + *(int *)(iVar6 + 0xc)),ALBW_AS_F32(pppppppfVar20));
    *(int *)(iVar6 + 8) = *(int *)(iVar6 + 8) + -1;
LAB_0064f9c4:
    pppppppfVar20 = (float *******)param_3[0xb];
    pppppppfVar36 = (float *******)CF_FBITS((ALBW_AS_F32(pppppppfVar20) - ALBW_AS_F32(pppppppfVar34)));
    local_1e8 = (float *******)(param_3[0xc] - *(int *)(param_3[0xc] + 0xc));
    iVar6 = *(int *)(param_3[0xc] + 0xc);
    pppppppfVar29 = (float *******)(*(int *)(param_3[0xc] + 4) - iVar6);
    if (pppppppfVar29 != local_1e8) {
      do {
        pppppppfVar20 =
             (float *******)
             CF_FBITS((ALBW_AS_F32(pppppppfVar29[0xc]) * ALBW_AS_F32(param_3[7]) +
              ALBW_AS_F32(pppppppfVar29[0xd]) * ALBW_AS_F32(param_3[8]) +
             ALBW_AS_F32(pppppppfVar29[0xe]) * ALBW_AS_F32(param_3[9])));
        if (((pppppppfVar20 <= DAT_00650724) &&
            (func_00115C70(&local_8c,(float *)&local_190,(float *)(pppppppfVar29 + 9)),
            pppppppfVar20 = (float *******)local_88,
            local_8c * ALBW_AS_F32(pppppppfVar29[0xf]) + ALBW_AS_F32(local_88) * ALBW_AS_F32(pppppppfVar29[0x10]) +
            local_84 * ALBW_AS_F32(pppppppfVar29[0x11]) <= ALBW_AS_F32(ppppppfVar11))) &&
           ((local_8c * ALBW_AS_F32(pppppppfVar29[0x12]) + ALBW_AS_F32(local_88) * ALBW_AS_F32(pppppppfVar29[0x13]) +
             local_84 * ALBW_AS_F32(pppppppfVar29[0x14]) <= ALBW_AS_F32(ppppppfVar11) &&
            (local_8c * ALBW_AS_F32(pppppppfVar29[0x15]) + ALBW_AS_F32(local_88) * ALBW_AS_F32(pppppppfVar29[0x16]) +
             local_84 * ALBW_AS_F32(pppppppfVar29[0x17]) <=
             ALBW_AS_F32(pppppppfVar29[0x1a]) + ALBW_AS_F32(ppppppfVar11))))) {
          fVar19 = -(local_8c * ALBW_AS_F32(pppppppfVar29[0xc]) +
                     ALBW_AS_F32(local_88) * ALBW_AS_F32(pppppppfVar29[0xd]) +
                    local_84 * ALBW_AS_F32(pppppppfVar29[0xe]));
          if ((fVar19 < fVar16) ||
             (pppppppfVar20 = (float *******)ppppppfVar11, ALBW_AS_F32(ppppppfVar11) < fVar19)) {
            fVar19 = ALBW_AS_F32(uVar38);
          }
          if (fVar19 != -3.4028235e+38) {
            local_200 = (float ******)
                        CF_FBITS((ALBW_AS_F32(pppppppfVar29[0xc]) * ALBW_AS_F32(param_3[4]) +
                         ALBW_AS_F32(pppppppfVar29[0xd]) * ALBW_AS_F32(param_3[5]) +
                        ALBW_AS_F32(pppppppfVar29[0xe]) * ALBW_AS_F32(param_3[6])));
            if (pfVar14 == (float *)0x0) {
              func_00115E10((float *)&local_160,DAT_00650720,(float *)(param_3 + 7));
              pfVar14 = local_dc;
              func_00115E10(pfVar14,(float *)&local_160,DAT_00650720);
            }
            if (DAT_00650728 < local_200) {
              local_234[0] = pppppppfVar29[9];
              uVar30 = ZEXT48(pppppppfVar35);
              local_234[1] = pppppppfVar29[10];
              local_234[2] = pppppppfVar29[0xb];
              pppppppfVar20 = pppppppfVar29 + 9;
              fVar23 = ALBW_AS_F32(pppppppfVar29[0xe]) * ALBW_AS_F32(pppppppfVar29[0x10]) -
                       ALBW_AS_F32(pppppppfVar29[0xd]) * ALBW_AS_F32(pppppppfVar29[0x11]);
              fVar25 = ALBW_AS_F32(pppppppfVar29[0xc]) * ALBW_AS_F32(pppppppfVar29[0x11]) -
                       ALBW_AS_F32(pppppppfVar29[0xe]) * ALBW_AS_F32(pppppppfVar29[0xf]);
              fVar26 = ALBW_AS_F32(pppppppfVar29[0xd]) * ALBW_AS_F32(pppppppfVar29[0xf]) -
                       ALBW_AS_F32(pppppppfVar29[0xc]) * ALBW_AS_F32(pppppppfVar29[0x10]);
              fVar21 = fVar23 * ALBW_AS_F32(pppppppfVar29[0x15]) + fVar25 * ALBW_AS_F32(pppppppfVar29[0x16]) +
                       fVar26 * ALBW_AS_F32(pppppppfVar29[0x17]);
              if (fVar21 <= ALBW_AS_F32(pppppppfVar35)) {
                local_234[3] = *pppppppfVar20;
                local_224 = pppppppfVar29[10];
                local_220 = pppppppfVar29[0xb];
              }
              else {
                fVar21 = ALBW_AS_F32(pppppppfVar29[0x1a]) / fVar21;
                local_234[3] = (float ******)CF_FBITS((ALBW_AS_F32(*pppppppfVar20) + fVar23 * fVar21));
                local_224 = (float ******)CF_FBITS((ALBW_AS_F32(pppppppfVar29[10]) + fVar25 * fVar21));
                local_220 = (float ******)CF_FBITS((ALBW_AS_F32(pppppppfVar29[0xb]) + fVar26 * fVar21));
              }
              fVar25 = ALBW_AS_F32(pppppppfVar29[0x14]) * ALBW_AS_F32(pppppppfVar29[0xd]) -
                       ALBW_AS_F32(pppppppfVar29[0x13]) * ALBW_AS_F32(pppppppfVar29[0xe]);
              fVar23 = ALBW_AS_F32(pppppppfVar29[0x12]) * ALBW_AS_F32(pppppppfVar29[0xe]) -
                       ALBW_AS_F32(pppppppfVar29[0x14]) * ALBW_AS_F32(pppppppfVar29[0xc]);
              fVar26 = ALBW_AS_F32(pppppppfVar29[0x13]) * ALBW_AS_F32(pppppppfVar29[0xc]) -
                       ALBW_AS_F32(pppppppfVar29[0x12]) * ALBW_AS_F32(pppppppfVar29[0xd]);
              fVar21 = fVar25 * ALBW_AS_F32(pppppppfVar29[0x15]) + fVar23 * ALBW_AS_F32(pppppppfVar29[0x16]) +
                       fVar26 * ALBW_AS_F32(pppppppfVar29[0x17]);
              if (fVar21 <= ALBW_AS_F32(pppppppfVar35)) {
                local_21c = *pppppppfVar20;
                local_218 = pppppppfVar29[10];
                local_214 = pppppppfVar29[0xb];
              }
              else {
                fVar21 = ALBW_AS_F32(pppppppfVar29[0x1a]) / fVar21;
                local_21c = (float ******)CF_FBITS((ALBW_AS_F32(*pppppppfVar20) + fVar25 * fVar21));
                local_218 = (float ******)CF_FBITS((ALBW_AS_F32(pppppppfVar29[10]) + fVar23 * fVar21));
                local_214 = (float ******)CF_FBITS((ALBW_AS_F32(pppppppfVar29[0xb]) + fVar26 * fVar21));
              }
              func_00115C70((float *)&local_1e4,(float *)local_234,(float *)(param_3 + 1));
              iVar12 = 0;
              ppppppfVar28 = (float ******)
                             CF_FBITS((*pfVar14 * ALBW_AS_F32(local_1e4) + pfVar14[1] * ALBW_AS_F32(local_1e0) +
                             pfVar14[2] * local_1dc));
              ppppppfVar2 = ppppppfVar28;
              do {
                pppppppfVar20 = (float *******)ppppppfVar2;
                ppppppfVar2 = (float ******)pppppppfVar20;
                if (iVar12 != 2) {
                  func_00115C70((float *)&local_1fc,(float *)(local_234 + (iVar12 + 1) * 3),
                                (float *)(param_3 + 1));
                  pppppppfVar20 =
                       (float *******)
                       CF_FBITS((*pfVar14 * ALBW_AS_F32(local_1fc) + pfVar14[1] * ALBW_AS_F32(local_1f8) +
                       pfVar14[2] * ALBW_AS_F32(local_1f4)));
                }
                fVar21 = ALBW_AS_F32(uVar30);
                bVar17 = ALBW_AS_F32(ppppppfVar28) == fVar21;
                bVar18 = fVar21 <= ALBW_AS_F32(ppppppfVar28);
                if (!bVar18 || bVar17) {
                  bVar17 = ALBW_AS_F32(pppppppfVar20) == fVar21;
                  bVar18 = fVar21 <= ALBW_AS_F32(pppppppfVar20);
                }
                if (bVar18 && !bVar17) goto LAB_0064ffa4;
                iVar12 = iVar12 + 1;
                ppppppfVar28 = (float ******)pppppppfVar20;
              } while (iVar12 < 3);
            }
            else if (DAT_0064f2b0 < (int)local_200) {
              func_00115D70((float *)&local_1fc,pfVar14,ALBW_AS_F32(((ulonglong)uVar40 >> 0x20)));
              local_184[0] = pppppppfVar29[9];
              local_184[1] = pppppppfVar29[10];
              local_184[2] = pppppppfVar29[0xb];
              pppppppfVar20 = pppppppfVar29 + 9;
              fVar21 = ALBW_AS_F32(pppppppfVar29[0xe]) * ALBW_AS_F32(pppppppfVar29[0x10]) -
                       ALBW_AS_F32(pppppppfVar29[0xd]) * ALBW_AS_F32(pppppppfVar29[0x11]);
              fVar23 = ALBW_AS_F32(pppppppfVar29[0xc]) * ALBW_AS_F32(pppppppfVar29[0x11]) -
                       ALBW_AS_F32(pppppppfVar29[0xe]) * ALBW_AS_F32(pppppppfVar29[0xf]);
              fVar25 = ALBW_AS_F32(pppppppfVar29[0xd]) * ALBW_AS_F32(pppppppfVar29[0xf]) -
                       ALBW_AS_F32(pppppppfVar29[0xc]) * ALBW_AS_F32(pppppppfVar29[0x10]);
              fVar26 = fVar21 * ALBW_AS_F32(pppppppfVar29[0x15]) + fVar23 * ALBW_AS_F32(pppppppfVar29[0x16]) +
                       fVar25 * ALBW_AS_F32(pppppppfVar29[0x17]);
              if (fVar26 <= ALBW_AS_F32(pppppppfVar35)) {
                local_184[3] = *pppppppfVar20;
                local_174 = pppppppfVar29[10];
                local_170 = pppppppfVar29[0xb];
              }
              else {
                fVar26 = ALBW_AS_F32(pppppppfVar29[0x1a]) / fVar26;
                local_184[3] = (float ******)CF_FBITS((ALBW_AS_F32(*pppppppfVar20) + fVar21 * fVar26));
                local_174 = (float ******)CF_FBITS((ALBW_AS_F32(pppppppfVar29[10]) + fVar23 * fVar26));
                local_170 = (float ******)CF_FBITS((ALBW_AS_F32(pppppppfVar29[0xb]) + fVar25 * fVar26));
              }
              fVar23 = ALBW_AS_F32(pppppppfVar29[0x14]) * ALBW_AS_F32(pppppppfVar29[0xd]) -
                       ALBW_AS_F32(pppppppfVar29[0x13]) * ALBW_AS_F32(pppppppfVar29[0xe]);
              fVar25 = ALBW_AS_F32(pppppppfVar29[0x12]) * ALBW_AS_F32(pppppppfVar29[0xe]) -
                       ALBW_AS_F32(pppppppfVar29[0x14]) * ALBW_AS_F32(pppppppfVar29[0xc]);
              fVar26 = ALBW_AS_F32(pppppppfVar29[0x13]) * ALBW_AS_F32(pppppppfVar29[0xc]) -
                       ALBW_AS_F32(pppppppfVar29[0x12]) * ALBW_AS_F32(pppppppfVar29[0xd]);
              fVar21 = fVar23 * ALBW_AS_F32(pppppppfVar29[0x15]) + fVar25 * ALBW_AS_F32(pppppppfVar29[0x16]) +
                       fVar26 * ALBW_AS_F32(pppppppfVar29[0x17]);
              if (fVar21 <= ALBW_AS_F32(pppppppfVar35)) {
                local_16c = *pppppppfVar20;
                local_168 = pppppppfVar29[10];
                local_164 = pppppppfVar29[0xb];
              }
              else {
                fVar21 = ALBW_AS_F32(pppppppfVar29[0x1a]) / fVar21;
                local_16c = (float ******)CF_FBITS((ALBW_AS_F32(*pppppppfVar20) + fVar23 * fVar21));
                local_168 = (float ******)CF_FBITS((ALBW_AS_F32(pppppppfVar29[10]) + fVar25 * fVar21));
                local_164 = (float ******)CF_FBITS((ALBW_AS_F32(pppppppfVar29[0xb]) + fVar26 * fVar21));
              }
              pppppppfVar33 = local_1f4;
              pppppppfVar31 = local_1f8;
              pppppppfVar37 = local_1fc;
              pppppppfVar20 = pppppppfVar35;
              func_00115C70((float *)&local_1f4,(float *)local_184,(float *)(param_3 + 1));
              iVar12 = 0;
              ppppppfVar28 = (float ******)
                             CF_FBITS((ALBW_AS_F32(pppppppfVar37) * ALBW_AS_F32(local_1f4) +
                              ALBW_AS_F32(pppppppfVar31) * ALBW_AS_F32(local_1f0) +
                             ALBW_AS_F32(pppppppfVar33) * ALBW_AS_F32(local_1ec)));
              uVar32 = CONCAT44(pppppppfVar20,ppppppfVar28);
              do {
                if (iVar12 == 2) {
                  pppppppfVar20 = (float *******)uVar32;
                }
                else {
                  func_00115C70((float *)&local_160,(float *)(local_184 + (iVar12 + 1) * 3),
                                (float *)(param_3 + 1));
                  pppppppfVar20 =
                       (float *******)
                       CF_FBITS((ALBW_AS_F32(pppppppfVar37) * ALBW_AS_F32(local_160) +
                        ALBW_AS_F32(pppppppfVar31) * ALBW_AS_F32(local_15c) +
                       ALBW_AS_F32(pppppppfVar33) * ALBW_AS_F32(local_158)));
                }
                fVar21 = ALBW_AS_F32(((ulonglong)uVar32 >> 0x20));
                bVar17 = ALBW_AS_F32(ppppppfVar28) == fVar21;
                bVar18 = fVar21 <= ALBW_AS_F32(ppppppfVar28);
                if (!bVar18 || bVar17) {
                  bVar17 = ALBW_AS_F32(pppppppfVar20) == fVar21;
                  bVar18 = fVar21 <= ALBW_AS_F32(pppppppfVar20);
                }
                if (bVar18 && !bVar17) goto LAB_0064ffa4;
                iVar12 = iVar12 + 1;
                ppppppfVar28 = (float ******)pppppppfVar20;
              } while (iVar12 < 3);
            }
            else {
LAB_0064ffa4:
              puVar8 = local_43c;
              if ((int)local_448 < iStack_444) {
                if (local_43c != (undefined4 *)0x0) {
                  puVar5 = (undefined4 *)*local_43c;
                  *local_43c = 0;
                  local_43c[1] = 0;
                  local_43c[2] = 0;
                  local_43c = puVar5;
                }
                if ((int)local_448 < iStack_444) {
                  *(undefined4 **)(local_440 + local_448 * 4) = puVar8;
                  local_448 = local_448 + 1;
                }
              }
              else {
                puVar8 = (undefined4 *)0x0;
              }
              *puVar8 = (undefined4)(uintptr_t)(pppppppfVar29);
              iVar12 = DAT_0065072c;
              puVar8[1] = (undefined4)(uintptr_t)(local_200);
              if (fVar19 <= ALBW_AS_F32(pppppppfVar35)) {
                fVar19 = -fVar19;
              }
              puVar8[2] = ALBW_AS_U32(fVar19);
              pppppppfVar20 = (float *******)local_200;
              if ((int)ALBW_AS_U32(fVar19) < iVar12) {
                puVar8[2] = (undefined4)(uintptr_t)(pppppppfVar35);
              }
            }
          }
        }
        pppppppfVar29 = (float *******)(*(int *)((int)pppppppfVar29 + iVar6 + 4) - iVar6);
      } while (pppppppfVar29 != local_1e8);
    }
    if (local_448 != 0) {
      piVar4 = (int *)param_2[0xb];
      if (piVar4 == (int *)0x0) {
        puVar15 = (uint *)param_2[9];
        if (puVar15 != (uint *)0x0) {
          if ((uint)param_3[0xd] < *puVar15) {
            uVar3 = puVar15[2] + param_3[0xd] * 0x9c;
          }
          else {
            uVar3 = puVar15[2];
          }
          *(float ********)(uVar3 + 0x30) = local_190;
          *(float ********)(uVar3 + 0x34) = local_18c;
          *(float ********)(uVar3 + 0x38) = local_188;
          *(float ********)(uVar3 + 0x74) = pppppppfVar36;
        }
      }
      else {
        iVar6 = *piVar4;
        if (iVar6 < piVar4[1]) {
          *piVar4 = iVar6 + 1;
          puVar8 = (undefined4 *)(piVar4[2] + iVar6 * 0x10);
        }
        else {
          puVar8 = (undefined4 *)0x0;
        }
        *puVar8 = (undefined4)(uintptr_t)(pppppppfVar34);
        puVar8[1] = param_3[7];
        puVar8[2] = param_3[8];
        puVar8[3] = param_3[9];
      }
      func_0048C258((int *)&local_448,DAT_00650730);
      local_1e8 = (float *******)param_3[10];
      uVar3 = 0;
      local_1e0 = (int *)param_3[0xc];
      local_1e4 = pppppppfVar36;
      if (0 < (int)local_448) {
        do {
          iVar6 = param_3[0xc];
          if (uVar3 < local_448) {
            piVar4 = *(int **)(local_440 + uVar3 * 4);
          }
          else {
            piVar4 = (int *)0x0;
          }
          ppppppfVar11 = (float ******)*piVar4;
          piVar9 = (int *)(*(int *)(iVar6 + 0xc) + (int)ppppppfVar11);
          piVar4 = piVar9 + 1;
          if (*piVar4 == 0) {
            piVar9 = (int *)*piVar9;
          }
          if (*piVar4 != 0 || piVar9 != (int *)0x0) {
            if ((local_138 == 0) || ((float ******)*param_3 != ppppppfVar11)) {
              local_1f4 = (float *******)ppppppfVar11[0xc];
              local_1f0 = (float *******)ppppppfVar11[0xd];
              local_1ec = (float *******)ppppppfVar11[0xe];
              local_210 = (float *******)ppppppfVar11;
              func_00115C70((float *)&local_134,(float *)&local_190,(float *)(ppppppfVar11 + 9));
              local_150 = local_134;
              local_14c = local_130;
              local_148 = local_12c;
              func_00115D70((float *)&local_11c,(float *)&local_1f4,
                            ALBW_AS_F32(local_1f4) * ALBW_AS_F32(local_134) +
                            ALBW_AS_F32(local_1f0) * ALBW_AS_F32(local_130) +
                            ALBW_AS_F32(local_1ec) * ALBW_AS_F32(local_12c));
              local_144 = local_11c;
              local_140 = local_118;
              local_13c = local_114;
              func_00115C70((float *)&local_110,(float *)&local_190,(float *)&local_144);
              local_20c[0] = local_110;
              local_20c[1] = local_10c;
              local_20c[2] = local_108;
              func_00115E10((float *)&local_200,(float *)&local_1f4,(float *)param_3[10]);
              func_00115DC8((float *)&local_200);
              func_00115C54((float *)&local_128,(float *)local_20c,(float *)&local_200);
              pfVar7 = (float *)(param_3 + 1);
              local_150 = local_128;
              local_14c = local_124;
              local_148 = local_120;
              func_00115C70((float *)&local_15c,(float *)&local_150,pfVar7);
              pppppppfVar20 = local_1f4;
              if (ALBW_AS_F32(local_1ec) * ALBW_AS_F32(local_15c) - ALBW_AS_F32(local_1f4) * ALBW_AS_F32(local_154) <
                  ALBW_AS_F32(pppppppfVar35)) {
                if (param_2 != (undefined4 *)0x0) {
                  pfVar7 = (float *)param_2[9];
                }
                if (param_2 != (undefined4 *)0x0 && pfVar7 != (float *)0x0) {
                  fVar19 = *pfVar7;
                  fVar21 = pfVar7[1];
                  fVar16 = fVar21;
                  if ((int)ALBW_AS_U32(fVar19) < (int)ALBW_AS_U32(fVar21)) {
                    fVar16 = ALBW_AS_F32(((int)ALBW_AS_U32(fVar19) + 1));
                  }
                  uVar1 = *(undefined1 *)((int)ALBW_AS_U32(pfVar7[2]) + (int)ALBW_AS_U32(fVar19) * 0x9c + -0xc);
                  if ((int)ALBW_AS_U32(fVar19) < (int)ALBW_AS_U32(fVar21)) {
                    *pfVar7 = fVar16;
                    pfVar7 = (float *)((int)ALBW_AS_U32(pfVar7[2]) + (int)ALBW_AS_U32(fVar19) * 0x9c);
                  }
                  else {
                    pfVar7 = (float *)0x0;
                  }
                  pfVar7[9] = ALBW_AS_F32(local_20c[0]);
                  pfVar7[10] = ALBW_AS_F32(local_20c[1]);
                  pfVar7[0xb] = ALBW_AS_F32(local_20c[2]);
                  pfVar7[0x1c] = ALBW_AS_F32(pppppppfVar36);
                  *(undefined1 *)(pfVar7 + 0x24) = uVar1;
                  *pfVar7 = ALBW_AS_F32(local_200);
                  pfVar7[1] = ALBW_AS_F32(local_1fc);
                  pfVar7[2] = ALBW_AS_F32(local_1f8);
                  pfVar7[6] = ALBW_AS_F32(local_1f4);
                  pfVar7[7] = ALBW_AS_F32(local_1f0);
                  pfVar7[8] = ALBW_AS_F32(local_1ec);
                  func_004A17A4(pfVar7);
                  local_1dc = ALBW_AS_F32((*(int *)param_2[9] + -1));
                }
                uVar13 = func_0064E9F4(local_30,param_2,(int *)&local_210);
                piVar4 = local_1e0;
                if (uVar13 < 2) {
                  return 0;
                }
                puVar15 = extraout_r1;
                if (param_2 != (undefined4 *)0x0) {
                  puVar15 = (uint *)param_2[9];
                }
                if ((param_2 != (undefined4 *)0x0 && puVar15 != (uint *)0x0) &&
                   (*puVar15 - 1 <= puVar15[1])) {
                  *puVar15 = *puVar15 - 1;
                }
                if (uVar13 == 2) {
                  piVar9 = (int *)(local_1e0[3] + (int)ppppppfVar11);
                  iVar6 = piVar9[1];
                  bVar17 = iVar6 == 0;
                  if (bVar17) {
                    iVar6 = *piVar9;
                  }
                  if (!bVar17 || iVar6 != 0) {
                    func_0010F1F8(piVar9,ALBW_AS_F32(pppppppfVar20));
                    piVar4[2] = piVar4[2] + -1;
                  }
                }
                local_138 = 0;
              }
            }
            else {
              piVar4 = (int *)(*(int *)(iVar6 + 0xc) + *param_3);
              iVar12 = piVar4[1];
              bVar17 = iVar12 == 0;
              if (bVar17) {
                iVar12 = *piVar4;
              }
              if (!bVar17 || iVar12 != 0) {
                func_0010F1F8(piVar4,ALBW_AS_F32(pppppppfVar20));
                *(int *)(iVar6 + 8) = *(int *)(iVar6 + 8) + -1;
              }
            }
          }
          uVar3 = uVar3 + 1;
        } while ((int)uVar3 < (int)local_448);
      }
    }
  }
  else {
    bVar17 = (int)local_160 < 0;
    bVar18 = local_160 != (float *******)0x0;
    if (bVar18) {
      bVar17 = ALBW_AS_F32(pppppppfVar34) < ALBW_AS_F32(local_134);
      pppppppfVar20 = local_134;
    }
    pppppppfVar35 = local_134;
    if (((bVar18 && ALBW_AS_F32(pppppppfVar34) != ALBW_AS_F32(local_134)) &&
         bVar17 == (bVar18 && (NAN(ALBW_AS_F32(pppppppfVar34)) || NAN(ALBW_AS_F32(local_134))))) &&
       ((((local_15c == (float *******)0x0 || (ALBW_AS_F32(pppppppfVar20) != ALBW_AS_F32(pppppppfVar36))) ||
         (pppppppfVar35 = pppppppfVar34, (int)param_2[10] < 2)) &&
        ((pppppppfVar34 = pppppppfVar20, pppppppfVar35 = local_134,
         *(char *)(local_1f4 + 0x31) == '\0' &&
         (ALBW_AS_F32(local_30[0x1d]) < ALBW_AS_F32(param_3[0xb]) - ALBW_AS_F32(pppppppfVar20))))))) {
      local_138 = 1;
    }
    local_134 = pppppppfVar35;
    uVar13 = 0;
    puVar15 = (uint *)local_30[1];
    uVar3 = *puVar15;
    fVar19 = DAT_0064f2c0;
    fVar21 = DAT_0064f2bc;
    pppppppfVar35 = pppppppfVar34;
    if (0 < (int)uVar3) {
      do {
        if (uVar13 < uVar3) {
          iVar12 = *(int *)(puVar15[2] + uVar13 * 4);
        }
        else {
          iVar12 = 0;
        }
        fVar23 = *(float *)(iVar12 + 0x30);
        fVar25 = *(float *)(iVar12 + 0x34);
        fVar26 = *(float *)(iVar12 + 0x38);
        fVar27 = local_1b4 * fVar23 + local_1b0 * fVar25 + local_1ac * fVar26;
        if ((fVar27 <= ALBW_AS_F32(pppppppfVar36)) && (iVar6 <= (int)ALBW_AS_U32(-fVar27))) {
          fVar27 = local_1b4 * fVar23 + local_1b0 * fVar25 + local_1ac * fVar26;
          if (((fVar27 < fVar21) || (fVar19 < fVar27)) &&
             ((pppppppfVar20 =
                    (float *******)
                    CF_FBITS((((fVar23 * *(float *)(iVar12 + 0x24) + fVar25 * *(float *)(iVar12 + 0x28) +
                      fVar26 * *(float *)(iVar12 + 0x2c)) -
                     (fVar23 * ALBW_AS_F32(local_1c0) + fVar25 * ALBW_AS_F32(local_1bc) +
                     fVar26 * ALBW_AS_F32(local_1b8))) / fVar27)),
              (int)ALBW_AS_U32((ALBW_AS_F32(pppppppfVar20) - ALBW_AS_F32(pppppppfVar35))) <= iVar6 &&
              (ALBW_AS_F32(pppppppfVar36) <= ALBW_AS_F32(pppppppfVar20))))) {
            local_1f8 = (float *******)&local_1c0;
            func_00115D70((float *)&local_154,&local_1b4,ALBW_AS_F32(pppppppfVar20));
            local_160 = local_154;
            local_15c = local_150;
            local_158 = local_14c;
            func_00115C54((float *)&local_148,(float *)local_1f8,(float *)&local_160);
            local_454 = local_148;
            local_450 = local_144;
            local_44c = local_140;
            func_00115C70((float *)&local_12c,(float *)&local_454,(float *)(iVar12 + 0x24));
            if (((int)ALBW_AS_U32((ALBW_AS_F32(local_12c) * *(float *)(iVar12 + 0x3c) +
                       ALBW_AS_F32(local_128) * *(float *)(iVar12 + 0x40) +
                      ALBW_AS_F32(local_124) * *(float *)(iVar12 + 0x44))) <= iVar6) &&
               ((((int)ALBW_AS_U32((ALBW_AS_F32(local_12c) * *(float *)(iVar12 + 0x48) +
                        ALBW_AS_F32(local_128) * *(float *)(iVar12 + 0x4c) +
                       ALBW_AS_F32(local_124) * *(float *)(iVar12 + 0x50))) <= iVar6 &&
                 (ALBW_AS_F32(local_12c) * *(float *)(iVar12 + 0x54) +
                  ALBW_AS_F32(local_128) * *(float *)(iVar12 + 0x58) +
                  ALBW_AS_F32(local_124) * *(float *)(iVar12 + 0x5c) <= *(float *)(iVar12 + 0x68) + fVar19
                 )) && (pppppppfVar20 != (float *******)0xff7fffff)))) {
              local_134 = pppppppfVar20;
              if (((uVar13 < *puVar15) && (*(int *)(puVar15[2] + uVar13 * 4) != 0)) &&
                 ((*(char *)(local_1f4 + 0x31) != '\0' ||
                  (ALBW_AS_F32(param_3[0xb]) - ALBW_AS_F32(pppppppfVar20) <= ALBW_AS_F32(local_30[0x1d]))))) {
                local_200 = (float ******)0x1;
                pppppppfVar34 = pppppppfVar20;
              }
              break;
            }
          }
        }
        uVar3 = *puVar15;
        uVar13 = uVar13 + 1;
      } while ((int)uVar13 < (int)uVar3);
    }
    pppppppfVar35 = pppppppfVar36;
    func_00115D70((float *)&local_458,&local_1cc,ALBW_AS_F32(pppppppfVar34));
    local_1ec = local_458;
    local_1e8 = local_454;
    local_1e4 = local_450;
    func_00115C54((float *)&local_190,(float *)&local_1d8,(float *)&local_1ec);
    pppppppfVar36 = (float *******)CF_FBITS((ALBW_AS_F32(param_3[0xb]) - ALBW_AS_F32(pppppppfVar34)));
    pppppppfVar20 = (float *******)CF_FBITS((ALBW_AS_F32(pppppppfVar34) - ALBW_AS_F32(param_3[0xb])));
    bVar17 = DAT_0064f6dc == ALBW_AS_F32(pppppppfVar20);
    bVar18 = ALBW_AS_F32(pppppppfVar20) <= DAT_0064f6dc;
    if (!bVar18 || bVar17) {
      bVar17 = ALBW_AS_F32(pppppppfVar20) == DAT_0064f6d8;
      bVar18 = DAT_0064f6d8 <= ALBW_AS_F32(pppppppfVar20);
    }
    if (((uint)local_200 & ~(uint)(!bVar18 || bVar17)) == 0) {
      if ((!bVar18 || bVar17) != 0) {
        func_001FE680((undefined4 *)(&local_160));
        piVar4 = local_30;
        local_160 = pppppppfVar35;
        if (local_200 != (float ******)0x0) {
          local_160 = (float *******)CF_FBITS((ALBW_AS_F32(param_3[0xb]) - ALBW_AS_F32(pppppppfVar34)));
        }
        local_140 = (float *******)*param_3;
        local_15c = local_190;
        local_158 = local_18c;
        local_154 = local_188;
        local_150 = (float *******)param_3[4];
        local_14c = (float *******)param_3[5];
        local_148 = (float *******)param_3[6];
        local_13c = (float *******)param_2[9];
        local_144 = (float *******)param_2[7];
        func_001FE680((undefined4 *)(&local_130));
        local_10c = local_13c;
        local_114 = local_144;
        func_00115E10((float *)&local_f4,(float *)&local_150,(float *)(local_140 + 0xc));
        pppppppfVar20 = (float *******)CF_FBITS(func_00115DC8((float *)&local_f4));
        pppppppfVar36 = local_140;
        func_0049F5FC(piVar4 + 6);
        uVar3 = 0;
        while( true ) {
          fVar19 = ALBW_AS_F32(uVar40);
          fVar16 = ALBW_AS_F32(((ulonglong)uVar38 >> 0x20));
          uVar13 = *(uint *)*piVar4;
          if ((int)uVar13 <= (int)uVar3) break;
          if (uVar3 < uVar13) {
            iVar6 = *(int *)(((uint *)*piVar4)[2] + uVar3 * 4);
          }
          else {
            iVar6 = 0;
          }
          func_0010F1DC(piVar4 + 6,(int *)(piVar4[9] + iVar6));
          uVar3 = uVar3 + 1;
          piVar4[8] = piVar4[8] + 1;
        }
        local_210 = pppppppfVar36;
        local_1e0 = piVar4 + 6;
        local_20c[0] = local_15c;
        local_20c[1] = local_158;
        local_20c[2] = local_154;
        local_200 = (float ******)local_f4;
        local_1fc = local_f0;
        local_1f8 = local_ec;
        local_1f4 = (float *******)pppppppfVar36[0xc];
        local_1f0 = (float *******)pppppppfVar36[0xd];
        local_1ec = (float *******)pppppppfVar36[0xe];
        local_1e8 = (float *******)(piVar4 + 0x12);
        local_1e4 = (float *******)piVar4[0x1c];
        if (local_10c == (float *******)0x0) {
          local_1dc = CF_NAN_NEG;
        }
        else {
          local_1dc = ALBW_AS_F32(((int)*local_10c + -1));
        }
        uVar3 = func_00650A24((int)piVar4,(float *)&local_130,(float *)&local_210);
        pppppppfVar36 = local_110;
        if (uVar3 < 2) {
          if (local_114 != (float *******)0x0) {
            *local_114 = (float ******)local_12c;
            local_114[1] = (float ******)local_128;
            local_114[2] = (float ******)local_124;
            piVar4[0xb] = (int)local_110;
          }
          if (local_144 != (float *******)0x0) {
            *local_144 = (float ******)local_12c;
            local_144[1] = (float ******)local_128;
            local_144[2] = (float ******)local_124;
            piVar4[0xb] = (int)local_110;
          }
LAB_0064f7e8:
          param_2[4] = (undefined4)(uintptr_t)(local_150);
          param_2[5] = (undefined4)(uintptr_t)(local_14c);
          param_2[6] = (undefined4)(uintptr_t)(local_148);
          param_2[1] = (undefined4)(uintptr_t)(local_15c);
          param_2[2] = (undefined4)(uintptr_t)(local_158);
          param_2[3] = (undefined4)(uintptr_t)(local_154);
          *param_2 = (undefined4)(uintptr_t)(local_160);
          param_2[8] = (undefined4)(uintptr_t)(local_140);
          puVar15 = (uint *)param_2[9];
          if (puVar15 != (uint *)0x0) {
            if ((uint)param_3[0xd] < *puVar15) {
              uVar3 = puVar15[2] + param_3[0xd] * 0x9c;
            }
            else {
              uVar3 = puVar15[2];
            }
            *(undefined4 *)(uVar3 + 0x30) = param_2[1];
            *(undefined4 *)(uVar3 + 0x34) = param_2[2];
            *(undefined4 *)(uVar3 + 0x38) = param_2[3];
            *(undefined4 *)(uVar3 + 0x74) = *param_2;
          }
          return 0;
        }
        if (local_110 != (float *******)0x0) {
          local_98[0] = local_110 + 0xf;
          local_98[1] = local_110 + 0x12;
          local_98[2] = local_110 + 0x15;
          pppppppfVar34 = local_130;
          func_00115C70((float *)&local_210,(float *)&local_12c,(float *)(local_110 + 9));
          local_e8 = local_210;
          local_e4 = local_20c[0];
          local_e0 = local_20c[1];
          iVar6 = -1;
          iVar12 = 0;
          do {
            ppppppfVar11 = (float ******)local_98[iVar12];
            if (EDGE_DIR_IN_RANGE(ALBW_AS_F32(*ppppppfVar11) * ALBW_AS_F32(local_150) +
                             ALBW_AS_F32(ppppppfVar11[1]) * ALBW_AS_F32(local_14c) +
                            ALBW_AS_F32(ppppppfVar11[2]) * ALBW_AS_F32(local_148))) {
              ppppppfVar2 = (float ******)
                            CF_FBITS((ALBW_AS_F32(local_210) * ALBW_AS_F32(*ppppppfVar11) +
                            ALBW_AS_F32(local_20c[0]) * ALBW_AS_F32(ppppppfVar11[1])));
              ppppppfVar28 = ppppppfVar2;
              if (iVar12 == 2) {
                ppppppfVar28 = pppppppfVar36[0x1a];
              }
              fVar21 = ALBW_AS_F32(ppppppfVar2) + ALBW_AS_F32(local_20c[1]) * ALBW_AS_F32(ppppppfVar11[2]);
              if (iVar12 == 2) {
                fVar21 = fVar21 - ALBW_AS_F32(ppppppfVar28);
              }
              if (fVar21 < ALBW_AS_F32(pppppppfVar35)) {
                fVar21 = -fVar21;
              }
              if (((int)ALBW_AS_U32(fVar21) < DAT_0064f2b0) && (fVar21 < fVar16)) {
                iVar6 = iVar12;
                fVar16 = fVar21;
              }
            }
            iVar12 = iVar12 + 1;
          } while (iVar12 < 3);
          pppppppfVar20 = local_148;
          if (-1 < iVar6) {
            func_00115E10((float *)&local_e8,(float *)&local_150,(float *)local_98[iVar6]);
            func_00115E10((float *)&local_100,(float *)&local_e8,(float *)local_98[iVar6]);
            func_00115DC8((float *)&local_100);
            pppppppfVar20 =
                 (float *******)
                 CF_FBITS((ALBW_AS_F32(local_100) * ALBW_AS_F32(piVar4[0x15]) + ALBW_AS_F32(local_fc) * ALBW_AS_F32(piVar4[0x16]) +
                 ALBW_AS_F32(local_f8) * ALBW_AS_F32(piVar4[0x17])));
            if (ALBW_AS_F32(pppppppfVar35) < ALBW_AS_F32(pppppppfVar20)) {
              pppppppfVar20 =
                   (float *******)
                   CF_FBITS(((ALBW_AS_F32(pppppppfVar34) / ALBW_AS_F32(pppppppfVar20)) *
                    (ALBW_AS_F32(pppppppfVar34) / ALBW_AS_F32(pppppppfVar20)) -
                   ALBW_AS_F32(pppppppfVar34) * ALBW_AS_F32(pppppppfVar34)));
              uVar30 = (ulonglong)(uint)ALBW_AS_U32(SQRT(ALBW_AS_F32(pppppppfVar20)));
              if (SQRT(ALBW_AS_F32(pppppppfVar20)) <= ALBW_AS_F32(piVar4[0x1b]) * fVar19) {
                func_001FE680((undefined4 *)(&local_210));
                local_1ec = local_13c;
                local_1e8 = (float *******)local_138;
                local_1f4 = local_144;
                local_d0 = local_140;
                local_cc = local_15c;
                local_c8 = local_158;
                local_c4 = local_154;
                local_c0 = -ALBW_AS_F32(local_150);
                local_bc = -ALBW_AS_F32(local_14c);
                local_b8 = -ALBW_AS_F32(local_148);
                local_b4 = local_140[0xc];
                local_b0 = local_140[0xd];
                local_ac = local_140[0xe];
                local_a0 = piVar4 + 2;
                local_a8 = DAT_00650720;
                local_a4 = (undefined4)uVar30;
                if (local_13c == (float *******)0x0) {
                  local_9c = -1;
                }
                else {
                  local_9c = (int)*local_13c + -1;
                }
                func_0049F5FC(piVar4 + 2);
                func_0049F5FC(piVar4 + 6);
                uVar3 = 0;
                while( true ) {
                  fVar16 = ALBW_AS_F32(uVar30);
                  uVar13 = *(uint *)*piVar4;
                  if ((int)uVar13 <= (int)uVar3) break;
                  if (uVar3 < uVar13) {
                    iVar6 = *(int *)(((uint *)*piVar4)[2] + uVar3 * 4);
                  }
                  else {
                    iVar6 = 0;
                  }
                  func_0010F1DC(piVar4 + 2,(int *)(iVar6 + piVar4[5]));
                  piVar4[4] = piVar4[4] + 1;
                  if (uVar3 < *(uint *)*piVar4) {
                    iVar6 = *(int *)(((uint *)*piVar4)[2] + uVar3 * 4);
                  }
                  else {
                    iVar6 = 0;
                  }
                  func_0010F1DC(piVar4 + 6,(int *)(piVar4[9] + iVar6));
                  uVar3 = uVar3 + 1;
                  piVar4[8] = piVar4[8] + 1;
                }
                func_0064CB28(piVar4,(int *)&local_210,(int *)&local_d0);
                local_140 = local_1f0;
                local_15c = local_20c[0];
                local_158 = local_20c[1];
                local_154 = local_20c[2];
                local_150 = (float *******)CF_FBITS(-ALBW_AS_F32(local_200));
                local_14c = (float *******)CF_FBITS(-ALBW_AS_F32(local_1fc));
                local_148 = (float *******)CF_FBITS(-ALBW_AS_F32(local_1f8));
                local_160 = (float *******)CF_FBITS((fVar16 - ALBW_AS_F32(local_210)));
                goto LAB_0064f7e8;
              }
            }
          }
        }
        iVar12 = param_3[0xc];
        piVar4 = (int *)(*param_3 + *(int *)(iVar12 + 0xc));
        iVar6 = piVar4[1];
        bVar17 = iVar6 == 0;
        if (bVar17) {
          iVar6 = *piVar4;
        }
        if (bVar17 && iVar6 == 0) {
          return 2;
        }
        goto code_r0x0064f980;
      }
      pppppppfVar36 = pppppppfVar34;
      if (local_138 == 0) goto LAB_0064f9a4;
      goto LAB_0064f9c4;
    }
  }
  func_001FE680((undefined4 *)(&local_210));
  piVar4 = local_30;
  local_1f0 = (float *******)*param_3;
  local_20c[0] = local_190;
  local_20c[1] = local_18c;
  local_20c[2] = local_188;
  local_200 = (float ******)param_3[4];
  local_1fc = (float *******)param_3[5];
  local_1f8 = (float *******)param_3[6];
  local_1ec = (float *******)param_2[9];
  local_1f4 = (float *******)param_2[7];
  local_210 = pppppppfVar36;
  func_001FE680((undefined4 *)(&local_160));
  local_13c = local_1ec;
  local_144 = local_1f4;
  func_00115E10((float *)&local_454,(float *)&local_200,(float *)(local_1f0 + 0xc));
  pppppppfVar20 = (float *******)CF_FBITS(func_00115DC8((float *)&local_454));
  pppppppfVar36 = local_1f0;
  func_0049F5FC(piVar4 + 6);
  uVar3 = 0;
  while( true ) {
    fVar19 = ALBW_AS_F32(uVar40);
    fVar16 = ALBW_AS_F32(((ulonglong)uVar38 >> 0x20));
    uVar13 = *(uint *)*piVar4;
    if ((int)uVar13 <= (int)uVar3) break;
    if (uVar3 < uVar13) {
      iVar6 = *(int *)(((uint *)*piVar4)[2] + uVar3 * 4);
    }
    else {
      iVar6 = 0;
    }
    func_0010F1DC(piVar4 + 6,(int *)(piVar4[9] + iVar6));
    uVar3 = uVar3 + 1;
    piVar4[8] = piVar4[8] + 1;
  }
  local_130 = pppppppfVar36;
  local_100 = (float *******)(piVar4 + 6);
  local_12c = local_20c[0];
  local_128 = local_20c[1];
  local_124 = local_20c[2];
  local_120 = local_454;
  local_11c = local_450;
  local_118 = local_44c;
  local_114 = (float *******)pppppppfVar36[0xc];
  local_110 = (float *******)pppppppfVar36[0xd];
  local_10c = (float *******)pppppppfVar36[0xe];
  local_108 = (float *******)(piVar4 + 0x12);
  local_104 = (float *******)piVar4[0x1c];
  if (local_13c == (float *******)0x0) {
    local_fc = (float ******)0xffffffff;
  }
  else {
    local_fc = (float ******)((int)*local_13c + -1);
  }
  uVar3 = func_00650A24((int)piVar4,(float *)&local_160,(float *)&local_130);
  pppppppfVar36 = local_140;
  if (1 < uVar3) {
    if (local_140 != (float *******)0x0) {
      local_98[0] = local_140 + 0xf;
      local_98[1] = local_140 + 0x12;
      local_98[2] = local_140 + 0x15;
      pppppppfVar34 = local_160;
      func_00115C70((float *)&local_130,(float *)&local_15c,(float *)(local_140 + 9));
      local_f0 = local_130;
      local_ec = local_12c;
      local_e8 = local_128;
      iVar6 = -1;
      iVar12 = 0;
      do {
        ppppppfVar11 = (float ******)local_98[iVar12];
        if (EDGE_DIR_IN_RANGE(ALBW_AS_F32(*ppppppfVar11) * ALBW_AS_F32(local_200) +
                         ALBW_AS_F32(ppppppfVar11[1]) * ALBW_AS_F32(local_1fc) +
                        ALBW_AS_F32(ppppppfVar11[2]) * ALBW_AS_F32(local_1f8))) {
          fVar21 = ALBW_AS_F32(local_130) * ALBW_AS_F32(*ppppppfVar11) +
                   ALBW_AS_F32(local_12c) * ALBW_AS_F32(ppppppfVar11[1]) +
                   ALBW_AS_F32(local_128) * ALBW_AS_F32(ppppppfVar11[2]);
          if (iVar12 == 2) {
            fVar21 = fVar21 - ALBW_AS_F32(pppppppfVar36[0x1a]);
          }
          if (fVar21 < ALBW_AS_F32(pppppppfVar35)) {
            fVar21 = -fVar21;
          }
          if (((int)ALBW_AS_U32(fVar21) < DAT_00650734) && (fVar21 < fVar16)) {
            iVar6 = iVar12;
            fVar16 = fVar21;
          }
        }
        iVar12 = iVar12 + 1;
      } while (iVar12 < 3);
      pppppppfVar20 = local_1f8;
      if (-1 < iVar6) {
        func_00115E10((float *)&local_f0,(float *)&local_200,(float *)local_98[iVar6]);
        func_00115E10((float *)&local_130,(float *)&local_f0,(float *)local_98[iVar6]);
        func_00115DC8((float *)&local_130);
        pppppppfVar20 =
             (float *******)
             CF_FBITS((ALBW_AS_F32(local_130) * ALBW_AS_F32(piVar4[0x15]) + ALBW_AS_F32(local_12c) * ALBW_AS_F32(piVar4[0x16]) +
             ALBW_AS_F32(local_128) * ALBW_AS_F32(piVar4[0x17])));
        if (ALBW_AS_F32(pppppppfVar35) < ALBW_AS_F32(pppppppfVar20)) {
          pppppppfVar20 =
               (float *******)
               CF_FBITS(((ALBW_AS_F32(pppppppfVar34) / ALBW_AS_F32(pppppppfVar20)) *
                (ALBW_AS_F32(pppppppfVar34) / ALBW_AS_F32(pppppppfVar20)) -
               ALBW_AS_F32(pppppppfVar34) * ALBW_AS_F32(pppppppfVar34)));
          uVar30 = (ulonglong)(uint)ALBW_AS_U32(SQRT(ALBW_AS_F32(pppppppfVar20)));
          if (SQRT(ALBW_AS_F32(pppppppfVar20)) <= ALBW_AS_F32(piVar4[0x1b]) * fVar19) {
            func_001FE680((undefined4 *)(&local_120));
            local_fc = (float ******)local_1ec;
            local_f8 = local_1e8;
            local_104 = local_1f4;
            local_d0 = local_1f0;
            local_cc = local_20c[0];
            local_c8 = local_20c[1];
            local_c4 = local_20c[2];
            local_c0 = -ALBW_AS_F32(local_200);
            local_bc = -ALBW_AS_F32(local_1fc);
            local_b8 = -ALBW_AS_F32(local_1f8);
            local_b4 = local_1f0[0xc];
            local_b0 = local_1f0[0xd];
            local_ac = local_1f0[0xe];
            local_a0 = piVar4 + 2;
            local_a8 = DAT_00650720;
            local_a4 = (undefined4)uVar30;
            if (local_1ec == (float *******)0x0) {
              local_9c = -1;
            }
            else {
              local_9c = (int)*local_1ec + -1;
            }
            func_0049F5FC(piVar4 + 2);
            func_0049F5FC(piVar4 + 6);
            uVar3 = 0;
            while( true ) {
              fVar16 = ALBW_AS_F32(uVar30);
              uVar13 = *(uint *)*piVar4;
              if ((int)uVar13 <= (int)uVar3) break;
              uVar10 = uVar13;
              if (uVar3 < uVar13) {
                uVar10 = ((uint *)*piVar4)[2];
              }
              if (uVar3 < uVar13) {
                iVar6 = *(int *)(uVar10 + uVar3 * 4);
              }
              else {
                iVar6 = 0;
              }
              func_0010F1DC(piVar4 + 2,(int *)(iVar6 + piVar4[5]));
              piVar4[4] = piVar4[4] + 1;
              if (uVar3 < *(uint *)*piVar4) {
                iVar6 = *(int *)(((uint *)*piVar4)[2] + uVar3 * 4);
              }
              else {
                iVar6 = 0;
              }
              func_0010F1DC(piVar4 + 6,(int *)(piVar4[9] + iVar6));
              uVar3 = uVar3 + 1;
              piVar4[8] = piVar4[8] + 1;
            }
            func_0064CB28(piVar4,(int *)&local_120,(int *)&local_d0);
            local_1f0 = local_100;
            local_20c[0] = local_11c;
            local_20c[1] = local_118;
            local_20c[2] = local_114;
            local_200 = (float ******)CF_FBITS(-ALBW_AS_F32(local_110));
            local_1fc = (float *******)CF_FBITS(-ALBW_AS_F32(local_10c));
            local_1f8 = (float *******)CF_FBITS(-ALBW_AS_F32(local_108));
            local_210 = (float *******)CF_FBITS((fVar16 - ALBW_AS_F32(local_120)));
            goto LAB_0065085c;
          }
        }
      }
    }
    iVar12 = param_3[0xc];
    piVar4 = (int *)(*param_3 + *(int *)(iVar12 + 0xc));
    iVar6 = piVar4[1];
    bVar17 = iVar6 == 0;
    if (bVar17) {
      iVar6 = *piVar4;
    }
    if (bVar17 && iVar6 == 0) {
      return 2;
    }
code_r0x0064f980:
    func_0010F1F8(piVar4,ALBW_AS_F32(pppppppfVar20));
    *(int *)(iVar12 + 8) = *(int *)(iVar12 + 8) + -1;
    return 2;
  }
  if (local_144 != (float *******)0x0) {
    *local_144 = (float ******)local_15c;
    local_144[1] = (float ******)local_158;
    local_144[2] = (float ******)local_154;
    piVar4[0xb] = (int)local_140;
  }
  if (local_1f4 != (float *******)0x0) {
    *local_1f4 = (float ******)local_15c;
    local_1f4[1] = (float ******)local_158;
    local_1f4[2] = (float ******)local_154;
    piVar4[0xb] = (int)local_140;
  }
LAB_0065085c:
  param_2[4] = (undefined4)(uintptr_t)(local_200);
  param_2[5] = (undefined4)(uintptr_t)(local_1fc);
  param_2[6] = (undefined4)(uintptr_t)(local_1f8);
  param_2[1] = (undefined4)(uintptr_t)(local_20c[0]);
  param_2[2] = (undefined4)(uintptr_t)(local_20c[1]);
  param_2[3] = (undefined4)(uintptr_t)(local_20c[2]);
  *param_2 = (undefined4)(uintptr_t)(local_210);
  param_2[8] = (undefined4)(uintptr_t)(local_1f0);
  puVar15 = (uint *)param_2[9];
  if (puVar15 != (uint *)0x0) {
    if ((uint)param_3[0xd] < *puVar15) {
      uVar3 = puVar15[2] + param_3[0xd] * 0x9c;
    }
    else {
      uVar3 = puVar15[2];
    }
    *(undefined4 *)(uVar3 + 0x30) = param_2[1];
    *(undefined4 *)(uVar3 + 0x34) = param_2[2];
    *(undefined4 *)(uVar3 + 0x38) = param_2[3];
    *(undefined4 *)(uVar3 + 0x74) = *param_2;
  }
  return 1;
}

