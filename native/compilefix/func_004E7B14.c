/* compilefix: USA 004E7B14 (EU 004E7AEC), the converted stage-2 text.
 * Fixed (BOOT_LOG 184): the ARM compares the float's bits (vmov rX, sY; cmp), which the converted text
 * wrote as a conversion of the value to an integer. */
#include "ghidra_types.h"

extern int func_00100118(int param_1,undefined *param_2,int param_3,int param_4);
extern int func_0010A794(undefined4 *param_1);
extern int func_0010BA78(undefined4 param_1);
extern undefined8 func_0010BEC4(int param_1,uint param_2,int *param_3);
extern int func_0010CEE0(undefined4 param_1,int *param_2,undefined4 param_3);
extern int func_00111A64(uint *param_1);
extern int func_00115C54(float *param_1,float *param_2,float *param_3);
extern int func_00133870(int param_1,uint param_2,int param_3);
extern int func_0014E428(int param_1,undefined4 param_2,int param_3,uint param_4,int param_5, undefined1 param_6,undefined1 param_7);
extern int func_0014E904(int param_1,int param_2,int param_3);
extern int func_00150A84(int *param_1,int *param_2,int param_3);
extern int func_0016898C(int param_1,uint *param_2);
extern int func_00168E9C(int *param_1,int param_2,int *param_3);
extern int func_00169688(uint *param_1,uint param_2,int *param_3,int param_4);
extern int func_00169A80(int *param_1,undefined4 param_2,undefined4 param_3,int *param_4);
extern int func_0016A02C(int param_1,int param_2,int *param_3,int param_4);
extern float func_00275FEC(int param_1,undefined4 param_2,uint param_3,uint param_4);
extern int func_002ACC68(undefined4 *param_1);
extern int func_0037D86C(undefined4 *param_1,uint *param_2);
extern undefined4 func_004CF864(int param_1,uint param_2,uint param_3,float fparam_0);
extern int func_004D80A4(float *param_1,uint param_2,float fparam_0);
extern int func_004E6E60(int param_1);
extern int func_004EA104(int param_1,int *param_2,int param_3);
extern int func_004ECF6C(int param_1);
extern int func_0052FBA0(int param_1,uint param_2);
extern int func_0054D89C(int param_1,uint param_2);
extern int func_0054D964(int param_1,uint param_2);
extern float func_0054DE3C(int param_1,uint param_2,int param_3);
extern int func_0066AA1C(undefined4 *param_1,undefined1 param_2);
extern int DAT_004e7f28;
extern int DAT_004e7f2c;
extern undefined4 DAT_004e7f30;
extern undefined4 DAT_004e7f34;
extern undefined4 DAT_004e7f38;
extern undefined4 *DAT_004e7f3c;
extern undefined4 DAT_004e7f40;
extern float DAT_004e7f44;
extern float DAT_004e7f48;
extern uint DAT_004e7f4c;
extern int *DAT_004e7f50;
extern undefined4 *DAT_004e7f54;
extern undefined4 DAT_004e7f58;
extern int DAT_004e7f5c;
extern undefined4 DAT_004e7f60;
extern int *DAT_004e7f64;
extern undefined4 DAT_004e7f68;
extern undefined4 DAT_004e7f6c;
extern undefined4 DAT_004e7f70;
extern undefined *DAT_004e8330;
extern uint DAT_004e8340;
extern float DAT_004e8394;
extern float DAT_004e8398;
extern int *DAT_004e839c;
extern int *DAT_004e83a0;
extern uint DAT_004e83a4;
extern float DAT_004e83a8;
extern uint DAT_004e83ac;
extern int *DAT_004e856c;
extern char s_SE_Fairy_UNMEW_004e854c[];
extern char s_SE_PL_FAIRY_GET_004e855c[];
extern char s_cState_Appear_004e8354[];
extern char s_cState_Carry_004e8384[];
extern char s_cState_FlyAway_004e8374[];
extern char s_cState_Fly_004e8334[];
extern char s_cState_Remedy_004e8344[];
extern char s_cState_Revival_004e8364[];

// USA 004E7B14 <- EU 004E7AEC (Ghidra, non-matching)
// GLOBAL DAT_004e7f28 int
// GLOBAL DAT_004e7f2c int
// GLOBAL DAT_004e7f30 undefined4
// GLOBAL DAT_004e7f34 undefined4
// GLOBAL DAT_004e7f38 undefined4
// GLOBAL DAT_004e7f3c undefined4 *
// GLOBAL DAT_004e7f40 undefined4
// GLOBAL DAT_004e7f44 float
// GLOBAL DAT_004e7f48 float
// GLOBAL DAT_004e7f4c uint
// GLOBAL DAT_004e7f50 int *
// GLOBAL DAT_004e7f54 undefined4 *
// GLOBAL DAT_004e7f58 undefined4
// GLOBAL DAT_004e7f5c int
// GLOBAL DAT_004e7f60 undefined4
// GLOBAL DAT_004e7f64 int *
// GLOBAL DAT_004e7f68 undefined4
// GLOBAL DAT_004e7f6c undefined4
// GLOBAL DAT_004e7f70 undefined4
// GLOBAL DAT_004e8330 undefined *
// GLOBAL DAT_004e8340 uint
// GLOBAL DAT_004e8394 float
// GLOBAL DAT_004e8398 float
// GLOBAL DAT_004e839c int *
// GLOBAL DAT_004e83a0 int *
// GLOBAL DAT_004e83a4 uint
// GLOBAL DAT_004e83a8 float
// GLOBAL DAT_004e83ac uint
// GLOBAL DAT_004e856c int *
// GLOBAL s_SE_Fairy_UNMEW_004e854c string
// GLOBAL s_SE_PL_FAIRY_GET_004e855c string
// GLOBAL s_cState_Appear_004e8354 string
// GLOBAL s_cState_Carry_004e8384 string
// GLOBAL s_cState_FlyAway_004e8374 string
// GLOBAL s_cState_Fly_004e8334 string
// GLOBAL s_cState_Remedy_004e8344 string
// GLOBAL s_cState_Revival_004e8364 string

/* WARNING: Variable defined which should be unmapped: objStack_c8 */
/* WARNING: Variable defined which should be unmapped: objStack_c0 */

int * func_004E7B14(undefined4 *param_1,uint *param_2)

{
  byte bVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  uint uVar5;
  bool bVar6;
  int *piVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  float *pfVar12;
  int iVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  float *pfVar16;
  undefined4 uVar17;
  uint uVar18;
  uint uVar19;
  uint in_fpscr;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  undefined8 uVar24;
  undefined4 uVar25;
  undefined4 uVar26;
  ulonglong uVar27;
  _Alignas(8) unsigned char albw_frame[0xd0];
  #define objStack_c8 ((uint *)(albw_frame + 0x8))
  #define objStack_c0 ((uint *)(albw_frame + 0x10))
  #define local_bc (*(char * *)(albw_frame + 0x14))
  #define local_b8 (*(float *)(albw_frame + 0x18))
  #define local_b4 (*(undefined4 *)(albw_frame + 0x1c))
  #define local_b0 (*(uint *)(albw_frame + 0x20))
  #define local_ac (*(char * *)(albw_frame + 0x24))
  #define local_a8 ((uint *)(albw_frame + 0x28))
  #define local_a0 (*(undefined4 * *)(albw_frame + 0x30))
  #define local_9c (*(undefined4 *)(albw_frame + 0x34))
  #define local_98 (*(undefined4 *)(albw_frame + 0x38))
  #define uStack_94 (*(undefined4 *)(albw_frame + 0x3c))
  #define uStack_90 (*(undefined4 *)(albw_frame + 0x40))
  #define uStack_8c (*(undefined4 *)(albw_frame + 0x44))
  #define local_88 (*(uint *)(albw_frame + 0x48))
  #define local_54 (*(undefined4 *)(albw_frame + 0x7c))
  #define local_50 (*(undefined1 *)(albw_frame + 0x80))
  #define local_4c (*(undefined4 *)(albw_frame + 0x84))
  #define local_48 (*(float *)(albw_frame + 0x88))
  #define local_44 (*(int * *)(albw_frame + 0x8c))
  #define local_40 (*(uint *)(albw_frame + 0x90))
  #define local_3c (*(char * *)(albw_frame + 0x94))
  piVar7 = func_0037D86C(param_1,param_2);
  iVar8 = DAT_004e7f28;
  piVar7[200] = DAT_004e7f28 + 100;
  *piVar7 = iVar8;
  piVar7[0x135] = 0;
  piVar7[0x136] = 0;
  iVar8 = func_0054D964((int)piVar7,0);
  piVar7[0x137] = iVar8;
  iVar8 = func_0054D89C((int)piVar7,0);
  piVar7[0x138] = iVar8;
  puVar9 = func_0010A794(piVar7 + 0x139);
  puVar9[5] = 0;
  puVar9[6] = 0;
  puVar9[7] = 0;
  puVar9[8] = 0;
  puVar9[9] = 0;
  puVar9[10] = 0;
  uVar15 = DAT_004e7f30;
  piVar7 = puVar9 + -0x139;
  puVar9[0xb] = puVar9[-0x3f];
  uVar17 = DAT_004e7f38;
  uVar14 = DAT_004e7f34;
  puVar9[0xc] = *(undefined4 *)(DAT_004e7f2c + 8);
  puVar9[0xe] = uVar15;
  puVar9[0xf] = uVar14;
  puVar9[0xd] = 0;
  fVar20 = func_0054DE3C(piVar7,0,1);
  puVar9[0x10] = ALBW_AS_U32(fVar20);
  fVar20 = DAT_004e7f44;
  uVar15 = DAT_004e7f40;
  uVar24 = CONCAT44(DAT_004e7f40,uVar17);
  puVar9[0x11] = puVar9[-0x45];
  puVar9[0x12] = puVar9[-0x44];
  puVar9[0x13] = puVar9[-0x43];
  uVar18 = DAT_004e7f4c;
  uVar27 = (ulonglong)DAT_004e7f4c;
  uVar14 = DAT_004e7f3c[1];
  uVar17 = DAT_004e7f3c[2];
  puVar9[0x14] = *DAT_004e7f3c;
  puVar9[0x15] = uVar14;
  puVar9[0x16] = uVar17;
  puVar9[0x17] = uVar15;
  puVar9[0x18] = uVar15;
  puVar2 = DAT_004e7f54;
  fVar21 = (float)VectorSignedToFloat((int)(short)param_2[0xb],(byte)(in_fpscr >> 0x15) & 3);
  puVar9[0x19] = ALBW_AS_U32(fVar21);
  fVar22 = fVar21 * DAT_004e7f48;
  puVar9[0x1a] = ALBW_AS_U32(fVar21 * fVar20);
  puVar9[0x1b] = ALBW_AS_U32(fVar22);
  puVar9[0x1c] = uVar18;
  puVar9[0x1d] = uVar15;
  *(undefined1 *)(puVar9 + 0x1e) = 0;
  *(undefined1 *)((int)puVar9 + 0x79) = 0;
  *(undefined1 *)((int)puVar9 + 0x7a) = 0;
  *(undefined1 *)((int)puVar9 + 0x7b) = 1;
  *(undefined1 *)(puVar9 + 0x1f) = 1;
  *(undefined1 *)((int)puVar9 + 0x7d) = 0;
  *(undefined1 *)((int)puVar9 + 0x7e) = 0;
  *(bool *)((int)puVar9 + 0x7f) = *(short *)((int)param_2 + 0x2e) == 1;
  *(bool *)(puVar9 + 0x20) =
       *(char *)(*DAT_004e7f50 + 0x18) == '\a' || *(char *)(*DAT_004e7f50 + 0x18) == '%';
  uVar15 = puVar2[1];
  puVar9[0x23] = *puVar2;
  puVar9[0x24] = uVar15;
  puVar9[0x21] = DAT_004e7f58;
  puVar9[0x22] = piVar7;
  objStack_c8[0] = 1;
  objStack_c8[1] = 0;
  objStack_c0[0] = 0;
  uVar15 = func_0014E428((int)piVar7,0,0,0,1,0,0);
  local_44 = puVar9 + -4;
  puVar9[-4] = uVar15;
  puVar9[-0x36] = uVar15;
  puVar9[-0x35] = puVar9[-1];
  puVar9[-0x32] = puVar9[-2];
  puVar9[-0x18] = puVar9 + 0x21;
  objStack_c8[1] = 7;
  *(undefined2 *)(puVar9[-2] + 0x28) = 7;
  *(uint *)(puVar9[-2] + 0x2c) = *(uint *)(puVar9[-2] + 0x2c) | 0x200000;
  uVar15 = func_0014E904((int)piVar7,2,1);
  iVar8 = DAT_004e7f5c;
  uVar18 = 0;
  puVar9[-3] = uVar15;
  do {
    func_00169688((uint *)puVar9[-3],uVar18,(int *)(iVar8 + uVar18 * 8),
                  *(int *)(puVar9[-0x85] + 0x1c8));
    func_00133870(puVar9[-3],uVar18,puVar9[-4]);
    fVar20 = ALBW_AS_F32(uVar27);
    uVar18 = uVar18 + 1;
  } while ((int)uVar18 < 2);
  func_0016A02C(puVar9[-3],-1,(int *)0xffffffff,0);
  local_a0 = &local_9c;
  uStack_94 = (undefined4)uVar24;
  local_98 = (undefined4)((ulonglong)uVar24 >> 0x20);
  local_a8[1] = 3;
  local_a8[0] = 1;
  local_54 = 10;
  local_50 = 0;
  local_9c = 0;
  local_88 = uVar18 | 0xff;
  uStack_90 = DAT_004e7f60;
  uStack_8c = uStack_94;
  func_0016898C(puVar9[-3],local_a8);
  if (*(short *)((int)param_2 + 0x2a) == 2) {
    func_004D80A4((float *)objStack_c8,puVar9[-0x3f],ALBW_AS_F32(uVar24));
    objStack_c8[1] = (uint)((ulonglong)uVar24 >> 0x20);
    func_00115C54((float *)(puVar9 + -0x45),(float *)(puVar9 + -0x45),(float *)objStack_c8);
  }
  else if (*(short *)((int)param_2 + 0x2a) == 1) {
    func_004D80A4((float *)objStack_c0,puVar9[-0x3f],fVar20);
    local_bc = (char *)((ulonglong)uVar24 >> 0x20);
    if (*(char *)((int)puVar9 + 0x7f) == '\0') {
      pfVar12 = (float *)(puVar9 + -0x45);
      pfVar16 = (float *)objStack_c0;
    }
    else {
      uVar18 = param_2[0x13];
      pfVar12 = (float *)objStack_c0;
      puVar9[9] = uVar18;
      if ((uVar18 == 0) || (iVar8 = func_0052FBA0(*DAT_004e7f64 + 0x3dbbc,uVar18), iVar8 == 0)) {
        pfVar16 = (float *)(puVar9 + -0x45);
      }
      else {
        pfVar16 = (float *)(iVar8 + 0x3d0);
      }
    }
    func_00115C54((float *)(puVar9 + -0x45),pfVar12,pfVar16);
  }
  uVar14 = DAT_004e7f70;
  uVar15 = DAT_004e7f6c;
  fVar20 = ALBW_AS_F32(((ulonglong)uVar24 >> 0x20));
  uVar18 = in_fpscr & 0xfffffff | (uint)(ALBW_AS_F32(puVar9[0x19]) == fVar20) << 0x1e |
           (uint)(fVar20 <= ALBW_AS_F32(puVar9[0x19])) << 0x1d;
  bVar1 = (byte)(uVar18 >> 0x18);
  if (!(bool)(bVar1 >> 5 & 1) || (bool)(bVar1 >> 6)) {
    puVar9[0x19] = DAT_004e7f68;
    puVar9[0x1a] = uVar15;
    puVar9[0x1b] = uVar14;
  }
  puVar9[5] = piVar7;
  *(undefined1 *)((int)puVar9 + 6) = 6;
  iVar8 = func_0010BA78(0x60);
  puVar2 = DAT_004e7f54;
  fVar20 = ALBW_AS_F32(uVar24);
  puVar9[6] = iVar8;
  puVar9[7] = iVar8 + (uint)*(byte *)((int)puVar9 + 6) * 8;
  iVar13 = 6;
  puVar10 = (undefined4 *)(iVar8 + -8);
  do {
    uVar15 = puVar2[0x1d];
    iVar13 = iVar13 + -1;
    puVar10[2] = puVar2[0x1c];
    puVar10[3] = uVar15;
    uVar15 = puVar2[0x1d];
    puVar10[4] = puVar2[0x1c];
    puVar10[5] = uVar15;
    puVar10 = puVar10 + 4;
  } while (iVar13 != 0);
  bVar1 = *(byte *)((int)puVar9 + 6);
  uVar19 = (uint)bVar1;
  puVar10 = (undefined4 *)func_0010BA78(uVar19 << 3);
  puVar9[8] = puVar10;
  if (uVar19 != 0) {
    puVar11 = puVar10 + -2;
    if ((bVar1 & 1) != 0) {
      uVar15 = puVar2[7];
      *puVar10 = puVar2[6];
      puVar10[1] = uVar15;
      puVar11 = puVar10;
    }
    for (iVar8 = (int)uVar19 >> 1; iVar8 != 0; iVar8 = iVar8 + -1) {
      uVar15 = puVar2[7];
      puVar11[2] = puVar2[6];
      puVar11[3] = uVar15;
      uVar15 = puVar2[7];
      puVar11[4] = puVar2[6];
      puVar11[5] = uVar15;
      puVar11 = puVar11 + 4;
    }
  }
  puVar10 = (undefined4 *)func_0010CEE0(0xe0,(int *)0x0,4);
  iVar8 = 0;
  if (puVar10 != (undefined4 *)0x0) {
    *puVar10 = 0x24;
    puVar10[1] = 6;
    iVar8 = func_00100118((int)(puVar10 + 2),DAT_004e8330,0x24,6);
  }
  if (iVar8 != 0) {
    puVar9[3] = iVar8;
    puVar9[2] = 6;
  }
  puVar9[-100] = puVar9;
  *(undefined2 *)((int)puVar9 + -0x18a) = 6;
  uVar19 = DAT_004e8340;
  local_ac = s_cState_Fly_004e8334;
  local_b0 = DAT_004e8340;
  func_0010BEC4((int)puVar9,0,(int *)&local_b0);
  puVar10 = (undefined4 *)puVar9[6];
  uVar25 = puVar2[6];
  uVar26 = puVar2[7];
  uVar14 = puVar2[3];
  uVar17 = puVar2[4];
  uVar15 = puVar2[5];
  *puVar10 = puVar2[2];
  puVar10[1] = uVar14;
  puVar10 = (undefined4 *)puVar9[7];
  *puVar10 = uVar17;
  puVar10[1] = uVar15;
  puVar10 = (undefined4 *)puVar9[8];
  *puVar10 = uVar25;
  puVar10[1] = uVar26;
  local_ac = s_cState_Remedy_004e8344;
  local_b0 = uVar19;
  func_0010BEC4((int)puVar9,1,(int *)&local_b0);
  iVar8 = puVar9[6];
  uVar15 = puVar2[9];
  uVar14 = puVar2[10];
  uVar17 = puVar2[0xb];
  *(undefined4 *)(iVar8 + 8) = puVar2[8];
  *(undefined4 *)(iVar8 + 0xc) = uVar15;
  iVar8 = puVar9[7];
  *(undefined4 *)(iVar8 + 8) = uVar14;
  *(undefined4 *)(iVar8 + 0xc) = uVar17;
  iVar8 = puVar9[8];
  *(undefined4 *)(iVar8 + 8) = uVar25;
  *(undefined4 *)(iVar8 + 0xc) = uVar26;
  local_ac = s_cState_Appear_004e8354;
  local_b0 = uVar19;
  func_0010BEC4((int)puVar9,2,(int *)&local_b0);
  iVar8 = puVar9[6];
  uVar15 = puVar2[0xd];
  uVar14 = puVar2[0xe];
  uVar17 = puVar2[0xf];
  *(undefined4 *)(iVar8 + 0x10) = puVar2[0xc];
  *(undefined4 *)(iVar8 + 0x14) = uVar15;
  iVar8 = puVar9[7];
  *(undefined4 *)(iVar8 + 0x10) = uVar14;
  *(undefined4 *)(iVar8 + 0x14) = uVar17;
  iVar8 = puVar9[8];
  *(undefined4 *)(iVar8 + 0x10) = uVar25;
  *(undefined4 *)(iVar8 + 0x14) = uVar26;
  local_ac = s_cState_Revival_004e8364;
  local_b0 = uVar19;
  func_0010BEC4((int)puVar9,3,(int *)&local_b0);
  iVar8 = puVar9[6];
  uVar15 = puVar2[0x11];
  uVar14 = puVar2[0x12];
  uVar17 = puVar2[0x13];
  *(undefined4 *)(iVar8 + 0x18) = puVar2[0x10];
  *(undefined4 *)(iVar8 + 0x1c) = uVar15;
  iVar8 = puVar9[7];
  *(undefined4 *)(iVar8 + 0x18) = uVar14;
  *(undefined4 *)(iVar8 + 0x1c) = uVar17;
  iVar8 = puVar9[8];
  *(undefined4 *)(iVar8 + 0x18) = uVar25;
  *(undefined4 *)(iVar8 + 0x1c) = uVar26;
  local_ac = s_cState_FlyAway_004e8374;
  local_b0 = uVar19;
  func_0010BEC4((int)puVar9,4,(int *)&local_b0);
  iVar8 = puVar9[6];
  uVar15 = puVar2[0x15];
  uVar14 = puVar2[0x16];
  uVar17 = puVar2[0x17];
  *(undefined4 *)(iVar8 + 0x20) = puVar2[0x14];
  *(undefined4 *)(iVar8 + 0x24) = uVar15;
  iVar8 = puVar9[7];
  *(undefined4 *)(iVar8 + 0x20) = uVar14;
  *(undefined4 *)(iVar8 + 0x24) = uVar17;
  iVar8 = puVar9[8];
  *(undefined4 *)(iVar8 + 0x20) = uVar25;
  *(undefined4 *)(iVar8 + 0x24) = uVar26;
  local_ac = s_cState_Carry_004e8384;
  local_b0 = uVar19;
  func_0010BEC4((int)puVar9,5,(int *)&local_b0);
  iVar8 = puVar9[6];
  uVar15 = puVar2[0x1a];
  uVar14 = puVar2[0x19];
  fVar21 = ALBW_AS_F32(puVar2[0x1b]);
  *(undefined4 *)(iVar8 + 0x28) = puVar2[0x18];
  *(undefined4 *)(iVar8 + 0x2c) = uVar14;
  iVar8 = puVar9[7];
  *(undefined4 *)(iVar8 + 0x28) = uVar15;
  *(float *)(iVar8 + 0x2c) = fVar21;
  piVar3 = DAT_004e839c;
  iVar8 = puVar9[8];
  *(undefined4 *)(iVar8 + 0x28) = uVar25;
  *(undefined4 *)(iVar8 + 0x2c) = uVar26;
  uVar5 = DAT_004e83a4;
  piVar4 = DAT_004e83a0;
  iVar8 = *piVar3;
  switch(*(undefined2 *)((int)param_2 + 0x2a)) {
  case 0:
    fVar21 = DAT_004e8394;
    fVar22 = DAT_004e8398;
    uVar19 = func_00111A64((uint *)(*DAT_004e83a0 + 0x660));
    uVar15 = (undefined4)((ulonglong)uVar5 * (ulonglong)uVar19 >> 0x20);
    puVar9[-0x3f] = uVar15;
    puVar9[0xb] = uVar15;
    uVar19 = func_00111A64((uint *)(*piVar4 + 0x660));
    fVar23 = (float)VectorUnsignedToFloat(uVar19,(byte)(uVar18 >> 0x15) & 3);
    *(bool *)((int)puVar9 + 0x7b) = (int)ALBW_AS_U32((fVar23 * DAT_004e83a8 * fVar20)) < 0x3f000000;
    func_0066AA1C(puVar9,0);
    puVar9[-0x43] = puVar9[0x13];
    puVar9[-0x45] = puVar9[0x11];
    puVar9[-0x44] = puVar9[0x12];
    if (iVar8 != 0) {
      local_bc = (char *)puVar9[-0x45];
      local_b8 = ALBW_AS_F32(puVar9[-0x44]) + fVar21;
      local_4c = puVar9[-0x45];
      local_44 = (int *)puVar9[-0x43];
      local_48 = ALBW_AS_F32(puVar9[-0x44]) - fVar22;
      local_b4 = puVar9[0x13];
      fVar20 = func_00275FEC(iVar8,&local_bc,(uint)&local_4c,0xffffffff);
      if (((int)DAT_004e83ac < (int)ALBW_AS_U32(ALBW_AS_F32(puVar9[-0x44]) - fVar20)) ||
         ((DAT_004e83ac | DAT_004e83ac << 0x1c) < (uint)ALBW_AS_U32(ALBW_AS_F32(puVar9[-0x44]) - fVar20))) {
        uVar18 = param_2[2];
        uVar19 = param_2[3];
        puVar9[-0x45] = param_2[1];
        puVar9[-0x44] = uVar18;
        puVar9[-0x43] = uVar19;
      }
    }
    break;
  case 1:
    func_0066AA1C(puVar9,1);
    local_bc = s_SE_PL_FAIRY_GET_004e855c;
    objStack_c0[0] = uVar19;
    func_004EA104(*DAT_004e856c,(int *)objStack_c0,0);
    break;
  case 2:
  case 4:
    if ((iVar8 != 0) &&
       (fVar20 = DAT_004e8394, fVar21 = DAT_004e8398, bVar6 = func_002ACC68(puVar9 + -0x45), !bVar6)
       ) {
      local_bc = (char *)puVar9[-0x45];
      local_b4 = puVar9[-0x43];
      local_b8 = ALBW_AS_F32(puVar9[-0x44]) + fVar20;
      local_4c = puVar9[-0x45];
      local_44 = (int *)puVar9[-0x43];
      local_48 = ALBW_AS_F32(puVar9[-0x44]) - fVar21;
      fVar20 = func_00275FEC(iVar8,&local_bc,(uint)&local_4c,0xffffffff);
      puVar9[-0x44] = ALBW_AS_U32(fVar20);
      if (fVar20 == -3.4028235e+38) {
        puVar9[-0x44] = param_2[2];
      }
    }
    func_0066AA1C(puVar9,0);
    local_3c = s_SE_Fairy_UNMEW_004e854c;
    local_40 = uVar19;
    func_00150A84(piVar7,(int *)&local_40,0);
    break;
  case 3:
    puVar9[-0x81] = puVar9[-0x81] | 2;
    *(undefined2 *)(puVar9 + -0x2e) = 2;
    func_0066AA1C(puVar9,2);
    *(uint *)(puVar9[-4] + 0x164) = *(uint *)(puVar9[-4] + 0x164) | 1;
    func_004CF864(puVar9[-4],1,0xffffffff,fVar21);
    *(uint *)(*local_44 + 0x164) = *(uint *)(*local_44 + 0x164) | 0x200000;
    break;
  default:
    func_0066AA1C(puVar9,0);
  }
  puVar9[-0x5f] = puVar9[-0x45];
  puVar9[-0x5e] = puVar9[-0x44];
  puVar9[-0x5d] = (int *)puVar9[-0x43];
  func_00169A80((int *)puVar9[-3],puVar9[-0x45],puVar9[-0x44],(int *)puVar9[-0x43]);
  func_00168E9C((int *)puVar9[-3],puVar9[-4],(int *)0x0);
  func_004E6E60((int)piVar7);
  func_004ECF6C((int)piVar7);
  return piVar7;
}

