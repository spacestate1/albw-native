/* compilefix: USA 00141A3C (EU 00141A3C), the converted stage-2 text.
 * Fixed (BOOT_LOG 184): the ARM compares the float's bits (vmov rX, sY; cmp), which the converted text
 * wrote as a conversion of the value to an integer. */
#include "ghidra_types.h"

extern int func_001151EC(undefined4 *param_1,undefined4 *param_2);
extern int func_00115C70(float *param_1,float *param_2,float *param_3);
extern int func_00115CE4(float *param_1,float *param_2,float *param_3);
extern int func_00115D18(float *param_1,float *param_2,float *param_3);
extern int func_00115D70(float *param_1,float *param_2,float fparam_0);
extern int func_00141FB4(int *param_1);
extern int func_001424F0(int param_1,int param_2);
extern int func_0014FAFC(int param_1,uint param_2,float fparam_0);
extern int func_0037C358(undefined4 *param_1,float *param_2,uint param_3,int param_4,float fparam_0, float fparam_1);
extern int func_004904CC(float fparam_0,float fparam_1);
extern float func_00491624(float *param_1,uint param_2,uint param_3,uint param_4);
extern int func_004D80A4(float *param_1,uint param_2,float fparam_0);
extern int func_0052FBA0(int param_1,uint param_2);
extern float DAT_00141d5c;
extern int DAT_00141d60;
extern float DAT_00141d64;
extern int DAT_00141d68;
extern float DAT_00141d6c;
extern float DAT_00141d70;
extern float DAT_00141d74;
extern float DAT_00141d78;
extern int DAT_00141d7c;
extern float DAT_00141d80;
extern float DAT_00141d84;
extern float DAT_00141d88;
extern float DAT_00141d8c;
extern float DAT_00141d90;
extern float DAT_00141d94;
extern int *DAT_00141d98;

// USA 00141A3C <- EU 00141A3C (Ghidra, non-matching)
// GLOBAL DAT_00141d5c float
// GLOBAL DAT_00141d60 int
// GLOBAL DAT_00141d64 float
// GLOBAL DAT_00141d68 int
// GLOBAL DAT_00141d6c float
// GLOBAL DAT_00141d70 float
// GLOBAL DAT_00141d74 float
// GLOBAL DAT_00141d78 float
// GLOBAL DAT_00141d7c int
// GLOBAL DAT_00141d80 float
// GLOBAL DAT_00141d84 float
// GLOBAL DAT_00141d88 float
// GLOBAL DAT_00141d8c float
// GLOBAL DAT_00141d90 float
// GLOBAL DAT_00141d94 float
// GLOBAL DAT_00141d98 int *

undefined4 func_00141A3C(int *param_1,float *param_2,float *param_3)

{
  int iVar1;
  uint uVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fparam_0;
  _Alignas(8) unsigned char albw_frame[0x80];
  #define local_80 (*(float *)(albw_frame + 0x0))
  #define local_7c (*(float *)(albw_frame + 0x4))
  #define local_78 (*(float *)(albw_frame + 0x8))
  #define local_74 ((float *)(albw_frame + 0xc))
  #define local_6c (*(float *)(albw_frame + 0x14))
  #define afStack_68 ((float *)(albw_frame + 0x18))
  #define local_44 (*(float *)(albw_frame + 0x3c))
  #define local_40 (*(float *)(albw_frame + 0x40))
  #define local_3c (*(float *)(albw_frame + 0x44))
  #define local_38 (*(float *)(albw_frame + 0x48))
  #define local_34 (*(float *)(albw_frame + 0x4c))
  #define local_30 (*(float *)(albw_frame + 0x50))
  fparam_0 = DAT_00141d5c;
  func_004D80A4(local_74,param_1[0xfa],DAT_00141d5c);
  func_00115C70(&local_80,param_2,(float *)(param_1 + 0xf4));
  fVar7 = local_80 * local_74[0] + local_78 * local_6c;
  fVar3 = DAT_00141d64;
  if (((int)ALBW_AS_U32(fVar7) < DAT_00141d60) && (fVar3 = fVar7, (int)ALBW_AS_U32(fVar7) < DAT_00141d68)) {
    fVar3 = DAT_00141d6c;
  }
  fVar7 = DAT_00141d64;
  func_00115D70(local_74,local_74,fVar3);
  func_0014FAFC((int)param_1,param_1[0xfa],DAT_00141d70);
  local_40 = DAT_00141d74;
  fVar6 = fVar3 * fVar7;
  if ((int)ALBW_AS_U32(fVar3 * fVar7) < 0x3f800000) {
    fVar6 = fparam_0;
  }
  if ((uint)ALBW_AS_U32(local_7c) < 0xc0800001) {
    if ((DAT_00141d7c <= (int)ALBW_AS_U32(fVar3)) || (DAT_00141d74 < local_7c)) {
      fVar3 = (fVar3 - DAT_00141d84) * DAT_00141d88;
      if ((int)ALBW_AS_U32(local_7c) < 0x3fc00000) {
        fVar5 = fVar6 * DAT_00141d90;
        fVar4 = local_7c;
        if (local_7c < DAT_00141d74) {
          fVar4 = DAT_00141d74;
        }
        fVar3 = ((fVar4 + fVar3 * DAT_00141d8c) * fVar7) / (fVar6 * fVar6);
        param_1[0x142] = (int)ALBW_AS_U32(fVar3);
        param_1[0xf8] = (int)ALBW_AS_U32((local_7c / fVar6 + fVar3 * fVar5));
      }
      else {
        fVar5 = DAT_00141d94 / fVar6;
        fVar4 = fVar6 * DAT_00141d90;
        fVar3 = ((DAT_00141d94 + fVar3 * DAT_00141d8c) * fVar7) / (fVar6 * fVar6);
        param_1[0x142] = (int)ALBW_AS_U32(fVar3);
        param_1[0xf8] = (int)ALBW_AS_U32((fVar5 + fVar3 * fVar4));
      }
    }
    else {
      param_1[0x142] = (int)ALBW_AS_U32(((local_7c * DAT_00141d80) / (fVar6 * fVar6)));
      param_1[0xf8] = (int)ALBW_AS_U32(local_40);
    }
  }
  else {
    param_1[0x142] = (int)ALBW_AS_U32(((local_7c * DAT_00141d78) / (fVar6 * fVar6)));
    param_1[0xf8] = (int)ALBW_AS_U32(local_40);
  }
  iVar1 = func_004904CC(ALBW_AS_F32(param_1[0xf8]),
                        SQRT(ALBW_AS_F32(param_1[0xf7]) * ALBW_AS_F32(param_1[0xf7]) +
                             ALBW_AS_F32(param_1[0xf9]) * ALBW_AS_F32(param_1[0xf9])));
  param_1[0x143] = iVar1;
  func_001151EC(param_1 + 0x152,param_3);
  func_001424F0((int)param_1,0);
  param_1[0x130] = param_1[0xf7];
  param_1[0x131] = param_1[0xf8];
  param_1[0x132] = param_1[0xf9];
  local_44 = fparam_0;
  local_3c = local_40;
  local_38 = local_40;
  local_34 = local_40;
  local_30 = fparam_0;
  func_00115D18(&local_38,param_3,&local_38);
  func_00115D18(&local_44,param_3,&local_44);
  iVar1 = func_004904CC(local_38,local_30);
  uVar2 = func_004904CC(local_34,SQRT(local_38 * local_38 + local_30 * local_30));
  func_00491624(afStack_68,0,-iVar1,0);
  func_00115CE4(&local_44,afStack_68,&local_44);
  func_00491624(afStack_68,uVar2,0,0);
  func_00115CE4(&local_44,afStack_68,&local_44);
  iVar1 = func_004904CC(local_40,local_44);
  param_1[0x144] = iVar1;
  iVar1 = func_0052FBA0(*DAT_00141d98 + 0x3dbbc,param_1[0x14]);
  if (iVar1 != 0) {
    if (0x40000000 < (int)ALBW_AS_U32(fVar6)) {
      fVar6 = fVar6 - fparam_0;
    }
    func_0037C358(param_1 + 0x110,(float *)(iVar1 + 0x3d0),*(uint *)(iVar1 + 1000),(int)fVar6,
                  fparam_0,fparam_0);
  }
  return func_00141FB4(param_1);
}

