/* compilefix: func_00256088, the converted stage-2 text (build/decomp/ghidra_fallback/ghidra_analyzed5_v4/002/func_00256088.c) with raw code-address string pointers
 * replaced by the strings themselves (tools/raw_cstr_fix.py, BOOT_LOG 143): 0x2567c0 "SE_PL_RS_HIT_TORNADO" */
#include "ghidra_types.h"

extern int func_00100174(int *param_1);
extern int func_00150A84(int *param_1,int *param_2,int param_3);
extern int func_0023A988(int param_1);
extern int func_0023BCAC(int param_1,int param_2,int param_3);
extern int func_002567B0(void);
extern int func_0028C920(int param_1,int param_2,undefined4 *param_3,float fparam_0,float fparam_1);
extern int func_002D55D0(int param_1,uint param_2);
extern int func_002FD11C(int *param_1,int param_2);
extern int func_00324610(int *param_1,int *param_2,float fparam_0,float fparam_1);
extern int func_0053EDD8(int param_1);
extern int func_005841A8(int param_1,undefined4 param_2,int *param_3);
extern float DAT_00256448;
extern float DAT_0025644c;
extern undefined4 *DAT_00256450;
extern float DAT_00256454;
extern int *DAT_00256458;
extern undefined4 *DAT_0025645c;
extern float DAT_00256460;
extern float DAT_00256464;
extern undefined4 DAT_00256468;
extern undefined4 *DAT_0025646c;
extern undefined4 *DAT_00256470;
extern int DAT_00256474;
extern uint *DAT_00256478;
extern undefined4 *DAT_0025647c;
extern uint *DAT_00256480;
extern int DAT_00256484;
extern int DAT_00256488;
extern undefined4 *DAT_0025648c;
extern undefined DAT_002567ac;
extern char s_SE_PL_RS_HIT_FIRE_00256798[];
extern char s_SE_PL_RS_HIT_WOOD_00256770[];

// GLOBAL DAT_00256448 float
// GLOBAL DAT_0025644c float
// GLOBAL DAT_00256450 undefined4 *
// GLOBAL DAT_00256454 float
// GLOBAL DAT_00256458 int *
// GLOBAL DAT_0025645c undefined4 *
// GLOBAL DAT_00256460 float
// GLOBAL DAT_00256464 float
// GLOBAL DAT_00256468 undefined4
// GLOBAL DAT_0025646c undefined4 *
// GLOBAL DAT_00256470 undefined4 *
// GLOBAL DAT_00256474 int
// GLOBAL DAT_00256478 uint *
// GLOBAL DAT_0025647c undefined4 *
// GLOBAL DAT_00256480 uint *
// GLOBAL DAT_00256484 int
// GLOBAL DAT_00256488 int
// GLOBAL DAT_0025648c undefined4 *
// GLOBAL DAT_002567ac undefined
// GLOBAL func_002567B0 undefined
// GLOBAL s_SE_PL_RS_HIT_FIRE_00256798 string
// GLOBAL s_SE_PL_RS_HIT_WOOD_00256770 string
// USA 00256088 <- EU 0025605C (Ghidra, function missing from the decomp table)

undefined4 func_00256088(int param_1,undefined4 param_2)

{
  bool bVar1;
  char cVar2;
  byte bVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int *piVar6;
  uint *puVar7;
  undefined4 *puVar8;
  int iVar9;
  float *pfVar10;
  int iVar11;
  undefined4 *puVar12;
  uint in_fpscr;
  uint uVar13;
  float fVar14;
  float fVar15;
  float fparam_0;
  float fVar16;
  float fparam_1;
  float fparam_1_00;
  _Alignas(8) unsigned char albw_frame[0x60];
  #define local_58 (*(int *)(albw_frame + 0x8))
  #define local_54 (*(code * *)(albw_frame + 0xc))
  #define local_50 ((int *)(albw_frame + 0x10))
  #define local_40 (*(int *)(albw_frame + 0x20))
  uVar5 = DAT_00256468;
  fparam_0 = DAT_00256464;
  fparam_1_00 = DAT_00256460;
  puVar4 = DAT_0025645c;
  piVar6 = DAT_00256458;
  fparam_1 = DAT_00256454;
  puVar8 = DAT_00256450;
  fVar16 = DAT_0025644c;
  fVar14 = DAT_00256448;
  switch(param_2) {
  case 0xad:
    piVar6 = *(int **)(*(int *)(param_1 + 0x2c) + 0x70);
    if ((piVar6 != (int *)0x0) && (iVar11 = func_002FD11C(piVar6,1), iVar11 != 0)) {
LAB_00256620:
      return func_002D55D0(param_1,0xae);
    }
    break;
  case 0xae:
    *(float *)(*(int *)(param_1 + 0x4c) + 0x100) = DAT_00256448;
    **(int **)(param_1 + 0x3c) = *(int *)(param_1 + 0x70) + -0x40000000;
    iVar11 = *(int *)(param_1 + 0x4c);
    *(undefined4 *)(iVar11 + 0x114) = *(undefined4 *)(param_1 + 0x78);
    *(undefined4 *)(iVar11 + 0x118) = 0;
    func_0028C920(*(int *)(param_1 + 0x4c),1,DAT_0025646c,fparam_0,fparam_1_00);
    fVar15 = *(float *)(*(int *)(*(int *)(param_1 + 0x48) + 0x14) + 0x11c);
    uVar13 = in_fpscr & 0xfffffff | (uint)(fVar14 <= fVar15) << 0x1d;
    bVar1 = SUB41(uVar13 >> 0x1d,0);
    if (!bVar1) {
      fVar15 = fVar15 * fparam_1_00;
    }
    fVar14 = (float)VectorSignedToFloat(*puVar8,(byte)(uVar13 >> 0x15) & 3);
    if (bVar1) {
      fVar15 = fVar15 * fVar16;
    }
    local_54 = (code *)(int)(fVar14 * fVar15);
    func_00324610((int *)(param_1 + 0x78),(int *)&local_54,fparam_0,fparam_1);
    *(undefined1 *)(*(int *)(param_1 + 0x2c) + 0x20) = 0x19;
    if ((**(uint **)(*(int *)(param_1 + 0x48) + 0x14) & 1) != 0) {
      puVar8 = (undefined4 *)func_005841A8(*piVar6,*DAT_00256470,*(int **)(DAT_00256474 + *piVar6));
      puVar7 = DAT_00256478;
      if (*(undefined4 **)(*piVar6 + 0x3dbc8) != puVar8) {
        do {
          puVar12 = (undefined4 *)*puVar8;
          if (((*puVar7 & 1) == 0) && (iVar11 = func_00100174((int *)DAT_00256478), iVar11 != 0)) {
            *DAT_0025647c = uVar5;
          }
          if ((puVar12 == (undefined4 *)0x0) ||
             (iVar11 = (**(code **)*puVar12)(puVar12,DAT_0025647c), iVar11 == 0)) {
            puVar12 = (undefined4 *)0x0;
          }
          if (puVar12 != (undefined4 *)0x0) {
            func_0023A988((int)puVar12);
          }
          puVar8 = (undefined4 *)func_005841A8(*piVar6,*puVar4,puVar8 + 1);
        } while (*(undefined4 **)(*piVar6 + 0x3dbc8) != puVar8);
      }
LAB_0025664c:
      return func_002D55D0(param_1,0xaf);
    }
    break;
  case 0xaf:
    **(int **)(param_1 + 0x3c) = *(int *)(param_1 + 0x70) + -0x40000000;
    *(undefined1 *)(*(int *)(param_1 + 0x2c) + 0x20) = 0x19;
    iVar11 = func_0053EDD8(*(int *)(param_1 + 0x4c) + 0x3c);
    puVar7 = *(uint **)(*(int *)(param_1 + 0x48) + 0x14);
    if (iVar11 != 0) {
      if ((puVar7[0x43] & 1) != 0) {
        return func_002D55D0(param_1,0xb1);
      }
      return func_002D55D0(param_1,0xb0);
    }
    if (((*puVar7 & 1) != 0) && (5 < *(uint *)(*(int *)(param_1 + 0x2c) + 0x44))) goto LAB_0025664c;
    iVar11 = *(int *)(param_1 + 0x4c);
    *(undefined4 *)(iVar11 + 0x114) = *(undefined4 *)(param_1 + 0x78);
    *(undefined4 *)(iVar11 + 0x118) = 0;
    func_0028C920(*(int *)(param_1 + 0x4c),1,DAT_0025646c,fparam_0,fparam_1_00);
    fVar15 = *(float *)(*(int *)(*(int *)(param_1 + 0x48) + 0x14) + 0x11c);
    uVar13 = in_fpscr & 0xfffffff | (uint)(fVar14 <= fVar15) << 0x1d;
    bVar1 = SUB41(uVar13 >> 0x1d,0);
    if (!bVar1) {
      fVar15 = fVar15 * fparam_1_00;
    }
    fVar14 = (float)VectorSignedToFloat(*puVar8,(byte)(uVar13 >> 0x15) & 3);
    if (bVar1) {
      fVar15 = fVar15 * fVar16;
    }
    local_54 = (code *)(int)(fVar14 * fVar15);
    func_00324610((int *)(param_1 + 0x78),(int *)&local_54,fparam_0,fparam_1);
    if ((*(int *)(*(int *)(param_1 + 0x2c) + 0x44) == 8) &&
       (puVar8 = (undefined4 *)func_005841A8(*piVar6,*puVar4,*(int **)(DAT_00256474 + *piVar6)),
       iVar11 = DAT_00256484, puVar7 = DAT_00256480, *(undefined4 **)(*piVar6 + 0x3dbc8) != puVar8))
    {
      local_40 = DAT_00256488;
      do {
        puVar12 = (undefined4 *)*puVar8;
        if (((*puVar7 & 1) == 0) && (iVar9 = func_00100174((int *)DAT_00256480), iVar9 != 0)) {
          *DAT_0025648c = uVar5;
        }
        if ((puVar12 == (undefined4 *)0x0) ||
           (iVar9 = (**(code **)*puVar12)(puVar12,DAT_0025648c), iVar9 == 0)) {
          puVar12 = (undefined4 *)0x0;
        }
        if (((puVar12 != (undefined4 *)0x0) &&
            (pfVar10 = *(float **)(param_1 + 0x30),
            (int)ALBW_AS_U32(SQRT((ALBW_AS_F32(puVar12[0xf4]) - *pfVar10) * (ALBW_AS_F32(puVar12[0xf4]) - *pfVar10) +
                      (ALBW_AS_F32(puVar12[0xf5]) - pfVar10[1]) * (ALBW_AS_F32(puVar12[0xf5]) - pfVar10[1]) +
                      (ALBW_AS_F32(puVar12[0xf6]) - pfVar10[2]) * (ALBW_AS_F32(puVar12[0xf6]) - pfVar10[2]))) <
            iVar11)) &&
           (iVar9 = func_0023BCAC((int)puVar12,(int)pfVar10,
                                  *(int *)(*(int *)(param_1 + 0x48) + 0x14) + 0x118), iVar9 != 0)) {
          cVar2 = *(char *)(*(int *)(param_1 + 0x2c) + 0x160);
          if (cVar2 == '\t') {
            local_58 = local_40;
            local_54 = (code *)&DAT_002567ac;
            func_00150A84(*(int **)(param_1 + 0x28),&local_58,0);
          }
          else if (cVar2 < '\n') {
            if (cVar2 == '\a') {
              local_58 = local_40;
              local_54 = func_002567B0;
              func_00150A84(*(int **)(param_1 + 0x28),&local_58,0);
            }
            else if (cVar2 == '\b') {
              local_58 = local_40;
              local_54 = (code *)s_SE_PL_RS_HIT_FIRE_00256798;
              func_00150A84(*(int **)(param_1 + 0x28),&local_58,0);
            }
          }
          else if (cVar2 == '\n') {
            local_58 = local_40;
            local_54 = (code *)"SE_PL_RS_HIT_TORNADO";
            func_00150A84(*(int **)(param_1 + 0x28),&local_58,0);
          }
          else if (cVar2 == '\x17') {
            local_58 = local_40;
            local_54 = (code *)s_SE_PL_RS_HIT_WOOD_00256770;
            func_00150A84(*(int **)(param_1 + 0x28),&local_58,0);
          }
        }
        puVar8 = (undefined4 *)func_005841A8(*piVar6,*puVar4,puVar8 + 1);
      } while (*(undefined4 **)(*piVar6 + 0x3dbc8) != puVar8);
    }
    break;
  case 0xb0:
    **(int **)(param_1 + 0x3c) = *(int *)(param_1 + 0x70) + -0x40000000;
    *(undefined1 *)(*(int *)(param_1 + 0x2c) + 0x20) = 0x19;
    iVar11 = func_0053EDD8(*(int *)(param_1 + 0x4c) + 0x3c);
    if (iVar11 != 0) goto LAB_00256620;
    if ((**(uint **)(*(int *)(param_1 + 0x48) + 0x14) & 1) != 0) goto LAB_0025664c;
    iVar11 = *(int *)(param_1 + 0x4c);
    *(undefined4 *)(iVar11 + 0x114) = *(undefined4 *)(param_1 + 0x78);
    *(undefined4 *)(iVar11 + 0x118) = 0;
    func_0028C920(*(int *)(param_1 + 0x4c),1,DAT_0025646c,fparam_0,fparam_1_00);
    fVar15 = *(float *)(*(int *)(*(int *)(param_1 + 0x48) + 0x14) + 0x11c);
    uVar13 = in_fpscr & 0xfffffff | (uint)(fVar14 <= fVar15) << 0x1d;
    if (!SUB41(uVar13 >> 0x1d,0)) goto LAB_0025674c;
    goto LAB_00256768;
  case 0xb1:
    **(int **)(param_1 + 0x3c) = *(int *)(param_1 + 0x70) + -0x40000000;
    if ((*(uint *)(*(int *)(*(int *)(param_1 + 0x48) + 0x14) + 0x10c) & 1) == 0) {
      return func_002D55D0(param_1,0xb0);
    }
    iVar11 = *(int *)(param_1 + 0x4c);
    *(undefined4 *)(iVar11 + 0x114) = *(undefined4 *)(param_1 + 0x78);
    *(undefined4 *)(iVar11 + 0x118) = 0;
    func_0028C920(*(int *)(param_1 + 0x4c),1,DAT_0025646c,fparam_0,fparam_1_00);
    fVar15 = *(float *)(*(int *)(*(int *)(param_1 + 0x48) + 0x14) + 0x11c);
    uVar13 = in_fpscr & 0xfffffff | (uint)(fVar14 < fVar15) << 0x1f |
             (uint)(fVar14 == fVar15) << 0x1e;
    bVar3 = (byte)(uVar13 >> 0x18);
    if (!(bool)(bVar3 >> 6 & 1) && (bool)(bVar3 >> 7) == (NAN(fVar14) || NAN(fVar15))) {
LAB_0025674c:
      fVar15 = fVar15 * fparam_1_00;
      goto LAB_002566ac;
    }
LAB_00256768:
    fVar15 = fVar15 * fVar16;
LAB_002566ac:
    fVar14 = (float)VectorSignedToFloat(*puVar8,(byte)(uVar13 >> 0x15) & 3);
    local_50[0] = (int)(fVar14 * fVar15);
    return func_00324610((int *)(param_1 + 0x78),local_50,fparam_0,fparam_1);
  }
  return 0;
}

