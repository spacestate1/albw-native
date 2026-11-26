/* compilefix: USA 003ED284 (EU 003ED264), the converted stage-2 text.
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
extern int DAT_003ed770;

// USA 003ED284 <- EU 003ED264 (Ghidra, non-matching)
// GLOBAL DAT_003ed770 int

void func_003ED284(int param_1,uint *param_2)

{
  float *pfVar1;
  uint uVar2;
  uint uVar3;
  float *pfVar4;
  uint uVar5;
  uint uVar6;
  uint in_fpscr;
  float fVar7;
  float fVar8;
  float fVar9;
  undefined8 uVar10;
  float fVar11;
  longlong lVar12;
  undefined8 uVar13;
  
  pfVar1 = (float *)param_2[0x4c];
  pfVar4 = (float *)param_2[0x4d];
  uVar5 = param_2[0x4e];
  uVar10 = *(undefined8 *)(param_2 + 2);
  fVar11 = ALBW_AS_F32(param_2[4]);
  param_2[2] = (uint)ALBW_AS_U32(ALBW_AS_F32(param_2[2]) + ALBW_AS_F32(param_2[8]));
  param_2[3] = (uint)ALBW_AS_U32((ALBW_AS_F32(((ulonglong)uVar10 >> 0x20)) + ALBW_AS_F32(param_2[9])));
  param_2[4] = (uint)ALBW_AS_U32((fVar11 + ALBW_AS_F32(param_2[10])));
  if ((*(uint *)(param_1 + 0x238) & 1) != 0) {
    param_2[8] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_2[8]) * *(float *)(uVar5 + 0x708)));
    param_2[9] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_2[9]) * *(float *)(uVar5 + 0x708)));
    param_2[10] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_2[10]) * *(float *)(uVar5 + 0x708)));
  }
  if ((*(uint *)(param_1 + 0x238) & 2) != 0) {
    if (*(char *)(uVar5 + 0x17b) == '\0') {
      param_2[8] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_2[8]) + *(float *)(uVar5 + 0x6ac)));
      param_2[9] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_2[9]) + *(float *)(uVar5 + 0x6b0)));
      fVar7 = ALBW_AS_F32(param_2[10]) + *(float *)(uVar5 + 0x6b4);
    }
    else {
      param_2[8] = (uint)ALBW_AS_U32((*(float *)(uVar5 + 0x6b0) * pfVar1[4] +
                          *(float *)(uVar5 + 0x6b4) * pfVar1[8] +
                         ALBW_AS_F32(param_2[8]) + *(float *)(uVar5 + 0x6ac) * *pfVar1));
      param_2[9] = (uint)ALBW_AS_U32((*(float *)(uVar5 + 0x6b0) * pfVar1[5] +
                          *(float *)(uVar5 + 0x6b4) * pfVar1[9] +
                         ALBW_AS_F32(param_2[9]) + *(float *)(uVar5 + 0x6ac) * pfVar1[1]));
      fVar7 = *(float *)(uVar5 + 0x6b0) * pfVar1[6] + *(float *)(uVar5 + 0x6b4) * pfVar1[10] +
              ALBW_AS_F32(param_2[10]) + *(float *)(uVar5 + 0x6ac) * pfVar1[2];
    }
    param_2[10] = (uint)ALBW_AS_U32(fVar7);
  }
  uVar2 = *param_2;
  if ((int)uVar2 < *(int *)(uVar5 + 0x6bc)) {
    param_2[0x17] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_2[0x17]) + *(float *)param_2[0x18]));
  }
  else if (*(int *)(uVar5 + 0x6b8) <= (int)uVar2) {
    param_2[0x17] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_2[0x17]) + *(float *)(param_2[0x18] + 4)));
  }
  if (((*(uint *)(param_1 + 0x238) & 0x40) != 0) && (*(int *)(uVar5 + 0x6c0) <= (int)uVar2)) {
    param_2[0x19] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_2[0x19]) + *(float *)param_2[0x1b]));
    param_2[0x1a] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_2[0x1a]) + ((float *)param_2[0x1b])[1]));
  }
  if ((*(uint *)(param_1 + 0x238) & 4) != 0) {
    param_2[0x11] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_2[0x11]) + ALBW_AS_F32(param_2[0x14])));
    param_2[0x12] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_2[0x12]) + ALBW_AS_F32(param_2[0x15])));
    param_2[0x13] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_2[0x13]) + ALBW_AS_F32(param_2[0x16])));
  }
  if ((*(uint *)(param_1 + 0x238) & 8) != 0) {
    fVar7 = *(float *)(uVar5 + 0x69c);
    param_2[0x14] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_2[0x14]) * fVar7));
    param_2[0x15] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_2[0x15]) * fVar7));
    param_2[0x16] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_2[0x16]) * fVar7));
  }
  if ((*(uint *)(param_1 + 0x238) & 0x2000) != 0) {
    uVar2 = *param_2;
    uVar6 = (uint)*(short *)(uVar5 + 0x6f8);
    uVar3 = uVar6;
    if (uVar6 == 0) {
      uVar2 = uVar2 * (int)*(short *)(uVar5 + 0x6fa);
      uVar3 = param_2[1];
    }
    lVar12 = func_001104E4(uVar2,uVar3);
    uVar2 = (uint)lVar12;
    if ((*(char *)(uVar5 + 0x6fc) == '\0') || (uVar2 < (uint)(int)*(short *)(uVar5 + 0x6fa))) {
      if ((uVar6 != 0) &&
         ((*(char *)(uVar5 + 0x6fc) == '\0' && ((*(uint *)(uVar5 + 0x548) & 0x4000) != 0)))) {
        uVar2 = uVar2 + param_2[0x54];
      }
      uVar13 = func_00110710(uVar2,(int)*(short *)(uVar5 + 0x6fa));
      uVar13 = func_00110710((uint)*(byte *)((int)((ulonglong)uVar13 >> 0x20) + uVar5 + 0x6d8),
                             (uint)*(byte *)(uVar5 + 0x6ce));
      fVar9 = *(float *)(uVar5 + 0x6d4);
      fVar8 = (float)VectorSignedToFloat((int)uVar13,(byte)(in_fpscr >> 0x15) & 3);
      fVar7 = (float)VectorSignedToFloat((int)((ulonglong)uVar13 >> 0x20),
                                         (byte)(in_fpscr >> 0x15) & 3);
      param_2[0x1d] = (uint)ALBW_AS_U32((*(float *)(uVar5 + 0x6d0) * fVar7));
      param_2[0x1e] = (uint)ALBW_AS_U32((fVar9 * fVar8));
    }
  }
  if ((*(uint *)(uVar5 + 0x548) & 0x800) != 0) {
    pfVar1 = (float *)(*(ushort *)(uVar5 + 0x556) + uVar5);
    if ((*(ushort *)(uVar5 + 0x54c) & 1) != 0) {
      pfVar1 = (float *)func_003EBDB4(param_1,param_2,(uint *)pfVar1);
    }
    if ((*(ushort *)(uVar5 + 0x54c) & 2) != 0) {
      pfVar1 = func_003EBB60(param_1,(int)param_2,pfVar1);
    }
    if ((*(ushort *)(uVar5 + 0x54c) & 4) != 0) {
      pfVar1 = (float *)func_003EB564(param_1,(int)param_2,(uint *)pfVar1);
    }
    if ((*(ushort *)(uVar5 + 0x54c) & 8) != 0) {
      pfVar1 = (float *)func_003EC100(param_1,param_2,(short *)pfVar1);
    }
    if ((*(ushort *)(uVar5 + 0x54c) & 0x10) != 0) {
      pfVar1 = (float *)func_003ECC68(param_1,(int)param_2,(int *)pfVar1);
    }
    if ((*(ushort *)(uVar5 + 0x54c) & 0x20) != 0) {
      func_003EBD0C(param_1,(int)param_2,pfVar1);
    }
  }
  fVar9 = ALBW_AS_F32(param_2[2]);
  fVar7 = ALBW_AS_F32(param_2[3]);
  fVar8 = ALBW_AS_F32(param_2[4]);
  param_2[0xb] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_2[0x41]) * fVar7 + ALBW_AS_F32(param_2[0x42]) * fVar8 +
                       ALBW_AS_F32(param_2[0x43]) + ALBW_AS_F32(param_2[0x40]) * fVar9));
  param_2[0xc] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_2[0x45]) * fVar7 + ALBW_AS_F32(param_2[0x46]) * fVar8 +
                       ALBW_AS_F32(param_2[0x47]) + ALBW_AS_F32(param_2[0x44]) * fVar9));
  param_2[0xd] = (uint)ALBW_AS_U32((ALBW_AS_F32(param_2[0x49]) * fVar7 + ALBW_AS_F32(param_2[0x4a]) * fVar8 +
                       ALBW_AS_F32(param_2[0x4b]) + ALBW_AS_F32(param_2[0x48]) * fVar9));
  if ((*(uint *)(param_1 + 0x238) & 0x10) != 0) {
    fVar9 = fVar9 - ALBW_AS_F32(uVar10);
    fVar7 = fVar7 - ALBW_AS_F32(((ulonglong)uVar10 >> 0x20));
    if (((DAT_003ed770 < (int)ALBW_AS_U32(ABS(fVar9))) || (DAT_003ed770 < (int)ALBW_AS_U32(ABS(fVar7)))) ||
       (DAT_003ed770 < (int)ALBW_AS_U32(ABS(fVar8 - fVar11)))) {
      param_2[5] = (uint)ALBW_AS_U32(((fVar9 - ALBW_AS_F32(param_2[5])) + ALBW_AS_F32(param_2[5])));
      param_2[6] = (uint)ALBW_AS_U32(((fVar7 - ALBW_AS_F32(param_2[6])) + ALBW_AS_F32(param_2[6])));
      param_2[7] = (uint)ALBW_AS_U32(((fVar8 - fVar11) - ALBW_AS_F32(param_2[7])) + ALBW_AS_F32(param_2[7]));
    }
    fVar8 = ALBW_AS_F32(param_2[5]);
    fVar7 = ALBW_AS_F32(param_2[6]);
    fVar11 = ALBW_AS_F32(param_2[7]);
    param_2[0xe] = (uint)ALBW_AS_U32((*pfVar4 * fVar8 + pfVar4[1] * fVar7 + pfVar4[2] * fVar11));
    param_2[0xf] = (uint)ALBW_AS_U32((pfVar4[4] * fVar8 + pfVar4[5] * fVar7 + pfVar4[6] * fVar11));
    param_2[0x10] = (uint)ALBW_AS_U32((pfVar4[8] * fVar8 + pfVar4[9] * fVar7 + pfVar4[10] * fVar11));
  }
  *param_2 = *param_2 + 1;
  return;
}

