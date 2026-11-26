/* compilefix: USA 004F9A2C, the converted stage-2 text with y and z of the returned vectors
 * (a vector returned in s0..s2 on ARM: BOOT_LOG 178). */
#include "ghidra_types.h"

extern int func_0010BAB4(undefined4 param_1);
extern int func_0014EB8C(int param_1,undefined4 param_2,undefined2 *param_3,uint *param_4,undefined2 param_5, undefined4 param_6,undefined2 param_7);
extern int func_004356B4(int *param_1);
extern int func_004EE484(undefined4 *param_1);
extern float func_004F93D8(int param_1,uint param_2);
extern int func_0054D964(int param_1,uint param_2);
extern float func_0054DE3C(int param_1,uint param_2,int param_3);
extern undefined4 DAT_004f9e00;
extern float DAT_004f9e04;
extern int DAT_004f9e08;
extern undefined4 DAT_004f9e0c;

float *albw_s012_get(void);   /* s0..s2 of a returned vector (native/runtime/vec3ret.c) */

// USA 004F9A2C <- EU 004F9A04 (Ghidra, non-matching)
// GLOBAL DAT_004f9e00 undefined4
// GLOBAL DAT_004f9e04 float
// GLOBAL DAT_004f9e08 int
// GLOBAL DAT_004f9e0c undefined4

void func_004F9A2C(int param_1,char *param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint extraout_r1;
  uint extraout_r1_00;
  uint extraout_r1_01;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 *puVar8;
  byte *pbVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  float fVar14;
  undefined4 in_s1;
  undefined4 in_s2;
  _Alignas(8) unsigned char albw_frame[0x30];
  #define local_30 ((uint *)(albw_frame + 0x0))
  uVar1 = (uint)param_2[2];
  uVar10 = (uint)*param_2;
  uVar12 = (uint)param_2[1];
  uVar13 = (uint)param_2[4];
  uVar11 = (uint)param_2[3];
  uVar3 = DAT_004f9e00;
  fVar14 = func_0054DE3C(param_1,uVar10,1);
  *(undefined4 *)(param_1 + 0x44c) = uVar3;
  *(float *)(param_1 + 0x450) = fVar14;
  *(undefined4 *)(param_1 + 0x454) = uVar3;
  fVar14 = func_004F93D8(param_1,uVar10);
  in_s1 = ALBW_AS_U32(albw_s012_get()[1]);
  in_s2 = ALBW_AS_U32(albw_s012_get()[2]);
  *(float *)(param_1 + 0x458) = fVar14;
  *(undefined4 *)(param_1 + 0x45c) = in_s1;
  *(undefined4 *)(param_1 + 0x460) = in_s2;
  uVar7 = extraout_r1;
  if (-1 < (int)uVar11) {
    fVar14 = func_0054DE3C(param_1,uVar11,1);
    *(undefined4 *)(param_1 + 0x47c) = uVar3;
    *(float *)(param_1 + 0x480) = fVar14;
    *(undefined4 *)(param_1 + 0x484) = uVar3;
    fVar14 = func_004F93D8(param_1,uVar11);
    in_s1 = ALBW_AS_U32(albw_s012_get()[1]);
    in_s2 = ALBW_AS_U32(albw_s012_get()[2]);
    *(float *)(param_1 + 0x488) = fVar14;
    *(undefined4 *)(param_1 + 0x48c) = in_s1;
    *(undefined4 *)(param_1 + 0x490) = in_s2;
    uVar7 = extraout_r1_00;
  }
  if (-1 < (int)uVar13) {
    fVar14 = func_0054DE3C(param_1,uVar13,1);
    *(undefined4 *)(param_1 + 0x494) = uVar3;
    *(float *)(param_1 + 0x498) = fVar14;
    *(undefined4 *)(param_1 + 0x49c) = uVar3;
    fVar14 = func_004F93D8(param_1,uVar13);
    in_s1 = ALBW_AS_U32(albw_s012_get()[1]);
    in_s2 = ALBW_AS_U32(albw_s012_get()[2]);
    *(float *)(param_1 + 0x4a0) = fVar14;
    *(undefined4 *)(param_1 + 0x4a4) = in_s1;
    *(undefined4 *)(param_1 + 0x4a8) = in_s2;
    uVar7 = extraout_r1_01;
  }
  if (uVar10 == uVar12) {
    uVar7 = uVar1;
  }
  puVar8 = (undefined4 *)(param_1 + 0x4b8);
  if (uVar10 != uVar12 || uVar10 != uVar7) {
    fVar14 = func_0054DE3C(param_1,uVar12,1);
    *(undefined4 *)(param_1 + 0x464) = uVar3;
    *(float *)(param_1 + 0x468) = fVar14;
    *(undefined4 *)(param_1 + 0x46c) = uVar3;
    fVar14 = func_004F93D8(param_1,uVar12);
    in_s1 = ALBW_AS_U32(albw_s012_get()[1]);
    in_s2 = ALBW_AS_U32(albw_s012_get()[2]);
    *(float *)(param_1 + 0x470) = fVar14;
    *(undefined4 *)(param_1 + 0x474) = in_s1;
    *(undefined4 *)(param_1 + 0x478) = in_s2;
    fVar14 = func_0054DE3C(param_1,uVar1,1);
    *puVar8 = uVar3;
    *(float *)(param_1 + 0x4bc) = fVar14;
    *(undefined4 *)(param_1 + 0x4c0) = uVar3;
    fVar14 = func_004F93D8(param_1,uVar1);
    in_s1 = ALBW_AS_U32(albw_s012_get()[1]);
    in_s2 = ALBW_AS_U32(albw_s012_get()[2]);
  }
  else {
    *puVar8 = *(undefined4 *)(param_1 + 0x44c);
    *(undefined4 *)(param_1 + 0x4bc) = *(undefined4 *)(param_1 + 0x450);
    *(undefined4 *)(param_1 + 0x4c0) = *(undefined4 *)(param_1 + 0x454);
    *(undefined4 *)(param_1 + 0x464) = *puVar8;
    *(undefined4 *)(param_1 + 0x468) = *(undefined4 *)(param_1 + 0x4bc);
    *(undefined4 *)(param_1 + 0x46c) = *(undefined4 *)(param_1 + 0x4c0);
    fVar14 = *(float *)(param_1 + 0x458);
    *(float *)(param_1 + 0x470) = fVar14;
    *(undefined4 *)(param_1 + 0x474) = *(undefined4 *)(param_1 + 0x45c);
    *(undefined4 *)(param_1 + 0x478) = *(undefined4 *)(param_1 + 0x460);
  }
  fVar14 = fVar14 * DAT_004f9e04;
  *(float *)(param_1 + 0x4c8) = fVar14;
  *(float *)(param_1 + 0x4c4) = fVar14;
  *(float *)(param_1 + 0x4bc) = fVar14;
  if (-1 < (int)uVar10) {
    iVar2 = func_0054D964(param_1,uVar10);
    *(int *)(param_1 + 0x424) = iVar2;
  }
  if (-1 < (int)uVar12) {
    iVar2 = func_0054D964(param_1,uVar12);
    *(int *)(param_1 + 0x430) = iVar2;
  }
  if (-1 < (int)uVar11) {
    puVar8 = (undefined4 *)func_0010BAB4(100);
    uVar3 = 0;
    if (puVar8 != (undefined4 *)0x0) {
      uVar3 = func_004EE484(puVar8);
    }
    *(undefined4 *)(param_1 + 0x428) = uVar3;
    iVar2 = func_0054D964(param_1,uVar11);
    *(int *)(param_1 + 0x42c) = iVar2;
  }
  if (-1 < (int)uVar13) {
    iVar2 = func_0054D964(param_1,uVar13);
    *(int *)(param_1 + 0x434) = iVar2;
  }
  iVar2 = *(int *)(param_1 + 0x430);
  if (iVar2 != 0) {
    *(undefined2 *)(iVar2 + 0x28) = 0;
    *(uint *)(iVar2 + 0x2c) = *(uint *)(iVar2 + 0x2c) & 0xffffe0ff;
  }
  iVar2 = *(int *)(param_1 + 0x434);
  if (iVar2 != 0) {
    *(undefined2 *)(iVar2 + 0x28) = 0;
    *(uint *)(iVar2 + 0x2c) = *(uint *)(iVar2 + 0x2c) & 0xffffe0ff;
  }
  if (*(int **)(param_1 + 0x424) != (int *)0x0) {
    func_004356B4(*(int **)(param_1 + 0x424));
  }
  if (*(int **)(param_1 + 0x42c) != (int *)0x0) {
    func_004356B4(*(int **)(param_1 + 0x42c));
  }
  if (*(int **)(param_1 + 0x430) != (int *)0x0) {
    func_004356B4(*(int **)(param_1 + 0x430));
  }
  if (*(int **)(param_1 + 0x434) != (int *)0x0) {
    func_004356B4(*(int **)(param_1 + 0x434));
  }
  uVar3 = DAT_004f9e0c;
  iVar2 = DAT_004f9e08;
  uVar4 = *(undefined4 *)(DAT_004f9e08 + 0x18);
  uVar6 = *(undefined4 *)(DAT_004f9e08 + 0x1c);
  *(int *)(param_1 + 0x518) = param_1;
  *(undefined4 *)(param_1 + 0x51c) = uVar4;
  *(undefined4 *)(param_1 + 0x520) = uVar6;
  uVar4 = *(undefined4 *)(iVar2 + 0x20);
  uVar6 = *(undefined4 *)(iVar2 + 0x24);
  *(int *)(param_1 + 0x528) = param_1;
  *(undefined4 *)(param_1 + 0x52c) = uVar4;
  *(undefined4 *)(param_1 + 0x530) = uVar6;
  uVar4 = *(undefined4 *)(iVar2 + 0x28);
  uVar6 = *(undefined4 *)(iVar2 + 0x2c);
  *(int *)(param_1 + 0x538) = param_1;
  *(undefined4 *)(param_1 + 0x53c) = uVar4;
  *(undefined4 *)(param_1 + 0x540) = uVar6;
  uVar6 = *(undefined4 *)(iVar2 + 0x30);
  uVar4 = *(undefined4 *)(iVar2 + 0x34);
  *(int *)(param_1 + 0x548) = param_1;
  *(undefined4 *)(param_1 + 0x550) = uVar4;
  *(undefined4 *)(param_1 + 0x54c) = uVar6;
  iVar2 = param_1 + 0x618;
  pbVar9 = (byte *)(param_1 + 0x652);
  if (*(int *)(param_1 + 0x424) != 0) {
    local_30[0] = *(uint *)(param_1 + 0x2cc);
    func_0014EB8C(*(int *)(param_1 + 0x420),*(int *)(param_1 + 0x424),
                  *(undefined2 **)(param_1 + 0x3a0),local_30,*(undefined2 *)(param_1 + 0x54),
                  param_1 + 0x514,(short)uVar3);
    *(uint *)(*(int *)(param_1 + 0x424) + 0x2c) = *(uint *)(*(int *)(param_1 + 0x424) + 0x2c) | 8;
    iVar5 = *(int *)(param_1 + 0x420);
    if (iVar5 != 0) {
      uVar7 = (uint)*pbVar9;
      if (uVar7 < 7) {
        if (uVar7 != 0) {
          uVar1 = uVar7 & 1;
          uVar10 = 0;
          if ((*pbVar9 & 1) != 0) {
            do {
              if (*(int *)(iVar2 + uVar10 * 4) == iVar5) goto LAB_004f9e38;
              uVar10 = uVar10 + 1;
            } while (uVar10 < uVar1);
          }
          for (; uVar1 < uVar7; uVar1 = uVar1 + 2) {
            if ((*(int *)(iVar2 + uVar1 * 4) == iVar5) || (*(int *)(iVar2 + uVar1 * 4 + 4) == iVar5)
               ) goto LAB_004f9e38;
          }
        }
        *(int *)(iVar2 + uVar7 * 4) = iVar5;
        *pbVar9 = *pbVar9 + 1;
      }
    }
  }
LAB_004f9e38:
  if (*(int *)(param_1 + 0x42c) != 0) {
    local_30[0] = *(uint *)(param_1 + 0x2cc);
    func_0014EB8C(*(int *)(param_1 + 0x428),*(int *)(param_1 + 0x42c),
                  *(undefined2 **)(param_1 + 0x3a0),local_30,*(undefined2 *)(param_1 + 0x54),
                  param_1 + 0x514,(short)uVar3);
    *(uint *)(*(int *)(param_1 + 0x42c) + 0x2c) = *(uint *)(*(int *)(param_1 + 0x42c) + 0x2c) | 8;
    iVar5 = *(int *)(param_1 + 0x428);
    if (iVar5 != 0) {
      uVar7 = (uint)*pbVar9;
      if (uVar7 < 7) {
        if (uVar7 != 0) {
          uVar1 = uVar7 & 1;
          uVar10 = 0;
          if ((*pbVar9 & 1) != 0) {
            do {
              if (*(int *)(iVar2 + uVar10 * 4) == iVar5) goto LAB_004f9f00;
              uVar10 = uVar10 + 1;
            } while (uVar10 < uVar1);
          }
          for (; uVar1 < uVar7; uVar1 = uVar1 + 2) {
            if ((*(int *)(iVar2 + uVar1 * 4) == iVar5) || (*(int *)(iVar2 + uVar1 * 4 + 4) == iVar5)
               ) goto LAB_004f9f00;
          }
        }
        *(int *)(iVar2 + uVar7 * 4) = iVar5;
        *pbVar9 = *pbVar9 + 1;
      }
    }
  }
LAB_004f9f00:
  *(uint *)(param_1 + 0x59c) = *(uint *)(param_1 + 0x59c) | 0xbc;
  return;
}

