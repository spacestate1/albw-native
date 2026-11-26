/* compilefix: USA 001A8B48, the converted stage-2 text with the returned velocity stored (the text stored unrelated locals)
 * (a vector returned in s0..s2 on ARM: BOOT_LOG 178). */
#include "ghidra_types.h"

extern int func_00115C54(float *param_1,float *param_2,float *param_3);
extern int func_00115C70(float *param_1,float *param_2,float *param_3);
extern int func_00115D70(float *param_1,float *param_2,float fparam_0);
extern int func_001A91A8(int param_1);
extern void func_001A9468(int param_1);
extern int func_001A9610(uint param_1);
extern int func_004D80A4(float *param_1,uint param_2,float fparam_0);
extern int func_0051D2CC(int *param_1,int param_2,float fparam_0);
extern int func_00520FC0(void);
extern int func_00520FF8(int param_1);
extern int func_0065A984(undefined4 *param_1,undefined1 param_2);
extern int func_0068C690(float *param_1);
extern float DAT_001a8e00;
extern float DAT_001a8e04;
extern int DAT_001a8e08;
extern undefined4 DAT_001a8e0c;
extern float DAT_001a8e10;
extern float DAT_001a8e14;
extern float DAT_001a8e18;

float *albw_s012_get(void);   /* s0..s2 of a returned vector (native/runtime/vec3ret.c) */

// USA 001A8B48 <- EU 001A8B48 (Ghidra, non-matching)
// GLOBAL DAT_001a8e00 float
// GLOBAL DAT_001a8e04 float
// GLOBAL DAT_001a8e08 int
// GLOBAL DAT_001a8e0c undefined4
// GLOBAL DAT_001a8e10 float
// GLOBAL DAT_001a8e14 float
// GLOBAL DAT_001a8e18 float

undefined4 func_001A8B48(uint param_1)

{
  undefined4 uVar1;
  bool bVar2;
  int iVar3;
  float *pfVar4;
  float *pfVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  _Alignas(8) unsigned char albw_frame[0x50];
  #define local_50 (*(float *)(albw_frame + 0x0))
  #define local_4c (*(float *)(albw_frame + 0x4))
  #define uStack_48 (*(undefined4 *)(albw_frame + 0x8))
  #define fStack_44 (*(float *)(albw_frame + 0xc))
  #define local_3c (*(float *)(albw_frame + 0x14))
  #define fStack_38 (*(float *)(albw_frame + 0x18))
  #define local_34 (*(float *)(albw_frame + 0x1c))
  #define local_30 (*(float *)(albw_frame + 0x20))
  #define uStack_2c (*(undefined4 *)(albw_frame + 0x24))
  #define uStack_28 (*(undefined4 *)(albw_frame + 0x28))
  #define local_24 (*(float *)(albw_frame + 0x2c))
  #define fStack_20 (*(float *)(albw_frame + 0x30))
  #define uStack_1c (*(undefined4 *)(albw_frame + 0x34))
  fVar9 = DAT_001a8e04;
  fVar6 = *(float *)(param_1 + 0x91c);
  *(float *)(param_1 + 0x91c) = fVar6 + (DAT_001a8e00 - fVar6) * DAT_001a8e04;
  iVar3 = func_00520FF8(param_1);
  if (iVar3 == 0) {
    *(undefined4 *)(param_1 + 0x920) = 0;
  }
  else {
    iVar3 = *(int *)(param_1 + 0x920) + 1;
    *(int *)(param_1 + 0x920) = iVar3;
    if ((4 < iVar3) && (bVar2 = func_001A9610(param_1), bVar2)) {
      func_0065A984((undefined4 *)(param_1 + 0x8bc),6);
    }
  }
  if (*(uint *)(param_1 + 0x8f8) <= *(uint *)(param_1 + 0x8f4)) {
LAB_001a8ca4:
    return func_0065A984((undefined4 *)(param_1 + 0x8bc),5);
  }
  pfVar4 = (float *)func_00520FC0();
  pfVar5 = (float *)(param_1 + 0x90c);
  func_00115C54(&local_4c,pfVar4,pfVar5);
  local_3c = local_4c;
  fStack_38 = ALBW_AS_F32(uStack_48);
  local_34 = fStack_44;
  pfVar4 = (float *)func_00520FC0();
  uVar1 = DAT_001a8e0c;
  fVar6 = *(float *)(param_1 + 0x3d0);
  fVar8 = *(float *)(param_1 + 0x3d8);
  if ((int)ALBW_AS_U32(((fVar6 - *pfVar4) * (fVar6 - *pfVar4) + (fVar8 - pfVar4[2]) * (fVar8 - pfVar4[2]))) <
      0x3f800000) goto LAB_001a8ca4;
  if (0x3f7fffff <
      (int)ALBW_AS_U32(((fVar6 - local_3c) * (fVar6 - local_3c) + (fVar8 - local_34) * (fVar8 - local_34)))) {
    fVar7 = fVar6 - *(float *)(param_1 + 8);
    fVar6 = fVar8 - *(float *)(param_1 + 0x10);
    if (DAT_001a8e08 < (int)ALBW_AS_U32((fVar7 * fVar7 + fVar6 * fVar6))) goto LAB_001a8ca4;
    if (*(uint *)(param_1 + 0x900) < *(uint *)(param_1 + 0x904)) goto LAB_001a8cec;
    *(undefined4 *)(param_1 + 0x904) = 0xf;
    *(undefined4 *)(param_1 + 0x908) = uVar1;
    *(undefined4 *)(param_1 + 0x900) = 0;
  }
  func_001A9468(param_1);
  *pfVar5 = albw_s012_get()[0];
  *(float *)(param_1 + 0x910) = albw_s012_get()[1];
  *(float *)(param_1 + 0x914) = albw_s012_get()[2];
LAB_001a8cec:
  if (*(uint *)(param_1 + 0x8f4) < *(uint *)(param_1 + 0x8f8)) {
    *(uint *)(param_1 + 0x8f4) = *(uint *)(param_1 + 0x8f4) + 1;
  }
  if (*(uint *)(param_1 + 0x900) < *(uint *)(param_1 + 0x904)) {
    *(uint *)(param_1 + 0x900) = *(uint *)(param_1 + 0x900) + 1;
  }
  pfVar4 = (float *)func_00520FC0();
  func_00115C54(&local_50,pfVar4,pfVar5);
  local_3c = local_50;
  fStack_38 = local_4c;
  local_34 = ALBW_AS_F32(uStack_48);
  func_00115C70(&local_50,&local_3c,(float *)(param_1 + 0x3d0));
  local_24 = local_50;
  fStack_20 = local_4c;
  uStack_1c = uStack_48;
  iVar3 = func_0068C690(&local_24);
  func_0051D2CC((int *)(param_1 + 1000),iVar3,fVar9);
  fVar9 = DAT_001a8e14;
  fVar6 = *(float *)(param_1 + 0x8f0) * DAT_001a8e10;
  *(float *)(param_1 + 0x8f0) = fVar6;
  if (fVar9 < fVar6) {
    fVar6 = fVar9;
  }
  *(float *)(param_1 + 0x8f0) = fVar6;
  func_004D80A4((float *)(param_1 + 0x3dc),*(uint *)(param_1 + 1000),fVar6);
  local_30 = *(float *)(param_1 + 0x3dc);
  uStack_2c = *(undefined4 *)(param_1 + 0x3e0);
  uStack_28 = *(undefined4 *)(param_1 + 0x3e4);
  iVar3 = func_00520FF8(param_1);
  if (iVar3 != 0) {
    func_00115D70(&local_30,&local_30,DAT_001a8e18);
  }
  func_00115C54((float *)(param_1 + 0x3d0),(float *)(param_1 + 0x3d0),&local_30);
  return func_001A91A8(param_1);
}

