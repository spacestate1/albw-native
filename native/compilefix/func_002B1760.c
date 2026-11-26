/* compilefix: USA 002B1760, the converted stage-2 text with y and z of the hit direction
 * (a vector returned in s0..s2 on ARM: BOOT_LOG 178). */
#include "ghidra_types.h"

extern int func_002ABEC8(int *param_1,int param_2);
extern int func_002ACC88(undefined4 *param_1);
extern int func_002AE594(int param_1,undefined4 *param_2);
extern int func_002AE620(int param_1,undefined4 *param_2,float *param_3);
extern int func_002AE72C(int param_1,undefined4 *param_2);
extern int func_00352128(int param_1,int *param_2,uint *param_3);
extern int func_004A2F38(int param_1,undefined4 *param_2);
extern int func_004F5390(undefined4 *param_1,int param_2,undefined4 *param_3,undefined1 param_4, undefined4 param_5,float fparam_0);
extern int func_004F5520(undefined4 *param_1);
extern float func_004FA13C(float *param_1,int param_2);
extern float func_004FBF4C(void);
extern int func_0058A378(undefined4 *param_1);
extern int *DAT_002b1910;
extern uint *DAT_002b1914;

float *albw_s012_get(void);   /* s0..s2 of a returned vector (native/runtime/vec3ret.c) */

// USA 002B1760 <- EU 002B173C (Ghidra, non-matching)
// GLOBAL DAT_002b1910 int *
// GLOBAL DAT_002b1914 uint *

undefined4 func_002B1760(float *param_1,int *param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  float fVar3;
  _Alignas(8) unsigned char albw_frame[0x80];
  #define auStack_74 ((undefined4 *)(albw_frame + 0xc))
  #define local_50 (*(char *)(albw_frame + 0x30))
  #define local_4d (*(char *)(albw_frame + 0x33))
  #define local_30 ((float *)(albw_frame + 0x50))
  #define local_24 (*(undefined4 *)(albw_frame + 0x5c))
  #define uStack_20 (*(undefined4 *)(albw_frame + 0x60))
  #define local_1c (*(undefined4 *)(albw_frame + 0x64))
  #define local_18 (*(int *)(albw_frame + 0x68))
  #define local_14 (*(int *)(albw_frame + 0x6c))
  local_30[0] = func_004FA13C(param_1,param_3);
  local_30[1] = albw_s012_get()[1];
  local_30[2] = albw_s012_get()[2];
  iVar2 = *(int *)(*DAT_002b1910 + 0x1c);
  func_004F5520(auStack_74);
  fVar3 = func_004FBF4C();
  func_004F5390(auStack_74,param_3,local_30,(char)*(undefined2 *)(param_3 + 0x30),param_2[0xfa],
                fVar3 + *(float *)(iVar2 + 4));
  puVar1 = func_0058A378(auStack_74);
  local_24 = *puVar1;
  uStack_20 = puVar1[1];
  local_1c = puVar1[2];
  if (local_50 == '\t') {
    if (local_4d == '\0') goto LAB_002b1854;
LAB_002b18c8:
    func_002AE594((int)param_2,auStack_74);
LAB_002b18d4:
    func_002ACC88(auStack_74);
  }
  else {
    if (local_50 < '\t') {
      if (local_50 == '\x05') {
        if (local_4d == '\0') {
LAB_002b1854:
          return func_002ACC88(auStack_74);
        }
        func_002AE620((int)param_2,auStack_74,(float *)0x0);
        goto LAB_002b18d4;
      }
      if (local_50 == '\a') {
        if (local_4d == '\0') {
          func_002AE72C((int)param_2,&local_24);
          goto LAB_002b1854;
        }
        goto LAB_002b18c8;
      }
    }
    else {
      if (local_50 == '\v') {
        if (local_4d == '\0') {
          return 0;
        }
        return func_002AE620((int)param_2,auStack_74,(float *)(param_2 + 0xf4));
      }
      if (local_50 == '\x0e') {
        if (local_4d == '\0') {
          return 0;
        }
        local_18 = 0;
        func_00352128((int)(param_2 + 0xc9),&local_18,DAT_002b1914);
        if ((local_18 != 0) && (*(int *)(local_18 + 0x1c) == local_14)) {
          func_004A2F38(local_18,auStack_74);
        }
        goto LAB_002b17f4;
      }
    }
    if (local_4d == '\0') {
      return 0;
    }
  }
LAB_002b17f4:
  return func_002ABEC8(param_2,(int)auStack_74);
}

