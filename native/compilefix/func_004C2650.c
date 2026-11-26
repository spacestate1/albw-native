/* compilefix: USA 004C2650 (EU 004C2628), Ghidra-derived (build/ghidra_analyzed4).
 * Failed to compile: operand of type 'float' cannot be cast to a pointer type
 * Fixed (each an exact C form of the ARM operation; the rest is the converted Ghidra text):
 *  - (T *)<float expr> -> (T *)CF_FBITS(expr): 32-bit copy of the float (vmov/vstr), never a conversion [5]
 *  - explicit casts at pointer-type mismatches (identity on the ARM) [3]
 * Confidence: high for the fixes (each class checked against the EU disassembly on sample sites);
 * the function body otherwise has the fidelity of the Ghidra output (bare `return;` exits of
 * functions retyped non-void return 0, as the converter does).
 * Fixed (BOOT_LOG 184): the ARM copies this word between a float and an integer (no vcvt), which the
 * converted text wrote as a conversion of the value. */
#include "ghidra_types.h"
#include "compilefix.h"

extern int func_0010A464(undefined4 *param_1);
extern int func_00115C54(float *param_1,float *param_2,float *param_3);
extern int func_0014EEC8(int param_1,uint param_2,undefined4 *param_3,undefined4 param_4,float fparam_0);
extern int func_0014FD6C(int param_1,float *param_2,undefined4 param_3);
extern int func_00150A84(int *param_1,int *param_2,int param_3);
extern int func_0025B61C(int param_1,int param_2,float fparam_0);
extern int func_0025B7B0(int param_1,uint param_2);
extern int func_0025B874(undefined4 *param_1);
extern int func_00392E48(undefined4 *param_1,int param_2,undefined4 *param_3,undefined1 param_4);
extern int func_004A8F40(int param_1,int *param_2,uint param_3);
extern float func_004C2328(int param_1,undefined4 param_2);
extern int func_00520ED8(int param_1);
extern int func_00520EE4(int param_1);
extern int func_00520FF8(int param_1);
extern int func_0052108C(int param_1);
extern int func_00521054(int param_1);
extern int func_005211D8(int param_1);
extern int func_00588BE4(int param_1);
extern char *DAT_004c2958;
extern float DAT_004c295c;
extern float DAT_004c2960;
extern float DAT_004c2964;
extern float DAT_004c2968;
extern char *DAT_004c296c;
extern char *DAT_004c2970;
extern float DAT_004c2974;
extern float DAT_004c2978;
extern undefined4 DAT_004c297c;
extern int *DAT_004c2980;
extern int *DAT_004c2984;
extern char *DAT_004c2988;
extern undefined4 DAT_004c2d78;
extern undefined4 DAT_004c2d7c;
extern undefined4 DAT_004c2d80;
extern float DAT_004c2d84;
extern float DAT_004c2dbc;
extern uint DAT_004c2dc0;
extern int *DAT_004c2dc4;
extern char s_SE_OBJ_FALL_WATER_FLAT_004c2da4[];
extern char s_SE_OBJ_FALL_WATER_FLAT_L_004c2d88[];

// USA 004C2650 <- EU 004C2628 [EDITED REGION: check by hand] (Ghidra, non-matching)
// GLOBAL DAT_004c2958 char *
// GLOBAL DAT_004c295c float
// GLOBAL DAT_004c2960 float
// GLOBAL DAT_004c2964 float
// GLOBAL DAT_004c2968 float
// GLOBAL DAT_004c296c char *
// GLOBAL DAT_004c2970 char *
// GLOBAL DAT_004c2974 float
// GLOBAL DAT_004c2978 float
// GLOBAL DAT_004c297c undefined4
// GLOBAL DAT_004c2980 int *
// GLOBAL DAT_004c2984 int *
// GLOBAL DAT_004c2988 char *
// GLOBAL DAT_004c2d78 undefined4
// GLOBAL DAT_004c2d7c undefined4
// GLOBAL DAT_004c2d80 undefined4
// GLOBAL DAT_004c2d84 float
// GLOBAL DAT_004c2dbc float
// GLOBAL DAT_004c2dc0 uint
// GLOBAL DAT_004c2dc4 int *
// GLOBAL s_SE_OBJ_FALL_WATER_FLAT_004c2da4 string
// GLOBAL s_SE_OBJ_FALL_WATER_FLAT_L_004c2d88 string

/* WARNING: Removing unreachable block (ram,0x004c26d8) */
/* WARNING: Removing unreachable block (ram,0x004c26dc) */
/* WARNING: Removing unreachable block (ram,0x004c26ec) */
/* WARNING: Removing unreachable block (ram,0x004c2838) */
/* WARNING: Removing unreachable block (ram,0x004c283c) */
/* WARNING: Removing unreachable block (ram,0x004c284c) */

undefined4 func_004C2650(int *param_1)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  float *pfVar4;
  int iVar5;
  uint uVar6;
  uint extraout_r1;
  int unaff_r8;
  bool bVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  char *pcVar12;
  char *pcVar13;
  char *pcVar14;
  char *pcVar15;
  _Alignas(8) unsigned char albw_frame[0xd0];
  #define apiStack_d0 ((int * *)(albw_frame + 0x0))
  #define aiStack_c8 ((int *)(albw_frame + 0x8))
  #define uStack_b8 (*(uint *)(albw_frame + 0x18))
  #define uStack_b4 (*(undefined4 *)(albw_frame + 0x1c))
  #define uStack_b0 (*(undefined4 *)(albw_frame + 0x20))
  #define iStack_ac (*(int *)(albw_frame + 0x24))
  #define uStack_a8 (*(undefined1 *)(albw_frame + 0x28))
  #define pcStack_a4 (*(char * *)(albw_frame + 0x2c))
  #define pcStack_a0 (*(char * *)(albw_frame + 0x30))
  #define pcStack_9c (*(char * *)(albw_frame + 0x34))
  #define pcStack_98 (*(char * *)(albw_frame + 0x38))
  #define uStack_94 (*(undefined4 *)(albw_frame + 0x3c))
  #define local_70 (*(char * *)(albw_frame + 0x60))
  #define local_6c (*(char * *)(albw_frame + 0x64))
  #define local_68 (*(char * *)(albw_frame + 0x68))
  #define local_60 (*(char * *)(albw_frame + 0x70))
  #define local_5c (*(undefined4 *)(albw_frame + 0x74))
  #define local_58 (*(char * *)(albw_frame + 0x78))
  #define local_54 (*(undefined4 *)(albw_frame + 0x7c))
  #define local_50 (*(char * *)(albw_frame + 0x80))
  #define local_4c (*(char * *)(albw_frame + 0x84))
  #define local_48 (*(char * *)(albw_frame + 0x88))
  #define local_44 (*(char * *)(albw_frame + 0x8c))
  #define local_40 (*(char * *)(albw_frame + 0x90))
  #define local_3c (*(char * *)(albw_frame + 0x94))
  fVar9 = DAT_004c2960;
  fVar10 = DAT_004c295c;
  pcVar12 = DAT_004c2958;
  bVar7 = (uint)param_1[0x162] < (uint)param_1[0x163];
  if (bVar7) {
    param_1[0x162] = param_1[0x162] + 1;
  }
  fVar8 = ALBW_AS_F32(param_1[0xf8]);
  if (bVar7) {
    unaff_r8 = 0;
  }
  if (!bVar7) {
    unaff_r8 = 1;
  }
  pcVar15 = (char *)CF_FBITS(((fVar9 - fVar8) * fVar10));
  if (ALBW_AS_F32(pcVar15) <= ALBW_AS_F32(pcVar12)) {
    pcVar15 = (char *)CF_FBITS(-ALBW_AS_F32(pcVar15));
  }
  pcVar13 = pcVar12;
  if ((ALBW_AS_F32(pcVar12) <= ALBW_AS_F32(pcVar15)) &&
     (pcVar13 = pcVar15, ALBW_AS_F32(param_1[0x15f]) < ALBW_AS_F32(pcVar15))) {
    pcVar13 = (char *)param_1[0x15f];
  }
  fVar11 = fVar8 + ALBW_AS_F32(pcVar13);
  if ((fVar9 <= fVar11) || (fVar11 < fVar8)) {
    param_1[0xf8] = (int)ALBW_AS_U32(fVar9);
  }
  else {
    param_1[0xf8] = (int)ALBW_AS_U32(fVar11);
  }
  func_00115C54((float *)(param_1 + 0xf4),(float *)(param_1 + 0xf4),(float *)(param_1 + 0xf7));
  pcVar15 = DAT_004c296c;
  fVar9 = (fVar10 * ((ALBW_AS_F32(param_1[0xf5]) - ALBW_AS_F32(param_1[0x15c])) - ALBW_AS_F32(pcVar12))) /
          DAT_004c2968 + DAT_004c2964;
  fVar10 = DAT_004c2964;
  if (0x3f800000 < (int)ALBW_AS_U32(fVar9)) {
    fVar10 = fVar9;
  }
  param_1[0x15d] = (int)ALBW_AS_U32(fVar9);
  param_1[0x15d] = (int)ALBW_AS_U32(fVar10);
  if (unaff_r8 != 0) {
    if (*(char *)((int)param_1 + 0x569) == '\0') {
      *(undefined1 *)((int)param_1 + 0x569) = 1;
      iVar5 = func_00392E48(param_1 + 0xf4,1,(undefined4 *)0x0,0);
      if ((iVar5 == 0) || ((iVar5 == 5 && (*(char *)((int)param_1 + 0x56a) == '\0')))) {
        func_004C2328((int)param_1,3);
        return 0;
      }
    }
    else {
      pfVar4 = (float *)(param_1 + 0x15f);
      fVar10 = *pfVar4;
      pcVar13 = (char *)CF_FBITS(((DAT_004c2974 - fVar10) * ALBW_AS_F32(pcVar15)));
      if (ALBW_AS_F32(pcVar13) <= ALBW_AS_F32(pcVar12)) {
        pcVar13 = (char *)CF_FBITS(-ALBW_AS_F32(pcVar13));
      }
      pcVar14 = pcVar12;
      if ((ALBW_AS_F32(pcVar12) <= ALBW_AS_F32(pcVar13)) &&
         (pcVar14 = pcVar13, ALBW_AS_F32(DAT_004c2970) < ALBW_AS_F32(pcVar13))) {
        pcVar14 = DAT_004c2970;
      }
      fVar9 = fVar10 + ALBW_AS_F32(pcVar14);
      if ((DAT_004c2974 <= fVar9) || (fVar9 < fVar10)) {
        *pfVar4 = DAT_004c2974;
      }
      else {
        *pfVar4 = fVar9;
      }
      fVar10 = ALBW_AS_F32(param_1[0xf9]) * DAT_004c2978;
      param_1[0xf7] = (int)ALBW_AS_U32((ALBW_AS_F32(param_1[0xf7]) * DAT_004c2978));
      param_1[0xf9] = (int)ALBW_AS_U32(fVar10);
    }
  }
  local_40 = pcVar15;
  if (ALBW_AS_F32(pcVar12) < ALBW_AS_F32(param_1[0xf5]) - ALBW_AS_F32(param_1[0x160])) {
    local_40 = (char *)CF_FBITS((ALBW_AS_F32(pcVar15) - (ALBW_AS_F32(param_1[0xf5]) - ALBW_AS_F32(param_1[0x160]))));
  }
  local_50 = pcVar12;
  local_4c = pcVar12;
  local_48 = pcVar12;
  local_44 = pcVar12;
  local_3c = pcVar12;
  iVar5 = func_0014EEC8((int)param_1,(uint)&local_50,(undefined4 *)(&local_44),DAT_004c297c,ALBW_AS_F32(pcVar15));
  pcVar13 = DAT_004c2988;
  piVar3 = DAT_004c2984;
  piVar2 = DAT_004c2980;
  if (iVar5 != 0) {
    func_00115C54((float *)(param_1 + 0xf4),(float *)(param_1 + 0xf4),(float *)&local_50);
    param_1[0xf7] = (int)pcVar12;
    param_1[0xf8] = (int)pcVar12;
    param_1[0xf9] = (int)pcVar12;
    param_1[0x15f] = (int)pcVar12;
    iVar5 = func_00520EE4((int)param_1);
    if (iVar5 != 0) {
      func_004C2328((int)param_1,3);
      return 0;
    }
    iVar5 = func_00520FF8((int)param_1);
    if (iVar5 == 0) {
      func_0010A464((undefined4 *)(apiStack_d0));
      iVar5 = func_00588BE4((int)param_1);
      if (iVar5 == *piVar2) {
        local_54 = DAT_004c2d78;
        local_58 = pcVar13;
        func_00150A84(param_1,(int *)&local_58,(int)apiStack_d0);
      }
      else {
        iVar5 = func_00588BE4((int)param_1);
        if (iVar5 == *piVar3) {
          local_54 = DAT_004c2d7c;
          local_58 = pcVar13;
          func_00150A84(param_1,(int *)&local_58,(int)apiStack_d0);
        }
        else {
          local_5c = DAT_004c2d80;
          local_60 = pcVar13;
          func_00150A84(param_1,(int *)&local_60,(int)apiStack_d0);
        }
      }
      iVar5 = func_00520ED8((int)param_1);
      if (iVar5 != 0) {
        func_0025B61C((int)apiStack_d0,0,DAT_004c2d84);
        local_70 = pcVar13;
        if (*(char *)((int)param_1 + 0x56b) == '\0') {
          local_6c = s_SE_OBJ_FALL_WATER_FLAT_004c2da4;
          func_00150A84(param_1,(int *)&local_70,(int)apiStack_d0);
        }
        else {
          local_6c = s_SE_OBJ_FALL_WATER_FLAT_L_004c2d88;
          func_00150A84(param_1,(int *)&local_70,(int)apiStack_d0);
        }
        func_0025B7B0((int)apiStack_d0,5);
      }
      (**(code **)(param_1[200] + 0x30))(param_1 + 200);
      *(undefined1 *)(param_1 + 0x15a) = 1;
      iVar5 = func_00588BE4((int)param_1);
      if (iVar5 == *piVar3) {
        local_70 = pcVar12;
        local_6c = pcVar15;
        local_68 = pcVar12;
        func_0014FD6C((int)param_1,(float *)&local_70,param_1[0xfa]);
      }
      return func_0025B874((undefined4 *)(apiStack_d0));
    }
    func_004C2328((int)param_1,4);
    return 0;
  }
  iVar5 = func_00520FF8((int)param_1);
  if ((iVar5 != 0) || (iVar5 = func_0052108C((int)param_1), iVar5 != 0)) {
    func_004C2328((int)param_1,4);
    goto LAB_004c2cbc;
  }
  if ((char)param_1[0x15b] != '\0') {
    func_004C2328((int)param_1,5);
    goto LAB_004c2cbc;
  }
  iVar5 = func_00520EE4((int)param_1);
  if (iVar5 == 0) {
    cVar1 = *(char *)((int)param_1 + 0x56a);
    apiStack_d0[0] = param_1 + 0x161;
    if (cVar1 == '\0') {
      iVar5 = func_00521054((int)param_1);
      if (iVar5 == 0) goto LAB_004c2cbc;
      fVar10 = ALBW_AS_F32(param_1[3]);
      if (ALBW_AS_F32(param_1[0xf5]) - DAT_004c2dbc <= ALBW_AS_F32(param_1[3])) {
        fVar10 = ALBW_AS_F32(param_1[0xf5]) - DAT_004c2dbc;
      }
      param_1[0x161] = (int)ALBW_AS_U32(fVar10);
      iVar5 = func_00392E48(param_1 + 0xf4,1,apiStack_d0[0],0);
      if (iVar5 == 0 || iVar5 == 5) {
LAB_004c2cb0:
        *(undefined1 *)((int)param_1 + 0x56a) = 1;
        goto LAB_004c2cbc;
      }
      if (iVar5 != 1) {
        *(undefined1 *)((int)param_1 + 0x56a) = 3;
        goto LAB_004c2cbc;
      }
    }
    else {
      if (cVar1 == '\x01') {
        if (unaff_r8 == 0) goto LAB_004c2cbc;
        goto LAB_004c2c54;
      }
      if (cVar1 == '\x02') {
        if (ALBW_AS_F32(param_1[0xf5]) <= ALBW_AS_F32(param_1[0x161])) {
          param_1[0xf5] = param_1[0x161];
          func_004C2328((int)param_1,4);
          (**(code **)(param_1[200] + 0x38))(param_1 + 200);
        }
        goto LAB_004c2cbc;
      }
      if (cVar1 != '\x03') goto LAB_004c2cbc;
      if (ALBW_AS_F32(param_1[0xf5]) <= ALBW_AS_F32(param_1[0x161])) {
        *(undefined1 *)((int)param_1 + 0x2d7) = 1;
        goto LAB_004c2cbc;
      }
      iVar5 = func_00392E48(param_1 + 0xf4,1,apiStack_d0[0],0);
      if (iVar5 == 0) goto LAB_004c2cb0;
      if (iVar5 != 1) goto LAB_004c2cbc;
    }
    *(undefined1 *)((int)param_1 + 0x56a) = 2;
  }
  else {
LAB_004c2c54:
    func_004C2328((int)param_1,3);
  }
LAB_004c2cbc:
  bVar7 = func_005211D8((int)param_1);
  uStack_b8 = DAT_004c2dc0;
  if (bVar7) {
    *(undefined1 *)((int)param_1 + 0x2d7) = 1;
  }
  uStack_b8 = uStack_b8 | extraout_r1 & 0xffff0000;
  aiStack_c8[0] = 0;
  aiStack_c8[1] = 0;
  aiStack_c8[2] = 0;
  uStack_b4 = 0xff;
  uStack_b0 = 0;
  uStack_a8 = 0;
  aiStack_c8[3] = param_1[0xb3];
  iStack_ac = param_1[0x13f];
  uVar6 = func_004A8F40(*DAT_004c2dc4,aiStack_c8,4);
  if (uVar6 != 0) {
    iVar5 = func_00588BE4((int)param_1);
    if (iVar5 == *piVar2) {
      uStack_94 = DAT_004c2d78;
      pcStack_98 = pcVar13;
      func_00150A84(param_1,(int *)&pcStack_98,0);
    }
    else {
      iVar5 = func_00588BE4((int)param_1);
      if (iVar5 == *piVar3) {
        uStack_94 = DAT_004c2d7c;
        pcStack_98 = pcVar13;
        func_00150A84(param_1,(int *)&pcStack_98,0);
      }
      else {
        pcStack_9c = (char *)DAT_004c2d80;
        pcStack_a0 = pcVar13;
        func_00150A84(param_1,(int *)&pcStack_a0,0);
      }
    }
    (**(code **)(param_1[200] + 0x30))(param_1 + 200);
    *(undefined1 *)(param_1 + 0x15a) = 1;
    iVar5 = func_00588BE4((int)param_1);
    if (iVar5 == *piVar3) {
      pcStack_a4 = pcVar12;
      pcStack_a0 = pcVar15;
      pcStack_9c = pcVar12;
      return func_0014FD6C((int)param_1,(float *)&pcStack_a4,param_1[0xfa]);
    }
  }
  return 0;
}

