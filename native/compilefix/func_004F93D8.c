/* compilefix: USA 004F93D8, the converted stage-2 text with the whole vector (component-wise product) published
 * (a vector returned in s0..s2 on ARM: BOOT_LOG 178). */
#include "ghidra_types.h"

extern int func_0054D884(int param_1,uint param_2);

float *albw_s012_get(void);   /* s0..s2 of a returned vector (native/runtime/vec3ret.c) */

// USA 004F93D8 <- EU 004F93B0 (Ghidra, non-matching)

float func_004F93D8(int param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = func_0054D884(*(int *)(param_1 + 0x2d0) + 0x18,param_2);
  { float *albw_v = albw_s012_get(); albw_v[0] = *(float *)(param_1 + 0x14) * *(float *)(iVar1 + 4); albw_v[1] = *(float *)(param_1 + 0x18) * *(float *)(iVar1 + 8); albw_v[2] = *(float *)(param_1 + 0x1c) * *(float *)(iVar1 + 0xc); }
  return *(float *)(param_1 + 0x14) * *(float *)(iVar1 + 4);
}

