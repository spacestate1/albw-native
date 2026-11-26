/* compilefix: USA 001588A0, the converted stage-2 text with the returned velocity stored (the text stored unrelated locals)
 * (a vector returned in s0..s2 on ARM: BOOT_LOG 178). */
#include "ghidra_types.h"

extern int func_00115C54(float *param_1,float *param_2,float *param_3);
extern int func_00115C70(float *param_1,float *param_2,float *param_3);
extern void func_00158D0C(int param_1);
extern int func_004D80A4(float *param_1,uint param_2,float fparam_0);
extern int func_0051D2CC(int *param_1,int param_2,float fparam_0);
extern int func_00520FC0(void);
extern int func_0058E2B8(int *param_1);
extern int func_0068C690(float *param_1);
extern undefined4 DAT_00158aac;
extern float DAT_00158ab0;
extern float DAT_00158ab4;
extern float DAT_00158ab8;
extern uint DAT_00158abc;

float *albw_s012_get(void);   /* s0..s2 of a returned vector (native/runtime/vec3ret.c) */

// USA 001588A0 <- EU 001588A4 (Ghidra, non-matching)
// GLOBAL DAT_00158aac undefined4
// GLOBAL DAT_00158ab0 float
// GLOBAL DAT_00158ab4 float
// GLOBAL DAT_00158ab8 float
// GLOBAL DAT_00158abc uint

void func_001588A0(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  float *pfVar3;
  int iVar4;
  uint uVar5;
  float *pfVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  _Alignas(8) unsigned char albw_frame[0x50];
  #define local_50 (*(float *)(albw_frame + 0x0))
  #define local_4c (*(undefined4 *)(albw_frame + 0x4))
  #define local_48 (*(float *)(albw_frame + 0x8))
  #define local_44 (*(uint *)(albw_frame + 0xc))
  #define local_40 (*(float *)(albw_frame + 0x10))
  #define uStack_3c (*(undefined4 *)(albw_frame + 0x14))
  #define fStack_38 (*(float *)(albw_frame + 0x18))
  #define local_34 (*(float *)(albw_frame + 0x1c))
  #define uStack_30 (*(undefined4 *)(albw_frame + 0x20))
  #define uStack_2c (*(undefined4 *)(albw_frame + 0x24))
  #define local_28 (*(float *)(albw_frame + 0x28))
  #define local_24 (*(undefined4 *)(albw_frame + 0x2c))
  #define local_20 (*(float *)(albw_frame + 0x30))
  #define local_1c (*(float *)(albw_frame + 0x34))
  #define uStack_18 (*(undefined4 *)(albw_frame + 0x38))
  #define uStack_14 (*(undefined4 *)(albw_frame + 0x3c))
  pfVar3 = (float *)func_00520FC0();
  pfVar6 = (float *)(param_1 + 0x90c);
  func_00115C54(&local_28,pfVar3,pfVar6);
  uVar1 = DAT_00158aac;
  local_50 = local_28;
  local_4c = local_24;
  local_48 = local_20;
  fVar9 = *(float *)(param_1 + 0x3d8);
  fVar7 = *(float *)(param_1 + 0x3d0) - local_28;
  fVar8 = fVar9 - local_20;
  if (0x3f7fffff < (int)ALBW_AS_U32((fVar7 * fVar7 + fVar8 * fVar8))) {
    if (*(uint *)(param_1 + 0x900) < *(uint *)(param_1 + 0x904)) goto LAB_0015894c;
    *(undefined4 *)(param_1 + 0x904) = 0xf;
    *(undefined4 *)(param_1 + 0x908) = uVar1;
    *(undefined4 *)(param_1 + 0x900) = 0;
  }
  func_00158D0C(param_1);
  *pfVar6 = albw_s012_get()[0];
  *(float *)(param_1 + 0x910) = albw_s012_get()[1];
  *(float *)(param_1 + 0x914) = albw_s012_get()[2];
LAB_0015894c:
  if (*(uint *)(param_1 + 0x8f4) < *(uint *)(param_1 + 0x8f8)) {
    *(uint *)(param_1 + 0x8f4) = *(uint *)(param_1 + 0x8f4) + 1;
  }
  if (*(uint *)(param_1 + 0x900) < *(uint *)(param_1 + 0x904)) {
    *(uint *)(param_1 + 0x900) = *(uint *)(param_1 + 0x900) + 1;
  }
  pfVar3 = (float *)func_00520FC0();
  func_00115C54(&local_28,pfVar3,pfVar6);
  local_50 = local_28;
  local_4c = local_24;
  local_48 = local_20;
  func_00115C70(&local_28,&local_50,(float *)(param_1 + 0x3d0));
  local_40 = local_28;
  uStack_3c = local_24;
  fStack_38 = local_20;
  iVar4 = func_0068C690(&local_40);
  func_0051D2CC((int *)(param_1 + 1000),iVar4,DAT_00158ab0);
  fVar7 = DAT_00158ab8;
  fVar8 = *(float *)(param_1 + 0x8f0) * DAT_00158ab4;
  *(float *)(param_1 + 0x8f0) = fVar8;
  if (fVar7 < fVar8) {
    fVar8 = fVar7;
  }
  *(float *)(param_1 + 0x8f0) = fVar8;
  func_004D80A4((float *)(param_1 + 0x3dc),*(uint *)(param_1 + 1000),fVar8);
  local_34 = *(float *)(param_1 + 0x3dc);
  uStack_30 = *(undefined4 *)(param_1 + 0x3e0);
  uStack_2c = *(undefined4 *)(param_1 + 0x3e4);
  func_00115C54((float *)(param_1 + 0x3d0),(float *)(param_1 + 0x3d0),&local_34);
  pfVar3 = (float *)func_00520FC0();
  func_00115C70(&local_1c,pfVar3,(float *)(param_1 + 0x3d0));
  local_28 = local_1c;
  local_24 = uStack_18;
  local_20 = ALBW_AS_F32(uStack_14);
  iVar4 = func_0068C690(&local_28);
  uVar2 = DAT_00158abc;
  local_44 = iVar4 - *(int *)(param_1 + 1000);
  uVar5 = func_0058E2B8((int *)&local_44);
  if (uVar5 < uVar2) {
    uVar5 = -uVar2;
    if (((int)uVar5 <= (int)local_44) && (uVar5 = local_44, (int)uVar2 < (int)local_44)) {
      uVar5 = uVar2;
    }
  }
  else {
    uVar5 = 0;
  }
  *(uint *)(param_1 + 0x93c) = uVar5;
  return;
}

