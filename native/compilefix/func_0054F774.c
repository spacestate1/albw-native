/* compilefix: USA 0054F774, the converted stage-2 text with the whole hit point published
 * (a vector returned in s0..s2 on ARM: BOOT_LOG 178). */
#include "ghidra_types.h"

extern int func_00115C54(float *param_1,float *param_2,float *param_3);
extern int func_00115D70(float *param_1,float *param_2,float fparam_0);
extern int func_0032EF74(float *param_1,float *param_2,float *param_3);
extern int func_004D80A4(float *param_1,uint param_2,float fparam_0);
extern int func_0054FF8C(int param_1,float *param_2,int param_3);
extern float func_005500C0(float *param_1,int param_2);
extern float DAT_0054f980;
extern uint DAT_0054f984;
extern float DAT_0054f988;
extern float DAT_0054f98c;

float *albw_s012_get(void);   /* s0..s2 of a returned vector (native/runtime/vec3ret.c) */

// USA 0054F774 <- EU 0054F74C (Ghidra, non-matching)
// GLOBAL DAT_0054f980 float
// GLOBAL DAT_0054f984 uint
// GLOBAL DAT_0054f988 float
// GLOBAL DAT_0054f98c float

float func_0054F774(int param_1,float *param_2,uint param_3,uint *param_4)

{
  int iVar1;
  uint uVar2;
  float *pfVar3;
  float fVar4;
  float fVar5;
  ulonglong uVar6;
  _Alignas(8) unsigned char albw_frame[0x140];
  #define local_138 (*(float *)(albw_frame + 0x8))
  #define uStack_134 (*(undefined4 *)(albw_frame + 0xc))
  #define uStack_130 (*(undefined4 *)(albw_frame + 0x10))
  #define local_124 (*(float *)(albw_frame + 0x1c))
  #define fStack_120 (*(float *)(albw_frame + 0x20))
  #define fStack_11c (*(float *)(albw_frame + 0x24))
  #define local_118 (*(float *)(albw_frame + 0x28))
  #define uStack_114 (*(undefined4 *)(albw_frame + 0x2c))
  #define uStack_110 (*(undefined4 *)(albw_frame + 0x30))
  #define local_f0 (*(float *)(albw_frame + 0x50))
  #define uStack_ec (*(undefined4 *)(albw_frame + 0x54))
  #define uStack_e8 (*(undefined4 *)(albw_frame + 0x58))
  #define afStack_e0 ((float *)(albw_frame + 0x60))
  #define afStack_d4 ((float *)(albw_frame + 0x6c))
  #define local_b8 ((float *)(albw_frame + 0x88))
  #define afStack_90 ((float *)(albw_frame + 0xb0))
  #define fStack_68 (*(float *)(albw_frame + 0xd8))
  #define local_64 (*(uint *)(albw_frame + 0xdc))
  #define afStack_50 ((float *)(albw_frame + 0xf0))
  #define afStack_44 ((float *)(albw_frame + 0xfc))
  local_124 = *param_2;
  fStack_120 = param_2[1];
  fStack_11c = param_2[2];
  func_004D80A4(&fStack_68,param_3,DAT_0054f980);
  uVar6 = (ulonglong)DAT_0054f984;
  local_64 = DAT_0054f984;
  func_00115D70(&local_118,&fStack_68,DAT_0054f988);
  local_138 = local_118;
  uStack_134 = uStack_114;
  uStack_130 = uStack_110;
  func_00115C54(&local_124,&local_124,&local_138);
  func_00115D70(&local_118,&fStack_68,DAT_0054f98c);
  local_138 = local_118;
  uStack_134 = uStack_114;
  uStack_130 = uStack_110;
  func_00115C54(&local_118,&local_124,&local_138);
  uVar2 = 0;
  local_f0 = local_118;
  uStack_ec = uStack_114;
  uStack_e8 = uStack_110;
  if (0 < *(int *)(param_1 + 0xc)) {
    do {
      pfVar3 = (float *)(param_1 + 0x10);
      if (uVar2 < 0x14) {
        pfVar3 = pfVar3 + uVar2 * 0xd;
      }
      func_0032EF74(afStack_50,&local_124,&local_f0);
      func_0032EF74(afStack_e0,pfVar3,pfVar3 + 3);
      func_0032EF74(&local_118,afStack_50,afStack_44);
      func_0032EF74(local_b8,afStack_50,afStack_e0);
      func_0032EF74(afStack_90,afStack_50,afStack_d4);
      fVar4 = func_005500C0(&local_118,local_b8);
      fVar5 = func_005500C0(&local_118,afStack_90);
      if (fVar4 * fVar5 <= ALBW_AS_F32(uVar6)) {
        func_0032EF74(&local_118,afStack_e0,afStack_d4);
        func_0032EF74(local_b8,afStack_e0,afStack_50);
        func_0032EF74(afStack_90,afStack_e0,afStack_44);
        fVar4 = func_005500C0(&local_118,local_b8);
        fVar5 = func_005500C0(&local_118,afStack_90);
        if (fVar4 * fVar5 <= ALBW_AS_F32(uVar6)) {
          func_0032EF74(&local_118,&local_124,&local_f0);
          func_0032EF74(afStack_e0,pfVar3,pfVar3 + 3);
          iVar1 = func_0054FF8C((int)&local_118,local_b8,(int)afStack_e0);
          if (iVar1 != 0) {
            pfVar3 = local_b8;
            if (param_4 != (uint *)0x0) {
              *param_4 = uVar2;
            }
            goto LAB_0054f958;
          }
        }
      }
      uVar2 = uVar2 + 1;
    } while ((int)uVar2 < *(int *)(param_1 + 0xc));
  }
  pfVar3 = (float *)(param_1 + 0x28);
LAB_0054f958:
  { float *albw_v = albw_s012_get(); albw_v[0] = pfVar3[0]; albw_v[1] = pfVar3[1]; albw_v[2] = pfVar3[2]; }
  return *pfVar3;
}

