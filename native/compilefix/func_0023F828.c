/* compilefix: USA 0023F828 (EU 0023F828), Ghidra-derived (decomp snapshot, ghidra_analyzed5_v4).
 * Stack overflow: func_004D7E0C writes a 3x3 rotation (9 floats, param_1[0..8]) into afStackY_34,
 * which Ghidra sized as 7 floats. The two words past it are other locals or saved registers (caught
 * as "stack smashing detected" in the armhf build, scripted new game at frame ~4210).
 * Fixed: afStackY_34 [9]. The rest is the converted Ghidra text.
 * Fixed: the vector the matrix rotates was three separate C locals, so its y and z were whatever lay
 * beside x (found by AddressSanitizer; EU: vstmia sp, {s0, s1} + vstr s0, [sp, #8]; BOOT_LOG 183).
 * Confidence: high (func_004D7E0C's body writes param_1[0] to param_1[8]). */
#include "ghidra_types.h"

extern int func_00115C54(float *param_1,float *param_2,float *param_3);
extern int func_00115CE4(float *param_1,float *param_2,float *param_3);
extern int func_0014E2A0(int param_1,undefined4 param_2,undefined4 param_3,uint param_4,undefined4 param_5 ,int param_6);
extern int func_00168E9C(int *param_1,int param_2,int *param_3);
extern int func_00169A80(int *param_1,undefined4 param_2,undefined4 param_3,int *param_4);
extern int func_00352210(int param_1,uint param_2,float fparam_0);
extern int func_004356B4(int *param_1);
extern int func_004CEAF0(int param_1);
extern int func_004CF478(int param_1,int param_2);
extern void func_004D7E0C(float *param_1,uint param_2,uint param_3);
extern int func_004D7EB0(float *param_1,uint param_2,uint param_3,float *param_4);
extern float fRam0023f9d8;
extern float fRam0023f9dc;

// USA 0023F828 <- EU 0023F828 (Ghidra, non-matching)
// GLOBAL UNK_0023f9d8 float
// GLOBAL UNK_0023f9dc float

undefined4 func_0023F828(int param_1)

{
  uint uVar1;
  int iVar2;
  code *pcVar3;
  undefined4 extraout_r1;
  float *pfVar4;
  uint in_fpscr;
  float fparam_0;
  float offset[3];   /* one vector: three consecutive stack words in the ARM code */
  float afStackY_34 [9];   /* a 3x3 matrix (func_004D7E0C) */
  
  uVar1 = *(uint *)(*(int *)(param_1 + 0x428) + *(char *)(param_1 + 0x410) * 8 + 4);
  pcVar3 = *(code **)(*(int *)(param_1 + 0x428) + *(char *)(param_1 + 0x410) * 8);
  if ((uVar1 & 1) != 0) {
    pcVar3 = *(code **)(pcVar3 + *(int *)(*(int *)(param_1 + 0x420) + ((int)uVar1 >> 1)));
  }
  (*pcVar3)((int)(*(int *)(param_1 + 0x420)) + ((int)uVar1 >> 1));
  iVar2 = *(int *)(param_1 + 0x40c) + 1;
  *(int *)(param_1 + 0x40c) = iVar2;
  if (*(int *)(param_1 + 0x41c) != 0) {
    fparam_0 = (float)VectorUnsignedToFloat(iVar2,(byte)(in_fpscr >> 0x15) & 3);
    func_00352210(*(int *)(param_1 + 0x41c),1,fparam_0);
  }
  func_0014E2A0(param_1,*(undefined4 *)(param_1 + 0x434),param_1 + 0x43c,0x4000,0,0);
  iVar2 = *(int *)(param_1 + 0x430);
  pfVar4 = (float *)(param_1 + 0x3d0);
  *(uint *)(iVar2 + 0x164) = *(uint *)(iVar2 + 0x164) | 0x40000000;
  uVar1 = *(uint *)(param_1 + 1000);
  func_004D7EB0((float *)(iVar2 + 0x80),*(uint *)(param_1 + 0x20),uVar1,pfVar4);
  func_00169A80(*(int **)(param_1 + 0x438),extraout_r1,uVar1,(int *)pfVar4);
  func_00168E9C(*(int **)(param_1 + 0x438),*(int *)(param_1 + 0x430),(int *)0x0);
  func_004CEAF0(*(int *)(param_1 + 0x430));
  if (*(char *)(param_1 + 0x410) != '\0') {
    return func_004CF478(*(int *)(param_1 + 0x430),0);
  }
  func_004CF478(*(int *)(param_1 + 0x430),1);
  offset[1] = *(float *)(*(int *)(param_1 + 0x434) + 0x58) * fRam0023f9d8;
  offset[0] = fRam0023f9dc;
  offset[2] = fRam0023f9dc;
  func_004D7E0C(afStackY_34,*(uint *)(param_1 + 0x20),*(uint *)(param_1 + 1000));
  func_00115CE4(offset,afStackY_34,offset);
  func_00115C54(offset,offset,(float *)(param_1 + 0x3d0));
  iVar2 = *(int *)(param_1 + 0x434);
  *(float *)(iVar2 + 4) = offset[0];
  *(float *)(iVar2 + 8) = offset[1];
  *(float *)(iVar2 + 0xc) = offset[2];
  return func_004356B4(*(int **)(param_1 + 0x434));
}

