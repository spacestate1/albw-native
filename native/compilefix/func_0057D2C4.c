/* compilefix: USA 0057D2C4 (EU 0057D29C), the converted stage-2 text.
 * Fixed (BOOT_LOG 184): the ARM copies this word between a float and an integer (no vcvt), which the
 * converted text wrote as a conversion of the value. */
#include "ghidra_types.h"

extern float DAT_0057d3b4;

// USA 0057D2C4 <- EU 0057D29C (Ghidra, non-matching)
// GLOBAL DAT_0057d3b4 float

float * func_0057D2C4(int *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  if ((char)param_1[1] != '\0') {
    (**(code **)(*param_1 + 0x14))(param_1,param_1 + 2);
    *(undefined1 *)(param_1 + 1) = 0;
    *(undefined1 *)((int)param_1 + 5) = 1;
  }
  if (*(char *)((int)param_1 + 5) != '\0') {
    (**(code **)(*param_1 + 0x18))(param_1,param_1 + 0x12,param_1 + 2,(char)param_1[0x22]);
    *(undefined1 *)((int)param_1 + 5) = 0;
  }
  fVar1 = *param_3;
  fVar2 = param_3[1];
  fVar3 = param_3[2];
  fVar4 = DAT_0057d3b4 /
          (ALBW_AS_F32(param_1[0xf]) * fVar2 + ALBW_AS_F32(param_1[0x10]) * fVar3 +
          ALBW_AS_F32(param_1[0x11]) + ALBW_AS_F32(param_1[0xe]) * fVar1);
  *param_2 = (ALBW_AS_F32(param_1[5]) + ALBW_AS_F32(param_1[2]) * fVar1 +
             ALBW_AS_F32(param_1[3]) * fVar2 + ALBW_AS_F32(param_1[4]) * fVar3) * fVar4;
  param_2[1] = (ALBW_AS_F32(param_1[9]) + ALBW_AS_F32(param_1[6]) * fVar1 +
               ALBW_AS_F32(param_1[7]) * fVar2 + ALBW_AS_F32(param_1[8]) * fVar3) * fVar4;
  param_2[2] = (ALBW_AS_F32(param_1[0xd]) + ALBW_AS_F32(param_1[10]) * fVar1 +
               ALBW_AS_F32(param_1[0xb]) * fVar2 + ALBW_AS_F32(param_1[0xc]) * fVar3) * fVar4;
  return (float *)(param_1 + 10);
}

