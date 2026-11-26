/* compilefix: USA 0050B61C (EU 0050B5F4), the converted stage-2 text taking its two float arguments:
 * the ARM keeps s0 / s1 (vmov.f64 d8, d0) and writes them to the animation entry (+8, +0x10). Its
 * caller 0050B604 passes 0.0 and 1.0; the converted text had dropped both, so the second was 0
 * (BOOT_LOG 182). */
// MAPFIX-INTEGRATED v1
#include "ghidra_types.h"

extern int func_0016898C(int param_1,uint *param_2);
extern undefined4 DAT_0050b6b0;
extern undefined4 DAT_0050b6b4;
extern undefined4 DAT_0050b6b8;

// USA 0050B61C <- EU 0050B5F4 (Ghidra, non-matching)
// MAPFIX: tools/ghidra_name_fixes.json applied (do not apply again)
// GLOBAL DAT_0050b6b0 undefined4
// GLOBAL DAT_0050b6b4 undefined4
// GLOBAL DAT_0050b6b8 undefined4

void func_0050B61C(int param_1,undefined4 param_2,float fparam_0,float fparam_1)

{
  int iVar1;
  uint in_r12;
  _Alignas(8) unsigned char albw_frame[0x80];
  #define auStack_78 ((uint *)(albw_frame + 0x8))
  #define puStack_70 (*(undefined4 * *)(albw_frame + 0x10))
  #define uStack_6c (*(undefined4 *)(albw_frame + 0x14))
  #define uStack_68 (*(undefined4 *)(albw_frame + 0x18))
  #define uStack_64 (*(undefined4 *)(albw_frame + 0x1c))
  #define uStack_60 (*(undefined4 *)(albw_frame + 0x20))
  #define uStack_5c (*(undefined4 *)(albw_frame + 0x24))
  #define uStack_58 (*(uint *)(albw_frame + 0x28))
  #define uStack_24 (*(undefined4 *)(albw_frame + 0x5c))
  #define uStack_20 (*(undefined1 *)(albw_frame + 0x60))
  auStack_78[1] = 3;
  puStack_70 = &uStack_6c;
  uStack_20 = 0;
  uStack_24 = 10;
  auStack_78[0] = 1;
  uStack_68 = DAT_0050b6b4;
  uStack_64 = DAT_0050b6b0;
  uStack_60 = DAT_0050b6b8;
  uStack_5c = DAT_0050b6b0;
  uStack_58 = in_r12 | 0xff;
  uStack_6c = param_2;
  func_0016898C(*(int *)(param_1 + 0x410),auStack_78);
  iVar1 = *(int *)(*(int *)(param_1 + 0x410) + 0x14);
  if (*(float *)(iVar1 + 8) != fparam_0) {
    *(float *)(iVar1 + 8) = fparam_0;
    *(undefined1 *)(iVar1 + 0x26) = 1;
  }
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x410) + 0x14) + 0x10) = ALBW_AS_U32(fparam_1);
  return;
}

