/* compilefix: USA 00548CC8, the converted stage-2 text with y and z of the hit point
 * (a vector returned in s0..s2 on ARM: BOOT_LOG 178). */
#include "ghidra_types.h"

extern int func_00115C70(float *param_1,float *param_2,float *param_3);
extern float func_00115DC8(float *param_1);
extern int func_004D7F70(float *param_1,uint param_2);
extern float func_0054F764(undefined4 *param_1,uint param_2,uint *param_3);
extern int func_0054FA10(int param_1,uint param_2);
extern int func_0068C690(float *param_1);
extern undefined4 DAT_00548e08;
extern int *DAT_00548e0c;
extern int DAT_00548e10;
extern float DAT_00548e14;

float *albw_s012_get(void);   /* s0..s2 of a returned vector (native/runtime/vec3ret.c) */

// USA 00548CC8 <- EU 00548CA0 (Ghidra, non-matching)
// GLOBAL DAT_00548e08 undefined4
// GLOBAL DAT_00548e0c int *
// GLOBAL DAT_00548e10 int
// GLOBAL DAT_00548e14 float

undefined4 func_00548CC8(int param_1,undefined4 *param_2,undefined4 *param_3,float *param_4)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  float *pfVar4;
  float fVar5;
  undefined4 in_s1;
  undefined4 in_s2;
  _Alignas(8) unsigned char albw_frame[0x50];
  #define local_50 (*(float *)(albw_frame + 0x0))
  #define local_4c (*(undefined4 *)(albw_frame + 0x4))
  #define uStack_48 (*(undefined4 *)(albw_frame + 0x8))
  #define local_44 (*(uint *)(albw_frame + 0xc))
  #define local_40 (*(float *)(albw_frame + 0x10))
  #define local_3c (*(undefined4 *)(albw_frame + 0x14))
  #define local_38 (*(undefined4 *)(albw_frame + 0x18))
  #define local_2c ((float *)(albw_frame + 0x24))
  #define local_24 (*(undefined4 *)(albw_frame + 0x2c))
  pfVar4 = (float *)(param_1 + 0xe30);
  local_50 = *pfVar4;
  uStack_48 = *(undefined4 *)(param_1 + 0xe38);
  cVar1 = *(char *)(param_1 + 0xe2c);
  local_4c = *(undefined4 *)(param_1 + 0xde0);
  func_00115C70(local_2c,(float *)(param_1 + 0xddc),&local_50);
  local_40 = local_2c[0];
  local_38 = local_24;
  local_3c = DAT_00548e08;
  func_00115DC8(&local_40);
  if (*(char *)(param_1 + 0xe2c) == '\0') {
    func_004D7F70(&local_40,*(uint *)(DAT_00548e10 + 100));
  }
  else {
    func_004D7F70(&local_40,-*DAT_00548e0c);
  }
  iVar2 = func_0068C690(&local_40);
  local_44 = 0;
  fVar5 = func_0054F764(pfVar4,iVar2,&local_44);
  in_s1 = ALBW_AS_U32(albw_s012_get()[1]);
  in_s2 = ALBW_AS_U32(albw_s012_get()[2]);
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = ALBW_AS_U32(fVar5);
    param_2[1] = in_s1;
    param_2[2] = in_s2;
    param_2[1] = ALBW_AS_U32(*(float *)(param_1 + 0xde0) + DAT_00548e14);
  }
  if (param_3 != (undefined4 *)0x0) {
    puVar3 = func_0054FA10((int)pfVar4,local_44);
    *param_3 = *puVar3;
    param_3[1] = puVar3[1];
    param_3[2] = puVar3[2];
  }
  if (param_4 != (float *)0x0) {
    pfVar4 = (float *)func_0054FA10((int)pfVar4,local_44);
    *param_4 = *pfVar4;
    param_4[1] = pfVar4[1];
    param_4[2] = pfVar4[2];
    if (cVar1 == '\0') {
      return func_004D7F70(param_4,0xc0000000);
    }
    func_004D7F70(param_4,0x40000000);
  }
  return 0;
}

