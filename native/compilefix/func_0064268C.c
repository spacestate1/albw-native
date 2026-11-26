/* compilefix: USA 0064268C (EU 00642664), Ghidra-derived (build/ghidra_analyzed4).
 * Failed to compile: operand of type 'float' cannot be cast to a pointer type
 * Fixed (each an exact C form of the ARM operation; the rest is the converted Ghidra text):
 *  - (T *)<float expr> -> (T *)CF_FBITS(expr): 32-bit copy of the float (vmov/vstr), never a conversion [76]
 *  - explicit casts at pointer-type mismatches (identity on the ARM) [26]
 *  - explicit (T)(uintptr_t) casts at int<->pointer mismatches (identity on the 32-bit ARM) [158]
 * Arguments restored (BOOT_LOG 166): the ARM passes r0 = the object, r1 (1 on both calls), r2 = a flag, s0, s1; the
 *    converted text declared (void) and read them as uninitialised registers (crash in the yard with clang 22).
 *    EU 001EEA30..001EEA64 (caller 001EA96C) and 0064399C..006439D8 (the call to itself).
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
extern float * * * * * * *DAT_00642a2c;
extern float DAT_00642a30;
extern float * * * * * * *DAT_00642a34;
extern undefined4 DAT_00642a38;
extern int DAT_00642a3c;
extern uint DAT_00642a40;
extern float * * * * * *DAT_00642a44;
extern undefined *DAT_00642a48;
extern int DAT_00643d48;
extern float DAT_00643d4c;
extern uint *DAT_006442fc;
extern uint *DAT_00644300;
extern float DAT_00644304;
extern float DAT_00644308;
extern undefined *DAT_0064430c;
extern uint *DAT_00644310;
extern uint *DAT_00644314;
extern undefined *DAT_00644318;
extern int DAT_0064431c;
extern float DAT_00645584;
extern float * * * * * * *DAT_00645588;
extern uint *DAT_0064558c;
extern float *DAT_00645590;
extern uint *DAT_00645594;
extern uint *DAT_00645598;
extern float * * * * *DAT_0064559c;
extern int DAT_006455a0;
extern uint *DAT_006455a4;
extern int *DAT_006455a8;
extern undefined *DAT_006455ac;
extern int DAT_006455b0;
extern int DAT_0064781c;
extern float * * * * * * *DAT_00647820;
extern int DAT_00647824;
extern int DAT_00648984;
extern float DAT_00648988;
extern int DAT_00649ac8;
extern int DAT_00649acc;

// USA 0064268C <- EU 00642664 (Ghidra, non-matching)
// GLOBAL DAT_00642a2c float * * * * * * *
// GLOBAL DAT_00642a30 float
// GLOBAL DAT_00642a34 float * * * * * * *
// GLOBAL DAT_00642a38 undefined4
// GLOBAL DAT_00642a3c int
// GLOBAL DAT_00642a40 uint
// GLOBAL DAT_00642a44 float * * * * * *
// GLOBAL DAT_00642a48 undefined *
// GLOBAL DAT_00643d48 int
// GLOBAL DAT_00643d4c float
// GLOBAL DAT_006442fc uint *
// GLOBAL DAT_00644300 uint *
// GLOBAL DAT_00644304 float
// GLOBAL DAT_00644308 float
// GLOBAL DAT_0064430c undefined *
// GLOBAL DAT_00644310 uint *
// GLOBAL DAT_00644314 uint *
// GLOBAL DAT_00644318 undefined *
// GLOBAL DAT_0064431c int
// GLOBAL DAT_00645584 float
// GLOBAL DAT_00645588 float * * * * * * *
// GLOBAL DAT_0064558c uint *
// GLOBAL DAT_00645590 float *
// GLOBAL DAT_00645594 uint *
// GLOBAL DAT_00645598 uint *
// GLOBAL DAT_0064559c float * * * * *
// GLOBAL DAT_006455a0 int
// GLOBAL DAT_006455a4 uint *
// GLOBAL DAT_006455a8 int *
// GLOBAL DAT_006455ac undefined *
// GLOBAL DAT_006455b0 int
// GLOBAL DAT_0064781c int
// GLOBAL DAT_00647820 float * * * * * * *
// GLOBAL DAT_00647824 int
// GLOBAL DAT_00648984 int
// GLOBAL DAT_00648988 float
// GLOBAL DAT_00649ac8 int
// GLOBAL DAT_00649acc int

/* WARNING: Removing unreachable block (ram,0x006435bc) */
/* WARNING: Removing unreachable block (ram,0x00643768) */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Restarted to delay deadcode elimination for space: stack */
/* WARNING: Unknown calling convention */

undefined4 func_0064268C(float ***********arg_r0,int arg_r1,int arg_r2,float fparam_0,float fparam_1)

{
  int *piVar1;
  int iVar2;
  uint *puVar3;
  float ***********in_r0;
  float ************ppppppppppppfVar4;
  float ************ppppppppppppfVar5;
  int iVar6;
  float *pfVar7;
  float ***********pppppppppppfVar8;
  int in_r1;
  float **********ppppppppppfVar9;
  float *********pppppppppfVar10;
  undefined4 *puVar11;
  uint uVar12;
  uint uVar13;
  undefined4 *puVar14;
  undefined4 *puVar15;
  float ***********extraout_r1;
  float ***********extraout_r1_00;
  float ***********extraout_r1_01;
  float ***********extraout_r1_02;
  float ***********extraout_r1_03;
  float ***********extraout_r1_04;
  int in_r2;
  uint *puVar16;
  float **********ppppppppppfVar17;
  uint *puVar18;
  uint uVar19;
  int *piVar20;
  float ***********pppppppppppfVar21;
  float **********ppppppppppfVar22;
  float *pfVar23;
  float ***********pppppppppppfVar24;
  float **********ppppppppppfVar25;
  float *********pppppppppfVar26;
  float *pfVar27;
  float ***********pppppppppppfVar28;
  float ***********pppppppppppfVar29;
  float **********ppppppppppfVar30;
  float **********ppppppppppfVar31;
  float ***********pppppppppppfVar32;
  float fVar33;
  float *****pppppfVar34;
  float ***********pppppppppppfVar35;
  float ***********pppppppppppfVar36;
  float ***********pppppppppppfVar37;
  bool bVar38;
  bool bVar39;
  bool bVar40;
  float ***********in_s0;
  float **********ppppppppppfVar41;
  float fVar42;
  float fVar43;
  float *******pppppppfVar44;
  float fVar45;
  float *********in_s1;
  float *********pppppppppfVar46;
  float *********pppppppppfVar47;
  float fVar48;
  undefined8 uVar49;
  ulonglong uVar50;
  ulonglong uVar51;
  float fVar52;
  float fVar53;
  float ***********pppppppppppfVar54;
  undefined8 uVar55;
  undefined4 uVar56;
  longlong lVar57;
  undefined4 uVar58;
  ulonglong uVar59;
  _Alignas(8) unsigned char albw_frame[0x1ef0];
  #define local_1ef0 (*(float *********** *)(albw_frame + 0x0))
  #define local_1eec (*(float *********** *)(albw_frame + 0x4))
  #define local_1ee8 (*(float *********** *)(albw_frame + 0x8))
  #define local_1ee4 (*(float *********** *)(albw_frame + 0xc))
  #define local_1ee0 (*(float *********** *)(albw_frame + 0x10))
  #define local_1edc (*(float *)(albw_frame + 0x14))
  #define local_1ed8 (*(float *********** *)(albw_frame + 0x18))
  #define local_1ed4 (*(float ************ *)(albw_frame + 0x1c))
  #define local_1ed0 (*(float *********** *)(albw_frame + 0x20))
  #define local_1ecc (*(float *********** *)(albw_frame + 0x24))
  #define local_1ec8 (*(float ************ *)(albw_frame + 0x28))
  #define local_1ec4 (*(float *********** *)(albw_frame + 0x2c))
  #define local_1ec0 ((float *)(albw_frame + 0x30))
  #define local_1e9c (*(float *********** *)(albw_frame + 0x54))
  #define local_1e98 (*(undefined4 *)(albw_frame + 0x58))
  #define local_1e90 (*(float ************ *)(albw_frame + 0x60))
  #define local_1e8c (*(float *********** *)(albw_frame + 0x64))
  #define local_1e88 (*(float *********** *)(albw_frame + 0x68))
  #define local_1e84 (*(float *********** *)(albw_frame + 0x6c))
  #define local_1e80 (*(float *********** *)(albw_frame + 0x70))
  #define local_1e7c (*(float *********** *)(albw_frame + 0x74))
  #define local_1e78 (*(float *********** *)(albw_frame + 0x78))
  #define local_1e74 (*(float ************ *)(albw_frame + 0x7c))
  #define local_1e70 (*(float *********** *)(albw_frame + 0x80))
  #define local_1e6c (*(float *********** *)(albw_frame + 0x84))
  #define local_1e68 (*(float *********** *)(albw_frame + 0x88))
  #define local_1e64 (*(float *********** *)(albw_frame + 0x8c))
  #define local_1e60 (*(float *********** *)(albw_frame + 0x90))
  #define local_1e5c (*(float *********** *)(albw_frame + 0x94))
  #define local_1e58 (*(float *********** *)(albw_frame + 0x98))
  #define local_1e54 (*(float *********** *)(albw_frame + 0x9c))
  #define local_1e50 (*(float *********** *)(albw_frame + 0xa0))
  #define local_1e4c (*(float *********** *)(albw_frame + 0xa4))
  #define local_1e48 (*(float *********** *)(albw_frame + 0xa8))
  #define local_1e44 (*(float *********** *)(albw_frame + 0xac))
  #define local_1e40 (*(float *********** *)(albw_frame + 0xb0))
  #define local_1e3c (*(float *********** *)(albw_frame + 0xb4))
  #define local_1e38 (*(float *********** *)(albw_frame + 0xb8))
  #define local_1e34 (*(float *********** *)(albw_frame + 0xbc))
  #define local_1e30 (*(float *********** *)(albw_frame + 0xc0))
  #define local_1e2c (*(float *********** *)(albw_frame + 0xc4))
  #define local_1e28 (*(float *********** *)(albw_frame + 0xc8))
  #define local_1e24 (*(float *********** *)(albw_frame + 0xcc))
  #define local_1e20 (*(float *********** *)(albw_frame + 0xd0))
  #define local_1e1c (*(float *********** *)(albw_frame + 0xd4))
  #define local_1e18 (*(float *********** *)(albw_frame + 0xd8))
  #define local_1e14 (*(float *********** *)(albw_frame + 0xdc))
  #define local_1e10 (*(float *********** *)(albw_frame + 0xe0))
  #define local_1e0c (*(float *********** *)(albw_frame + 0xe4))
  #define local_1e08 (*(float *********** *)(albw_frame + 0xe8))
  #define local_1e04 (*(float *********** *)(albw_frame + 0xec))
  #define local_1e00 (*(float *********** *)(albw_frame + 0xf0))
  #define local_1dfc (*(float *********** *)(albw_frame + 0xf4))
  #define local_1df8 (*(float *********** *)(albw_frame + 0xf8))
  #define local_1df4 (*(float *********** *)(albw_frame + 0xfc))
  #define local_1df0 (*(float *********** *)(albw_frame + 0x100))
  #define local_1dec (*(float *********** *)(albw_frame + 0x104))
  #define local_1de8 (*(float *********** *)(albw_frame + 0x108))
  #define local_1de4 (*(float *********** *)(albw_frame + 0x10c))
  #define local_1de0 (*(float ************ *)(albw_frame + 0x110))
  #define local_1ddc (*(float *********** *)(albw_frame + 0x114))
  #define local_1dd8 (*(float *********** *)(albw_frame + 0x118))
  #define local_1dd4 (*(float *********** *)(albw_frame + 0x11c))
  #define local_1dd0 (*(float *********** *)(albw_frame + 0x120))
  #define local_1dcc (*(float *********** *)(albw_frame + 0x124))
  #define local_1dc8 (*(float ********* *)(albw_frame + 0x128))
  #define local_1dc4 (*(float ********* *)(albw_frame + 0x12c))
  #define local_1dc0 (*(float *********** *)(albw_frame + 0x130))
  #define local_1dbc (*(float *********** *)(albw_frame + 0x134))
  #define local_1db8 (*(float *********** *)(albw_frame + 0x138))
  #define local_30 (*(float *********** *)(albw_frame + 0x1ec0))
  #define local_2c (*(int *)(albw_frame + 0x1ec4))
  #define local_28 (*(int *)(albw_frame + 0x1ec8))
  uVar50 = ZEXT48(DAT_00642a2c);
  pppppppppppfVar36 = (float ***********)DAT_00642a2c;
  in_r0 = arg_r0;
  in_r1 = arg_r1;
  in_r2 = arg_r2;
  in_s0 = (float ***********)CF_FBITS(fparam_0);
  in_s1 = (float *********)CF_FBITS(fparam_1);
  local_30 = in_r0;
  local_2c = in_r1;
  local_28 = in_r2;
  func_001FE680((undefined4 *)(&local_1e88));
  pppppppppppfVar29 = local_30;
  local_1e64 = local_30 + 0x29;
  ppppppppppfVar9 = *local_1e64;
  if ((int)ppppppppppfVar9 < (int)local_30[0x2a]) {
    *local_1e64 = (float **********)((int)ppppppppppfVar9 + 1);
    ppppppppppfVar9 = local_30[0x2b] + (int)ppppppppppfVar9 * 0x27;
  }
  else {
    ppppppppppfVar9 = (float **********)0x0;
  }
  ppppppppppfVar9[0x1c] = (float *********)in_s0;
  fVar43 = DAT_00642a30;
  ppppppppppfVar41 = (float **********)CF_FBITS((ALBW_AS_F32(in_s0) * DAT_00642a30));
  ppppppppppfVar9[9] = (float *********)local_30[0xc];
  ppppppppppfVar9[10] = (float *********)local_30[0xd];
  ppppppppppfVar9[0xb] = (float *********)local_30[0xe];
  *(undefined1 *)(ppppppppppfVar9 + 0x24) = 1;
  local_30[0x1d] = ppppppppppfVar41;
  local_1e60 = (float ***********)0x0;
  local_1e58 = (float ***********)local_30[10];
  local_1e54 = (float ***********)local_30[0xc];
  local_1e50 = (float ***********)local_30[0xd];
  local_1e4c = (float ***********)local_30[0xe];
  local_1e48 = (float ***********)local_30[0x12];
  local_1e44 = (float ***********)local_30[0x13];
  local_1e40 = (float ***********)local_30[0x14];
  ppppppppppfVar9 = local_30[10];
  local_1e3c = (float ***********)ppppppppppfVar9[0xc];
  local_1e38 = (float ***********)ppppppppppfVar9[0xd];
  local_1e34 = (float ***********)ppppppppppfVar9[0xe];
  local_1e28 = local_30 + 2;
  local_1e30 = (float ***********)DAT_00642a34;
  local_1e2c = in_s0;
  local_1e04 = local_1e64;
  local_1df8 = local_1e28;
  if (local_1e64 != (float ***********)0x0) {
    ppppppppppfVar9 = local_30[0x2b] + (int)*local_1e64 * 0x27 + -0x27;
    *ppppppppppfVar9 = (float *********)local_1e48;
    ppppppppppfVar9[1] = (float *********)local_1e44;
    ppppppppppfVar9[2] = (float *********)local_1e40;
    ppppppppppfVar9[6] = (float *********)local_1e3c;
    ppppppppppfVar9[7] = (float *********)local_1e38;
    ppppppppppfVar9[8] = (float *********)local_1e34;
    func_004A17A4((float *)ppppppppppfVar9);
    local_1e24 = (float ***********)((int)*local_1e64 + -1);
  }
  func_0049F5FC((undefined4 *)(pppppppppppfVar29 + 2));
  func_0049F5FC((undefined4 *)(pppppppppppfVar29 + 6));
  pppppppppfVar26 = (float *********)0x0;
  while( true ) {
    fVar33 = ALBW_AS_F32(uVar50);
    ppppppppppfVar9 = *pppppppppppfVar29;
    pppppppppfVar10 = *ppppppppppfVar9;
    if ((int)pppppppppfVar10 <= (int)pppppppppfVar26) break;
    if (pppppppppfVar26 < pppppppppfVar10) {
      ppppppppppfVar9 = (float **********)ppppppppppfVar9[2];
    }
    if (pppppppppfVar26 < pppppppppfVar10) {
      pppppppppfVar10 = ppppppppppfVar9[(int)pppppppppfVar26];
    }
    else {
      pppppppppfVar10 = (float *********)0x0;
    }
    func_0010F1DC((int *)(pppppppppppfVar29 + 2),
                  (int *)((int)pppppppppppfVar29[5] + (int)pppppppppfVar10));
    pppppppppppfVar29[4] = (float **********)((int)pppppppppppfVar29[4] + 1);
    ppppppppppfVar9 = *pppppppppppfVar29;
    pppppppppfVar10 = *ppppppppppfVar9;
    if (pppppppppfVar26 < pppppppppfVar10) {
      ppppppppppfVar9 = (float **********)ppppppppppfVar9[2];
    }
    if (pppppppppfVar26 < pppppppppfVar10) {
      pppppppppfVar10 = ppppppppppfVar9[(int)pppppppppfVar26];
    }
    else {
      pppppppppfVar10 = (float *********)0x0;
    }
    func_0010F1DC((int *)(pppppppppppfVar29 + 6),
                  (int *)((int)pppppppppppfVar29[9] + (int)pppppppppfVar10));
    pppppppppfVar26 = (float *********)((int)pppppppppfVar26 + 1);
    pppppppppppfVar29[8] = (float **********)((int)pppppppppppfVar29[8] + 1);
  }
  func_0064CB28((int *)pppppppppppfVar29,(int *)&local_1e88,(int *)&local_1e58);
  uVar55 = CONCAT44(DAT_00642a38,fVar33);
  if (local_1e68 == (float ***********)0x0) {
    return 0;
  }
  lVar57 = (ulonglong)DAT_00642a40 << 0x20;
  local_30[0xedc] = (float **********)local_1e84;
  local_30[0xedd] = (float **********)local_1e80;
  local_30[0xede] = (float **********)local_1e7c;
  local_30[0xee2] = local_1e68[0xc];
  local_30[0xee3] = local_1e68[0xd];
  local_30[0xee4] = local_1e68[0xe];
  if (DAT_00642a3c < (int)local_1e88) {
    if ((ALBW_AS_F32(local_30[0x1e]) != fVar33) && ((int)DAT_00642a44 < (int)local_1e88)) {
      return 0;
    }
    local_1de0 = &local_1ddc;
    local_1de4 = (float ***********)0x30;
    local_1de8 = (float ***********)0x0;
    pppppppppppfVar36 = local_1e88;
    func_00100118((int)local_1de0,DAT_00642a48,0x9c,0x30);
    pppppppppppfVar29 = local_30;
    if ((int)local_1de8 < (int)local_1de4) {
      ppppppppppppfVar4 = local_1de0 + (int)local_1de8 * 0x27;
      local_1de8 = (float ***********)((int)local_1de8 + 1);
    }
    else {
      ppppppppppppfVar4 = (float ************)0x0;
    }
    ppppppppppppfVar4[0x1c] = pppppppppppfVar36;
    ppppppppppppfVar4[9] = (float ***********)local_30[0xc];
    ppppppppppppfVar4[10] = (float ***********)local_30[0xd];
    ppppppppppppfVar4[0xb] = (float ***********)local_30[0xe];
    *(undefined1 *)(ppppppppppppfVar4 + 0x24) = 0;
    pppppppppppfVar54 = (float ***********)CF_FBITS(-ALBW_AS_F32(local_1e88));
    func_001FE680((undefined4 *)(&local_1ef0));
    local_1ed4 = &local_1e14;
    local_1ecc = (float ***********)&local_1de8;
    if (ALBW_AS_F32(pppppppppppfVar54) <= ALBW_AS_F32(uVar55)) {
      local_1e2c = (float ***********)CF_FBITS(-ALBW_AS_F32(pppppppppppfVar54));
      lVar57 = CONCAT44((int)((ulonglong)lVar57 >> 0x20),local_1e2c);
      pppppppppppfVar29[0x1d] = (float **********)CF_FBITS(-(fVar43 * ALBW_AS_F32(pppppppppppfVar54)));
      local_1ec8 = (float ************)0x0;
      local_1e58 = (float ***********)pppppppppppfVar29[10];
      local_1e54 = (float ***********)pppppppppppfVar29[0xc];
      local_1e50 = (float ***********)pppppppppppfVar29[0xd];
      local_1e4c = (float ***********)pppppppppppfVar29[0xe];
      local_1e48 = (float ***********)CF_FBITS(-ALBW_AS_F32(pppppppppppfVar29[0x12]));
      local_1e44 = (float ***********)CF_FBITS(-ALBW_AS_F32(pppppppppppfVar29[0x13]));
      local_1e40 = (float ***********)CF_FBITS(-ALBW_AS_F32(pppppppppppfVar29[0x14]));
      ppppppppppfVar9 = pppppppppppfVar29[10];
      local_1e3c = (float ***********)ppppppppppfVar9[0xc];
      local_1e38 = (float ***********)ppppppppppfVar9[0xd];
      local_1e34 = (float ***********)ppppppppppfVar9[0xe];
      local_1e30 = (float ***********)DAT_00642a34;
      local_1e28 = local_1df8;
      if (&local_1de8 != (float ************)0x0) {
        ppppppppppppfVar4 = local_1de0 + (int)local_1de8 * 0x27 + -0x27;
        *ppppppppppppfVar4 = local_1e48;
        ppppppppppppfVar4[1] = local_1e44;
        ppppppppppppfVar4[2] = local_1e40;
        ppppppppppppfVar4[6] = local_1e3c;
        ppppppppppppfVar4[7] = local_1e38;
        ppppppppppppfVar4[8] = local_1e34;
        func_004A17A4((float *)ppppppppppppfVar4);
        local_1e24 = (float ***********)((int)*local_1ecc + -1);
      }
      func_0049F5FC((undefined4 *)(pppppppppppfVar29 + 2));
      func_0049F5FC((undefined4 *)(pppppppppppfVar29 + 6));
      pppppppppfVar26 = (float *********)0x0;
      while( true ) {
        ppppppppppfVar9 = *pppppppppppfVar29;
        pppppppppfVar10 = *ppppppppppfVar9;
        if ((int)pppppppppfVar10 <= (int)pppppppppfVar26) break;
        if (pppppppppfVar26 < pppppppppfVar10) {
          ppppppppppfVar9 = (float **********)ppppppppppfVar9[2];
        }
        if (pppppppppfVar26 < pppppppppfVar10) {
          pppppppppfVar10 = ppppppppppfVar9[(int)pppppppppfVar26];
        }
        else {
          pppppppppfVar10 = (float *********)0x0;
        }
        func_0010F1DC((int *)(pppppppppppfVar29 + 2),
                      (int *)((int)pppppppppppfVar29[5] + (int)pppppppppfVar10));
        pppppppppppfVar29[4] = (float **********)((int)pppppppppppfVar29[4] + 1);
        ppppppppppfVar9 = *pppppppppppfVar29;
        pppppppppfVar10 = *ppppppppppfVar9;
        if (pppppppppfVar26 < pppppppppfVar10) {
          ppppppppppfVar9 = (float **********)ppppppppppfVar9[2];
        }
        if (pppppppppfVar26 < pppppppppfVar10) {
          pppppppppfVar10 = ppppppppppfVar9[(int)pppppppppfVar26];
        }
        else {
          pppppppppfVar10 = (float *********)0x0;
        }
        func_0010F1DC((int *)(pppppppppppfVar29 + 6),
                      (int *)((int)pppppppppppfVar29[9] + (int)pppppppppfVar10));
        pppppppppfVar26 = (float *********)((int)pppppppppfVar26 + 1);
        pppppppppppfVar29[8] = (float **********)((int)pppppppppppfVar29[8] + 1);
      }
      func_0064E9F4((int *)pppppppppppfVar29,(undefined4 *)(&local_1ef0),(int *)&local_1e58);
      ppppppppppfVar9 =
           (float **********)CF_FBITS((ALBW_AS_F32(pppppppppppfVar29[0x1e]) - (ALBW_AS_F32(lVar57) - ALBW_AS_F32(local_1ef0))));
    }
    else {
      pppppppppppfVar29[0x1d] = (float **********)CF_FBITS((ALBW_AS_F32(pppppppppppfVar54) * fVar43));
      local_1ec8 = (float ************)0x0;
      local_1e58 = (float ***********)pppppppppppfVar29[10];
      local_1e54 = (float ***********)pppppppppppfVar29[0xc];
      local_1e50 = (float ***********)pppppppppppfVar29[0xd];
      local_1e4c = (float ***********)pppppppppppfVar29[0xe];
      local_1e48 = (float ***********)pppppppppppfVar29[0x12];
      local_1e44 = (float ***********)pppppppppppfVar29[0x13];
      local_1e40 = (float ***********)pppppppppppfVar29[0x14];
      ppppppppppfVar9 = pppppppppppfVar29[10];
      local_1e3c = (float ***********)ppppppppppfVar9[0xc];
      local_1e38 = (float ***********)ppppppppppfVar9[0xd];
      local_1e34 = (float ***********)ppppppppppfVar9[0xe];
      local_1e30 = (float ***********)DAT_00642a34;
      local_1e28 = local_1df8;
      local_1e2c = pppppppppppfVar54;
      if (&local_1de8 != (float ************)0x0) {
        ppppppppppppfVar4 = local_1de0 + (int)local_1de8 * 0x27 + -0x27;
        *ppppppppppppfVar4 = local_1e48;
        ppppppppppppfVar4[1] = local_1e44;
        ppppppppppppfVar4[2] = local_1e40;
        ppppppppppppfVar4[6] = local_1e3c;
        ppppppppppppfVar4[7] = local_1e38;
        ppppppppppppfVar4[8] = local_1e34;
        func_004A17A4((float *)ppppppppppppfVar4);
        local_1e24 = (float ***********)((int)*local_1ecc + -1);
      }
      func_0049F5FC((undefined4 *)(pppppppppppfVar29 + 2));
      func_0049F5FC((undefined4 *)(pppppppppppfVar29 + 6));
      pppppppppfVar26 = (float *********)0x0;
      while( true ) {
        ppppppppppfVar9 = *pppppppppppfVar29;
        pppppppppfVar10 = *ppppppppppfVar9;
        if ((int)pppppppppfVar10 <= (int)pppppppppfVar26) break;
        if (pppppppppfVar26 < pppppppppfVar10) {
          ppppppppppfVar9 = (float **********)ppppppppppfVar9[2];
        }
        if (pppppppppfVar26 < pppppppppfVar10) {
          pppppppppfVar10 = ppppppppppfVar9[(int)pppppppppfVar26];
        }
        else {
          pppppppppfVar10 = (float *********)0x0;
        }
        func_0010F1DC((int *)(pppppppppppfVar29 + 2),
                      (int *)((int)pppppppppppfVar29[5] + (int)pppppppppfVar10));
        pppppppppppfVar29[4] = (float **********)((int)pppppppppppfVar29[4] + 1);
        ppppppppppfVar9 = *pppppppppppfVar29;
        pppppppppfVar10 = *ppppppppppfVar9;
        if (pppppppppfVar26 < pppppppppfVar10) {
          ppppppppppfVar9 = (float **********)ppppppppppfVar9[2];
        }
        if (pppppppppfVar26 < pppppppppfVar10) {
          pppppppppfVar10 = ppppppppppfVar9[(int)pppppppppfVar26];
        }
        else {
          pppppppppfVar10 = (float *********)0x0;
        }
        func_0010F1DC((int *)(pppppppppppfVar29 + 6),
                      (int *)((int)pppppppppppfVar29[9] + (int)pppppppppfVar10));
        pppppppppfVar26 = (float *********)((int)pppppppppfVar26 + 1);
        pppppppppppfVar29[8] = (float **********)((int)pppppppppppfVar29[8] + 1);
      }
      func_0064CB28((int *)pppppppppppfVar29,(int *)&local_1ef0,(int *)&local_1e58);
      ppppppppppfVar9 =
           (float **********)
           CF_FBITS((ALBW_AS_F32(pppppppppppfVar29[0x1e]) + (ALBW_AS_F32(pppppppppppfVar54) - ALBW_AS_F32(local_1ef0))));
    }
    pppppppppppfVar29[0x1e] = ppppppppppfVar9;
    if (local_1ed0 != (float ***********)0x0) {
      *(float ***********)(DAT_00643d48 + (int)pppppppppppfVar29) = *local_1ed0;
      pppppppppppfVar29[0xc] = (float **********)local_1eec;
      pppppppppppfVar29[0xd] = (float **********)local_1ee8;
      pppppppppppfVar29[0xe] = (float **********)local_1ee4;
      if ((float ***********)pppppppppppfVar29[10] != local_1ed0) {
        pppppppppppfVar29[10] = (float **********)local_1ed0;
        pppppppppppfVar29[0x18] = local_1ed0[0xc];
        pppppppppppfVar29[0x19] = local_1ed0[0xd];
        pppppppppppfVar29[0x1a] = local_1ed0[0xe];
        pppppppfVar44 = DAT_00642a34;
        pppppppppppfVar29[0x15] = (float **********)*DAT_00642a34;
        pppppppppppfVar29[0x16] = (float **********)pppppppfVar44[1];
        pppppppppppfVar29[0x17] = (float **********)pppppppfVar44[2];
        func_004A17E4((float *)(pppppppppppfVar29 + 0x12));
      }
      pppppppppppfVar29[0xf] = (float **********)local_1e14;
      pppppppppppfVar29[0x10] = (float **********)local_1e10;
      pppppppppppfVar29[0x11] = (float **********)local_1e0c;
    }
    local_1e88 = local_1ef0;
    if ((int)ALBW_AS_U32(DAT_00643d4c) < (int)local_1ef0) {
      return 0;
    }
    if (local_1de8 == (float ***********)0x1) {
      if (*local_1e64 == (float **********)0x0) {
        ppppppppppfVar9 = (float **********)0x0;
      }
      else {
        ppppppppppfVar9 = local_1e64[2];
      }
      ppppppppppfVar9[9] = (float *********)local_30[0xc];
      ppppppppppfVar9[10] = (float *********)local_30[0xd];
      ppppppppppfVar9[0xb] = (float *********)local_30[0xe];
      ppppppppppfVar9[0x1c] = (float *********)CF_FBITS((ALBW_AS_F32(in_s0) + ALBW_AS_F32(pppppppppppfVar36)));
    }
    else {
      fVar33 = ALBW_AS_F32(uVar55);
      pppppppppppfVar29 = (float ***********)0x0;
      if (*local_1e64 == (float **********)0x0) {
        ppppppppppfVar9 = (float **********)0x0;
      }
      else {
        ppppppppppfVar9 = local_1e64[2];
      }
      if (0 < (int)local_1de8) {
        fVar48 = ALBW_AS_F32(((ulonglong)lVar57 >> 0x20));
        ppppppppppppfVar4 = (float ************)0x0;
        do {
          ppppppppppppfVar5 = local_1de0;
          if (pppppppppppfVar29 < local_1de8) {
            ppppppppppppfVar5 = local_1de0 + (int)pppppppppppfVar29 * 0x27;
          }
          if (((ALBW_AS_F32(ppppppppppfVar9[6]) == ALBW_AS_F32(ppppppppppppfVar5[6])) &&
              (ALBW_AS_F32(ppppppppppfVar9[7]) == ALBW_AS_F32(ppppppppppppfVar5[7]))) &&
             (ALBW_AS_F32(ppppppppppfVar9[8]) == ALBW_AS_F32(ppppppppppppfVar5[8]))) {
            ppppppppppfVar9[9] = (float *********)ppppppppppppfVar5[0xc];
            ppppppppppfVar9[10] = (float *********)ppppppppppppfVar5[0xd];
            ppppppppppfVar9[0xb] = (float *********)ppppppppppppfVar5[0xe];
            fVar33 = ALBW_AS_F32(ppppppppppppfVar5[0x1c]) - ALBW_AS_F32(ppppppppppppfVar5[0x1d]);
            ppppppppppfVar9[0x1c] = (float *********)CF_FBITS((ALBW_AS_F32(in_s0) + fVar33));
            ppppppppppppfVar5 = ppppppppppppfVar4;
          }
          else {
            pppppppppppfVar54 = ppppppppppppfVar5[0x1d];
            *(undefined1 *)(ppppppppppppfVar5 + 0x24) = 1;
            if (ppppppppppppfVar4 == (float ************)0x0) {
              pppppppppppfVar8 = (float ***********)ppppppppppfVar9[0x1c];
            }
            else {
              pppppppppppfVar8 = ppppppppppppfVar4[0x1c];
            }
            ppppppppppppfVar5[0x1d] = pppppppppppfVar8;
            fVar33 = (ALBW_AS_F32(ppppppppppppfVar5[0x1c]) - ALBW_AS_F32(pppppppppppfVar54)) + fVar33;
            ppppppppppppfVar5[0x1c] = (float ***********)CF_FBITS((ALBW_AS_F32(in_s0) + fVar33));
            pppppppppppfVar8 = ppppppppppppfVar5[9];
            pppppppppppfVar35 = ppppppppppppfVar5[10];
            ppppppppppppfVar5[9] = ppppppppppppfVar5[0xc];
            ppppppppppppfVar5[10] = ppppppppppppfVar5[0xd];
            pppppppppppfVar54 = ppppppppppppfVar5[0xe];
            ppppppppppppfVar5[0xe] = ppppppppppppfVar5[0xb];
            ppppppppppppfVar5[0xb] = pppppppppppfVar54;
            ppppppppppppfVar5[0xc] = pppppppppppfVar8;
            ppppppppppppfVar5[0xd] = pppppppppppfVar35;
            func_00115D70((float *)ppppppppppppfVar5,(float *)ppppppppppppfVar5,fVar48);
            func_00115D70((float *)(ppppppppppppfVar5 + 3),(float *)(ppppppppppppfVar5 + 3),fVar48);
            ppppppppppfVar41 = *local_1e64;
            if ((int)ppppppppppfVar41 < (int)local_1e64[1]) {
              *local_1e64 = (float **********)((int)ppppppppppfVar41 + 1);
              ppppppppppfVar41 = local_1e64[2] + (int)ppppppppppfVar41 * 0x27;
              local_1e58 = (float ***********)(ppppppppppfVar41 + 9);
              *ppppppppppfVar41 = (float *********)*ppppppppppppfVar5;
              local_1ec8 = ppppppppppppfVar5 + 0xf;
              ppppppppppfVar41[1] = (float *********)ppppppppppppfVar5[1];
              ppppppppppfVar41[2] = (float *********)ppppppppppppfVar5[2];
              ppppppppppfVar41[3] = (float *********)ppppppppppppfVar5[3];
              ppppppppppfVar41[4] = (float *********)ppppppppppppfVar5[4];
              local_1e90 = ppppppppppppfVar5 + 0x12;
              ppppppppppfVar41[5] = (float *********)ppppppppppppfVar5[5];
              ppppppppppfVar41[6] = (float *********)ppppppppppppfVar5[6];
              ppppppppppfVar41[7] = (float *********)ppppppppppppfVar5[7];
              ppppppppppfVar41[8] = (float *********)ppppppppppppfVar5[8];
              *local_1e58 = (float **********)ppppppppppppfVar5[9];
              ppppppppppfVar41[10] = (float *********)ppppppppppppfVar5[10];
              ppppppppppfVar41[0xb] = (float *********)ppppppppppppfVar5[0xb];
              ppppppppppfVar41[0xc] = (float *********)ppppppppppppfVar5[0xc];
              ppppppppppfVar41[0xd] = (float *********)ppppppppppppfVar5[0xd];
              ppppppppppfVar41[0xe] = (float *********)ppppppppppppfVar5[0xe];
              ppppppppppfVar41[0xf] = (float *********)*local_1ec8;
              ppppppppppfVar41[0x10] = (float *********)ppppppppppppfVar5[0x10];
              ppppppppppfVar41[0x11] = (float *********)ppppppppppppfVar5[0x11];
              ppppppppppfVar41[0x12] = (float *********)*local_1e90;
              ppppppppppfVar41[0x13] = (float *********)ppppppppppppfVar5[0x13];
              ppppppppppfVar41[0x14] = (float *********)ppppppppppppfVar5[0x14];
              ppppppppppfVar41[0x15] = (float *********)ppppppppppppfVar5[0x15];
              ppppppppppfVar41[0x16] = (float *********)ppppppppppppfVar5[0x16];
              ppppppppppfVar41[0x17] = (float *********)ppppppppppppfVar5[0x17];
              ppppppppppfVar41[0x18] = (float *********)ppppppppppppfVar5[0x18];
              ppppppppppfVar41[0x19] = (float *********)ppppppppppppfVar5[0x19];
              ppppppppppfVar41[0x1a] = (float *********)ppppppppppppfVar5[0x1a];
              ppppppppppfVar41[0x1b] = (float *********)ppppppppppppfVar5[0x1b];
              ppppppppppfVar41[0x1c] = (float *********)ppppppppppppfVar5[0x1c];
              ppppppppppfVar41[0x1d] = (float *********)ppppppppppppfVar5[0x1d];
              ppppppppppfVar41[0x1e] = (float *********)ppppppppppppfVar5[0x1e];
              ppppppppppfVar41[0x1f] = (float *********)ppppppppppppfVar5[0x1f];
              ppppppppppfVar41[0x20] = (float *********)ppppppppppppfVar5[0x20];
              ppppppppppfVar41[0x21] = (float *********)ppppppppppppfVar5[0x21];
              ppppppppppfVar41[0x22] = (float *********)ppppppppppppfVar5[0x22];
              ppppppppppfVar41[0x23] = (float *********)ppppppppppppfVar5[0x23];
              *(undefined1 *)(ppppppppppfVar41 + 0x24) = *(undefined1 *)(ppppppppppppfVar5 + 0x24);
              *(undefined1 *)((int)ppppppppppfVar41 + 0x91) =
                   *(undefined1 *)((int)ppppppppppppfVar5 + 0x91);
              *(undefined1 *)((int)ppppppppppfVar41 + 0x92) =
                   *(undefined1 *)((int)ppppppppppppfVar5 + 0x92);
              *(undefined1 *)((int)ppppppppppfVar41 + 0x93) =
                   *(undefined1 *)((int)ppppppppppppfVar5 + 0x93);
              *(undefined1 *)(ppppppppppfVar41 + 0x25) = *(undefined1 *)(ppppppppppppfVar5 + 0x25);
              *(undefined1 *)((int)ppppppppppfVar41 + 0x95) =
                   *(undefined1 *)((int)ppppppppppppfVar5 + 0x95);
              *(undefined1 *)((int)ppppppppppfVar41 + 0x96) =
                   *(undefined1 *)((int)ppppppppppppfVar5 + 0x96);
              *(undefined1 *)((int)ppppppppppfVar41 + 0x97) =
                   *(undefined1 *)((int)ppppppppppppfVar5 + 0x97);
              *(undefined1 *)(ppppppppppfVar41 + 0x26) = *(undefined1 *)(ppppppppppppfVar5 + 0x26);
            }
          }
          pppppppppppfVar29 = (float ***********)((int)pppppppppppfVar29 + 1);
          ppppppppppppfVar4 = ppppppppppppfVar5;
        } while ((int)pppppppppppfVar29 < (int)local_1de8);
      }
    }
  }
  uVar49 = CONCAT44(in_s0,local_1e88);
  func_001FE680((undefined4 *)(&local_1e60));
  pppppppppppfVar29 = local_30;
  local_1e3c = local_1e04;
  ppppppppppfVar9 = *local_1e04;
  if ((int)ppppppppppfVar9 < (int)local_1e04[1]) {
    *local_1e04 = (float **********)((int)ppppppppppfVar9 + 1);
    ppppppppppfVar41 = local_1e04[2] + (int)ppppppppppfVar9 * 0x27;
  }
  else {
    ppppppppppfVar41 = (float **********)0x0;
  }
  ppppppppppfVar41[0x1c] = in_s1;
  pppppppfVar44 = DAT_00642a34;
  local_1dc4 = (float *********)CF_FBITS((ALBW_AS_F32(in_s1) + ALBW_AS_F32(uVar49)));
  ppppppppppfVar41[9] = (float *********)local_30[0xc];
  ppppppppppfVar41[10] = (float *********)local_30[0xd];
  ppppppppppfVar41[0xb] = (float *********)local_30[0xe];
  *(undefined1 *)(ppppppppppfVar41 + 0x24) = 0;
  local_30[0x1d] = (float **********)CF_FBITS((ALBW_AS_F32(local_1dc4) * fVar43));
  local_1e38 = (float ***********)0x0;
  local_1df0 = (float ***********)local_30[10];
  local_1dec = (float ***********)local_30[0xc];
  local_1de8 = (float ***********)local_30[0xd];
  local_1de4 = (float ***********)local_30[0xe];
  local_1de0 = (float ************)CF_FBITS(-ALBW_AS_F32(local_30[0x12]));
  local_1ddc = (float ***********)CF_FBITS(-ALBW_AS_F32(local_30[0x13]));
  local_1dd8 = (float ***********)CF_FBITS(-ALBW_AS_F32(local_30[0x14]));
  ppppppppppfVar41 = local_30[10];
  local_1dd4 = (float ***********)ppppppppppfVar41[0xc];
  local_1dd0 = (float ***********)ppppppppppfVar41[0xd];
  local_1dcc = (float ***********)ppppppppppfVar41[0xe];
  local_1dc8 = (float *********)pppppppfVar44;
  local_1dc0 = local_1df8;
  if (local_1e04 != (float ***********)0x0) {
    ppppppppppfVar41 = local_1e04[2] + (int)*local_1e04 * 0x27 + -0x27;
    *ppppppppppfVar41 = (float *********)local_1de0;
    ppppppppppfVar41[1] = (float *********)local_1ddc;
    ppppppppppfVar41[2] = (float *********)local_1dd8;
    ppppppppppfVar41[6] = (float *********)local_1dd4;
    ppppppppppfVar41[7] = (float *********)local_1dd0;
    ppppppppppfVar41[8] = (float *********)local_1dcc;
    func_004A17A4((float *)ppppppppppfVar41);
    local_1dbc = (float ***********)((int)*local_1e3c + -1);
  }
  func_0049F5FC((undefined4 *)(pppppppppppfVar29 + 2));
  func_0049F5FC((undefined4 *)(pppppppppppfVar29 + 6));
  pppppppppfVar26 = (float *********)0x0;
  while( true ) {
    pppppppppfVar47 = (float *********)((ulonglong)uVar49 >> 0x20);
    ppppppppppfVar41 = *pppppppppppfVar29;
    pppppppppfVar10 = *ppppppppppfVar41;
    if ((int)pppppppppfVar10 <= (int)pppppppppfVar26) break;
    if (pppppppppfVar26 < pppppppppfVar10) {
      ppppppppppfVar41 = (float **********)ppppppppppfVar41[2];
    }
    if (pppppppppfVar26 < pppppppppfVar10) {
      pppppppppfVar10 = ppppppppppfVar41[(int)pppppppppfVar26];
    }
    else {
      pppppppppfVar10 = (float *********)0x0;
    }
    func_0010F1DC((int *)(pppppppppppfVar29 + 2),
                  (int *)((int)pppppppppppfVar29[5] + (int)pppppppppfVar10));
    pppppppppppfVar29[4] = (float **********)((int)pppppppppppfVar29[4] + 1);
    ppppppppppfVar41 = *pppppppppppfVar29;
    pppppppppfVar10 = *ppppppppppfVar41;
    if (pppppppppfVar26 < pppppppppfVar10) {
      ppppppppppfVar41 = (float **********)ppppppppppfVar41[2];
    }
    if (pppppppppfVar26 < pppppppppfVar10) {
      pppppppppfVar10 = ppppppppppfVar41[(int)pppppppppfVar26];
    }
    else {
      pppppppppfVar10 = (float *********)0x0;
    }
    func_0010F1DC((int *)(pppppppppppfVar29 + 6),
                  (int *)((int)pppppppppppfVar29[9] + (int)pppppppppfVar10));
    pppppppppfVar26 = (float *********)((int)pppppppppfVar26 + 1);
    pppppppppppfVar29[8] = (float **********)((int)pppppppppppfVar29[8] + 1);
  }
  func_0064E9F4((int *)pppppppppppfVar29,(undefined4 *)(&local_1e60),(int *)&local_1df0);
  pppppppppppfVar29 = local_30;
  if (local_1e40 == (float ***********)0x0) {
    return 0;
  }
  fVar33 = ALBW_AS_F32(uVar55);
  local_30[0xedf] = (float **********)local_1e5c;
  local_30[0xee0] = (float **********)local_1e58;
  local_30[0xee1] = (float **********)local_1e54;
  local_30[0xee5] = local_1e40[0xc];
  local_30[0xee6] = local_1e40[0xd];
  local_30[0xee7] = local_1e40[0xe];
  local_1df4 = local_30 + 0x77c;
  if (DAT_00642a3c < (int)local_1e60) {
    ppppppppppfVar41 = local_30[0x1e];
    bVar39 = ALBW_AS_F32(ppppppppppfVar41) < fVar33;
    bVar40 = NAN(ALBW_AS_F32(ppppppppppfVar41)) || NAN(fVar33);
    if (ALBW_AS_F32(ppppppppppfVar41) != fVar33) {
      bVar40 = SBORROW4((int)local_1e60,(int)DAT_00642a44);
      bVar39 = (int)local_1e60 - (int)DAT_00642a44 < 0;
    }
    if ((ALBW_AS_F32(ppppppppppfVar41) != fVar33 && local_1e60 != (float ***********)DAT_00642a44) &&
        bVar39 == bVar40) {
      return 0;
    }
    if (local_2c != 0) {
      return 0;
    }
    uVar49 = CONCAT44(local_1e60,in_s1);
    uVar50 = ZEXT48(local_1e60);
    func_001FE680((undefined4 *)(&local_1e90));
    pppppppppppfVar36 = (float ***********)uVar50;
    local_1e74 = &local_1ecc;
    if (ALBW_AS_F32(pppppppppppfVar36) <= ALBW_AS_F32(uVar55)) {
      local_1e04 = (float ***********)CF_FBITS(-ALBW_AS_F32(pppppppppppfVar36));
      uVar50 = ZEXT48(local_1e04);
      pppppppppppfVar29[0x1d] = (float **********)CF_FBITS(-(fVar43 * ALBW_AS_F32(pppppppppppfVar36)));
      local_1e30 = (float ***********)pppppppppppfVar29[10];
      local_1e2c = (float ***********)pppppppppppfVar29[0xc];
      local_1e28 = (float ***********)pppppppppppfVar29[0xd];
      local_1e24 = (float ***********)pppppppppppfVar29[0xe];
      local_1e20 = (float ***********)CF_FBITS(-ALBW_AS_F32(pppppppppppfVar29[0x12]));
      local_1e18 = (float ***********)CF_FBITS(-ALBW_AS_F32(pppppppppppfVar29[0x14]));
      local_1e1c = (float ***********)CF_FBITS(-ALBW_AS_F32(pppppppppppfVar29[0x13]));
      ppppppppppfVar41 = pppppppppppfVar29[10];
      local_1e14 = (float ***********)ppppppppppfVar41[0xc];
      local_1e10 = (float ***********)ppppppppppfVar41[0xd];
      local_1e0c = (float ***********)ppppppppppfVar41[0xe];
      local_1e00 = local_1df8;
      local_1e08 = (float ***********)pppppppfVar44;
      local_1e68 = (float ***********)0x0;
      local_1e6c = (float ***********)0x0;
      local_1ee8 = (float ***********)&local_1e90;
      func_0049F5FC((undefined4 *)(pppppppppppfVar29 + 2));
      func_0049F5FC((undefined4 *)(pppppppppppfVar29 + 6));
      pppppppppfVar26 = (float *********)0x0;
      while( true ) {
        fVar43 = ALBW_AS_F32(uVar50);
        ppppppppppfVar41 = *pppppppppppfVar29;
        pppppppppfVar10 = *ppppppppppfVar41;
        if ((int)pppppppppfVar10 <= (int)pppppppppfVar26) break;
        if (pppppppppfVar26 < pppppppppfVar10) {
          ppppppppppfVar41 = (float **********)ppppppppppfVar41[2];
        }
        if (pppppppppfVar26 < pppppppppfVar10) {
          pppppppppfVar10 = ppppppppppfVar41[(int)pppppppppfVar26];
        }
        else {
          pppppppppfVar10 = (float *********)0x0;
        }
        func_0010F1DC((int *)(pppppppppppfVar29 + 2),
                      (int *)((int)pppppppppppfVar29[5] + (int)pppppppppfVar10));
        pppppppppppfVar29[4] = (float **********)((int)pppppppppppfVar29[4] + 1);
        ppppppppppfVar41 = *pppppppppppfVar29;
        pppppppppfVar10 = *ppppppppppfVar41;
        if (pppppppppfVar26 < pppppppppfVar10) {
          ppppppppppfVar41 = (float **********)ppppppppppfVar41[2];
        }
        if (pppppppppfVar26 < pppppppppfVar10) {
          pppppppppfVar10 = ppppppppppfVar41[(int)pppppppppfVar26];
        }
        else {
          pppppppppfVar10 = (float *********)0x0;
        }
        func_0010F1DC((int *)(pppppppppppfVar29 + 6),
                      (int *)((int)pppppppppppfVar29[9] + (int)pppppppppfVar10));
        pppppppppfVar26 = (float *********)((int)pppppppppfVar26 + 1);
        pppppppppppfVar29[8] = (float **********)((int)pppppppppppfVar29[8] + 1);
      }
      func_0064E9F4((int *)pppppppppppfVar29,(undefined4 *)(local_1ee8),(int *)&local_1e30);
      ppppppppppfVar41 =
           (float **********)CF_FBITS((ALBW_AS_F32(pppppppppppfVar29[0x1e]) - (fVar43 - ALBW_AS_F32(local_1e90))));
    }
    else {
      pppppppppppfVar29[0x1d] = (float **********)CF_FBITS((ALBW_AS_F32(pppppppppppfVar36) * fVar43));
      local_1e30 = (float ***********)pppppppppppfVar29[10];
      local_1e2c = (float ***********)pppppppppppfVar29[0xc];
      local_1e28 = (float ***********)pppppppppppfVar29[0xd];
      local_1e24 = (float ***********)pppppppppppfVar29[0xe];
      local_1e20 = (float ***********)pppppppppppfVar29[0x12];
      local_1e1c = (float ***********)pppppppppppfVar29[0x13];
      local_1e18 = (float ***********)pppppppppppfVar29[0x14];
      ppppppppppfVar41 = pppppppppppfVar29[10];
      local_1e14 = (float ***********)ppppppppppfVar41[0xc];
      local_1e10 = (float ***********)ppppppppppfVar41[0xd];
      local_1e0c = (float ***********)ppppppppppfVar41[0xe];
      local_1e00 = local_1df8;
      local_1e08 = (float ***********)pppppppfVar44;
      local_1e68 = (float ***********)0x0;
      local_1e6c = (float ***********)0x0;
      local_1ee0 = (float ***********)&local_1e90;
      local_1e04 = pppppppppppfVar36;
      func_0049F5FC((undefined4 *)(pppppppppppfVar29 + 2));
      func_0049F5FC((undefined4 *)(pppppppppppfVar29 + 6));
      pppppppppfVar26 = (float *********)0x0;
      while( true ) {
        fVar43 = ALBW_AS_F32(uVar50);
        ppppppppppfVar41 = *pppppppppppfVar29;
        pppppppppfVar10 = *ppppppppppfVar41;
        if ((int)pppppppppfVar10 <= (int)pppppppppfVar26) break;
        if (pppppppppfVar26 < pppppppppfVar10) {
          ppppppppppfVar41 = (float **********)ppppppppppfVar41[2];
        }
        if (pppppppppfVar26 < pppppppppfVar10) {
          pppppppppfVar10 = ppppppppppfVar41[(int)pppppppppfVar26];
        }
        else {
          pppppppppfVar10 = (float *********)0x0;
        }
        func_0010F1DC((int *)(pppppppppppfVar29 + 2),
                      (int *)((int)pppppppppppfVar29[5] + (int)pppppppppfVar10));
        pppppppppppfVar29[4] = (float **********)((int)pppppppppppfVar29[4] + 1);
        ppppppppppfVar41 = *pppppppppppfVar29;
        pppppppppfVar10 = *ppppppppppfVar41;
        if (pppppppppfVar26 < pppppppppfVar10) {
          ppppppppppfVar41 = (float **********)ppppppppppfVar41[2];
        }
        if (pppppppppfVar26 < pppppppppfVar10) {
          pppppppppfVar10 = ppppppppppfVar41[(int)pppppppppfVar26];
        }
        else {
          pppppppppfVar10 = (float *********)0x0;
        }
        func_0010F1DC((int *)(pppppppppppfVar29 + 6),
                      (int *)((int)pppppppppppfVar29[9] + (int)pppppppppfVar10));
        pppppppppfVar26 = (float *********)((int)pppppppppfVar26 + 1);
        pppppppppppfVar29[8] = (float **********)((int)pppppppppppfVar29[8] + 1);
      }
      func_0064CB28((int *)pppppppppppfVar29,(int *)local_1ee0,(int *)&local_1e30);
      ppppppppppfVar41 =
           (float **********)CF_FBITS((ALBW_AS_F32(pppppppppppfVar29[0x1e]) + (fVar43 - ALBW_AS_F32(local_1e90))));
    }
    pppppppppppfVar29[0x1e] = ppppppppppfVar41;
    if (local_1e70 != (float ***********)0x0) {
      *(float ***********)(DAT_00643d48 + (int)pppppppppppfVar29) = *local_1e70;
      pppppppppppfVar29[0xc] = (float **********)local_1e8c;
      pppppppppppfVar29[0xd] = (float **********)local_1e88;
      pppppppppppfVar29[0xe] = (float **********)local_1e84;
      if ((float ***********)pppppppppppfVar29[10] != local_1e70) {
        pppppppppppfVar29[10] = (float **********)local_1e70;
        pppppppppppfVar29[0x18] = local_1e70[0xc];
        pppppppppppfVar29[0x19] = local_1e70[0xd];
        pppppppppppfVar29[0x1a] = local_1e70[0xe];
        pppppppppppfVar29[0x15] = (float **********)*pppppppfVar44;
        pppppppppppfVar29[0x16] = (float **********)pppppppfVar44[1];
        pppppppppppfVar29[0x17] = (float **********)pppppppfVar44[2];
        func_004A17E4((float *)(pppppppppppfVar29 + 0x12));
      }
      pppppppppppfVar29[0xf] = (float **********)local_1ecc;
      pppppppppppfVar29[0x10] = (float **********)local_1ec8;
      pppppppppppfVar29[0x11] = (float **********)local_1ec4;
    }
    fVar43 = DAT_00643d4c;
    local_1e60 = (float ***********)local_1e90;
    if (ppppppppppfVar9 < *local_1e3c) {
      ppppppppppfVar9 = local_1e3c[2] + (int)ppppppppppfVar9 * 0x27;
    }
    else {
      ppppppppppfVar9 = (float **********)0x0;
    }
    ppppppppppfVar9[9] = (float *********)local_30[0xc];
    ppppppppppfVar9[10] = (float *********)local_30[0xd];
    ppppppppppfVar9[0xb] = (float *********)local_30[0xe];
    ppppppppppfVar9[0x1c] = (float *********)CF_FBITS((ALBW_AS_F32(uVar49) + ALBW_AS_F32(((ulonglong)uVar49 >> 0x20))));
    if ((int)ALBW_AS_U32(fVar43) < (int)local_1e90) {
      return 0;
    }
    *(undefined1 *)(local_30 + 0xf70) = 0;
    local_30[0x29] = (float **********)0x0;
    *local_1df4 = (float **********)0x0;
    return func_0064268C(local_30,1,local_28,fparam_0,fparam_1);
  }
  if (local_28 == 0) {
    return 0;
  }
  func_001FE680((undefined4 *)(local_1ec0));
  pppppppppppfVar29 = local_30;
  *local_1df4 = (float **********)0x0;
  local_1e9c = local_1df4;
  ppppppppppfVar9 = *local_1df4;
  if ((int)ppppppppppfVar9 < (int)local_1df4[1]) {
    *local_1df4 = (float **********)((int)ppppppppppfVar9 + 1);
    ppppppppppfVar9 = local_1df4[2] + (int)ppppppppppfVar9 * 0x27;
  }
  else {
    ppppppppppfVar9 = (float **********)0x0;
  }
  ppppppppppfVar9[0x1c] = pppppppppfVar47;
  ppppppppppfVar9[9] = (float *********)local_30[0xf];
  ppppppppppfVar9[10] = (float *********)local_30[0x10];
  ppppppppppfVar9[0xb] = (float *********)local_30[0x11];
  *(undefined1 *)(ppppppppppfVar9 + 0x24) = 1;
  local_1e98 = 0;
  local_1e90 = (float ************)local_30[0xb];
  local_1e8c = (float ***********)local_30[0xf];
  local_1e88 = (float ***********)local_30[0x10];
  local_1e84 = (float ***********)local_30[0x11];
  local_1ee4 = (float ***********)((ulonglong)uVar55 >> 0x20);
  local_1ee0 = (float ***********)uVar55;
  local_1ecc = local_1e90[0xc];
  local_1ec8 = (float ************)local_1e90[0xd];
  local_1ec4 = local_1e90[0xe];
  local_1ed8 = (float ***********)*pppppppfVar44;
  local_1ed4 = (float ************)pppppppfVar44[1];
  local_1ed0 = (float ***********)pppppppfVar44[2];
  local_1edc = ALBW_AS_F32(local_1ee0);
  func_004A17E4((float *)&local_1ee4);
  local_1e7c = local_1ee0;
  local_1e80 = local_1ee4;
  local_1e78 = (float ***********)CF_FBITS(local_1edc);
  ppppppppppfVar9 = pppppppppppfVar29[0xb];
  local_1e74 = (float ************)ppppppppppfVar9[0xc];
  local_1e70 = (float ***********)ppppppppppfVar9[0xd];
  local_1e6c = (float ***********)ppppppppppfVar9[0xe];
  local_1e68 = (float ***********)pppppppfVar44;
  local_1e60 = local_1df8;
  local_1e64 = (float ***********)pppppppppfVar47;
  if (local_1e9c != (float ***********)0x0) {
    ppppppppppfVar9 = local_1e9c[2] + (int)*local_1e9c * 0x27 + -0x27;
    *ppppppppppfVar9 = (float *********)local_1ee4;
    ppppppppppfVar9[1] = (float *********)local_1ee0;
    ppppppppppfVar9[2] = (float *********)CF_FBITS(local_1edc);
    ppppppppppfVar9[6] = (float *********)local_1e74;
    ppppppppppfVar9[7] = (float *********)local_1e70;
    ppppppppppfVar9[8] = (float *********)local_1e6c;
    func_004A17A4((float *)ppppppppppfVar9);
    local_1e5c = (float ***********)((int)*local_1e9c + -1);
  }
  func_0049F5FC((undefined4 *)(pppppppppppfVar29 + 2));
  func_0049F5FC((undefined4 *)(pppppppppppfVar29 + 6));
  pppppppppfVar26 = (float *********)0x0;
  while( true ) {
    uVar58 = (undefined4)((ulonglong)lVar57 >> 0x20);
    ppppppppppfVar9 = *pppppppppppfVar29;
    pppppppppfVar10 = *ppppppppppfVar9;
    if ((int)pppppppppfVar10 <= (int)pppppppppfVar26) break;
    if (pppppppppfVar26 < pppppppppfVar10) {
      ppppppppppfVar9 = (float **********)ppppppppppfVar9[2];
    }
    if (pppppppppfVar26 < pppppppppfVar10) {
      pppppppppfVar10 = ppppppppppfVar9[(int)pppppppppfVar26];
    }
    else {
      pppppppppfVar10 = (float *********)0x0;
    }
    func_0010F1DC((int *)(pppppppppppfVar29 + 2),
                  (int *)((int)pppppppppppfVar29[5] + (int)pppppppppfVar10));
    pppppppppppfVar29[4] = (float **********)((int)pppppppppppfVar29[4] + 1);
    ppppppppppfVar9 = *pppppppppppfVar29;
    pppppppppfVar10 = *ppppppppppfVar9;
    if (pppppppppfVar26 < pppppppppfVar10) {
      ppppppppppfVar9 = (float **********)ppppppppppfVar9[2];
    }
    if (pppppppppfVar26 < pppppppppfVar10) {
      pppppppppfVar10 = ppppppppppfVar9[(int)pppppppppfVar26];
    }
    else {
      pppppppppfVar10 = (float *********)0x0;
    }
    func_0010F1DC((int *)(pppppppppppfVar29 + 6),
                  (int *)((int)pppppppppppfVar29[9] + (int)pppppppppfVar10));
    pppppppppfVar26 = (float *********)((int)pppppppppfVar26 + 1);
    pppppppppppfVar29[8] = (float **********)((int)pppppppppppfVar29[8] + 1);
  }
  func_00649E18((int)pppppppppppfVar29,local_1ec0,(float *)&local_1e90);
  pppppppppppfVar29 = local_30;
  uVar49 = CONCAT44(uVar58,local_1ec0[0]);
  ppppppppppfVar9 = *local_1e9c;
  if ((int)ppppppppppfVar9 < (int)local_1e9c[1]) {
    *local_1e9c = (float **********)((int)ppppppppppfVar9 + 1);
    ppppppppppfVar9 = local_1e9c[2] + (int)ppppppppppfVar9 * 0x27;
  }
  else {
    ppppppppppfVar9 = (float **********)0x0;
  }
  ppppppppppfVar9[0x1c] = in_s1;
  local_1e58 = (float ***********)((ulonglong)uVar55 >> 0x20);
  uVar50 = ZEXT48(local_1e58);
  local_1e54 = (float ***********)uVar55;
  ppppppppppfVar9[9] = (float *********)local_30[0xf];
  ppppppppppfVar9[10] = (float *********)local_30[0x10];
  ppppppppppfVar9[0xb] = (float *********)local_30[0x11];
  *(undefined1 *)(ppppppppppfVar9 + 0x24) = 0;
  local_1e98 = 0;
  uVar55 = CONCAT44(local_1e54,local_1ec0[0] + ALBW_AS_F32(in_s1));
  local_1e90 = (float ************)local_30[0xb];
  local_1e8c = (float ***********)local_30[0xf];
  local_1e88 = (float ***********)local_30[0x10];
  local_1e84 = (float ***********)local_30[0x11];
  local_1e40 = local_1e90[0xc];
  local_1e3c = local_1e90[0xd];
  local_1e38 = local_1e90[0xe];
  local_1e4c = (float ***********)*pppppppfVar44;
  local_1e48 = (float ***********)pppppppfVar44[1];
  local_1e44 = (float ***********)pppppppfVar44[2];
  local_1e50 = local_1e54;
  func_004A17E4((float *)&local_1e58);
  local_1e80 = (float ***********)CF_FBITS(-ALBW_AS_F32(local_1e58));
  local_1e78 = (float ***********)CF_FBITS(-ALBW_AS_F32(local_1e50));
  local_1e7c = (float ***********)CF_FBITS(-ALBW_AS_F32(local_1e54));
  ppppppppppfVar9 = pppppppppppfVar29[0xb];
  local_1e74 = (float ************)ppppppppppfVar9[0xc];
  local_1e70 = (float ***********)ppppppppppfVar9[0xd];
  local_1e6c = (float ***********)ppppppppppfVar9[0xe];
  local_1e68 = (float ***********)pppppppfVar44;
  local_1e64 = (float ***********)uVar55;
  local_1e60 = local_1df8;
  if (local_1e9c != (float ***********)0x0) {
    ppppppppppfVar9 = local_1e9c[2] + (int)*local_1e9c * 0x27 + -0x27;
    *ppppppppppfVar9 = (float *********)local_1e80;
    ppppppppppfVar9[1] = (float *********)local_1e7c;
    ppppppppppfVar9[2] = (float *********)local_1e78;
    ppppppppppfVar9[6] = (float *********)local_1e74;
    ppppppppppfVar9[7] = (float *********)local_1e70;
    ppppppppppfVar9[8] = (float *********)local_1e6c;
    func_004A17A4((float *)ppppppppppfVar9);
    local_1e5c = (float ***********)((int)*local_1e9c + -1);
  }
  func_0049F5FC((undefined4 *)(pppppppppppfVar29 + 2));
  func_0049F5FC((undefined4 *)(pppppppppppfVar29 + 6));
  pppppppppfVar26 = (float *********)0x0;
  while( true ) {
    fVar43 = ALBW_AS_F32(uVar50);
    uVar58 = (undefined4)((ulonglong)uVar55 >> 0x20);
    ppppppppppfVar9 = *pppppppppppfVar29;
    pppppppppfVar10 = *ppppppppppfVar9;
    if ((int)pppppppppfVar10 <= (int)pppppppppfVar26) break;
    if (pppppppppfVar26 < pppppppppfVar10) {
      ppppppppppfVar9 = (float **********)ppppppppppfVar9[2];
    }
    if (pppppppppfVar26 < pppppppppfVar10) {
      pppppppppfVar10 = ppppppppppfVar9[(int)pppppppppfVar26];
    }
    else {
      pppppppppfVar10 = (float *********)0x0;
    }
    func_0010F1DC((int *)(pppppppppppfVar29 + 2),
                  (int *)((int)pppppppppppfVar29[5] + (int)pppppppppfVar10));
    pppppppppppfVar29[4] = (float **********)((int)pppppppppppfVar29[4] + 1);
    ppppppppppfVar9 = *pppppppppppfVar29;
    pppppppppfVar10 = *ppppppppppfVar9;
    if (pppppppppfVar26 < pppppppppfVar10) {
      ppppppppppfVar9 = (float **********)ppppppppppfVar9[2];
    }
    if (pppppppppfVar26 < pppppppppfVar10) {
      pppppppppfVar10 = ppppppppppfVar9[(int)pppppppppfVar26];
    }
    else {
      pppppppppfVar10 = (float *********)0x0;
    }
    func_0010F1DC((int *)(pppppppppppfVar29 + 6),
                  (int *)((int)pppppppppppfVar29[9] + (int)pppppppppfVar10));
    pppppppppfVar26 = (float *********)((int)pppppppppfVar26 + 1);
    pppppppppppfVar29[8] = (float **********)((int)pppppppppppfVar29[8] + 1);
  }
  func_0064B4A0((int)pppppppppppfVar29,local_1ec0,(float *)&local_1e90);
  pppppppppppfVar29 = local_30;
  uVar50 = CONCAT44(uVar58,local_1ec0[0]);
  local_1ed0 = (float ***********)0x0;
  fVar53 = ALBW_AS_F32(pppppppppfVar47) + ALBW_AS_F32(pppppppppppfVar36);
  pppppppppppfVar54 = local_30 + 0x29;
  fVar48 = ALBW_AS_F32(in_s1) + fVar33;
  if (((*DAT_006442fc & 1) == 0) &&
     (iVar6 = func_00100174((int *)DAT_006442fc), puVar3 = DAT_00644300, iVar6 != 0)) {
    puVar16 = DAT_00644300 + 3;
    *DAT_00644300 = 0;
    puVar3[1] = 0;
    puVar3[2] = 0;
    func_0010B3EC(puVar3,0x20,(int)puVar16);
  }
  fVar45 = DAT_00644308;
  fVar52 = DAT_00644304;
  puVar3 = DAT_00644300;
  uVar51 = CONCAT44(DAT_00644304,fVar43);
  uVar59 = (ulonglong)(uint)ALBW_AS_U32(DAT_00644308);
  *DAT_00644300 = 0;
  ppppppppppfVar9 = (float **********)0x0;
  fVar42 = fVar43 / (ALBW_AS_F32(pppppppppppfVar36) - fVar53);
  local_1edc = fVar42 * fVar52;
  local_1e8c = (float ***********)CF_FBITS((fVar52 + fVar53 * fVar42 * fVar45));
  fVar43 = fVar43 / (fVar33 - fVar48);
  local_1ee0 = (float ***********)CF_FBITS((fVar43 * fVar45));
  local_1e90 = (float ************)CF_FBITS((fVar52 + fVar48 * fVar43 * fVar52));
  if (0 < (int)*pppppppppppfVar54) {
    fVar43 = ALBW_AS_F32(((ulonglong)uVar49 >> 0x20));
    do {
      if (ppppppppppfVar9 < *pppppppppppfVar54) {
        ppppppppppfVar41 = pppppppppppfVar29[0x2b] + (int)ppppppppppfVar9 * 0x27;
      }
      else {
        ppppppppppfVar41 = pppppppppppfVar29[0x2b];
      }
      ppppppppppfVar41[0x1c] =
           (float *********)
           CF_FBITS((ALBW_AS_F32((&local_1e90)[*(char *)(ppppppppppfVar41 + 0x24)]) +
           ALBW_AS_F32((&local_1ee0)[*(char *)(ppppppppppfVar41 + 0x24)]) * ALBW_AS_F32(ppppppppppfVar41[0x1c])))
      ;
      pppppppppfVar26 =
           (float *********)
           CF_FBITS((ALBW_AS_F32((&local_1e90)[*(char *)(ppppppppppfVar41 + 0x24)]) +
           ALBW_AS_F32((&local_1ee0)[*(char *)(ppppppppppfVar41 + 0x24)]) * ALBW_AS_F32(ppppppppppfVar41[0x1d])))
      ;
      ppppppppppfVar41[0x1d] = pppppppppfVar26;
      if (ALBW_AS_F32(pppppppppfVar26) < ALBW_AS_F32(ppppppppppfVar41[0x1c])) {
        pppppppppfVar26 = ppppppppppfVar41[9];
        pppppppppfVar10 = ppppppppppfVar41[10];
        pppppppppfVar46 = ppppppppppfVar41[0xb];
        ppppppppppfVar41[9] = ppppppppppfVar41[0xc];
        ppppppppppfVar41[10] = ppppppppppfVar41[0xd];
        ppppppppppfVar41[0xb] = ppppppppppfVar41[0xe];
        ppppppppppfVar41[0xc] = pppppppppfVar26;
        ppppppppppfVar41[0xd] = pppppppppfVar10;
        ppppppppppfVar41[0xe] = pppppppppfVar46;
        pppppppppfVar26 = ppppppppppfVar41[0x1c];
        ppppppppppfVar41[0x1c] = ppppppppppfVar41[0x1d];
        ppppppppppfVar41[0x1d] = pppppppppfVar26;
      }
      ppppppppppfVar41[0xf] = ppppppppppfVar41[9];
      ppppppppppfVar41[0x10] = ppppppppppfVar41[10];
      ppppppppppfVar41[0x11] = ppppppppppfVar41[0xb];
      ppppppppppfVar41[0x12] = ppppppppppfVar41[0xc];
      ppppppppppfVar41[0x13] = ppppppppppfVar41[0xd];
      ppppppppppfVar41[0x14] = ppppppppppfVar41[0xe];
      *(undefined1 *)((int)ppppppppppfVar41 + 0x92) = 0;
      *(undefined1 *)((int)ppppppppppfVar41 + 0x91) = 0;
      ppppppppppfVar41[0x1b] = (float *********)(uVar50 >> 0x20);
      *(undefined1 *)(ppppppppppfVar41 + 0x26) = 0;
      *(undefined1 *)((int)ppppppppppfVar41 + 0x97) = 0;
      *(undefined1 *)((int)ppppppppppfVar41 + 0x95) = 0;
      *(undefined1 *)(ppppppppppfVar41 + 0x25) = 0;
      if (*(char *)(ppppppppppfVar41 + 0x24) == '\0') {
        func_00115D70((float *)ppppppppppfVar41,(float *)ppppppppppfVar41,fVar43);
        func_00115D70((float *)(ppppppppppfVar41 + 3),(float *)(ppppppppppfVar41 + 3),fVar43);
      }
      fVar45 = ALBW_AS_F32(uVar59);
      ppppppppppfVar9 = (float **********)((int)ppppppppppfVar9 + 1);
    } while ((int)ppppppppppfVar9 < (int)*pppppppppppfVar54);
  }
  ppppppppppfVar9 = (float **********)0x0;
  if (0 < (int)*pppppppppppfVar54) {
    do {
      puVar16 = DAT_00644300;
      ppppppppppfVar17 = *pppppppppppfVar54;
      ppppppppppfVar41 = pppppppppppfVar29[0x2b];
      if (ppppppppppfVar9 < ppppppppppfVar17) {
        ppppppppppfVar41 = ppppppppppfVar41 + (int)ppppppppppfVar9 * 0x27;
      }
      ppppppppppfVar22 = pppppppppppfVar29[0x2b];
      if (ppppppppppfVar9 < ppppppppppfVar17) {
        ppppppppppfVar22 = ppppppppppfVar22 + (int)ppppppppppfVar9 * 0x27;
      }
      if ((0xb4000000 < (uint)ALBW_AS_U32(ALBW_AS_F32(ppppppppppfVar41[0x1c]) - ALBW_AS_F32(ppppppppppfVar22[0x1d]))) ||
         (0x34000000 < (int)ALBW_AS_U32(ALBW_AS_F32(ppppppppppfVar41[0x1c]) - ALBW_AS_F32(ppppppppppfVar22[0x1d])))) {
        if (ppppppppppfVar9 < ppppppppppfVar17) {
          ppppppppppfVar41 = pppppppppppfVar29[0x2b] + (int)ppppppppppfVar9 * 0x27;
        }
        else {
          ppppppppppfVar41 = pppppppppppfVar29[0x2b];
        }
        if ((int)*DAT_00644300 < (int)DAT_00644300[1]) {
          *(float ***********)(DAT_00644300[2] + *DAT_00644300 * 4) = ppppppppppfVar41;
          *puVar16 = *puVar16 + 1;
        }
      }
      ppppppppppfVar9 = (float **********)((int)ppppppppppfVar9 + 1);
    } while ((int)ppppppppppfVar9 < (int)*pppppppppppfVar54);
  }
  *pppppppppppfVar54 = (float **********)0x0;
  if (*puVar3 != 0) {
    func_0048C258((int *)DAT_00644300,DAT_0064430c);
    if (((*DAT_00644310 & 1) == 0) &&
       (iVar6 = func_00100174((int *)DAT_00644310), puVar16 = DAT_00644314, iVar6 != 0)) {
      puVar18 = DAT_00644314 + 3;
      *DAT_00644314 = 0;
      puVar16[1] = 0x30;
      puVar16[2] = (uint)puVar18;
      func_00100118((int)(puVar16 + 3),DAT_00644318,0x9c,0x30);
    }
    puVar16 = DAT_00644314;
    *DAT_00644314 = 0;
    if (*puVar3 == 0) {
      puVar11 = (undefined4 *)0x0;
    }
    else {
      puVar11 = *(undefined4 **)puVar3[2];
    }
    if (0 < (int)puVar16[1]) {
      *puVar16 = 1;
      func_001FE514((undefined4 *)puVar16[2],puVar11);
    }
    iVar6 = *puVar16 * 0x9c + -0x9c + puVar16[2];
    uVar19 = 1;
    if (1 < (int)*puVar3) {
      do {
        uVar12 = *puVar3;
        uVar13 = uVar12;
        if (uVar19 < uVar12) {
          uVar13 = puVar3[2];
        }
        if (uVar19 < uVar12) {
          puVar11 = *(undefined4 **)(uVar13 + uVar19 * 4);
        }
        else {
          puVar11 = (undefined4 *)0x0;
        }
        fVar43 = *(float *)(iVar6 + 0x18) * ALBW_AS_F32(puVar11[6]) +
                 *(float *)(iVar6 + 0x1c) * ALBW_AS_F32(puVar11[7]) +
                 *(float *)(iVar6 + 0x20) * ALBW_AS_F32(puVar11[8]);
        if (fVar43 <= ALBW_AS_F32((uVar50 >> 0x20))) {
          fVar43 = -fVar43;
        }
        if (DAT_0064431c < (int)ALBW_AS_U32(fVar43)) {
          if (*(float *)(iVar6 + 0x74) < ALBW_AS_F32(puVar11[0x1d])) {
            *(undefined4 *)(iVar6 + 0x30) = puVar11[0xc];
            *(undefined4 *)(iVar6 + 0x34) = puVar11[0xd];
            *(undefined4 *)(iVar6 + 0x38) = puVar11[0xe];
            *(undefined4 *)(iVar6 + 0x74) = puVar11[0x1d];
            *(undefined4 *)(iVar6 + 0x48) = puVar11[0x12];
            *(undefined4 *)(iVar6 + 0x4c) = puVar11[0x13];
            *(undefined4 *)(iVar6 + 0x50) = puVar11[0x14];
          }
        }
        else {
          uVar13 = *puVar16;
          if ((int)uVar13 < (int)puVar16[1]) {
            *puVar16 = uVar13 + 1;
            puVar14 = (undefined4 *)(puVar16[2] + uVar13 * 0x9c);
            local_1ec4 = (float ***********)(puVar11 + 0xc);
            *puVar14 = *puVar11;
            local_1e74 = (float ************)(puVar14 + 6);
            puVar14[1] = puVar11[1];
            puVar14[2] = puVar11[2];
            local_1e84 = (float ***********)(puVar14 + 0xf);
            puVar14[3] = puVar11[3];
            puVar14[4] = puVar11[4];
            local_1e78 = (float ***********)(puVar11 + 0x12);
            puVar14[5] = puVar11[5];
            puVar14[6] = (undefined4)(uintptr_t)((float **********)puVar11[6]);
            puVar14[7] = puVar11[7];
            local_1e70 = (float ***********)(puVar11 + 0x15);
            puVar14[8] = puVar11[8];
            puVar14[9] = puVar11[9];
            puVar14[10] = puVar11[10];
            puVar14[0xb] = puVar11[0xb];
            puVar14[0xc] = (undefined4)(uintptr_t)((float **********)puVar11[0xc]);
            puVar14[0xd] = puVar11[0xd];
            puVar14[0xe] = puVar11[0xe];
            puVar14[0xf] = (undefined4)(uintptr_t)((float **********)puVar11[0xf]);
            puVar14[0x10] = puVar11[0x10];
            puVar14[0x11] = puVar11[0x11];
            puVar14[0x12] = (undefined4)(uintptr_t)((float **********)puVar11[0x12]);
            puVar14[0x13] = puVar11[0x13];
            puVar14[0x14] = puVar11[0x14];
            puVar14[0x15] = (undefined4)(uintptr_t)((float **********)puVar11[0x15]);
            puVar14[0x16] = puVar11[0x16];
            puVar14[0x17] = puVar11[0x17];
            puVar14[0x18] = puVar11[0x18];
            puVar14[0x19] = puVar11[0x19];
            puVar14[0x1a] = puVar11[0x1a];
            puVar14[0x1b] = puVar11[0x1b];
            puVar14[0x1c] = puVar11[0x1c];
            puVar14[0x1d] = puVar11[0x1d];
            puVar14[0x1e] = puVar11[0x1e];
            puVar14[0x1f] = puVar11[0x1f];
            puVar14[0x20] = puVar11[0x20];
            puVar14[0x21] = puVar11[0x21];
            puVar14[0x22] = puVar11[0x22];
            puVar14[0x23] = puVar11[0x23];
            *(undefined1 *)(puVar14 + 0x24) = *(undefined1 *)(puVar11 + 0x24);
            *(undefined1 *)((int)puVar14 + 0x91) = *(undefined1 *)((int)puVar11 + 0x91);
            *(undefined1 *)((int)puVar14 + 0x92) = *(undefined1 *)((int)puVar11 + 0x92);
            *(undefined1 *)((int)puVar14 + 0x93) = *(undefined1 *)((int)puVar11 + 0x93);
            *(undefined1 *)(puVar14 + 0x25) = *(undefined1 *)(puVar11 + 0x25);
            *(undefined1 *)((int)puVar14 + 0x95) = *(undefined1 *)((int)puVar11 + 0x95);
            *(undefined1 *)((int)puVar14 + 0x96) = *(undefined1 *)((int)puVar11 + 0x96);
            *(undefined1 *)((int)puVar14 + 0x97) = *(undefined1 *)((int)puVar11 + 0x97);
            *(undefined1 *)(puVar14 + 0x26) = *(undefined1 *)(puVar11 + 0x26);
          }
          iVar6 = *puVar16 * 0x9c + -0x9c + puVar16[2];
        }
        uVar19 = uVar19 + 1;
      } while ((int)uVar19 < (int)*puVar3);
    }
    uVar19 = *puVar16;
    local_1ee8 = (float ***********)0x0;
    uVar13 = 1;
    if (1 < (int)uVar19) {
      pfVar23 = (float *)puVar16[2];
      fVar43 = ABS(DAT_00645584);
      do {
        pfVar7 = pfVar23;
        if (uVar13 - 1 < uVar19) {
          pfVar7 = pfVar23 + (uVar13 - 1) * 0x27;
        }
        pfVar27 = pfVar23;
        if (uVar13 < uVar19) {
          pfVar27 = pfVar23 + uVar13 * 0x27;
        }
        fVar33 = pfVar7[7];
        iVar6 = (int)ALBW_AS_U32(fVar33) - (int)ALBW_AS_U32(fVar43);
        if ((int)ALBW_AS_U32(fVar33) <= (int)ALBW_AS_U32(fVar43)) {
          fVar33 = pfVar27[7];
          iVar6 = (int)ALBW_AS_U32(fVar33) - (int)ALBW_AS_U32(fVar43);
        }
        if (fVar33 == fVar43 || iVar6 < 0 != SBORROW4((int)ALBW_AS_U32(fVar33),(int)ALBW_AS_U32(fVar43))) break;
        if ((uint)ALBW_AS_U32(DAT_00645584) <
            (uint)ALBW_AS_U32((*pfVar7 * pfVar27[6] + pfVar7[1] * pfVar27[7] + pfVar7[2] * pfVar27[8])))
        goto LAB_00644650;
        uVar13 = uVar13 + 1;
      } while ((int)uVar13 < (int)uVar19);
    }
    if (((int)uVar13 < (int)uVar19) && (uVar12 = uVar19 - 1, (int)uVar13 <= (int)uVar12)) {
      pfVar23 = (float *)puVar16[2];
      do {
        pfVar7 = pfVar23;
        if (uVar12 - 1 < uVar19) {
          pfVar7 = pfVar23 + (uVar12 - 1) * 0x27;
        }
        pfVar27 = pfVar23;
        if (uVar12 < uVar19) {
          pfVar27 = pfVar23 + uVar12 * 0x27;
        }
        fVar43 = pfVar7[7];
        iVar6 = (int)ALBW_AS_U32(fVar43) - (int)ALBW_AS_U32(DAT_00643d4c);
        if ((int)ALBW_AS_U32(fVar43) <= (int)ALBW_AS_U32(DAT_00643d4c)) {
          fVar43 = pfVar27[7];
          iVar6 = (int)ALBW_AS_U32(fVar43) - (int)ALBW_AS_U32(DAT_00643d4c);
        }
        if (fVar43 == DAT_00643d4c || iVar6 < 0 != SBORROW4((int)ALBW_AS_U32(fVar43),(int)ALBW_AS_U32(DAT_00643d4c))) break;
        if (DAT_00645588 <
            (float *******)CF_FBITS((*pfVar7 * pfVar27[6] + pfVar7[1] * pfVar27[7] + pfVar7[2] * pfVar27[8])))
        goto LAB_00644650;
        uVar12 = uVar12 - 1;
      } while ((int)uVar13 <= (int)uVar12);
    }
    goto LAB_00644704;
  }
LAB_00644988:
  pppppppppppfVar29 = local_1df4;
  fVar43 = ALBW_AS_F32(pppppppppfVar47) + ALBW_AS_F32(uVar49);
  fVar33 = ALBW_AS_F32(in_s1) + ALBW_AS_F32(uVar50);
  if (((*DAT_0064558c & 1) == 0) &&
     (iVar6 = func_00100174((int *)DAT_0064558c), pfVar23 = DAT_00645590, iVar6 != 0)) {
    pfVar7 = DAT_00645590 + 3;
    *DAT_00645590 = 0.0;
    pfVar23[1] = 0.0;
    pfVar23[2] = 0.0;
    func_0010B3EC((undefined4 *)(pfVar23),0x20,(int)pfVar7);
  }
  pfVar23 = DAT_00645590;
  uVar59 = uVar51 & 0xffffffff;
  *DAT_00645590 = 0.0;
  ppppppppppfVar9 = (float **********)0x0;
  fVar48 = ALBW_AS_F32(uVar51) / (ALBW_AS_F32(uVar49) - fVar43);
  fVar53 = ALBW_AS_F32((uVar51 >> 0x20));
  local_1edc = (float)(fVar48 * fVar53);
  local_1ed4 = (float ************)CF_FBITS((fVar53 + fVar43 * fVar48 * fVar45));
  fVar43 = ALBW_AS_F32(uVar51) / (ALBW_AS_F32(uVar50) - fVar33);
  local_1ee0 = (float ***********)CF_FBITS((fVar43 * fVar45));
  local_1ed8 = (float ***********)CF_FBITS((fVar53 + fVar33 * fVar43 * fVar53));
  if (0 < (int)*pppppppppppfVar29) {
    do {
      if (ppppppppppfVar9 < *pppppppppppfVar29) {
        ppppppppppfVar41 = pppppppppppfVar29[2] + (int)ppppppppppfVar9 * 0x27;
      }
      else {
        ppppppppppfVar41 = pppppppppppfVar29[2];
      }
      ppppppppppfVar41[0x1c] =
           (float *********)
           CF_FBITS((ALBW_AS_F32((&local_1ed8)[*(char *)(ppppppppppfVar41 + 0x24)]) +
           ALBW_AS_F32((&local_1ee0)[*(char *)(ppppppppppfVar41 + 0x24)]) * ALBW_AS_F32(ppppppppppfVar41[0x1c])))
      ;
      pppppppppfVar26 =
           (float *********)
           CF_FBITS((ALBW_AS_F32((&local_1ed8)[*(char *)(ppppppppppfVar41 + 0x24)]) +
           ALBW_AS_F32((&local_1ee0)[*(char *)(ppppppppppfVar41 + 0x24)]) * ALBW_AS_F32(ppppppppppfVar41[0x1d])))
      ;
      ppppppppppfVar41[0x1d] = pppppppppfVar26;
      if (ALBW_AS_F32(pppppppppfVar26) < ALBW_AS_F32(ppppppppppfVar41[0x1c])) {
        pppppppppfVar47 = ppppppppppfVar41[9];
        pppppppppfVar26 = ppppppppppfVar41[10];
        pppppppppfVar10 = ppppppppppfVar41[0xb];
        ppppppppppfVar41[9] = ppppppppppfVar41[0xc];
        ppppppppppfVar41[10] = ppppppppppfVar41[0xd];
        ppppppppppfVar41[0xb] = ppppppppppfVar41[0xe];
        ppppppppppfVar41[0xc] = pppppppppfVar47;
        ppppppppppfVar41[0xd] = pppppppppfVar26;
        ppppppppppfVar41[0xe] = pppppppppfVar10;
        pppppppppfVar26 = ppppppppppfVar41[0x1c];
        ppppppppppfVar41[0x1c] = ppppppppppfVar41[0x1d];
        ppppppppppfVar41[0x1d] = pppppppppfVar26;
      }
      ppppppppppfVar41[0xf] = ppppppppppfVar41[9];
      ppppppppppfVar41[0x10] = ppppppppppfVar41[10];
      ppppppppppfVar41[0x11] = ppppppppppfVar41[0xb];
      ppppppppppfVar41[0x12] = ppppppppppfVar41[0xc];
      ppppppppppfVar41[0x13] = ppppppppppfVar41[0xd];
      ppppppppppfVar41[0x14] = ppppppppppfVar41[0xe];
      *(undefined1 *)((int)ppppppppppfVar41 + 0x92) = 0;
      *(undefined1 *)((int)ppppppppppfVar41 + 0x91) = 0;
      ppppppppppfVar41[0x1b] = (float *********)(uVar50 >> 0x20);
      *(undefined1 *)(ppppppppppfVar41 + 0x26) = 0;
      *(undefined1 *)((int)ppppppppppfVar41 + 0x97) = 0;
      *(undefined1 *)((int)ppppppppppfVar41 + 0x95) = 0;
      *(undefined1 *)(ppppppppppfVar41 + 0x25) = 0;
      if (*(char *)(ppppppppppfVar41 + 0x24) == '\0') {
        func_00115D70((float *)ppppppppppfVar41,(float *)ppppppppppfVar41,
                      ALBW_AS_F32(((ulonglong)uVar49 >> 0x20)));
        func_00115D70((float *)(ppppppppppfVar41 + 3),(float *)(ppppppppppfVar41 + 3),
                      ALBW_AS_F32(((ulonglong)uVar49 >> 0x20)));
      }
      ppppppppppfVar9 = (float **********)((int)ppppppppppfVar9 + 1);
    } while ((int)ppppppppppfVar9 < (int)*pppppppppppfVar29);
  }
  ppppppppppfVar9 = (float **********)0x0;
  if (0 < (int)*pppppppppppfVar29) {
    do {
      pfVar7 = DAT_00645590;
      if (ppppppppppfVar9 < *pppppppppppfVar29) {
        ppppppppppfVar41 = pppppppppppfVar29[2] + (int)ppppppppppfVar9 * 0x27;
        ppppppppppfVar17 = pppppppppppfVar29[2] + (int)ppppppppppfVar9 * 0x27;
      }
      else {
        ppppppppppfVar41 = pppppppppppfVar29[2];
        ppppppppppfVar17 = pppppppppppfVar29[2];
      }
      if ((0xb4000000 < (uint)ALBW_AS_U32(ALBW_AS_F32(ppppppppppfVar41[0x1c]) - ALBW_AS_F32(ppppppppppfVar17[0x1d]))) ||
         (0x34000000 < (int)ALBW_AS_U32(ALBW_AS_F32(ppppppppppfVar41[0x1c]) - ALBW_AS_F32(ppppppppppfVar17[0x1d])))) {
        if (ppppppppppfVar9 < *pppppppppppfVar29) {
          ppppppppppfVar41 = pppppppppppfVar29[2] + (int)ppppppppppfVar9 * 0x27;
        }
        else {
          ppppppppppfVar41 = pppppppppppfVar29[2];
        }
        if ((int)ALBW_AS_U32(*DAT_00645590) < (int)ALBW_AS_U32(DAT_00645590[1])) {
          *(float ***********)((int)ALBW_AS_U32(DAT_00645590[2]) + (int)ALBW_AS_U32(*DAT_00645590) * 4) = ppppppppppfVar41;
          *pfVar7 = ALBW_AS_F32(((int)ALBW_AS_U32(*pfVar7) + 1));
        }
      }
      ppppppppppfVar9 = (float **********)((int)ppppppppppfVar9 + 1);
    } while ((int)ppppppppppfVar9 < (int)*pppppppppppfVar29);
  }
  *pppppppppppfVar29 = (float **********)0x0;
  if (*pfVar23 != 0.0) {
    func_0048C258((int *)DAT_00645590,DAT_0064430c);
    if (((*DAT_00645594 & 1) == 0) &&
       (iVar6 = func_00100174((int *)DAT_00645594), puVar3 = DAT_00645598, iVar6 != 0)) {
      puVar16 = DAT_00645598 + 3;
      *DAT_00645598 = 0;
      puVar3[1] = 0x30;
      puVar3[2] = (uint)puVar16;
      func_00100118((int)(puVar3 + 3),DAT_00644318,0x9c,0x30);
    }
    puVar3 = DAT_00645598;
    *DAT_00645598 = 0;
    if (*pfVar23 == 0.0) {
      puVar11 = (undefined4 *)0x0;
    }
    else {
      puVar11 = *(undefined4 **)CF_FBITS(pfVar23[2]);
    }
    if (0 < (int)puVar3[1]) {
      *puVar3 = 1;
      func_001FE514((undefined4 *)puVar3[2],puVar11);
    }
    fVar43 = *pfVar23;
    iVar6 = *puVar3 * 0x9c + -0x9c + puVar3[2];
    puVar11 = (undefined4 *)0x1;
    if (1 < (int)ALBW_AS_U32(fVar43)) {
      do {
        puVar14 = (undefined4 *)CF_FBITS(*pfVar23);
        if (puVar11 < puVar14) {
          fVar43 = pfVar23[2];
          puVar15 = puVar14;
        }
        else {
          puVar15 = (undefined4 *)0x0;
        }
        if (puVar11 < puVar14) {
          puVar15 = *(undefined4 **)((int)ALBW_AS_U32(fVar43) + (int)puVar11 * 4);
        }
        fVar43 = *(float *)(iVar6 + 0x18) * ALBW_AS_F32(puVar15[6]) +
                 *(float *)(iVar6 + 0x1c) * ALBW_AS_F32(puVar15[7]) +
                 *(float *)(iVar6 + 0x20) * ALBW_AS_F32(puVar15[8]);
        if (fVar43 <= ALBW_AS_F32((uVar50 >> 0x20))) {
          fVar43 = -fVar43;
        }
        if (DAT_0064431c < (int)ALBW_AS_U32(fVar43)) {
          if (*(float *)(iVar6 + 0x74) < ALBW_AS_F32(puVar15[0x1d])) {
            *(undefined4 *)(iVar6 + 0x30) = puVar15[0xc];
            *(undefined4 *)(iVar6 + 0x34) = puVar15[0xd];
            *(undefined4 *)(iVar6 + 0x38) = puVar15[0xe];
            *(undefined4 *)(iVar6 + 0x74) = puVar15[0x1d];
            *(undefined4 *)(iVar6 + 0x48) = puVar15[0x12];
            *(undefined4 *)(iVar6 + 0x4c) = puVar15[0x13];
            *(undefined4 *)(iVar6 + 0x50) = puVar15[0x14];
          }
        }
        else {
          uVar19 = *puVar3;
          if ((int)uVar19 < (int)puVar3[1]) {
            *puVar3 = uVar19 + 1;
            puVar14 = (undefined4 *)(puVar3[2] + uVar19 * 0x9c);
            *puVar14 = *puVar15;
            puVar14[1] = puVar15[1];
            puVar14[2] = puVar15[2];
            local_1e8c = (float ***********)(puVar14 + 0xf);
            puVar14[3] = puVar15[3];
            local_1e80 = (float ***********)(puVar14 + 0x15);
            puVar14[4] = puVar15[4];
            puVar14[5] = puVar15[5];
            puVar14[6] = puVar15[6];
            puVar14[7] = puVar15[7];
            local_1e74 = (float ************)(puVar15 + 0x15);
            puVar14[8] = puVar15[8];
            puVar14[9] = puVar15[9];
            puVar14[10] = puVar15[10];
            puVar14[0xb] = puVar15[0xb];
            puVar14[0xc] = puVar15[0xc];
            puVar14[0xd] = puVar15[0xd];
            puVar14[0xe] = puVar15[0xe];
            *local_1e8c = (float **********)puVar15[0xf];
            puVar14[0x10] = puVar15[0x10];
            puVar14[0x11] = puVar15[0x11];
            puVar14[0x12] = puVar15[0x12];
            puVar14[0x13] = puVar15[0x13];
            puVar14[0x14] = puVar15[0x14];
            *local_1e80 = (float **********)*local_1e74;
            puVar14[0x16] = puVar15[0x16];
            puVar14[0x17] = puVar15[0x17];
            puVar14[0x18] = puVar15[0x18];
            puVar14[0x19] = puVar15[0x19];
            puVar14[0x1a] = puVar15[0x1a];
            puVar14[0x1b] = puVar15[0x1b];
            puVar14[0x1c] = puVar15[0x1c];
            puVar14[0x1d] = puVar15[0x1d];
            puVar14[0x1e] = puVar15[0x1e];
            puVar14[0x1f] = puVar15[0x1f];
            puVar14[0x20] = puVar15[0x20];
            puVar14[0x21] = puVar15[0x21];
            puVar14[0x22] = puVar15[0x22];
            puVar14[0x23] = puVar15[0x23];
            *(undefined1 *)(puVar14 + 0x24) = *(undefined1 *)(puVar15 + 0x24);
            *(undefined1 *)((int)puVar14 + 0x91) = *(undefined1 *)((int)puVar15 + 0x91);
            *(undefined1 *)((int)puVar14 + 0x92) = *(undefined1 *)((int)puVar15 + 0x92);
            *(undefined1 *)((int)puVar14 + 0x93) = *(undefined1 *)((int)puVar15 + 0x93);
            *(undefined1 *)(puVar14 + 0x25) = *(undefined1 *)(puVar15 + 0x25);
            *(undefined1 *)((int)puVar14 + 0x95) = *(undefined1 *)((int)puVar15 + 0x95);
            *(undefined1 *)((int)puVar14 + 0x96) = *(undefined1 *)((int)puVar15 + 0x96);
            *(undefined1 *)((int)puVar14 + 0x97) = *(undefined1 *)((int)puVar15 + 0x97);
            *(undefined1 *)(puVar14 + 0x26) = *(undefined1 *)(puVar15 + 0x26);
          }
          fVar43 = ALBW_AS_F32(puVar3[2]);
          iVar6 = *puVar3 * 0x9c + -0x9c + (int)ALBW_AS_U32(fVar43);
        }
        puVar11 = (undefined4 *)((int)puVar11 + 1);
      } while ((int)puVar11 < (int)ALBW_AS_U32(*pfVar23));
    }
    uVar19 = *puVar3;
    local_1e78 = (float ***********)0x0;
    uVar13 = 1;
    if (1 < (int)uVar19) {
      pfVar23 = (float *)puVar3[2];
      do {
        pfVar7 = pfVar23;
        if (uVar13 - 1 < uVar19) {
          pfVar7 = pfVar23 + (uVar13 - 1) * 0x27;
        }
        pfVar27 = pfVar23;
        if (uVar13 < uVar19) {
          pfVar27 = pfVar23 + uVar13 * 0x27;
        }
        pppppfVar34 = (float *****)CF_FBITS(pfVar7[7]);
        iVar6 = (int)pppppfVar34 - (int)DAT_0064559c;
        if ((int)pppppfVar34 <= (int)DAT_0064559c) {
          pppppfVar34 = (float *****)CF_FBITS(pfVar27[7]);
          iVar6 = (int)pppppfVar34 - (int)DAT_0064559c;
        }
        if (pppppfVar34 == DAT_0064559c || iVar6 < 0 != SBORROW4((int)pppppfVar34,(int)DAT_0064559c)
           ) break;
        if ((int)DAT_0064559c <
            (int)ALBW_AS_U32((*pfVar7 * pfVar27[6] + pfVar7[1] * pfVar27[7] + pfVar7[2] * pfVar27[8])))
        goto LAB_006450b0;
        uVar13 = uVar13 + 1;
      } while ((int)uVar13 < (int)uVar19);
    }
    if (((int)uVar13 < (int)uVar19) && (uVar12 = uVar19 - 1, (int)uVar13 <= (int)uVar12)) {
      pfVar23 = (float *)puVar3[2];
      do {
        pfVar7 = pfVar23;
        if (uVar12 - 1 < uVar19) {
          pfVar7 = pfVar23 + (uVar12 - 1) * 0x27;
        }
        pfVar27 = pfVar23;
        if (uVar12 < uVar19) {
          pfVar27 = pfVar23 + uVar12 * 0x27;
        }
        pppppfVar34 = (float *****)CF_FBITS(pfVar7[7]);
        iVar6 = (int)pppppfVar34 - (int)DAT_0064559c;
        if ((int)pppppfVar34 <= (int)DAT_0064559c) {
          pppppfVar34 = (float *****)CF_FBITS(pfVar27[7]);
          iVar6 = (int)pppppfVar34 - (int)DAT_0064559c;
        }
        if (pppppfVar34 == DAT_0064559c || iVar6 < 0 != SBORROW4((int)pppppfVar34,(int)DAT_0064559c)
           ) break;
        if (DAT_006455a0 <
            (int)ALBW_AS_U32((*pfVar7 * pfVar27[6] + pfVar7[1] * pfVar27[7] + pfVar7[2] * pfVar27[8])))
        goto LAB_006450b0;
        uVar12 = uVar12 - 1;
      } while ((int)uVar13 <= (int)uVar12);
    }
LAB_00645164:
    uVar19 = 0;
    if (0 < (int)*DAT_00645598) {
      do {
        puVar3 = DAT_00645598;
        uVar13 = DAT_00645598[2];
        if (uVar19 < *DAT_00645598) {
          uVar13 = uVar13 + uVar19 * 0x9c;
        }
        *(undefined1 *)(uVar13 + 0x93) = 0;
        puVar11 = (undefined4 *)puVar3[2];
        if (uVar19 < *puVar3) {
          puVar11 = puVar11 + uVar19 * 0x27;
        }
        ppppppppppfVar9 = *pppppppppppfVar29;
        if ((int)ppppppppppfVar9 < (int)pppppppppppfVar29[1]) {
          *pppppppppppfVar29 = (float **********)((int)ppppppppppfVar9 + 1);
          local_1ecc = (float ***********)(puVar11 + 0xf);
          ppppppppppfVar9 = pppppppppppfVar29[2] + (int)ppppppppppfVar9 * 0x27;
          *ppppppppppfVar9 = (float *********)*puVar11;
          local_1e8c = (float ***********)(ppppppppppfVar9 + 9);
          local_1e7c = (float ***********)(ppppppppppfVar9 + 0xc);
          ppppppppppfVar9[1] = (float *********)puVar11[1];
          ppppppppppfVar9[2] = (float *********)puVar11[2];
          ppppppppppfVar9[3] = (float *********)puVar11[3];
          ppppppppppfVar9[4] = (float *********)puVar11[4];
          ppppppppppfVar9[5] = (float *********)puVar11[5];
          ppppppppppfVar9[6] = (float *********)puVar11[6];
          ppppppppppfVar9[7] = (float *********)puVar11[7];
          ppppppppppfVar9[8] = (float *********)puVar11[8];
          *local_1e8c = (float **********)puVar11[9];
          ppppppppppfVar9[10] = (float *********)puVar11[10];
          ppppppppppfVar9[0xb] = (float *********)puVar11[0xb];
          *local_1e7c = (float **********)puVar11[0xc];
          ppppppppppfVar9[0xd] = (float *********)puVar11[0xd];
          ppppppppppfVar9[0xe] = (float *********)puVar11[0xe];
          ppppppppppfVar9[0xf] = (float *********)*local_1ecc;
          ppppppppppfVar9[0x10] = (float *********)puVar11[0x10];
          ppppppppppfVar9[0x11] = (float *********)puVar11[0x11];
          ppppppppppfVar9[0x12] = (float *********)puVar11[0x12];
          ppppppppppfVar9[0x13] = (float *********)puVar11[0x13];
          ppppppppppfVar9[0x14] = (float *********)puVar11[0x14];
          ppppppppppfVar9[0x15] = (float *********)puVar11[0x15];
          ppppppppppfVar9[0x16] = (float *********)puVar11[0x16];
          ppppppppppfVar9[0x17] = (float *********)puVar11[0x17];
          ppppppppppfVar9[0x18] = (float *********)puVar11[0x18];
          ppppppppppfVar9[0x19] = (float *********)puVar11[0x19];
          ppppppppppfVar9[0x1a] = (float *********)puVar11[0x1a];
          ppppppppppfVar9[0x1b] = (float *********)puVar11[0x1b];
          ppppppppppfVar9[0x1c] = (float *********)puVar11[0x1c];
          ppppppppppfVar9[0x1d] = (float *********)puVar11[0x1d];
          ppppppppppfVar9[0x1e] = (float *********)puVar11[0x1e];
          ppppppppppfVar9[0x1f] = (float *********)puVar11[0x1f];
          ppppppppppfVar9[0x20] = (float *********)puVar11[0x20];
          ppppppppppfVar9[0x21] = (float *********)puVar11[0x21];
          ppppppppppfVar9[0x22] = (float *********)puVar11[0x22];
          ppppppppppfVar9[0x23] = (float *********)puVar11[0x23];
          *(undefined1 *)(ppppppppppfVar9 + 0x24) = *(undefined1 *)(puVar11 + 0x24);
          *(undefined1 *)((int)ppppppppppfVar9 + 0x91) = *(undefined1 *)((int)puVar11 + 0x91);
          *(undefined1 *)((int)ppppppppppfVar9 + 0x92) = *(undefined1 *)((int)puVar11 + 0x92);
          *(undefined1 *)((int)ppppppppppfVar9 + 0x93) = *(undefined1 *)((int)puVar11 + 0x93);
          *(undefined1 *)(ppppppppppfVar9 + 0x25) = *(undefined1 *)(puVar11 + 0x25);
          *(undefined1 *)((int)ppppppppppfVar9 + 0x95) = *(undefined1 *)((int)puVar11 + 0x95);
          *(undefined1 *)((int)ppppppppppfVar9 + 0x96) = *(undefined1 *)((int)puVar11 + 0x96);
          *(undefined1 *)((int)ppppppppppfVar9 + 0x97) = *(undefined1 *)((int)puVar11 + 0x97);
          *(undefined1 *)(ppppppppppfVar9 + 0x26) = *(undefined1 *)(puVar11 + 0x26);
        }
        uVar19 = uVar19 + 1;
      } while ((int)uVar19 < (int)*DAT_00645598);
    }
    if (local_1e78 != (float ***********)0x0) {
      local_1ed0 = (float ***********)((uint)local_1ed0 | 2);
    }
  }
  pppppppppppfVar29 = local_1df4;
  local_1ec8 = (float ************)local_30;
  local_1e90 = (float ************)local_1ed0;
  local_1ec4 = local_30 + 0x29;
  if (((*DAT_006455a4 & 1) == 0) &&
     (iVar6 = func_00100174((int *)DAT_006455a4), piVar1 = DAT_006455a8, iVar6 != 0)) {
    piVar20 = DAT_006455a8 + 3;
    *DAT_006455a8 = 0;
    piVar1[1] = 0x30;
    piVar1[2] = (int)piVar20;
    func_00100118((int)(piVar1 + 3),DAT_006455ac,0x9c,0x30);
  }
  pppppppppppfVar36 = (float ***********)0x0;
  *DAT_006455a8 = 0;
  local_1ecc = (float ***********)0x0;
  if (0 < (int)*local_1ec4) {
LAB_00645490:
    iVar6 = DAT_006455b0;
    local_1edc = ALBW_AS_F32(local_1e90);
    if (local_1ecc < *local_1ec4) {
      ppppppppppfVar9 = local_1ec4[2] + (int)local_1ecc * 0x27;
    }
    else {
      ppppppppppfVar9 = local_1ec4[2];
    }
    pppppppppppfVar54 = (float ***********)*pppppppppppfVar29;
    if ((int)pppppppppppfVar36 < (int)pppppppppppfVar54) {
      uVar51 = uVar50 >> 0x20;
      pppppppppppfVar8 = pppppppppppfVar36;
      do {
        ppppppppppfVar41 = pppppppppppfVar29[2];
        if (pppppppppppfVar8 < pppppppppppfVar54) {
          ppppppppppfVar41 = ppppppppppfVar41 + (int)pppppppppppfVar8 * 0x27;
        }
        fVar43 = ALBW_AS_F32(ppppppppppfVar9[6]) * ALBW_AS_F32(ppppppppppfVar41[6]) +
                 ALBW_AS_F32(ppppppppppfVar9[7]) * ALBW_AS_F32(ppppppppppfVar41[7]) +
                 ALBW_AS_F32(ppppppppppfVar9[8]) * ALBW_AS_F32(ppppppppppfVar41[8]);
        if (fVar43 <= ALBW_AS_F32(uVar51)) {
          fVar43 = -fVar43;
        }
        if (iVar6 < (int)ALBW_AS_U32(fVar43)) {
          func_00115C70((float *)&local_1e8c,(float *)(ppppppppppfVar9 + 9),
                        (float *)(ppppppppppfVar41 + 9));
          fVar43 = ALBW_AS_F32(ppppppppppfVar9[6]) * ALBW_AS_F32(local_1e8c) +
                   ALBW_AS_F32(ppppppppppfVar9[7]) * ALBW_AS_F32(local_1e88) +
                   ALBW_AS_F32(ppppppppppfVar9[8]) * ALBW_AS_F32(local_1e84);
          if (fVar43 <= ALBW_AS_F32(uVar51)) {
            fVar43 = -fVar43;
          }
          if ((int)ALBW_AS_U32(fVar43) < DAT_006455a0) {
            local_1ee4 = pppppppppppfVar8;
            if (-1 < (int)pppppppppppfVar8) goto joined_r0x0064571c;
            break;
          }
        }
        pppppppppppfVar54 = (float ***********)*pppppppppppfVar29;
        pppppppppppfVar8 = (float ***********)((int)pppppppppppfVar8 + 1);
      } while ((int)pppppppppppfVar8 < (int)pppppppppppfVar54);
    }
    pppppppppfVar26 = (float *********)(uVar50 >> 0x20);
    ppppppppppfVar9[0x1f] = pppppppppfVar26;
    ppppppppppfVar9[0x1e] = pppppppppfVar26;
    func_00115D70((float *)&local_1e5c,(float *)(ppppppppppfVar9 + 3),ALBW_AS_F32(local_1ec8[0x1c]));
    local_1e68 = local_1e5c;
    local_1e64 = local_1e58;
    local_1e60 = local_1e54;
    func_00115D88((float *)&local_1e38,(float *)&local_1e68,ALBW_AS_F32(ppppppppppfVar9[4]));
    local_1e74 = (float ************)local_1e38;
    local_1e70 = local_1e34;
    local_1e6c = local_1e30;
    func_00115C54((float *)&local_1e44,(float *)(ppppppppppfVar9 + 9),(float *)&local_1e74);
    local_1e80 = local_1e44;
    local_1e7c = local_1e40;
    local_1e78 = local_1e3c;
    ppppppppppfVar9[0x15] = (float *********)local_1e44;
    ppppppppppfVar9[0x16] = (float *********)local_1e40;
    ppppppppppfVar9[0x17] = (float *********)local_1e3c;
    func_00115D70((float *)&local_1e50,(float *)(ppppppppppfVar9 + 3),ALBW_AS_F32(local_1ec8[0x1c]));
    local_1e68 = local_1e50;
    local_1e64 = local_1e4c;
    local_1e60 = local_1e48;
    func_00115D88((float *)&local_1e20,(float *)&local_1e68,ALBW_AS_F32(ppppppppppfVar9[4]));
    local_1e80 = local_1e20;
    local_1e7c = local_1e1c;
    local_1e78 = local_1e18;
    func_00115C54((float *)&local_1e2c,(float *)(ppppppppppfVar9 + 0xc),(float *)&local_1e80);
    local_1e74 = (float ************)local_1e2c;
    local_1e70 = local_1e28;
    local_1e6c = local_1e24;
    ppppppppppfVar9[0x18] = (float *********)local_1e2c;
    ppppppppppfVar9[0x19] = (float *********)local_1e28;
    ppppppppppfVar9[0x1a] = (float *********)local_1e24;
    *(undefined1 *)(ppppppppppfVar9 + 0x26) = 1;
    iVar6 = *DAT_006455a8;
    if (iVar6 < DAT_006455a8[1]) {
      piVar1 = DAT_006455a8 + 2;
      *DAT_006455a8 = iVar6 + 1;
      func_001FE514((undefined4 *)(*piVar1 + iVar6 * 0x9c),(undefined4 *)(ppppppppppfVar9));
    }
    goto LAB_00645ef0;
  }
LAB_00645f0c:
  pppppppppppfVar54 = local_30;
  fVar43 = ALBW_AS_F32((uVar50 >> 0x20));
  ppppppppppfVar9 = *local_1ec4;
  ppppppppppfVar41 = local_1ec4[2];
  pppppppppppfVar8 = (float ***********)*pppppppppppfVar29;
  bVar40 = pppppppppppfVar36 <= pppppppppppfVar8;
  bVar39 = pppppppppppfVar8 == pppppppppppfVar36;
  if ((int)pppppppppppfVar36 < (int)pppppppppppfVar8) {
    do {
      if (!bVar40 || bVar39) {
        ppppppppppfVar17 = pppppppppppfVar29[2];
      }
      else {
        ppppppppppfVar17 = pppppppppppfVar29[2] + (int)pppppppppppfVar36 * 0x27;
      }
      ppppppppppfVar17[0x1e] = ppppppppppfVar41[(int)ppppppppppfVar9 * 0x27 + -10];
      ppppppppppfVar17[0x1f] = ppppppppppfVar41[(int)ppppppppppfVar9 * 0x27 + -10];
      ppppppppppfVar17[0x15] = ppppppppppfVar41[(int)ppppppppppfVar9 * 0x27 + -0x15];
      ppppppppppfVar17[0x16] = ppppppppppfVar41[(int)ppppppppppfVar9 * 0x27 + -0x14];
      ppppppppppfVar17[0x17] = ppppppppppfVar41[(int)ppppppppppfVar9 * 0x27 + -0x13];
      ppppppppppfVar17[0x18] = ppppppppppfVar41[(int)ppppppppppfVar9 * 0x27 + -0x15];
      ppppppppppfVar17[0x19] = ppppppppppfVar41[(int)ppppppppppfVar9 * 0x27 + -0x14];
      ppppppppppfVar17[0x1a] = ppppppppppfVar41[(int)ppppppppppfVar9 * 0x27 + -0x13];
      *(undefined1 *)((int)ppppppppppfVar17 + 0x97) = 1;
      if (pppppppppppfVar36 < *pppppppppppfVar29) {
        ppppppppppfVar17 = pppppppppppfVar29[2] + (int)pppppppppppfVar36 * 0x27;
      }
      else {
        ppppppppppfVar17 = pppppppppppfVar29[2];
      }
      iVar6 = *DAT_006455a8;
      if (iVar6 < DAT_006455a8[1]) {
        piVar1 = DAT_006455a8 + 2;
        *DAT_006455a8 = iVar6 + 1;
        puVar11 = (undefined4 *)(*piVar1 + iVar6 * 0x9c);
        local_1ecc = (float ***********)(puVar11 + 6);
        *puVar11 = (undefined4)(uintptr_t)(*ppppppppppfVar17);
        local_1edc = ALBW_AS_F32((puVar11 + 0xc));
        puVar11[1] = (undefined4)(uintptr_t)(ppppppppppfVar17[1]);
        local_1e88 = (float ***********)(ppppppppppfVar17 + 0xf);
        local_1ed4 = (float ************)(puVar11 + 0xf);
        puVar11[2] = (undefined4)(uintptr_t)(ppppppppppfVar17[2]);
        puVar11[3] = (undefined4)(uintptr_t)(ppppppppppfVar17[3]);
        puVar11[4] = (undefined4)(uintptr_t)(ppppppppppfVar17[4]);
        puVar11[5] = (undefined4)(uintptr_t)(ppppppppppfVar17[5]);
        *local_1ecc = (float **********)ppppppppppfVar17[6];
        puVar11[7] = (undefined4)(uintptr_t)(ppppppppppfVar17[7]);
        puVar11[8] = (undefined4)(uintptr_t)(ppppppppppfVar17[8]);
        puVar11[9] = (undefined4)(uintptr_t)(ppppppppppfVar17[9]);
        puVar11[10] = (undefined4)(uintptr_t)(ppppppppppfVar17[10]);
        puVar11[0xb] = (undefined4)(uintptr_t)(ppppppppppfVar17[0xb]);
        *(float **********)CF_FBITS(local_1edc) = ppppppppppfVar17[0xc];
        puVar11[0xd] = (undefined4)(uintptr_t)(ppppppppppfVar17[0xd]);
        puVar11[0xe] = (undefined4)(uintptr_t)(ppppppppppfVar17[0xe]);
        *local_1ed4 = (float ***********)*local_1e88;
        puVar11[0x10] = (undefined4)(uintptr_t)(ppppppppppfVar17[0x10]);
        puVar11[0x11] = (undefined4)(uintptr_t)(ppppppppppfVar17[0x11]);
        puVar11[0x12] = (undefined4)(uintptr_t)(ppppppppppfVar17[0x12]);
        puVar11[0x13] = (undefined4)(uintptr_t)(ppppppppppfVar17[0x13]);
        puVar11[0x14] = (undefined4)(uintptr_t)(ppppppppppfVar17[0x14]);
        puVar11[0x15] = (undefined4)(uintptr_t)(ppppppppppfVar17[0x15]);
        puVar11[0x16] = (undefined4)(uintptr_t)(ppppppppppfVar17[0x16]);
        puVar11[0x17] = (undefined4)(uintptr_t)(ppppppppppfVar17[0x17]);
        puVar11[0x18] = (undefined4)(uintptr_t)(ppppppppppfVar17[0x18]);
        puVar11[0x19] = (undefined4)(uintptr_t)(ppppppppppfVar17[0x19]);
        puVar11[0x1a] = (undefined4)(uintptr_t)(ppppppppppfVar17[0x1a]);
        puVar11[0x1b] = (undefined4)(uintptr_t)(ppppppppppfVar17[0x1b]);
        puVar11[0x1c] = (undefined4)(uintptr_t)(ppppppppppfVar17[0x1c]);
        puVar11[0x1d] = (undefined4)(uintptr_t)(ppppppppppfVar17[0x1d]);
        puVar11[0x1e] = (undefined4)(uintptr_t)(ppppppppppfVar17[0x1e]);
        puVar11[0x1f] = (undefined4)(uintptr_t)(ppppppppppfVar17[0x1f]);
        puVar11[0x20] = (undefined4)(uintptr_t)(ppppppppppfVar17[0x20]);
        puVar11[0x21] = (undefined4)(uintptr_t)(ppppppppppfVar17[0x21]);
        puVar11[0x22] = (undefined4)(uintptr_t)(ppppppppppfVar17[0x22]);
        puVar11[0x23] = (undefined4)(uintptr_t)(ppppppppppfVar17[0x23]);
        *(undefined1 *)(puVar11 + 0x24) = *(undefined1 *)(ppppppppppfVar17 + 0x24);
        *(undefined1 *)((int)puVar11 + 0x91) = *(undefined1 *)((int)ppppppppppfVar17 + 0x91);
        *(undefined1 *)((int)puVar11 + 0x92) = *(undefined1 *)((int)ppppppppppfVar17 + 0x92);
        *(undefined1 *)((int)puVar11 + 0x93) = *(undefined1 *)((int)ppppppppppfVar17 + 0x93);
        *(undefined1 *)(puVar11 + 0x25) = *(undefined1 *)(ppppppppppfVar17 + 0x25);
        *(undefined1 *)((int)puVar11 + 0x95) = *(undefined1 *)((int)ppppppppppfVar17 + 0x95);
        *(undefined1 *)((int)puVar11 + 0x96) = *(undefined1 *)((int)ppppppppppfVar17 + 0x96);
        *(undefined1 *)((int)puVar11 + 0x97) = *(undefined1 *)((int)ppppppppppfVar17 + 0x97);
        *(undefined1 *)(puVar11 + 0x26) = *(undefined1 *)(ppppppppppfVar17 + 0x26);
      }
      pppppppppppfVar8 = (float ***********)*pppppppppppfVar29;
      pppppppppppfVar36 = (float ***********)((int)pppppppppppfVar36 + 1);
      bVar40 = pppppppppppfVar36 <= pppppppppppfVar8;
      bVar39 = pppppppppppfVar8 == pppppppppppfVar36;
    } while (!bVar39 && (int)pppppppppppfVar36 <= (int)pppppppppppfVar8);
  }
  pppppppppppfVar29 = (float ***********)0x0;
  local_1ec8[0x29] = (float ***********)0x0;
  pppppppppppfVar36 = (float ***********)*DAT_006455a8;
  if (0 < (int)pppppppppppfVar36) {
    do {
      pppppppppppfVar36 = (float ***********)DAT_006455a8[2];
      if (pppppppppppfVar29 < (float ***********)*DAT_006455a8) {
        pppppppppppfVar36 = pppppppppppfVar36 + (int)pppppppppppfVar29 * 0x27;
      }
      ppppppppppfVar9 = (float **********)local_1ec8[0x29];
      if ((int)ppppppppppfVar9 < (int)local_1ec8[0x2a]) {
        local_1ec8[0x29] = (float ***********)((int)ppppppppppfVar9 + 1);
        local_1e88 = pppppppppppfVar36 + 0xf;
        ppppppppppfVar9 = (float **********)(local_1ec8[0x2b] + (int)ppppppppppfVar9 * 0x27);
        *ppppppppppfVar9 = (float *********)*pppppppppppfVar36;
        local_1edc = ALBW_AS_F32((ppppppppppfVar9 + 0xc));
        ppppppppppfVar9[1] = (float *********)pppppppppppfVar36[1];
        ppppppppppfVar9[2] = (float *********)pppppppppppfVar36[2];
        ppppppppppfVar9[3] = (float *********)pppppppppppfVar36[3];
        ppppppppppfVar9[4] = (float *********)pppppppppppfVar36[4];
        ppppppppppfVar9[5] = (float *********)pppppppppppfVar36[5];
        ppppppppppfVar9[6] = (float *********)pppppppppppfVar36[6];
        ppppppppppfVar9[7] = (float *********)pppppppppppfVar36[7];
        ppppppppppfVar9[8] = (float *********)pppppppppppfVar36[8];
        ppppppppppfVar9[9] = (float *********)pppppppppppfVar36[9];
        ppppppppppfVar9[10] = (float *********)pppppppppppfVar36[10];
        ppppppppppfVar9[0xb] = (float *********)pppppppppppfVar36[0xb];
        *(float ***********)CF_FBITS(local_1edc) = pppppppppppfVar36[0xc];
        ppppppppppfVar9[0xd] = (float *********)pppppppppppfVar36[0xd];
        ppppppppppfVar9[0xe] = (float *********)pppppppppppfVar36[0xe];
        ppppppppppfVar9[0xf] = (float *********)*local_1e88;
        ppppppppppfVar9[0x10] = (float *********)pppppppppppfVar36[0x10];
        ppppppppppfVar9[0x11] = (float *********)pppppppppppfVar36[0x11];
        ppppppppppfVar9[0x12] = (float *********)pppppppppppfVar36[0x12];
        ppppppppppfVar9[0x13] = (float *********)pppppppppppfVar36[0x13];
        ppppppppppfVar9[0x14] = (float *********)pppppppppppfVar36[0x14];
        ppppppppppfVar9[0x15] = (float *********)pppppppppppfVar36[0x15];
        ppppppppppfVar9[0x16] = (float *********)pppppppppppfVar36[0x16];
        ppppppppppfVar9[0x17] = (float *********)pppppppppppfVar36[0x17];
        ppppppppppfVar9[0x18] = (float *********)pppppppppppfVar36[0x18];
        ppppppppppfVar9[0x19] = (float *********)pppppppppppfVar36[0x19];
        ppppppppppfVar9[0x1a] = (float *********)pppppppppppfVar36[0x1a];
        ppppppppppfVar9[0x1b] = (float *********)pppppppppppfVar36[0x1b];
        ppppppppppfVar9[0x1c] = (float *********)pppppppppppfVar36[0x1c];
        ppppppppppfVar9[0x1d] = (float *********)pppppppppppfVar36[0x1d];
        ppppppppppfVar9[0x1e] = (float *********)pppppppppppfVar36[0x1e];
        ppppppppppfVar9[0x1f] = (float *********)pppppppppppfVar36[0x1f];
        ppppppppppfVar9[0x20] = (float *********)pppppppppppfVar36[0x20];
        ppppppppppfVar9[0x21] = (float *********)pppppppppppfVar36[0x21];
        ppppppppppfVar9[0x22] = (float *********)pppppppppppfVar36[0x22];
        ppppppppppfVar9[0x23] = (float *********)pppppppppppfVar36[0x23];
        *(undefined1 *)(ppppppppppfVar9 + 0x24) = *(undefined1 *)(pppppppppppfVar36 + 0x24);
        *(undefined1 *)((int)ppppppppppfVar9 + 0x91) =
             *(undefined1 *)((int)pppppppppppfVar36 + 0x91);
        *(undefined1 *)((int)ppppppppppfVar9 + 0x92) =
             *(undefined1 *)((int)pppppppppppfVar36 + 0x92);
        *(undefined1 *)((int)ppppppppppfVar9 + 0x93) =
             *(undefined1 *)((int)pppppppppppfVar36 + 0x93);
        *(undefined1 *)(ppppppppppfVar9 + 0x25) = *(undefined1 *)(pppppppppppfVar36 + 0x25);
        *(undefined1 *)((int)ppppppppppfVar9 + 0x95) =
             *(undefined1 *)((int)pppppppppppfVar36 + 0x95);
        *(undefined1 *)((int)ppppppppppfVar9 + 0x96) =
             *(undefined1 *)((int)pppppppppppfVar36 + 0x96);
        *(undefined1 *)((int)ppppppppppfVar9 + 0x97) =
             *(undefined1 *)((int)pppppppppppfVar36 + 0x97);
        pppppppppppfVar8 = pppppppppppfVar36 + 0x26;
        pppppppppppfVar36 = (float ***********)(uint)*(byte *)pppppppppppfVar8;
        *(byte *)(ppppppppppfVar9 + 0x26) = *(byte *)pppppppppppfVar8;
      }
      pppppppppppfVar29 = (float ***********)((int)pppppppppppfVar29 + 1);
    } while ((int)pppppppppppfVar29 < *DAT_006455a8);
  }
  if (((uint)local_1ed0 & 1) != 0) {
    uVar51 = (ulonglong)(uint)ALBW_AS_U32(fVar43);
    ppppppppppfVar9 = (float **********)0x0;
    pppppppppppfVar37 = (float ***********)0x1;
    pppppppppppfVar35 = local_30 + 0x29;
    pppppppppppfVar8 = (float ***********)*pppppppppppfVar35;
    local_1e20 = (float ***********)0x0;
    local_1e1c = (float ***********)0x0;
    if (0 < (int)pppppppppppfVar8) {
      pppppppppppfVar29 = (float ***********)0x0;
      do {
        if (ppppppppppfVar9 < *pppppppppppfVar35) {
          pppppppppppfVar36 = (float ***********)(local_30[0x2b] + (int)ppppppppppfVar9 * 0x27);
        }
        else {
          pppppppppppfVar36 = (float ***********)local_30[0x2b];
        }
        ppppppppppfVar41 = local_30[0x2b];
        if (ppppppppppfVar9 < *pppppppppppfVar35) {
          ppppppppppfVar41 = ppppppppppfVar41 + (int)ppppppppppfVar9 * 0x27;
        }
        ppppppppppfVar9 = (float **********)((int)ppppppppppfVar9 + 1);
        *(undefined1 *)(ppppppppppfVar41 + 0x25) = 0;
        *(undefined1 *)((int)pppppppppppfVar36 + 0x95) = 0;
      } while ((int)ppppppppppfVar9 < (int)pppppppppppfVar8);
    }
    if (1 < (int)pppppppppppfVar8) {
      do {
        pppppfVar34 = DAT_0064559c;
        uVar58 = (undefined4)uVar51;
        uVar56 = (undefined4)(uVar50 >> 0x20);
        if ((float ***********)((int)pppppppppppfVar37 + -1) < *pppppppppppfVar35) {
          pppppppppppfVar29 = (float ***********)pppppppppppfVar54[0x2b];
          pppppppppppfVar28 = pppppppppppfVar29 + ((int)pppppppppppfVar37 + -1) * 0x27;
        }
        else {
          pppppppppppfVar28 = (float ***********)pppppppppppfVar54[0x2b];
        }
        if (pppppppppppfVar37 < *pppppppppppfVar35) {
          pppppppppppfVar29 = (float ***********)pppppppppppfVar54[0x2b];
          pppppppppppfVar32 = pppppppppppfVar29 + (int)pppppppppppfVar37 * 0x27;
        }
        else {
          pppppppppppfVar32 = (float ***********)pppppppppppfVar54[0x2b];
        }
        if ((((int)pppppppppppfVar28[7] <= (int)DAT_0064559c) &&
            (pppppppppppfVar36 = pppppppppppfVar37, (int)pppppppppppfVar32[7] <= (int)DAT_0064559c))
           || (pppppppppppfVar36 = (float ***********)DAT_00645588,
              (float *******)
              CF_FBITS((ALBW_AS_F32(*pppppppppppfVar28) * ALBW_AS_F32(pppppppppppfVar32[6]) +
               ALBW_AS_F32(pppppppppppfVar28[1]) * ALBW_AS_F32(pppppppppppfVar32[7]) +
              ALBW_AS_F32(pppppppppppfVar28[2]) * ALBW_AS_F32(pppppppppppfVar32[8]))) <= DAT_00645588)) break;
        fVar43 = ALBW_AS_F32(local_30[0x1c]) / ALBW_AS_F32(pppppppppppfVar28[4]);
        if (*(char *)((int)pppppppppppfVar28 + 0x93) == '\0') {
          pppppppppppfVar29 = pppppppppppfVar28 + 0x18;
        }
        else {
          pppppppppppfVar29 = pppppppppppfVar28 + 0xc;
        }
        fVar33 = ALBW_AS_F32(local_30[0x1c]) / ALBW_AS_F32(pppppppppppfVar32[4]);
        local_1e14 = pppppppppppfVar29;
        func_00115D70((float *)&local_1e68,(float *)(pppppppppppfVar28 + 3),fVar43);
        local_1e78 = local_1e68;
        local_1e74 = (float ************)local_1e64;
        local_1e70 = local_1e60;
        func_00115C54((float *)&local_1ef0,(float *)pppppppppppfVar29,(float *)&local_1e78);
        local_1e38 = local_1ef0;
        local_1e34 = local_1eec;
        local_1e30 = local_1ee8;
        local_1e90 = (float ************)local_1ef0;
        local_1e8c = local_1eec;
        local_1e88 = local_1ee8;
        if (*(char *)((int)pppppppppppfVar32 + 0x93) == '\0') {
          pppppppppppfVar29 = pppppppppppfVar32 + 0x15;
        }
        else {
          pppppppppppfVar29 = pppppppppppfVar32 + 9;
        }
        func_00115D70((float *)&local_1dec,(float *)(pppppppppppfVar32 + 3),fVar33);
        local_1e38 = local_1dec;
        local_1e34 = local_1de8;
        local_1e30 = local_1de4;
        func_00115C54((float *)&local_1e04,(float *)pppppppppppfVar29,(float *)&local_1e38);
        local_1e78 = local_1e04;
        local_1e74 = (float ************)local_1e00;
        local_1e70 = local_1dfc;
        local_1e5c = local_1e04;
        local_1e58 = local_1e00;
        local_1e54 = local_1dfc;
        uVar50 = CONCAT44(uVar56,ALBW_AS_F32(*pppppppppppfVar28) * ALBW_AS_F32(pppppppppppfVar32[6]) +
                                 ALBW_AS_F32(pppppppppppfVar28[1]) * ALBW_AS_F32(pppppppppppfVar32[7]) +
                                 ALBW_AS_F32(pppppppppppfVar28[2]) * ALBW_AS_F32(pppppppppppfVar32[8]));
        func_00115C70((float *)&local_1df8,(float *)&local_1e90,(float *)pppppppppppfVar29);
        fVar48 = (-(ALBW_AS_F32(pppppppppppfVar32[6]) * ALBW_AS_F32(local_1df8) +
                   ALBW_AS_F32(pppppppppppfVar32[7]) * ALBW_AS_F32(local_1df4)) +
                 -(ALBW_AS_F32(pppppppppppfVar32[8]) * ALBW_AS_F32(local_1df0))) / ALBW_AS_F32(uVar50);
        uVar51 = CONCAT44(fVar48,uVar58);
        if ((int)pppppfVar34 < (int)ALBW_AS_U32(fVar48)) {
          func_00115D70((float *)&local_1de0,(float *)pppppppppppfVar28,fVar48);
          local_1e68 = (float ***********)local_1de0;
          local_1e64 = local_1ddc;
          local_1e60 = local_1dd8;
          func_00115C54((float *)&local_1e10,(float *)&local_1e90,(float *)&local_1e68);
          pppppppppppfVar28[0x12] = (float **********)local_1e10;
          pppppppppppfVar28[0x13] = (float **********)local_1e0c;
          pppppppppppfVar28[0x14] = (float **********)local_1e08;
          if (*(char *)((int)pppppppppppfVar28 + 0x93) == '\x01') {
            func_00115D70((float *)&local_1dd4,(float *)(pppppppppppfVar28 + 3),
                          ALBW_AS_F32(((ulonglong)uVar49 >> 0x20)));
            local_1e78 = local_1dd4;
            local_1e74 = (float ************)local_1dd0;
            local_1e70 = local_1dcc;
            func_00115D70((float *)&local_1e50,(float *)&local_1e78,fVar43);
            local_1e44 = local_1e50;
            local_1e40 = local_1e4c;
            local_1e3c = local_1e48;
            func_00115C54((float *)(pppppppppppfVar28 + 0x12),(float *)(pppppppppppfVar28 + 0x12),
                          (float *)&local_1e44);
          }
          if (*(char *)((int)pppppppppppfVar28 + 0x93) == '\0') {
            func_00115C70((float *)&local_1e78,(float *)(pppppppppppfVar28 + 0x12),
                          (float *)(pppppppppppfVar28 + 0xc));
            pppppppppppfVar28[0x1b] =
                 (float **********)
                 CF_FBITS((ALBW_AS_F32(*pppppppppppfVar28) * ALBW_AS_F32(local_1e78) +
                  ALBW_AS_F32(pppppppppppfVar28[1]) * ALBW_AS_F32(local_1e74) +
                 ALBW_AS_F32(pppppppppppfVar28[2]) * ALBW_AS_F32(local_1e70)));
          }
          uVar51 = (ulonglong)(uint)ALBW_AS_U32((ALBW_AS_F32(uVar51) + ALBW_AS_F32((uVar51 >> 0x20))));
          *(undefined1 *)((int)pppppppppppfVar28 + 0x95) = 1;
        }
        uVar58 = (undefined4)uVar51;
        fVar43 = -(ALBW_AS_F32(*pppppppppppfVar32) * ALBW_AS_F32(pppppppppppfVar28[6]) +
                   ALBW_AS_F32(pppppppppppfVar32[1]) * ALBW_AS_F32(pppppppppppfVar28[7]) +
                  ALBW_AS_F32(pppppppppppfVar32[2]) * ALBW_AS_F32(pppppppppppfVar28[8]));
        pppppppppppfVar29 = local_1e14;
        func_00115C70((float *)&local_1e78,(float *)&local_1e5c,(float *)local_1e14);
        fVar43 = (-(ALBW_AS_F32(pppppppppppfVar28[6]) * ALBW_AS_F32(local_1e78) +
                   ALBW_AS_F32(pppppppppppfVar28[7]) * ALBW_AS_F32(local_1e74)) +
                 -(ALBW_AS_F32(pppppppppppfVar28[8]) * ALBW_AS_F32(local_1e70))) / fVar43;
        uVar51 = CONCAT44(fVar43,uVar58);
        pppppppppppfVar36 = extraout_r1;
        if ((int)pppppfVar34 < (int)ALBW_AS_U32(fVar43)) {
          func_00115D70((float *)&local_1e68,(float *)pppppppppppfVar32,fVar43);
          local_1e78 = local_1e68;
          local_1e74 = (float ************)local_1e64;
          local_1e70 = local_1e60;
          func_00115C70((float *)&local_1e68,(float *)&local_1e5c,(float *)&local_1e78);
          pppppppppppfVar32[0xf] = (float **********)local_1e68;
          pppppppppppfVar32[0x10] = (float **********)local_1e64;
          pppppppppppfVar32[0x11] = (float **********)local_1e60;
          pppppppppppfVar36 = local_1e64;
          pppppppppppfVar29 = local_1e60;
          if (*(char *)((int)pppppppppppfVar32 + 0x93) == '\x01') {
            func_00115D70((float *)&local_1e68,(float *)(pppppppppppfVar32 + 3),
                          ALBW_AS_F32(((ulonglong)uVar49 >> 0x20)));
            local_1e78 = local_1e68;
            local_1e74 = (float ************)local_1e64;
            local_1e70 = local_1e60;
            func_00115D70((float *)&local_1e68,(float *)&local_1e78,fVar33);
            pppppppppppfVar29 = (float ***********)&local_1eec;
            local_1eec = local_1e68;
            local_1ee8 = local_1e64;
            local_1ee4 = local_1e60;
            func_00115C54((float *)(pppppppppppfVar32 + 0xf),(float *)(pppppppppppfVar32 + 0xf),
                          (float *)pppppppppppfVar29);
            pppppppppppfVar36 = extraout_r1_00;
          }
          if (*(char *)((int)pppppppppppfVar32 + 0x93) == '\0') {
            pppppppppppfVar29 = pppppppppppfVar32 + 0xf;
            func_00115C70((float *)&local_1e78,(float *)(pppppppppppfVar32 + 9),
                          (float *)pppppppppppfVar29);
            pppppppppppfVar32[0x1b] =
                 (float **********)
                 CF_FBITS((ALBW_AS_F32(*pppppppppppfVar32) * ALBW_AS_F32(local_1e78) +
                  ALBW_AS_F32(pppppppppppfVar32[1]) * ALBW_AS_F32(local_1e74) +
                 ALBW_AS_F32(pppppppppppfVar32[2]) * ALBW_AS_F32(local_1e70)));
            pppppppppppfVar36 = extraout_r1_01;
          }
          uVar51 = (ulonglong)(uint)ALBW_AS_U32((ALBW_AS_F32(uVar51) + ALBW_AS_F32((uVar51 >> 0x20))));
          *(undefined1 *)(pppppppppppfVar32 + 0x25) = 1;
        }
        pppppppppppfVar37 = (float ***********)((int)pppppppppppfVar37 + 1);
        local_1e1c = (float ***********)((int)local_1e1c + 1);
      } while ((int)pppppppppppfVar37 < (int)pppppppppppfVar8);
    }
    fVar33 = ALBW_AS_F32(uVar51);
    iVar6 = DAT_0064781c;
    pppppppppppfVar28 = pppppppppppfVar8;
    if ((int)pppppppppppfVar37 < (int)pppppppppppfVar8) {
      while (pppppppppppfVar32 = (float ***********)((int)pppppppppppfVar28 + -1),
            DAT_0064781c = iVar6, (int)pppppppppppfVar37 <= (int)pppppppppppfVar32) {
        uVar58 = (undefined4)(uVar50 >> 0x20);
        fVar33 = ALBW_AS_F32(uVar51);
        pppppppppppfVar36 = (float ***********)*pppppppppppfVar35;
        pppppppppppfVar28 = (float ***********)((int)pppppppppppfVar28 + -2);
        if (pppppppppppfVar28 < pppppppppppfVar36) {
          pppppppppppfVar29 = (float ***********)((int)pppppppppppfVar28 * 0x27);
          ppppppppppfVar9 = pppppppppppfVar54[0x2b] + (int)pppppppppppfVar28 * 0x27;
        }
        else {
          ppppppppppfVar9 = pppppppppppfVar54[0x2b];
          pppppppppppfVar29 = pppppppppppfVar28;
        }
        if (pppppppppppfVar32 < pppppppppppfVar36) {
          pppppppppppfVar36 = (float ***********)pppppppppppfVar54[0x2b];
          pppppppppppfVar29 = (float ***********)((int)pppppppppppfVar32 * 7);
          pppppppppppfVar28 = pppppppppppfVar36 + (int)pppppppppppfVar32 * 0x27;
        }
        else {
          pppppppppppfVar28 = (float ***********)pppppppppppfVar54[0x2b];
        }
        if ((((int)ppppppppppfVar9[7] <= iVar6) && ((int)pppppppppppfVar28[7] <= iVar6)) ||
           (pppppppppppfVar36 = (float ***********)DAT_00647820,
           (float ***********)
           CF_FBITS((ALBW_AS_F32(*ppppppppppfVar9) * ALBW_AS_F32(pppppppppppfVar28[6]) +
            ALBW_AS_F32(ppppppppppfVar9[1]) * ALBW_AS_F32(pppppppppppfVar28[7]) +
           ALBW_AS_F32(ppppppppppfVar9[2]) * ALBW_AS_F32(pppppppppppfVar28[8]))) <= DAT_00647820)) break;
        fVar43 = ALBW_AS_F32(local_30[0x1c]) / ALBW_AS_F32(ppppppppppfVar9[4]);
        if (*(char *)((int)ppppppppppfVar9 + 0x93) == '\0') {
          pppppppppppfVar29 = (float ***********)(ppppppppppfVar9 + 0x18);
        }
        else {
          pppppppppppfVar29 = (float ***********)(ppppppppppfVar9 + 0xc);
        }
        fVar48 = ALBW_AS_F32(local_30[0x1c]) / ALBW_AS_F32(pppppppppppfVar28[4]);
        local_1e30 = pppppppppppfVar29;
        func_00115D70((float *)&local_1df0,(float *)(ppppppppppfVar9 + 3),fVar43);
        local_1ee8 = local_1df0;
        local_1ee4 = local_1dec;
        local_1ee0 = local_1de8;
        func_00115C54((float *)&local_1dd8,(float *)pppppppppppfVar29,(float *)&local_1ee8);
        local_1e58 = local_1dd8;
        local_1e54 = local_1dd4;
        local_1e50 = local_1dd0;
        local_1e4c = local_1dd8;
        local_1e48 = local_1dd4;
        local_1e44 = local_1dd0;
        if (*(char *)((int)pppppppppppfVar28 + 0x93) == '\0') {
          pppppppppppfVar29 = pppppppppppfVar28 + 0x15;
        }
        else {
          pppppppppppfVar29 = pppppppppppfVar28 + 9;
        }
        local_1ec4 = pppppppppppfVar29;
        func_00115D70((float *)&local_1e08,(float *)(pppppppppppfVar28 + 3),fVar48);
        local_1e58 = local_1e08;
        local_1e54 = local_1e04;
        local_1e50 = local_1e00;
        func_00115C54((float *)&local_1de4,(float *)pppppppppppfVar29,(float *)&local_1e58);
        local_1ee8 = local_1de4;
        local_1ee4 = (float ***********)local_1de0;
        local_1ee0 = local_1ddc;
        local_1e90 = (float ************)local_1de4;
        local_1e8c = (float ***********)local_1de0;
        local_1e88 = local_1ddc;
        uVar50 = CONCAT44(uVar58,ALBW_AS_F32(*ppppppppppfVar9) * ALBW_AS_F32(pppppppppppfVar28[6]) +
                                 ALBW_AS_F32(ppppppppppfVar9[1]) * ALBW_AS_F32(pppppppppppfVar28[7]) +
                                 ALBW_AS_F32(ppppppppppfVar9[2]) * ALBW_AS_F32(pppppppppppfVar28[8]));
        func_00115C70((float *)&local_1dfc,(float *)&local_1e4c,(float *)local_1ec4);
        fVar53 = (-(ALBW_AS_F32(pppppppppppfVar28[6]) * ALBW_AS_F32(local_1dfc) +
                   ALBW_AS_F32(pppppppppppfVar28[7]) * ALBW_AS_F32(local_1df8)) +
                 -(ALBW_AS_F32(pppppppppppfVar28[8]) * ALBW_AS_F32(local_1df4))) / ALBW_AS_F32(uVar50);
        uVar51 = CONCAT44(fVar53,fVar33);
        if (iVar6 < (int)ALBW_AS_U32(fVar53)) {
          func_00115D70((float *)&local_1e14,(float *)ppppppppppfVar9,fVar53);
          local_1e40 = local_1e14;
          local_1e3c = local_1e10;
          local_1e38 = local_1e0c;
          func_00115C54((float *)&local_1dcc,(float *)&local_1e4c,(float *)&local_1e40);
          ppppppppppfVar9[0x12] = (float *********)local_1dcc;
          ppppppppppfVar9[0x13] = local_1dc8;
          ppppppppppfVar9[0x14] = local_1dc4;
          if (*(char *)((int)ppppppppppfVar9 + 0x93) == '\x01') {
            func_00115D70((float *)&local_1e68,(float *)(ppppppppppfVar9 + 3),
                          ALBW_AS_F32(((ulonglong)uVar49 >> 0x20)));
            local_1e78 = local_1e68;
            local_1e74 = (float ************)local_1e64;
            local_1e70 = local_1e60;
            func_00115D70((float *)&local_1e68,(float *)&local_1e78,fVar43);
            local_1ef0 = local_1e68;
            local_1eec = local_1e64;
            local_1ee8 = local_1e60;
            func_00115C54((float *)(ppppppppppfVar9 + 0x12),(float *)(ppppppppppfVar9 + 0x12),
                          (float *)&local_1ef0);
          }
          if (*(char *)((int)ppppppppppfVar9 + 0x93) == '\0') {
            func_00115C70((float *)&local_1e78,(float *)(ppppppppppfVar9 + 0x12),
                          (float *)(ppppppppppfVar9 + 0xc));
            ppppppppppfVar9[0x1b] =
                 (float *********)
                 CF_FBITS((ALBW_AS_F32(*ppppppppppfVar9) * ALBW_AS_F32(local_1e78) +
                  ALBW_AS_F32(ppppppppppfVar9[1]) * ALBW_AS_F32(local_1e74) +
                 ALBW_AS_F32(ppppppppppfVar9[2]) * ALBW_AS_F32(local_1e70)));
          }
          uVar51 = (ulonglong)(uint)ALBW_AS_U32((ALBW_AS_F32(uVar51) + ALBW_AS_F32((uVar51 >> 0x20))));
          *(undefined1 *)((int)ppppppppppfVar9 + 0x95) = 1;
        }
        uVar58 = (undefined4)uVar51;
        fVar43 = -(ALBW_AS_F32(*pppppppppppfVar28) * ALBW_AS_F32(ppppppppppfVar9[6]) +
                   ALBW_AS_F32(pppppppppppfVar28[1]) * ALBW_AS_F32(ppppppppppfVar9[7]) +
                  ALBW_AS_F32(pppppppppppfVar28[2]) * ALBW_AS_F32(ppppppppppfVar9[8]));
        pppppppppppfVar29 = local_1e30;
        func_00115C70((float *)&local_1e78,(float *)&local_1e90,(float *)local_1e30);
        fVar43 = (-(ALBW_AS_F32(ppppppppppfVar9[6]) * ALBW_AS_F32(local_1e78) +
                   ALBW_AS_F32(ppppppppppfVar9[7]) * ALBW_AS_F32(local_1e74)) +
                 -(ALBW_AS_F32(ppppppppppfVar9[8]) * ALBW_AS_F32(local_1e70))) / fVar43;
        uVar51 = CONCAT44(fVar43,uVar58);
        pppppppppppfVar36 = extraout_r1_02;
        if (iVar6 < (int)ALBW_AS_U32(fVar43)) {
          func_00115D70((float *)&local_1e78,(float *)pppppppppppfVar28,fVar43);
          local_1e68 = local_1e78;
          local_1e64 = (float ***********)local_1e74;
          local_1e60 = local_1e70;
          func_00115C70((float *)&local_1e78,(float *)&local_1e90,(float *)&local_1e68);
          pppppppppppfVar28[0xf] = (float **********)local_1e78;
          pppppppppppfVar28[0x10] = (float **********)local_1e74;
          pppppppppppfVar28[0x11] = (float **********)local_1e70;
          pppppppppppfVar36 = (float ***********)local_1e74;
          pppppppppppfVar29 = local_1e70;
          if (*(char *)((int)pppppppppppfVar28 + 0x93) == '\x01') {
            func_00115D70((float *)&local_1e78,(float *)(pppppppppppfVar28 + 3),
                          ALBW_AS_F32(((ulonglong)uVar49 >> 0x20)));
            local_1ef0 = local_1e78;
            local_1eec = (float ***********)local_1e74;
            local_1ee8 = local_1e70;
            func_00115D70((float *)&local_1e78,(float *)&local_1ef0,fVar48);
            pppppppppppfVar29 = (float ***********)&local_1e68;
            local_1e68 = local_1e78;
            local_1e64 = (float ***********)local_1e74;
            local_1e60 = local_1e70;
            func_00115C54((float *)(pppppppppppfVar28 + 0xf),(float *)(pppppppppppfVar28 + 0xf),
                          (float *)pppppppppppfVar29);
            pppppppppppfVar36 = extraout_r1_03;
          }
          if (*(char *)((int)pppppppppppfVar28 + 0x93) == '\0') {
            pppppppppppfVar29 = pppppppppppfVar28 + 0xf;
            func_00115C70((float *)&local_1e78,(float *)(pppppppppppfVar28 + 9),
                          (float *)pppppppppppfVar29);
            pppppppppppfVar28[0x1b] =
                 (float **********)
                 CF_FBITS((ALBW_AS_F32(*pppppppppppfVar28) * ALBW_AS_F32(local_1e78) +
                  ALBW_AS_F32(pppppppppppfVar28[1]) * ALBW_AS_F32(local_1e74) +
                 ALBW_AS_F32(pppppppppppfVar28[2]) * ALBW_AS_F32(local_1e70)));
            pppppppppppfVar36 = extraout_r1_04;
          }
          uVar51 = (ulonglong)(uint)ALBW_AS_U32((ALBW_AS_F32(uVar51) + ALBW_AS_F32((uVar51 >> 0x20))));
          *(undefined1 *)(pppppppppppfVar28 + 0x25) = 1;
        }
        fVar33 = ALBW_AS_F32(uVar51);
        local_1e20 = (float ***********)((int)local_1e20 + 1);
        iVar6 = DAT_0064781c;
        pppppppppppfVar28 = pppppppppppfVar32;
      }
    }
    fVar43 = ALBW_AS_F32((uVar50 >> 0x20));
    if (fVar43 < fVar33) {
      pppppppppppfVar28 = (float ***********)((int)pppppppppppfVar8 + -1);
      pppppppppppfVar37 = local_1e1c;
      if (local_1e1c == pppppppppppfVar28) {
        pppppppppppfVar37 = local_1e20;
      }
      if (local_1e1c == pppppppppppfVar28 && pppppppppppfVar37 == (float ***********)0x0) {
        local_1e20 = (float ***********)0x1;
        local_1e1c = (float ***********)((int)local_1e1c + -1);
      }
      fVar48 = fVar43;
      fVar53 = fVar43;
      if (0 < (int)local_1e1c) {
        if (0 < (int)pppppppppppfVar8) {
          pppppppppppfVar36 = (float ***********)pppppppppppfVar54[0x2b];
          pppppppppppfVar29 = (float ***********)*pppppppppppfVar35;
        }
        pppppppppppfVar37 = (float ***********)0x0;
        if (0 < (int)pppppppppppfVar8) {
          do {
            pppppppppppfVar32 = pppppppppppfVar36;
            if (pppppppppppfVar37 < pppppppppppfVar29) {
              pppppppppppfVar32 = pppppppppppfVar36 + (int)pppppppppppfVar37 * 0x27;
            }
            if ((0x3effffff < (int)pppppppppppfVar32[0x1d]) &&
               (ppppppppppfVar9 = pppppppppppfVar32[0x1c], (int)ppppppppppfVar9 < 0x3f000001)) {
              if (pppppppppppfVar37 == (float ***********)0x0) {
                if ((float ***********)0x1 < pppppppppppfVar29) {
                  pppppppppppfVar36 = pppppppppppfVar36 + 0x27;
                }
                fVar48 = (ALBW_AS_F32(pppppppppppfVar36[0x1d]) - ALBW_AS_F32(pppppppppppfVar36[0x1c])) + fVar43;
                fVar53 = (ALBW_AS_F32(pppppppppppfVar32[0x1d]) - ALBW_AS_F32(ppppppppppfVar9)) + fVar43;
              }
              else {
                pppppppppppfVar24 = (float ***********)((int)pppppppppppfVar37 + -1);
                pppppppppppfVar21 = pppppppppppfVar36;
                if (pppppppppppfVar24 < pppppppppppfVar29) {
                  pppppppppppfVar21 = pppppppppppfVar36 + (int)pppppppppppfVar24 * 0x27;
                }
                if (pppppppppppfVar24 < pppppppppppfVar29) {
                  pppppppppppfVar36 = pppppppppppfVar36 + ((int)pppppppppppfVar37 + -1) * 0x27;
                }
                fVar48 = (ALBW_AS_F32(pppppppppppfVar32[0x1d]) - ALBW_AS_F32(ppppppppppfVar9)) + fVar43;
                fVar53 = (ALBW_AS_F32(pppppppppppfVar21[0x1d]) - ALBW_AS_F32(pppppppppppfVar36[0x1c])) + fVar43;
              }
              break;
            }
            pppppppppppfVar37 = (float ***********)((int)pppppppppppfVar37 + 1);
          } while ((int)pppppppppppfVar37 < (int)pppppppppppfVar8);
        }
      }
      if ((0 < (int)local_1e20) && (-1 < (int)pppppppppppfVar28)) {
        ppppppppppfVar9 = pppppppppppfVar54[0x2b];
        pppppppppppfVar36 = (float ***********)*pppppppppppfVar35;
        pppppppppppfVar29 = pppppppppppfVar28;
        do {
          ppppppppppfVar41 = ppppppppppfVar9;
          if (pppppppppppfVar29 < pppppppppppfVar36) {
            ppppppppppfVar41 = ppppppppppfVar9 + (int)pppppppppppfVar29 * 0x27;
          }
          if ((0x3effffff < (int)ppppppppppfVar41[0x1d]) &&
             (pppppppppfVar26 = ppppppppppfVar41[0x1c], (int)pppppppppfVar26 < 0x3f000001)) {
            if (pppppppppppfVar29 == pppppppppppfVar28) {
              pppppppppppfVar37 = (float ***********)((int)pppppppppppfVar29 + -1);
              ppppppppppfVar17 = ppppppppppfVar9;
              if (pppppppppppfVar37 < pppppppppppfVar36) {
                ppppppppppfVar17 = ppppppppppfVar9 + (int)pppppppppppfVar37 * 0x27;
              }
              fVar48 = (ALBW_AS_F32(ppppppppppfVar41[0x1d]) - ALBW_AS_F32(pppppppppfVar26)) + fVar48;
              if (pppppppppppfVar37 < pppppppppppfVar36) {
                ppppppppppfVar9 = ppppppppppfVar9 + ((int)pppppppppppfVar29 + -1) * 0x27;
              }
              fVar53 = (ALBW_AS_F32(ppppppppppfVar17[0x1d]) - ALBW_AS_F32(ppppppppppfVar9[0x1c])) + fVar53;
            }
            else {
              pppppppppppfVar37 = (float ***********)((int)pppppppppppfVar29 + 1);
              ppppppppppfVar17 = ppppppppppfVar9;
              if (pppppppppppfVar37 < pppppppppppfVar36) {
                ppppppppppfVar17 = ppppppppppfVar9 + (int)pppppppppppfVar37 * 0x27;
              }
              fVar53 = (ALBW_AS_F32(ppppppppppfVar41[0x1d]) - ALBW_AS_F32(pppppppppfVar26)) + fVar53;
              if (pppppppppppfVar37 < pppppppppppfVar36) {
                ppppppppppfVar9 = ppppppppppfVar9 + ((int)pppppppppppfVar29 + 1) * 0x27;
              }
              fVar48 = (ALBW_AS_F32(ppppppppppfVar17[0x1d]) - ALBW_AS_F32(ppppppppppfVar9[0x1c])) + fVar48;
            }
            break;
          }
          pppppppppppfVar29 = (float ***********)((int)pppppppppppfVar29 + -1);
        } while (-1 < (int)pppppppppppfVar29);
      }
      uVar51 = (ulonglong)(uint)ALBW_AS_U32(fVar43);
      fVar52 = fVar43;
      if (fVar43 < fVar53 + fVar48) {
        fVar43 = fVar33 * fVar48 * (ALBW_AS_F32(uVar59) / (fVar53 + fVar48));
        fVar52 = fVar33 - fVar43;
      }
      pppppppppppfVar29 = (float ***********)0x0;
      for (; ((int)pppppppppppfVar29 < (int)pppppppppppfVar8 && (ALBW_AS_F32(uVar51) < fVar43));
          fVar43 = fVar43 - fVar33) {
        if (pppppppppppfVar29 < *pppppppppppfVar35) {
          ppppppppppfVar9 = pppppppppppfVar54[0x2b] + (int)pppppppppppfVar29 * 0x27;
        }
        else {
          ppppppppppfVar9 = pppppppppppfVar54[0x2b];
        }
        func_00115C70((float *)&local_1ee0,(float *)(ppppppppppfVar9 + 0x12),
                      (float *)(ppppppppppfVar9 + 0xf));
        fVar33 = ALBW_AS_F32(*ppppppppppfVar9) * ALBW_AS_F32(local_1ee0) +
                 ALBW_AS_F32(ppppppppppfVar9[1]) * local_1edc +
                 ALBW_AS_F32(ppppppppppfVar9[2]) * ALBW_AS_F32(local_1ed8);
        if (fVar43 < fVar33) {
          bVar39 = false;
          fVar48 = ALBW_AS_F32(uVar51);
          fVar33 = fVar43 - ALBW_AS_F32(ppppppppppfVar9[0x1b]);
          if (fVar43 - ALBW_AS_F32(ppppppppppfVar9[0x1b]) < fVar48) {
            fVar33 = fVar48;
          }
          if (fVar33 == fVar48) {
            local_1e84 = (float ***********)ppppppppppfVar9[9];
            local_1e80 = (float ***********)ppppppppppfVar9[10];
            local_1e7c = (float ***********)ppppppppppfVar9[0xb];
LAB_00647134:
            if (pppppppppppfVar29 != (float ***********)0x0) goto LAB_00647158;
          }
          else {
            if (*(char *)((int)ppppppppppfVar9 + 0x93) == '\0') {
              func_00115D70((float *)&local_1e90,(float *)ppppppppppfVar9,fVar33);
              local_1ee8 = (float ***********)local_1e90;
              local_1ee4 = local_1e8c;
              local_1ee0 = local_1e88;
              func_00115C54((float *)&local_1e90,(float *)(ppppppppppfVar9 + 0xf),
                            (float *)&local_1ee8);
              local_1e84 = (float ***********)local_1e90;
              local_1e80 = local_1e8c;
              local_1e7c = local_1e88;
              goto LAB_00647134;
            }
            func_00115D70((float *)&local_1ee8,(float *)ppppppppppfVar9,fVar33);
            local_1e6c = local_1ee8;
            local_1e68 = local_1ee4;
            local_1e64 = local_1ee0;
            func_00115C54((float *)&local_1ee8,(float *)(ppppppppppfVar9 + 0xf),(float *)&local_1e6c
                         );
            local_1e90 = (float ************)local_1ee8;
            local_1e8c = local_1ee4;
            local_1e88 = local_1ee0;
            func_00115D70((float *)&local_1ee8,(float *)(ppppppppppfVar9 + 3),ALBW_AS_F32(local_30[0x1c]))
            ;
            local_1e4c = local_1ee8;
            local_1e48 = local_1ee4;
            local_1e44 = local_1ee0;
            func_00115D88((float *)&local_1ee8,(float *)&local_1e4c,ALBW_AS_F32(ppppppppppfVar9[4]));
            local_1e58 = local_1ee8;
            local_1e54 = local_1ee4;
            local_1e50 = local_1ee0;
            func_00115C54((float *)&local_1ee8,(float *)&local_1e90,(float *)&local_1e58);
            local_1e84 = local_1ee8;
            local_1e80 = local_1ee4;
            local_1e7c = local_1ee0;
            if (pppppppppppfVar29 != (float ***********)0x0) {
              if (*(char *)(ppppppppppfVar9 + 0x25) != '\0') {
                func_00115D70((float *)&local_1e40,(float *)ppppppppppfVar9,fVar33);
                local_1ee8 = local_1e40;
                local_1ee4 = local_1e3c;
                local_1ee0 = local_1e38;
                func_00115C54((float *)(ppppppppppfVar9 + 0xf),(float *)(ppppppppppfVar9 + 0xf),
                              (float *)&local_1ee8);
                func_00115C70((float *)&local_1e40,(float *)&local_1e84,
                              (float *)(ppppppppppfVar9 + 0xf));
                local_1ee8 = local_1e40;
                local_1ee4 = local_1e3c;
                local_1ee0 = local_1e38;
                func_0068906C((float *)&local_1e78,(float *)&local_1ee8);
                bVar39 = true;
              }
              goto LAB_00647158;
            }
          }
          if (*(char *)(ppppppppppfVar9 + 0x26) == '\0') {
LAB_00647158:
            pppppppppppfVar36 = (float ***********)0x0;
            local_1eec = pppppppppppfVar29;
            goto LAB_006473c0;
          }
          pppppppppppfVar36 = (float ***********)0x0;
          local_1eec = (float ***********)0x1;
          goto LAB_006473cc;
        }
        pppppppppppfVar29 = (float ***********)((int)pppppppppppfVar29 + 1);
      }
LAB_006473d4:
      while( true ) {
        pppppppppppfVar29 = (float ***********)((int)pppppppppppfVar8 + -1);
        fVar43 = ALBW_AS_F32((uVar50 >> 0x20));
        bVar39 = (int)pppppppppppfVar29 < 0;
        bVar40 = pppppppppppfVar29 == (float ***********)0x0;
        bVar38 = false;
        if (!bVar39) {
          fVar33 = ALBW_AS_F32(uVar51);
          bVar39 = fVar52 < fVar33;
          bVar40 = fVar52 == fVar33;
          bVar38 = NAN(fVar52) || NAN(fVar33);
        }
        if (bVar40 || bVar39 != bVar38) goto LAB_006478a4;
        if (pppppppppppfVar29 < *pppppppppppfVar35) {
          ppppppppppfVar9 = pppppppppppfVar54[0x2b] + (int)pppppppppppfVar29 * 0x27;
        }
        else {
          ppppppppppfVar9 = pppppppppppfVar54[0x2b];
        }
        func_00115C70((float *)&local_1e90,(float *)(ppppppppppfVar9 + 0x12),
                      (float *)(ppppppppppfVar9 + 0xf));
        fVar43 = ALBW_AS_F32(*ppppppppppfVar9) * ALBW_AS_F32(local_1e90) +
                 ALBW_AS_F32(ppppppppppfVar9[1]) * ALBW_AS_F32(local_1e8c) +
                 ALBW_AS_F32(ppppppppppfVar9[2]) * ALBW_AS_F32(local_1e88);
        if (fVar52 < fVar43) break;
        fVar52 = fVar52 - fVar43;
        pppppppppppfVar8 = pppppppppppfVar29;
      }
      bVar39 = false;
      fVar33 = ALBW_AS_F32(uVar51);
      fVar43 = fVar52 - ALBW_AS_F32(ppppppppppfVar9[0x1b]);
      if (fVar52 - ALBW_AS_F32(ppppppppppfVar9[0x1b]) < fVar33) {
        fVar43 = fVar33;
      }
      if (fVar43 == fVar33) {
        local_1e84 = (float ***********)ppppppppppfVar9[0xc];
        local_1e80 = (float ***********)ppppppppppfVar9[0xd];
        local_1e7c = (float ***********)ppppppppppfVar9[0xe];
      }
      else if (*(char *)((int)ppppppppppfVar9 + 0x93) == '\0') {
        func_00115D70((float *)&local_1eec,(float *)ppppppppppfVar9,fVar43);
        local_1e90 = (float ************)local_1eec;
        local_1e8c = local_1ee8;
        local_1e88 = local_1ee4;
        func_00115C70((float *)&local_1ef0,(float *)(ppppppppppfVar9 + 0x12),(float *)&local_1e90);
        local_1e84 = local_1ef0;
        local_1e80 = local_1eec;
        local_1e7c = local_1ee8;
      }
      else {
        func_00115D70((float *)&local_1ee8,(float *)ppppppppppfVar9,fVar43);
        local_1e6c = local_1ee8;
        local_1e68 = local_1ee4;
        local_1e64 = local_1ee0;
        func_00115C70((float *)&local_1ee8,(float *)(ppppppppppfVar9 + 0x12),(float *)&local_1e6c);
        local_1e90 = (float ************)local_1ee8;
        local_1e8c = local_1ee4;
        local_1e88 = local_1ee0;
        func_00115D70((float *)&local_1ee8,(float *)(ppppppppppfVar9 + 3),ALBW_AS_F32(local_30[0x1c]));
        local_1e50 = local_1ee8;
        local_1e4c = local_1ee4;
        local_1e48 = local_1ee0;
        func_00115D88((float *)&local_1ee8,(float *)&local_1e50,ALBW_AS_F32(ppppppppppfVar9[4]));
        local_1e60 = local_1ee8;
        local_1e5c = local_1ee4;
        local_1e58 = local_1ee0;
        func_00115C54((float *)&local_1ee8,(float *)&local_1e90,(float *)&local_1e60);
        local_1e84 = local_1ee8;
        local_1e80 = local_1ee4;
        local_1e7c = local_1ee0;
        pppppppppppfVar36 = local_1ee8;
        if (pppppppppppfVar29 != pppppppppppfVar28) {
          pppppppppppfVar36 = (float ***********)(uint)*(byte *)((int)ppppppppppfVar9 + 0x95);
        }
        if (pppppppppppfVar29 != pppppppppppfVar28 && pppppppppppfVar36 != (float ***********)0x0) {
          func_00115D70((float *)&local_1e44,(float *)ppppppppppfVar9,fVar43);
          local_1ee8 = local_1e44;
          local_1ee4 = local_1e40;
          local_1ee0 = local_1e3c;
          func_00115C70((float *)(ppppppppppfVar9 + 0x12),(float *)(ppppppppppfVar9 + 0x12),
                        (float *)&local_1ee8);
          func_00115C70((float *)&local_1e44,(float *)&local_1e84,(float *)(ppppppppppfVar9 + 0x12))
          ;
          local_1ee8 = local_1e44;
          local_1ee4 = local_1e40;
          local_1ee0 = local_1e3c;
          func_0068906C((float *)&local_1e78,(float *)&local_1ee8);
          bVar39 = true;
        }
      }
      pppppppppppfVar36 = pppppppppppfVar29;
      if ((pppppppppppfVar29 == pppppppppppfVar28) && (*(char *)(ppppppppppfVar9 + 0x26) != '\0')) {
        pppppppppppfVar36 = (float ***********)((int)pppppppppppfVar8 + -2);
      }
      pppppppppppfVar8 = (float ***********)*pppppppppppfVar35;
LAB_00647898:
      do {
        pppppppppppfVar8 = (float ***********)((int)pppppppppppfVar8 + -1);
        fVar43 = ALBW_AS_F32((uVar50 >> 0x20));
        pppppppppppfVar37 = (float ***********)((int)pppppppppppfVar8 - (int)pppppppppppfVar36);
        if ((int)pppppppppppfVar8 >= (int)pppppppppppfVar36) {
          pppppppppppfVar37 = pppppppppppfVar8;
        }
        if ((int)pppppppppppfVar37 < 0 !=
            ((int)pppppppppppfVar8 < (int)pppppppppppfVar36 &&
            SBORROW4((int)pppppppppppfVar8,(int)pppppppppppfVar36))) break;
        if (pppppppppppfVar8 < *pppppppppppfVar35) {
          ppppppppppfVar9 = pppppppppppfVar54[0x2b] + (int)pppppppppppfVar8 * 0x27;
        }
        else {
          ppppppppppfVar9 = pppppppppppfVar54[0x2b];
        }
        *(undefined1 *)((int)ppppppppppfVar9 + 0x92) = 1;
        if (*(char *)((int)ppppppppppfVar9 + 0x93) == '\0') {
          func_00115C70((float *)&local_1ef0,(float *)&local_1e84,(float *)(ppppppppppfVar9 + 0x12))
          ;
          func_00115D70((float *)&local_1e6c,(float *)(ppppppppppfVar9 + 6),
                        ALBW_AS_F32(ppppppppppfVar9[6]) * ALBW_AS_F32(local_1ef0) +
                        ALBW_AS_F32(ppppppppppfVar9[7]) * ALBW_AS_F32(local_1eec) +
                        ALBW_AS_F32(ppppppppppfVar9[8]) * ALBW_AS_F32(local_1ee8));
          local_1e90 = (float ************)local_1e6c;
          local_1e8c = local_1e68;
          local_1e88 = local_1e64;
          func_00115C70((float *)&local_1ef0,(float *)&local_1e84,(float *)&local_1e90);
          ppppppppppfVar9 = ppppppppppfVar9 + 0x12;
          pppppppppppfVar37 = local_1ef0;
          pppppppppppfVar28 = local_1eec;
          pppppppppppfVar32 = local_1ee8;
        }
        else {
          if (pppppppppppfVar8 != pppppppppppfVar29 && bVar39) {
            fVar33 = ALBW_AS_F32(ppppppppppfVar9[6]) * ALBW_AS_F32(local_1e78) +
                     ALBW_AS_F32(ppppppppppfVar9[7]) * ALBW_AS_F32(local_1e74) +
                     ALBW_AS_F32(ppppppppppfVar9[8]) * ALBW_AS_F32(local_1e70);
            fVar43 = fVar33;
            if (fVar33 <= ALBW_AS_F32(uVar51)) {
              fVar43 = -fVar33;
            }
            if (DAT_00647824 < (int)ALBW_AS_U32(fVar43)) {
              func_00115C70((float *)&local_1e20,(float *)&local_1e84,
                            (float *)(ppppppppppfVar9 + 0xc));
              local_1e60 = local_1e20;
              local_1e5c = local_1e1c;
              local_1e58 = local_1e18;
              func_00115D70((float *)&local_1e14,(float *)&local_1e78,
                            ALBW_AS_F32(ppppppppppfVar9[6]) * ALBW_AS_F32(local_1e20) +
                            ALBW_AS_F32(ppppppppppfVar9[7]) * ALBW_AS_F32(local_1e1c) +
                            ALBW_AS_F32(ppppppppppfVar9[8]) * ALBW_AS_F32(local_1e18));
              local_1e6c = local_1e14;
              local_1e68 = local_1e10;
              local_1e64 = local_1e0c;
              func_00115D88((float *)&local_1e08,(float *)&local_1e6c,fVar33);
              local_1e60 = local_1e08;
              local_1e5c = local_1e04;
              local_1e58 = local_1e00;
              func_00115C70((float *)&local_1e2c,(float *)&local_1e84,(float *)&local_1e60);
              local_1ef0 = local_1e2c;
              local_1eec = local_1e28;
              local_1ee8 = local_1e24;
              func_00115C70((float *)&local_1e50,(float *)&local_1ef0,
                            (float *)(ppppppppppfVar9 + 0x12));
              local_1e6c = local_1e50;
              local_1e68 = local_1e4c;
              local_1e64 = local_1e48;
              if (ALBW_AS_F32(uVar51) <
                  ALBW_AS_F32(local_1e50) * ALBW_AS_F32(ppppppppppfVar9[3]) +
                  ALBW_AS_F32(local_1e4c) * ALBW_AS_F32(ppppppppppfVar9[4]) +
                  ALBW_AS_F32(local_1e48) * ALBW_AS_F32(ppppppppppfVar9[5])) {
                ppppppppppfVar9[0x18] = (float *********)local_1ef0;
                ppppppppppfVar9[0x19] = (float *********)local_1eec;
                ppppppppppfVar9[0x1a] = (float *********)local_1ee8;
                goto LAB_00647898;
              }
            }
          }
          func_00115C70((float *)&local_1e44,(float *)&local_1e84,(float *)(ppppppppppfVar9 + 0x12))
          ;
          func_00115D70((float *)&local_1e38,(float *)(ppppppppppfVar9 + 6),
                        ALBW_AS_F32(ppppppppppfVar9[6]) * ALBW_AS_F32(local_1e44) +
                        ALBW_AS_F32(ppppppppppfVar9[7]) * ALBW_AS_F32(local_1e40) +
                        ALBW_AS_F32(ppppppppppfVar9[8]) * ALBW_AS_F32(local_1e3c));
          local_1df0 = local_1e38;
          local_1dec = local_1e34;
          local_1de8 = local_1e30;
          func_00115C70((float *)&local_1dfc,(float *)&local_1e84,(float *)&local_1df0);
          ppppppppppfVar9 = ppppppppppfVar9 + 0x18;
          pppppppppppfVar37 = local_1dfc;
          pppppppppppfVar28 = local_1df8;
          pppppppppppfVar32 = local_1df4;
        }
        *ppppppppppfVar9 = (float *********)pppppppppppfVar37;
        ppppppppppfVar9[1] = (float *********)pppppppppppfVar28;
        ppppppppppfVar9[2] = (float *********)pppppppppppfVar32;
      } while( true );
    }
  }
LAB_006478a4:
  pppppppppppfVar29 = local_30;
  if (((uint)local_1ed0 & 2) != 0) {
    ppppppppppfVar9 = (float **********)0x0;
    ppppppppppfVar17 = (float **********)0x1;
    pppppppppppfVar36 = local_30 + 0x29;
    ppppppppppfVar41 = *pppppppppppfVar36;
    local_1df8 = (float ***********)0x0;
    local_1e5c = (float ***********)0x0;
    if (0 < (int)ppppppppppfVar41) {
      do {
        if (ppppppppppfVar9 < *pppppppppppfVar36) {
          ppppppppppfVar22 = local_30[0x2b] + (int)ppppppppppfVar9 * 0x27;
          ppppppppppfVar25 = local_30[0x2b] + (int)ppppppppppfVar9 * 0x27;
        }
        else {
          ppppppppppfVar22 = local_30[0x2b];
          ppppppppppfVar25 = local_30[0x2b];
        }
        ppppppppppfVar9 = (float **********)((int)ppppppppppfVar9 + 1);
        *(undefined1 *)(ppppppppppfVar25 + 0x25) = 0;
        *(undefined1 *)((int)ppppppppppfVar22 + 0x95) = 0;
      } while ((int)ppppppppppfVar9 < (int)ppppppppppfVar41);
    }
    if (1 < (int)ppppppppppfVar41) {
      do {
        if ((float **********)((int)ppppppppppfVar17 + -1) < *pppppppppppfVar36) {
          ppppppppppfVar9 = pppppppppppfVar29[0x2b] + ((int)ppppppppppfVar17 + -1) * 0x27;
        }
        else {
          ppppppppppfVar9 = pppppppppppfVar29[0x2b];
        }
        if (ppppppppppfVar17 < *pppppppppppfVar36) {
          ppppppppppfVar22 = pppppppppppfVar29[0x2b] + (int)ppppppppppfVar17 * 0x27;
        }
        else {
          ppppppppppfVar22 = pppppppppppfVar29[0x2b];
        }
        if ((((int)ppppppppppfVar9[7] <= DAT_0064781c) && ((int)ppppppppppfVar22[7] <= DAT_0064781c)
            ) || ((int)ALBW_AS_U32((ALBW_AS_F32(*ppppppppppfVar9) * ALBW_AS_F32(ppppppppppfVar22[6]) +
                        ALBW_AS_F32(ppppppppppfVar9[1]) * ALBW_AS_F32(ppppppppppfVar22[7]) +
                       ALBW_AS_F32(ppppppppppfVar9[2]) * ALBW_AS_F32(ppppppppppfVar22[8]))) <= DAT_00648984))
        break;
        fVar33 = ALBW_AS_F32(local_30[0x1c]) / ALBW_AS_F32(ppppppppppfVar9[4]);
        uVar50 = (ulonglong)(uint)ALBW_AS_U32(fVar33);
        if (*(char *)((int)ppppppppppfVar9 + 0x93) == '\0') {
          pppppppppppfVar54 = (float ***********)(ppppppppppfVar9 + 0xc);
        }
        else {
          pppppppppppfVar54 = (float ***********)(ppppppppppfVar9 + 0x15);
        }
        fVar48 = ALBW_AS_F32(local_30[0x1c]) / ALBW_AS_F32(ppppppppppfVar22[4]);
        local_1e40 = pppppppppppfVar54;
        func_00115D70((float *)&local_1ecc,(float *)(ppppppppppfVar9 + 3),fVar33);
        local_1ee8 = local_1ecc;
        local_1ee4 = (float ***********)local_1ec8;
        local_1ee0 = local_1ec4;
        func_00115C70((float *)&local_1ecc,(float *)pppppppppppfVar54,(float *)&local_1ee8);
        local_1ed8 = local_1ecc;
        local_1ed4 = local_1ec8;
        local_1ed0 = local_1ec4;
        local_1e38 = local_1ecc;
        local_1e34 = (float ***********)local_1ec8;
        local_1e30 = local_1ec4;
        if (*(char *)((int)ppppppppppfVar22 + 0x93) == '\0') {
          pppppppppppfVar54 = (float ***********)(ppppppppppfVar22 + 9);
        }
        else {
          pppppppppppfVar54 = (float ***********)(ppppppppppfVar22 + 0x15);
        }
        local_1e8c = pppppppppppfVar54;
        func_00115D70((float *)&local_1ecc,(float *)(ppppppppppfVar22 + 3),fVar48);
        local_1ed8 = local_1ecc;
        local_1ed4 = local_1ec8;
        local_1ed0 = local_1ec4;
        func_00115C70((float *)&local_1ecc,(float *)pppppppppppfVar54,(float *)&local_1ed8);
        local_1ee8 = local_1ecc;
        local_1ee4 = (float ***********)local_1ec8;
        local_1ee0 = local_1ec4;
        local_1e2c = local_1ecc;
        local_1e28 = (float ***********)local_1ec8;
        local_1e24 = local_1ec4;
        fVar33 = ALBW_AS_F32(*ppppppppppfVar9) * ALBW_AS_F32(ppppppppppfVar22[6]) +
                 ALBW_AS_F32(ppppppppppfVar9[1]) * ALBW_AS_F32(ppppppppppfVar22[7]) +
                 ALBW_AS_F32(ppppppppppfVar9[2]) * ALBW_AS_F32(ppppppppppfVar22[8]);
        func_00115C70((float *)&local_1ee4,(float *)&local_1e38,(float *)local_1e8c);
        fVar33 = (-(ALBW_AS_F32(ppppppppppfVar22[6]) * ALBW_AS_F32(local_1ee4) +
                   ALBW_AS_F32(ppppppppppfVar22[7]) * ALBW_AS_F32(local_1ee0)) +
                 -(ALBW_AS_F32(ppppppppppfVar22[8]) * local_1edc)) / fVar33;
        if (DAT_0064781c < (int)ALBW_AS_U32(fVar33)) {
          if (*(char *)((int)ppppppppppfVar9 + 0x93) == '\0') {
            ppppppppppfVar25 = ppppppppppfVar17;
            fVar53 = fVar43;
            if ((int)ppppppppppfVar17 < (int)*pppppppppppfVar36) {
              do {
                if (ppppppppppfVar25 < *pppppppppppfVar36) {
                  ppppppppppfVar30 = pppppppppppfVar29[0x2b] + (int)ppppppppppfVar25 * 0x27;
                }
                else {
                  ppppppppppfVar30 = pppppppppppfVar29[0x2b];
                }
                func_00115C70((float *)&local_1ed8,(float *)(ppppppppppfVar30 + 0xc),
                              (float *)(ppppppppppfVar30 + 9));
                ppppppppppfVar25 = (float **********)((int)ppppppppppfVar25 + 1);
                fVar52 = ALBW_AS_F32(*ppppppppppfVar30) * ALBW_AS_F32(local_1ed8) +
                         ALBW_AS_F32(ppppppppppfVar30[1]) * ALBW_AS_F32(local_1ed4) +
                         ALBW_AS_F32(ppppppppppfVar30[2]) * ALBW_AS_F32(local_1ed0);
                if (fVar52 <= fVar43) {
                  fVar52 = -fVar52;
                }
                fVar53 = fVar52 + fVar53;
              } while ((int)ppppppppppfVar25 < (int)*pppppppppppfVar36);
            }
            if (fVar53 < fVar33) {
              fVar33 = fVar53;
            }
            if (*(char *)((int)ppppppppppfVar9 + 0x93) != '\0') goto LAB_00647b9c;
            func_00115D70((float *)&local_1e20,(float *)ppppppppppfVar9,fVar33);
            local_1e54 = local_1e20;
            local_1e50 = local_1e1c;
            local_1e4c = local_1e18;
            func_00115C54((float *)&local_1e14,(float *)&local_1e38,(float *)&local_1e54);
            ppppppppppfVar9[0x12] = (float *********)local_1e14;
            ppppppppppfVar9[0x13] = (float *********)local_1e10;
            ppppppppppfVar9[0x14] = (float *********)local_1e0c;
          }
          else {
LAB_00647b9c:
            func_00115D70((float *)&local_1e08,(float *)ppppppppppfVar9,fVar33);
            local_1e90 = (float ************)local_1e08;
            local_1e8c = local_1e04;
            local_1e88 = local_1e00;
            func_00115C54((float *)(ppppppppppfVar9 + 0x18),(float *)(ppppppppppfVar9 + 0x18),
                          (float *)&local_1e90);
          }
          if (*(char *)((int)ppppppppppfVar9 + 0x93) == '\0') {
            func_00115D70((float *)&local_1ed4,(float *)(ppppppppppfVar9 + 3),ALBW_AS_F32(uVar59));
            local_1ee4 = (float ***********)local_1ed4;
            local_1ee0 = local_1ed0;
            local_1edc = ALBW_AS_F32(local_1ecc);
            func_00115D70((float *)&local_1ed8,(float *)&local_1ee4,ALBW_AS_F32(uVar50));
            local_1e68 = local_1ed8;
            local_1e64 = (float ***********)local_1ed4;
            local_1e60 = local_1ed0;
            func_00115C54((float *)(ppppppppppfVar9 + 0x12),(float *)(ppppppppppfVar9 + 0x12),
                          (float *)&local_1e68);
          }
          *(undefined1 *)((int)ppppppppppfVar9 + 0x95) = 1;
          if (*(char *)((int)ppppppppppfVar22 + 0x93) == '\0') {
            if (*(char *)((int)ppppppppppfVar9 + 0x93) == '\0') {
              local_1e88 = (float ***********)(ppppppppppfVar9 + 0x18);
              func_00115C70((float *)&local_1e74,(float *)(ppppppppppfVar9 + 0x18),
                            (float *)(ppppppppppfVar9 + 0x12));
              func_00115D70((float *)&local_1e74,(float *)(ppppppppppfVar9 + 6),
                            ALBW_AS_F32(ppppppppppfVar9[6]) * ALBW_AS_F32(local_1e74) +
                            ALBW_AS_F32(ppppppppppfVar9[7]) * ALBW_AS_F32(local_1e70) +
                            ALBW_AS_F32(ppppppppppfVar9[8]) * ALBW_AS_F32(local_1e6c));
              local_1ee8 = (float ***********)local_1e74;
              local_1ee4 = local_1e70;
              local_1ee0 = local_1e6c;
              func_00115C70((float *)&local_1e74,(float *)local_1e88,(float *)&local_1ee8);
              local_1edc = ALBW_AS_F32(local_1e74);
              local_1ed8 = local_1e70;
              local_1ed4 = (float ************)local_1e6c;
            }
            else {
              local_1edc = ALBW_AS_F32(ppppppppppfVar9[0x12]);
              local_1ed8 = (float ***********)ppppppppppfVar9[0x13];
              local_1ed4 = (float ************)ppppppppppfVar9[0x14];
            }
            if (*(char *)((int)ppppppppppfVar9 + 0x93) == '\0') {
              func_00115C70((float *)&local_1e90,(float *)(ppppppppppfVar9 + 0x12),&local_1edc);
              local_1ee8 = (float ***********)local_1e90;
              local_1ee4 = local_1e8c;
              local_1ee0 = local_1e88;
              func_0068906C((float *)&local_1ecc,(float *)&local_1ee8);
            }
            else {
              func_00115C70((float *)&local_1e90,(float *)(ppppppppppfVar9 + 0x18),&local_1edc);
              local_1ee8 = (float ***********)local_1e90;
              local_1ee4 = local_1e8c;
              local_1ee0 = local_1e88;
              func_0068906C((float *)&local_1ecc,(float *)&local_1ee8);
            }
            iVar6 = DAT_00647824;
            fVar53 = ALBW_AS_F32(ppppppppppfVar22[6]) * ALBW_AS_F32(local_1ecc) +
                     ALBW_AS_F32(ppppppppppfVar22[7]) * ALBW_AS_F32(local_1ec8) +
                     ALBW_AS_F32(ppppppppppfVar22[8]) * ALBW_AS_F32(local_1ec4);
            fVar33 = fVar53;
            if (fVar53 <= fVar43) {
              fVar33 = -fVar53;
            }
            if (DAT_00647824 < (int)ALBW_AS_U32(fVar33)) {
              func_00115C70((float *)&local_1e90,&local_1edc,(float *)(ppppppppppfVar22 + 9));
              fVar33 = -(ALBW_AS_F32(ppppppppppfVar22[6]) * ALBW_AS_F32(local_1e90) +
                         ALBW_AS_F32(ppppppppppfVar22[7]) * ALBW_AS_F32(local_1e8c) +
                        ALBW_AS_F32(ppppppppppfVar22[8]) * ALBW_AS_F32(local_1e88));
              if (fVar33 <= fVar43) {
                if ((uint)ALBW_AS_U32(DAT_00648988) < (uint)ALBW_AS_U32(fVar33)) {
                  func_00115C70((float *)&local_1e74,(float *)(ppppppppppfVar9 + 0xc),
                                (float *)(ppppppppppfVar9 + 9));
                  func_00115D70((float *)&local_1e74,(float *)ppppppppppfVar22,
                                ALBW_AS_F32(*ppppppppppfVar9) * ALBW_AS_F32(local_1e74) +
                                ALBW_AS_F32(ppppppppppfVar9[1]) * ALBW_AS_F32(local_1e70) +
                                ALBW_AS_F32(ppppppppppfVar9[2]) * ALBW_AS_F32(local_1e6c));
                  local_1e90 = local_1e74;
                  local_1e8c = local_1e70;
                  local_1e88 = local_1e6c;
                  func_00115C70((float *)&local_1e74,(float *)&local_1e2c,(float *)&local_1e90);
                  ppppppppppfVar22[0xf] = (float *********)local_1e74;
                  ppppppppppfVar22[0x10] = (float *********)local_1e70;
                  ppppppppppfVar22[0x11] = (float *********)local_1e6c;
                  func_00115D70((float *)&local_1ee8,(float *)(ppppppppppfVar22 + 3),ALBW_AS_F32(uVar59));
                  local_1e68 = local_1ee8;
                  local_1e64 = local_1ee4;
                  local_1e60 = local_1ee0;
                  func_00115D70((float *)&local_1e74,(float *)&local_1e68,fVar48);
                  local_1e90 = local_1e74;
                  local_1e8c = local_1e70;
                  local_1e88 = local_1e6c;
                  func_00115C54((float *)(ppppppppppfVar22 + 0xf),(float *)(ppppppppppfVar22 + 0xf),
                                (float *)&local_1e90);
                  *(undefined1 *)(ppppppppppfVar22 + 0x25) = 1;
                  if (*(char *)((int)ppppppppppfVar22 + 0x93) == '\0') {
                    local_1ed0 = (float ***********)(ppppppppppfVar22 + 0x15);
                    local_1ee0 = (float ***********)(ppppppppppfVar22 + 6);
                    func_00115C70((float *)&local_1e74,(float *)(ppppppppppfVar22 + 0x15),
                                  (float *)(ppppppppppfVar22 + 0xf));
                    func_00115D70((float *)&local_1e74,(float *)local_1ee0,
                                  ALBW_AS_F32(ppppppppppfVar22[6]) * ALBW_AS_F32(local_1e74) +
                                  ALBW_AS_F32(ppppppppppfVar22[7]) * ALBW_AS_F32(local_1e70) +
                                  ALBW_AS_F32(ppppppppppfVar22[8]) * ALBW_AS_F32(local_1e6c));
                    local_1e54 = (float ***********)local_1e74;
                    local_1e50 = local_1e70;
                    local_1e4c = local_1e6c;
                    func_00115C70((float *)&local_1ee8,(float *)local_1ed0,(float *)&local_1e54);
                    local_1edc = ALBW_AS_F32(local_1ee8);
                    local_1ed8 = local_1ee4;
                    local_1ed4 = (float ************)local_1ee0;
                  }
                  else {
                    local_1edc = ALBW_AS_F32(ppppppppppfVar22[0xf]);
                    local_1ed8 = (float ***********)ppppppppppfVar22[0x10];
                    local_1ed4 = (float ************)ppppppppppfVar22[0x11];
                  }
                  if (*(char *)((int)ppppppppppfVar22 + 0x93) == '\0') {
                    func_00115C70((float *)&local_1ee8,(float *)(ppppppppppfVar22 + 0xf),&local_1edc
                                 );
                    local_1e74 = (float ************)local_1ee8;
                    local_1e70 = local_1ee4;
                    local_1e6c = local_1ee0;
                    func_0068906C((float *)&local_1ecc,(float *)&local_1e74);
                  }
                  else {
                    func_00115C70((float *)&local_1ee8,(float *)(ppppppppppfVar22 + 0x15),
                                  &local_1edc);
                    local_1e74 = (float ************)local_1ee8;
                    local_1e70 = local_1ee4;
                    local_1e6c = local_1ee0;
                    func_0068906C((float *)&local_1ecc,(float *)&local_1e74);
                  }
                  fVar53 = ALBW_AS_F32(ppppppppppfVar9[6]) * ALBW_AS_F32(local_1ecc) +
                           ALBW_AS_F32(ppppppppppfVar9[7]) * ALBW_AS_F32(local_1ec8) +
                           ALBW_AS_F32(ppppppppppfVar9[8]) * ALBW_AS_F32(local_1ec4);
                  fVar33 = fVar53;
                  if (fVar53 <= fVar43) {
                    fVar33 = -fVar53;
                  }
                  if (iVar6 < (int)ALBW_AS_U32(fVar33)) {
                    func_00115C70((float *)&local_1e74,&local_1edc,(float *)(ppppppppppfVar9 + 0xc))
                    ;
                    fVar33 = -(ALBW_AS_F32(ppppppppppfVar9[6]) * ALBW_AS_F32(local_1e74) +
                              ALBW_AS_F32(ppppppppppfVar9[7]) * ALBW_AS_F32(local_1e70)) +
                             -(ALBW_AS_F32(ppppppppppfVar9[8]) * ALBW_AS_F32(local_1e6c));
                    if (fVar43 < fVar33) {
                      func_00115D70((float *)&local_1e14,(float *)&local_1ecc,fVar33);
                      local_1e54 = local_1e14;
                      local_1e50 = local_1e10;
                      local_1e4c = local_1e0c;
                      func_00115D88((float *)&local_1e14,(float *)&local_1e54,fVar53);
                      local_1e74 = (float ************)local_1e14;
                      local_1e70 = local_1e10;
                      local_1e6c = local_1e0c;
                      func_00115C54((float *)&local_1ee8,&local_1edc,(float *)&local_1e74);
                      local_1e20 = local_1ee8;
                      local_1e1c = local_1ee4;
                      local_1e18 = local_1ee0;
                      func_00115C70((float *)&local_1e14,(float *)(ppppppppppfVar9 + 0x12),
                                    (float *)&local_1e20);
                      local_1e54 = local_1e14;
                      local_1e50 = local_1e10;
                      local_1e4c = local_1e0c;
                      if (fVar43 < ALBW_AS_F32(local_1e14) * ALBW_AS_F32(ppppppppppfVar9[3]) +
                                   ALBW_AS_F32(local_1e10) * ALBW_AS_F32(ppppppppppfVar9[4]) +
                                   ALBW_AS_F32(local_1e0c) * ALBW_AS_F32(ppppppppppfVar9[5])) {
                        ppppppppppfVar9[0x18] = (float *********)local_1e20;
                        ppppppppppfVar9[0x19] = (float *********)local_1e1c;
                        ppppppppppfVar9[0x1a] = (float *********)local_1e18;
                        *(undefined1 *)((int)ppppppppppfVar9 + 0x95) = 1;
                        if ((*(char *)((int)ppppppppppfVar9 + 0x97) != '\0') &&
                           (*(char *)(ppppppppppfVar9 + 0x25) == '\0')) {
                          ppppppppppfVar25 = ppppppppppfVar9 + 0x15;
                          ppppppppppfVar9[0x15] = ppppppppppfVar9[0x18];
                          ppppppppppfVar9[0x16] = ppppppppppfVar9[0x19];
                          pppppppppfVar26 = ppppppppppfVar9[0x1a];
                          goto LAB_00648228;
                        }
                      }
                    }
                  }
                }
              }
              else {
                func_00115D70((float *)&local_1e20,(float *)&local_1ecc,fVar33);
                local_1e6c = local_1e20;
                local_1e68 = local_1e1c;
                local_1e64 = local_1e18;
                func_00115D88((float *)&local_1e20,(float *)&local_1e6c,fVar53);
                local_1e54 = local_1e20;
                local_1e50 = local_1e1c;
                local_1e4c = local_1e18;
                func_00115C54((float *)&local_1ee8,&local_1edc,(float *)&local_1e54);
                local_1e90 = (float ************)local_1ee8;
                local_1e8c = local_1ee4;
                local_1e88 = local_1ee0;
                func_00115C70((float *)&local_1ee8,(float *)(ppppppppppfVar22 + 0xf),
                              (float *)&local_1e90);
                local_1e6c = local_1ee8;
                local_1e68 = local_1ee4;
                local_1e64 = local_1ee0;
                if (fVar43 < ALBW_AS_F32(local_1ee8) * ALBW_AS_F32(ppppppppppfVar22[3]) +
                             ALBW_AS_F32(local_1ee4) * ALBW_AS_F32(ppppppppppfVar22[4]) +
                             ALBW_AS_F32(local_1ee0) * ALBW_AS_F32(ppppppppppfVar22[5])) {
                  ppppppppppfVar22[0x15] = (float *********)local_1e90;
                  ppppppppppfVar22[0x16] = (float *********)local_1e8c;
                  ppppppppppfVar22[0x17] = (float *********)local_1e88;
                  *(undefined1 *)(ppppppppppfVar22 + 0x25) = 1;
                  if ((*(char *)((int)ppppppppppfVar22 + 0x97) != '\0') &&
                     (*(char *)((int)ppppppppppfVar22 + 0x95) == '\0')) {
                    ppppppppppfVar25 = ppppppppppfVar22 + 0x18;
                    ppppppppppfVar22[0x18] = ppppppppppfVar22[0x15];
                    ppppppppppfVar22[0x19] = ppppppppppfVar22[0x16];
                    pppppppppfVar26 = ppppppppppfVar22[0x17];
LAB_00648228:
                    ppppppppppfVar25[2] = pppppppppfVar26;
                  }
                }
              }
            }
          }
        }
        fVar33 = -(ALBW_AS_F32(*ppppppppppfVar22) * ALBW_AS_F32(ppppppppppfVar9[6]) +
                   ALBW_AS_F32(ppppppppppfVar22[1]) * ALBW_AS_F32(ppppppppppfVar9[7]) +
                  ALBW_AS_F32(ppppppppppfVar22[2]) * ALBW_AS_F32(ppppppppppfVar9[8]));
        func_00115C70((float *)&local_1ee8,(float *)&local_1e2c,(float *)local_1e40);
        fVar53 = ALBW_AS_F32(uVar50);
        fVar33 = (-(ALBW_AS_F32(ppppppppppfVar9[6]) * ALBW_AS_F32(local_1ee8) +
                   ALBW_AS_F32(ppppppppppfVar9[7]) * ALBW_AS_F32(local_1ee4)) +
                 -(ALBW_AS_F32(ppppppppppfVar9[8]) * ALBW_AS_F32(local_1ee0))) / fVar33;
        if (DAT_0064781c < (int)ALBW_AS_U32(fVar33)) {
          if (*(char *)((int)ppppppppppfVar22 + 0x93) == '\0') {
            ppppppppppfVar25 = (float **********)0x0;
            fVar52 = fVar43;
            if (0 < (int)ppppppppppfVar17) {
              do {
                if (ppppppppppfVar25 < *pppppppppppfVar36) {
                  ppppppppppfVar30 = pppppppppppfVar29[0x2b] + (int)ppppppppppfVar25 * 0x27;
                }
                else {
                  ppppppppppfVar30 = pppppppppppfVar29[0x2b];
                }
                func_00115C70(&local_1edc,(float *)(ppppppppppfVar30 + 0xc),
                              (float *)(ppppppppppfVar30 + 9));
                fVar53 = ALBW_AS_F32(uVar50);
                ppppppppppfVar25 = (float **********)((int)ppppppppppfVar25 + 1);
                fVar45 = ALBW_AS_F32(*ppppppppppfVar30) * local_1edc +
                         ALBW_AS_F32(ppppppppppfVar30[1]) * ALBW_AS_F32(local_1ed8) +
                         ALBW_AS_F32(ppppppppppfVar30[2]) * ALBW_AS_F32(local_1ed4);
                if (fVar45 <= fVar43) {
                  fVar45 = -fVar45;
                }
                fVar52 = fVar45 + fVar52;
              } while ((int)ppppppppppfVar25 < (int)ppppppppppfVar17);
            }
            if (fVar52 < fVar33) {
              fVar33 = fVar52;
            }
            if (*(char *)((int)ppppppppppfVar22 + 0x93) != '\0') goto LAB_0064832c;
            func_00115D70(&local_1edc,(float *)ppppppppppfVar22,fVar33);
            local_1ecc = (float ***********)CF_FBITS(local_1edc);
            local_1ec8 = (float ************)local_1ed8;
            local_1ec4 = (float ***********)local_1ed4;
            func_00115C70((float *)&local_1ee4,(float *)&local_1e2c,(float *)&local_1ecc);
            ppppppppppfVar22[0xf] = (float *********)local_1ee4;
            ppppppppppfVar22[0x10] = (float *********)local_1ee0;
            ppppppppppfVar22[0x11] = (float *********)CF_FBITS(local_1edc);
          }
          else {
LAB_0064832c:
            local_1edc = -ALBW_AS_F32(*ppppppppppfVar22);
            local_1ed8 = (float ***********)CF_FBITS(-ALBW_AS_F32(ppppppppppfVar22[1]));
            local_1ed4 = (float ************)CF_FBITS(-ALBW_AS_F32(ppppppppppfVar22[2]));
            func_00115D70((float *)&local_1ee8,&local_1edc,fVar33);
            local_1ecc = local_1ee8;
            local_1ec8 = (float ************)local_1ee4;
            local_1ec4 = local_1ee0;
            func_00115C54((float *)(ppppppppppfVar22 + 0x15),(float *)(ppppppppppfVar22 + 0x15),
                          (float *)&local_1ecc);
          }
          if (*(char *)((int)ppppppppppfVar22 + 0x93) == '\0') {
            func_00115D70((float *)&local_1ed4,(float *)(ppppppppppfVar22 + 3),ALBW_AS_F32(uVar59));
            local_1ee4 = (float ***********)local_1ed4;
            local_1ee0 = local_1ed0;
            local_1edc = ALBW_AS_F32(local_1ecc);
            func_00115D70((float *)&local_1ed8,(float *)&local_1ee4,fVar48);
            local_1e90 = (float ************)local_1ed8;
            local_1e8c = (float ***********)local_1ed4;
            local_1e88 = local_1ed0;
            func_00115C54((float *)(ppppppppppfVar22 + 0xf),(float *)(ppppppppppfVar22 + 0xf),
                          (float *)&local_1e90);
          }
          *(undefined1 *)(ppppppppppfVar22 + 0x25) = 1;
          if (*(char *)((int)ppppppppppfVar9 + 0x93) == '\0') {
            if (*(char *)((int)ppppppppppfVar22 + 0x93) == '\0') {
              func_00115C70((float *)&local_1ed0,(float *)(ppppppppppfVar22 + 0x15),
                            (float *)(ppppppppppfVar22 + 0xf));
              func_00115D70((float *)&local_1ed4,(float *)(ppppppppppfVar22 + 6),
                            ALBW_AS_F32(ppppppppppfVar22[6]) * ALBW_AS_F32(local_1ed0) +
                            ALBW_AS_F32(ppppppppppfVar22[7]) * ALBW_AS_F32(local_1ecc) +
                            ALBW_AS_F32(ppppppppppfVar22[8]) * ALBW_AS_F32(local_1ec8));
              local_1e90 = local_1ed4;
              local_1e8c = local_1ed0;
              local_1e88 = local_1ecc;
              func_00115C70(&local_1edc,(float *)(ppppppppppfVar22 + 0x15),(float *)&local_1e90);
              local_1e48 = (float ***********)CF_FBITS(local_1edc);
              local_1e44 = local_1ed8;
              local_1e40 = (float ***********)local_1ed4;
            }
            else {
              local_1e48 = (float ***********)ppppppppppfVar22[0xf];
              local_1e44 = (float ***********)ppppppppppfVar22[0x10];
              local_1e40 = (float ***********)ppppppppppfVar22[0x11];
            }
            if (*(char *)((int)ppppppppppfVar22 + 0x93) == '\0') {
              func_00115C70((float *)&local_1ed0,(float *)(ppppppppppfVar22 + 0xf),
                            (float *)&local_1e48);
              local_1edc = ALBW_AS_F32(local_1ed0);
              local_1ed8 = local_1ecc;
              local_1ed4 = local_1ec8;
              func_0068906C((float *)&local_1ee8,&local_1edc);
            }
            else {
              func_00115C70((float *)&local_1ed0,(float *)(ppppppppppfVar22 + 0x15),
                            (float *)&local_1e48);
              local_1edc = ALBW_AS_F32(local_1ed0);
              local_1ed8 = local_1ecc;
              local_1ed4 = local_1ec8;
              func_0068906C((float *)&local_1ee8,&local_1edc);
            }
            iVar6 = DAT_00647824;
            fVar48 = ALBW_AS_F32(ppppppppppfVar9[6]) * ALBW_AS_F32(local_1ee8) +
                     ALBW_AS_F32(ppppppppppfVar9[7]) * ALBW_AS_F32(local_1ee4) +
                     ALBW_AS_F32(ppppppppppfVar9[8]) * ALBW_AS_F32(local_1ee0);
            fVar33 = fVar48;
            if (fVar48 <= fVar43) {
              fVar33 = -fVar48;
            }
            if (DAT_00647824 < (int)ALBW_AS_U32(fVar33)) {
              func_00115C70(&local_1edc,(float *)&local_1e48,(float *)(ppppppppppfVar9 + 0xc));
              fVar33 = -(ALBW_AS_F32(ppppppppppfVar9[6]) * local_1edc +
                         ALBW_AS_F32(ppppppppppfVar9[7]) * ALBW_AS_F32(local_1ed8) +
                        ALBW_AS_F32(ppppppppppfVar9[8]) * ALBW_AS_F32(local_1ed4));
              if (fVar33 <= fVar43) {
                if ((uint)ALBW_AS_U32(DAT_00648988) < (uint)ALBW_AS_U32(fVar33)) {
                  func_00115C70((float *)&local_1e74,(float *)(ppppppppppfVar22 + 0xc),
                                (float *)(ppppppppppfVar22 + 9));
                  func_00115D70((float *)&local_1e74,(float *)ppppppppppfVar9,
                                ALBW_AS_F32(*ppppppppppfVar22) * ALBW_AS_F32(local_1e74) +
                                ALBW_AS_F32(ppppppppppfVar22[1]) * ALBW_AS_F32(local_1e70) +
                                ALBW_AS_F32(ppppppppppfVar22[2]) * ALBW_AS_F32(local_1e6c));
                  local_1ecc = (float ***********)local_1e74;
                  local_1ec8 = (float ************)local_1e70;
                  local_1ec4 = local_1e6c;
                  func_00115C54((float *)&local_1e74,(float *)&local_1e38,(float *)&local_1ecc);
                  ppppppppppfVar9[0x12] = (float *********)local_1e74;
                  ppppppppppfVar9[0x13] = (float *********)local_1e70;
                  ppppppppppfVar9[0x14] = (float *********)local_1e6c;
                  func_00115D70((float *)&local_1e74,(float *)(ppppppppppfVar9 + 3),ALBW_AS_F32(uVar59));
                  local_1edc = ALBW_AS_F32(local_1e74);
                  local_1ed8 = local_1e70;
                  local_1ed4 = (float ************)local_1e6c;
                  func_00115D70((float *)&local_1e74,&local_1edc,fVar53);
                  local_1ecc = (float ***********)local_1e74;
                  local_1ec8 = (float ************)local_1e70;
                  local_1ec4 = local_1e6c;
                  func_00115C54((float *)(ppppppppppfVar9 + 0x12),(float *)(ppppppppppfVar9 + 0x12),
                                (float *)&local_1ecc);
                  *(undefined1 *)((int)ppppppppppfVar9 + 0x95) = 1;
                  if (*(char *)((int)ppppppppppfVar9 + 0x93) == '\0') {
                    local_1e6c = (float ***********)(ppppppppppfVar9 + 0x18);
                    func_00115C70((float *)&local_1e68,(float *)(ppppppppppfVar9 + 0x18),
                                  (float *)(ppppppppppfVar9 + 0x12));
                    func_00115D70((float *)&local_1e68,(float *)(ppppppppppfVar9 + 6),
                                  ALBW_AS_F32(ppppppppppfVar9[6]) * ALBW_AS_F32(local_1e68) +
                                  ALBW_AS_F32(ppppppppppfVar9[7]) * ALBW_AS_F32(local_1e64) +
                                  ALBW_AS_F32(ppppppppppfVar9[8]) * ALBW_AS_F32(local_1e60));
                    local_1e90 = (float ************)local_1e68;
                    local_1e8c = local_1e64;
                    local_1e88 = local_1e60;
                    func_00115C70((float *)&local_1e68,(float *)local_1e6c,(float *)&local_1e90);
                    local_1e48 = local_1e68;
                    local_1e44 = local_1e64;
                    local_1e40 = local_1e60;
                  }
                  else {
                    local_1e48 = (float ***********)ppppppppppfVar9[0x12];
                    local_1e44 = (float ***********)ppppppppppfVar9[0x13];
                    local_1e40 = (float ***********)ppppppppppfVar9[0x14];
                  }
                  if (*(char *)((int)ppppppppppfVar9 + 0x93) == '\0') {
                    func_00115C70((float *)&local_1e74,(float *)(ppppppppppfVar9 + 0x12),
                                  (float *)&local_1e48);
                    local_1e90 = local_1e74;
                    local_1e8c = local_1e70;
                    local_1e88 = local_1e6c;
                    func_0068906C((float *)&local_1ee8,(float *)&local_1e90);
                  }
                  else {
                    func_00115C70((float *)&local_1e74,(float *)(ppppppppppfVar9 + 0x18),
                                  (float *)&local_1e48);
                    local_1e90 = local_1e74;
                    local_1e8c = local_1e70;
                    local_1e88 = local_1e6c;
                    func_0068906C((float *)&local_1ee8,(float *)&local_1e90);
                  }
                  fVar48 = ALBW_AS_F32(ppppppppppfVar22[6]) * ALBW_AS_F32(local_1ee8) +
                           ALBW_AS_F32(ppppppppppfVar22[7]) * ALBW_AS_F32(local_1ee4) +
                           ALBW_AS_F32(ppppppppppfVar22[8]) * ALBW_AS_F32(local_1ee0);
                  fVar33 = fVar48;
                  if (fVar48 <= fVar43) {
                    fVar33 = -fVar48;
                  }
                  if (iVar6 < (int)ALBW_AS_U32(fVar33)) {
                    func_00115C70((float *)&local_1e90,(float *)&local_1e48,
                                  (float *)(ppppppppppfVar22 + 9));
                    fVar33 = -(ALBW_AS_F32(ppppppppppfVar22[6]) * ALBW_AS_F32(local_1e90) +
                              ALBW_AS_F32(ppppppppppfVar22[7]) * ALBW_AS_F32(local_1e8c)) +
                             -(ALBW_AS_F32(ppppppppppfVar22[8]) * ALBW_AS_F32(local_1e88));
                    if (fVar43 < fVar33) {
                      func_00115D70((float *)&local_1e54,(float *)&local_1ee8,fVar33);
                      local_1e74 = (float ************)local_1e54;
                      local_1e70 = local_1e50;
                      local_1e6c = local_1e4c;
                      func_00115D88((float *)&local_1e58,(float *)&local_1e74,fVar48);
                      local_1e68 = local_1e58;
                      local_1e64 = local_1e54;
                      local_1e60 = local_1e50;
                      func_00115C54((float *)&local_1e58,(float *)&local_1e48,(float *)&local_1e68);
                      local_1e90 = (float ************)local_1e58;
                      local_1e8c = local_1e54;
                      local_1e88 = local_1e50;
                      func_00115C70((float *)&local_1e58,(float *)(ppppppppppfVar22 + 0xf),
                                    (float *)&local_1e90);
                      local_1e74 = (float ************)local_1e58;
                      local_1e70 = local_1e54;
                      local_1e6c = local_1e50;
                      if (fVar43 < ALBW_AS_F32(local_1e58) * ALBW_AS_F32(ppppppppppfVar22[3]) +
                                   ALBW_AS_F32(local_1e54) * ALBW_AS_F32(ppppppppppfVar22[4]) +
                                   ALBW_AS_F32(local_1e50) * ALBW_AS_F32(ppppppppppfVar22[5])) {
                        ppppppppppfVar22[0x15] = (float *********)local_1e90;
                        ppppppppppfVar22[0x16] = (float *********)local_1e8c;
                        ppppppppppfVar22[0x17] = (float *********)local_1e88;
                        *(undefined1 *)(ppppppppppfVar22 + 0x25) = 1;
                        if ((*(char *)((int)ppppppppppfVar22 + 0x97) != '\0') &&
                           (*(char *)((int)ppppppppppfVar22 + 0x95) == '\0')) {
                          ppppppppppfVar25 = ppppppppppfVar22 + 0x18;
                          ppppppppppfVar22[0x18] = ppppppppppfVar22[0x15];
                          ppppppppppfVar22[0x19] = ppppppppppfVar22[0x16];
                          pppppppppfVar26 = ppppppppppfVar22[0x17];
                          goto LAB_006489fc;
                        }
                      }
                    }
                  }
                }
              }
              else {
                func_00115D70((float *)&local_1e74,(float *)&local_1ee8,fVar33);
                local_1ecc = (float ***********)local_1e74;
                local_1ec8 = (float ************)local_1e70;
                local_1ec4 = local_1e6c;
                func_00115D88((float *)&local_1e74,(float *)&local_1ecc,fVar48);
                local_1e90 = local_1e74;
                local_1e8c = local_1e70;
                local_1e88 = local_1e6c;
                func_00115C54((float *)&local_1e74,(float *)&local_1e48,(float *)&local_1e90);
                local_1ed8 = (float ***********)local_1e74;
                local_1ed4 = (float ************)local_1e70;
                local_1ed0 = local_1e6c;
                func_00115C70((float *)&local_1e70,(float *)(ppppppppppfVar9 + 0x12),
                              (float *)&local_1ed8);
                local_1ecc = local_1e70;
                local_1ec8 = (float ************)local_1e6c;
                local_1ec4 = local_1e68;
                if (fVar43 < ALBW_AS_F32(local_1e70) * ALBW_AS_F32(ppppppppppfVar9[3]) +
                             ALBW_AS_F32(local_1e6c) * ALBW_AS_F32(ppppppppppfVar9[4]) +
                             ALBW_AS_F32(local_1e68) * ALBW_AS_F32(ppppppppppfVar9[5])) {
                  ppppppppppfVar9[0x18] = (float *********)local_1ed8;
                  ppppppppppfVar9[0x19] = (float *********)local_1ed4;
                  ppppppppppfVar9[0x1a] = (float *********)local_1ed0;
                  *(undefined1 *)((int)ppppppppppfVar9 + 0x95) = 1;
                  if ((*(char *)((int)ppppppppppfVar9 + 0x97) != '\0') &&
                     (*(char *)(ppppppppppfVar9 + 0x25) == '\0')) {
                    ppppppppppfVar25 = ppppppppppfVar9 + 0x15;
                    ppppppppppfVar9[0x15] = ppppppppppfVar9[0x18];
                    ppppppppppfVar9[0x16] = ppppppppppfVar9[0x19];
                    pppppppppfVar26 = ppppppppppfVar9[0x1a];
LAB_006489fc:
                    ppppppppppfVar25[2] = pppppppppfVar26;
                  }
                }
              }
            }
          }
        }
        ppppppppppfVar17 = (float **********)((int)ppppppppppfVar17 + 1);
        local_1e5c = (float ***********)((int)local_1e5c + 1);
      } while ((int)ppppppppppfVar17 < (int)ppppppppppfVar41);
      if (0 < (int)local_1e5c) {
        ppppppppppfVar9 = (float **********)0x0;
        do {
          if (ppppppppppfVar9 < *pppppppppppfVar36) {
            ppppppppppfVar22 = pppppppppppfVar29[0x2b] + (int)ppppppppppfVar9 * 0x27;
          }
          else {
            ppppppppppfVar22 = pppppppppppfVar29[0x2b];
          }
          *(undefined1 *)((int)ppppppppppfVar22 + 0x91) = 1;
          *(undefined1 *)((int)ppppppppppfVar22 + 0x92) = 1;
          if (*(char *)((int)ppppppppppfVar22 + 0x93) == '\0') {
            local_1e84 = (float ***********)ppppppppppfVar22[0x15];
            local_1e80 = (float ***********)ppppppppppfVar22[0x16];
            local_1e7c = (float ***********)ppppppppppfVar22[0x17];
            func_00115C70((float *)&local_1ed4,(float *)&local_1e84,
                          (float *)(ppppppppppfVar22 + 0xf));
            func_00115D70((float *)&local_1e90,(float *)(ppppppppppfVar22 + 6),
                          ALBW_AS_F32(ppppppppppfVar22[6]) * ALBW_AS_F32(local_1ed4) +
                          ALBW_AS_F32(ppppppppppfVar22[7]) * ALBW_AS_F32(local_1ed0) +
                          ALBW_AS_F32(ppppppppppfVar22[8]) * ALBW_AS_F32(local_1ecc));
            local_1ee4 = (float ***********)local_1e90;
            local_1ee0 = local_1e8c;
            local_1edc = ALBW_AS_F32(local_1e88);
            func_00115C70((float *)&local_1e74,(float *)&local_1e84,(float *)&local_1ee4);
            ppppppppppfVar22[0x15] = (float *********)local_1e74;
            ppppppppppfVar22[0x16] = (float *********)local_1e70;
            ppppppppppfVar22[0x17] = (float *********)local_1e6c;
            local_1e84 = (float ***********)ppppppppppfVar22[0x18];
            local_1e80 = (float ***********)ppppppppppfVar22[0x19];
            local_1e7c = (float ***********)ppppppppppfVar22[0x1a];
            func_00115C70((float *)&local_1e68,(float *)&local_1e84,
                          (float *)(ppppppppppfVar22 + 0x12));
            func_00115D70((float *)&local_1e58,(float *)(ppppppppppfVar22 + 6),
                          ALBW_AS_F32(ppppppppppfVar22[6]) * ALBW_AS_F32(local_1e68) +
                          ALBW_AS_F32(ppppppppppfVar22[7]) * ALBW_AS_F32(local_1e64) +
                          ALBW_AS_F32(ppppppppppfVar22[8]) * ALBW_AS_F32(local_1e60));
            local_1ee4 = local_1e58;
            local_1ee0 = local_1e54;
            local_1edc = ALBW_AS_F32(local_1e50);
            func_00115C70((float *)&local_1e4c,(float *)&local_1e84,(float *)&local_1ee4);
            ppppppppppfVar22[0x18] = (float *********)local_1e4c;
            ppppppppppfVar22[0x19] = (float *********)local_1e48;
            ppppppppppfVar22[0x1a] = (float *********)local_1e44;
          }
          ppppppppppfVar9 = (float **********)((int)ppppppppppfVar9 + 1);
        } while ((int)ppppppppppfVar9 <= (int)local_1e5c);
      }
    }
    ppppppppppfVar9 = (float **********)((int)ppppppppppfVar41 + -1);
    if (((int)ppppppppppfVar17 < (int)ppppppppppfVar41) &&
       ((int)ppppppppppfVar17 <= (int)ppppppppppfVar9)) {
      do {
        if ((float **********)((int)ppppppppppfVar9 + -1) < *pppppppppppfVar36) {
          ppppppppppfVar22 = pppppppppppfVar29[0x2b] + ((int)ppppppppppfVar9 + -1) * 0x27;
        }
        else {
          ppppppppppfVar22 = pppppppppppfVar29[0x2b];
        }
        if (ppppppppppfVar9 < *pppppppppppfVar36) {
          ppppppppppfVar25 = pppppppppppfVar29[0x2b] + (int)ppppppppppfVar9 * 0x27;
        }
        else {
          ppppppppppfVar25 = pppppppppppfVar29[0x2b];
        }
        if ((((int)ppppppppppfVar22[7] <= DAT_00649ac8) &&
            ((int)ppppppppppfVar25[7] <= DAT_00649ac8)) ||
           ((int)ALBW_AS_U32((ALBW_AS_F32(*ppppppppppfVar22) * ALBW_AS_F32(ppppppppppfVar25[6]) +
                  ALBW_AS_F32(ppppppppppfVar22[1]) * ALBW_AS_F32(ppppppppppfVar25[7]) +
                 ALBW_AS_F32(ppppppppppfVar22[2]) * ALBW_AS_F32(ppppppppppfVar25[8]))) <= DAT_00648984)) break;
        fVar33 = ALBW_AS_F32(local_30[0x1c]) / ALBW_AS_F32(ppppppppppfVar22[4]);
        uVar50 = (ulonglong)(uint)ALBW_AS_U32(fVar33);
        if (*(char *)((int)ppppppppppfVar22 + 0x93) == '\0') {
          pppppppppppfVar54 = (float ***********)(ppppppppppfVar22 + 0xc);
        }
        else {
          pppppppppppfVar54 = (float ***********)(ppppppppppfVar22 + 0x15);
        }
        fVar48 = ALBW_AS_F32(local_30[0x1c]) / ALBW_AS_F32(ppppppppppfVar25[4]);
        local_1e44 = pppppppppppfVar54;
        func_00115D70((float *)&local_1e68,(float *)(ppppppppppfVar22 + 3),fVar33);
        local_1ed4 = (float ************)local_1e68;
        local_1ed0 = local_1e64;
        local_1ecc = local_1e60;
        func_00115C70((float *)&local_1e68,(float *)pppppppppppfVar54,(float *)&local_1ed4);
        local_1ee0 = local_1e68;
        local_1edc = ALBW_AS_F32(local_1e64);
        local_1ed8 = local_1e60;
        local_1e14 = local_1e68;
        local_1e10 = local_1e64;
        local_1e0c = local_1e60;
        if (*(char *)((int)ppppppppppfVar25 + 0x93) == '\0') {
          pppppppppppfVar54 = (float ***********)(ppppppppppfVar25 + 9);
        }
        else {
          pppppppppppfVar54 = (float ***********)(ppppppppppfVar25 + 0x15);
        }
        local_1ec8 = (float ************)pppppppppppfVar54;
        func_00115D70((float *)&local_1e68,(float *)(ppppppppppfVar25 + 3),fVar48);
        local_1ee0 = local_1e68;
        local_1edc = ALBW_AS_F32(local_1e64);
        local_1ed8 = local_1e60;
        func_00115C70((float *)&local_1e68,(float *)pppppppppppfVar54,(float *)&local_1ee0);
        local_1ed4 = (float ************)local_1e68;
        local_1ed0 = local_1e64;
        local_1ecc = local_1e60;
        local_1e74 = (float ************)local_1e68;
        local_1e70 = local_1e64;
        local_1e6c = local_1e60;
        fVar33 = ALBW_AS_F32(*ppppppppppfVar22) * ALBW_AS_F32(ppppppppppfVar25[6]) +
                 ALBW_AS_F32(ppppppppppfVar22[1]) * ALBW_AS_F32(ppppppppppfVar25[7]) +
                 ALBW_AS_F32(ppppppppppfVar22[2]) * ALBW_AS_F32(ppppppppppfVar25[8]);
        func_00115C70((float *)&local_1e04,(float *)&local_1e14,(float *)local_1ec8);
        fVar33 = -(ALBW_AS_F32(ppppppppppfVar25[6]) * ALBW_AS_F32(local_1e04) +
                   ALBW_AS_F32(ppppppppppfVar25[7]) * ALBW_AS_F32(local_1e00) +
                  ALBW_AS_F32(ppppppppppfVar25[8]) * ALBW_AS_F32(local_1dfc)) / fVar33;
        if (DAT_00649ac8 < (int)ALBW_AS_U32(fVar33)) {
          if (*(char *)((int)ppppppppppfVar22 + 0x93) == '\0') {
            ppppppppppfVar30 = ppppppppppfVar9;
            fVar53 = fVar43;
            if ((int)ppppppppppfVar9 < (int)*pppppppppppfVar36) {
              do {
                if (ppppppppppfVar30 < *pppppppppppfVar36) {
                  ppppppppppfVar31 = pppppppppppfVar29[0x2b] + (int)ppppppppppfVar30 * 0x27;
                }
                else {
                  ppppppppppfVar31 = pppppppppppfVar29[0x2b];
                }
                func_00115C70((float *)&local_1ed8,(float *)(ppppppppppfVar31 + 0xc),
                              (float *)(ppppppppppfVar31 + 9));
                ppppppppppfVar30 = (float **********)((int)ppppppppppfVar30 + 1);
                fVar52 = ALBW_AS_F32(*ppppppppppfVar31) * ALBW_AS_F32(local_1ed8) +
                         ALBW_AS_F32(ppppppppppfVar31[1]) * ALBW_AS_F32(local_1ed4) +
                         ALBW_AS_F32(ppppppppppfVar31[2]) * ALBW_AS_F32(local_1ed0);
                if (fVar52 <= fVar43) {
                  fVar52 = -fVar52;
                }
                fVar53 = fVar52 + fVar53;
              } while ((int)ppppppppppfVar30 < (int)*pppppppppppfVar36);
            }
            if (fVar53 < fVar33) {
              fVar33 = fVar53;
            }
            if (*(char *)((int)ppppppppppfVar22 + 0x93) != '\0') goto LAB_00648e00;
            func_00115D70((float *)&local_1e38,(float *)ppppppppppfVar22,fVar33);
            local_1e68 = local_1e38;
            local_1e64 = local_1e34;
            local_1e60 = local_1e30;
            func_00115C54((float *)&local_1df4,(float *)&local_1e14,(float *)&local_1e68);
            ppppppppppfVar22[0x12] = (float *********)local_1df4;
            ppppppppppfVar22[0x13] = (float *********)local_1df0;
            ppppppppppfVar22[0x14] = (float *********)local_1dec;
          }
          else {
LAB_00648e00:
            func_00115D70((float *)&local_1e20,(float *)ppppppppppfVar22,fVar33);
            local_1e5c = local_1e20;
            local_1e58 = local_1e1c;
            local_1e54 = local_1e18;
            func_00115C54((float *)(ppppppppppfVar22 + 0x18),(float *)(ppppppppppfVar22 + 0x18),
                          (float *)&local_1e5c);
          }
          if (*(char *)((int)ppppppppppfVar22 + 0x93) == '\0') {
            func_00115D70((float *)&local_1ed4,(float *)(ppppppppppfVar22 + 3),ALBW_AS_F32(uVar59));
            local_1ee8 = (float ***********)local_1ed4;
            local_1ee4 = local_1ed0;
            local_1ee0 = local_1ecc;
            func_00115D70((float *)&local_1ed8,(float *)&local_1ee8,ALBW_AS_F32(uVar50));
            local_1e68 = local_1ed8;
            local_1e64 = (float ***********)local_1ed4;
            local_1e60 = local_1ed0;
            func_00115C54((float *)(ppppppppppfVar22 + 0x12),(float *)(ppppppppppfVar22 + 0x12),
                          (float *)&local_1e68);
          }
          *(undefined1 *)((int)ppppppppppfVar22 + 0x95) = 1;
          if (*(char *)((int)ppppppppppfVar25 + 0x93) == '\0') {
            if (*(char *)((int)ppppppppppfVar22 + 0x93) == '\0') {
              local_1e88 = (float ***********)(ppppppppppfVar22 + 0x18);
              func_00115C70((float *)&local_1ed0,(float *)(ppppppppppfVar22 + 0x18),
                            (float *)(ppppppppppfVar22 + 0x12));
              func_00115D70((float *)&local_1ed0,(float *)(ppppppppppfVar22 + 6),
                            ALBW_AS_F32(ppppppppppfVar22[6]) * ALBW_AS_F32(local_1ed0) +
                            ALBW_AS_F32(ppppppppppfVar22[7]) * ALBW_AS_F32(local_1ecc) +
                            ALBW_AS_F32(ppppppppppfVar22[8]) * ALBW_AS_F32(local_1ec8));
              local_1e68 = local_1ed0;
              local_1e64 = local_1ecc;
              local_1e60 = (float ***********)local_1ec8;
              func_00115C70((float *)&local_1ee8,(float *)local_1e88,(float *)&local_1e68);
              local_1e50 = local_1ee8;
              local_1e4c = local_1ee4;
              local_1e48 = local_1ee0;
            }
            else {
              local_1e50 = (float ***********)ppppppppppfVar22[0x12];
              local_1e4c = (float ***********)ppppppppppfVar22[0x13];
              local_1e48 = (float ***********)ppppppppppfVar22[0x14];
            }
            if (*(char *)((int)ppppppppppfVar22 + 0x93) == '\0') {
              func_00115C70((float *)&local_1ed0,(float *)(ppppppppppfVar22 + 0x12),
                            (float *)&local_1e50);
              local_1ee8 = local_1ed0;
              local_1ee4 = local_1ecc;
              local_1ee0 = (float ***********)local_1ec8;
              func_0068906C(&local_1edc,(float *)&local_1ee8);
            }
            else {
              func_00115C70((float *)&local_1ed0,(float *)(ppppppppppfVar22 + 0x18),
                            (float *)&local_1e50);
              local_1ee8 = local_1ed0;
              local_1ee4 = local_1ecc;
              local_1ee0 = (float ***********)local_1ec8;
              func_0068906C(&local_1edc,(float *)&local_1ee8);
            }
            iVar6 = DAT_00649acc;
            fVar53 = ALBW_AS_F32(ppppppppppfVar25[6]) * local_1edc +
                     ALBW_AS_F32(ppppppppppfVar25[7]) * ALBW_AS_F32(local_1ed8) +
                     ALBW_AS_F32(ppppppppppfVar25[8]) * ALBW_AS_F32(local_1ed4);
            fVar33 = fVar53;
            if (fVar53 <= fVar43) {
              fVar33 = -fVar53;
            }
            if (DAT_00649acc < (int)ALBW_AS_U32(fVar33)) {
              func_00115C70((float *)&local_1ee8,(float *)&local_1e50,
                            (float *)(ppppppppppfVar25 + 9));
              fVar33 = -(ALBW_AS_F32(ppppppppppfVar25[6]) * ALBW_AS_F32(local_1ee8) +
                        ALBW_AS_F32(ppppppppppfVar25[7]) * ALBW_AS_F32(local_1ee4)) +
                       -(ALBW_AS_F32(ppppppppppfVar25[8]) * ALBW_AS_F32(local_1ee0));
              if (fVar33 <= fVar43) {
                if ((uint)ALBW_AS_U32(DAT_00648988) < (uint)ALBW_AS_U32(fVar33)) {
                  func_00115C70((float *)&local_1ed0,(float *)(ppppppppppfVar22 + 0xc),
                                (float *)(ppppppppppfVar22 + 9));
                  func_00115D70((float *)&local_1ed0,(float *)ppppppppppfVar25,
                                ALBW_AS_F32(*ppppppppppfVar22) * ALBW_AS_F32(local_1ed0) +
                                ALBW_AS_F32(ppppppppppfVar22[1]) * ALBW_AS_F32(local_1ecc) +
                                ALBW_AS_F32(ppppppppppfVar22[2]) * ALBW_AS_F32(local_1ec8));
                  local_1e38 = local_1ed0;
                  local_1e34 = local_1ecc;
                  local_1e30 = (float ***********)local_1ec8;
                  func_00115C70((float *)&local_1ed0,(float *)&local_1e74,(float *)&local_1e38);
                  ppppppppppfVar25[0xf] = (float *********)local_1ed0;
                  ppppppppppfVar25[0x10] = (float *********)local_1ecc;
                  ppppppppppfVar25[0x11] = (float *********)local_1ec8;
                  func_00115D70((float *)&local_1ed0,(float *)(ppppppppppfVar25 + 3),ALBW_AS_F32(uVar59));
                  local_1e68 = local_1ed0;
                  local_1e64 = local_1ecc;
                  local_1e60 = (float ***********)local_1ec8;
                  func_00115D70((float *)&local_1ed0,(float *)&local_1e68,fVar48);
                  local_1e38 = local_1ed0;
                  local_1e34 = local_1ecc;
                  local_1e30 = (float ***********)local_1ec8;
                  func_00115C54((float *)(ppppppppppfVar25 + 0xf),(float *)(ppppppppppfVar25 + 0xf),
                                (float *)&local_1e38);
                  *(undefined1 *)(ppppppppppfVar25 + 0x25) = 1;
                  if (*(char *)((int)ppppppppppfVar25 + 0x93) == '\0') {
                    local_1e88 = (float ***********)(ppppppppppfVar25 + 0x15);
                    local_1ee0 = (float ***********)(ppppppppppfVar25 + 6);
                    func_00115C70((float *)&local_1ed0,(float *)(ppppppppppfVar25 + 0x15),
                                  (float *)(ppppppppppfVar25 + 0xf));
                    func_00115D70((float *)&local_1ed0,(float *)local_1ee0,
                                  ALBW_AS_F32(ppppppppppfVar25[6]) * ALBW_AS_F32(local_1ed0) +
                                  ALBW_AS_F32(ppppppppppfVar25[7]) * ALBW_AS_F32(local_1ecc) +
                                  ALBW_AS_F32(ppppppppppfVar25[8]) * ALBW_AS_F32(local_1ec8));
                    local_1e5c = local_1ed0;
                    local_1e58 = local_1ecc;
                    local_1e54 = (float ***********)local_1ec8;
                    func_00115C70((float *)&local_1ee8,(float *)local_1e88,(float *)&local_1e5c);
                    local_1e50 = local_1ee8;
                    local_1e4c = local_1ee4;
                    local_1e48 = local_1ee0;
                  }
                  else {
                    local_1e50 = (float ***********)ppppppppppfVar25[0xf];
                    local_1e4c = (float ***********)ppppppppppfVar25[0x10];
                    local_1e48 = (float ***********)ppppppppppfVar25[0x11];
                  }
                  if (*(char *)((int)ppppppppppfVar25 + 0x93) == '\0') {
                    func_00115C70((float *)&local_1ed0,(float *)(ppppppppppfVar25 + 0xf),
                                  (float *)&local_1e50);
                    local_1ee8 = local_1ed0;
                    local_1ee4 = local_1ecc;
                    local_1ee0 = (float ***********)local_1ec8;
                    func_0068906C(&local_1edc,(float *)&local_1ee8);
                  }
                  else {
                    func_00115C70((float *)&local_1ed0,(float *)(ppppppppppfVar25 + 0x15),
                                  (float *)&local_1e50);
                    local_1ee8 = local_1ed0;
                    local_1ee4 = local_1ecc;
                    local_1ee0 = (float ***********)local_1ec8;
                    func_0068906C(&local_1edc,(float *)&local_1ee8);
                  }
                  fVar53 = ALBW_AS_F32(ppppppppppfVar22[6]) * local_1edc +
                           ALBW_AS_F32(ppppppppppfVar22[7]) * ALBW_AS_F32(local_1ed8) +
                           ALBW_AS_F32(ppppppppppfVar22[8]) * ALBW_AS_F32(local_1ed4);
                  fVar33 = fVar53;
                  if (fVar53 <= fVar43) {
                    fVar33 = -fVar53;
                  }
                  if (iVar6 < (int)ALBW_AS_U32(fVar33)) {
                    func_00115C70((float *)&local_1ee8,(float *)&local_1e50,
                                  (float *)(ppppppppppfVar22 + 0xc));
                    fVar33 = -(ALBW_AS_F32(ppppppppppfVar22[6]) * ALBW_AS_F32(local_1ee8) +
                              ALBW_AS_F32(ppppppppppfVar22[7]) * ALBW_AS_F32(local_1ee4)) +
                             -(ALBW_AS_F32(ppppppppppfVar22[8]) * ALBW_AS_F32(local_1ee0));
                    if (fVar43 < fVar33) {
                      func_00115D70((float *)&local_1ed0,&local_1edc,fVar33);
                      local_1e5c = local_1ed0;
                      local_1e58 = local_1ecc;
                      local_1e54 = (float ***********)local_1ec8;
                      func_00115D88((float *)&local_1e20,(float *)&local_1e5c,fVar53);
                      local_1e2c = local_1e20;
                      local_1e28 = local_1e1c;
                      local_1e24 = local_1e18;
                      func_00115C54((float *)&local_1ed0,(float *)&local_1e50,(float *)&local_1e2c);
                      local_1ee8 = local_1ed0;
                      local_1ee4 = local_1ecc;
                      local_1ee0 = (float ***********)local_1ec8;
                      func_00115C70((float *)&local_1e20,(float *)(ppppppppppfVar22 + 0x12),
                                    (float *)&local_1ee8);
                      local_1e5c = local_1e20;
                      local_1e58 = local_1e1c;
                      local_1e54 = local_1e18;
                      if (fVar43 < ALBW_AS_F32(local_1e20) * ALBW_AS_F32(ppppppppppfVar22[3]) +
                                   ALBW_AS_F32(local_1e1c) * ALBW_AS_F32(ppppppppppfVar22[4]) +
                                   ALBW_AS_F32(local_1e18) * ALBW_AS_F32(ppppppppppfVar22[5])) {
                        ppppppppppfVar22[0x18] = (float *********)local_1ee8;
                        ppppppppppfVar22[0x19] = (float *********)local_1ee4;
                        ppppppppppfVar22[0x1a] = (float *********)local_1ee0;
                        *(undefined1 *)((int)ppppppppppfVar22 + 0x95) = 1;
                        if ((*(char *)((int)ppppppppppfVar22 + 0x97) != '\0') &&
                           (*(char *)(ppppppppppfVar22 + 0x25) == '\0')) {
                          ppppppppppfVar30 = ppppppppppfVar22 + 0x15;
                          ppppppppppfVar22[0x15] = ppppppppppfVar22[0x18];
                          ppppppppppfVar22[0x16] = ppppppppppfVar22[0x19];
                          pppppppppfVar26 = ppppppppppfVar22[0x1a];
                          goto LAB_00649494;
                        }
                      }
                    }
                  }
                }
              }
              else {
                func_00115D70((float *)&local_1ee8,&local_1edc,fVar33);
                local_1ed0 = local_1ee8;
                local_1ecc = local_1ee4;
                local_1ec8 = (float ************)local_1ee0;
                func_00115D88((float *)&local_1e5c,(float *)&local_1ed0,fVar53);
                local_1e38 = local_1e5c;
                local_1e34 = local_1e58;
                local_1e30 = local_1e54;
                func_00115C54((float *)&local_1ee8,(float *)&local_1e50,(float *)&local_1e38);
                local_1e68 = local_1ee8;
                local_1e64 = local_1ee4;
                local_1e60 = local_1ee0;
                func_00115C70((float *)&local_1e5c,(float *)(ppppppppppfVar25 + 0xf),
                              (float *)&local_1e68);
                local_1ed0 = local_1e5c;
                local_1ecc = local_1e58;
                local_1ec8 = (float ************)local_1e54;
                if (fVar43 < ALBW_AS_F32(local_1e5c) * ALBW_AS_F32(ppppppppppfVar25[3]) +
                             ALBW_AS_F32(local_1e58) * ALBW_AS_F32(ppppppppppfVar25[4]) +
                             ALBW_AS_F32(local_1e54) * ALBW_AS_F32(ppppppppppfVar25[5])) {
                  ppppppppppfVar25[0x15] = (float *********)local_1e68;
                  ppppppppppfVar25[0x16] = (float *********)local_1e64;
                  ppppppppppfVar25[0x17] = (float *********)local_1e60;
                  *(undefined1 *)(ppppppppppfVar25 + 0x25) = 1;
                  if ((*(char *)((int)ppppppppppfVar25 + 0x97) != '\0') &&
                     (*(char *)((int)ppppppppppfVar25 + 0x95) == '\0')) {
                    ppppppppppfVar30 = ppppppppppfVar25 + 0x18;
                    ppppppppppfVar25[0x18] = ppppppppppfVar25[0x15];
                    ppppppppppfVar25[0x19] = ppppppppppfVar25[0x16];
                    pppppppppfVar26 = ppppppppppfVar25[0x17];
LAB_00649494:
                    ppppppppppfVar30[2] = pppppppppfVar26;
                  }
                }
              }
            }
          }
        }
        fVar33 = -(ALBW_AS_F32(*ppppppppppfVar25) * ALBW_AS_F32(ppppppppppfVar22[6]) +
                   ALBW_AS_F32(ppppppppppfVar25[1]) * ALBW_AS_F32(ppppppppppfVar22[7]) +
                  ALBW_AS_F32(ppppppppppfVar25[2]) * ALBW_AS_F32(ppppppppppfVar22[8]));
        func_00115C70((float *)&local_1ee8,(float *)&local_1e74,(float *)local_1e44);
        fVar53 = ALBW_AS_F32(uVar50);
        fVar33 = -(ALBW_AS_F32(ppppppppppfVar22[6]) * ALBW_AS_F32(local_1ee8) +
                   ALBW_AS_F32(ppppppppppfVar22[7]) * ALBW_AS_F32(local_1ee4) +
                  ALBW_AS_F32(ppppppppppfVar22[8]) * ALBW_AS_F32(local_1ee0)) / fVar33;
        if (DAT_00649ac8 < (int)ALBW_AS_U32(fVar33)) {
          if (*(char *)((int)ppppppppppfVar25 + 0x93) == '\0') {
            ppppppppppfVar30 = (float **********)0x0;
            fVar52 = fVar43;
            if (0 < (int)ppppppppppfVar9) {
              do {
                if (ppppppppppfVar30 < *pppppppppppfVar36) {
                  ppppppppppfVar31 = pppppppppppfVar29[0x2b] + (int)ppppppppppfVar30 * 0x27;
                }
                else {
                  ppppppppppfVar31 = pppppppppppfVar29[0x2b];
                }
                func_00115C70((float *)&local_1ed4,(float *)(ppppppppppfVar31 + 0xc),
                              (float *)(ppppppppppfVar31 + 9));
                fVar53 = ALBW_AS_F32(uVar50);
                ppppppppppfVar30 = (float **********)((int)ppppppppppfVar30 + 1);
                fVar45 = ALBW_AS_F32(*ppppppppppfVar31) * ALBW_AS_F32(local_1ed4) +
                         ALBW_AS_F32(ppppppppppfVar31[1]) * ALBW_AS_F32(local_1ed0) +
                         ALBW_AS_F32(ppppppppppfVar31[2]) * ALBW_AS_F32(local_1ecc);
                if (fVar45 <= fVar43) {
                  fVar45 = -fVar45;
                }
                fVar52 = fVar45 + fVar52;
              } while ((int)ppppppppppfVar30 < (int)ppppppppppfVar9);
            }
            if (fVar52 < fVar33) {
              fVar33 = fVar52;
            }
            if (*(char *)((int)ppppppppppfVar25 + 0x93) != '\0') goto LAB_006495a0;
            func_00115D70(&local_1edc,(float *)ppppppppppfVar25,fVar33);
            local_1ed0 = (float ***********)CF_FBITS(local_1edc);
            local_1ecc = local_1ed8;
            local_1ec8 = local_1ed4;
            func_00115C70((float *)&local_1ee0,(float *)&local_1e74,(float *)&local_1ed0);
            ppppppppppfVar25[0xf] = (float *********)local_1ee0;
            ppppppppppfVar25[0x10] = (float *********)CF_FBITS(local_1edc);
            ppppppppppfVar25[0x11] = (float *********)local_1ed8;
          }
          else {
LAB_006495a0:
            local_1ed4 = (float ************)CF_FBITS(-ALBW_AS_F32(*ppppppppppfVar25));
            local_1ed0 = (float ***********)CF_FBITS(-ALBW_AS_F32(ppppppppppfVar25[1]));
            local_1ecc = (float ***********)CF_FBITS(-ALBW_AS_F32(ppppppppppfVar25[2]));
            func_00115D70((float *)&local_1ee8,(float *)&local_1ed4,fVar33);
            local_1e90 = (float ************)local_1ee8;
            local_1e8c = local_1ee4;
            local_1e88 = local_1ee0;
            func_00115C54((float *)(ppppppppppfVar25 + 0x15),(float *)(ppppppppppfVar25 + 0x15),
                          (float *)&local_1e90);
          }
          if (*(char *)((int)ppppppppppfVar25 + 0x93) == '\0') {
            func_00115D70((float *)&local_1ed4,(float *)(ppppppppppfVar25 + 3),ALBW_AS_F32(uVar59));
            local_1ee4 = (float ***********)local_1ed4;
            local_1ee0 = local_1ed0;
            local_1edc = ALBW_AS_F32(local_1ecc);
            func_00115D70((float *)&local_1ed8,(float *)&local_1ee4,fVar48);
            local_1e90 = (float ************)local_1ed8;
            local_1e8c = (float ***********)local_1ed4;
            local_1e88 = local_1ed0;
            func_00115C54((float *)(ppppppppppfVar25 + 0xf),(float *)(ppppppppppfVar25 + 0xf),
                          (float *)&local_1e90);
          }
          *(undefined1 *)(ppppppppppfVar25 + 0x25) = 1;
          if (*(char *)((int)ppppppppppfVar22 + 0x93) == '\0') {
            if (*(char *)((int)ppppppppppfVar25 + 0x93) == '\0') {
              local_1e90 = (float ************)(ppppppppppfVar25 + 0x15);
              func_00115C70((float *)&local_1e68,(float *)(ppppppppppfVar25 + 0x15),
                            (float *)(ppppppppppfVar25 + 0xf));
              func_00115D70((float *)&local_1e68,(float *)(ppppppppppfVar25 + 6),
                            ALBW_AS_F32(ppppppppppfVar25[6]) * ALBW_AS_F32(local_1e68) +
                            ALBW_AS_F32(ppppppppppfVar25[7]) * ALBW_AS_F32(local_1e64) +
                            ALBW_AS_F32(ppppppppppfVar25[8]) * ALBW_AS_F32(local_1e60));
              local_1e5c = local_1e68;
              local_1e58 = local_1e64;
              local_1e54 = local_1e60;
              func_00115C70(&local_1edc,(float *)local_1e90,(float *)&local_1e5c);
              local_1ed0 = (float ***********)CF_FBITS(local_1edc);
              local_1ecc = local_1ed8;
              local_1ec8 = local_1ed4;
            }
            else {
              local_1ed0 = (float ***********)ppppppppppfVar25[0xf];
              local_1ecc = (float ***********)ppppppppppfVar25[0x10];
              local_1ec8 = (float ************)ppppppppppfVar25[0x11];
            }
            if (*(char *)((int)ppppppppppfVar25 + 0x93) == '\0') {
              func_00115C70((float *)&local_1e90,(float *)(ppppppppppfVar25 + 0xf),
                            (float *)&local_1ed0);
              local_1edc = ALBW_AS_F32(local_1e90);
              local_1ed8 = local_1e8c;
              local_1ed4 = (float ************)local_1e88;
              func_0068906C((float *)&local_1ee8,&local_1edc);
            }
            else {
              func_00115C70((float *)&local_1e90,(float *)(ppppppppppfVar25 + 0x15),
                            (float *)&local_1ed0);
              local_1edc = ALBW_AS_F32(local_1e90);
              local_1ed8 = local_1e8c;
              local_1ed4 = (float ************)local_1e88;
              func_0068906C((float *)&local_1ee8,&local_1edc);
            }
            iVar6 = DAT_00649acc;
            fVar48 = ALBW_AS_F32(ppppppppppfVar22[6]) * ALBW_AS_F32(local_1ee8) +
                     ALBW_AS_F32(ppppppppppfVar22[7]) * ALBW_AS_F32(local_1ee4) +
                     ALBW_AS_F32(ppppppppppfVar22[8]) * ALBW_AS_F32(local_1ee0);
            fVar33 = fVar48;
            if (fVar48 <= fVar43) {
              fVar33 = -fVar48;
            }
            if (DAT_00649acc < (int)ALBW_AS_U32(fVar33)) {
              func_00115C70(&local_1edc,(float *)&local_1ed0,(float *)(ppppppppppfVar22 + 0xc));
              fVar33 = -(ALBW_AS_F32(ppppppppppfVar22[6]) * local_1edc +
                         ALBW_AS_F32(ppppppppppfVar22[7]) * ALBW_AS_F32(local_1ed8) +
                        ALBW_AS_F32(ppppppppppfVar22[8]) * ALBW_AS_F32(local_1ed4));
              if (fVar33 <= fVar43) {
                if ((uint)ALBW_AS_U32(DAT_00648988) < (uint)ALBW_AS_U32(fVar33)) {
                  func_00115C70((float *)&local_1e90,(float *)(ppppppppppfVar25 + 0xc),
                                (float *)(ppppppppppfVar25 + 9));
                  func_00115D70((float *)&local_1e90,(float *)ppppppppppfVar22,
                                ALBW_AS_F32(*ppppppppppfVar25) * ALBW_AS_F32(local_1e90) +
                                ALBW_AS_F32(ppppppppppfVar25[1]) * ALBW_AS_F32(local_1e8c) +
                                ALBW_AS_F32(ppppppppppfVar25[2]) * ALBW_AS_F32(local_1e88));
                  local_1e38 = (float ***********)local_1e90;
                  local_1e34 = local_1e8c;
                  local_1e30 = local_1e88;
                  func_00115C54((float *)&local_1e90,(float *)&local_1e14,(float *)&local_1e38);
                  ppppppppppfVar22[0x12] = (float *********)local_1e90;
                  ppppppppppfVar22[0x13] = (float *********)local_1e8c;
                  ppppppppppfVar22[0x14] = (float *********)local_1e88;
                  func_00115D70((float *)&local_1e90,(float *)(ppppppppppfVar22 + 3),ALBW_AS_F32(uVar59));
                  local_1e5c = (float ***********)local_1e90;
                  local_1e58 = local_1e8c;
                  local_1e54 = local_1e88;
                  func_00115D70((float *)&local_1e90,(float *)&local_1e5c,fVar53);
                  local_1e38 = (float ***********)local_1e90;
                  local_1e34 = local_1e8c;
                  local_1e30 = local_1e88;
                  func_00115C54((float *)(ppppppppppfVar22 + 0x12),
                                (float *)(ppppppppppfVar22 + 0x12),(float *)&local_1e38);
                  *(undefined1 *)((int)ppppppppppfVar22 + 0x95) = 1;
                  if (*(char *)((int)ppppppppppfVar22 + 0x93) == '\0') {
                    local_1e68 = (float ***********)(ppppppppppfVar22 + 0x18);
                    local_1ed4 = (float ************)(ppppppppppfVar22 + 6);
                    func_00115C70((float *)&local_1e90,(float *)(ppppppppppfVar22 + 0x18),
                                  (float *)(ppppppppppfVar22 + 0x12));
                    func_00115D70((float *)&local_1e90,(float *)local_1ed4,
                                  ALBW_AS_F32(ppppppppppfVar22[6]) * ALBW_AS_F32(local_1e90) +
                                  ALBW_AS_F32(ppppppppppfVar22[7]) * ALBW_AS_F32(local_1e8c) +
                                  ALBW_AS_F32(ppppppppppfVar22[8]) * ALBW_AS_F32(local_1e88));
                    local_1e50 = (float ***********)local_1e90;
                    local_1e4c = local_1e8c;
                    local_1e48 = local_1e88;
                    func_00115C70(&local_1edc,(float *)local_1e68,(float *)&local_1e50);
                    local_1ed0 = (float ***********)CF_FBITS(local_1edc);
                    local_1ecc = local_1ed8;
                    local_1ec8 = local_1ed4;
                  }
                  else {
                    local_1ed0 = (float ***********)ppppppppppfVar22[0x12];
                    local_1ecc = (float ***********)ppppppppppfVar22[0x13];
                    local_1ec8 = (float ************)ppppppppppfVar22[0x14];
                  }
                  if (*(char *)((int)ppppppppppfVar22 + 0x93) == '\0') {
                    func_00115C70((float *)&local_1e90,(float *)(ppppppppppfVar22 + 0x12),
                                  (float *)&local_1ed0);
                    local_1edc = ALBW_AS_F32(local_1e90);
                    local_1ed8 = local_1e8c;
                    local_1ed4 = (float ************)local_1e88;
                    func_0068906C((float *)&local_1ee8,&local_1edc);
                  }
                  else {
                    func_00115C70((float *)&local_1e90,(float *)(ppppppppppfVar22 + 0x18),
                                  (float *)&local_1ed0);
                    local_1edc = ALBW_AS_F32(local_1e90);
                    local_1ed8 = local_1e8c;
                    local_1ed4 = (float ************)local_1e88;
                    func_0068906C((float *)&local_1ee8,&local_1edc);
                  }
                  fVar48 = ALBW_AS_F32(ppppppppppfVar25[6]) * ALBW_AS_F32(local_1ee8) +
                           ALBW_AS_F32(ppppppppppfVar25[7]) * ALBW_AS_F32(local_1ee4) +
                           ALBW_AS_F32(ppppppppppfVar25[8]) * ALBW_AS_F32(local_1ee0);
                  fVar33 = fVar48;
                  if (fVar48 <= fVar43) {
                    fVar33 = -fVar48;
                  }
                  if (iVar6 < (int)ALBW_AS_U32(fVar33)) {
                    func_00115C70(&local_1edc,(float *)&local_1ed0,(float *)(ppppppppppfVar25 + 9));
                    fVar33 = -(ALBW_AS_F32(ppppppppppfVar25[6]) * local_1edc +
                              ALBW_AS_F32(ppppppppppfVar25[7]) * ALBW_AS_F32(local_1ed8)) +
                             -(ALBW_AS_F32(ppppppppppfVar25[8]) * ALBW_AS_F32(local_1ed4));
                    if (fVar43 < fVar33) {
                      func_00115D70(&local_1edc,(float *)&local_1ee8,fVar33);
                      local_1e90 = (float ************)CF_FBITS(local_1edc);
                      local_1e8c = local_1ed8;
                      local_1e88 = (float ***********)local_1ed4;
                      func_00115D88((float *)&local_1e2c,(float *)&local_1e90,fVar48);
                      local_1e68 = local_1e2c;
                      local_1e64 = local_1e28;
                      local_1e60 = local_1e24;
                      func_00115C54(&local_1edc,(float *)&local_1ed0,(float *)&local_1e68);
                      local_1e50 = (float ***********)CF_FBITS(local_1edc);
                      local_1e4c = local_1ed8;
                      local_1e48 = (float ***********)local_1ed4;
                      func_00115C70((float *)&local_1e2c,(float *)(ppppppppppfVar25 + 0xf),
                                    (float *)&local_1e50);
                      local_1e88 = local_1e24;
                      local_1e90 = (float ************)local_1e2c;
                      local_1e8c = local_1e28;
                      if (fVar43 < ALBW_AS_F32(local_1e2c) * ALBW_AS_F32(ppppppppppfVar25[3]) +
                                   ALBW_AS_F32(local_1e28) * ALBW_AS_F32(ppppppppppfVar25[4]) +
                                   ALBW_AS_F32(local_1e24) * ALBW_AS_F32(ppppppppppfVar25[5])) {
                        ppppppppppfVar25[0x15] = (float *********)local_1e50;
                        ppppppppppfVar25[0x16] = (float *********)local_1e4c;
                        ppppppppppfVar25[0x17] = (float *********)local_1e48;
                        *(undefined1 *)(ppppppppppfVar25 + 0x25) = 1;
                        if ((*(char *)((int)ppppppppppfVar25 + 0x97) != '\0') &&
                           (*(char *)((int)ppppppppppfVar25 + 0x95) == '\0')) {
                          ppppppppppfVar30 = ppppppppppfVar25 + 0x18;
                          ppppppppppfVar25[0x18] = ppppppppppfVar25[0x15];
                          ppppppppppfVar25[0x19] = ppppppppppfVar25[0x16];
                          pppppppppfVar26 = ppppppppppfVar25[0x17];
                          goto LAB_00649c68;
                        }
                      }
                    }
                  }
                }
              }
              else {
                func_00115D70((float *)&local_1e68,(float *)&local_1ee8,fVar33);
                local_1edc = ALBW_AS_F32(local_1e68);
                local_1ed8 = local_1e64;
                local_1ed4 = (float ************)local_1e60;
                func_00115D88((float *)&local_1e68,&local_1edc,fVar48);
                local_1e54 = local_1e68;
                local_1e50 = local_1e64;
                local_1e4c = local_1e60;
                func_00115C54((float *)&local_1e68,(float *)&local_1ed0,(float *)&local_1e54);
                local_1e90 = (float ************)local_1e68;
                local_1e8c = local_1e64;
                local_1e88 = local_1e60;
                func_00115C70((float *)&local_1e60,(float *)(ppppppppppfVar22 + 0x12),
                              (float *)&local_1e90);
                local_1edc = ALBW_AS_F32(local_1e60);
                local_1ed8 = local_1e5c;
                local_1ed4 = (float ************)local_1e58;
                if (fVar43 < ALBW_AS_F32(local_1e60) * ALBW_AS_F32(ppppppppppfVar22[3]) +
                             ALBW_AS_F32(local_1e5c) * ALBW_AS_F32(ppppppppppfVar22[4]) +
                             ALBW_AS_F32(local_1e58) * ALBW_AS_F32(ppppppppppfVar22[5])) {
                  ppppppppppfVar22[0x18] = (float *********)local_1e90;
                  ppppppppppfVar22[0x19] = (float *********)local_1e8c;
                  ppppppppppfVar22[0x1a] = (float *********)local_1e88;
                  *(undefined1 *)((int)ppppppppppfVar22 + 0x95) = 1;
                  if ((*(char *)((int)ppppppppppfVar22 + 0x97) != '\0') &&
                     (*(char *)(ppppppppppfVar22 + 0x25) == '\0')) {
                    ppppppppppfVar30 = ppppppppppfVar22 + 0x15;
                    ppppppppppfVar22[0x15] = ppppppppppfVar22[0x18];
                    ppppppppppfVar22[0x16] = ppppppppppfVar22[0x19];
                    pppppppppfVar26 = ppppppppppfVar22[0x1a];
LAB_00649c68:
                    ppppppppppfVar30[2] = pppppppppfVar26;
                  }
                }
              }
            }
          }
        }
        ppppppppppfVar9 = (float **********)((int)ppppppppppfVar9 + -1);
        local_1df8 = (float ***********)((int)local_1df8 + 1);
      } while ((int)ppppppppppfVar17 <= (int)ppppppppppfVar9);
      if ((0 < (int)local_1df8) &&
         (ppppppppppfVar41 = (float **********)((int)ppppppppppfVar41 + -1),
         (int)ppppppppppfVar9 <= (int)ppppppppppfVar41)) {
        do {
          if (ppppppppppfVar41 < *pppppppppppfVar36) {
            ppppppppppfVar17 = pppppppppppfVar29[0x2b] + (int)ppppppppppfVar41 * 0x27;
          }
          else {
            ppppppppppfVar17 = pppppppppppfVar29[0x2b];
          }
          *(undefined1 *)((int)ppppppppppfVar17 + 0x91) = 1;
          *(undefined1 *)((int)ppppppppppfVar17 + 0x92) = 1;
          if (*(char *)((int)ppppppppppfVar17 + 0x93) == '\0') {
            local_1e84 = (float ***********)ppppppppppfVar17[0x15];
            local_1e80 = (float ***********)ppppppppppfVar17[0x16];
            local_1e7c = (float ***********)ppppppppppfVar17[0x17];
            func_00115C70((float *)&local_1ef0,(float *)&local_1e84,
                          (float *)(ppppppppppfVar17 + 0xf));
            func_00115D70((float *)&local_1e78,(float *)(ppppppppppfVar17 + 6),
                          ALBW_AS_F32(ppppppppppfVar17[6]) * ALBW_AS_F32(local_1ef0) +
                          ALBW_AS_F32(ppppppppppfVar17[7]) * ALBW_AS_F32(local_1eec) +
                          ALBW_AS_F32(ppppppppppfVar17[8]) * ALBW_AS_F32(local_1ee8));
            local_1e6c = local_1e78;
            local_1e68 = (float ***********)local_1e74;
            local_1e64 = local_1e70;
            func_00115C70((float *)&local_1ee4,(float *)&local_1e84,(float *)&local_1e6c);
            ppppppppppfVar17[0x15] = (float *********)local_1ee4;
            ppppppppppfVar17[0x16] = (float *********)local_1ee0;
            ppppppppppfVar17[0x17] = (float *********)CF_FBITS(local_1edc);
            local_1e84 = (float ***********)ppppppppppfVar17[0x18];
            local_1e80 = (float ***********)ppppppppppfVar17[0x19];
            local_1e7c = (float ***********)ppppppppppfVar17[0x1a];
            func_00115C70((float *)&local_1e60,(float *)&local_1e84,
                          (float *)(ppppppppppfVar17 + 0x12));
            func_00115D70((float *)&local_1ed8,(float *)(ppppppppppfVar17 + 6),
                          ALBW_AS_F32(ppppppppppfVar17[6]) * ALBW_AS_F32(local_1e60) +
                          ALBW_AS_F32(ppppppppppfVar17[7]) * ALBW_AS_F32(local_1e5c) +
                          ALBW_AS_F32(ppppppppppfVar17[8]) * ALBW_AS_F32(local_1e58));
            local_1e6c = local_1ed8;
            local_1e68 = (float ***********)local_1ed4;
            local_1e64 = local_1ed0;
            func_00115C70((float *)&local_1e90,(float *)&local_1e84,(float *)&local_1e6c);
            ppppppppppfVar17[0x18] = (float *********)local_1e90;
            ppppppppppfVar17[0x19] = (float *********)local_1e8c;
            ppppppppppfVar17[0x1a] = (float *********)local_1e88;
          }
          ppppppppppfVar41 = (float **********)((int)ppppppppppfVar41 + -1);
        } while ((int)ppppppppppfVar9 <= (int)ppppppppppfVar41);
      }
    }
  }
  return 0;
LAB_00644650:
  local_1ee8 = (float ***********)0x1;
LAB_00644704:
  uVar19 = 0;
  if (0 < (int)*DAT_00644314) {
    do {
      puVar3 = DAT_00644314;
      uVar13 = DAT_00644314[2];
      if (uVar19 < *DAT_00644314) {
        uVar13 = uVar13 + uVar19 * 0x9c;
      }
      *(undefined1 *)(uVar13 + 0x93) = 1;
      puVar11 = (undefined4 *)puVar3[2];
      if (uVar19 < *puVar3) {
        puVar11 = puVar11 + uVar19 * 0x27;
      }
      ppppppppppfVar9 = *pppppppppppfVar54;
      if ((int)ppppppppppfVar9 < (int)pppppppppppfVar29[0x2a]) {
        ppppppppppfVar41 = pppppppppppfVar29[0x2b];
        *pppppppppppfVar54 = (float **********)((int)ppppppppppfVar9 + 1);
        local_1ed8 = (float ***********)(puVar11 + 9);
        ppppppppppfVar41 = ppppppppppfVar41 + (int)ppppppppppfVar9 * 0x27;
        *ppppppppppfVar41 = (float *********)*puVar11;
        local_1ecc = (float ***********)(ppppppppppfVar41 + 0xc);
        ppppppppppfVar41[1] = (float *********)puVar11[1];
        local_1e70 = (float ***********)(puVar11 + 0xf);
        ppppppppppfVar41[2] = (float *********)puVar11[2];
        ppppppppppfVar41[3] = (float *********)puVar11[3];
        ppppppppppfVar41[4] = (float *********)puVar11[4];
        ppppppppppfVar41[5] = (float *********)puVar11[5];
        ppppppppppfVar41[6] = (float *********)puVar11[6];
        ppppppppppfVar41[7] = (float *********)puVar11[7];
        ppppppppppfVar41[8] = (float *********)puVar11[8];
        ppppppppppfVar41[9] = (float *********)*local_1ed8;
        ppppppppppfVar41[10] = (float *********)puVar11[10];
        ppppppppppfVar41[0xb] = (float *********)puVar11[0xb];
        ppppppppppfVar41[0xc] = (float *********)puVar11[0xc];
        ppppppppppfVar41[0xd] = (float *********)puVar11[0xd];
        ppppppppppfVar41[0xe] = (float *********)puVar11[0xe];
        ppppppppppfVar41[0xf] = (float *********)puVar11[0xf];
        ppppppppppfVar41[0x10] = (float *********)puVar11[0x10];
        ppppppppppfVar41[0x11] = (float *********)puVar11[0x11];
        ppppppppppfVar41[0x12] = (float *********)puVar11[0x12];
        ppppppppppfVar41[0x13] = (float *********)puVar11[0x13];
        ppppppppppfVar41[0x14] = (float *********)puVar11[0x14];
        ppppppppppfVar41[0x15] = (float *********)puVar11[0x15];
        ppppppppppfVar41[0x16] = (float *********)puVar11[0x16];
        ppppppppppfVar41[0x17] = (float *********)puVar11[0x17];
        ppppppppppfVar41[0x18] = (float *********)puVar11[0x18];
        ppppppppppfVar41[0x19] = (float *********)puVar11[0x19];
        ppppppppppfVar41[0x1a] = (float *********)puVar11[0x1a];
        ppppppppppfVar41[0x1b] = (float *********)puVar11[0x1b];
        ppppppppppfVar41[0x1c] = (float *********)puVar11[0x1c];
        ppppppppppfVar41[0x1d] = (float *********)puVar11[0x1d];
        ppppppppppfVar41[0x1e] = (float *********)puVar11[0x1e];
        ppppppppppfVar41[0x1f] = (float *********)puVar11[0x1f];
        ppppppppppfVar41[0x20] = (float *********)puVar11[0x20];
        ppppppppppfVar41[0x21] = (float *********)puVar11[0x21];
        ppppppppppfVar41[0x22] = (float *********)puVar11[0x22];
        ppppppppppfVar41[0x23] = (float *********)puVar11[0x23];
        *(undefined1 *)(ppppppppppfVar41 + 0x24) = *(undefined1 *)(puVar11 + 0x24);
        *(undefined1 *)((int)ppppppppppfVar41 + 0x91) = *(undefined1 *)((int)puVar11 + 0x91);
        *(undefined1 *)((int)ppppppppppfVar41 + 0x92) = *(undefined1 *)((int)puVar11 + 0x92);
        *(undefined1 *)((int)ppppppppppfVar41 + 0x93) = *(undefined1 *)((int)puVar11 + 0x93);
        *(undefined1 *)(ppppppppppfVar41 + 0x25) = *(undefined1 *)(puVar11 + 0x25);
        *(undefined1 *)((int)ppppppppppfVar41 + 0x95) = *(undefined1 *)((int)puVar11 + 0x95);
        *(undefined1 *)((int)ppppppppppfVar41 + 0x96) = *(undefined1 *)((int)puVar11 + 0x96);
        *(undefined1 *)((int)ppppppppppfVar41 + 0x97) = *(undefined1 *)((int)puVar11 + 0x97);
        *(undefined1 *)(ppppppppppfVar41 + 0x26) = *(undefined1 *)(puVar11 + 0x26);
      }
      uVar19 = uVar19 + 1;
    } while ((int)uVar19 < (int)*DAT_00644314);
  }
  if (local_1ee8 != (float ***********)0x0) {
    local_1ed0 = (float ***********)0x1;
  }
  goto LAB_00644988;
LAB_006450b0:
  local_1e78 = (float ***********)0x1;
  goto LAB_00645164;
joined_r0x0064571c:
  for (; (int)pppppppppppfVar36 < (int)pppppppppppfVar8;
      pppppppppppfVar36 = (float ***********)((int)pppppppppppfVar36 + 1)) {
    if (pppppppppppfVar36 < *pppppppppppfVar29) {
      ppppppppppfVar41 = pppppppppppfVar29[2] + (int)pppppppppppfVar36 * 0x27;
    }
    else {
      ppppppppppfVar41 = pppppppppppfVar29[2];
    }
    ppppppppppfVar41[0x1e] = ppppppppppfVar9[0x1c];
    ppppppppppfVar41[0x1f] = ppppppppppfVar9[0x1c];
    ppppppppppfVar41[0x15] = ppppppppppfVar9[0xf];
    ppppppppppfVar41[0x16] = ppppppppppfVar9[0x10];
    ppppppppppfVar41[0x17] = ppppppppppfVar9[0x11];
    ppppppppppfVar41[0x18] = ppppppppppfVar9[0xf];
    ppppppppppfVar41[0x19] = ppppppppppfVar9[0x10];
    ppppppppppfVar41[0x1a] = ppppppppppfVar9[0x11];
    *(undefined1 *)((int)ppppppppppfVar41 + 0x97) = 1;
    if (pppppppppppfVar36 < *pppppppppppfVar29) {
      ppppppppppfVar41 = pppppppppppfVar29[2] + (int)pppppppppppfVar36 * 0x27;
    }
    else {
      ppppppppppfVar41 = pppppppppppfVar29[2];
    }
    iVar6 = *DAT_006455a8;
    if (iVar6 < DAT_006455a8[1]) {
      piVar1 = DAT_006455a8 + 2;
      *DAT_006455a8 = iVar6 + 1;
      puVar11 = (undefined4 *)(*piVar1 + iVar6 * 0x9c);
      local_1e84 = (float ***********)(puVar11 + 9);
      *puVar11 = (undefined4)(uintptr_t)(*ppppppppppfVar41);
      local_1e74 = (float ************)(puVar11 + 0xc);
      puVar11[1] = (undefined4)(uintptr_t)(ppppppppppfVar41[1]);
      local_1ed4 = (float ************)(ppppppppppfVar41 + 0xf);
      puVar11[2] = (undefined4)(uintptr_t)(ppppppppppfVar41[2]);
      local_1e70 = (float ***********)(puVar11 + 0xf);
      puVar11[3] = (undefined4)(uintptr_t)(ppppppppppfVar41[3]);
      puVar11[4] = (undefined4)(uintptr_t)(ppppppppppfVar41[4]);
      puVar11[5] = (undefined4)(uintptr_t)(ppppppppppfVar41[5]);
      puVar11[6] = (undefined4)(uintptr_t)(ppppppppppfVar41[6]);
      puVar11[7] = (undefined4)(uintptr_t)(ppppppppppfVar41[7]);
      puVar11[8] = (undefined4)(uintptr_t)(ppppppppppfVar41[8]);
      *local_1e84 = (float **********)ppppppppppfVar41[9];
      puVar11[10] = (undefined4)(uintptr_t)(ppppppppppfVar41[10]);
      puVar11[0xb] = (undefined4)(uintptr_t)(ppppppppppfVar41[0xb]);
      *local_1e74 = (float ***********)ppppppppppfVar41[0xc];
      puVar11[0xd] = (undefined4)(uintptr_t)(ppppppppppfVar41[0xd]);
      puVar11[0xe] = (undefined4)(uintptr_t)(ppppppppppfVar41[0xe]);
      *local_1e70 = (float **********)*local_1ed4;
      puVar11[0x10] = (undefined4)(uintptr_t)(ppppppppppfVar41[0x10]);
      puVar11[0x11] = (undefined4)(uintptr_t)(ppppppppppfVar41[0x11]);
      puVar11[0x12] = (undefined4)(uintptr_t)(ppppppppppfVar41[0x12]);
      puVar11[0x13] = (undefined4)(uintptr_t)(ppppppppppfVar41[0x13]);
      puVar11[0x14] = (undefined4)(uintptr_t)(ppppppppppfVar41[0x14]);
      puVar11[0x15] = (undefined4)(uintptr_t)(ppppppppppfVar41[0x15]);
      puVar11[0x16] = (undefined4)(uintptr_t)(ppppppppppfVar41[0x16]);
      puVar11[0x17] = (undefined4)(uintptr_t)(ppppppppppfVar41[0x17]);
      puVar11[0x18] = (undefined4)(uintptr_t)(ppppppppppfVar41[0x18]);
      puVar11[0x19] = (undefined4)(uintptr_t)(ppppppppppfVar41[0x19]);
      puVar11[0x1a] = (undefined4)(uintptr_t)(ppppppppppfVar41[0x1a]);
      puVar11[0x1b] = (undefined4)(uintptr_t)(ppppppppppfVar41[0x1b]);
      puVar11[0x1c] = (undefined4)(uintptr_t)(ppppppppppfVar41[0x1c]);
      puVar11[0x1d] = (undefined4)(uintptr_t)(ppppppppppfVar41[0x1d]);
      puVar11[0x1e] = (undefined4)(uintptr_t)(ppppppppppfVar41[0x1e]);
      puVar11[0x1f] = (undefined4)(uintptr_t)(ppppppppppfVar41[0x1f]);
      puVar11[0x20] = (undefined4)(uintptr_t)(ppppppppppfVar41[0x20]);
      puVar11[0x21] = (undefined4)(uintptr_t)(ppppppppppfVar41[0x21]);
      puVar11[0x22] = (undefined4)(uintptr_t)(ppppppppppfVar41[0x22]);
      puVar11[0x23] = (undefined4)(uintptr_t)(ppppppppppfVar41[0x23]);
      *(undefined1 *)(puVar11 + 0x24) = *(undefined1 *)(ppppppppppfVar41 + 0x24);
      *(undefined1 *)((int)puVar11 + 0x91) = *(undefined1 *)((int)ppppppppppfVar41 + 0x91);
      *(undefined1 *)((int)puVar11 + 0x92) = *(undefined1 *)((int)ppppppppppfVar41 + 0x92);
      *(undefined1 *)((int)puVar11 + 0x93) = *(undefined1 *)((int)ppppppppppfVar41 + 0x93);
      *(undefined1 *)(puVar11 + 0x25) = *(undefined1 *)(ppppppppppfVar41 + 0x25);
      *(undefined1 *)((int)puVar11 + 0x95) = *(undefined1 *)((int)ppppppppppfVar41 + 0x95);
      *(undefined1 *)((int)puVar11 + 0x96) = *(undefined1 *)((int)ppppppppppfVar41 + 0x96);
      *(undefined1 *)((int)puVar11 + 0x97) = *(undefined1 *)((int)ppppppppppfVar41 + 0x97);
      *(undefined1 *)(puVar11 + 0x26) = *(undefined1 *)(ppppppppppfVar41 + 0x26);
    }
  }
  iVar6 = *DAT_006455a8;
  if (iVar6 < 1) {
    if ((int)local_1ecc + 1 < (int)*local_1ec4) {
      ppppppppppfVar41 = ppppppppppfVar9;
      if ((float **********)((int)local_1ecc + 1) < *local_1ec4) {
        ppppppppppfVar17 = local_1ec4[2] + ((int)local_1ecc + 1) * 0x27;
      }
      else {
        ppppppppppfVar17 = local_1ec4[2];
      }
      goto LAB_00645a44;
    }
  }
  else {
    ppppppppppfVar41 = (float **********)(DAT_006455a8[2] + iVar6 * 0x9c + -0x9c);
    ppppppppppfVar17 = ppppppppppfVar9;
LAB_00645a44:
    pppppppppfVar26 = ppppppppppfVar41[7];
    iVar2 = (int)pppppppppfVar26 - (int)DAT_0064559c;
    if ((int)pppppppppfVar26 <= (int)DAT_0064559c) {
      pppppppppfVar26 = ppppppppppfVar17[7];
      iVar2 = (int)pppppppppfVar26 - (int)DAT_0064559c;
    }
    if (pppppppppfVar26 != (float *********)DAT_0064559c &&
        iVar2 < 0 == SBORROW4((int)pppppppppfVar26,(int)DAT_0064559c)) {
      pppppppfVar44 =
           (float *******)
           CF_FBITS((ALBW_AS_F32(*ppppppppppfVar41) * ALBW_AS_F32(ppppppppppfVar17[6]) +
            ALBW_AS_F32(ppppppppppfVar41[1]) * ALBW_AS_F32(ppppppppppfVar17[7]) +
           ALBW_AS_F32(ppppppppppfVar41[2]) * ALBW_AS_F32(ppppppppppfVar17[8])));
      if (DAT_00645588 < pppppppfVar44) {
LAB_00645a90:
        local_1edc = 0.0;
      }
      else if (DAT_006455a0 < (int)pppppppfVar44) {
        local_1edc = 2.8026e-45;
        if ((int)local_1ecc + 1 < (int)*local_1ec4) {
          if ((float **********)((int)local_1ecc + 1) < *local_1ec4) {
            ppppppppppfVar41 = local_1ec4[2] + ((int)local_1ecc + 1) * 0x27;
          }
          else {
            ppppppppppfVar41 = local_1ec4[2];
          }
          if (DAT_00645588 <
              (float *******)
              CF_FBITS((ALBW_AS_F32(*ppppppppppfVar9) * ALBW_AS_F32(ppppppppppfVar41[6]) +
               ALBW_AS_F32(ppppppppppfVar9[1]) * ALBW_AS_F32(ppppppppppfVar41[7]) +
              ALBW_AS_F32(ppppppppppfVar9[2]) * ALBW_AS_F32(ppppppppppfVar41[8])))) goto LAB_00645a90;
        }
      }
    }
  }
  if (iVar6 < DAT_006455a8[1]) {
    piVar1 = DAT_006455a8 + 2;
    *DAT_006455a8 = iVar6 + 1;
    puVar11 = (undefined4 *)(*piVar1 + iVar6 * 0x9c);
  }
  else {
    puVar11 = (undefined4 *)0x0;
  }
  if (pppppppppppfVar8 < *pppppppppppfVar29) {
    ppppppppppfVar41 = pppppppppppfVar29[2] + (int)pppppppppppfVar8 * 0x27;
  }
  else {
    ppppppppppfVar41 = pppppppppppfVar29[2];
  }
  if ((uint)ALBW_AS_U32(local_1edc) < (float ***********)0x2) {
    *puVar11 = (undefined4)(uintptr_t)(*ppppppppppfVar9);
    puVar11[1] = (undefined4)(uintptr_t)(ppppppppppfVar9[1]);
    puVar11[2] = (undefined4)(uintptr_t)(ppppppppppfVar9[2]);
    puVar11[3] = (undefined4)(uintptr_t)(ppppppppppfVar9[3]);
    puVar11[4] = (undefined4)(uintptr_t)(ppppppppppfVar9[4]);
    puVar11[5] = (undefined4)(uintptr_t)(ppppppppppfVar9[5]);
    puVar11[6] = (undefined4)(uintptr_t)(ppppppppppfVar9[6]);
    puVar11[7] = (undefined4)(uintptr_t)(ppppppppppfVar9[7]);
    puVar11[8] = (undefined4)(uintptr_t)(ppppppppppfVar9[8]);
    puVar11[9] = (undefined4)(uintptr_t)(ppppppppppfVar9[9]);
    puVar11[10] = (undefined4)(uintptr_t)(ppppppppppfVar9[10]);
    puVar11[0xb] = (undefined4)(uintptr_t)(ppppppppppfVar9[0xb]);
    puVar11[0xc] = (undefined4)(uintptr_t)(ppppppppppfVar9[0xc]);
    puVar11[0xd] = (undefined4)(uintptr_t)(ppppppppppfVar9[0xd]);
    puVar11[0xe] = (undefined4)(uintptr_t)(ppppppppppfVar9[0xe]);
    puVar11[0xf] = (undefined4)(uintptr_t)(ppppppppppfVar9[0xf]);
    puVar11[0x10] = (undefined4)(uintptr_t)(ppppppppppfVar9[0x10]);
    puVar11[0x11] = (undefined4)(uintptr_t)(ppppppppppfVar9[0x11]);
    puVar11[0x12] = (undefined4)(uintptr_t)(ppppppppppfVar9[0x12]);
    puVar11[0x13] = (undefined4)(uintptr_t)(ppppppppppfVar9[0x13]);
    puVar11[0x14] = (undefined4)(uintptr_t)(ppppppppppfVar9[0x14]);
    puVar11[0x15] = (undefined4)(uintptr_t)(ppppppppppfVar9[0x15]);
    puVar11[0x16] = (undefined4)(uintptr_t)(ppppppppppfVar9[0x16]);
    puVar11[0x17] = (undefined4)(uintptr_t)(ppppppppppfVar9[0x17]);
    puVar11[0x18] = (undefined4)(uintptr_t)(ppppppppppfVar9[0x18]);
    puVar11[0x19] = (undefined4)(uintptr_t)(ppppppppppfVar9[0x19]);
    puVar11[0x1a] = (undefined4)(uintptr_t)(ppppppppppfVar9[0x1a]);
    puVar11[0x1b] = (undefined4)(uintptr_t)(ppppppppppfVar9[0x1b]);
    puVar11[0x1c] = (undefined4)(uintptr_t)(ppppppppppfVar9[0x1c]);
    puVar11[0x1d] = (undefined4)(uintptr_t)(ppppppppppfVar9[0x1d]);
    puVar11[0x1e] = (undefined4)(uintptr_t)(ppppppppppfVar9[0x1e]);
    puVar11[0x1f] = (undefined4)(uintptr_t)(ppppppppppfVar9[0x1f]);
    puVar11[0x20] = (undefined4)(uintptr_t)(ppppppppppfVar9[0x20]);
    puVar11[0x21] = (undefined4)(uintptr_t)(ppppppppppfVar9[0x21]);
    puVar11[0x22] = (undefined4)(uintptr_t)(ppppppppppfVar9[0x22]);
    puVar11[0x23] = (undefined4)(uintptr_t)(ppppppppppfVar9[0x23]);
    *(undefined1 *)(puVar11 + 0x24) = *(undefined1 *)(ppppppppppfVar9 + 0x24);
    *(undefined1 *)((int)puVar11 + 0x91) = *(undefined1 *)((int)ppppppppppfVar9 + 0x91);
    *(undefined1 *)((int)puVar11 + 0x92) = *(undefined1 *)((int)ppppppppppfVar9 + 0x92);
    *(undefined1 *)((int)puVar11 + 0x93) = *(undefined1 *)((int)ppppppppppfVar9 + 0x93);
    *(undefined1 *)(puVar11 + 0x25) = *(undefined1 *)(ppppppppppfVar9 + 0x25);
    *(undefined1 *)((int)puVar11 + 0x95) = *(undefined1 *)((int)ppppppppppfVar9 + 0x95);
    *(undefined1 *)((int)puVar11 + 0x96) = *(undefined1 *)((int)ppppppppppfVar9 + 0x96);
    *(undefined1 *)((int)puVar11 + 0x97) = *(undefined1 *)((int)ppppppppppfVar9 + 0x97);
    *(undefined1 *)(puVar11 + 0x26) = *(undefined1 *)(ppppppppppfVar9 + 0x26);
    puVar11[0x1e] = (undefined4)(uintptr_t)(ppppppppppfVar41[0x1c]);
    puVar11[0x1f] = (undefined4)(uintptr_t)(ppppppppppfVar41[0x1d]);
    puVar11[0x15] = (undefined4)(uintptr_t)(ppppppppppfVar41[0xf]);
    puVar11[0x16] = (undefined4)(uintptr_t)(ppppppppppfVar41[0x10]);
    puVar11[0x17] = (undefined4)(uintptr_t)(ppppppppppfVar41[0x11]);
    puVar11[0x18] = (undefined4)(uintptr_t)(ppppppppppfVar41[0x12]);
    puVar11[0x19] = (undefined4)(uintptr_t)(ppppppppppfVar41[0x13]);
    pppppppppfVar26 = ppppppppppfVar41[0x14];
  }
  else {
    if ((float ***********)CF_FBITS(local_1edc) != (float ***********)0x2 &&
        (float ***********)CF_FBITS(local_1edc) != (float ***********)0x3) goto LAB_00645ee8;
    *puVar11 = (undefined4)(uintptr_t)(*ppppppppppfVar41);
    puVar11[1] = (undefined4)(uintptr_t)(ppppppppppfVar41[1]);
    puVar11[2] = (undefined4)(uintptr_t)(ppppppppppfVar41[2]);
    puVar11[3] = (undefined4)(uintptr_t)(ppppppppppfVar41[3]);
    puVar11[4] = (undefined4)(uintptr_t)(ppppppppppfVar41[4]);
    puVar11[5] = (undefined4)(uintptr_t)(ppppppppppfVar41[5]);
    puVar11[6] = (undefined4)(uintptr_t)(ppppppppppfVar41[6]);
    puVar11[7] = (undefined4)(uintptr_t)(ppppppppppfVar41[7]);
    puVar11[8] = (undefined4)(uintptr_t)(ppppppppppfVar41[8]);
    puVar11[9] = (undefined4)(uintptr_t)(ppppppppppfVar41[9]);
    puVar11[10] = (undefined4)(uintptr_t)(ppppppppppfVar41[10]);
    puVar11[0xb] = (undefined4)(uintptr_t)(ppppppppppfVar41[0xb]);
    puVar11[0xc] = (undefined4)(uintptr_t)(ppppppppppfVar41[0xc]);
    puVar11[0xd] = (undefined4)(uintptr_t)(ppppppppppfVar41[0xd]);
    puVar11[0xe] = (undefined4)(uintptr_t)(ppppppppppfVar41[0xe]);
    puVar11[0xf] = (undefined4)(uintptr_t)(ppppppppppfVar41[0xf]);
    puVar11[0x10] = (undefined4)(uintptr_t)(ppppppppppfVar41[0x10]);
    puVar11[0x11] = (undefined4)(uintptr_t)(ppppppppppfVar41[0x11]);
    puVar11[0x12] = (undefined4)(uintptr_t)(ppppppppppfVar41[0x12]);
    puVar11[0x13] = (undefined4)(uintptr_t)(ppppppppppfVar41[0x13]);
    puVar11[0x14] = (undefined4)(uintptr_t)(ppppppppppfVar41[0x14]);
    puVar11[0x15] = (undefined4)(uintptr_t)(ppppppppppfVar41[0x15]);
    puVar11[0x16] = (undefined4)(uintptr_t)(ppppppppppfVar41[0x16]);
    puVar11[0x17] = (undefined4)(uintptr_t)(ppppppppppfVar41[0x17]);
    puVar11[0x18] = (undefined4)(uintptr_t)(ppppppppppfVar41[0x18]);
    puVar11[0x19] = (undefined4)(uintptr_t)(ppppppppppfVar41[0x19]);
    puVar11[0x1a] = (undefined4)(uintptr_t)(ppppppppppfVar41[0x1a]);
    puVar11[0x1b] = (undefined4)(uintptr_t)(ppppppppppfVar41[0x1b]);
    puVar11[0x1c] = (undefined4)(uintptr_t)(ppppppppppfVar41[0x1c]);
    puVar11[0x1d] = (undefined4)(uintptr_t)(ppppppppppfVar41[0x1d]);
    puVar11[0x1e] = (undefined4)(uintptr_t)(ppppppppppfVar41[0x1e]);
    puVar11[0x1f] = (undefined4)(uintptr_t)(ppppppppppfVar41[0x1f]);
    puVar11[0x20] = (undefined4)(uintptr_t)(ppppppppppfVar41[0x20]);
    puVar11[0x21] = (undefined4)(uintptr_t)(ppppppppppfVar41[0x21]);
    puVar11[0x22] = (undefined4)(uintptr_t)(ppppppppppfVar41[0x22]);
    puVar11[0x23] = (undefined4)(uintptr_t)(ppppppppppfVar41[0x23]);
    *(undefined1 *)(puVar11 + 0x24) = *(undefined1 *)(ppppppppppfVar41 + 0x24);
    *(undefined1 *)((int)puVar11 + 0x91) = *(undefined1 *)((int)ppppppppppfVar41 + 0x91);
    *(undefined1 *)((int)puVar11 + 0x92) = *(undefined1 *)((int)ppppppppppfVar41 + 0x92);
    *(undefined1 *)((int)puVar11 + 0x93) = *(undefined1 *)((int)ppppppppppfVar41 + 0x93);
    *(undefined1 *)(puVar11 + 0x25) = *(undefined1 *)(ppppppppppfVar41 + 0x25);
    *(undefined1 *)((int)puVar11 + 0x95) = *(undefined1 *)((int)ppppppppppfVar41 + 0x95);
    *(undefined1 *)((int)puVar11 + 0x96) = *(undefined1 *)((int)ppppppppppfVar41 + 0x96);
    *(undefined1 *)((int)puVar11 + 0x97) = *(undefined1 *)((int)ppppppppppfVar41 + 0x97);
    *(undefined1 *)(puVar11 + 0x26) = *(undefined1 *)(ppppppppppfVar41 + 0x26);
    puVar11[0x1e] = (undefined4)(uintptr_t)(ppppppppppfVar9[0x1c]);
    puVar11[0x1f] = (undefined4)(uintptr_t)(ppppppppppfVar9[0x1d]);
    puVar11[0x15] = (undefined4)(uintptr_t)(ppppppppppfVar9[0xf]);
    puVar11[0x16] = (undefined4)(uintptr_t)(ppppppppppfVar9[0x10]);
    puVar11[0x17] = (undefined4)(uintptr_t)(ppppppppppfVar9[0x11]);
    puVar11[0x18] = (undefined4)(uintptr_t)(ppppppppppfVar9[0x12]);
    puVar11[0x19] = (undefined4)(uintptr_t)(ppppppppppfVar9[0x13]);
    pppppppppfVar26 = ppppppppppfVar9[0x14];
  }
  puVar11[0x1a] = (undefined4)(uintptr_t)(pppppppppfVar26);
LAB_00645ee8:
  pppppppppppfVar36 = (float ***********)((int)pppppppppppfVar8 + 1);
LAB_00645ef0:
  local_1ecc = (float ***********)((int)local_1ecc + 1);
  if ((int)*local_1ec4 <= (int)local_1ecc) goto LAB_00645f0c;
  goto LAB_00645490;
LAB_006473cc:
  do {
    if ((int)pppppppppppfVar8 <= (int)pppppppppppfVar36) break;
    if (pppppppppppfVar36 < *pppppppppppfVar35) {
      ppppppppppfVar9 = pppppppppppfVar54[0x2b] + (int)pppppppppppfVar36 * 0x27;
    }
    else {
      ppppppppppfVar9 = pppppppppppfVar54[0x2b];
    }
    *(undefined1 *)((int)ppppppppppfVar9 + 0x91) = 1;
    if (*(char *)((int)ppppppppppfVar9 + 0x93) == '\0') {
      func_00115C70((float *)&local_1e90,(float *)&local_1e84,(float *)(ppppppppppfVar9 + 0xf));
      func_00115D70((float *)&local_1e90,(float *)(ppppppppppfVar9 + 6),
                    ALBW_AS_F32(ppppppppppfVar9[6]) * ALBW_AS_F32(local_1e90) +
                    ALBW_AS_F32(ppppppppppfVar9[7]) * ALBW_AS_F32(local_1e8c) +
                    ALBW_AS_F32(ppppppppppfVar9[8]) * ALBW_AS_F32(local_1e88));
      local_1ee4 = (float ***********)local_1e90;
      local_1ee0 = local_1e8c;
      local_1edc = ALBW_AS_F32(local_1e88);
      func_00115C70((float *)&local_1e90,(float *)&local_1e84,(float *)&local_1ee4);
      ppppppppppfVar9 = ppppppppppfVar9 + 0xf;
LAB_006473b8:
      *ppppppppppfVar9 = (float *********)local_1e90;
      ppppppppppfVar9[1] = (float *********)local_1e8c;
      ppppppppppfVar9[2] = (float *********)local_1e88;
    }
    else {
      if (pppppppppppfVar36 == pppppppppppfVar29 || !bVar39) {
LAB_006472ec:
        func_00115C70((float *)&local_1e90,(float *)&local_1e84,(float *)(ppppppppppfVar9 + 0xf));
        func_00115D70((float *)&local_1e90,(float *)(ppppppppppfVar9 + 6),
                      ALBW_AS_F32(ppppppppppfVar9[6]) * ALBW_AS_F32(local_1e90) +
                      ALBW_AS_F32(ppppppppppfVar9[7]) * ALBW_AS_F32(local_1e8c) +
                      ALBW_AS_F32(ppppppppppfVar9[8]) * ALBW_AS_F32(local_1e88));
        local_1ee4 = (float ***********)local_1e90;
        local_1ee0 = local_1e8c;
        local_1edc = ALBW_AS_F32(local_1e88);
        func_00115C70((float *)&local_1e90,(float *)&local_1e84,(float *)&local_1ee4);
        ppppppppppfVar9 = ppppppppppfVar9 + 0x15;
        goto LAB_006473b8;
      }
      fVar33 = ALBW_AS_F32(ppppppppppfVar9[6]) * ALBW_AS_F32(local_1e78) +
               ALBW_AS_F32(ppppppppppfVar9[7]) * ALBW_AS_F32(local_1e74) +
               ALBW_AS_F32(ppppppppppfVar9[8]) * ALBW_AS_F32(local_1e70);
      fVar43 = fVar33;
      if (fVar33 <= ALBW_AS_F32(uVar51)) {
        fVar43 = -fVar33;
      }
      if ((int)ALBW_AS_U32(fVar43) <= DAT_00647824) goto LAB_006472ec;
      func_00115C70((float *)&local_1e58,(float *)&local_1e84,(float *)(ppppppppppfVar9 + 9));
      local_1ee8 = local_1e58;
      local_1ee4 = local_1e54;
      local_1ee0 = local_1e50;
      func_00115D70((float *)&local_1e58,(float *)&local_1e78,
                    ALBW_AS_F32(ppppppppppfVar9[6]) * ALBW_AS_F32(local_1e58) +
                    ALBW_AS_F32(ppppppppppfVar9[7]) * ALBW_AS_F32(local_1e54) +
                    ALBW_AS_F32(ppppppppppfVar9[8]) * ALBW_AS_F32(local_1e50));
      local_1e90 = (float ************)local_1e58;
      local_1e8c = local_1e54;
      local_1e88 = local_1e50;
      func_00115D88((float *)&local_1e58,(float *)&local_1e90,fVar33);
      local_1ee8 = local_1e58;
      local_1ee4 = local_1e54;
      local_1ee0 = local_1e50;
      func_00115C70((float *)&local_1dc0,(float *)&local_1e84,(float *)&local_1ee8);
      local_1e6c = local_1dc0;
      local_1e68 = local_1dbc;
      local_1e64 = local_1db8;
      func_00115C70((float *)&local_1e54,(float *)&local_1e6c,(float *)(ppppppppppfVar9 + 0xf));
      local_1e90 = (float ************)local_1e54;
      local_1e8c = local_1e50;
      local_1e88 = local_1e4c;
      if (ALBW_AS_F32(local_1e54) * ALBW_AS_F32(ppppppppppfVar9[3]) +
          ALBW_AS_F32(local_1e50) * ALBW_AS_F32(ppppppppppfVar9[4]) +
          ALBW_AS_F32(local_1e4c) * ALBW_AS_F32(ppppppppppfVar9[5]) <= ALBW_AS_F32(uVar51)) goto LAB_006472ec;
      ppppppppppfVar9[0x15] = (float *********)local_1e6c;
      ppppppppppfVar9[0x16] = (float *********)local_1e68;
      ppppppppppfVar9[0x17] = (float *********)local_1e64;
    }
    pppppppppppfVar36 = (float ***********)((int)pppppppppppfVar36 + 1);
LAB_006473c0:
  } while ((int)pppppppppppfVar36 <= (int)local_1eec);
  goto LAB_006473d4;
}

