/* compilefix: USA 001C2BC4 (EU 001C2BC4), the converted stage-2 text.
 * Fixed (BOOT_LOG 184): the ARM copies this word between a float and an integer (no vcvt), which the
 * converted text wrote as a conversion of the value. */
#include "ghidra_types.h"

extern int func_0014E2A0(int param_1,undefined4 param_2,undefined4 param_3,uint param_4,undefined4 param_5 ,int param_6);
extern int func_001DDDE8(int param_1,float *param_2,int param_3,float fparam_0);
extern int func_0034CA20(undefined4 *param_1);
extern int func_004356B4(int *param_1);
extern int func_00520FC0(void);
extern int func_00520FD4(void);
extern int func_0065BB78(undefined4 *param_1,undefined1 param_2);
extern int DAT_001c2dbc;
extern float DAT_001c2dc0;
extern float DAT_001c2dc4;
extern int *DAT_001c2dc8;
extern int *DAT_001c2dcc;
extern float DAT_001c2dd0;
extern float DAT_001c2dd4;

// USA 001C2BC4 <- EU 001C2BC4 (Ghidra, non-matching)
// GLOBAL DAT_001c2dbc int
// GLOBAL DAT_001c2dc0 float
// GLOBAL DAT_001c2dc4 float
// GLOBAL DAT_001c2dc8 int *
// GLOBAL DAT_001c2dcc int *
// GLOBAL DAT_001c2dd0 float
// GLOBAL DAT_001c2dd4 float

/* WARNING: Variable defined which should be unmapped: objStack_20 */

void func_001C2BC4(int param_1)

{
  char cVar1;
  bool bVar2;
  float *pfVar3;
  int iVar4;
  undefined1 uVar5;
  undefined4 uVar6;
  float fVar7;
  float fVar8;
  _Alignas(8) unsigned char albw_frame[0x20];
  #define objStack_20 ((uint *)(albw_frame + 0x0))
  pfVar3 = (float *)func_00520FC0();
  fVar7 = *pfVar3 - *(float *)(param_1 + 0x3d0);
  fVar8 = pfVar3[2] - *(float *)(param_1 + 0x3d8);
  if ((int)ALBW_AS_U32((fVar7 * fVar7 + fVar8 * fVar8)) < DAT_001c2dbc) {
    objStack_20[1] = (uint)ALBW_AS_U32((*(float *)(param_1 + 0x3d4) + DAT_001c2dc0));
    objStack_20[0] = (uint)ALBW_AS_U32(*(float *)(param_1 + 0x3d0));
    objStack_20[2] = (uint)ALBW_AS_U32(*(float *)(param_1 + 0x3d8));
    func_001DDDE8(*DAT_001c2dc8,(float *)objStack_20,1,DAT_001c2dc4);
  }
  func_0034CA20(*(undefined4 **)(param_1 + 0x7c4));
  objStack_20[0] = 0;
  objStack_20[1] = 0;
  func_0014E2A0(param_1,*(undefined4 *)(param_1 + 0x7b8),param_1 + 0x7c8,0x1f00,0,0);
  cVar1 = *(char *)(*(int *)(param_1 + 0x7c4) + 0x21);
  if (cVar1 == '\b') {
LAB_001c2cf8:
    uVar5 = 3;
    if (*(short *)(param_1 + 0x84c) != 0) goto LAB_001c2d54;
    if (*DAT_001c2dcc != 0) {
      iVar4 = *(int *)(*DAT_001c2dcc + 0x44);
      goto joined_r0x001c2d48;
    }
  }
  else {
    if (cVar1 < '\b') {
      if (cVar1 == '\x01') {
LAB_001c2d24:
        uVar5 = 2;
        if (*(short *)(param_1 + 0x84c) != 0) goto LAB_001c2d54;
        if (*DAT_001c2dcc != 0) {
          iVar4 = *(int *)(*DAT_001c2dcc + 0x44);
          goto joined_r0x001c2d48;
        }
        goto LAB_001c2d4c;
      }
      if (cVar1 == '\x02') goto LAB_001c2cf8;
      if (cVar1 != '\x05') goto LAB_001c2d54;
    }
    else if (cVar1 != '\n') {
      if (cVar1 == '\r') goto LAB_001c2d24;
      if (cVar1 != '\x0f') goto LAB_001c2d54;
      goto LAB_001c2cf8;
    }
    uVar5 = 1;
    if (*(short *)(param_1 + 0x84c) != 0) goto LAB_001c2d54;
    if (*DAT_001c2dcc != 0) {
      iVar4 = *(int *)(*DAT_001c2dcc + 0x44);
joined_r0x001c2d48:
      if (iVar4 != 0) goto LAB_001c2d54;
    }
  }
LAB_001c2d4c:
  func_0065BB78((undefined4 *)(param_1 + 0x788),uVar5);
LAB_001c2d54:
  bVar2 = func_00520FD4();
  if ((int)*(char *)(param_1 + 0x850) != (uint)bVar2) {
    *(bool *)(param_1 + 0x850) = bVar2;
    uVar6 = *(undefined4 *)(param_1 + 0x3d0);
    fVar7 = *(float *)(param_1 + 0x3d8);
    iVar4 = *(int *)(param_1 + 0x7b8);
    fVar8 = *(float *)(param_1 + 0x3d4) + DAT_001c2dd0;
    if (bVar2 != 1) {
      fVar7 = fVar7 - DAT_001c2dd4;
    }
    *(float *)(iVar4 + 0xc) = fVar7;
    *(undefined4 *)(iVar4 + 4) = uVar6;
    *(float *)(iVar4 + 8) = fVar8;
    func_004356B4(*(int **)(param_1 + 0x7b8));
  }
  if (*(short *)(param_1 + 0x84c) != 0) {
    *(short *)(param_1 + 0x84c) = *(short *)(param_1 + 0x84c) + -1;
  }
  return;
}

