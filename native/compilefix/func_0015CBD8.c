/* compilefix: USA 0015CBD8, the converted stage-2 text with y and z of the returned direction
 * (a vector returned in s0..s2 on ARM: BOOT_LOG 178). */
#include "ghidra_types.h"

extern int func_0015C534(undefined4 *param_1);
extern int func_00161178(undefined4 *param_1);
extern int func_0024D32C(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5 );
extern int func_0024D3F0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,int param_4, int param_5,undefined2 param_6);
extern float func_0032EF0C(float *param_1,float *param_2);
extern int func_00520FC0(void);
extern int func_0054FAC0(int param_1,uint param_2);
extern int func_0054FBC4(int param_1,float *param_2,float *param_3);
extern int func_00550078(float *param_1,float *param_2);
extern uint DAT_0015ce40;
extern uint DAT_0015ce44;
extern int DAT_0015ce48;
extern undefined4 DAT_0015ce4c;

float *albw_s012_get(void);   /* s0..s2 of a returned vector (native/runtime/vec3ret.c) */

// USA 0015CBD8 <- EU 0015CBDC (Ghidra, non-matching)
// GLOBAL DAT_0015ce40 uint
// GLOBAL DAT_0015ce44 uint
// GLOBAL DAT_0015ce48 int
// GLOBAL DAT_0015ce4c undefined4

/* WARNING: Variable defined which should be unmapped: objStack_58 */

void func_0015CBD8(undefined4 *param_1)

{
  bool bVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  float *pfVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  float *pfVar9;
  int iVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  float in_s2;
  _Alignas(8) unsigned char albw_frame[0x60];
  #define objStack_58 ((uint *)(albw_frame + 0x8))
  #define local_50 (*(float *)(albw_frame + 0x10))
  #define local_4c (*(float *)(albw_frame + 0x14))
  #define local_48 (*(int *)(albw_frame + 0x18))
  #define local_44 (*(undefined4 *)(albw_frame + 0x1c))
  #define local_40 ((float *)(albw_frame + 0x20))
  #define local_34 (*(float *)(albw_frame + 0x2c))
  uVar11 = 0;
  if ((*(ushort *)((int)param_1 + 0x2e) & 0xff) == 0) {
    pfVar9 = (float *)(param_1 + 0x26d);
    pfVar5 = (float *)func_00520FC0();
    objStack_58[0] = param_1[0xf4];
    objStack_58[1] = param_1[0xf5];
    local_50 = ALBW_AS_F32(param_1[0xf6]);
    local_4c = *pfVar9;
    local_48 = param_1[0x26e];
    local_44 = param_1[0x26f];
    local_40[0] = func_0032EF0C((float *)(param_1 + 0xf4),pfVar9);
    local_40[1] = albw_s012_get()[1];
    local_40[2] = albw_s012_get()[2];
    in_s2 = local_40[2];
    local_34 = -(local_40[0] * ALBW_AS_F32(objStack_58[0])) + -(in_s2 * local_50);
    bVar1 = func_00550078((float *)objStack_58,pfVar5);
    uVar6 = func_0054FBC4((int)pfVar9,(float *)(param_1 + 0xf4),(float *)0x0);
    iVar7 = func_0054FAC0((int)pfVar9,uVar6);
    local_48 = iVar7 + -0x80000000;
    local_44 = param_1[0xb3];
    objStack_58[1] = 0;
    objStack_58[0] = 1;
    func_0024D3F0(pfVar9,&local_44,&local_48,bVar1 ^ 1,1,0);
    iVar10 = func_0015C534(param_1);
    if (iVar10 != 0) {
      local_50 = ALBW_AS_F32(param_1[0xb3]);
      objStack_58[1] = 0;
      objStack_58[0] = 1;
      local_48 = iVar7;
      func_0024D3F0(pfVar9,&local_50,&local_48,bVar1 ^ 1,1,0);
    }
  }
  else {
    puVar2 = func_00161178(param_1);
    iVar7 = DAT_0015ce48;
    uVar6 = DAT_0015ce44;
    uVar8 = 1;
    if (puVar2 != (undefined4 *)0x0) {
      uVar8 = DAT_0015ce40;
    }
    iVar10 = param_1[0x245];
    if (puVar2 != (undefined4 *)0x0) {
      uVar8 = (uint)*(char *)((int)puVar2 + uVar8);
    }
    iVar3 = 0;
    do {
      if (*(int *)(DAT_0015ce48 + iVar3 * 4) == iVar10) {
        if (-1 < iVar3) {
          uVar4 = iVar3 + (uVar8 ^ 1) * 2 + 2;
          uVar12 = *(undefined4 *)
                    (DAT_0015ce48 +
                    uVar4 * 4 + (uint)((ulonglong)uVar4 * (ulonglong)DAT_0015ce44 >> 0x22) * -0x18);
          goto LAB_0015cd6c;
        }
        break;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 6);
    uVar12 = 0;
LAB_0015cd6c:
    objStack_58[0] = func_0015C534(param_1);
    local_40[0] = ALBW_AS_F32(param_1[0xb3]);
    func_0024D32C(local_40,iVar10,uVar12,uVar8,objStack_58[0]);
    iVar3 = func_0015C534(param_1);
    if (iVar3 != 0) {
      iVar3 = 0;
      do {
        if (*(int *)(iVar7 + iVar3 * 4) == iVar10) {
          if (-1 < iVar3) {
            uVar4 = iVar3 + uVar8 * 2 + 2;
            uVar11 = *(undefined4 *)
                      (iVar7 + uVar4 * 4 +
                               (uint)((ulonglong)uVar4 * (ulonglong)uVar6 >> 0x22) * -0x18);
          }
          break;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < 6);
      objStack_58[0] = func_0015C534(param_1);
      local_48 = param_1[0xb3];
      func_0024D32C(&local_48,iVar10,uVar11,uVar8 ^ 1,objStack_58[0]);
    }
  }
  uVar11 = DAT_0015ce4c;
  param_1[0x24f] = 0x14;
  param_1[0x250] = uVar11;
  param_1[0x24e] = 0;
  return;
}

