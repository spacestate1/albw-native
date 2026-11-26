/* compilefix: USA 002BC6B0 (EU 002BC68C), the converted stage-2 text.
 * Fixed (BOOT_LOG 184): the ARM compares the float's bits (vmov rX, sY; cmp), which the converted text
 * wrote as a conversion of the value to an integer. */
#include "ghidra_types.h"

extern int func_00115C70(float *param_1,float *param_2,float *param_3);
extern int func_002BDDA4(int param_1);
extern int func_0058E2B8(int *param_1);
extern int func_0068C690(float *param_1);
extern int *DAT_002bc768;
extern undefined4 *DAT_002bc76c;
extern float DAT_002bc770;
extern undefined4 *DAT_002bc774;

// USA 002BC6B0 <- EU 002BC68C (Ghidra, non-matching)
// GLOBAL DAT_002bc768 int *
// GLOBAL DAT_002bc76c undefined4 *
// GLOBAL DAT_002bc770 float
// GLOBAL DAT_002bc774 undefined4 *

void func_002BC6B0(int param_1)

{
  char cVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  uint in_fpscr;
  float fVar6;
  float fVar7;
  float fVar8;
  _Alignas(8) unsigned char albw_frame[0x30];
  #define local_30 (*(int *)(albw_frame + 0x0))
  #define local_2c (*(float *)(albw_frame + 0x4))
  #define uStack_28 (*(undefined4 *)(albw_frame + 0x8))
  #define uStack_24 (*(undefined4 *)(albw_frame + 0xc))
  #define local_20 (*(float *)(albw_frame + 0x10))
  #define uStack_1c (*(undefined4 *)(albw_frame + 0x14))
  #define uStack_18 (*(undefined4 *)(albw_frame + 0x18))
  piVar2 = DAT_002bc768;
  if (*DAT_002bc768 != 0) {
    puVar3 = func_002BDDA4(param_1);
    cVar1 = '\0';
    if (puVar3 != (undefined4 *)0x0) {
      cVar1 = *(char *)(puVar3 + 0x342);
    }
    if (puVar3 != (undefined4 *)0x0 && cVar1 != '\0') {
      func_00115C70(&local_20,*(float **)(*piVar2 + 0x1c),(float *)(param_1 + 0x3d0));
      local_2c = local_20;
      uStack_28 = uStack_1c;
      uStack_24 = uStack_18;
      iVar5 = func_0068C690(&local_2c);
    }
    else {
      iVar5 = 0;
    }
    local_30 = iVar5 - *(int *)(param_1 + 1000);
    iVar4 = func_0058E2B8(&local_30);
    fVar8 = (float)VectorUnsignedToFloat(iVar4,(byte)(in_fpscr >> 0x15) & 3);
    fVar7 = (float)VectorSignedToFloat(*DAT_002bc76c,(byte)(in_fpscr >> 0x15) & 3);
    fVar6 = fVar8 / fVar7;
    if (0x3f800000 < (int)ALBW_AS_U32(fVar8 / fVar7)) {
      fVar6 = DAT_002bc770;
    }
    fVar7 = (float)VectorSignedToFloat(*DAT_002bc774,(byte)(in_fpscr >> 0x15) & 3);
    iVar4 = (int)(fVar7 * fVar6);
    if (iVar5 - *(int *)(param_1 + 1000) < 0) {
      iVar4 = -iVar4;
    }
    *(int *)(param_1 + 1000) = iVar4 + *(int *)(param_1 + 1000);
  }
  return;
}

