/* compilefix: USA 004FA174 (EU 004FA14C), the converted stage-2 text with the default case of its
 * switch inlined from the ARM; the Vec3 result (s0..s2 on ARM, BOOT_LOG 160l) is also published
 * in albw_s012 (callers read y / z from it) (the fragment "004FA420" Ghidra cut off ran on garbage registers:
 * the shield crashed, BOOT_LOG 144).  Arguments as on the ARM: r3 = the hit record's byte +0x20,
 * then three on the stack. 004FA13C (built from C++) passes them so; the Ghidra callers left r3
 * out, and this text then read that byte as the vector pointer (crash, BOOT_LOG 173): they pass r3
 * now. Confidence: high. */
#include "ghidra_types.h"

extern int func_00115C54(float *param_1,float *param_2,float *param_3);
extern int func_00115C70(float *param_1,float *param_2,float *param_3);
extern int func_00115D70(float *param_1,float *param_2,float fparam_0);
extern float func_00115DC8(float *param_1);
extern int func_004D80A4(float *param_1,uint param_2,float fparam_0);
extern int func_004FA420(void);
extern float DAT_004fa4fc;
extern float DAT_004fa500;
extern int *DAT_004fa504;
extern float DAT_004fa508;
extern float DAT_004fa50c;
extern float DAT_004fa5e8;
float *albw_s012_get(void);   /* s0..s2 of a Vec3 return, per thread (native/runtime/vec3ret.c) */
#define albw_s012 (albw_s012_get())

// USA 004FA174 <- EU 004FA14C (Ghidra, non-matching)
// GLOBAL DAT_004fa4fc float
// GLOBAL DAT_004fa500 float
// GLOBAL DAT_004fa504 int *
// GLOBAL DAT_004fa508 float
// GLOBAL DAT_004fa50c float
// GLOBAL DAT_004fa5e8 float

float func_004FA174(float *param_1,int param_2,int param_3,uint in_r3,float *param_4,int param_5,int param_6)

{
  float *pfVar1;
  int iVar2;
  bool bVar3;
  float fVar4;
  _Alignas(8) unsigned char albw_frame[0x70];
  #define local_68 (*(float *)(albw_frame + 0x8))
  #define fStack_64 (*(float *)(albw_frame + 0xc))
  #define local_60 (*(float *)(albw_frame + 0x10))
  #define local_58 (*(float *)(albw_frame + 0x18))
  #define local_54 (*(float *)(albw_frame + 0x1c))
  #define local_50 (*(float *)(albw_frame + 0x20))
  #define local_4c (*(float *)(albw_frame + 0x24))
  #define local_48 (*(float *)(albw_frame + 0x28))
  #define local_44 (*(float *)(albw_frame + 0x2c))
  #define local_40 (*(float *)(albw_frame + 0x30))
  #define local_3c (*(float *)(albw_frame + 0x34))
  #define local_38 (*(float *)(albw_frame + 0x38))
  #define local_34 (*(float *)(albw_frame + 0x3c))
  #define local_30 (*(float *)(albw_frame + 0x40))
  #define local_2c (*(undefined4 *)(albw_frame + 0x44))
  #define local_28 (*(float *)(albw_frame + 0x48))
  local_58 = DAT_004fa4fc;
  local_54 = DAT_004fa500;
  local_50 = DAT_004fa4fc;
  iVar2 = *DAT_004fa504;
  pfVar1 = *(float **)(iVar2 + 0x1c);
  switch(param_3) {
  case 5:
  case 0xb:
  case 0xd:
  case 0x13:
  case 0x15:
  case 0x16:
  case 0x17:
  case 0x18:
  case 0x19:
  case 0x1a:
  case 0x1b:
  case 0x1c:
    break;
  case 6:
  case 9:
  case 0xc:
  case 0x14:
code_r0x004fa3f8:
    func_00115C70(&local_68,param_1,param_4);
    local_58 = local_68;
    local_50 = local_60;
    local_54 = DAT_004fa4fc;
    func_00115DC8(&local_58);
    break;
  case 7:
  case 8:
  case 10:
  case 0x1d:
    func_00115C70(&local_68,param_1,pfVar1);
    local_58 = local_68;
    local_50 = local_60;
    local_54 = DAT_004fa4fc;
    func_00115DC8(&local_58);
    break;
  case 0xe:
  case 0xf:
  case 0x10:
  case 0x11:
  case 0x12:
  case 0x1e:
    if (param_3 == 0x12) {
      func_004D80A4(&local_48,**(uint **)(iVar2 + 0x24),DAT_004fa500);
      local_44 = DAT_004fa4fc;
      fVar4 = DAT_004fa4fc;
      func_00115C70(&local_30,param_1,pfVar1);
      local_3c = local_30;
      local_34 = local_28;
      local_38 = fVar4;
      func_00115DC8(&local_3c);
      func_00115D70(&local_30,&local_3c,DAT_004fa508);
      local_68 = local_30;
      fStack_64 = ALBW_AS_F32(local_2c);
      local_60 = local_28;
      func_00115C54(&local_30,&local_48,&local_68);
      local_58 = local_30;
      local_54 = ALBW_AS_F32(local_2c);
      local_50 = local_28;
      func_00115DC8(&local_58);
      { albw_s012[0] = local_58; albw_s012[1] = local_54; albw_s012[2] = local_50; return local_58; }
    }
    if (param_5 == 5) {
      if (param_6 == 3) {
        func_004D80A4(&local_3c,**(uint **)(iVar2 + 0x24),DAT_004fa500);
        local_38 = DAT_004fa4fc;
        fVar4 = DAT_004fa4fc;
        func_00115C70(&local_30,param_1,param_4);
        local_48 = local_30;
        local_40 = local_28;
        local_44 = fVar4;
        func_00115DC8(&local_48);
        func_00115D70(&local_30,&local_48,DAT_004fa50c);
        local_68 = local_30;
        fStack_64 = ALBW_AS_F32(local_2c);
        local_60 = local_28;
        func_00115C54(&local_30,&local_3c,&local_68);
        local_58 = local_30;
        local_54 = ALBW_AS_F32(local_2c);
        local_50 = local_28;
        func_00115DC8(&local_58);
        { albw_s012[0] = local_58; albw_s012[1] = local_54; albw_s012[2] = local_50; return local_58; }
      }
    }
    else {
      if (param_5 == 9 || param_5 == 10) {
        func_00115C70(&local_68,param_1,pfVar1);
        local_58 = local_68;
        local_50 = local_60;
        local_54 = DAT_004fa4fc;
        func_00115DC8(&local_58);
        { albw_s012[0] = local_58; albw_s012[1] = local_54; albw_s012[2] = local_50; return local_58; }
      }
      if (param_5 == 0xf) goto code_r0x004fa3f8;
    }
    if (in_r3 == 0xc || in_r3 == 3) {
      bVar3 = false;
      if (*(float *)(param_2 + 0x24) == DAT_004fa4fc) {
        bVar3 = *(float *)(param_2 + 0x2c) == DAT_004fa4fc;
      }
      if (!bVar3) {
        local_38 = *(float *)(param_2 + 0x2c);
        local_40 = *(float *)(param_2 + 0x24);
        local_3c = DAT_004fa4fc;
        fVar4 = DAT_004fa4fc;
        func_00115DC8(&local_40);
        func_00115C70(&local_34,param_1,param_4);
        local_4c = local_34;
        local_44 = ALBW_AS_F32(local_2c);
        local_48 = fVar4;
        func_00115DC8(&local_4c);
        func_00115D70(&local_34,&local_40,DAT_004fa5e8);
        local_68 = local_34;
        fStack_64 = local_30;
        local_60 = ALBW_AS_F32(local_2c);
        func_00115C54(&local_34,&local_4c,&local_68);
        local_58 = local_34;
        local_54 = local_30;
        local_50 = ALBW_AS_F32(local_2c);
        func_00115DC8(&local_58);
        { albw_s012[0] = local_58; albw_s012[1] = local_54; albw_s012[2] = local_50; return local_58; }
      }
      if (in_r3 == 3) {
        fVar4 = DAT_004fa4fc;
        func_00115C70(&local_68,param_1,param_4);
        local_58 = local_68;
        local_50 = local_60;
        local_54 = fVar4;
        func_00115DC8(&local_58);
        { albw_s012[0] = local_58; albw_s012[1] = local_54; albw_s012[2] = local_50; return local_58; }
      }
    }
    func_004D80A4(&local_48,**(uint **)(iVar2 + 0x24),DAT_004fa500);
    local_44 = DAT_004fa4fc;
    fVar4 = DAT_004fa4fc;
    func_00115C70(&local_30,param_1,pfVar1);
    local_3c = local_30;
    local_34 = local_28;
    local_38 = fVar4;
    func_00115DC8(&local_3c);
    func_00115D70(&local_30,&local_3c,DAT_004fa50c);
    local_68 = local_30;
    fStack_64 = ALBW_AS_F32(local_2c);
    local_60 = local_28;
    func_00115C54(&local_30,&local_48,&local_68);
    local_58 = local_30;
    local_54 = ALBW_AS_F32(local_2c);
    local_50 = local_28;
    func_00115DC8(&local_58);
    break;
  default:
    /* EU 4FA3F8..4FA42C (Ghidra split this case off as "004FA420"; it runs on this frame and
     * r4 = param_1, r5 = param_4, the first stack argument): d = *param_1 - *param_4,
     * {d.x, 0, d.z} normalised (BOOT_LOG 144) */
    func_00115C70(&local_68,param_1,param_4);
    local_58 = local_68;
    local_50 = local_60;
    local_54 = DAT_004fa4fc;
    func_00115DC8(&local_58);
    break;
  }
  { albw_s012[0] = local_58; albw_s012[1] = local_54; albw_s012[2] = local_50; return local_58; }
}

