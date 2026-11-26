/* compilefix: USA 003D6464 with the arguments its indirect tail call passes through restored
 * (tools/tail_args_fix.py, BOOT_LOG 172). */
/* compilefix: func_003D6464, the converted stage-2 text (build/decomp/ghidra_fallback/ghidra_analyzed5_v4/003/func_003D6464.c) with `this` restored in 1
 * member-function-pointer call(s) by tools/pmf_this_fix.py (BOOT_LOG 140): this = BASE + (adj >> 1).
 * Further arguments of those calls are as Ghidra printed them. */
#include "ghidra_types.h"

extern int func_003D6778(int param_1,int *param_2);
extern int DAT_003d64ac;

// USA 003D6464 <- EU 003D6444 (Ghidra, non-matching)
// GLOBAL DAT_003d64ac int

undefined4 func_003D6464(int param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar2 = *(int *)(param_1 + 0x10) + 1;
  *(int *)(param_1 + 0x10) = iVar2;
  if (iVar2 == *(int *)(param_1 + 0x14)) {
    return 4;
  }
  uVar3 = (uint)*(ushort *)(*(int *)(param_1 + 0xc) + iVar2 * 2);
  if (0x5e < uVar3 - 0x20) {
    uVar1 = func_003D6778(param_1,param_2);
    return uVar1;
  }
  iVar2 = DAT_003d64ac + uVar3 * 8;
  uVar3 = *(uint *)(iVar2 + -0xfc);
  UNRECOVERED_JUMPTABLE = *(code **)(iVar2 + -0x100);
  if ((uVar3 & 1) != 0) {
    UNRECOVERED_JUMPTABLE =
         *(code **)(UNRECOVERED_JUMPTABLE + *(int *)(param_1 + ((int)uVar3 >> 1)));
  }
                    /* WARNING: Could not recover jumptable at 0x003d649c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(int (*)())UNRECOVERED_JUMPTABLE)(((int *)((int)(param_1) + ((int)uVar3 >> 1))),param_2);   /* this restored (pmf_this_fix) */
  return uVar1;
}

