/* compilefix: USA 004DE3E0 (EU 004DE3B8), the converted stage-2 text.
 * Fixed (BOOT_LOG 184): the ARM copies this word between a float and an integer (no vcvt), which the
 * converted text wrote as a conversion of the value. */
#include "ghidra_types.h"

extern float func_004DFA60(undefined4 param_1,undefined4 param_2,float fparam_0,float fparam_1, float fparam_2);
extern float DAT_004de7bc;
extern float DAT_004de7c0;
extern undefined4 *DAT_004de7c4;
extern undefined4 *DAT_004de7c8;
extern float DAT_004de7cc;
extern float DAT_004de7d0;
extern float DAT_004de7d4;
extern float DAT_004de7d8;
extern float DAT_004de7dc;
extern float *DAT_004de7e0;
extern undefined4 *DAT_004de7e4;
extern undefined4 *DAT_004de7e8;
extern undefined4 DAT_004de7ec;
extern int DAT_004de7f0;
extern undefined4 *DAT_004de7f4;
extern float DAT_004de7f8;
extern float DAT_004de7fc;
extern float DAT_004de800;
extern undefined4 *DAT_004de804;
extern undefined4 *DAT_004de808;
extern float DAT_004de80c;
extern float DAT_004de810;
extern float *DAT_004de814;
extern undefined4 *DAT_004de8b4;

// USA 004DE3E0 <- EU 004DE3B8 (Ghidra, non-matching)
// GLOBAL DAT_004de7bc float
// GLOBAL DAT_004de7c0 float
// GLOBAL DAT_004de7c4 undefined4 *
// GLOBAL DAT_004de7c8 undefined4 *
// GLOBAL DAT_004de7cc float
// GLOBAL DAT_004de7d0 float
// GLOBAL DAT_004de7d4 float
// GLOBAL DAT_004de7d8 float
// GLOBAL DAT_004de7dc float
// GLOBAL DAT_004de7e0 float *
// GLOBAL DAT_004de7e4 undefined4 *
// GLOBAL DAT_004de7e8 undefined4 *
// GLOBAL DAT_004de7ec undefined4
// GLOBAL DAT_004de7f0 int
// GLOBAL DAT_004de7f4 undefined4 *
// GLOBAL DAT_004de7f8 float
// GLOBAL DAT_004de7fc float
// GLOBAL DAT_004de800 float
// GLOBAL DAT_004de804 undefined4 *
// GLOBAL DAT_004de808 undefined4 *
// GLOBAL DAT_004de80c float
// GLOBAL DAT_004de810 float
// GLOBAL DAT_004de814 float *
// GLOBAL DAT_004de8b4 undefined4 *

void func_004DE3E0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,float fparam_0)

{
  float *pfVar1;
  uint in_fpscr;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  undefined4 uVar9;
  float fVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  
  uVar9 = DAT_004de7ec;
  fVar10 = DAT_004de7d8;
  fVar2 = DAT_004de7d4;
  fVar3 = DAT_004de7d0;
  switch(param_3) {
  default:
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    param_1[4] = 0;
    param_1[5] = 0;
    param_1[6] = 0;
    param_1[7] = 0;
    param_1[8] = 0;
    param_1[9] = 0;
    param_1[10] = 0;
    return;
  case 1:
    fVar3 = func_004DFA60(param_2,param_3,DAT_004de7c0,DAT_004de7bc,fparam_0);
    fVar10 = (float)VectorSignedToFloat(*DAT_004de7c4,(byte)(in_fpscr >> 0x15) & 3);
    fVar2 = (float)VectorSignedToFloat(DAT_004de7c4[-2],(byte)(in_fpscr >> 0x15) & 3);
    fVar2 = func_004DFA60(param_2,param_3,fVar2,fVar10,fparam_0);
    fVar8 = ALBW_AS_F32((int)fVar2);
    fVar10 = (float)VectorSignedToFloat(*DAT_004de7c8,(byte)(in_fpscr >> 0x15) & 3);
    fVar2 = (float)VectorSignedToFloat(DAT_004de7c8[-2],(byte)(in_fpscr >> 0x15) & 3);
    fVar2 = func_004DFA60(param_2,param_3,fVar2,fVar10,fparam_0);
    fVar16 = ALBW_AS_F32((int)fVar2);
    fVar2 = func_004DFA60(param_2,param_3,DAT_004de7d0,DAT_004de7cc,fparam_0);
    fVar10 = func_004DFA60(param_2,param_3,DAT_004de7d4,DAT_004de7d4,fparam_0);
    fVar4 = func_004DFA60(param_2,param_3,DAT_004de7d8,DAT_004de7d8,fparam_0);
    fVar5 = func_004DFA60(param_2,param_3,DAT_004de7dc,DAT_004de7dc,fparam_0);
    pfVar1 = DAT_004de7e0;
    fVar17 = ALBW_AS_F32(VectorFloatToUnsigned(fVar5,3));
    fVar5 = func_004DFA60(param_2,param_3,DAT_004de7e0[-3],*DAT_004de7e0,fparam_0);
    fVar6 = func_004DFA60(param_2,param_3,pfVar1[-2],pfVar1[1],fparam_0);
    fVar7 = func_004DFA60(param_2,param_3,pfVar1[-1],pfVar1[2],fparam_0);
    *param_1 = ALBW_AS_U32(fVar3);
    ((float *)param_1)[9] = fVar7;
    ((float *)param_1)[1] = fVar8;
    ((float *)param_1)[2] = fVar16;
    ((float *)param_1)[3] = fVar2;
    ((float *)param_1)[4] = fVar10;
    ((float *)param_1)[5] = fVar4;
    ((float *)param_1)[6] = fVar17;
    ((float *)param_1)[7] = fVar5;
    ((float *)param_1)[8] = fVar6;
    ((float *)param_1)[10] = 0.0;
    return;
  case 5:
  case 6:
    uVar13 = *DAT_004de7e8;
    uVar11 = *DAT_004de7e4;
    uVar12 = DAT_004de7e4[1];
    uVar14 = DAT_004de7e8[1];
    uVar15 = DAT_004de7e8[2];
    *param_1 = ALBW_AS_U32(DAT_004de7c0);
    param_1[5] = ALBW_AS_U32(fVar10);
    fVar3 = 5.510298e-39;
    param_1[1] = uVar11;
    param_1[2] = uVar12;
    param_1[3] = uVar9;
    param_1[4] = ALBW_AS_U32(fVar2);
    param_1[6] = 0;
    param_1[7] = uVar13;
    param_1[8] = uVar14;
    param_1[9] = uVar15;
    break;
  case 7:
    uVar12 = *DAT_004de7f4;
    uVar11 = DAT_004de7f4[1];
    uVar14 = DAT_004de7f4[2];
    uVar9 = *(undefined4 *)(DAT_004de7f0 + 0x24);
    uVar13 = *(undefined4 *)(DAT_004de7f0 + 0x28);
    *param_1 = ALBW_AS_U32(DAT_004de7c0);
    fVar2 = DAT_004de7fc;
    param_1[1] = uVar9;
    param_1[4] = ALBW_AS_U32(fVar3);
    fVar3 = DAT_004de7f8;
    param_1[5] = ALBW_AS_U32(fVar2);
    param_1[2] = uVar13;
    param_1[3] = ALBW_AS_U32(fVar3);
    param_1[6] = 0;
    param_1[7] = uVar12;
    param_1[8] = uVar11;
    fVar3 = 1.68156e-43;
    param_1[9] = uVar14;
    break;
  case 8:
  case 9:
    fVar2 = func_004DFA60(param_2,param_3,DAT_004de7c0,DAT_004de800,fparam_0);
    fVar10 = (float)VectorSignedToFloat(*DAT_004de804,(byte)(in_fpscr >> 0x15) & 3);
    fVar3 = (float)VectorSignedToFloat(DAT_004de804[-2],(byte)(in_fpscr >> 0x15) & 3);
    fVar3 = func_004DFA60(param_2,param_3,fVar3,fVar10,fparam_0);
    fVar16 = ALBW_AS_F32((int)fVar3);
    fVar10 = (float)VectorSignedToFloat(*DAT_004de808,(byte)(in_fpscr >> 0x15) & 3);
    fVar3 = (float)VectorSignedToFloat(DAT_004de808[-2],(byte)(in_fpscr >> 0x15) & 3);
    fVar3 = func_004DFA60(param_2,param_3,fVar3,fVar10,fparam_0);
    fVar17 = ALBW_AS_F32((int)fVar3);
    fVar3 = DAT_004de7d0;
    fVar10 = func_004DFA60(param_2,param_3,DAT_004de7f8,DAT_004de7d0,fparam_0);
    fVar4 = func_004DFA60(param_2,param_3,fVar3,DAT_004de80c,fparam_0);
    fVar5 = func_004DFA60(param_2,param_3,DAT_004de7fc,DAT_004de810,fparam_0);
    fVar3 = func_004DFA60(param_2,param_3,DAT_004de7dc,DAT_004de7dc,fparam_0);
    pfVar1 = DAT_004de814;
    fVar18 = ALBW_AS_F32(VectorFloatToUnsigned(fVar3,3));
    fVar6 = func_004DFA60(param_2,param_3,DAT_004de814[-3],*DAT_004de814,fparam_0);
    fVar7 = func_004DFA60(param_2,param_3,pfVar1[-2],pfVar1[1],fparam_0);
    fVar8 = func_004DFA60(param_2,param_3,pfVar1[-1],pfVar1[2],fparam_0);
    *param_1 = ALBW_AS_U32(fVar2);
    fVar3 = 5.51013e-39;
    ((float *)param_1)[9] = fVar8;
    ((float *)param_1)[1] = fVar16;
    ((float *)param_1)[2] = fVar17;
    ((float *)param_1)[3] = fVar10;
    ((float *)param_1)[4] = fVar4;
    ((float *)param_1)[5] = fVar5;
    ((float *)param_1)[6] = fVar18;
    ((float *)param_1)[7] = fVar6;
    ((float *)param_1)[8] = fVar7;
    break;
  case 10:
    uVar11 = *DAT_004de8b4;
    uVar13 = DAT_004de8b4[1];
    uVar14 = DAT_004de8b4[2];
    uVar12 = *(undefined4 *)(DAT_004de7f0 + 0x34);
    uVar9 = *(undefined4 *)(DAT_004de7f0 + 0x38);
    fVar3 = 8.265195e-39;
    *param_1 = ALBW_AS_U32(DAT_004de7c0);
    fVar4 = DAT_004de7f8;
    param_1[1] = uVar12;
    param_1[2] = uVar9;
    fVar10 = DAT_004de7d8;
    fVar2 = DAT_004de7d4;
    param_1[3] = ALBW_AS_U32(fVar4);
    param_1[4] = ALBW_AS_U32(fVar2);
    param_1[5] = ALBW_AS_U32(fVar10);
    param_1[6] = 0;
    param_1[7] = uVar11;
    param_1[8] = uVar13;
    param_1[9] = uVar14;
  }
  ((float *)param_1)[10] = fVar3;
  return;
}

