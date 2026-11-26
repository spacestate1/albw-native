/* compilefix: USA 0040CE44 (EU 0040CE24), the converted stage-2 text.
 * Fixed (BOOT_LOG 184): the ARM compares the float's bits (vmov rX, sY; cmp), which the converted text
 * wrote as a conversion of the value to an integer. */
#include "ghidra_types.h"

extern int func_001164F4(undefined4 *param_1,uint param_2);
extern float func_00590EC8(float fparam_0,float fparam_1);
extern int DAT_0040cfc4;
extern float DAT_0040cfc8;
extern float DAT_0040cfcc;
extern float DAT_0040cfd0;
extern float DAT_0040cfd4;
extern float DAT_0040cfd8;
extern float DAT_0040cfdc;
extern float DAT_0040cfe0;
extern int DAT_0040cfe4;
extern float DAT_0040cfe8;
extern float DAT_0040cfec;
extern float DAT_0040cff0;

// USA 0040CE44 <- EU 0040CE24 (Ghidra, non-matching)
// GLOBAL DAT_0040cfc4 int
// GLOBAL DAT_0040cfc8 float
// GLOBAL DAT_0040cfcc float
// GLOBAL DAT_0040cfd0 float
// GLOBAL DAT_0040cfd4 float
// GLOBAL DAT_0040cfd8 float
// GLOBAL DAT_0040cfdc float
// GLOBAL DAT_0040cfe0 float
// GLOBAL DAT_0040cfe4 int
// GLOBAL DAT_0040cfe8 float
// GLOBAL DAT_0040cfec float
// GLOBAL DAT_0040cff0 float

undefined4 func_0040CE44(int param_1)

{
  int iVar1;
  uint in_fpscr;
  float fVar2;
  int iVar3;
  float fparam_0;
  float fVar4;
  float fVar5;
  int iVar6;
  float fVar7;
  float fVar8;
  
  fVar7 = DAT_0040cfe0;
  fparam_0 = DAT_0040cfdc;
  fVar8 = DAT_0040cfd8;
  fVar5 = DAT_0040cfcc;
  fVar4 = DAT_0040cfc8;
  iVar3 = DAT_0040cfc4;
  iVar1 = 0;
  iVar6 = ALBW_AS_U32(VectorUnsignedToFloat(*(undefined4 *)(param_1 + 0xc),(byte)(in_fpscr >> 0x15) & 3));
  fVar2 = DAT_0040cfc8;
  if (DAT_0040cfc4 < iVar6) {
    fVar2 = (float)VectorUnsignedToFloat
                             (*(undefined4 *)(param_1 + 0xc),(byte)(in_fpscr >> 0x15) & 3);
  }
  iVar6 = VectorFloatToUnsigned(fVar2 * DAT_0040cfcc,3);
  *(int *)(param_1 + 0xa4) = iVar6 * 0xa0;
  *(undefined4 *)(param_1 + 0xa8) = 0;
  fVar2 = DAT_0040cfd0;
  iVar6 = ALBW_AS_U32(VectorUnsignedToFloat(*(undefined4 *)(param_1 + 0x14),(byte)(in_fpscr >> 0x15) & 3));
  if (iVar3 < iVar6) {
    fVar4 = (float)VectorUnsignedToFloat
                             (*(undefined4 *)(param_1 + 0x14),(byte)(in_fpscr >> 0x15) & 3);
  }
  iVar3 = VectorFloatToUnsigned(fVar4 * fVar5,3);
  fVar4 = (float)VectorUnsignedToFloat(*(undefined4 *)(param_1 + 0x10),(byte)(in_fpscr >> 0x15) & 3)
  ;
  *(int *)(param_1 + 0xac) = iVar3 * 0xa0;
  *(undefined4 *)(param_1 + 0xb0) = 0;
  *(undefined4 *)(param_1 + 0xb4) = *(undefined4 *)(param_1 + 0x38);
  *(undefined4 *)(param_1 + 0xb8) = *(undefined4 *)(param_1 + 0x3c);
  fVar4 = fVar4 * fVar2 * DAT_0040cfd4;
  do {
    iVar3 = param_1 + iVar1 * 4;
    *(undefined4 *)(iVar3 + 0xbc) = 0;
    fVar2 = (float)VectorSignedToFloat(*(undefined4 *)(iVar3 + 0xb4),(byte)(in_fpscr >> 0x15) & 3);
    fVar5 = fparam_0;
    func_00590EC8(fparam_0,(fVar2 * fVar8) / fVar4);
    iVar1 = iVar1 + 1;
    *(int *)(iVar3 + 0xc4) = (int)(fparam_0 * fVar7);
    iVar3 = DAT_0040cfe4;
    fparam_0 = fVar5;
  } while (iVar1 < 2);
  *(undefined4 *)(param_1 + 0xcc) = *(undefined4 *)(param_1 + 0x40);
  *(undefined4 *)(param_1 + 0xd0) = 0;
  fVar4 = *(float *)(param_1 + 0x1c);
  if (iVar3 < (int)ALBW_AS_U32(*(float *)(param_1 + 0x1c))) {
    fVar4 = DAT_0040cfe8;
  }
  *(int *)(param_1 + 0xe8) = (int)(*(float *)(param_1 + 0x24) * fVar7);
  *(int *)(param_1 + 0xec) = (int)(*(float *)(param_1 + 0x28) * fVar7);
  *(int *)(param_1 + 0xd4) = (int)(*(float *)(param_1 + 0x18) * fVar7);
  if (*(char *)(param_1 + 0x2d) == '\x01') {
    fVar5 = fVar4 - DAT_0040cfec;
    *(int *)(param_1 + 0xf4) = (int)(fVar4 * DAT_0040cff0);
    *(int *)(param_1 + 0xf0) = (int)(fVar5 * fVar7);
  }
  else {
    *(int *)(param_1 + 0xf0) = (int)((DAT_0040cfec - fVar4) * fVar7);
    *(int *)(param_1 + 0xf4) = (int)(fVar4 * fVar7);
  }
  return func_001164F4(*(undefined4 **)(param_1 + 0x30),*(uint *)(param_1 + 0x34));
}

