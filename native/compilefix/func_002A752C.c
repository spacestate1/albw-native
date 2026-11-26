/* compilefix: USA 002A752C (EU 002A7508), the Thieves' Hideout boss's constructor, with its split tail
 * rejoined (BOOT_LOG 172). Ghidra made the last third a function of its own (002A87FC(void), reading
 * r4, r7..r11, d8 and two stack slots of this one): spawning the boss read garbage and crashed. The
 * tail is hagure_boss_tail, its inputs taken from EU 2A7508..2A8708 (r4 = this, r7 = table + 0x100,
 * r8 = 0, r9 = DAT_002a7980, r10 = this + 0x40C, r11 = 1, s16/s17 = table + 0x4C/0x50, [sp+0xC] =
 * this + 0x800, [sp+0x70] = param_2; the SafeString vtable store of r6 restored). */
#include "ghidra_types.h"

extern int func_00100118(int param_1,undefined *param_2,int param_3,int param_4);
extern int func_0010983C(undefined4 param_1,undefined4 param_2);
extern int func_0010A794(undefined4 *param_1);
extern int func_0010BA78(undefined4 param_1);
extern int func_0010BAB4(undefined4 param_1);
extern undefined8 func_0010BEC4(int param_1,uint param_2,int *param_3);
extern int func_0010CEE0(undefined4 param_1,int *param_2,undefined4 param_3);
extern int func_00111A20(int param_1,undefined4 param_2,uint *param_3);
extern int func_0014DF18(int param_1,undefined4 param_2,int param_3,uint param_4,undefined1 param_5, undefined1 param_6);
extern int func_0014EB8C(int param_1,undefined4 param_2,undefined2 *param_3,uint *param_4,undefined2 param_5, undefined4 param_6,undefined2 param_7);
extern int func_00151358(int *param_1);
extern int func_0015137C(undefined4 *param_1,undefined4 param_2,undefined4 param_3);
extern int func_002A3D8C(int param_1);
extern int func_002A4DF4(int param_1);
extern int func_0032493C(undefined4 *param_1);
extern int func_0036C884(undefined4 *param_1,undefined4 *param_2,undefined1 param_3);
extern int func_0036D0C8(int *param_1,int param_2);
extern int func_004356B4(int *param_1);
extern int func_004A3700(int param_1);
extern undefined4 func_004A7F00(int param_1,int param_2,uint param_3);
extern int func_004EDAD0(int param_1,uint *param_2);
extern int func_004EDB28(int param_1,int param_2);
extern int func_004EDC9C(undefined4 *param_1);
extern int func_004EE484(undefined4 *param_1);
extern int func_004F5BD8(int param_1,uint *param_2,int **param_3,float *param_4);
extern int func_004FAC70(int param_1,uint param_2,int *param_3);
extern int func_004FACA4(int param_1,uint param_2,int *param_3);
extern int func_004FB024(int param_1);
extern int func_004FB30C(int param_1,int param_2);
extern int func_004FB344(int param_1,int param_2);
extern void func_004FB408(int param_1);
extern int func_004FB468(int param_1);
extern int func_004FB4C4(int param_1,float fparam_0);
extern int func_004FC1CC(int param_1,int param_2,byte param_3,float fparam_0);
extern int func_004FC8D8(int param_1,int param_2);
extern int func_004FCDF4(int param_1,int param_2);
extern int func_004FCF20(int param_1,int param_2);
extern int func_004FD464(undefined4 *param_1,uint *param_2,uint *param_3);
extern int func_005330A8(int param_1,int param_2,int *param_3);
extern int func_0054D964(int param_1,uint param_2);
extern int func_0054DDF4(int param_1,uint param_2);
extern int func_00564A78(int param_1,int *param_2);
extern undefined8 func_0058A474(undefined4 param_1,uint param_2);
extern uint *DAT_002a7960;
extern int DAT_002a7964;
extern int DAT_002a7968;
extern int DAT_002a796c;
extern undefined4 *DAT_002a7970;
extern undefined4 DAT_002a7974;
extern float DAT_002a7978;
extern undefined4 DAT_002a797c;
extern undefined4 DAT_002a7980;
extern undefined4 *DAT_002a7984;
extern undefined *DAT_002a7988;
extern undefined4 DAT_002a798c;
extern undefined4 DAT_002a7990;
extern undefined *DAT_002a7994;
extern int DAT_002a7e30;
extern uint DAT_002a7e3c;
extern int DAT_002a7e40;
extern undefined4 *DAT_002a7e44;
extern int DAT_002a7e48;
extern int *DAT_002a7e54;
extern float DAT_002a7e58;
extern undefined4 DAT_002a7e5c;
extern undefined4 DAT_002a7e60;
extern undefined4 DAT_002a7e64;
extern int DAT_002a7e68;
extern uint DAT_002a82ec;
extern int DAT_002a8308;
extern int *DAT_002a830c;
extern undefined *DAT_002a8310;
extern int DAT_002a8314;
extern char s_Actor_HagureBoss_kcl_002a82f0[];
extern char s_arm_l3_002a7e34[];
extern char s_cState_Attack2_002a8738[];
extern char s_cState_Attack3_002a8748[];
extern char s_cState_Attack4_002a8758[];
extern char s_cState_Attack5_002a8768[];
extern char s_cState_Attack6_002a8778[];
extern char s_cState_Attack_002a8728[];
extern char s_cState_BackStep_002a8350[];
extern char s_cState_Blaze_002a8788[];
extern char s_cState_DosunWait_002a8318[];
extern char s_cState_Find_002a8344[];
extern char s_cState_Move_002a832c[];
extern char s_cState_OffShieldDemo_002a8798[];
extern char s_cState_Reaction_002a87c8[];
extern char s_cState_Seek_002a8338[];
extern char s_cState_SeparationDemo_002a87b0[];
extern char s_cState_WarpS_002a8718[];
extern char s_cState_Warp_002a870c[];
extern char s_cf_002a82f0[];
extern char s_end_st_002a7e4c[];

// USA 002A752C <- EU 002A7508 (Ghidra, non-matching)
// GLOBAL DAT_002a7960 uint *
// GLOBAL DAT_002a7964 int
// GLOBAL DAT_002a7968 int
// GLOBAL DAT_002a796c int
// GLOBAL DAT_002a7970 undefined4 *
// GLOBAL DAT_002a7974 undefined4
// GLOBAL DAT_002a7978 float
// GLOBAL DAT_002a797c undefined4
// GLOBAL DAT_002a7980 undefined4
// GLOBAL DAT_002a7984 undefined4 *
// GLOBAL DAT_002a7988 undefined *
// GLOBAL DAT_002a798c undefined4
// GLOBAL DAT_002a7990 undefined4
// GLOBAL DAT_002a7994 undefined *
// GLOBAL DAT_002a7e30 int
// GLOBAL DAT_002a7e3c uint
// GLOBAL DAT_002a7e40 int
// GLOBAL DAT_002a7e44 undefined4 *
// GLOBAL DAT_002a7e48 int
// GLOBAL DAT_002a7e54 int *
// GLOBAL DAT_002a7e58 float
// GLOBAL DAT_002a7e5c undefined4
// GLOBAL DAT_002a7e60 undefined4
// GLOBAL DAT_002a7e64 undefined4
// GLOBAL DAT_002a7e68 int
// GLOBAL DAT_002a82ec uint
// GLOBAL DAT_002a8308 int
// GLOBAL DAT_002a830c int *
// GLOBAL DAT_002a8310 undefined *
// GLOBAL DAT_002a8314 int
// GLOBAL s_cf_002a82f0 string
// GLOBAL s_arm_l3_002a7e34 string
// GLOBAL s_cState_Attack2_002a8738 string
// GLOBAL s_cState_Attack3_002a8748 string
// GLOBAL s_cState_Attack4_002a8758 string
// GLOBAL s_cState_Attack5_002a8768 string
// GLOBAL s_cState_Attack6_002a8778 string
// GLOBAL s_cState_Attack_002a8728 string
// GLOBAL s_cState_BackStep_002a8350 string
// GLOBAL s_cState_Blaze_002a8788 string
// GLOBAL s_cState_DosunWait_002a8318 string
// GLOBAL s_cState_Find_002a8344 string
// GLOBAL s_cState_Move_002a832c string
// GLOBAL s_cState_OffShieldDemo_002a8798 string
// GLOBAL s_cState_Reaction_002a87c8 string
// GLOBAL s_cState_Seek_002a8338 string
// GLOBAL s_cState_SeparationDemo_002a87b0 string
// GLOBAL s_cState_WarpS_002a8718 string
// GLOBAL s_cState_Warp_002a870c string
// GLOBAL s_end_st_002a7e4c string

/* WARNING: Variable defined which should be unmapped: objStack_98 */
/* WARNING: Variable defined which should be unmapped: objStack_94 */

extern int func_002A6B54(int param_1);
extern int func_002AFEC4(int param_1,int param_2,int param_3);
extern int func_004F87F8(int param_1,int param_2);
extern int func_00581B9C(int param_1);
extern int func_00582250(int param_1);
extern int func_00662128(undefined4 *param_1,undefined1 param_2);
extern undefined4 DAT_002a82ec;
extern undefined4 *DAT_002a8b6c;
extern int DAT_002a8b70;
extern int *DAT_002a8b74;
extern char s_cState_Die_002a8b50[];
extern char s_cState_ReactionWait_002a8b3c[];
extern char s_wrist_l_002a8b64[];
extern char s_wrist_r_002a8b5c[];
extern char data_006F5988[];

static int hagure_boss_tail(int unaff_r4, int tbl, uint *param_2)
{
  /* the registers and stack slots of 002A752C that the tail reads (EU 2A7508..2A8708) */
  int unaff_r7 = tbl + 0x100;
  undefined4 unaff_r8 = 0, unaff_r9 = DAT_002a7980;
  int *unaff_r10 = (int *)(unaff_r4 + 0x40c);
  undefined1 unaff_r11 = 1;
  undefined8 in_d8 = *(undefined8 *)(tbl + 0x4c);          /* s16, s17 */
  uint safe_str[2];                                         /* sead::SafeString {vtable, cstr} */
  safe_str[0] = (uint)(uintptr_t)data_006F5988;
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  uint *puVar7;
  uint slot_0c;
  int iVar8;
  undefined4 uVar9;
  int *piVar10;
  undefined4 uVar11;
  
  iVar1 = *(int *)(unaff_r4 + 0xa00);
  *(int *)(iVar1 + 0x80) = (int)in_d8;
  *(int *)(iVar1 + 0x84) = (int)((ulonglong)in_d8 >> 0x20);
  safe_str[1] = (uint)(uintptr_t)s_cState_ReactionWait_002a8b3c;
  func_0010BEC4(unaff_r4 + 0x9e0,0x11,(int *)safe_str);
  iVar1 = *(int *)(unaff_r4 + 0x9f8);
  uVar2 = *(undefined4 *)(unaff_r7 + 0x58);
  uVar9 = *(undefined4 *)(unaff_r7 + 0x5c);
  uVar11 = *(undefined4 *)(unaff_r7 + 0x60);
  *(undefined4 *)(iVar1 + 0x88) = *(undefined4 *)(unaff_r7 + 0x54);
  *(undefined4 *)(iVar1 + 0x8c) = uVar2;
  iVar1 = *(int *)(unaff_r4 + 0x9fc);
  *(undefined4 *)(iVar1 + 0x88) = uVar9;
  *(undefined4 *)(iVar1 + 0x8c) = uVar11;
  iVar1 = *(int *)(unaff_r4 + 0xa00);
  *(int *)(iVar1 + 0x88) = (int)in_d8;
  *(int *)(iVar1 + 0x8c) = (int)((ulonglong)in_d8 >> 0x20);
  safe_str[1] = (uint)(uintptr_t)s_cState_Die_002a8b50;
  func_0010BEC4(unaff_r4 + 0x9e0,0x12,(int *)safe_str);
  iVar1 = *(int *)(unaff_r4 + 0x9f8);
  uVar9 = *(undefined4 *)(unaff_r7 + 0x68);
  uVar11 = *(undefined4 *)(unaff_r7 + 0x6c);
  uVar2 = *(undefined4 *)(unaff_r7 + 0x70);
  *(undefined4 *)(iVar1 + 0x90) = *(undefined4 *)(unaff_r7 + 100);
  *(undefined4 *)(iVar1 + 0x94) = uVar9;
  iVar1 = *(int *)(unaff_r4 + 0x9fc);
  *(undefined4 *)(iVar1 + 0x90) = uVar11;
  *(undefined4 *)(iVar1 + 0x94) = uVar2;
  iVar1 = *(int *)(unaff_r4 + 0xa00);
  *(int *)(iVar1 + 0x90) = (int)in_d8;
  *(int *)(iVar1 + 0x94) = (int)((ulonglong)in_d8 >> 0x20);
  *(uint *)(unaff_r4 + 0x59c) = *(uint *)(unaff_r4 + 0x59c) & 0xfff7ffdf | 0x860000;
  *(undefined1 *)(unaff_r4 + 0x895) = 5;
  func_002AFEC4(unaff_r4,-1,-1);
  *(uint *)(*(int *)(unaff_r4 + 0x424) + 0x2c) =
       *(uint *)(*(int *)(unaff_r4 + 0x424) + 0x2c) | 0x100000;
  *(undefined4 *)(unaff_r4 + 0x4f8) = *(undefined4 *)(unaff_r4 + 0x800 + 0x334);
  *(undefined2 *)(*(int *)(unaff_r4 + 0xa24) + 0x28) = 0xa0;
  safe_str[1] = (uint)(uintptr_t)s_wrist_r_002a8b5c;
  uVar3 = func_00564A78(*(int *)(unaff_r4 + 0x40c),(int *)safe_str);
  *(uint *)(unaff_r4 + 0xb40) = uVar3;
  safe_str[1] = (uint)(uintptr_t)s_wrist_l_002a8b64;
  uVar3 = func_00564A78(*unaff_r10,(int *)safe_str);
  *(uint *)(unaff_r4 + 0xb44) = uVar3;
  piVar10 = *(int **)(unaff_r4 + 0xaf8);
  piVar10[1] = *(int *)(unaff_r4 + 0xa6c);
  piVar10[2] = *(int *)(unaff_r4 + 0xa70);
  piVar10[3] = *(int *)(unaff_r4 + 0xa74);
  func_004356B4(piVar10);
  puVar4 = (undefined4 *)func_0010BAB4(0x10);
  puVar6 = DAT_002a8b6c;
  if (puVar4 != (undefined4 *)0x0) {
    puVar4[1] = unaff_r8;
    uVar2 = *puVar6;
    uVar9 = puVar6[1];
    *puVar4 = unaff_r9;
    puVar4[2] = uVar2;
    puVar4[3] = uVar9;
  }
  *(undefined4 **)(unaff_r4 + 0xa40) = puVar4;
  *(int **)(unaff_r4 + 0xa28) = piVar10;
  *(undefined2 *)(piVar10 + 10) = 0xa0;
  slot_0c = *(uint *)(unaff_r4 + 0x2cc);
  func_0014EB8C(*(int *)(unaff_r4 + 0xafc),*(undefined4 *)(unaff_r4 + 0xaf8),
                *(undefined2 **)(unaff_r4 + 0xbf4),&slot_0c,*(undefined2 *)(unaff_r4 + 0x54)
                ,unaff_r8,(short)DAT_002a82ec);
  iVar1 = DAT_002a8b70;
  *(char *)(*(int *)(unaff_r4 + 0xafc) + 0x61) = (char)unaff_r8;
  iVar5 = *(int *)(unaff_r4 + 0xa40);
  uVar2 = *(undefined4 *)(iVar1 + 0x174);
  uVar9 = *(undefined4 *)(iVar1 + 0x178);
  *(int *)(iVar5 + 4) = unaff_r4;
  *(undefined4 *)(iVar5 + 8) = uVar2;
  *(undefined4 *)(iVar5 + 0xc) = uVar9;
  func_002A6B54(unaff_r4);
  func_004F87F8(unaff_r4,1);
  *(undefined1 *)(unaff_r4 + 0x848) = unaff_r11;
  *(uint *)(unaff_r4 + 0x59c) = *(uint *)(unaff_r4 + 0x59c) & 0xfff7ffff;
  if (*(char *)(unaff_r4 + 0xb99) == '\0') {
    func_00662128((undefined4 *)(unaff_r4 + 0x9e0),1);
  }
  else {
    func_00662128((undefined4 *)(unaff_r4 + 0x9e0),0);
  }
  puVar6 = (undefined4 *)(unaff_r4 + 0x3d0);
  *(undefined4 *)(unaff_r4 + 0xa9c) = *puVar6;
  *(undefined4 *)(unaff_r4 + 0xaa0) = *(undefined4 *)(unaff_r4 + 0x3d4);
  *(undefined4 *)(unaff_r4 + 0xaa4) = *(undefined4 *)(unaff_r4 + 0x3d8);
  *(undefined4 *)(unaff_r4 + 0xaa8) = *puVar6;
  *(undefined4 *)(unaff_r4 + 0xaac) = *(undefined4 *)(unaff_r4 + 0x3d4);
  *(undefined4 *)(unaff_r4 + 0xab0) = *(undefined4 *)(unaff_r4 + 0x3d8);
  *(undefined4 *)(unaff_r4 + 0xab4) = *puVar6;
  *(undefined4 *)(unaff_r4 + 0xab8) = *(undefined4 *)(unaff_r4 + 0x3d4);
  *(undefined4 *)(unaff_r4 + 0xabc) = *(undefined4 *)(unaff_r4 + 0x3d8);
  *(undefined4 *)(unaff_r4 + 0xac0) = *puVar6;
  *(undefined4 *)(unaff_r4 + 0xac4) = *(undefined4 *)(unaff_r4 + 0x3d4);
  *(undefined4 *)(unaff_r4 + 0xac8) = *(undefined4 *)(unaff_r4 + 0x3d8);
  *(undefined4 *)(unaff_r4 + 0xad4) = *(undefined4 *)(unaff_r4 + 0x3d8);
  *(undefined4 *)(unaff_r4 + 0xacc) = *puVar6;
  *(undefined4 *)(unaff_r4 + 0xad0) = *(undefined4 *)(unaff_r4 + 0x3d4);
  uVar3 = *(uint *)((int)param_2 + 0x29c);
  *(uint *)(unaff_r4 + 0xb4c) = uVar3;
  if (-1 < (int)uVar3) {
    iVar1 = *DAT_002a8b74;
    iVar5 = func_00581B9C(iVar1);
    if (((iVar5 == 1) && (puVar7 = (uint *)func_00582250(iVar1), uVar3 < *puVar7)) &&
       (iVar1 = *(int *)(puVar7[2] + uVar3 * 4), iVar1 != 0)) {
      uVar3 = 0;
      do {
        if (((*(int *)(iVar1 + 0x28) != 0) && (uVar3 < *(uint *)(iVar1 + 0x20))) &&
           (iVar5 = *(int *)(*(int *)(iVar1 + 0x28) + uVar3 * 4), iVar5 != 0)) {
          uVar9 = *(undefined4 *)(iVar5 + 0x1c);
          iVar8 = unaff_r4 + uVar3 * 0xc;
          uVar2 = *(undefined4 *)(iVar5 + 0x20);
          *(undefined4 *)(iVar8 + 0xa9c) = *(undefined4 *)(iVar5 + 0x18);
          *(undefined4 *)(iVar8 + 0xaa0) = uVar9;
          *(undefined4 *)(iVar8 + 0xaa4) = uVar2;
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 < 5);
    }
  }
  return unaff_r4;
}


undefined4 func_002A752C(undefined4 *param_1,uint *param_2)

{
  byte bVar1;
  int iVar2;
  uint auVar3 [1];
  undefined2 uVar4;
  uint uVar5;
  int *piVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int iVar9;
  uint *puVar10;
  int iVar11;
  float *pfVar12;
  int iVar13;
  undefined4 uVar14;
  int iVar15;
  uint uVar16;
  undefined4 uVar17;
  int iVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  uint uVar21;
  int iVar22;
  float fVar23;
  undefined4 uVar24;
  undefined8 uVar25;
  _Alignas(8) unsigned char albw_frame[0xa0];
  #define objStack_98 ((uint *)(albw_frame + 0x8))
  #define objStack_94 ((uint *)(albw_frame + 0xc))
  #define local_88 (*(uint *)(albw_frame + 0x18))
  #define local_84 (*(char * *)(albw_frame + 0x1c))
  #define local_80 (*(int *)(albw_frame + 0x20))
  #define local_7c (*(undefined1 * *)(albw_frame + 0x24))
  #define local_78 (*(int * *)(albw_frame + 0x28))
  #define local_74 ((undefined1 *)(albw_frame + 0x2c))
  #define uStack_35 (*(undefined1 *)(albw_frame + 0x6b))
  #define puStack_2c (*(undefined4 * *)(albw_frame + 0x74))
  #define local_28 (*(uint * *)(albw_frame + 0x78))
  puStack_2c = param_1;
  local_28 = param_2;
  piVar6 = func_004FD464(param_1,param_2,DAT_002a7960);
  puVar7 = DAT_002a7970;
  iVar9 = DAT_002a7964;
  piVar6[200] = DAT_002a7964 + 0x84;
  iVar2 = DAT_002a7968;
  *piVar6 = iVar9;
  piVar6[0x230] = 0;
  iVar11 = *(int *)(iVar2 + 0x188);
  piVar6[0x231] = *(int *)(iVar2 + 0x184);
  iVar9 = DAT_002a796c;
  piVar6[0x232] = iVar11;
  piVar6[0x22f] = iVar9;
  piVar6[0x233] = 0;
  piVar6[0x234] = 0;
  uVar14 = *puVar7;
  uVar17 = puVar7[1];
  puVar7 = func_0036C884(piVar6 + 0x235,piVar6,1);
  *puVar7 = DAT_002a7974;
  puVar7[0x40] = uVar14;
  puVar7[0x41] = uVar17;
  puVar8 = (undefined4 *)func_0010BAB4(0xc);
  uVar14 = 0;
  if (puVar8 != (undefined4 *)0x0) {
    uVar14 = func_0032493C(puVar8);
  }
  puVar7[0x42] = uVar14;
  puVar8 = func_0010A794(puVar7 + 0x43);
  puVar8[5] = 0;
  uVar14 = DAT_002a797c;
  puVar8[6] = 0;
  puVar8[7] = 0;
  puVar8[8] = 0;
  puVar8[9] = uVar14;
  fVar23 = DAT_002a7978;
  puVar8[10] = puVar8 + -0x278;
  puVar8[0xb] = ALBW_AS_U32(fVar23);
  iVar9 = DAT_002a7968;
  puVar8[0xc] = 0;
  puVar8[0xd] = 0;
  puVar8[0xe] = 0;
  uVar17 = DAT_002a7980;
  uVar14 = *(undefined4 *)(iVar9 + 0xc);
  uVar19 = *(undefined4 *)(iVar9 + 0x10);
  puVar8[0x14] = puVar8 + -0x278;
  puVar8[0x15] = uVar14;
  puVar8[0x16] = uVar19;
  puVar8[0x13] = uVar17;
  uVar14 = *(undefined4 *)(iVar9 + 0x14);
  puVar8[0x1c] = *(undefined4 *)(iVar9 + 0x18);
  puVar8[0x19] = uVar17;
  puVar8[0x1a] = puVar8 + -0x278;
  puVar8[0x1b] = uVar14;
  puVar7 = DAT_002a7984;
  puVar8[0x1d] = puVar8[-0x184];
  puVar8[0x1e] = puVar8[-0x183];
  puVar8[0x1f] = puVar8[-0x182];
  uVar14 = puVar7[1];
  uVar19 = puVar7[2];
  puVar8[0x20] = *puVar7;
  puVar8[0x21] = uVar14;
  puVar8[0x22] = uVar19;
  puVar8[0x23] = puVar8[-0x184];
  puVar8[0x24] = puVar8[-0x183];
  puVar8[0x25] = puVar8[-0x182];
  puVar8[0x26] = puVar8[-0x184];
  puVar8[0x27] = puVar8[-0x183];
  puVar8[0x28] = puVar8[-0x182];
  puVar8[0x29] = puVar8[-0x184];
  puVar8[0x2a] = puVar8[-0x183];
  puVar8[0x2b] = puVar8[-0x182];
  puVar8[0x2c] = puVar8[-0x184];
  puVar8[0x2d] = puVar8[-0x183];
  puVar8[0x2e] = puVar8[-0x182];
  iVar9 = func_00100118((int)(puVar8 + 0x2f),DAT_002a7988,0xc,5);
  iVar15 = iVar9 + -0xa9c;
  iVar11 = func_0054D964(iVar15,1);
  *(int *)(iVar9 + 0x54) = iVar11;
  puVar8 = (undefined4 *)func_0010BAB4(100);
  uVar14 = 0;
  if (puVar8 != (undefined4 *)0x0) {
    uVar14 = func_004EE484(puVar8);
  }
  *(undefined4 *)(iVar9 + 0x58) = uVar14;
  iVar11 = func_0054D964(iVar15,2);
  *(int *)(iVar9 + 0x5c) = iVar11;
  puVar8 = (undefined4 *)func_0010BAB4(100);
  uVar14 = 0;
  if (puVar8 != (undefined4 *)0x0) {
    uVar14 = func_004EE484(puVar8);
  }
  *(undefined4 *)(iVar9 + 0x60) = uVar14;
  *(undefined4 *)(iVar9 + 100) = *(undefined4 *)(iVar9 + -0x6cc);
  *(undefined4 *)(iVar9 + 0x68) = *(undefined4 *)(iVar9 + -0x6c8);
  *(undefined4 *)(iVar9 + 0x6c) = *(undefined4 *)(iVar9 + -0x6c4);
  uVar14 = DAT_002a798c;
  uVar19 = puVar7[1];
  uVar20 = puVar7[2];
  *(undefined4 *)(iVar9 + 0x70) = *puVar7;
  *(undefined4 *)(iVar9 + 0x74) = uVar19;
  *(undefined4 *)(iVar9 + 0x78) = uVar20;
  uVar19 = puVar7[1];
  uVar20 = puVar7[2];
  *(undefined4 *)(iVar9 + 0x7c) = *puVar7;
  *(undefined4 *)(iVar9 + 0x80) = uVar19;
  *(undefined4 *)(iVar9 + 0x84) = uVar20;
  *(float *)(iVar9 + 0x88) = fVar23;
  *(float *)(iVar9 + 0x8c) = fVar23;
  *(float *)(iVar9 + 0x90) = fVar23;
  *(float *)(iVar9 + 0x94) = fVar23;
  *(float *)(iVar9 + 0x98) = fVar23;
  *(float *)(iVar9 + 0x9c) = fVar23;
  *(float *)(iVar9 + 0xa0) = fVar23;
  *(undefined4 *)(iVar9 + 0xa4) = 0;
  *(undefined4 *)(iVar9 + 0xa8) = 0;
  *(undefined4 *)(iVar9 + 0xb0) = 0xffffffff;
  *(undefined4 *)(iVar9 + 0xac) = 0;
  *(undefined2 *)(iVar9 + 0xb4) = 0;
  *(undefined2 *)(iVar9 + 0xb6) = 0;
  *(undefined4 *)(iVar9 + 0xb8) = 0;
  *(undefined4 *)(iVar9 + 0xbc) = 0;
  *(undefined4 *)(iVar9 + 0xc0) = uVar14;
  *(undefined4 *)(iVar9 + 0xc4) = 0;
  *(undefined4 *)(iVar9 + 200) = 0;
  *(undefined4 *)(iVar9 + 0xcc) = uVar14;
  *(undefined4 *)(iVar9 + 0xd0) = 0;
  *(undefined4 *)(iVar9 + 0xd4) = 0;
  *(undefined4 *)(iVar9 + 0xd8) = uVar14;
  *(undefined1 *)(iVar9 + 0xdc) = 4;
  *(undefined4 *)(iVar9 + 0xe0) = 0;
  *(undefined4 *)(iVar9 + 0xe4) = 0;
  *(undefined4 *)(iVar9 + 0xe8) = 0;
  *(undefined4 *)(iVar9 + 0xec) = 0;
  *(undefined4 *)(iVar9 + 0xf0) = 0;
  *(undefined1 *)(iVar9 + 0xf4) = 0;
  *(undefined1 *)(iVar9 + 0xf5) = 0;
  *(undefined1 *)(iVar9 + 0xf6) = 0;
  *(undefined1 *)(iVar9 + 0xf7) = 0;
  *(undefined1 *)(iVar9 + 0xf8) = 0;
  *(undefined1 *)(iVar9 + 0xf9) = 0;
  *(undefined1 *)(iVar9 + 0xfa) = 0;
  *(undefined1 *)(iVar9 + 0xfb) = 0;
  *(undefined1 *)(iVar9 + 0xfc) = 0;
  *(bool *)(iVar9 + 0xfd) = *(short *)((int)local_28 + 0x32) != 0;
  *(undefined1 *)(iVar9 + 0xfe) = 0;
  *(undefined1 *)(iVar9 + 0xff) = 0;
  *(undefined1 *)(iVar9 + 0x100) = 0;
  *(undefined1 *)(iVar9 + 0x101) = 0;
  puVar8 = (undefined4 *)func_0010BAB4(0x90);
  if (puVar8 != (undefined4 *)0x0) {
    puVar8[1] = iVar15;
    *(undefined1 *)(puVar8 + 0x1d) = 1;
    *(undefined1 *)((int)puVar8 + 0x75) = 1;
    puVar8[2] = uVar14;
    puVar8[3] = ALBW_AS_U32(fVar23);
    puVar8[4] = ALBW_AS_U32(fVar23);
    puVar8[5] = ALBW_AS_U32(fVar23);
    puVar8[6] = uVar14;
    puVar8[7] = ALBW_AS_U32(fVar23);
    puVar8[8] = ALBW_AS_U32(fVar23);
    puVar8[9] = ALBW_AS_U32(fVar23);
    puVar8[10] = uVar14;
    puVar8[0xb] = uVar14;
    puVar8[0xc] = ALBW_AS_U32(fVar23);
    puVar8[0xd] = ALBW_AS_U32(fVar23);
    puVar8[0xe] = ALBW_AS_U32(fVar23);
    puVar8[0xf] = uVar14;
    puVar8[0x10] = ALBW_AS_U32(fVar23);
    puVar8[0x11] = ALBW_AS_U32(fVar23);
    puVar8[0x12] = ALBW_AS_U32(fVar23);
    puVar8[0x13] = uVar14;
    puVar8[0x14] = uVar14;
    puVar8[0x15] = ALBW_AS_U32(fVar23);
    puVar8[0x16] = ALBW_AS_U32(fVar23);
    puVar8[0x17] = ALBW_AS_U32(fVar23);
    puVar8[0x18] = uVar14;
    puVar8[0x19] = ALBW_AS_U32(fVar23);
    puVar8[0x1a] = ALBW_AS_U32(fVar23);
    uVar19 = DAT_002a7990;
    puVar8[0x1b] = ALBW_AS_U32(fVar23);
    puVar8[0x1c] = uVar14;
    *puVar8 = uVar19;
    uVar14 = puVar7[1];
    uVar19 = puVar7[2];
    puVar8[0x1e] = *puVar7;
    puVar8[0x1f] = uVar14;
    puVar8[0x20] = uVar19;
    uVar14 = puVar7[1];
    uVar19 = puVar7[2];
    puVar8[0x21] = *puVar7;
    puVar8[0x22] = uVar14;
    puVar8[0x23] = uVar19;
  }
  *(undefined4 **)(iVar9 + 0x104) = puVar8;
  iVar9 = func_00100118(iVar9 + 0x108,DAT_002a7994,8,5);
  iVar9 = func_00100118(iVar9 + 0x28,DAT_002a7994,8,5);
  objStack_94[1] = iVar9 + 0x2c;
  iVar11 = iVar9 + -0xbcc;
  uVar14 = *(undefined4 *)(DAT_002a7968 + 0x1c);
  uVar16 = 0;
  *(undefined4 *)(iVar9 + 0x38) = *(undefined4 *)(DAT_002a7968 + 0x20);
  *(undefined4 *)(iVar9 + 0x34) = uVar14;
  *(int *)(iVar9 + 0x30) = iVar11;
  *(undefined4 *)objStack_94[1] = uVar17;
  *(undefined1 *)(iVar9 + -0x3a) = 0;
  do {
    iVar18 = iVar11 + uVar16 * 8;
    iVar15 = *(int *)(iVar18 + 0xba4);
    if ((iVar15 != 0) && (*(int *)(iVar15 + 0x1c) == *(int *)(iVar18 + 0xba8))) {
      puVar10 = (uint *)(iVar15 + 0x3c);
      uVar21 = *(uint *)(iVar15 + 0x3c);
      *(uint *)(iVar15 + 0x3c) = uVar21 & 0xfffffffb;
      *puVar10 = uVar21 & 0xffffffbb;
      *puVar10 = *puVar10 | 8;
      func_004A3700(iVar15);
    }
    iVar15 = *(int *)(iVar18 + 0xbcc);
    if ((iVar15 != 0) && (*(int *)(iVar15 + 0x1c) == *(int *)(iVar18 + 0xbd0))) {
      uVar21 = *(uint *)(iVar15 + 0x3c) & 0xffffffbb;
      *(uint *)(iVar15 + 0x3c) = *(uint *)(iVar15 + 0x3c) & 0xfffffffb;
      *(uint *)(iVar15 + 0x3c) = uVar21;
      *(uint *)(iVar15 + 0x3c) = uVar21 | 8;
      func_004A3700(iVar15);
    }
    uVar16 = uVar16 + 1;
  } while (uVar16 < 5);
  *(uint *)(iVar9 + -0x630) = *(uint *)(iVar9 + -0x630) & 0xfffffffd;
  local_80 = iVar9 + -0x624;
  func_004FCDF4(local_80,0);
  puVar8 = (undefined4 *)func_0010BAB4(0x20);
  puVar7 = (undefined4 *)0x0;
  if (puVar8 != (undefined4 *)0x0) {
    puVar7 = func_0015137C(puVar8,iVar11,0);
  }
  *(undefined4 **)(iVar9 + -0x1b0) = puVar7;
  puVar8 = (undefined4 *)func_0010BAB4(0x20);
  puVar7 = (undefined4 *)0x0;
  if (puVar8 != (undefined4 *)0x0) {
    puVar7 = func_0015137C(puVar8,iVar11,0);
  }
  *(undefined4 **)(iVar9 + -0x1ac) = puVar7;
  iVar15 = DAT_002a7e30;
  piVar6 = *(int **)(iVar9 + -0x1b0);
  piVar6[4] = DAT_002a7e30;
  piVar6[5] = iVar15;
  piVar6[6] = iVar15;
  func_00151358(piVar6);
  piVar6 = *(int **)(iVar9 + -0x1ac);
  piVar6[4] = iVar15;
  piVar6[5] = iVar15;
  piVar6[6] = iVar15;
  func_00151358(piVar6);
  *(undefined4 *)(iVar9 + -0xf4) = *(undefined4 *)(iVar9 + -0x7fc);
  *(undefined4 *)(iVar9 + -0xf0) = *(undefined4 *)(iVar9 + -0x7f8);
  *(undefined4 *)(iVar9 + -0xec) = *(undefined4 *)(iVar9 + -0x7f4);
  pfVar12 = *(float **)(iVar9 + -0x7f4);
  *(undefined4 *)(iVar9 + -0xe8) = *(undefined4 *)(iVar9 + -0x7fc);
  *(undefined4 *)(iVar9 + -0xe4) = *(undefined4 *)(iVar9 + -0x7f8);
  *(float **)(iVar9 + -0xe0) = pfVar12;
  func_004FC8D8(local_80,*(int *)(iVar9 + -0x1b0));
  func_004FC8D8(local_80,*(int *)(iVar9 + -0x1ac));
  uVar16 = DAT_002a7e3c;
  local_84 = s_arm_l3_002a7e34;
  local_88 = DAT_002a7e3c;
  uVar21 = func_00564A78(*(int *)(iVar9 + -0x7c0),(int *)&local_88);
  if (uVar21 != 0xffff) {
    puVar10 = (uint *)(*(int *)(*(int *)(*(int *)(iVar9 + -0x7c0) + 0x24) + 0xc) + uVar21 * 0x40);
    *puVar10 = *puVar10 | 0x10;
    *(int *)(*(int *)(iVar9 + -0x7c0) + 0x16c) = iVar9 + -0x1c8;
  }
  iVar15 = DAT_002a7e40;
  *(undefined1 *)(iVar9 + -0x204) = 1;
  *(int *)(iVar9 + -0x84) = (int)*(short *)(iVar15 + iVar11);
  *(undefined4 *)(iVar9 + -0x824) = *(undefined4 *)(iVar9 + -0x2c);
  func_0036D0C8((int *)(iVar9 + -0x300),0);
  iVar15 = *(int *)(iVar9 + -0x300);
  if (iVar15 == 0) {
    objStack_98[0] = 1;
  }
  else {
    objStack_98[0] = func_0010983C(*DAT_002a7e44,iVar15);
  }
  func_004FB344(iVar11,0x21);
  iVar15 = DAT_002a7e48;
  uVar21 = 0;
  do {
    func_004FACA4(iVar11,uVar21,(int *)(iVar15 + uVar21 * 8));
    uVar21 = uVar21 + 1;
  } while ((int)uVar21 < 0x21);
  func_004FB468(iVar11);
  if (objStack_98[0] != 1) {
    func_0010983C(*DAT_002a7e44,objStack_98[0]);
  }
  func_0036D0C8((int *)(iVar9 + -0x2fc),0);
  if (*(int *)(iVar9 + -0x2fc) == 0) {
    iVar15 = 1;
  }
  else {
    iVar15 = func_0010983C(*DAT_002a7e44,*(int *)(iVar9 + -0x2fc));
  }
  func_004FB30C(iVar11,1);
  objStack_94[0] = (uint)s_end_st_002a7e4c;
  objStack_98[0] = uVar16;
  func_004FAC70(iVar11,0,(int *)objStack_98);
  func_004FB408(iVar11);
  func_004FB4C4(iVar11,fVar23);
  if (iVar15 != 1) {
    func_0010983C(*DAT_002a7e44,iVar15);
  }
  func_004F5BD8(iVar11,(uint *)0x0,(int **)0x0,pfVar12);
  uVar21 = func_005330A8(iVar11,0,DAT_002a7e54);
  puVar10 = DAT_002a7960;
  objStack_98[0] = 0;
  objStack_94[0] = 0;
  piVar6 = func_0014DF18(*(int *)(iVar9 + -0x8fc),DAT_002a7960[1],DAT_002a7960[2],uVar21,0,0);
  fVar23 = DAT_002a7e58;
  *(int **)(iVar9 + -0x1bc) = piVar6;
  func_004FC1CC(iVar11,(int)piVar6,0xb,fVar23);
  uVar21 = func_005330A8(iVar11,0,(int *)(puVar10 + -0x8b));
  objStack_98[0] = 0;
  objStack_94[0] = 0;
  piVar6 = func_0014DF18(*(int *)(iVar9 + -0x8fc),puVar10[1],puVar10[2],uVar21,0,0);
  *(int **)(iVar9 + -0x1b8) = piVar6;
  func_004FC1CC(iVar11,(int)piVar6,0xb,fVar23);
  (*(undefined2 *)((char *)&objStack_98[0] + 0)) = (short)DAT_002a7e5c;
  *(short *)(*(int *)(iVar9 + -0x79c) + 0x28) = (short)DAT_002a7e5c;
  iVar15 = *(int *)(iVar9 + -0x7a8);
  if (iVar15 != 0) {
    *(uint *)(iVar15 + 0x2c) = *(uint *)(iVar15 + 0x2c) | 0x40008;
  }
  uVar14 = DAT_002a7e60;
  if (*(byte *)(iVar9 + -0x3a) < 3) {
    *(undefined4 *)(iVar9 + -0x74) = 10;
    *(undefined4 *)(iVar9 + -0x70) = uVar14;
    *(undefined4 *)(iVar9 + -0x78) = 0;
  }
  objStack_94[2] = iVar9 - 0x3cc;
  *(undefined4 *)(iVar9 + -0xa0) = DAT_002a7e64;
  uVar25 = func_0058A474(iVar11,0x32);
  if ((int)uVar25 != 0) {
    *(undefined1 *)(iVar9 + -0x2f) = 1;
  }
  objStack_98[0] = *(uint *)(iVar9 + -0x174);
  piVar6 = *(int **)(iVar9 + -0xdc);
  iVar15 = *(int *)(iVar9 + -0x170);
  iVar18 = *(int *)(iVar9 + -0x16c);
  iVar13 = *(int *)(iVar9 + -0x168);
  iVar22 = *(int *)(iVar9 + -0x164);
  piVar6[0x16] = *(int *)(iVar9 + -0x178);
  piVar6[0x18] = iVar15;
  iVar15 = DAT_002a7e68;
  piVar6[0x17] = objStack_98[0];
  piVar6[0x19] = iVar18;
  piVar6[0x1a] = iVar13;
  piVar6[0x1b] = iVar22;
  piVar6[0x1c] = iVar15;
  func_004356B4(piVar6);
  iVar15 = func_0054DDF4(iVar11,1);
  *(int *)(iVar9 + 0x28) = iVar15;
  puVar7 = (undefined4 *)func_0010BAB4(0x10);
  uVar21 = objStack_94[1];
  if (puVar7 != (undefined4 *)0x0) {
    puVar7[1] = 0;
    uVar14 = *(undefined4 *)(DAT_002a7968 + 400);
    puVar7[2] = *(undefined4 *)(DAT_002a7968 + 0x18c);
    puVar7[3] = uVar14;
    *puVar7 = uVar17;
  }
  local_78 = (int *)(iVar9 + -400);
  *(undefined4 **)(iVar9 + -400) = puVar7;
  *(int **)(iVar9 + -0x1a8) = piVar6;
  *(undefined2 *)(piVar6 + 10) = 0xa0;
  local_7c = *(undefined1 **)(iVar9 + -0x900);
  objStack_98[0] = (uint)*(short *)(iVar9 + -0xb78);
  objStack_94[0] = objStack_94[1];
  objStack_94[1] = DAT_002a82ec;
  uVar5 = objStack_94[1];
  (*(undefined2 *)((char *)&objStack_94[1] + 0)) = (undefined2)DAT_002a82ec;
  uVar4 = (undefined2)objStack_94[1];
  objStack_94[1] = uVar5;
  func_0014EB8C(*(int *)(iVar9 + -0xd8),*(undefined4 *)(iVar9 + -0xdc),
                *(undefined2 **)(iVar9 + 0x28),(uint *)&local_7c,*(short *)(iVar9 + -0xb78),uVar21,
                uVar4);
  func_004FCF20(local_80,*(int *)(iVar9 + -0xd8));
  iVar15 = DAT_002a7968;
  iVar18 = *(int *)(iVar9 + -0xdc);
  uVar21 = *(uint *)(iVar18 + 0x2c);
  *(uint *)(iVar18 + 0x2c) = uVar21 | 0x40008;
  *(uint *)(*(int *)(iVar9 + -0xdc) + 0x2c) = uVar21 | 0x140008;
  uVar17 = *(undefined4 *)(iVar15 + 0x24);
  iVar18 = *local_78;
  uVar14 = *(undefined4 *)(iVar15 + 0x28);
  *(int *)(iVar18 + 4) = iVar11;
  *(undefined4 *)(iVar18 + 8) = uVar17;
  *(undefined4 *)(iVar18 + 0xc) = uVar14;
  *(int *)(iVar9 + -0x788) = iVar9 + -0x188;
  func_002A3D8C(iVar11);
  func_004FB024(iVar11);
  puVar8 = (undefined4 *)func_0010BAB4(0x48);
  puVar7 = (undefined4 *)0x0;
  if (puVar8 != (undefined4 *)0x0) {
    puVar7 = func_004EDC9C(puVar8);
  }
  *(undefined4 **)(iVar9 + -0x1b4) = puVar7;
  objStack_98[0] = (uint)s_Actor_HagureBoss_kcl_002a82f0;
  local_7c = local_74;
  local_78 = (int *)0x40;
  uStack_35 = 0;
  local_74[0] = 0;
  piVar6 = (int *)(iVar9 + -0x1b4);
  local_80 = DAT_002a8308;
  func_00111A20((int)&local_80,s_Actor_HagureBoss_kcl_002a82f0,objStack_94);
  func_004EDB28(*(int *)(iVar9 + -0x1b4),(int)&local_80);
  *(undefined1 *)(*piVar6 + 0x44) = 0;
  func_002A4DF4(iVar11);
  objStack_94[0] = *(uint *)(iVar9 + -0x900);
  func_004EDAD0(*piVar6,objStack_94);
  iVar15 = DAT_002a7968;
  *(undefined2 *)(*piVar6 + 0x2c) = *(undefined2 *)(iVar9 + -0xb78);
  uVar14 = *(undefined4 *)(iVar15 + 0x2c);
  uVar17 = *(undefined4 *)(iVar15 + 0x30);
  *(int *)(iVar9 + -0x30c) = iVar11;
  *(undefined4 *)(iVar9 + -0x308) = uVar14;
  *(undefined4 *)(iVar9 + -0x304) = uVar17;
  *(int *)(*piVar6 + 0x28) = iVar9 + -0x310;
  func_004A7F00(*DAT_002a830c,*piVar6,3);
  uVar14 = *(undefined4 *)(iVar15 + 0x34);
  uVar17 = *(undefined4 *)(iVar15 + 0x38);
  *(int *)(iVar9 + -0x19c) = iVar11;
  *(undefined4 *)(iVar9 + -0x198) = uVar14;
  *(undefined4 *)(iVar9 + -0x194) = uVar17;
  *(int *)(iVar9 + -0x7e0) = iVar9 + -0x1a0;
  objStack_98[0] = 0x13;
  *(undefined1 *)(iVar9 + -0x1e6) = 0x13;
  *(int *)(iVar9 + -0x1d8) = iVar11;
  iVar15 = func_0010BA78(0x130);
  *(int *)(iVar9 + -0x1d4) = iVar15;
  iVar18 = 0x13;
  *(uint *)(iVar9 + -0x1d0) = iVar15 + (uint)*(byte *)(iVar9 + -0x1e6) * 8;
  puVar7 = (undefined4 *)(iVar15 + -8);
  do {
    uVar14 = *(undefined4 *)(DAT_002a7968 + 0x180);
    iVar18 = iVar18 + -1;
    puVar7[2] = *(undefined4 *)(DAT_002a7968 + 0x17c);
    puVar7[3] = uVar14;
    uVar14 = *(undefined4 *)(iVar2 + 0x180);
    puVar7[4] = *(undefined4 *)(iVar2 + 0x17c);
    puVar7[5] = uVar14;
    puVar7 = puVar7 + 4;
  } while (iVar18 != 0);
  bVar1 = *(byte *)(iVar9 + -0x1e6);
  uVar21 = (uint)bVar1;
  puVar7 = (undefined4 *)func_0010BA78(uVar21 << 3);
  auVar3[0] = objStack_98[0];
  *(undefined4 **)(iVar9 + -0x1cc) = puVar7;
  if (uVar21 != 0) {
    puVar8 = puVar7 + -2;
    if ((bVar1 & 1) != 0) {
      uVar14 = *(undefined4 *)(DAT_002a7968 + 0x50);
      *puVar7 = *(undefined4 *)(DAT_002a7968 + 0x4c);
      puVar7[1] = uVar14;
      puVar8 = puVar7;
    }
    iVar18 = DAT_002a7968;
    for (iVar15 = (int)uVar21 >> 1; iVar15 != 0; iVar15 = iVar15 + -1) {
      uVar14 = *(undefined4 *)(iVar18 + 0x50);
      puVar8[2] = *(undefined4 *)(iVar18 + 0x4c);
      puVar8[3] = uVar14;
      uVar14 = *(undefined4 *)(iVar18 + 0x50);
      puVar8[4] = *(undefined4 *)(iVar18 + 0x4c);
      puVar8[5] = uVar14;
      puVar8 = puVar8 + 4;
    }
  }
  if (0 < (int)objStack_98[0]) {
    puVar7 = (undefined4 *)func_0010CEE0(objStack_98[0] * 0x24 + 8,(int *)0x0,4);
    iVar15 = 0;
    if (puVar7 != (undefined4 *)0x0) {
      *puVar7 = 0x24;
      puVar7[1] = auVar3[0];
      iVar15 = func_00100118((int)(puVar7 + 2),DAT_002a8310,0x24,auVar3[0]);
    }
    if (iVar15 != 0) {
      *(uint *)(iVar9 + -0x1e4) = auVar3[0];
      *(int *)(iVar9 + -0x1e0) = iVar15;
    }
  }
  iVar15 = DAT_002a8314;
  *(int *)(iVar9 + -0x878) = iVar9 + -0x1ec;
  *(undefined2 *)(iVar15 + iVar11) = 0x13;
  local_84 = s_cState_DosunWait_002a8318;
  local_88 = uVar16;
  func_0010BEC4(iVar9 + -0x1ec,0,(int *)&local_88);
  iVar11 = DAT_002a7968;
  puVar7 = *(undefined4 **)(iVar9 + -0x1d4);
  uVar14 = *(undefined4 *)(DAT_002a7968 + 0x44);
  uVar17 = *(undefined4 *)(DAT_002a7968 + 0x48);
  uVar19 = *(undefined4 *)(DAT_002a7968 + 0x40);
  uVar20 = *(undefined4 *)(DAT_002a7968 + 0x4c);
  uVar24 = *(undefined4 *)(DAT_002a7968 + 0x50);
  *puVar7 = *(undefined4 *)(DAT_002a7968 + 0x3c);
  puVar7[1] = uVar19;
  puVar7 = *(undefined4 **)(iVar9 + -0x1d0);
  *puVar7 = uVar14;
  puVar7[1] = uVar17;
  puVar7 = *(undefined4 **)(iVar9 + -0x1cc);
  *puVar7 = uVar20;
  puVar7[1] = uVar24;
  local_84 = s_cState_Move_002a832c;
  local_88 = uVar16;
  func_0010BEC4(iVar9 + -0x1ec,1,(int *)&local_88);
  iVar15 = *(int *)(iVar9 + -0x1d4);
  uVar14 = *(undefined4 *)(iVar11 + 0x58);
  uVar17 = *(undefined4 *)(iVar11 + 0x5c);
  uVar19 = *(undefined4 *)(iVar11 + 0x60);
  *(undefined4 *)(iVar15 + 8) = *(undefined4 *)(iVar11 + 0x54);
  *(undefined4 *)(iVar15 + 0xc) = uVar14;
  iVar15 = *(int *)(iVar9 + -0x1d0);
  *(undefined4 *)(iVar15 + 8) = uVar17;
  *(undefined4 *)(iVar15 + 0xc) = uVar19;
  iVar15 = *(int *)(iVar9 + -0x1cc);
  *(undefined4 *)(iVar15 + 8) = uVar20;
  *(undefined4 *)(iVar15 + 0xc) = uVar24;
  local_84 = s_cState_Seek_002a8338;
  local_88 = uVar16;
  func_0010BEC4(iVar9 + -0x1ec,2,(int *)&local_88);
  iVar15 = *(int *)(iVar9 + -0x1d4);
  uVar14 = *(undefined4 *)(iVar11 + 0x68);
  uVar17 = *(undefined4 *)(iVar11 + 0x6c);
  uVar19 = *(undefined4 *)(iVar11 + 0x70);
  *(undefined4 *)(iVar15 + 0x10) = *(undefined4 *)(iVar11 + 100);
  *(undefined4 *)(iVar15 + 0x14) = uVar14;
  iVar15 = *(int *)(iVar9 + -0x1d0);
  *(undefined4 *)(iVar15 + 0x10) = uVar17;
  *(undefined4 *)(iVar15 + 0x14) = uVar19;
  iVar15 = *(int *)(iVar9 + -0x1cc);
  *(undefined4 *)(iVar15 + 0x10) = uVar20;
  *(undefined4 *)(iVar15 + 0x14) = uVar24;
  local_84 = s_cState_Find_002a8344;
  local_88 = uVar16;
  func_0010BEC4(iVar9 + -0x1ec,3,(int *)&local_88);
  iVar15 = *(int *)(iVar9 + -0x1d4);
  uVar14 = *(undefined4 *)(iVar11 + 0x78);
  uVar17 = *(undefined4 *)(iVar11 + 0x7c);
  uVar19 = *(undefined4 *)(iVar11 + 0x80);
  *(undefined4 *)(iVar15 + 0x18) = *(undefined4 *)(iVar11 + 0x74);
  *(undefined4 *)(iVar15 + 0x1c) = uVar14;
  iVar15 = *(int *)(iVar9 + -0x1d0);
  *(undefined4 *)(iVar15 + 0x18) = uVar17;
  *(undefined4 *)(iVar15 + 0x1c) = uVar19;
  iVar15 = *(int *)(iVar9 + -0x1cc);
  *(undefined4 *)(iVar15 + 0x18) = uVar20;
  *(undefined4 *)(iVar15 + 0x1c) = uVar24;
  local_84 = s_cState_BackStep_002a8350;
  local_88 = uVar16;
  func_0010BEC4(iVar9 + -0x1ec,4,(int *)&local_88);
  iVar15 = *(int *)(iVar9 + -0x1d4);
  uVar14 = *(undefined4 *)(iVar11 + 0x88);
  uVar17 = *(undefined4 *)(iVar11 + 0x8c);
  uVar19 = *(undefined4 *)(iVar11 + 0x90);
  *(undefined4 *)(iVar15 + 0x20) = *(undefined4 *)(iVar11 + 0x84);
  *(undefined4 *)(iVar15 + 0x24) = uVar14;
  iVar15 = *(int *)(iVar9 + -0x1d0);
  *(undefined4 *)(iVar15 + 0x20) = uVar17;
  *(undefined4 *)(iVar15 + 0x24) = uVar19;
  iVar15 = *(int *)(iVar9 + -0x1cc);
  *(undefined4 *)(iVar15 + 0x20) = uVar20;
  *(undefined4 *)(iVar15 + 0x24) = uVar24;
  local_84 = s_cState_Warp_002a870c;
  local_88 = uVar16;
  func_0010BEC4(iVar9 + -0x1ec,5,(int *)&local_88);
  iVar15 = *(int *)(iVar9 + -0x1d4);
  uVar14 = *(undefined4 *)(iVar11 + 0x98);
  uVar17 = *(undefined4 *)(iVar11 + 0x9c);
  uVar19 = *(undefined4 *)(iVar11 + 0xa0);
  *(undefined4 *)(iVar15 + 0x28) = *(undefined4 *)(iVar11 + 0x94);
  *(undefined4 *)(iVar15 + 0x2c) = uVar14;
  iVar15 = *(int *)(iVar9 + -0x1d0);
  *(undefined4 *)(iVar15 + 0x28) = uVar17;
  *(undefined4 *)(iVar15 + 0x2c) = uVar19;
  iVar15 = *(int *)(iVar9 + -0x1cc);
  *(undefined4 *)(iVar15 + 0x28) = uVar20;
  *(undefined4 *)(iVar15 + 0x2c) = uVar24;
  local_84 = s_cState_WarpS_002a8718;
  local_88 = uVar16;
  func_0010BEC4(iVar9 + -0x1ec,6,(int *)&local_88);
  iVar15 = *(int *)(iVar9 + -0x1d4);
  uVar14 = *(undefined4 *)(iVar11 + 0xa8);
  uVar17 = *(undefined4 *)(iVar11 + 0xac);
  uVar19 = *(undefined4 *)(iVar11 + 0xb0);
  *(undefined4 *)(iVar15 + 0x30) = *(undefined4 *)(iVar11 + 0xa4);
  *(undefined4 *)(iVar15 + 0x34) = uVar14;
  iVar15 = *(int *)(iVar9 + -0x1d0);
  *(undefined4 *)(iVar15 + 0x30) = uVar17;
  *(undefined4 *)(iVar15 + 0x34) = uVar19;
  iVar15 = *(int *)(iVar9 + -0x1cc);
  *(undefined4 *)(iVar15 + 0x30) = uVar20;
  *(undefined4 *)(iVar15 + 0x34) = uVar24;
  local_84 = s_cState_Attack_002a8728;
  local_88 = uVar16;
  func_0010BEC4(iVar9 + -0x1ec,7,(int *)&local_88);
  iVar15 = *(int *)(iVar9 + -0x1d4);
  uVar14 = *(undefined4 *)(iVar11 + 0xbc);
  uVar19 = *(undefined4 *)(iVar11 + 0xb8);
  uVar17 = *(undefined4 *)(iVar11 + 0xc0);
  *(undefined4 *)(iVar15 + 0x38) = *(undefined4 *)(iVar11 + 0xb4);
  *(undefined4 *)(iVar15 + 0x3c) = uVar19;
  iVar15 = *(int *)(iVar9 + -0x1d0);
  *(undefined4 *)(iVar15 + 0x38) = uVar14;
  *(undefined4 *)(iVar15 + 0x3c) = uVar17;
  iVar15 = *(int *)(iVar9 + -0x1cc);
  *(undefined4 *)(iVar15 + 0x38) = uVar20;
  *(undefined4 *)(iVar15 + 0x3c) = uVar24;
  local_84 = s_cState_Attack2_002a8738;
  local_88 = uVar16;
  func_0010BEC4(iVar9 + -0x1ec,8,(int *)&local_88);
  iVar15 = *(int *)(iVar9 + -0x1d4);
  uVar19 = *(undefined4 *)(iVar11 + 200);
  uVar14 = *(undefined4 *)(iVar11 + 0xcc);
  uVar17 = *(undefined4 *)(iVar11 + 0xd0);
  *(undefined4 *)(iVar15 + 0x40) = *(undefined4 *)(iVar11 + 0xc4);
  *(undefined4 *)(iVar15 + 0x44) = uVar19;
  iVar15 = *(int *)(iVar9 + -0x1d0);
  *(undefined4 *)(iVar15 + 0x40) = uVar14;
  *(undefined4 *)(iVar15 + 0x44) = uVar17;
  iVar15 = *(int *)(iVar9 + -0x1cc);
  *(undefined4 *)(iVar15 + 0x40) = uVar20;
  *(undefined4 *)(iVar15 + 0x44) = uVar24;
  local_84 = s_cState_Attack3_002a8748;
  local_88 = uVar16;
  func_0010BEC4(iVar9 + -0x1ec,9,(int *)&local_88);
  iVar15 = *(int *)(iVar9 + -0x1d4);
  uVar14 = *(undefined4 *)(iVar11 + 0xd8);
  uVar17 = *(undefined4 *)(iVar11 + 0xe0);
  uVar19 = *(undefined4 *)(iVar11 + 0xdc);
  *(undefined4 *)(iVar15 + 0x48) = *(undefined4 *)(iVar11 + 0xd4);
  *(undefined4 *)(iVar15 + 0x4c) = uVar14;
  iVar15 = *(int *)(iVar9 + -0x1d0);
  *(undefined4 *)(iVar15 + 0x48) = uVar19;
  *(undefined4 *)(iVar15 + 0x4c) = uVar17;
  iVar15 = *(int *)(iVar9 + -0x1cc);
  *(undefined4 *)(iVar15 + 0x48) = uVar20;
  *(undefined4 *)(iVar15 + 0x4c) = uVar24;
  local_84 = s_cState_Attack4_002a8758;
  local_88 = uVar16;
  func_0010BEC4(iVar9 + -0x1ec,10,(int *)&local_88);
  iVar15 = *(int *)(iVar9 + -0x1d4);
  uVar17 = *(undefined4 *)(iVar11 + 0xe8);
  uVar19 = *(undefined4 *)(iVar11 + 0xec);
  uVar14 = *(undefined4 *)(iVar11 + 0xf0);
  *(undefined4 *)(iVar15 + 0x50) = *(undefined4 *)(iVar11 + 0xe4);
  *(undefined4 *)(iVar15 + 0x54) = uVar17;
  iVar15 = *(int *)(iVar9 + -0x1d0);
  *(undefined4 *)(iVar15 + 0x50) = uVar19;
  *(undefined4 *)(iVar15 + 0x54) = uVar14;
  iVar15 = *(int *)(iVar9 + -0x1cc);
  *(undefined4 *)(iVar15 + 0x50) = uVar20;
  *(undefined4 *)(iVar15 + 0x54) = uVar24;
  local_84 = s_cState_Attack5_002a8768;
  local_88 = uVar16;
  func_0010BEC4(iVar9 + -0x1ec,0xb,(int *)&local_88);
  iVar15 = *(int *)(iVar9 + -0x1d4);
  uVar17 = *(undefined4 *)(iVar11 + 0xfc);
  uVar14 = *(undefined4 *)(iVar11 + 0x100);
  uVar19 = *(undefined4 *)(iVar11 + 0xf8);
  *(undefined4 *)(iVar15 + 0x58) = *(undefined4 *)(iVar11 + 0xf4);
  *(undefined4 *)(iVar15 + 0x5c) = uVar19;
  iVar11 = *(int *)(iVar9 + -0x1d0);
  *(undefined4 *)(iVar11 + 0x58) = uVar17;
  *(undefined4 *)(iVar11 + 0x5c) = uVar14;
  iVar11 = *(int *)(iVar9 + -0x1cc);
  *(undefined4 *)(iVar11 + 0x58) = uVar20;
  *(undefined4 *)(iVar11 + 0x5c) = uVar24;
  local_84 = s_cState_Attack6_002a8778;
  local_88 = uVar16;
  func_0010BEC4(iVar9 + -0x1ec,0xc,(int *)&local_88);
  iVar11 = *(int *)(iVar9 + -0x1d4);
  uVar14 = *(undefined4 *)(DAT_002a7968 + 0x108);
  uVar17 = *(undefined4 *)(iVar2 + 0x10c);
  uVar19 = *(undefined4 *)(iVar2 + 0x110);
  *(undefined4 *)(iVar11 + 0x60) = *(undefined4 *)(DAT_002a7968 + 0x104);
  *(undefined4 *)(iVar11 + 100) = uVar14;
  iVar11 = *(int *)(iVar9 + -0x1d0);
  *(undefined4 *)(iVar11 + 0x60) = uVar17;
  *(undefined4 *)(iVar11 + 100) = uVar19;
  iVar11 = *(int *)(iVar9 + -0x1cc);
  *(undefined4 *)(iVar11 + 0x60) = uVar20;
  *(undefined4 *)(iVar11 + 100) = uVar24;
  local_84 = s_cState_Blaze_002a8788;
  local_88 = uVar16;
  func_0010BEC4(iVar9 + -0x1ec,0xd,(int *)&local_88);
  iVar11 = *(int *)(iVar9 + -0x1d4);
  uVar14 = *(undefined4 *)(iVar2 + 0x118);
  uVar17 = *(undefined4 *)(iVar2 + 0x11c);
  uVar19 = *(undefined4 *)(iVar2 + 0x120);
  *(undefined4 *)(iVar11 + 0x68) = *(undefined4 *)(iVar2 + 0x114);
  *(undefined4 *)(iVar11 + 0x6c) = uVar14;
  iVar11 = *(int *)(iVar9 + -0x1d0);
  *(undefined4 *)(iVar11 + 0x68) = uVar17;
  *(undefined4 *)(iVar11 + 0x6c) = uVar19;
  iVar11 = *(int *)(iVar9 + -0x1cc);
  *(undefined4 *)(iVar11 + 0x68) = uVar20;
  *(undefined4 *)(iVar11 + 0x6c) = uVar24;
  local_84 = s_cState_OffShieldDemo_002a8798;
  local_88 = uVar16;
  func_0010BEC4(iVar9 + -0x1ec,0xe,(int *)&local_88);
  iVar11 = *(int *)(iVar9 + -0x1d4);
  uVar14 = *(undefined4 *)(iVar2 + 0x128);
  uVar17 = *(undefined4 *)(iVar2 + 300);
  uVar19 = *(undefined4 *)(iVar2 + 0x130);
  *(undefined4 *)(iVar11 + 0x70) = *(undefined4 *)(iVar2 + 0x124);
  *(undefined4 *)(iVar11 + 0x74) = uVar14;
  iVar11 = *(int *)(iVar9 + -0x1d0);
  *(undefined4 *)(iVar11 + 0x70) = uVar17;
  *(undefined4 *)(iVar11 + 0x74) = uVar19;
  iVar11 = *(int *)(iVar9 + -0x1cc);
  *(undefined4 *)(iVar11 + 0x70) = uVar20;
  *(undefined4 *)(iVar11 + 0x74) = uVar24;
  local_84 = s_cState_SeparationDemo_002a87b0;
  local_88 = uVar16;
  func_0010BEC4(iVar9 + -0x1ec,0xf,(int *)&local_88);
  iVar11 = *(int *)(iVar9 + -0x1d4);
  uVar14 = *(undefined4 *)(iVar2 + 0x13c);
  uVar19 = *(undefined4 *)(iVar2 + 0x140);
  uVar17 = *(undefined4 *)(DAT_002a7968 + 0x138);
  *(undefined4 *)(iVar11 + 0x78) = *(undefined4 *)(DAT_002a7968 + 0x134);
  *(undefined4 *)(iVar11 + 0x7c) = uVar17;
  iVar11 = *(int *)(iVar9 + -0x1d0);
  *(undefined4 *)(iVar11 + 0x78) = uVar14;
  *(undefined4 *)(iVar11 + 0x7c) = uVar19;
  iVar11 = *(int *)(iVar9 + -0x1cc);
  *(undefined4 *)(iVar11 + 0x78) = uVar20;
  *(undefined4 *)(iVar11 + 0x7c) = uVar24;
  local_84 = s_cState_Reaction_002a87c8;
  local_88 = uVar16;
  func_0010BEC4(iVar9 + -0x1ec,0x10,(int *)&local_88);
  iVar11 = *(int *)(iVar9 + -0x1d4);
  uVar14 = *(undefined4 *)(iVar2 + 0x14c);
  uVar17 = *(undefined4 *)(iVar2 + 0x150);
  uVar19 = *(undefined4 *)(iVar2 + 0x148);
  *(undefined4 *)(iVar11 + 0x80) = *(undefined4 *)(iVar2 + 0x144);
  *(undefined4 *)(iVar11 + 0x84) = uVar19;
  iVar9 = *(int *)(iVar9 + -0x1d0);
  *(undefined4 *)(iVar9 + 0x80) = uVar14;
  *(undefined4 *)(iVar9 + 0x84) = uVar17;
  return hagure_boss_tail((int)param_1, DAT_002a7968, local_28);   /* the split tail, EU 2A87D8 */
}

