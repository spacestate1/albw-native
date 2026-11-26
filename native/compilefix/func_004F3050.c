/* compilefix: func_004F3050, the converted stage-2 text (build/decomp/ghidra_fallback/ghidra_analyzed5_v4/004/func_004F3050.c) with raw code-address string pointers
 * replaced by the strings themselves (tools/raw_cstr_fix.py, BOOT_LOG 143): 0x4f3110 "Fire" */
#include "ghidra_types.h"

extern int func_00110848(int param_1);
extern int func_00150A84(int *param_1,int *param_2,int param_3);
extern int func_004A1B9C(int *param_1,int param_2,uint *param_3);
extern int func_004FABDC(int param_1,undefined4 param_2,uint param_3,int param_4);
extern int func_00588BE4(int param_1);
extern int iRam004f312c;
extern int *piRam004f310c;
extern undefined4 DAT_004f3108;
extern char s_SE_Amos_MOVE_START_004f3118[];

// USA 004F3050 <- EU 004F3028 (Ghidra, non-matching)
// GLOBAL DAT_004f3108 undefined4
// GLOBAL UNK_004f310c int *
// GLOBAL UNK_004f312c int
// GLOBAL s_SE_Amos_MOVE_START_004f3118 string

undefined4 func_004F3050(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  _Alignas(8) unsigned char albw_frame[0x20];
  #define iStack_20 (*(int *)(albw_frame + 0x0))
  #define pcStack_1c (*(char * *)(albw_frame + 0x4))
  #define iStack_18 (*(int *)(albw_frame + 0x8))
  #define uStack_14 (*(undefined4 *)(albw_frame + 0xc))
  uVar1 = DAT_004f3108;
  *(undefined4 *)(param_1 + 0x3dc) = DAT_004f3108;
  *(undefined4 *)(param_1 + 0x3e0) = uVar1;
  *(undefined4 *)(param_1 + 0x3e4) = uVar1;
  *(undefined4 *)(param_1 + 0x914) = uVar1;
  func_004FABDC(param_1,0,0xffffffff,0);
  *(uint *)(param_1 + 0x59c) = *(uint *)(param_1 + 0x59c) | 0x300;
  iVar2 = func_00588BE4(param_1);
  if (iVar2 == *piRam004f310c) {
    piVar3 = (int *)(param_1 + 0x8fc);
    if (*(int *)(param_1 + 0x344) == 0) {
      *piVar3 = 0;
      *(undefined4 *)(param_1 + 0x900) = 0;
    }
    else {
      iVar2 = *piVar3;
      if ((iVar2 != 0) && (*(int *)(iVar2 + 0x1c) == *(int *)(param_1 + 0x900))) {
        func_00110848(iVar2);
      }
      func_004A1B9C(&iStack_18,*(int *)(param_1 + 0x344),(uint *)"Fire");
      *piVar3 = iStack_18;
      *(undefined4 *)(param_1 + 0x900) = uStack_14;
    }
  }
  pcStack_1c = s_SE_Amos_MOVE_START_004f3118;
  iStack_20 = iRam004f312c;
  return func_00150A84((int *)param_1,&iStack_20,0);
}

