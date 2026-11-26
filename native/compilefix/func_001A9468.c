/* compilefix: USA 001A9468, the converted stage-2 text with the y of both angle branches and the z of the random branch restored and the vector published
 * (a vector returned in s0..s2 on ARM: BOOT_LOG 178). */
#include "ghidra_types.h"

extern int func_00111A64(uint *param_1);
extern int func_00115C70(float *param_1,float *param_2,float *param_3);
extern int func_004D80A4(float *param_1,uint param_2,float fparam_0);
extern int func_00520FC0(void);
extern int func_0058A7D4(void);
extern int func_0058E2B8(int *param_1);
extern int func_0068C690(float *param_1);
extern int *DAT_001a95f8;
extern float DAT_001a95fc;
extern float DAT_001a9600;
extern undefined4 DAT_001a9604;
extern float DAT_001a9608;
extern float DAT_001a960c;

float *albw_s012_get(void);   /* s0..s2 of a returned vector (native/runtime/vec3ret.c) */

// USA 001A9468 <- EU 001A9468 (Ghidra, non-matching)
// GLOBAL DAT_001a95f8 int *
// GLOBAL DAT_001a95fc float
// GLOBAL DAT_001a9600 float
// GLOBAL DAT_001a9604 undefined4
// GLOBAL DAT_001a9608 float
// GLOBAL DAT_001a960c float

void func_001A9468(int param_1)

{
  float *pfVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  int iVar6;
  uint in_fpscr;
  float fVar7;
  float fVar8;
  undefined4 uVar9;
  float fVar10;
  _Alignas(8) unsigned char albw_frame[0x50];
  #define local_50 (*(float *)(albw_frame + 0x0))
  #define local_4c (*(undefined4 *)(albw_frame + 0x4))
  #define local_44 (*(float *)(albw_frame + 0xc))
  #define iStack_40 (*(int *)(albw_frame + 0x10))
  #define uStack_3c (*(undefined4 *)(albw_frame + 0x14))
  #define local_38 (*(float *)(albw_frame + 0x18))
  #define local_34 (*(int *)(albw_frame + 0x1c))
  #define uStack_30 (*(undefined4 *)(albw_frame + 0x20))
  #define local_2c ((int *)(albw_frame + 0x24))
  iVar6 = **(int **)(*DAT_001a95f8 + 0x24);
  pfVar1 = (float *)func_00520FC0();
  func_00115C70(&local_38,(float *)(param_1 + 0x3d0),pfVar1);
  local_44 = local_38;
  iStack_40 = local_34;
  uStack_3c = uStack_30;
  iVar2 = func_0068C690(&local_44);
  local_2c[0] = iVar6 - iVar2;
  uVar3 = func_0058E2B8(local_2c);
  if ((uVar3 < 0x40000000) && (0x1e < *(int *)(param_1 + 0x8f8) - *(int *)(param_1 + 0x8f4))) {
    fVar8 = DAT_001a95fc;
    fVar10 = DAT_001a9600;
    puVar4 = (uint *)func_0058A7D4();
    uVar3 = func_00111A64(puVar4);
    local_38 = ALBW_AS_F32((iVar6 - (iVar2 + 0xc0000000U)));
    fVar7 = (float)VectorUnsignedToFloat(uVar3,(byte)(in_fpscr >> 0x15) & 3);
    fVar8 = fVar7 * fVar10 * fVar8 + DAT_001a9608;
    uVar3 = func_0058E2B8((int *)&local_38);
    local_34 = iVar6 - (iVar2 + 0x40000000U);
    uVar5 = func_0058E2B8(&local_34);
    if (uVar3 < uVar5) {
      func_004D80A4(&local_50,iVar2 + 0x40000000U,fVar8);
      local_4c = DAT_001a9604;
    }
    else {
      func_004D80A4(&local_50,iVar2 + 0xc0000000U,fVar8);
      local_4c = DAT_001a9604;
    }
  }
  else {
    fVar8 = DAT_001a95fc;
    uVar9 = DAT_001a9604;
    fVar10 = DAT_001a9600;
    puVar4 = (uint *)func_0058A7D4();
    uVar3 = func_00111A64(puVar4);
    fVar7 = (float)VectorUnsignedToFloat(uVar3,(byte)(in_fpscr >> 0x15) & 3);
    local_50 = fVar7 * fVar10 * fVar8 - DAT_001a960c;
    local_4c = uVar9;
    puVar4 = (uint *)func_0058A7D4();
    uVar3 = func_00111A64(puVar4);
    fVar7 = (float)VectorUnsignedToFloat(uVar3,(byte)(in_fpscr >> 0x15) & 3);
    *(float *)(albw_frame + 0x8) = fVar7 * fVar10 * fVar8 - DAT_001a960c;
  }
  { float *albw_v = albw_s012_get(); albw_v[0] = local_50; albw_v[1] = ALBW_AS_F32(local_4c); albw_v[2] = *(float *)(albw_frame + 0x8); }
  return local_50;
}

