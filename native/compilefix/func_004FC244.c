/* compilefix: USA 004FC244, the converted stage-2 text passing 004FA174 its r3 argument (BOOT_LOG 173). */
#include "ghidra_types.h"

extern int func_0014DBF4(int *param_1,int *param_2,undefined4 param_3,int param_4);
extern int func_002AC2D4(int param_1);
extern int func_002AFA70(int param_1,undefined4 *param_2,int param_3,int param_4);
extern int func_004F5390(undefined4 *param_1,int param_2,undefined4 *param_3,undefined1 param_4, undefined4 param_5,float fparam_0);
extern int func_004F5494(undefined4 *param_1);
extern float func_004FA174(float *param_1,int param_2,int param_3,uint in_r3,float *param_4,int param_5,int param_6);
extern int func_004FB4FC(int *param_1,int *param_2);
extern int DAT_004fc4b0;
extern uint *DAT_004fc4b4;
extern float DAT_004fc4b8;
extern int DAT_004fc4bc;
extern int *DAT_004fc4d0;
extern char s_SE_EN_DAMAGE_004fc4c0[];
extern char s_SE_EN_DAMAGE_FIRE_004fc4d4[];

// USA 004FC244 <- EU 004FC21C (Ghidra, non-matching)
// PARAM param_5 Stack[0x0]:4 int
// GLOBAL DAT_004fc4b0 int
// GLOBAL DAT_004fc4b4 uint *
// GLOBAL DAT_004fc4b8 float
// GLOBAL DAT_004fc4bc int
// GLOBAL DAT_004fc4d0 int *
// GLOBAL s_SE_EN_DAMAGE_004fc4c0 string
// GLOBAL s_SE_EN_DAMAGE_FIRE_004fc4d4 string

/* WARNING: Variable defined which should be unmapped: objStack_a4 */

undefined4 func_004FC244(int *param_1,int *param_2,int param_3,undefined4 param_4,int param_5)

{
  uint uVar1;
  uint extraout_r1;
  uint uVar2;
  int extraout_r1_00;
  int iVar3;
  int iVar4;
  uint uVar5;
  short sVar6;
  bool bVar7;
  uint in_fpscr;
  float fVar8;
  float fVar9;
  undefined8 uVar10;
  _Alignas(8) unsigned char albw_frame[0xb0];
  #define objStack_a4 ((uint *)(albw_frame + 0xc))
  #define local_60 (*(int *)(albw_frame + 0x50))
  #define local_5c (*(char * *)(albw_frame + 0x54))
  #define local_54 (*(int *)(albw_frame + 0x5c))
  #define local_50 ((float *)(albw_frame + 0x60))
  #define piStack_34 (*(int * *)(albw_frame + 0x7c))
  #define piStack_30 (*(int * *)(albw_frame + 0x80))
  #define iStack_2c (*(int *)(albw_frame + 0x84))
  #define local_28 (*(undefined4 *)(albw_frame + 0x88))
  iVar4 = param_3;
  if (param_3 == 0) {
    iVar4 = 1;
  }
  piStack_34 = param_1;
  piStack_30 = param_2;
  iStack_2c = param_3;
  local_28 = param_4;
  uVar1 = func_004FB4FC(param_1,param_2);
  uVar5 = (uint)*(char *)((int)param_2 + 0x21);
  objStack_a4[1] = (uint)param_2[0xe] >> 0x1c;
  objStack_a4[0] = uVar5;
  local_50[0] = func_004FA174((float *)(param_1 + 0xf4),param_1[0x10f],uVar1,*(byte *)((int)param_2 + 0x20),(float *)(param_2 + 5),
                              uVar5,objStack_a4[1]);
  iVar3 = DAT_004fc4b0;
  if (uVar1 == 3) {
    sVar6 = 0;
LAB_004fc294:
    local_54 = 0;
  }
  else {
    sVar6 = (short)param_2[0xc];
    if (sVar6 == 0) goto LAB_004fc294;
    local_54 = 1;
  }
  param_1[0x197] = 0;
  param_1[0x198] = iVar3;
  param_1[0x196] = 0;
  func_002AC2D4(param_1[0x144]);
  param_1[0x19a] = 0;
  param_1[0x19b] = iVar3;
  param_1[0x199] = 0;
  if (param_5 != 0 && uVar1 != 0x13) {
    uVar1 = uVar1 & 0xff;
    bVar7 = 0x1d < uVar1;
    uVar2 = extraout_r1;
    if (uVar1 != 0x1e) {
      uVar2 = uVar1 - 0xe;
      bVar7 = 2 < uVar2;
    }
    if ((bVar7 && (uVar1 != 0x1e && uVar2 != 3)) && (uVar1 != 0x12 && uVar1 != 0x1d)) {
      return uVar1;
    }
  }
  objStack_a4[0] = *DAT_004fc4b4;
  objStack_a4[1] = DAT_004fc4b4[1];
  objStack_a4[2] = DAT_004fc4b4[2];
  func_004F5494(objStack_a4);
  if (uVar5 == 0xc) {
LAB_004fc470:
    fVar8 = *(float *)(*(int *)(*DAT_004fc4d0 + 0x1c) + 4) + ALBW_AS_F32(param_1[0x1e6]);
  }
  else {
    if ((int)uVar5 < 0xd) {
      if ((uVar5 == 5 || uVar5 == 8) || uVar5 == 9) goto LAB_004fc470;
    }
    else if ((uVar5 == 0xd || uVar5 == 0xe) || uVar5 == 0x1f) goto LAB_004fc470;
    fVar8 = ALBW_AS_F32(param_1[0xf5]) + ALBW_AS_F32(param_1[0x1e6]);
  }
  func_004F5390(objStack_a4,(int)param_2,local_50,(char)sVar6,local_28,fVar8);
  func_002AFA70(param_1[0x144],objStack_a4,1,0);
  fVar8 = DAT_004fc4b8;
  uVar10 = CONCAT44(DAT_004fc4b8,iVar3);
  param_1[0x197] = iVar4;
  if (iVar4 == 0) {
    param_1[0x198] = iVar3;
  }
  else {
    fVar9 = (float)VectorUnsignedToFloat(iVar4,(byte)(in_fpscr >> 0x15) & 3);
    param_1[0x198] = (int)ALBW_AS_U32((fVar8 / fVar9));
  }
  param_1[0x196] = 0;
  if (local_54 != 0) {
    iVar3 = extraout_r1_00;
    if (uVar5 != 1) {
      iVar3 = 0;
    }
    local_60 = DAT_004fc4bc;
    if (uVar5 == 1 || iVar3 == 1) {
      local_5c = s_SE_EN_DAMAGE_FIRE_004fc4d4;
      func_0014DBF4(param_1,&local_60,objStack_a4,0);
    }
    else {
      local_5c = s_SE_EN_DAMAGE_004fc4c0;
      func_0014DBF4(param_1,&local_60,objStack_a4,0);
    }
    param_1[0x19a] = iVar4;
    if (iVar4 == 0) {
      param_1[0x19b] = (int)uVar10;
    }
    else {
      fVar8 = (float)VectorUnsignedToFloat(iVar4,(byte)(in_fpscr >> 0x15) & 3);
      param_1[0x19b] = (int)ALBW_AS_U32((ALBW_AS_F32(((ulonglong)uVar10 >> 0x20)) / fVar8));
    }
    param_1[0x199] = 0;
  }
  return 0;
}

