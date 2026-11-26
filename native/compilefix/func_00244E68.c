/* compilefix: USA 00244E68 (EU 00244E68), the converted stage-2 text.
 * Fixed (BOOT_LOG 184): the ARM copies this word between a float and an integer (no vcvt), which the
 * converted text wrote as a conversion of the value. */
#include "ghidra_types.h"

extern float func_00245484(float fparam_0,float fparam_1,float fparam_2);
extern float DAT_00244fd4;
extern float DAT_00244fd8;
extern undefined4 *DAT_00244fdc;
extern undefined4 *DAT_00244fe0;
extern float DAT_00244fe4;
extern float DAT_00244fe8;
extern float DAT_00244fec;
extern float DAT_00244ff0;
extern float DAT_00244ff4;
extern float *DAT_00244ff8;

// USA 00244E68 <- EU 00244E68 (Ghidra, non-matching)
// GLOBAL DAT_00244fd4 float
// GLOBAL DAT_00244fd8 float
// GLOBAL DAT_00244fdc undefined4 *
// GLOBAL DAT_00244fe0 undefined4 *
// GLOBAL DAT_00244fe4 float
// GLOBAL DAT_00244fe8 float
// GLOBAL DAT_00244fec float
// GLOBAL DAT_00244ff0 float
// GLOBAL DAT_00244ff4 float
// GLOBAL DAT_00244ff8 float *

void func_00244E68(undefined4 *param_1,undefined4 param_2,float fparam_0)

{
  float *pfVar1;
  float *pfVar2;
  uint in_fpscr;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  
  fVar3 = func_00245484(DAT_00244fd8,DAT_00244fd4,fparam_0);
  fVar9 = (float)VectorSignedToFloat(*DAT_00244fdc,(byte)(in_fpscr >> 0x15) & 3);
  fVar4 = (float)VectorSignedToFloat(DAT_00244fdc[-2],(byte)(in_fpscr >> 0x15) & 3);
  fVar4 = func_00245484(fVar4,fVar9,fparam_0);
  fVar10 = ALBW_AS_F32((int)fVar4);
  fVar9 = (float)VectorSignedToFloat(*DAT_00244fe0,(byte)(in_fpscr >> 0x15) & 3);
  fVar4 = (float)VectorSignedToFloat(DAT_00244fe0[-2],(byte)(in_fpscr >> 0x15) & 3);
  fVar4 = func_00245484(fVar4,fVar9,fparam_0);
  fVar11 = ALBW_AS_F32((int)fVar4);
  fVar4 = func_00245484(DAT_00244fe8,DAT_00244fe4,fparam_0);
  fVar9 = func_00245484(DAT_00244fec,DAT_00244fec,fparam_0);
  fVar5 = func_00245484(DAT_00244ff0,DAT_00244ff0,fparam_0);
  fVar6 = func_00245484(DAT_00244ff4,DAT_00244ff4,fparam_0);
  pfVar1 = DAT_00244ff8;
  fVar12 = ALBW_AS_F32(VectorFloatToUnsigned(fVar6,3));
  pfVar2 = DAT_00244ff8;
  fVar6 = func_00245484(DAT_00244ff8[-3],*DAT_00244ff8,fparam_0);
  fVar7 = func_00245484(pfVar1[-2],pfVar2[1],fparam_0);
  fVar8 = func_00245484(pfVar1[-1],pfVar2[2],fparam_0);
  *param_1 = ALBW_AS_U32(fVar3);
  ((float *)param_1)[7] = fVar6;
  ((float *)param_1)[8] = fVar7;
  ((float *)param_1)[9] = fVar8;
  ((float *)param_1)[1] = fVar10;
  ((float *)param_1)[2] = fVar11;
  ((float *)param_1)[5] = fVar5;
  ((float *)param_1)[6] = fVar12;
  ((float *)param_1)[3] = fVar4;
  ((float *)param_1)[4] = fVar9;
  ((float *)param_1)[10] = 5.51013e-39;
  return;
}

