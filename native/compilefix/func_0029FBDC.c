/* compilefix: func_0029FBDC, the converted stage-2 text (build/decomp/ghidra_fallback/ghidra_analyzed5_v4/002/func_0029FBDC.c) with inlined two-sided approaches
 * restored (tools/approach_fix.py, BOOT_LOG 150).
 * Fixed (BOOT_LOG 184): the ARM copies this word between a float and an integer (no vcvt), which the
 * converted text wrote as a conversion of the value. */
// MAPFIX-INTEGRATED v1
#include "ghidra_types.h"

extern int func_00115C70(float *param_1,float *param_2,float *param_3);
extern int func_001512B4(int param_1,float *param_2);
extern int func_00291EB8(int param_1);
extern int func_002A11DC(int *param_1);
extern int func_00392E48(undefined4 *param_1,int param_2,undefined4 *param_3,undefined1 param_4);
extern int func_004905E0(float fparam_0);
extern int func_004D838C(float *param_1,float *param_2,float fparam_0,float fparam_1,float fparam_2);
extern int func_004F8738(undefined4 *param_1);
extern int func_004FABDC(int param_1,undefined4 param_2,uint param_3,int param_4);
extern int func_0051D2F4(int *param_1,int param_2,int param_3,int param_4,float fparam_0);
extern int func_00521078(int param_1);
extern int func_0052108C(int param_1);
extern int func_0053F7A8(int param_1);
extern int func_00556E64(int param_1);
extern int func_0058A4BC(undefined4 param_1,float *param_2,float *param_3,float *param_4,undefined1 param_5, undefined4 param_6,uint param_7);
extern int func_00661FE4(undefined4 *param_1,undefined1 param_2);
extern int iRam002a0298;
extern int iRam002a029c;
extern float DAT_0029ff04;
extern float DAT_0029ff08;
extern float DAT_0029ff0c;
extern float DAT_0029ff10;
extern int *DAT_0029ff14;
extern float DAT_0029ff18;
extern float DAT_0029ff1c;
extern float DAT_0029ff20;
extern int DAT_002a0290;
extern int DAT_002a0294;
extern float DAT_002a02a0;
extern float DAT_002a02a4;
extern float DAT_002a02a8;
extern float DAT_002a02ac;
extern int DAT_002a02b0;
extern int DAT_002a02b4;
extern float DAT_002a02b8;
extern float DAT_002a02bc;
extern float DAT_002a02c0;
extern float DAT_002a02c4;
extern float DAT_002a0480;
extern int DAT_002a0484;
extern float DAT_002a0488;
extern undefined4 DAT_002a048c;

// USA 0029FBDC <- EU 0029FBB8 (Ghidra, non-matching)
// GLOBAL DAT_0029ff04 float
// GLOBAL DAT_0029ff08 float
// GLOBAL DAT_0029ff0c float
// GLOBAL DAT_0029ff10 float
// GLOBAL DAT_0029ff14 int *
// GLOBAL DAT_0029ff18 float
// GLOBAL DAT_0029ff1c float
// GLOBAL DAT_0029ff20 float
// GLOBAL DAT_002a0290 int
// GLOBAL DAT_002a0294 int
// GLOBAL DAT_002a02a0 float
// GLOBAL DAT_002a02a4 float
// GLOBAL DAT_002a02a8 float
// GLOBAL DAT_002a02ac float
// GLOBAL DAT_002a02b0 int
// GLOBAL DAT_002a02b4 int
// GLOBAL DAT_002a02b8 float
// GLOBAL DAT_002a02bc float
// GLOBAL DAT_002a02c0 float
// GLOBAL DAT_002a02c4 float
// GLOBAL DAT_002a0480 float
// GLOBAL DAT_002a0484 int
// GLOBAL DAT_002a0488 float
// GLOBAL DAT_002a048c undefined4
// GLOBAL UNK_002a0298 int
// GLOBAL UNK_002a029c int

/* WARNING: Removing unreachable block (ram,0x002a0328) */
/* WARNING: Removing unreachable block (ram,0x002a032c) */
/* WARNING: Removing unreachable block (ram,0x002a0340) */
/* WARNING: Removing unreachable block (ram,0x002a034c) */
/* WARNING: Removing unreachable block (ram,0x002a0354) */
/* WARNING: Removing unreachable block (ram,0x002a0358) */
/* WARNING: Removing unreachable block (ram,0x002a0368) */
/* WARNING: Removing unreachable block (ram,0x002a03d4) */
/* WARNING: Removing unreachable block (ram,0x002a03d8) */
/* WARNING: Removing unreachable block (ram,0x002a03e8) */
/* WARNING: Removing unreachable block (ram,0x002a03f4) */

#ifndef ALBW_APPROACH_DEFINED
#define ALBW_APPROACH_DEFINED
/* inlined two-sided approach (tools/approach_fix.py, BOOT_LOG 150): v -> t by s, no overshoot */
static float albw_approach(float v, float t, float s) {
    float n;
    if (v < t) { n = v + s; return (t <= n || v > n) ? t : n; }
    if (v > t) { n = v - s; if (n <= t) return t; return n <= v ? n : t; }
    return v;
}
#endif
undefined4 func_0029FBDC(int *param_1,uint param_2,float fparam_0,float fparam_1)

{
  _Alignas(8) unsigned char albw_frame[0xd0]; /* entry_sp - 0xd0 .. entry_sp + 0x0 */
#define stack0xffffff30 (*(undefined4 *)(albw_frame + 0x0))
  bool bVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  float *pfVar5;
  int iVar6;
  float fVar7;
  float fVar8;
  uint uVar9;
  float fVar10;
  int iVar11;
  int *piVar12;
  bool bVar13;
  bool bVar14;
  uint in_fpscr;
  float fVar15;
  float fVar16;
  float fVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  #define local_c4 (*(float *)(albw_frame + 0xc))
  #define local_c0 (*(int *)(albw_frame + 0x10))
  #define local_bc (*(float *)(albw_frame + 0x14))
  #define fStack_b8 (*(float *)(albw_frame + 0x18))
  #define local_b4 (*(float *)(albw_frame + 0x1c))
  #define local_b0 (*(float *)(albw_frame + 0x20))
  #define fStack_ac (*(float *)(albw_frame + 0x24))
  #define iStack_a8 (*(int *)(albw_frame + 0x28))
  #define fStack_a4 (*(float *)(albw_frame + 0x2c))
  #define local_a0 ((float *)(albw_frame + 0x30))
  #define local_98 (*(float *)(albw_frame + 0x38))
  #define fStack_88 (*(float *)(albw_frame + 0x48))
  #define iStack_84 (*(int *)(albw_frame + 0x4c))
  #define iStack_78 (*(int *)(albw_frame + 0x58))
  fVar8 = DAT_0029ff0c;
  fVar17 = DAT_0029ff08;
  fVar16 = DAT_0029ff04;
  uVar9 = param_1[0x245];
  if (uVar9 != 0) {
    param_2 = param_1[0x244];
  }
  fVar7 = DAT_0029ff04;
  if ((uVar9 != 0 && param_2 != 0) && (fVar7 = DAT_0029ff08, param_2 < uVar9)) {
    fparam_0 = (float)VectorUnsignedToFloat(param_2,(byte)(in_fpscr >> 0x15) & 3);
    fVar7 = fparam_0 * ALBW_AS_F32(param_1[0x246]);
  }
  bVar14 = (uint)param_1[0x244] < uVar9;
  if (bVar14) {
    param_1[0x244] = param_1[0x244] + 1;
  }
  iVar4 = param_1[0x103];
  if (iVar4 != 0) {
    if (bVar14) {
      param_1[0xf7] = (int)ALBW_AS_U32(fVar16);
      param_1[0xf8] = (int)ALBW_AS_U32(fVar16);
      param_1[0xf9] = (int)ALBW_AS_U32(fVar16);
      param_1[0xf5] = (int)ALBW_AS_U32((ALBW_AS_F32(param_1[0x23d]) + fVar8));
    }
    else {
      param_1[0x167] = param_1[0x167] | 1;
      fVar8 = ALBW_AS_F32(param_1[0x248]);
      if ((uint)param_1[0x247] < (uint)ALBW_AS_U32(fVar8)) {
        bVar13 = fVar8 != 0.0;
        fVar10 = ALBW_AS_F32(param_1[0x247] + 1);
        if (bVar13) {
          fparam_0 = fVar10;
        }
        if (!bVar13 || fVar10 == 0.0) {
          fparam_0 = fVar16;
        }
        param_1[0x247] = (int)ALBW_AS_U32(fVar10);
        fVar15 = fparam_0;
        if ((bVar13 && fVar10 != 0.0) && (fVar15 = fVar17, (uint)ALBW_AS_U32(fparam_0) < (uint)ALBW_AS_U32(fVar8))) {
          fVar8 = (float)VectorUnsignedToFloat(ALBW_AS_U32(fparam_0),(byte)(in_fpscr >> 0x15) & 3);
          fVar15 = fVar8 * ALBW_AS_F32(param_1[0x249]);
        }
        *(float *)(iVar4 + 0x158) = fVar15;
      }
      else {
        *(float *)(iVar4 + 0x158) = fVar17;
        param_1[0x167] = param_1[0x167] | 0x30;
      }
    }
  }
  fVar10 = ALBW_AS_F32(param_1[0xf5]);
  fVar15 = ALBW_AS_F32(param_1[3]) - DAT_0029ff10;
  piVar12 = param_1 + 0x24e;
  fVar8 = fVar10 - fVar15;
  if (fVar10 - fVar15 < fVar16) {
    fVar8 = fVar16;
  }
  bVar13 = *(char *)((int)param_1 + 0x989) != '\0';
  if (bVar13) {
    fVar15 = ALBW_AS_F32(param_1[0x241]);
  }
  bVar1 = fVar15 != fVar10;
  bVar2 = fVar10 <= fVar15;
  fVar10 = DAT_0029ff10;
  if (*(short *)((int)param_1 + 0x90a) == 1) {
    bVar3 = func_00521078((int)param_1);
    if ((!bVar3) && ((param_1[0xe7] & 0x400U) == 0 && (param_1[0xe7] & 0x800U) == 0)) {
      bVar3 = DAT_0029ff20 == fVar8;
      if ((int)ALBW_AS_U32(DAT_0029ff20) <= (int)ALBW_AS_U32(fVar8)) {
        bVar3 = !bVar13 || (!bVar1 || !bVar2);
      }
      if (bVar3) goto LAB_0029fd1c;
    }
    param_1[0xf7] = (int)ALBW_AS_U32(fVar16);
    param_1[0xf8] = (int)ALBW_AS_U32(fVar16);
    param_1[0xf9] = (int)ALBW_AS_U32(fVar16);
    iVar4 = func_0052108C((int)param_1);
    if (iVar4 == 0) {
      bVar14 = func_00521078((int)param_1);
      if (!bVar14 && (!bVar13 || (!bVar1 || !bVar2))) goto LAB_0029fe74;
      if ((bVar13 && bVar1) && (!bVar13 || bVar2)) {
        param_1[0xf5] = param_1[0x241];
      }
    }
    else {
      iVar4 = func_00392E48(param_1 + 0xf4,1,(undefined4 *)0x0,0);
      if (iVar4 == 2) {
LAB_0029fe74:
        return func_00661FE4(piVar12,3);
      }
    }
    func_002A11DC(param_1);
    return func_00661FE4(piVar12,2);
  }
LAB_0029fd1c:
  bVar13 = false;
  uVar18 = CONCAT44(fVar8 * DAT_0029ff18,fVar17);
  iVar4 = *DAT_0029ff14;
  if ((iVar4 == 0) || (bVar2 = func_00556E64(iVar4), bVar2)) {
    local_c4 = ALBW_AS_F32(param_1[600]);
    bVar13 = true;
    local_bc = ALBW_AS_F32(param_1[0x25a]);
    local_c0 = param_1[0xf5];
  }
  else {
    pfVar5 = *(float **)(iVar4 + 0x1c);
    func_00115C70(&local_b4,pfVar5,(float *)(param_1 + 0xf4));
    if ((((int)ALBW_AS_U32((local_b4 * local_b4 + local_b0 * local_b0 + fStack_ac * fStack_ac)) < 0x3f800000) &&
        (iVar11 = func_0053F7A8(iVar4), iVar11 == 0)) && (iVar4 = func_00291EB8(iVar4), iVar4 != 0))
    {
      return func_00661FE4(piVar12,8);
    }
    local_c4 = *pfVar5;
    local_bc = pfVar5[2];
    local_c0 = param_1[0xf5];
  }
  func_00115C70(local_a0,&local_c4,(float *)(param_1 + 600));
  uVar19 = CONCAT44(fVar10,fVar16);
  bVar2 = false;
  fVar17 = local_a0[0] * local_a0[0] + local_98 * local_98;
  fVar8 = (ALBW_AS_F32(param_1[0x23d]) + DAT_0029ff1c) - ALBW_AS_F32(param_1[0xf5]);
  if (!bVar14) {
    if ((bVar13) || ((uint)param_1[0x24b] <= (uint)param_1[0x24a])) {
      bVar2 = true;
    }
    else {
      param_1[0x24a] = param_1[0x24a] + 1;
      bVar2 = false;
    }
  }
  iVar4 = DAT_002a0294;
  if ((DAT_002a0290 < (int)ALBW_AS_U32(fVar8)) && (bVar2)) {
    if (*(short *)((int)param_1 + 0x90a) == 0) {
      *(undefined2 *)((int)param_1 + 0x90a) = 1;
      param_1[0xf8] = iVar4;
      func_004FABDC((int)param_1,1,0xffffffff,0);
      iVar4 = iRam002a0298;
      param_1[0x241] = param_1[3];
      iVar11 = 0;
      *(undefined1 *)((int)param_1 + 0x989) = 0;
      do {
        fStack_ac = ALBW_AS_F32(param_1[0xf4]);
        iStack_a8 = param_1[0xf5];
        fStack_a4 = ALBW_AS_F32(param_1[0xf6]);
        fStack_b8 = ALBW_AS_F32(param_1[0xf4]);
        local_b4 = ALBW_AS_F32(param_1[0xf5]);
        local_b0 = ALBW_AS_F32(param_1[0xf6]);
        func_004F8738(&fStack_88);
        pfVar5 = (float *)(iVar4 + iVar11 * 8);
        fVar8 = *pfVar5;
        fVar10 = pfVar5[1];
        fStack_ac = fStack_ac + fVar8;
        fStack_a4 = fStack_a4 + fVar10;
        fStack_b8 = fStack_b8 + fVar8;
        local_b0 = local_b0 + fVar10;
        local_b4 = ALBW_AS_F32(param_1[0x241]);
        iVar6 = func_0058A4BC(param_1,&fStack_ac,&fStack_b8,&fStack_88,0,0,0xf);
        if ((iVar6 != 0) && (iRam002a029c < iStack_78)) {
          param_1[0x241] = iStack_84;
          *(undefined1 *)((int)param_1 + 0x989) = 1;
        }
        iVar11 = iVar11 + 1;
      } while (iVar11 < 4);
    }
  }
  else if (*(short *)((int)param_1 + 0x90a) == 0) {
    if (local_98 == fVar16 && local_a0[0] == fVar16) {
      iVar4 = 0;
    }
    else if (local_98 < fVar16) {
      if (local_a0[0] < fVar16) {
        if (local_a0[0] < local_98) {
          iVar4 = func_004905E0(local_98 / local_a0[0]);
          iVar4 = -0x40000000 - iVar4;
        }
        else {
          iVar4 = func_004905E0(local_a0[0] / local_98);
          iVar4 = iVar4 + -0x80000000;
        }
      }
      else {
        local_98 = -local_98;
        if (local_98 < local_a0[0]) {
          iVar4 = func_004905E0(local_98 / local_a0[0]);
          iVar4 = iVar4 + 0x40000000;
        }
        else {
          iVar4 = func_004905E0(local_a0[0] / local_98);
          iVar4 = -0x80000000 - iVar4;
        }
      }
    }
    else if (local_a0[0] < fVar16) {
      local_a0[0] = -local_a0[0];
      if (local_98 < local_a0[0]) {
        iVar4 = func_004905E0(local_98 / local_a0[0]);
        iVar4 = iVar4 + -0x40000000;
      }
      else {
        iVar4 = func_004905E0(local_a0[0] / local_98);
        iVar4 = -iVar4;
      }
    }
    else if (local_98 < local_a0[0]) {
      iVar4 = func_004905E0(local_98 / local_a0[0]);
      iVar4 = 0x40000000 - iVar4;
    }
    else {
      iVar4 = func_004905E0(local_a0[0] / local_98);
    }
    fVar15 = DAT_002a02a4;
    fVar10 = DAT_002a02a0;
    param_1[0x24d] = iVar4;
    param_1[0xf8] = (int)ALBW_AS_U32(((ALBW_AS_F32(param_1[0xf8]) + fVar8 * fVar10) * fVar15));
  }
  if ((int)ALBW_AS_U32(fVar7) < 0x3f800000) {
    param_1[0xfa] = param_1[0x24d];
  }
  else {
    fVar17 = fVar17 * DAT_002a02a8;
    fVar8 = ALBW_AS_F32(uVar19);
    if ((fVar8 <= fVar17) && (fVar8 = fVar17, ALBW_AS_F32(uVar18) < fVar17)) {
      fVar8 = ALBW_AS_F32(uVar18);
    }
    func_0051D2F4(param_1 + 0xfa,param_1[0x24d],DAT_002a02b4,DAT_002a02b0,fVar8 * DAT_002a02ac);
  }
  fVar17 = DAT_002a02b8;
  if (*(short *)((int)param_1 + 0x90a) == 0) {
    fVar8 = ALBW_AS_F32(((ulonglong)uVar19 >> 0x20)) +
            (ALBW_AS_F32(uVar18) - ALBW_AS_F32(((ulonglong)uVar18 >> 0x20))) * DAT_002a0480;
    uVar19 = CONCAT44(fVar8,(int)uVar19);
    param_1[0x23e] = (int)ALBW_AS_U32(fVar8);
  }
  else {
    param_1[0x23e] = (int)ALBW_AS_U32(DAT_002a02b8);
  }
  fVar8 = DAT_002a02bc;
  fVar7 = ALBW_AS_F32(uVar19);
  pfVar5 = (float *)(param_1 + 0x23f);
  if (bVar14) {
    fVar8 = *pfVar5 + DAT_002a0488;
    if ((DAT_002a02bc <= fVar8) || (fVar8 < *pfVar5)) {
      *pfVar5 = DAT_002a02bc;
      goto LAB_002a03f8;
    }
  }
  else {
    if (*(short *)((int)param_1 + 0x90a) != 1) {
      *pfVar5 = albw_approach(*pfVar5, DAT_002a02c0, DAT_002a02c4);   /* two-sided approach restored (approach_fix) */
      fVar7 = ALBW_AS_F32(param_1[0x23f]);
      if (DAT_002a0484 <= (int)ALBW_AS_U32(fVar7)) {
        fVar7 = fVar8;
      }
      goto LAB_002a03f8;
    }
    fVar8 = *pfVar5 + DAT_002a02c0;
    fVar7 = fVar17;
    if ((fVar17 <= fVar8) || (fVar8 < *pfVar5)) {
      *pfVar5 = fVar17;
      goto LAB_002a03f8;
    }
  }
  *pfVar5 = fVar8;
LAB_002a03f8:
  func_004D838C((float *)(param_1 + 600),&local_c4,ALBW_AS_F32(param_1[0x23e]),fVar7,ALBW_AS_F32(param_1[0x23f])
               );
  param_1[0x259] = param_1[0xf5];
  param_1[0xf4] = (int)ALBW_AS_U32((ALBW_AS_F32(param_1[600]) + fVar16));
  param_1[0xf6] = (int)ALBW_AS_U32((ALBW_AS_F32(param_1[0x25a]) + fVar16));
  if (param_1[599] == 0) {
    return 0;
  }
  return func_001512B4(param_1[599],(float *)&stack0xffffff30);
}

