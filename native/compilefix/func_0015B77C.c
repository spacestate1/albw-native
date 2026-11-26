/* compilefix: USA 0015B77C, the converted stage-2 text with z of the hit point
 * (a vector returned in s0..s2 on ARM: BOOT_LOG 178). */
#include "ghidra_types.h"

extern int func_00115C70(float *param_1,float *param_2,float *param_3);
extern int func_001E8500(int param_1,float *param_2,float param_3,float fparam_0);
extern int func_004F68AC();
extern int func_00520FD4(void);
extern float func_0054F774(int param_1,float *param_2,uint param_3,uint *param_4);
extern int func_0068C690(float *param_1);
extern int *DAT_0015b878;
extern int *DAT_0015b87c;
extern float DAT_0015b880;

float *albw_s012_get(void);   /* s0..s2 of a returned vector (native/runtime/vec3ret.c) */

// USA 0015B77C <- EU 0015B780 (Ghidra, non-matching)
// GLOBAL DAT_0015b878 int *
// GLOBAL DAT_0015b87c int *
// GLOBAL DAT_0015b880 float

undefined4 func_0015B77C(int param_1,int param_2,undefined4 param_3,float *param_4)

{
  bool bVar1;
  uint uVar2;
  float *pfVar3;
  int iVar4;
  _Alignas(8) unsigned char albw_frame[0x40];
  #define local_38 (*(float *)(albw_frame + 0x8))
  #define uStack_34 (*(undefined4 *)(albw_frame + 0xc))
  #define uStack_30 (*(undefined4 *)(albw_frame + 0x10))
  #define local_2c (*(float *)(albw_frame + 0x14))
  #define uStack_28 (*(undefined4 *)(albw_frame + 0x18))
  #define uStack_24 (*(undefined4 *)(albw_frame + 0x1c))
  #define local_20 (*(float *)(albw_frame + 0x20))
  #define local_1c (*(undefined4 *)(albw_frame + 0x24))
  if ((((0 < *(short *)(param_1 + 0x508)) && (*(char *)(param_1 + 0x8c0) != '\0')) &&
      (bVar1 = func_00520FD4(), !bVar1)) &&
     (((*DAT_0015b878 != 0 && (*(int *)(*DAT_0015b87c + 0x44) == 0)) &&
      ((iVar4 = *(int *)(*DAT_0015b878 + 0x18), iVar4 != 0 &&
       ((*(ushort *)(param_1 + 0x2e) & 0xff) == 0)))))) {
    pfVar3 = (float *)(param_1 + 0x9b4);
    func_00115C70(&local_2c,(float *)(param_1 + 0x988),pfVar3);
    local_38 = local_2c;
    uStack_34 = uStack_28;
    uStack_30 = uStack_24;
    uVar2 = func_0068C690(&local_38);
    param_4 = (float *)0x0;
    local_20 = func_0054F774((int)pfVar3,pfVar3,uVar2,(uint *)0x0);
    *(float *)(albw_frame + 0x28) = albw_s012_get()[2];
    local_1c = *(undefined4 *)(param_1 + 0xc);
    param_3 = 1;
    func_001E8500(iVar4,&local_20,1,DAT_0015b880);
  }
  return func_004F68AC(param_1,param_2,param_3,param_4);
}

