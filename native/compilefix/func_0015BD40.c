/* compilefix: USA 0015BD40 (EU 0015BD44), the converted stage-2 text.
 * Fixed (BOOT_LOG 184): the ARM copies this word between a float and an integer (no vcvt), which the
 * converted text wrote as a conversion of the value. */
#include "ghidra_types.h"

extern int func_00115C54(float *param_1,float *param_2,float *param_3);
extern int func_00115C70(float *param_1,float *param_2,float *param_3);
extern int func_00115D70(float *param_1,float *param_2,float fparam_0);
extern int func_0015B580(int param_1,uint param_2);
extern int func_00161178(undefined4 *param_1);
extern int func_0032ECE0(float *param_1,float *param_2,float *param_3,float *param_4);
extern float func_0049216C(float *param_1,uint *param_2,float *param_3);
extern int func_004A2D1C(int param_1,float *param_2);
extern int func_0054F9E4(int param_1,uint param_2);
extern int func_0054FA10(int param_1,uint param_2);
extern int func_0054FBC4(int param_1,float *param_2,float *param_3);
extern undefined8 func_0058A474(undefined4 param_1,uint param_2);
extern int func_0065836C(undefined4 *param_1,undefined1 param_2);
extern int func_0068C690(float *param_1);
extern float DAT_0015c104;
extern float DAT_0015c108;
extern int DAT_0015c10c;
extern float DAT_0015c110;
extern float DAT_0015c114;

// USA 0015BD40 <- EU 0015BD44 (Ghidra, non-matching)
// GLOBAL DAT_0015c104 float
// GLOBAL DAT_0015c108 float
// GLOBAL DAT_0015c10c int
// GLOBAL DAT_0015c110 float
// GLOBAL DAT_0015c114 float

undefined4 func_0015BD40(undefined4 *param_1)

{
  ushort uVar1;
  float *pfVar2;
  float *pfVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 *puVar8;
  bool bVar9;
  float fVar10;
  undefined8 uVar11;
  _Alignas(8) unsigned char albw_frame[0xd0];
  #define local_c8 (*(undefined4 * *)(albw_frame + 0x8))
  #define puStack_c4 (*(undefined4 * *)(albw_frame + 0xc))
  #define puStack_c0 (*(undefined4 * *)(albw_frame + 0x10))
  #define local_bc (*(undefined4 * *)(albw_frame + 0x14))
  #define local_b0 (*(float * *)(albw_frame + 0x20))
  #define local_a4 (*(undefined4 * *)(albw_frame + 0x2c))
  #define puStack_a0 (*(undefined4 * *)(albw_frame + 0x30))
  #define puStack_9c (*(undefined4 * *)(albw_frame + 0x34))
  #define local_98 (*(undefined4 * *)(albw_frame + 0x38))
  #define puStack_94 (*(undefined4 * *)(albw_frame + 0x3c))
  #define puStack_90 (*(undefined4 * *)(albw_frame + 0x40))
  #define local_8c ((undefined4 * *)(albw_frame + 0x44))
  #define local_7c (*(float *)(albw_frame + 0x54))
  #define local_78 (*(float *)(albw_frame + 0x58))
  #define local_74 (*(undefined4 *)(albw_frame + 0x5c))
  #define local_70 (*(float *)(albw_frame + 0x60))
  #define fStack_6c (*(float *)(albw_frame + 0x64))
  #define local_68 (*(float *)(albw_frame + 0x68))
  #define afStack_60 ((float *)(albw_frame + 0x70))
  local_bc = param_1 + 0x26d;
  pfVar2 = (float *)func_0054F9E4((int)local_bc,param_1[0x245]);
  pfVar3 = (float *)func_0054FA10((int)local_bc,param_1[0x245]);
  fVar10 = DAT_0015c104;
  func_00115D70((float *)local_8c,pfVar3,DAT_0015c104);
  local_c8 = local_8c[0];
  puStack_c4 = local_8c[1];
  puStack_c0 = local_8c[2];
  func_00115C54((float *)local_8c,pfVar2,(float *)&local_c8);
  local_a4 = local_8c[0];
  puStack_a0 = local_8c[1];
  puStack_9c = local_8c[2];
  func_00115D70((float *)local_8c,pfVar3,fVar10);
  local_c8 = local_8c[0];
  puStack_c4 = local_8c[1];
  puStack_c0 = local_8c[2];
  func_00115C70((float *)local_8c,pfVar2,(float *)&local_c8);
  local_98 = local_8c[0];
  puStack_94 = local_8c[1];
  puStack_90 = local_8c[2];
  local_b0 = (float *)(param_1 + 0x265);
  if (*(char *)(param_1 + 0x26b) == '\0') goto LAB_0015bf24;
  puVar8 = param_1 + 0x22f;
  if ((uint)param_1[599] < 0x3c) {
    fVar10 = ALBW_AS_F32(param_1[0x268]) - *local_b0;
    if (SQRT(fVar10 * fVar10 +
             (ALBW_AS_F32(param_1[0x26a]) - ALBW_AS_F32(param_1[0x267])) *
             (ALBW_AS_F32(param_1[0x26a]) - ALBW_AS_F32(param_1[0x267]))) <= DAT_0015c108) {
      fVar10 = *pfVar2 - ALBW_AS_F32(param_1[0x262]);
      if (0x3effffff <
          (int)ALBW_AS_U32(SQRT(fVar10 * fVar10 +
                    (pfVar2[2] - ALBW_AS_F32(param_1[0x264])) * (pfVar2[2] - ALBW_AS_F32(param_1[0x264])))))
      goto LAB_0015bf24;
      uVar1 = *(ushort *)((int)param_1 + 0x2e);
    }
    else {
      iVar4 = func_0032ECE0((float *)(param_1 + 0x268),local_b0,(float *)&local_a4,
                            (float *)&local_98);
      if (iVar4 == 0) {
LAB_0015bf24:
        uVar1 = *(ushort *)((int)param_1 + 0x2e);
        bVar9 = (uVar1 & 0xff) != 0;
        if (bVar9) {
          uVar1 = (ushort)*(byte *)(param_1 + 0x26b);
        }
        if ((bVar9 && uVar1 != 0) && (*(char *)((int)param_1 + 0xdf1) == '\0')) {
          local_8c[0] = func_00161178(param_1);
          local_8c[1] = func_0015B580((int)param_1,0);
          local_8c[2] = func_0015B580((int)param_1,1);
          iVar4 = DAT_0015c10c;
          uVar7 = 0;
          do {
            puVar8 = local_8c[uVar7];
            if ((((puVar8 != (undefined4 *)0x0 && puVar8 != param_1) &&
                 (*(char *)(puVar8 + 0x26b) != '\0')) && (*(char *)(puVar8 + 0x230) == '\n')) &&
               ((*(char *)((int)puVar8 + 0xdf1) == '\0' &&
                (fVar10 = ALBW_AS_F32(param_1[0x262]) - ALBW_AS_F32(puVar8[0x262]),
                (int)ALBW_AS_U32(SQRT(fVar10 * fVar10 +
                          (ALBW_AS_F32(param_1[0x264]) - ALBW_AS_F32(puVar8[0x264])) *
                          (ALBW_AS_F32(param_1[0x264]) - ALBW_AS_F32(puVar8[0x264])))) < iVar4)))) {
              uVar11 = func_0058A474(param_1,0x3c);
              if ((int)uVar11 != 0) {
                uVar5 = param_1[0x245];
                uVar6 = param_1[0x244];
                param_1[0x245] = puVar8[0x245];
                param_1[0x244] = puVar8[0x244];
                puVar8[0x244] = uVar6;
                puVar8[0x245] = uVar5;
                break;
              }
              *(undefined1 *)((int)param_1 + 0xdf1) = 1;
              *(undefined1 *)((int)puVar8 + 0xdf1) = 1;
            }
            uVar7 = uVar7 + 1;
          } while (uVar7 < 3);
        }
        if (param_1[900] != 0) {
          uVar7 = func_0054FBC4((int)local_bc,local_b0,(float *)0x0);
          pfVar2 = (float *)func_0054FA10((int)local_bc,uVar7);
          local_70 = *pfVar2;
          fStack_6c = pfVar2[1];
          local_68 = pfVar2[2];
          local_8c[1] = (undefined4 *)func_0068C690(&local_70);
          local_8c[2] = (undefined4 *)0x0;
          local_8c[0] = (undefined4 *)0x0;
          local_7c = ALBW_AS_F32(param_1[0x262]);
          local_78 = DAT_0015c110;
          if ((*(ushort *)((int)param_1 + 0x2e) & 0xff) != 0) {
            local_78 = DAT_0015c114;
          }
          local_74 = param_1[0x264];
          local_78 = local_78 + ALBW_AS_F32(param_1[3]);
          func_0049216C(afStack_60,(uint *)local_8c,&local_7c);
          iVar4 = param_1[900];
          if (iVar4 != 0) {
            if (*(int *)(iVar4 + 0x1c) == param_1[0x385]) {
              func_004A2D1C(iVar4,afStack_60);
            }
            return 0;
          }
        }
        return 0;
      }
      uVar1 = *(ushort *)((int)param_1 + 0x2e);
    }
    if ((uVar1 & 0xff) == 0) {
      return func_0065836C(puVar8,7);
    }
  }
  else if ((*(ushort *)((int)param_1 + 0x2e) & 0xff) == 0) {
    return func_0065836C(puVar8,0xb);
  }
  return func_0065836C(puVar8,9);
}

