/* compilefix: USA 005445F8, the converted stage-2 text with y and z computed as on ARM and the vector published
 * (a vector returned in s0..s2 on ARM: BOOT_LOG 178). */
#include "ghidra_types.h"

extern float *DAT_00544610;

float *albw_s012_get(void);   /* s0..s2 of a returned vector (native/runtime/vec3ret.c) */

// USA 005445F8 <- EU 005445D0 (Ghidra, non-matching)
// GLOBAL DAT_00544610 float *

float func_005445F8(int param_1)

{
  float fVar1;
  
  /* EU 005445D0: v = *DAT_00544610; when active, x and z come from +0x470 / +0x474 / +0x46C */
  float *albw_v = albw_s012_get();
  float x = DAT_00544610[0], y = DAT_00544610[1], z = DAT_00544610[2];
  if (*(char *)(param_1 + 0x47e) != '\0') {
    float a = *(float *)(param_1 + 0x470), b = *(float *)(param_1 + 0x474), c = *(float *)(param_1 + 0x46c);
    int neg = *(char *)(param_1 + 0x42c) == '\x01';
    x = neg ? -(b * a) : b * a;
    z = neg ? -(b * c) : b * c;
  }
  albw_v[0] = x;
  albw_v[1] = y;
  albw_v[2] = z;
  fVar1 = x;
  return fVar1;
}

