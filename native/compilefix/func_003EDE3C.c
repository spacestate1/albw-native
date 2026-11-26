/* compilefix: USA 003EDE3C (EU 003EDE1C), the converted stage-2 text.
 * Fixed (BOOT_LOG 184): the ARM copies this word between a float and an integer (no vcvt), which the
 * converted text wrote as a conversion of the value. */
#include "ghidra_types.h"

extern longlong func_001104E4(int param_1,int param_2);
extern ulonglong func_00110710(uint param_1,uint param_2);
extern int func_003EAA08(int param_1,undefined4 *param_2);
extern int func_003EB564(undefined4 param_1,int param_2,uint *param_3);
extern int func_003EBB60(int param_1,int param_2,float *param_3);
extern int func_003EBD0C(undefined4 param_1,int param_2,float *param_3);
extern int func_003EBDB4(int param_1,uint *param_2,uint *param_3);
extern int func_003EC100(int param_1,undefined4 *param_2,short *param_3);
extern int func_003ECC68(int param_1,int param_2,int *param_3);
extern int DAT_003ee318;
extern int DAT_003ee31c;
extern int DAT_003ee320;
extern int DAT_003ee324;

// USA 003EDE3C <- EU 003EDE1C (Ghidra, non-matching)
// GLOBAL DAT_003ee318 int
// GLOBAL DAT_003ee31c int
// GLOBAL DAT_003ee320 int
// GLOBAL DAT_003ee324 int

void func_003EDE3C(int param_1,uint *param_2)

{
  int iVar1;
  float *pfVar2;
  uint uVar3;
  uint uVar4;
  float *pfVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint in_fpscr;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  undefined8 uVar19;
  float fVar20;
  longlong lVar21;
  undefined8 uVar22;
  
  iVar6 = *(int *)(param_1 + 0xd8);
  pfVar5 = (float *)param_2[0x4d];
  uVar19 = *(undefined8 *)(param_2 + 2);
  fVar20 = ALBW_AS_F32(param_2[4]);
  param_2[2] = (uint)ALBW_AS_U32((ALBW_AS_F32(uVar19) + ALBW_AS_F32(param_2[8])));
  param_2[3] = (uint)ALBW_AS_U32((ALBW_AS_F32(((ulonglong)uVar19 >> 0x20)) + ALBW_AS_F32(param_2[9])));
  param_2[4] = (uint)ALBW_AS_U32((fVar20 + ALBW_AS_F32(param_2[10])));
  if (*(char *)(param_1 + 0x2ac) != '\0') {
    pfVar2 = (float *)param_2[0x18];
    if ((int)ALBW_AS_U32(pfVar2[2]) < (int)*param_2) {
      if ((int)ALBW_AS_U32(pfVar2[3]) < (int)*param_2) {
        param_2[0x17] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_2[0x17]) + pfVar2[1]));
      }
    }
    else {
      param_2[0x17] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_2[0x17]) + *pfVar2));
    }
  }
  if (*(char *)(param_1 + 0x2ad) != '\0') {
    pfVar2 = (float *)param_2[0x1b];
    if ((int)ALBW_AS_U32(pfVar2[4]) < (int)*param_2) {
      if ((int)ALBW_AS_U32(pfVar2[5]) < (int)*param_2) {
        fVar9 = pfVar2[3];
        param_2[0x19] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_2[0x19]) + pfVar2[2]));
        param_2[0x1a] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_2[0x1a]) + fVar9));
      }
    }
    else {
      fVar9 = pfVar2[1];
      param_2[0x19] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_2[0x19]) + *pfVar2));
      param_2[0x1a] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_2[0x1a]) + fVar9));
    }
  }
  (**(code **)(DAT_003ee318 + (uint)*(byte *)(param_1 + 0x2a8) * 4))(param_2);
  (**(code **)(DAT_003ee31c + (uint)*(byte *)(param_1 + 0x2a9) * 4))(param_2);
  iVar1 = DAT_003ee320;
  fVar9 = *(float *)(param_2[0x4e] + 0x538);
  param_2[0x14] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_2[0x14]) * fVar9));
  param_2[0x15] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_2[0x15]) * fVar9));
  param_2[0x16] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_2[0x16]) * fVar9));
  (**(code **)(iVar1 + (uint)*(byte *)(param_1 + 0x2aa) * 4))(param_2);
  uVar7 = *(uint *)(param_1 + 0x234);
  if ((uVar7 & 0x400) != 0) {
    fVar14 = *(float *)(iVar6 + 0x378);
    fVar9 = *(float *)(iVar6 + 0x38c);
    fVar11 = *(float *)(iVar6 + 0x3a4);
    fVar12 = *(float *)(iVar6 + 0x390);
    param_2[0x1f] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_2[0x1f]) + *(float *)(iVar6 + 0x374)));
    param_2[0x20] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_2[0x20]) + fVar14));
    param_2[0x1c] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_2[0x1c]) + fVar11));
    param_2[0x21] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_2[0x21]) + fVar9));
    param_2[0x22] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_2[0x22]) + fVar12));
  }
  if ((uVar7 & 0x10000) != 0) {
    if ((uVar7 & 0x4000) != 0) {
      uVar3 = *param_2;
      uVar8 = (uint)*(short *)(iVar6 + 0x3b8);
      uVar4 = uVar8;
      if (uVar8 == 0) {
        uVar3 = uVar3 * (int)*(short *)(iVar6 + 0x3ba);
        uVar4 = param_2[1];
      }
      lVar21 = func_001104E4(uVar3,uVar4);
      uVar3 = (uint)lVar21;
      if ((*(char *)(iVar6 + 0x3b2) == '\0') || (uVar3 < (uint)(int)*(short *)(iVar6 + 0x3ba))) {
        if ((uVar8 != 0) &&
           ((*(char *)(iVar6 + 0x3b2) == '\0' && (*(char *)(iVar6 + 0x3b1) != '\0')))) {
          uVar3 = uVar3 + param_2[0x54];
        }
        uVar22 = func_00110710(uVar3,(int)*(short *)(iVar6 + 0x3ba));
        uVar22 = func_00110710((uint)*(byte *)((int)((ulonglong)uVar22 >> 0x20) + iVar6 + 0x3bc),
                               (uint)*(byte *)(iVar6 + 0x3b3));
        fVar12 = *(float *)(iVar6 + 0x3e4);
        fVar11 = (float)VectorSignedToFloat((int)uVar22,(byte)(in_fpscr >> 0x15) & 3);
        fVar9 = (float)VectorSignedToFloat((int)((ulonglong)uVar22 >> 0x20),
                                           (byte)(in_fpscr >> 0x15) & 3);
        param_2[0x24] = (uint)ALBW_AS_U32((*(float *)(iVar6 + 0x3e0) * fVar9));
        param_2[0x25] = (uint)ALBW_AS_U32((fVar12 * fVar11));
      }
    }
    if ((uVar7 & 0x800) != 0) {
      fVar9 = *(float *)(iVar6 + 0x408);
      fVar11 = *(float *)(iVar6 + 0x41c);
      fVar12 = *(float *)(iVar6 + 0x3ec);
      fVar14 = *(float *)(iVar6 + 0x3f0);
      param_2[0x28] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_2[0x28]) + *(float *)(iVar6 + 0x404)));
      param_2[0x29] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_2[0x29]) + fVar9));
      param_2[0x23] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_2[0x23]) + fVar11));
      param_2[0x26] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_2[0x26]) + fVar12));
      param_2[0x27] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_2[0x27]) + fVar14));
    }
  }
  if ((*(ushort *)(iVar6 + 0x54e) & 1) != 0) {
    func_003EAA08(param_1,param_2);
  }
  if (*(ushort *)(iVar6 + 0x54c) != 0) {
    pfVar2 = (float *)((uint)*(ushort *)(iVar6 + 0x556) + iVar6);
    if ((*(ushort *)(iVar6 + 0x54c) & 1) != 0) {
      pfVar2 = (float *)func_003EBDB4(param_1,param_2,(uint *)pfVar2);
    }
    if ((*(ushort *)(iVar6 + 0x54c) & 2) != 0) {
      pfVar2 = func_003EBB60(param_1,(int)param_2,pfVar2);
    }
    if ((*(ushort *)(iVar6 + 0x54c) & 4) != 0) {
      pfVar2 = (float *)func_003EB564(param_1,(int)param_2,(uint *)pfVar2);
    }
    if ((*(ushort *)(iVar6 + 0x54c) & 8) != 0) {
      pfVar2 = (float *)func_003EC100(param_1,param_2,(short *)pfVar2);
    }
    if ((*(ushort *)(iVar6 + 0x54c) & 0x10) != 0) {
      pfVar2 = (float *)func_003ECC68(param_1,(int)param_2,(int *)pfVar2);
    }
    if ((*(ushort *)(iVar6 + 0x54c) & 0x20) != 0) {
      func_003EBD0C(param_1,(int)param_2,pfVar2);
    }
  }
  fVar9 = ALBW_AS_F32(param_2[2]);
  fVar11 = ALBW_AS_F32(param_2[3]);
  fVar12 = ALBW_AS_F32(param_2[4]);
  fVar14 = fVar9 - ALBW_AS_F32(uVar19);
  fVar10 = fVar11 - ALBW_AS_F32(((ulonglong)uVar19 >> 0x20));
  if (((DAT_003ee324 < (int)ALBW_AS_U32(ABS(fVar14))) || (DAT_003ee324 < (int)ALBW_AS_U32(ABS(fVar10)))) ||
     (DAT_003ee324 < (int)ALBW_AS_U32(ABS(fVar12 - fVar20)))) {
    fVar13 = ALBW_AS_F32(param_2[5]);
    param_2[5] = (uint)ALBW_AS_U32(((fVar14 - fVar13) + fVar13));
    param_2[6] = (uint)ALBW_AS_U32(((fVar10 - ALBW_AS_F32(param_2[6])) + ALBW_AS_F32(param_2[6])));
    param_2[7] = (uint)ALBW_AS_U32(((fVar12 - fVar20) - ALBW_AS_F32(param_2[7])) + ALBW_AS_F32(param_2[7]));
  }
  fVar10 = pfVar5[5];
  fVar18 = pfVar5[9];
  fVar15 = pfVar5[6];
  fVar20 = pfVar5[7];
  fVar17 = pfVar5[4];
  fVar13 = pfVar5[10];
  fVar14 = pfVar5[0xb];
  fVar16 = pfVar5[8];
  uVar7 = *(uint *)(param_1 + 0x234);
  param_2[0xb] = (uint)ALBW_AS_U32((pfVar5[1] * fVar11 + pfVar5[2] * fVar12 + pfVar5[3] + *pfVar5 * fVar9));
  param_2[0xc] = (uint)ALBW_AS_U32((fVar10 * fVar11 + fVar15 * fVar12 + fVar20 + fVar17 * fVar9));
  param_2[0xd] = (uint)ALBW_AS_U32((fVar18 * fVar11 + fVar13 * fVar12 + fVar14 + fVar16 * fVar9));
  if ((uVar7 & 0x10) != 0) {
    fVar20 = ALBW_AS_F32(param_2[5]);
    fVar12 = pfVar5[4];
    fVar16 = pfVar5[8];
    fVar9 = ALBW_AS_F32(param_2[6]);
    fVar15 = pfVar5[5];
    fVar13 = pfVar5[9];
    fVar11 = ALBW_AS_F32(param_2[7]);
    fVar10 = pfVar5[6];
    fVar14 = pfVar5[10];
    param_2[0xe] = (uint)ALBW_AS_U32((*pfVar5 * fVar20 + pfVar5[1] * fVar9 + pfVar5[2] * fVar11));
    param_2[0xf] = (uint)ALBW_AS_U32((fVar12 * fVar20 + fVar15 * fVar9 + fVar10 * fVar11));
    param_2[0x10] = (uint)ALBW_AS_U32((fVar16 * fVar20 + fVar13 * fVar9 + fVar14 * fVar11));
  }
  *param_2 = *param_2 + 1;
  return;
}

