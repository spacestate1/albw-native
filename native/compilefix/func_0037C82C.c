/* compilefix: USA 0037C82C (EU 0037C808), the converted stage-2 text.
 * Fixed (BOOT_LOG 187): picking an item up passes the item to the method (vtable +0x50), as the ARM does. */
#include "ghidra_types.h"

extern int func_00100174(int *param_1);
extern int func_0018E508(int param_1);
extern int func_00291F20(int param_1);
extern int func_00315930(int param_1);
extern int func_004C6940(int param_1,int param_2,undefined4 param_3);
extern int func_004EA104(int param_1,int *param_2,int param_3);
extern int func_004EABB8(int param_1,int *param_2,undefined4 *param_3);
extern int func_00521098(undefined4 param_1,int *param_2);
extern int func_0052FBA0(int param_1,uint param_2);
extern int *DAT_0037cb4c;
extern int *DAT_0037cb50;
extern int DAT_0037cb54;
extern undefined4 DAT_0037cb58;
extern uint *DAT_0037cb5c;
extern undefined4 *DAT_0037cb60;
extern uint *DAT_0037cb64;
extern undefined4 *DAT_0037cb68;
extern uint *DAT_0037cb6c;
extern undefined4 *DAT_0037cb70;
extern undefined4 DAT_0037cb74;
extern int *DAT_0037cb78;
extern int *DAT_0037cb7c;
extern int DAT_0037cb80;
extern char s_SE_PL_Net_GET_0037cb84[];

// USA 0037C82C <- EU 0037C808 (Ghidra, non-matching)
// GLOBAL DAT_0037cb4c int *
// GLOBAL DAT_0037cb50 int *
// GLOBAL DAT_0037cb54 int
// GLOBAL DAT_0037cb58 undefined4
// GLOBAL DAT_0037cb5c uint *
// GLOBAL DAT_0037cb60 undefined4 *
// GLOBAL DAT_0037cb64 uint *
// GLOBAL DAT_0037cb68 undefined4 *
// GLOBAL DAT_0037cb6c uint *
// GLOBAL DAT_0037cb70 undefined4 *
// GLOBAL DAT_0037cb74 undefined4
// GLOBAL DAT_0037cb78 int *
// GLOBAL DAT_0037cb7c int *
// GLOBAL DAT_0037cb80 int
// GLOBAL s_SE_PL_Net_GET_0037cb84 string

undefined4 func_0037C82C(int *param_1,int param_2)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  _Alignas(8) unsigned char albw_frame[0x40];
  #define local_38 (*(int *)(albw_frame + 0x8))
  #define local_34 (*(char * *)(albw_frame + 0xc))
  if (*DAT_0037cb4c != 0) {
    func_00291F20(*DAT_0037cb4c);
  }
  uVar5 = DAT_0037cb58;
  piVar1 = DAT_0037cb50;
  if (*(char *)((int)param_1 + 0x426) == '\0') {
    return 0;
  }
  if (*(int *)(param_2 + 0x2c) == 0) {
    return 0;
  }
  uVar6 = *(uint *)(param_2 + 0x28);
  iVar7 = (int)*(char *)(*(int *)(param_2 + 0x2c) + 1);
  if (param_1[0x105] == 0) {
    iVar3 = DAT_0037cb54;
    if (iVar7 == 9) {
      puVar4 = (undefined4 *)func_0052FBA0(*DAT_0037cb50 + 0x3dbbc,uVar6);
      if (puVar4 == (undefined4 *)0x0) {
        return 0;
      }
      if (((*DAT_0037cb5c & 1) == 0) && (iVar7 = func_00100174((int *)DAT_0037cb5c), iVar7 != 0)) {
        *DAT_0037cb60 = uVar5;
      }
      iVar7 = (**(code **)*puVar4)(puVar4,DAT_0037cb60);
      if (iVar7 == 0) {
        puVar4 = (undefined4 *)0x0;
      }
      if (puVar4 == (undefined4 *)0x0) {
        return 1;
      }
      iVar7 = func_0018E508((int)puVar4);
joined_r0x0037c910:
      if (iVar7 == 0) {
        return 1;
      }
      param_1[0x114] = 0;
      param_1[0x105] = uVar6;
      param_1[0xf7] = iVar3;
      param_1[0xf8] = iVar3;
      param_1[0xf9] = iVar3;
      (**(code **)(*param_1 + 0x54))(param_1);
      return 1;
    }
    if (iVar7 == 10) {
      puVar4 = (undefined4 *)func_0052FBA0(*DAT_0037cb50 + 0x3dbbc,uVar6);
      if (puVar4 == (undefined4 *)0x0) {
        return 0;
      }
      if (((*DAT_0037cb64 & 1) == 0) && (iVar7 = func_00100174((int *)DAT_0037cb64), iVar7 != 0)) {
        *DAT_0037cb68 = uVar5;
      }
      iVar7 = (**(code **)*puVar4)(puVar4,DAT_0037cb68);
      if (iVar7 == 0) {
        puVar4 = (undefined4 *)0x0;
      }
      if (puVar4 == (undefined4 *)0x0) {
        return 1;
      }
      iVar7 = func_00315930((int)puVar4);
      goto joined_r0x0037c910;
    }
  }
  if (iVar7 == 5 || iVar7 == 0x11) {
    bVar2 = func_00521098(param_1,(int *)(param_2 + 0x28));
    if (bVar2) {
      if (*(char *)((int)param_1 + 0x2d7) != '\0') {
        return 0;
      }
      iVar3 = (**(code **)(*param_1 + 0x4c))(param_1,iVar7);
    }
    else {
      puVar4 = (undefined4 *)func_0052FBA0(*piVar1 + 0x3dbbc,uVar6);
      if (puVar4 == (undefined4 *)0x0) {
        return 0;
      }
      if (((*DAT_0037cb6c & 1) == 0) && (iVar3 = func_00100174((int *)DAT_0037cb6c), iVar3 != 0)) {
        *DAT_0037cb70 = DAT_0037cb74;
      }
      iVar3 = (**(code **)*puVar4)(puVar4,DAT_0037cb70);
      if (iVar3 == 0) {
        puVar4 = (undefined4 *)0x0;
      }
      if (puVar4 == (undefined4 *)0x0) goto LAB_0037caa0;
      iVar3 = (**(code **)(*param_1 + 0x50))(param_1,puVar4);   /* r1 = the item actor (movs r1, r5) */
    }
    if (iVar3 != 0) {
      return 1;
    }
  }
LAB_0037caa0:
  if ((iVar7 != 0xe) || (iVar7 = param_1[0x120], iVar7 == 0)) {
    return 0;
  }
  if (*(char *)((int)param_1 + 0x42a) == '\0') {
    *(undefined1 *)((int)param_1 + 0x42b) = 1;
  }
  else {
    if (iVar7 == 8) {
      uVar5 = 0x17;
    }
    else if (iVar7 == 9) {
      uVar5 = 0x18;
    }
    else {
      if (iVar7 != 10) {
        return 1;
      }
      uVar5 = 0x19;
    }
    iVar7 = func_004C6940(*DAT_0037cb78,*(int *)(param_2 + 0x28),uVar5);
    if (iVar7 == 0) {
      return 1;
    }
    *(undefined1 *)((int)param_1 + 0x2d7) = 1;
  }
  bVar2 = func_00521098(param_1,(int *)(param_2 + 0x28));
  local_38 = DAT_0037cb80;
  local_34 = s_SE_PL_Net_GET_0037cb84;
  if (bVar2) {
    func_004EA104(*DAT_0037cb7c,&local_38,0);
  }
  else {
    func_004EABB8(*DAT_0037cb7c,&local_38,(undefined4 *)0x0);
  }
  return 1;
}

