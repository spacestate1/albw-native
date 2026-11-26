/* compilefix: USA 0020643C, the converted stage-2 text with y and z of the hit direction
 * (a vector returned in s0..s2 on ARM: BOOT_LOG 178). */
#include "ghidra_types.h"

extern int func_00115D70(float *param_1,float *param_2,float fparam_0);
extern int func_00150A84(int *param_1,int *param_2,int param_3);
extern int func_004FAB60(int param_1,undefined4 param_2,int param_3);
extern int func_004FABDC(int param_1,undefined4 param_2,uint param_3,int param_4);
extern int func_004FACD4(int param_1,int *param_2,undefined4 param_3,int *param_4);
extern int func_004FB070(int param_1,float fparam_0);
extern int func_004FB4C4(int param_1,float fparam_0);
extern float func_004FBF58(int *param_1);
extern int iRam00206588;
extern float DAT_00206560;
extern float DAT_00206564;
extern int DAT_00206568;
extern float DAT_0020656c;
extern undefined DAT_00206570;
extern char s_cf_00206574[];
extern undefined4 _DAT_00206570;

float *albw_s012_get(void);   /* s0..s2 of a returned vector (native/runtime/vec3ret.c) */

// USA 0020643C <- EU 0020643C (Ghidra, non-matching)
// GLOBAL DAT_00206560 float
// GLOBAL DAT_00206564 float
// GLOBAL DAT_00206568 int
// GLOBAL DAT_0020656c float
// GLOBAL DAT_00206570 undefined
// GLOBAL UNK_00206588 int

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 func_0020643C(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  float fparam_0;
  float fparam_0_00;
  _Alignas(8) unsigned char albw_frame[0x30];
  #define local_30 ((float *)(albw_frame + 0x0))
  #define iStack_20 (*(int *)(albw_frame + 0x10))
  #define pcStack_1c (*(char * *)(albw_frame + 0x14))
  param_1[0x167] = param_1[0x167] | 0x4000;
  local_30[0] = func_004FBF58(param_1);
  local_30[1] = albw_s012_get()[1];
  local_30[2] = albw_s012_get()[2];
  fparam_0 = DAT_00206560;
  param_1[0xf7] = (int)ALBW_AS_U32(DAT_00206560);
  param_1[0xf8] = (int)ALBW_AS_U32(fparam_0);
  param_1[0xf9] = (int)ALBW_AS_U32(fparam_0);
  func_00115D70((float *)(param_1 + 0xf7),local_30,DAT_00206564);
  param_1[0x24f] = (int)ALBW_AS_U32(fparam_0);
  param_1[0x250] = (int)ALBW_AS_U32(fparam_0);
  param_1[0x251] = (int)ALBW_AS_U32(fparam_0);
  func_00115D70((float *)(param_1 + 0x24f),local_30,fparam_0);
  iVar1 = DAT_00206568;
  param_1[0x249] = 0x28;
  param_1[0x24a] = iVar1;
  iVar1 = _DAT_00206570;
  param_1[0x248] = 0;
  param_1[0x24c] = 4;
  param_1[0x24d] = iVar1;
  param_1[0x24b] = 0;
  fparam_0_00 = DAT_0020656c;
  piVar3 = (int *)0x0;
  param_1[0x24e] = param_1[0xfa];
  func_004FABDC((int)param_1,7,0xffffffff,0);
  uVar2 = 0;
  func_004FAB60((int)param_1,2,0);
  func_004FB070((int)param_1,fparam_0);
  func_004FB4C4((int)param_1,fparam_0_00);
  func_004FACD4((int)param_1,(int *)0x0,uVar2,piVar3);
  pcStack_1c = s_cf_00206574;
  iStack_20 = iRam00206588;
  return func_00150A84(param_1,&iStack_20,0);
}

