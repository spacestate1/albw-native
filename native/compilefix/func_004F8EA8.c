/* compilefix: USA 004F8EA8 (EU 004F8E80) enemy hit processing, the converted stage-2 text with the
 * Vec3 returns restored (BOOT_LOG 160l): 004FA174 (hit direction) and the enemy virtual vt+0x58
 * (EU 0058A7C0: the hit record's direction) return a Vec3 in s0..s2 (ARM hard-float HFA); Ghidra
 * kept s0 only and filled y / z with stale register stand-ins. The direction came out as
 * (x, z-ish, garbage): flying enemies (Poes, type 1) were knocked back UPWARD and stayed out of
 * reach. The values come through albw_s012 (native/runtime/vec3ret.c). Confidence: high. */
#include "ghidra_types.h"
float *albw_s012_get(void);   /* s0..s2 of a Vec3 return, per thread (native/runtime/vec3ret.c) */
#define albw_s012 (albw_s012_get())

extern float func_00115DC8(float *param_1);
extern int func_002ABDE8(undefined4 *param_1,uint param_2,int param_3,undefined4 *param_4, undefined1 param_5,undefined4 param_6,int param_7);
extern int func_004F5390(undefined4 *param_1,int param_2,undefined4 *param_3,undefined1 param_4, undefined4 param_5,float fparam_0);
extern int func_004F5494(undefined4 *param_1);
extern float func_004FA174(float *param_1,int param_2,int param_3,uint in_r3,float *param_4,int param_5,int param_6);
extern int func_00542AE4(int param_1,uint param_2);
extern undefined4 *DAT_004f91e8;
extern float DAT_004f91ec;
extern int *DAT_004f91f0;
extern float DAT_004f91f4;
extern undefined4 *DAT_004f91f8;
extern int DAT_004f93a0;
extern int DAT_004f93a4;
extern int DAT_004f93a8;
extern int DAT_004f93ac;

// USA 004F8EA8 <- EU 004F8E80 (Ghidra, non-matching)
// GLOBAL DAT_004f91e8 undefined4 *
// GLOBAL DAT_004f91ec float
// GLOBAL DAT_004f91f0 int *
// GLOBAL DAT_004f91f4 float
// GLOBAL DAT_004f91f8 undefined4 *
// GLOBAL DAT_004f93a0 int
// GLOBAL DAT_004f93a4 int
// GLOBAL DAT_004f93a8 int
// GLOBAL DAT_004f93ac int

bool func_004F8EA8(int *param_1,uint param_2,float *param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  int iVar8;
  undefined1 uVar9;
  uint in_fpscr;
  float fVar10;
  int iVar11;
  float fVar12;
  float fVar13;
  float in_s2;
  _Alignas(8) unsigned char albw_frame[0x80];
  #define local_7c (*(float *)(albw_frame + 0x4))
  #define local_78 (*(float *)(albw_frame + 0x8))
  #define local_74 (*(float *)(albw_frame + 0xc))
  #define local_70 (*(undefined4 *)(albw_frame + 0x10))
  #define uStack_6c (*(undefined4 *)(albw_frame + 0x14))
  #define uStack_68 (*(undefined4 *)(albw_frame + 0x18))
  #define local_64 (*(float *)(albw_frame + 0x1c))
  #define local_60 (*(float *)(albw_frame + 0x20))
  #define local_5c (*(float *)(albw_frame + 0x24))
  #define local_4c (*(char *)(albw_frame + 0x34))
  #define local_4b (*(undefined1 *)(albw_frame + 0x35))
  #define local_4a (*(undefined1 *)(albw_frame + 0x36))
  #define local_49 (*(undefined1 *)(albw_frame + 0x37))
  #define local_48 (*(undefined1 *)(albw_frame + 0x38))
  #define local_47 (*(undefined1 *)(albw_frame + 0x39))
  #define local_46 (*(undefined1 *)(albw_frame + 0x3a))
  #define local_44 (*(float *)(albw_frame + 0x3c))
  #define local_40 (*(int *)(albw_frame + 0x40))
  #define local_3c (*(int *)(albw_frame + 0x44))
  #define local_38 (*(undefined4 *)(albw_frame + 0x48))
  #define uStack_34 (*(undefined4 *)(albw_frame + 0x4c))
  #define local_30 (*(undefined4 *)(albw_frame + 0x50))
  if (param_2 == 0) {
    bVar4 = func_002ABDE8((undefined4 *)param_1[0x144],0,param_1[0x10f],DAT_004f91f8,0,1,0);
    return bVar4;
  }
  iVar5 = func_00542AE4(param_1[0x144],param_2 & 0xff);
  if (iVar5 == 0) {
    return false;
  }
  if (param_2 != 3) {
    iVar5 = param_1[0x10f];
  }
  iVar8 = param_1[0x10f];
  if (param_2 != 3) {
    uVar9 = (undefined1)*(undefined2 *)(iVar5 + 0x30);
  }
  else {
    uVar9 = 0;
  }
  iVar5 = (int)*(char *)(iVar8 + 0x21);
  uint hit_byte = *(byte *)(iVar8 + 0x20);   /* r9, EU 4F8ED0 */
  uVar1 = *(uint *)(iVar8 + 0x38) >> 0x1c;
  local_7c = func_004FA174((float *)(param_1 + 0xf4),iVar8,param_2,hit_byte,param_3,iVar5,uVar1);
  local_78 = albw_s012[1];   /* Vec3 return: s1 / s2 */
  local_74 = albw_s012[2];
  local_70 = *DAT_004f91e8;
  uStack_6c = DAT_004f91e8[1];
  uStack_68 = DAT_004f91e8[2];
  local_4c = '\0';
  local_4b = 0;
  local_48 = 0;
  local_4a = 0;
  local_47 = 0;
  local_49 = 0;
  local_46 = 0;
  local_44 = DAT_004f91ec;
  local_40 = 0;
  local_3c = 0;
  local_38 = *DAT_004f91e8;
  uStack_34 = DAT_004f91e8[1];
  local_30 = DAT_004f91e8[2];
  fVar12 = DAT_004f91ec;
  func_004F5494(&local_70);
  if (param_2 == 3) {
    if (*(int *)param_1[0x10f] == 0) {
      if (iVar5 == 0xc) {
LAB_004f9180:
        fVar10 = ALBW_AS_F32(param_1[0x1e6]);
        fVar13 = *(float *)(*(int *)(*DAT_004f91f0 + 0x1c) + 4);
        in_s2 = fVar13 + fVar10;
      }
      else {
        if (iVar5 < 0xd) {
          if ((iVar5 == 5 || iVar5 == 8) || iVar5 == 9) goto LAB_004f9180;
        }
        else if ((iVar5 == 0xd || iVar5 == 0xe) || iVar5 == 0x1f) goto LAB_004f9180;
        fVar10 = ALBW_AS_F32(param_1[0xf5]);
        fVar13 = ALBW_AS_F32(param_1[0x1e6]);
        in_s2 = fVar10 + fVar13;
      }
      iVar8 = param_1[0xfa];
      func_004F5494(&local_70);
      local_64 = local_7c;
      local_44 = in_s2;
      local_3c = iVar8;
    }
    else {
      if (iVar5 == 0xc) {
LAB_004f9158:
        fVar13 = *(float *)(*(int *)(*DAT_004f91f0 + 0x1c) + 4);
        fVar10 = fVar13 + ALBW_AS_F32(param_1[0x1e6]);
      }
      else {
        if (iVar5 < 0xd) {
          if ((iVar5 == 5 || iVar5 == 8) || iVar5 == 9) goto LAB_004f9158;
        }
        else if ((iVar5 == 0xd || iVar5 == 0xe) || iVar5 == 0x1f) goto LAB_004f9158;
        fVar13 = ALBW_AS_F32(param_1[0x1e6]);
        fVar10 = ALBW_AS_F32(param_1[0xf5]) + fVar13;
      }
      func_004F5390(&local_70,param_1[0x10f],&local_7c,uVar9,param_1[0xfa],fVar10);
    }
  }
  else {
    if (iVar5 == 0xc) {
LAB_004f91a8:
      fVar13 = *(float *)(*(int *)(*DAT_004f91f0 + 0x1c) + 4);
      fVar10 = fVar13 + ALBW_AS_F32(param_1[0x1e6]);
    }
    else {
      if (iVar5 < 0xd) {
        if ((iVar5 == 5 || iVar5 == 8) || iVar5 == 9) goto LAB_004f91a8;
      }
      else if ((iVar5 == 0xd || iVar5 == 0xe) || iVar5 == 0x1f) goto LAB_004f91a8;
      fVar13 = ALBW_AS_F32(param_1[0x1e6]);
      fVar10 = ALBW_AS_F32(param_1[0xf5]) + fVar13;
    }
    func_004F5390(&local_70,param_1[0x10f],&local_7c,uVar9,param_1[0xfa],fVar10);
  }
  (**(code **)(*param_1 + 0x58))(param_1,param_2,&local_70);
  local_7c = albw_s012[0];   /* vt+0x58 returns a Vec3 in s0..s2 (EU 4F8FCC vstmia {s0-s2}) */
  local_78 = albw_s012[1];
  local_74 = albw_s012[2];
  func_00115DC8(&local_7c);
  local_64 = local_7c;
  local_60 = local_78;
  local_5c = local_74;
  param_1[0x168] = param_1[0x168] & 0xffffff7f;
  uVar6 = (**(code **)(*param_1 + 0x5c))(param_1,param_2,&local_70);
  fVar10 = DAT_004f91f4;
  *(char *)((int)param_1 + 0x897) = *(char *)((int)param_1 + 0x897) + '\x01';
  iVar3 = DAT_004f93ac;
  iVar2 = DAT_004f93a8;
  iVar11 = DAT_004f93a4;
  iVar8 = DAT_004f93a0;
  if (local_4c != '\x05') {
    if (local_4c == '\x06') {
      param_1[0x1ac] = 0x1e;
      param_1[0x1ad] = iVar2;
      param_1[0x1ab] = 0;
      goto switchD_004f91cc_default;
    }
    if (local_4c != '\x0e') {
      if (local_4c == '\f') {
        param_1[0x228] = local_40;
      }
      else if (local_4c == '\v') {
        param_1[0x229] = local_40;
      }
      goto switchD_004f91cc_default;
    }
    piVar7 = param_1 + 0x1c6;
    param_1[0x1c7] = 0x32;
    param_1[0x1c8] = iVar3;
    goto LAB_004f9218;
  }
  switch(local_48) {
  case 0:
    iVar8 = (int)*(short *)((int)param_1 + 0x786);
    piVar7 = param_1 + 0x1a2;
    if (iVar8 < 0) {
      iVar8 = 0x16;
    }
    param_1[0x1a3] = iVar8;
    if (iVar8 != 0) goto LAB_004f9308;
LAB_004f9300:
    piVar7[2] = (int)ALBW_AS_U32(fVar12);
    break;
  case 1:
    iVar8 = (int)(short)param_1[0x1e2];
    piVar7 = param_1 + 0x1a5;
    if (iVar8 < 0) {
      iVar8 = 0x16;
    }
    param_1[0x1a6] = iVar8;
    if (iVar8 == 0) goto LAB_004f9300;
LAB_004f9308:
    fVar13 = (float)VectorUnsignedToFloat(iVar8,(byte)(in_fpscr >> 0x15) & 3);
    in_s2 = fVar10 / fVar13;
    piVar7[2] = (int)ALBW_AS_U32(in_s2);
    break;
  case 2:
  case 4:
    piVar7 = param_1 + 0x19f;
    param_1[0x1a0] = 0x3c;
    iVar11 = iVar8;
    goto LAB_004f9214;
  case 3:
    piVar7 = param_1 + 0x1a8;
    param_1[0x1a9] = 0x20;
LAB_004f9214:
    piVar7[2] = iVar11;
LAB_004f9218:
    *piVar7 = 0;
  default:
    goto switchD_004f91cc_default;
  }
  *piVar7 = 0;
switchD_004f91cc_default:
  if (uVar6 != 0x21) {
    if (param_2 != uVar6) {
      fVar12 = func_004FA174((float *)(param_1 + 0xf4),param_1[0x10f],uVar6,hit_byte,param_3,iVar5,uVar1);
      fVar13 = albw_s012[1];   /* Vec3 return: s1 / s2 */
      in_s2 = albw_s012[2];
      local_7c = fVar12;
      local_78 = fVar13;
      local_74 = in_s2;
      local_64 = fVar12;
      local_60 = fVar13;
      local_5c = in_s2;
      (**(code **)(*param_1 + 0x58))(param_1,param_2,&local_70);
      local_7c = albw_s012[0];   /* vt+0x58 Vec3 return */
      local_78 = albw_s012[1];
      local_74 = albw_s012[2];
      func_00115DC8(&local_7c);
      local_64 = local_7c;
      local_60 = local_78;
      local_5c = local_74;
    }
    func_002ABDE8((undefined4 *)param_1[0x144],uVar6 & 0xff,param_1[0x10f],&local_7c,uVar9,1,0);
    if (uVar6 != 0) {
      return true;
    }
  }
  return false;
}

