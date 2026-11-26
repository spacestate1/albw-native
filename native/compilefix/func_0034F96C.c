/* compilefix: USA 0034F96C (EU 0034F948), the converted stage-2 text with a branch rejoined
 * (BOOT_LOG 175): the block at EU 350038 (taken when the byte +0x22A is 2) is part of this function,
 * but Ghidra called it as a function of its own, `return func_0035005C(2, x)`, reading the caller's
 * registers and stack: crash (found by random play in a Hyrule cave). It turns +0x2C towards +0x30
 * at the rate of DAT_003501C4 once the byte +0x22B reaches 5, else falls into the following chain. */
// MAPFIX-INTEGRATED v1
#include "ghidra_types.h"

extern int func_00100174(int *param_1);
extern ulonglong func_00110710(uint param_1,uint param_2);
extern undefined8 func_00114608(uint param_1,uint param_2);
extern int func_001157FC(float *param_1,float *param_2,float *param_3);
extern int func_00115C54(float *param_1,float *param_2,float *param_3);
extern int func_00115C70(float *param_1,float *param_2,float *param_3);
extern int func_00115CA8(float *param_1,float *param_2,float *param_3);
extern int func_0012159C(int param_1);
extern int func_00261564(int param_1);
extern int func_0029F9D0(undefined1 *param_1);
extern int func_0029FA1C(int param_1);
extern int func_002E12C0(undefined4 param_1,float *param_2,float *param_3,undefined4 *param_4,int param_5, float fparam_0);
extern int func_002E1424(float *param_1,float *param_2);
extern int func_002E15CC(float *param_1,float *param_2,float *param_3,int param_4,int param_5,int param_6, float fparam_0,float fparam_1,float fparam_2);
extern int func_0034CE10(int param_1,int param_2,float *param_3);
extern int func_0034D780(int param_1,float *param_2,int param_3);
extern int func_0034DF14(int param_1,float *param_2,int param_3,int param_4,float fparam_0);
extern int func_0034E038(int param_1,float *param_2,int param_3,int param_4,float fparam_0,float fparam_1);
extern int func_0034E344(int param_1);
extern undefined8 func_0034EFB0(int param_1);
extern int func_003517A4(int param_1,float *param_2,undefined4 param_3,float *param_4,float fparam_0);
extern int func_0036F6C8(float *param_1,float *param_2,float *param_3);
extern int func_0036F874(float *param_1,float *param_2,undefined4 *param_3,float fparam_0);
extern int func_0036FA1C(undefined4 *param_1,undefined1 param_2);
extern int func_0036FA58(float *param_1,byte *param_2,float *param_3,int param_4);
extern int func_004904CC(float fparam_0,float fparam_1);
extern int func_00491E80(float *param_1,uint param_2,uint param_3,uint param_4);
extern float func_004D7FBC(float *param_1,float *param_2,uint param_3,uint param_4,float fparam_0);
extern int func_004D838C(float *param_1,float *param_2,float fparam_0,float fparam_1,float fparam_2);
extern int func_0051D27C(int *param_1,int param_2,int param_3);
extern int func_0052FBA0(int param_1,uint param_2);
extern int func_00541190(int param_1);
extern float func_00542330(undefined4 param_1,int param_2);
extern float func_00542350(undefined4 param_1,int param_2);
extern int func_00553E4C(int param_1,int param_2);
extern float func_005548EC(int param_1,int param_2);
extern int func_005569A4();
extern int func_00556A90();
extern int func_005581D4(float *param_1,float *param_2,int param_3,byte *param_4);
extern int func_00581DF8(int param_1,undefined4 param_2,undefined4 param_3);
extern int func_00588BE4(int param_1);
extern int func_00588F20(undefined4 param_1,float *param_2,float fparam_0);
extern int func_00589170(int param_1,float *param_2,int param_3,uint *param_4,int param_5,float fparam_0);
extern int func_0058E2B8(int *param_1);
extern int *DAT_0034fde8;
extern float DAT_0034fdec;
extern undefined4 DAT_0034fdf0;
extern int *DAT_0034fdf4;
extern float DAT_0034fdf8;
extern float DAT_0034fdfc;
extern float DAT_0034fe00;
extern float DAT_0034fe04;
extern float DAT_0034fe08;
extern float DAT_0034fe0c;
extern float DAT_003501b0;
extern int DAT_003501b4;
extern int DAT_003501b8;
extern uint DAT_003501bc;
extern uint DAT_003501c0;
extern uint DAT_003501c4;
extern uint *DAT_003501c8;
extern int DAT_003501cc;
extern float DAT_003501d0;
extern int DAT_003501d4;
extern uint DAT_00350718;
extern uint DAT_0035071c;
extern uint DAT_00350720;
extern int DAT_00350724;
extern int DAT_00350728;
extern float DAT_0035072c;
extern int *DAT_00350730;
extern int *DAT_00350734;
extern int *DAT_00350738;
extern int *DAT_0035073c;
extern int *DAT_00350740;
extern float DAT_00350744;
extern float DAT_00350748;
extern float DAT_0035074c;
extern undefined4 DAT_00350750;
extern float *DAT_003514d4;
extern int DAT_003514d8;
extern int DAT_003514dc;
extern int *DAT_003514e0;
extern int DAT_003514e4;
extern float DAT_003514e8;
extern int DAT_003514ec;
extern int *DAT_003514f0;
extern int *DAT_003514f4;
extern int DAT_003514f8;
extern int DAT_003516bc;
extern int *DAT_003516c0;
extern uint *DAT_003516c4;
extern undefined4 *DAT_003516c8;
extern undefined4 DAT_003516cc;

// USA 0034F96C <- EU 0034F948 (Ghidra, non-matching)
// GLOBAL DAT_0034fde8 int *
// GLOBAL DAT_0034fdec float
// GLOBAL DAT_0034fdf0 undefined4
// GLOBAL DAT_0034fdf4 int *
// GLOBAL DAT_0034fdf8 float
// GLOBAL DAT_0034fdfc float
// GLOBAL DAT_0034fe00 float
// GLOBAL DAT_0034fe04 float
// GLOBAL DAT_0034fe08 float
// GLOBAL DAT_0034fe0c float
// GLOBAL DAT_003501b0 float
// GLOBAL DAT_003501b4 int
// GLOBAL DAT_003501b8 int
// GLOBAL DAT_003501bc uint
// GLOBAL DAT_003501c0 uint
// GLOBAL DAT_003501c8 uint *
// GLOBAL DAT_003501cc int
// GLOBAL DAT_003501d0 float
// GLOBAL DAT_003501d4 int
// GLOBAL DAT_00350718 uint
// GLOBAL DAT_0035071c uint
// GLOBAL DAT_00350720 uint
// GLOBAL DAT_00350724 int
// GLOBAL DAT_00350728 int
// GLOBAL DAT_0035072c float
// GLOBAL DAT_00350730 int *
// GLOBAL DAT_00350734 int *
// GLOBAL DAT_00350738 int *
// GLOBAL DAT_0035073c int *
// GLOBAL DAT_00350740 int *
// GLOBAL DAT_00350744 float
// GLOBAL DAT_00350748 float
// GLOBAL DAT_0035074c float
// GLOBAL DAT_00350750 undefined4
// GLOBAL DAT_003514d4 float *
// GLOBAL DAT_003514d8 int
// GLOBAL DAT_003514dc int
// GLOBAL DAT_003514e0 int *
// GLOBAL DAT_003514e4 int
// GLOBAL DAT_003514e8 float
// GLOBAL DAT_003514ec int
// GLOBAL DAT_003514f0 int *
// GLOBAL DAT_003514f4 int *
// GLOBAL DAT_003514f8 int
// GLOBAL DAT_003516bc int
// GLOBAL DAT_003516c0 int *
// GLOBAL DAT_003516c4 uint *
// GLOBAL DAT_003516c8 undefined4 *
// GLOBAL DAT_003516cc undefined4

undefined4 func_0034F96C(int param_1,float *param_2,byte *param_3)

{
  char cVar1;
  char cVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  int iVar7;
  int *piVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  uint uVar11;
  uint extraout_r1;
  uint uVar12;
  uint extraout_r1_00;
  undefined4 *puVar13;
  int iVar14;
  int iVar15;
  float *pfVar16;
  bool bVar17;
  bool bVar18;
  uint in_fpscr;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  undefined8 uVar28;
  ulonglong uVar29;
  ulonglong uVar30;
  undefined8 uVar31;
  _Alignas(8) unsigned char albw_frame[0x160];
  #define fStack_158 (*(float *)(albw_frame + 0x8))
  #define fStack_154 (*(float *)(albw_frame + 0xc))
  #define fStack_150 (*(float *)(albw_frame + 0x10))
  #define fStack_14c (*(float *)(albw_frame + 0x14))
  #define fStack_148 (*(float *)(albw_frame + 0x18))
  #define fStack_144 (*(float *)(albw_frame + 0x1c))
  #define local_140 (*(float *)(albw_frame + 0x20))
  #define afStack_13c ((float *)(albw_frame + 0x24))
  #define local_128 (*(float *)(albw_frame + 0x38))
  #define local_124 (*(float *)(albw_frame + 0x3c))
  #define local_120 (*(float *)(albw_frame + 0x40))
  #define fStack_11c (*(float *)(albw_frame + 0x44))
  #define fStack_118 (*(float *)(albw_frame + 0x48))
  #define fStack_114 (*(float *)(albw_frame + 0x4c))
  #define fStack_110 (*(float *)(albw_frame + 0x50))
  #define fStack_10c (*(float *)(albw_frame + 0x54))
  #define fStack_108 (*(float *)(albw_frame + 0x58))
  #define fStack_104 (*(float *)(albw_frame + 0x5c))
  #define fStack_100 (*(float *)(albw_frame + 0x60))
  #define iStack_fc (*(int *)(albw_frame + 0x64))
  #define afStack_f8 ((float *)(albw_frame + 0x68))
  #define fStack_f0 (*(float *)(albw_frame + 0x70))
  #define afStack_ec ((float *)(albw_frame + 0x74))
  #define fStack_e4 (*(float *)(albw_frame + 0x7c))
  #define fStack_e0 (*(float *)(albw_frame + 0x80))
  #define fStack_dc (*(float *)(albw_frame + 0x84))
  #define fStack_d8 (*(float *)(albw_frame + 0x88))
  #define local_c4 (*(uint *)(albw_frame + 0x9c))
  #define afStack_c0 ((float *)(albw_frame + 0xa0))
  #define afStack_90 ((float *)(albw_frame + 0xd0))
  #define fStack_84 (*(float *)(albw_frame + 0xdc))
  #define uStack_74 (*(undefined4 *)(albw_frame + 0xec))
  #define uStack_64 (*(undefined4 *)(albw_frame + 0xfc))
  #define iStack_60 (*(int *)(albw_frame + 0x100))
  #define afStack_5c ((float *)(albw_frame + 0x104))
  #define fStack_54 (*(float *)(albw_frame + 0x10c))
  #define fStack_50 (*(float *)(albw_frame + 0x110))
  #define uStack_4c (*(undefined4 *)(albw_frame + 0x114))
  #define uStack_48 (*(undefined4 *)(albw_frame + 0x118))
  cVar1 = *(char *)(*DAT_0034fde8 + 0x98);
  *(undefined1 *)(*DAT_0034fde8 + 0x98) = 0;
  if (cVar1 != '\0') {
    func_0029F9D0((undefined1 *)(param_1 + 0x98));
  }
  fVar26 = *(float *)(param_1 + 0x118);
  fVar19 = func_005548EC(param_1,0);
  *(float *)(param_1 + 0x118) = fVar19;
  fVar19 = func_005548EC(param_1,1);
  *(float *)(param_1 + 0x11c) = fVar19;
  fVar25 = (float)VectorSignedToFloat(*(undefined4 *)(param_1 + 0x128),(byte)(in_fpscr >> 0x15) & 3)
  ;
  iVar4 = func_00553E4C(param_1,0);
  *(int *)(param_1 + 0x128) = iVar4;
  iVar4 = func_00553E4C(param_1,1);
  *(int *)(param_1 + 300) = iVar4;
  uVar9 = DAT_0034fdf0;
  fVar19 = DAT_0034fdec;
  fVar20 = (float)VectorSignedToFloat((int)*(char *)(param_1 + 0x132),(byte)(in_fpscr >> 0x15) & 3);
  if ((*(char *)(*(int *)(param_1 + 0x90) + 0x24) == '\0') ||
     ((*(char *)(param_1 + 0x133) != '\0' && (*(char *)(*DAT_0034fde8 + 0x95) != '\0')))) {
    uVar10 = 0;
  }
  else {
    uVar10 = 1;
  }
  iVar4 = *(int *)(param_1 + 0x110);
  bVar17 = iVar4 == -1;
  if (bVar17) {
    iVar4 = -2;
  }
  *(char *)(param_1 + 0x132) = (char)uVar10;
  if (bVar17) {
LAB_0034fa78:
    *(int *)(param_1 + 0x110) = iVar4;
  }
  else {
    uVar5 = in_fpscr & 0xfffffff;
    in_fpscr = uVar5 | (uint)(*(float *)(param_1 + 0x118) == fVar26) << 0x1e;
    if (SUB41(in_fpscr >> 0x1e,0)) {
      fVar21 = (float)VectorSignedToFloat(*(undefined4 *)(param_1 + 0x128),
                                          (byte)(in_fpscr >> 0x15) & 3);
      in_fpscr = uVar5 | (uint)(fVar21 == fVar25) << 0x1e;
      if (SUB41(in_fpscr >> 0x1e,0)) {
        fVar21 = (float)VectorSignedToFloat(uVar10,(byte)(in_fpscr >> 0x15) & 3);
        in_fpscr = uVar5 | (uint)(fVar21 == fVar20) << 0x1e;
        if (SUB41(in_fpscr >> 0x1e,0)) {
          if (-1 < iVar4) {
            iVar4 = iVar4 + 1;
            goto LAB_0034fa78;
          }
          *(undefined4 *)(param_1 + 0x120) = uVar9;
          *(undefined4 *)(param_1 + 0x110) = 0;
          goto LAB_0034fac4;
        }
      }
    }
    if (iVar4 < 0) {
      *(undefined4 *)(param_1 + 0x120) = uVar9;
    }
    else {
      *(float *)(param_1 + 0x120) = fVar19;
    }
    *(float *)(param_1 + 0x114) = fVar26;
    *(undefined4 *)(param_1 + 0x110) = 0;
    fVar20 = func_005548EC(param_1,1);
    *(float *)(param_1 + 0x11c) = fVar20;
    *(int *)(param_1 + 0x124) = (int)fVar25;
    iVar4 = func_00553E4C(param_1,1);
    *(int *)(param_1 + 300) = iVar4;
  }
LAB_0034fac4:
  if ((((*(char *)(param_1 + 0x2a1) != '\0') && (-1 < *(short *)(param_1 + 0x29e))) &&
      (*(short *)(param_1 + 0x29e) < 1)) && (*(char *)(param_1 + 0x2a0) == '\0')) {
    func_0034E344(param_1);
  }
  if ((*(char *)(param_1 + 0x22c) != '\0') && (*(char *)(param_1 + 0x22d) == '\0')) {
    param_2[3] = *(float *)(param_1 + 0x230);
    param_2[4] = *(float *)(param_1 + 0x234);
    param_2[5] = *(float *)(param_1 + 0x238);
  }
  cVar1 = *(char *)(param_1 + 0x29c);
  *(undefined1 *)(param_1 + 0x29c) = 0;
  piVar8 = DAT_0034fde8;
  if (*(char *)(param_1 + 0x20) == '\0') {
    if (*(int *)(param_1 + 0x264) != 0) {
      fVar21 = *(float *)(*(int *)(param_3 + 4) + 4);
      iVar4 = *(int *)(param_1 + 0x264);
      fVar22 = *(float *)(iVar4 + 0x3d0);
      fVar23 = *(float *)(iVar4 + 0x3d8);
      iVar4 = func_00541190(iVar4);
      fVar20 = *(float *)(iVar4 + 8);
      fVar25 = *(float *)(iVar4 + 0x34);
      fVar26 = *(float *)(*(int *)(*DAT_0034fdf4 + 0x1c) + 4);
      uVar5 = in_fpscr & 0xfffffff;
      in_fpscr = uVar5 | (uint)(fVar26 == fVar25) << 0x1e | (uint)(fVar25 <= fVar26) << 0x1d;
      bVar3 = (byte)(in_fpscr >> 0x18);
      if (!(bool)(bVar3 >> 5 & 1) || (bool)(bVar3 >> 6)) {
        fVar20 = *(float *)(iVar4 + 0xc);
      }
      else {
        fVar24 = fVar25 + *(float *)(iVar4 + 0x38);
        uVar5 = uVar5 | (uint)(fVar24 < fVar26) << 0x1f;
        in_fpscr = uVar5 | (uint)(NAN(fVar24) || NAN(fVar26)) << 0x1c;
        if ((byte)(uVar5 >> 0x1f) == ((byte)(in_fpscr >> 0x1c) & 1)) {
          fVar20 = *(float *)(iVar4 + 0xc) +
                   (fVar20 - *(float *)(iVar4 + 0xc)) *
                   ((fVar26 - fVar25) / *(float *)(iVar4 + 0x38));
        }
      }
      param_2[3] = fVar22;
      param_2[4] = fVar21 + fVar20;
      param_2[5] = fVar23;
    }
  }
  else {
    cVar2 = *(char *)(param_1 + 0x22a);
    if ((cVar2 != '\0') || (*(short *)(param_1 + 0x228) < 10)) {
      pfVar16 = *(float **)(*DAT_0034fdf4 + 0x1c);
      iVar4 = **(int **)(*DAT_0034fdf4 + 0x24);
      if (cVar2 == '\x01') {
        fVar20 = DAT_0034fdf8;
        uVar5 = func_00589170(*DAT_0034fde8,pfVar16,iVar4,(uint *)0x0,1,DAT_0034fdfc);
        if (uVar5 < 2) {
          uVar5 = func_00589170(*piVar8,pfVar16,iVar4 + -0x80000000,(uint *)0x0,0,fVar20);
        }
        if (uVar5 == 2 || uVar5 == 3) {
          *(undefined1 *)(param_1 + 0x22a) = 2;
          *(char *)(param_1 + 0x29c) = (char)uVar5;
          *(undefined1 *)(param_1 + 0x22b) = 0;
        }
      }
      else if (cVar2 == '\x02') {
        *(char *)(param_1 + 0x29c) = cVar1;
        if (*(char *)(param_1 + 0x22b) != -1) {
          *(char *)(param_1 + 0x22b) = *(char *)(param_1 + 0x22b) + '\x01';
        }
      }
      else {
        fVar20 = DAT_0034fdf8;
        local_140 = ALBW_AS_F32(func_004904CC(*(float *)(*(int *)(param_3 + 0x20) + 8),
                                         *(float *)(*(int *)(param_3 + 0x20) + 0x10)));
        iVar4 = func_00589170(*DAT_0034fde8,pfVar16,iVar4,(uint *)&local_140,0,fVar20);
        *(char *)(param_1 + 0x29c) = (char)iVar4;
        if ((iVar4 == 0) && (cVar1 == '\x02' || cVar1 == '\x03')) {
          *(char *)(param_1 + 0x29d) = cVar1;
        }
      }
    }
  }
  uVar11 = (uint)*(byte *)(param_1 + 0x20);
  local_c4 = (uint)*(char *)(param_1 + 0x148);
  uVar5 = local_c4;
  if (uVar11 != 0) {
    uVar5 = (uint)*(byte *)(param_1 + 0x164);
  }
  if (uVar11 == 0 || uVar5 == 0) {
    *(undefined1 *)(param_1 + 0x148) = 0;
  }
  iVar4 = (int)*(char *)(param_1 + 0x21);
  uVar28 = CONCAT44(param_2[6],uVar9);
  if (iVar4 != 0) {
    func_0034D780(param_1,param_2,(int)param_3);
    *(char *)(param_1 + 0x164) = *(char *)(param_1 + 0x20);
    uVar11 = extraout_r1;
    if (*(char *)(param_1 + 0x20) != '\0') {
      uVar11 = 1;
      *(undefined1 *)(param_1 + 0x165) = 1;
      *(undefined1 *)(param_1 + 0x166) = 0;
      *(undefined1 *)(param_1 + 0x178) = 1;
      *(undefined1 *)(param_1 + 0x17a) = 0;
      *(undefined1 *)(param_1 + 0x17b) = 0;
      *(undefined1 *)(param_1 + 0x17c) = 0;
    }
    *(int *)(param_1 + 0x108) = (int)uVar28;
  }
  fVar20 = DAT_0034fe00;
  if (*(char *)(param_1 + 0x20) == '\0') {
    fVar26 = *(float *)(param_3 + 0x28);
    fVar21 = *(float *)(param_1 + 0x104);
    fVar25 = DAT_0034fe04;
    if (*(char *)(param_1 + 0x22) != '\0') {
      fVar25 = ALBW_AS_F32(uVar28);
    }
    fVar25 = (fVar26 - fVar21) * fVar25;
    if (fVar25 <= DAT_0034fe00) {
      fVar25 = -fVar25;
    }
    uVar5 = in_fpscr & 0xfffffff | (uint)(DAT_0034fe08 <= fVar25) << 0x1d;
    fVar22 = DAT_0034fe08;
    if ((SUB41(uVar5 >> 0x1d,0)) &&
       (uVar5 = in_fpscr & 0xfffffff | (uint)(fVar25 < DAT_0034fe0c) << 0x1f |
                (uint)(fVar25 == DAT_0034fe0c) << 0x1e, bVar3 = (byte)(uVar5 >> 0x18),
       fVar22 = fVar25,
       !(bool)(bVar3 >> 6 & 1) && (bool)(bVar3 >> 7) == (NAN(fVar25) || NAN(DAT_0034fe0c)))) {
      fVar22 = DAT_0034fe0c;
    }
    uVar5 = uVar5 & 0xfffffff;
    uVar12 = uVar5 | (uint)(fVar21 < fVar26) << 0x1f | (uint)(fVar21 == fVar26) << 0x1e |
             (uint)(fVar26 <= fVar21) << 0x1d;
    in_fpscr = uVar12 | (uint)(NAN(fVar21) || NAN(fVar26)) << 0x1c;
    bVar3 = (byte)(uVar12 >> 0x18);
    if ((bool)(bVar3 >> 5 & 1)) {
      if (!(bool)(bVar3 >> 6 & 1) && bVar3 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1)) {
        fVar22 = fVar21 - fVar22;
        in_fpscr = uVar5 | (uint)(fVar22 == fVar26) << 0x1e | (uint)(fVar26 <= fVar22) << 0x1d;
        bVar3 = (byte)(in_fpscr >> 0x18);
        if ((!(bool)(bVar3 >> 5 & 1) || (bool)(bVar3 >> 6)) ||
           (uVar5 = uVar5 | (uint)(fVar22 < fVar21) << 0x1f | (uint)(fVar22 == fVar21) << 0x1e,
           in_fpscr = uVar5 | (uint)(NAN(fVar22) || NAN(fVar21)) << 0x1c,
           bVar3 = (byte)(uVar5 >> 0x18),
           !(bool)(bVar3 >> 6 & 1) && bVar3 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1)))
        goto LAB_0034fe14;
        goto LAB_0034fe1c;
      }
    }
    else {
      fVar22 = fVar21 + fVar22;
      in_fpscr = uVar5 | (uint)(fVar26 == fVar22) << 0x1e | (uint)(fVar22 <= fVar26) << 0x1d;
      bVar3 = (byte)(in_fpscr >> 0x18);
      if ((!(bool)(bVar3 >> 5 & 1) || (bool)(bVar3 >> 6)) ||
         (uVar5 = uVar5 | (uint)(fVar21 < fVar22) << 0x1f | (uint)(fVar21 == fVar22) << 0x1e,
         in_fpscr = uVar5 | (uint)(NAN(fVar21) || NAN(fVar22)) << 0x1c,
         bVar3 = (byte)(uVar5 >> 0x18),
         !(bool)(bVar3 >> 6 & 1) && bVar3 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1))) {
LAB_0034fe14:
        *(float *)(param_1 + 0x104) = fVar26;
      }
      else {
LAB_0034fe1c:
        *(float *)(param_1 + 0x104) = fVar22;
      }
    }
  }
  fVar25 = *(float *)(param_1 + 0x1c);
  uVar5 = in_fpscr & 0xfffffff | (uint)(fVar25 <= fVar20) << 0x1d;
  if (!SUB41(uVar5 >> 0x1d,0)) {
    param_2[3] = param_2[3] + (*(float *)(param_1 + 0x10) - param_2[3]) * fVar25;
    param_2[4] = param_2[4] + (*(float *)(param_1 + 0x14) - param_2[4]) * fVar25;
    param_2[5] = param_2[5] + (*(float *)(param_1 + 0x18) - param_2[5]) * fVar25;
  }
  iVar15 = *(int *)(param_1 + 0x30);
  bVar17 = false;
  if (*(char *)(param_1 + 0x20) == '\0') {
    if (*(int *)(param_1 + 0x264) == 0) {
      uVar31 = func_00114608((uint)ALBW_AS_U32((**(float **)(param_1 + 0x90) * DAT_003501b0)),uVar11);
      *(int *)(param_1 + 0x30) = (int)uVar31;
      iVar14 = func_00553E4C(param_1,1);
      uVar11 = DAT_003501c0;
      uVar12 = 0;
      if (iVar14 != 0) {
        iVar14 = *(int *)(param_1 + 0x30) + iVar14;
        *(int *)(param_1 + 0x30) = iVar14;
        iVar7 = ((int)uVar11 >> 0x1e) - uVar11;
        if ((int)uVar11 < iVar14) goto LAB_0034ffc8;
        uVar12 = uVar11;
        if (iVar14 < iVar7) {
          *(int *)(param_1 + 0x30) = iVar7;
        }
      }
    }
    else {
      uVar12 = 0;
      if (*(char *)(param_1 + 0x248) != '\0') {
        puVar6 = (uint *)func_00541190(*(int *)(param_1 + 0x264));
        uVar11 = *puVar6;
LAB_0034ffc8:
        *(uint *)(param_1 + 0x30) = uVar11;
        uVar12 = uVar11;
      }
    }
  }
  else if (((*(short *)(param_1 + 0x228) < 0x1e) && (*(char *)(param_1 + 0x22a) != '\x01')) &&
          ((*(char *)(param_1 + 0x22a) != '\x02' || (4 < *(byte *)(param_1 + 0x22b))))) {
    if (*(char *)(param_1 + 0x137) == '\0') {
      if (*(char *)(param_1 + 0x139) != '\0') {
        uVar11 = *(uint *)(param_1 + 0x13c);
        goto LAB_0034ffc8;
      }
      bVar17 = *(char *)(param_1 + 0x164) == '\0';
      if (bVar17) {
        uVar12 = *(uint *)(param_1 + 0x174);
        *(uint *)(param_1 + 0x30) = uVar12;
      }
      else {
        uVar31 = func_00114608((uint)ALBW_AS_U32((**(float **)(param_1 + 0x94) * DAT_003501b0)),uVar11);
        uVar12 = (uint)((ulonglong)uVar31 >> 0x20);
        *(int *)(param_1 + 0x30) = (int)uVar31;
      }
      iVar14 = (int)*(short *)(param_1 + 0x29e);
      if ((-1 < iVar14) && (iVar14 < 1)) {
        uVar12 = *(int *)(param_1 + 0x30) + *(int *)(DAT_003501b8 + iVar14 * 0x14);
        *(uint *)(param_1 + 0x30) = uVar12;
      }
    }
    else {
      func_00115C70(&local_128,(float *)(param_1 + 0x158),param_2 + 3);
      iVar14 = func_004904CC(local_124,SQRT(local_128 * local_128 + local_120 * local_120));
      *(int *)(param_1 + 0x30) = iVar14;
      uVar12 = extraout_r1_00;
    }
  }
  else {
    uVar12 = *(uint *)(DAT_003501b4 + 0x20);
    *(uint *)(param_1 + 0x30) = uVar12;
  }
  uVar30 = (ulonglong)DAT_003501bc;
  if (*(char *)(param_1 + 0x22a) == '\x02' && 4 < *(byte *)(param_1 + 0x22b)) {   /* EU 350038 */
    uVar31 = func_00114608(DAT_003501c4,uVar12);
    func_0051D27C((int *)(param_1 + 0x2c),*(int *)(param_1 + 0x30),(int)uVar31);
  }
  else if (bVar17) {
    iVar14 = *(int *)(param_1 + 0x2c);
    if (iVar15 == *(int *)(param_1 + 0x30)) {
      fVar19 = *(float *)(param_1 + 0x188);
      uVar11 = uVar5 & 0xfffffff;
      uVar12 = uVar11 | (uint)(fVar19 < fVar20) << 0x1f | (uint)(fVar19 == fVar20) << 0x1e;
      uVar5 = uVar12 | (uint)(NAN(fVar19) || NAN(fVar20)) << 0x1c;
      bVar3 = (byte)(uVar12 >> 0x18);
      if (!(bool)(bVar3 >> 6 & 1) && bVar3 >> 7 == ((byte)(uVar5 >> 0x1c) & 1)) {
        fVar19 = *(float *)(param_1 + 0x194) + ALBW_AS_F32(uVar28);
        *(float *)(param_1 + 0x194) = fVar19;
        uVar11 = uVar11 | (uint)(fVar19 < *(float *)(param_1 + 0x188)) << 0x1f;
        uVar5 = uVar11 | (uint)(NAN(fVar19) || NAN(*(float *)(param_1 + 0x188))) << 0x1c;
        if ((byte)(uVar11 >> 0x1f) != ((byte)(uVar5 >> 0x1c) & 1)) goto code_r0x003500dc;
        *(undefined4 *)(param_1 + 400) = 0;
        *(undefined4 *)(param_1 + 0x18c) = 0;
        *(float *)(param_1 + 0x188) = fVar20;
        *(float *)(param_1 + 0x184) = fVar20;
        *(float *)(param_1 + 0x194) = fVar20;
        *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_1 + 0x30);
      }
    }
    else {
      local_140 = ALBW_AS_F32((iVar15 - *(int *)(param_1 + 0x30)));
      uVar11 = func_0058E2B8((int *)&local_140);
      uVar12 = *DAT_003501c8;
      uVar31 = func_00110710(uVar11,uVar12);
      iVar15 = DAT_003501cc;
      fVar21 = (float)VectorUnsignedToFloat((int)uVar31,(byte)(uVar5 >> 0x15) & 3);
      fVar26 = (float)VectorUnsignedToFloat
                                ((int)((ulonglong)uVar31 >> 0x20),(byte)(uVar5 >> 0x15) & 3);
      fVar25 = (float)VectorSignedToFloat(uVar12,(byte)(uVar5 >> 0x15) & 3);
      fVar25 = *(float *)(param_1 + 0x188) + fVar21 + fVar26 / fVar25;
      *(float *)(param_1 + 0x188) = fVar25;
      if ((int)ALBW_AS_U32((fVar25 - *(float *)(param_1 + 0x194))) < iVar15) {
        *(float *)(param_1 + 0x188) = *(float *)(param_1 + 0x194) + DAT_003501d0;
      }
      if (DAT_003501d4 < (int)ALBW_AS_U32((*(float *)(param_1 + 0x188) - *(float *)(param_1 + 0x194)))) {
        *(float *)(param_1 + 0x188) = *(float *)(param_1 + 0x194) + fVar19;
      }
      *(undefined4 *)(param_1 + 0x184) = *(undefined4 *)(param_1 + 0x194);
      *(undefined4 *)(param_1 + 0x180) = *(undefined4 *)(param_1 + 0x2c);
      *(float *)(param_1 + 0x194) = *(float *)(param_1 + 0x194) + ALBW_AS_F32(uVar28);
      *(undefined4 *)(param_1 + 0x18c) = *(undefined4 *)(param_1 + 400);
code_r0x003500dc:
      uVar31 = func_0034EFB0(param_1);
      *(int *)(param_1 + 0x2c) = (int)uVar31;
      *(int *)(param_1 + 400) = (int)uVar31 - iVar14;
    }
  }
  else if (*(short *)(param_1 + 0x228) < 0) {
    uVar31 = func_00114608(DAT_0035071c,uVar12);
    func_0051D27C((int *)(param_1 + 0x2c),*(int *)(param_1 + 0x30),(int)uVar31);
  }
  else {
    uVar31 = func_00114608(DAT_00350718,uVar12);
    func_0051D27C((int *)(param_1 + 0x2c),*(int *)(param_1 + 0x30),(int)uVar31);
  }
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 0x2c);
  func_0034CE10(param_1,(int)param_3,param_2 + 3);
  iVar15 = 0;
  switch(*param_3) {
  default:
    func_0036FA1C((undefined4 *)(param_1 + 0x44),0);
    break;
  case 8:
    fVar19 = *(float *)(param_1 + 0xb8);
    fVar25 = *(float *)(param_1 + 0xc4);
    uVar11 = uVar5 & 0xfffffff;
    uVar12 = uVar11 | (uint)(fVar19 < fVar25) << 0x1f | (uint)(fVar19 == fVar25) << 0x1e;
    uVar5 = uVar12 | (uint)(NAN(fVar19) || NAN(fVar25)) << 0x1c;
    bVar3 = (byte)(uVar12 >> 0x18);
    if ((bool)(bVar3 >> 6 & 1) || bVar3 >> 7 != ((byte)(uVar5 >> 0x1c) & 1)) {
      fVar19 = *(float *)(param_1 + 0xbc);
      fVar25 = *(float *)(param_1 + 200);
      uVar12 = uVar11 | (uint)(fVar19 < fVar25) << 0x1f | (uint)(fVar19 == fVar25) << 0x1e;
      uVar5 = uVar12 | (uint)(NAN(fVar19) || NAN(fVar25)) << 0x1c;
      bVar3 = (byte)(uVar12 >> 0x18);
      if ((bool)(bVar3 >> 6 & 1) || bVar3 >> 7 != ((byte)(uVar5 >> 0x1c) & 1)) {
        uVar5 = uVar11 | (uint)(*(float *)(param_1 + 0xc0) <= *(float *)(param_1 + 0xcc)) << 0x1d;
        iVar15 = 0;
        if (SUB41(uVar5 >> 0x1d,0)) goto switchD_00350244_caseD_0;
      }
    }
    iVar15 = 1;
  case 0:
  case 4:
  case 5:
  case 6:
switchD_00350244_caseD_0:
    fStack_148 = param_2[3];
    local_140 = param_2[5];
    fStack_144 = param_2[4] - *(float *)(param_1 + 0x24);
    if (*(char *)(param_1 + 0x22) != '\0') {
      func_00115C70(&fStack_148,&fStack_148,(float *)(param_1 + 0x290));
    }
    func_0036FA58((float *)(param_1 + 0x44),param_3,&fStack_148,iVar15);
  }
  func_0029FA1C(param_1 + 0x98);
  fVar25 = *(float *)(param_1 + 0x24);
  fVar19 = func_00542330(param_1 + 0x98,param_3);
  uVar29 = (ulonglong)DAT_00350720;
  *(float *)(param_1 + 0x24) = fVar25 + (fVar19 - fVar25) * *(float *)(DAT_003501b4 + 8);
  piVar8 = DAT_0034fdf4;
  if (0x3f7fffff < *(int *)(param_1 + 0x108)) goto LAB_003505fc;
  if ((*param_3 == 4 || *param_3 == 5) &&
     ((*(char *)(param_1 + 0x22c) != '\0' || (*(char *)(param_1 + 0x22d) == '\0')))) {
    *(int *)(param_1 + 0x108) = (int)uVar28;
    goto LAB_003505fc;
  }
  func_005569A4(*DAT_0034fdf4,&fStack_144);
  fVar19 = fStack_144 * fStack_144 + local_140 * local_140 + afStack_13c[0] * afStack_13c[0];
  bVar17 = DAT_00350724 < (int)ALBW_AS_U32(fVar19);
  if (DAT_00350724 < (int)ALBW_AS_U32(fVar19)) {
    *(undefined1 *)(param_1 + 0x22e) = 0xff;
  }
  else if ((*(char *)(param_1 + 0x22c) == '\0') &&
          ((*(char *)(param_1 + 0x22d) != '\0' || (*(byte *)(param_1 + 0x22e) < 5)))) {
    bVar17 = true;
    if ((int)ALBW_AS_U32(fVar19) < DAT_00350728) {
      fVar19 = DAT_0035072c;
    }
    *(char *)(param_1 + 0x22e) = *(char *)(param_1 + 0x22e) + '\x01';
  }
  else {
    *(undefined1 *)(param_1 + 0x22e) = 0xff;
    uVar11 = func_00556A90(*piVar8);
    if (((uVar11 != 0) && (iVar15 = func_0052FBA0(*DAT_00350730 + 0x3dbbc,uVar11), iVar15 != 0)) &&
       ((((iVar15 = func_00588BE4(iVar15), iVar15 == *DAT_00350734 || (iVar15 == *DAT_00350738)) ||
         (iVar15 == *DAT_0035073c)) ||
        (bVar17 = iVar15 == *DAT_00350740 && bVar17, iVar15 == *DAT_00350740)))) {
      bVar17 = true;
    }
  }
  fVar25 = fStack_144 * fStack_144 + afStack_13c[0] * afStack_13c[0];
  if (bVar17) {
LAB_003505b8:
    fVar25 = SQRT(fVar19) * DAT_00350748;
    if (ALBW_AS_F32(uVar29) < SQRT(fVar19) * DAT_00350748) {
      fVar25 = ALBW_AS_F32(uVar29);
    }
    fVar25 = *(float *)(param_1 + 0x108) + fVar25;
    fVar19 = ALBW_AS_F32(uVar28);
    uVar11 = uVar5 & 0xfffffff | (uint)(fVar25 < fVar19) << 0x1f | (uint)(fVar25 == fVar19) << 0x1e;
    uVar5 = uVar11 | (uint)(NAN(fVar25) || NAN(fVar19)) << 0x1c;
    bVar3 = (byte)(uVar11 >> 0x18);
    if (!(bool)(bVar3 >> 6 & 1) && bVar3 >> 7 == ((byte)(uVar5 >> 0x1c) & 1)) {
      fVar25 = fVar19;
    }
    *(float *)(param_1 + 0x108) = fVar25;
  }
  else {
    uVar11 = uVar5 & 0xfffffff | (uint)(fVar25 < fVar20) << 0x1f | (uint)(fVar25 == fVar20) << 0x1e;
    uVar5 = uVar11 | (uint)(NAN(fVar25) || NAN(fVar20)) << 0x1c;
    bVar3 = (byte)(uVar11 >> 0x18);
    if ((!(bool)(bVar3 >> 6 & 1) && bVar3 >> 7 == ((byte)(uVar5 >> 0x1c) & 1)) &&
       (bVar3 = func_00588F20(*DAT_0034fde8,*(undefined4 *)(*piVar8 + 0x1c),DAT_00350744),
       bVar3 != 0)) {
      iVar15 = func_004904CC(fStack_144,afStack_13c[0]);
      if ((bVar3 & 4) == 0) {
        if ((bVar3 & 8) != 0) {
          local_124 = ALBW_AS_F32(((*(int *)(param_1 + 0xc) + 0x40000000) - iVar15));
          uVar11 = func_0058E2B8((int *)&local_124);
          goto joined_r0x00350554;
        }
      }
      else {
        local_124 = ALBW_AS_F32(((*(int *)(param_1 + 0xc) + -0x40000000) - iVar15));
        uVar11 = func_0058E2B8((int *)&local_124);
joined_r0x00350554:
        if (uVar11 < 0x40000000) goto LAB_003505b8;
      }
      if ((bVar3 & 2) == 0) {
        if ((bVar3 & 1) == 0) goto LAB_003505ec;
        fStack_148 = ALBW_AS_F32(((*(int *)(param_1 + 0xc) + -0x80000000) - iVar15));
        uVar11 = func_0058E2B8((int *)&fStack_148);
      }
      else {
        fStack_148 = ALBW_AS_F32((*(int *)(param_1 + 0xc) - iVar15));
        uVar11 = func_0058E2B8((int *)&fStack_148);
      }
      if (uVar11 < 0x40000000) goto LAB_003505b8;
    }
LAB_003505ec:
    *(float *)(param_1 + 0x108) = *(float *)(param_1 + 0x108) * DAT_0035074c;
  }
LAB_003505fc:
  uVar31 = CONCAT44(fVar20,DAT_00350750);
  iStack_60 = 1;
  do {
    pfVar16 = *(float **)(param_3 + 4);
    fStack_154 = *pfVar16;
    fStack_150 = pfVar16[1];
    fVar19 = pfVar16[2];
    bVar17 = *(char *)(param_1 + 0x20) != '\0';
    cVar1 = '\0';
    if (bVar17) {
      cVar1 = *(char *)(param_1 + 0x137);
    }
    fStack_14c = fVar19;
    if (bVar17 && cVar1 != '\0') {
      func_0036FA1C((undefined4 *)(param_1 + 0x44),0);
    }
    func_005581D4((float *)(param_1 + 0x44),&fStack_144,(uint)(*(char *)(param_1 + 0x20) == '\0'),
                  (byte *)0x0);
    func_00115C54(&fStack_154,&fStack_154,&fStack_144);
    if (*(char *)(param_1 + 0x20) == '\0') {
      fVar20 = *(float *)(param_1 + 0x24);
    }
    else {
      fVar20 = *(float *)(param_1 + 0x1c4);
    }
    fStack_150 = fStack_150 + fVar20;
    if ((*(char *)(param_1 + 0x20) == '\0') && (*(int *)(param_1 + 0x264) != 0)) {
      piVar8 = (int *)func_00541190(*(int *)(param_1 + 0x264));
      iVar14 = *DAT_0034fdf4;
      iVar15 = *(int *)(param_1 + 0x264);
      pfVar16 = *(float **)(iVar14 + 0x1c);
      fVar20 = *pfVar16 - *(float *)(iVar15 + 0x3d0);
      fVar19 = pfVar16[2] - *(float *)(iVar15 + 0x3d8);
      fVar19 = SQRT(fVar20 * fVar20 + fVar19 * fVar19);
      uVar5 = uVar5 & 0xfffffff;
      if (pfVar16[1] <= ALBW_AS_F32(piVar8[0xd])) {
        *(undefined1 *)(param_1 + 0x250) = 0;
      }
      else {
        *(bool *)(param_1 + 0x250) = ALBW_AS_F32(piVar8[7]) <= fVar19;
      }
      uVar11 = uVar5;
      if (*(char *)(param_1 + 0x250) != '\0') {
        fVar20 = ALBW_AS_F32(piVar8[7]);
        fVar25 = ALBW_AS_F32(piVar8[8]);
        uVar11 = uVar5 | (uint)(fVar25 < fVar20) << 0x1f;
        fVar26 = ALBW_AS_F32(uVar28);
        if (fVar25 == fVar20 || SUB41(uVar11 >> 0x1f,0) != (NAN(fVar25) || NAN(fVar20))) {
          *(float *)(param_1 + 0x254) = fVar26;
        }
        else {
          fVar19 = (fVar19 - fVar20) / (fVar25 - fVar20);
          uVar11 = uVar5 | (uint)(fVar19 < fVar26) << 0x1f;
          if (fVar19 != fVar26 && SUB41(uVar11 >> 0x1f,0) == (NAN(fVar19) || NAN(fVar26))) {
            fVar19 = fVar26;
          }
          *(float *)(param_1 + 0x254) = fVar19;
        }
      }
      fStack_154 = *(float *)(iVar15 + 0x3d0);
      fStack_14c = *(float *)(iVar15 + 0x3d8);
      fVar19 = ALBW_AS_F32(piVar8[0xd]);
      fVar20 = ALBW_AS_F32(piVar8[2]);
      fVar25 = *(float *)(*(int *)(iVar14 + 0x1c) + 4);
      uVar5 = uVar11 & 0xfffffff | (uint)(fVar25 == fVar19) << 0x1e |
              (uint)(fVar19 <= fVar25) << 0x1d;
      bVar3 = (byte)(uVar5 >> 0x18);
      if (!(bool)(bVar3 >> 5 & 1) || (bool)(bVar3 >> 6)) {
        fVar20 = ALBW_AS_F32(piVar8[3]);
      }
      else {
        fVar26 = fVar19 + ALBW_AS_F32(piVar8[0xe]);
        uVar11 = uVar11 & 0xfffffff | (uint)(fVar26 < fVar25) << 0x1f;
        uVar5 = uVar11 | (uint)(NAN(fVar26) || NAN(fVar25)) << 0x1c;
        if ((byte)(uVar11 >> 0x1f) == ((byte)(uVar5 >> 0x1c) & 1)) {
          fVar25 = fVar25 - fVar19;
          fVar19 = ALBW_AS_F32(piVar8[3]);
          fVar20 = fVar19 + (fVar20 - fVar19) * (fVar25 / ALBW_AS_F32(piVar8[0xe]));
        }
      }
      fStack_150 = fVar20 + fStack_150;
      func_00115C70(afStack_5c,(float *)(*(int *)(param_1 + 0x264) + 0x3d0),*(float **)(param_3 + 4)
                   );
      if (*(char *)(param_1 + 0x250) != '\0') {
        iVar15 = func_004904CC(afStack_5c[0],fStack_54);
        *(int *)(param_1 + 600) = iVar15;
      }
      func_00491E80(afStack_c0,0,*(uint *)(param_1 + 600),0);
      iStack_fc = piVar8[1];
      local_128 = ALBW_AS_F32(uVar28);
      local_124 = ALBW_AS_F32(((ulonglong)uVar31 >> 0x20));
      local_120 = local_124;
      fStack_11c = local_124;
      fStack_118 = local_124;
      fStack_114 = local_128;
      fStack_110 = local_124;
      fStack_10c = local_124;
      fStack_108 = local_124;
      fStack_104 = local_124;
      fStack_100 = local_128;
      func_00491E80(afStack_f8,-*piVar8,0,0);
      func_001157FC(afStack_f8,afStack_f8,&local_128);
      func_001157FC(afStack_90,afStack_c0,afStack_f8);
      fStack_50 = fStack_84;
      uStack_4c = uStack_74;
      uStack_48 = uStack_64;
      func_00115C54((float *)(param_1 + 0x23c),&fStack_154,&fStack_50);
      *(undefined1 *)(param_1 + 0x248) = 1;
      *(undefined1 *)(param_1 + 0x249) = 0;
      *(undefined1 *)(param_1 + 0x24a) = 0;
    }
    else {
      *(int *)(param_1 + 0x25c) = (int)((ulonglong)uVar31 >> 0x20);
    }
    if (((*(char *)(param_1 + 0x20) == '\0') &&
        (iVar15 = *(int *)(param_1 + 0x90), *(char *)(iVar15 + 0x24) != '\0')) &&
       ((*(char *)(param_1 + 0x133) == '\0' || (*(char *)(*DAT_0034fde8 + 0x95) == '\0')))) {
      fVar20 = func_005548EC(param_1,1);
      fVar19 = *(float *)(iVar15 + 0x18) + *(float *)(param_1 + 0x104);
      fStack_158 = (fVar20 + fVar19) - fStack_150;
      fVar20 = ALBW_AS_F32(((ulonglong)uVar31 >> 0x20));
      uVar11 = uVar5 & 0xfffffff | (uint)(fStack_158 < fVar20) << 0x1f |
               (uint)(fStack_158 == fVar20) << 0x1e;
      uVar5 = uVar11 | (uint)(NAN(fStack_158) || NAN(fVar20)) << 0x1c;
      bVar3 = (byte)(uVar11 >> 0x18);
      if ((bool)(bVar3 >> 6 & 1) || bVar3 >> 7 != ((byte)(uVar5 >> 0x1c) & 1)) {
        fStack_158 = -fStack_158;
      }
      iVar15 = *DAT_0034fde8;
      cVar1 = *(char *)(iVar15 + 0x88);
      bVar17 = cVar1 == '\0';
      if (bVar17) {
        cVar1 = *(char *)(iVar15 + 0x94);
      }
      bVar18 = bVar17 && cVar1 == '\0';
      if (bVar17 && cVar1 == '\0') {
        bVar18 = *(char *)(iVar15 + 0x95) == '\0';
      }
      if (!bVar18) {
        func_0012159C(*(int *)(iVar15 + 0x18));
      }
LAB_00350a40:
      if (*(char *)(param_1 + 0x20) == '\0') {
LAB_00350a4c:
        *(float *)(param_1 + 0x1bc) = fStack_158;
      }
    }
    else {
      fStack_158 = *(float *)(param_1 + 0xa0);
      if (*(char *)(param_1 + 0x20) == '\0') {
        iVar15 = *(int *)(param_1 + 0x90);
        if ((*(char *)(iVar15 + 0x24) != '\0') && (-1 < *(int *)(param_1 + 0x110))) {
          fVar20 = (float)VectorSignedToFloat(*(int *)(param_1 + 0x110),(byte)(uVar5 >> 0x15) & 3);
          fVar20 = fVar20 / *(float *)(param_1 + 0x120);
          if ((int)ALBW_AS_U32(fVar20) < 0x3f800000) {
            fVar25 = func_005548EC(param_1,1);
            fVar19 = *(float *)(iVar15 + 0x18) + *(float *)(param_1 + 0x104);
            fVar25 = (fVar25 + fVar19) - fStack_150;
            fVar26 = ALBW_AS_F32(((ulonglong)uVar31 >> 0x20));
            uVar11 = uVar5 & 0xfffffff | (uint)(fVar25 < fVar26) << 0x1f |
                     (uint)(fVar25 == fVar26) << 0x1e;
            uVar5 = uVar11 | (uint)(NAN(fVar25) || NAN(fVar26)) << 0x1c;
            bVar3 = (byte)(uVar11 >> 0x18);
            if ((bool)(bVar3 >> 6 & 1) || bVar3 >> 7 != ((byte)(uVar5 >> 0x1c) & 1)) {
              fVar25 = -fVar25;
            }
            fStack_158 = fVar25 + (fStack_158 - fVar25) * fVar20;
            goto LAB_00350a40;
          }
        }
        goto LAB_00350a4c;
      }
    }
    if (*(int *)(param_1 + 0x264) == 0) {
      *(int *)(param_1 + 0x24c) = (int)((ulonglong)uVar31 >> 0x20);
    }
    else {
      iVar15 = func_00541190(*(int *)(param_1 + 0x264));
      fVar25 = *(float *)(param_1 + 0x24c);
      fVar20 = *(float *)(iVar15 + 4);
      uVar11 = uVar5 & 0xfffffff;
      if (fVar25 == ALBW_AS_F32(((ulonglong)uVar31 >> 0x20))) {
        uVar12 = uVar11 | (uint)(fStack_158 < fVar20) << 0x1f | (uint)(fStack_158 == fVar20) << 0x1e
                 | (uint)(fVar20 <= fStack_158) << 0x1d;
        uVar5 = uVar12 | (uint)(NAN(fStack_158) || NAN(fVar20)) << 0x1c;
        bVar3 = (byte)(uVar12 >> 0x18);
        fVar25 = fVar20;
        if ((bool)(bVar3 >> 5 & 1)) {
          fVar25 = fStack_158;
          if (!(bool)(bVar3 >> 6 & 1) && bVar3 >> 7 == ((byte)(uVar5 >> 0x1c) & 1)) {
            fVar19 = fStack_158 - ALBW_AS_F32(uVar31);
            uVar5 = uVar11 | (uint)(fVar19 == fVar20) << 0x1e | (uint)(fVar20 <= fVar19) << 0x1d;
            bVar3 = (byte)(uVar5 >> 0x18);
            fVar25 = fVar20;
            if (((bool)(bVar3 >> 5 & 1) && !(bool)(bVar3 >> 6)) &&
               (uVar11 = uVar11 | (uint)(fVar19 < fStack_158) << 0x1f |
                         (uint)(fVar19 == fStack_158) << 0x1e,
               uVar5 = uVar11 | (uint)(NAN(fVar19) || NAN(fStack_158)) << 0x1c,
               bVar3 = (byte)(uVar11 >> 0x18),
               (bool)(bVar3 >> 6 & 1) || bVar3 >> 7 != ((byte)(uVar5 >> 0x1c) & 1)))
            goto LAB_00350ae0;
          }
        }
        else {
          fVar19 = fStack_158 + ALBW_AS_F32(uVar31);
          uVar5 = uVar11 | (uint)(fVar20 == fVar19) << 0x1e | (uint)(fVar19 <= fVar20) << 0x1d;
          bVar3 = (byte)(uVar5 >> 0x18);
          if (((bool)(bVar3 >> 5 & 1) && !(bool)(bVar3 >> 6)) &&
             (uVar11 = uVar11 | (uint)(fStack_158 < fVar19) << 0x1f |
                       (uint)(fStack_158 == fVar19) << 0x1e,
             uVar5 = uVar11 | (uint)(NAN(fStack_158) || NAN(fVar19)) << 0x1c,
             bVar3 = (byte)(uVar11 >> 0x18),
             (bool)(bVar3 >> 6 & 1) || bVar3 >> 7 != ((byte)(uVar5 >> 0x1c) & 1))) {
LAB_00350ae0:
            fVar25 = fVar19;
          }
        }
        fStack_158 = fVar25;
        *(float *)(param_1 + 0x24c) = fStack_158;
      }
      else {
        uVar12 = uVar11 | (uint)(fVar25 < fVar20) << 0x1f | (uint)(fVar25 == fVar20) << 0x1e |
                 (uint)(fVar20 <= fVar25) << 0x1d;
        uVar5 = uVar12 | (uint)(NAN(fVar25) || NAN(fVar20)) << 0x1c;
        fVar19 = *(float *)(iVar15 + 0x10);
        bVar3 = (byte)(uVar12 >> 0x18);
        if ((bool)(bVar3 >> 5 & 1)) {
          if (!(bool)(bVar3 >> 6 & 1) && bVar3 >> 7 == ((byte)(uVar5 >> 0x1c) & 1)) {
            fVar19 = fVar25 - fVar19;
            uVar5 = uVar11 | (uint)(fVar19 == fVar20) << 0x1e | (uint)(fVar20 <= fVar19) << 0x1d;
            bVar3 = (byte)(uVar5 >> 0x18);
            if ((!(bool)(bVar3 >> 5 & 1) || (bool)(bVar3 >> 6)) ||
               (uVar11 = uVar11 | (uint)(fVar19 < fVar25) << 0x1f | (uint)(fVar19 == fVar25) << 0x1e
               , uVar5 = uVar11 | (uint)(NAN(fVar19) || NAN(fVar25)) << 0x1c,
               bVar3 = (byte)(uVar11 >> 0x18),
               !(bool)(bVar3 >> 6 & 1) && bVar3 >> 7 == ((byte)(uVar5 >> 0x1c) & 1)))
            goto LAB_00350b44;
            goto LAB_00350b4c;
          }
        }
        else {
          fVar19 = fVar25 + fVar19;
          uVar5 = uVar11 | (uint)(fVar20 == fVar19) << 0x1e | (uint)(fVar19 <= fVar20) << 0x1d;
          bVar3 = (byte)(uVar5 >> 0x18);
          if ((!(bool)(bVar3 >> 5 & 1) || (bool)(bVar3 >> 6)) ||
             (uVar11 = uVar11 | (uint)(fVar25 < fVar19) << 0x1f | (uint)(fVar25 == fVar19) << 0x1e,
             uVar5 = uVar11 | (uint)(NAN(fVar25) || NAN(fVar19)) << 0x1c,
             bVar3 = (byte)(uVar11 >> 0x18),
             !(bool)(bVar3 >> 6 & 1) && bVar3 >> 7 == ((byte)(uVar5 >> 0x1c) & 1))) {
LAB_00350b44:
            *(float *)(param_1 + 0x24c) = fVar20;
          }
          else {
LAB_00350b4c:
            *(float *)(param_1 + 0x24c) = fVar19;
          }
        }
        fStack_158 = *(float *)(param_1 + 0x24c);
      }
    }
    fVar20 = ALBW_AS_F32(uVar30);
    uVar9 = (undefined4)uVar29;
    if (*(char *)(param_1 + 0x134) == '\0') goto LAB_00350c40;
    fVar25 = *(float *)(param_1 + 0xb8);
    fVar26 = *(float *)(param_1 + 0xc4);
    uVar11 = uVar5 & 0xfffffff;
    uVar12 = uVar11 | (uint)(fVar25 < fVar26) << 0x1f | (uint)(fVar25 == fVar26) << 0x1e;
    uVar5 = uVar12 | (uint)(NAN(fVar25) || NAN(fVar26)) << 0x1c;
    bVar3 = (byte)(uVar12 >> 0x18);
    if (!(bool)(bVar3 >> 6 & 1) && bVar3 >> 7 == ((byte)(uVar5 >> 0x1c) & 1)) {
LAB_00350c24:
      func_002E15CC((float *)(param_1 + 0xb8),&fStack_154,&fStack_158,1,1,0,fVar25,fVar26,fVar19);
      goto LAB_00350c40;
    }
    fVar25 = *(float *)(param_1 + 0xbc);
    fVar26 = *(float *)(param_1 + 200);
    uVar12 = uVar11 | (uint)(fVar25 < fVar26) << 0x1f | (uint)(fVar25 == fVar26) << 0x1e;
    uVar5 = uVar12 | (uint)(NAN(fVar25) || NAN(fVar26)) << 0x1c;
    bVar3 = (byte)(uVar12 >> 0x18);
    if (!(bool)(bVar3 >> 6 & 1) && bVar3 >> 7 == ((byte)(uVar5 >> 0x1c) & 1)) goto LAB_00350c24;
    fVar25 = *(float *)(param_1 + 0xc0);
    fVar26 = *(float *)(param_1 + 0xcc);
    uVar11 = uVar11 | (uint)(fVar25 < fVar26) << 0x1f | (uint)(fVar25 == fVar26) << 0x1e;
    uVar5 = uVar11 | (uint)(NAN(fVar25) || NAN(fVar26)) << 0x1c;
    bVar3 = (byte)(uVar11 >> 0x18);
    if (!(bool)(bVar3 >> 6 & 1) && bVar3 >> 7 == ((byte)(uVar5 >> 0x1c) & 1)) goto LAB_00350c24;
    func_002E15CC((float *)(param_1 + 0xb8),&fStack_154,&fStack_158,iStack_60,0,0,fVar25,fVar26,
                  fVar19);
    fVar20 = ALBW_AS_F32(uVar30);
    uVar9 = (undefined4)uVar29;
    if ((*(char *)(param_1 + 0x20) != '\0') || (iStack_60 == 0)) break;
    func_004D7FBC(&fStack_148,&fStack_154,*(uint *)(param_1 + 0x30),*(uint *)(param_1 + 0x38),
                  fStack_158);
    fVar20 = func_00542350(param_1 + 0x98,0);
    iVar15 = func_0036F874((float *)(param_1 + 0x44),&fStack_154,&fStack_148,fVar20);
    fVar20 = ALBW_AS_F32(uVar30);
    uVar9 = (undefined4)uVar29;
    if (iVar15 != 0) break;
    iStack_60 = 0;
  } while( true );
  *(undefined4 *)(param_1 + 0xd4) = 0;
  *(int *)(param_1 + 0xd8) = (int)((ulonglong)uVar31 >> 0x20);
LAB_00350c40:
  fVar25 = ALBW_AS_F32(((ulonglong)uVar31 >> 0x20));
  if ((*(char *)(param_1 + 0x20) == '\0') &&
     (((int)((uint)*(ushort *)(param_3 + 0x1c) << 0x1d) < 0 ||
      (func_003517A4(param_1,&fStack_154,*(undefined4 *)(param_3 + 4),(float *)0x0,fStack_158),
      *(char *)(param_1 + 0x20) == '\0')))) {
    fStack_148 = fStack_154;
    fStack_144 = fStack_150;
    local_140 = fStack_14c;
    local_128 = *DAT_003514d4;
    local_124 = DAT_003514d4[1];
    local_120 = DAT_003514d4[2];
    if (*(int *)(param_1 + 0x264) == 0) {
      func_002E1424((float *)(param_1 + 0xdc),&fStack_154);
    }
    if (*(char *)(param_1 + 0x134) != '\0') {
      fVar26 = *(float *)(param_1 + 0xdc);
      fVar21 = *(float *)(param_1 + 0xe8);
      uVar11 = uVar5 & 0xfffffff;
      uVar12 = uVar11 | (uint)(fVar26 < fVar21) << 0x1f | (uint)(fVar26 == fVar21) << 0x1e;
      uVar5 = uVar12 | (uint)(NAN(fVar26) || NAN(fVar21)) << 0x1c;
      bVar3 = (byte)(uVar12 >> 0x18);
      if ((bool)(bVar3 >> 6 & 1) || bVar3 >> 7 != ((byte)(uVar5 >> 0x1c) & 1)) {
        fVar26 = *(float *)(param_1 + 0xe0);
        fVar21 = *(float *)(param_1 + 0xec);
        uVar12 = uVar11 | (uint)(fVar26 < fVar21) << 0x1f | (uint)(fVar26 == fVar21) << 0x1e;
        uVar5 = uVar12 | (uint)(NAN(fVar26) || NAN(fVar21)) << 0x1c;
        bVar3 = (byte)(uVar12 >> 0x18);
        if ((bool)(bVar3 >> 6 & 1) || bVar3 >> 7 != ((byte)(uVar5 >> 0x1c) & 1)) {
          fVar26 = *(float *)(param_1 + 0xe4);
          fVar21 = *(float *)(param_1 + 0xf0);
          uVar11 = uVar11 | (uint)(fVar26 < fVar21) << 0x1f | (uint)(fVar26 == fVar21) << 0x1e;
          uVar5 = uVar11 | (uint)(NAN(fVar26) || NAN(fVar21)) << 0x1c;
          bVar3 = (byte)(uVar11 >> 0x18);
          if ((bool)(bVar3 >> 6 & 1) || bVar3 >> 7 != ((byte)(uVar5 >> 0x1c) & 1)) {
            func_002E15CC((float *)(param_1 + 0xdc),&fStack_154,&fStack_158,0,0,1,fVar26,fVar21,
                          fVar19);
            func_00115C70(&local_128,&fStack_154,&fStack_148);
            func_004D7FBC(&fStack_11c,&fStack_154,*(uint *)(param_1 + 0x30),
                          *(uint *)(param_1 + 0x38),fStack_158);
            fVar19 = func_00542350(param_1 + 0x98,0);
            func_002E12C0(param_1 + 0xdc,&fStack_110,&fStack_154,&fStack_11c,param_1 + 0x44,fVar19);
            func_00115C54(&fStack_154,&fStack_154,&fStack_110);
            *(undefined4 *)(param_1 + 0xf8) = 0;
            *(float *)(param_1 + 0xfc) = fVar25;
            goto LAB_00350da4;
          }
        }
      }
      func_002E15CC((float *)(param_1 + 0xdc),&fStack_154,&fStack_158,1,1,0,fVar26,fVar21,fVar19);
    }
LAB_00350da4:
    fVar19 = *(float *)(param_1 + 0xdc);
    fVar26 = *(float *)(param_1 + 0xe8);
    uVar11 = uVar5 & 0xfffffff;
    uVar12 = uVar11 | (uint)(fVar19 < fVar26) << 0x1f | (uint)(fVar19 == fVar26) << 0x1e;
    uVar5 = uVar12 | (uint)(NAN(fVar19) || NAN(fVar26)) << 0x1c;
    bVar3 = (byte)(uVar12 >> 0x18);
    if (!(bool)(bVar3 >> 6 & 1) && bVar3 >> 7 == ((byte)(uVar5 >> 0x1c) & 1)) goto LAB_00350dec;
    fVar19 = *(float *)(param_1 + 0xe0);
    fVar26 = *(float *)(param_1 + 0xec);
    uVar12 = uVar11 | (uint)(fVar19 < fVar26) << 0x1f | (uint)(fVar19 == fVar26) << 0x1e;
    uVar5 = uVar12 | (uint)(NAN(fVar19) || NAN(fVar26)) << 0x1c;
    bVar3 = (byte)(uVar12 >> 0x18);
    if (!(bool)(bVar3 >> 6 & 1) && bVar3 >> 7 == ((byte)(uVar5 >> 0x1c) & 1)) goto LAB_00350dec;
    fVar19 = *(float *)(param_1 + 0xe4);
    fVar26 = *(float *)(param_1 + 0xf0);
    uVar11 = uVar11 | (uint)(fVar19 < fVar26) << 0x1f | (uint)(fVar19 == fVar26) << 0x1e;
    uVar5 = uVar11 | (uint)(NAN(fVar19) || NAN(fVar26)) << 0x1c;
    bVar3 = (byte)(uVar11 >> 0x18);
    if ((!(bool)(bVar3 >> 6 & 1) && bVar3 >> 7 == ((byte)(uVar5 >> 0x1c) & 1)) ||
       ((*(ushort *)(param_3 + 0x1c) & 4) != 0)) goto LAB_00350dec;
    func_003517A4(param_1,&fStack_154,*(undefined4 *)(param_3 + 4),&fStack_148,fStack_158);
    fVar19 = SQRT(local_128 * local_128 + local_124 * local_124 + local_120 * local_120);
    if ((*(char *)(param_1 + 0x22) == '\0') ||
       (uVar5 = uVar5 & 0xfffffff | (uint)(fVar19 == fVar25) << 0x1e, !SUB41(uVar5 >> 0x1e,0))) {
      *(float *)(param_1 + 0x2cc) = fVar19;
    }
    else if (DAT_003514e4 <
             (int)ALBW_AS_U32(SQRT(*(float *)(param_1 + 0x290) * *(float *)(param_1 + 0x290) +
                       *(float *)(param_1 + 0x294) * *(float *)(param_1 + 0x294) +
                       *(float *)(param_1 + 0x298) * *(float *)(param_1 + 0x298)))) {
      *(undefined4 *)(param_1 + 0x108) = *(undefined4 *)(param_1 + 0x10c);
    }
    if ((int)*(float *)(param_1 + 0x108) < 0x3f800000) {
      uVar11 = uVar5 & 0xfffffff;
      uVar5 = uVar11 | (uint)(*(float *)(param_1 + 0x2cc) <= fVar25) << 0x1d;
      if (!SUB41(uVar5 >> 0x1d,0)) {
        fVar19 = SQRT((fStack_154 - fStack_148) * (fStack_154 - fStack_148) +
                      (fStack_150 - fStack_144) * (fStack_150 - fStack_144) +
                      (fStack_14c - local_140) * (fStack_14c - local_140)) /
                 *(float *)(param_1 + 0x2cc);
        uVar5 = uVar11 | (uint)(fVar19 <= *(float *)(param_1 + 0x108)) << 0x1d;
        if (!SUB41(uVar5 >> 0x1d,0)) {
          fVar26 = fVar19;
          if (0x3f800000 < (int)ALBW_AS_U32(fVar19)) {
            fVar26 = ALBW_AS_F32(uVar28);
          }
          *(float *)(param_1 + 0x108) = fVar19;
          *(float *)(param_1 + 0x108) = fVar26;
        }
      }
    }
  }
  else {
LAB_00350dec:
    *(float *)(param_1 + 0x290) = fVar25;
    *(float *)(param_1 + 0x294) = fVar25;
    *(float *)(param_1 + 0x298) = fVar25;
  }
  *(undefined1 *)(param_1 + 0x134) = 1;
  if (*(char *)(param_1 + 0x164) == '\0') {
    uVar11 = (uint)*param_3;
  }
  else {
    uVar11 = 7;
  }
  pfVar16 = (float *)(DAT_003514d8 + uVar11 * 0xc);
  fVar26 = ALBW_AS_F32(uVar28);
  uVar11 = uVar5 & 0xfffffff | 0x40000000;
  bVar17 = SUB41(uVar11 >> 0x1e,0);
  fVar19 = (fVar26 - SQRT(fVar26 - *pfVar16)) * *(float *)(param_1 + 0x108);
  if (!bVar17) {
    fVar19 = fVar26;
  }
  uVar31 = CONCAT44(fVar25,fVar19);
  if ((((bVar17) && ((int)ALBW_AS_U32(fVar19) < DAT_003514dc)) && (*(char *)(param_1 + 0x133) != '\0')) &&
     ((-1 < *(int *)(param_1 + 0x110) &&
      (*(int *)(*DAT_003514e0 + 0x8c) != *(int *)(param_1 + 0x124))))) {
    fVar19 = (float)VectorSignedToFloat(*(int *)(param_1 + 0x110),(byte)(uVar11 >> 0x15) & 3);
    uVar11 = uVar5 & 0xfffffff | (uint)(*(float *)(param_1 + 0x120) == fVar19) << 0x1e |
             (uint)(fVar19 <= *(float *)(param_1 + 0x120)) << 0x1d;
    bVar3 = (byte)(uVar11 >> 0x18);
    if ((bool)(bVar3 >> 5 & 1) && !(bool)(bVar3 >> 6)) {
      uVar31 = CONCAT44(fVar25,uVar9);
    }
  }
  fVar25 = ALBW_AS_F32(((ulonglong)uVar28 >> 0x20));
  fVar19 = param_2[3];
  uVar28 = *(undefined8 *)(param_2 + 4);
  if (((*(char *)(param_1 + 0x22c) == '\0') || (*(char *)(param_1 + 0x22d) != '\0')) &&
     ((*(char *)(param_1 + 0x20) == '\0' ||
      ((((*(char *)(param_1 + 0x164) != '\0' || (*(short *)(param_1 + 0x29e) < 0)) ||
        (0 < *(short *)(param_1 + 0x29e))) || (*(char *)(param_1 + 0x2b8) == '\0')))))) {
    if (local_c4 == 0) {
      func_004D838C(param_2 + 3,&fStack_154,ALBW_AS_F32(uVar31),pfVar16[1],pfVar16[2]);
    }
    else {
      func_004D838C(param_2 + 3,(float *)(param_1 + 0x14c),ALBW_AS_F32(uVar31),pfVar16[1],pfVar16[2]);
    }
  }
  fVar26 = *(float *)(param_1 + 0x1c);
  fVar21 = ALBW_AS_F32(((ulonglong)uVar31 >> 0x20));
  uVar11 = uVar11 & 0xfffffff | (uint)(fVar26 < fVar21) << 0x1f | (uint)(fVar26 == fVar21) << 0x1e;
  uVar5 = uVar11 | (uint)(NAN(fVar26) || NAN(fVar21)) << 0x1c;
  bVar3 = (byte)(uVar11 >> 0x18);
  if (!(bool)(bVar3 >> 6 & 1) && bVar3 >> 7 == ((byte)(uVar5 >> 0x1c) & 1)) {
    fVar21 = param_2[3];
    param_2[3] = fVar21 + (fVar19 - fVar21) * fVar26;
    param_2[4] = param_2[4] + (ALBW_AS_F32(uVar28) - param_2[4]) * fVar26;
    param_2[5] = param_2[5] + (ALBW_AS_F32(((ulonglong)uVar28 >> 0x20)) - param_2[5]) * fVar26;
  }
  if (*(char *)(param_1 + 0x164) == '\0') {
    func_0034DF14(param_1,param_2,(int)param_3,iVar4,fStack_158);
    if (*(char *)(param_1 + 0x20) == '\0') {
      fVar19 = *(float *)(param_1 + 0xdc);
      fVar26 = *(float *)(param_1 + 0xe8);
      uVar11 = uVar5 & 0xfffffff;
      uVar12 = uVar11 | (uint)(fVar19 < fVar26) << 0x1f | (uint)(fVar19 == fVar26) << 0x1e;
      uVar5 = uVar12 | (uint)(NAN(fVar19) || NAN(fVar26)) << 0x1c;
      bVar3 = (byte)(uVar12 >> 0x18);
      if ((bool)(bVar3 >> 6 & 1) || bVar3 >> 7 != ((byte)(uVar5 >> 0x1c) & 1)) {
        fVar19 = *(float *)(param_1 + 0xe0);
        fVar26 = *(float *)(param_1 + 0xec);
        uVar12 = uVar11 | (uint)(fVar19 < fVar26) << 0x1f | (uint)(fVar19 == fVar26) << 0x1e;
        uVar5 = uVar12 | (uint)(NAN(fVar19) || NAN(fVar26)) << 0x1c;
        bVar3 = (byte)(uVar12 >> 0x18);
        if ((bool)(bVar3 >> 6 & 1) || bVar3 >> 7 != ((byte)(uVar5 >> 0x1c) & 1)) {
          fVar19 = *(float *)(param_1 + 0xe4);
          fVar26 = *(float *)(param_1 + 0xf0);
          uVar12 = uVar11 | (uint)(fVar19 < fVar26) << 0x1f | (uint)(fVar19 == fVar26) << 0x1e;
          uVar5 = uVar12 | (uint)(NAN(fVar19) || NAN(fVar26)) << 0x1c;
          bVar3 = (byte)(uVar12 >> 0x18);
          if ((bool)(bVar3 >> 6 & 1) || bVar3 >> 7 != ((byte)(uVar5 >> 0x1c) & 1)) {
            fVar19 = ALBW_AS_F32(((ulonglong)uVar31 >> 0x20));
            uVar5 = uVar11 | (uint)(*(float *)(param_1 + 0x290) == fVar19) << 0x1e;
            bVar17 = false;
            if (SUB41(uVar5 >> 0x1e,0)) {
              uVar5 = uVar11 | (uint)(*(float *)(param_1 + 0x294) == fVar19) << 0x1e;
              bVar17 = SUB41(uVar5 >> 0x1e,0);
            }
            bVar18 = false;
            if (bVar17) {
              uVar5 = uVar5 & 0xfffffff | (uint)(*(float *)(param_1 + 0x298) == fVar19) << 0x1e;
              bVar18 = SUB41(uVar5 >> 0x1e,0);
            }
            if ((!bVar18) &&
               ((bVar3 = *param_3, bVar3 == 0 || bVar3 == 4 || (bVar3 == 5 || bVar3 == 6)))) {
              fStack_144 = fVar19;
              local_140 = fVar19;
              afStack_13c[0] = fVar19;
              bVar17 = func_00581DF8(*DAT_003514f4,&fStack_144,param_2);
              if (bVar17) {
                uVar11 = uVar5 & 0xfffffff;
                uVar5 = uVar11 | (uint)(fStack_144 == fVar19) << 0x1e;
                bVar17 = false;
                if (SUB41(uVar5 >> 0x1e,0)) {
                  uVar5 = uVar11 | (uint)(local_140 == fVar19) << 0x1e;
                  bVar17 = SUB41(uVar5 >> 0x1e,0);
                }
                bVar18 = false;
                if (bVar17) {
                  uVar5 = uVar5 & 0xfffffff | (uint)(afStack_13c[0] == fVar19) << 0x1e;
                  bVar18 = SUB41(uVar5 >> 0x1e,0);
                }
                if (!bVar18) {
                  func_00115C54(param_2,param_2,&fStack_144);
                  func_00115C54(param_2 + 3,param_2 + 3,&fStack_144);
                }
              }
              goto LAB_003510bc;
            }
          }
        }
      }
      goto LAB_003511a8;
    }
    if (*(char *)(param_1 + 0x22a) == '\0') {
      func_0036F6C8((float *)(param_1 + 0x44),param_2 + 3,*(float **)(param_3 + 4));
      goto LAB_003510bc;
    }
LAB_003512c4:
    if (((*(char *)(param_1 + 0x164) == '\0') && (-1 < *(short *)(param_1 + 0x29e))) &&
       (*(short *)(param_1 + 0x29e) < 1)) {
      if (*(char *)(param_1 + 0x2b8) == '\0') {
        *(undefined4 *)(param_1 + 0x2b0) = 0;
        *(undefined4 *)(param_1 + 0x2b4) = 0;
      }
      else {
        func_00115C70(afStack_f8,*(float **)(*DAT_003514f0 + 0x1c),(float *)(param_1 + 0x2a4));
        func_00115C70(afStack_ec,(float *)(param_1 + 700),(float *)(param_1 + 0x2a4));
        iVar15 = func_004904CC(afStack_f8[0],fStack_f0);
        iVar14 = func_004904CC(afStack_ec[0],fStack_e4);
        fStack_148 = ALBW_AS_F32((iVar15 - iVar14));
        afStack_13c[0] = fStack_148;
        uVar11 = func_0058E2B8((int *)afStack_13c);
        uVar12 = *(uint *)(DAT_003514f8 + *(short *)(param_1 + 0x29e) * 0x14 + 0x10);
        if (uVar11 < uVar12) {
          uVar11 = uVar11 >> 1;
        }
        else {
          fVar26 = (float)VectorSignedToFloat(uVar12,(byte)(uVar5 >> 0x15) & 3);
          fVar19 = (float)VectorUnsignedToFloat(-0x80000000 - uVar11,(byte)(uVar5 >> 0x15) & 3);
          fVar21 = (float)VectorUnsignedToFloat(-0x80000000 - uVar12,(byte)(uVar5 >> 0x15) & 3);
          uVar11 = (uint)(fVar26 * (fVar19 / fVar21) * fVar20);
        }
        if (0 < (int)ALBW_AS_U32(fStack_148)) {
          uVar11 = -uVar11;
        }
        *(uint *)(param_1 + 0x2b0) = uVar11 + iVar15 + -0x80000000;
        func_00491E80(&local_128,0,*(uint *)(param_1 + 0x2b4),0);
        fStack_e0 = ALBW_AS_F32(((ulonglong)uVar31 >> 0x20));
        fStack_d8 = -SQRT(afStack_f8[0] * afStack_f8[0] + fStack_f0 * fStack_f0);
        fStack_dc = fStack_e0;
        func_00115CA8(&fStack_e0,&local_128,&fStack_e0);
        fVar19 = param_2[4];
        func_00115C54(param_2 + 3,(float *)(param_1 + 0x2a4),&fStack_e0);
        param_2[4] = fVar19;
      }
      func_0036FA1C((undefined4 *)(param_1 + 0x44),0);
      if (*(char *)(param_1 + 0x20) == '\0') goto LAB_003514fc;
    }
    fVar19 = *(float *)(param_1 + 0x1c8);
  }
  else {
    func_0034E038(param_1,param_2,(int)param_3,iVar4,fStack_158,ALBW_AS_F32(uVar31));
LAB_003510bc:
    if (*(char *)(param_1 + 0x20) != '\0') goto LAB_003512c4;
LAB_003511a8:
    if (*(int *)(param_1 + 0x264) != 0) {
      iVar15 = func_00541190(*(int *)(param_1 + 0x264));
      func_00115C70(&local_128,param_2 + 3,param_2);
      fVar19 = *(float *)(iVar15 + 4);
      pfVar16 = (float *)(DAT_003514ec + (*(uint *)(param_1 + 8) >> 0x18) * 0x10);
      fVar26 = (float)VectorUnsignedToFloat
                                (*(uint *)(param_1 + 8) & 0xffffff,(byte)(uVar5 >> 0x15) & 3);
      fVar26 = *pfVar16 + pfVar16[1] * fVar26 * DAT_003514e8;
      fVar21 = ALBW_AS_F32(((ulonglong)uVar31 >> 0x20));
      uVar5 = uVar5 & 0xfffffff;
      uVar11 = uVar5 | (uint)(fVar26 == fVar21) << 0x1e;
      if (!SUB41(uVar11 >> 0x1e,0)) {
        fVar23 = *(float *)(iVar15 + 0x34);
        fVar22 = *(float *)(iVar15 + 8);
        fVar24 = *(float *)(*(int *)(*DAT_003514f0 + 0x1c) + 4);
        uVar11 = uVar5 | (uint)(fVar24 == fVar23) << 0x1e | (uint)(fVar23 <= fVar24) << 0x1d;
        bVar3 = (byte)(uVar11 >> 0x18);
        if (!(bool)(bVar3 >> 5 & 1) || (bool)(bVar3 >> 6)) {
          fVar22 = *(float *)(iVar15 + 0xc);
        }
        else {
          fVar27 = fVar23 + *(float *)(iVar15 + 0x38);
          uVar11 = uVar5 | (uint)(fVar27 < fVar24) << 0x1f;
          if (SUB41(uVar11 >> 0x1f,0) == (NAN(fVar27) || NAN(fVar24))) {
            fVar22 = *(float *)(iVar15 + 0xc) +
                     (fVar22 - *(float *)(iVar15 + 0xc)) *
                     ((fVar24 - fVar23) / *(float *)(iVar15 + 0x38));
          }
        }
        fVar19 = fVar22 / fVar26 + fVar19;
      }
      fVar26 = SQRT(local_128 * local_128 + local_124 * local_124 + local_120 * local_120);
      uVar11 = uVar11 & 0xfffffff | (uint)(fVar26 < fVar21) << 0x1f |
               (uint)(fVar26 == fVar21) << 0x1e;
      uVar5 = uVar11 | (uint)(NAN(fVar26) || NAN(fVar21)) << 0x1c;
      bVar3 = (byte)(uVar11 >> 0x18);
      if (!(bool)(bVar3 >> 6 & 1) && bVar3 >> 7 == ((byte)(uVar5 >> 0x1c) & 1)) {
        fVar19 = fVar19 / fVar26;
        local_128 = local_128 * fVar19;
        local_124 = local_124 * fVar19;
        local_120 = local_120 * fVar19;
      }
      func_00115C54(param_2 + 3,param_2,&local_128);
      if (*(char *)(param_1 + 0x20) != '\0') goto LAB_003512c4;
    }
LAB_003514fc:
    fVar19 = *(float *)(param_1 + 0xa8);
  }
  param_2[6] = fVar19;
  if (((*(char *)(param_1 + 0x164) != '\0') &&
      (param_2[6] = fVar25 + (param_2[6] - fVar25) * ALBW_AS_F32(uVar31), iVar4 == 0)) &&
     (param_3[0x2c] == 0)) {
    iVar4 = *DAT_003514f0;
    fVar19 = ALBW_AS_F32(((ulonglong)uVar31 >> 0x20));
    if (*(float *)(*(int *)(iVar4 + 0x28) + 4) == fVar19) {
      pfVar16 = *(float **)(iVar4 + 0x1c);
      fVar20 = *(float *)(param_1 + 0x1a4) - *pfVar16;
      fVar26 = *(float *)(param_1 + 0x1a8) - pfVar16[1];
      fVar25 = *(float *)(param_1 + 0x1ac) - pfVar16[2];
      if (DAT_003516bc <= (int)ALBW_AS_U32((fVar20 * fVar20 + fVar26 * fVar26 + fVar25 * fVar25))) {
        bVar17 = *(char *)(param_1 + 0x137) != '\0';
        cVar1 = '\0';
        if (bVar17) {
          cVar1 = *(char *)(param_1 + 0x148);
        }
        if (!bVar17 || cVar1 == '\0') {
          *(undefined1 *)(param_1 + 0x164) = 0;
          *(undefined1 *)(param_1 + 0x135) = 0;
          uVar9 = *(undefined4 *)(param_1 + 8);
          *(undefined4 *)(param_1 + 0x2c) = uVar9;
          *(undefined4 *)(param_1 + 0x174) = uVar9;
          *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(param_1 + 0xc);
          *(undefined4 *)(param_1 + 0x180) = uVar9;
          *(float *)(param_1 + 0x184) = fVar19;
          *(float *)(param_1 + 0x194) = fVar19;
          *(undefined4 *)(param_1 + 400) = 0;
          *(undefined4 *)(param_1 + 0x18c) = 0;
          *(float *)(param_1 + 0x188) = fVar19;
        }
      }
    }
    else {
      puVar13 = *(undefined4 **)(iVar4 + 0x1c);
      *(undefined4 *)(param_1 + 0x1a4) = *puVar13;
      *(undefined4 *)(param_1 + 0x1a8) = puVar13[1];
      *(undefined4 *)(param_1 + 0x1ac) = puVar13[2];
    }
  }
  *(undefined1 *)(param_1 + 0x22) = 0;
  bVar17 = *(char *)(param_1 + 0x22c) != '\0';
  cVar1 = '\0';
  if (bVar17) {
    cVar1 = *(char *)(param_1 + 0x22d);
  }
  if (bVar17 && cVar1 != '\0') {
    *(float *)(param_1 + 0x230) = param_2[3];
    *(float *)(param_1 + 0x234) = param_2[4];
    *(float *)(param_1 + 0x238) = param_2[5];
  }
  piVar8 = DAT_003516c0;
  *(undefined1 *)(param_1 + 0x22d) = 0;
  piVar8 = *(int **)(*piVar8 + 0x44);
  if (((*DAT_003516c4 & 1) == 0) && (iVar4 = func_00100174((int *)DAT_003516c4), iVar4 != 0)) {
    *DAT_003516c8 = DAT_003516cc;
  }
  if (((piVar8 == (int *)0x0) ||
      (iVar4 = (**(code **)(*piVar8 + 8))(piVar8,DAT_003516c8), iVar4 == 0)) &&
     (*(undefined1 *)(param_1 + 0x22a) = 0, piVar8 == (int *)0x0)) {
    *(undefined4 *)(param_1 + 0x264) = 0;
  }
  return func_00261564(param_1);
}

