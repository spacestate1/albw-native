/* compilefix: USA 00670D14 (EU 00670CEC), the converted stage-2 text.
 * Fixed (BOOT_LOG 184): the ARM copies this word between a float and an integer (no vcvt), which the
 * converted text wrote as a conversion of the value. */
#include "ghidra_types.h"

extern undefined8 func_00110D44(undefined4 *param_1,byte *param_2,uint param_3);
extern undefined8 func_00114608(uint param_1,uint param_2);
extern float func_00115154(float *param_1,float *param_2,uint param_3);
extern int func_00115C54(float *param_1,float *param_2,float *param_3);
extern int func_00115C70(float *param_1,float *param_2,float *param_3);
extern int func_00115D70(float *param_1,float *param_2,float fparam_0);
extern int func_0034DC88(int param_1,float *param_2,int param_3);
extern int func_0034E4B0(int param_1,float *param_2,int param_3);
extern float func_0034EE0C(undefined4 param_1,float *param_2,float *param_3,float *param_4,float *param_5);
extern int func_004904CC(float fparam_0,float fparam_1);
extern int func_004A8030(int param_1,int *param_2,uint param_3);
extern int func_004A9F98(int param_1,uint *param_2,uint param_3,float fparam_0,float fparam_1);
extern int func_004AACA0(int param_1,undefined4 *param_2,uint param_3,undefined4 param_4);
extern float func_004D7FBC(float *param_1,float *param_2,uint param_3,uint param_4,float fparam_0);
extern int func_004ED868(void);
extern int func_0052E94C(int param_1,int param_2);
extern float func_00554804(int param_1,int param_2,int param_3,float fparam_0);
extern int func_005549BC(int param_1,int param_2);
extern int func_00556EAC(int param_1,int param_2);
extern int func_0058E2B8(int *param_1);
extern int *DAT_006710c4;
extern float DAT_006710c8;
extern int DAT_006710cc;
extern float DAT_006710d0;
extern float DAT_006710d4;
extern float *DAT_006710d8;
extern undefined4 DAT_006710dc;
extern float DAT_006710e0;
extern undefined4 DAT_006710e4;
extern undefined4 DAT_006710e8;
extern undefined4 DAT_006710ec;
extern float DAT_006710f0;
extern undefined4 DAT_00671520;
extern uint DAT_00671e18;
extern int *DAT_00671e1c;
extern int *DAT_00671e20;
extern float DAT_00671e24;
extern float DAT_00671e28;
extern float DAT_00671e2c;
extern int DAT_00671e30;
extern float DAT_00671e34;
extern float DAT_00671e38;
extern float DAT_00671e3c;
extern float *DAT_00671e40;
extern float DAT_00671e44;

// USA 00670D14 <- EU 00670CEC (Ghidra, non-matching)
// GLOBAL DAT_006710c4 int *
// GLOBAL DAT_006710c8 float
// GLOBAL DAT_006710cc int
// GLOBAL DAT_006710d0 float
// GLOBAL DAT_006710d4 float
// GLOBAL DAT_006710d8 float *
// GLOBAL DAT_006710dc undefined4
// GLOBAL DAT_006710e0 float
// GLOBAL DAT_006710e4 undefined4
// GLOBAL DAT_006710e8 undefined4
// GLOBAL DAT_006710ec undefined4
// GLOBAL DAT_006710f0 float
// GLOBAL DAT_00671520 undefined4
// GLOBAL DAT_00671e18 uint
// GLOBAL DAT_00671e1c int *
// GLOBAL DAT_00671e20 int *
// GLOBAL DAT_00671e24 float
// GLOBAL DAT_00671e28 float
// GLOBAL DAT_00671e2c float
// GLOBAL DAT_00671e30 int
// GLOBAL DAT_00671e34 float
// GLOBAL DAT_00671e38 float
// GLOBAL DAT_00671e3c float
// GLOBAL DAT_00671e40 float *
// GLOBAL DAT_00671e44 float

/* WARNING: Variable defined which should be unmapped: objStack_258 */

uint func_00670D14(int param_1,float *param_2,int param_3,uint param_4,float fparam_0)

{
  char cVar1;
  int *piVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  float **ppfVar9;
  float fVar10;
  uint unaff_r10;
  uint unaff_r11;
  bool bVar11;
  float fVar12;
  float fVar13;
  undefined4 in_s1;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  ulonglong uVar19;
  longlong lVar20;
  undefined8 uVar21;
  undefined8 uVar22;
  undefined8 uVar23;
  _Alignas(8) unsigned char albw_frame[0x260];
  #define objStack_258 ((uint *)(albw_frame + 0x8))
  #define local_254 (*(float *)(albw_frame + 0xc))
  #define local_250 (*(float *)(albw_frame + 0x10))
  #define local_24c (*(float *)(albw_frame + 0x14))
  #define local_248 (*(float *)(albw_frame + 0x18))
  #define local_244 (*(float *)(albw_frame + 0x1c))
  #define local_240 (*(float *)(albw_frame + 0x20))
  #define local_23c (*(float *)(albw_frame + 0x24))
  #define local_238 (*(float *)(albw_frame + 0x28))
  #define local_234 (*(float *)(albw_frame + 0x2c))
  #define fStack_230 (*(float *)(albw_frame + 0x30))
  #define local_22c (*(float *)(albw_frame + 0x34))
  #define local_228 (*(float *)(albw_frame + 0x38))
  #define local_224 (*(float *)(albw_frame + 0x3c))
  #define local_220 (*(float *)(albw_frame + 0x40))
  #define local_21c (*(float *)(albw_frame + 0x44))
  #define local_218 (*(int *)(albw_frame + 0x48))
  #define local_214 (*(uint *)(albw_frame + 0x4c))
  #define local_210 (*(float *)(albw_frame + 0x50))
  #define local_20c (*(float *)(albw_frame + 0x54))
  #define local_208 (*(float *)(albw_frame + 0x58))
  #define local_204 (*(float *)(albw_frame + 0x5c))
  #define local_200 (*(uint *)(albw_frame + 0x60))
  #define local_1fc (*(float *)(albw_frame + 0x64))
  #define fStack_1f8 (*(float *)(albw_frame + 0x68))
  #define fStack_1f4 (*(float *)(albw_frame + 0x6c))
  #define local_1f0 (*(float *)(albw_frame + 0x70))
  #define fStack_1ec (*(float *)(albw_frame + 0x74))
  #define fStack_1e8 (*(float *)(albw_frame + 0x78))
  #define local_1e4 (*(float *)(albw_frame + 0x7c))
  #define local_1e0 ((float *)(albw_frame + 0x80))
  #define local_1c8 ((float * *)(albw_frame + 0x98))
  #define afStack_1c0 ((float *)(albw_frame + 0xa0))
  #define local_1b0 (*(float *)(albw_frame + 0xb0))
  #define local_1ac (*(float *)(albw_frame + 0xb4))
  #define local_1a8 (*(uint *)(albw_frame + 0xb8))
  #define local_1a4 (*(int *)(albw_frame + 0xbc))
  #define local_1a0 (*(float * *)(albw_frame + 0xc0))
  #define local_19c (*(int *)(albw_frame + 0xc4))
  #define local_198 (*(undefined4 *)(albw_frame + 0xc8))
  #define local_194 (*(undefined4 *)(albw_frame + 0xcc))
  #define local_190 (*(uint *)(albw_frame + 0xd0))
  #define local_18c (*(undefined4 *)(albw_frame + 0xd4))
  #define uStack_188 (*(undefined4 *)(albw_frame + 0xd8))
  #define local_184 (*(float * *)(albw_frame + 0xdc))
  #define local_180 (*(float * *)(albw_frame + 0xe0))
  #define local_17c (*(float *)(albw_frame + 0xe4))
  #define local_178 (*(undefined1 *)(albw_frame + 0xe8))
  #define local_177 (*(undefined1 *)(albw_frame + 0xe9))
  #define local_174 ((byte *)(albw_frame + 0xec))
  #define local_170 ((float *)(albw_frame + 0xf0))
  #define uStack_164 (*(uint *)(albw_frame + 0xfc))
  #define local_160 (*(undefined4 *)(albw_frame + 0x100))
  #define local_15c (*(undefined4 *)(albw_frame + 0x104))
  #define local_158 ((float *)(albw_frame + 0x108))
  #define local_14c (*(undefined1 *)(albw_frame + 0x114))
  #define local_14b (*(undefined1 *)(albw_frame + 0x115))
  #define local_148 (*(float *)(albw_frame + 0x118))
  #define local_144 (*(uint *)(albw_frame + 0x11c))
  #define afStack_140 ((float *)(albw_frame + 0x120))
  #define local_134 (*(uint *)(albw_frame + 0x12c))
  #define local_130 (*(float *)(albw_frame + 0x130))
  #define fStack_12c (*(float *)(albw_frame + 0x134))
  #define fStack_128 (*(float *)(albw_frame + 0x138))
  #define local_124 (*(float *)(albw_frame + 0x13c))
  #define local_120 (*(undefined4 *)(albw_frame + 0x140))
  #define local_11c (*(undefined4 *)(albw_frame + 0x144))
  #define local_118 (*(float * *)(albw_frame + 0x148))
  #define local_114 (*(int *)(albw_frame + 0x14c))
  #define local_104 (*(undefined4 *)(albw_frame + 0x15c))
  #define local_fc (*(float * *)(albw_frame + 0x164))
  #define local_f8 (*(float * *)(albw_frame + 0x168))
  #define local_ec (*(float *)(albw_frame + 0x174))
  #define local_e8 (*(float *)(albw_frame + 0x178))
  #define fStack_e4 (*(float *)(albw_frame + 0x17c))
  #define fStack_e0 (*(float *)(albw_frame + 0x180))
  #define local_d8 (*(int *)(albw_frame + 0x188))
  #define local_d4 (*(int *)(albw_frame + 0x18c))
  #define local_d0 ((byte *)(albw_frame + 0x190))
  #define local_c0 (*(uint *)(albw_frame + 0x1a0))
  #define local_bc (*(undefined4 *)(albw_frame + 0x1a4))
  #define uStack_b8 (*(undefined4 *)(albw_frame + 0x1a8))
  #define local_b4 (*(undefined4 *)(albw_frame + 0x1ac))
  #define local_b0 (*(undefined4 *)(albw_frame + 0x1b0))
  #define local_ac (*(float *)(albw_frame + 0x1b4))
  #define local_a8 (*(undefined1 *)(albw_frame + 0x1b8))
  #define local_a7 (*(undefined1 *)(albw_frame + 0x1b9))
  #define local_a4 (*(uint *)(albw_frame + 0x1bc))
  #define local_9c (*(uint *)(albw_frame + 0x1c4))
  #define local_98 (*(int *)(albw_frame + 0x1c8))
  #define local_94 (*(uint *)(albw_frame + 0x1cc))
  #define afStack_88 ((float *)(albw_frame + 0x1d8))
  #define uStack_3c (*(undefined8 *)(albw_frame + 0x224))
  #define iStack_34 (*(int *)(albw_frame + 0x22c))
  #define local_30 (*(float * *)(albw_frame + 0x230))
  #define iStack_2c (*(int *)(albw_frame + 0x234))
  #define local_28 (*(uint *)(albw_frame + 0x238))
  uStack_3c = CONCAT44(in_s1,fparam_0);
  local_1a8 = *(uint *)(param_1 + 8);
  iStack_34 = param_1;
  local_30 = param_2;
  iStack_2c = param_3;
  local_28 = param_4;
  bVar3 = func_00556EAC(*DAT_006710c4,0x62);
  local_9c = (uint)bVar3;
  fVar18 = DAT_006710c8;
  iVar4 = func_004ED868();
  if (iVar4 == 0) {
    fVar10 = *(float *)(DAT_006710cc + 0x10);
  }
  else {
    fVar10 = *(float *)(DAT_006710cc + 0x14);
  }
  local_1a4 = param_1 + 0x200;
  local_d8 = (int)*(char *)(param_1 + 0x22a);
  if (*(byte *)(param_1 + 0x20) != 0) {
    uVar23 = func_00114608((uint)ALBW_AS_U32((**(float **)(param_1 + 0x94) * DAT_006710d0)),
                           (uint)*(byte *)(param_1 + 0x20));
    fVar17 = ALBW_AS_F32(uVar23);
    if (*(char *)(param_1 + 0x164) == '\0') {
      *(float *)(param_1 + 8) = fVar17;
    }
    local_218 = (int)ALBW_AS_U32(fVar17) - (int)ALBW_AS_U32(fVar10);
    uVar5 = func_0058E2B8(&local_218);
    if (uVar5 < 0x11) {
      fVar10 = fVar17;
    }
    uVar5 = local_28;
    if (local_28 == 0) {
      uVar5 = (uint)*(byte *)(param_1 + 0x164);
    }
    if (local_28 == 0 && uVar5 == 0) {
      *(undefined1 *)(param_1 + 0x137) = 0;
      piVar2 = DAT_006710c4;
      local_254 = 0.0;
      local_24c = 0.0;
      objStack_258[0] = objStack_258[0] & 0xffffff00;
      local_23c = 0.0;
      local_238 = 0.0;
      local_234 = 0.0;
      local_22c = ALBW_AS_F32(((uint)ALBW_AS_U32(local_22c) & 0xffffff00));
      func_0052E94C(*DAT_006710c4,(int)objStack_258);
      iVar4 = func_004904CC(*(float *)((int)ALBW_AS_U32(local_238) + 8),*(float *)((int)ALBW_AS_U32(local_238) + 0x10));
      func_0034DC88(param_1,*(float **)(*piVar2 + 0x1c),iVar4);
      *(undefined1 *)(param_1 + 0x138) = 0;
      if (*(char *)(param_1 + 0x137) == '\0') {
        *(undefined4 *)(param_1 + 0x144) = 0;
        *(undefined1 *)(param_1 + 0x136) = 0;
      }
    }
  }
  local_148 = *(float *)(param_1 + 8);
  lVar20 = (ulonglong)(uint)ALBW_AS_U32(DAT_006710d4) << 0x20;
  local_c0 = unaff_r10 & 0xffff0000 | 0xffff;
  local_218 = 0;
  local_d0[0] = 0;
  local_d0[1] = 0;
  local_d0[2] = 0;
  local_d0[3] = 0;
  local_d0[4] = 0;
  local_d0[5] = 0;
  local_d0[6] = 0;
  local_d0[7] = 0;
  local_d0[8] = 0;
  local_d0[9] = 0;
  local_d0[10] = 0;
  local_d0[0xb] = 0;
  local_d0[0xc] = 0;
  local_d0[0xd] = 0;
  local_d0[0xe] = 0;
  local_d0[0xf] = 0;
  local_bc = 0xff;
  uStack_b8 = 0;
  local_b4 = 0;
  local_b0 = 0;
  local_ac = DAT_006710d4;
  local_a8 = 0;
  local_a7 = 1;
  fVar13 = DAT_006710d4;
  fVar12 = DAT_006710d4;
  func_00110D44(&local_118,local_d0,0x2a);
  fVar17 = DAT_006710e0;
  fVar16 = ALBW_AS_F32(((ulonglong)lVar20 >> 0x20));
  local_e8 = *DAT_006710d8;
  fStack_e4 = DAT_006710d8[1];
  fStack_e0 = DAT_006710d8[2];
  uVar23 = CONCAT44(fparam_0,DAT_006710dc);
  uVar19 = (ulonglong)(uint)ALBW_AS_U32(DAT_006710e0);
  local_190 = unaff_r11 & 0xffff0000 | 0xffff;
  local_1a0 = (float *)0x0;
  local_19c = 0;
  local_198 = 0;
  local_194 = 0;
  local_18c = 0xff;
  uStack_188 = 0;
  local_184 = (float *)0x0;
  local_180 = (float *)0x0;
  local_178 = 0;
  local_177 = 1;
  local_210 = *DAT_006710d8;
  local_d4 = 1;
  local_20c = DAT_006710d8[1];
  local_208 = DAT_006710d8[2];
  local_134 = 0;
  local_254 = 1.4013e-45;
  uVar22 = CONCAT44(DAT_006710e4,fVar13);
  bVar3 = false;
  *(undefined1 *)(param_1 + 0x220) = 0;
  local_a4 = 0;
  local_144 = 0;
  local_94 = 0;
  local_17c = fVar12;
  local_ec = fVar12;
  if (((local_28 == 0) && (*(char *)(param_1 + 0x20) != '\0')) &&
     (*(char *)(param_1 + 0x137) != '\0')) {
    func_00115C70(&local_254,(float *)(param_1 + 0x158),local_30 + 3);
    *(undefined4 *)(param_1 + 0x1c4) = *(undefined4 *)(param_1 + 0x24);
    *(float *)(param_1 + 0x1c0) =
         *(float *)(param_1 + 0x1c0) +
         (SQRT(local_254 * local_254 + local_250 * local_250 + local_24c * local_24c) -
         *(float *)(param_1 + 0x1c0)) * fVar12;
    goto LAB_00671bf8;
  }
  uVar21 = CONCAT44(DAT_006710ec,DAT_006710e8);
  local_98 = param_1 + 0x1d8;
  fVar13 = fVar12;
  local_234 = fVar10;
  do {
    fVar17 = ALBW_AS_F32(uVar19);
    local_204 = 0.0;
    local_248 = 0.0;
    local_244 = local_30[3];
    local_23c = local_30[5];
    local_200 = 0;
    local_21c = ALBW_NAN_NEG;
    local_214 = 0;
    fVar16 = ALBW_AS_F32(((ulonglong)lVar20 >> 0x20));
    local_240 = local_30[4] + ALBW_AS_F32(uVar23);
    fVar10 = fVar16;
    if (*(char *)(local_1a4 + 0x20) != '\0') {
      if (*(char *)(param_1 + 0x20) == '\0' || param_3 == 0) break;
      fVar14 = fVar13 + fVar17;
      if (DAT_006710f0 <= fVar13 + fVar17) {
        fVar14 = fVar17;
      }
      local_214 = (uint)(fVar14 == fVar17);
      fVar13 = fVar14;
      if (local_d4 == 0) {
        iVar4 = *(int *)(param_1 + 0xc);
      }
      else {
        iVar4 = func_005549BC(param_1,param_3);
      }
      uVar5 = iVar4 + 0x40000000;
      local_220 = ALBW_AS_F32((*(int *)(param_3 + 0xc) - (*(int *)(param_1 + 0xc) + 0x40000000)));
      uVar6 = func_0058E2B8((int *)&local_220);
      if (uVar6 < 0x40000001) {
        if (local_d4 == 0) {
LAB_006710fc:
          uVar5 = iVar4 + 0xc0000000;
        }
      }
      else if (local_d4 != 0) goto LAB_006710fc;
      func_00115154((float *)objStack_258,&local_250,uVar5);
      local_244 = local_244 + ALBW_AS_F32(objStack_258[0]) * fVar14;
      local_23c = local_23c + local_250 * fVar14;
    }
    lVar20 = CONCAT44(fVar10,DAT_00671520);
    fVar10 = local_148;
    if (*(char *)(param_1 + 0x139) != '\0') {
      fVar10 = *(float *)(param_1 + 0x13c);
    }
    *(float *)(param_1 + 8) = fVar10;
LAB_0067114c:
    fVar17 = ALBW_AS_F32(uVar19);
    uVar8 = *(undefined4 *)(param_1 + 0xc);
    bVar11 = *(char *)(local_1a4 + 0x20) != '\0';
    iVar4 = 0;
    if (bVar11) {
      iVar4 = local_d4;
    }
    fVar10 = func_00554804(param_1,(uint)(bVar11 && iVar4 != 0),param_3,fVar13);
    uVar5 = (uint)fVar10;
    *(uint *)(param_1 + 0xc) = uVar5;
    if (local_254 == 0.0) {
      bVar11 = local_a4 == *(uint *)(param_1 + 8);
      uVar6 = local_a4;
      if (bVar11) {
        uVar6 = local_144;
      }
      if (!bVar11 || uVar6 != uVar5) goto LAB_006711ac;
    }
    else {
LAB_006711ac:
      func_004D7FBC((float *)(param_1 + 0x1f8),DAT_006710d8,*(uint *)(param_1 + 8),uVar5,fVar17);
      local_254 = 0.0;
      local_a4 = *(uint *)(param_1 + 8);
      local_144 = *(uint *)(param_1 + 0xc);
    }
    *(undefined4 *)(param_1 + 0xc) = uVar8;
    func_00115D70(&local_228,(float *)(param_1 + 0x1f8),fVar18);
    local_1fc = local_228;
    fStack_1f8 = local_224;
    fStack_1f4 = local_220;
    func_00115C54(&local_124,&local_244,&local_1fc);
    local_1a0 = &local_210;
    local_18c = 0x79;
    local_184 = afStack_140;
    local_180 = &local_124;
    local_19c = local_98;
    *(float *)(param_1 + 0x204) = local_124;
    *(undefined4 *)(param_1 + 0x208) = local_120;
    *(undefined4 *)(param_1 + 0x20c) = local_11c;
    *(int *)(param_1 + 0x21c) = (int)lVar20;
    local_104 = 0x79;
    local_114 = 0;
    uVar5 = (uint)*(char *)(param_1 + 0x139);
    local_118 = local_1a0;
    local_fc = local_184;
    local_f8 = local_180;
    local_ec = fVar17;
    if (((uVar5 != 0) && (local_28 == 0)) ||
       ((*(char *)(local_1a4 + 0x2a) == '\x01' || (0xe < *(short *)(local_1a4 + 0x28)))))
    goto LAB_00671a38;
    fVar10 = ALBW_AS_F32(((ulonglong)lVar20 >> 0x20));
    uVar19 = CONCAT44(fVar10,fVar17);
    if (fVar12 == fVar10) {
      bVar11 = (uVar5 & -local_28) == 0;
      if (bVar11) {
        uVar5 = (uint)*(byte *)(param_1 + 0x131);
      }
      if (bVar11 && uVar5 == 0) {
        local_250 = *(float *)(param_1 + 0x9c) + ALBW_AS_F32(uVar21);
        func_004D7FBC(local_158,&local_244,*(uint *)(param_1 + 8),*(uint *)(param_1 + 0xc),local_250
                     );
        func_004D7FBC(afStack_88,&local_244,(uint)ALBW_AS_U32(local_234),*(uint *)(param_1 + 0xc),local_250);
        objStack_258[0] = (uint)&local_244;
        fVar10 = func_0034EE0C(param_1,&local_130,local_158,afStack_88,&local_244);
        iVar4 = 0;
LAB_006713b8:
        fVar17 = ALBW_AS_F32(uVar19);
        bVar3 = true;
LAB_00671338:
        *(bool *)((int)&local_1b0 + iVar4) = param_3 != 0;
        if (param_3 != 0) {
          fVar12 = fVar17;
          if (bVar3 && param_3 != 0) {
            iVar7 = func_005549BC(param_1,param_3);
          }
          else {
            iVar7 = *(int *)(param_1 + 0xc);
          }
          uVar5 = iVar7 + 0x40000000;
          local_1ac = ALBW_AS_F32((*(int *)(param_3 + 0xc) - (*(int *)(param_1 + 0xc) + 0x40000000)));
          uVar6 = func_0058E2B8((int *)&local_1ac);
          if (uVar6 < 0x40000001) {
            if (!bVar3) {
LAB_006713cc:
              uVar5 = iVar7 + 0xc0000000;
            }
          }
          else if (bVar3) goto LAB_006713cc;
          ppfVar9 = local_1c8 + iVar4 * 3;
          fVar14 = local_30[4];
          fVar15 = local_30[5];
          *ppfVar9 = (float *)ALBW_PTR_BITS(local_30[3]);
          afStack_1c0[iVar4 * 3 + -1] = fVar14;
          afStack_1c0[iVar4 * 3] = fVar15;
          afStack_1c0[iVar4 * 3 + -1] = fVar14 + ALBW_AS_F32(uVar23);
          func_00115154(&local_220,&local_1e4,uVar5);
          *ppfVar9 = (float *)ALBW_PTR_BITS((ALBW_AS_F32(*ppfVar9) + local_220 * fVar12));
          afStack_1c0[iVar4 * 3] = afStack_1c0[iVar4 * 3] + local_1e4 * fVar12;
          fVar12 = func_00554804(param_1,1,param_3,fVar12);
          func_004D7FBC(local_170 + iVar4 * 3,(float *)ppfVar9,*(uint *)(param_1 + 8),(int)fVar12,
                        local_250);
          func_004D7FBC(local_1e0 + iVar4 * 3,(float *)ppfVar9,(uint)ALBW_AS_U32(local_234),(int)fVar12,local_250
                       );
        }
        iVar4 = iVar4 + 1;
        if (1 < iVar4) {
          fVar17 = ALBW_AS_F32((uVar19 >> 0x20));
          iVar4 = 0;
          fVar12 = fVar10;
          do {
            fVar15 = fVar17;
            fVar14 = fVar17;
            if (*(char *)((int)&local_1b0 + iVar4) != '\0') {
              fVar15 = SQRT((local_130 - local_1e0[iVar4 * 3]) * (local_130 - local_1e0[iVar4 * 3])
                            + (fStack_12c - local_1e0[iVar4 * 3 + 1]) *
                              (fStack_12c - local_1e0[iVar4 * 3 + 1]) +
                            (fStack_128 - local_1e0[iVar4 * 3 + 2]) *
                            (fStack_128 - local_1e0[iVar4 * 3 + 2]));
              fVar14 = SQRT((local_130 - local_170[iVar4 * 3]) * (local_130 - local_170[iVar4 * 3])
                            + (fStack_12c - local_170[iVar4 * 3 + 1]) *
                              (fStack_12c - local_170[iVar4 * 3 + 1]) +
                            (fStack_128 - local_170[iVar4 * 3 + 2]) *
                            (fStack_128 - local_170[iVar4 * 3 + 2]));
            }
            if (fVar14 <= fVar15) {
              fVar14 = fVar15;
            }
            if (fVar12 < fVar14) {
              fVar12 = fVar14;
            }
            if ((*(char *)((int)&local_1b0 + iVar4) != '\0') &&
               (fVar14 = SQRT((local_130 - ALBW_AS_F32(local_1c8[iVar4 * 3])) *
                              (local_130 - ALBW_AS_F32(local_1c8[iVar4 * 3])) +
                              (fStack_12c - afStack_1c0[iVar4 * 3 + -1]) *
                              (fStack_12c - afStack_1c0[iVar4 * 3 + -1]) +
                              (fStack_128 - afStack_1c0[iVar4 * 3]) *
                              (fStack_128 - afStack_1c0[iVar4 * 3])), fVar10 < fVar14)) {
              fVar10 = fVar14;
            }
            iVar4 = iVar4 + 1;
          } while (iVar4 < 2);
          bVar3 = true;
          if (fVar12 <= fVar10) {
            fVar12 = fVar10;
          }
          goto LAB_00671670;
        }
        if (iVar4 != 0) goto code_r0x00671330;
        goto LAB_006713b8;
      }
    }
    else if (fVar10 < fVar12) {
      if (!bVar3) {
        uVar5 = local_94;
      }
      if (!bVar3 && uVar5 == 0) {
        uStack_164 = (uint)local_180 & 0xffff0000 | DAT_00671e18;
        local_174[0] = 0;
        local_174[1] = 0;
        local_174[2] = 0;
        local_174[3] = 0;
        local_160 = 0xff;
        local_170[0] = 0.0;
        local_170[1] = 0.0;
        local_170[2] = 0.0;
        fVar17 = fVar12 * ALBW_AS_F32(((ulonglong)uVar21 >> 0x20));
        local_15c = 0;
        local_158[0] = 0.0;
        local_158[1] = 0.0;
        local_14c = 0;
        local_14b = 1;
        local_158[2] = fVar10;
        func_00110D44(&local_1e4,local_174,0x2a);
        afStack_1c0[3] = *DAT_006710d8;
        local_1b0 = DAT_006710d8[1];
        local_1ac = DAT_006710d8[2];
        local_1c8[0] = &local_130;
        local_1c8[1] = local_1c8[0];
        afStack_1c0[2] = fVar17;
        func_004AACA0(*DAT_00671e1c,&local_1e4,0xff,0);
        local_94 = 1;
      }
    }
LAB_00671670:
    piVar2 = DAT_00671e1c;
    fVar10 = ALBW_AS_F32(((ulonglong)uVar23 >> 0x20));
    while( true ) {
      local_210 = ALBW_AS_F32((uVar19 >> 0x20));
      if (local_200 != 0) {
        fVar10 = ALBW_AS_F32(((ulonglong)uVar23 >> 0x20));
      }
      local_20c = local_210;
      local_208 = local_210;
      func_00115D70(&local_228,(float *)(param_1 + 0x1f8),fVar10);
      local_1e4 = local_228;
      local_1e0[0] = local_224;
      local_1e0[1] = local_220;
      func_00115C54(afStack_140,&local_124,&local_1e4);
      if (((fVar12 <= ALBW_AS_F32((uVar19 >> 0x20))) || (bVar3)) || (local_94 == 0)) {
        local_178 = 0;
      }
      else {
        local_178 = 1;
      }
      *(bool *)(param_1 + 0x130) = *(float *)(param_1 + 8) != local_234;
      uVar6 = func_004A8030(*piVar2,(int *)&local_1a0,3);
      bVar11 = *(char *)(param_1 + 0x139) != '\0';
      uVar5 = 0;
      if (bVar11) {
        uVar5 = local_28;
      }
      if (bVar11 && uVar5 != 0) {
        return uVar6 ^ 1;
      }
      fVar17 = ALBW_AS_F32(((ulonglong)uVar23 >> 0x20));
      if ((uVar6 != 0) && (bVar3 = false, ALBW_AS_F32((uVar19 >> 0x20)) <= *(float *)(param_1 + 0x21c))) {
        fVar10 = fVar10 / fVar17;
        func_00115C70(&local_228,(float *)(param_1 + 0x210),afStack_140);
        fVar16 = local_228 * *(float *)(param_1 + 0x1f8) + local_224 * *(float *)(param_1 + 0x1fc) +
                 local_220 * *(float *)(param_1 + 0x200);
        goto LAB_006717a8;
      }
      if (fVar17 <= fVar10) break;
      fVar10 = fVar10 + ALBW_AS_F32(uVar19);
      if (fVar17 < fVar10) {
        fVar10 = fVar17;
      }
    }
    fVar10 = ALBW_AS_F32(lVar20);
LAB_006717a8:
    fVar14 = ALBW_AS_F32(((ulonglong)uVar23 >> 0x20));
    if (local_200 != 0) goto LAB_0067196c;
    if (fVar10 < ALBW_AS_F32((uVar19 >> 0x20))) {
      local_248 = *(float *)(param_1 + 8);
      if ((*(char *)(local_1a4 + 0x20) != '\0') && ((int)ALBW_AS_U32(local_248) <= local_218)) {
        *(int *)(param_1 + 8) = local_218;
        goto LAB_0067196c;
      }
      if ((int)ALBW_AS_U32(local_21c) < 0) {
        if (local_148 == local_248) goto LAB_0067196c;
        *(int *)(param_1 + 8) = ((int)ALBW_AS_U32(local_204) + (int)ALBW_AS_U32(local_248)) / 2;
        local_21c = 0.0;
      }
      else if ((int)ALBW_AS_U32(local_21c) < 4) {
        *(int *)(param_1 + 8) = ((int)ALBW_AS_U32(local_204) + (int)ALBW_AS_U32(local_248)) / 2;
        local_21c = ALBW_AS_F32(((int)ALBW_AS_U32(local_21c) + 1));
      }
      else {
        local_200 = 1;
      }
      goto LAB_0067114c;
    }
    fVar10 = *(float *)(param_1 + 8);
    if (fVar10 != local_234) {
      local_204 = fVar10;
      if ((int)ALBW_AS_U32(local_21c) < 0) {
        iVar4 = *DAT_00671e20;
        *(int *)(param_1 + 8) = (int)ALBW_AS_U32(fVar10) + iVar4;
        if ((int)ALBW_AS_U32(local_234) <= (int)ALBW_AS_U32(fVar10) + iVar4) {
          *(float *)(param_1 + 8) = local_234;
        }
      }
      else if ((int)ALBW_AS_U32(local_21c) < 4) {
        *(int *)(param_1 + 8) = ((int)ALBW_AS_U32(fVar10) + (int)ALBW_AS_U32(local_248)) / 2;
        local_21c = ALBW_AS_F32(((int)ALBW_AS_U32(local_21c) + 1));
      }
      else {
        local_200 = 1;
        *(float *)(param_1 + 8) = local_248;
      }
      goto LAB_0067114c;
    }
    if (local_28 != 0) {
      return 0;
    }
    func_00115D70(&local_224,(float *)(param_1 + 0x1f8),fVar16);
    local_250 = local_224;
    local_24c = local_220;
    local_248 = local_21c;
    func_00115C54(&local_224,afStack_140,&local_250);
    fVar14 = SQRT((local_244 - local_224) * (local_244 - local_224) +
                  (local_240 - local_220) * (local_240 - local_220) +
                  (local_23c - local_21c) * (local_23c - local_21c));
LAB_0067196c:
    fVar17 = ALBW_AS_F32(uVar19);
    iVar4 = *(int *)(param_1 + 8);
    uVar8 = (undefined4)((ulonglong)uVar22 >> 0x20);
    if ((local_218 < iVar4) || (*(char *)(local_1a4 + 0x20) == '\0')) {
      uVar22 = CONCAT44(uVar8,fVar14);
      local_218 = iVar4;
      if (*(char *)(local_1a4 + 0x20) != '\0') goto LAB_006719a4;
      *(undefined1 *)(param_1 + 0x220) = 1;
    }
    else {
      if ((local_218 == iVar4) && (fVar14 < ALBW_AS_F32(uVar22))) {
        uVar22 = CONCAT44(uVar8,fVar14);
      }
LAB_006719a4:
      if (local_214 != 0) {
        if (local_d4 == 0) break;
        fVar13 = ALBW_AS_F32(((ulonglong)lVar20 >> 0x20));
        local_d4 = 0;
      }
    }
  } while ((local_134 & ~local_200) == 0);
  if (local_28 != 0) {
    return 1;
  }
  if (local_d8 == 1) {
    local_218 = *(int *)(DAT_006710cc + 0x20);
  }
  else if (local_9c != 0) {
    *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(DAT_006710cc + 0x14);
  }
  *(int *)(param_1 + 8) = local_218;
LAB_00671a38:
  fVar16 = ALBW_AS_F32(((ulonglong)lVar20 >> 0x20));
  *(undefined1 *)(param_1 + 0x131) = 0;
  iVar4 = func_004ED868();
  fVar18 = DAT_00671e24;
  if (iVar4 == 0) {
    fVar18 = DAT_00671e28;
  }
  fVar10 = ALBW_AS_F32(((ulonglong)uVar23 >> 0x20));
  if ((local_d8 == 0) || ((local_d8 == 2 && (0x13 < *(byte *)(param_1 + 0x22b))))) {
    if ((local_9c == 0) || (*(short *)(local_1a4 + 0x28) < 0xf)) {
      if ((*(char *)(param_1 + 0x139) != '\0') && (local_d8 == 0)) {
        *(undefined4 *)(param_1 + 0x1c0) = *(undefined4 *)(param_1 + 0x140);
        goto LAB_00671bc4;
      }
      fVar12 = *(float *)(param_1 + 0x1c0);
      fVar13 = fVar12;
      if (fVar18 <= fVar12) {
        fVar13 = fVar18;
      }
      if ((fVar12 <= fVar10) || (*(char *)(param_1 + 0x164) != '\0')) {
        fVar14 = fVar12 + (ALBW_AS_F32(uVar22) - fVar12) * fVar17;
        if (fVar14 < fVar13) goto LAB_00671bb8;
        if (fVar10 < fVar14) {
          fVar14 = fVar10;
        }
      }
      else {
        fVar14 = fVar12 + (ALBW_AS_F32(uVar22) - fVar12) * fVar17;
        if (fVar14 < fVar13) goto LAB_00671ba4;
        fVar13 = fVar12;
        if (fVar12 < fVar14) goto LAB_00671bb8;
      }
    }
    else {
      fVar12 = *(float *)(param_1 + 0x1c0);
      fVar14 = fVar12 + (DAT_00671e2c - fVar12) * fVar17;
      if ((int)ALBW_AS_U32(fVar12) < DAT_00671e30) {
        fVar13 = fVar12;
        if (fVar12 <= fVar14) {
          fVar13 = DAT_00671e2c;
          if (fVar14 <= DAT_00671e2c) goto LAB_00671b1c;
LAB_00671ba4:
          fVar14 = fVar13;
          goto LAB_00671b1c;
        }
      }
      else {
        fVar13 = DAT_00671e2c;
        if (fVar14 < DAT_00671e2c) goto LAB_00671ba4;
        fVar13 = fVar12;
        if (fVar14 <= fVar12) goto LAB_00671b1c;
      }
LAB_00671bb8:
      fVar14 = fVar13;
    }
LAB_00671b1c:
    *(float *)(param_1 + 0x1c0) = fVar14;
  }
  else {
    *(float *)(param_1 + 0x1c0) = DAT_00671e2c;
  }
LAB_00671bc4:
  fVar13 = ALBW_AS_F32(((ulonglong)uVar22 >> 0x20));
  if (fVar10 - fVar18 != fVar16) {
    fVar13 = ((*(float *)(param_1 + 0x24) - fVar13) * (*(float *)(param_1 + 0x1c0) - fVar18)) /
             (fVar10 - fVar18) + fVar13;
  }
  *(float *)(param_1 + 0x1c4) = fVar13;
LAB_00671bf8:
  fVar18 = ALBW_AS_F32(uVar23);
  fVar10 = ALBW_AS_F32(((ulonglong)uVar22 >> 0x20));
  *(undefined4 *)(param_1 + 0x1c8) = *(undefined4 *)(param_1 + 0xa8);
  if (*(char *)(param_1 + 0x164) == '\0') {
    func_004D7FBC((float *)(param_1 + 0x1f8),DAT_006710d8,local_1a8,*(uint *)(param_1 + 0xc),fVar17)
    ;
  }
  else {
    func_004D7FBC((float *)(param_1 + 0x1f8),DAT_006710d8,*(uint *)(param_1 + 8),
                  *(uint *)(param_1 + 0xc),fVar17);
  }
  func_00115D70(&local_254,(float *)(param_1 + 0x1f8),*(float *)(param_1 + 0x1c0));
  local_1f0 = local_254;
  fStack_1ec = local_250;
  fStack_1e8 = local_24c;
  func_00115C54(local_30,local_30 + 3,&local_1f0);
  local_184 = local_30;
  bVar3 = *(char *)(param_1 + 0x20) == '\0';
  cVar1 = '\0';
  if (!bVar3) {
    cVar1 = *(char *)(param_1 + 0x137);
  }
  local_210 = fVar16;
  local_20c = fVar16;
  local_208 = fVar16;
  local_1a0 = &local_210;
  if (bVar3 || cVar1 == '\0') {
    local_fc = local_30;
    local_238 = *local_f8;
    local_234 = local_f8[1];
    fStack_230 = local_f8[2];
    local_f8 = &local_238;
    func_00115C70((float *)objStack_258,local_30,&local_238);
    fVar17 = SQRT(ALBW_AS_F32(objStack_258[0]) * ALBW_AS_F32(objStack_258[0]) + local_254 * local_254 +
                  local_250 * local_250);
    if (fVar16 < fVar17) {
      fVar17 = DAT_00671e34 / fVar17;
      objStack_258[0] = (uint)ALBW_AS_U32(ALBW_AS_F32(objStack_258[0]) * fVar17);
      local_254 = local_254 * fVar17;
      local_250 = local_250 * fVar17;
    }
    func_00115C70(&local_238,local_fc,(float *)objStack_258);
    local_114 = param_1 + 0x1e8;
    local_118 = &local_210;
    local_ec = fVar10;
    iVar4 = func_004A9F98(*DAT_00671e1c,(uint *)&local_118,0xf,DAT_00671e3c,DAT_00671e38);
    if (iVar4 != 0) {
      func_00115D70(&local_22c,(float *)(param_1 + 0x1f8),
                    *(float *)(param_1 + 0x1f8) * local_210 +
                    *(float *)(param_1 + 0x1fc) * local_20c +
                    *(float *)(param_1 + 0x200) * local_208);
      local_244 = local_22c;
      local_240 = local_228;
      local_23c = local_224;
      func_00115C70(&local_210,&local_210,&local_244);
      func_00115D70(&local_22c,DAT_00671e40,
                    local_210 * *DAT_00671e40 + local_20c * DAT_00671e40[1] +
                    local_208 * DAT_00671e40[2]);
      local_244 = local_22c;
      local_240 = local_228;
      local_23c = local_224;
      func_00115C70(&local_210,&local_210,&local_244);
    }
    fVar10 = DAT_00671e44;
    *(float *)(param_1 + 0x1cc) =
         *(float *)(param_1 + 0x1cc) + (local_210 - *(float *)(param_1 + 0x1cc)) * DAT_00671e44;
    *(float *)(param_1 + 0x1d0) =
         *(float *)(param_1 + 0x1d0) + (local_20c - *(float *)(param_1 + 0x1d0)) * fVar10;
    *(float *)(param_1 + 0x1d4) =
         *(float *)(param_1 + 0x1d4) + (local_208 - *(float *)(param_1 + 0x1d4)) * fVar10;
    func_00115C54(local_30,local_30,(float *)(param_1 + 0x1cc));
    bVar3 = *(char *)(param_1 + 0x20) != '\0';
    cVar1 = '\0';
    if (bVar3) {
      cVar1 = *(char *)(param_1 + 0x137);
    }
    if (!bVar3 || cVar1 == '\0') {
      local_30[1] = local_30[1] + fVar18;
    }
  }
  func_0034E4B0(param_1,local_30,param_3);
  if (*(char *)(param_1 + 0x164) == '\0') {
    uVar8 = *(undefined4 *)(param_1 + 8);
    *(uint *)(param_1 + 8) = local_1a8;
    *(undefined4 *)(param_1 + 0x174) = uVar8;
  }
  return 1;
code_r0x00671330:
  bVar3 = false;
  goto LAB_00671338;
}

