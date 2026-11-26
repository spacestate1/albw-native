/* compilefix: USA 00513D68, the converted stage-2 text with the whole vector published
 * (a vector returned in s0..s2 on ARM: BOOT_LOG 178). */
#include "ghidra_types.h"

extern int func_00115C54(float *param_1,float *param_2,float *param_3);
extern int func_004D80A4(float *param_1,uint param_2,float fparam_0);
extern float DAT_00513d84;
extern undefined4 DAT_00513d88;

float *albw_s012_get(void);   /* s0..s2 of a returned vector (native/runtime/vec3ret.c) */

// USA 00513D68 <- EU 00513D40 (Ghidra, non-matching)
// GLOBAL DAT_00513d84 float
// GLOBAL DAT_00513d88 undefined4

float func_00513D68(int param_1)

{
  _Alignas(8) unsigned char albw_frame[0x20];
  #define fStack_20 (*(float *)(albw_frame + 0x0))
  #define local_1c (*(undefined4 *)(albw_frame + 0x4))
  #define local_14 ((float *)(albw_frame + 0xc))
  func_004D80A4(&fStack_20,*(uint *)(param_1 + 1000),DAT_00513d84);
  local_1c = DAT_00513d88;
  func_00115C54(local_14,(float *)(param_1 + 0x3d0),&fStack_20);
  { float *albw_v = albw_s012_get(); albw_v[0] = local_14[0]; albw_v[1] = local_14[1]; albw_v[2] = local_14[2]; }
  return local_14[0];
}

