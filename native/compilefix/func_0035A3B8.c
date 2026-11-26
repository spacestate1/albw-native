/* compilefix: USA 0035A3B8, the converted stage-2 text with the animation request of 0016898C restored
 * (BOOT_LOG 172: lost stack stores): EU 35A4F0..35A548; crash entering Lorule field 31 (sand boss) */
#include "ghidra_types.h"

extern int func_0010BAB4(undefined4 param_1);
extern int func_001151F8(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3);
extern int func_0014DF18(int param_1,undefined4 param_2,int param_3,uint param_4,undefined1 param_5, undefined1 param_6);
extern int func_00150E40(undefined4 *param_1,uint *param_2);
extern int func_0016898C(int param_1,uint *param_2);
extern int func_00169608(uint *param_1,uint param_2,int *param_3,int param_4);
extern int func_0016A02C(int param_1,int param_2,int *param_3,int param_4);
extern int func_0016A2FC(undefined4 *param_1,int param_2,undefined4 param_3,int param_4);
extern float func_00491624(float *param_1,uint param_2,uint param_3,uint param_4);
extern undefined4 func_004A7F00(int param_1,int param_2,uint param_3);
extern int func_004CEAF0(int param_1);
extern int func_004ED9C8(int param_1);
extern int func_004EDAB0(int param_1,undefined4 *param_2);
extern int func_004EDAD0(int param_1,uint *param_2);
extern int func_004EDC5C(int param_1,int param_2);
extern int func_004EDC9C(undefined4 *param_1);
extern int DAT_0035a5bc;
extern undefined4 DAT_0035a5c0;
extern int DAT_0035a5d4;
extern undefined4 DAT_0035a5d8;
extern undefined4 DAT_0035a5dc;
extern undefined4 DAT_0035a5e0;
extern int *DAT_0035a600;
extern char s_Actor_BossSandThrough_kcl_0035a5e4[];
extern char s_BossSandThrough_0035a5c4[];
extern char s_cf_0035a5e4[];

// USA 0035A3B8 <- EU 0035A394 (Ghidra, non-matching)
// GLOBAL DAT_0035a5bc int
// GLOBAL DAT_0035a5c0 undefined4
// GLOBAL DAT_0035a5d4 int
// GLOBAL DAT_0035a5d8 undefined4
// GLOBAL DAT_0035a5dc undefined4
// GLOBAL DAT_0035a5e0 undefined4
// GLOBAL DAT_0035a600 int *
// GLOBAL s_cf_0035a5e4 string
// GLOBAL s_BossSandThrough_0035a5c4 string

/* WARNING: Variable defined which should be unmapped: objStack_d0 */

int * func_0035A3B8(undefined4 *param_1,uint *param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  _Alignas(8) unsigned char albw_frame[0xd0];
  #define objStack_d0 ((uint *)(albw_frame + 0x0))
  #define afStack_74 ((float *)(albw_frame + 0x5c))
  #define local_40 (*(int *)(albw_frame + 0x90))
  #define local_3c (*(char * *)(albw_frame + 0x94))
  #define local_38 (*(int *)(albw_frame + 0x98))
  #define local_34 (*(char * *)(albw_frame + 0x9c))
  #define local_30 ((uint *)(albw_frame + 0xa0))
  piVar1 = func_00150E40(param_1,param_2);
  iVar5 = DAT_0035a5bc;
  piVar1[200] = DAT_0035a5bc + 0x54;
  *piVar1 = iVar5;
  piVar1[0x103] = 0;
  piVar7 = piVar1 + 0x103;
  piVar1[0x104] = 0;
  puVar2 = (undefined4 *)func_0010BAB4(0x48);
  puVar3 = (undefined4 *)0x0;
  if (puVar2 != (undefined4 *)0x0) {
    puVar3 = func_004EDC9C(puVar2);
  }
  piVar1[0x105] = (int)puVar3;
  objStack_d0[0] = 0;
  objStack_d0[1] = 0;
  piVar6 = piVar1 + 0x105;
  piVar4 = func_0014DF18(piVar1[0xb4],1,0,0,0,0);
  piVar1[0x103] = (int)piVar4;
  (**(code **)(*piVar4 + 0x10))(piVar4,0x24);
  func_00491624(afStack_74,param_2[7],param_2[8],param_2[9]);
  iVar5 = *piVar7;
  *(uint *)(iVar5 + 0x164) = *(uint *)(iVar5 + 0x164) | 0x40000000;
  func_001151F8((undefined4 *)(iVar5 + 0x80),afStack_74,param_2 + 1);
  iVar5 = *piVar7;
  *(uint *)(iVar5 + 0x164) = *(uint *)(iVar5 + 0x164) | 0x40000000;
  *(uint *)(iVar5 + 0x74) = param_2[4];
  *(uint *)(iVar5 + 0x78) = param_2[5];
  *(uint *)(iVar5 + 0x7c) = param_2[6];
  *(uint *)(*piVar7 + 0x164) = *(uint *)(*piVar7 + 0x164) | 0x90000;
  func_004CEAF0(piVar1[0x103]);
  puVar2 = (undefined4 *)func_0010BAB4(0xa8);
  puVar3 = (undefined4 *)0x0;
  if (puVar2 != (undefined4 *)0x0) {
    puVar3 = func_0016A2FC(puVar2,1,DAT_0035a5c0,1);
  }
  piVar1[0x104] = (int)puVar3;
  iVar5 = DAT_0035a5d4;
  local_34 = s_BossSandThrough_0035a5c4;
  local_38 = DAT_0035a5d4;
  func_00169608((uint *)piVar1[0x104],0,&local_38,*(int *)(piVar1[0xb4] + 0x1c8));
  func_0016A02C(piVar1[0x104],-1,(int *)0xffffffff,piVar1[0x103]);
  objStack_d0[1] = 3;
  objStack_d0[0] = 1;

  /* request {count 1, capacity 3, entries -> +0xC}; entry {anim 0, 0.0, 1.0, -1.0, 1.0, flag -1}; +0x54 = 10, +0x58 = 0 */
  {
    uint32_t *rq = (uint32_t *)objStack_d0;
    rq[0] = 1; rq[1] = 3; rq[2] = (uint32_t)(uintptr_t)(rq + 3); rq[3] = 0;
    rq[4] = 0x00000000u; rq[5] = 0x3F800000u; rq[6] = 0xBF800000u; rq[7] = 0x3F800000u;
    *(uint8_t *)(rq + 8) = 0xFF; rq[0x15] = 10; *(uint8_t *)(rq + 0x16) = 0;
  }
  func_0016898C(piVar1[0x104],objStack_d0);
  local_3c = s_Actor_BossSandThrough_kcl_0035a5e4;
  local_40 = iVar5;
  func_004EDC5C(piVar1[0x105],(int)&local_40);
  *(short *)(*piVar6 + 0x2c) = (short)param_2[0x14];
  local_30[0] = piVar1[0xb3];
  func_004EDAD0(*piVar6,local_30);
  func_004EDAB0(*piVar6,piVar1 + 0xf4);
  func_004ED9C8(*piVar6);
  func_004A7F00(*DAT_0035a600,*piVar6,0);
  return piVar1;
}

