/* compilefix: USA 002BCD98 (EU 002BCD74), the converted stage-2 text.
 * Fixed (BOOT_LOG 184): the ARM compares the float's bits (vmov rX, sY; cmp), which the converted text
 * wrote as a conversion of the value to an integer. */
#include "ghidra_types.h"

extern int func_00115C70(float *param_1,float *param_2,float *param_3);
extern int func_00115D70(float *param_1,float *param_2,float fparam_0);
extern float func_00115DC8(float *param_1);
extern int func_002BDDA4(int param_1);
extern int func_00532554(int param_1,uint param_2);
extern int func_0058E2B8(int *param_1);
extern int func_00662A14(undefined4 *param_1,undefined1 param_2);
extern int func_0068C690(float *param_1);
extern undefined4 *DAT_002bceec;
extern float DAT_002bcef0;
extern undefined4 *DAT_002bcef4;
extern float DAT_002bcef8;
extern int DAT_002bcefc;

// USA 002BCD98 <- EU 002BCD74 (Ghidra, non-matching)
// GLOBAL DAT_002bceec undefined4 *
// GLOBAL DAT_002bcef0 float
// GLOBAL DAT_002bcef4 undefined4 *
// GLOBAL DAT_002bcef8 float
// GLOBAL DAT_002bcefc int

void func_002BCD98(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  uint in_fpscr;
  float fVar4;
  float fVar5;
  float fVar6;
  _Alignas(8) unsigned char albw_frame[0x30];
  #define local_28 (*(float *)(albw_frame + 0x8))
  #define uStack_24 (*(undefined4 *)(albw_frame + 0xc))
  #define uStack_20 (*(undefined4 *)(albw_frame + 0x10))
  #define local_1c (*(float *)(albw_frame + 0x14))
  #define uStack_18 (*(undefined4 *)(albw_frame + 0x18))
  #define uStack_14 (*(undefined4 *)(albw_frame + 0x1c))
  #define local_10 (*(int *)(albw_frame + 0x20))
  puVar1 = func_002BDDA4(param_1);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)func_00532554((int)puVar1,(int)*(short *)(param_1 + 0x2e));
    *(undefined4 *)(param_1 + 0x920) = *puVar1;
    *(undefined4 *)(param_1 + 0x924) = puVar1[1];
    *(undefined4 *)(param_1 + 0x928) = puVar1[2];
  }
  puVar1 = func_002BDDA4(param_1);
  if (puVar1 != (undefined4 *)0x0) {
    func_00115C70(&local_1c,(float *)(param_1 + 0x920),(float *)(param_1 + 0x3d0));
    local_28 = local_1c;
    uStack_24 = uStack_18;
    uStack_20 = uStack_14;
    iVar2 = func_0068C690(&local_28);
    local_10 = iVar2 - *(int *)(param_1 + 1000);
    iVar3 = func_0058E2B8(&local_10);
    fVar6 = (float)VectorUnsignedToFloat(iVar3,(byte)(in_fpscr >> 0x15) & 3);
    fVar5 = (float)VectorSignedToFloat(*DAT_002bceec,(byte)(in_fpscr >> 0x15) & 3);
    fVar4 = fVar6 / fVar5;
    if (0x3f800000 < (int)ALBW_AS_U32(fVar6 / fVar5)) {
      fVar4 = DAT_002bcef0;
    }
    fVar5 = (float)VectorSignedToFloat(*DAT_002bcef4,(byte)(in_fpscr >> 0x15) & 3);
    iVar3 = (int)(fVar5 * fVar4);
    if (iVar2 - *(int *)(param_1 + 1000) < 0) {
      iVar3 = -iVar3;
    }
    *(int *)(param_1 + 1000) = *(int *)(param_1 + 1000) + iVar3;
  }
  func_00115C70(&local_28,(float *)(param_1 + 0x920),(float *)(param_1 + 0x3d0));
  *(float *)(param_1 + 0x3dc) = local_28;
  *(undefined4 *)(param_1 + 0x3e0) = uStack_24;
  *(undefined4 *)(param_1 + 0x3e4) = uStack_20;
  func_00115DC8((float *)(param_1 + 0x3dc));
  func_00115D70((float *)(param_1 + 0x3dc),(float *)(param_1 + 0x3dc),DAT_002bcef8);
  fVar4 = *(float *)(param_1 + 0x3d0) - *(float *)(param_1 + 0x920);
  fVar6 = *(float *)(param_1 + 0x3d4) - *(float *)(param_1 + 0x924);
  fVar5 = *(float *)(param_1 + 0x3d8) - *(float *)(param_1 + 0x928);
  if ((int)ALBW_AS_U32(SQRT(fVar4 * fVar4 + fVar6 * fVar6 + fVar5 * fVar5)) < DAT_002bcefc) {
    func_00662A14((undefined4 *)(param_1 + 0x8bc),2);
  }
  return;
}

