/* compilefix: USA 0063AEA8 (EU 0063AE80), Ghidra-derived (build/ghidra_analyzed4).
 * Failed to compile: operand of type 'float' cannot be cast to a pointer type
 * Fixed (each an exact C form of the ARM operation; the rest is the converted Ghidra text):
 *  - (T *)<float expr> -> (T *)CF_FBITS(expr): 32-bit copy of the float (vmov/vstr), never a conversion [62]
 *  - explicit casts at pointer-type mismatches (identity on the ARM) [26]
 *  - explicit (T)(uintptr_t) casts at int<->pointer mismatches (identity on the 32-bit ARM) [156]
 *  - (float)<pointer> -> ALBW_AS_F32(pointer): 32-bit copy [1]
 * Arguments restored (BOOT_LOG 166): the ARM passes r0 = the object, r1, r2 = a flag, s0, s1; the converted text
 *    declared (void) and read them as uninitialised registers. EU 001F61C8..001F61FC and 0063C1A8..0063C1E4.
 * Confidence: high for the fixes (each class checked against the EU disassembly on sample sites);
 * the function body otherwise has the fidelity of the Ghidra output (bare `return;` exits of
 * functions retyped non-void return 0, as the converter does).
 * Fixed (BOOT_LOG 184): the ARM compares the float's bits (vmov rX, sY; cmp), which the converted text
 * wrote as a conversion of the value to an integer. */
#include "ghidra_types.h"
#include "../include/ghidra_concat44.h"
#include "compilefix.h"

extern int func_00100118(int param_1,undefined *param_2,int param_3,int param_4);
extern int func_00100174(int *param_1);
extern int func_0010B3EC(undefined4 *param_1,int param_2,int param_3);
extern int func_0010F1DC(int *param_1,int *param_2);
extern int func_00115C54(float *param_1,float *param_2,float *param_3);
extern int func_00115C70(float *param_1,float *param_2,float *param_3);
extern int func_00115D70(float *param_1,float *param_2,float fparam_0);
extern int func_00115D88(float *param_1,float *param_2,float fparam_0);
extern int func_001FE514(undefined4 *param_1,undefined4 *param_2);
extern int func_001FE680(undefined4 *param_1);
extern int func_0048C258(int *param_1,undefined *param_2);
extern int func_0049F5FC(undefined4 *param_1);
extern int func_004A17A4(float *param_1);
extern int func_004A17E4(float *param_1);
extern int func_00649E18(int param_1,float *param_2,float *param_3);
extern int func_0064B4A0(int param_1,float *param_2,float *param_3);
extern int func_0064CB28(int *param_1,int *param_2,int *param_3);
extern int func_0064E9F4(int *param_1,undefined4 *param_2,int *param_3);
extern float func_0068906C(float *param_1,float *param_2);
extern undefined DAT_00000030;
extern float * * * * * * *DAT_0063b234;
extern float DAT_0063b238;
extern float * * * * * * *DAT_0063b23c;
extern float * * * * * * *DAT_0063b240;
extern int DAT_0063b244;
extern uint DAT_0063b248;
extern int DAT_0063b24c;
extern undefined *DAT_0063b250;
extern int DAT_0063c558;
extern float DAT_0063c55c;
extern uint *DAT_0063cb08;
extern uint *DAT_0063cb0c;
extern float DAT_0063cb10;
extern float DAT_0063cb14;
extern undefined *DAT_0063cb18;
extern uint *DAT_0063cb1c;
extern uint *DAT_0063cb20;
extern undefined *DAT_0063cb24;
extern int DAT_0063cb28;
extern float DAT_0063ddb0;
extern float * * * * * * *DAT_0063ddb4;
extern uint *DAT_0063ddb8;
extern float *DAT_0063ddbc;
extern uint *DAT_0063ddc0;
extern uint *DAT_0063ddc4;
extern float * * * * *DAT_0063ddc8;
extern int DAT_0063ddcc;
extern uint *DAT_0063ddd0;
extern int *DAT_0063ddd4;
extern undefined *DAT_0063ddd8;
extern int DAT_0063dddc;
extern int DAT_00640064;
extern float * * * * * * *DAT_00640068;
extern int DAT_0064006c;
extern int DAT_006411c8;
extern float DAT_006411cc;
extern int DAT_0064232c;
extern int DAT_00642330;

// USA 0063AEA8 <- EU 0063AE80 (Ghidra, non-matching)
// GLOBAL DAT_00000030 undefined
// GLOBAL DAT_0063b234 float * * * * * * *
// GLOBAL DAT_0063b238 float
// GLOBAL DAT_0063b23c float * * * * * * *
// GLOBAL DAT_0063b240 float * * * * * * *
// GLOBAL DAT_0063b244 int
// GLOBAL DAT_0063b248 uint
// GLOBAL DAT_0063b24c int
// GLOBAL DAT_0063b250 undefined *
// GLOBAL DAT_0063c558 int
// GLOBAL DAT_0063c55c float
// GLOBAL DAT_0063cb08 uint *
// GLOBAL DAT_0063cb0c uint *
// GLOBAL DAT_0063cb10 float
// GLOBAL DAT_0063cb14 float
// GLOBAL DAT_0063cb18 undefined *
// GLOBAL DAT_0063cb1c uint *
// GLOBAL DAT_0063cb20 uint *
// GLOBAL DAT_0063cb24 undefined *
// GLOBAL DAT_0063cb28 int
// GLOBAL DAT_0063ddb0 float
// GLOBAL DAT_0063ddb4 float * * * * * * *
// GLOBAL DAT_0063ddb8 uint *
// GLOBAL DAT_0063ddbc float *
// GLOBAL DAT_0063ddc0 uint *
// GLOBAL DAT_0063ddc4 uint *
// GLOBAL DAT_0063ddc8 float * * * * *
// GLOBAL DAT_0063ddcc int
// GLOBAL DAT_0063ddd0 uint *
// GLOBAL DAT_0063ddd4 int *
// GLOBAL DAT_0063ddd8 undefined *
// GLOBAL DAT_0063dddc int
// GLOBAL DAT_00640064 int
// GLOBAL DAT_00640068 float * * * * * * *
// GLOBAL DAT_0064006c int
// GLOBAL DAT_006411c8 int
// GLOBAL DAT_006411cc float
// GLOBAL DAT_0064232c int
// GLOBAL DAT_00642330 int

/* WARNING: Removing unreachable block (ram,0x0063bdbc) */
/* WARNING: Removing unreachable block (ram,0x0063bf78) */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Restarted to delay deadcode elimination for space: stack */
/* WARNING: Unknown calling convention */

float func_0063AEA8(float ***********arg_r0,int arg_r1,int arg_r2,float fparam_0,float fparam_1)

{
  int *piVar1;
  int iVar2;
  uint *puVar3;
  float *************in_r0;
  float *************pppppppppppppfVar4;
  float ************ppppppppppppfVar5;
  int iVar6;
  float *pfVar7;
  int in_r1;
  float ***********pppppppppppfVar8;
  float ************ppppppppppppfVar9;
  float ***********pppppppppppfVar10;
  float ***********pppppppppppfVar11;
  float ***********pppppppppppfVar12;
  float ***********pppppppppppfVar13;
  undefined4 *puVar14;
  uint uVar15;
  uint uVar16;
  undefined4 *puVar17;
  undefined4 *puVar18;
  float *********pppppppppfVar19;
  float ***********extraout_r1;
  float ***********extraout_r1_00;
  float ***********extraout_r1_01;
  float *************extraout_r1_02;
  float *************extraout_r1_03;
  float *************extraout_r1_04;
  int in_r2;
  uint *puVar20;
  uint *puVar21;
  uint uVar22;
  int *piVar23;
  float *************pppppppppppppfVar24;
  float ************ppppppppppppfVar25;
  float *pfVar26;
  float *************pppppppppppppfVar27;
  float ************ppppppppppppfVar28;
  float *pfVar29;
  float *************pppppppppppppfVar30;
  float *************pppppppppppppfVar31;
  float ************ppppppppppppfVar32;
  float ************ppppppppppppfVar33;
  float *****pppppfVar34;
  float *************pppppppppppppfVar35;
  float *************pppppppppppppfVar36;
  bool bVar37;
  bool bVar38;
  bool bVar39;
  uint in_s0;
  float ************ppppppppppppfVar40;
  float fVar41;
  float fVar42;
  float **********ppppppppppfVar43;
  float **********ppppppppppfVar44;
  float *******pppppppfVar45;
  float **********in_s1;
  float **********ppppppppppfVar46;
  float fVar47;
  longlong lVar48;
  undefined8 uVar49;
  float ***********pppppppppppfVar52;
  ulonglong uVar50;
  ulonglong uVar51;
  float fVar53;
  float fVar54;
  float fVar55;
  undefined8 uVar56;
  undefined4 uVar57;
  longlong lVar58;
  undefined4 uVar59;
  ulonglong uVar60;
  _Alignas(8) unsigned char albw_frame[0x1ef0];
  #define local_1ef0 (*(float ************ *)(albw_frame + 0x0))
  #define local_1eec (*(float ************ *)(albw_frame + 0x4))
  #define local_1ee8 (*(float ************ *)(albw_frame + 0x8))
  #define local_1ee4 (*(float *********** *)(albw_frame + 0xc))
  #define local_1ee0 (*(float ************ *)(albw_frame + 0x10))
  #define local_1edc (*(float *********** *)(albw_frame + 0x14))
  #define local_1ed8 (*(float ************ *)(albw_frame + 0x18))
  #define local_1ed4 (*(float ************ *)(albw_frame + 0x1c))
  #define local_1ed0 (*(float *********** *)(albw_frame + 0x20))
  #define local_1ecc (*(float ************ *)(albw_frame + 0x24))
  #define local_1ec8 (*(float ************ *)(albw_frame + 0x28))
  #define local_1ec4 (*(float ************ *)(albw_frame + 0x2c))
  #define local_1ec0 ((float *)(albw_frame + 0x30))
  #define local_1e9c (*(float ************ *)(albw_frame + 0x54))
  #define local_1e98 (*(undefined4 *)(albw_frame + 0x58))
  #define local_1e90 (*(float ************ *)(albw_frame + 0x60))
  #define local_1e8c (*(float ************ *)(albw_frame + 0x64))
  #define local_1e88 (*(float ************ *)(albw_frame + 0x68))
  #define local_1e84 (*(float ************ *)(albw_frame + 0x6c))
  #define local_1e80 (*(float ************ *)(albw_frame + 0x70))
  #define local_1e7c (*(float ************ *)(albw_frame + 0x74))
  #define local_1e78 (*(float ************ *)(albw_frame + 0x78))
  #define local_1e74 (*(float *********** *)(albw_frame + 0x7c))
  #define local_1e70 (*(float ************ *)(albw_frame + 0x80))
  #define local_1e6c (*(float *********** *)(albw_frame + 0x84))
  #define local_1e68 (*(float *********** *)(albw_frame + 0x88))
  #define local_1e64 (*(float ************ *)(albw_frame + 0x8c))
  #define local_1e60 (*(float *********** *)(albw_frame + 0x90))
  #define local_1e5c (*(float ************* *)(albw_frame + 0x94))
  #define local_1e58 (*(float ************ *)(albw_frame + 0x98))
  #define local_1e54 (*(float *********** *)(albw_frame + 0x9c))
  #define local_1e50 (*(float *********** *)(albw_frame + 0xa0))
  #define local_1e4c (*(float *********** *)(albw_frame + 0xa4))
  #define local_1e48 (*(float ************ *)(albw_frame + 0xa8))
  #define local_1e44 (*(float ************ *)(albw_frame + 0xac))
  #define local_1e40 (*(float *********** *)(albw_frame + 0xb0))
  #define local_1e3c (*(float *********** *)(albw_frame + 0xb4))
  #define local_1e38 (*(float *********** *)(albw_frame + 0xb8))
  #define local_1e34 (*(float *********** *)(albw_frame + 0xbc))
  #define local_1e30 (*(float ************ *)(albw_frame + 0xc0))
  #define local_1e2c (*(float ************ *)(albw_frame + 0xc4))
  #define local_1e28 (*(float *********** *)(albw_frame + 0xc8))
  #define local_1e24 (*(float *********** *)(albw_frame + 0xcc))
  #define local_1e20 (*(float ************ *)(albw_frame + 0xd0))
  #define local_1e1c (*(float ************* *)(albw_frame + 0xd4))
  #define local_1e18 (*(float *********** *)(albw_frame + 0xd8))
  #define local_1e14 (*(float *********** *)(albw_frame + 0xdc))
  #define local_1e10 (*(float ************ *)(albw_frame + 0xe0))
  #define local_1e0c (*(float ************ *)(albw_frame + 0xe4))
  #define local_1e08 (*(float *********** *)(albw_frame + 0xe8))
  #define local_1e04 (*(float ************ *)(albw_frame + 0xec))
  #define local_1e00 (*(float ************ *)(albw_frame + 0xf0))
  #define ppppppppppppfStack_1dfc (*(float ************ *)(albw_frame + 0xf4))
  #define local_1df8 (*(float *********** *)(albw_frame + 0xf8))
  #define local_1df4 (*(float *********** *)(albw_frame + 0xfc))
  #define local_1df0 (*(float *********** *)(albw_frame + 0x100))
  #define local_1dec (*(float *********** *)(albw_frame + 0x104))
  #define local_1de8 (*(float *********** *)(albw_frame + 0x108))
  #define local_1de4 (*(float ************ *)(albw_frame + 0x10c))
  #define local_1de0 (*(float ************* *)(albw_frame + 0x110))
  #define local_1ddc (*(float ************* *)(albw_frame + 0x114))
  #define local_1dd8 (*(float *********** *)(albw_frame + 0x118))
  #define local_1dd4 (*(float *********** *)(albw_frame + 0x11c))
  #define local_1dd0 (*(float ************* *)(albw_frame + 0x120))
  #define local_1dcc (*(float ************ *)(albw_frame + 0x124))
  #define local_1dc8 (*(undefined4 *)(albw_frame + 0x128))
  #define local_1dc4 (*(float ************ *)(albw_frame + 0x12c))
  #define local_1dc0 (*(float *********** *)(albw_frame + 0x130))
  #define local_1dbc (*(float *********** *)(albw_frame + 0x134))
  #define local_1db8 (*(float ************* *)(albw_frame + 0x138))
  #define local_30 (*(float ************* *)(albw_frame + 0x1ec0))
  #define local_2c (*(int *)(albw_frame + 0x1ec4))
  #define local_28 (*(int *)(albw_frame + 0x1ec8))
  in_r0 = arg_r0;
  in_r1 = arg_r1;
  in_r2 = arg_r2;
  in_s0 = ALBW_AS_U32(fparam_0);
  in_s1 = (float **********)CF_FBITS(fparam_1);
  lVar48 = (ulonglong)in_s0 << 0x20;
  uVar50 = ZEXT48(DAT_0063b234);
  ppppppppppppfVar5 = (float ************)DAT_0063b234;
  local_30 = in_r0;
  local_2c = in_r1;
  local_28 = in_r2;
  func_001FE680((undefined4 *)(&local_1e88));
  pppppppppppppfVar30 = local_30;
  local_1e64 = (float ************)(local_30 + 0x29);
  pppppppppppfVar8 = *local_1e64;
  if ((int)pppppppppppfVar8 < (int)local_30[0x2a]) {
    *local_1e64 = (float ***********)((int)pppppppppppfVar8 + 1);
    ppppppppppppfVar9 = local_30[0x2b] + (int)pppppppppppfVar8 * 0x27;
  }
  else {
    ppppppppppppfVar9 = (float ************)0x0;
  }
  local_1e2c = (float ************)((ulonglong)lVar48 >> 0x20);
  ppppppppppppfVar9[0x1c] = (float ***********)local_1e2c;
  fVar41 = DAT_0063b238;
  ppppppppppppfVar40 = (float ************)CF_FBITS((ALBW_AS_F32(local_1e2c) * DAT_0063b238));
  ppppppppppppfVar9[9] = (float ***********)local_30[0xc];
  ppppppppppppfVar9[10] = (float ***********)local_30[0xd];
  ppppppppppppfVar9[0xb] = (float ***********)local_30[0xe];
  *(undefined1 *)(ppppppppppppfVar9 + 0x24) = 0;
  local_30[0x1d] = ppppppppppppfVar40;
  local_1e60 = (float ***********)0x0;
  local_1e58 = local_30[10];
  local_1e54 = (float ***********)local_30[0xc];
  local_1e50 = (float ***********)local_30[0xd];
  local_1e4c = (float ***********)local_30[0xe];
  local_1e48 = (float ************)CF_FBITS(-ALBW_AS_F32(local_30[0x12]));
  local_1e40 = (float ***********)CF_FBITS(-ALBW_AS_F32(local_30[0x14]));
  local_1e44 = (float ************)CF_FBITS(-ALBW_AS_F32(local_30[0x13]));
  ppppppppppppfVar9 = local_30[10];
  local_1e3c = ppppppppppppfVar9[0xc];
  local_1e38 = ppppppppppppfVar9[0xd];
  local_1e34 = ppppppppppppfVar9[0xe];
  local_1e28 = (float ***********)(local_30 + 2);
  local_1e30 = (float ************)DAT_0063b23c;
  local_1e04 = local_1e64;
  local_1df8 = local_1e28;
  if (local_1e64 != (float ************)0x0) {
    ppppppppppppfVar9 = local_30[0x2b] + (int)*local_1e64 * 0x27 + -0x27;
    *ppppppppppppfVar9 = (float ***********)local_1e48;
    ppppppppppppfVar9[1] = (float ***********)local_1e44;
    ppppppppppppfVar9[2] = local_1e40;
    ppppppppppppfVar9[6] = local_1e3c;
    ppppppppppppfVar9[7] = local_1e38;
    ppppppppppppfVar9[8] = local_1e34;
    func_004A17A4((float *)ppppppppppppfVar9);
    local_1e24 = (float ***********)((int)*local_1e64 + -1);
  }
  func_0049F5FC((undefined4 *)(pppppppppppppfVar30 + 2));
  func_0049F5FC((undefined4 *)(pppppppppppppfVar30 + 6));
  pppppppppppfVar8 = (float ***********)0x0;
  while( true ) {
    pppppppppppfVar13 = (float ***********)uVar50;
    ppppppppppppfVar9 = *pppppppppppppfVar30;
    pppppppppppfVar10 = *ppppppppppppfVar9;
    if ((int)pppppppppppfVar10 <= (int)pppppppppppfVar8) break;
    if (pppppppppppfVar8 < pppppppppppfVar10) {
      ppppppppppppfVar9 = (float ************)ppppppppppppfVar9[2];
    }
    if (pppppppppppfVar8 < pppppppppppfVar10) {
      pppppppppppfVar10 = ppppppppppppfVar9[(int)pppppppppppfVar8];
    }
    else {
      pppppppppppfVar10 = (float ***********)0x0;
    }
    func_0010F1DC((int *)(pppppppppppppfVar30 + 2),
                  (int *)((int)pppppppppppppfVar30[5] + (int)pppppppppppfVar10));
    pppppppppppppfVar30[4] = (float ************)((int)pppppppppppppfVar30[4] + 1);
    ppppppppppppfVar9 = *pppppppppppppfVar30;
    pppppppppppfVar10 = *ppppppppppppfVar9;
    if (pppppppppppfVar8 < pppppppppppfVar10) {
      ppppppppppppfVar9 = (float ************)ppppppppppppfVar9[2];
    }
    if (pppppppppppfVar8 < pppppppppppfVar10) {
      pppppppppppfVar10 = ppppppppppppfVar9[(int)pppppppppppfVar8];
    }
    else {
      pppppppppppfVar10 = (float ***********)0x0;
    }
    func_0010F1DC((int *)(pppppppppppppfVar30 + 6),
                  (int *)((int)pppppppppppppfVar30[9] + (int)pppppppppppfVar10));
    pppppppppppfVar8 = (float ***********)((int)pppppppppppfVar8 + 1);
    pppppppppppppfVar30[8] = (float ************)((int)pppppppppppppfVar30[8] + 1);
  }
  func_0064E9F4((int *)pppppppppppppfVar30,(undefined4 *)(&local_1e88),(int *)&local_1e58);
  pppppppppppfVar8 = (float ***********)DAT_0063b240;
  if (local_1e68 == (float ***********)0x0) {
    return ALBW_AS_F32(DAT_0063b240);
  }
  lVar58 = (ulonglong)DAT_0063b248 << 0x20;
  local_30[0xedf] = local_1e84;
  local_30[0xee0] = local_1e80;
  local_30[0xee1] = local_1e7c;
  local_30[0xee5] = (float ************)local_1e68[0xc];
  local_30[0xee6] = (float ************)local_1e68[0xd];
  local_30[0xee7] = (float ************)local_1e68[0xe];
  if (DAT_0063b244 < (int)local_1e88) {
    lVar48 = CONCAT44((int)((ulonglong)lVar48 >> 0x20),pppppppppppfVar13);
    if ((ALBW_AS_F32(local_30[0x1e]) != ALBW_AS_F32(pppppppppppfVar13)) && (DAT_0063b24c < (int)local_1e88)) {
      return ALBW_AS_F32(local_1e88);
    }
    local_1de0 = (float *************)&local_1ddc;
    local_1de4 = (float ************)&DAT_00000030;
    local_1de8 = (float ***********)0x0;
    ppppppppppppfVar5 = local_1e88;
    func_00100118((int)local_1de0,DAT_0063b250,0x9c,0x30);
    pppppppppppppfVar30 = local_30;
    if ((int)local_1de8 < (int)local_1de4) {
      pppppppppppppfVar4 = local_1de0 + (int)local_1de8 * 0x27;
      local_1de8 = (float ***********)((int)local_1de8 + 1);
    }
    else {
      pppppppppppppfVar4 = (float *************)0x0;
    }
    pppppppppppppfVar4[0x1c] = ppppppppppppfVar5;
    pppppppppppppfVar4[9] = local_30[0xc];
    pppppppppppppfVar4[10] = local_30[0xd];
    pppppppppppppfVar4[0xb] = local_30[0xe];
    *(undefined1 *)(pppppppppppppfVar4 + 0x24) = 1;
    func_001FE680((undefined4 *)(&local_1ef0));
    local_1ed4 = &local_1e14;
    local_1ecc = &local_1de8;
    if (ALBW_AS_F32(local_1e88) <= ALBW_AS_F32(lVar48)) {
      local_1e2c = (float ************)CF_FBITS(-ALBW_AS_F32(local_1e88));
      lVar58 = CONCAT44((int)((ulonglong)lVar58 >> 0x20),local_1e2c);
      pppppppppppppfVar30[0x1d] = (float ************)CF_FBITS(-(fVar41 * ALBW_AS_F32(local_1e88)));
      local_1ec8 = (float ************)0x0;
      local_1e58 = pppppppppppppfVar30[10];
      local_1e54 = (float ***********)pppppppppppppfVar30[0xc];
      local_1e50 = (float ***********)pppppppppppppfVar30[0xd];
      local_1e4c = (float ***********)pppppppppppppfVar30[0xe];
      local_1e48 = (float ************)CF_FBITS(-ALBW_AS_F32(pppppppppppppfVar30[0x12]));
      local_1e40 = (float ***********)CF_FBITS(-ALBW_AS_F32(pppppppppppppfVar30[0x14]));
      local_1e44 = (float ************)CF_FBITS(-ALBW_AS_F32(pppppppppppppfVar30[0x13]));
      ppppppppppppfVar9 = pppppppppppppfVar30[10];
      local_1e3c = ppppppppppppfVar9[0xc];
      local_1e38 = ppppppppppppfVar9[0xd];
      local_1e34 = ppppppppppppfVar9[0xe];
      local_1e30 = (float ************)DAT_0063b23c;
      local_1e28 = local_1df8;
      if (&local_1de8 != (float ************)0x0) {
        pppppppppppppfVar4 = local_1de0 + (int)local_1de8 * 0x27 + -0x27;
        *pppppppppppppfVar4 = local_1e48;
        pppppppppppppfVar4[1] = local_1e44;
        pppppppppppppfVar4[2] = (float ************)local_1e40;
        pppppppppppppfVar4[6] = (float ************)local_1e3c;
        pppppppppppppfVar4[7] = (float ************)local_1e38;
        pppppppppppppfVar4[8] = (float ************)local_1e34;
        func_004A17A4((float *)pppppppppppppfVar4);
        local_1e24 = (float ***********)((int)*local_1ecc + -1);
      }
      func_0049F5FC((undefined4 *)(pppppppppppppfVar30 + 2));
      func_0049F5FC((undefined4 *)(pppppppppppppfVar30 + 6));
      pppppppppppfVar10 = (float ***********)0x0;
      while( true ) {
        ppppppppppppfVar9 = *pppppppppppppfVar30;
        pppppppppppfVar11 = *ppppppppppppfVar9;
        if ((int)pppppppppppfVar11 <= (int)pppppppppppfVar10) break;
        if (pppppppppppfVar10 < pppppppppppfVar11) {
          ppppppppppppfVar9 = (float ************)ppppppppppppfVar9[2];
        }
        if (pppppppppppfVar10 < pppppppppppfVar11) {
          pppppppppppfVar11 = ppppppppppppfVar9[(int)pppppppppppfVar10];
        }
        else {
          pppppppppppfVar11 = (float ***********)0x0;
        }
        func_0010F1DC((int *)(pppppppppppppfVar30 + 2),
                      (int *)((int)pppppppppppppfVar30[5] + (int)pppppppppppfVar11));
        pppppppppppppfVar30[4] = (float ************)((int)pppppppppppppfVar30[4] + 1);
        ppppppppppppfVar9 = *pppppppppppppfVar30;
        pppppppppppfVar11 = *ppppppppppppfVar9;
        if (pppppppppppfVar10 < pppppppppppfVar11) {
          ppppppppppppfVar9 = (float ************)ppppppppppppfVar9[2];
        }
        if (pppppppppppfVar10 < pppppppppppfVar11) {
          pppppppppppfVar11 = ppppppppppppfVar9[(int)pppppppppppfVar10];
        }
        else {
          pppppppppppfVar11 = (float ***********)0x0;
        }
        func_0010F1DC((int *)(pppppppppppppfVar30 + 6),
                      (int *)((int)pppppppppppppfVar30[9] + (int)pppppppppppfVar11));
        pppppppppppfVar10 = (float ***********)((int)pppppppppppfVar10 + 1);
        pppppppppppppfVar30[8] = (float ************)((int)pppppppppppppfVar30[8] + 1);
      }
      func_0064E9F4((int *)pppppppppppppfVar30,(undefined4 *)(&local_1ef0),(int *)&local_1e58);
      ppppppppppppfVar9 =
           (float ************)
           CF_FBITS((ALBW_AS_F32(pppppppppppppfVar30[0x1e]) - (ALBW_AS_F32(lVar58) - ALBW_AS_F32(local_1ef0))));
    }
    else {
      pppppppppppppfVar30[0x1d] = (float ************)CF_FBITS((ALBW_AS_F32(local_1e88) * fVar41));
      local_1ec8 = (float ************)0x0;
      local_1e58 = pppppppppppppfVar30[10];
      local_1e54 = (float ***********)pppppppppppppfVar30[0xc];
      local_1e50 = (float ***********)pppppppppppppfVar30[0xd];
      local_1e4c = (float ***********)pppppppppppppfVar30[0xe];
      local_1e48 = pppppppppppppfVar30[0x12];
      local_1e44 = pppppppppppppfVar30[0x13];
      local_1e40 = (float ***********)pppppppppppppfVar30[0x14];
      ppppppppppppfVar9 = pppppppppppppfVar30[10];
      local_1e3c = ppppppppppppfVar9[0xc];
      local_1e38 = ppppppppppppfVar9[0xd];
      local_1e34 = ppppppppppppfVar9[0xe];
      local_1e30 = (float ************)DAT_0063b23c;
      local_1e28 = local_1df8;
      local_1e2c = local_1e88;
      if (&local_1de8 != (float ************)0x0) {
        pppppppppppppfVar4 = local_1de0 + (int)local_1de8 * 0x27 + -0x27;
        *pppppppppppppfVar4 = local_1e48;
        pppppppppppppfVar4[1] = local_1e44;
        pppppppppppppfVar4[2] = (float ************)local_1e40;
        pppppppppppppfVar4[6] = (float ************)local_1e3c;
        pppppppppppppfVar4[7] = (float ************)local_1e38;
        pppppppppppppfVar4[8] = (float ************)local_1e34;
        func_004A17A4((float *)pppppppppppppfVar4);
        local_1e24 = (float ***********)((int)*local_1ecc + -1);
      }
      func_0049F5FC((undefined4 *)(pppppppppppppfVar30 + 2));
      func_0049F5FC((undefined4 *)(pppppppppppppfVar30 + 6));
      pppppppppppfVar10 = (float ***********)0x0;
      while( true ) {
        ppppppppppppfVar9 = *pppppppppppppfVar30;
        pppppppppppfVar11 = *ppppppppppppfVar9;
        if ((int)pppppppppppfVar11 <= (int)pppppppppppfVar10) break;
        if (pppppppppppfVar10 < pppppppppppfVar11) {
          ppppppppppppfVar9 = (float ************)ppppppppppppfVar9[2];
        }
        if (pppppppppppfVar10 < pppppppppppfVar11) {
          pppppppppppfVar11 = ppppppppppppfVar9[(int)pppppppppppfVar10];
        }
        else {
          pppppppppppfVar11 = (float ***********)0x0;
        }
        func_0010F1DC((int *)(pppppppppppppfVar30 + 2),
                      (int *)((int)pppppppppppppfVar30[5] + (int)pppppppppppfVar11));
        pppppppppppppfVar30[4] = (float ************)((int)pppppppppppppfVar30[4] + 1);
        ppppppppppppfVar9 = *pppppppppppppfVar30;
        pppppppppppfVar11 = *ppppppppppppfVar9;
        if (pppppppppppfVar10 < pppppppppppfVar11) {
          ppppppppppppfVar9 = (float ************)ppppppppppppfVar9[2];
        }
        if (pppppppppppfVar10 < pppppppppppfVar11) {
          pppppppppppfVar11 = ppppppppppppfVar9[(int)pppppppppppfVar10];
        }
        else {
          pppppppppppfVar11 = (float ***********)0x0;
        }
        func_0010F1DC((int *)(pppppppppppppfVar30 + 6),
                      (int *)((int)pppppppppppppfVar30[9] + (int)pppppppppppfVar11));
        pppppppppppfVar10 = (float ***********)((int)pppppppppppfVar10 + 1);
        pppppppppppppfVar30[8] = (float ************)((int)pppppppppppppfVar30[8] + 1);
      }
      func_0064CB28((int *)pppppppppppppfVar30,(int *)&local_1ef0,(int *)&local_1e58);
      ppppppppppppfVar9 =
           (float ************)
           CF_FBITS((ALBW_AS_F32(pppppppppppppfVar30[0x1e]) + (ALBW_AS_F32(local_1e88) - ALBW_AS_F32(local_1ef0))));
    }
    pppppppppppppfVar30[0x1e] = ppppppppppppfVar9;
    if (local_1ed0 != (float ***********)0x0) {
      *(float ***********)(DAT_0063c558 + (int)pppppppppppppfVar30) = *local_1ed0;
      pppppppppppppfVar30[0xc] = local_1eec;
      pppppppppppppfVar30[0xd] = local_1ee8;
      pppppppppppppfVar30[0xe] = (float ************)local_1ee4;
      if (pppppppppppppfVar30[10] != (float ************)local_1ed0) {
        pppppppppppppfVar30[10] = (float ************)local_1ed0;
        pppppppppppppfVar30[0x18] = (float ************)local_1ed0[0xc];
        pppppppppppppfVar30[0x19] = (float ************)local_1ed0[0xd];
        pppppppppppppfVar30[0x1a] = (float ************)local_1ed0[0xe];
        pppppppfVar45 = DAT_0063b23c;
        pppppppppppppfVar30[0x15] = (float ************)*DAT_0063b23c;
        pppppppppppppfVar30[0x16] = (float ************)pppppppfVar45[1];
        pppppppppppppfVar30[0x17] = (float ************)pppppppfVar45[2];
        func_004A17E4((float *)(pppppppppppppfVar30 + 0x12));
      }
      pppppppppppppfVar30[0xf] = (float ************)local_1e14;
      pppppppppppppfVar30[0x10] = local_1e10;
      pppppppppppppfVar30[0x11] = local_1e0c;
    }
    local_1e88 = local_1ef0;
    if ((int)ALBW_AS_U32(DAT_0063c55c) < (int)local_1ef0) {
      return ALBW_AS_F32(local_1ef0);
    }
    if (local_1de8 == (float ***********)0x1) {
      if (*local_1e64 == (float ***********)0x0) {
        pppppppppppfVar10 = (float ***********)0x0;
      }
      else {
        pppppppppppfVar10 = local_1e64[2];
      }
      pppppppppppfVar10[9] = (float **********)local_30[0xc];
      pppppppppppfVar10[10] = (float **********)local_30[0xd];
      pppppppppppfVar10[0xb] = (float **********)local_30[0xe];
      pppppppppppfVar10[0x1c] =
           (float **********)CF_FBITS((ALBW_AS_F32(((ulonglong)lVar48 >> 0x20)) + ALBW_AS_F32(ppppppppppppfVar5)));
    }
    else {
      pppppppppppppfVar30 = (float *************)0x0;
      if (*local_1e64 == (float ***********)0x0) {
        pppppppppppfVar10 = (float ***********)0x0;
      }
      else {
        pppppppppppfVar10 = local_1e64[2];
      }
      if (0 < (int)local_1de8) {
        fVar47 = ALBW_AS_F32(((ulonglong)lVar58 >> 0x20));
        pppppppppppppfVar4 = (float *************)0x0;
        do {
          pppppppppppppfVar35 = local_1de0;
          if (pppppppppppppfVar30 < local_1de8) {
            pppppppppppppfVar35 = local_1de0 + (int)pppppppppppppfVar30 * 0x27;
          }
          fVar55 = ALBW_AS_F32(((ulonglong)lVar48 >> 0x20));
          if (((ALBW_AS_F32(pppppppppppfVar10[6]) == ALBW_AS_F32(pppppppppppppfVar35[6])) &&
              (ALBW_AS_F32(pppppppppppfVar10[7]) == ALBW_AS_F32(pppppppppppppfVar35[7]))) &&
             (ALBW_AS_F32(pppppppppppfVar10[8]) == ALBW_AS_F32(pppppppppppppfVar35[8]))) {
            pppppppppppfVar10[9] = (float **********)pppppppppppppfVar35[0xc];
            pppppppppppfVar10[10] = (float **********)pppppppppppppfVar35[0xd];
            pppppppppppfVar10[0xb] = (float **********)pppppppppppppfVar35[0xe];
            lVar48 = CONCAT44(fVar55,ALBW_AS_F32(pppppppppppppfVar35[0x1c]) -
                                     ALBW_AS_F32(pppppppppppppfVar35[0x1d]));
            pppppppppppfVar10[0x1c] =
                 (float **********)
                 CF_FBITS((fVar55 + (ALBW_AS_F32(pppppppppppppfVar35[0x1c]) - ALBW_AS_F32(pppppppppppppfVar35[0x1d]))));
            pppppppppppppfVar35 = pppppppppppppfVar4;
          }
          else {
            ppppppppppppfVar9 = pppppppppppppfVar35[0x1d];
            *(undefined1 *)(pppppppppppppfVar35 + 0x24) = 0;
            if (pppppppppppppfVar4 == (float *************)0x0) {
              ppppppppppppfVar40 = (float ************)pppppppppppfVar10[0x1c];
            }
            else {
              ppppppppppppfVar40 = pppppppppppppfVar4[0x1c];
            }
            pppppppppppppfVar35[0x1d] = ppppppppppppfVar40;
            fVar53 = (ALBW_AS_F32(pppppppppppppfVar35[0x1c]) - ALBW_AS_F32(ppppppppppppfVar9)) + ALBW_AS_F32(lVar48);
            lVar48 = CONCAT44(fVar55,fVar53);
            pppppppppppppfVar35[0x1c] = (float ************)CF_FBITS((fVar55 + fVar53));
            ppppppppppppfVar9 = pppppppppppppfVar35[9];
            ppppppppppppfVar40 = pppppppppppppfVar35[10];
            ppppppppppppfVar25 = pppppppppppppfVar35[0xb];
            pppppppppppppfVar35[9] = pppppppppppppfVar35[0xc];
            pppppppppppppfVar35[10] = pppppppppppppfVar35[0xd];
            pppppppppppppfVar35[0xb] = pppppppppppppfVar35[0xe];
            pppppppppppppfVar35[0xc] = ppppppppppppfVar9;
            pppppppppppppfVar35[0xd] = ppppppppppppfVar40;
            pppppppppppppfVar35[0xe] = ppppppppppppfVar25;
            func_00115D70((float *)pppppppppppppfVar35,(float *)pppppppppppppfVar35,fVar47);
            func_00115D70((float *)(pppppppppppppfVar35 + 3),(float *)(pppppppppppppfVar35 + 3),
                          fVar47);
            pppppppppppfVar11 = *local_1e64;
            if ((int)pppppppppppfVar11 < (int)local_1e64[1]) {
              *local_1e64 = (float ***********)((int)pppppppppppfVar11 + 1);
              pppppppppppfVar11 = local_1e64[2] + (int)pppppppppppfVar11 * 0x27;
              local_1ed0 = pppppppppppfVar11 + 0xc;
              *pppppppppppfVar11 = (float **********)*pppppppppppppfVar35;
              pppppppppppfVar11[1] = (float **********)pppppppppppppfVar35[1];
              local_1ec8 = (float ************)(pppppppppppppfVar35 + 0xf);
              local_1ee4 = pppppppppppfVar11 + 0xf;
              pppppppppppfVar11[2] = (float **********)pppppppppppppfVar35[2];
              pppppppppppfVar11[3] = (float **********)pppppppppppppfVar35[3];
              pppppppppppfVar11[4] = (float **********)pppppppppppppfVar35[4];
              pppppppppppfVar11[5] = (float **********)pppppppppppppfVar35[5];
              pppppppppppfVar11[6] = (float **********)pppppppppppppfVar35[6];
              pppppppppppfVar11[7] = (float **********)pppppppppppppfVar35[7];
              pppppppppppfVar11[8] = (float **********)pppppppppppppfVar35[8];
              pppppppppppfVar11[9] = (float **********)pppppppppppppfVar35[9];
              pppppppppppfVar11[10] = (float **********)pppppppppppppfVar35[10];
              pppppppppppfVar11[0xb] = (float **********)pppppppppppppfVar35[0xb];
              *local_1ed0 = (float **********)pppppppppppppfVar35[0xc];
              pppppppppppfVar11[0xd] = (float **********)pppppppppppppfVar35[0xd];
              pppppppppppfVar11[0xe] = (float **********)pppppppppppppfVar35[0xe];
              *local_1ee4 = (float **********)*local_1ec8;
              pppppppppppfVar11[0x10] = (float **********)pppppppppppppfVar35[0x10];
              pppppppppppfVar11[0x11] = (float **********)pppppppppppppfVar35[0x11];
              pppppppppppfVar11[0x12] = (float **********)pppppppppppppfVar35[0x12];
              pppppppppppfVar11[0x13] = (float **********)pppppppppppppfVar35[0x13];
              pppppppppppfVar11[0x14] = (float **********)pppppppppppppfVar35[0x14];
              pppppppppppfVar11[0x15] = (float **********)pppppppppppppfVar35[0x15];
              pppppppppppfVar11[0x16] = (float **********)pppppppppppppfVar35[0x16];
              pppppppppppfVar11[0x17] = (float **********)pppppppppppppfVar35[0x17];
              pppppppppppfVar11[0x18] = (float **********)pppppppppppppfVar35[0x18];
              pppppppppppfVar11[0x19] = (float **********)pppppppppppppfVar35[0x19];
              pppppppppppfVar11[0x1a] = (float **********)pppppppppppppfVar35[0x1a];
              pppppppppppfVar11[0x1b] = (float **********)pppppppppppppfVar35[0x1b];
              pppppppppppfVar11[0x1c] = (float **********)pppppppppppppfVar35[0x1c];
              pppppppppppfVar11[0x1d] = (float **********)pppppppppppppfVar35[0x1d];
              pppppppppppfVar11[0x1e] = (float **********)pppppppppppppfVar35[0x1e];
              pppppppppppfVar11[0x1f] = (float **********)pppppppppppppfVar35[0x1f];
              pppppppppppfVar11[0x20] = (float **********)pppppppppppppfVar35[0x20];
              pppppppppppfVar11[0x21] = (float **********)pppppppppppppfVar35[0x21];
              pppppppppppfVar11[0x22] = (float **********)pppppppppppppfVar35[0x22];
              pppppppppppfVar11[0x23] = (float **********)pppppppppppppfVar35[0x23];
              *(undefined1 *)(pppppppppppfVar11 + 0x24) =
                   *(undefined1 *)(pppppppppppppfVar35 + 0x24);
              *(undefined1 *)((int)pppppppppppfVar11 + 0x91) =
                   *(undefined1 *)((int)pppppppppppppfVar35 + 0x91);
              *(undefined1 *)((int)pppppppppppfVar11 + 0x92) =
                   *(undefined1 *)((int)pppppppppppppfVar35 + 0x92);
              *(undefined1 *)((int)pppppppppppfVar11 + 0x93) =
                   *(undefined1 *)((int)pppppppppppppfVar35 + 0x93);
              *(undefined1 *)(pppppppppppfVar11 + 0x25) =
                   *(undefined1 *)(pppppppppppppfVar35 + 0x25);
              *(undefined1 *)((int)pppppppppppfVar11 + 0x95) =
                   *(undefined1 *)((int)pppppppppppppfVar35 + 0x95);
              *(undefined1 *)((int)pppppppppppfVar11 + 0x96) =
                   *(undefined1 *)((int)pppppppppppppfVar35 + 0x96);
              *(undefined1 *)((int)pppppppppppfVar11 + 0x97) =
                   *(undefined1 *)((int)pppppppppppppfVar35 + 0x97);
              *(undefined1 *)(pppppppppppfVar11 + 0x26) =
                   *(undefined1 *)(pppppppppppppfVar35 + 0x26);
            }
          }
          pppppppppppppfVar30 = (float *************)((int)pppppppppppppfVar30 + 1);
          pppppppppppppfVar4 = pppppppppppppfVar35;
        } while ((int)pppppppppppppfVar30 < (int)local_1de8);
      }
    }
  }
  uVar49 = CONCAT44((int)((ulonglong)lVar48 >> 0x20),local_1e88);
  func_001FE680((undefined4 *)(&local_1df0));
  pppppppppppppfVar30 = local_30;
  local_1dcc = local_1e04;
  pppppppppppfVar10 = *local_1e04;
  if ((int)pppppppppppfVar10 < (int)local_1e04[1]) {
    pppppppppppfVar11 = local_1e04[2] + (int)pppppppppppfVar10 * 0x27;
    *local_1e04 = (float ***********)((int)pppppppppppfVar10 + 1);
  }
  else {
    pppppppppppfVar11 = (float ***********)0x0;
  }
  pppppppppppfVar11[0x1c] = in_s1;
  pppppppfVar45 = DAT_0063b23c;
  local_1e64 = (float ************)CF_FBITS((ALBW_AS_F32(in_s1) + ALBW_AS_F32(uVar49)));
  pppppppppppfVar11[9] = (float **********)local_30[0xc];
  pppppppppppfVar11[10] = (float **********)local_30[0xd];
  pppppppppppfVar11[0xb] = (float **********)local_30[0xe];
  *(undefined1 *)(pppppppppppfVar11 + 0x24) = 1;
  local_30[0x1d] = (float ************)CF_FBITS((ALBW_AS_F32(local_1e64) * fVar41));
  local_1dc8 = 0;
  local_1e90 = local_30[10];
  local_1e8c = local_30[0xc];
  local_1e88 = local_30[0xd];
  local_1e84 = local_30[0xe];
  local_1e80 = local_30[0x12];
  local_1e7c = local_30[0x13];
  local_1e78 = local_30[0x14];
  ppppppppppppfVar9 = local_30[10];
  local_1e74 = ppppppppppppfVar9[0xc];
  local_1e70 = (float ************)ppppppppppppfVar9[0xd];
  local_1e6c = ppppppppppppfVar9[0xe];
  local_1e68 = (float ***********)pppppppfVar45;
  local_1e60 = local_1df8;
  if (local_1e04 != (float ************)0x0) {
    pppppppppppfVar11 = local_1e04[2] + (int)*local_1e04 * 0x27 + -0x27;
    *pppppppppppfVar11 = (float **********)local_1e80;
    pppppppppppfVar11[1] = (float **********)local_1e7c;
    pppppppppppfVar11[2] = (float **********)local_1e78;
    pppppppppppfVar11[6] = (float **********)local_1e74;
    pppppppppppfVar11[7] = (float **********)local_1e70;
    pppppppppppfVar11[8] = (float **********)local_1e6c;
    func_004A17A4((float *)pppppppppppfVar11);
    local_1e5c = (float *************)((int)*local_1dcc + -1);
  }
  func_0049F5FC((undefined4 *)(pppppppppppppfVar30 + 2));
  func_0049F5FC((undefined4 *)(pppppppppppppfVar30 + 6));
  pppppppppppfVar11 = (float ***********)0x0;
  while( true ) {
    pppppppppppfVar52 = (float ***********)((ulonglong)uVar49 >> 0x20);
    ppppppppppppfVar9 = *pppppppppppppfVar30;
    pppppppppppfVar12 = *ppppppppppppfVar9;
    if ((int)pppppppppppfVar12 <= (int)pppppppppppfVar11) break;
    if (pppppppppppfVar11 < pppppppppppfVar12) {
      ppppppppppppfVar9 = (float ************)ppppppppppppfVar9[2];
    }
    if (pppppppppppfVar11 < pppppppppppfVar12) {
      pppppppppppfVar12 = ppppppppppppfVar9[(int)pppppppppppfVar11];
    }
    else {
      pppppppppppfVar12 = (float ***********)0x0;
    }
    func_0010F1DC((int *)(pppppppppppppfVar30 + 2),
                  (int *)((int)pppppppppppppfVar30[5] + (int)pppppppppppfVar12));
    pppppppppppppfVar30[4] = (float ************)((int)pppppppppppppfVar30[4] + 1);
    ppppppppppppfVar9 = *pppppppppppppfVar30;
    pppppppppppfVar12 = *ppppppppppppfVar9;
    if (pppppppppppfVar11 < pppppppppppfVar12) {
      ppppppppppppfVar9 = (float ************)ppppppppppppfVar9[2];
    }
    if (pppppppppppfVar11 < pppppppppppfVar12) {
      pppppppppppfVar12 = ppppppppppppfVar9[(int)pppppppppppfVar11];
    }
    else {
      pppppppppppfVar12 = (float ***********)0x0;
    }
    func_0010F1DC((int *)(pppppppppppppfVar30 + 6),
                  (int *)((int)pppppppppppppfVar30[9] + (int)pppppppppppfVar12));
    pppppppppppfVar11 = (float ***********)((int)pppppppppppfVar11 + 1);
    pppppppppppppfVar30[8] = (float ************)((int)pppppppppppppfVar30[8] + 1);
  }
  func_0064CB28((int *)pppppppppppppfVar30,(int *)&local_1df0,(int *)&local_1e90);
  pppppppppppppfVar30 = local_30;
  if (local_1dd0 == (float *************)0x0) {
    return ALBW_AS_F32(pppppppppppfVar8);
  }
  local_30[0xedc] = (float ************)local_1dec;
  local_30[0xedd] = (float ************)local_1de8;
  local_30[0xede] = local_1de4;
  local_30[0xee2] = local_1dd0[0xc];
  local_30[0xee3] = local_1dd0[0xd];
  local_30[0xee4] = local_1dd0[0xe];
  local_1e20 = (float ************)(local_30 + 0x77c);
  if (DAT_0063b244 < (int)local_1df0) {
    if ((ALBW_AS_F32(local_30[0x1e]) != ALBW_AS_F32(pppppppppppfVar13)) && (DAT_0063b24c < (int)local_1df0)) {
      return ALBW_AS_F32(local_1df0);
    }
    if (local_2c != 0) {
      return ALBW_AS_F32(local_1df0);
    }
    uVar50 = (ulonglong)(uint)ALBW_AS_U32(-ALBW_AS_F32(local_1df0));
    func_001FE680((undefined4 *)(&local_1e90));
    local_1e34 = (float ***********)uVar50;
    local_1e74 = (float ***********)&local_1ed0;
    if (ALBW_AS_F32(local_1e34) <= ALBW_AS_F32(pppppppppppfVar13)) {
      ppppppppppppfVar9 = (float ************)CF_FBITS(-ALBW_AS_F32(local_1e34));
      pppppppppppppfVar30[0x1d] = (float ************)CF_FBITS(-(fVar41 * ALBW_AS_F32(local_1e34)));
      local_1e60 = (float ***********)pppppppppppppfVar30[10];
      local_1e5c = (float *************)pppppppppppppfVar30[0xc];
      local_1e58 = pppppppppppppfVar30[0xd];
      local_1e54 = (float ***********)pppppppppppppfVar30[0xe];
      local_1e50 = (float ***********)CF_FBITS(-ALBW_AS_F32(pppppppppppppfVar30[0x12]));
      local_1e48 = (float ************)CF_FBITS(-ALBW_AS_F32(pppppppppppppfVar30[0x14]));
      local_1e4c = (float ***********)CF_FBITS(-ALBW_AS_F32(pppppppppppppfVar30[0x13]));
      ppppppppppppfVar5 = pppppppppppppfVar30[10];
      local_1e44 = (float ************)ppppppppppppfVar5[0xc];
      local_1e40 = ppppppppppppfVar5[0xd];
      local_1e3c = ppppppppppppfVar5[0xe];
      local_1e30 = (float ************)local_1df8;
      local_1e38 = (float ***********)pppppppfVar45;
      local_1e68 = (float ***********)0x0;
      local_1e6c = (float ***********)0x0;
      local_1ec4 = (float ************)&local_1e90;
      local_1e34 = (float ***********)ppppppppppppfVar9;
      func_0049F5FC((undefined4 *)(pppppppppppppfVar30 + 2));
      func_0049F5FC((undefined4 *)(pppppppppppppfVar30 + 6));
      pppppppppppfVar8 = (float ***********)0x0;
      while( true ) {
        ppppppppppppfVar5 = *pppppppppppppfVar30;
        pppppppppppfVar13 = *ppppppppppppfVar5;
        if ((int)pppppppppppfVar13 <= (int)pppppppppppfVar8) break;
        if (pppppppppppfVar8 < pppppppppppfVar13) {
          ppppppppppppfVar5 = (float ************)ppppppppppppfVar5[2];
        }
        if (pppppppppppfVar8 < pppppppppppfVar13) {
          pppppppppppfVar13 = ppppppppppppfVar5[(int)pppppppppppfVar8];
        }
        else {
          pppppppppppfVar13 = (float ***********)0x0;
        }
        func_0010F1DC((int *)(pppppppppppppfVar30 + 2),
                      (int *)((int)pppppppppppppfVar30[5] + (int)pppppppppppfVar13));
        pppppppppppppfVar30[4] = (float ************)((int)pppppppppppppfVar30[4] + 1);
        ppppppppppppfVar5 = *pppppppppppppfVar30;
        pppppppppppfVar13 = *ppppppppppppfVar5;
        if (pppppppppppfVar8 < pppppppppppfVar13) {
          ppppppppppppfVar5 = (float ************)ppppppppppppfVar5[2];
        }
        if (pppppppppppfVar8 < pppppppppppfVar13) {
          pppppppppppfVar13 = ppppppppppppfVar5[(int)pppppppppppfVar8];
        }
        else {
          pppppppppppfVar13 = (float ***********)0x0;
        }
        func_0010F1DC((int *)(pppppppppppppfVar30 + 6),
                      (int *)((int)pppppppppppppfVar30[9] + (int)pppppppppppfVar13));
        pppppppppppfVar8 = (float ***********)((int)pppppppppppfVar8 + 1);
        pppppppppppppfVar30[8] = (float ************)((int)pppppppppppppfVar30[8] + 1);
      }
      func_0064E9F4((int *)pppppppppppppfVar30,(undefined4 *)(local_1ec4),(int *)&local_1e60);
      ppppppppppppfVar5 =
           (float ************)
           CF_FBITS((ALBW_AS_F32(pppppppppppppfVar30[0x1e]) - (ALBW_AS_F32(ppppppppppppfVar9) - ALBW_AS_F32(local_1e90))));
    }
    else {
      pppppppppppppfVar30[0x1d] = (float ************)CF_FBITS((ALBW_AS_F32(local_1e34) * fVar41));
      local_1e60 = (float ***********)pppppppppppppfVar30[10];
      local_1e5c = (float *************)pppppppppppppfVar30[0xc];
      local_1e58 = pppppppppppppfVar30[0xd];
      local_1e54 = (float ***********)pppppppppppppfVar30[0xe];
      local_1e50 = (float ***********)pppppppppppppfVar30[0x12];
      local_1e4c = (float ***********)pppppppppppppfVar30[0x13];
      local_1e48 = pppppppppppppfVar30[0x14];
      ppppppppppppfVar5 = pppppppppppppfVar30[10];
      local_1e44 = (float ************)ppppppppppppfVar5[0xc];
      local_1e40 = ppppppppppppfVar5[0xd];
      local_1e3c = ppppppppppppfVar5[0xe];
      local_1e30 = (float ************)local_1df8;
      local_1e38 = (float ***********)pppppppfVar45;
      local_1e68 = (float ***********)0x0;
      local_1e6c = (float ***********)0x0;
      local_1ed8 = (float ************)&local_1e90;
      func_0049F5FC((undefined4 *)(pppppppppppppfVar30 + 2));
      func_0049F5FC((undefined4 *)(pppppppppppppfVar30 + 6));
      pppppppppppfVar8 = (float ***********)0x0;
      while( true ) {
        fVar41 = ALBW_AS_F32(uVar50);
        ppppppppppppfVar5 = *pppppppppppppfVar30;
        pppppppppppfVar13 = *ppppppppppppfVar5;
        if ((int)pppppppppppfVar13 <= (int)pppppppppppfVar8) break;
        if (pppppppppppfVar8 < pppppppppppfVar13) {
          ppppppppppppfVar5 = (float ************)ppppppppppppfVar5[2];
        }
        if (pppppppppppfVar8 < pppppppppppfVar13) {
          pppppppppppfVar13 = ppppppppppppfVar5[(int)pppppppppppfVar8];
        }
        else {
          pppppppppppfVar13 = (float ***********)0x0;
        }
        func_0010F1DC((int *)(pppppppppppppfVar30 + 2),
                      (int *)((int)pppppppppppppfVar30[5] + (int)pppppppppppfVar13));
        pppppppppppppfVar30[4] = (float ************)((int)pppppppppppppfVar30[4] + 1);
        ppppppppppppfVar5 = *pppppppppppppfVar30;
        pppppppppppfVar13 = *ppppppppppppfVar5;
        if (pppppppppppfVar8 < pppppppppppfVar13) {
          ppppppppppppfVar5 = (float ************)ppppppppppppfVar5[2];
        }
        if (pppppppppppfVar8 < pppppppppppfVar13) {
          pppppppppppfVar13 = ppppppppppppfVar5[(int)pppppppppppfVar8];
        }
        else {
          pppppppppppfVar13 = (float ***********)0x0;
        }
        func_0010F1DC((int *)(pppppppppppppfVar30 + 6),
                      (int *)((int)pppppppppppppfVar30[9] + (int)pppppppppppfVar13));
        pppppppppppfVar8 = (float ***********)((int)pppppppppppfVar8 + 1);
        pppppppppppppfVar30[8] = (float ************)((int)pppppppppppppfVar30[8] + 1);
      }
      func_0064CB28((int *)pppppppppppppfVar30,(int *)local_1ed8,(int *)&local_1e60);
      ppppppppppppfVar5 =
           (float ************)CF_FBITS((ALBW_AS_F32(pppppppppppppfVar30[0x1e]) + (fVar41 - ALBW_AS_F32(local_1e90))));
    }
    pppppppppppppfVar30[0x1e] = ppppppppppppfVar5;
    pppppppppppfVar8 = local_1df0;
    if (local_1e70 != (float ************)0x0) {
      *(float ************)(DAT_0063c558 + (int)pppppppppppppfVar30) = *local_1e70;
      pppppppppppppfVar30[0xc] = local_1e8c;
      pppppppppppppfVar30[0xd] = local_1e88;
      pppppppppppppfVar30[0xe] = local_1e84;
      if (pppppppppppppfVar30[10] != local_1e70) {
        pppppppppppppfVar30[10] = local_1e70;
        pppppppppppppfVar30[0x18] = (float ************)local_1e70[0xc];
        pppppppppppppfVar30[0x19] = (float ************)local_1e70[0xd];
        pppppppppppppfVar30[0x1a] = (float ************)local_1e70[0xe];
        pppppppppppppfVar30[0x15] = (float ************)*pppppppfVar45;
        pppppppppppppfVar30[0x16] = (float ************)pppppppfVar45[1];
        pppppppppppppfVar30[0x17] = (float ************)pppppppfVar45[2];
        func_004A17E4((float *)(pppppppppppppfVar30 + 0x12));
        pppppppppppfVar8 = local_1df0;
      }
      pppppppppppppfVar30[0xf] = (float ************)local_1ed0;
      pppppppppppppfVar30[0x10] = local_1ecc;
      pppppppppppppfVar30[0x11] = local_1ec8;
    }
    fVar41 = DAT_0063c55c;
    local_1df0 = (float ***********)local_1e90;
    if (pppppppppppfVar10 < *local_1dcc) {
      pppppppppppfVar10 = local_1dcc[2] + (int)pppppppppppfVar10 * 0x27;
    }
    else {
      pppppppppppfVar10 = (float ***********)0x0;
    }
    pppppppppppfVar10[9] = (float **********)local_30[0xc];
    pppppppppppfVar10[10] = (float **********)local_30[0xd];
    pppppppppppfVar10[0xb] = (float **********)local_30[0xe];
    pppppppppppfVar10[0x1c] = (float **********)CF_FBITS((ALBW_AS_F32(in_s1) + ALBW_AS_F32(pppppppppppfVar8)));
    if ((int)ALBW_AS_U32(fVar41) < (int)local_1e90) {
      return ALBW_AS_F32(local_1e90);
    }
    *(undefined1 *)(local_30 + 0xf70) = 1;
    local_30[0x29] = (float ************)0x0;
    *local_1e20 = (float ***********)0x0;
    fVar41 = func_0063AEA8(local_30,1,local_28,fparam_0,fparam_1);
    return fVar41;
  }
  if (local_28 == 0) {
    return ALBW_AS_F32(pppppppppppfVar13);
  }
  pppppppppppfVar10 = pppppppppppfVar13;
  func_001FE680((undefined4 *)(local_1ec0));
  pppppppppppppfVar30 = local_30;
  *local_1e20 = (float ***********)0x0;
  local_1e9c = local_1e20;
  pppppppppppfVar11 = *local_1e20;
  if ((int)pppppppppppfVar11 < (int)local_1e20[1]) {
    *local_1e20 = (float ***********)((int)pppppppppppfVar11 + 1);
    pppppppppppfVar11 = local_1e20[2] + (int)pppppppppppfVar11 * 0x27;
  }
  else {
    pppppppppppfVar11 = (float ***********)0x0;
  }
  pppppppppppfVar11[0x1c] = (float **********)pppppppppppfVar52;
  pppppppppppfVar11[9] = (float **********)local_30[0xf];
  pppppppppppfVar11[10] = (float **********)local_30[0x10];
  pppppppppppfVar11[0xb] = (float **********)local_30[0x11];
  *(undefined1 *)(pppppppppppfVar11 + 0x24) = 0;
  local_1e98 = 0;
  local_1e90 = local_30[0xb];
  local_1e8c = local_30[0xf];
  local_1e88 = local_30[0x10];
  local_1e84 = local_30[0x11];
  local_1ed4 = (float ************)local_1e90[0xc];
  local_1ed0 = local_1e90[0xd];
  local_1ecc = (float ************)local_1e90[0xe];
  local_1ee0 = (float ************)*pppppppfVar45;
  local_1edc = (float ***********)pppppppfVar45[1];
  local_1ed8 = (float ************)pppppppfVar45[2];
  local_1eec = (float ************)pppppppppppfVar8;
  local_1ee8 = (float ************)pppppppppppfVar13;
  local_1ee4 = pppppppppppfVar13;
  func_004A17E4((float *)&local_1eec);
  local_1e80 = (float ************)CF_FBITS(-ALBW_AS_F32(local_1eec));
  local_1e78 = (float ************)CF_FBITS(-ALBW_AS_F32(local_1ee4));
  local_1e7c = (float ************)CF_FBITS(-ALBW_AS_F32(local_1ee8));
  ppppppppppppfVar9 = pppppppppppppfVar30[0xb];
  local_1e74 = ppppppppppppfVar9[0xc];
  local_1e70 = (float ************)ppppppppppppfVar9[0xd];
  local_1e6c = ppppppppppppfVar9[0xe];
  local_1e68 = (float ***********)pppppppfVar45;
  local_1e60 = local_1df8;
  local_1e64 = (float ************)pppppppppppfVar52;
  if (local_1e9c != (float ************)0x0) {
    pppppppppppfVar11 = local_1e9c[2] + (int)*local_1e9c * 0x27 + -0x27;
    *pppppppppppfVar11 = (float **********)local_1e80;
    pppppppppppfVar11[1] = (float **********)local_1e7c;
    pppppppppppfVar11[2] = (float **********)local_1e78;
    pppppppppppfVar11[6] = (float **********)local_1e74;
    pppppppppppfVar11[7] = (float **********)local_1e70;
    pppppppppppfVar11[8] = (float **********)local_1e6c;
    func_004A17A4((float *)pppppppppppfVar11);
    local_1e5c = (float *************)((int)*local_1e9c + -1);
  }
  func_0049F5FC((undefined4 *)(pppppppppppppfVar30 + 2));
  func_0049F5FC((undefined4 *)(pppppppppppppfVar30 + 6));
  pppppppppppfVar11 = (float ***********)0x0;
  while( true ) {
    uVar59 = (undefined4)((ulonglong)lVar58 >> 0x20);
    ppppppppppppfVar9 = *pppppppppppppfVar30;
    pppppppppppfVar12 = *ppppppppppppfVar9;
    if ((int)pppppppppppfVar12 <= (int)pppppppppppfVar11) break;
    if (pppppppppppfVar11 < pppppppppppfVar12) {
      ppppppppppppfVar9 = (float ************)ppppppppppppfVar9[2];
    }
    if (pppppppppppfVar11 < pppppppppppfVar12) {
      pppppppppppfVar12 = ppppppppppppfVar9[(int)pppppppppppfVar11];
    }
    else {
      pppppppppppfVar12 = (float ***********)0x0;
    }
    func_0010F1DC((int *)(pppppppppppppfVar30 + 2),
                  (int *)((int)pppppppppppppfVar30[5] + (int)pppppppppppfVar12));
    pppppppppppppfVar30[4] = (float ************)((int)pppppppppppppfVar30[4] + 1);
    ppppppppppppfVar9 = *pppppppppppppfVar30;
    pppppppppppfVar12 = *ppppppppppppfVar9;
    if (pppppppppppfVar11 < pppppppppppfVar12) {
      ppppppppppppfVar9 = (float ************)ppppppppppppfVar9[2];
    }
    if (pppppppppppfVar11 < pppppppppppfVar12) {
      pppppppppppfVar12 = ppppppppppppfVar9[(int)pppppppppppfVar11];
    }
    else {
      pppppppppppfVar12 = (float ***********)0x0;
    }
    func_0010F1DC((int *)(pppppppppppppfVar30 + 6),
                  (int *)((int)pppppppppppppfVar30[9] + (int)pppppppppppfVar12));
    pppppppppppfVar11 = (float ***********)((int)pppppppppppfVar11 + 1);
    pppppppppppppfVar30[8] = (float ************)((int)pppppppppppppfVar30[8] + 1);
  }
  func_0064B4A0((int)pppppppppppppfVar30,local_1ec0,(float *)&local_1e90);
  pppppppppppppfVar30 = local_30;
  uVar49 = CONCAT44(uVar59,local_1ec0[0]);
  pppppppppppfVar11 = *local_1e9c;
  if ((int)pppppppppppfVar11 < (int)local_1e9c[1]) {
    *local_1e9c = (float ***********)((int)pppppppppppfVar11 + 1);
    pppppppppppfVar11 = local_1e9c[2] + (int)pppppppppppfVar11 * 0x27;
  }
  else {
    pppppppppppfVar11 = (float ***********)0x0;
  }
  pppppppppppfVar11[0x1c] = in_s1;
  uVar50 = ZEXT48(pppppppppppfVar8);
  pppppppppppfVar11[9] = (float **********)local_30[0xf];
  pppppppppppfVar11[10] = (float **********)local_30[0x10];
  pppppppppppfVar11[0xb] = (float **********)local_30[0x11];
  *(undefined1 *)(pppppppppppfVar11 + 0x24) = 1;
  local_1e98 = 0;
  uVar56 = CONCAT44(pppppppppppfVar13,local_1ec0[0] + ALBW_AS_F32(in_s1));
  local_1e90 = local_30[0xb];
  local_1e8c = local_30[0xf];
  local_1e88 = local_30[0x10];
  local_1e84 = local_30[0x11];
  local_1ed4 = (float ************)((float ***********)local_1e90)[0xc];
  local_1ed0 = (float ***********)((float ***********)local_1e90)[0xd];
  local_1ecc = (float ************)((float ***********)local_1e90)[0xe];
  local_1ee0 = (float ************)*pppppppfVar45;
  local_1edc = (float ***********)pppppppfVar45[1];
  local_1ed8 = (float ************)pppppppfVar45[2];
  local_1eec = (float ************)pppppppppppfVar8;
  local_1ee8 = (float ************)pppppppppppfVar13;
  local_1ee4 = pppppppppppfVar13;
  func_004A17E4((float *)&local_1eec);
  local_1e80 = local_1eec;
  local_1e7c = local_1ee8;
  local_1e78 = (float ************)local_1ee4;
  ppppppppppppfVar9 = pppppppppppppfVar30[0xb];
  local_1e74 = ppppppppppppfVar9[0xc];
  local_1e70 = (float ************)ppppppppppppfVar9[0xd];
  local_1e6c = ppppppppppppfVar9[0xe];
  local_1e68 = (float ***********)pppppppfVar45;
  local_1e64 = (float ************)uVar56;
  local_1e60 = local_1df8;
  if (local_1e9c != (float ************)0x0) {
    pppppppppppfVar8 = local_1e9c[2] + (int)*local_1e9c * 0x27 + -0x27;
    *pppppppppppfVar8 = (float **********)local_1eec;
    pppppppppppfVar8[1] = (float **********)local_1ee8;
    pppppppppppfVar8[2] = (float **********)local_1ee4;
    pppppppppppfVar8[6] = (float **********)local_1e74;
    pppppppppppfVar8[7] = (float **********)local_1e70;
    pppppppppppfVar8[8] = (float **********)local_1e6c;
    func_004A17A4((float *)pppppppppppfVar8);
    local_1e5c = (float *************)((int)*local_1e9c + -1);
  }
  func_0049F5FC((undefined4 *)(pppppppppppppfVar30 + 2));
  func_0049F5FC((undefined4 *)(pppppppppppppfVar30 + 6));
  pppppppppppfVar8 = (float ***********)0x0;
  while( true ) {
    fVar41 = ALBW_AS_F32(uVar50);
    uVar59 = (undefined4)((ulonglong)uVar56 >> 0x20);
    ppppppppppppfVar9 = *pppppppppppppfVar30;
    pppppppppppfVar13 = *ppppppppppppfVar9;
    if ((int)pppppppppppfVar13 <= (int)pppppppppppfVar8) break;
    if (pppppppppppfVar8 < pppppppppppfVar13) {
      ppppppppppppfVar9 = (float ************)ppppppppppppfVar9[2];
    }
    if (pppppppppppfVar8 < pppppppppppfVar13) {
      pppppppppppfVar13 = ppppppppppppfVar9[(int)pppppppppppfVar8];
    }
    else {
      pppppppppppfVar13 = (float ***********)0x0;
    }
    func_0010F1DC((int *)(pppppppppppppfVar30 + 2),
                  (int *)((int)pppppppppppppfVar30[5] + (int)pppppppppppfVar13));
    pppppppppppppfVar30[4] = (float ************)((int)pppppppppppppfVar30[4] + 1);
    ppppppppppppfVar9 = *pppppppppppppfVar30;
    pppppppppppfVar13 = *ppppppppppppfVar9;
    if (pppppppppppfVar8 < pppppppppppfVar13) {
      ppppppppppppfVar9 = (float ************)ppppppppppppfVar9[2];
    }
    if (pppppppppppfVar8 < pppppppppppfVar13) {
      pppppppppppfVar13 = ppppppppppppfVar9[(int)pppppppppppfVar8];
    }
    else {
      pppppppppppfVar13 = (float ***********)0x0;
    }
    func_0010F1DC((int *)(pppppppppppppfVar30 + 6),
                  (int *)((int)pppppppppppppfVar30[9] + (int)pppppppppppfVar13));
    pppppppppppfVar8 = (float ***********)((int)pppppppppppfVar8 + 1);
    pppppppppppppfVar30[8] = (float ************)((int)pppppppppppppfVar30[8] + 1);
  }
  func_00649E18((int)pppppppppppppfVar30,local_1ec0,(float *)&local_1e90);
  pppppppppppppfVar30 = local_30;
  uVar50 = CONCAT44(uVar59,local_1ec0[0]);
  local_1e50 = (float ***********)0x0;
  fVar55 = ALBW_AS_F32(pppppppppppfVar52) + ALBW_AS_F32(ppppppppppppfVar5);
  pppppppppppppfVar4 = local_30 + 0x29;
  fVar47 = ALBW_AS_F32(in_s1) + ALBW_AS_F32(pppppppppppfVar10);
  if (((*DAT_0063cb08 & 1) == 0) &&
     (iVar6 = func_00100174((int *)DAT_0063cb08), puVar3 = DAT_0063cb0c, iVar6 != 0)) {
    puVar20 = DAT_0063cb0c + 3;
    *DAT_0063cb0c = 0;
    puVar3[1] = 0;
    puVar3[2] = 0;
    func_0010B3EC(puVar3,0x20,(int)puVar20);
  }
  fVar54 = DAT_0063cb14;
  fVar53 = DAT_0063cb10;
  puVar3 = DAT_0063cb0c;
  uVar51 = CONCAT44(DAT_0063cb10,fVar41);
  uVar60 = (ulonglong)(uint)ALBW_AS_U32(DAT_0063cb14);
  ppppppppppppfVar9 = (float ************)0x0;
  *DAT_0063cb0c = 0;
  fVar42 = fVar41 / (ALBW_AS_F32(ppppppppppppfVar5) - fVar55);
  local_1ee4 = (float ***********)CF_FBITS((fVar42 * fVar53));
  local_1edc = (float ***********)CF_FBITS((fVar53 + fVar55 * fVar42 * fVar54));
  fVar41 = fVar41 / (ALBW_AS_F32(pppppppppppfVar10) - fVar47);
  local_1ee8 = (float ************)CF_FBITS((fVar41 * fVar54));
  local_1ee0 = (float ************)CF_FBITS((fVar53 + fVar47 * fVar41 * fVar53));
  if (0 < (int)*pppppppppppppfVar4) {
    fVar41 = ALBW_AS_F32(((ulonglong)uVar49 >> 0x20));
    do {
      if (ppppppppppppfVar9 < *pppppppppppppfVar4) {
        ppppppppppppfVar5 = pppppppppppppfVar30[0x2b] + (int)ppppppppppppfVar9 * 0x27;
      }
      else {
        ppppppppppppfVar5 = pppppppppppppfVar30[0x2b];
      }
      ppppppppppppfVar5[0x1c] =
           (float ***********)
           CF_FBITS((ALBW_AS_F32((&local_1ee0)[*(char *)(ppppppppppppfVar5 + 0x24)]) +
           ALBW_AS_F32((&local_1ee8)[*(char *)(ppppppppppppfVar5 + 0x24)]) *
           ALBW_AS_F32(ppppppppppppfVar5[0x1c])));
      pppppppppppfVar8 =
           (float ***********)
           CF_FBITS((ALBW_AS_F32((&local_1ee0)[*(char *)(ppppppppppppfVar5 + 0x24)]) +
           ALBW_AS_F32((&local_1ee8)[*(char *)(ppppppppppppfVar5 + 0x24)]) *
           ALBW_AS_F32(ppppppppppppfVar5[0x1d])));
      ppppppppppppfVar5[0x1d] = pppppppppppfVar8;
      if (ALBW_AS_F32(pppppppppppfVar8) < ALBW_AS_F32(ppppppppppppfVar5[0x1c])) {
        pppppppppppfVar8 = ppppppppppppfVar5[9];
        pppppppppppfVar10 = ppppppppppppfVar5[10];
        pppppppppppfVar13 = ppppppppppppfVar5[0xb];
        ppppppppppppfVar5[9] = ppppppppppppfVar5[0xc];
        ppppppppppppfVar5[10] = ppppppppppppfVar5[0xd];
        ppppppppppppfVar5[0xb] = ppppppppppppfVar5[0xe];
        ppppppppppppfVar5[0xc] = pppppppppppfVar8;
        ppppppppppppfVar5[0xd] = pppppppppppfVar10;
        ppppppppppppfVar5[0xe] = pppppppppppfVar13;
        pppppppppppfVar8 = ppppppppppppfVar5[0x1c];
        ppppppppppppfVar5[0x1c] = ppppppppppppfVar5[0x1d];
        ppppppppppppfVar5[0x1d] = pppppppppppfVar8;
      }
      ppppppppppppfVar5[0xf] = ppppppppppppfVar5[9];
      ppppppppppppfVar5[0x10] = ppppppppppppfVar5[10];
      ppppppppppppfVar5[0x11] = ppppppppppppfVar5[0xb];
      ppppppppppppfVar5[0x12] = ppppppppppppfVar5[0xc];
      ppppppppppppfVar5[0x13] = ppppppppppppfVar5[0xd];
      ppppppppppppfVar5[0x14] = ppppppppppppfVar5[0xe];
      *(undefined1 *)((int)ppppppppppppfVar5 + 0x92) = 0;
      *(undefined1 *)((int)ppppppppppppfVar5 + 0x91) = 0;
      ppppppppppppfVar5[0x1b] = (float ***********)(uVar50 >> 0x20);
      *(undefined1 *)(ppppppppppppfVar5 + 0x26) = 0;
      *(undefined1 *)((int)ppppppppppppfVar5 + 0x97) = 0;
      *(undefined1 *)((int)ppppppppppppfVar5 + 0x95) = 0;
      *(undefined1 *)(ppppppppppppfVar5 + 0x25) = 0;
      if (*(char *)(ppppppppppppfVar5 + 0x24) == '\0') {
        func_00115D70((float *)ppppppppppppfVar5,(float *)ppppppppppppfVar5,fVar41);
        func_00115D70((float *)(ppppppppppppfVar5 + 3),(float *)(ppppppppppppfVar5 + 3),fVar41);
      }
      fVar54 = ALBW_AS_F32(uVar60);
      ppppppppppppfVar9 = (float ************)((int)ppppppppppppfVar9 + 1);
    } while ((int)ppppppppppppfVar9 < (int)*pppppppppppppfVar4);
  }
  ppppppppppppfVar5 = (float ************)0x0;
  if (0 < (int)*pppppppppppppfVar4) {
    do {
      puVar20 = DAT_0063cb0c;
      ppppppppppppfVar40 = *pppppppppppppfVar4;
      ppppppppppppfVar9 = pppppppppppppfVar30[0x2b];
      if (ppppppppppppfVar5 < ppppppppppppfVar40) {
        ppppppppppppfVar9 = ppppppppppppfVar9 + (int)ppppppppppppfVar5 * 0x27;
      }
      ppppppppppppfVar25 = pppppppppppppfVar30[0x2b];
      if (ppppppppppppfVar5 < ppppppppppppfVar40) {
        ppppppppppppfVar25 = ppppppppppppfVar25 + (int)ppppppppppppfVar5 * 0x27;
      }
      if ((0xb4000000 < (uint)ALBW_AS_U32(ALBW_AS_F32(ppppppppppppfVar9[0x1c]) - ALBW_AS_F32(ppppppppppppfVar25[0x1d]))) ||
         (0x34000000 < (int)ALBW_AS_U32(ALBW_AS_F32(ppppppppppppfVar9[0x1c]) - ALBW_AS_F32(ppppppppppppfVar25[0x1d])))) {
        if (ppppppppppppfVar5 < ppppppppppppfVar40) {
          ppppppppppppfVar9 = pppppppppppppfVar30[0x2b] + (int)ppppppppppppfVar5 * 0x27;
        }
        else {
          ppppppppppppfVar9 = pppppppppppppfVar30[0x2b];
        }
        if ((int)*DAT_0063cb0c < (int)DAT_0063cb0c[1]) {
          *(float *************)(DAT_0063cb0c[2] + *DAT_0063cb0c * 4) = ppppppppppppfVar9;
          *puVar20 = *puVar20 + 1;
        }
      }
      ppppppppppppfVar5 = (float ************)((int)ppppppppppppfVar5 + 1);
    } while ((int)ppppppppppppfVar5 < (int)*pppppppppppppfVar4);
  }
  *pppppppppppppfVar4 = (float ************)0x0;
  if (*puVar3 != 0) {
    func_0048C258((int *)DAT_0063cb0c,DAT_0063cb18);
    if (((*DAT_0063cb1c & 1) == 0) &&
       (iVar6 = func_00100174((int *)DAT_0063cb1c), puVar20 = DAT_0063cb20, iVar6 != 0)) {
      puVar21 = DAT_0063cb20 + 3;
      *DAT_0063cb20 = 0;
      puVar20[1] = 0x30;
      puVar20[2] = (uint)puVar21;
      func_00100118((int)(puVar20 + 3),DAT_0063cb24,0x9c,0x30);
    }
    puVar20 = DAT_0063cb20;
    *DAT_0063cb20 = 0;
    if (*puVar3 == 0) {
      puVar14 = (undefined4 *)0x0;
    }
    else {
      puVar14 = *(undefined4 **)puVar3[2];
    }
    if (0 < (int)puVar20[1]) {
      *puVar20 = 1;
      func_001FE514((undefined4 *)puVar20[2],puVar14);
    }
    uVar22 = 1;
    iVar6 = *puVar20 * 0x9c + -0x9c + puVar20[2];
    uVar15 = *puVar3;
    if (1 < (int)uVar15) {
      do {
        uVar16 = uVar15;
        if (uVar22 < uVar15) {
          uVar16 = puVar3[2];
        }
        if (uVar22 < uVar15) {
          puVar14 = *(undefined4 **)(uVar16 + uVar22 * 4);
        }
        else {
          puVar14 = (undefined4 *)0x0;
        }
        fVar41 = *(float *)(iVar6 + 0x18) * ALBW_AS_F32(puVar14[6]) +
                 *(float *)(iVar6 + 0x1c) * ALBW_AS_F32(puVar14[7]) +
                 *(float *)(iVar6 + 0x20) * ALBW_AS_F32(puVar14[8]);
        if (fVar41 <= ALBW_AS_F32((uVar50 >> 0x20))) {
          fVar41 = -fVar41;
        }
        if (DAT_0063cb28 < (int)ALBW_AS_U32(fVar41)) {
          if (*(float *)(iVar6 + 0x74) < ALBW_AS_F32(puVar14[0x1d])) {
            *(undefined4 *)(iVar6 + 0x30) = puVar14[0xc];
            *(undefined4 *)(iVar6 + 0x34) = puVar14[0xd];
            *(undefined4 *)(iVar6 + 0x38) = puVar14[0xe];
            *(undefined4 *)(iVar6 + 0x74) = puVar14[0x1d];
            *(undefined4 *)(iVar6 + 0x48) = puVar14[0x12];
            *(undefined4 *)(iVar6 + 0x4c) = puVar14[0x13];
            *(undefined4 *)(iVar6 + 0x50) = puVar14[0x14];
          }
        }
        else {
          uVar15 = *puVar20;
          if ((int)uVar15 < (int)puVar20[1]) {
            *puVar20 = uVar15 + 1;
            puVar17 = (undefined4 *)(puVar20[2] + uVar15 * 0x9c);
            local_1ec8 = (float ************)(puVar14 + 0xc);
            *puVar17 = *puVar14;
            local_1ecc = (float ************)(puVar17 + 0xc);
            puVar17[1] = puVar14[1];
            local_1e84 = (float ************)(puVar14 + 0xf);
            puVar17[2] = puVar14[2];
            puVar17[3] = puVar14[3];
            puVar17[4] = puVar14[4];
            puVar17[5] = puVar14[5];
            puVar17[6] = puVar14[6];
            puVar17[7] = puVar14[7];
            puVar17[8] = puVar14[8];
            local_1e74 = (float ***********)(puVar17 + 0x15);
            puVar17[9] = puVar14[9];
            puVar17[10] = puVar14[10];
            local_1e90 = (float ************)(puVar14 + 0x18);
            puVar17[0xb] = puVar14[0xb];
            *local_1ecc = (float ***********)puVar14[0xc];
            puVar17[0xd] = puVar14[0xd];
            puVar17[0xe] = puVar14[0xe];
            puVar17[0xf] = (undefined4)(uintptr_t)((float ***********)puVar14[0xf]);
            puVar17[0x10] = puVar14[0x10];
            puVar17[0x11] = puVar14[0x11];
            puVar17[0x12] = puVar14[0x12];
            puVar17[0x13] = puVar14[0x13];
            puVar17[0x14] = puVar14[0x14];
            puVar17[0x15] = (undefined4)(uintptr_t)((float **********)puVar14[0x15]);
            puVar17[0x16] = puVar14[0x16];
            puVar17[0x17] = puVar14[0x17];
            puVar17[0x18] = (undefined4)(uintptr_t)((float **********)puVar14[0x18]);
            puVar17[0x19] = puVar14[0x19];
            puVar17[0x1a] = puVar14[0x1a];
            puVar17[0x1b] = puVar14[0x1b];
            puVar17[0x1c] = puVar14[0x1c];
            puVar17[0x1d] = puVar14[0x1d];
            puVar17[0x1e] = puVar14[0x1e];
            puVar17[0x1f] = puVar14[0x1f];
            puVar17[0x20] = puVar14[0x20];
            puVar17[0x21] = puVar14[0x21];
            puVar17[0x22] = puVar14[0x22];
            puVar17[0x23] = puVar14[0x23];
            *(undefined1 *)(puVar17 + 0x24) = *(undefined1 *)(puVar14 + 0x24);
            *(undefined1 *)((int)puVar17 + 0x91) = *(undefined1 *)((int)puVar14 + 0x91);
            *(undefined1 *)((int)puVar17 + 0x92) = *(undefined1 *)((int)puVar14 + 0x92);
            *(undefined1 *)((int)puVar17 + 0x93) = *(undefined1 *)((int)puVar14 + 0x93);
            *(undefined1 *)(puVar17 + 0x25) = *(undefined1 *)(puVar14 + 0x25);
            *(undefined1 *)((int)puVar17 + 0x95) = *(undefined1 *)((int)puVar14 + 0x95);
            *(undefined1 *)((int)puVar17 + 0x96) = *(undefined1 *)((int)puVar14 + 0x96);
            *(undefined1 *)((int)puVar17 + 0x97) = *(undefined1 *)((int)puVar14 + 0x97);
            *(undefined1 *)(puVar17 + 0x26) = *(undefined1 *)(puVar14 + 0x26);
          }
          iVar6 = *puVar20 * 0x9c + -0x9c + puVar20[2];
        }
        uVar15 = *puVar3;
        uVar22 = uVar22 + 1;
      } while ((int)uVar22 < (int)uVar15);
    }
    uVar15 = *puVar20;
    local_1ed8 = (float ************)0x0;
    uVar22 = 1;
    if (1 < (int)uVar15) {
      pfVar26 = (float *)puVar20[2];
      fVar41 = ABS(DAT_0063ddb0);
      do {
        pfVar7 = pfVar26;
        if (uVar22 - 1 < uVar15) {
          pfVar7 = pfVar26 + (uVar22 - 1) * 0x27;
        }
        pfVar29 = pfVar26;
        if (uVar22 < uVar15) {
          pfVar29 = pfVar26 + uVar22 * 0x27;
        }
        fVar47 = pfVar7[7];
        iVar6 = (int)ALBW_AS_U32(fVar47) - (int)ALBW_AS_U32(fVar41);
        if ((int)ALBW_AS_U32(fVar47) <= (int)ALBW_AS_U32(fVar41)) {
          fVar47 = pfVar29[7];
          iVar6 = (int)ALBW_AS_U32(fVar47) - (int)ALBW_AS_U32(fVar41);
        }
        if (fVar47 == fVar41 || iVar6 < 0 != SBORROW4((int)ALBW_AS_U32(fVar47),(int)ALBW_AS_U32(fVar41))) break;
        if ((uint)ALBW_AS_U32(DAT_0063ddb0) <
            (uint)ALBW_AS_U32((*pfVar7 * pfVar29[6] + pfVar7[1] * pfVar29[7] + pfVar7[2] * pfVar29[8])))
        goto LAB_0063ce6c;
        uVar22 = uVar22 + 1;
      } while ((int)uVar22 < (int)uVar15);
    }
    if (((int)uVar22 < (int)uVar15) && (uVar16 = uVar15 - 1, (int)uVar22 <= (int)uVar16)) {
      pfVar26 = (float *)puVar20[2];
      do {
        pfVar7 = pfVar26;
        if (uVar16 - 1 < uVar15) {
          pfVar7 = pfVar26 + (uVar16 - 1) * 0x27;
        }
        pfVar29 = pfVar26;
        if (uVar16 < uVar15) {
          pfVar29 = pfVar26 + uVar16 * 0x27;
        }
        fVar41 = pfVar7[7];
        iVar6 = (int)ALBW_AS_U32(fVar41) - (int)ALBW_AS_U32(DAT_0063c55c);
        if ((int)ALBW_AS_U32(fVar41) <= (int)ALBW_AS_U32(DAT_0063c55c)) {
          fVar41 = pfVar29[7];
          iVar6 = (int)ALBW_AS_U32(fVar41) - (int)ALBW_AS_U32(DAT_0063c55c);
        }
        if (fVar41 == DAT_0063c55c || iVar6 < 0 != SBORROW4((int)ALBW_AS_U32(fVar41),(int)ALBW_AS_U32(DAT_0063c55c))) break;
        if (DAT_0063ddb4 <
            (float *******)CF_FBITS((*pfVar7 * pfVar29[6] + pfVar7[1] * pfVar29[7] + pfVar7[2] * pfVar29[8])))
        goto LAB_0063ce6c;
        uVar16 = uVar16 - 1;
      } while ((int)uVar22 <= (int)uVar16);
    }
    goto LAB_0063cf20;
  }
LAB_0063d1a4:
  ppppppppppppfVar5 = local_1e20;
  fVar41 = ALBW_AS_F32(pppppppppppfVar52) + ALBW_AS_F32(uVar49);
  fVar47 = ALBW_AS_F32(in_s1) + ALBW_AS_F32(uVar50);
  if (((*DAT_0063ddb8 & 1) == 0) &&
     (iVar6 = func_00100174((int *)DAT_0063ddb8), pfVar26 = DAT_0063ddbc, iVar6 != 0)) {
    pfVar7 = DAT_0063ddbc + 3;
    *DAT_0063ddbc = 0.0;
    pfVar26[1] = 0.0;
    pfVar26[2] = 0.0;
    func_0010B3EC((undefined4 *)(pfVar26),0x20,(int)pfVar7);
  }
  pfVar26 = DAT_0063ddbc;
  uVar60 = uVar51 & 0xffffffff;
  *DAT_0063ddbc = 0.0;
  pppppppppppfVar8 = (float ***********)0x0;
  fVar55 = ALBW_AS_F32(uVar51) / (ALBW_AS_F32(uVar49) - fVar41);
  fVar53 = ALBW_AS_F32((uVar51 >> 0x20));
  local_1edc = (float ***********)CF_FBITS((fVar55 * fVar53));
  local_1ecc = (float ************)CF_FBITS((fVar53 + fVar41 * fVar55 * fVar54));
  fVar41 = ALBW_AS_F32(uVar51) / (ALBW_AS_F32(uVar50) - fVar47);
  local_1ee0 = (float ************)CF_FBITS((fVar41 * fVar54));
  local_1ed0 = (float ***********)CF_FBITS((fVar53 + fVar47 * fVar41 * fVar53));
  if (0 < (int)*ppppppppppppfVar5) {
    do {
      if (pppppppppppfVar8 < *ppppppppppppfVar5) {
        pppppppppppfVar10 = ppppppppppppfVar5[2] + (int)pppppppppppfVar8 * 0x27;
      }
      else {
        pppppppppppfVar10 = ppppppppppppfVar5[2];
      }
      pppppppppppfVar10[0x1c] =
           (float **********)
           CF_FBITS((ALBW_AS_F32((&local_1ed0)[*(char *)(pppppppppppfVar10 + 0x24)]) +
           ALBW_AS_F32((&local_1ee0)[*(char *)(pppppppppppfVar10 + 0x24)]) *
           ALBW_AS_F32(pppppppppppfVar10[0x1c])));
      ppppppppppfVar43 =
           (float **********)
           CF_FBITS((ALBW_AS_F32((&local_1ed0)[*(char *)(pppppppppppfVar10 + 0x24)]) +
           ALBW_AS_F32((&local_1ee0)[*(char *)(pppppppppppfVar10 + 0x24)]) *
           ALBW_AS_F32(pppppppppppfVar10[0x1d])));
      pppppppppppfVar10[0x1d] = ppppppppppfVar43;
      if (ALBW_AS_F32(ppppppppppfVar43) < ALBW_AS_F32(pppppppppppfVar10[0x1c])) {
        ppppppppppfVar43 = pppppppppppfVar10[10];
        ppppppppppfVar46 = pppppppppppfVar10[9];
        ppppppppppfVar44 = pppppppppppfVar10[0xb];
        pppppppppppfVar10[9] = pppppppppppfVar10[0xc];
        pppppppppppfVar10[10] = pppppppppppfVar10[0xd];
        pppppppppppfVar10[0xb] = pppppppppppfVar10[0xe];
        pppppppppppfVar10[0xc] = ppppppppppfVar46;
        pppppppppppfVar10[0xd] = ppppppppppfVar43;
        pppppppppppfVar10[0xe] = ppppppppppfVar44;
        ppppppppppfVar43 = pppppppppppfVar10[0x1c];
        pppppppppppfVar10[0x1c] = pppppppppppfVar10[0x1d];
        pppppppppppfVar10[0x1d] = ppppppppppfVar43;
      }
      pppppppppppfVar10[0xf] = pppppppppppfVar10[9];
      pppppppppppfVar10[0x10] = pppppppppppfVar10[10];
      pppppppppppfVar10[0x11] = pppppppppppfVar10[0xb];
      pppppppppppfVar10[0x12] = pppppppppppfVar10[0xc];
      pppppppppppfVar10[0x13] = pppppppppppfVar10[0xd];
      pppppppppppfVar10[0x14] = pppppppppppfVar10[0xe];
      *(undefined1 *)((int)pppppppppppfVar10 + 0x92) = 0;
      *(undefined1 *)((int)pppppppppppfVar10 + 0x91) = 0;
      pppppppppppfVar10[0x1b] = (float **********)(uVar50 >> 0x20);
      *(undefined1 *)(pppppppppppfVar10 + 0x26) = 0;
      *(undefined1 *)((int)pppppppppppfVar10 + 0x97) = 0;
      *(undefined1 *)((int)pppppppppppfVar10 + 0x95) = 0;
      *(undefined1 *)(pppppppppppfVar10 + 0x25) = 0;
      if (*(char *)(pppppppppppfVar10 + 0x24) == '\0') {
        func_00115D70((float *)pppppppppppfVar10,(float *)pppppppppppfVar10,
                      ALBW_AS_F32(((ulonglong)uVar49 >> 0x20)));
        func_00115D70((float *)(pppppppppppfVar10 + 3),(float *)(pppppppppppfVar10 + 3),
                      ALBW_AS_F32(((ulonglong)uVar49 >> 0x20)));
      }
      pppppppppppfVar8 = (float ***********)((int)pppppppppppfVar8 + 1);
    } while ((int)pppppppppppfVar8 < (int)*ppppppppppppfVar5);
  }
  pppppppppppfVar8 = (float ***********)0x0;
  if (0 < (int)*ppppppppppppfVar5) {
    do {
      pfVar7 = DAT_0063ddbc;
      if (pppppppppppfVar8 < *ppppppppppppfVar5) {
        pppppppppppfVar10 = ppppppppppppfVar5[2] + (int)pppppppppppfVar8 * 0x27;
        pppppppppppfVar13 = ppppppppppppfVar5[2] + (int)pppppppppppfVar8 * 0x27;
      }
      else {
        pppppppppppfVar10 = ppppppppppppfVar5[2];
        pppppppppppfVar13 = ppppppppppppfVar5[2];
      }
      if ((0xb4000000 < (uint)ALBW_AS_U32(ALBW_AS_F32(pppppppppppfVar10[0x1c]) - ALBW_AS_F32(pppppppppppfVar13[0x1d]))) ||
         (0x34000000 < (int)ALBW_AS_U32(ALBW_AS_F32(pppppppppppfVar10[0x1c]) - ALBW_AS_F32(pppppppppppfVar13[0x1d])))) {
        if (pppppppppppfVar8 < *ppppppppppppfVar5) {
          pppppppppppfVar10 = ppppppppppppfVar5[2] + (int)pppppppppppfVar8 * 0x27;
        }
        else {
          pppppppppppfVar10 = ppppppppppppfVar5[2];
        }
        if ((int)ALBW_AS_U32(*DAT_0063ddbc) < (int)ALBW_AS_U32(DAT_0063ddbc[1])) {
          *(float ************)((int)ALBW_AS_U32(DAT_0063ddbc[2]) + (int)ALBW_AS_U32(*DAT_0063ddbc) * 4) = pppppppppppfVar10;
          *pfVar7 = ALBW_AS_F32(((int)ALBW_AS_U32(*pfVar7) + 1));
        }
      }
      pppppppppppfVar8 = (float ***********)((int)pppppppppppfVar8 + 1);
    } while ((int)pppppppppppfVar8 < (int)*ppppppppppppfVar5);
  }
  *ppppppppppppfVar5 = (float ***********)0x0;
  if (*pfVar26 != 0.0) {
    func_0048C258((int *)DAT_0063ddbc,DAT_0063cb18);
    if (((*DAT_0063ddc0 & 1) == 0) &&
       (iVar6 = func_00100174((int *)DAT_0063ddc0), puVar3 = DAT_0063ddc4, iVar6 != 0)) {
      puVar20 = DAT_0063ddc4 + 3;
      *DAT_0063ddc4 = 0;
      puVar3[1] = 0x30;
      puVar3[2] = (uint)puVar20;
      func_00100118((int)(puVar3 + 3),DAT_0063cb24,0x9c,0x30);
    }
    puVar3 = DAT_0063ddc4;
    *DAT_0063ddc4 = 0;
    if (*pfVar26 == 0.0) {
      puVar14 = (undefined4 *)0x0;
    }
    else {
      puVar14 = *(undefined4 **)CF_FBITS(pfVar26[2]);
    }
    if (0 < (int)puVar3[1]) {
      *puVar3 = 1;
      func_001FE514((undefined4 *)puVar3[2],puVar14);
    }
    fVar41 = *pfVar26;
    iVar6 = *puVar3 * 0x9c + -0x9c + puVar3[2];
    puVar14 = (undefined4 *)0x1;
    if (1 < (int)ALBW_AS_U32(fVar41)) {
      do {
        puVar17 = (undefined4 *)CF_FBITS(*pfVar26);
        if (puVar14 < puVar17) {
          fVar41 = pfVar26[2];
          puVar18 = puVar17;
        }
        else {
          puVar18 = (undefined4 *)0x0;
        }
        if (puVar14 < puVar17) {
          puVar18 = *(undefined4 **)((int)ALBW_AS_U32(fVar41) + (int)puVar14 * 4);
        }
        fVar41 = *(float *)(iVar6 + 0x18) * ALBW_AS_F32(puVar18[6]) +
                 *(float *)(iVar6 + 0x1c) * ALBW_AS_F32(puVar18[7]) +
                 *(float *)(iVar6 + 0x20) * ALBW_AS_F32(puVar18[8]);
        if (fVar41 <= ALBW_AS_F32((uVar50 >> 0x20))) {
          fVar41 = -fVar41;
        }
        if (DAT_0063cb28 < (int)ALBW_AS_U32(fVar41)) {
          if (*(float *)(iVar6 + 0x74) < ALBW_AS_F32(puVar18[0x1d])) {
            *(undefined4 *)(iVar6 + 0x30) = puVar18[0xc];
            *(undefined4 *)(iVar6 + 0x34) = puVar18[0xd];
            *(undefined4 *)(iVar6 + 0x38) = puVar18[0xe];
            *(undefined4 *)(iVar6 + 0x74) = puVar18[0x1d];
            *(undefined4 *)(iVar6 + 0x48) = puVar18[0x12];
            *(undefined4 *)(iVar6 + 0x4c) = puVar18[0x13];
            *(undefined4 *)(iVar6 + 0x50) = puVar18[0x14];
          }
        }
        else {
          uVar15 = *puVar3;
          if ((int)uVar15 < (int)puVar3[1]) {
            *puVar3 = uVar15 + 1;
            local_1e88 = (float ************)(puVar18 + 0xc);
            puVar17 = (undefined4 *)(puVar3[2] + uVar15 * 0x9c);
            *puVar17 = *puVar18;
            local_1ed8 = (float ************)(puVar17 + 6);
            puVar17[1] = puVar18[1];
            puVar17[2] = puVar18[2];
            puVar17[3] = puVar18[3];
            puVar17[4] = puVar18[4];
            local_1e7c = (float ************)(puVar18 + 0x12);
            puVar17[5] = puVar18[5];
            local_1e78 = (float ************)(puVar17 + 0x12);
            *local_1ed8 = (float ***********)puVar18[6];
            puVar17[7] = puVar18[7];
            puVar17[8] = puVar18[8];
            puVar17[9] = puVar18[9];
            puVar17[10] = puVar18[10];
            puVar17[0xb] = puVar18[0xb];
            puVar17[0xc] = (undefined4)(uintptr_t)(*local_1e88);
            puVar17[0xd] = puVar18[0xd];
            puVar17[0xe] = puVar18[0xe];
            puVar17[0xf] = puVar18[0xf];
            puVar17[0x10] = puVar18[0x10];
            puVar17[0x11] = puVar18[0x11];
            *local_1e78 = *local_1e7c;
            puVar17[0x13] = puVar18[0x13];
            puVar17[0x14] = puVar18[0x14];
            puVar17[0x15] = puVar18[0x15];
            puVar17[0x16] = puVar18[0x16];
            puVar17[0x17] = puVar18[0x17];
            puVar17[0x18] = puVar18[0x18];
            puVar17[0x19] = puVar18[0x19];
            puVar17[0x1a] = puVar18[0x1a];
            puVar17[0x1b] = puVar18[0x1b];
            puVar17[0x1c] = puVar18[0x1c];
            puVar17[0x1d] = puVar18[0x1d];
            puVar17[0x1e] = puVar18[0x1e];
            puVar17[0x1f] = puVar18[0x1f];
            puVar17[0x20] = puVar18[0x20];
            puVar17[0x21] = puVar18[0x21];
            puVar17[0x22] = puVar18[0x22];
            puVar17[0x23] = puVar18[0x23];
            *(undefined1 *)(puVar17 + 0x24) = *(undefined1 *)(puVar18 + 0x24);
            *(undefined1 *)((int)puVar17 + 0x91) = *(undefined1 *)((int)puVar18 + 0x91);
            *(undefined1 *)((int)puVar17 + 0x92) = *(undefined1 *)((int)puVar18 + 0x92);
            *(undefined1 *)((int)puVar17 + 0x93) = *(undefined1 *)((int)puVar18 + 0x93);
            *(undefined1 *)(puVar17 + 0x25) = *(undefined1 *)(puVar18 + 0x25);
            *(undefined1 *)((int)puVar17 + 0x95) = *(undefined1 *)((int)puVar18 + 0x95);
            *(undefined1 *)((int)puVar17 + 0x96) = *(undefined1 *)((int)puVar18 + 0x96);
            *(undefined1 *)((int)puVar17 + 0x97) = *(undefined1 *)((int)puVar18 + 0x97);
            *(undefined1 *)(puVar17 + 0x26) = *(undefined1 *)(puVar18 + 0x26);
          }
          fVar41 = (float)(*puVar3 * 7);
          iVar6 = *puVar3 * 0x9c + -0x9c + puVar3[2];
        }
        puVar14 = (undefined4 *)((int)puVar14 + 1);
      } while ((int)puVar14 < (int)ALBW_AS_U32(*pfVar26));
    }
    uVar15 = *puVar3;
    local_1ed4 = (float ************)0x0;
    uVar22 = 1;
    if (1 < (int)uVar15) {
      pfVar26 = (float *)puVar3[2];
      do {
        pfVar7 = pfVar26;
        if (uVar22 - 1 < uVar15) {
          pfVar7 = pfVar26 + (uVar22 - 1) * 0x27;
        }
        pfVar29 = pfVar26;
        if (uVar22 < uVar15) {
          pfVar29 = pfVar26 + uVar22 * 0x27;
        }
        pppppfVar34 = (float *****)CF_FBITS(pfVar7[7]);
        iVar6 = (int)pppppfVar34 - (int)DAT_0063ddc8;
        if ((int)pppppfVar34 <= (int)DAT_0063ddc8) {
          pppppfVar34 = (float *****)CF_FBITS(pfVar29[7]);
          iVar6 = (int)pppppfVar34 - (int)DAT_0063ddc8;
        }
        if (pppppfVar34 == DAT_0063ddc8 || iVar6 < 0 != SBORROW4((int)pppppfVar34,(int)DAT_0063ddc8)
           ) break;
        if ((int)DAT_0063ddc8 <
            (int)ALBW_AS_U32((*pfVar7 * pfVar29[6] + pfVar7[1] * pfVar29[7] + pfVar7[2] * pfVar29[8])))
        goto LAB_0063d8cc;
        uVar22 = uVar22 + 1;
      } while ((int)uVar22 < (int)uVar15);
    }
    if (((int)uVar22 < (int)uVar15) && (uVar16 = uVar15 - 1, (int)uVar22 <= (int)uVar16)) {
      pfVar26 = (float *)puVar3[2];
      do {
        pfVar7 = pfVar26;
        if (uVar16 - 1 < uVar15) {
          pfVar7 = pfVar26 + (uVar16 - 1) * 0x27;
        }
        pfVar29 = pfVar26;
        if (uVar16 < uVar15) {
          pfVar29 = pfVar26 + uVar16 * 0x27;
        }
        pppppfVar34 = (float *****)CF_FBITS(pfVar7[7]);
        iVar6 = (int)pppppfVar34 - (int)DAT_0063ddc8;
        if ((int)pppppfVar34 <= (int)DAT_0063ddc8) {
          pppppfVar34 = (float *****)CF_FBITS(pfVar29[7]);
          iVar6 = (int)pppppfVar34 - (int)DAT_0063ddc8;
        }
        if (pppppfVar34 == DAT_0063ddc8 || iVar6 < 0 != SBORROW4((int)pppppfVar34,(int)DAT_0063ddc8)
           ) break;
        if (DAT_0063ddcc <
            (int)ALBW_AS_U32((*pfVar7 * pfVar29[6] + pfVar7[1] * pfVar29[7] + pfVar7[2] * pfVar29[8])))
        goto LAB_0063d8cc;
        uVar16 = uVar16 - 1;
      } while ((int)uVar22 <= (int)uVar16);
    }
LAB_0063d980:
    uVar15 = 0;
    if (0 < (int)*DAT_0063ddc4) {
      do {
        puVar3 = DAT_0063ddc4;
        uVar22 = DAT_0063ddc4[2];
        if (uVar15 < *DAT_0063ddc4) {
          uVar22 = uVar22 + uVar15 * 0x9c;
        }
        *(undefined1 *)(uVar22 + 0x93) = 0;
        puVar14 = (undefined4 *)puVar3[2];
        if (uVar15 < *puVar3) {
          puVar14 = puVar14 + uVar15 * 0x27;
        }
        pppppppppppfVar8 = *ppppppppppppfVar5;
        if ((int)pppppppppppfVar8 < (int)ppppppppppppfVar5[1]) {
          *ppppppppppppfVar5 = (float ***********)((int)pppppppppppfVar8 + 1);
          pppppppppppfVar8 = ppppppppppppfVar5[2] + (int)pppppppppppfVar8 * 0x27;
          *pppppppppppfVar8 = (float **********)*puVar14;
          local_1e8c = (float ************)(pppppppppppfVar8 + 9);
          local_1ee4 = pppppppppppfVar8 + 0xc;
          pppppppppppfVar8[1] = (float **********)puVar14[1];
          local_1ed8 = (float ************)(puVar14 + 0xf);
          pppppppppppfVar8[2] = (float **********)puVar14[2];
          pppppppppppfVar8[3] = (float **********)puVar14[3];
          pppppppppppfVar8[4] = (float **********)puVar14[4];
          pppppppppppfVar8[5] = (float **********)puVar14[5];
          pppppppppppfVar8[6] = (float **********)puVar14[6];
          pppppppppppfVar8[7] = (float **********)puVar14[7];
          pppppppppppfVar8[8] = (float **********)puVar14[8];
          *local_1e8c = (float ***********)puVar14[9];
          pppppppppppfVar8[10] = (float **********)puVar14[10];
          pppppppppppfVar8[0xb] = (float **********)puVar14[0xb];
          *local_1ee4 = (float **********)puVar14[0xc];
          pppppppppppfVar8[0xd] = (float **********)puVar14[0xd];
          pppppppppppfVar8[0xe] = (float **********)puVar14[0xe];
          pppppppppppfVar8[0xf] = (float **********)*local_1ed8;
          pppppppppppfVar8[0x10] = (float **********)puVar14[0x10];
          pppppppppppfVar8[0x11] = (float **********)puVar14[0x11];
          pppppppppppfVar8[0x12] = (float **********)puVar14[0x12];
          pppppppppppfVar8[0x13] = (float **********)puVar14[0x13];
          pppppppppppfVar8[0x14] = (float **********)puVar14[0x14];
          pppppppppppfVar8[0x15] = (float **********)puVar14[0x15];
          pppppppppppfVar8[0x16] = (float **********)puVar14[0x16];
          pppppppppppfVar8[0x17] = (float **********)puVar14[0x17];
          pppppppppppfVar8[0x18] = (float **********)puVar14[0x18];
          pppppppppppfVar8[0x19] = (float **********)puVar14[0x19];
          pppppppppppfVar8[0x1a] = (float **********)puVar14[0x1a];
          pppppppppppfVar8[0x1b] = (float **********)puVar14[0x1b];
          pppppppppppfVar8[0x1c] = (float **********)puVar14[0x1c];
          pppppppppppfVar8[0x1d] = (float **********)puVar14[0x1d];
          pppppppppppfVar8[0x1e] = (float **********)puVar14[0x1e];
          pppppppppppfVar8[0x1f] = (float **********)puVar14[0x1f];
          pppppppppppfVar8[0x20] = (float **********)puVar14[0x20];
          pppppppppppfVar8[0x21] = (float **********)puVar14[0x21];
          pppppppppppfVar8[0x22] = (float **********)puVar14[0x22];
          pppppppppppfVar8[0x23] = (float **********)puVar14[0x23];
          *(undefined1 *)(pppppppppppfVar8 + 0x24) = *(undefined1 *)(puVar14 + 0x24);
          *(undefined1 *)((int)pppppppppppfVar8 + 0x91) = *(undefined1 *)((int)puVar14 + 0x91);
          *(undefined1 *)((int)pppppppppppfVar8 + 0x92) = *(undefined1 *)((int)puVar14 + 0x92);
          *(undefined1 *)((int)pppppppppppfVar8 + 0x93) = *(undefined1 *)((int)puVar14 + 0x93);
          *(undefined1 *)(pppppppppppfVar8 + 0x25) = *(undefined1 *)(puVar14 + 0x25);
          *(undefined1 *)((int)pppppppppppfVar8 + 0x95) = *(undefined1 *)((int)puVar14 + 0x95);
          *(undefined1 *)((int)pppppppppppfVar8 + 0x96) = *(undefined1 *)((int)puVar14 + 0x96);
          *(undefined1 *)((int)pppppppppppfVar8 + 0x97) = *(undefined1 *)((int)puVar14 + 0x97);
          *(undefined1 *)(pppppppppppfVar8 + 0x26) = *(undefined1 *)(puVar14 + 0x26);
        }
        uVar15 = uVar15 + 1;
      } while ((int)uVar15 < (int)*DAT_0063ddc4);
    }
    if (local_1ed4 != (float ************)0x0) {
      local_1e50 = (float ***********)((uint)local_1e50 | 2);
    }
  }
  ppppppppppppfVar5 = local_1e20;
  local_1e84 = (float ************)local_30;
  local_1e80 = (float ************)local_1e50;
  local_1ec8 = (float ************)(local_30 + 0x29);
  if (((*DAT_0063ddd0 & 1) == 0) &&
     (iVar6 = func_00100174((int *)DAT_0063ddd0), piVar1 = DAT_0063ddd4, iVar6 != 0)) {
    piVar23 = DAT_0063ddd4 + 3;
    *DAT_0063ddd4 = 0;
    piVar1[1] = 0x30;
    piVar1[2] = (int)piVar23;
    func_00100118((int)(piVar1 + 3),DAT_0063ddd8,0x9c,0x30);
  }
  ppppppppppppfVar9 = (float ************)0x0;
  *DAT_0063ddd4 = 0;
  local_1ec4 = (float ************)0x0;
  if (0 < (int)*local_1ec8) {
LAB_0063dcbc:
    iVar6 = DAT_0063dddc;
    local_1edc = (float ***********)local_1e80;
    if (local_1ec4 < *local_1ec8) {
      ppppppppppfVar43 = (float **********)(local_1ec8[2] + (int)local_1ec4 * 0x27);
    }
    else {
      ppppppppppfVar43 = (float **********)local_1ec8[2];
    }
    ppppppppppppfVar40 = (float ************)*ppppppppppppfVar5;
    if ((int)ppppppppppppfVar9 < (int)ppppppppppppfVar40) {
      uVar51 = uVar50 >> 0x20;
      ppppppppppppfVar25 = ppppppppppppfVar9;
      do {
        pppppppppppfVar8 = ppppppppppppfVar5[2];
        if (ppppppppppppfVar25 < ppppppppppppfVar40) {
          pppppppppppfVar8 = pppppppppppfVar8 + (int)ppppppppppppfVar25 * 0x27;
        }
        fVar41 = ALBW_AS_F32(ppppppppppfVar43[6]) * ALBW_AS_F32(pppppppppppfVar8[6]) +
                 ALBW_AS_F32(ppppppppppfVar43[7]) * ALBW_AS_F32(pppppppppppfVar8[7]) +
                 ALBW_AS_F32(ppppppppppfVar43[8]) * ALBW_AS_F32(pppppppppppfVar8[8]);
        if (fVar41 <= ALBW_AS_F32(uVar51)) {
          fVar41 = -fVar41;
        }
        if (iVar6 < (int)ALBW_AS_U32(fVar41)) {
          func_00115C70((float *)&local_1e70,(float *)(ppppppppppfVar43 + 9),
                        (float *)(pppppppppppfVar8 + 9));
          fVar41 = ALBW_AS_F32(ppppppppppfVar43[6]) * ALBW_AS_F32(local_1e70) +
                   ALBW_AS_F32(ppppppppppfVar43[7]) * ALBW_AS_F32(local_1e6c) +
                   ALBW_AS_F32(ppppppppppfVar43[8]) * ALBW_AS_F32(local_1e68);
          if (fVar41 <= ALBW_AS_F32(uVar51)) {
            fVar41 = -fVar41;
          }
          if ((int)ALBW_AS_U32(fVar41) < DAT_0063ddcc) {
            local_1ee8 = ppppppppppppfVar25;
            if (-1 < (int)ppppppppppppfVar25) goto joined_r0x0063df48;
            break;
          }
        }
        ppppppppppppfVar40 = (float ************)*ppppppppppppfVar5;
        ppppppppppppfVar25 = (float ************)((int)ppppppppppppfVar25 + 1);
      } while ((int)ppppppppppppfVar25 < (int)ppppppppppppfVar40);
    }
    pppppppppfVar19 = (float *********)(uVar50 >> 0x20);
    ppppppppppfVar43[0x1f] = pppppppppfVar19;
    ppppppppppfVar43[0x1e] = pppppppppfVar19;
    func_00115D70((float *)&local_1e64,(float *)(ppppppppppfVar43 + 3),ALBW_AS_F32(local_1e84[0x1c]));
    local_1ed4 = local_1e64;
    local_1ed0 = local_1e60;
    local_1ecc = (float ************)local_1e5c;
    func_00115D88((float *)&local_1e40,(float *)&local_1ed4,ALBW_AS_F32(ppppppppppfVar43[4]));
    local_1e90 = (float ************)local_1e40;
    local_1e8c = (float ************)local_1e3c;
    local_1e88 = (float ************)local_1e38;
    func_00115C54((float *)&local_1e34,(float *)(ppppppppppfVar43 + 9),(float *)&local_1e90);
    local_1e7c = (float ************)local_1e34;
    local_1e78 = local_1e30;
    local_1e74 = (float ***********)local_1e2c;
    ppppppppppfVar43[0x15] = (float *********)local_1e34;
    ppppppppppfVar43[0x16] = (float *********)local_1e30;
    ppppppppppfVar43[0x17] = (float *********)local_1e2c;
    func_00115D70((float *)&local_1e4c,(float *)(ppppppppppfVar43 + 3),ALBW_AS_F32(local_1e84[0x1c]));
    local_1ed4 = (float ************)local_1e4c;
    local_1ed0 = (float ***********)local_1e48;
    local_1ecc = local_1e44;
    func_00115D88((float *)&local_1e1c,(float *)&local_1ed4,ALBW_AS_F32(ppppppppppfVar43[4]));
    local_1e7c = (float ************)local_1e1c;
    local_1e78 = (float ************)local_1e18;
    local_1e74 = local_1e14;
    func_00115C54((float *)&local_1e28,(float *)(ppppppppppfVar43 + 0xc),(float *)&local_1e7c);
    local_1e90 = (float ************)local_1e28;
    local_1e8c = (float ************)local_1e24;
    local_1e88 = local_1e20;
    ppppppppppfVar43[0x18] = (float *********)local_1e28;
    ppppppppppfVar43[0x19] = (float *********)local_1e24;
    ppppppppppfVar43[0x1a] = (float *********)local_1e20;
    *(undefined1 *)(ppppppppppfVar43 + 0x26) = 1;
    iVar6 = *DAT_0063ddd4;
    if (iVar6 < DAT_0063ddd4[1]) {
      piVar1 = DAT_0063ddd4 + 2;
      *DAT_0063ddd4 = iVar6 + 1;
      func_001FE514((undefined4 *)(*piVar1 + iVar6 * 0x9c),(undefined4 *)(ppppppppppfVar43));
    }
    goto LAB_0063e728;
  }
LAB_0063e744:
  pppppppppppppfVar30 = local_30;
  ppppppppppfVar43 = (float **********)*local_1ec8;
  ppppppppppfVar44 = (float **********)local_1ec8[2];
  ppppppppppppfVar40 = (float ************)*ppppppppppppfVar5;
  bVar39 = ppppppppppppfVar9 <= ppppppppppppfVar40;
  bVar38 = ppppppppppppfVar40 == ppppppppppppfVar9;
  if ((int)ppppppppppppfVar9 < (int)ppppppppppppfVar40) {
    do {
      pppppppppppfVar8 = ppppppppppppfVar5[2];
      if (bVar39 && !bVar38) {
        pppppppppppfVar8 = pppppppppppfVar8 + (int)ppppppppppppfVar9 * 0x27;
      }
      pppppppppppfVar8[0x1e] =
           (float **********)ppppppppppfVar44[(int)ppppppppppfVar43 * 0x27 + -10];
      pppppppppppfVar8[0x1f] =
           (float **********)ppppppppppfVar44[(int)ppppppppppfVar43 * 0x27 + -10];
      pppppppppppfVar8[0x15] =
           (float **********)ppppppppppfVar44[(int)ppppppppppfVar43 * 0x27 + -0x15];
      pppppppppppfVar8[0x16] =
           (float **********)ppppppppppfVar44[(int)ppppppppppfVar43 * 0x27 + -0x14];
      pppppppppppfVar8[0x17] =
           (float **********)ppppppppppfVar44[(int)ppppppppppfVar43 * 0x27 + -0x13];
      pppppppppppfVar8[0x18] =
           (float **********)ppppppppppfVar44[(int)ppppppppppfVar43 * 0x27 + -0x15];
      pppppppppppfVar8[0x19] =
           (float **********)ppppppppppfVar44[(int)ppppppppppfVar43 * 0x27 + -0x14];
      pppppppppppfVar8[0x1a] =
           (float **********)ppppppppppfVar44[(int)ppppppppppfVar43 * 0x27 + -0x13];
      *(undefined1 *)((int)pppppppppppfVar8 + 0x97) = 1;
      if (ppppppppppppfVar9 < *ppppppppppppfVar5) {
        pppppppppppfVar8 = ppppppppppppfVar5[2] + (int)ppppppppppppfVar9 * 0x27;
      }
      else {
        pppppppppppfVar8 = ppppppppppppfVar5[2];
      }
      iVar6 = *DAT_0063ddd4;
      if (iVar6 < DAT_0063ddd4[1]) {
        piVar1 = DAT_0063ddd4 + 2;
        *DAT_0063ddd4 = iVar6 + 1;
        puVar14 = (undefined4 *)(*piVar1 + iVar6 * 0x9c);
        *puVar14 = (undefined4)(uintptr_t)(*pppppppppppfVar8);
        local_1edc = (float ***********)(puVar14 + 6);
        local_1ed8 = (float ************)(puVar14 + 9);
        local_1ecc = (float ************)(puVar14 + 0xc);
        puVar14[1] = (undefined4)(uintptr_t)(pppppppppppfVar8[1]);
        local_1e90 = (float ************)(puVar14 + 0xf);
        puVar14[2] = (undefined4)(uintptr_t)(pppppppppppfVar8[2]);
        puVar14[3] = (undefined4)(uintptr_t)(pppppppppppfVar8[3]);
        puVar14[4] = (undefined4)(uintptr_t)(pppppppppppfVar8[4]);
        puVar14[5] = (undefined4)(uintptr_t)(pppppppppppfVar8[5]);
        *local_1edc = pppppppppppfVar8[6];
        puVar14[7] = (undefined4)(uintptr_t)(pppppppppppfVar8[7]);
        puVar14[8] = (undefined4)(uintptr_t)(pppppppppppfVar8[8]);
        *local_1ed8 = (float ***********)pppppppppppfVar8[9];
        puVar14[10] = (undefined4)(uintptr_t)(pppppppppppfVar8[10]);
        puVar14[0xb] = (undefined4)(uintptr_t)(pppppppppppfVar8[0xb]);
        *local_1ecc = (float ***********)pppppppppppfVar8[0xc];
        puVar14[0xd] = (undefined4)(uintptr_t)(pppppppppppfVar8[0xd]);
        puVar14[0xe] = (undefined4)(uintptr_t)(pppppppppppfVar8[0xe]);
        *local_1e90 = (float ***********)pppppppppppfVar8[0xf];
        puVar14[0x10] = (undefined4)(uintptr_t)(pppppppppppfVar8[0x10]);
        puVar14[0x11] = (undefined4)(uintptr_t)(pppppppppppfVar8[0x11]);
        puVar14[0x12] = (undefined4)(uintptr_t)(pppppppppppfVar8[0x12]);
        puVar14[0x13] = (undefined4)(uintptr_t)(pppppppppppfVar8[0x13]);
        puVar14[0x14] = (undefined4)(uintptr_t)(pppppppppppfVar8[0x14]);
        puVar14[0x15] = (undefined4)(uintptr_t)(pppppppppppfVar8[0x15]);
        puVar14[0x16] = (undefined4)(uintptr_t)(pppppppppppfVar8[0x16]);
        puVar14[0x17] = (undefined4)(uintptr_t)(pppppppppppfVar8[0x17]);
        puVar14[0x18] = (undefined4)(uintptr_t)(pppppppppppfVar8[0x18]);
        puVar14[0x19] = (undefined4)(uintptr_t)(pppppppppppfVar8[0x19]);
        puVar14[0x1a] = (undefined4)(uintptr_t)(pppppppppppfVar8[0x1a]);
        puVar14[0x1b] = (undefined4)(uintptr_t)(pppppppppppfVar8[0x1b]);
        puVar14[0x1c] = (undefined4)(uintptr_t)(pppppppppppfVar8[0x1c]);
        puVar14[0x1d] = (undefined4)(uintptr_t)(pppppppppppfVar8[0x1d]);
        puVar14[0x1e] = (undefined4)(uintptr_t)(pppppppppppfVar8[0x1e]);
        puVar14[0x1f] = (undefined4)(uintptr_t)(pppppppppppfVar8[0x1f]);
        puVar14[0x20] = (undefined4)(uintptr_t)(pppppppppppfVar8[0x20]);
        puVar14[0x21] = (undefined4)(uintptr_t)(pppppppppppfVar8[0x21]);
        puVar14[0x22] = (undefined4)(uintptr_t)(pppppppppppfVar8[0x22]);
        puVar14[0x23] = (undefined4)(uintptr_t)(pppppppppppfVar8[0x23]);
        *(undefined1 *)(puVar14 + 0x24) = *(undefined1 *)(pppppppppppfVar8 + 0x24);
        *(undefined1 *)((int)puVar14 + 0x91) = *(undefined1 *)((int)pppppppppppfVar8 + 0x91);
        *(undefined1 *)((int)puVar14 + 0x92) = *(undefined1 *)((int)pppppppppppfVar8 + 0x92);
        *(undefined1 *)((int)puVar14 + 0x93) = *(undefined1 *)((int)pppppppppppfVar8 + 0x93);
        *(undefined1 *)(puVar14 + 0x25) = *(undefined1 *)(pppppppppppfVar8 + 0x25);
        *(undefined1 *)((int)puVar14 + 0x95) = *(undefined1 *)((int)pppppppppppfVar8 + 0x95);
        *(undefined1 *)((int)puVar14 + 0x96) = *(undefined1 *)((int)pppppppppppfVar8 + 0x96);
        *(undefined1 *)((int)puVar14 + 0x97) = *(undefined1 *)((int)pppppppppppfVar8 + 0x97);
        *(undefined1 *)(puVar14 + 0x26) = *(undefined1 *)(pppppppppppfVar8 + 0x26);
      }
      ppppppppppppfVar40 = (float ************)*ppppppppppppfVar5;
      ppppppppppppfVar9 = (float ************)((int)ppppppppppppfVar9 + 1);
      bVar39 = ppppppppppppfVar9 <= ppppppppppppfVar40;
      bVar38 = ppppppppppppfVar40 == ppppppppppppfVar9;
    } while (!bVar38 && (int)ppppppppppppfVar9 <= (int)ppppppppppppfVar40);
  }
  ppppppppppppfVar5 = (float ************)0x0;
  local_1e84[0x29] = (float ***********)0x0;
  pppppppppppppfVar4 = (float *************)*DAT_0063ddd4;
  if (0 < (int)pppppppppppppfVar4) {
    do {
      pppppppppppppfVar4 = (float *************)DAT_0063ddd4[2];
      if (ppppppppppppfVar5 < (float ************)*DAT_0063ddd4) {
        pppppppppppppfVar4 = pppppppppppppfVar4 + (int)ppppppppppppfVar5 * 0x27;
      }
      ppppppppppppfVar9 = (float ************)local_1e84[0x29];
      if ((int)ppppppppppppfVar9 < (int)local_1e84[0x2a]) {
        local_1e84[0x29] = (float ***********)((int)ppppppppppppfVar9 + 1);
        local_1ecc = (float ************)(pppppppppppppfVar4 + 0xf);
        ppppppppppppfVar9 = (float ************)(local_1e84[0x2b] + (int)ppppppppppppfVar9 * 0x27);
        *ppppppppppppfVar9 = (float ***********)*pppppppppppppfVar4;
        local_1ee0 = ppppppppppppfVar9 + 0xc;
        ppppppppppppfVar9[1] = (float ***********)pppppppppppppfVar4[1];
        ppppppppppppfVar9[2] = (float ***********)pppppppppppppfVar4[2];
        ppppppppppppfVar9[3] = (float ***********)pppppppppppppfVar4[3];
        ppppppppppppfVar9[4] = (float ***********)pppppppppppppfVar4[4];
        ppppppppppppfVar9[5] = (float ***********)pppppppppppppfVar4[5];
        ppppppppppppfVar9[6] = (float ***********)pppppppppppppfVar4[6];
        ppppppppppppfVar9[7] = (float ***********)pppppppppppppfVar4[7];
        ppppppppppppfVar9[8] = (float ***********)pppppppppppppfVar4[8];
        ppppppppppppfVar9[9] = (float ***********)pppppppppppppfVar4[9];
        ppppppppppppfVar9[10] = (float ***********)pppppppppppppfVar4[10];
        ppppppppppppfVar9[0xb] = (float ***********)pppppppppppppfVar4[0xb];
        *local_1ee0 = (float ***********)pppppppppppppfVar4[0xc];
        ppppppppppppfVar9[0xd] = (float ***********)pppppppppppppfVar4[0xd];
        ppppppppppppfVar9[0xe] = (float ***********)pppppppppppppfVar4[0xe];
        ppppppppppppfVar9[0xf] = *local_1ecc;
        ppppppppppppfVar9[0x10] = (float ***********)pppppppppppppfVar4[0x10];
        ppppppppppppfVar9[0x11] = (float ***********)pppppppppppppfVar4[0x11];
        ppppppppppppfVar9[0x12] = (float ***********)pppppppppppppfVar4[0x12];
        ppppppppppppfVar9[0x13] = (float ***********)pppppppppppppfVar4[0x13];
        ppppppppppppfVar9[0x14] = (float ***********)pppppppppppppfVar4[0x14];
        ppppppppppppfVar9[0x15] = (float ***********)pppppppppppppfVar4[0x15];
        ppppppppppppfVar9[0x16] = (float ***********)pppppppppppppfVar4[0x16];
        ppppppppppppfVar9[0x17] = (float ***********)pppppppppppppfVar4[0x17];
        ppppppppppppfVar9[0x18] = (float ***********)pppppppppppppfVar4[0x18];
        ppppppppppppfVar9[0x19] = (float ***********)pppppppppppppfVar4[0x19];
        ppppppppppppfVar9[0x1a] = (float ***********)pppppppppppppfVar4[0x1a];
        ppppppppppppfVar9[0x1b] = (float ***********)pppppppppppppfVar4[0x1b];
        ppppppppppppfVar9[0x1c] = (float ***********)pppppppppppppfVar4[0x1c];
        ppppppppppppfVar9[0x1d] = (float ***********)pppppppppppppfVar4[0x1d];
        ppppppppppppfVar9[0x1e] = (float ***********)pppppppppppppfVar4[0x1e];
        ppppppppppppfVar9[0x1f] = (float ***********)pppppppppppppfVar4[0x1f];
        ppppppppppppfVar9[0x20] = (float ***********)pppppppppppppfVar4[0x20];
        ppppppppppppfVar9[0x21] = (float ***********)pppppppppppppfVar4[0x21];
        ppppppppppppfVar9[0x22] = (float ***********)pppppppppppppfVar4[0x22];
        ppppppppppppfVar9[0x23] = (float ***********)pppppppppppppfVar4[0x23];
        *(undefined1 *)(ppppppppppppfVar9 + 0x24) = *(undefined1 *)(pppppppppppppfVar4 + 0x24);
        *(undefined1 *)((int)ppppppppppppfVar9 + 0x91) =
             *(undefined1 *)((int)pppppppppppppfVar4 + 0x91);
        *(undefined1 *)((int)ppppppppppppfVar9 + 0x92) =
             *(undefined1 *)((int)pppppppppppppfVar4 + 0x92);
        *(undefined1 *)((int)ppppppppppppfVar9 + 0x93) =
             *(undefined1 *)((int)pppppppppppppfVar4 + 0x93);
        *(undefined1 *)(ppppppppppppfVar9 + 0x25) = *(undefined1 *)(pppppppppppppfVar4 + 0x25);
        *(undefined1 *)((int)ppppppppppppfVar9 + 0x95) =
             *(undefined1 *)((int)pppppppppppppfVar4 + 0x95);
        *(undefined1 *)((int)ppppppppppppfVar9 + 0x96) =
             *(undefined1 *)((int)pppppppppppppfVar4 + 0x96);
        *(undefined1 *)((int)ppppppppppppfVar9 + 0x97) =
             *(undefined1 *)((int)pppppppppppppfVar4 + 0x97);
        pppppppppppppfVar35 = pppppppppppppfVar4 + 0x26;
        pppppppppppppfVar4 = (float *************)(uint)*(byte *)pppppppppppppfVar35;
        *(byte *)(ppppppppppppfVar9 + 0x26) = *(byte *)pppppppppppppfVar35;
      }
      ppppppppppppfVar5 = (float ************)((int)ppppppppppppfVar5 + 1);
    } while ((int)ppppppppppppfVar5 < *DAT_0063ddd4);
  }
  if (((uint)local_1e50 & 1) != 0) {
    uVar51 = uVar50 >> 0x20;
    ppppppppppppfVar9 = (float ************)0x0;
    ppppppppppppfVar40 = (float ************)0x1;
    pppppppppppppfVar31 = local_30 + 0x29;
    pppppppppppppfVar35 = (float *************)*pppppppppppppfVar31;
    local_1db8 = (float *************)0x0;
    local_1e40 = (float ***********)0x0;
    if (0 < (int)pppppppppppppfVar35) {
      ppppppppppppfVar5 = (float ************)0x0;
      do {
        if (ppppppppppppfVar9 < *pppppppppppppfVar31) {
          pppppppppppppfVar4 = (float *************)(local_30[0x2b] + (int)ppppppppppppfVar9 * 0x27)
          ;
        }
        else {
          pppppppppppppfVar4 = (float *************)local_30[0x2b];
        }
        ppppppppppppfVar25 = local_30[0x2b];
        if (ppppppppppppfVar9 < *pppppppppppppfVar31) {
          ppppppppppppfVar25 = ppppppppppppfVar25 + (int)ppppppppppppfVar9 * 0x27;
        }
        ppppppppppppfVar9 = (float ************)((int)ppppppppppppfVar9 + 1);
        *(undefined1 *)(ppppppppppppfVar25 + 0x25) = 0;
        *(undefined1 *)((int)pppppppppppppfVar4 + 0x95) = 0;
      } while ((int)ppppppppppppfVar9 < (int)pppppppppppppfVar35);
    }
    if (1 < (int)pppppppppppppfVar35) {
      do {
        pppppfVar34 = DAT_0063ddc8;
        uVar59 = (undefined4)uVar51;
        uVar57 = (undefined4)(uVar50 >> 0x20);
        if ((float ************)((int)ppppppppppppfVar40 + -1) < *pppppppppppppfVar31) {
          ppppppppppppfVar5 = pppppppppppppfVar30[0x2b];
          ppppppppppppfVar9 = ppppppppppppfVar5 + ((int)ppppppppppppfVar40 + -1) * 0x27;
        }
        else {
          ppppppppppppfVar9 = pppppppppppppfVar30[0x2b];
        }
        if (ppppppppppppfVar40 < *pppppppppppppfVar31) {
          ppppppppppppfVar5 = pppppppppppppfVar30[0x2b];
          ppppppppppppfVar25 = ppppppppppppfVar5 + (int)ppppppppppppfVar40 * 0x27;
        }
        else {
          ppppppppppppfVar25 = pppppppppppppfVar30[0x2b];
        }
        if ((((int)ppppppppppppfVar9[7] <= (int)DAT_0063ddc8) &&
            (pppppppppppppfVar4 = (float *************)ppppppppppppfVar40,
            (int)ppppppppppppfVar25[7] <= (int)DAT_0063ddc8)) ||
           (pppppppppppppfVar4 = (float *************)DAT_0063ddb4,
           (float *******)
           CF_FBITS((ALBW_AS_F32(*ppppppppppppfVar9) * ALBW_AS_F32(ppppppppppppfVar25[6]) +
            ALBW_AS_F32(ppppppppppppfVar9[1]) * ALBW_AS_F32(ppppppppppppfVar25[7]) +
           ALBW_AS_F32(ppppppppppppfVar9[2]) * ALBW_AS_F32(ppppppppppppfVar25[8]))) <= DAT_0063ddb4)) break;
        fVar41 = ALBW_AS_F32(local_30[0x1c]) / ALBW_AS_F32(ppppppppppppfVar9[4]);
        if (*(char *)((int)ppppppppppppfVar9 + 0x93) == '\0') {
          pppppppppppfVar8 = (float ***********)(ppppppppppppfVar9 + 0x18);
        }
        else {
          pppppppppppfVar8 = (float ***********)(ppppppppppppfVar9 + 0xc);
        }
        fVar47 = ALBW_AS_F32(local_30[0x1c]) / ALBW_AS_F32(ppppppppppppfVar25[4]);
        local_1e08 = pppppppppppfVar8;
        func_00115D70((float *)&local_1e3c,(float *)(ppppppppppppfVar9 + 3),fVar41);
        local_1ed4 = (float ************)local_1e3c;
        local_1ed0 = local_1e38;
        local_1ecc = (float ************)local_1e34;
        func_00115C54((float *)&local_1dd4,(float *)pppppppppppfVar8,(float *)&local_1ed4);
        local_1e68 = local_1dd4;
        local_1e64 = (float ************)local_1dd0;
        local_1e60 = (float ***********)local_1dcc;
        local_1ee0 = (float ************)local_1dd4;
        local_1edc = (float ***********)local_1dd0;
        local_1ed8 = local_1dcc;
        if (*(char *)((int)ppppppppppppfVar25 + 0x93) == '\0') {
          ppppppppppppfVar5 = ppppppppppppfVar25 + 0x15;
        }
        else {
          ppppppppppppfVar5 = ppppppppppppfVar25 + 9;
        }
        func_00115D70((float *)&local_1dec,(float *)(ppppppppppppfVar25 + 3),fVar47);
        local_1e68 = local_1dec;
        local_1e64 = (float ************)local_1de8;
        local_1e60 = (float ***********)local_1de4;
        func_00115C54((float *)&local_1e90,(float *)ppppppppppppfVar5,(float *)&local_1e68);
        local_1ed4 = local_1e90;
        local_1ed0 = (float ***********)local_1e8c;
        local_1ecc = local_1e88;
        local_1e74 = (float ***********)local_1e90;
        local_1e70 = local_1e8c;
        local_1e6c = (float ***********)local_1e88;
        uVar50 = CONCAT44(uVar57,ALBW_AS_F32(*ppppppppppppfVar9) * ALBW_AS_F32(ppppppppppppfVar25[6]) +
                                 ALBW_AS_F32(ppppppppppppfVar9[1]) * ALBW_AS_F32(ppppppppppppfVar25[7]) +
                                 ALBW_AS_F32(ppppppppppppfVar9[2]) * ALBW_AS_F32(ppppppppppppfVar25[8]));
        func_00115C70((float *)&local_1e3c,(float *)&local_1ee0,(float *)ppppppppppppfVar5);
        fVar55 = (-(ALBW_AS_F32(ppppppppppppfVar25[6]) * ALBW_AS_F32(local_1e3c) +
                   ALBW_AS_F32(ppppppppppppfVar25[7]) * ALBW_AS_F32(local_1e38)) +
                 -(ALBW_AS_F32(ppppppppppppfVar25[8]) * ALBW_AS_F32(local_1e34))) / ALBW_AS_F32(uVar50);
        uVar51 = CONCAT44(fVar55,uVar59);
        if ((int)pppppfVar34 < (int)ALBW_AS_U32(fVar55)) {
          func_00115D70((float *)&local_1e04,(float *)ppppppppppppfVar9,fVar55);
          local_1e30 = local_1e04;
          local_1e2c = local_1e00;
          local_1e28 = (float ***********)ppppppppppppfStack_1dfc;
          func_00115C54((float *)&local_1de0,(float *)&local_1ee0,(float *)&local_1e30);
          ppppppppppppfVar9[0x12] = (float ***********)local_1de0;
          ppppppppppppfVar9[0x13] = (float ***********)local_1ddc;
          ppppppppppppfVar9[0x14] = local_1dd8;
          if (*(char *)((int)ppppppppppppfVar9 + 0x93) == '\x01') {
            func_00115D70((float *)&local_1df8,(float *)(ppppppppppppfVar9 + 3),
                          ALBW_AS_F32(((ulonglong)uVar49 >> 0x20)));
            local_1ed4 = (float ************)local_1df8;
            local_1ed0 = local_1df4;
            local_1ecc = (float ************)local_1df0;
            func_00115D70((float *)&local_1e18,(float *)&local_1ed4,fVar41);
            local_1e24 = local_1e18;
            local_1e20 = (float ************)local_1e14;
            local_1e1c = (float *************)local_1e10;
            func_00115C54((float *)(ppppppppppppfVar9 + 0x12),(float *)(ppppppppppppfVar9 + 0x12),
                          (float *)&local_1e24);
          }
          if (*(char *)((int)ppppppppppppfVar9 + 0x93) == '\0') {
            func_00115C70((float *)&local_1e68,(float *)(ppppppppppppfVar9 + 0x12),
                          (float *)(ppppppppppppfVar9 + 0xc));
            ppppppppppppfVar9[0x1b] =
                 (float ***********)
                 CF_FBITS((ALBW_AS_F32(*ppppppppppppfVar9) * ALBW_AS_F32(local_1e68) +
                  ALBW_AS_F32(ppppppppppppfVar9[1]) * ALBW_AS_F32(local_1e64) +
                 ALBW_AS_F32(ppppppppppppfVar9[2]) * ALBW_AS_F32(local_1e60)));
          }
          uVar51 = (ulonglong)(uint)ALBW_AS_U32((ALBW_AS_F32(uVar51) + ALBW_AS_F32((uVar51 >> 0x20))));
          *(undefined1 *)((int)ppppppppppppfVar9 + 0x95) = 1;
        }
        uVar59 = (undefined4)uVar51;
        fVar41 = -(ALBW_AS_F32(*ppppppppppppfVar25) * ALBW_AS_F32(ppppppppppppfVar9[6]) +
                   ALBW_AS_F32(ppppppppppppfVar25[1]) * ALBW_AS_F32(ppppppppppppfVar9[7]) +
                  ALBW_AS_F32(ppppppppppppfVar25[2]) * ALBW_AS_F32(ppppppppppppfVar9[8]));
        ppppppppppppfVar5 = (float ************)local_1e08;
        func_00115C70((float *)&local_1ed4,(float *)&local_1e74,(float *)local_1e08);
        fVar41 = (-(ALBW_AS_F32(ppppppppppppfVar9[6]) * ALBW_AS_F32(local_1ed4) +
                   ALBW_AS_F32(ppppppppppppfVar9[7]) * ALBW_AS_F32(local_1ed0)) +
                 -(ALBW_AS_F32(ppppppppppppfVar9[8]) * ALBW_AS_F32(local_1ecc))) / fVar41;
        uVar51 = CONCAT44(fVar41,uVar59);
        pppppppppppppfVar4 = (float *************)extraout_r1;
        if ((int)pppppfVar34 < (int)ALBW_AS_U32(fVar41)) {
          func_00115D70((float *)&local_1e90,(float *)ppppppppppppfVar25,fVar41);
          local_1e68 = (float ***********)local_1e90;
          local_1e64 = local_1e8c;
          local_1e60 = (float ***********)local_1e88;
          func_00115C70((float *)&local_1ed4,(float *)&local_1e74,(float *)&local_1e68);
          ppppppppppppfVar25[0xf] = (float ***********)local_1ed4;
          ppppppppppppfVar25[0x10] = local_1ed0;
          ppppppppppppfVar25[0x11] = (float ***********)local_1ecc;
          pppppppppppppfVar4 = (float *************)local_1ed0;
          ppppppppppppfVar5 = local_1ecc;
          if (*(char *)((int)ppppppppppppfVar25 + 0x93) == '\x01') {
            func_00115D70((float *)&local_1e68,(float *)(ppppppppppppfVar25 + 3),
                          ALBW_AS_F32(((ulonglong)uVar49 >> 0x20)));
            local_1ed4 = (float ************)local_1e68;
            local_1ed0 = (float ***********)local_1e64;
            local_1ecc = (float ************)local_1e60;
            func_00115D70((float *)&local_1e68,(float *)&local_1ed4,fVar47);
            ppppppppppppfVar5 = &local_1e3c;
            local_1e3c = local_1e68;
            local_1e38 = (float ***********)local_1e64;
            local_1e34 = local_1e60;
            func_00115C54((float *)(ppppppppppppfVar25 + 0xf),(float *)(ppppppppppppfVar25 + 0xf),
                          (float *)ppppppppppppfVar5);
            pppppppppppppfVar4 = (float *************)extraout_r1_00;
          }
          if (*(char *)((int)ppppppppppppfVar25 + 0x93) == '\0') {
            ppppppppppppfVar5 = ppppppppppppfVar25 + 0xf;
            func_00115C70((float *)&local_1e90,(float *)(ppppppppppppfVar25 + 9),
                          (float *)ppppppppppppfVar5);
            ppppppppppppfVar25[0x1b] =
                 (float ***********)
                 CF_FBITS((ALBW_AS_F32(*ppppppppppppfVar25) * ALBW_AS_F32(local_1e90) +
                  ALBW_AS_F32(ppppppppppppfVar25[1]) * ALBW_AS_F32(local_1e8c) +
                 ALBW_AS_F32(ppppppppppppfVar25[2]) * ALBW_AS_F32(local_1e88)));
            pppppppppppppfVar4 = (float *************)extraout_r1_01;
          }
          uVar51 = (ulonglong)(uint)ALBW_AS_U32((ALBW_AS_F32(uVar51) + ALBW_AS_F32((uVar51 >> 0x20))));
          *(undefined1 *)(ppppppppppppfVar25 + 0x25) = 1;
        }
        ppppppppppppfVar40 = (float ************)((int)ppppppppppppfVar40 + 1);
        local_1e40 = (float ***********)((int)local_1e40 + 1);
      } while ((int)ppppppppppppfVar40 < (int)pppppppppppppfVar35);
    }
    fVar41 = ALBW_AS_F32(uVar51);
    iVar6 = DAT_00640064;
    pppppppppppppfVar24 = pppppppppppppfVar35;
    if ((int)ppppppppppppfVar40 < (int)pppppppppppppfVar35) {
      while (pppppppppppppfVar36 = (float *************)((int)pppppppppppppfVar24 + -1),
            DAT_00640064 = iVar6, (int)ppppppppppppfVar40 <= (int)pppppppppppppfVar36) {
        uVar59 = (undefined4)(uVar50 >> 0x20);
        fVar41 = ALBW_AS_F32(uVar51);
        pppppppppppppfVar4 = (float *************)*pppppppppppppfVar31;
        ppppppppppppfVar9 = (float ************)((int)pppppppppppppfVar24 + -2);
        if (ppppppppppppfVar9 < pppppppppppppfVar4) {
          ppppppppppppfVar5 = (float ************)((int)ppppppppppppfVar9 * 0x27);
          ppppppppppppfVar25 = pppppppppppppfVar30[0x2b] + (int)ppppppppppppfVar9 * 0x27;
        }
        else {
          ppppppppppppfVar25 = pppppppppppppfVar30[0x2b];
          ppppppppppppfVar5 = ppppppppppppfVar9;
        }
        if (pppppppppppppfVar36 < pppppppppppppfVar4) {
          pppppppppppppfVar4 = (float *************)pppppppppppppfVar30[0x2b];
          ppppppppppppfVar5 = (float ************)((int)pppppppppppppfVar36 * 7);
          ppppppppppppfVar9 =
               (float ************)pppppppppppppfVar4 + (int)pppppppppppppfVar36 * 0x27;
        }
        else {
          ppppppppppppfVar9 = pppppppppppppfVar30[0x2b];
        }
        if ((((int)ppppppppppppfVar25[7] <= iVar6) && ((int)ppppppppppppfVar9[7] <= iVar6)) ||
           (pppppppppppppfVar4 =
                 (float *************)
                 CF_FBITS((ALBW_AS_F32(*ppppppppppppfVar25) * ALBW_AS_F32(ppppppppppppfVar9[6]) +
                  ALBW_AS_F32(ppppppppppppfVar25[1]) * ALBW_AS_F32(ppppppppppppfVar9[7]) +
                 ALBW_AS_F32(ppppppppppppfVar25[2]) * ALBW_AS_F32(ppppppppppppfVar9[8]))),
           pppppppppppppfVar4 <= DAT_00640068)) break;
        fVar47 = ALBW_AS_F32(local_30[0x1c]) / ALBW_AS_F32(ppppppppppppfVar25[4]);
        if (*(char *)((int)ppppppppppppfVar25 + 0x93) == '\0') {
          ppppppppppppfVar5 = ppppppppppppfVar25 + 0x18;
        }
        else {
          ppppppppppppfVar5 = ppppppppppppfVar25 + 0xc;
        }
        fVar55 = ALBW_AS_F32(local_30[0x1c]) / ALBW_AS_F32(ppppppppppppfVar9[4]);
        local_1e24 = (float ***********)ppppppppppppfVar5;
        func_00115D70((float *)&local_1df8,(float *)(ppppppppppppfVar25 + 3),fVar47);
        local_1edc = local_1df8;
        local_1ed8 = (float ************)local_1df4;
        local_1ed4 = (float ************)local_1df0;
        func_00115C54((float *)&local_1dd4,(float *)ppppppppppppfVar5,(float *)&local_1edc);
        local_1e68 = local_1dd4;
        local_1e64 = (float ************)local_1dd0;
        local_1e60 = (float ***********)local_1dcc;
        local_1e74 = local_1dd4;
        local_1e70 = (float ************)local_1dd0;
        local_1e6c = (float ***********)local_1dcc;
        if (*(char *)((int)ppppppppppppfVar9 + 0x93) == '\0') {
          pppppppppppppfVar4 = (float *************)(ppppppppppppfVar9 + 0x15);
        }
        else {
          pppppppppppppfVar4 = (float *************)(ppppppppppppfVar9 + 9);
        }
        local_1e90 = (float ************)pppppppppppppfVar4;
        func_00115D70((float *)&local_1e04,(float *)(ppppppppppppfVar9 + 3),fVar55);
        local_1e68 = (float ***********)local_1e04;
        local_1e64 = local_1e00;
        local_1e60 = (float ***********)ppppppppppppfStack_1dfc;
        func_00115C54((float *)&local_1dc4,(float *)pppppppppppppfVar4,(float *)&local_1e68);
        local_1edc = (float ***********)local_1dc4;
        local_1ed8 = (float ************)local_1dc0;
        local_1ed4 = (float ************)local_1dbc;
        local_1e3c = (float ***********)local_1dc4;
        local_1e38 = local_1dc0;
        local_1e34 = local_1dbc;
        uVar50 = CONCAT44(uVar59,ALBW_AS_F32(*ppppppppppppfVar25) * ALBW_AS_F32(ppppppppppppfVar9[6]) +
                                 ALBW_AS_F32(ppppppppppppfVar25[1]) * ALBW_AS_F32(ppppppppppppfVar9[7]) +
                                 ALBW_AS_F32(ppppppppppppfVar25[2]) * ALBW_AS_F32(ppppppppppppfVar9[8]));
        func_00115C70((float *)&local_1dec,(float *)&local_1e74,(float *)local_1e90);
        fVar53 = (-(ALBW_AS_F32(ppppppppppppfVar9[6]) * ALBW_AS_F32(local_1dec) +
                   ALBW_AS_F32(ppppppppppppfVar9[7]) * ALBW_AS_F32(local_1de8)) +
                 -(ALBW_AS_F32(ppppppppppppfVar9[8]) * ALBW_AS_F32(local_1de4))) / ALBW_AS_F32(uVar50);
        uVar51 = CONCAT44(fVar53,fVar41);
        if (iVar6 < (int)ALBW_AS_U32(fVar53)) {
          func_00115D70((float *)&local_1e1c,(float *)ppppppppppppfVar25,fVar53);
          local_1e90 = (float ************)local_1e1c;
          local_1e8c = (float ************)local_1e18;
          local_1e88 = (float ************)local_1e14;
          func_00115C54((float *)&local_1de0,(float *)&local_1e74,(float *)&local_1e90);
          ppppppppppppfVar25[0x12] = (float ***********)local_1de0;
          ppppppppppppfVar25[0x13] = (float ***********)local_1ddc;
          ppppppppppppfVar25[0x14] = local_1dd8;
          if (*(char *)((int)ppppppppppppfVar25 + 0x93) == '\x01') {
            func_00115D70((float *)&local_1e10,(float *)(ppppppppppppfVar25 + 3),
                          ALBW_AS_F32(((ulonglong)uVar49 >> 0x20)));
            local_1ee0 = local_1e10;
            local_1edc = (float ***********)local_1e0c;
            local_1ed8 = (float ************)local_1e08;
            func_00115D70((float *)&local_1e90,(float *)&local_1ee0,fVar47);
            local_1e30 = local_1e90;
            local_1e2c = local_1e8c;
            local_1e28 = (float ***********)local_1e88;
            func_00115C54((float *)(ppppppppppppfVar25 + 0x12),(float *)(ppppppppppppfVar25 + 0x12),
                          (float *)&local_1e30);
          }
          if (*(char *)((int)ppppppppppppfVar25 + 0x93) == '\0') {
            func_00115C70((float *)&local_1edc,(float *)(ppppppppppppfVar25 + 0x12),
                          (float *)(ppppppppppppfVar25 + 0xc));
            ppppppppppppfVar25[0x1b] =
                 (float ***********)
                 CF_FBITS((ALBW_AS_F32(*ppppppppppppfVar25) * ALBW_AS_F32(local_1edc) +
                  ALBW_AS_F32(ppppppppppppfVar25[1]) * ALBW_AS_F32(local_1ed8) +
                 ALBW_AS_F32(ppppppppppppfVar25[2]) * ALBW_AS_F32(local_1ed4)));
          }
          uVar51 = (ulonglong)(uint)ALBW_AS_U32((ALBW_AS_F32(uVar51) + ALBW_AS_F32((uVar51 >> 0x20))));
          *(undefined1 *)((int)ppppppppppppfVar25 + 0x95) = 1;
        }
        uVar59 = (undefined4)uVar51;
        fVar41 = -(ALBW_AS_F32(*ppppppppppppfVar9) * ALBW_AS_F32(ppppppppppppfVar25[6]) +
                   ALBW_AS_F32(ppppppppppppfVar9[1]) * ALBW_AS_F32(ppppppppppppfVar25[7]) +
                  ALBW_AS_F32(ppppppppppppfVar9[2]) * ALBW_AS_F32(ppppppppppppfVar25[8]));
        ppppppppppppfVar5 = (float ************)local_1e24;
        func_00115C70((float *)&local_1ee4,(float *)&local_1e3c,(float *)local_1e24);
        fVar41 = (-(ALBW_AS_F32(ppppppppppppfVar25[6]) * ALBW_AS_F32(local_1ee4) +
                   ALBW_AS_F32(ppppppppppppfVar25[7]) * ALBW_AS_F32(local_1ee0)) +
                 -(ALBW_AS_F32(ppppppppppppfVar25[8]) * ALBW_AS_F32(local_1edc))) / fVar41;
        uVar51 = CONCAT44(fVar41,uVar59);
        pppppppppppppfVar4 = extraout_r1_02;
        if (iVar6 < (int)ALBW_AS_U32(fVar41)) {
          func_00115D70((float *)&local_1e68,(float *)ppppppppppppfVar9,fVar41);
          local_1e90 = (float ************)local_1e68;
          local_1e8c = local_1e64;
          local_1e88 = (float ************)local_1e60;
          func_00115C70((float *)&local_1edc,(float *)&local_1e3c,(float *)&local_1e90);
          ppppppppppppfVar9[0xf] = local_1edc;
          ppppppppppppfVar9[0x10] = (float ***********)local_1ed8;
          ppppppppppppfVar9[0x11] = (float ***********)local_1ed4;
          pppppppppppppfVar4 = (float *************)local_1ed8;
          ppppppppppppfVar5 = local_1ed4;
          if (*(char *)((int)ppppppppppppfVar9 + 0x93) == '\x01') {
            func_00115D70((float *)&local_1e90,(float *)(ppppppppppppfVar9 + 3),
                          ALBW_AS_F32(((ulonglong)uVar49 >> 0x20)));
            local_1ee0 = local_1e90;
            local_1edc = (float ***********)local_1e8c;
            local_1ed8 = local_1e88;
            func_00115D70((float *)&local_1e90,(float *)&local_1ee0,fVar55);
            ppppppppppppfVar5 = &local_1e68;
            local_1e68 = (float ***********)local_1e90;
            local_1e64 = local_1e8c;
            local_1e60 = (float ***********)local_1e88;
            func_00115C54((float *)(ppppppppppppfVar9 + 0xf),(float *)(ppppppppppppfVar9 + 0xf),
                          (float *)ppppppppppppfVar5);
            pppppppppppppfVar4 = extraout_r1_03;
          }
          if (*(char *)((int)ppppppppppppfVar9 + 0x93) == '\0') {
            ppppppppppppfVar5 = ppppppppppppfVar9 + 0xf;
            func_00115C70((float *)&local_1edc,(float *)(ppppppppppppfVar9 + 9),
                          (float *)ppppppppppppfVar5);
            ppppppppppppfVar9[0x1b] =
                 (float ***********)
                 CF_FBITS((ALBW_AS_F32(*ppppppppppppfVar9) * ALBW_AS_F32(local_1edc) +
                  ALBW_AS_F32(ppppppppppppfVar9[1]) * ALBW_AS_F32(local_1ed8) +
                 ALBW_AS_F32(ppppppppppppfVar9[2]) * ALBW_AS_F32(local_1ed4)));
            pppppppppppppfVar4 = extraout_r1_04;
          }
          uVar51 = (ulonglong)(uint)ALBW_AS_U32((ALBW_AS_F32(uVar51) + ALBW_AS_F32((uVar51 >> 0x20))));
          *(undefined1 *)(ppppppppppppfVar9 + 0x25) = 1;
        }
        fVar41 = ALBW_AS_F32(uVar51);
        local_1db8 = (float *************)((int)local_1db8 + 1);
        iVar6 = DAT_00640064;
        pppppppppppppfVar24 = pppppppppppppfVar36;
      }
    }
    fVar47 = ALBW_AS_F32((uVar50 >> 0x20));
    if (fVar47 < fVar41) {
      pppppppppppppfVar36 = (float *************)((int)pppppppppppppfVar35 + -1);
      pppppppppppppfVar24 = (float *************)local_1e40;
      if (local_1e40 == (float ***********)pppppppppppppfVar36) {
        pppppppppppppfVar24 = local_1db8;
      }
      if (local_1e40 == (float ***********)pppppppppppppfVar36 &&
          pppppppppppppfVar24 == (float *************)0x0) {
        local_1db8 = (float *************)0x1;
        local_1e40 = (float ***********)((int)local_1e40 + -1);
      }
      fVar55 = fVar47;
      fVar53 = fVar47;
      if (0 < (int)local_1e40) {
        if (0 < (int)pppppppppppppfVar35) {
          pppppppppppppfVar4 = (float *************)pppppppppppppfVar30[0x2b];
          ppppppppppppfVar5 = *pppppppppppppfVar31;
        }
        ppppppppppppfVar9 = (float ************)0x0;
        if (0 < (int)pppppppppppppfVar35) {
          do {
            pppppppppppppfVar24 = pppppppppppppfVar4;
            if (ppppppppppppfVar9 < ppppppppppppfVar5) {
              pppppppppppppfVar24 = pppppppppppppfVar4 + (int)ppppppppppppfVar9 * 0x27;
            }
            if ((0x3effffff < (int)pppppppppppppfVar24[0x1d]) &&
               (ppppppppppppfVar40 = pppppppppppppfVar24[0x1c], (int)ppppppppppppfVar40 < 0x3f000001
               )) {
              if (ppppppppppppfVar9 == (float ************)0x0) {
                if ((float ************)0x1 < ppppppppppppfVar5) {
                  pppppppppppppfVar4 = pppppppppppppfVar4 + 0x27;
                }
                fVar55 = (ALBW_AS_F32(pppppppppppppfVar4[0x1d]) - ALBW_AS_F32(pppppppppppppfVar4[0x1c])) +
                         fVar47;
                fVar53 = (ALBW_AS_F32(pppppppppppppfVar24[0x1d]) - ALBW_AS_F32(ppppppppppppfVar40)) + fVar47;
              }
              else {
                ppppppppppppfVar25 = (float ************)((int)ppppppppppppfVar9 + -1);
                pppppppppppppfVar27 = pppppppppppppfVar4;
                if (ppppppppppppfVar25 < ppppppppppppfVar5) {
                  pppppppppppppfVar27 = pppppppppppppfVar4 + (int)ppppppppppppfVar25 * 0x27;
                }
                if (ppppppppppppfVar25 < ppppppppppppfVar5) {
                  pppppppppppppfVar4 = pppppppppppppfVar4 + ((int)ppppppppppppfVar9 + -1) * 0x27;
                }
                fVar55 = (ALBW_AS_F32(pppppppppppppfVar24[0x1d]) - ALBW_AS_F32(ppppppppppppfVar40)) + fVar47;
                fVar53 = (ALBW_AS_F32(pppppppppppppfVar27[0x1d]) - ALBW_AS_F32(pppppppppppppfVar4[0x1c])) +
                         fVar47;
              }
              break;
            }
            ppppppppppppfVar9 = (float ************)((int)ppppppppppppfVar9 + 1);
          } while ((int)ppppppppppppfVar9 < (int)pppppppppppppfVar35);
        }
      }
      if ((0 < (int)local_1db8) && (-1 < (int)pppppppppppppfVar36)) {
        ppppppppppppfVar5 = pppppppppppppfVar30[0x2b];
        pppppppppppppfVar24 = (float *************)*pppppppppppppfVar31;
        pppppppppppppfVar4 = pppppppppppppfVar36;
        do {
          ppppppppppppfVar9 = ppppppppppppfVar5;
          if (pppppppppppppfVar4 < pppppppppppppfVar24) {
            ppppppppppppfVar9 = ppppppppppppfVar5 + (int)pppppppppppppfVar4 * 0x27;
          }
          if ((0x3effffff < (int)ppppppppppppfVar9[0x1d]) &&
             (pppppppppppfVar8 = ppppppppppppfVar9[0x1c], (int)pppppppppppfVar8 < 0x3f000001)) {
            if (pppppppppppppfVar4 == pppppppppppppfVar36) {
              pppppppppppppfVar27 = (float *************)((int)pppppppppppppfVar4 + -1);
              ppppppppppppfVar40 = ppppppppppppfVar5;
              if (pppppppppppppfVar27 < pppppppppppppfVar24) {
                ppppppppppppfVar40 = ppppppppppppfVar5 + (int)pppppppppppppfVar27 * 0x27;
              }
              fVar55 = (ALBW_AS_F32(ppppppppppppfVar9[0x1d]) - ALBW_AS_F32(pppppppppppfVar8)) + fVar55;
              if (pppppppppppppfVar27 < pppppppppppppfVar24) {
                ppppppppppppfVar5 = ppppppppppppfVar5 + ((int)pppppppppppppfVar4 + -1) * 0x27;
              }
              fVar53 = (ALBW_AS_F32(ppppppppppppfVar40[0x1d]) - ALBW_AS_F32(ppppppppppppfVar5[0x1c])) + fVar53;
            }
            else {
              pppppppppppppfVar27 = (float *************)((int)pppppppppppppfVar4 + 1);
              ppppppppppppfVar40 = ppppppppppppfVar5;
              if (pppppppppppppfVar27 < pppppppppppppfVar24) {
                ppppppppppppfVar40 = ppppppppppppfVar5 + (int)pppppppppppppfVar27 * 0x27;
              }
              fVar53 = (ALBW_AS_F32(ppppppppppppfVar9[0x1d]) - ALBW_AS_F32(pppppppppppfVar8)) + fVar53;
              if (pppppppppppppfVar27 < pppppppppppppfVar24) {
                ppppppppppppfVar5 = ppppppppppppfVar5 + ((int)pppppppppppppfVar4 + 1) * 0x27;
              }
              fVar55 = (ALBW_AS_F32(ppppppppppppfVar40[0x1d]) - ALBW_AS_F32(ppppppppppppfVar5[0x1c])) + fVar55;
            }
            break;
          }
          pppppppppppppfVar4 = (float *************)((int)pppppppppppppfVar4 + -1);
        } while (-1 < (int)pppppppppppppfVar4);
      }
      uVar51 = (ulonglong)(uint)ALBW_AS_U32(fVar47);
      fVar54 = fVar47;
      if (fVar47 < fVar53 + fVar55) {
        fVar47 = fVar41 * fVar55 * (ALBW_AS_F32(uVar60) / (fVar53 + fVar55));
        fVar54 = fVar41 - fVar47;
      }
      ppppppppppppfVar5 = (float ************)0x0;
      for (; ((int)ppppppppppppfVar5 < (int)pppppppppppppfVar35 && (ALBW_AS_F32(uVar51) < fVar47));
          fVar47 = fVar47 - fVar41) {
        if (ppppppppppppfVar5 < *pppppppppppppfVar31) {
          ppppppppppppfVar9 = pppppppppppppfVar30[0x2b] + (int)ppppppppppppfVar5 * 0x27;
        }
        else {
          ppppppppppppfVar9 = pppppppppppppfVar30[0x2b];
        }
        func_00115C70((float *)&local_1ed0,(float *)(ppppppppppppfVar9 + 0x12),
                      (float *)(ppppppppppppfVar9 + 0xf));
        fVar41 = ALBW_AS_F32(*ppppppppppppfVar9) * ALBW_AS_F32(local_1ed0) +
                 ALBW_AS_F32(ppppppppppppfVar9[1]) * ALBW_AS_F32(local_1ecc) +
                 ALBW_AS_F32(ppppppppppppfVar9[2]) * ALBW_AS_F32(local_1ec8);
        if (fVar47 < fVar41) {
          bVar38 = false;
          fVar55 = ALBW_AS_F32(uVar51);
          fVar41 = fVar47 - ALBW_AS_F32(ppppppppppppfVar9[0x1b]);
          if (fVar47 - ALBW_AS_F32(ppppppppppppfVar9[0x1b]) < fVar55) {
            fVar41 = fVar55;
          }
          if (fVar41 == fVar55) {
            local_1e80 = (float ************)ppppppppppppfVar9[9];
            local_1e7c = (float ************)ppppppppppppfVar9[10];
            local_1e78 = (float ************)ppppppppppppfVar9[0xb];
LAB_0063f970:
            if (ppppppppppppfVar5 != (float ************)0x0) goto LAB_0063f994;
          }
          else {
            if (*(char *)((int)ppppppppppppfVar9 + 0x93) == '\0') {
              func_00115D70((float *)&local_1e90,(float *)ppppppppppppfVar9,fVar41);
              local_1ed0 = (float ***********)local_1e90;
              local_1ecc = local_1e8c;
              local_1ec8 = local_1e88;
              func_00115C54((float *)&local_1e90,(float *)(ppppppppppppfVar9 + 0xf),
                            (float *)&local_1ed0);
              local_1e80 = local_1e90;
              local_1e7c = local_1e8c;
              local_1e78 = local_1e88;
              goto LAB_0063f970;
            }
            func_00115D70((float *)&local_1e68,(float *)ppppppppppppfVar9,fVar41);
            local_1e90 = (float ************)local_1e68;
            local_1e8c = local_1e64;
            local_1e88 = (float ************)local_1e60;
            func_00115C54((float *)&local_1e68,(float *)(ppppppppppppfVar9 + 0xf),
                          (float *)&local_1e90);
            local_1ed0 = local_1e68;
            local_1ecc = local_1e64;
            local_1ec8 = (float ************)local_1e60;
            func_00115D70((float *)&local_1e68,(float *)(ppppppppppppfVar9 + 3),
                          ALBW_AS_F32(local_30[0x1c]));
            local_1e38 = local_1e68;
            local_1e34 = (float ***********)local_1e64;
            local_1e30 = (float ************)local_1e60;
            func_00115D88((float *)&local_1e68,(float *)&local_1e38,ALBW_AS_F32(ppppppppppppfVar9[4]));
            local_1e74 = local_1e68;
            local_1e70 = local_1e64;
            local_1e6c = local_1e60;
            func_00115C54((float *)&local_1e68,(float *)&local_1ed0,(float *)&local_1e74);
            local_1e80 = (float ************)local_1e68;
            local_1e7c = local_1e64;
            local_1e78 = (float ************)local_1e60;
            if (ppppppppppppfVar5 != (float ************)0x0) {
              if (*(char *)(ppppppppppppfVar9 + 0x25) != '\0') {
                func_00115D70((float *)&local_1e2c,(float *)ppppppppppppfVar9,fVar41);
                local_1e68 = (float ***********)local_1e2c;
                local_1e64 = (float ************)local_1e28;
                local_1e60 = local_1e24;
                func_00115C54((float *)(ppppppppppppfVar9 + 0xf),(float *)(ppppppppppppfVar9 + 0xf),
                              (float *)&local_1e68);
                func_00115C70((float *)&local_1e2c,(float *)&local_1e80,
                              (float *)(ppppppppppppfVar9 + 0xf));
                local_1e68 = (float ***********)local_1e2c;
                local_1e64 = (float ************)local_1e28;
                local_1e60 = local_1e24;
                func_0068906C((float *)&local_1edc,(float *)&local_1e68);
                bVar38 = true;
              }
              goto LAB_0063f994;
            }
          }
          if (*(char *)(ppppppppppppfVar9 + 0x26) == '\0') {
LAB_0063f994:
            ppppppppppppfVar9 = (float ************)0x0;
            local_1ee0 = ppppppppppppfVar5;
            goto LAB_0063fbfc;
          }
          ppppppppppppfVar9 = (float ************)0x0;
          local_1ee0 = (float ************)0x1;
          goto LAB_0063fc08;
        }
        ppppppppppppfVar5 = (float ************)((int)ppppppppppppfVar5 + 1);
      }
LAB_0063fc10:
      while( true ) {
        pppppppppppppfVar4 = (float *************)((int)pppppppppppppfVar35 + -1);
        bVar38 = (int)pppppppppppppfVar4 < 0;
        bVar39 = pppppppppppppfVar4 == (float *************)0x0;
        bVar37 = false;
        if (!bVar38) {
          fVar41 = ALBW_AS_F32(uVar51);
          bVar38 = fVar54 < fVar41;
          bVar39 = fVar54 == fVar41;
          bVar37 = NAN(fVar54) || NAN(fVar41);
        }
        if (bVar39 || bVar38 != bVar37) goto LAB_006400e8;
        if (pppppppppppppfVar4 < *pppppppppppppfVar31) {
          ppppppppppppfVar5 = pppppppppppppfVar30[0x2b] + (int)pppppppppppppfVar4 * 0x27;
        }
        else {
          ppppppppppppfVar5 = pppppppppppppfVar30[0x2b];
        }
        func_00115C70((float *)&local_1e90,(float *)(ppppppppppppfVar5 + 0x12),
                      (float *)(ppppppppppppfVar5 + 0xf));
        fVar41 = ALBW_AS_F32(*ppppppppppppfVar5) * ALBW_AS_F32(local_1e90) +
                 ALBW_AS_F32(ppppppppppppfVar5[1]) * ALBW_AS_F32(local_1e8c) +
                 ALBW_AS_F32(ppppppppppppfVar5[2]) * ALBW_AS_F32(local_1e88);
        if (fVar54 < fVar41) break;
        fVar54 = fVar54 - fVar41;
        pppppppppppppfVar35 = pppppppppppppfVar4;
      }
      bVar38 = false;
      fVar47 = ALBW_AS_F32(uVar51);
      fVar41 = fVar54 - ALBW_AS_F32(ppppppppppppfVar5[0x1b]);
      if (fVar54 - ALBW_AS_F32(ppppppppppppfVar5[0x1b]) < fVar47) {
        fVar41 = fVar47;
      }
      if (fVar41 == fVar47) {
        local_1e80 = (float ************)ppppppppppppfVar5[0xc];
        local_1e7c = (float ************)ppppppppppppfVar5[0xd];
        local_1e78 = (float ************)ppppppppppppfVar5[0xe];
      }
      else if (*(char *)((int)ppppppppppppfVar5 + 0x93) == '\0') {
        func_00115D70((float *)&local_1eec,(float *)ppppppppppppfVar5,fVar41);
        local_1e90 = local_1eec;
        local_1e8c = local_1ee8;
        local_1e88 = (float ************)local_1ee4;
        func_00115C70((float *)&local_1eec,(float *)(ppppppppppppfVar5 + 0x12),(float *)&local_1e90)
        ;
        local_1e80 = local_1eec;
        local_1e7c = local_1ee8;
        local_1e78 = (float ************)local_1ee4;
      }
      else {
        func_00115D70((float *)&local_1e28,(float *)ppppppppppppfVar5,fVar41);
        local_1e40 = local_1e28;
        local_1e3c = local_1e24;
        local_1e38 = (float ***********)local_1e20;
        func_00115C70((float *)&local_1ee8,(float *)(ppppppppppppfVar5 + 0x12),(float *)&local_1e40)
        ;
        local_1e70 = local_1ee8;
        local_1e6c = local_1ee4;
        local_1e68 = (float ***********)local_1ee0;
        func_00115D70((float *)&local_1e28,(float *)(ppppppppppppfVar5 + 3),ALBW_AS_F32(local_30[0x1c]));
        local_1e34 = local_1e28;
        local_1e30 = (float ************)local_1e24;
        local_1e2c = local_1e20;
        func_00115D88((float *)&local_1ee8,(float *)&local_1e34,ALBW_AS_F32(ppppppppppppfVar5[4]));
        local_1e90 = local_1ee8;
        local_1e8c = (float ************)local_1ee4;
        local_1e88 = local_1ee0;
        func_00115C54((float *)&local_1ee8,(float *)&local_1e70,(float *)&local_1e90);
        local_1e80 = local_1ee8;
        local_1e7c = (float ************)local_1ee4;
        local_1e78 = local_1ee0;
        pppppppppppppfVar24 = (float *************)local_1ee8;
        if (pppppppppppppfVar4 != pppppppppppppfVar36) {
          pppppppppppppfVar24 = (float *************)(uint)*(byte *)((int)ppppppppppppfVar5 + 0x95);
        }
        if (pppppppppppppfVar4 != pppppppppppppfVar36 &&
            pppppppppppppfVar24 != (float *************)0x0) {
          func_00115D70((float *)&local_1e28,(float *)ppppppppppppfVar5,fVar41);
          local_1ee8 = (float ************)local_1e28;
          local_1ee4 = local_1e24;
          local_1ee0 = local_1e20;
          func_00115C70((float *)(ppppppppppppfVar5 + 0x12),(float *)(ppppppppppppfVar5 + 0x12),
                        (float *)&local_1ee8);
          func_00115C70((float *)&local_1e28,(float *)&local_1e80,
                        (float *)(ppppppppppppfVar5 + 0x12));
          local_1ee8 = (float ************)local_1e28;
          local_1ee4 = local_1e24;
          local_1ee0 = local_1e20;
          func_0068906C((float *)&local_1edc,(float *)&local_1ee8);
          bVar38 = true;
        }
      }
      pppppppppppppfVar24 = pppppppppppppfVar4;
      if ((pppppppppppppfVar4 == pppppppppppppfVar36) &&
         (*(char *)(ppppppppppppfVar5 + 0x26) != '\0')) {
        pppppppppppppfVar24 = (float *************)((int)pppppppppppppfVar35 + -2);
      }
      pppppppppppppfVar35 = (float *************)*pppppppppppppfVar31;
LAB_006400dc:
      do {
        pppppppppppppfVar35 = (float *************)((int)pppppppppppppfVar35 + -1);
        pppppppppppppfVar36 =
             (float *************)((int)pppppppppppppfVar35 - (int)pppppppppppppfVar24);
        if ((int)pppppppppppppfVar35 >= (int)pppppppppppppfVar24) {
          pppppppppppppfVar36 = pppppppppppppfVar35;
        }
        if ((int)pppppppppppppfVar36 < 0 !=
            ((int)pppppppppppppfVar35 < (int)pppppppppppppfVar24 &&
            SBORROW4((int)pppppppppppppfVar35,(int)pppppppppppppfVar24))) break;
        if (pppppppppppppfVar35 < *pppppppppppppfVar31) {
          ppppppppppppfVar5 = pppppppppppppfVar30[0x2b] + (int)pppppppppppppfVar35 * 0x27;
        }
        else {
          ppppppppppppfVar5 = pppppppppppppfVar30[0x2b];
        }
        *(undefined1 *)((int)ppppppppppppfVar5 + 0x92) = 1;
        if (*(char *)((int)ppppppppppppfVar5 + 0x93) == '\0') {
          func_00115C70((float *)&local_1eec,(float *)&local_1e80,
                        (float *)(ppppppppppppfVar5 + 0x12));
          func_00115D70((float *)&local_1e8c,(float *)(ppppppppppppfVar5 + 6),
                        ALBW_AS_F32(ppppppppppppfVar5[6]) * ALBW_AS_F32(local_1eec) +
                        ALBW_AS_F32(ppppppppppppfVar5[7]) * ALBW_AS_F32(local_1ee8) +
                        ALBW_AS_F32(ppppppppppppfVar5[8]) * ALBW_AS_F32(local_1ee4));
          local_1e40 = (float ***********)local_1e8c;
          local_1e3c = (float ***********)local_1e88;
          local_1e38 = (float ***********)local_1e84;
          func_00115C70((float *)&local_1eec,(float *)&local_1e80,(float *)&local_1e40);
          ppppppppppppfVar5 = ppppppppppppfVar5 + 0x12;
          ppppppppppppfVar9 = local_1eec;
          ppppppppppppfVar40 = local_1ee8;
          pppppppppppfVar8 = local_1ee4;
        }
        else {
          if (pppppppppppppfVar35 != pppppppppppppfVar4 && bVar38) {
            fVar47 = ALBW_AS_F32(ppppppppppppfVar5[6]) * ALBW_AS_F32(local_1edc) +
                     ALBW_AS_F32(ppppppppppppfVar5[7]) * ALBW_AS_F32(local_1ed8) +
                     ALBW_AS_F32(ppppppppppppfVar5[8]) * ALBW_AS_F32(local_1ed4);
            fVar41 = fVar47;
            if (fVar47 <= ALBW_AS_F32(uVar51)) {
              fVar41 = -fVar47;
            }
            if (DAT_0064006c < (int)ALBW_AS_U32(fVar41)) {
              func_00115C70((float *)&local_1e10,(float *)&local_1e80,
                            (float *)(ppppppppppppfVar5 + 0xc));
              local_1e70 = local_1e10;
              local_1e6c = (float ***********)local_1e0c;
              local_1e68 = local_1e08;
              func_00115D70((float *)&local_1e04,(float *)&local_1edc,
                            ALBW_AS_F32(ppppppppppppfVar5[6]) * ALBW_AS_F32(local_1e10) +
                            ALBW_AS_F32(ppppppppppppfVar5[7]) * ALBW_AS_F32(local_1e0c) +
                            ALBW_AS_F32(ppppppppppppfVar5[8]) * ALBW_AS_F32(local_1e08));
              local_1ee8 = local_1e04;
              local_1ee4 = (float ***********)local_1e00;
              local_1ee0 = ppppppppppppfStack_1dfc;
              func_00115D88((float *)&local_1df8,(float *)&local_1ee8,fVar47);
              local_1e70 = (float ************)local_1df8;
              local_1e6c = local_1df4;
              local_1e68 = local_1df0;
              func_00115C70((float *)&local_1e5c,(float *)&local_1e80,(float *)&local_1e70);
              local_1e8c = (float ************)local_1e5c;
              local_1e88 = local_1e58;
              local_1e84 = (float ************)local_1e54;
              func_00115C70((float *)&local_1e28,(float *)&local_1e8c,
                            (float *)(ppppppppppppfVar5 + 0x12));
              local_1ee0 = local_1e20;
              local_1ee8 = (float ************)local_1e28;
              local_1ee4 = local_1e24;
              if (ALBW_AS_F32(uVar51) <
                  ALBW_AS_F32(local_1e28) * ALBW_AS_F32(ppppppppppppfVar5[3]) +
                  ALBW_AS_F32(local_1e24) * ALBW_AS_F32(ppppppppppppfVar5[4]) +
                  ALBW_AS_F32(local_1e20) * ALBW_AS_F32(ppppppppppppfVar5[5])) {
                ppppppppppppfVar5[0x18] = (float ***********)local_1e8c;
                ppppppppppppfVar5[0x19] = (float ***********)local_1e88;
                ppppppppppppfVar5[0x1a] = (float ***********)local_1e84;
                goto LAB_006400dc;
              }
            }
          }
          func_00115C70((float *)&local_1dec,(float *)&local_1e80,
                        (float *)(ppppppppppppfVar5 + 0x12));
          func_00115D70((float *)&local_1e1c,(float *)(ppppppppppppfVar5 + 6),
                        ALBW_AS_F32(ppppppppppppfVar5[6]) * ALBW_AS_F32(local_1dec) +
                        ALBW_AS_F32(ppppppppppppfVar5[7]) * ALBW_AS_F32(local_1de8) +
                        ALBW_AS_F32(ppppppppppppfVar5[8]) * ALBW_AS_F32(local_1de4));
          local_1e34 = (float ***********)local_1e1c;
          local_1e30 = (float ************)local_1e18;
          local_1e2c = (float ************)local_1e14;
          func_00115C70((float *)&local_1de0,(float *)&local_1e80,(float *)&local_1e34);
          ppppppppppppfVar5 = ppppppppppppfVar5 + 0x18;
          ppppppppppppfVar9 = (float ************)local_1de0;
          ppppppppppppfVar40 = (float ************)local_1ddc;
          pppppppppppfVar8 = local_1dd8;
        }
        *ppppppppppppfVar5 = (float ***********)ppppppppppppfVar9;
        ppppppppppppfVar5[1] = (float ***********)ppppppppppppfVar40;
        ppppppppppppfVar5[2] = pppppppppppfVar8;
      } while( true );
    }
  }
LAB_006400e8:
  pppppppppppppfVar30 = local_30;
  fVar41 = ALBW_AS_F32((uVar50 >> 0x20));
  if (((uint)local_1e50 & 2) != 0) {
    ppppppppppppfVar5 = (float ************)0x0;
    ppppppppppppfVar40 = (float ************)0x1;
    pppppppppppppfVar4 = local_30 + 0x29;
    ppppppppppppfVar9 = *pppppppppppppfVar4;
    local_1de4 = (float ************)0x0;
    local_1e50 = (float ***********)0x0;
    if (0 < (int)ppppppppppppfVar9) {
      do {
        if (ppppppppppppfVar5 < *pppppppppppppfVar4) {
          ppppppppppppfVar25 = local_30[0x2b] + (int)ppppppppppppfVar5 * 0x27;
          ppppppppppppfVar28 = local_30[0x2b] + (int)ppppppppppppfVar5 * 0x27;
        }
        else {
          ppppppppppppfVar25 = local_30[0x2b];
          ppppppppppppfVar28 = local_30[0x2b];
        }
        ppppppppppppfVar5 = (float ************)((int)ppppppppppppfVar5 + 1);
        *(undefined1 *)(ppppppppppppfVar28 + 0x25) = 0;
        *(undefined1 *)((int)ppppppppppppfVar25 + 0x95) = 0;
      } while ((int)ppppppppppppfVar5 < (int)ppppppppppppfVar9);
    }
    fVar47 = fVar41;
    if (1 < (int)ppppppppppppfVar9) {
      do {
        if ((float ************)((int)ppppppppppppfVar40 + -1) < *pppppppppppppfVar4) {
          ppppppppppppfVar5 = pppppppppppppfVar30[0x2b] + ((int)ppppppppppppfVar40 + -1) * 0x27;
        }
        else {
          ppppppppppppfVar5 = pppppppppppppfVar30[0x2b];
        }
        if (ppppppppppppfVar40 < *pppppppppppppfVar4) {
          ppppppppppppfVar25 = pppppppppppppfVar30[0x2b] + (int)ppppppppppppfVar40 * 0x27;
        }
        else {
          ppppppppppppfVar25 = pppppppppppppfVar30[0x2b];
        }
        if ((((int)ppppppppppppfVar5[7] <= DAT_00640064) &&
            ((int)ppppppppppppfVar25[7] <= DAT_00640064)) ||
           ((int)ALBW_AS_U32((ALBW_AS_F32(*ppppppppppppfVar5) * ALBW_AS_F32(ppppppppppppfVar25[6]) +
                  ALBW_AS_F32(ppppppppppppfVar5[1]) * ALBW_AS_F32(ppppppppppppfVar25[7]) +
                 ALBW_AS_F32(ppppppppppppfVar5[2]) * ALBW_AS_F32(ppppppppppppfVar25[8]))) <= DAT_006411c8))
        break;
        fVar47 = ALBW_AS_F32(local_30[0x1c]) / ALBW_AS_F32(ppppppppppppfVar5[4]);
        uVar50 = CONCAT44((int)(uVar50 >> 0x20),fVar47);
        if (*(char *)((int)ppppppppppppfVar5 + 0x93) == '\0') {
          ppppppppppppfVar28 = ppppppppppppfVar5 + 0xc;
        }
        else {
          ppppppppppppfVar28 = ppppppppppppfVar5 + 0x15;
        }
        fVar55 = ALBW_AS_F32(local_30[0x1c]) / ALBW_AS_F32(ppppppppppppfVar25[4]);
        local_1ec4 = ppppppppppppfVar28;
        func_00115D70((float *)&local_1e5c,(float *)(ppppppppppppfVar5 + 3),fVar47);
        local_1ee4 = (float ***********)local_1e5c;
        local_1ee0 = local_1e58;
        local_1edc = local_1e54;
        func_00115C70((float *)&local_1ed8,(float *)ppppppppppppfVar28,(float *)&local_1ee4);
        local_1e90 = local_1ed8;
        local_1e8c = local_1ed4;
        local_1e88 = (float ************)local_1ed0;
        local_1e80 = local_1ed8;
        local_1e7c = local_1ed4;
        local_1e78 = (float ************)local_1ed0;
        if (*(char *)((int)ppppppppppppfVar25 + 0x93) == '\0') {
          ppppppppppppfVar28 = ppppppppppppfVar25 + 9;
        }
        else {
          ppppppppppppfVar28 = ppppppppppppfVar25 + 0x15;
        }
        local_1ed4 = ppppppppppppfVar28;
        func_00115D70((float *)&local_1e5c,(float *)(ppppppppppppfVar25 + 3),fVar55);
        local_1e90 = (float ************)local_1e5c;
        local_1e8c = local_1e58;
        local_1e88 = (float ************)local_1e54;
        func_00115C70((float *)&local_1e5c,(float *)ppppppppppppfVar28,(float *)&local_1e90);
        local_1ee4 = (float ***********)local_1e5c;
        local_1ee0 = local_1e58;
        local_1edc = local_1e54;
        local_1e68 = (float ***********)local_1e5c;
        local_1e64 = local_1e58;
        local_1e60 = local_1e54;
        fVar47 = ALBW_AS_F32(*ppppppppppppfVar5) * ALBW_AS_F32(ppppppppppppfVar25[6]) +
                 ALBW_AS_F32(ppppppppppppfVar5[1]) * ALBW_AS_F32(ppppppppppppfVar25[7]) +
                 ALBW_AS_F32(ppppppppppppfVar5[2]) * ALBW_AS_F32(ppppppppppppfVar25[8]);
        func_00115C70((float *)&local_1ee8,(float *)&local_1e80,(float *)local_1ed4);
        fVar47 = (-(ALBW_AS_F32(ppppppppppppfVar25[6]) * ALBW_AS_F32(local_1ee8) +
                   ALBW_AS_F32(ppppppppppppfVar25[7]) * ALBW_AS_F32(local_1ee4)) +
                 -(ALBW_AS_F32(ppppppppppppfVar25[8]) * ALBW_AS_F32(local_1ee0))) / fVar47;
        if (DAT_00640064 < (int)ALBW_AS_U32(fVar47)) {
          if (*(char *)((int)ppppppppppppfVar5 + 0x93) == '\0') {
            ppppppppppppfVar28 = ppppppppppppfVar40;
            fVar53 = fVar41;
            if ((int)ppppppppppppfVar40 < (int)*pppppppppppppfVar4) {
              do {
                if (ppppppppppppfVar28 < *pppppppppppppfVar4) {
                  ppppppppppppfVar32 = pppppppppppppfVar30[0x2b] + (int)ppppppppppppfVar28 * 0x27;
                }
                else {
                  ppppppppppppfVar32 = pppppppppppppfVar30[0x2b];
                }
                func_00115C70((float *)&local_1ed8,(float *)(ppppppppppppfVar32 + 0xc),
                              (float *)(ppppppppppppfVar32 + 9));
                ppppppppppppfVar28 = (float ************)((int)ppppppppppppfVar28 + 1);
                fVar54 = ALBW_AS_F32(*ppppppppppppfVar32) * ALBW_AS_F32(local_1ed8) +
                         ALBW_AS_F32(ppppppppppppfVar32[1]) * ALBW_AS_F32(local_1ed4) +
                         ALBW_AS_F32(ppppppppppppfVar32[2]) * ALBW_AS_F32(local_1ed0);
                if (fVar54 <= fVar41) {
                  fVar54 = -fVar54;
                }
                fVar53 = fVar54 + fVar53;
              } while ((int)ppppppppppppfVar28 < (int)*pppppppppppppfVar4);
            }
            if (fVar53 < fVar47) {
              fVar47 = fVar53;
            }
            if (*(char *)((int)ppppppppppppfVar5 + 0x93) != '\0') goto LAB_006403e0;
            func_00115D70((float *)&local_1e34,(float *)ppppppppppppfVar5,fVar47);
            local_1e5c = (float *************)local_1e34;
            local_1e58 = local_1e30;
            local_1e54 = (float ***********)local_1e2c;
            func_00115C54((float *)&local_1e04,(float *)&local_1e80,(float *)&local_1e5c);
            ppppppppppppfVar5[0x12] = (float ***********)local_1e04;
            ppppppppppppfVar5[0x13] = (float ***********)local_1e00;
            ppppppppppppfVar5[0x14] = (float ***********)ppppppppppppfStack_1dfc;
          }
          else {
LAB_006403e0:
            func_00115D70((float *)&local_1e10,(float *)ppppppppppppfVar5,fVar47);
            local_1df8 = (float ***********)local_1e10;
            local_1df4 = (float ***********)local_1e0c;
            local_1df0 = local_1e08;
            func_00115C54((float *)(ppppppppppppfVar5 + 0x18),(float *)(ppppppppppppfVar5 + 0x18),
                          (float *)&local_1df8);
          }
          if (*(char *)((int)ppppppppppppfVar5 + 0x93) == '\0') {
            func_00115D70((float *)&local_1e5c,(float *)(ppppppppppppfVar5 + 3),ALBW_AS_F32(uVar60));
            local_1ee8 = (float ************)local_1e5c;
            local_1ee4 = (float ***********)local_1e58;
            local_1ee0 = (float ************)local_1e54;
            func_00115D70((float *)&local_1e5c,(float *)&local_1ee8,ALBW_AS_F32(uVar50));
            local_1e90 = (float ************)local_1e5c;
            local_1e8c = local_1e58;
            local_1e88 = (float ************)local_1e54;
            func_00115C54((float *)(ppppppppppppfVar5 + 0x12),(float *)(ppppppppppppfVar5 + 0x12),
                          (float *)&local_1e90);
          }
          *(undefined1 *)((int)ppppppppppppfVar5 + 0x95) = 1;
          if (*(char *)((int)ppppppppppppfVar25 + 0x93) == '\0') {
            if (*(char *)((int)ppppppppppppfVar5 + 0x93) == '\0') {
              local_1e88 = ppppppppppppfVar5 + 0x18;
              func_00115C70((float *)&local_1e5c,(float *)(ppppppppppppfVar5 + 0x18),
                            (float *)(ppppppppppppfVar5 + 0x12));
              func_00115D70((float *)&local_1e5c,(float *)(ppppppppppppfVar5 + 6),
                            ALBW_AS_F32(ppppppppppppfVar5[6]) * ALBW_AS_F32(local_1e5c) +
                            ALBW_AS_F32(ppppppppppppfVar5[7]) * ALBW_AS_F32(local_1e58) +
                            ALBW_AS_F32(ppppppppppppfVar5[8]) * ALBW_AS_F32(local_1e54));
              local_1ed8 = (float ************)local_1e5c;
              local_1ed4 = local_1e58;
              local_1ed0 = local_1e54;
              func_00115C70((float *)&local_1e5c,(float *)local_1e88,(float *)&local_1ed8);
              local_1e4c = (float ***********)local_1e5c;
              local_1e48 = local_1e58;
              local_1e44 = (float ************)local_1e54;
            }
            else {
              local_1e4c = ppppppppppppfVar5[0x12];
              local_1e48 = (float ************)ppppppppppppfVar5[0x13];
              local_1e44 = (float ************)ppppppppppppfVar5[0x14];
            }
            if (*(char *)((int)ppppppppppppfVar5 + 0x93) == '\0') {
              func_00115C70((float *)&local_1e90,(float *)(ppppppppppppfVar5 + 0x12),
                            (float *)&local_1e4c);
              local_1edc = (float ***********)local_1e90;
              local_1ed8 = local_1e8c;
              local_1ed4 = local_1e88;
              func_0068906C((float *)&local_1ee8,(float *)&local_1edc);
            }
            else {
              func_00115C70((float *)&local_1e90,(float *)(ppppppppppppfVar5 + 0x18),
                            (float *)&local_1e4c);
              local_1edc = (float ***********)local_1e90;
              local_1ed8 = local_1e8c;
              local_1ed4 = local_1e88;
              func_0068906C((float *)&local_1ee8,(float *)&local_1edc);
            }
            iVar6 = DAT_0064006c;
            fVar53 = ALBW_AS_F32(ppppppppppppfVar25[6]) * ALBW_AS_F32(local_1ee8) +
                     ALBW_AS_F32(ppppppppppppfVar25[7]) * ALBW_AS_F32(local_1ee4) +
                     ALBW_AS_F32(ppppppppppppfVar25[8]) * ALBW_AS_F32(local_1ee0);
            fVar47 = fVar53;
            if (fVar53 <= fVar41) {
              fVar47 = -fVar53;
            }
            if (DAT_0064006c < (int)ALBW_AS_U32(fVar47)) {
              func_00115C70((float *)&local_1edc,(float *)&local_1e4c,
                            (float *)(ppppppppppppfVar25 + 9));
              fVar47 = -(ALBW_AS_F32(ppppppppppppfVar25[6]) * ALBW_AS_F32(local_1edc) +
                         ALBW_AS_F32(ppppppppppppfVar25[7]) * ALBW_AS_F32(local_1ed8) +
                        ALBW_AS_F32(ppppppppppppfVar25[8]) * ALBW_AS_F32(local_1ed4));
              if (fVar47 <= fVar41) {
                if ((uint)ALBW_AS_U32(DAT_006411cc) < (uint)ALBW_AS_U32(fVar47)) {
                  func_00115C70((float *)&local_1edc,(float *)(ppppppppppppfVar5 + 0xc),
                                (float *)(ppppppppppppfVar5 + 9));
                  func_00115D70((float *)&local_1e90,(float *)ppppppppppppfVar25,
                                ALBW_AS_F32(*ppppppppppppfVar5) * ALBW_AS_F32(local_1edc) +
                                ALBW_AS_F32(ppppppppppppfVar5[1]) * ALBW_AS_F32(local_1ed8) +
                                ALBW_AS_F32(ppppppppppppfVar5[2]) * ALBW_AS_F32(local_1ed4));
                  local_1e34 = (float ***********)local_1e90;
                  local_1e30 = local_1e8c;
                  local_1e2c = local_1e88;
                  func_00115C70((float *)&local_1e90,(float *)&local_1e68,(float *)&local_1e34);
                  ppppppppppppfVar25[0xf] = (float ***********)local_1e90;
                  ppppppppppppfVar25[0x10] = (float ***********)local_1e8c;
                  ppppppppppppfVar25[0x11] = (float ***********)local_1e88;
                  func_00115D70((float *)&local_1ed8,(float *)(ppppppppppppfVar25 + 3),ALBW_AS_F32(uVar60)
                               );
                  local_1e40 = (float ***********)local_1ed8;
                  local_1e3c = (float ***********)local_1ed4;
                  local_1e38 = local_1ed0;
                  func_00115D70((float *)&local_1ed8,(float *)&local_1e40,fVar55);
                  local_1e34 = (float ***********)local_1ed8;
                  local_1e30 = local_1ed4;
                  local_1e2c = (float ************)local_1ed0;
                  func_00115C54((float *)(ppppppppppppfVar25 + 0xf),
                                (float *)(ppppppppppppfVar25 + 0xf),(float *)&local_1e34);
                  *(undefined1 *)(ppppppppppppfVar25 + 0x25) = 1;
                  if (*(char *)((int)ppppppppppppfVar25 + 0x93) == '\0') {
                    local_1ed0 = (float ***********)(ppppppppppppfVar25 + 0x15);
                    local_1e88 = ppppppppppppfVar25 + 6;
                    func_00115C70((float *)&local_1edc,(float *)(ppppppppppppfVar25 + 0x15),
                                  (float *)(ppppppppppppfVar25 + 0xf));
                    func_00115D70((float *)&local_1edc,(float *)local_1e88,
                                  ALBW_AS_F32(ppppppppppppfVar25[6]) * ALBW_AS_F32(local_1edc) +
                                  ALBW_AS_F32(ppppppppppppfVar25[7]) * ALBW_AS_F32(local_1ed8) +
                                  ALBW_AS_F32(ppppppppppppfVar25[8]) * ALBW_AS_F32(local_1ed4));
                    local_1e5c = (float *************)local_1edc;
                    local_1e58 = local_1ed8;
                    local_1e54 = (float ***********)local_1ed4;
                    func_00115C70((float *)&local_1edc,(float *)local_1ed0,(float *)&local_1e5c);
                    local_1e4c = local_1edc;
                    local_1e48 = local_1ed8;
                    local_1e44 = local_1ed4;
                  }
                  else {
                    local_1e4c = ppppppppppppfVar25[0xf];
                    local_1e48 = (float ************)ppppppppppppfVar25[0x10];
                    local_1e44 = (float ************)ppppppppppppfVar25[0x11];
                  }
                  if (*(char *)((int)ppppppppppppfVar25 + 0x93) == '\0') {
                    func_00115C70((float *)&local_1edc,(float *)(ppppppppppppfVar25 + 0xf),
                                  (float *)&local_1e4c);
                    local_1e90 = (float ************)local_1edc;
                    local_1e8c = local_1ed8;
                    local_1e88 = local_1ed4;
                    func_0068906C((float *)&local_1ee8,(float *)&local_1e90);
                  }
                  else {
                    func_00115C70((float *)&local_1edc,(float *)(ppppppppppppfVar25 + 0x15),
                                  (float *)&local_1e4c);
                    local_1e90 = (float ************)local_1edc;
                    local_1e8c = local_1ed8;
                    local_1e88 = local_1ed4;
                    func_0068906C((float *)&local_1ee8,(float *)&local_1e90);
                  }
                  fVar53 = ALBW_AS_F32(ppppppppppppfVar5[6]) * ALBW_AS_F32(local_1ee8) +
                           ALBW_AS_F32(ppppppppppppfVar5[7]) * ALBW_AS_F32(local_1ee4) +
                           ALBW_AS_F32(ppppppppppppfVar5[8]) * ALBW_AS_F32(local_1ee0);
                  fVar47 = fVar53;
                  if (fVar53 <= fVar41) {
                    fVar47 = -fVar53;
                  }
                  if (iVar6 < (int)ALBW_AS_U32(fVar47)) {
                    func_00115C70((float *)&local_1edc,(float *)&local_1e4c,
                                  (float *)(ppppppppppppfVar5 + 0xc));
                    fVar47 = -(ALBW_AS_F32(ppppppppppppfVar5[6]) * ALBW_AS_F32(local_1edc) +
                              ALBW_AS_F32(ppppppppppppfVar5[7]) * ALBW_AS_F32(local_1ed8)) +
                             -(ALBW_AS_F32(ppppppppppppfVar5[8]) * ALBW_AS_F32(local_1ed4));
                    if (fVar41 < fVar47) {
                      func_00115D70((float *)&local_1edc,(float *)&local_1ee8,fVar47);
                      local_1e90 = (float ************)local_1edc;
                      local_1e8c = local_1ed8;
                      local_1e88 = local_1ed4;
                      func_00115D88((float *)&local_1ed8,(float *)&local_1e90,fVar53);
                      local_1e1c = (float *************)local_1ed8;
                      local_1e18 = (float ***********)local_1ed4;
                      local_1e14 = local_1ed0;
                      func_00115C54((float *)&local_1edc,(float *)&local_1e4c,(float *)&local_1e1c);
                      local_1e5c = (float *************)local_1edc;
                      local_1e58 = local_1ed8;
                      local_1e54 = (float ***********)local_1ed4;
                      func_00115C70((float *)&local_1e10,(float *)(ppppppppppppfVar5 + 0x12),
                                    (float *)&local_1e5c);
                      local_1e90 = local_1e10;
                      local_1e8c = local_1e0c;
                      local_1e88 = (float ************)local_1e08;
                      if (fVar41 < ALBW_AS_F32(local_1e10) * ALBW_AS_F32(ppppppppppppfVar5[3]) +
                                   ALBW_AS_F32(local_1e0c) * ALBW_AS_F32(ppppppppppppfVar5[4]) +
                                   ALBW_AS_F32(local_1e08) * ALBW_AS_F32(ppppppppppppfVar5[5])) {
                        ppppppppppppfVar5[0x18] = (float ***********)local_1e5c;
                        ppppppppppppfVar5[0x19] = (float ***********)local_1e58;
                        ppppppppppppfVar5[0x1a] = local_1e54;
                        *(undefined1 *)((int)ppppppppppppfVar5 + 0x95) = 1;
                        if ((*(char *)((int)ppppppppppppfVar5 + 0x97) != '\0') &&
                           (*(char *)(ppppppppppppfVar5 + 0x25) == '\0')) {
                          ppppppppppppfVar28 = ppppppppppppfVar5 + 0x15;
                          ppppppppppppfVar5[0x15] = ppppppppppppfVar5[0x18];
                          ppppppppppppfVar5[0x16] = ppppppppppppfVar5[0x19];
                          pppppppppppfVar8 = ppppppppppppfVar5[0x1a];
                          goto LAB_00640a70;
                        }
                      }
                    }
                  }
                }
              }
              else {
                func_00115D70((float *)&local_1edc,(float *)&local_1ee8,fVar47);
                local_1e5c = (float *************)local_1edc;
                local_1e58 = local_1ed8;
                local_1e54 = (float ***********)local_1ed4;
                func_00115D88((float *)&local_1ed8,(float *)&local_1e5c,fVar53);
                local_1e34 = (float ***********)local_1ed8;
                local_1e30 = local_1ed4;
                local_1e2c = (float ************)local_1ed0;
                func_00115C54((float *)&local_1edc,(float *)&local_1e4c,(float *)&local_1e34);
                local_1e90 = (float ************)local_1edc;
                local_1e8c = local_1ed8;
                local_1e88 = local_1ed4;
                func_00115C70((float *)&local_1e40,(float *)(ppppppppppppfVar25 + 0xf),
                              (float *)&local_1e90);
                local_1e5c = (float *************)local_1e40;
                local_1e58 = (float ************)local_1e3c;
                local_1e54 = local_1e38;
                if (fVar41 < ALBW_AS_F32(local_1e40) * ALBW_AS_F32(ppppppppppppfVar25[3]) +
                             ALBW_AS_F32(local_1e3c) * ALBW_AS_F32(ppppppppppppfVar25[4]) +
                             ALBW_AS_F32(local_1e38) * ALBW_AS_F32(ppppppppppppfVar25[5])) {
                  ppppppppppppfVar25[0x15] = (float ***********)local_1e90;
                  ppppppppppppfVar25[0x16] = (float ***********)local_1e8c;
                  ppppppppppppfVar25[0x17] = (float ***********)local_1e88;
                  *(undefined1 *)(ppppppppppppfVar25 + 0x25) = 1;
                  if ((*(char *)((int)ppppppppppppfVar25 + 0x97) != '\0') &&
                     (*(char *)((int)ppppppppppppfVar25 + 0x95) == '\0')) {
                    ppppppppppppfVar28 = ppppppppppppfVar25 + 0x18;
                    ppppppppppppfVar25[0x18] = ppppppppppppfVar25[0x15];
                    ppppppppppppfVar25[0x19] = ppppppppppppfVar25[0x16];
                    pppppppppppfVar8 = ppppppppppppfVar25[0x17];
LAB_00640a70:
                    ppppppppppppfVar28[2] = pppppppppppfVar8;
                  }
                }
              }
            }
          }
        }
        fVar47 = -(ALBW_AS_F32(*ppppppppppppfVar25) * ALBW_AS_F32(ppppppppppppfVar5[6]) +
                   ALBW_AS_F32(ppppppppppppfVar25[1]) * ALBW_AS_F32(ppppppppppppfVar5[7]) +
                  ALBW_AS_F32(ppppppppppppfVar25[2]) * ALBW_AS_F32(ppppppppppppfVar5[8]));
        func_00115C70((float *)&local_1ee4,(float *)&local_1e68,(float *)local_1ec4);
        fVar47 = (-(ALBW_AS_F32(ppppppppppppfVar5[6]) * ALBW_AS_F32(local_1ee4) +
                   ALBW_AS_F32(ppppppppppppfVar5[7]) * ALBW_AS_F32(local_1ee0)) +
                 -(ALBW_AS_F32(ppppppppppppfVar5[8]) * ALBW_AS_F32(local_1edc))) / fVar47;
        if (DAT_00640064 < (int)ALBW_AS_U32(fVar47)) {
          if (*(char *)((int)ppppppppppppfVar25 + 0x93) == '\0') {
            ppppppppppppfVar28 = (float ************)0x0;
            fVar53 = fVar41;
            if (0 < (int)ppppppppppppfVar40) {
              do {
                if (ppppppppppppfVar28 < *pppppppppppppfVar4) {
                  ppppppppppppfVar32 = pppppppppppppfVar30[0x2b] + (int)ppppppppppppfVar28 * 0x27;
                }
                else {
                  ppppppppppppfVar32 = pppppppppppppfVar30[0x2b];
                }
                func_00115C70((float *)&local_1ed8,(float *)(ppppppppppppfVar32 + 0xc),
                              (float *)(ppppppppppppfVar32 + 9));
                ppppppppppppfVar28 = (float ************)((int)ppppppppppppfVar28 + 1);
                fVar54 = ALBW_AS_F32(*ppppppppppppfVar32) * ALBW_AS_F32(local_1ed8) +
                         ALBW_AS_F32(ppppppppppppfVar32[1]) * ALBW_AS_F32(local_1ed4) +
                         ALBW_AS_F32(ppppppppppppfVar32[2]) * ALBW_AS_F32(local_1ed0);
                if (fVar54 <= fVar41) {
                  fVar54 = -fVar54;
                }
                fVar53 = fVar54 + fVar53;
              } while ((int)ppppppppppppfVar28 < (int)ppppppppppppfVar40);
            }
            if (fVar53 < fVar47) {
              fVar47 = fVar53;
            }
            if (*(char *)((int)ppppppppppppfVar25 + 0x93) != '\0') goto LAB_00640b74;
            func_00115D70((float *)&local_1e90,(float *)ppppppppppppfVar25,fVar47);
            local_1edc = (float ***********)local_1e90;
            local_1ed8 = local_1e8c;
            local_1ed4 = local_1e88;
            func_00115C70((float *)&local_1e90,(float *)&local_1e68,(float *)&local_1edc);
            ppppppppppppfVar25[0xf] = (float ***********)local_1e90;
            ppppppppppppfVar25[0x10] = (float ***********)local_1e8c;
            ppppppppppppfVar25[0x11] = (float ***********)local_1e88;
          }
          else {
LAB_00640b74:
            local_1ed0 = (float ***********)CF_FBITS(-ALBW_AS_F32(ppppppppppppfVar25[2]));
            local_1ed8 = (float ************)CF_FBITS(-ALBW_AS_F32(*ppppppppppppfVar25));
            local_1ed4 = (float ************)CF_FBITS(-ALBW_AS_F32(ppppppppppppfVar25[1]));
            func_00115D70((float *)&local_1ee8,(float *)&local_1ed8,fVar47);
            local_1e90 = local_1ee8;
            local_1e8c = (float ************)local_1ee4;
            local_1e88 = local_1ee0;
            func_00115C54((float *)(ppppppppppppfVar25 + 0x15),(float *)(ppppppppppppfVar25 + 0x15),
                          (float *)&local_1e90);
          }
          if (*(char *)((int)ppppppppppppfVar25 + 0x93) == '\0') {
            func_00115D70((float *)&local_1ed4,(float *)(ppppppppppppfVar25 + 3),ALBW_AS_F32(uVar60));
            local_1ee4 = (float ***********)local_1ed4;
            local_1ee0 = (float ************)local_1ed0;
            local_1edc = (float ***********)local_1ecc;
            func_00115D70((float *)&local_1ed8,(float *)&local_1ee4,fVar55);
            local_1e90 = local_1ed8;
            local_1e8c = local_1ed4;
            local_1e88 = (float ************)local_1ed0;
            func_00115C54((float *)(ppppppppppppfVar25 + 0xf),(float *)(ppppppppppppfVar25 + 0xf),
                          (float *)&local_1e90);
          }
          *(undefined1 *)(ppppppppppppfVar25 + 0x25) = 1;
          if (*(char *)((int)ppppppppppppfVar5 + 0x93) == '\0') {
            if (*(char *)((int)ppppppppppppfVar25 + 0x93) == '\0') {
              func_00115C70((float *)&local_1e5c,(float *)(ppppppppppppfVar25 + 0x15),
                            (float *)(ppppppppppppfVar25 + 0xf));
              func_00115D70((float *)&local_1e5c,(float *)(ppppppppppppfVar25 + 6),
                            ALBW_AS_F32(ppppppppppppfVar25[6]) * ALBW_AS_F32(local_1e5c) +
                            ALBW_AS_F32(ppppppppppppfVar25[7]) * ALBW_AS_F32(local_1e58) +
                            ALBW_AS_F32(ppppppppppppfVar25[8]) * ALBW_AS_F32(local_1e54));
              local_1e90 = (float ************)local_1e5c;
              local_1e8c = local_1e58;
              local_1e88 = (float ************)local_1e54;
              func_00115C70((float *)&local_1ee8,(float *)(ppppppppppppfVar25 + 0x15),
                            (float *)&local_1e90);
              local_1e40 = (float ***********)local_1ee8;
              local_1e3c = local_1ee4;
              local_1e38 = (float ***********)local_1ee0;
            }
            else {
              local_1e40 = ppppppppppppfVar25[0xf];
              local_1e3c = ppppppppppppfVar25[0x10];
              local_1e38 = ppppppppppppfVar25[0x11];
            }
            if (*(char *)((int)ppppppppppppfVar25 + 0x93) == '\0') {
              func_00115C70((float *)&local_1e90,(float *)(ppppppppppppfVar25 + 0xf),
                            (float *)&local_1e40);
              local_1ee8 = local_1e90;
              local_1ee4 = (float ***********)local_1e8c;
              local_1ee0 = local_1e88;
              func_0068906C((float *)&local_1edc,(float *)&local_1ee8);
            }
            else {
              func_00115C70((float *)&local_1e90,(float *)(ppppppppppppfVar25 + 0x15),
                            (float *)&local_1e40);
              local_1ee8 = local_1e90;
              local_1ee4 = (float ***********)local_1e8c;
              local_1ee0 = local_1e88;
              func_0068906C((float *)&local_1edc,(float *)&local_1ee8);
            }
            iVar6 = DAT_0064006c;
            fVar55 = ALBW_AS_F32(ppppppppppppfVar5[6]) * ALBW_AS_F32(local_1edc) +
                     ALBW_AS_F32(ppppppppppppfVar5[7]) * ALBW_AS_F32(local_1ed8) +
                     ALBW_AS_F32(ppppppppppppfVar5[8]) * ALBW_AS_F32(local_1ed4);
            fVar47 = fVar55;
            if (fVar55 <= fVar41) {
              fVar47 = -fVar55;
            }
            if (DAT_0064006c < (int)ALBW_AS_U32(fVar47)) {
              func_00115C70((float *)&local_1e90,(float *)&local_1e40,
                            (float *)(ppppppppppppfVar5 + 0xc));
              fVar47 = -(ALBW_AS_F32(ppppppppppppfVar5[6]) * ALBW_AS_F32(local_1e90) +
                        ALBW_AS_F32(ppppppppppppfVar5[7]) * ALBW_AS_F32(local_1e8c)) +
                       -(ALBW_AS_F32(ppppppppppppfVar5[8]) * ALBW_AS_F32(local_1e88));
              if (fVar47 <= fVar41) {
                if ((uint)ALBW_AS_U32(DAT_006411cc) < (uint)ALBW_AS_U32(fVar47)) {
                  func_00115C70((float *)&local_1e90,(float *)(ppppppppppppfVar25 + 0xc),
                                (float *)(ppppppppppppfVar25 + 9));
                  func_00115D70((float *)&local_1e90,(float *)ppppppppppppfVar5,
                                ALBW_AS_F32(*ppppppppppppfVar25) * ALBW_AS_F32(local_1e90) +
                                ALBW_AS_F32(ppppppppppppfVar25[1]) * ALBW_AS_F32(local_1e8c) +
                                ALBW_AS_F32(ppppppppppppfVar25[2]) * ALBW_AS_F32(local_1e88));
                  local_1e34 = (float ***********)local_1e90;
                  local_1e30 = local_1e8c;
                  local_1e2c = local_1e88;
                  func_00115C54((float *)&local_1e90,(float *)&local_1e80,(float *)&local_1e34);
                  ppppppppppppfVar5[0x12] = (float ***********)local_1e90;
                  ppppppppppppfVar5[0x13] = (float ***********)local_1e8c;
                  ppppppppppppfVar5[0x14] = (float ***********)local_1e88;
                  func_00115D70((float *)&local_1e90,(float *)(ppppppppppppfVar5 + 3),ALBW_AS_F32(uVar60))
                  ;
                  local_1e5c = (float *************)local_1e90;
                  local_1e58 = local_1e8c;
                  local_1e54 = (float ***********)local_1e88;
                  func_00115D70((float *)&local_1e90,(float *)&local_1e5c,ALBW_AS_F32(uVar50));
                  local_1e34 = (float ***********)local_1e90;
                  local_1e30 = local_1e8c;
                  local_1e2c = local_1e88;
                  func_00115C54((float *)(ppppppppppppfVar5 + 0x12),
                                (float *)(ppppppppppppfVar5 + 0x12),(float *)&local_1e34);
                  *(undefined1 *)((int)ppppppppppppfVar5 + 0x95) = 1;
                  if (*(char *)((int)ppppppppppppfVar5 + 0x93) == '\0') {
                    local_1ed0 = (float ***********)(ppppppppppppfVar5 + 0x18);
                    func_00115C70((float *)&local_1e4c,(float *)(ppppppppppppfVar5 + 0x18),
                                  (float *)(ppppppppppppfVar5 + 0x12));
                    func_00115D70((float *)&local_1e4c,(float *)(ppppppppppppfVar5 + 6),
                                  ALBW_AS_F32(ppppppppppppfVar5[6]) * ALBW_AS_F32(local_1e4c) +
                                  ALBW_AS_F32(ppppppppppppfVar5[7]) * ALBW_AS_F32(local_1e48) +
                                  ALBW_AS_F32(ppppppppppppfVar5[8]) * ALBW_AS_F32(local_1e44));
                    local_1e90 = (float ************)local_1e4c;
                    local_1e8c = local_1e48;
                    local_1e88 = local_1e44;
                    func_00115C70((float *)&local_1ee8,(float *)local_1ed0,(float *)&local_1e90);
                    local_1e40 = (float ***********)local_1ee8;
                    local_1e3c = local_1ee4;
                    local_1e38 = (float ***********)local_1ee0;
                  }
                  else {
                    local_1e40 = ppppppppppppfVar5[0x12];
                    local_1e3c = ppppppppppppfVar5[0x13];
                    local_1e38 = ppppppppppppfVar5[0x14];
                  }
                  if (*(char *)((int)ppppppppppppfVar5 + 0x93) == '\0') {
                    func_00115C70((float *)&local_1e90,(float *)(ppppppppppppfVar5 + 0x12),
                                  (float *)&local_1e40);
                    local_1ee8 = local_1e90;
                    local_1ee4 = (float ***********)local_1e8c;
                    local_1ee0 = local_1e88;
                    func_0068906C((float *)&local_1edc,(float *)&local_1ee8);
                  }
                  else {
                    func_00115C70((float *)&local_1e90,(float *)(ppppppppppppfVar5 + 0x18),
                                  (float *)&local_1e40);
                    local_1ee8 = local_1e90;
                    local_1ee4 = (float ***********)local_1e8c;
                    local_1ee0 = local_1e88;
                    func_0068906C((float *)&local_1edc,(float *)&local_1ee8);
                  }
                  fVar55 = ALBW_AS_F32(ppppppppppppfVar25[6]) * ALBW_AS_F32(local_1edc) +
                           ALBW_AS_F32(ppppppppppppfVar25[7]) * ALBW_AS_F32(local_1ed8) +
                           ALBW_AS_F32(ppppppppppppfVar25[8]) * ALBW_AS_F32(local_1ed4);
                  fVar47 = fVar55;
                  if (fVar55 <= fVar41) {
                    fVar47 = -fVar55;
                  }
                  if (iVar6 < (int)ALBW_AS_U32(fVar47)) {
                    func_00115C70((float *)&local_1e90,(float *)&local_1e40,
                                  (float *)(ppppppppppppfVar25 + 9));
                    fVar47 = -(ALBW_AS_F32(ppppppppppppfVar25[6]) * ALBW_AS_F32(local_1e90) +
                              ALBW_AS_F32(ppppppppppppfVar25[7]) * ALBW_AS_F32(local_1e8c)) +
                             -(ALBW_AS_F32(ppppppppppppfVar25[8]) * ALBW_AS_F32(local_1e88));
                    if (fVar41 < fVar47) {
                      func_00115D70((float *)&local_1e28,(float *)&local_1edc,fVar47);
                      local_1e90 = (float ************)local_1e28;
                      local_1e8c = (float ************)local_1e24;
                      local_1e88 = local_1e20;
                      func_00115D88((float *)&local_1eec,(float *)&local_1e90,fVar55);
                      local_1e1c = (float *************)local_1eec;
                      local_1e18 = (float ***********)local_1ee8;
                      local_1e14 = local_1ee4;
                      func_00115C54((float *)&local_1eec,(float *)&local_1e40,(float *)&local_1e1c);
                      local_1e4c = (float ***********)local_1eec;
                      local_1e48 = local_1ee8;
                      local_1e44 = (float ************)local_1ee4;
                      func_00115C70((float *)&local_1e28,(float *)(ppppppppppppfVar25 + 0xf),
                                    (float *)&local_1e4c);
                      local_1e90 = (float ************)local_1e28;
                      local_1e8c = (float ************)local_1e24;
                      local_1e88 = local_1e20;
                      if (fVar41 < ALBW_AS_F32(local_1e28) * ALBW_AS_F32(ppppppppppppfVar25[3]) +
                                   ALBW_AS_F32(local_1e24) * ALBW_AS_F32(ppppppppppppfVar25[4]) +
                                   ALBW_AS_F32(local_1e20) * ALBW_AS_F32(ppppppppppppfVar25[5])) {
                        ppppppppppppfVar25[0x15] = local_1e4c;
                        ppppppppppppfVar25[0x16] = (float ***********)local_1e48;
                        ppppppppppppfVar25[0x17] = (float ***********)local_1e44;
                        *(undefined1 *)(ppppppppppppfVar25 + 0x25) = 1;
                        if ((*(char *)((int)ppppppppppppfVar25 + 0x97) != '\0') &&
                           (*(char *)((int)ppppppppppppfVar25 + 0x95) == '\0')) {
                          ppppppppppppfVar28 = ppppppppppppfVar25 + 0x18;
                          ppppppppppppfVar25[0x18] = ppppppppppppfVar25[0x15];
                          ppppppppppppfVar25[0x19] = ppppppppppppfVar25[0x16];
                          pppppppppppfVar8 = ppppppppppppfVar25[0x17];
                          goto LAB_0064123c;
                        }
                      }
                    }
                  }
                }
              }
              else {
                func_00115D70((float *)&local_1e34,(float *)&local_1edc,fVar47);
                local_1e5c = (float *************)local_1e34;
                local_1e58 = local_1e30;
                local_1e54 = (float ***********)local_1e2c;
                func_00115D88((float *)&local_1ee8,(float *)&local_1e5c,fVar55);
                local_1e4c = (float ***********)local_1ee8;
                local_1e48 = (float ************)local_1ee4;
                local_1e44 = local_1ee0;
                func_00115C54((float *)&local_1ee8,(float *)&local_1e40,(float *)&local_1e4c);
                local_1e90 = local_1ee8;
                local_1e8c = (float ************)local_1ee4;
                local_1e88 = local_1ee0;
                func_00115C70((float *)&local_1e34,(float *)(ppppppppppppfVar5 + 0x12),
                              (float *)&local_1e90);
                local_1e5c = (float *************)local_1e34;
                local_1e58 = local_1e30;
                local_1e54 = (float ***********)local_1e2c;
                if (fVar41 < ALBW_AS_F32(local_1e34) * ALBW_AS_F32(ppppppppppppfVar5[3]) +
                             ALBW_AS_F32(local_1e30) * ALBW_AS_F32(ppppppppppppfVar5[4]) +
                             ALBW_AS_F32(local_1e2c) * ALBW_AS_F32(ppppppppppppfVar5[5])) {
                  ppppppppppppfVar5[0x18] = (float ***********)local_1e90;
                  ppppppppppppfVar5[0x19] = (float ***********)local_1e8c;
                  ppppppppppppfVar5[0x1a] = (float ***********)local_1e88;
                  *(undefined1 *)((int)ppppppppppppfVar5 + 0x95) = 1;
                  if ((*(char *)((int)ppppppppppppfVar5 + 0x97) != '\0') &&
                     (*(char *)(ppppppppppppfVar5 + 0x25) == '\0')) {
                    ppppppppppppfVar28 = ppppppppppppfVar5 + 0x15;
                    ppppppppppppfVar5[0x15] = ppppppppppppfVar5[0x18];
                    ppppppppppppfVar5[0x16] = ppppppppppppfVar5[0x19];
                    pppppppppppfVar8 = ppppppppppppfVar5[0x1a];
LAB_0064123c:
                    ppppppppppppfVar28[2] = pppppppppppfVar8;
                  }
                }
              }
            }
          }
        }
        ppppppppppppfVar40 = (float ************)((int)ppppppppppppfVar40 + 1);
        local_1e50 = (float ***********)((int)local_1e50 + 1);
      } while ((int)ppppppppppppfVar40 < (int)ppppppppppppfVar9);
      fVar47 = fVar41;
      if (0 < (int)local_1e50) {
        ppppppppppppfVar5 = (float ************)0x0;
        do {
          if (ppppppppppppfVar5 < *pppppppppppppfVar4) {
            ppppppppppppfVar25 = pppppppppppppfVar30[0x2b] + (int)ppppppppppppfVar5 * 0x27;
          }
          else {
            ppppppppppppfVar25 = pppppppppppppfVar30[0x2b];
          }
          *(undefined1 *)((int)ppppppppppppfVar25 + 0x91) = 1;
          *(undefined1 *)((int)ppppppppppppfVar25 + 0x92) = 1;
          if (*(char *)((int)ppppppppppppfVar25 + 0x93) == '\0') {
            local_1e74 = ppppppppppppfVar25[0x15];
            local_1e70 = (float ************)ppppppppppppfVar25[0x16];
            local_1e6c = ppppppppppppfVar25[0x17];
            func_00115C70((float *)&local_1e68,(float *)&local_1e74,
                          (float *)(ppppppppppppfVar25 + 0xf));
            func_00115D70((float *)&local_1e80,(float *)(ppppppppppppfVar25 + 6),
                          ALBW_AS_F32(ppppppppppppfVar25[6]) * ALBW_AS_F32(local_1e68) +
                          ALBW_AS_F32(ppppppppppppfVar25[7]) * ALBW_AS_F32(local_1e64) +
                          ALBW_AS_F32(ppppppppppppfVar25[8]) * ALBW_AS_F32(local_1e60));
            local_1ee4 = (float ***********)local_1e80;
            local_1ee0 = local_1e7c;
            local_1edc = (float ***********)local_1e78;
            func_00115C70((float *)&local_1e5c,(float *)&local_1e74,(float *)&local_1ee4);
            ppppppppppppfVar25[0x15] = (float ***********)local_1e5c;
            ppppppppppppfVar25[0x16] = (float ***********)local_1e58;
            ppppppppppppfVar25[0x17] = local_1e54;
            local_1e74 = ppppppppppppfVar25[0x18];
            local_1e70 = (float ************)ppppppppppppfVar25[0x19];
            local_1e6c = ppppppppppppfVar25[0x1a];
            func_00115C70((float *)&local_1e90,(float *)&local_1e74,
                          (float *)(ppppppppppppfVar25 + 0x12));
            func_00115D70((float *)&local_1e4c,(float *)(ppppppppppppfVar25 + 6),
                          ALBW_AS_F32(ppppppppppppfVar25[6]) * ALBW_AS_F32(local_1e90) +
                          ALBW_AS_F32(ppppppppppppfVar25[7]) * ALBW_AS_F32(local_1e8c) +
                          ALBW_AS_F32(ppppppppppppfVar25[8]) * ALBW_AS_F32(local_1e88));
            local_1ee4 = local_1e4c;
            local_1ee0 = local_1e48;
            local_1edc = (float ***********)local_1e44;
            func_00115C70((float *)&local_1ed4,(float *)&local_1e74,(float *)&local_1ee4);
            ppppppppppppfVar25[0x18] = (float ***********)local_1ed4;
            ppppppppppppfVar25[0x19] = local_1ed0;
            ppppppppppppfVar25[0x1a] = (float ***********)local_1ecc;
          }
          ppppppppppppfVar5 = (float ************)((int)ppppppppppppfVar5 + 1);
        } while ((int)ppppppppppppfVar5 <= (int)local_1e50);
      }
    }
    fVar41 = ALBW_AS_F32((uVar50 >> 0x20));
    ppppppppppppfVar5 = (float ************)((int)ppppppppppppfVar9 + -1);
    if (((int)ppppppppppppfVar40 < (int)ppppppppppppfVar9) &&
       ((int)ppppppppppppfVar40 <= (int)ppppppppppppfVar5)) {
      do {
        if ((float ************)((int)ppppppppppppfVar5 + -1) < *pppppppppppppfVar4) {
          ppppppppppppfVar25 = pppppppppppppfVar30[0x2b] + ((int)ppppppppppppfVar5 + -1) * 0x27;
        }
        else {
          ppppppppppppfVar25 = pppppppppppppfVar30[0x2b];
        }
        if (ppppppppppppfVar5 < *pppppppppppppfVar4) {
          ppppppppppppfVar28 = pppppppppppppfVar30[0x2b] + (int)ppppppppppppfVar5 * 0x27;
        }
        else {
          ppppppppppppfVar28 = pppppppppppppfVar30[0x2b];
        }
        if ((((int)ppppppppppppfVar25[7] <= DAT_0064232c) &&
            ((int)ppppppppppppfVar28[7] <= DAT_0064232c)) ||
           ((int)ALBW_AS_U32((ALBW_AS_F32(*ppppppppppppfVar25) * ALBW_AS_F32(ppppppppppppfVar28[6]) +
                  ALBW_AS_F32(ppppppppppppfVar25[1]) * ALBW_AS_F32(ppppppppppppfVar28[7]) +
                 ALBW_AS_F32(ppppppppppppfVar25[2]) * ALBW_AS_F32(ppppppppppppfVar28[8]))) <= DAT_006411c8))
        break;
        fVar41 = ALBW_AS_F32(local_30[0x1c]) / ALBW_AS_F32(ppppppppppppfVar25[4]);
        uVar50 = CONCAT44((int)(uVar50 >> 0x20),fVar41);
        if (*(char *)((int)ppppppppppppfVar25 + 0x93) == '\0') {
          ppppppppppppfVar32 = ppppppppppppfVar25 + 0xc;
        }
        else {
          ppppppppppppfVar32 = ppppppppppppfVar25 + 0x15;
        }
        fVar55 = ALBW_AS_F32(local_30[0x1c]) / ALBW_AS_F32(ppppppppppppfVar28[4]);
        local_1e8c = ppppppppppppfVar32;
        func_00115D70((float *)&local_1e68,(float *)(ppppppppppppfVar25 + 3),fVar41);
        local_1e80 = (float ************)local_1e68;
        local_1e7c = local_1e64;
        local_1e78 = (float ************)local_1e60;
        func_00115C70((float *)&local_1e68,(float *)ppppppppppppfVar32,(float *)&local_1e80);
        local_1ee0 = (float ************)local_1e68;
        local_1edc = (float ***********)local_1e64;
        local_1ed8 = (float ************)local_1e60;
        local_1e50 = local_1e68;
        local_1e4c = (float ***********)local_1e64;
        local_1e48 = (float ************)local_1e60;
        if (*(char *)((int)ppppppppppppfVar28 + 0x93) == '\0') {
          pppppppppppppfVar35 = (float *************)(ppppppppppppfVar28 + 9);
        }
        else {
          pppppppppppppfVar35 = (float *************)(ppppppppppppfVar28 + 0x15);
        }
        local_1ed0 = (float ***********)pppppppppppppfVar35;
        func_00115D70((float *)&local_1e68,(float *)(ppppppppppppfVar28 + 3),fVar55);
        local_1ee0 = (float ************)local_1e68;
        local_1edc = (float ***********)local_1e64;
        local_1ed8 = (float ************)local_1e60;
        func_00115C70((float *)&local_1e68,(float *)pppppppppppppfVar35,(float *)&local_1ee0);
        local_1e80 = (float ************)local_1e68;
        local_1e7c = local_1e64;
        local_1e78 = (float ************)local_1e60;
        local_1e38 = local_1e68;
        local_1e34 = (float ***********)local_1e64;
        local_1e30 = (float ************)local_1e60;
        fVar41 = ALBW_AS_F32(*ppppppppppppfVar25) * ALBW_AS_F32(ppppppppppppfVar28[6]) +
                 ALBW_AS_F32(ppppppppppppfVar25[1]) * ALBW_AS_F32(ppppppppppppfVar28[7]) +
                 ALBW_AS_F32(ppppppppppppfVar25[2]) * ALBW_AS_F32(ppppppppppppfVar28[8]);
        func_00115C70((float *)&local_1e00,(float *)&local_1e50,(float *)local_1ed0);
        fVar41 = (-(ALBW_AS_F32(ppppppppppppfVar28[6]) * ALBW_AS_F32(local_1e00) +
                   ALBW_AS_F32(ppppppppppppfVar28[7]) * ALBW_AS_F32(ppppppppppppfStack_1dfc)) +
                 -(ALBW_AS_F32(ppppppppppppfVar28[8]) * ALBW_AS_F32(local_1df8))) / fVar41;
        if (DAT_0064232c < (int)ALBW_AS_U32(fVar41)) {
          if (*(char *)((int)ppppppppppppfVar25 + 0x93) == '\0') {
            ppppppppppppfVar32 = ppppppppppppfVar5;
            fVar53 = fVar47;
            if ((int)ppppppppppppfVar5 < (int)*pppppppppppppfVar4) {
              do {
                if (ppppppppppppfVar32 < *pppppppppppppfVar4) {
                  ppppppppppppfVar33 = pppppppppppppfVar30[0x2b] + (int)ppppppppppppfVar32 * 0x27;
                }
                else {
                  ppppppppppppfVar33 = pppppppppppppfVar30[0x2b];
                }
                func_00115C70((float *)&local_1e80,(float *)(ppppppppppppfVar33 + 0xc),
                              (float *)(ppppppppppppfVar33 + 9));
                ppppppppppppfVar32 = (float ************)((int)ppppppppppppfVar32 + 1);
                fVar54 = ALBW_AS_F32(*ppppppppppppfVar33) * ALBW_AS_F32(local_1e80) +
                         ALBW_AS_F32(ppppppppppppfVar33[1]) * ALBW_AS_F32(local_1e7c) +
                         ALBW_AS_F32(ppppppppppppfVar33[2]) * ALBW_AS_F32(local_1e78);
                if (fVar54 <= fVar47) {
                  fVar54 = -fVar54;
                }
                fVar53 = fVar54 + fVar53;
              } while ((int)ppppppppppppfVar32 < (int)*pppppppppppppfVar4);
            }
            if (fVar53 < fVar41) {
              fVar41 = fVar53;
            }
            if (*(char *)((int)ppppppppppppfVar25 + 0x93) != '\0') goto LAB_00641658;
            func_00115D70((float *)&local_1e24,(float *)ppppppppppppfVar25,fVar41);
            local_1e5c = (float *************)local_1e24;
            local_1e58 = local_1e20;
            local_1e54 = (float ***********)local_1e1c;
            func_00115C54((float *)&local_1df4,(float *)&local_1e50,(float *)&local_1e5c);
            ppppppppppppfVar25[0x12] = local_1df4;
            ppppppppppppfVar25[0x13] = local_1df0;
            ppppppppppppfVar25[0x14] = local_1dec;
          }
          else {
LAB_00641658:
            func_00115D70((float *)&local_1e0c,(float *)ppppppppppppfVar25,fVar41);
            local_1e18 = (float ***********)local_1e0c;
            local_1e14 = local_1e08;
            local_1e10 = local_1e04;
            func_00115C54((float *)(ppppppppppppfVar25 + 0x18),(float *)(ppppppppppppfVar25 + 0x18),
                          (float *)&local_1e18);
          }
          if (*(char *)((int)ppppppppppppfVar25 + 0x93) == '\0') {
            func_00115D70((float *)&local_1e80,(float *)(ppppppppppppfVar25 + 3),ALBW_AS_F32(uVar60));
            local_1ee4 = (float ***********)local_1e80;
            local_1ee0 = local_1e7c;
            local_1edc = (float ***********)local_1e78;
            func_00115D70((float *)&local_1e80,(float *)&local_1ee4,ALBW_AS_F32(uVar50));
            local_1e68 = (float ***********)local_1e80;
            local_1e64 = local_1e7c;
            local_1e60 = (float ***********)local_1e78;
            func_00115C54((float *)(ppppppppppppfVar25 + 0x12),(float *)(ppppppppppppfVar25 + 0x12),
                          (float *)&local_1e68);
          }
          *(undefined1 *)((int)ppppppppppppfVar25 + 0x95) = 1;
          if (*(char *)((int)ppppppppppppfVar28 + 0x93) == '\0') {
            if (*(char *)((int)ppppppppppppfVar25 + 0x93) == '\0') {
              local_1ecc = ppppppppppppfVar25 + 0x18;
              func_00115C70((float *)&local_1e68,(float *)(ppppppppppppfVar25 + 0x18),
                            (float *)(ppppppppppppfVar25 + 0x12));
              func_00115D70((float *)&local_1e68,(float *)(ppppppppppppfVar25 + 6),
                            ALBW_AS_F32(ppppppppppppfVar25[6]) * ALBW_AS_F32(local_1e68) +
                            ALBW_AS_F32(ppppppppppppfVar25[7]) * ALBW_AS_F32(local_1e64) +
                            ALBW_AS_F32(ppppppppppppfVar25[8]) * ALBW_AS_F32(local_1e60));
              local_1e5c = (float *************)local_1e68;
              local_1e58 = local_1e64;
              local_1e54 = local_1e60;
              func_00115C70((float *)&local_1e68,(float *)local_1ecc,(float *)&local_1e5c);
              local_1e80 = (float ************)local_1e68;
              local_1e7c = local_1e64;
              local_1e78 = (float ************)local_1e60;
            }
            else {
              local_1e80 = (float ************)ppppppppppppfVar25[0x12];
              local_1e7c = (float ************)ppppppppppppfVar25[0x13];
              local_1e78 = (float ************)ppppppppppppfVar25[0x14];
            }
            if (*(char *)((int)ppppppppppppfVar25 + 0x93) == '\0') {
              func_00115C70((float *)&local_1e5c,(float *)(ppppppppppppfVar25 + 0x12),
                            (float *)&local_1e80);
              local_1e68 = (float ***********)local_1e5c;
              local_1e64 = local_1e58;
              local_1e60 = local_1e54;
              func_0068906C((float *)&local_1ee8,(float *)&local_1e68);
            }
            else {
              func_00115C70((float *)&local_1e5c,(float *)(ppppppppppppfVar25 + 0x18),
                            (float *)&local_1e80);
              local_1e68 = (float ***********)local_1e5c;
              local_1e64 = local_1e58;
              local_1e60 = local_1e54;
              func_0068906C((float *)&local_1ee8,(float *)&local_1e68);
            }
            iVar6 = DAT_00642330;
            fVar53 = ALBW_AS_F32(ppppppppppppfVar28[6]) * ALBW_AS_F32(local_1ee8) +
                     ALBW_AS_F32(ppppppppppppfVar28[7]) * ALBW_AS_F32(local_1ee4) +
                     ALBW_AS_F32(ppppppppppppfVar28[8]) * ALBW_AS_F32(local_1ee0);
            fVar41 = fVar53;
            if (fVar53 <= fVar47) {
              fVar41 = -fVar53;
            }
            if (DAT_00642330 < (int)ALBW_AS_U32(fVar41)) {
              func_00115C70((float *)&local_1e68,(float *)&local_1e80,
                            (float *)(ppppppppppppfVar28 + 9));
              fVar41 = -(ALBW_AS_F32(ppppppppppppfVar28[6]) * ALBW_AS_F32(local_1e68) +
                        ALBW_AS_F32(ppppppppppppfVar28[7]) * ALBW_AS_F32(local_1e64)) +
                       -(ALBW_AS_F32(ppppppppppppfVar28[8]) * ALBW_AS_F32(local_1e60));
              if (fVar41 <= fVar47) {
                if ((uint)ALBW_AS_U32(DAT_006411cc) < (uint)ALBW_AS_U32(fVar41)) {
                  func_00115C70((float *)&local_1e68,(float *)(ppppppppppppfVar25 + 0xc),
                                (float *)(ppppppppppppfVar25 + 9));
                  func_00115D70((float *)&local_1e68,(float *)ppppppppppppfVar28,
                                ALBW_AS_F32(*ppppppppppppfVar25) * ALBW_AS_F32(local_1e68) +
                                ALBW_AS_F32(ppppppppppppfVar25[1]) * ALBW_AS_F32(local_1e64) +
                                ALBW_AS_F32(ppppppppppppfVar25[2]) * ALBW_AS_F32(local_1e60));
                  local_1e5c = (float *************)local_1e68;
                  local_1e58 = local_1e64;
                  local_1e54 = local_1e60;
                  func_00115C70((float *)&local_1e68,(float *)&local_1e38,(float *)&local_1e5c);
                  ppppppppppppfVar28[0xf] = local_1e68;
                  ppppppppppppfVar28[0x10] = (float ***********)local_1e64;
                  ppppppppppppfVar28[0x11] = local_1e60;
                  func_00115D70((float *)&local_1e68,(float *)(ppppppppppppfVar28 + 3),ALBW_AS_F32(uVar60)
                               );
                  local_1e0c = (float ************)local_1e68;
                  local_1e08 = (float ***********)local_1e64;
                  local_1e04 = (float ************)local_1e60;
                  func_00115D70((float *)&local_1e68,(float *)&local_1e0c,fVar55);
                  local_1e5c = (float *************)local_1e68;
                  local_1e58 = local_1e64;
                  local_1e54 = local_1e60;
                  func_00115C54((float *)(ppppppppppppfVar28 + 0xf),
                                (float *)(ppppppppppppfVar28 + 0xf),(float *)&local_1e5c);
                  *(undefined1 *)(ppppppppppppfVar28 + 0x25) = 1;
                  if (*(char *)((int)ppppppppppppfVar28 + 0x93) == '\0') {
                    local_1ecc = ppppppppppppfVar28 + 0x15;
                    local_1edc = (float ***********)(ppppppppppppfVar28 + 6);
                    func_00115C70((float *)&local_1e68,(float *)(ppppppppppppfVar28 + 0x15),
                                  (float *)(ppppppppppppfVar28 + 0xf));
                    func_00115D70((float *)&local_1e68,(float *)local_1edc,
                                  ALBW_AS_F32(ppppppppppppfVar28[6]) * ALBW_AS_F32(local_1e68) +
                                  ALBW_AS_F32(ppppppppppppfVar28[7]) * ALBW_AS_F32(local_1e64) +
                                  ALBW_AS_F32(ppppppppppppfVar28[8]) * ALBW_AS_F32(local_1e60));
                    local_1e44 = (float ************)local_1e68;
                    local_1e40 = (float ***********)local_1e64;
                    local_1e3c = local_1e60;
                    func_00115C70((float *)&local_1e68,(float *)local_1ecc,(float *)&local_1e44);
                    local_1e80 = (float ************)local_1e68;
                    local_1e7c = local_1e64;
                    local_1e78 = (float ************)local_1e60;
                  }
                  else {
                    local_1e80 = (float ************)ppppppppppppfVar28[0xf];
                    local_1e7c = (float ************)ppppppppppppfVar28[0x10];
                    local_1e78 = (float ************)ppppppppppppfVar28[0x11];
                  }
                  if (*(char *)((int)ppppppppppppfVar28 + 0x93) == '\0') {
                    func_00115C70((float *)&local_1e44,(float *)(ppppppppppppfVar28 + 0xf),
                                  (float *)&local_1e80);
                    local_1e68 = (float ***********)local_1e44;
                    local_1e64 = (float ************)local_1e40;
                    local_1e60 = local_1e3c;
                    func_0068906C((float *)&local_1ee8,(float *)&local_1e68);
                  }
                  else {
                    func_00115C70((float *)&local_1e44,(float *)(ppppppppppppfVar28 + 0x15),
                                  (float *)&local_1e80);
                    local_1e68 = (float ***********)local_1e44;
                    local_1e64 = (float ************)local_1e40;
                    local_1e60 = local_1e3c;
                    func_0068906C((float *)&local_1ee8,(float *)&local_1e68);
                  }
                  fVar53 = ALBW_AS_F32(ppppppppppppfVar25[6]) * ALBW_AS_F32(local_1ee8) +
                           ALBW_AS_F32(ppppppppppppfVar25[7]) * ALBW_AS_F32(local_1ee4) +
                           ALBW_AS_F32(ppppppppppppfVar25[8]) * ALBW_AS_F32(local_1ee0);
                  fVar41 = fVar53;
                  if (fVar53 <= fVar47) {
                    fVar41 = -fVar53;
                  }
                  if (iVar6 < (int)ALBW_AS_U32(fVar41)) {
                    func_00115C70((float *)&local_1e68,(float *)&local_1e80,
                                  (float *)(ppppppppppppfVar25 + 0xc));
                    fVar41 = -(ALBW_AS_F32(ppppppppppppfVar25[6]) * ALBW_AS_F32(local_1e68) +
                              ALBW_AS_F32(ppppppppppppfVar25[7]) * ALBW_AS_F32(local_1e64)) +
                             -(ALBW_AS_F32(ppppppppppppfVar25[8]) * ALBW_AS_F32(local_1e60));
                    if (fVar47 < fVar41) {
                      func_00115D70((float *)&local_1e24,(float *)&local_1ee8,fVar41);
                      local_1e18 = local_1e24;
                      local_1e14 = (float ***********)local_1e20;
                      local_1e10 = (float ************)local_1e1c;
                      func_00115D88((float *)&local_1e24,(float *)&local_1e18,fVar53);
                      local_1e44 = (float ************)local_1e24;
                      local_1e40 = (float ***********)local_1e20;
                      local_1e3c = (float ***********)local_1e1c;
                      func_00115C54((float *)&local_1e24,(float *)&local_1e80,(float *)&local_1e44);
                      local_1e68 = local_1e24;
                      local_1e64 = local_1e20;
                      local_1e60 = (float ***********)local_1e1c;
                      func_00115C70((float *)&local_1e24,(float *)(ppppppppppppfVar25 + 0x12),
                                    (float *)&local_1e68);
                      local_1e18 = local_1e24;
                      local_1e14 = (float ***********)local_1e20;
                      local_1e10 = (float ************)local_1e1c;
                      if (fVar47 < ALBW_AS_F32(local_1e24) * ALBW_AS_F32(ppppppppppppfVar25[3]) +
                                   ALBW_AS_F32(local_1e20) * ALBW_AS_F32(ppppppppppppfVar25[4]) +
                                   ALBW_AS_F32(local_1e1c) * ALBW_AS_F32(ppppppppppppfVar25[5])) {
                        ppppppppppppfVar25[0x18] = local_1e68;
                        ppppppppppppfVar25[0x19] = (float ***********)local_1e64;
                        ppppppppppppfVar25[0x1a] = local_1e60;
                        *(undefined1 *)((int)ppppppppppppfVar25 + 0x95) = 1;
                        if ((*(char *)((int)ppppppppppppfVar25 + 0x97) != '\0') &&
                           (*(char *)(ppppppppppppfVar25 + 0x25) == '\0')) {
                          ppppppppppppfVar32 = ppppppppppppfVar25 + 0x15;
                          ppppppppppppfVar25[0x15] = ppppppppppppfVar25[0x18];
                          ppppppppppppfVar25[0x16] = ppppppppppppfVar25[0x19];
                          pppppppppppfVar8 = ppppppppppppfVar25[0x1a];
                          goto LAB_00641cec;
                        }
                      }
                    }
                  }
                }
              }
              else {
                func_00115D70((float *)&local_1e44,(float *)&local_1ee8,fVar41);
                local_1e68 = (float ***********)local_1e44;
                local_1e64 = (float ************)local_1e40;
                local_1e60 = local_1e3c;
                func_00115D88((float *)&local_1e44,(float *)&local_1e68,fVar53);
                local_1e24 = (float ***********)local_1e44;
                local_1e20 = (float ************)local_1e40;
                local_1e1c = (float *************)local_1e3c;
                func_00115C54((float *)&local_1e44,(float *)&local_1e80,(float *)&local_1e24);
                local_1e5c = (float *************)local_1e44;
                local_1e58 = (float ************)local_1e40;
                local_1e54 = local_1e3c;
                func_00115C70((float *)&local_1e44,(float *)(ppppppppppppfVar28 + 0xf),
                              (float *)&local_1e5c);
                local_1e68 = (float ***********)local_1e44;
                local_1e64 = (float ************)local_1e40;
                local_1e60 = local_1e3c;
                if (fVar47 < ALBW_AS_F32(local_1e44) * ALBW_AS_F32(ppppppppppppfVar28[3]) +
                             ALBW_AS_F32(local_1e40) * ALBW_AS_F32(ppppppppppppfVar28[4]) +
                             ALBW_AS_F32(local_1e3c) * ALBW_AS_F32(ppppppppppppfVar28[5])) {
                  ppppppppppppfVar28[0x15] = (float ***********)local_1e5c;
                  ppppppppppppfVar28[0x16] = (float ***********)local_1e58;
                  ppppppppppppfVar28[0x17] = local_1e54;
                  *(undefined1 *)(ppppppppppppfVar28 + 0x25) = 1;
                  if ((*(char *)((int)ppppppppppppfVar28 + 0x97) != '\0') &&
                     (*(char *)((int)ppppppppppppfVar28 + 0x95) == '\0')) {
                    ppppppppppppfVar32 = ppppppppppppfVar28 + 0x18;
                    ppppppppppppfVar28[0x18] = ppppppppppppfVar28[0x15];
                    ppppppppppppfVar28[0x19] = ppppppppppppfVar28[0x16];
                    pppppppppppfVar8 = ppppppppppppfVar28[0x17];
LAB_00641cec:
                    ppppppppppppfVar32[2] = pppppppppppfVar8;
                  }
                }
              }
            }
          }
        }
        fVar41 = -(ALBW_AS_F32(*ppppppppppppfVar28) * ALBW_AS_F32(ppppppppppppfVar25[6]) +
                   ALBW_AS_F32(ppppppppppppfVar28[1]) * ALBW_AS_F32(ppppppppppppfVar25[7]) +
                  ALBW_AS_F32(ppppppppppppfVar28[2]) * ALBW_AS_F32(ppppppppppppfVar25[8]));
        func_00115C70((float *)&local_1ee4,(float *)&local_1e38,(float *)local_1e8c);
        fVar41 = (-(ALBW_AS_F32(ppppppppppppfVar25[6]) * ALBW_AS_F32(local_1ee4) +
                   ALBW_AS_F32(ppppppppppppfVar25[7]) * ALBW_AS_F32(local_1ee0)) +
                 -(ALBW_AS_F32(ppppppppppppfVar25[8]) * ALBW_AS_F32(local_1edc))) / fVar41;
        if (DAT_0064232c < (int)ALBW_AS_U32(fVar41)) {
          if (*(char *)((int)ppppppppppppfVar28 + 0x93) == '\0') {
            ppppppppppppfVar32 = (float ************)0x0;
            fVar53 = fVar47;
            if (0 < (int)ppppppppppppfVar5) {
              do {
                if (ppppppppppppfVar32 < *pppppppppppppfVar4) {
                  ppppppppppppfVar33 = pppppppppppppfVar30[0x2b] + (int)ppppppppppppfVar32 * 0x27;
                }
                else {
                  ppppppppppppfVar33 = pppppppppppppfVar30[0x2b];
                }
                func_00115C70((float *)&local_1e80,(float *)(ppppppppppppfVar33 + 0xc),
                              (float *)(ppppppppppppfVar33 + 9));
                ppppppppppppfVar32 = (float ************)((int)ppppppppppppfVar32 + 1);
                fVar54 = ALBW_AS_F32(*ppppppppppppfVar33) * ALBW_AS_F32(local_1e80) +
                         ALBW_AS_F32(ppppppppppppfVar33[1]) * ALBW_AS_F32(local_1e7c) +
                         ALBW_AS_F32(ppppppppppppfVar33[2]) * ALBW_AS_F32(local_1e78);
                if (fVar54 <= fVar47) {
                  fVar54 = -fVar54;
                }
                fVar53 = fVar54 + fVar53;
              } while ((int)ppppppppppppfVar32 < (int)ppppppppppppfVar5);
            }
            if (fVar53 < fVar41) {
              fVar41 = fVar53;
            }
            if (*(char *)((int)ppppppppppppfVar28 + 0x93) != '\0') goto LAB_00641df4;
            func_00115D70((float *)&local_1e80,(float *)ppppppppppppfVar28,fVar41);
            local_1e68 = (float ***********)local_1e80;
            local_1e64 = local_1e7c;
            local_1e60 = (float ***********)local_1e78;
            func_00115C70((float *)&local_1ee0,(float *)&local_1e38,(float *)&local_1e68);
            ppppppppppppfVar28[0xf] = (float ***********)local_1ee0;
            ppppppppppppfVar28[0x10] = local_1edc;
            ppppppppppppfVar28[0x11] = (float ***********)local_1ed8;
          }
          else {
LAB_00641df4:
            local_1e78 = (float ************)CF_FBITS(-ALBW_AS_F32(ppppppppppppfVar28[2]));
            local_1e80 = (float ************)CF_FBITS(-ALBW_AS_F32(*ppppppppppppfVar28));
            local_1e7c = (float ************)CF_FBITS(-ALBW_AS_F32(ppppppppppppfVar28[1]));
            func_00115D70((float *)&local_1ee8,(float *)&local_1e80,fVar41);
            local_1e68 = (float ***********)local_1ee8;
            local_1e64 = (float ************)local_1ee4;
            local_1e60 = (float ***********)local_1ee0;
            func_00115C54((float *)(ppppppppppppfVar28 + 0x15),(float *)(ppppppppppppfVar28 + 0x15),
                          (float *)&local_1e68);
          }
          if (*(char *)((int)ppppppppppppfVar28 + 0x93) == '\0') {
            func_00115D70((float *)&local_1e80,(float *)(ppppppppppppfVar28 + 3),ALBW_AS_F32(uVar60));
            local_1ee4 = (float ***********)local_1e80;
            local_1ee0 = local_1e7c;
            local_1edc = (float ***********)local_1e78;
            func_00115D70((float *)&local_1e90,(float *)&local_1ee4,fVar55);
            local_1e68 = (float ***********)local_1e90;
            local_1e64 = local_1e8c;
            local_1e60 = (float ***********)local_1e88;
            func_00115C54((float *)(ppppppppppppfVar28 + 0xf),(float *)(ppppppppppppfVar28 + 0xf),
                          (float *)&local_1e68);
          }
          *(undefined1 *)(ppppppppppppfVar28 + 0x25) = 1;
          if (*(char *)((int)ppppppppppppfVar25 + 0x93) == '\0') {
            if (*(char *)((int)ppppppppppppfVar28 + 0x93) == '\0') {
              local_1ed8 = ppppppppppppfVar28 + 0x15;
              func_00115C70((float *)&local_1e80,(float *)(ppppppppppppfVar28 + 0x15),
                            (float *)(ppppppppppppfVar28 + 0xf));
              func_00115D70((float *)&local_1e80,(float *)(ppppppppppppfVar28 + 6),
                            ALBW_AS_F32(ppppppppppppfVar28[6]) * ALBW_AS_F32(local_1e80) +
                            ALBW_AS_F32(ppppppppppppfVar28[7]) * ALBW_AS_F32(local_1e7c) +
                            ALBW_AS_F32(ppppppppppppfVar28[8]) * ALBW_AS_F32(local_1e78));
              local_1e5c = (float *************)local_1e80;
              local_1e58 = local_1e7c;
              local_1e54 = (float ***********)local_1e78;
              func_00115C70((float *)&local_1ee8,(float *)local_1ed8,(float *)&local_1e5c);
              local_1e68 = (float ***********)local_1ee8;
              local_1e64 = (float ************)local_1ee4;
              local_1e60 = (float ***********)local_1ee0;
            }
            else {
              local_1e68 = ppppppppppppfVar28[0xf];
              local_1e64 = (float ************)ppppppppppppfVar28[0x10];
              local_1e60 = ppppppppppppfVar28[0x11];
            }
            if (*(char *)((int)ppppppppppppfVar28 + 0x93) == '\0') {
              func_00115C70((float *)&local_1e80,(float *)(ppppppppppppfVar28 + 0xf),
                            (float *)&local_1e68);
              local_1ee8 = local_1e80;
              local_1ee4 = (float ***********)local_1e7c;
              local_1ee0 = local_1e78;
              func_0068906C((float *)&local_1e90,(float *)&local_1ee8);
            }
            else {
              func_00115C70((float *)&local_1e80,(float *)(ppppppppppppfVar28 + 0x15),
                            (float *)&local_1e68);
              local_1ee8 = local_1e80;
              local_1ee4 = (float ***********)local_1e7c;
              local_1ee0 = local_1e78;
              func_0068906C((float *)&local_1e90,(float *)&local_1ee8);
            }
            iVar6 = DAT_00642330;
            fVar55 = ALBW_AS_F32(ppppppppppppfVar25[6]) * ALBW_AS_F32(local_1e90) +
                     ALBW_AS_F32(ppppppppppppfVar25[7]) * ALBW_AS_F32(local_1e8c) +
                     ALBW_AS_F32(ppppppppppppfVar25[8]) * ALBW_AS_F32(local_1e88);
            fVar41 = fVar55;
            if (fVar55 <= fVar47) {
              fVar41 = -fVar55;
            }
            if (DAT_00642330 < (int)ALBW_AS_U32(fVar41)) {
              func_00115C70((float *)&local_1ee8,(float *)&local_1e68,
                            (float *)(ppppppppppppfVar25 + 0xc));
              fVar41 = -(ALBW_AS_F32(ppppppppppppfVar25[6]) * ALBW_AS_F32(local_1ee8) +
                        ALBW_AS_F32(ppppppppppppfVar25[7]) * ALBW_AS_F32(local_1ee4)) +
                       -(ALBW_AS_F32(ppppppppppppfVar25[8]) * ALBW_AS_F32(local_1ee0));
              if (fVar41 <= fVar47) {
                if ((uint)ALBW_AS_U32(DAT_006411cc) < (uint)ALBW_AS_U32(fVar41)) {
                  func_00115C70((float *)&local_1ee0,(float *)(ppppppppppppfVar28 + 0xc),
                                (float *)(ppppppppppppfVar28 + 9));
                  func_00115D70((float *)&local_1e80,(float *)ppppppppppppfVar25,
                                ALBW_AS_F32(*ppppppppppppfVar28) * ALBW_AS_F32(local_1ee0) +
                                ALBW_AS_F32(ppppppppppppfVar28[1]) * ALBW_AS_F32(local_1edc) +
                                ALBW_AS_F32(ppppppppppppfVar28[2]) * ALBW_AS_F32(local_1ed8));
                  local_1e5c = (float *************)local_1e80;
                  local_1e58 = local_1e7c;
                  local_1e54 = (float ***********)local_1e78;
                  func_00115C54((float *)&local_1ee0,(float *)&local_1e50,(float *)&local_1e5c);
                  ppppppppppppfVar25[0x12] = (float ***********)local_1ee0;
                  ppppppppppppfVar25[0x13] = local_1edc;
                  ppppppppppppfVar25[0x14] = (float ***********)local_1ed8;
                  func_00115D70((float *)&local_1ee0,(float *)(ppppppppppppfVar25 + 3),ALBW_AS_F32(uVar60)
                               );
                  local_1e44 = local_1ee0;
                  local_1e40 = local_1edc;
                  local_1e3c = (float ***********)local_1ed8;
                  func_00115D70((float *)&local_1ee4,(float *)&local_1e44,ALBW_AS_F32(uVar50));
                  local_1e5c = (float *************)local_1ee4;
                  local_1e58 = local_1ee0;
                  local_1e54 = local_1edc;
                  func_00115C54((float *)(ppppppppppppfVar25 + 0x12),
                                (float *)(ppppppppppppfVar25 + 0x12),(float *)&local_1e5c);
                  *(undefined1 *)((int)ppppppppppppfVar25 + 0x95) = 1;
                  if (*(char *)((int)ppppppppppppfVar25 + 0x93) == '\0') {
                    local_1edc = (float ***********)(ppppppppppppfVar25 + 0x18);
                    local_1ee4 = (float ***********)(ppppppppppppfVar25 + 6);
                    func_00115C70((float *)&local_1e80,(float *)(ppppppppppppfVar25 + 0x18),
                                  (float *)(ppppppppppppfVar25 + 0x12));
                    func_00115D70((float *)&local_1e80,(float *)local_1ee4,
                                  ALBW_AS_F32(ppppppppppppfVar25[6]) * ALBW_AS_F32(local_1e80) +
                                  ALBW_AS_F32(ppppppppppppfVar25[7]) * ALBW_AS_F32(local_1e7c) +
                                  ALBW_AS_F32(ppppppppppppfVar25[8]) * ALBW_AS_F32(local_1e78));
                    local_1e2c = local_1e80;
                    local_1e28 = (float ***********)local_1e7c;
                    local_1e24 = (float ***********)local_1e78;
                    func_00115C70((float *)&local_1ee8,(float *)local_1edc,(float *)&local_1e2c);
                    local_1e68 = (float ***********)local_1ee8;
                    local_1e64 = (float ************)local_1ee4;
                    local_1e60 = (float ***********)local_1ee0;
                  }
                  else {
                    local_1e68 = ppppppppppppfVar25[0x12];
                    local_1e64 = (float ************)ppppppppppppfVar25[0x13];
                    local_1e60 = ppppppppppppfVar25[0x14];
                  }
                  if (*(char *)((int)ppppppppppppfVar25 + 0x93) == '\0') {
                    func_00115C70((float *)&local_1e80,(float *)(ppppppppppppfVar25 + 0x12),
                                  (float *)&local_1e68);
                    local_1ee8 = local_1e80;
                    local_1ee4 = (float ***********)local_1e7c;
                    local_1ee0 = local_1e78;
                    func_0068906C((float *)&local_1e90,(float *)&local_1ee8);
                  }
                  else {
                    func_00115C70((float *)&local_1e80,(float *)(ppppppppppppfVar25 + 0x18),
                                  (float *)&local_1e68);
                    local_1ee8 = local_1e80;
                    local_1ee4 = (float ***********)local_1e7c;
                    local_1ee0 = local_1e78;
                    func_0068906C((float *)&local_1e90,(float *)&local_1ee8);
                  }
                  fVar55 = ALBW_AS_F32(ppppppppppppfVar28[6]) * ALBW_AS_F32(local_1e90) +
                           ALBW_AS_F32(ppppppppppppfVar28[7]) * ALBW_AS_F32(local_1e8c) +
                           ALBW_AS_F32(ppppppppppppfVar28[8]) * ALBW_AS_F32(local_1e88);
                  fVar41 = fVar55;
                  if (fVar55 <= fVar47) {
                    fVar41 = -fVar55;
                  }
                  if (iVar6 < (int)ALBW_AS_U32(fVar41)) {
                    func_00115C70((float *)&local_1eec,(float *)&local_1e68,
                                  (float *)(ppppppppppppfVar28 + 9));
                    fVar41 = -(ALBW_AS_F32(ppppppppppppfVar28[6]) * ALBW_AS_F32(local_1eec) +
                               ALBW_AS_F32(ppppppppppppfVar28[7]) * ALBW_AS_F32(local_1ee8) +
                              ALBW_AS_F32(ppppppppppppfVar28[8]) * ALBW_AS_F32(local_1ee4));
                    if (fVar47 < fVar41) {
                      func_00115D70((float *)&local_1e20,(float *)&local_1e90,fVar41);
                      local_1ee8 = local_1e20;
                      local_1ee4 = (float ***********)local_1e1c;
                      local_1ee0 = (float ************)local_1e18;
                      func_00115D88((float *)&local_1e20,(float *)&local_1ee8,fVar55);
                      local_1e2c = local_1e20;
                      local_1e28 = (float ***********)local_1e1c;
                      local_1e24 = local_1e18;
                      func_00115C54((float *)&local_1e20,(float *)&local_1e68,(float *)&local_1e2c);
                      local_1e80 = local_1e20;
                      local_1e7c = (float ************)local_1e1c;
                      local_1e78 = (float ************)local_1e18;
                      func_00115C70((float *)&local_1e20,(float *)(ppppppppppppfVar28 + 0xf),
                                    (float *)&local_1e80);
                      local_1ee8 = local_1e20;
                      local_1ee4 = (float ***********)local_1e1c;
                      local_1ee0 = (float ************)local_1e18;
                      if (fVar47 < ALBW_AS_F32(local_1e20) * ALBW_AS_F32(ppppppppppppfVar28[3]) +
                                   ALBW_AS_F32(local_1e1c) * ALBW_AS_F32(ppppppppppppfVar28[4]) +
                                   ALBW_AS_F32(local_1e18) * ALBW_AS_F32(ppppppppppppfVar28[5])) {
                        ppppppppppppfVar28[0x15] = (float ***********)local_1e80;
                        ppppppppppppfVar28[0x16] = (float ***********)local_1e7c;
                        ppppppppppppfVar28[0x17] = (float ***********)local_1e78;
                        *(undefined1 *)(ppppppppppppfVar28 + 0x25) = 1;
                        if ((*(char *)((int)ppppppppppppfVar28 + 0x97) != '\0') &&
                           (*(char *)((int)ppppppppppppfVar28 + 0x95) == '\0')) {
                          ppppppppppppfVar32 = ppppppppppppfVar28 + 0x18;
                          ppppppppppppfVar28[0x18] = ppppppppppppfVar28[0x15];
                          ppppppppppppfVar28[0x19] = ppppppppppppfVar28[0x16];
                          pppppppppppfVar8 = ppppppppppppfVar28[0x17];
                          goto LAB_006424d4;
                        }
                      }
                    }
                  }
                }
              }
              else {
                func_00115D70((float *)&local_1e5c,(float *)&local_1e90,fVar41);
                local_1ee4 = (float ***********)local_1e5c;
                local_1ee0 = local_1e58;
                local_1edc = local_1e54;
                func_00115D88((float *)&local_1e5c,(float *)&local_1ee4,fVar55);
                local_1e44 = (float ************)local_1e5c;
                local_1e40 = (float ***********)local_1e58;
                local_1e3c = local_1e54;
                func_00115C54((float *)&local_1e5c,(float *)&local_1e68,(float *)&local_1e44);
                local_1e80 = (float ************)local_1e5c;
                local_1e7c = local_1e58;
                local_1e78 = (float ************)local_1e54;
                func_00115C70((float *)&local_1e5c,(float *)(ppppppppppppfVar25 + 0x12),
                              (float *)&local_1e80);
                local_1ee4 = (float ***********)local_1e5c;
                local_1ee0 = local_1e58;
                local_1edc = local_1e54;
                if (fVar47 < ALBW_AS_F32(local_1e5c) * ALBW_AS_F32(ppppppppppppfVar25[3]) +
                             ALBW_AS_F32(local_1e58) * ALBW_AS_F32(ppppppppppppfVar25[4]) +
                             ALBW_AS_F32(local_1e54) * ALBW_AS_F32(ppppppppppppfVar25[5])) {
                  ppppppppppppfVar25[0x18] = (float ***********)local_1e80;
                  ppppppppppppfVar25[0x19] = (float ***********)local_1e7c;
                  ppppppppppppfVar25[0x1a] = (float ***********)local_1e78;
                  *(undefined1 *)((int)ppppppppppppfVar25 + 0x95) = 1;
                  if ((*(char *)((int)ppppppppppppfVar25 + 0x97) != '\0') &&
                     (*(char *)(ppppppppppppfVar25 + 0x25) == '\0')) {
                    ppppppppppppfVar32 = ppppppppppppfVar25 + 0x15;
                    ppppppppppppfVar25[0x15] = ppppppppppppfVar25[0x18];
                    ppppppppppppfVar25[0x16] = ppppppppppppfVar25[0x19];
                    pppppppppppfVar8 = ppppppppppppfVar25[0x1a];
LAB_006424d4:
                    ppppppppppppfVar32[2] = pppppppppppfVar8;
                  }
                }
              }
            }
          }
        }
        ppppppppppppfVar5 = (float ************)((int)ppppppppppppfVar5 + -1);
        local_1de4 = (float ************)((int)local_1de4 + 1);
      } while ((int)ppppppppppppfVar40 <= (int)ppppppppppppfVar5);
      fVar41 = ALBW_AS_F32((uVar50 >> 0x20));
      if ((0 < (int)local_1de4) &&
         (ppppppppppppfVar9 = (float ************)((int)ppppppppppppfVar9 + -1),
         (int)ppppppppppppfVar5 <= (int)ppppppppppppfVar9)) {
        do {
          if (ppppppppppppfVar9 < *pppppppppppppfVar4) {
            ppppppppppppfVar40 = pppppppppppppfVar30[0x2b] + (int)ppppppppppppfVar9 * 0x27;
          }
          else {
            ppppppppppppfVar40 = pppppppppppppfVar30[0x2b];
          }
          *(undefined1 *)((int)ppppppppppppfVar40 + 0x91) = 1;
          *(undefined1 *)((int)ppppppppppppfVar40 + 0x92) = 1;
          if (*(char *)((int)ppppppppppppfVar40 + 0x93) == '\0') {
            local_1e74 = ppppppppppppfVar40[0x15];
            local_1e70 = (float ************)ppppppppppppfVar40[0x16];
            local_1e6c = ppppppppppppfVar40[0x17];
            func_00115C70((float *)&local_1ed0,(float *)&local_1e74,
                          (float *)(ppppppppppppfVar40 + 0xf));
            func_00115D70((float *)&local_1e90,(float *)(ppppppppppppfVar40 + 6),
                          ALBW_AS_F32(ppppppppppppfVar40[6]) * ALBW_AS_F32(local_1ed0) +
                          ALBW_AS_F32(ppppppppppppfVar40[7]) * ALBW_AS_F32(local_1ecc) +
                          ALBW_AS_F32(ppppppppppppfVar40[8]) * ALBW_AS_F32(local_1ec8));
            local_1ee4 = (float ***********)local_1e90;
            local_1ee0 = local_1e8c;
            local_1edc = (float ***********)local_1e88;
            func_00115C70((float *)&local_1e68,(float *)&local_1e74,(float *)&local_1ee4);
            ppppppppppppfVar40[0x15] = local_1e68;
            ppppppppppppfVar40[0x16] = (float ***********)local_1e64;
            ppppppppppppfVar40[0x17] = local_1e60;
            local_1e74 = ppppppppppppfVar40[0x18];
            local_1e70 = (float ************)ppppppppppppfVar40[0x19];
            local_1e6c = ppppppppppppfVar40[0x1a];
            func_00115C70((float *)&local_1e84,(float *)&local_1e74,
                          (float *)(ppppppppppppfVar40 + 0x12));
            func_00115D70((float *)&local_1e5c,(float *)(ppppppppppppfVar40 + 6),
                          ALBW_AS_F32(ppppppppppppfVar40[6]) * ALBW_AS_F32(local_1e84) +
                          ALBW_AS_F32(ppppppppppppfVar40[7]) * ALBW_AS_F32(local_1e80) +
                          ALBW_AS_F32(ppppppppppppfVar40[8]) * ALBW_AS_F32(local_1e7c));
            local_1ee4 = (float ***********)local_1e5c;
            local_1ee0 = local_1e58;
            local_1edc = local_1e54;
            func_00115C70((float *)&local_1e50,(float *)&local_1e74,(float *)&local_1ee4);
            ppppppppppppfVar40[0x18] = local_1e50;
            ppppppppppppfVar40[0x19] = local_1e4c;
            ppppppppppppfVar40[0x1a] = (float ***********)local_1e48;
          }
          fVar41 = ALBW_AS_F32((uVar50 >> 0x20));
          ppppppppppppfVar9 = (float ************)((int)ppppppppppppfVar9 + -1);
        } while ((int)ppppppppppppfVar5 <= (int)ppppppppppppfVar9);
      }
    }
  }
  return fVar41;
LAB_0063ce6c:
  local_1ed8 = (float ************)0x1;
LAB_0063cf20:
  uVar15 = 0;
  if (0 < (int)*DAT_0063cb20) {
    do {
      puVar3 = DAT_0063cb20;
      uVar22 = DAT_0063cb20[2];
      if (uVar15 < *DAT_0063cb20) {
        uVar22 = uVar22 + uVar15 * 0x9c;
      }
      *(undefined1 *)(uVar22 + 0x93) = 1;
      puVar14 = (undefined4 *)puVar3[2];
      if (uVar15 < *puVar3) {
        puVar14 = puVar14 + uVar15 * 0x27;
      }
      ppppppppppppfVar5 = *pppppppppppppfVar4;
      if ((int)ppppppppppppfVar5 < (int)pppppppppppppfVar30[0x2a]) {
        ppppppppppppfVar9 = pppppppppppppfVar30[0x2b];
        *pppppppppppppfVar4 = (float ************)((int)ppppppppppppfVar5 + 1);
        ppppppppppppfVar9 = ppppppppppppfVar9 + (int)ppppppppppppfVar5 * 0x27;
        *ppppppppppppfVar9 = (float ***********)*puVar14;
        local_1e80 = ppppppppppppfVar9 + 9;
        local_1ecc = ppppppppppppfVar9 + 0xc;
        ppppppppppppfVar9[1] = (float ***********)puVar14[1];
        local_1e74 = (float ***********)(puVar14 + 0xf);
        ppppppppppppfVar9[2] = (float ***********)puVar14[2];
        ppppppppppppfVar9[3] = (float ***********)puVar14[3];
        ppppppppppppfVar9[4] = (float ***********)puVar14[4];
        ppppppppppppfVar9[5] = (float ***********)puVar14[5];
        ppppppppppppfVar9[6] = (float ***********)puVar14[6];
        ppppppppppppfVar9[7] = (float ***********)puVar14[7];
        ppppppppppppfVar9[8] = (float ***********)puVar14[8];
        ppppppppppppfVar9[9] = (float ***********)puVar14[9];
        ppppppppppppfVar9[10] = (float ***********)puVar14[10];
        ppppppppppppfVar9[0xb] = (float ***********)puVar14[0xb];
        *local_1ecc = (float ***********)puVar14[0xc];
        ppppppppppppfVar9[0xd] = (float ***********)puVar14[0xd];
        ppppppppppppfVar9[0xe] = (float ***********)puVar14[0xe];
        ppppppppppppfVar9[0xf] = (float ***********)puVar14[0xf];
        ppppppppppppfVar9[0x10] = (float ***********)puVar14[0x10];
        ppppppppppppfVar9[0x11] = (float ***********)puVar14[0x11];
        ppppppppppppfVar9[0x12] = (float ***********)puVar14[0x12];
        ppppppppppppfVar9[0x13] = (float ***********)puVar14[0x13];
        ppppppppppppfVar9[0x14] = (float ***********)puVar14[0x14];
        ppppppppppppfVar9[0x15] = (float ***********)puVar14[0x15];
        ppppppppppppfVar9[0x16] = (float ***********)puVar14[0x16];
        ppppppppppppfVar9[0x17] = (float ***********)puVar14[0x17];
        ppppppppppppfVar9[0x18] = (float ***********)puVar14[0x18];
        ppppppppppppfVar9[0x19] = (float ***********)puVar14[0x19];
        ppppppppppppfVar9[0x1a] = (float ***********)puVar14[0x1a];
        ppppppppppppfVar9[0x1b] = (float ***********)puVar14[0x1b];
        ppppppppppppfVar9[0x1c] = (float ***********)puVar14[0x1c];
        ppppppppppppfVar9[0x1d] = (float ***********)puVar14[0x1d];
        ppppppppppppfVar9[0x1e] = (float ***********)puVar14[0x1e];
        ppppppppppppfVar9[0x1f] = (float ***********)puVar14[0x1f];
        ppppppppppppfVar9[0x20] = (float ***********)puVar14[0x20];
        ppppppppppppfVar9[0x21] = (float ***********)puVar14[0x21];
        ppppppppppppfVar9[0x22] = (float ***********)puVar14[0x22];
        ppppppppppppfVar9[0x23] = (float ***********)puVar14[0x23];
        *(undefined1 *)(ppppppppppppfVar9 + 0x24) = *(undefined1 *)(puVar14 + 0x24);
        *(undefined1 *)((int)ppppppppppppfVar9 + 0x91) = *(undefined1 *)((int)puVar14 + 0x91);
        *(undefined1 *)((int)ppppppppppppfVar9 + 0x92) = *(undefined1 *)((int)puVar14 + 0x92);
        *(undefined1 *)((int)ppppppppppppfVar9 + 0x93) = *(undefined1 *)((int)puVar14 + 0x93);
        *(undefined1 *)(ppppppppppppfVar9 + 0x25) = *(undefined1 *)(puVar14 + 0x25);
        *(undefined1 *)((int)ppppppppppppfVar9 + 0x95) = *(undefined1 *)((int)puVar14 + 0x95);
        *(undefined1 *)((int)ppppppppppppfVar9 + 0x96) = *(undefined1 *)((int)puVar14 + 0x96);
        *(undefined1 *)((int)ppppppppppppfVar9 + 0x97) = *(undefined1 *)((int)puVar14 + 0x97);
        *(undefined1 *)(ppppppppppppfVar9 + 0x26) = *(undefined1 *)(puVar14 + 0x26);
      }
      uVar15 = uVar15 + 1;
    } while ((int)uVar15 < (int)*DAT_0063cb20);
  }
  if (local_1ed8 != (float ************)0x0) {
    local_1e50 = (float ***********)0x1;
  }
  goto LAB_0063d1a4;
LAB_0063d8cc:
  local_1ed4 = (float ************)0x1;
  goto LAB_0063d980;
joined_r0x0063df48:
  for (; (int)ppppppppppppfVar9 < (int)ppppppppppppfVar25;
      ppppppppppppfVar9 = (float ************)((int)ppppppppppppfVar9 + 1)) {
    if (ppppppppppppfVar9 < *ppppppppppppfVar5) {
      pppppppppppfVar8 = ppppppppppppfVar5[2] + (int)ppppppppppppfVar9 * 0x27;
    }
    else {
      pppppppppppfVar8 = ppppppppppppfVar5[2];
    }
    pppppppppppfVar8[0x1e] = (float **********)ppppppppppfVar43[0x1c];
    pppppppppppfVar8[0x1f] = (float **********)ppppppppppfVar43[0x1c];
    pppppppppppfVar8[0x15] = (float **********)ppppppppppfVar43[0xf];
    pppppppppppfVar8[0x16] = (float **********)ppppppppppfVar43[0x10];
    pppppppppppfVar8[0x17] = (float **********)ppppppppppfVar43[0x11];
    pppppppppppfVar8[0x18] = (float **********)ppppppppppfVar43[0xf];
    pppppppppppfVar8[0x19] = (float **********)ppppppppppfVar43[0x10];
    pppppppppppfVar8[0x1a] = (float **********)ppppppppppfVar43[0x11];
    *(undefined1 *)((int)pppppppppppfVar8 + 0x97) = 1;
    if (ppppppppppppfVar9 < *ppppppppppppfVar5) {
      pppppppppppfVar8 = ppppppppppppfVar5[2] + (int)ppppppppppppfVar9 * 0x27;
    }
    else {
      pppppppppppfVar8 = ppppppppppppfVar5[2];
    }
    iVar6 = *DAT_0063ddd4;
    if (iVar6 < DAT_0063ddd4[1]) {
      piVar1 = DAT_0063ddd4 + 2;
      *DAT_0063ddd4 = iVar6 + 1;
      puVar14 = (undefined4 *)(*piVar1 + iVar6 * 0x9c);
      local_1e90 = (float ************)(puVar14 + 9);
      *puVar14 = (undefined4)(uintptr_t)(*pppppppppppfVar8);
      local_1ed4 = (float ************)(puVar14 + 0xc);
      puVar14[1] = (undefined4)(uintptr_t)(pppppppppppfVar8[1]);
      local_1e88 = (float ************)(pppppppppppfVar8 + 0xf);
      puVar14[2] = (undefined4)(uintptr_t)(pppppppppppfVar8[2]);
      local_1e7c = (float ************)(puVar14 + 0xf);
      puVar14[3] = (undefined4)(uintptr_t)(pppppppppppfVar8[3]);
      puVar14[4] = (undefined4)(uintptr_t)(pppppppppppfVar8[4]);
      local_1ecc = (float ************)(pppppppppppfVar8 + 0x12);
      puVar14[5] = (undefined4)(uintptr_t)(pppppppppppfVar8[5]);
      puVar14[6] = (undefined4)(uintptr_t)(pppppppppppfVar8[6]);
      puVar14[7] = (undefined4)(uintptr_t)(pppppppppppfVar8[7]);
      puVar14[8] = (undefined4)(uintptr_t)(pppppppppppfVar8[8]);
      *local_1e90 = (float ***********)pppppppppppfVar8[9];
      puVar14[10] = (undefined4)(uintptr_t)(pppppppppppfVar8[10]);
      puVar14[0xb] = (undefined4)(uintptr_t)(pppppppppppfVar8[0xb]);
      *local_1ed4 = (float ***********)pppppppppppfVar8[0xc];
      puVar14[0xd] = (undefined4)(uintptr_t)(pppppppppppfVar8[0xd]);
      puVar14[0xe] = (undefined4)(uintptr_t)(pppppppppppfVar8[0xe]);
      *local_1e7c = *local_1e88;
      puVar14[0x10] = (undefined4)(uintptr_t)(pppppppppppfVar8[0x10]);
      puVar14[0x11] = (undefined4)(uintptr_t)(pppppppppppfVar8[0x11]);
      puVar14[0x12] = (undefined4)(uintptr_t)(*local_1ecc);
      puVar14[0x13] = (undefined4)(uintptr_t)(pppppppppppfVar8[0x13]);
      puVar14[0x14] = (undefined4)(uintptr_t)(pppppppppppfVar8[0x14]);
      puVar14[0x15] = (undefined4)(uintptr_t)(pppppppppppfVar8[0x15]);
      puVar14[0x16] = (undefined4)(uintptr_t)(pppppppppppfVar8[0x16]);
      puVar14[0x17] = (undefined4)(uintptr_t)(pppppppppppfVar8[0x17]);
      puVar14[0x18] = (undefined4)(uintptr_t)(pppppppppppfVar8[0x18]);
      puVar14[0x19] = (undefined4)(uintptr_t)(pppppppppppfVar8[0x19]);
      puVar14[0x1a] = (undefined4)(uintptr_t)(pppppppppppfVar8[0x1a]);
      puVar14[0x1b] = (undefined4)(uintptr_t)(pppppppppppfVar8[0x1b]);
      puVar14[0x1c] = (undefined4)(uintptr_t)(pppppppppppfVar8[0x1c]);
      puVar14[0x1d] = (undefined4)(uintptr_t)(pppppppppppfVar8[0x1d]);
      puVar14[0x1e] = (undefined4)(uintptr_t)(pppppppppppfVar8[0x1e]);
      puVar14[0x1f] = (undefined4)(uintptr_t)(pppppppppppfVar8[0x1f]);
      puVar14[0x20] = (undefined4)(uintptr_t)(pppppppppppfVar8[0x20]);
      puVar14[0x21] = (undefined4)(uintptr_t)(pppppppppppfVar8[0x21]);
      puVar14[0x22] = (undefined4)(uintptr_t)(pppppppppppfVar8[0x22]);
      puVar14[0x23] = (undefined4)(uintptr_t)(pppppppppppfVar8[0x23]);
      *(undefined1 *)(puVar14 + 0x24) = *(undefined1 *)(pppppppppppfVar8 + 0x24);
      *(undefined1 *)((int)puVar14 + 0x91) = *(undefined1 *)((int)pppppppppppfVar8 + 0x91);
      *(undefined1 *)((int)puVar14 + 0x92) = *(undefined1 *)((int)pppppppppppfVar8 + 0x92);
      *(undefined1 *)((int)puVar14 + 0x93) = *(undefined1 *)((int)pppppppppppfVar8 + 0x93);
      *(undefined1 *)(puVar14 + 0x25) = *(undefined1 *)(pppppppppppfVar8 + 0x25);
      *(undefined1 *)((int)puVar14 + 0x95) = *(undefined1 *)((int)pppppppppppfVar8 + 0x95);
      *(undefined1 *)((int)puVar14 + 0x96) = *(undefined1 *)((int)pppppppppppfVar8 + 0x96);
      *(undefined1 *)((int)puVar14 + 0x97) = *(undefined1 *)((int)pppppppppppfVar8 + 0x97);
      *(undefined1 *)(puVar14 + 0x26) = *(undefined1 *)(pppppppppppfVar8 + 0x26);
    }
  }
  iVar6 = *DAT_0063ddd4;
  if (iVar6 < 1) {
    if ((int)local_1ec4 + 1 < (int)*local_1ec8) {
      ppppppppppfVar44 = ppppppppppfVar43;
      if ((float **********)((int)local_1ec4 + 1) < *local_1ec8) {
        ppppppppppfVar46 = (float **********)(local_1ec8[2] + ((int)local_1ec4 + 1) * 0x27);
      }
      else {
        ppppppppppfVar46 = (float **********)local_1ec8[2];
      }
      goto LAB_0063e280;
    }
  }
  else {
    ppppppppppfVar44 = (float **********)(DAT_0063ddd4[2] + iVar6 * 0x9c + -0x9c);
    ppppppppppfVar46 = ppppppppppfVar43;
LAB_0063e280:
    pppppppppfVar19 = ppppppppppfVar44[7];
    iVar2 = (int)pppppppppfVar19 - (int)DAT_0063ddc8;
    if ((int)pppppppppfVar19 <= (int)DAT_0063ddc8) {
      pppppppppfVar19 = ppppppppppfVar46[7];
      iVar2 = (int)pppppppppfVar19 - (int)DAT_0063ddc8;
    }
    if (pppppppppfVar19 != (float *********)DAT_0063ddc8 &&
        iVar2 < 0 == SBORROW4((int)pppppppppfVar19,(int)DAT_0063ddc8)) {
      pppppppfVar45 =
           (float *******)
           CF_FBITS((ALBW_AS_F32(*ppppppppppfVar44) * ALBW_AS_F32(ppppppppppfVar46[6]) +
            ALBW_AS_F32(ppppppppppfVar44[1]) * ALBW_AS_F32(ppppppppppfVar46[7]) +
           ALBW_AS_F32(ppppppppppfVar44[2]) * ALBW_AS_F32(ppppppppppfVar46[8])));
      if (DAT_0063ddb4 < pppppppfVar45) {
LAB_0063e2cc:
        local_1edc = (float ***********)0x0;
      }
      else if (DAT_0063ddcc < (int)pppppppfVar45) {
        local_1edc = (float ***********)0x2;
        if ((int)local_1ec4 + 1 < (int)*local_1ec8) {
          if ((float **********)((int)local_1ec4 + 1) < *local_1ec8) {
            ppppppppppfVar44 = (float **********)(local_1ec8[2] + ((int)local_1ec4 + 1) * 0x27);
          }
          else {
            ppppppppppfVar44 = (float **********)local_1ec8[2];
          }
          if (DAT_0063ddb4 <
              (float *******)
              CF_FBITS((ALBW_AS_F32(*ppppppppppfVar43) * ALBW_AS_F32(ppppppppppfVar44[6]) +
               ALBW_AS_F32(ppppppppppfVar43[1]) * ALBW_AS_F32(ppppppppppfVar44[7]) +
              ALBW_AS_F32(ppppppppppfVar43[2]) * ALBW_AS_F32(ppppppppppfVar44[8])))) goto LAB_0063e2cc;
        }
      }
    }
  }
  if (iVar6 < DAT_0063ddd4[1]) {
    piVar1 = DAT_0063ddd4 + 2;
    *DAT_0063ddd4 = iVar6 + 1;
    puVar14 = (undefined4 *)(*piVar1 + iVar6 * 0x9c);
  }
  else {
    puVar14 = (undefined4 *)0x0;
  }
  if (ppppppppppppfVar25 < *ppppppppppppfVar5) {
    pppppppppppfVar8 = ppppppppppppfVar5[2] + (int)ppppppppppppfVar25 * 0x27;
  }
  else {
    pppppppppppfVar8 = ppppppppppppfVar5[2];
  }
  if (local_1edc < (float ***********)0x2) {
    *puVar14 = (undefined4)(uintptr_t)(*ppppppppppfVar43);
    puVar14[1] = (undefined4)(uintptr_t)(ppppppppppfVar43[1]);
    puVar14[2] = (undefined4)(uintptr_t)(ppppppppppfVar43[2]);
    puVar14[3] = (undefined4)(uintptr_t)(ppppppppppfVar43[3]);
    puVar14[4] = (undefined4)(uintptr_t)(ppppppppppfVar43[4]);
    puVar14[5] = (undefined4)(uintptr_t)(ppppppppppfVar43[5]);
    puVar14[6] = (undefined4)(uintptr_t)(ppppppppppfVar43[6]);
    puVar14[7] = (undefined4)(uintptr_t)(ppppppppppfVar43[7]);
    puVar14[8] = (undefined4)(uintptr_t)(ppppppppppfVar43[8]);
    puVar14[9] = (undefined4)(uintptr_t)(ppppppppppfVar43[9]);
    puVar14[10] = (undefined4)(uintptr_t)(ppppppppppfVar43[10]);
    puVar14[0xb] = (undefined4)(uintptr_t)(ppppppppppfVar43[0xb]);
    puVar14[0xc] = (undefined4)(uintptr_t)(ppppppppppfVar43[0xc]);
    puVar14[0xd] = (undefined4)(uintptr_t)(ppppppppppfVar43[0xd]);
    puVar14[0xe] = (undefined4)(uintptr_t)(ppppppppppfVar43[0xe]);
    puVar14[0xf] = (undefined4)(uintptr_t)(ppppppppppfVar43[0xf]);
    puVar14[0x10] = (undefined4)(uintptr_t)(ppppppppppfVar43[0x10]);
    puVar14[0x11] = (undefined4)(uintptr_t)(ppppppppppfVar43[0x11]);
    puVar14[0x12] = (undefined4)(uintptr_t)(ppppppppppfVar43[0x12]);
    puVar14[0x13] = (undefined4)(uintptr_t)(ppppppppppfVar43[0x13]);
    puVar14[0x14] = (undefined4)(uintptr_t)(ppppppppppfVar43[0x14]);
    puVar14[0x15] = (undefined4)(uintptr_t)(ppppppppppfVar43[0x15]);
    puVar14[0x16] = (undefined4)(uintptr_t)(ppppppppppfVar43[0x16]);
    puVar14[0x17] = (undefined4)(uintptr_t)(ppppppppppfVar43[0x17]);
    puVar14[0x18] = (undefined4)(uintptr_t)(ppppppppppfVar43[0x18]);
    puVar14[0x19] = (undefined4)(uintptr_t)(ppppppppppfVar43[0x19]);
    puVar14[0x1a] = (undefined4)(uintptr_t)(ppppppppppfVar43[0x1a]);
    puVar14[0x1b] = (undefined4)(uintptr_t)(ppppppppppfVar43[0x1b]);
    puVar14[0x1c] = (undefined4)(uintptr_t)(ppppppppppfVar43[0x1c]);
    puVar14[0x1d] = (undefined4)(uintptr_t)(ppppppppppfVar43[0x1d]);
    puVar14[0x1e] = (undefined4)(uintptr_t)(ppppppppppfVar43[0x1e]);
    puVar14[0x1f] = (undefined4)(uintptr_t)(ppppppppppfVar43[0x1f]);
    puVar14[0x20] = (undefined4)(uintptr_t)(ppppppppppfVar43[0x20]);
    puVar14[0x21] = (undefined4)(uintptr_t)(ppppppppppfVar43[0x21]);
    puVar14[0x22] = (undefined4)(uintptr_t)(ppppppppppfVar43[0x22]);
    puVar14[0x23] = (undefined4)(uintptr_t)(ppppppppppfVar43[0x23]);
    *(undefined1 *)(puVar14 + 0x24) = *(undefined1 *)(ppppppppppfVar43 + 0x24);
    *(undefined1 *)((int)puVar14 + 0x91) = *(undefined1 *)((int)ppppppppppfVar43 + 0x91);
    *(undefined1 *)((int)puVar14 + 0x92) = *(undefined1 *)((int)ppppppppppfVar43 + 0x92);
    *(undefined1 *)((int)puVar14 + 0x93) = *(undefined1 *)((int)ppppppppppfVar43 + 0x93);
    *(undefined1 *)(puVar14 + 0x25) = *(undefined1 *)(ppppppppppfVar43 + 0x25);
    *(undefined1 *)((int)puVar14 + 0x95) = *(undefined1 *)((int)ppppppppppfVar43 + 0x95);
    *(undefined1 *)((int)puVar14 + 0x96) = *(undefined1 *)((int)ppppppppppfVar43 + 0x96);
    *(undefined1 *)((int)puVar14 + 0x97) = *(undefined1 *)((int)ppppppppppfVar43 + 0x97);
    *(undefined1 *)(puVar14 + 0x26) = *(undefined1 *)(ppppppppppfVar43 + 0x26);
    puVar14[0x1e] = (undefined4)(uintptr_t)(pppppppppppfVar8[0x1c]);
    puVar14[0x1f] = (undefined4)(uintptr_t)(pppppppppppfVar8[0x1d]);
    puVar14[0x15] = (undefined4)(uintptr_t)(pppppppppppfVar8[0xf]);
    puVar14[0x16] = (undefined4)(uintptr_t)(pppppppppppfVar8[0x10]);
    puVar14[0x17] = (undefined4)(uintptr_t)(pppppppppppfVar8[0x11]);
    puVar14[0x18] = (undefined4)(uintptr_t)(pppppppppppfVar8[0x12]);
    puVar14[0x19] = (undefined4)(uintptr_t)(pppppppppppfVar8[0x13]);
    ppppppppppfVar43 = pppppppppppfVar8[0x14];
  }
  else {
    if (local_1edc != (float ***********)0x2 && local_1edc != (float ***********)0x3)
    goto LAB_0063e720;
    *puVar14 = (undefined4)(uintptr_t)(*pppppppppppfVar8);
    puVar14[1] = (undefined4)(uintptr_t)(pppppppppppfVar8[1]);
    puVar14[2] = (undefined4)(uintptr_t)(pppppppppppfVar8[2]);
    puVar14[3] = (undefined4)(uintptr_t)(pppppppppppfVar8[3]);
    puVar14[4] = (undefined4)(uintptr_t)(pppppppppppfVar8[4]);
    puVar14[5] = (undefined4)(uintptr_t)(pppppppppppfVar8[5]);
    puVar14[6] = (undefined4)(uintptr_t)(pppppppppppfVar8[6]);
    puVar14[7] = (undefined4)(uintptr_t)(pppppppppppfVar8[7]);
    puVar14[8] = (undefined4)(uintptr_t)(pppppppppppfVar8[8]);
    puVar14[9] = (undefined4)(uintptr_t)(pppppppppppfVar8[9]);
    puVar14[10] = (undefined4)(uintptr_t)(pppppppppppfVar8[10]);
    puVar14[0xb] = (undefined4)(uintptr_t)(pppppppppppfVar8[0xb]);
    puVar14[0xc] = (undefined4)(uintptr_t)(pppppppppppfVar8[0xc]);
    puVar14[0xd] = (undefined4)(uintptr_t)(pppppppppppfVar8[0xd]);
    puVar14[0xe] = (undefined4)(uintptr_t)(pppppppppppfVar8[0xe]);
    puVar14[0xf] = (undefined4)(uintptr_t)(pppppppppppfVar8[0xf]);
    puVar14[0x10] = (undefined4)(uintptr_t)(pppppppppppfVar8[0x10]);
    puVar14[0x11] = (undefined4)(uintptr_t)(pppppppppppfVar8[0x11]);
    puVar14[0x12] = (undefined4)(uintptr_t)(pppppppppppfVar8[0x12]);
    puVar14[0x13] = (undefined4)(uintptr_t)(pppppppppppfVar8[0x13]);
    puVar14[0x14] = (undefined4)(uintptr_t)(pppppppppppfVar8[0x14]);
    puVar14[0x15] = (undefined4)(uintptr_t)(pppppppppppfVar8[0x15]);
    puVar14[0x16] = (undefined4)(uintptr_t)(pppppppppppfVar8[0x16]);
    puVar14[0x17] = (undefined4)(uintptr_t)(pppppppppppfVar8[0x17]);
    puVar14[0x18] = (undefined4)(uintptr_t)(pppppppppppfVar8[0x18]);
    puVar14[0x19] = (undefined4)(uintptr_t)(pppppppppppfVar8[0x19]);
    puVar14[0x1a] = (undefined4)(uintptr_t)(pppppppppppfVar8[0x1a]);
    puVar14[0x1b] = (undefined4)(uintptr_t)(pppppppppppfVar8[0x1b]);
    puVar14[0x1c] = (undefined4)(uintptr_t)(pppppppppppfVar8[0x1c]);
    puVar14[0x1d] = (undefined4)(uintptr_t)(pppppppppppfVar8[0x1d]);
    puVar14[0x1e] = (undefined4)(uintptr_t)(pppppppppppfVar8[0x1e]);
    puVar14[0x1f] = (undefined4)(uintptr_t)(pppppppppppfVar8[0x1f]);
    puVar14[0x20] = (undefined4)(uintptr_t)(pppppppppppfVar8[0x20]);
    puVar14[0x21] = (undefined4)(uintptr_t)(pppppppppppfVar8[0x21]);
    puVar14[0x22] = (undefined4)(uintptr_t)(pppppppppppfVar8[0x22]);
    puVar14[0x23] = (undefined4)(uintptr_t)(pppppppppppfVar8[0x23]);
    *(undefined1 *)(puVar14 + 0x24) = *(undefined1 *)(pppppppppppfVar8 + 0x24);
    *(undefined1 *)((int)puVar14 + 0x91) = *(undefined1 *)((int)pppppppppppfVar8 + 0x91);
    *(undefined1 *)((int)puVar14 + 0x92) = *(undefined1 *)((int)pppppppppppfVar8 + 0x92);
    *(undefined1 *)((int)puVar14 + 0x93) = *(undefined1 *)((int)pppppppppppfVar8 + 0x93);
    *(undefined1 *)(puVar14 + 0x25) = *(undefined1 *)(pppppppppppfVar8 + 0x25);
    *(undefined1 *)((int)puVar14 + 0x95) = *(undefined1 *)((int)pppppppppppfVar8 + 0x95);
    *(undefined1 *)((int)puVar14 + 0x96) = *(undefined1 *)((int)pppppppppppfVar8 + 0x96);
    *(undefined1 *)((int)puVar14 + 0x97) = *(undefined1 *)((int)pppppppppppfVar8 + 0x97);
    *(undefined1 *)(puVar14 + 0x26) = *(undefined1 *)(pppppppppppfVar8 + 0x26);
    puVar14[0x1e] = (undefined4)(uintptr_t)(ppppppppppfVar43[0x1c]);
    puVar14[0x1f] = (undefined4)(uintptr_t)(ppppppppppfVar43[0x1d]);
    puVar14[0x15] = (undefined4)(uintptr_t)(ppppppppppfVar43[0xf]);
    puVar14[0x16] = (undefined4)(uintptr_t)(ppppppppppfVar43[0x10]);
    puVar14[0x17] = (undefined4)(uintptr_t)(ppppppppppfVar43[0x11]);
    puVar14[0x18] = (undefined4)(uintptr_t)(ppppppppppfVar43[0x12]);
    puVar14[0x19] = (undefined4)(uintptr_t)(ppppppppppfVar43[0x13]);
    ppppppppppfVar43 = (float **********)ppppppppppfVar43[0x14];
  }
  puVar14[0x1a] = (undefined4)(uintptr_t)(ppppppppppfVar43);
LAB_0063e720:
  ppppppppppppfVar9 = (float ************)((int)ppppppppppppfVar25 + 1);
LAB_0063e728:
  local_1ec4 = (float ************)((int)local_1ec4 + 1);
  if ((int)*local_1ec8 <= (int)local_1ec4) goto LAB_0063e744;
  goto LAB_0063dcbc;
LAB_0063fc08:
  do {
    if ((int)pppppppppppppfVar35 <= (int)ppppppppppppfVar9) break;
    if (ppppppppppppfVar9 < *pppppppppppppfVar31) {
      ppppppppppppfVar40 = pppppppppppppfVar30[0x2b] + (int)ppppppppppppfVar9 * 0x27;
    }
    else {
      ppppppppppppfVar40 = pppppppppppppfVar30[0x2b];
    }
    *(undefined1 *)((int)ppppppppppppfVar40 + 0x91) = 1;
    if (*(char *)((int)ppppppppppppfVar40 + 0x93) == '\0') {
      func_00115C70((float *)&local_1e90,(float *)&local_1e80,(float *)(ppppppppppppfVar40 + 0xf));
      func_00115D70((float *)&local_1e90,(float *)(ppppppppppppfVar40 + 6),
                    ALBW_AS_F32(ppppppppppppfVar40[6]) * ALBW_AS_F32(local_1e90) +
                    ALBW_AS_F32(ppppppppppppfVar40[7]) * ALBW_AS_F32(local_1e8c) +
                    ALBW_AS_F32(ppppppppppppfVar40[8]) * ALBW_AS_F32(local_1e88));
      local_1ed0 = (float ***********)local_1e90;
      local_1ecc = local_1e8c;
      local_1ec8 = local_1e88;
      func_00115C70((float *)&local_1e90,(float *)&local_1e80,(float *)&local_1ed0);
      ppppppppppppfVar40 = ppppppppppppfVar40 + 0xf;
LAB_0063fbf4:
      *ppppppppppppfVar40 = (float ***********)local_1e90;
      ppppppppppppfVar40[1] = (float ***********)local_1e8c;
      ppppppppppppfVar40[2] = (float ***********)local_1e88;
    }
    else {
      if (ppppppppppppfVar9 == ppppppppppppfVar5 || !bVar38) {
LAB_0063fb28:
        func_00115C70((float *)&local_1e90,(float *)&local_1e80,(float *)(ppppppppppppfVar40 + 0xf))
        ;
        func_00115D70((float *)&local_1e90,(float *)(ppppppppppppfVar40 + 6),
                      ALBW_AS_F32(ppppppppppppfVar40[6]) * ALBW_AS_F32(local_1e90) +
                      ALBW_AS_F32(ppppppppppppfVar40[7]) * ALBW_AS_F32(local_1e8c) +
                      ALBW_AS_F32(ppppppppppppfVar40[8]) * ALBW_AS_F32(local_1e88));
        local_1ed0 = (float ***********)local_1e90;
        local_1ecc = local_1e8c;
        local_1ec8 = local_1e88;
        func_00115C70((float *)&local_1e90,(float *)&local_1e80,(float *)&local_1ed0);
        ppppppppppppfVar40 = ppppppppppppfVar40 + 0x15;
        goto LAB_0063fbf4;
      }
      fVar47 = ALBW_AS_F32(ppppppppppppfVar40[6]) * ALBW_AS_F32(local_1edc) +
               ALBW_AS_F32(ppppppppppppfVar40[7]) * ALBW_AS_F32(local_1ed8) +
               ALBW_AS_F32(ppppppppppppfVar40[8]) * ALBW_AS_F32(local_1ed4);
      fVar41 = fVar47;
      if (fVar47 <= ALBW_AS_F32(uVar51)) {
        fVar41 = -fVar47;
      }
      if ((int)ALBW_AS_U32(fVar41) <= DAT_0064006c) goto LAB_0063fb28;
      func_00115C70((float *)&local_1e38,(float *)&local_1e80,(float *)(ppppppppppppfVar40 + 9));
      local_1e74 = local_1e38;
      local_1e70 = (float ************)local_1e34;
      local_1e6c = (float ***********)local_1e30;
      func_00115D70((float *)&local_1e38,(float *)&local_1edc,
                    ALBW_AS_F32(ppppppppppppfVar40[6]) * ALBW_AS_F32(local_1e38) +
                    ALBW_AS_F32(ppppppppppppfVar40[7]) * ALBW_AS_F32(local_1e34) +
                    ALBW_AS_F32(ppppppppppppfVar40[8]) * ALBW_AS_F32(local_1e30));
      local_1ed0 = local_1e38;
      local_1ecc = (float ************)local_1e34;
      local_1ec8 = local_1e30;
      func_00115D88((float *)&local_1e38,(float *)&local_1ed0,fVar47);
      local_1e74 = local_1e38;
      local_1e70 = (float ************)local_1e34;
      local_1e6c = (float ***********)local_1e30;
      func_00115C70((float *)&local_1e4c,(float *)&local_1e80,(float *)&local_1e74);
      local_1e90 = (float ************)local_1e4c;
      local_1e8c = local_1e48;
      local_1e88 = local_1e44;
      func_00115C70((float *)&local_1e38,(float *)&local_1e90,(float *)(ppppppppppppfVar40 + 0xf));
      local_1ed0 = local_1e38;
      local_1ecc = (float ************)local_1e34;
      local_1ec8 = local_1e30;
      if (ALBW_AS_F32(local_1e38) * ALBW_AS_F32(ppppppppppppfVar40[3]) +
          ALBW_AS_F32(local_1e34) * ALBW_AS_F32(ppppppppppppfVar40[4]) +
          ALBW_AS_F32(local_1e30) * ALBW_AS_F32(ppppppppppppfVar40[5]) <= ALBW_AS_F32(uVar51)) goto LAB_0063fb28;
      ppppppppppppfVar40[0x15] = (float ***********)local_1e90;
      ppppppppppppfVar40[0x16] = (float ***********)local_1e8c;
      ppppppppppppfVar40[0x17] = (float ***********)local_1e88;
    }
    ppppppppppppfVar9 = (float ************)((int)ppppppppppppfVar9 + 1);
LAB_0063fbfc:
  } while ((int)ppppppppppppfVar9 <= (int)local_1ee0);
  goto LAB_0063fc10;
}

