/* compilefix: USA 0054F764, the converted stage-2 text with the whole hit point published
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

// USA 0054F764 <- EU 0054F73C (Ghidra, non-matching)
// GLOBAL DAT_0054f980 float
// GLOBAL DAT_0054f984 uint
// GLOBAL DAT_0054f988 float
// GLOBAL DAT_0054f98c float

float func_0054F764(undefined4 *param_1,uint param_2,uint *param_3)

{
  int iVar1;
  float *pfVar2;
  uint uVar3;
  float fVar4;
  float fVar5;
  ulonglong uVar6;
  _Alignas(8) unsigned char albw_frame[0x140];
  #define fStack_138 (*(float *)(albw_frame + 0x8))
  #define uStack_134 (*(undefined4 *)(albw_frame + 0xc))
  #define uStack_130 (*(undefined4 *)(albw_frame + 0x10))
  #define fStack_124 (*(float *)(albw_frame + 0x1c))
  #define uStack_120 (*(undefined4 *)(albw_frame + 0x20))
  #define uStack_11c (*(undefined4 *)(albw_frame + 0x24))
  #define fStack_118 (*(float *)(albw_frame + 0x28))
  #define uStack_114 (*(undefined4 *)(albw_frame + 0x2c))
  #define uStack_110 (*(undefined4 *)(albw_frame + 0x30))
  #define fStack_f0 (*(float *)(albw_frame + 0x50))
  #define uStack_ec (*(undefined4 *)(albw_frame + 0x54))
  #define uStack_e8 (*(undefined4 *)(albw_frame + 0x58))
  #define afStack_e0 ((float *)(albw_frame + 0x60))
  #define afStack_d4 ((float *)(albw_frame + 0x6c))
  #define afStack_b8 ((float *)(albw_frame + 0x88))
  #define afStack_90 ((float *)(albw_frame + 0xb0))
  #define fStack_68 (*(float *)(albw_frame + 0xd8))
  #define uStack_64 (*(uint *)(albw_frame + 0xdc))
  #define afStack_50 ((float *)(albw_frame + 0xf0))
  #define afStack_44 ((float *)(albw_frame + 0xfc))
  fStack_124 = ALBW_AS_F32(*param_1);
  uStack_120 = param_1[1];
  uStack_11c = param_1[2];
  func_004D80A4(&fStack_68,param_2,DAT_0054f980);
  uVar6 = (ulonglong)DAT_0054f984;
  uStack_64 = DAT_0054f984;
  func_00115D70(&fStack_118,&fStack_68,DAT_0054f988);
  fStack_138 = fStack_118;
  uStack_134 = uStack_114;
  uStack_130 = uStack_110;
  func_00115C54(&fStack_124,&fStack_124,&fStack_138);
  func_00115D70(&fStack_118,&fStack_68,DAT_0054f98c);
  fStack_138 = fStack_118;
  uStack_134 = uStack_114;
  uStack_130 = uStack_110;
  func_00115C54(&fStack_118,&fStack_124,&fStack_138);
  uVar3 = 0;
  fStack_f0 = fStack_118;
  uStack_ec = uStack_114;
  uStack_e8 = uStack_110;
  if (0 < (int)param_1[3]) {
    do {
      pfVar2 = (float *)(param_1 + 4);
      if (uVar3 < 0x14) {
        pfVar2 = pfVar2 + uVar3 * 0xd;
      }
      func_0032EF74(afStack_50,&fStack_124,&fStack_f0);
      func_0032EF74(afStack_e0,pfVar2,pfVar2 + 3);
      func_0032EF74(&fStack_118,afStack_50,afStack_44);
      func_0032EF74(afStack_b8,afStack_50,afStack_e0);
      func_0032EF74(afStack_90,afStack_50,afStack_d4);
      fVar4 = func_005500C0(&fStack_118,afStack_b8);
      fVar5 = func_005500C0(&fStack_118,afStack_90);
      if (fVar4 * fVar5 <= ALBW_AS_F32(uVar6)) {
        func_0032EF74(&fStack_118,afStack_e0,afStack_d4);
        func_0032EF74(afStack_b8,afStack_e0,afStack_50);
        func_0032EF74(afStack_90,afStack_e0,afStack_44);
        fVar4 = func_005500C0(&fStack_118,afStack_b8);
        fVar5 = func_005500C0(&fStack_118,afStack_90);
        if (fVar4 * fVar5 <= ALBW_AS_F32(uVar6)) {
          func_0032EF74(&fStack_118,&fStack_124,&fStack_f0);
          func_0032EF74(afStack_e0,pfVar2,pfVar2 + 3);
          iVar1 = func_0054FF8C((int)&fStack_118,afStack_b8,(int)afStack_e0);
          if (iVar1 != 0) {
            pfVar2 = afStack_b8;
            if (param_3 != (uint *)0x0) {
              *param_3 = uVar3;
            }
            goto LAB_0054f958;
          }
        }
      }
      uVar3 = uVar3 + 1;
    } while ((int)uVar3 < (int)param_1[3]);
  }
  pfVar2 = (float *)(param_1 + 10);
LAB_0054f958:
  { float *albw_v = albw_s012_get(); albw_v[0] = pfVar2[0]; albw_v[1] = pfVar2[1]; albw_v[2] = pfVar2[2]; }
  return *pfVar2;
}

