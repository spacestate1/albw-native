/* compilefix: USA 0015CB98 (EU 0015CB9C), the converted stage-2 text.
 * Fixed (BOOT_LOG 184): the ARM copies this word between a float and an integer (no vcvt), which the
 * converted text wrote as a conversion of the value. */
#include "ghidra_types.h"

extern int func_0015C534(undefined4 *param_1);
extern int func_00161178(undefined4 *param_1);
extern int func_002228D0(int param_1,int param_2,uint param_3);
extern int func_0024D32C(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5 );
extern int func_0024D3F0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,int param_4, int param_5,undefined2 param_6);
extern float func_0032EF0C(float *param_1,float *param_2);
extern int func_004FC07C(int param_1,int param_2,uint param_3,int param_4);
extern int func_00520FC0(void);
extern int func_0054FAC0(int param_1,uint param_2);
extern int func_0054FBC4(int param_1,float *param_2,float *param_3);
extern int func_00550078(float *param_1,float *param_2);
extern uint DAT_0015ce40;
extern uint DAT_0015ce44;
extern int DAT_0015ce48;
extern undefined4 DAT_0015ce4c;

// USA 0015CB98 <- EU 0015CB9C (Ghidra, non-matching)
// GLOBAL DAT_0015ce40 uint
// GLOBAL DAT_0015ce44 uint
// GLOBAL DAT_0015ce48 int
// GLOBAL DAT_0015ce4c undefined4

void func_0015CB98(undefined4 *param_1)

{
  _Alignas(8) unsigned char albw_frame[0x60]; /* entry_sp - 0x60 .. entry_sp + 0x0 */
#define stack0xffffffa8 (*(undefined4 *)(albw_frame + 0x8))
  bool bVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  float *pfVar5;
  uint uVar6;
  int iVar7;
  float fVar8;
  uint uVar9;
  float *pfVar10;
  int iVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  float in_s2;
  #define fStack_50 (*(float *)(albw_frame + 0x10))
  #define fStack_4c (*(float *)(albw_frame + 0x14))
  #define iStack_48 (*(int *)(albw_frame + 0x18))
  #define uStack_44 (*(undefined4 *)(albw_frame + 0x1c))
  #define afStack_40 ((float *)(albw_frame + 0x20))
  #define fStack_34 (*(float *)(albw_frame + 0x2c))
  func_004FC07C((int)param_1,1,0xffffffff,0);
  if (param_1[600] != 0) {
    func_002228D0(param_1[600],1,0xffffffff);
  }
  uVar12 = 0;
  if ((*(ushort *)((int)param_1 + 0x2e) & 0xff) == 0) {
    pfVar10 = (float *)(param_1 + 0x26d);
    pfVar5 = (float *)func_00520FC0();
    fVar8 = ALBW_AS_F32(param_1[0xf4]);
    fStack_50 = ALBW_AS_F32(param_1[0xf6]);
    fStack_4c = *pfVar10;
    iStack_48 = param_1[0x26e];
    uStack_44 = param_1[0x26f];
    afStack_40[0] = func_0032EF0C((float *)(param_1 + 0xf4),pfVar10);
    fStack_34 = -(afStack_40[0] * fVar8) + -(in_s2 * fStack_50);
    bVar1 = func_00550078((float *)&stack0xffffffa8,pfVar5);
    uVar6 = func_0054FBC4((int)pfVar10,(float *)(param_1 + 0xf4),(float *)0x0);
    iVar7 = func_0054FAC0((int)pfVar10,uVar6);
    iStack_48 = iVar7 + -0x80000000;
    uStack_44 = param_1[0xb3];
    func_0024D3F0(pfVar10,&uStack_44,&iStack_48,bVar1 ^ 1,1,0);
    iVar11 = func_0015C534(param_1);
    if (iVar11 != 0) {
      fStack_50 = ALBW_AS_F32(param_1[0xb3]);
      iStack_48 = iVar7;
      func_0024D3F0(pfVar10,&fStack_50,&iStack_48,bVar1 ^ 1,1,0);
    }
  }
  else {
    puVar2 = func_00161178(param_1);
    iVar7 = DAT_0015ce48;
    uVar6 = DAT_0015ce44;
    uVar9 = 1;
    if (puVar2 != (undefined4 *)0x0) {
      uVar9 = DAT_0015ce40;
    }
    iVar11 = param_1[0x245];
    if (puVar2 != (undefined4 *)0x0) {
      uVar9 = (uint)*(char *)((int)puVar2 + uVar9);
    }
    iVar3 = 0;
    do {
      if (*(int *)(DAT_0015ce48 + iVar3 * 4) == iVar11) {
        if (-1 < iVar3) {
          uVar4 = iVar3 + (uVar9 ^ 1) * 2 + 2;
          uVar13 = *(undefined4 *)
                    (DAT_0015ce48 +
                    uVar4 * 4 + (uint)((ulonglong)uVar4 * (ulonglong)DAT_0015ce44 >> 0x22) * -0x18);
          goto LAB_0015cd6c;
        }
        break;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 6);
    uVar13 = 0;
LAB_0015cd6c:
    iVar3 = func_0015C534(param_1);
    afStack_40[0] = ALBW_AS_F32(param_1[0xb3]);
    func_0024D32C(afStack_40,iVar11,uVar13,uVar9,iVar3);
    iVar3 = func_0015C534(param_1);
    if (iVar3 != 0) {
      iVar3 = 0;
      do {
        if (*(int *)(iVar7 + iVar3 * 4) == iVar11) {
          if (-1 < iVar3) {
            uVar4 = iVar3 + uVar9 * 2 + 2;
            uVar12 = *(undefined4 *)
                      (iVar7 + uVar4 * 4 +
                               (uint)((ulonglong)uVar4 * (ulonglong)uVar6 >> 0x22) * -0x18);
          }
          break;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < 6);
      iVar7 = func_0015C534(param_1);
      iStack_48 = param_1[0xb3];
      func_0024D32C(&iStack_48,iVar11,uVar12,uVar9 ^ 1,iVar7);
    }
  }
  uVar12 = DAT_0015ce4c;
  param_1[0x24f] = 0x14;
  param_1[0x250] = uVar12;
  param_1[0x24e] = 0;
  return;
}

