/* compilefix: USA 001818F8, the converted stage-2 text with y and z of the returned vector
 * (a vector returned in s0..s2 on ARM: BOOT_LOG 178). */
#include "ghidra_types.h"

extern int func_00100174(int *param_1);
extern int func_00115C54(float *param_1,float *param_2,float *param_3);
extern int func_001507A8(int param_1,int param_2);
extern int func_00520EE4(int param_1);
extern int func_00520FF8(int param_1);
extern int func_0052FBA0(int param_1,uint param_2);
extern float func_005445F8(int param_1);
extern int func_00588BE4(int param_1);
extern int *DAT_00181aa4;
extern int *DAT_00181aa8;
extern int DAT_00181aac;
extern int *DAT_00181ab0;
extern int *DAT_00181ab4;
extern int *DAT_00181ab8;
extern uint *DAT_00181abc;
extern undefined4 *DAT_00181ac0;
extern undefined4 DAT_00181ac4;
extern int *DAT_00181ac8;
extern int *DAT_00181acc;

float *albw_s012_get(void);   /* s0..s2 of a returned vector (native/runtime/vec3ret.c) */

// USA 001818F8 <- EU 001818F8 (Ghidra, non-matching)
// GLOBAL DAT_00181aa4 int *
// GLOBAL DAT_00181aa8 int *
// GLOBAL DAT_00181aac int
// GLOBAL DAT_00181ab0 int *
// GLOBAL DAT_00181ab4 int *
// GLOBAL DAT_00181ab8 int *
// GLOBAL DAT_00181abc uint *
// GLOBAL DAT_00181ac0 undefined4 *
// GLOBAL DAT_00181ac4 undefined4
// GLOBAL DAT_00181ac8 int *
// GLOBAL DAT_00181acc int *

bool func_001818F8(int param_1,int param_2)

{
  bool bVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  undefined4 in_s1;
  undefined4 in_s2;
  
  if (*(char *)(param_1 + 0x964) == '\t') {
    bVar1 = true;
    if (DAT_00181aac < *(int *)(param_2 + 8)) {
      return false;
    }
  }
  else {
    bVar1 = false;
  }
  puVar2 = (undefined4 *)func_0052FBA0(*DAT_00181aa4 + 0x3dbbc,*(uint *)(param_2 + 0x28));
  if (puVar2 != (undefined4 *)0x0) {
    iVar3 = func_00588BE4((int)puVar2);
    if (iVar3 == *DAT_00181aa8) {
      fVar5 = func_005445F8(puVar2);
      in_s1 = ALBW_AS_U32(albw_s012_get()[1]);
      in_s2 = ALBW_AS_U32(albw_s012_get()[2]);
      *(float *)(param_1 + 0xa34) = fVar5;
      *(undefined4 *)(param_1 + 0xa38) = in_s1;
      *(undefined4 *)(param_1 + 0xa3c) = in_s2;
      *(undefined1 *)(param_1 + 0xbef) = 0;
      if (bVar1) {
        return false;
      }
    }
    if (((iVar3 != *DAT_00181ab0) && (iVar3 != *DAT_00181ab4)) && (iVar3 != *DAT_00181ab8)) {
      *(undefined1 *)(param_1 + 0xbef) = 0;
    }
    if (((*DAT_00181abc & 1) == 0) && (iVar4 = func_00100174((int *)DAT_00181abc), iVar4 != 0)) {
      *DAT_00181ac0 = DAT_00181ac4;
    }
    iVar4 = (**(code **)*puVar2)(puVar2,DAT_00181ac0);
    if (iVar4 == 0) {
      puVar2 = (undefined4 *)0x0;
    }
    if (((puVar2 != (undefined4 *)0x0) || (iVar3 == *DAT_00181ac8)) || (iVar3 == *DAT_00181acc)) {
      return false;
    }
  }
  bVar1 = func_001507A8(param_1,param_2);
  if (bVar1) {
    func_00115C54((float *)(param_1 + 0xa28),(float *)(param_1 + 0xa28),(float *)(param_2 + 4));
    iVar3 = func_00520EE4(param_1);
    if ((iVar3 != 0) || (iVar3 = func_00520FF8(param_1), iVar3 != 0)) {
      *(undefined1 *)(param_1 + 0xbef) = 0;
    }
  }
  return bVar1;
}

