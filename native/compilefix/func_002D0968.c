/* compilefix: func_002D0968, the converted stage-2 text (build/decomp/ghidra_fallback/ghidra_analyzed5_v4/002/func_002D0968.c) with raw code-address string pointers
 * replaced by the strings themselves (tools/raw_cstr_fix.py, BOOT_LOG 143): 0x2d0b1c "Fall" */
#include "ghidra_types.h"

extern int func_00110848(int param_1);
extern int func_00115C54(float *param_1,float *param_2,float *param_3);
extern int func_0014EEB8(int param_1,undefined4 *param_2,undefined4 param_3,float fparam_0);
extern undefined4 func_00151148(int param_1,int param_2);
extern int func_002D068C(int *param_1,undefined4 param_2,undefined4 param_3,int param_4);
extern int func_004A1B9C(int *param_1,int param_2,uint *param_3);
extern int func_004CEAF0(int param_1);
extern int func_004CF478(int param_1,int param_2);
extern float func_004D8AEC(float *param_1,uint param_2,float *param_3);
extern int func_0052107C(int param_1);
extern float fRam002d0b14;
extern int iRam002d0b08;
extern int iRam002d0b18;
extern undefined4 *puRam002d0b10;
extern int DAT_002d0b0c;
extern undefined4 DAT_002d0b24;
extern undefined4 *DAT_002d0b28;

// USA 002D0968 <- EU 002D0944 (Ghidra, non-matching)
// GLOBAL DAT_002d0b0c int
// GLOBAL DAT_002d0b24 undefined4
// GLOBAL DAT_002d0b28 undefined4 *
// GLOBAL UNK_002d0b08 int
// GLOBAL UNK_002d0b10 uint *
// GLOBAL UNK_002d0b14 float
// GLOBAL UNK_002d0b18 int

undefined4 func_002D0968(int *param_1)

{
  bool bVar1;
  float *pfVar2;
  int iVar3;
  undefined4 extraout_r1;
  undefined4 uVar4;
  int in_r3;
  uint in_fpscr;
  float fVar5;
  _Alignas(8) unsigned char albw_frame[0x20];
  #define fStack_20 (*(float *)(albw_frame + 0x0))
  #define fStack_1c (*(float *)(albw_frame + 0x4))
  #define fStack_18 (*(float *)(albw_frame + 0x8))
  if (param_1[0x133] != 0) {
    iVar3 = param_1[0x133] + -1;
    param_1[0x133] = iVar3;
    if (iVar3 != 0) {
      return 0;
    }
    func_00151148(param_1[0x113],1);
    param_1[0xf8] = iRam002d0b08;
  }
  if ((*(char *)(param_1[0x111] + 0x30) == '\0') &&
     ((int)ALBW_AS_U32((ALBW_AS_F32(param_1[0xf5]) - ALBW_AS_F32(param_1[3]))) < DAT_002d0b0c)) {
    func_004CF478(param_1[0x111],1);
    fStack_20 = ALBW_AS_F32(param_1[0xf4]);
    fStack_1c = ALBW_AS_F32(param_1[0xf5]);
    pfVar2 = (float *)(iRam002d0b18 + (*puRam002d0b10 >> 0x18) * 0x10);
    fVar5 = (float)VectorUnsignedToFloat(*puRam002d0b10 & 0xffffff,(byte)(in_fpscr >> 0x15) & 3);
    fStack_18 = ALBW_AS_F32(param_1[0xf6]) -
                (fStack_1c - ALBW_AS_F32(param_1[3])) * (*pfVar2 + pfVar2[1] * fVar5 * fRam002d0b14);
    iVar3 = param_1[0x111];
    *(uint *)(iVar3 + 0x164) = *(uint *)(iVar3 + 0x164) | 0x40000000;
    func_004D8AEC((float *)(iVar3 + 0x80),param_1[0xfa],&fStack_20);
    func_004CEAF0(param_1[0x111]);
    *(undefined1 *)((int)param_1 + 0x4b1) = 1;
    pfVar2 = (float *)(param_1 + 0x131);
    if (param_1[0xd1] == 0) {
      *pfVar2 = 0.0;
      param_1[0x132] = 0;
    }
    else {
      fVar5 = *pfVar2;
      if ((fVar5 != 0.0) && (*(int *)((int)ALBW_AS_U32(fVar5) + 0x1c) == param_1[0x132])) {
        func_00110848((int)ALBW_AS_U32(fVar5));
      }
      func_004A1B9C((int *)&fStack_20,param_1[0xd1],(uint *)"Fall");
      *pfVar2 = fStack_20;
      param_1[0x132] = (int)ALBW_AS_U32(fStack_1c);
    }
  }
  func_00115C54((float *)(param_1 + 0xf4),(float *)(param_1 + 0xf4),(float *)(param_1 + 0xf7));
  uVar4 = DAT_002d0b24;
  func_0014EEB8((int)param_1,DAT_002d0b28,DAT_002d0b24,*(float *)(param_1[0x112] + 0x58));
  bVar1 = func_0052107C((int)param_1);
  if ((!bVar1) && ((param_1[0xe7] & 0x10U) == 0)) {
    return 0;
  }
  return func_002D068C(param_1,extraout_r1,uVar4,in_r3);
}

