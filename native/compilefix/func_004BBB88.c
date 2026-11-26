/* compilefix: USA 004BBB88, the converted stage-2 text with the whole vector published
 * (a vector returned in s0..s2 on ARM: BOOT_LOG 178). */
#include "ghidra_types.h"

extern int func_00100174(int *param_1);
extern uint *DAT_004bbbe4;
extern float *DAT_004bbbe8;
extern float DAT_004bbbec;
extern float DAT_004bbbf0;
extern float DAT_004bbbf4;
extern int *DAT_004bbbf8;
extern int DAT_004bbbfc;
extern uint DAT_004bbc00;

float *albw_s012_get(void);   /* s0..s2 of a returned vector (native/runtime/vec3ret.c) */

// USA 004BBB88 <- EU 004BBB60 (Ghidra, non-matching)
// GLOBAL DAT_004bbbe4 uint *
// GLOBAL DAT_004bbbe8 float *
// GLOBAL DAT_004bbbec float
// GLOBAL DAT_004bbbf0 float
// GLOBAL DAT_004bbbf4 float
// GLOBAL DAT_004bbbf8 int *
// GLOBAL DAT_004bbbfc int
// GLOBAL DAT_004bbc00 uint

float func_004BBB88(int param_1)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  
  if (((*DAT_004bbbe4 & 1) == 0) &&
     (iVar3 = func_00100174((int *)DAT_004bbbe4), fVar2 = DAT_004bbbf4, fVar4 = DAT_004bbbf0,
     pfVar1 = DAT_004bbbe8, iVar3 != 0)) {
    *DAT_004bbbe8 = DAT_004bbbec;
    pfVar1[1] = fVar4;
    pfVar1[2] = fVar2;
  }
  if ((**(int **)(*DAT_004bbbf8 + 0x1c) < DAT_004bbbfc) &&
     (DAT_004bbc00 < (uint)(*(int **)(*DAT_004bbbf8 + 0x1c))[2])) {
    pfVar1 = DAT_004bbbe8;
  }
  else {
    pfVar1 = (float *)(param_1 + 8);
  }
  { float *albw_v = albw_s012_get(); albw_v[0] = pfVar1[0]; albw_v[1] = pfVar1[1]; albw_v[2] = pfVar1[2]; }
  fVar4 = pfVar1[0];
  return fVar4;
}

