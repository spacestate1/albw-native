/* compilefix: USA 00521F10, the converted stage-2 text with y and z of the returned direction
 * (a vector returned in s0..s2 on ARM: BOOT_LOG 178). */
#include "ghidra_types.h"

extern int func_00115C54(float *param_1,float *param_2,float *param_3);
extern int func_00115C70(float *param_1,float *param_2,float *param_3);
extern int func_00115D70(float *param_1,float *param_2,float fparam_0);
extern float func_00115DC8(float *param_1);
extern float func_0032EF0C(float *param_1,float *param_2);
extern int func_0054F9B8(int param_1,uint param_2);
extern int func_0054F9E4(int param_1,uint param_2);
extern int func_0054FA10(int param_1,uint param_2);
extern int func_0054FA98(int param_1,uint param_2);
extern int func_0054FBC4(int param_1,float *param_2,float *param_3);
extern int func_00550078(float *param_1,float *param_2);
extern undefined4 DAT_00522154;
extern float DAT_00522158;

float *albw_s012_get(void);   /* s0..s2 of a returned vector (native/runtime/vec3ret.c) */

// USA 00521F10 <- EU 00521EE8 (Ghidra, non-matching)
// GLOBAL DAT_00522154 undefined4
// GLOBAL DAT_00522158 float

undefined1 func_00521F10(int param_1,float *param_2)

{
  bool bVar1;
  undefined1 uVar2;
  int iVar3;
  uint uVar4;
  float *pfVar5;
  float fVar6;
  float in_s2;
  float fVar7;
  undefined4 uVar8;
  _Alignas(8) unsigned char albw_frame[0x90];
  #define local_88 (*(float *)(albw_frame + 0x8))
  #define local_84 (*(float *)(albw_frame + 0xc))
  #define local_80 (*(float *)(albw_frame + 0x10))
  #define local_7c (*(float *)(albw_frame + 0x14))
  #define fStack_78 (*(float *)(albw_frame + 0x18))
  #define fStack_74 (*(float *)(albw_frame + 0x1c))
  #define local_70 (*(float *)(albw_frame + 0x20))
  #define fStack_6c (*(float *)(albw_frame + 0x24))
  #define local_64 (*(float *)(albw_frame + 0x2c))
  #define local_60 (*(float *)(albw_frame + 0x30))
  #define fStack_5c (*(float *)(albw_frame + 0x34))
  #define local_58 (*(float *)(albw_frame + 0x38))
  #define local_4c (*(float *)(albw_frame + 0x44))
  #define local_48 (*(float *)(albw_frame + 0x48))
  #define local_44 (*(float *)(albw_frame + 0x4c))
  #define local_40 (*(float *)(albw_frame + 0x50))
  #define local_3c (*(undefined4 *)(albw_frame + 0x54))
  #define local_38 (*(float *)(albw_frame + 0x58))
  #define local_34 (*(float *)(albw_frame + 0x5c))
  #define fStack_30 (*(float *)(albw_frame + 0x60))
  #define local_2c (*(float *)(albw_frame + 0x64))
  #define fStack_28 (*(float *)(albw_frame + 0x68))
  #define local_24 (*(float *)(albw_frame + 0x6c))
  iVar3 = param_1 + 0x9b4;
  uVar4 = func_0054FBC4(iVar3,(float *)(param_1 + 0x3d0),(float *)0x0);
  pfVar5 = (float *)func_0054FA98(iVar3,uVar4);
  local_60 = *pfVar5;
  fStack_5c = pfVar5[1];
  local_58 = pfVar5[2];
  pfVar5 = (float *)func_0054F9E4(iVar3,uVar4);
  local_2c = *pfVar5;
  fStack_28 = pfVar5[1];
  local_24 = pfVar5[2];
  func_00115C70(&local_88,&local_60,&local_2c);
  local_4c = local_88;
  local_44 = local_80;
  local_48 = ALBW_AS_F32(DAT_00522154);
  uVar8 = DAT_00522154;
  func_00115DC8(&local_4c);
  fVar7 = DAT_00522158;
  func_00115D70(&local_4c,&local_4c,DAT_00522158);
  func_00115C54(&local_88,&local_2c,&local_4c);
  local_60 = local_88;
  fStack_5c = local_84;
  local_58 = local_80;
  pfVar5 = (float *)func_0054FA10(iVar3,uVar4);
  func_00115C54(&local_84,&local_60,pfVar5);
  fStack_74 = local_7c;
  fStack_78 = local_80;
  fVar6 = local_84;
  local_38 = local_84;
  local_34 = local_80;
  fStack_30 = local_7c;
  local_88 = local_60;
  local_84 = fStack_5c;
  local_80 = local_58;
  local_7c = fVar6;
  local_70 = func_0032EF0C(&local_60,&local_38);
  fStack_6c = albw_s012_get()[1];
  *(float *)(albw_frame + 0x28) = albw_s012_get()[2];
  in_s2 = albw_s012_get()[2];
  local_64 = -(local_70 * local_88) + -(in_s2 * local_80);
  fVar6 = local_80;
  bVar1 = func_00550078(&local_88,param_2);
  if (bVar1) {
    uVar2 = 0;
  }
  else {
    pfVar5 = (float *)func_0054F9B8(iVar3,uVar4);
    local_60 = *pfVar5;
    fStack_5c = pfVar5[1];
    local_58 = pfVar5[2];
    pfVar5 = (float *)func_0054F9E4(iVar3,uVar4);
    local_34 = *pfVar5;
    fStack_30 = pfVar5[1];
    local_2c = pfVar5[2];
    func_00115C70(&local_88,&local_60,&local_34);
    local_40 = local_88;
    local_38 = local_80;
    local_3c = uVar8;
    func_00115DC8(&local_40);
    func_00115D70(&local_40,&local_40,fVar7);
    func_00115C54(&local_88,&local_34,&local_40);
    local_60 = local_88;
    fStack_5c = local_84;
    local_58 = local_80;
    pfVar5 = (float *)func_0054FA10(iVar3,uVar4);
    func_00115C54(&local_84,&local_60,pfVar5);
    fStack_74 = local_7c;
    fStack_78 = local_80;
    fVar7 = local_84;
    local_4c = local_84;
    local_48 = local_80;
    local_44 = local_7c;
    local_88 = local_60;
    local_84 = fStack_5c;
    local_80 = local_58;
    local_7c = fVar7;
    local_70 = func_0032EF0C(&local_60,&local_4c);
    fStack_6c = albw_s012_get()[1];
    *(float *)(albw_frame + 0x28) = albw_s012_get()[2];
    in_s2 = albw_s012_get()[2];
    local_64 = -(local_70 * local_88) + -(in_s2 * local_80);
    fStack_6c = fVar6;
    bVar1 = func_00550078(&local_88,param_2);
    uVar2 = 0;
    if (bVar1) {
      uVar2 = 1;
    }
  }
  return uVar2;
}

