/* compilefix: USA 0015EF88, the converted stage-2 text with y and z of the three hit points
 * (a vector returned in s0..s2 on ARM: BOOT_LOG 178). */
#include "ghidra_types.h"

extern int func_00115C54(float *param_1,float *param_2,float *param_3);
extern int func_0015C534(undefined4 *param_1);
extern int func_0015FA90(undefined4 *param_1,undefined4 *param_2,undefined4 param_3);
extern int func_002228D0(int param_1,int param_2,uint param_3);
extern int func_004FC07C(int param_1,int param_2,uint param_3,int param_4);
extern int func_00520FC0(void);
extern float func_0054F774(int param_1,float *param_2,uint param_3,uint *param_4);
extern int func_0054F9E4(int param_1,uint param_2);
extern int func_0054FA10(int param_1,uint param_2);
extern int func_0054FAC0(int param_1,uint param_2);
extern int func_0054FBB0(int param_1,int param_2);
extern int func_0054FBC4(int param_1,float *param_2,float *param_3);
extern int func_0054FC84(int param_1,int param_2);
extern int func_0068C690(float *param_1);
extern float DAT_0015f37c;
extern float DAT_0015f380;
extern float DAT_0015f384;
extern float *DAT_0015f388;
extern undefined4 DAT_0015f428;
extern undefined4 DAT_0015f42c;

float *albw_s012_get(void);   /* s0..s2 of a returned vector (native/runtime/vec3ret.c) */

// USA 0015EF88 <- EU 0015EF8C (Ghidra, non-matching)
// GLOBAL DAT_0015f37c float
// GLOBAL DAT_0015f380 float
// GLOBAL DAT_0015f384 float
// GLOBAL DAT_0015f388 float *
// GLOBAL DAT_0015f428 undefined4
// GLOBAL DAT_0015f42c undefined4

void func_0015EF88(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  float *pfVar7;
  int iVar8;
  float fVar9;
  float fVar10;
  float in_s2;
  float fVar11;
  float fVar12;
  _Alignas(8) unsigned char albw_frame[0x70];
  #define local_64 (*(float *)(albw_frame + 0xc))
  #define fStack_60 (*(float *)(albw_frame + 0x10))
  #define local_5c (*(float *)(albw_frame + 0x14))
  #define local_58 (*(float *)(albw_frame + 0x18))
  #define fStack_54 (*(float *)(albw_frame + 0x1c))
  #define local_50 (*(float *)(albw_frame + 0x20))
  #define local_4c (*(float *)(albw_frame + 0x24))
  #define local_48 (*(float *)(albw_frame + 0x28))
  #define local_44 (*(float *)(albw_frame + 0x2c))
  #define local_40 (*(uint *)(albw_frame + 0x30))
  #define local_3c (*(float *)(albw_frame + 0x34))
  #define uStack_38 (*(undefined4 *)(albw_frame + 0x38))
  #define local_34 (*(float *)(albw_frame + 0x3c))
  func_004FC07C((int)param_1,1,0xffffffff,0);
  if (param_1[600] != 0) {
    func_002228D0(param_1[600],1,0xffffffff);
  }
  puVar5 = param_1 + 0x26d;
  if ((*(ushort *)((int)param_1 + 0x2e) & 0xff) == 0) {
    uVar6 = func_0054FBC4((int)puVar5,(float *)(param_1 + 0xf4),(float *)0x0);
    uVar3 = func_0054FC84((int)puVar5,uVar6);
    uVar1 = func_0054FAC0((int)puVar5,uVar3);
    puVar4 = (undefined4 *)func_0054F9E4((int)puVar5,uVar3);
    func_0015FA90(param_1,puVar4,uVar1);
    uVar3 = func_0054FBB0((int)puVar5,uVar6);
    uVar1 = func_0054FAC0((int)puVar5,uVar3);
    puVar4 = (undefined4 *)func_0054F9E4((int)puVar5,uVar3);
    func_0015FA90(param_1,puVar4,uVar1);
    iVar8 = func_0015C534(param_1);
    if (iVar8 != 0) {
      pfVar7 = (float *)func_0054FA10((int)puVar5,uVar6);
      local_58 = *pfVar7;
      fStack_54 = pfVar7[1];
      local_50 = pfVar7[2];
      local_64 = 0.0;
      uVar3 = func_0068C690(&local_58);
      pfVar7 = (float *)func_0054F9E4((int)puVar5,uVar6);
      func_0054F774((int)puVar5,pfVar7,uVar3,(uint *)&local_64);
      uVar1 = func_0054FAC0((int)puVar5,(uint)ALBW_AS_U32(local_64));
      puVar5 = (undefined4 *)func_0054F9E4((int)puVar5,(uint)ALBW_AS_U32(local_64));
      func_0015FA90(param_1,puVar5,uVar1);
    }
  }
  else {
    local_4c = DAT_0015f380;
    local_48 = DAT_0015f37c;
    local_44 = DAT_0015f37c;
    fVar9 = ALBW_AS_F32(param_1[0x26d]);
    if (fVar9 < ALBW_AS_F32(param_1[0xf4])) {
      local_4c = DAT_0015f384;
    }
    local_64 = *DAT_0015f388;
    fStack_60 = DAT_0015f388[1];
    local_5c = DAT_0015f388[2];
    local_58 = *DAT_0015f388;
    fStack_54 = DAT_0015f388[1];
    local_50 = DAT_0015f388[2];
    local_3c = ALBW_AS_F32(param_1[0xf4]);
    uStack_38 = param_1[0xf5];
    local_34 = ALBW_AS_F32(param_1[0xf6]);
    local_40 = 0;
    fVar11 = DAT_0015f37c;
    fVar12 = DAT_0015f380;
    local_58 = func_0054F774((int)puVar5,&local_3c,param_1[0xfa] + 0x80000000,&local_40);
    fStack_54 = albw_s012_get()[1];
    local_50 = albw_s012_get()[2];
    uVar1 = func_0054FAC0((int)puVar5,local_40);
    func_00115C54(&local_58,&local_58,&local_4c);
    fVar10 = ALBW_AS_F32(param_1[0x26d]);
    fVar9 = ALBW_AS_F32(param_1[0xf4]) - fVar10;
    if (fVar9 <= fVar11) {
      fVar9 = -fVar9;
    }
    local_4c = -local_4c;
    if ((int)ALBW_AS_U32(fVar9) < 0x40000000) {
      local_3c = ALBW_AS_F32(param_1[0xf4]);
      uStack_38 = param_1[0xf5];
      local_34 = ALBW_AS_F32(param_1[0xf6]);
      local_40 = 0;
      local_64 = func_0054F774((int)puVar5,&local_3c,param_1[0xfa] + 0x80000000,&local_40);
      fStack_60 = albw_s012_get()[1];
      local_5c = albw_s012_get()[2];
      uVar2 = func_0054FAC0((int)puVar5,local_40);
      func_00115C54(&local_64,&local_64,&local_4c);
    }
    else {
      local_3c = ALBW_AS_F32(param_1[0x26d]);
      uStack_38 = param_1[0x26e];
      fVar9 = ALBW_AS_F32(param_1[0xf6]);
      if (ALBW_AS_F32(param_1[0x26f]) < fVar9) {
        local_34 = ALBW_AS_F32(param_1[0x26f]) + fVar12;
      }
      else {
        local_34 = ALBW_AS_F32(param_1[0x26f]) - fVar12;
      }
      uVar6 = func_0068C690(&local_4c);
      local_40 = 0;
      local_64 = func_0054F774((int)puVar5,&local_3c,uVar6,&local_40);
      fStack_60 = albw_s012_get()[1];
      local_5c = albw_s012_get()[2];
      uVar2 = func_0054FAC0((int)puVar5,local_40);
    }
    pfVar7 = (float *)func_00520FC0();
    fVar9 = SQRT((local_58 - *pfVar7) * (local_58 - *pfVar7) +
                 (local_50 - pfVar7[2]) * (local_50 - pfVar7[2]));
    pfVar7 = (float *)func_00520FC0();
    if (SQRT((local_64 - *pfVar7) * (local_64 - *pfVar7) +
             (local_5c - pfVar7[2]) * (local_5c - pfVar7[2])) <= fVar9) {
      func_0015FA90(param_1,&local_64,uVar2);
      iVar8 = func_0015C534(param_1);
      if (iVar8 != 0) {
        fVar9 = ALBW_AS_F32(param_1[0xf4]) - ALBW_AS_F32(param_1[0x26d]);
        if (fVar9 <= fVar11) {
          fVar9 = -fVar9;
        }
        if ((int)ALBW_AS_U32(fVar9) < 0x40000000) {
          func_0015FA90(param_1,&local_58,uVar1);
        }
      }
    }
    else {
      func_0015FA90(param_1,&local_58,uVar1);
      iVar8 = func_0015C534(param_1);
      if (iVar8 != 0) {
        fVar9 = ALBW_AS_F32(param_1[0xf4]) - ALBW_AS_F32(param_1[0x26d]);
        if (fVar9 <= fVar11) {
          fVar9 = -fVar9;
        }
        if ((int)ALBW_AS_U32(fVar9) < 0x40000000) {
          func_0015FA90(param_1,&local_64,uVar2);
        }
      }
    }
  }
  uVar1 = DAT_0015f428;
  param_1[0x239] = 0x5a;
  param_1[0x23a] = uVar1;
  uVar1 = DAT_0015f42c;
  param_1[0x238] = 0;
  param_1[0x255] = 0x14;
  param_1[0x256] = uVar1;
  param_1[0x254] = 0;
  return;
}

