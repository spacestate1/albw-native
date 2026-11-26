/* compilefix: USA 0037BD10, the converted stage-2 text with y and z of the hit direction (y was a parameter)
 * (a vector returned in s0..s2 on ARM: BOOT_LOG 178). */
#include "ghidra_types.h"

extern int func_00115D70(float *param_1,float *param_2,float fparam_0);
extern float func_004FBF58(int *param_1);
extern float DAT_0037bd98;
extern float DAT_0037bd9c;
extern int DAT_0037bda0;

float *albw_s012_get(void);   /* s0..s2 of a returned vector (native/runtime/vec3ret.c) */

// USA 0037BD10 <- EU 0037BCEC (Ghidra, non-matching)
// GLOBAL DAT_0037bd98 float
// GLOBAL DAT_0037bd9c float
// GLOBAL DAT_0037bda0 int

void func_0037BD10(int *param_1,int param_2,float fparam_0,float fparam_1)

{
  float fVar1;
  int iVar2;
  uint in_fpscr;
  float fVar3;
  _Alignas(8) unsigned char albw_frame[0x20];
  #define local_20 (*(float *)(albw_frame + 0x0))
  #define fStack_1c (*(float *)(albw_frame + 0x4))
  fVar3 = fparam_1;
  local_20 = func_004FBF58((int *)*param_1);
  fStack_1c = albw_s012_get()[1];
  *(float *)(albw_frame + 0x8) = albw_s012_get()[2];
  func_00115D70((float *)(*param_1 + 0x3dc),&local_20,fparam_0);
  func_00115D70((float *)(param_1 + 8),&local_20,fVar3);
  fVar1 = DAT_0037bd98;
  if (param_2 == 0) {
    fVar3 = DAT_0037bd9c;
  }
  param_1[2] = param_2;
  if (param_2 == 0) {
    param_1[3] = (int)ALBW_AS_U32(fVar3);
  }
  else {
    fVar3 = (float)VectorUnsignedToFloat(param_2,(byte)(in_fpscr >> 0x15) & 3);
    param_1[3] = (int)ALBW_AS_U32((fVar1 / fVar3));
  }
  param_1[1] = 0;
  iVar2 = DAT_0037bda0;
  param_1[5] = 4;
  param_1[6] = iVar2;
  param_1[4] = 0;
  param_1[7] = *(int *)(*param_1 + 1000);
  return;
}

