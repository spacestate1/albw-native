/* compilefix: USA 00229E24 (EU 00229E24), the converted stage-2 text.
 * Fixed (BOOT_LOG 184): the ARM compares the float's bits (vmov rX, sY; cmp), which the converted text
 * wrote as a conversion of the value to an integer. */
#include "ghidra_types.h"

extern int func_00115C70(float *param_1,float *param_2,float *param_3);
extern int func_0058E2B8(int *param_1);
extern int func_0068C690(float *param_1);
extern int *DAT_00229f40;
extern float DAT_00229f44;
extern undefined4 *DAT_00229f48;
extern undefined4 *DAT_00229f4c;
extern undefined4 *DAT_00229f50;
extern undefined4 *DAT_00229f54;

// USA 00229E24 <- EU 00229E24 (Ghidra, non-matching)
// GLOBAL DAT_00229f40 int *
// GLOBAL DAT_00229f44 float
// GLOBAL DAT_00229f48 undefined4 *
// GLOBAL DAT_00229f4c undefined4 *
// GLOBAL DAT_00229f50 undefined4 *
// GLOBAL DAT_00229f54 undefined4 *

void func_00229E24(int param_1)

{
  int iVar1;
  int iVar2;
  uint in_fpscr;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  _Alignas(8) unsigned char albw_frame[0x40];
  #define local_3c (*(int *)(albw_frame + 0x4))
  #define local_38 (*(float *)(albw_frame + 0x8))
  #define uStack_34 (*(undefined4 *)(albw_frame + 0xc))
  #define uStack_30 (*(undefined4 *)(albw_frame + 0x10))
  #define local_2c (*(float *)(albw_frame + 0x14))
  #define uStack_28 (*(undefined4 *)(albw_frame + 0x18))
  #define uStack_24 (*(undefined4 *)(albw_frame + 0x1c))
  if (*DAT_00229f40 != 0) {
    func_00115C70(&local_2c,*(float **)(*DAT_00229f40 + 0x1c),(float *)(param_1 + 0x3d0));
    local_38 = local_2c;
    uStack_34 = uStack_28;
    uStack_30 = uStack_24;
    iVar1 = func_0068C690(&local_38);
    local_3c = iVar1 - *(int *)(param_1 + 1000);
    if (*(char *)(param_1 + 0xd09) == '\0') {
      fVar4 = DAT_00229f44;
      iVar2 = func_0058E2B8(&local_3c);
      fVar3 = (float)VectorUnsignedToFloat(iVar2,(byte)(in_fpscr >> 0x15) & 3);
      fVar5 = (float)VectorSignedToFloat(*DAT_00229f50,(byte)(in_fpscr >> 0x15) & 3);
      fVar6 = fVar3 / fVar5;
      if (0x3f800000 < (int)ALBW_AS_U32(fVar3 / fVar5)) {
        fVar6 = fVar4;
      }
      fVar4 = (float)VectorSignedToFloat(*DAT_00229f54,(byte)(in_fpscr >> 0x15) & 3);
      fVar4 = fVar4 * fVar6;
    }
    else {
      fVar4 = DAT_00229f44;
      iVar2 = func_0058E2B8(&local_3c);
      fVar3 = (float)VectorUnsignedToFloat(iVar2,(byte)(in_fpscr >> 0x15) & 3);
      fVar5 = (float)VectorSignedToFloat(*DAT_00229f48,(byte)(in_fpscr >> 0x15) & 3);
      fVar6 = fVar3 / fVar5;
      if (0x3f800000 < (int)ALBW_AS_U32(fVar3 / fVar5)) {
        fVar6 = fVar4;
      }
      fVar4 = (float)VectorSignedToFloat(*DAT_00229f4c,(byte)(in_fpscr >> 0x15) & 3);
      fVar4 = fVar4 * fVar6;
    }
    iVar2 = (int)fVar4;
    if (iVar1 - *(int *)(param_1 + 1000) < 0) {
      iVar2 = -iVar2;
    }
    *(int *)(param_1 + 0xac0) = iVar2;
    *(int *)(param_1 + 1000) = iVar2 + *(int *)(param_1 + 1000);
  }
  return;
}

