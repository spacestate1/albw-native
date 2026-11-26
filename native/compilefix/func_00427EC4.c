/* compilefix: USA 00427EC4 (EU 00427EA4), Ghidra-derived (build/ghidra_analyzed4).
 * Failed to compile: use of undeclared identifier 'BADSPACEBASE'
 * Fixed (each an exact C form of the ARM operation; the rest is the converted Ghidra text):
 *  - ((int)(BADSPACEBASE *)0 + ADDR) + n (a pc-relative address) -> s_cf_<ADDR+n> (string in the code section) [1]
 *  - explicit (T)(uintptr_t) casts at int<->pointer mismatches (identity on the 32-bit ARM) [27]
 * Confidence: high for the fixes (each class checked against the EU disassembly on sample sites);
 * the function body otherwise has the fidelity of the Ghidra output (bare `return;` exits of
 * functions retyped non-void return 0, as the converter does). */
#include "ghidra_types.h"
extern char s_cf_00428834[];
#include "compilefix.h"

extern int func_0010B3EC(undefined4 *param_1,int param_2,int param_3);
extern int func_0010BAB4(undefined4 param_1);
extern int func_0016898C(int param_1,uint *param_2);
extern int func_00169608(uint *param_1,uint param_2,int *param_3,int param_4);
extern int func_00169A80(int *param_1,undefined4 param_2,undefined4 param_3,int *param_4);
extern int func_0016A02C(int param_1,int param_2,int *param_3,int param_4);
extern int func_0016A2A4(uint *param_1,uint param_2,int *param_3);
extern int func_0016A2FC(undefined4 *param_1,int param_2,undefined4 param_3,int param_4);
extern int func_002C11E8(int *param_1,undefined4 param_2,int param_3,undefined1 param_4);
extern int func_002C2D00(int *param_1);
extern int func_004CE4C8(int param_1,uint param_2,uint param_3);
extern float func_004CE804(int param_1,int param_2,int param_3,int param_4,float fparam_0);
extern int func_004CF478(int param_1,int param_2);
extern int func_0055326C(void);
extern int func_00564A78(int param_1,int *param_2);
extern float fRam00428804;
extern float fRam00428830;
extern int iRam004287f4;
extern int DAT_004282f8;
extern undefined4 DAT_004282fc;
extern undefined *DAT_00428300;
extern int *DAT_00428310;
extern int DAT_00428324;
extern undefined *PTR_00428314;
extern undefined *PTR_00428318;
extern undefined *PTR_0042831c;
extern undefined *PTR_00428320;
extern char s_Link_Blink_00428848[];
extern char s_Link_BootsChange_00428808[];
extern char s_Link_BraceletChange_0042881c[];
extern char s_Link_Change_004287f8[];
extern char s_animator_00428304[];

// USA 00427EC4 <- EU 00427EA4 (Ghidra, non-matching)
// GLOBAL DAT_004282f8 int
// GLOBAL DAT_004282fc undefined4
// GLOBAL DAT_00428300 undefined *
// GLOBAL DAT_00428310 int *
// GLOBAL DAT_00428324 int
// GLOBAL PTR_00428314 undefined *
// GLOBAL PTR_00428318 undefined *
// GLOBAL PTR_0042831c undefined *
// GLOBAL PTR_00428320 undefined *
// GLOBAL UNK_004287f4 int
// GLOBAL UNK_00428804 float
// GLOBAL UNK_00428830 float
// GLOBAL s_Link_Blink_00428848 string
// GLOBAL s_Link_BootsChange_00428808 string
// GLOBAL s_Link_BraceletChange_0042881c string
// GLOBAL s_Link_Change_004287f8 string
// GLOBAL s_animator_00428304 string

undefined4 * func_00427EC4(undefined4 *param_1,int param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int *piVar6;
  uint uVar7;
  int *piVar8;
  uint *puVar9;
  undefined4 uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  float in_s0;
  float fVar14;
  float fVar15;
  _Alignas(8) unsigned char albw_frame[0x100];
  #define local_100 (*(undefined * *)(albw_frame + 0x0))
  #define local_fc (*(char * *)(albw_frame + 0x4))
  #define aiStack_f8 ((int *)(albw_frame + 0x8))
  #define local_9c (*(undefined * *)(albw_frame + 0x64))
  #define puStack_98 (*(undefined * *)(albw_frame + 0x68))
  #define local_94 (*(undefined * *)(albw_frame + 0x6c))
  #define puStack_90 (*(undefined * *)(albw_frame + 0x70))
  #define local_8c (*(char * *)(albw_frame + 0x74))
  #define uStack_88 (*(undefined4 *)(albw_frame + 0x78))
  #define local_84 (*(undefined4 *)(albw_frame + 0x7c))
  #define local_80 (*(undefined1 *)(albw_frame + 0x80))
  #define local_7f (*(undefined1 *)(albw_frame + 0x81))
  #define local_7c (*(undefined4 *)(albw_frame + 0x84))
  #define local_78 (*(undefined4 *)(albw_frame + 0x88))
  #define local_74 (*(undefined4 *)(albw_frame + 0x8c))
  #define local_70 (*(undefined4 *)(albw_frame + 0x90))
  #define local_6c (*(undefined4 *)(albw_frame + 0x94))
  #define local_68 (*(undefined4 *)(albw_frame + 0x98))
  #define local_64 (*(undefined1 *)(albw_frame + 0x9c))
  #define local_63 (*(undefined1 *)(albw_frame + 0x9d))
  #define puStack_38 (*(undefined * *)(albw_frame + 0xc8))
  #define pcStack_34 (*(char * *)(albw_frame + 0xcc))
  iVar13 = DAT_004282f8;
  *param_1 = DAT_004282fc;
  if (param_2 == 0) {
    uVar10 = *(undefined4 *)(iVar13 + 0x10);
    uVar3 = *(undefined4 *)(iVar13 + 0x14);
  }
  else {
    uVar10 = *(undefined4 *)(iVar13 + 8);
    uVar3 = *(undefined4 *)(iVar13 + 0xc);
  }
  param_1[2] = uVar3;
  param_1[3] = 0;
  param_1[1] = uVar10;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  func_0010B3EC(param_1 + 4,3,(int)(param_1 + 7));
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  func_0010B3EC(param_1 + 0xb,4,(int)(param_1 + 0xe));
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  func_0010B3EC(param_1 + 0x13,2,(int)(param_1 + 0x16));
  puVar4 = (undefined4 *)func_0010BAB4(0xa8);
  puVar1 = DAT_00428300;
  puVar5 = (undefined4 *)0x0;
  if (puVar4 != (undefined4 *)0x0) {
    local_fc = s_animator_00428304;
    local_100 = DAT_00428300;
    puVar5 = (undefined4 *)(uintptr_t)(func_0016A2FC(puVar4,1,(undefined4)(uintptr_t)(&local_100),1));
  }
  param_1[0x18] = (undefined4)(uintptr_t)(puVar5);
  puVar4 = (undefined4 *)func_0010BAB4(0xa8);
  puVar5 = (undefined4 *)0x0;
  if (puVar4 != (undefined4 *)0x0) {
    local_fc = s_animator_00428304;
    local_100 = puVar1;
    puVar5 = (undefined4 *)(uintptr_t)(func_0016A2FC(puVar4,1,(undefined4)(uintptr_t)(&local_100),1));
  }
  param_1[0x19] = (undefined4)(uintptr_t)(puVar5);
  puVar4 = (undefined4 *)func_0010BAB4(0xa8);
  puVar5 = (undefined4 *)0x0;
  if (puVar4 != (undefined4 *)0x0) {
    local_fc = s_animator_00428304;
    local_100 = puVar1;
    puVar5 = (undefined4 *)(uintptr_t)(func_0016A2FC(puVar4,1,(undefined4)(uintptr_t)(&local_100),1));
  }
  param_1[0x1a] = (undefined4)(uintptr_t)(puVar5);
  puVar4 = (undefined4 *)func_0010BAB4(0xa8);
  puVar5 = (undefined4 *)0x0;
  if (puVar4 != (undefined4 *)0x0) {
    local_fc = s_animator_00428304;
    local_100 = puVar1;
    puVar5 = (undefined4 *)(uintptr_t)(func_0016A2FC(puVar4,1,(undefined4)(uintptr_t)(&local_100),1));
  }
  param_1[0x1b] = (undefined4)(uintptr_t)(puVar5);
  if (param_2 == 0) {
    puVar5 = (undefined4 *)0x0;
  }
  else {
    puVar4 = (undefined4 *)func_0010BAB4(0xa8);
    puVar5 = (undefined4 *)0x0;
    if (puVar4 != (undefined4 *)0x0) {
      local_fc = s_animator_00428304;
      local_100 = puVar1;
      puVar5 = (undefined4 *)(uintptr_t)(func_0016A2FC(puVar4,1,(undefined4)(uintptr_t)(&local_100),1));
    }
  }
  param_1[0x1c] = (undefined4)(uintptr_t)(puVar5);
  param_1[0x1d] = 0xffffffff;
  param_1[0x1e] = 0xffffffff;
  param_1[0x1f] = 0;
  *(undefined1 *)(param_1 + 0x20) = 0;
  *(undefined1 *)((int)param_1 + 0x81) = 0;
  if (param_2 != 0) {
    *(undefined1 *)((int)param_1 + 0x81) = 4;
  }
  puVar2 = PTR_00428314;
  iVar13 = *(int *)(*DAT_00428310 + 0x10);
  local_8c = *(char **)(iVar13 + 0x10);
  local_9c = puVar1;
  puStack_98 = PTR_00428314;
  uStack_88 = 0;
  local_94 = puVar1;
  puStack_90 = PTR_00428314;
  local_80 = 0;
  local_64 = 1;
  local_6c = 0;
  local_70 = 0;
  local_68 = 0;
  local_78 = 0;
  local_7f = 1;
  local_84 = 1;
  local_7c = 0;
  local_74 = 0;
  local_63 = 0xc4;
  piVar6 = (int *)(uintptr_t)(func_002C2D00((int *)&local_9c));
  param_1[3] = (undefined4)(uintptr_t)(piVar6);
  piVar6[0x59] = piVar6[0x59] | 1;
  func_004CE4C8(param_1[3],0,0xffffffff);
  func_004CF478(param_1[3],0);
  uVar7 = 0;
  if (*(int *)(*(int *)PTR_00428318 + 0xf3c) != 0) {
    uVar7 = *(uint *)(*(int *)(*(int *)PTR_00428318 + 0xf3c) + 4);
  }
  func_004CE804(param_1[3],uVar7 & 0xffff,0,0,in_s0);
  uVar7 = func_00564A78(param_1[3],(int *)PTR_0042831c);
  param_1[0x1d] = uVar7;
  uVar7 = func_00564A78(param_1[3],(int *)PTR_00428320);
  iVar12 = DAT_004282f8;
  iVar11 = 0;
  param_1[0x1e] = uVar7;
  do {
    if (*(byte *)(iVar12 + iVar11) == 0x20) {
      piVar6 = param_1 + 4;
      if (*piVar6 < (int)param_1[5]) {
        *(undefined4 *)(param_1[6] + *piVar6 * 4) = 0;
        *piVar6 = *piVar6 + 1;
      }
    }
    else {
      local_8c = *(char **)(iVar13 + 0x10 + (uint)*(byte *)(iVar12 + iVar11) * 4);
      local_9c = puVar1;
      puStack_98 = puVar2;
      uStack_88 = 0;
      local_84 = 0;
      local_94 = puVar1;
      puStack_90 = puVar2;
      local_64 = 1;
      local_80 = 0;
      local_6c = 0;
      local_68 = 0;
      local_78 = 0;
      local_7c = 0;
      local_70 = 0;
      local_74 = 0;
      local_63 = 0xc4;
      local_7f = 1;
      piVar6 = (int *)(uintptr_t)(func_002C2D00((int *)&local_9c));
      piVar6[0x59] = piVar6[0x59] | 1;
      func_004CE4C8((int)piVar6,0,0xffffffff);
      func_004CF478((int)piVar6,0);
      uVar7 = 0;
      if (*(int *)(*(int *)PTR_00428318 + 0xf3c) != 0) {
        uVar7 = *(uint *)(*(int *)(*(int *)PTR_00428318 + 0xf3c) + 4);
      }
      func_004CE804((int)piVar6,uVar7 & 0xffff,0,0,fVar14);
      piVar8 = param_1 + 4;
      if (*piVar8 < (int)param_1[5]) {
        *(int **)(param_1[6] + *piVar8 * 4) = piVar6;
        *piVar8 = *piVar8 + 1;
      }
    }
    iVar11 = iVar11 + 1;
  } while (iVar11 < 3);
  iVar12 = 0;
  do {
    local_8c = *(char **)(iVar13 + 0x10 + (uint)*(byte *)(DAT_00428324 + iVar12) * 4);
    local_9c = puVar1;
    puStack_98 = puVar2;
    uStack_88 = 0;
    local_84 = 0;
    local_94 = puVar1;
    puStack_90 = puVar2;
    local_64 = 1;
    local_80 = 0;
    local_78 = 0;
    local_6c = 0;
    local_68 = 0;
    local_63 = 0xc4;
    local_7c = 0;
    local_70 = 0;
    local_74 = 0;
    local_7f = 1;
    piVar6 = (int *)(uintptr_t)(func_002C2D00((int *)&local_9c));
    piVar6[0x59] = piVar6[0x59] | 1;
    func_004CE4C8((int)piVar6,0,0xffffffff);
    func_004CF478((int)piVar6,0);
    uVar7 = 0;
    if (*(int *)(*(int *)PTR_00428318 + 0xf3c) != 0) {
      uVar7 = *(uint *)(*(int *)(*(int *)PTR_00428318 + 0xf3c) + 4);
    }
    func_004CE804((int)piVar6,uVar7 & 0xffff,0,0,fVar14);
    if ((int)param_1[0xb] < (int)param_1[0xc]) {
      *(int **)(param_1[0xd] + param_1[0xb] * 4) = piVar6;
      param_1[0xb] = param_1[0xb] + 1;
    }
    iVar12 = iVar12 + 1;
  } while (iVar12 < 4);
  iVar12 = 0;
  if (param_1[0xb] == 0) {
    uVar10 = 0;
  }
  else {
    uVar10 = *(undefined4 *)param_1[0xd];
  }
  param_1[0x12] = uVar10;
  do {
    puVar5 = (undefined4 *)func_0010BAB4(0xa8);
    puVar9 = (uint *)0x0;
    if (puVar5 != (undefined4 *)0x0) {
      local_8c = s_animator_00428304;
      puStack_90 = puVar1;
      puVar9 = (uint *)(uintptr_t)(func_0016A2FC(puVar5,2,(undefined4)(uintptr_t)(&puStack_90),1));
    }
    uVar7 = 0;
    iVar11 = iRam004287f4 + iVar12 * 4;
    do {
      func_0016A2A4(puVar9,uVar7,*(int **)(iVar13 + 0x110 + *(short *)(iVar11 + uVar7 * 2) * 4));
      uVar7 = uVar7 + 1;
    } while ((int)uVar7 < 2);
    func_0016A02C((int)puVar9,-1,(int *)0xffffffff,param_1[3]);
    piVar6 = param_1 + 0x13;
    if (*piVar6 < (int)param_1[0x14]) {
      *(uint **)(param_1[0x15] + *piVar6 * 4) = puVar9;
      *piVar6 = *piVar6 + 1;
    }
    iVar12 = iVar12 + 1;
  } while (iVar12 < 2);
  puVar9 = (uint *)func_002C11E8(aiStack_f8,0,10,0);
  if ((uint)*(byte *)(param_1 + 0x20) < (uint)param_1[0x13]) {
    iVar13 = *(int *)(param_1[0x15] + (uint)*(byte *)(param_1 + 0x20) * 4);
  }
  else {
    iVar13 = 0;
  }
  func_0016898C(iVar13,puVar9);
  iVar13 = func_0055326C();
  local_fc = s_Link_Change_004287f8;
  local_100 = puVar1;
  func_00169608((uint *)param_1[0x18],0,(int *)&local_100,iVar13);
  func_0016A02C(param_1[0x18],-1,(int *)0xffffffff,param_1[3]);
  piVar6 = (int *)0x0;
  puVar9 = (uint *)func_002C11E8(aiStack_f8,0,10,0);
  iVar12 = param_1[0x18];
  func_0016898C(iVar12,puVar9);
  fVar14 = fRam00428804;
  *(float *)(*(int *)(param_1[0x18] + 0x14) + 0x10) = fRam00428804;
  uVar10 = *(undefined4 *)(param_1[0x18] + 0xc);
  iVar13 = *(int *)(param_1[0x18] + 0x14);
  if (*(float *)(iVar13 + 8) != fVar14) {
    *(float *)(iVar13 + 8) = fVar14;
    *(undefined1 *)(iVar13 + 0x26) = 1;
  }
  func_00169A80((int *)param_1[0x18],uVar10,iVar12,piVar6);
  iVar13 = func_0055326C();
  local_fc = s_Link_BootsChange_00428808;
  local_100 = puVar1;
  func_00169608((uint *)param_1[0x19],0,(int *)&local_100,iVar13);
  func_0016A02C(param_1[0x19],-1,(int *)0xffffffff,param_1[3]);
  piVar6 = (int *)0x0;
  puVar9 = (uint *)func_002C11E8(aiStack_f8,0,10,0);
  iVar12 = param_1[0x19];
  func_0016898C(iVar12,puVar9);
  *(float *)(*(int *)(param_1[0x19] + 0x14) + 0x10) = fVar14;
  uVar10 = *(undefined4 *)(param_1[0x19] + 0xc);
  iVar13 = *(int *)(param_1[0x19] + 0x14);
  if (*(float *)(iVar13 + 8) != fVar14) {
    *(float *)(iVar13 + 8) = fVar14;
    *(undefined1 *)(iVar13 + 0x26) = 1;
  }
  func_00169A80((int *)param_1[0x19],uVar10,iVar12,piVar6);
  iVar13 = func_0055326C();
  local_fc = s_Link_BraceletChange_0042881c;
  local_100 = puVar1;
  func_00169608((uint *)param_1[0x1a],0,(int *)&local_100,iVar13);
  func_0016A02C(param_1[0x1a],-1,(int *)0xffffffff,param_1[3]);
  piVar6 = (int *)0x0;
  puVar9 = (uint *)func_002C11E8(aiStack_f8,0,10,0);
  iVar12 = param_1[0x1a];
  func_0016898C(iVar12,puVar9);
  fVar15 = fRam00428830;
  *(float *)(*(int *)(param_1[0x1a] + 0x14) + 0x10) = fVar14;
  uVar10 = *(undefined4 *)(param_1[0x1a] + 0xc);
  iVar13 = *(int *)(param_1[0x1a] + 0x14);
  if (*(float *)(iVar13 + 8) != fVar15) {
    *(float *)(iVar13 + 8) = fVar15;
    *(undefined1 *)(iVar13 + 0x26) = 1;
  }
  func_00169A80((int *)param_1[0x1a],uVar10,iVar12,piVar6);
  iVar13 = func_0055326C();
  local_fc = (char *)((int)s_cf_00428834);
  local_100 = puVar1;
  func_00169608((uint *)param_1[0x1b],0,(int *)&local_100,iVar13);
  func_0016A02C(param_1[0x1b],-1,(int *)0xffffffff,param_1[3]);
  piVar6 = (int *)0x0;
  puVar9 = (uint *)func_002C11E8(aiStack_f8,0,10,0);
  iVar12 = param_1[0x1b];
  func_0016898C(iVar12,puVar9);
  *(float *)(*(int *)(param_1[0x1b] + 0x14) + 0x10) = fVar14;
  uVar10 = *(undefined4 *)(param_1[0x1b] + 0xc);
  iVar13 = *(int *)(param_1[0x1b] + 0x14);
  if (*(float *)(iVar13 + 8) != fVar14) {
    *(float *)(iVar13 + 8) = fVar14;
    *(undefined1 *)(iVar13 + 0x26) = 1;
  }
  func_00169A80((int *)param_1[0x1b],uVar10,iVar12,piVar6);
  if (param_1[0x1c] != 0) {
    iVar13 = func_0055326C();
    pcStack_34 = s_Link_Blink_00428848;
    puStack_38 = puVar1;
    func_00169608((uint *)param_1[0x1c],0,(int *)&puStack_38,iVar13);
    func_0016A02C(param_1[0x1c],-1,(int *)0xffffffff,param_1[3]);
    puVar9 = (uint *)func_002C11E8((int *)&local_9c,0,10,0);
    func_0016898C(param_1[0x1c],puVar9);
    *(float *)(*(int *)(param_1[0x1c] + 0x14) + 0x10) = fVar15;
    iVar13 = *(int *)(param_1[0x1c] + 0x14);
    if (*(float *)(iVar13 + 8) != fVar14) {
      *(float *)(iVar13 + 8) = fVar14;
      *(undefined1 *)(iVar13 + 0x26) = 1;
    }
  }
  return param_1;
}

