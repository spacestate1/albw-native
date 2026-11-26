/* compilefix: USA 002E8400, the converted stage-2 text.
 * Fixed (BOOT_LOG 186): the two camera calls pass their vector and value, as the ARM does. */
// MAPFIX-INTEGRATED v1
#include "ghidra_types.h"

extern int func_00115C54(float *param_1,float *param_2,float *param_3);
extern int func_00115C70(float *param_1,float *param_2,float *param_3);
extern int func_001E8500(int param_1,float *param_2,float param_3,float fparam_0);
extern int func_0028F7B8(int param_1,undefined1 param_2);
extern void func_004CE804(int param_1,int param_2,int param_3,int param_4,float fparam_0);
extern int func_004CF478(int param_1,int param_2);
extern int func_004D838C(float *param_1,float *param_2,float fparam_0,float fparam_1,float fparam_2);
extern void func_004ED678(int param_1,float fparam_0);
extern void func_004ED714(int param_1,float *param_2);
extern int func_004F68AC();
extern int func_00520FC0(void);
extern int func_00522DDC(int param_1);
extern int func_0052FBA0(int param_1,uint param_2);
extern int func_0052FD14(int param_1,undefined4 *param_2);
extern int func_00556AF8();
extern int func_00556E64(int param_1);
extern int func_0068A560(float *param_1,float *param_2,float *param_3,float fparam_0);
extern int func_0068C690(float *param_1);
extern undefined4 uRam002e870c;
extern float DAT_002e86e8;
extern int *DAT_002e86ec;
extern int *DAT_002e86f0;
extern int *DAT_002e86f4;
extern float DAT_002e86f8;
extern undefined4 DAT_002e86fc;
extern undefined4 DAT_002e8700;
extern int *DAT_002e8704;
extern float DAT_002e8708;
extern float DAT_002e8710;
extern float DAT_002e8714;
extern int DAT_002e8844;
extern float *DAT_002e8848;

// USA 002E8400 <- EU 002E83DC (Ghidra, non-matching)
// GLOBAL DAT_002e86e8 float
// GLOBAL DAT_002e86ec int *
// GLOBAL DAT_002e86f0 int *
// GLOBAL DAT_002e86f4 int *
// GLOBAL DAT_002e86f8 float
// GLOBAL DAT_002e86fc undefined4
// GLOBAL DAT_002e8700 undefined4
// GLOBAL DAT_002e8704 int *
// GLOBAL DAT_002e8708 float
// GLOBAL DAT_002e8710 float
// GLOBAL DAT_002e8714 float
// GLOBAL DAT_002e8844 int
// GLOBAL DAT_002e8848 float *
// GLOBAL UNK_002e870c undefined4

undefined4 func_002E8400(int param_1,int param_2,float *param_3,float *param_4)

{
  char cVar1;
  undefined4 uVar2;
  bool bVar3;
  uint uVar4;
  int iVar5;
  float *pfVar6;
  int iVar7;
  int *piVar8;
  undefined1 extraout_r1;
  undefined1 uVar9;
  int iVar10;
  float *pfVar11;
  float in_s0;
  float fparam_0;
  float fVar12;
  float fVar13;
  float fVar14;
  undefined8 uVar15;
  _Alignas(8) unsigned char albw_frame[0x60];
  #define local_60 (*(float *)(albw_frame + 0x0))
  #define fStack_5c (*(float *)(albw_frame + 0x4))
  #define local_58 (*(float *)(albw_frame + 0x8))
  #define local_54 (*(float *)(albw_frame + 0xc))
  #define uStack_50 (*(undefined4 *)(albw_frame + 0x10))
  #define uStack_4c (*(undefined4 *)(albw_frame + 0x14))
  #define local_48 ((float *)(albw_frame + 0x18))
  fVar13 = DAT_002e86e8;
  if (*(int *)(param_1 + 0xdc4) != 0) {
    uVar4 = func_00522DDC(*DAT_002e86ec);
    param_4 = (float *)0x0;
    if (*(int *)(param_1 + 0xb78) == -1) {
      *(uint *)(param_1 + 0xb78) = uVar4;
    }
    param_3 = (float *)0x0;
    func_004CE804(*(int *)(param_1 + 0xdc4),uVar4 & 0xffff,0,0,in_s0);
    if ((param_2 == 0) && (*(char *)(param_1 + 0xe0e) != '\0')) {
      if (*(uint *)(param_1 + 0xb78) == uVar4) {
        bVar3 = *(uint *)(param_1 + 0xb70) <= *(uint *)(param_1 + 0xb6c);
        param_3 = (float *)0x0;
        uVar4 = *(uint *)(*(int *)(param_1 + 0xdc4) + 0x164);
        if (bVar3) {
          uVar4 = uVar4 | 1;
        }
        else {
          uVar4 = uVar4 & 0xfffffffe;
        }
        *(uint *)(*(int *)(param_1 + 0xdc4) + 0x164) = uVar4;
        func_004CF478(*(int *)(param_1 + 0xdc4),(uint)!bVar3);
        uVar2 = uRam002e870c;
        *(undefined4 *)(param_1 + 0xb70) = 300;
        *(undefined4 *)(param_1 + 0xb74) = uVar2;
        *(undefined4 *)(param_1 + 0xb6c) = 0;
      }
      else if (*(uint *)(param_1 + 0xb6c) < *(uint *)(param_1 + 0xb70)) {
        *(uint *)(param_1 + 0xb6c) = *(uint *)(param_1 + 0xb6c) + 1;
      }
      else {
        iVar5 = *(int *)(param_1 + 0xdc4);
        if (iVar5 != 0) {
          param_3 = (float *)0x0;
          *(uint *)(iVar5 + 0x164) = *(uint *)(iVar5 + 0x164) | 1;
          func_004CF478(*(int *)(param_1 + 0xdc4),0);
        }
      }
    }
  }
  piVar8 = DAT_002e8704;
  iVar5 = *DAT_002e86f0;
  iVar10 = *DAT_002e86f4;
  if (iVar5 != 0) {
    uVar15 = CONCAT44(DAT_002e8700,DAT_002e86fc);
    pfVar11 = (float *)(param_1 + 0xbfc);
    if (*(char *)(param_1 + 0xe0c) == '\0') {
      if (0 < *(short *)(DAT_002e8844 + param_1)) {
        fVar14 = DAT_002e86f8;
        fVar12 = DAT_002e8708;
        func_004ED678(iVar5,*(float *)(param_1 + 0xc08));   /* vldr s0, [param_1 + 0xC00, #8] */
        iVar5 = *(int *)(iVar5 + 0x18);
        if (iVar5 != 0) {
          pfVar6 = (float *)func_00520FC0();
          local_60 = *pfVar6;
          fStack_5c = pfVar6[1];
          local_58 = pfVar6[2];
          cVar1 = *(char *)(param_1 + 0x8cc);
          fparam_0 = fVar12;
          if (cVar1 != ' ') {
            fparam_0 = *(float *)(param_1 + 0xb90);
            if (*(char *)(param_1 + 0xd45) == '\x01') {
              fparam_0 = fVar13;
            }
            if (((cVar1 == '\f') || ((cVar1 == '!' && (*(char *)(param_1 + 0x8cd) == '\f')))) &&
               (fparam_0 = fVar12,
               iVar10 = func_0052FBA0(*piVar8 + 0x3dbbc,*(uint *)(param_1 + 0xc90)), iVar10 != 0)) {
              local_58 = *(float *)(iVar10 + 0x3d8);
              local_60 = *(float *)(iVar10 + 0x3d0);
              fStack_5c = *(float *)(iVar10 + 0x3d4);
            }
          }
          func_0068A560(local_48,&local_60,(float *)(param_1 + 0x3d0),fparam_0);
          func_004D838C(pfVar11,local_48,ALBW_AS_F32(uVar15),fVar12,fVar14);
          fVar13 = ALBW_AS_F32(((ulonglong)uVar15 >> 0x20));
          param_4 = &local_54;
          local_54 = *(float *)(param_1 + 0xbfc);
          uStack_50 = *(undefined4 *)(param_1 + 0xc00);
          uStack_4c = *(undefined4 *)(param_1 + 0xc04);
          func_00115C54(&local_54,&local_54,DAT_002e8848);
          param_3 = (float *)0x64;
          func_001E8500(iVar5,&local_54,100,fVar13);
        }
      }
    }
    else {
      fVar14 = DAT_002e86f8;
      fVar12 = DAT_002e8708;
      func_004ED714(iVar5,(float *)(param_1 + 0xddc));   /* r1 = param_1 + 0xDDC */
      if ((iVar10 == 0) || (bVar3 = func_00556E64(iVar10), !bVar3)) {
        iVar7 = *(int *)(iVar5 + 0x18);
        pfVar6 = (float *)func_00520FC0();
        local_60 = *pfVar6;
        fStack_5c = pfVar6[1];
        local_58 = pfVar6[2];
        local_48[0] = DAT_002e8710;
        iVar5 = func_0052FD14(*piVar8 + 0x3dbbc,local_48);
        if (iVar5 != 0) {
          fVar13 = DAT_002e8714;
        }
        func_0068A560(&local_54,&local_60,(float *)(param_1 + 0xddc),fVar13);
        func_004D838C(pfVar11,&local_54,ALBW_AS_F32(uVar15),fVar12,fVar14);
        if (iVar7 != 0) {
          func_001E8500(iVar7,pfVar11,10,ALBW_AS_F32(((ulonglong)uVar15 >> 0x20)));
        }
      }
      func_00115C70(&local_60,(float *)(param_1 + 0xddc),(float *)(param_1 + 0xe30));
      iVar5 = func_0068C690(&local_60);
      pfVar11 = (float *)func_00520FC0();
      param_3 = (float *)(param_1 + 0xe30);
      func_00115C70(&local_60,pfVar11,param_3);
      iVar7 = func_0068C690(&local_60);
      uVar9 = extraout_r1;
      if (iVar7 != iVar5 && -1 < iVar7 - iVar5) {
        uVar9 = 2;
      }
      if (iVar7 - iVar5 < 1) {
        uVar9 = 1;
      }
      iVar5 = 0;
      if (iVar10 != 0) {
        func_0028F7B8(iVar10,uVar9);
        iVar5 = func_00556AF8(iVar10);
        if (iVar5 != 0) {
          *(undefined4 *)(param_1 + 0xb58) = 0;
          *(float *)(param_1 + 0xb5c) = fVar12;
          *(undefined4 *)(param_1 + 0xb54) = 0;
        }
      }
      piVar8 = (int *)func_0052FBA0(*piVar8 + 0x3dbbc,*(uint *)(param_1 + 0xcac));
      if (piVar8 != (int *)0x0) {
        param_3 = *(float **)(param_1 + 0xb58);
        *(bool *)((int)piVar8 + 0x40e) = *(float **)(param_1 + 0xb54) < param_3;
        if (iVar5 != 0) {
          (**(code **)(*piVar8 + 0x1c))(piVar8);
        }
      }
    }
  }
  return func_004F68AC(param_1,param_2,param_3,param_4);
}

