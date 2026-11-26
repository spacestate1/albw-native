/* compilefix: USA 002AEEB4 (EU 002AEE90), the converted stage-2 text.
 * Fixed (BOOT_LOG 184): the ARM copies this word between a float and an integer (no vcvt), which the
 * converted text wrote as a conversion of the value. */
#include "ghidra_types.h"

extern int func_002ACD14(undefined4 *param_1,int param_2,int param_3);
extern int func_002AD0E4(undefined4 *param_1,int param_2,float *param_3,undefined1 param_4,int param_5);
extern int func_002AD550(int param_1,int param_2,int param_3);
extern float func_004F944C(void);
extern int func_00521078(int param_1);
extern int func_006624F4(undefined4 *param_1,undefined1 param_2);
extern float DAT_002af0d4;
extern float DAT_002af0d8;
extern float DAT_002af0dc;
extern float DAT_002af0e0;

// USA 002AEEB4 <- EU 002AEE90 (Ghidra, non-matching)
// GLOBAL DAT_002af0d4 float
// GLOBAL DAT_002af0d8 float
// GLOBAL DAT_002af0dc float
// GLOBAL DAT_002af0e0 float

undefined4 func_002AEEB4(undefined4 *param_1)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  undefined8 uVar8;
  
  fVar6 = DAT_002af0d4;
  *(short *)(param_1 + 0xb0) = *(short *)(param_1 + 0xb0) + 1;
  fVar7 = DAT_002af0dc;
  fVar5 = ALBW_AS_F32(param_1[100]);
  if (ALBW_AS_F32(param_1[100]) <= fVar6) {
    fVar5 = DAT_002af0d8;
  }
  fVar5 = ALBW_AS_F32(param_1[0x10]) - fVar5;
  param_1[0x10] = ALBW_AS_U32(fVar5);
  fVar7 = *(float *)(param_1[0xd] + 0x4c8) - fVar7;
  if (fVar7 <= fVar6) {
    fVar7 = -fVar7;
  }
  if (fVar5 < -fVar7) {
    fVar5 = -fVar7;
  }
  param_1[0x10] = ALBW_AS_U32(fVar5);
  if (*(char *)(param_1 + 0x7a) == '\0') {
    fVar7 = *(float *)(param_1[0xd] + 0x36c);
    if ((ALBW_AS_F32(param_1[0x79]) < fVar7) && (fVar7 + fVar5 <= ALBW_AS_F32(param_1[0x79]))) {
      *(undefined1 *)(param_1 + 0x7a) = 1;
      iVar3 = func_002AD0E4(param_1,1,(float *)0x0,0,0);
      if (iVar3 != 0) {
        return 0;
      }
    }
  }
  uVar8 = CONCAT44(fVar6,param_1[0x10]);
  if (fVar6 < ALBW_AS_F32(param_1[0x10])) {
    if ((*(uint *)(param_1[0xd] + 0x5a0) & 0x800000) != 0) {
      param_1[0x10] = ALBW_AS_U32(fVar6);
    }
  }
  else {
    bVar2 = func_00521078(param_1[0xd]);
    if (bVar2) {
      if (*(byte *)(param_1 + 9) < 2) {
        fVar6 = ALBW_AS_F32(uVar8) * DAT_002af0e0;
        *(ushort *)(param_1 + 0xe) = *(ushort *)(param_1 + 0xe) | 2;
        param_1[0x10] = ALBW_AS_U32(fVar6);
        if (*(char *)(param_1 + 9) == '\0') {
          (**(code **)(*(int *)param_1[0xd] + 0x4c))((int *)param_1[0xd]);
        }
      }
      else {
        fVar6 = func_004F944C();
        param_1[0x10] = ALBW_AS_U32(fVar6);
        if ((uint)param_1[10] < (uint)param_1[0xb]) {
          param_1[10] = param_1[10] + 1;
        }
      }
      cVar1 = *(char *)(param_1 + 9);
      *(char *)(param_1 + 9) = cVar1 + '\x01';
      if ((char)(cVar1 + '\x01') == '\x02') {
        if ((*(uint *)(param_1[0xd] + 0x59c) & 0x80000) == 0) {
          param_1[0xb] = 0;
          param_1[0xc] = (int)((ulonglong)uVar8 >> 0x20);
          param_1[10] = 0;
        }
        else {
          func_002AD550((int)param_1,param_1[0xb] - param_1[10],1);
        }
      }
    }
  }
  uVar4 = param_1[0x1f];
  if (uVar4 < (uint)param_1[0x20]) {
    uVar4 = uVar4 + 1;
    param_1[0x1f] = uVar4;
  }
  if ((uint)param_1[0x20] <= uVar4) {
    *(ushort *)(param_1 + 0xe) = *(ushort *)(param_1 + 0xe) & 0xfff7;
  }
  if ((((uint)param_1[0xb] <= (uint)param_1[10]) &&
      ((*(uint *)(param_1[0xd] + 0x59c) & 0x80000) != 0)) &&
     (*(char *)(param_1[0xd] + 0x7fc) != '\x05')) {
    return func_006624F4(param_1,2);
  }
  return func_002ACD14(param_1,0,(uint)((*(uint *)(param_1[0xd] + 0x59c) & 0x80000) != 0));
}

