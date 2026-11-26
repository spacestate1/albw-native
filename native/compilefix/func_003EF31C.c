/* compilefix: USA 003EF31C (EU 003EF2FC), the converted stage-2 text.
 * Fixed (BOOT_LOG 184): the ARM copies this word between a float and an integer (no vcvt), which the
 * converted text wrote as a conversion of the value. */
#include "ghidra_types.h"

extern longlong func_001104E4(int param_1,int param_2);
extern ulonglong func_00110710(uint param_1,uint param_2);
extern int func_003EB564(undefined4 param_1,int param_2,uint *param_3);
extern int func_003EBB60(int param_1,int param_2,float *param_3);
extern int func_003EBD0C(undefined4 param_1,int param_2,float *param_3);
extern int func_003EBDB4(int param_1,uint *param_2,uint *param_3);
extern int func_003EC100(int param_1,undefined4 *param_2,short *param_3);
extern int func_003ECC68(int param_1,int param_2,int *param_3);
extern int *DAT_003ef8f0;
extern uint DAT_003ef8f4;
extern uint DAT_003ef8f8;
extern float *DAT_003ef8fc;
extern int DAT_003ef900;

// USA 003EF31C <- EU 003EF2FC (Ghidra, non-matching)
// GLOBAL DAT_003ef8f0 int *
// GLOBAL DAT_003ef8f4 uint
// GLOBAL DAT_003ef8f8 uint
// GLOBAL DAT_003ef8fc float *
// GLOBAL DAT_003ef900 int

void func_003EF31C(uint *param_1)

{
  int *piVar1;
  uint uVar2;
  float *pfVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  float *pfVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint in_fpscr;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  longlong lVar22;
  undefined8 uVar23;
  
  uVar5 = DAT_003ef8f8;
  piVar1 = DAT_003ef8f0;
  iVar4 = DAT_003ef8f0[1];
  puVar6 = (uint *)*DAT_003ef8f0;
  uVar8 = param_1[0x51];
  puVar6[1] = DAT_003ef8f4;
  *puVar6 = iVar4 * 10 + 1U | 0x80000000;
  iVar4 = piVar1[3];
  pfVar7 = (float *)param_1[0x4d];
  uVar9 = param_1[0x4e];
  fVar11 = ALBW_AS_F32(param_1[8]);
  fVar12 = ALBW_AS_F32(param_1[9]);
  fVar13 = ALBW_AS_F32(param_1[10]);
  uVar2 = *(uint *)(uVar8 + 0x238);
  param_1[2] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_1[2]) + fVar11));
  param_1[3] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_1[3]) + fVar12));
  param_1[4] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_1[4]) + fVar13));
  puVar6[3] = iVar4 * 0x400000 - 0x100000U | uVar5;
  if ((uVar2 & 1) != 0) {
    fVar14 = *(float *)(uVar9 + 0x708);
    param_1[8] = (uint)ALBW_AS_U32((fVar11 * fVar14));
    param_1[9] = (uint)ALBW_AS_U32((fVar12 * fVar14));
    param_1[10] = (uint)ALBW_AS_U32((fVar13 * fVar14));
  }
  if ((uVar2 & 2) != 0) {
    if (*(char *)(param_1[0x4e] + 0x17b) == '\0') {
      fVar11 = *(float *)(uVar9 + 0x6b0);
      fVar12 = *(float *)(uVar9 + 0x6b4);
      param_1[8] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_1[8]) + *(float *)(uVar9 + 0x6ac)));
      param_1[9] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_1[9]) + fVar11));
      param_1[10] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_1[10]) + fVar12));
    }
    else {
      pfVar3 = (float *)param_1[0x4c];
      fVar11 = *(float *)(uVar9 + 0x6b0);
      fVar13 = *(float *)(uVar9 + 0x6b4);
      fVar19 = *(float *)(uVar9 + 0x6ac);
      fVar21 = pfVar3[5];
      fVar20 = pfVar3[6];
      fVar18 = pfVar3[9];
      fVar12 = pfVar3[10];
      fVar14 = pfVar3[1];
      fVar16 = pfVar3[2];
      param_1[8] = (uint)ALBW_AS_U32((fVar11 * pfVar3[4] + fVar13 * pfVar3[8] +
                         ALBW_AS_F32(param_1[8]) + fVar19 * *pfVar3));
      param_1[9] = (uint)ALBW_AS_U32((fVar11 * fVar21 + fVar13 * fVar18 + ALBW_AS_F32(param_1[9]) + fVar19 * fVar14));
      param_1[10] = (uint)ALBW_AS_U32((fVar11 * fVar20 + fVar13 * fVar12 + ALBW_AS_F32(param_1[10]) + fVar19 * fVar16))
      ;
    }
  }
  if ((int)*param_1 < *(int *)(uVar9 + 0x6bc)) {
    param_1[0x17] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_1[0x17]) + *(float *)param_1[0x18]));
  }
  else if (*(int *)(uVar9 + 0x6b8) <= (int)*param_1) {
    param_1[0x17] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_1[0x17]) + *(float *)(param_1[0x18] + 4)));
  }
  puVar6[2] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_1[0x17]) * ALBW_AS_F32(param_1[0x2a])));
  uVar5 = param_1[0x1c];
  uVar2 = *(uint *)(uVar8 + 0x238);
  puVar6[7] = param_1[0x23];
  puVar6[8] = uVar5;
  if (((uVar2 & 0x40) != 0) && (*(int *)(uVar9 + 0x6c0) <= (int)*param_1)) {
    fVar11 = ((float *)param_1[0x1b])[1];
    param_1[0x19] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_1[0x19]) + *(float *)param_1[0x1b]));
    param_1[0x1a] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_1[0x1a]) + fVar11));
  }
  fVar11 = ALBW_AS_F32(param_1[0x19]);
  uVar5 = *(uint *)(uVar8 + 0x238);
  fVar12 = *DAT_003ef8fc;
  puVar6[9] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_1[0x1a]) * DAT_003ef8fc[1]));
  puVar6[10] = (uint)ALBW_AS_U32((fVar11 * fVar12));
  if ((uVar5 & 4) != 0) {
    param_1[0x11] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_1[0x11]) + ALBW_AS_F32(param_1[0x14])));
    param_1[0x12] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_1[0x12]) + ALBW_AS_F32(param_1[0x15])));
    param_1[0x13] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_1[0x13]) + ALBW_AS_F32(param_1[0x16])));
  }
  if ((uVar5 & 8) != 0) {
    fVar11 = *(float *)(uVar9 + 0x69c);
    param_1[0x16] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_1[0x16]) * fVar11));
    param_1[0x15] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_1[0x15]) * fVar11));
    param_1[0x14] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_1[0x14]) * fVar11));
  }
  piVar1 = DAT_003ef8f0;
  uVar2 = param_1[0x12];
  uVar10 = param_1[0x13];
  uVar5 = *(uint *)(uVar8 + 0x238);
  puVar6[0x1e] = param_1[0x11];
  puVar6[0x1d] = uVar2;
  puVar6[0x1c] = uVar10;
  iVar4 = piVar1[4];
  puVar6[4] = param_1[iVar4 * 4 + 0x2e];
  puVar6[5] = param_1[iVar4 * 4 + 0x2d];
  puVar6[6] = param_1[iVar4 * 4 + 0x2c];
  if ((uVar5 & 0x2000) != 0) {
    uVar5 = *param_1;
    uVar10 = (uint)*(short *)(uVar9 + 0x6f8);
    uVar2 = uVar10;
    if (uVar10 == 0) {
      uVar5 = uVar5 * (int)*(short *)(uVar9 + 0x6fa);
      uVar2 = param_1[1];
    }
    lVar22 = func_001104E4(uVar5,uVar2);
    uVar5 = (uint)lVar22;
    if ((*(char *)(uVar9 + 0x6fc) == '\0') || (uVar5 < (uint)(int)*(short *)(uVar9 + 0x6fa))) {
      if ((uVar10 != 0) &&
         ((*(char *)(uVar9 + 0x6fc) == '\0' && ((*(uint *)(uVar9 + 0x548) & 0x4000) != 0)))) {
        uVar5 = uVar5 + param_1[0x54];
      }
      uVar23 = func_00110710(uVar5,(int)*(short *)(uVar9 + 0x6fa));
      uVar23 = func_00110710((uint)*(byte *)((int)((ulonglong)uVar23 >> 0x20) + uVar9 + 0x6d8),
                             (uint)*(byte *)(uVar9 + 0x6ce));
      fVar13 = *(float *)(uVar9 + 0x6d4);
      fVar12 = (float)VectorSignedToFloat((int)uVar23,(byte)(in_fpscr >> 0x15) & 3);
      fVar11 = (float)VectorSignedToFloat((int)((ulonglong)uVar23 >> 0x20),
                                          (byte)(in_fpscr >> 0x15) & 3);
      param_1[0x1d] = (uint)ALBW_AS_U32((*(float *)(uVar9 + 0x6d0) * fVar11));
      param_1[0x1e] = (uint)ALBW_AS_U32((fVar13 * fVar12));
    }
  }
  piVar1 = DAT_003ef8f0;
  uVar5 = param_1[0x22];
  puVar6[0xc] = param_1[0x21];
  puVar6[0xb] = uVar5;
  puVar6[0xd] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_1[0x1e]) - ALBW_AS_F32(param_1[0x20])));
  puVar6[0xe] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_1[0x1d]) + ALBW_AS_F32(param_1[0x1f])));
  if ((*(uint *)(uVar9 + 0x548) & 0x800) != 0) {
    pfVar3 = (float *)(*(ushort *)(uVar9 + 0x556) + uVar9);
    if ((*(ushort *)(uVar9 + 0x54c) & 1) != 0) {
      pfVar3 = (float *)func_003EBDB4(uVar8,param_1,(uint *)pfVar3);
    }
    if ((*(ushort *)(uVar9 + 0x54c) & 2) != 0) {
      pfVar3 = func_003EBB60(uVar8,(int)param_1,pfVar3);
    }
    if ((*(ushort *)(uVar9 + 0x54c) & 4) != 0) {
      pfVar3 = (float *)func_003EB564(uVar8,(int)param_1,(uint *)pfVar3);
    }
    if ((*(ushort *)(uVar9 + 0x54c) & 8) != 0) {
      pfVar3 = (float *)func_003EC100(uVar8,param_1,(short *)pfVar3);
    }
    if ((*(ushort *)(uVar9 + 0x54c) & 0x10) != 0) {
      pfVar3 = (float *)func_003ECC68(uVar8,(int)param_1,(int *)pfVar3);
    }
    if ((*(ushort *)(uVar9 + 0x54c) & 0x20) != 0) {
      func_003EBD0C(uVar8,(int)param_1,pfVar3);
    }
  }
  fVar18 = ALBW_AS_F32(param_1[0x41]);
  fVar12 = ALBW_AS_F32(param_1[3]);
  fVar16 = ALBW_AS_F32(param_1[0x45]);
  fVar11 = ALBW_AS_F32(param_1[4]);
  fVar13 = ALBW_AS_F32(param_1[2]);
  fVar20 = ALBW_AS_F32(param_1[0x42]);
  fVar19 = ALBW_AS_F32(param_1[0x43]);
  fVar15 = ALBW_AS_F32(param_1[0x40]);
  fVar21 = ALBW_AS_F32(param_1[0x46]);
  fVar14 = ALBW_AS_F32(param_1[0x47]);
  fVar17 = ALBW_AS_F32(param_1[0x44]);
  uVar5 = *(uint *)(uVar8 + 0x238);
  iVar4 = *piVar1;
  *(float *)(iVar4 + 0x50) =
       ALBW_AS_F32(param_1[0x49]) * fVar12 + ALBW_AS_F32(param_1[0x4a]) * fVar11 +
       ALBW_AS_F32(param_1[0x4b]) + ALBW_AS_F32(param_1[0x48]) * fVar13;
  *(float *)(iVar4 + 0x54) = fVar16 * fVar12 + fVar21 * fVar11 + fVar14 + fVar17 * fVar13;
  *(float *)(iVar4 + 0x58) = fVar18 * fVar12 + fVar20 * fVar11 + fVar19 + fVar15 * fVar13;
  *(undefined4 *)(iVar4 + 0x5c) = 0;
  if ((uVar5 & 0x10) != 0) {
    if (((DAT_003ef900 < (int)ALBW_AS_U32(ABS(ALBW_AS_F32(param_1[8])))) ||
        (DAT_003ef900 < (int)ALBW_AS_U32(ABS(ALBW_AS_F32(param_1[9]))))) ||
       (DAT_003ef900 < (int)ALBW_AS_U32(ABS(ALBW_AS_F32(param_1[10]))))) {
      param_1[5] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_1[8]) - ALBW_AS_F32(param_1[5])) + ALBW_AS_F32(param_1[5]));
      param_1[6] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_1[9]) - ALBW_AS_F32(param_1[6])) + ALBW_AS_F32(param_1[6]));
      param_1[7] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_1[10]) - ALBW_AS_F32(param_1[7])) + ALBW_AS_F32(param_1[7]));
    }
    fVar12 = ALBW_AS_F32(param_1[5]);
    fVar11 = ALBW_AS_F32(param_1[6]);
    fVar13 = ALBW_AS_F32(param_1[7]);
    fVar16 = *pfVar7 * fVar12 + pfVar7[1] * fVar11 + pfVar7[2] * fVar13;
    fVar14 = pfVar7[4] * fVar12 + pfVar7[5] * fVar11 + pfVar7[6] * fVar13;
    fVar11 = pfVar7[8] * fVar12 + pfVar7[9] * fVar11 + pfVar7[10] * fVar13;
    param_1[0xe] = (uint)ALBW_AS_U32(fVar16);
    param_1[0xf] = (uint)ALBW_AS_U32(fVar14);
    param_1[0x10] = (uint)ALBW_AS_U32(fVar11);
    *(float *)(iVar4 + 0x60) = fVar11;
    *(float *)(iVar4 + 100) = fVar14;
    *(float *)(iVar4 + 0x68) = fVar16;
  }
  *param_1 = *param_1 + 1;
  return;
}

