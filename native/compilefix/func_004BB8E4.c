/* compilefix: USA 004BB8E4, the converted stage-2 text with y and z of the returned position
 * (a vector returned in s0..s2 on ARM: BOOT_LOG 178). */
#include "ghidra_types.h"

extern int func_0043625C(int *param_1,undefined4 *param_2);
extern float func_004BBB88(int param_1);
extern float func_004D8AEC(float *param_1,uint param_2,float *param_3);
extern int func_004ED9C8(int param_1);
extern int func_00588BE4(int param_1);
extern int *DAT_004bba2c;
extern float DAT_004bba30;
extern float DAT_004bba34;

float *albw_s012_get(void);   /* s0..s2 of a returned vector (native/runtime/vec3ret.c) */

// USA 004BB8E4 <- EU 004BB8BC (Ghidra, non-matching)
// GLOBAL DAT_004bba2c int *
// GLOBAL DAT_004bba30 float
// GLOBAL DAT_004bba34 float

undefined4 func_004BB8E4(int param_1)

{
  char cVar1;
  int iVar2;
  bool bVar3;
  float fVar4;
  float in_s1;
  float in_s2;
  
  if (*(char *)(param_1 + 0x448) == '\0') {
    bVar3 = *(char *)(param_1 + 0x44a) != '\x01';
    cVar1 = '\x01';
    if (bVar3) {
      cVar1 = *(char *)(param_1 + 0x44c);
    }
    if (!bVar3 || cVar1 == '\x01') {
      return 0;
    }
  }
  iVar2 = func_00588BE4(param_1);
  fVar4 = DAT_004bba30;
  if (iVar2 != *DAT_004bba2c) {
    return 0;
  }
  if (*(char *)(param_1 + 0x448) == '\x01') {
    if (0x3b < *(byte *)(param_1 + 0x449)) {
      *(undefined1 *)(param_1 + 0x448) = 2;
      *(undefined1 *)(param_1 + 0x449) = 0;
      fVar4 = func_004BBB88(param_1);
      in_s1 = albw_s012_get()[1];
      in_s2 = albw_s012_get()[2];
      in_s1 = in_s1 - DAT_004bba34;
      *(float *)(param_1 + 0x3d0) = fVar4;
      *(float *)(param_1 + 0x3d4) = in_s1;
      *(float *)(param_1 + 0x3d8) = in_s2;
      goto LAB_004bb9f0;
    }
    *(char *)(param_1 + 0x449) = *(byte *)(param_1 + 0x449) + 1;
    fVar4 = *(float *)(param_1 + 0x3d4) - fVar4;
  }
  else {
    if (*(char *)(param_1 + 0x448) != '\x02') {
      fVar4 = func_004BBB88(param_1);
      in_s1 = albw_s012_get()[1];
      in_s2 = albw_s012_get()[2];
      bVar3 = false;
      if (fVar4 == *(float *)(param_1 + 0x3d0)) {
        bVar3 = in_s2 == *(float *)(param_1 + 0x3d8);
      }
      if (!bVar3) {
        if (*(char *)(param_1 + 0x44f) != '\x01') {
          return 0;
        }
        *(undefined1 *)(param_1 + 0x44f) = 0;
        *(undefined1 *)(param_1 + 0x448) = 1;
        *(undefined1 *)(param_1 + 0x449) = 0;
        return 0;
      }
      *(undefined1 *)(param_1 + 0x44f) = 0;
      return 0;
    }
    if (0x3b < *(byte *)(param_1 + 0x449)) {
      *(undefined1 *)(param_1 + 0x448) = 0;
      fVar4 = func_004BBB88(param_1);
      in_s1 = albw_s012_get()[1];
      in_s2 = albw_s012_get()[2];
      *(float *)(param_1 + 0x3d0) = fVar4;
      *(float *)(param_1 + 0x3d4) = in_s1;
      *(float *)(param_1 + 0x3d8) = in_s2;
      goto LAB_004bb9f0;
    }
    *(char *)(param_1 + 0x449) = *(byte *)(param_1 + 0x449) + 1;
    fVar4 = *(float *)(param_1 + 0x3d4) + fVar4;
  }
  *(float *)(param_1 + 0x3d4) = fVar4;
LAB_004bb9f0:
  iVar2 = *(int *)(param_1 + 0x43c);
  *(uint *)(iVar2 + 0x164) = *(uint *)(iVar2 + 0x164) | 0x40000000;
  func_004D8AEC((float *)(iVar2 + 0x80),*(uint *)(param_1 + 1000),(float *)(param_1 + 0x3d0));
  func_0043625C(*(int **)(*(int *)(param_1 + 0x444) + 0x14),(undefined4 *)(param_1 + 0x3d0));
  return func_004ED9C8(*(int *)(param_1 + 0x444));
}

