/* compilefix: USA 003F0A54 (EU 003F0A34), the converted stage-2 text.
 * Fixed (BOOT_LOG 184): the ARM copies this word between a float and an integer (no vcvt), which the
 * converted text wrote as a conversion of the value. */
#include "ghidra_types.h"

extern int func_003EAA08(int param_1,undefined4 *param_2);
extern int func_003EB564(undefined4 param_1,int param_2,uint *param_3);
extern int func_003EBB60(int param_1,int param_2,float *param_3);
extern int func_003EBD0C(undefined4 param_1,int param_2,float *param_3);
extern int func_003EBDB4(int param_1,uint *param_2,uint *param_3);
extern int func_003EC100(int param_1,undefined4 *param_2,short *param_3);
extern int func_003ECC68(int param_1,int param_2,int *param_3);
extern int func_003F41F8(float *param_1,float *param_2,uint *param_3,int param_4);
extern int func_003F6B40(uint *param_1,int param_2);
extern int *DAT_003f108c;
extern uint DAT_003f1090;
extern uint DAT_003f1094;
extern float *DAT_003f1098;
extern float DAT_003f109c;
extern int DAT_003f10a0;
extern int DAT_003f10a4;

// USA 003F0A54 <- EU 003F0A34 (Ghidra, non-matching)
// GLOBAL DAT_003f108c int *
// GLOBAL DAT_003f1090 uint
// GLOBAL DAT_003f1094 uint
// GLOBAL DAT_003f1098 float *
// GLOBAL DAT_003f109c float
// GLOBAL DAT_003f10a0 int
// GLOBAL DAT_003f10a4 int

void func_003F0A54(uint *param_1)

{
  char cVar1;
  int *piVar2;
  uint *puVar3;
  uint uVar4;
  float *pfVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  float *pfVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  undefined8 uVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  
  piVar2 = DAT_003f108c;
  puVar3 = (uint *)*DAT_003f108c;
  iVar7 = DAT_003f108c[1];
  uVar12 = param_1[0x51];
  puVar3[1] = DAT_003f1090;
  *puVar3 = iVar7 * 10 + 1U | 0x80000000;
  iVar7 = *(int *)(uVar12 + 200);
  pfVar10 = (float *)param_1[0x4d];
  uVar11 = param_1[0x4e];
  puVar3[3] = DAT_003f1094 | piVar2[3] * 0x400000 - 0x100000U;
  if (iVar7 == 2) {
    uVar4 = *(uint *)(uVar12 + 0x80);
    uVar8 = *(uint *)(uVar12 + 0x60);
    uVar9 = *(uint *)(uVar12 + 0x30);
    uVar13 = *(uint *)(uVar12 + 0x50);
    uVar14 = *(uint *)(uVar12 + 0x40);
    param_1[0x47] = *(uint *)(uVar12 + 0x70);
    param_1[0x4b] = uVar4;
    param_1[0x43] = uVar8;
    param_1[0x37] = uVar9;
    param_1[0x3f] = uVar13;
    param_1[0x3b] = uVar14;
  }
  uVar4 = param_1[0x4e];
  fVar15 = ALBW_AS_F32(param_1[8]);
  fVar17 = ALBW_AS_F32(param_1[9]);
  fVar18 = ALBW_AS_F32(param_1[10]);
  fVar20 = *(float *)(uVar4 + 0x300);
  uVar24 = *(undefined8 *)(param_1 + 2);
  fVar25 = ALBW_AS_F32(param_1[4]);
  cVar1 = *(char *)(uVar4 + 0x17b);
  fVar19 = fVar18 * fVar20;
  fVar16 = fVar15 * fVar20;
  fVar20 = fVar17 * fVar20;
  param_1[8] = (uint)ALBW_AS_U32(fVar16);
  param_1[9] = (uint)ALBW_AS_U32(fVar20);
  param_1[10] = (uint)ALBW_AS_U32(fVar19);
  param_1[2] = (uint)ALBW_AS_U32((ALBW_AS_F32(uVar24) + fVar15));
  param_1[3] = (uint)ALBW_AS_U32((ALBW_AS_F32(((ulonglong)uVar24 >> 0x20)) + fVar17));
  param_1[4] = (uint)ALBW_AS_U32((fVar25 + fVar18));
  if (cVar1 == '\0') {
    fVar15 = *(float *)(uVar4 + 0x308);
    fVar17 = *(float *)(uVar4 + 0x30c);
    param_1[8] = (uint)ALBW_AS_U32((fVar16 + *(float *)(uVar4 + 0x304)));
    param_1[9] = (uint)ALBW_AS_U32((fVar20 + fVar15));
    param_1[10] = (uint)ALBW_AS_U32((fVar19 + fVar17));
  }
  else {
    pfVar5 = (float *)param_1[0x4c];
    fVar15 = *(float *)(uVar4 + 0x308);
    fVar17 = *(float *)(uVar4 + 0x30c);
    fVar21 = *(float *)(uVar4 + 0x304);
    fVar27 = pfVar5[6];
    fVar28 = pfVar5[5];
    fVar18 = pfVar5[10];
    fVar26 = pfVar5[2];
    fVar22 = pfVar5[9];
    fVar23 = pfVar5[1];
    param_1[8] = (uint)ALBW_AS_U32((fVar15 * pfVar5[4] + fVar17 * pfVar5[8] + fVar16 + fVar21 * *pfVar5));
    param_1[9] = (uint)ALBW_AS_U32((fVar15 * fVar28 + fVar17 * fVar22 + fVar20 + fVar21 * fVar23));
    param_1[10] = (uint)ALBW_AS_U32((fVar15 * fVar27 + fVar17 * fVar18 + fVar19 + fVar21 * fVar26));
  }
  if ((*(ushort *)(uVar11 + 0x54e) & 1) != 0) {
    func_003EAA08(uVar12,param_1);
  }
  if (*(char *)(param_1[0x51] + 0x2ac) != '\0') {
    pfVar5 = (float *)param_1[0x18];
    if ((int)ALBW_AS_U32(pfVar5[2]) < (int)*param_1) {
      if ((int)ALBW_AS_U32(pfVar5[3]) < (int)*param_1) {
        param_1[0x17] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_1[0x17]) + pfVar5[1]));
      }
    }
    else {
      param_1[0x17] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_1[0x17]) + *pfVar5));
    }
  }
  iVar7 = *piVar2;
  *(float *)(iVar7 + 8) = ALBW_AS_F32(param_1[0x17]) * ALBW_AS_F32(param_1[0x2a]);
  if (*(char *)(param_1[0x51] + 0x2ad) != '\0') {
    pfVar5 = (float *)param_1[0x1b];
    if ((int)ALBW_AS_U32(pfVar5[4]) < (int)*param_1) {
      if ((int)ALBW_AS_U32(pfVar5[5]) < (int)*param_1) {
        fVar15 = pfVar5[3];
        param_1[0x19] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_1[0x19]) + pfVar5[2]));
        param_1[0x1a] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_1[0x1a]) + fVar15));
      }
    }
    else {
      fVar15 = pfVar5[1];
      param_1[0x19] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_1[0x19]) + *pfVar5));
      param_1[0x1a] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_1[0x1a]) + fVar15));
    }
  }
  iVar6 = DAT_003f10a0;
  fVar17 = ALBW_AS_F32(param_1[0x19]);
  fVar20 = *DAT_003f1098;
  fVar16 = ALBW_AS_F32(param_1[0x2b]);
  fVar15 = ALBW_AS_F32(param_1[0x1a]) * DAT_003f1098[1] * fVar16;
  if (DAT_003f109c < *(float *)(uVar11 + 0x504)) {
    fVar15 = fVar15 + (SQRT(ALBW_AS_F32(param_1[8]) * ALBW_AS_F32(param_1[8]) +
                            ALBW_AS_F32(param_1[9]) * ALBW_AS_F32(param_1[9]) +
                            ALBW_AS_F32(param_1[10]) * ALBW_AS_F32(param_1[10])) +
                      SQRT(ALBW_AS_F32(param_1[5]) * ALBW_AS_F32(param_1[5]) +
                           ALBW_AS_F32(param_1[6]) * ALBW_AS_F32(param_1[6]) +
                           ALBW_AS_F32(param_1[7]) * ALBW_AS_F32(param_1[7]))) * *(float *)(uVar11 + 0x504);
  }
  uVar4 = param_1[0x4e];
  fVar21 = ALBW_AS_F32(param_1[0x16]);
  fVar22 = ALBW_AS_F32(param_1[0x15]);
  fVar18 = ALBW_AS_F32(param_1[0x13]);
  fVar26 = ALBW_AS_F32(param_1[0x11]);
  fVar19 = ALBW_AS_F32(param_1[0x12]);
  uVar8 = *(uint *)(uVar11 + 0x188);
  fVar23 = ALBW_AS_F32(param_1[0x14]);
  *(float *)(iVar7 + 0x24) = fVar15;
  *(float *)(iVar7 + 0x28) = fVar17 * fVar20 * fVar16;
  fVar26 = fVar26 + fVar23;
  fVar15 = *(float *)(uVar4 + 0x538);
  fVar18 = fVar18 + fVar21;
  fVar19 = fVar19 + fVar22;
  param_1[0x13] = (uint)ALBW_AS_U32(fVar18);
  param_1[0x12] = (uint)ALBW_AS_U32(fVar19);
  param_1[0x11] = (uint)ALBW_AS_U32(fVar26);
  *(float *)(iVar7 + 0x78) = fVar26;
  *(float *)(iVar7 + 0x70) = fVar18;
  *(float *)(iVar7 + 0x74) = fVar19;
  iVar7 = piVar2[4];
  param_1[0x16] = (uint)ALBW_AS_U32((fVar21 * fVar15));
  param_1[0x14] = (uint)ALBW_AS_U32((fVar23 * fVar15));
  param_1[0x15] = (uint)ALBW_AS_U32((fVar22 * fVar15));
  if ((*(uint *)(iVar6 + iVar7 * 4) & uVar8) != 0) {
    func_003F6B40(param_1,iVar7);
  }
  iVar6 = piVar2[4];
  iVar7 = *piVar2;
  uVar4 = *(uint *)(uVar11 + 0x188);
  *(uint *)(iVar7 + 0x10) = param_1[iVar6 * 4 + 0x2e];
  *(uint *)(iVar7 + 0x14) = param_1[iVar6 * 4 + 0x2d];
  *(uint *)(iVar7 + 0x18) = param_1[iVar6 * 4 + 0x2c];
  if ((uVar4 & 0x2000) != 0) {
    func_003F41F8((float *)(param_1 + 0x1d),(float *)(param_1 + 0x1e),param_1,param_1[0x4e] + 0x338)
    ;
  }
  if ((*(uint *)(uVar11 + 0x188) & 0x400) != 0) {
    uVar4 = param_1[0x4e];
    fVar16 = *(float *)(uVar4 + 0x378);
    fVar15 = *(float *)(uVar4 + 0x38c);
    fVar17 = *(float *)(uVar4 + 0x390);
    fVar20 = *(float *)(uVar4 + 0x374);
    param_1[0x1c] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_1[0x1c]) + *(float *)(uVar4 + 0x3a4)));
    param_1[0x1f] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_1[0x1f]) + fVar20));
    param_1[0x20] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_1[0x20]) + fVar16));
    param_1[0x21] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_1[0x21]) + fVar15));
    param_1[0x22] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_1[0x22]) + fVar17));
  }
  iVar7 = *piVar2;
  uVar4 = param_1[0x22];
  uVar8 = param_1[0x21];
  *(uint *)(iVar7 + 0x20) = param_1[0x1c];
  *(uint *)(iVar7 + 0x2c) = uVar4;
  *(uint *)(iVar7 + 0x30) = uVar8;
  *(float *)(iVar7 + 0x34) = ALBW_AS_F32(param_1[0x1e]) - ALBW_AS_F32(param_1[0x20]);
  *(float *)(iVar7 + 0x38) = ALBW_AS_F32(param_1[0x1d]) + ALBW_AS_F32(param_1[0x1f]);
  if ((*(uint *)(uVar11 + 0x188) & 0x4000) != 0) {
    func_003F41F8((float *)(param_1 + 0x24),(float *)(param_1 + 0x25),param_1,param_1[0x4e] + 0x3b0)
    ;
  }
  if ((*(uint *)(uVar11 + 0x188) & 0x800) != 0) {
    fVar20 = *(float *)(uVar11 + 0x3f0);
    fVar15 = *(float *)(uVar11 + 0x41c);
    fVar16 = *(float *)(uVar11 + 0x404);
    fVar17 = *(float *)(uVar11 + 0x408);
    param_1[0x26] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_1[0x26]) + *(float *)(uVar11 + 0x3ec)));
    param_1[0x27] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_1[0x27]) + fVar20));
    param_1[0x23] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_1[0x23]) + fVar15));
    param_1[0x28] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_1[0x28]) + fVar16));
    param_1[0x29] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_1[0x29]) + fVar17));
  }
  iVar7 = *piVar2;
  uVar4 = param_1[0x29];
  uVar8 = param_1[0x28];
  *(uint *)(iVar7 + 0x1c) = param_1[0x23];
  *(uint *)(iVar7 + 0x3c) = uVar4;
  *(uint *)(iVar7 + 0x40) = uVar8;
  *(float *)(iVar7 + 0x44) = ALBW_AS_F32(param_1[0x25]) - ALBW_AS_F32(param_1[0x27]);
  *(float *)(iVar7 + 0x48) = ALBW_AS_F32(param_1[0x24]) + ALBW_AS_F32(param_1[0x26]);
  if (*(ushort *)(uVar11 + 0x54c) != 0) {
    pfVar5 = (float *)(*(ushort *)(uVar11 + 0x556) + uVar11);
    if ((*(ushort *)(uVar11 + 0x54c) & 1) != 0) {
      pfVar5 = (float *)func_003EBDB4(uVar12,param_1,(uint *)pfVar5);
    }
    if ((*(ushort *)(uVar11 + 0x54c) & 2) != 0) {
      pfVar5 = func_003EBB60(uVar12,(int)param_1,pfVar5);
    }
    if ((*(ushort *)(uVar11 + 0x54c) & 4) != 0) {
      pfVar5 = (float *)func_003EB564(uVar12,(int)param_1,(uint *)pfVar5);
    }
    if ((*(ushort *)(uVar11 + 0x54c) & 8) != 0) {
      pfVar5 = (float *)func_003EC100(uVar12,param_1,(short *)pfVar5);
    }
    if ((*(ushort *)(uVar11 + 0x54c) & 0x10) != 0) {
      pfVar5 = (float *)func_003ECC68(uVar12,(int)param_1,(int *)pfVar5);
    }
    if ((*(ushort *)(uVar11 + 0x54c) & 0x20) != 0) {
      func_003EBD0C(uVar12,(int)param_1,pfVar5);
    }
  }
  fVar15 = ALBW_AS_F32(param_1[4]);
  fVar16 = ALBW_AS_F32(param_1[2]);
  fVar17 = ALBW_AS_F32(param_1[3]);
  fVar20 = fVar16 - ALBW_AS_F32(uVar24);
  fVar18 = fVar17 - ALBW_AS_F32(((ulonglong)uVar24 >> 0x20));
  if (((DAT_003f10a4 < (int)ALBW_AS_U32(ABS(fVar20))) || (DAT_003f10a4 < (int)ALBW_AS_U32(ABS(fVar18)))) ||
     (DAT_003f10a4 < (int)ALBW_AS_U32(ABS(fVar15 - fVar25)))) {
    param_1[5] = (uint)ALBW_AS_U32(((fVar20 - ALBW_AS_F32(param_1[5])) + ALBW_AS_F32(param_1[5])));
    param_1[6] = (uint)ALBW_AS_U32(((fVar18 - ALBW_AS_F32(param_1[6])) + ALBW_AS_F32(param_1[6])));
    param_1[7] = (uint)ALBW_AS_U32(((fVar15 - fVar25) - ALBW_AS_F32(param_1[7])) + ALBW_AS_F32(param_1[7]));
  }
  fVar25 = pfVar10[5];
  fVar20 = pfVar10[1];
  fVar21 = pfVar10[2];
  fVar18 = pfVar10[3];
  fVar23 = *pfVar10;
  fVar22 = pfVar10[6];
  fVar19 = pfVar10[7];
  fVar26 = pfVar10[4];
  iVar7 = *piVar2;
  *(float *)(iVar7 + 0x50) =
       pfVar10[9] * fVar17 + pfVar10[10] * fVar15 + pfVar10[0xb] + pfVar10[8] * fVar16;
  *(float *)(iVar7 + 0x54) = fVar25 * fVar17 + fVar22 * fVar15 + fVar19 + fVar26 * fVar16;
  *(float *)(iVar7 + 0x58) = fVar20 * fVar17 + fVar21 * fVar15 + fVar18 + fVar23 * fVar16;
  *(undefined4 *)(iVar7 + 0x5c) = 0;
  if (*(char *)(uVar12 + 0x2ab) != '\0') {
    fVar16 = ALBW_AS_F32(param_1[5]);
    fVar15 = ALBW_AS_F32(param_1[6]);
    fVar20 = ALBW_AS_F32(param_1[7]);
    fVar17 = *pfVar10 * fVar16 + pfVar10[1] * fVar15 + pfVar10[2] * fVar20;
    fVar18 = pfVar10[4] * fVar16 + pfVar10[5] * fVar15 + pfVar10[6] * fVar20;
    fVar15 = pfVar10[8] * fVar16 + pfVar10[9] * fVar15 + pfVar10[10] * fVar20;
    param_1[0xe] = (uint)ALBW_AS_U32(fVar17);
    param_1[0xf] = (uint)ALBW_AS_U32(fVar18);
    param_1[0x10] = (uint)ALBW_AS_U32(fVar15);
    *(float *)(iVar7 + 0x60) = fVar15;
    *(float *)(iVar7 + 100) = fVar18;
    *(float *)(iVar7 + 0x68) = fVar17;
  }
  *param_1 = *param_1 + 1;
  return;
}

