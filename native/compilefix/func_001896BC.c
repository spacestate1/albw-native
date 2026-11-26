/* compilefix: USA 001896BC, the converted stage-2 text with y and z of the returned vector
 * (a vector returned in s0..s2 on ARM: BOOT_LOG 178). */
#include "ghidra_types.h"

extern int func_00115C54(float *param_1,float *param_2,float *param_3);
extern int func_001507A8(int param_1,int param_2);
extern int func_00187F18(int param_1,int param_2);
extern int func_004A1B9C(int *param_1,int param_2,uint *param_3);
extern int func_00520F54(int param_1,float *param_2,undefined4 param_3);
extern int func_0052FBA0(int param_1,uint param_2);
extern float func_005445F8(int param_1);
extern int func_00588BE4(int param_1);
extern int func_00659544(undefined4 *param_1,undefined1 param_2);
extern int *DAT_0018991c;
extern int *DAT_00189920;
extern int *DAT_00189924;
extern int *DAT_00189928;
extern int *DAT_0018992c;
extern int *DAT_00189930;
extern int *DAT_00189934;
extern int *DAT_00189938;
extern int *DAT_0018993c;
extern int *DAT_00189940;
extern char s_fff_ff__PlopWaterFall_00189904[];

float *albw_s012_get(void);   /* s0..s2 of a returned vector (native/runtime/vec3ret.c) */

// USA 001896BC <- EU 001896BC (Ghidra, non-matching)
// GLOBAL DAT_0018991c int *
// GLOBAL DAT_00189920 int *
// GLOBAL DAT_00189924 int *
// GLOBAL DAT_00189928 int *
// GLOBAL DAT_0018992c int *
// GLOBAL DAT_00189930 int *
// GLOBAL DAT_00189934 int *
// GLOBAL DAT_00189938 int *
// GLOBAL DAT_0018993c int *
// GLOBAL DAT_00189940 int *

undefined4 func_001896BC(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  float fVar5;
  undefined4 in_s1;
  undefined4 in_s2;
  _Alignas(8) unsigned char albw_frame[0x20];
  #define aiStack_20 ((int *)(albw_frame + 0x0))
  uVar4 = *(ushort *)(param_2 + 0x20) & 0x7e0;
  uVar1 = uVar4 >> 5;
  if ((uVar1 != 0x13 && uVar1 != 0x14) && uVar1 != 0x12) {
    if ((*(ushort *)(param_2 + 0x20) & 0x1f) != 7) {
LAB_00189778:
      iVar2 = func_00187F18(param_1,param_2);
      if (iVar2 != 0) {
        return 1;
      }
      iVar2 = func_0052FBA0(*DAT_0018991c + 0x3dbbc,*(uint *)(param_2 + 0x28));
      if (iVar2 != 0) {
        iVar3 = func_00588BE4(iVar2);
        if (((((iVar3 == *DAT_00189920) || (iVar3 = func_00588BE4(iVar2), iVar3 == *DAT_00189924))
             || (iVar3 = func_00588BE4(iVar2), iVar3 == *DAT_00189928)) ||
            ((iVar3 = func_00588BE4(iVar2), iVar3 == *DAT_0018992c ||
             (iVar3 = func_00588BE4(iVar2), iVar3 == *DAT_00189930)))) ||
           ((iVar3 = func_00588BE4(iVar2), iVar3 == *DAT_00189934 ||
            ((iVar3 = func_00588BE4(iVar2), iVar3 == *DAT_00189938 ||
             (iVar3 = func_00588BE4(iVar2), iVar3 == *DAT_0018993c)))))) {
          *(undefined1 *)(param_1 + 0x701) = 1;
          func_00520F54(iVar2,(float *)(param_1 + 0x558),param_1 + 0x3d0);
        }
        else {
          iVar3 = func_00588BE4(iVar2);
          if (iVar3 == *DAT_00189940) {
            *(undefined1 *)(param_1 + 0x701) = 1;
            fVar5 = func_005445F8(iVar2);
            in_s1 = ALBW_AS_U32(albw_s012_get()[1]);
            in_s2 = ALBW_AS_U32(albw_s012_get()[2]);
            *(float *)(param_1 + 0x558) = fVar5;
            *(undefined4 *)(param_1 + 0x55c) = in_s1;
            *(undefined4 *)(param_1 + 0x560) = in_s2;
          }
        }
      }
      func_00115C54((float *)(param_1 + 0x54c),(float *)(param_1 + 0x54c),(float *)(param_2 + 4));
      *(undefined4 *)(param_1 + 0x680) = *(undefined4 *)(param_2 + 4);
      *(undefined4 *)(param_1 + 0x684) = *(undefined4 *)(param_2 + 8);
      *(undefined4 *)(param_1 + 0x688) = *(undefined4 *)(param_2 + 0xc);
      func_001507A8(param_1,param_2);
      return 1;
    }
    if (uVar4 == 0xc0) {
      if ((int)(*(undefined4 *)((char *)&s_fff_ff__PlopWaterFall_00189904 + 0)) < *(int *)(param_2 + 8)) {
        func_00659544((undefined4 *)(param_1 + 0x4fc),0xb);
      }
    }
    else {
      if ((uVar1 != 0xc) || ((int)(*(undefined4 *)((char *)&s_fff_ff__PlopWaterFall_00189904 + 4)) <= *(int *)(param_2 + 8)))
      goto LAB_00189778;
      if (*(char *)(param_1 + 0x702) == '\0') {
        if (*(int *)(param_1 + 0x344) != 0) {
          func_004A1B9C(aiStack_20,*(int *)(param_1 + 0x344),
                        (uint *)(s_fff_ff__PlopWaterFall_00189904 + 8));
        }
        *(undefined1 *)(param_1 + 0x702) = 1;
      }
    }
  }
  return 0;
}

