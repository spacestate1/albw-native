/* compilefix: USA 004CDBEC (EU 004CDBC4), the Ghidra text with the virtual call at slot +0x2C given
 * its second argument. The ARM (EU 4CDCD8 mov r1, r0 ... 4CDD38 blx r3) calls it with r0 = the object
 * at +0x44 and r1 = the actor 0052FBA0 returned (uVar4); Ghidra dropped r1, so the callee
 * (00532984: compares a1 +0x2CC with its own targets) read a stale register: SIGSEGV at 0x2CD
 * (a1 = 1), House of Gales (user crash report). Confidence: high (checked against the ARM). */
#include "ghidra_types.h"

extern int func_002E3608(int param_1,undefined1 param_2,uint param_3);
extern int func_004CD960(int param_1);
extern int func_0052FBA0(int param_1,uint param_2);
extern int func_005568E8(int param_1);
extern int *DAT_004cddb4;
extern int *DAT_004cddb8;
extern int *DAT_004cddbc;
extern int *DAT_004cddc0;

// USA 004CDBEC <- EU 004CDBC4 (Ghidra, non-matching)
// GLOBAL DAT_004cddb4 int *
// GLOBAL DAT_004cddb8 int *
// GLOBAL DAT_004cddbc int *
// GLOBAL DAT_004cddc0 int *

void func_004CDBEC(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  undefined4 uVar7;
  bool bVar8;
  
  if (*(int **)(param_1 + 0x44) != (int *)0x0) {
    *(undefined1 *)(param_1 + 0x10) = 1;
    iVar2 = (**(code **)(**(int **)(param_1 + 0x44) + 0x1c))(*(int **)(param_1 + 0x44));
    *(undefined1 *)(param_1 + 0x10) = 0;
    if (iVar2 == 1) {
      (**(code **)(**(int **)(param_1 + 0x44) + 0x20))(*(int **)(param_1 + 0x44));
      *(undefined4 *)(param_1 + 0x44) = 0;
    }
  }
  *(undefined1 *)(param_1 + 0x10) = 1;
  uVar7 = *(undefined4 *)(param_1 + 0x44);
  iVar2 = *(int *)(param_1 + 0x3c);
  while (iVar6 = *(int *)(iVar2 + 4), iVar2 != param_1 + 0x38) {
    puVar3 = *(undefined4 **)(*(int *)(iVar2 + 8) + 0x20);
    iVar2 = iVar6;
    if (puVar3 != (undefined4 *)0x0) {
      (**(code **)*puVar3)(puVar3,uVar7);
    }
  }
  *(undefined1 *)(param_1 + 0x10) = 0;
  func_004CD960(param_1);
  bVar8 = *(int *)(param_1 + 0x44) == 0;
  iVar2 = *DAT_004cddb4;
  func_002E3608(iVar2,bVar8,0);
  func_002E3608(iVar2,bVar8,2);
  piVar1 = DAT_004cddb8;
  if (!bVar8) {
    uVar4 = func_005568E8(*DAT_004cddb8);
    uVar4 = func_0052FBA0(*DAT_004cddbc + 0x3dbbc,uVar4);
    if ((((uVar4 == 0) ||
         (piVar5 = *(int **)(param_1 + 0x44), (-(uint)(piVar5 != (int *)0x0) & uVar4) == 0)) ||
        (*(char *)(uVar4 + 0x2d7) != '\0')) ||
       ((((*(uint *)(uVar4 + 0x2e0) & 2) == 0 &&
         ((*piVar1 == 0 || (**(int **)(*piVar1 + 0x2c) != *(int *)(uVar4 + 0x2cc))))) &&
        (iVar6 = (**(code **)(*piVar5 + 0x2c))(piVar5,uVar4), iVar6 == 0)))) {
      func_002E3608(iVar2,0,9);
      func_002E3608(iVar2,0,10);
      goto LAB_004cdd90;
    }
  }
  func_002E3608(iVar2,1,9);
  func_002E3608(iVar2,1,10);
LAB_004cdd90:
  if (*(int *)(param_1 + 0x44) != 0) {
    *(undefined1 *)(*DAT_004cddc0 + 0x2c1b) = 0;
  }
  return;
}

