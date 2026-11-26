/* compilefix: USA 002CEA4C (EU 002CEA28), the converted stage-2 text.
 * Fixed (BOOT_LOG 184): the ARM copies this word between a float and an integer (no vcvt), which the
 * converted text wrote as a conversion of the value. */
#include "ghidra_types.h"

extern float func_002CEFDC(float fparam_0,float fparam_1,float fparam_2);
extern float DAT_002ceb80;
extern float DAT_002ceb84;
extern undefined4 *DAT_002ceb88;
extern undefined4 *DAT_002ceb8c;
extern float DAT_002ceb90;
extern float DAT_002ceb94;
extern float DAT_002ceb98;
extern float DAT_002ceb9c;
extern float DAT_002ceba0;
extern float *DAT_002ceba4;

// USA 002CEA4C <- EU 002CEA28 (Ghidra, non-matching)
// GLOBAL DAT_002ceb80 float
// GLOBAL DAT_002ceb84 float
// GLOBAL DAT_002ceb88 undefined4 *
// GLOBAL DAT_002ceb8c undefined4 *
// GLOBAL DAT_002ceb90 float
// GLOBAL DAT_002ceb94 float
// GLOBAL DAT_002ceb98 float
// GLOBAL DAT_002ceb9c float
// GLOBAL DAT_002ceba0 float
// GLOBAL DAT_002ceba4 float *

void func_002CEA4C(undefined4 *param_1,undefined4 param_2,float fparam_0)

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
  
  fVar3 = func_002CEFDC(DAT_002ceb84,DAT_002ceb80,fparam_0);
  fVar9 = (float)VectorSignedToFloat(*DAT_002ceb88,(byte)(in_fpscr >> 0x15) & 3);
  fVar4 = (float)VectorSignedToFloat(DAT_002ceb88[-2],(byte)(in_fpscr >> 0x15) & 3);
  fVar4 = func_002CEFDC(fVar4,fVar9,fparam_0);
  fVar10 = ALBW_AS_F32((int)fVar4);
  fVar9 = (float)VectorSignedToFloat(*DAT_002ceb8c,(byte)(in_fpscr >> 0x15) & 3);
  fVar4 = (float)VectorSignedToFloat(DAT_002ceb8c[-2],(byte)(in_fpscr >> 0x15) & 3);
  fVar4 = func_002CEFDC(fVar4,fVar9,fparam_0);
  fVar11 = ALBW_AS_F32((int)fVar4);
  fVar4 = func_002CEFDC(DAT_002ceb94,DAT_002ceb90,fparam_0);
  fVar9 = func_002CEFDC(DAT_002ceb98,DAT_002ceb98,fparam_0);
  fVar5 = func_002CEFDC(DAT_002ceb9c,DAT_002ceb9c,fparam_0);
  fVar6 = func_002CEFDC(DAT_002ceba0,DAT_002ceba0,fparam_0);
  pfVar1 = DAT_002ceba4;
  fVar12 = ALBW_AS_F32(VectorFloatToUnsigned(fVar6,3));
  pfVar2 = DAT_002ceba4;
  fVar6 = func_002CEFDC(DAT_002ceba4[-3],*DAT_002ceba4,fparam_0);
  fVar7 = func_002CEFDC(pfVar1[-2],pfVar2[1],fparam_0);
  fVar8 = func_002CEFDC(pfVar1[-1],pfVar2[2],fparam_0);
  *param_1 = ALBW_AS_U32(fVar3);
  ((float *)param_1)[9] = fVar8;
  ((float *)param_1)[1] = fVar10;
  ((float *)param_1)[2] = fVar11;
  ((float *)param_1)[3] = fVar4;
  ((float *)param_1)[4] = fVar9;
  ((float *)param_1)[5] = fVar5;
  ((float *)param_1)[6] = fVar12;
  ((float *)param_1)[7] = fVar6;
  ((float *)param_1)[8] = fVar7;
  ((float *)param_1)[10] = 0.0;
  return;
}

