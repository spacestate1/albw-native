/* compilefix: USA 002B705C, the converted stage-2 text with the speed factor used (the text dropped the result)
 * (BOOT_LOG 179). */
#include "ghidra_types.h"

extern int func_00100174(int *param_1);
extern int func_00115C54(float *param_1,float *param_2,float *param_3);
extern int func_00115DAC(float *param_1,float *param_2,float *param_3,float fparam_0);
extern float func_00115DC8(float *param_1);
extern int func_0016898C(int param_1,uint *param_2);
extern int func_002B5638(int param_1,uint *param_2);
extern float func_002B6294(int param_1);
extern int func_002B66B0(int param_1);
extern int func_002B7AD0(int param_1);
extern float func_002BA9A0(int param_1,float fparam_0);
extern int func_003838A8(int param_1,int param_2);
extern int func_003840A0(int param_1,int param_2);
extern int func_004D80A4(float *param_1,uint param_2,float fparam_0);
extern int func_004D80EC(float *param_1,float *param_2,int param_3);
extern int func_0051D2CC(int *param_1,int param_2,float fparam_0);
extern int func_0051D2F4(int *param_1,int param_2,int param_3,int param_4,float fparam_0);
extern int func_0052FBA0(int param_1,uint param_2);
extern float DAT_002b7454;
extern float DAT_002b7458;
extern float DAT_002b745c;
extern int DAT_002b7460;
extern float DAT_002b7464;
extern float DAT_002b7468;
extern float DAT_002b746c;
extern float DAT_002b7470;
extern float DAT_002b7474;
extern int *DAT_002b7478;
extern uint *DAT_002b747c;
extern undefined4 *DAT_002b7480;
extern undefined4 DAT_002b7484;
extern undefined4 DAT_002b7488;
extern float DAT_002b74dc;
extern float DAT_002b74e0;

// USA 002B705C <- EU 002B7038 (Ghidra, non-matching)
// GLOBAL DAT_002b7454 float
// GLOBAL DAT_002b7458 float
// GLOBAL DAT_002b745c float
// GLOBAL DAT_002b7460 int
// GLOBAL DAT_002b7464 float
// GLOBAL DAT_002b7468 float
// GLOBAL DAT_002b746c float
// GLOBAL DAT_002b7470 float
// GLOBAL DAT_002b7474 float
// GLOBAL DAT_002b7478 int *
// GLOBAL DAT_002b747c uint *
// GLOBAL DAT_002b7480 undefined4 *
// GLOBAL DAT_002b7484 undefined4
// GLOBAL DAT_002b7488 undefined4
// GLOBAL DAT_002b74dc float
// GLOBAL DAT_002b74e0 float

undefined4 func_002B705C(int param_1)

{
  int iVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  float *pfVar5;
  uint uVar6;
  int *piVar7;
  uint in_r12;
  float fVar8;
  float fVar9;
  float fparam_0;
  float fparam_0_00;
  float fVar10;
  float fVar11;
  float fVar12;
  _Alignas(8) unsigned char albw_frame[0xd0];
  #define local_d0 ((uint *)(albw_frame + 0x0))
  #define pfStack_c8 (*(float * *)(albw_frame + 0x8))
  #define local_c4 (*(float *)(albw_frame + 0xc))
  #define local_c0 (*(float *)(albw_frame + 0x10))
  #define fStack_bc (*(float *)(albw_frame + 0x14))
  #define uStack_b8 (*(undefined4 *)(albw_frame + 0x18))
  #define fStack_b4 (*(float *)(albw_frame + 0x1c))
  #define local_b0 (*(uint *)(albw_frame + 0x20))
  #define local_7c (*(undefined4 *)(albw_frame + 0x54))
  #define local_78 (*(undefined1 *)(albw_frame + 0x58))
  #define local_5c ((uint *)(albw_frame + 0x74))
  func_002B7AD0(param_1);
  func_002B66B0(param_1);
  local_5c[0] = func_004D80EC((float *)(param_1 + 0x3d0),(float *)(param_1 + 0xa08),
                              *(int *)(param_1 + 1000));
  func_002B5638(param_1,local_5c);
  pfVar5 = (float *)(param_1 + 0xa2c);
  fVar11 = DAT_002b7454;
  fparam_0_00 = DAT_002b7454;
  func_004D80A4(&local_c4,local_5c[0],DAT_002b7458);
  local_c0 = fVar11;
  func_00115C54(pfVar5,pfVar5,&local_c4);
  fVar8 = SQRT(*pfVar5 * *pfVar5 + *(float *)(param_1 + 0xa30) * *(float *)(param_1 + 0xa30) +
               *(float *)(param_1 + 0xa34) * *(float *)(param_1 + 0xa34));
  fparam_0 = DAT_002b745c;
  if (0x3f800000 < (int)ALBW_AS_U32(fVar8)) {
    fVar8 = DAT_002b745c;
    func_00115DC8(pfVar5);
    fparam_0 = fVar8;
  }
  fVar12 = DAT_002b7468;
  iVar4 = DAT_002b7460;
  cVar2 = *(char *)(param_1 + 0x936);
  uVar6 = *(uint *)(param_1 + 0xa1c);
  fVar10 = fparam_0;
  if (cVar2 == '\0') {
    *(float *)(*(int *)(*(int *)(param_1 + 0x8dc) + 0x14) + 0x10) = fparam_0;
    *(float *)(*(int *)(*(int *)(param_1 + 0x8e0) + 0x14) + 0x10) = fparam_0;
  }
  else {
    iVar1 = DAT_002b7460 >> 2;
    piVar7 = (int *)(param_1 + 0xa1c);
    if (cVar2 == '\x02') {
      fparam_0_00 = fVar8 * DAT_002b7474;
      fparam_0 = DAT_002b7468;
      fVar12 = DAT_002b7464;
      fVar9 = func_002B6294(param_1);
      fVar8 = fVar9 * fVar8;
      if (*(char *)(param_1 + 0xb3f) != '\0') {
        fVar8 = fVar10;
      }
      *(float *)(*(int *)(*(int *)(param_1 + 0x8e0) + 0x14) + 0x10) = fVar8;
      func_0051D2F4((int *)(param_1 + 1000),*(int *)(param_1 + 0xa20),iVar1,iVar4,fVar12);
      func_0051D2CC(piVar7,local_5c[0],fparam_0);
      uVar6 = *(uint *)(param_1 + 0xa1c);
    }
    else if (cVar2 == '\x03') {
      fVar9 = DAT_002b7464;
      fparam_0_00 = func_002BA9A0(param_1,fVar8);
      fVar10 = fparam_0;
      fparam_0 = fVar12;
      func_0051D2F4((int *)(param_1 + 1000),*(int *)(param_1 + 0xa20),iVar1,iVar4,fVar9);
      func_0051D2CC(piVar7,local_5c[0],fparam_0);
      uVar6 = *(uint *)(param_1 + 0xa1c);
    }
    else {
      fparam_0_00 = fVar8 * DAT_002b746c;
      fVar8 = fparam_0_00 * DAT_002b7470;
      if (*(char *)(param_1 + 0xb3f) != '\0') {
        fVar8 = fparam_0;
      }
      *(float *)(*(int *)(*(int *)(param_1 + 0x8dc) + 0x14) + 0x10) = fVar8;
      *(float *)(*(int *)(*(int *)(param_1 + 0x8e0) + 0x14) + 0x10) = fVar8;
      fparam_0 = fVar12;
      func_0051D2CC((int *)(param_1 + 1000),local_5c[0],fVar12);
      func_0051D2CC(piVar7,local_5c[0],fparam_0);
      uVar6 = *(uint *)(param_1 + 1000);
    }
  }
  if (*(char *)(param_1 + 0xb3f) != '\0') {
    *pfVar5 = fVar11;
    *(float *)(param_1 + 0xa30) = fVar11;
    *(float *)(param_1 + 0xa34) = fVar11;
    fparam_0_00 = fVar11;
  }
  bVar3 = func_003840A0(param_1 + 0x8c0,0x59);
  if ((bVar3) || (bVar3 = func_003840A0(param_1 + 0x8c0,0x58), bVar3)) {
    piVar7 = (int *)func_0052FBA0(*DAT_002b7478 + 0x3dbbc,
                                  *(uint *)(*(int *)(param_1 + 0x93c) + 0x5cc));
    if (((*DAT_002b747c & 1) == 0) && (iVar4 = func_00100174((int *)DAT_002b747c), iVar4 != 0)) {
      *DAT_002b7480 = DAT_002b7484;
    }
    if ((piVar7 == (int *)0x0) || (iVar4 = (**(code **)*piVar7)(piVar7,DAT_002b7480), iVar4 == 0)) {
      piVar7 = (int *)0x0;
    }
    if (piVar7 != (int *)0x0) {
      fparam_0 = ((float (*)(int *))*(code **)(*piVar7 + 0x60))(piVar7);   /* speed factor */
      fparam_0_00 = fparam_0 * fparam_0_00;
    }
    iVar4 = func_003838A8(param_1 + 0x8c0,7);
    if (**(int **)(*(int *)(param_1 + 0x8e0) + 0x14) != iVar4) {
      fVar8 = ALBW_AS_F32(func_003838A8(param_1 + 0x8c0,7));
      iVar4 = func_003838A8(param_1 + 0x8c0,(int)ALBW_AS_U32(fVar8));
      if (**(int **)(*(int *)(param_1 + 0x8e0) + 0x14) != iVar4) {
        pfStack_c8 = &local_c4;
        local_d0[1] = 3;
        local_d0[0] = 1;
        local_7c = 10;
        local_78 = 0;
        local_b0 = in_r12 | 0xff;
        uStack_b8 = DAT_002b7488;
        local_c4 = fVar8;
        local_c0 = fVar11;
        fStack_bc = fVar10;
        fStack_b4 = fVar10;
        func_0016898C(*(int *)(param_1 + 0x8e0),local_d0);
      }
    }
  }
  if ((*(char *)(param_1 + 0xb34) != '\0') && (*(short *)(param_1 + 0xaf0) == 0)) {
    pfVar5 = (float *)(param_1 + 0x988);
    func_004D80A4(pfVar5,uVar6,fparam_0_00);
    *(float *)(param_1 + 0x98c) = fVar11;
    if (*(char *)(param_1 + 0x392) == '\t') {
      return func_00115DAC((float *)(param_1 + 0x3dc),pfVar5,(float *)(param_1 + 0x3dc),DAT_002b74e0);
    }
    func_00115DAC((float *)(param_1 + 0x3dc),pfVar5,(float *)(param_1 + 0x3dc),
                  *(float *)(param_1 + 0xa58) +
                  (fVar10 - *(float *)(param_1 + 0xa58)) * DAT_002b74dc);
  }
  return 0;
}

