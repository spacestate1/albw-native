/* compilefix: USA 0031DA18 (EU 0031D9F4), Ghidra-derived (build/ghidra_analyzed4).
 * Failed to compile: use of undeclared identifier 'BADSPACEBASE'
 * Fixed (each an exact C form of the ARM operation; the rest is the converted Ghidra text):
 *  - Ghidra string label with punctuation (s_T<SE_..._ADDR + n) -> s_cf_<ADDR+n>, the same code-section address (checked: add rX,pc,#imm in the ARM) [1]
 *  - ((int)(BADSPACEBASE *)0 + ADDR) + n (a pc-relative address) -> s_cf_<ADDR+n> (string in the code section) [1]
 *  - explicit (T)(uintptr_t) casts at int<->pointer mismatches (identity on the 32-bit ARM) [19]
 *  - explicit casts at pointer-type mismatches (identity on the ARM) [1]
 *  - implicit float<->int conversions (Ghidra COPY between a float and an int-typed variable or
 *    pool word, e.g. `fVar = _DAT_xxx;`, `puVar[3] = fVar;`) made bit copies [7]
 * Confidence: high for the fixes (each class checked against the EU disassembly on sample sites);
 * the function body otherwise has the fidelity of the Ghidra output (bare `return;` exits of
 * functions retyped non-void return 0, as the converter does). */
#include "ghidra_types.h"
#include "../include/ghidra_concat44.h"
extern char s_cf_0031dde6[];
extern char s_cf_0031de58[];
#include "compilefix.h"

extern int func_00100118(int param_1,undefined *param_2,int param_3,int param_4);
extern int func_0010A794(undefined4 *param_1);
extern int func_0010BA78(undefined4 param_1);
extern int func_0010BAB4(undefined4 param_1);
extern int func_0010BEC4(int param_1,uint param_2,int *param_3);
extern int func_0010CEE0(undefined4 param_1,int *param_2,undefined4 param_3);
extern int func_0010DA7C(undefined4 *param_1,undefined4 param_2,int param_3);
extern int func_001119F4(undefined4 *param_1,undefined4 *param_2);
extern int func_0016898C(int param_1,uint *param_2);
extern int func_00169608(uint *param_1,uint param_2,int *param_3,int param_4);
extern int func_00169688(uint *param_1,uint param_2,int *param_3,int param_4);
extern int func_0016A02C(int param_1,int param_2,int *param_3,int param_4);
extern int func_0016A2FC(undefined4 *param_1,int param_2,undefined4 param_3,int param_4);
extern int func_002C11E8(int *param_1,undefined4 param_2,int param_3,undefined1 param_4);
extern int func_002C2D00(int *param_1);
extern int func_0031D1B0(int param_1);
extern int func_0031D578(int param_1,undefined4 param_2,undefined4 param_3,int *param_4);
extern int func_00498624(undefined4 *param_1);
extern float func_004CE804(int param_1,int param_2,int param_3,int param_4,float fparam_0);
extern int func_004CF478(int param_1,int param_2);
extern int func_004CF864(int param_1,uint param_2,uint param_3,float fparam_0);
extern int func_00504D48(int param_1,int param_2);
extern int func_00533400(int param_1,int *param_2);
extern int func_0066552C(undefined4 *param_1,undefined1 param_2);
extern float fRam0031de54;
extern int iRam0031de70;
extern int *piRam0031e264;
extern undefined4 *puRam0031e204;
extern undefined4 *puRam0031e208;
extern undefined4 DAT_0031ddc4;
extern undefined4 DAT_0031ddc8;
extern undefined4 DAT_0031ddcc;
extern undefined4 DAT_0031ddd0;
extern undefined4 DAT_0031ddd4;
extern undefined4 *DAT_0031ddd8;
extern undefined4 DAT_0031dddc;
extern float DAT_0031dde0;
extern undefined DAT_0031dde4;
extern int DAT_0031de08;
extern undefined4 DAT_0031de0c;
extern int *DAT_0031de18;
extern int *DAT_0031de30;
extern char s_APlayerItem_PictureStaffRoll_bch_0031dde6[];
extern char s_PictureStaffRoll_0031de1c[];
extern char s_PictureStaffRoll_Mat_0031de34[];
extern char s_World_0031de10[];
extern char s_cState_BackRoll_0031e22c[];
extern char s_cState_BackWait_0031e21c[];
extern char s_cState_FrontRoll_0031e250[];
extern char s_cState_FrontWait_0031e23c[];
extern char s_cState_Sleep_0031e20c[];
extern char s_change_0031de4c[];
extern char s_stencil_0031de74[];
extern undefined4 _DAT_0031dde4;

// USA 0031DA18 <- EU 0031D9F4 (Ghidra, non-matching)
// GLOBAL DAT_0031ddc4 undefined4
// GLOBAL DAT_0031ddc8 undefined4
// GLOBAL DAT_0031ddcc undefined4
// GLOBAL DAT_0031ddd0 undefined4
// GLOBAL DAT_0031ddd4 undefined4
// GLOBAL DAT_0031ddd8 undefined4 *
// GLOBAL DAT_0031dddc undefined4
// GLOBAL DAT_0031dde0 float
// GLOBAL DAT_0031dde4 undefined
// GLOBAL DAT_0031de08 int
// GLOBAL DAT_0031de0c undefined4
// GLOBAL DAT_0031de18 int *
// GLOBAL DAT_0031de30 int *
// GLOBAL UNK_0031de54 float
// GLOBAL UNK_0031de70 int
// GLOBAL UNK_0031e204 undefined4 *
// GLOBAL UNK_0031e208 undefined *
// GLOBAL UNK_0031e264 int *
// GLOBAL s_cf_0031dde6 string
// GLOBAL s_PictureStaffRoll_0031de1c string
// GLOBAL s_PictureStaffRoll_Mat_0031de34 string
// GLOBAL s_World_0031de10 string
// GLOBAL s_cState_BackRoll_0031e22c string
// GLOBAL s_cState_BackWait_0031e21c string
// GLOBAL s_cState_FrontRoll_0031e250 string
// GLOBAL s_cState_FrontWait_0031e23c string
// GLOBAL s_cState_Sleep_0031e20c string
// GLOBAL s_change_0031de4c string
// GLOBAL s_stencil_0031de74 string

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * func_0031DA18(undefined4 *param_1)

{
  byte bVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 *puVar5;
  uint *puVar6;
  int iVar7;
  undefined4 *puVar8;
  uint uVar9;
  undefined4 extraout_r1;
  int iVar10;
  code *pcVar11;
  undefined4 uVar12;
  int *piVar13;
  undefined4 uVar14;
  undefined4 *puVar15;
  undefined4 uVar16;
  int iVar17;
  float fVar18;
  undefined8 uVar19;
  _Alignas(8) unsigned char albw_frame[0x100];
  #define iStack_100 (*(int *)(albw_frame + 0x0))
  #define local_fc (*(char * *)(albw_frame + 0x4))
  #define local_f8 (*(int *)(albw_frame + 0x8))
  #define local_f4 (*(char * *)(albw_frame + 0xc))
  #define iStack_f0 (*(int *)(albw_frame + 0x10))
  #define uStack_ec (*(undefined4 *)(albw_frame + 0x14))
  #define local_e8 (*(undefined4 *)(albw_frame + 0x18))
  #define local_e4 (*(undefined4 *)(albw_frame + 0x1c))
  #define local_e0 (*(undefined4 *)(albw_frame + 0x20))
  #define uStack_dc (*(undefined4 *)(albw_frame + 0x24))
  #define local_d8 (*(undefined4 *)(albw_frame + 0x28))
  #define local_d4 (*(undefined4 *)(albw_frame + 0x2c))
  #define local_d0 (*(undefined4 *)(albw_frame + 0x30))
  #define local_cc (*(undefined4 *)(albw_frame + 0x34))
  #define local_c8 (*(undefined4 *)(albw_frame + 0x38))
  #define local_c4 (*(int *)(albw_frame + 0x3c))
  #define local_c0 (*(char * *)(albw_frame + 0x40))
  #define local_bc (*(undefined1 *)(albw_frame + 0x44))
  #define local_bb (*(undefined1 *)(albw_frame + 0x45))
  #define local_ba (*(undefined1 *)(albw_frame + 0x46))
  #define local_b9 (*(undefined1 *)(albw_frame + 0x47))
  #define local_b8 (*(undefined1 *)(albw_frame + 0x48))
  #define local_b4 (*(int *)(albw_frame + 0x4c))
  #define pcStack_b0 (*(char * *)(albw_frame + 0x50))
  #define uStack_ac (*(undefined4 *)(albw_frame + 0x54))
  #define local_a8 (*(undefined4 *)(albw_frame + 0x58))
  #define local_a4 (*(undefined1 *)(albw_frame + 0x5c))
  #define iStack_a0 (*(int *)(albw_frame + 0x60))
  #define uStack_9c (*(undefined4 *)(albw_frame + 0x64))
  #define iStack_98 (*(int *)(albw_frame + 0x68))
  #define uStack_94 (*(undefined4 *)(albw_frame + 0x6c))
  #define local_90 (*(int *)(albw_frame + 0x70))
  #define pcStack_8c (*(char * *)(albw_frame + 0x74))
  #define local_88 (*(int *)(albw_frame + 0x78))
  #define local_84 (*(undefined1 *)(albw_frame + 0x7c))
  #define local_83 (*(undefined1 *)(albw_frame + 0x7d))
  #define local_80 (*(undefined4 *)(albw_frame + 0x80))
  #define local_7c (*(undefined4 *)(albw_frame + 0x84))
  #define local_78 (*(undefined4 *)(albw_frame + 0x88))
  #define local_74 (*(undefined4 *)(albw_frame + 0x8c))
  #define local_70 (*(undefined4 *)(albw_frame + 0x90))
  #define local_6c (*(undefined4 *)(albw_frame + 0x94))
  #define local_68 (*(undefined1 *)(albw_frame + 0x98))
  #define local_67 (*(undefined1 *)(albw_frame + 0x99))
  #define iStack_40 (*(int *)(albw_frame + 0xc0))
  #define pcStack_3c (*(char * *)(albw_frame + 0xc4))
  puVar2 = (undefined4 *)(uintptr_t)(func_0010DA7C(param_1,0,3));
  *puVar2 = DAT_0031ddc4;
  puVar2 = (undefined4 *)(uintptr_t)(func_0010A794(puVar2 + 4));
  puVar2[5] = 0;
  puVar2[6] = 0;
  puVar2[7] = 0;
  puVar2[8] = 0;
  puVar2[9] = 0;
  uVar16 = DAT_0031ddc8;
  puVar2[10] = 0;
  uVar12 = DAT_0031ddcc;
  puVar2[0xb] = 0;
  puVar2[0xd] = uVar16;
  puVar2[0xe] = uVar16;
  uVar14 = DAT_0031ddd0;
  puVar2[0x10] = uVar12;
  uVar12 = DAT_0031ddd4;
  puVar2[0x11] = uVar14;
  puVar2[0xf] = 0;
  puVar2[0x12] = uVar12;
  func_001119F4(puVar2 + 0x13,DAT_0031ddd8);
  uVar12 = _DAT_0031dde4;
  fVar18 = DAT_0031dde0;
  uVar19 = CONCAT44(DAT_0031dde0,uVar16);
  puVar2[0x12] = DAT_0031dddc;
  puVar2[0x1f] = ALBW_AS_U32(fVar18);
  puVar2[0x20] = ALBW_AS_U32(fVar18);
  puVar2[0x21] = uVar12;
  puVar2[0x22] = ALBW_AS_U32(fVar18);
  puVar2[0x23] = ALBW_AS_U32(fVar18);
  puVar2[0x24] = ALBW_AS_U32(fVar18);
  puVar2[0x25] = ALBW_AS_U32(fVar18);
  puVar2[0x26] = uVar16;
  puVar2[0x27] = ALBW_AS_U32(fVar18);
  puVar2 = (undefined4 *)(uintptr_t)(func_00498624(puVar2 + 0x28));
  iVar17 = DAT_0031de08;
  *(undefined1 *)(puVar2 + 0x2e) = 0;
  uVar16 = DAT_0031de0c;
  *(undefined1 *)((int)puVar2 + 0xba) = 0;
  puVar15 = puVar2 + -0x2c;
  local_f8 = iVar17;
  local_f4 = s_APlayerItem_PictureStaffRoll_bch_0031dde6 + 2;
  iStack_f0 = iVar17;
  uStack_ec = uVar16;
  local_e8 = 0;
  local_e4 = 0;
  local_e0 = 0x20;
  uStack_dc = 0;
  local_d4 = 0;
  local_c0 = s_World_0031de10;
  local_d0 = 0;
  local_cc = 0;
  local_bc = 7;
  local_d8 = 0;
  local_c8 = 0;
  local_c4 = iVar17;
  local_ba = 0;
  local_b4 = iVar17;
  pcStack_b0 = s_APlayerItem_PictureStaffRoll_bch_0031dde6 + 2;
  uStack_ac = 0;
  local_a8 = 0;
  local_b9 = 1;
  local_bb = 0xff;
  local_a4 = 0;
  local_b8 = 1;
  puVar3 = (undefined4 *)(uintptr_t)(func_00504D48(*DAT_0031de18,(int)&iStack_f0));
  iStack_100 = iVar17;
  local_fc = s_PictureStaffRoll_0031de1c;
  local_90 = func_00533400((int)puVar3,&iStack_100);
  iStack_a0 = iVar17;
  uStack_9c = uVar16;
  pcStack_8c = (char *)0x0;
  iStack_98 = iVar17;
  uStack_94 = uVar16;
  local_68 = 1;
  local_70 = 0;
  local_6c = 0;
  local_7c = 0;
  local_74 = 0;
  local_83 = 1;
  local_80 = 0;
  local_78 = 0;
  local_67 = 0xc4;
  local_84 = 1;
  local_88 = 1;
  piVar4 = (int *)(uintptr_t)(func_002C2D00(&iStack_a0));
  puVar2[-0x1f] = (undefined4)(uintptr_t)(piVar4);
  uVar9 = piVar4[0x59];
  piVar4[0x59] = uVar9 | 0x90000;
  *(uint *)(puVar2[-0x1f] + 0x164) = uVar9 | 0x90001;
  uVar9 = 0;
  if (*(int *)(*DAT_0031de30 + 0xf3c) != 0) {
    uVar9 = *(uint *)(*(int *)(*DAT_0031de30 + 0xf3c) + 4);
  }
  func_004CE804(puVar2[-0x1f],uVar9 & 0xffff,0,0,fVar18);
  func_004CF478(puVar2[-0x1f],1);
  func_004CF864(puVar2[-0x1f],1,0xffffffff,fVar18);
  puVar5 = (undefined4 *)func_0010BAB4(0xa8);
  if (puVar5 == (undefined4 *)0x0) {
    puVar2[-0x1d] = 0;
  }
  else {
    pcStack_3c = s_PictureStaffRoll_Mat_0031de34;
    iStack_40 = iVar17;
    puVar5 = (undefined4 *)(uintptr_t)(func_0016A2FC(puVar5,1,(undefined4)(uintptr_t)(&iStack_40),1));
    puVar2[-0x1d] = (undefined4)(uintptr_t)(puVar5);
  }
  pcStack_3c = s_change_0031de4c;
  iStack_40 = iVar17;
  func_00169608((uint *)puVar2[-0x1d],0,&iStack_40,(int)puVar3);
  func_0016A02C(puVar2[-0x1d],-1,(int *)0xffffffff,puVar2[-0x1f]);
  puVar6 = (uint *)func_002C11E8(&iStack_a0,0,10,0);
  func_0016898C(puVar2[-0x1d],puVar6);
  fVar18 = fRam0031de54;
  iVar7 = *(int *)(puVar2[-0x1d] + 0x14);
  if (*(float *)(iVar7 + 8) != fRam0031de54) {
    *(float *)(iVar7 + 8) = fRam0031de54;
    *(undefined1 *)(iVar7 + 0x26) = 1;
  }
  *(int *)(*(int *)(puVar2[-0x1d] + 0x14) + 0x10) = (int)((ulonglong)uVar19 >> 0x20);
  puVar5 = (undefined4 *)func_0010BAB4(0xa8);
  if (puVar5 == (undefined4 *)0x0) {
    puVar2[-0x1c] = 0;
  }
  else {
    pcStack_8c = (char *)((int)s_cf_0031de58);
    local_90 = iVar17;
    puVar5 = (undefined4 *)(uintptr_t)(func_0016A2FC(puVar5,2,(undefined4)(uintptr_t)(&local_90),1));
    puVar2[-0x1c] = (undefined4)(uintptr_t)(puVar5);
  }
  iVar7 = iRam0031de70;
  uVar9 = 0;
  do {
    uStack_94 = *(undefined4 *)(iVar7 + uVar9 * 4);
    iStack_98 = iVar17;
    func_00169688((uint *)puVar2[-0x1c],uVar9,&iStack_98,(int)puVar3);
    uVar12 = (undefined4)((ulonglong)uVar19 >> 0x20);
    uVar9 = uVar9 + 1;
  } while ((int)uVar9 < 2);
  func_0016A02C(puVar2[-0x1c],-1,(int *)0xffffffff,puVar2[-0x1f]);
  piVar13 = (int *)0x0;
  puVar2[-0x1a] = *(undefined4 *)(*(int *)**(undefined4 **)(puVar2[-0x1c] + 8) + 8);
  puVar6 = (uint *)func_002C11E8(&local_88,1,10,0);
  func_0016898C(puVar2[-0x1c],puVar6);
  *(undefined4 *)(*(int *)(puVar2[-0x1c] + 0x14) + 0x10) = uVar12;
  local_fc = s_stencil_0031de74;
  iStack_100 = iVar17;
  local_90 = func_00533400((int)puVar3,&iStack_100);
  iStack_a0 = iVar17;
  uStack_9c = uVar16;
  pcStack_8c = (char *)0x0;
  local_88 = 0;
  iStack_98 = iVar17;
  uStack_94 = uVar16;
  local_68 = 1;
  local_84 = 0;
  local_70 = 0;
  local_6c = 0;
  local_7c = 0;
  local_80 = 0;
  local_74 = 0;
  local_78 = 0;
  local_67 = 0xc4;
  local_83 = 1;
  piVar4 = (int *)(uintptr_t)(func_002C2D00(&iStack_a0));
  puVar2[-0x1e] = (undefined4)(uintptr_t)(piVar4);
  uVar9 = piVar4[0x59];
  piVar4[0x59] = uVar9 | 0x90000;
  *(uint *)(puVar2[-0x1e] + 0x164) = uVar9 | 0x90001;
  func_004CF864(puVar2[-0x1e],1,0xffffffff,fVar18);
  pcVar11 = *(code **)(*(int *)puVar2[-0x1e] + 0x10);
  (*pcVar11)((int *)puVar2[-0x1e],0xf1);
  func_0031D578((int)puVar15,extraout_r1,(undefined4)(uintptr_t)(pcVar11),piVar13);
  func_0031D1B0((int)puVar15);
  *(undefined1 *)((int)puVar2 + -0x9a) = 5;
  puVar2[-0x23] = (undefined4)(uintptr_t)(puVar15);
  iVar7 = func_0010BA78(0x50);
  puVar2[-0x22] = iVar7;
  puVar3 = puRam0031e204;
  puVar2[-0x21] = iVar7 + (uint)*(byte *)((int)puVar2 + -0x9a) * 8;
  iVar10 = 5;
  puVar5 = (undefined4 *)(iVar7 + -8);
  do {
    uVar16 = puVar3[1];
    puVar5[2] = *puVar3;
    puVar5[3] = uVar16;
    iVar10 = iVar10 + -1;
    uVar16 = puVar3[1];
    puVar5[4] = *puVar3;
    puVar5[5] = uVar16;
    puVar5 = puVar5 + 4;
  } while (iVar10 != 0);
  bVar1 = *(byte *)((int)puVar2 + -0x9a);
  uVar9 = (uint)bVar1;
  puVar5 = (undefined4 *)func_0010BA78(uVar9 << 3);
  puVar2[-0x20] = (undefined4)(uintptr_t)(puVar5);
  if (uVar9 != 0) {
    puVar8 = puVar5 + -2;
    if ((bVar1 & 1) != 0) {
      uVar16 = puVar3[5];
      *puVar5 = puVar3[4];
      puVar5[1] = uVar16;
      puVar8 = puVar5;
    }
    for (iVar7 = (int)uVar9 >> 1; iVar7 != 0; iVar7 = iVar7 + -1) {
      uVar16 = puVar3[5];
      puVar8[2] = puVar3[4];
      puVar8[3] = uVar16;
      uVar16 = puVar3[5];
      puVar8[4] = puVar3[4];
      puVar8[5] = uVar16;
      puVar8 = puVar8 + 4;
    }
  }
  puVar5 = (undefined4 *)func_0010CEE0(0xbc,(int *)0x0,4);
  iVar7 = 0;
  if (puVar5 != (undefined4 *)0x0) {
    *puVar5 = 0x24;
    puVar5[1] = 5;
    iVar7 = func_00100118((int)(puVar5 + 2),(undefined *)(puRam0031e208),0x24,5);
  }
  if (iVar7 != 0) {
    puVar2[-0x25] = iVar7;
    puVar2[-0x26] = 5;
  }
  local_f4 = s_cState_Sleep_0031e20c;
  local_f8 = iVar17;
  func_0010BEC4((int)(puVar2 + -0x28),0,&local_f8);
  puVar5 = (undefined4 *)puVar2[-0x22];
  uVar12 = puVar3[1];
  uVar16 = puVar3[2];
  uVar14 = puVar3[3];
  uVar19 = *(undefined8 *)(puVar3 + 4);
  *puVar5 = *puVar3;
  puVar5[1] = uVar12;
  puVar5 = (undefined4 *)puVar2[-0x21];
  *puVar5 = uVar16;
  puVar5[1] = uVar14;
  puVar5 = (undefined4 *)puVar2[-0x20];
  *puVar5 = (int)uVar19;
  puVar5[1] = (int)((ulonglong)uVar19 >> 0x20);
  local_f4 = s_cState_BackWait_0031e21c;
  local_f8 = iVar17;
  func_0010BEC4((int)(puVar2 + -0x28),1,&local_f8);
  iVar7 = puVar2[-0x22];
  uVar12 = puVar3[7];
  uVar14 = puVar3[8];
  uVar16 = puVar3[9];
  *(undefined4 *)(iVar7 + 8) = puVar3[6];
  *(undefined4 *)(iVar7 + 0xc) = uVar12;
  iVar7 = puVar2[-0x21];
  *(undefined4 *)(iVar7 + 8) = uVar14;
  *(undefined4 *)(iVar7 + 0xc) = uVar16;
  iVar7 = puVar2[-0x20];
  *(int *)(iVar7 + 8) = (int)uVar19;
  *(int *)(iVar7 + 0xc) = (int)((ulonglong)uVar19 >> 0x20);
  local_f4 = s_cState_BackRoll_0031e22c;
  local_f8 = iVar17;
  func_0010BEC4((int)(puVar2 + -0x28),2,&local_f8);
  iVar7 = puVar2[-0x22];
  uVar16 = puVar3[0xb];
  uVar14 = puVar3[0xc];
  uVar12 = puVar3[0xd];
  *(undefined4 *)(iVar7 + 0x10) = puVar3[10];
  *(undefined4 *)(iVar7 + 0x14) = uVar16;
  iVar7 = puVar2[-0x21];
  *(undefined4 *)(iVar7 + 0x10) = uVar14;
  *(undefined4 *)(iVar7 + 0x14) = uVar12;
  iVar7 = puVar2[-0x20];
  *(int *)(iVar7 + 0x10) = (int)uVar19;
  *(int *)(iVar7 + 0x14) = (int)((ulonglong)uVar19 >> 0x20);
  local_f4 = s_cState_FrontWait_0031e23c;
  local_f8 = iVar17;
  func_0010BEC4((int)(puVar2 + -0x28),3,&local_f8);
  iVar7 = puVar2[-0x22];
  uVar12 = puVar3[0xf];
  uVar16 = puVar3[0x10];
  uVar14 = puVar3[0x11];
  *(undefined4 *)(iVar7 + 0x18) = puVar3[0xe];
  *(undefined4 *)(iVar7 + 0x1c) = uVar12;
  iVar7 = puVar2[-0x21];
  *(undefined4 *)(iVar7 + 0x18) = uVar16;
  *(undefined4 *)(iVar7 + 0x1c) = uVar14;
  iVar7 = puVar2[-0x20];
  *(int *)(iVar7 + 0x18) = (int)uVar19;
  *(int *)(iVar7 + 0x1c) = (int)((ulonglong)uVar19 >> 0x20);
  local_f4 = s_cState_FrontRoll_0031e250;
  local_f8 = iVar17;
  func_0010BEC4((int)(puVar2 + -0x28),4,&local_f8);
  iVar17 = puVar2[-0x22];
  uVar12 = puVar3[0x13];
  uVar16 = puVar3[0x14];
  uVar14 = puVar3[0x15];
  *(undefined4 *)(iVar17 + 0x20) = puVar3[0x12];
  *(undefined4 *)(iVar17 + 0x24) = uVar12;
  iVar17 = puVar2[-0x21];
  *(undefined4 *)(iVar17 + 0x20) = uVar16;
  *(undefined4 *)(iVar17 + 0x24) = uVar14;
  iVar17 = puVar2[-0x20];
  *(int *)(iVar17 + 0x20) = (int)uVar19;
  *(int *)(iVar17 + 0x24) = (int)((ulonglong)uVar19 >> 0x20);
  func_0066552C(puVar2 + -0x28,0);
  piVar4 = piRam0031e264;
  *(byte *)(*piRam0031e264 + 0x2c1e) = *(byte *)(*piRam0031e264 + 0x2c1e) | 1;
  *(undefined1 *)(*piVar4 + 0x2c1c) = 1;
  return puVar15;
}

