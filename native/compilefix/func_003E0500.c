/* compilefix: USA 003E0500 (EU 003E04E0), the converted stage-2 text.
 * Fixed (BOOT_LOG 184): the ARM compares the float's bits (vmov rX, sY; cmp), which the converted text
 * wrote as a conversion of the value to an integer. */
#include "ghidra_types.h"

extern int func_001164F4(undefined4 *param_1,uint param_2);
extern float func_00590EC8(float fparam_0,float fparam_1);
extern int DAT_003e06a4;
extern float DAT_003e06a8;
extern float DAT_003e06ac;
extern float DAT_003e06b0;
extern float DAT_003e06b4;
extern float DAT_003e06b8;
extern float DAT_003e06bc;
extern float DAT_003e06c0;
extern int DAT_003e06c4;
extern float DAT_003e06c8;
extern float DAT_003e06cc;
extern float DAT_003e06d0;

// USA 003E0500 <- EU 003E04E0 (Ghidra, non-matching)
// GLOBAL DAT_003e06a4 int
// GLOBAL DAT_003e06a8 float
// GLOBAL DAT_003e06ac float
// GLOBAL DAT_003e06b0 float
// GLOBAL DAT_003e06b4 float
// GLOBAL DAT_003e06b8 float
// GLOBAL DAT_003e06bc float
// GLOBAL DAT_003e06c0 float
// GLOBAL DAT_003e06c4 int
// GLOBAL DAT_003e06c8 float
// GLOBAL DAT_003e06cc float
// GLOBAL DAT_003e06d0 float

undefined4 func_003E0500(int param_1)

{
  int iVar1;
  uint in_fpscr;
  float fVar2;
  int iVar3;
  float fparam_0;
  float fVar4;
  int iVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  
  fVar7 = DAT_003e06c0;
  fparam_0 = DAT_003e06bc;
  fVar8 = DAT_003e06b8;
  fVar4 = DAT_003e06ac;
  fVar2 = DAT_003e06a8;
  iVar3 = DAT_003e06a4;
  iVar1 = 0;
  iVar5 = ALBW_AS_U32(VectorUnsignedToFloat(*(undefined4 *)(param_1 + 4),(byte)(in_fpscr >> 0x15) & 3));
  fVar6 = DAT_003e06a8;
  if (DAT_003e06a4 < iVar5) {
    fVar6 = (float)VectorUnsignedToFloat(*(undefined4 *)(param_1 + 4),(byte)(in_fpscr >> 0x15) & 3);
  }
  iVar5 = VectorFloatToUnsigned(fVar6 * DAT_003e06ac,3);
  *(int *)(param_1 + 0x9c) = iVar5 * 0xa0;
  *(undefined4 *)(param_1 + 0xa0) = 0;
  fVar6 = DAT_003e06b0;
  iVar5 = ALBW_AS_U32(VectorUnsignedToFloat(ALBW_AS_U32(*(float *)(param_1 + 0xc)),(byte)(in_fpscr >> 0x15) & 3));
  if (iVar3 < iVar5) {
    fVar2 = *(float *)(param_1 + 0xc);
  }
  if (iVar3 < iVar5) {
    fVar2 = (float)VectorUnsignedToFloat(ALBW_AS_U32(fVar2),(byte)(in_fpscr >> 0x15) & 3);
  }
  iVar3 = VectorFloatToUnsigned(fVar2 * fVar4,3);
  fVar2 = (float)VectorUnsignedToFloat(*(undefined4 *)(param_1 + 8),(byte)(in_fpscr >> 0x15) & 3);
  *(int *)(param_1 + 0xa4) = iVar3 * 0xa0;
  *(undefined4 *)(param_1 + 0xa8) = 0;
  *(undefined4 *)(param_1 + 0xac) = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 *)(param_1 + 0xb0) = *(undefined4 *)(param_1 + 0x34);
  fVar2 = fVar2 * fVar6 * DAT_003e06b4;
  do {
    iVar3 = param_1 + iVar1 * 4;
    *(undefined4 *)(iVar3 + 0xb4) = 0;
    fVar6 = (float)VectorSignedToFloat(*(undefined4 *)(iVar3 + 0xac),(byte)(in_fpscr >> 0x15) & 3);
    fVar4 = fparam_0;
    func_00590EC8(fparam_0,(fVar6 * fVar8) / fVar2);
    iVar1 = iVar1 + 1;
    *(int *)(iVar3 + 0xbc) = (int)(fparam_0 * fVar7);
    iVar3 = DAT_003e06c4;
    fparam_0 = fVar4;
  } while (iVar1 < 2);
  *(undefined4 *)(param_1 + 0xc4) = *(undefined4 *)(param_1 + 0x38);
  *(undefined4 *)(param_1 + 200) = 0;
  fVar2 = DAT_003e06cc;
  fVar4 = *(float *)(param_1 + 0x14);
  if (iVar3 < (int)ALBW_AS_U32(*(float *)(param_1 + 0x14))) {
    fVar4 = DAT_003e06c8;
  }
  *(int *)(param_1 + 0xcc) = (int)(*(float *)(param_1 + 0x10) * fVar7);
  *(int *)(param_1 + 0xe4) = (int)(*(float *)(param_1 + 0x20) * fVar7);
  *(int *)(param_1 + 0xe0) = (int)(*(float *)(param_1 + 0x1c) * fVar7);
  if (*(char *)(param_1 + 0x24) == '\x01') {
    fVar2 = fVar4 - fVar2;
    fVar8 = DAT_003e06d0;
  }
  else {
    fVar2 = fVar2 - fVar4;
    fVar8 = fVar7;
  }
  *(int *)(param_1 + 0xe8) = (int)(fVar2 * fVar7);
  *(int *)(param_1 + 0xec) = (int)(fVar4 * fVar8);
  return func_001164F4(*(undefined4 **)(param_1 + 0x28),*(uint *)(param_1 + 0x2c));
}

