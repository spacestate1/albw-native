/* compilefix: USA 003F06D8 (EU 003F06B8), the converted stage-2 text.
 * Fixed (BOOT_LOG 184): the ARM copies this word between a float and an integer (no vcvt), which the
 * converted text wrote as a conversion of the value. */
#include "ghidra_types.h"

extern int *DAT_003f0a24;
extern uint DAT_003f0a28;
extern uint DAT_003f0a2c;
extern float *DAT_003f0a30;

// USA 003F06D8 <- EU 003F06B8 (Ghidra, non-matching)
// GLOBAL DAT_003f0a24 int *
// GLOBAL DAT_003f0a28 uint
// GLOBAL DAT_003f0a2c uint
// GLOBAL DAT_003f0a30 float *

undefined4 func_003F06D8(int *param_1)

{
  char cVar1;
  int *piVar2;
  uint *puVar3;
  int iVar4;
  float *pfVar5;
  int iVar6;
  uint uVar7;
  float fVar8;
  uint uVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  
  piVar2 = DAT_003f0a24;
  puVar3 = (uint *)*DAT_003f0a24;
  iVar4 = DAT_003f0a24[1];
  puVar3[1] = DAT_003f0a28;
  *puVar3 = iVar4 * 10 + 1U | 0x80000000;
  fVar8 = ALBW_AS_F32(param_1[3]);
  fVar11 = ALBW_AS_F32(param_1[9]);
  pfVar5 = (float *)param_1[0x4d];
  puVar3[3] = DAT_003f0a2c | piVar2[3] * 0x400000 - 0x100000U;
  fVar8 = fVar8 + fVar11;
  fVar12 = pfVar5[5];
  fVar10 = ALBW_AS_F32(param_1[2]) + ALBW_AS_F32(param_1[8]);
  fVar11 = ALBW_AS_F32(param_1[4]) + ALBW_AS_F32(param_1[10]);
  fVar15 = pfVar5[9];
  fVar16 = pfVar5[6];
  fVar14 = pfVar5[7];
  fVar17 = pfVar5[4];
  fVar18 = pfVar5[10];
  fVar13 = pfVar5[0xb];
  fVar19 = pfVar5[8];
  iVar4 = param_1[0x51];
  puVar3[0x16] = (uint)ALBW_AS_U32((pfVar5[1] * fVar8 + pfVar5[2] * fVar11 + pfVar5[3] + *pfVar5 * fVar10));
  puVar3[0x14] = (uint)ALBW_AS_U32((fVar15 * fVar8 + fVar18 * fVar11 + fVar13 + fVar19 * fVar10));
  puVar3[0x15] = (uint)ALBW_AS_U32((fVar12 * fVar8 + fVar16 * fVar11 + fVar14 + fVar17 * fVar10));
  puVar3[0x17] = 0;
  cVar1 = *(char *)(iVar4 + 0x2ac);
  param_1[2] = (int)ALBW_AS_U32(fVar10);
  param_1[3] = (int)ALBW_AS_U32(fVar8);
  param_1[4] = (int)ALBW_AS_U32(fVar11);
  if (cVar1 != '\0') {
    pfVar5 = (float *)param_1[0x18];
    if ((int)ALBW_AS_U32(pfVar5[2]) < *param_1) {
      if ((int)ALBW_AS_U32(pfVar5[3]) < *param_1) {
        param_1[0x17] = (int)ALBW_AS_U32((ALBW_AS_F32(param_1[0x17]) + pfVar5[1]));
      }
    }
    else {
      param_1[0x17] = (int)ALBW_AS_U32((ALBW_AS_F32(param_1[0x17]) + *pfVar5));
    }
  }
  puVar3[2] = param_1[0x17];
  iVar4 = piVar2[4];
  iVar6 = param_1[0x51];
  uVar7 = param_1[0x23];
  uVar9 = param_1[0x1c];
  puVar3[4] = param_1[iVar4 * 4 + 0x2e];
  puVar3[5] = param_1[iVar4 * 4 + 0x2d];
  puVar3[6] = param_1[iVar4 * 4 + 0x2c];
  puVar3[7] = uVar7;
  puVar3[8] = uVar9;
  if (*(char *)(iVar6 + 0x2ad) != '\0') {
    pfVar5 = (float *)param_1[0x1b];
    if ((int)ALBW_AS_U32(pfVar5[4]) < *param_1) {
      if ((int)ALBW_AS_U32(pfVar5[5]) < *param_1) {
        fVar11 = pfVar5[3];
        param_1[0x19] = (int)ALBW_AS_U32((ALBW_AS_F32(param_1[0x19]) + pfVar5[2]));
        param_1[0x1a] = (int)ALBW_AS_U32((ALBW_AS_F32(param_1[0x1a]) + fVar11));
      }
    }
    else {
      fVar11 = pfVar5[1];
      param_1[0x19] = (int)ALBW_AS_U32((ALBW_AS_F32(param_1[0x19]) + *pfVar5));
      param_1[0x1a] = (int)ALBW_AS_U32((ALBW_AS_F32(param_1[0x1a]) + fVar11));
    }
  }
  fVar11 = ALBW_AS_F32(param_1[0x19]);
  fVar8 = *DAT_003f0a30;
  uVar7 = param_1[0x21];
  uVar9 = param_1[0x22];
  puVar3[9] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_1[0x1a]) * DAT_003f0a30[1]));
  puVar3[10] = (uint)ALBW_AS_U32((fVar11 * fVar8));
  puVar3[0xc] = uVar7;
  puVar3[0xb] = uVar9;
  puVar3[0xd] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_1[0x1e]) - ALBW_AS_F32(param_1[0x20])));
  puVar3[0xe] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_1[0x1d]) + ALBW_AS_F32(param_1[0x1f])));
  fVar11 = ALBW_AS_F32(param_1[0x13]);
  uVar7 = param_1[0x11];
  uVar9 = param_1[0x12];
  iVar4 = param_1[0x4e];
  param_1[0x13] = (int)ALBW_AS_U32(fVar11 + ALBW_AS_F32(param_1[0x16]));
  puVar3[0x1c] = (uint)ALBW_AS_U32(fVar11 + ALBW_AS_F32(param_1[0x16]));
  puVar3[0x1d] = uVar9;
  puVar3[0x1e] = uVar7;
  if (*(char *)(iVar4 + 0x17b) == '\0') {
    fVar11 = *(float *)(iVar4 + 0x308);
    fVar8 = *(float *)(iVar4 + 0x30c);
    param_1[8] = (int)ALBW_AS_U32((ALBW_AS_F32(param_1[8]) + *(float *)(iVar4 + 0x304)));
    param_1[9] = (int)ALBW_AS_U32((ALBW_AS_F32(param_1[9]) + fVar11));
    param_1[10] = (int)ALBW_AS_U32((ALBW_AS_F32(param_1[10]) + fVar8));
  }
  else {
    fVar11 = *(float *)(iVar4 + 0x308);
    pfVar5 = (float *)param_1[0x4c];
    fVar12 = *(float *)(iVar4 + 0x30c);
    fVar15 = *(float *)(iVar4 + 0x304);
    fVar16 = pfVar5[6];
    fVar17 = pfVar5[5];
    fVar13 = pfVar5[1];
    fVar14 = pfVar5[2];
    fVar8 = pfVar5[10];
    fVar10 = pfVar5[9];
    param_1[8] = (int)ALBW_AS_U32((fVar11 * pfVar5[4] + fVar12 * pfVar5[8] +
                      ALBW_AS_F32(param_1[8]) + fVar15 * *pfVar5));
    param_1[9] = (int)ALBW_AS_U32((fVar11 * fVar17 + fVar12 * fVar10 + ALBW_AS_F32(param_1[9]) + fVar15 * fVar13));
    param_1[10] = (int)ALBW_AS_U32((fVar11 * fVar16 + fVar12 * fVar8 + ALBW_AS_F32(param_1[10]) + fVar15 * fVar14));
  }
  fVar11 = *(float *)(iVar4 + 0x300);
  param_1[8] = (int)ALBW_AS_U32((ALBW_AS_F32(param_1[8]) * fVar11));
  param_1[9] = (int)ALBW_AS_U32((ALBW_AS_F32(param_1[9]) * fVar11));
  param_1[10] = (int)ALBW_AS_U32((ALBW_AS_F32(param_1[10]) * fVar11));
  *param_1 = *param_1 + 1;
  return (undefined4)param_1;
}

