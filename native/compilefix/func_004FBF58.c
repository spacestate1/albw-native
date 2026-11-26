/* compilefix: USA 004FBF58, the converted stage-2 text passing 004FA174 its r3 argument (BOOT_LOG 173). */
#include "ghidra_types.h"

extern float func_004FA174(float *param_1,int param_2,int param_3,uint in_r3,float *param_4,int param_5,int param_6);
extern float func_004FAD90(int param_1);
extern int func_004FC244(int *param_1,int *param_2,int param_3,undefined4 param_4,int param_5);

// USA 004FBF58 <- EU 004FBF30 (Ghidra, non-matching)

float func_004FBF58(int *param_1)

{
  int iVar1;
  float fVar2;
  
  func_004FC244(param_1,(int *)param_1[0x10f],0xc,1,1);
  func_004FAD90((int)param_1);
  iVar1 = param_1[0x10f];
  fVar2 = func_004FA174((float *)(param_1 + 0xf4),iVar1,0x10,*(byte *)(iVar1 + 0x20),(float *)(iVar1 + 0x14),
                        (int)*(char *)(iVar1 + 0x21),*(uint *)(iVar1 + 0x38) >> 0x1c);
  return fVar2;
}

