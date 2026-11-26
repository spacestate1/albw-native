/* compilefix: USA 00158BE4, the converted stage-2 text with the returned velocity stored
 * (a vector returned in s0..s2 on ARM: BOOT_LOG 178). */
#include "ghidra_types.h"

extern void func_00158D0C(int param_1);
extern float func_004F898C(void);
extern int func_004FABDC(int param_1,undefined4 param_2,uint param_3,int param_4);
extern undefined4 DAT_00158c68;
extern undefined4 DAT_00158c6c;
extern undefined4 DAT_00158c70;

float *albw_s012_get(void);   /* s0..s2 of a returned vector (native/runtime/vec3ret.c) */

// USA 00158BE4 <- EU 00158BE8 (Ghidra, non-matching)
// GLOBAL DAT_00158c68 undefined4
// GLOBAL DAT_00158c6c undefined4
// GLOBAL DAT_00158c70 undefined4

undefined4 func_00158BE4(int param_1)

{
  undefined4 uVar1;
  float fVar2;
  undefined4 in_s1;
  undefined4 in_s2;
  
  *(undefined4 *)(param_1 + 0x8f0) = DAT_00158c68;
  uVar1 = DAT_00158c6c;
  *(undefined4 *)(param_1 + 0x8f8) = 200;
  *(undefined4 *)(param_1 + 0x8fc) = uVar1;
  uVar1 = DAT_00158c70;
  *(undefined4 *)(param_1 + 0x8f4) = 0;
  *(undefined4 *)(param_1 + 0x904) = 0xf;
  *(undefined4 *)(param_1 + 0x908) = uVar1;
  *(undefined4 *)(param_1 + 0x900) = 0;
  fVar2 = func_004F898C();
  *(float *)(param_1 + 0x3e0) = fVar2;
  func_00158D0C(param_1);
  fVar2 = albw_s012_get()[0];
  in_s1 = ALBW_AS_U32(albw_s012_get()[1]);
  in_s2 = ALBW_AS_U32(albw_s012_get()[2]);
  *(float *)(param_1 + 0x90c) = fVar2;
  *(undefined4 *)(param_1 + 0x910) = in_s1;
  *(undefined4 *)(param_1 + 0x914) = in_s2;
  return func_004FABDC(param_1,1,0xffffffff,0);
}

