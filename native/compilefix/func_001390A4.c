/* compilefix: USA 001390A4 (EU 001390A4), the converted stage-2 text.
 * Fixed (BOOT_LOG 184): the ARM copies this word between a float and an integer (no vcvt), which the
 * converted text wrote as a conversion of the value. */
#include "ghidra_types.h"

extern int func_00100118(int param_1,undefined *param_2,int param_3,int param_4);
extern int func_0010A794(undefined4 *param_1);
extern int func_0010BA78(undefined4 param_1);
extern int func_0010BAB4(undefined4 param_1);
extern int func_0010CEE0(undefined4 param_1,int *param_2,undefined4 param_3);
extern undefined8 func_0010E3C4(uint *param_1,uint *param_2,uint param_3);
extern int func_00111A20(int param_1,undefined4 param_2,uint *param_3);
extern int func_001151CC(undefined4 *param_1,undefined4 *param_2);
extern int func_00115C54(float *param_1,float *param_2,float *param_3);
extern int func_0014E428(int param_1,undefined4 param_2,int param_3,uint param_4,int param_5, undefined1 param_6,undefined1 param_7);
extern int func_00150E40(undefined4 *param_1,uint *param_2);
extern int func_0034CAA0(undefined4 *param_1);
extern int func_004356B4(int *param_1);
extern int func_0043625C(int *param_1,undefined4 *param_2);
extern float func_00491624(float *param_1,uint param_2,uint param_3,uint param_4);
extern int func_004A879C(int param_1,int param_2,uint param_3);
extern float func_004D8AEC(float *param_1,uint param_2,float *param_3);
extern int func_004ED9C8(int param_1);
extern int func_004EDAD0(int param_1,uint *param_2);
extern int func_004EDB28(int param_1,int param_2);
extern int func_004EDC9C(undefined4 *param_1);
extern int func_0054D964(int param_1,uint param_2);
extern int func_00588BF0(int param_1,int param_2);
extern int func_006571B4(undefined4 *param_1,undefined1 param_2);
extern int DAT_00139580;
extern undefined4 *DAT_00139584;
extern undefined4 DAT_00139588;
extern undefined4 DAT_0013958c;
extern float DAT_00139590;
extern int DAT_00139594;
extern float DAT_001395ac;
extern float DAT_001395b0;
extern float DAT_001395b4;
extern float *DAT_001395b8;
extern undefined4 DAT_00139964;
extern int *DAT_00139968;
extern undefined *DAT_0013996c;
extern int DAT_00139970;
extern undefined4 *DAT_00139980;
extern float DAT_00139b1c;
extern char s_Actor_BlockIce_kcl_00139598[];
extern char s_cState_Erase_00139990[];
extern char s_cState_Melt_00139984[];
extern char s_cState_Wait_00139974[];
extern char s_cf_00139598[];

// USA 001390A4 <- EU 001390A4 (Ghidra, non-matching)
// GLOBAL DAT_00139580 int
// GLOBAL DAT_00139584 undefined4 *
// GLOBAL DAT_00139588 undefined4
// GLOBAL DAT_0013958c undefined4
// GLOBAL DAT_00139590 float
// GLOBAL DAT_00139594 int
// GLOBAL DAT_001395ac float
// GLOBAL DAT_001395b0 float
// GLOBAL DAT_001395b4 float
// GLOBAL DAT_001395b8 float *
// GLOBAL DAT_00139964 undefined4
// GLOBAL DAT_00139968 int *
// GLOBAL DAT_0013996c undefined *
// GLOBAL DAT_00139970 int
// GLOBAL DAT_00139980 undefined4 *
// GLOBAL DAT_00139b1c float
// GLOBAL s_cf_00139598 string
// GLOBAL s_cState_Erase_00139990 string
// GLOBAL s_cState_Melt_00139984 string
// GLOBAL s_cState_Wait_00139974 string

/* WARNING: Variable defined which should be unmapped: objStack_98 */
/* WARNING: Variable defined which should be unmapped: objStack_94 */
/* WARNING: Variable defined which should be unmapped: objStack_90 */

undefined4 * func_001390A4(undefined4 *param_1,uint *param_2)

{
  float *pfVar1;
  uint auVar2 [1];
  byte bVar3;
  bool bVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  int iVar10;
  undefined4 *puVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  undefined4 uVar15;
  undefined4 *puVar16;
  int iVar17;
  int iVar18;
  uint *puVar19;
  bool bVar20;
  float fVar21;
  undefined4 uVar22;
  undefined4 uVar23;
  undefined4 uVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  _Alignas(8) unsigned char albw_frame[0xa0];
  #define objStack_98 ((uint *)(albw_frame + 0x8))
  #define objStack_94 ((uint *)(albw_frame + 0xc))
  #define objStack_90 ((uint *)(albw_frame + 0x10))
  #define local_88 (*(int *)(albw_frame + 0x18))
  #define local_84 (*(uint * *)(albw_frame + 0x1c))
  #define local_80 (*(float *)(albw_frame + 0x20))
  #define local_7c (*(float * *)(albw_frame + 0x24))
  #define local_78 (*(float *)(albw_frame + 0x28))
  #define local_74 (*(float *)(albw_frame + 0x2c))
  #define local_70 (*(float *)(albw_frame + 0x30))
  #define local_6c (*(float *)(albw_frame + 0x34))
  #define local_68 (*(float *)(albw_frame + 0x38))
  #define local_64 (*(float *)(albw_frame + 0x3c))
  #define local_60 (*(float *)(albw_frame + 0x40))
  #define uStack_35 (*(undefined1 *)(albw_frame + 0x6b))
  piVar5 = func_00150E40(param_1,param_2);
  iVar10 = DAT_00139580;
  *piVar5 = DAT_00139580;
  piVar5[200] = iVar10 + 0x54;
  puVar6 = func_0010A794(piVar5 + 0x103);
  puVar6[5] = 0;
  puVar6[6] = 0;
  puVar6[7] = 0;
  puVar6[8] = 0;
  objStack_98[0] = 1;
  objStack_94[0] = 0;
  puVar16 = puVar6 + -0x103;
  objStack_90[0] = 1;
  uVar7 = func_0014E428((int)puVar16,1,0,0,1,0,1);
  puVar6[9] = uVar7;
  puVar8 = (undefined4 *)func_0010BAB4(0x48);
  puVar9 = (undefined4 *)0x0;
  if (puVar8 != (undefined4 *)0x0) {
    puVar9 = func_004EDC9C(puVar8);
  }
  puVar6[10] = puVar9;
  piVar5 = puVar6 + 10;
  iVar10 = func_0054D964((int)puVar16,0);
  objStack_98[0] = (uint)(puVar6 + 0xb);
  puVar6[0xb] = iVar10;
  puVar8 = (undefined4 *)func_0010BAB4(0x48);
  puVar9 = (undefined4 *)0x0;
  if (puVar8 != (undefined4 *)0x0) {
    puVar9 = func_0034CAA0(puVar8);
  }
  puVar8 = DAT_00139584;
  puVar6[0xc] = puVar9;
  puVar6[0xe] = 0;
  uVar7 = puVar8[0x13];
  puVar6[0xf] = puVar8[0x12];
  puVar6[0x10] = uVar7;
  puVar6[0xd] = DAT_00139588;
  uVar12 = param_2[5];
  uVar14 = param_2[6];
  puVar6[0x11] = param_2[4];
  puVar6[0x12] = uVar12;
  puVar6[0x13] = uVar14;
  (*(undefined2 *)((char *)&objStack_94[0] + 0)) = (short)DAT_0013958c;
  *(short *)(puVar6[0xb] + 0x28) = (short)DAT_0013958c;
  uVar7 = *puVar8;
  uVar15 = puVar8[1];
  puVar6[0xe] = puVar16;
  puVar6[0xf] = uVar7;
  puVar6[0x10] = uVar15;
  iVar10 = puVar6[9];
  *(uint *)(iVar10 + 0x164) = *(uint *)(iVar10 + 0x164) | 0x40000000;
  func_004D8AEC((float *)(iVar10 + 0x80),puVar6[-9],(float *)(puVar6 + -0xf));
  (**(code **)(*(int *)puVar6[9] + 0x10))((int *)puVar6[9],0x24);
  iVar10 = DAT_00139594;
  iVar18 = DAT_00139594 + 8;
  fVar25 = DAT_00139590;
  if (puVar6[10] == 0) goto LAB_00139658;
  objStack_94[0] = (uint)s_Actor_BlockIce_kcl_00139598;
  local_7c = &local_74;
  local_78 = 8.96831e-44;
  uStack_35 = 0;
  local_74 = ALBW_AS_F32(((uint)ALBW_AS_U32(local_74) & 0xffffff00));
  local_80 = DAT_001395ac;
  func_00111A20((int)&local_80,s_Actor_BlockIce_kcl_00139598,objStack_90);
  func_004EDB28(puVar6[10],(int)&local_80);
  func_00491624(&local_80,param_2[7],param_2[8],param_2[9]);
  fVar27 = DAT_001395b4;
  fVar26 = DAT_001395b0;
  iVar17 = *(int *)(*piVar5 + 0x14);
  fVar21 = local_80 - *(float *)(iVar17 + 0x18);
  bVar4 = DAT_001395b4 == fVar21;
  bVar20 = fVar21 <= DAT_001395b4;
  if (!bVar20 || bVar4) {
    bVar4 = fVar21 == DAT_001395b0;
    bVar20 = DAT_001395b0 <= fVar21;
  }
  if (bVar20 && !bVar4) {
LAB_001393c0:
    bVar4 = false;
  }
  else {
    fVar21 = ALBW_AS_F32(local_7c) - *(float *)(iVar17 + 0x1c);
    bVar4 = DAT_001395b4 == fVar21;
    bVar20 = fVar21 <= DAT_001395b4;
    if (!bVar20 || bVar4) {
      bVar4 = fVar21 == DAT_001395b0;
      bVar20 = DAT_001395b0 <= fVar21;
    }
    if (bVar20 && !bVar4) goto LAB_001393c0;
    fVar21 = local_78 - *(float *)(iVar17 + 0x20);
    bVar4 = DAT_001395b4 == fVar21;
    bVar20 = fVar21 <= DAT_001395b4;
    if (!bVar20 || bVar4) {
      bVar4 = fVar21 == DAT_001395b0;
      bVar20 = DAT_001395b0 <= fVar21;
    }
    if (bVar20 && !bVar4) goto LAB_001393c0;
    fVar21 = local_74 - *(float *)(iVar17 + 0x24);
    bVar4 = DAT_001395b4 == fVar21;
    bVar20 = fVar21 <= DAT_001395b4;
    if (!bVar20 || bVar4) {
      bVar4 = fVar21 == DAT_001395b0;
      bVar20 = DAT_001395b0 <= fVar21;
    }
    if (bVar20 && !bVar4) goto LAB_001393c0;
    fVar21 = local_70 - *(float *)(iVar17 + 0x28);
    bVar4 = DAT_001395b4 == fVar21;
    bVar20 = fVar21 <= DAT_001395b4;
    if (!bVar20 || bVar4) {
      bVar4 = fVar21 == DAT_001395b0;
      bVar20 = DAT_001395b0 <= fVar21;
    }
    if (bVar20 && !bVar4) goto LAB_001393c0;
    fVar21 = local_6c - *(float *)(iVar17 + 0x2c);
    bVar4 = DAT_001395b4 == fVar21;
    bVar20 = fVar21 <= DAT_001395b4;
    if (!bVar20 || bVar4) {
      bVar4 = fVar21 == DAT_001395b0;
      bVar20 = DAT_001395b0 <= fVar21;
    }
    if (bVar20 && !bVar4) goto LAB_001393c0;
    fVar21 = local_68 - *(float *)(iVar17 + 0x30);
    bVar4 = DAT_001395b4 == fVar21;
    bVar20 = fVar21 <= DAT_001395b4;
    if (!bVar20 || bVar4) {
      bVar4 = fVar21 == DAT_001395b0;
      bVar20 = DAT_001395b0 <= fVar21;
    }
    if (bVar20 && !bVar4) goto LAB_001393c0;
    fVar21 = local_64 - *(float *)(iVar17 + 0x34);
    bVar4 = DAT_001395b4 == fVar21;
    bVar20 = fVar21 <= DAT_001395b4;
    if (!bVar20 || bVar4) {
      bVar4 = fVar21 == DAT_001395b0;
      bVar20 = DAT_001395b0 <= fVar21;
    }
    if (bVar20 && !bVar4) goto LAB_001393c0;
    fVar21 = local_60 - *(float *)(iVar17 + 0x38);
    bVar4 = DAT_001395b4 == fVar21;
    bVar20 = fVar21 <= DAT_001395b4;
    if (!bVar20 || bVar4) {
      bVar4 = fVar21 == DAT_001395b0;
      bVar20 = DAT_001395b0 <= fVar21;
    }
    if (bVar20 && !bVar4) goto LAB_001393c0;
    bVar4 = true;
  }
  if (!bVar4) {
    bVar3 = *(byte *)(iVar17 + 0xa8);
    *(byte *)(iVar17 + 0xa8) = bVar3 | 8;
    uVar7 = DAT_00139964;
    if ((((local_80 == 1.0 && ALBW_AS_F32(local_7c) == fVar25) &&
         (local_78 == fVar25 && local_74 == fVar25)) && (local_70 == 1.0 && local_6c == fVar25)) &&
       ((local_68 == fVar25 && local_64 == fVar25) && local_60 == 1.0)) {
      bVar3 = bVar3 & 0xfb | 8;
      *(undefined4 *)(iVar17 + 0x18) = DAT_00139964;
      *(float *)(iVar17 + 0x1c) = fVar25;
      *(float *)(iVar17 + 0x20) = fVar25;
      *(float *)(iVar17 + 0x24) = fVar25;
      *(undefined4 *)(iVar17 + 0x28) = uVar7;
      *(float *)(iVar17 + 0x2c) = fVar25;
      *(float *)(iVar17 + 0x30) = fVar25;
      *(float *)(iVar17 + 0x34) = fVar25;
      *(undefined4 *)(iVar17 + 0x38) = uVar7;
    }
    else {
      func_001151CC((undefined4 *)(iVar17 + 0x18),&local_80);
      bVar3 = *(byte *)(iVar17 + 0xa8) | 4;
    }
    *(byte *)(iVar17 + 0xa8) = bVar3;
  }
  func_0043625C(*(int **)(puVar6[10] + 0x14),puVar6 + -0xf);
  iVar17 = *(int *)(*piVar5 + 0x14);
  fVar21 = ALBW_AS_F32(param_2[4]) - *(float *)(iVar17 + 4);
  bVar4 = fVar27 == fVar21;
  bVar20 = fVar21 <= fVar27;
  if (!bVar20 || bVar4) {
    bVar4 = fVar21 == fVar26;
    bVar20 = fVar26 <= fVar21;
  }
  if (bVar20 && !bVar4) {
LAB_001394e4:
    bVar4 = false;
  }
  else {
    fVar21 = ALBW_AS_F32(param_2[5]) - *(float *)(iVar17 + 8);
    bVar4 = fVar27 == fVar21;
    bVar20 = fVar21 <= fVar27;
    if (!bVar20 || bVar4) {
      bVar4 = fVar21 == fVar26;
      bVar20 = fVar26 <= fVar21;
    }
    if (bVar20 && !bVar4) goto LAB_001394e4;
    fVar21 = ALBW_AS_F32(param_2[6]) - *(float *)(iVar17 + 0xc);
    bVar4 = fVar27 == fVar21;
    bVar20 = fVar21 <= fVar27;
    if (!bVar20 || bVar4) {
      bVar4 = fVar21 == fVar26;
      bVar20 = fVar26 <= fVar21;
    }
    if (bVar20 && !bVar4) goto LAB_001394e4;
    bVar4 = true;
  }
  if (!bVar4) {
    *(byte *)(iVar17 + 0xa8) = *(byte *)(iVar17 + 0xa8) | 8;
    pfVar1 = DAT_001395b8;
    fVar21 = ALBW_AS_F32(param_2[4]) - *DAT_001395b8;
    bVar4 = fVar27 == fVar21;
    bVar20 = fVar21 <= fVar27;
    if (!bVar20 || bVar4) {
      bVar4 = fVar21 == fVar26;
      bVar20 = fVar26 <= fVar21;
    }
    if (bVar20 && !bVar4) {
LAB_001395fc:
      *(uint *)(iVar17 + 4) = param_2[4];
      *(uint *)(iVar17 + 8) = param_2[5];
      *(uint *)(iVar17 + 0xc) = param_2[6];
      bVar3 = *(byte *)(iVar17 + 0xa8) | 2;
    }
    else {
      fVar21 = ALBW_AS_F32(param_2[5]) - DAT_001395b8[1];
      bVar4 = fVar27 == fVar21;
      bVar20 = fVar21 <= fVar27;
      if (!bVar20 || bVar4) {
        bVar4 = fVar21 == fVar26;
        bVar20 = fVar26 <= fVar21;
      }
      if (bVar20 && !bVar4) goto LAB_001395fc;
      fVar21 = ALBW_AS_F32(param_2[6]) - DAT_001395b8[2];
      bVar4 = fVar27 == fVar21;
      bVar20 = fVar21 <= fVar27;
      if (!bVar20 || bVar4) {
        bVar4 = fVar21 == fVar26;
        bVar20 = fVar26 <= fVar21;
      }
      if (bVar20 && !bVar4) goto LAB_001395fc;
      *(float *)(iVar17 + 4) = *DAT_001395b8;
      *(float *)(iVar17 + 8) = pfVar1[1];
      *(float *)(iVar17 + 0xc) = pfVar1[2];
      bVar3 = *(byte *)(iVar17 + 0xa8) & 0xfd;
    }
    *(byte *)(iVar17 + 0xa8) = bVar3;
  }
  objStack_94[0] = puVar6[-0x50];
  func_004EDAD0(puVar6[10],objStack_94);
  *(undefined2 *)(*piVar5 + 0x2c) = *(undefined2 *)(puVar6 + -0xee);
  func_004ED9C8(*piVar5);
  func_004A879C(*DAT_00139968,*piVar5,2);
LAB_00139658:
  puVar6[5] = puVar16;
  *(undefined1 *)((int)puVar6 + 6) = 3;
  iVar17 = func_0010BA78(0x30);
  puVar6[6] = iVar17;
  puVar6[7] = iVar17 + (uint)*(byte *)((int)puVar6 + 6) * 8;
  iVar13 = 3;
  puVar9 = (undefined4 *)(iVar17 + -8);
  do {
    uVar7 = puVar8[0x11];
    iVar13 = iVar13 + -1;
    puVar9[2] = puVar8[0x10];
    puVar9[3] = uVar7;
    uVar7 = puVar8[0x11];
    puVar9[4] = puVar8[0x10];
    puVar9[5] = uVar7;
    puVar9 = puVar9 + 4;
  } while (iVar13 != 0);
  bVar3 = *(byte *)((int)puVar6 + 6);
  uVar12 = (uint)bVar3;
  puVar9 = (undefined4 *)func_0010BA78(uVar12 << 3);
  puVar6[8] = puVar9;
  if (uVar12 != 0) {
    puVar11 = puVar9 + -2;
    if ((bVar3 & 1) != 0) {
      uVar7 = puVar8[7];
      *puVar9 = puVar8[6];
      puVar9[1] = uVar7;
      puVar11 = puVar9;
    }
    for (iVar17 = (int)uVar12 >> 1; iVar17 != 0; iVar17 = iVar17 + -1) {
      uVar7 = puVar8[7];
      puVar11[2] = puVar8[6];
      puVar11[3] = uVar7;
      uVar7 = puVar8[7];
      puVar11[4] = puVar8[6];
      puVar11[5] = uVar7;
      puVar11 = puVar11 + 4;
    }
  }
  puVar9 = (undefined4 *)func_0010CEE0(0x74,(int *)0x0,4);
  iVar17 = 0;
  if (puVar9 != (undefined4 *)0x0) {
    *puVar9 = 0x24;
    puVar9[1] = 3;
    iVar17 = func_00100118((int)(puVar9 + 2),DAT_0013996c,0x24,3);
  }
  if (iVar17 != 0) {
    puVar6[2] = 3;
    puVar6[3] = iVar17;
  }
  iVar17 = DAT_00139970;
  puVar6[-0x2e] = puVar6;
  *(undefined2 *)(iVar17 + (int)puVar16) = 3;
  local_84 = (uint *)s_cState_Wait_00139974;
  iVar17 = puVar6[3];
  objStack_94[0] = *(uint *)(iVar17 + 4);
  objStack_90[0] = (uint)puVar6;
  local_88 = iVar18;
  (**(code **)(iVar10 + 0x10))(&local_88);
  auVar2[0] = objStack_94[0];
  uVar12 = 0;
  do {
    if (*(char *)((int)local_84 + uVar12) == '\0') {
      if ((int)uVar12 < 0x40001) goto LAB_001397e4;
      break;
    }
    uVar12 = uVar12 + 1;
  } while ((int)uVar12 < 0x40001);
  uVar12 = 0;
LAB_001397e4:
  iVar17 = *(int *)(iVar17 + 8);
  if (iVar17 <= (int)uVar12) {
    uVar12 = iVar17 - 1;
  }
  (**(code **)(local_88 + 8))(&local_88);
  func_0010E3C4((uint *)auVar2[0],local_84,uVar12);
  *(undefined1 *)(objStack_94[0] + uVar12) = 0;
  puVar9 = (undefined4 *)puVar6[6];
  uVar7 = DAT_00139980[1];
  uVar15 = DAT_00139980[2];
  uVar22 = DAT_00139980[3];
  uVar23 = DAT_00139980[4];
  uVar24 = DAT_00139980[5];
  *puVar9 = *DAT_00139980;
  puVar9[1] = uVar7;
  puVar9 = (undefined4 *)puVar6[7];
  *puVar9 = uVar15;
  puVar9[1] = uVar22;
  puVar9 = (undefined4 *)puVar6[8];
  *puVar9 = uVar23;
  puVar9[1] = uVar24;
  local_84 = (uint *)s_cState_Melt_00139984;
  if ((uint)puVar6[2] < 2) {
    iVar17 = puVar6[3];
  }
  else {
    iVar17 = puVar6[3] + 0x24;
  }
  puVar19 = *(uint **)(iVar17 + 4);
  local_88 = iVar18;
  (**(code **)(iVar10 + 0x10))(&local_88);
  uVar12 = 0;
  do {
    if (*(char *)((int)local_84 + uVar12) == '\0') {
      if ((int)uVar12 < 0x40001) goto LAB_001398a4;
      break;
    }
    uVar12 = uVar12 + 1;
  } while ((int)uVar12 < 0x40001);
  uVar12 = 0;
LAB_001398a4:
  if (*(int *)(iVar17 + 8) <= (int)uVar12) {
    uVar12 = *(int *)(iVar17 + 8) - 1;
  }
  (**(code **)(local_88 + 8))(&local_88);
  func_0010E3C4(puVar19,local_84,uVar12);
  *(undefined1 *)((int)puVar19 + uVar12) = 0;
  puVar9 = DAT_00139584;
  iVar17 = puVar6[6];
  uVar7 = DAT_00139584[6];
  uVar15 = DAT_00139584[7];
  uVar22 = DAT_00139584[9];
  uVar23 = DAT_00139584[10];
  uVar24 = DAT_00139584[0xb];
  *(undefined4 *)(iVar17 + 8) = DAT_00139584[8];
  *(undefined4 *)(iVar17 + 0xc) = uVar22;
  iVar17 = puVar6[7];
  *(undefined4 *)(iVar17 + 8) = uVar23;
  *(undefined4 *)(iVar17 + 0xc) = uVar24;
  iVar17 = puVar6[8];
  *(undefined4 *)(iVar17 + 8) = uVar7;
  *(undefined4 *)(iVar17 + 0xc) = uVar15;
  local_84 = (uint *)s_cState_Erase_00139990;
  uVar12 = puVar6[2];
  if (uVar12 < 3) {
    iVar17 = puVar6[3];
    uVar14 = uVar12;
  }
  else {
    iVar17 = iVar18;
    uVar14 = puVar6[3];
  }
  if (2 < uVar12) {
    iVar17 = uVar14 + 0x48;
  }
  puVar19 = *(uint **)(iVar17 + 4);
  local_88 = iVar18;
  (**(code **)(iVar10 + 0x10))(&local_88);
  uVar12 = 0;
  do {
    if (*(char *)((int)local_84 + uVar12) == '\0') {
      if ((int)uVar12 < 0x40001) goto LAB_001399ac;
      break;
    }
    uVar12 = uVar12 + 1;
  } while ((int)uVar12 < 0x40001);
  uVar12 = 0;
LAB_001399ac:
  if (*(int *)(iVar17 + 8) <= (int)uVar12) {
    uVar12 = *(int *)(iVar17 + 8) - 1;
  }
  (**(code **)(local_88 + 8))(&local_88);
  func_0010E3C4(puVar19,local_84,uVar12);
  *(undefined1 *)((int)puVar19 + uVar12) = 0;
  iVar10 = puVar6[6];
  uVar7 = puVar9[0xf];
  uVar15 = puVar9[0xe];
  uVar22 = puVar9[6];
  uVar24 = puVar9[0xd];
  uVar23 = puVar9[7];
  *(undefined4 *)(iVar10 + 0x10) = puVar9[0xc];
  *(undefined4 *)(iVar10 + 0x14) = uVar24;
  iVar10 = puVar6[7];
  *(undefined4 *)(iVar10 + 0x10) = uVar15;
  *(undefined4 *)(iVar10 + 0x14) = uVar7;
  iVar10 = puVar6[8];
  *(undefined4 *)(iVar10 + 0x10) = uVar22;
  *(undefined4 *)(iVar10 + 0x14) = uVar23;
  if ((*(short *)((int)param_2 + 0x32) == 0) || (bVar4 = func_00588BF0((int)puVar16,0), !bVar4)) {
    func_006571B4((undefined4 *)objStack_90[0],0);
  }
  else {
    func_006571B4((undefined4 *)objStack_90[0],2);
  }
  auVar2[0] = objStack_98[0];
  if (puVar6[0xb] != 0) {
    objStack_94[0] = (uint)ALBW_AS_U32(*(float *)(puVar6[0xb] + 0x5c) * DAT_00139b1c);
    iVar10 = *(int *)objStack_98[0];
    objStack_98[0] = (uint)ALBW_AS_U32(fVar25);
    objStack_90[0] = (uint)ALBW_AS_U32(fVar25);
    func_00115C54(&local_80,(float *)(puVar6 + -0xf),(float *)objStack_98);
    *(float *)(iVar10 + 4) = local_80;
    *(float **)(iVar10 + 8) = local_7c;
    *(float *)(iVar10 + 0xc) = local_78;
    func_004356B4(*(int **)auVar2[0]);
  }
  if (puVar6[10] != 0) {
    func_0043625C(*(int **)(puVar6[10] + 0x14),puVar6 + -0xf);
    func_004ED9C8(*piVar5);
  }
  iVar10 = puVar6[9];
  if (iVar10 != 0) {
    *(uint *)(iVar10 + 0x164) = *(uint *)(iVar10 + 0x164) | 0x40000000;
    *(undefined4 *)(iVar10 + 0x74) = puVar6[0x11];
    *(undefined4 *)(iVar10 + 0x78) = puVar6[0x12];
    *(undefined4 *)(iVar10 + 0x7c) = puVar6[0x13];
  }
  return puVar16;
}

