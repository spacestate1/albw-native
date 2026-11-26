/* compilefix: USA 003EF924 (EU 003EF904), the converted stage-2 text.
 * Fixed (BOOT_LOG 184): the ARM copies this word between a float and an integer (no vcvt), which the
 * converted text wrote as a conversion of the value. */
#include "ghidra_types.h"

extern int func_003F41F8(float *param_1,float *param_2,uint *param_3,int param_4);
extern int func_003F6B40(uint *param_1,int param_2);
extern int *DAT_003effd0;
extern uint DAT_003effd4;
extern int DAT_003effd8;
extern int DAT_003effdc;
extern float *DAT_003effe0;
extern float DAT_003effe4;
extern uint DAT_003effe8;
extern float DAT_003effec;

// USA 003EF924 <- EU 003EF904 (Ghidra, non-matching)
// GLOBAL DAT_003effd0 int *
// GLOBAL DAT_003effd4 uint
// GLOBAL DAT_003effd8 int
// GLOBAL DAT_003effdc int
// GLOBAL DAT_003effe0 float *
// GLOBAL DAT_003effe4 float
// GLOBAL DAT_003effe8 uint
// GLOBAL DAT_003effec float

void func_003EF924(uint *param_1)

{
  char cVar1;
  int *piVar2;
  float *pfVar3;
  uint *puVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  float fVar10;
  uint uVar11;
  float fVar12;
  uint uVar13;
  float fVar14;
  float fVar15;
  uint uVar16;
  float fVar17;
  uint uVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  
  uVar8 = DAT_003effd4;
  piVar2 = DAT_003effd0;
  uVar9 = DAT_003effd4 | (int)DAT_003effd4 >> 0x13;
  puVar4 = (uint *)*DAT_003effd0;
  uVar6 = param_1[0x51];
  *puVar4 = DAT_003effd0[1] * 10 + 1U | 0x80000000;
  puVar4[1] = uVar8;
  iVar7 = *(int *)(uVar6 + 200);
  pfVar3 = (float *)param_1[0x4d];
  uVar8 = param_1[0x4e];
  puVar4[3] = uVar9 | piVar2[3] * 0x400000 - 0x100000U;
  if (iVar7 == 2) {
    uVar9 = *(uint *)(uVar6 + 0x70);
    uVar11 = *(uint *)(uVar6 + 0x80);
    uVar13 = *(uint *)(uVar6 + 0x30);
    uVar16 = *(uint *)(uVar6 + 0x40);
    uVar18 = *(uint *)(uVar6 + 0x50);
    param_1[0x43] = *(uint *)(uVar6 + 0x60);
    param_1[0x47] = uVar9;
    param_1[0x4b] = uVar11;
    param_1[0x37] = uVar13;
    param_1[0x3b] = uVar16;
    param_1[0x3f] = uVar18;
  }
  if (*(char *)(uVar6 + 0x2ab) != '\0') {
    if (((DAT_003effd8 < (int)ALBW_AS_U32(ABS(ALBW_AS_F32(param_1[8])))) ||
        (DAT_003effd8 < (int)ALBW_AS_U32(ABS(ALBW_AS_F32(param_1[9]))))) ||
       (DAT_003effd8 < (int)ALBW_AS_U32(ABS(ALBW_AS_F32(param_1[10]))))) {
      fVar14 = ALBW_AS_F32(param_1[5]);
      param_1[7] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_1[10]) - ALBW_AS_F32(param_1[7])) + ALBW_AS_F32(param_1[7]));
      param_1[5] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_1[8]) - fVar14) + fVar14);
      param_1[6] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_1[9]) - ALBW_AS_F32(param_1[6])) + ALBW_AS_F32(param_1[6]));
    }
    fVar12 = ALBW_AS_F32(param_1[5]);
    fVar10 = ALBW_AS_F32(param_1[6]);
    fVar14 = ALBW_AS_F32(param_1[7]);
    fVar15 = *pfVar3 * fVar12 + pfVar3[1] * fVar10 + pfVar3[2] * fVar14;
    fVar17 = pfVar3[4] * fVar12 + pfVar3[5] * fVar10 + pfVar3[6] * fVar14;
    fVar14 = pfVar3[8] * fVar12 + pfVar3[9] * fVar10 + pfVar3[10] * fVar14;
    param_1[0x10] = (uint)ALBW_AS_U32(fVar14);
    param_1[0xe] = (uint)ALBW_AS_U32(fVar15);
    param_1[0xf] = (uint)ALBW_AS_U32(fVar17);
    puVar4[0x18] = (uint)ALBW_AS_U32(fVar14);
    puVar4[0x19] = (uint)ALBW_AS_U32(fVar17);
    puVar4[0x1a] = (uint)ALBW_AS_U32(fVar15);
  }
  fVar21 = pfVar3[1];
  fVar12 = ALBW_AS_F32(param_1[3]) + ALBW_AS_F32(param_1[9]);
  fVar22 = pfVar3[9];
  fVar20 = pfVar3[5];
  fVar10 = ALBW_AS_F32(param_1[2]) + ALBW_AS_F32(param_1[8]);
  fVar14 = ALBW_AS_F32(param_1[4]) + ALBW_AS_F32(param_1[10]);
  fVar23 = pfVar3[2];
  fVar15 = pfVar3[3];
  fVar26 = *pfVar3;
  fVar25 = pfVar3[10];
  fVar19 = pfVar3[0xb];
  fVar28 = pfVar3[8];
  fVar24 = pfVar3[6];
  fVar17 = pfVar3[7];
  fVar27 = pfVar3[4];
  uVar6 = param_1[0x51];
  param_1[4] = (uint)ALBW_AS_U32(fVar14);
  param_1[2] = (uint)ALBW_AS_U32(fVar10);
  param_1[3] = (uint)ALBW_AS_U32(fVar12);
  puVar4[0x14] = (uint)ALBW_AS_U32((fVar22 * fVar12 + fVar25 * fVar14 + fVar19 + fVar28 * fVar10));
  puVar4[0x15] = (uint)ALBW_AS_U32((fVar20 * fVar12 + fVar24 * fVar14 + fVar17 + fVar27 * fVar10));
  puVar4[0x16] = (uint)ALBW_AS_U32((fVar21 * fVar12 + fVar23 * fVar14 + fVar15 + fVar26 * fVar10));
  puVar4[0x17] = 0;
  if (*(char *)(uVar6 + 0x2ac) != '\0') {
    pfVar3 = (float *)param_1[0x18];
    if ((int)ALBW_AS_U32(pfVar3[2]) < (int)*param_1) {
      if ((int)ALBW_AS_U32(pfVar3[3]) < (int)*param_1) {
        param_1[0x17] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_1[0x17]) + pfVar3[1]));
      }
    }
    else {
      param_1[0x17] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_1[0x17]) + *pfVar3));
    }
  }
  iVar7 = DAT_003effdc;
  puVar4[2] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_1[0x17]) * ALBW_AS_F32(param_1[0x2a])));
  if ((*(uint *)(uVar8 + 0x188) & *(uint *)(iVar7 + piVar2[4] * 4)) != 0) {
    func_003F6B40(param_1,piVar2[4]);
  }
  iVar5 = piVar2[4];
  iVar7 = *piVar2;
  uVar6 = param_1[0x51];
  *(uint *)(iVar7 + 0x10) = param_1[iVar5 * 4 + 0x2e];
  *(uint *)(iVar7 + 0x14) = param_1[iVar5 * 4 + 0x2d];
  *(uint *)(iVar7 + 0x18) = param_1[iVar5 * 4 + 0x2c];
  if (*(char *)(uVar6 + 0x2ad) != '\0') {
    pfVar3 = (float *)param_1[0x1b];
    if ((int)ALBW_AS_U32(pfVar3[4]) < (int)*param_1) {
      if ((int)ALBW_AS_U32(pfVar3[5]) < (int)*param_1) {
        fVar14 = pfVar3[3];
        param_1[0x19] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_1[0x19]) + pfVar3[2]));
        param_1[0x1a] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_1[0x1a]) + fVar14));
      }
    }
    else {
      fVar14 = pfVar3[1];
      param_1[0x19] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_1[0x19]) + *pfVar3));
      param_1[0x1a] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_1[0x1a]) + fVar14));
    }
  }
  fVar12 = ALBW_AS_F32(param_1[0x19]);
  fVar15 = *DAT_003effe0;
  fVar10 = ALBW_AS_F32(param_1[0x2b]);
  fVar14 = ALBW_AS_F32(param_1[0x1a]) * DAT_003effe0[1] * fVar10;
  if (DAT_003effe4 < *(float *)(uVar8 + 0x504)) {
    fVar14 = fVar14 + (SQRT(ALBW_AS_F32(param_1[8]) * ALBW_AS_F32(param_1[8]) +
                            ALBW_AS_F32(param_1[9]) * ALBW_AS_F32(param_1[9]) +
                            ALBW_AS_F32(param_1[10]) * ALBW_AS_F32(param_1[10])) +
                      SQRT(ALBW_AS_F32(param_1[5]) * ALBW_AS_F32(param_1[5]) +
                           ALBW_AS_F32(param_1[6]) * ALBW_AS_F32(param_1[6]) +
                           ALBW_AS_F32(param_1[7]) * ALBW_AS_F32(param_1[7]))) * *(float *)(uVar8 + 0x504);
  }
  uVar6 = *(uint *)(uVar8 + 0x188);
  *(float *)(iVar7 + 0x24) = fVar14;
  *(float *)(iVar7 + 0x28) = fVar12 * fVar15 * fVar10;
  if ((uVar6 & 0x2000) != 0) {
    func_003F41F8((float *)(param_1 + 0x1d),(float *)(param_1 + 0x1e),param_1,param_1[0x4e] + 0x338)
    ;
  }
  fVar14 = DAT_003effec;
  uVar6 = DAT_003effe8;
  fVar10 = ALBW_AS_F32((DAT_003effe8 | DAT_003effe8 << 0xe));
  if ((*(uint *)(uVar8 + 0x188) & 0x400) != 0) {
    fVar12 = ALBW_AS_F32(param_1[0x1f]) + *(float *)(uVar8 + 0x374);
    param_1[0x1f] = (uint)ALBW_AS_U32(fVar12);
    if ((int)uVar6 < (int)ALBW_AS_U32(fVar12)) {
      fVar12 = fVar12 - fVar14;
LAB_003efd28:
      param_1[0x1f] = (uint)ALBW_AS_U32(fVar12);
    }
    else if ((uint)ALBW_AS_U32(fVar10) < (uint)ALBW_AS_U32(fVar12)) {
      fVar12 = fVar12 + fVar14;
      goto LAB_003efd28;
    }
    fVar12 = ALBW_AS_F32(param_1[0x20]) + *(float *)(uVar8 + 0x378);
    param_1[0x20] = (uint)ALBW_AS_U32(fVar12);
    if ((int)uVar6 < (int)ALBW_AS_U32(fVar12)) {
      fVar12 = fVar12 - fVar14;
LAB_003efd5c:
      param_1[0x20] = (uint)ALBW_AS_U32(fVar12);
    }
    else if ((uint)ALBW_AS_U32(fVar10) < (uint)ALBW_AS_U32(fVar12)) {
      fVar12 = fVar12 + fVar14;
      goto LAB_003efd5c;
    }
    uVar9 = param_1[0x4e];
    fVar12 = *(float *)(uVar9 + 0x390);
    fVar15 = *(float *)(uVar9 + 0x3a4);
    param_1[0x21] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_1[0x21]) + *(float *)(uVar9 + 0x38c)));
    param_1[0x22] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_1[0x22]) + fVar12));
    param_1[0x1c] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_1[0x1c]) + fVar15));
  }
  iVar7 = *piVar2;
  uVar9 = param_1[0x22];
  uVar11 = param_1[0x21];
  *(uint *)(iVar7 + 0x20) = param_1[0x1c];
  *(uint *)(iVar7 + 0x2c) = uVar9;
  *(uint *)(iVar7 + 0x30) = uVar11;
  *(float *)(iVar7 + 0x34) = ALBW_AS_F32(param_1[0x1e]) - ALBW_AS_F32(param_1[0x20]);
  *(float *)(iVar7 + 0x38) = ALBW_AS_F32(param_1[0x1d]) + ALBW_AS_F32(param_1[0x1f]);
  if ((*(uint *)(uVar8 + 0x188) & 0x4000) != 0) {
    func_003F41F8((float *)(param_1 + 0x24),(float *)(param_1 + 0x25),param_1,param_1[0x4e] + 0x3b0)
    ;
  }
  if ((*(uint *)(uVar8 + 0x188) & 0x800) == 0) goto LAB_003efe94;
  fVar12 = ALBW_AS_F32(param_1[0x26]) + *(float *)(uVar8 + 0x3ec);
  param_1[0x26] = (uint)ALBW_AS_U32(fVar12);
  if ((int)uVar6 < (int)ALBW_AS_U32(fVar12)) {
    fVar12 = fVar12 - fVar14;
LAB_003efe2c:
    param_1[0x26] = (uint)ALBW_AS_U32(fVar12);
  }
  else if ((uint)ALBW_AS_U32(fVar10) < (uint)ALBW_AS_U32(fVar12)) {
    fVar12 = fVar12 + fVar14;
    goto LAB_003efe2c;
  }
  fVar12 = ALBW_AS_F32(param_1[0x27]) + *(float *)(uVar8 + 0x3f0);
  param_1[0x27] = (uint)ALBW_AS_U32(fVar12);
  if ((int)uVar6 < (int)ALBW_AS_U32(fVar12)) {
    fVar12 = fVar12 - fVar14;
LAB_003efe60:
    param_1[0x27] = (uint)ALBW_AS_U32(fVar12);
  }
  else if ((uint)ALBW_AS_U32(fVar10) < (uint)ALBW_AS_U32(fVar12)) {
    fVar12 = fVar12 + fVar14;
    goto LAB_003efe60;
  }
  fVar14 = *(float *)(uVar8 + 0x408);
  fVar10 = *(float *)(uVar8 + 0x404);
  param_1[0x23] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_1[0x23]) + *(float *)(uVar8 + 0x41c)));
  param_1[0x28] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_1[0x28]) + fVar10));
  param_1[0x29] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_1[0x29]) + fVar14));
LAB_003efe94:
  iVar7 = *piVar2;
  uVar8 = param_1[0x29];
  uVar6 = param_1[0x28];
  *(uint *)(iVar7 + 0x1c) = param_1[0x23];
  *(uint *)(iVar7 + 0x3c) = uVar8;
  *(uint *)(iVar7 + 0x40) = uVar6;
  *(float *)(iVar7 + 0x44) = ALBW_AS_F32(param_1[0x25]) - ALBW_AS_F32(param_1[0x27]);
  *(float *)(iVar7 + 0x48) = ALBW_AS_F32(param_1[0x24]) + ALBW_AS_F32(param_1[0x26]);
  fVar14 = ALBW_AS_F32(param_1[0x16]);
  fVar10 = ALBW_AS_F32(param_1[0x15]);
  fVar12 = ALBW_AS_F32(param_1[0x14]);
  uVar8 = param_1[0x4e];
  fVar20 = ALBW_AS_F32(param_1[0x13]) + fVar14;
  fVar15 = ALBW_AS_F32(param_1[0x12]) + fVar10;
  fVar17 = ALBW_AS_F32(param_1[0x11]) + fVar12;
  fVar19 = *(float *)(uVar8 + 0x538);
  param_1[0x13] = (uint)ALBW_AS_U32(fVar20);
  param_1[0x12] = (uint)ALBW_AS_U32(fVar15);
  param_1[0x11] = (uint)ALBW_AS_U32(fVar17);
  *(float *)(iVar7 + 0x70) = fVar20;
  *(float *)(iVar7 + 0x74) = fVar15;
  *(float *)(iVar7 + 0x78) = fVar17;
  cVar1 = *(char *)(uVar8 + 0x17b);
  param_1[0x16] = (uint)ALBW_AS_U32((fVar14 * fVar19));
  param_1[0x15] = (uint)ALBW_AS_U32((fVar10 * fVar19));
  param_1[0x14] = (uint)ALBW_AS_U32((fVar12 * fVar19));
  if (cVar1 == '\0') {
    fVar10 = *(float *)(uVar8 + 0x30c);
    fVar14 = ALBW_AS_F32(param_1[9]) + *(float *)(uVar8 + 0x308);
    param_1[8] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_1[8]) + *(float *)(uVar8 + 0x304)));
    param_1[9] = (uint)ALBW_AS_U32(fVar14);
    param_1[10] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_1[10]) + fVar10));
  }
  else {
    fVar10 = *(float *)(uVar8 + 0x308);
    pfVar3 = (float *)param_1[0x4c];
    fVar15 = *(float *)(uVar8 + 0x30c);
    fVar19 = *(float *)(uVar8 + 0x304);
    fVar20 = pfVar3[6];
    fVar12 = pfVar3[10];
    fVar17 = pfVar3[2];
    fVar14 = fVar10 * pfVar3[5] + fVar15 * pfVar3[9] + ALBW_AS_F32(param_1[9]) + fVar19 * pfVar3[1];
    param_1[8] = (uint)ALBW_AS_U32((fVar10 * pfVar3[4] + fVar15 * pfVar3[8] +
                       ALBW_AS_F32(param_1[8]) + fVar19 * *pfVar3));
    param_1[9] = (uint)ALBW_AS_U32(fVar14);
    param_1[10] = (uint)ALBW_AS_U32((fVar10 * fVar20 + fVar15 * fVar12 + ALBW_AS_F32(param_1[10]) + fVar19 * fVar17));
  }
  fVar10 = *(float *)(uVar8 + 0x300);
  param_1[8] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_1[8]) * fVar10));
  param_1[9] = (uint)ALBW_AS_U32((fVar14 * fVar10));
  param_1[10] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_1[10]) * fVar10));
  *param_1 = *param_1 + 1;
  return;
}

