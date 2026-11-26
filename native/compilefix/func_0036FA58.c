/* compilefix: USA 0036FA58 (EU 0036FA34), the converted stage-2 text.
 * Fixed (BOOT_LOG 184): the ARM compares the float's bits (vmov rX, sY; cmp), which the converted text
 * wrote as a conversion of the value to an integer. */
#include "ghidra_types.h"

extern int func_00100174(int *param_1);
extern undefined8 func_00114608(uint param_1,uint param_2);
extern float func_00115154(float *param_1,float *param_2,uint param_3);
extern int func_00115C54(float *param_1,float *param_2,float *param_3);
extern int func_00115C70(float *param_1,float *param_2,float *param_3);
extern int func_00115D70(float *param_1,float *param_2,float fparam_0);
extern int func_00115DAC(float *param_1,float *param_2,float *param_3,float fparam_0);
extern float func_00115DC8(float *param_1);
extern int func_00115E10(float *param_1,float *param_2,float *param_3);
extern float func_002E0458(void);
extern int func_0036F590(float *param_1);
extern int func_004D80A4(float *param_1,uint param_2,float fparam_0);
extern int func_004D838C(float *param_1,float *param_2,float fparam_0,float fparam_1,float fparam_2);
extern int func_004D8490(float *param_1,float fparam_0);
extern int func_0053F400(int param_1);
extern int func_0054729C(int param_1);
extern int func_005582E8(int param_1);
extern int func_005841A8(int param_1,undefined4 param_2,int *param_3);
extern int func_00589050(int param_1,undefined4 *param_2,float *param_3);
extern int func_0058E2B8(int *param_1);
extern int func_0068C690(float *param_1);
extern int *DAT_0036fe9c;
extern undefined4 *DAT_0036fea0;
extern int DAT_0036fea4;
extern uint *DAT_0036fea8;
extern undefined4 *DAT_0036feac;
extern undefined4 DAT_0036feb0;
extern int *DAT_0036feb4;
extern float DAT_0036feb8;
extern int *DAT_0036febc;
extern float DAT_0036fec0;
extern float DAT_0036fec4;
extern int DAT_0036fec8;
extern float DAT_0036fecc;
extern float DAT_0036fed0;
extern float DAT_0036fed4;
extern uint DAT_0036fed8;
extern float DAT_0036fedc;
extern float DAT_0036fee0;
extern float DAT_00370334;
extern float DAT_00370338;
extern float DAT_0037033c;
extern float DAT_00370340;
extern float DAT_00370494;
extern float DAT_00370498;
extern float DAT_0037049c;
extern int DAT_003704a0;

// USA 0036FA58 <- EU 0036FA34 (Ghidra, non-matching)
// GLOBAL DAT_0036fe9c int *
// GLOBAL DAT_0036fea0 undefined4 *
// GLOBAL DAT_0036fea4 int
// GLOBAL DAT_0036fea8 uint *
// GLOBAL DAT_0036feac undefined4 *
// GLOBAL DAT_0036feb0 undefined4
// GLOBAL DAT_0036feb4 int *
// GLOBAL DAT_0036feb8 float
// GLOBAL DAT_0036febc int *
// GLOBAL DAT_0036fec0 float
// GLOBAL DAT_0036fec4 float
// GLOBAL DAT_0036fec8 int
// GLOBAL DAT_0036fecc float
// GLOBAL DAT_0036fed0 float
// GLOBAL DAT_0036fed4 float
// GLOBAL DAT_0036fed8 uint
// GLOBAL DAT_0036fedc float
// GLOBAL DAT_0036fee0 float
// GLOBAL DAT_00370334 float
// GLOBAL DAT_00370338 float
// GLOBAL DAT_0037033c float
// GLOBAL DAT_00370340 float
// GLOBAL DAT_00370494 float
// GLOBAL DAT_00370498 float
// GLOBAL DAT_0037049c float
// GLOBAL DAT_003704a0 int

void func_0036FA58(float *param_1,byte *param_2,float *param_3,int param_4)

{
  short sVar1;
  byte bVar2;
  char cVar3;
  char cVar4;
  int *piVar5;
  undefined1 uVar6;
  undefined4 *puVar7;
  int iVar8;
  uint uVar9;
  float *pfVar10;
  int iVar11;
  int iVar12;
  bool bVar13;
  bool bVar14;
  uint in_fpscr;
  float fVar15;
  float fVar16;
  float fVar17;
  uint uVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  undefined8 uVar26;
  _Alignas(8) unsigned char albw_frame[0x100];
  #define local_f8 (*(float *)(albw_frame + 0x8))
  #define local_f4 (*(float *)(albw_frame + 0xc))
  #define local_f0 (*(float *)(albw_frame + 0x10))
  #define fStack_ec (*(float *)(albw_frame + 0x14))
  #define local_e8 (*(float *)(albw_frame + 0x18))
  #define local_e4 (*(float *)(albw_frame + 0x1c))
  #define local_e0 (*(float *)(albw_frame + 0x20))
  #define local_dc (*(float *)(albw_frame + 0x24))
  #define local_d8 (*(float *)(albw_frame + 0x28))
  #define local_d4 (*(float *)(albw_frame + 0x2c))
  #define local_d0 (*(float *)(albw_frame + 0x30))
  #define local_cc (*(float *)(albw_frame + 0x34))
  #define local_c8 (*(float *)(albw_frame + 0x38))
  #define local_c4 (*(float *)(albw_frame + 0x3c))
  #define local_c0 (*(float *)(albw_frame + 0x40))
  #define local_bc (*(float *)(albw_frame + 0x44))
  #define fStack_b8 (*(float *)(albw_frame + 0x48))
  #define fStack_b4 (*(float *)(albw_frame + 0x4c))
  #define local_b0 (*(float *)(albw_frame + 0x50))
  #define local_ac (*(float *)(albw_frame + 0x54))
  #define local_a8 (*(float *)(albw_frame + 0x58))
  #define local_a4 (*(float *)(albw_frame + 0x5c))
  #define local_a0 (*(float *)(albw_frame + 0x60))
  #define local_9c (*(float *)(albw_frame + 0x64))
  #define local_98 (*(float *)(albw_frame + 0x68))
  #define uStack_94 (*(undefined4 *)(albw_frame + 0x6c))
  #define fStack_90 (*(float *)(albw_frame + 0x70))
  #define local_8c (*(float *)(albw_frame + 0x74))
  #define local_88 (*(float *)(albw_frame + 0x78))
  #define local_84 (*(float *)(albw_frame + 0x7c))
  #define local_80 (*(float *)(albw_frame + 0x80))
  #define local_7c (*(float *)(albw_frame + 0x84))
  #define local_78 (*(float *)(albw_frame + 0x88))
  #define local_74 (*(float *)(albw_frame + 0x8c))
  #define fStack_70 (*(float *)(albw_frame + 0x90))
  #define fStack_6c (*(float *)(albw_frame + 0x94))
  #define local_68 (*(float *)(albw_frame + 0x98))
  #define uStack_64 (*(undefined4 *)(albw_frame + 0x9c))
  #define local_60 (*(float *)(albw_frame + 0xa0))
  #define pfStack_34 (*(float * *)(albw_frame + 0xcc))
  #define pbStack_30 (*(byte * *)(albw_frame + 0xd0))
  #define pfStack_2c (*(float * *)(albw_frame + 0xd4))
  #define local_28 (*(int *)(albw_frame + 0xd8))
  pfStack_34 = param_1;
  pbStack_30 = param_2;
  pfStack_2c = param_3;
  local_28 = param_4;
  if (*(byte *)((int)param_1 + 0x17) < 2) {
    puVar7 = (undefined4 *)
             func_005841A8(*DAT_0036fe9c,*DAT_0036fea0,*(int **)(DAT_0036fea4 + *DAT_0036fe9c));
    puVar7 = (undefined4 *)*puVar7;
    if (((*DAT_0036fea8 & 1) == 0) && (iVar8 = func_00100174((int *)DAT_0036fea8), iVar8 != 0)) {
      *DAT_0036feac = DAT_0036feb0;
    }
    if ((puVar7 == (undefined4 *)0x0) ||
       (iVar8 = (**(code **)*puVar7)(puVar7,DAT_0036feac), iVar8 == 0)) {
      puVar7 = (undefined4 *)0x0;
    }
    if (puVar7 == (undefined4 *)0x0) {
      *(char *)((int)param_1 + 0x17) = *(char *)((int)param_1 + 0x17) + '\x01';
    }
    else if (*(char *)(puVar7 + 0x103) != '\0') {
      param_1[7] = ALBW_AS_F32(puVar7[0x104]);
      param_1[8] = ALBW_AS_F32(puVar7[0x105]);
      param_1[9] = ALBW_AS_F32(puVar7[0x106]);
      iVar8 = func_0054729C((int)puVar7);
      *(short *)(param_1 + 6) = (short)iVar8;
      *(undefined1 *)((int)puVar7 + 0x2d7) = 1;
      *(undefined1 *)((int)param_1 + 0x17) = 0xff;
    }
  }
  fVar17 = DAT_0036feb8;
  piVar5 = DAT_0036feb4;
  uVar9 = *(uint *)(*(int *)(param_2 + 0x20) + 4);
  bVar14 = uVar9 == 0x3f800000;
  if (bVar14) {
    uVar9 = (uint)*param_2;
  }
  if (!bVar14 || uVar9 != 0) {
    *(undefined1 *)((int)param_1 + 0x12) = 0;
  }
  cVar4 = *(char *)((int)param_1 + 0x16);
  *(undefined1 *)((int)param_1 + 0x16) = 0;
  *(undefined1 *)(param_1 + 5) = 0;
  iVar8 = func_00589050(*DAT_0036febc,&local_bc,*(float **)(*piVar5 + 0x1c));
  fVar20 = DAT_0036fec0;
  if (iVar8 == 0) {
    pfVar10 = (float *)func_005582E8((int)param_1);
    func_00115C54(&local_f8,pfVar10,param_1 + 0xd);
    uVar9 = in_fpscr & 0xfffffff;
    in_fpscr = uVar9 | (uint)(local_f8 == fVar20) << 0x1e;
    bVar14 = false;
    if (SUB41(in_fpscr >> 0x1e,0)) {
      in_fpscr = uVar9 | (uint)(local_f4 == fVar20) << 0x1e;
      bVar14 = SUB41(in_fpscr >> 0x1e,0);
    }
    if ((bVar14) &&
       (in_fpscr = in_fpscr & 0xfffffff | (uint)(local_f0 == fVar20) << 0x1e,
       SUB41(in_fpscr >> 0x1e,0))) {
      func_0036F590(param_1);
    }
  }
  fVar21 = DAT_0036fee0;
  fVar22 = DAT_0036fed4;
  fVar24 = DAT_0036fed0;
  fVar16 = DAT_0036fecc;
  iVar8 = DAT_0036fec8;
  fVar23 = DAT_0036fec4;
  bVar2 = *param_2;
  bVar14 = (bVar2 == 4 || bVar2 == 5) || bVar2 == 6;
  if ((bVar2 == 4 || bVar2 == 5) || bVar2 == 6) {
    bVar14 = *(char *)((int)param_1 + 0x15) == '\0';
  }
  if (bVar14) {
    fVar17 = DAT_0036fecc;
    fVar20 = DAT_0036fed0;
    uVar9 = func_0053F400(*piVar5);
    if (*param_2 == 5) {
      iVar11 = **(int **)(*piVar5 + 0x24);
      uVar26 = func_00114608(DAT_0036fed8,5);
      uVar9 = (int)uVar26 + iVar11 & 0xe0000000;
    }
    func_00115154(&local_f8,&local_f4,uVar9);
    if (*param_2 != 5) {
      fVar17 = fVar20;
    }
    *param_1 = local_f8 * fVar17;
    param_1[2] = local_f4 * fVar17;
    param_1[0x10] = local_f8 * fVar17;
    param_1[0x11] = param_1[1];
    param_1[0x12] = param_1[2];
    param_1[3] = *(float *)(iVar8 + 4);
    *(undefined1 *)((int)param_1 + 0x12) = 1;
    *(bool *)((int)param_1 + 0x13) = *param_2 == 5;
    if (*(char *)(param_1 + 4) != '\x04' && *(char *)(param_1 + 4) != '\x05') goto LAB_0036fcb0;
LAB_0036fcb8:
    uVar6 = 0;
  }
  else {
    if ((bVar2 != 8) || (local_28 == 0)) {
      cVar3 = *(char *)(param_1 + 4);
      if ((cVar3 == '\0' || cVar3 == '\x04') || (cVar3 == '\x05' || cVar3 == '\x06')) {
LAB_0036fd38:
        if (*(char *)((int)param_1 + 0x11) == '\0') {
          fVar15 = *(float *)(param_2 + 8);
          uVar9 = in_fpscr & 0xfffffff;
          uVar18 = uVar9 | (uint)(fVar15 < fVar20) << 0x1f | (uint)(fVar15 == fVar20) << 0x1e;
          in_fpscr = uVar18 | (uint)(NAN(fVar15) || NAN(fVar20)) << 0x1c;
          bVar2 = (byte)(uVar18 >> 0x18);
          if (((bool)(bVar2 >> 6 & 1) || bVar2 >> 7 != ((byte)(in_fpscr >> 0x1c) & 1)) ||
             ((*(ushort *)(param_2 + 0x1c) & 1) != 0)) {
            in_fpscr = uVar9 | (uint)(*(float *)(param_2 + 0x10) == fVar20) << 0x1e;
            bVar14 = false;
            if (SUB41(in_fpscr >> 0x1e,0)) {
              in_fpscr = uVar9 | (uint)(*(float *)(param_2 + 0x14) == fVar20) << 0x1e;
              bVar14 = SUB41(in_fpscr >> 0x1e,0);
            }
            bVar13 = false;
            if (bVar14) {
              in_fpscr = in_fpscr & 0xfffffff | (uint)(*(float *)(param_2 + 0x18) == fVar20) << 0x1e
              ;
              bVar13 = SUB41(in_fpscr >> 0x1e,0);
            }
            if (!bVar13) goto LAB_0036fee4;
            param_1[3] = *(float *)(DAT_0036fec8 + 4);
            if (*(char *)((int)param_1 + 0x12) != '\0') {
              fVar15 = fVar16;
              if (*(char *)((int)param_1 + 0x13) == '\0') {
                fVar15 = fVar24;
              }
              uVar9 = in_fpscr & 0xfffffff | (uint)(fVar17 <= fVar15) << 0x1d;
              if (!SUB41(uVar9 >> 0x1d,0)) {
                fVar15 = fVar17;
              }
              fVar25 = SQRT(*param_1 * *param_1 + param_1[2] * param_1[2]);
              if (*(int *)(*(int *)(param_2 + 0x20) + 4) == 0x3f800000) {
                uVar18 = func_0068C690(param_1);
                func_00115154(&local_f4,&local_f0,uVar18);
                fVar17 = SQRT(local_f4 * fVar16 * local_f4 * fVar16 +
                              local_f0 * fVar24 * local_f0 * fVar24);
              }
              uVar9 = uVar9 & 0xfffffff;
              in_fpscr = uVar9 | (uint)(fVar25 == fVar17) << 0x1e | (uint)(fVar17 <= fVar25) << 0x1d
              ;
              bVar2 = (byte)(in_fpscr >> 0x18);
              fVar16 = fVar20;
              if (((bool)(bVar2 >> 5 & 1) && !(bool)(bVar2 >> 6)) &&
                 (uVar18 = uVar9 | (uint)(fVar25 < fVar15) << 0x1f,
                 in_fpscr = uVar18 | (uint)(NAN(fVar25) || NAN(fVar15)) << 0x1c, fVar16 = fVar22,
                 (byte)(uVar18 >> 0x1f) != ((byte)(in_fpscr >> 0x1c) & 1))) {
                in_fpscr = uVar9 | (uint)(fVar15 - fVar17 == fVar20) << 0x1e;
                fVar16 = fVar20;
                if (!SUB41(in_fpscr >> 0x1e,0)) {
                  fVar16 = (fVar22 * (fVar25 - fVar17)) / (fVar15 - fVar17) + fVar20;
                }
              }
              param_1[3] = *(float *)(iVar8 + 4) + (fVar21 - *(float *)(iVar8 + 4)) * fVar16;
            }
          }
          else {
LAB_0036fee4:
            fVar16 = DAT_0036fedc;
            fVar21 = DAT_0036fecc;
            fVar15 = DAT_0036fee0;
            if (*(int *)(*(int *)(param_2 + 0x20) + 4) == 0x3f800000) {
              func_00115154(&local_f4,&local_f8,*(uint *)(param_2 + 0xc));
              local_c8 = local_f4 * fVar21;
              local_c0 = local_f8 * fVar24;
              fVar17 = SQRT(local_c8 * local_c8 + fVar20 * fVar20 + local_c0 * local_c0);
              local_c4 = fVar20;
              func_00115D70(&local_c8,&local_c8,*(float *)(param_2 + 8));
            }
            else {
              func_004D80A4(&local_c8,*(uint *)(param_2 + 0xc),*(float *)(param_2 + 8) * fVar17);
              local_c4 = fVar20;
            }
            local_8c = *(float *)(param_2 + 0x10) * DAT_00370334;
            local_84 = *(float *)(param_2 + 0x18) * DAT_00370338;
            local_88 = fVar20;
            func_00115C54(&local_c8,&local_c8,&local_8c);
            if (*(char *)((int)param_1 + 0x12) == '\0') {
              fVar25 = fVar22;
              if (0x3f800000 < (int)ALBW_AS_U32(*(float *)(param_2 + 8))) {
                fVar25 = *(float *)(param_2 + 8);
              }
              fVar25 = fVar25 * fVar17;
              uVar9 = in_fpscr & 0xfffffff;
              in_fpscr = uVar9 | (uint)(local_c8 * local_c8 + local_c0 * local_c0 <= fVar25 * fVar25
                                       ) << 0x1d;
              if (!SUB41(in_fpscr >> 0x1d,0)) {
                fVar19 = SQRT(local_c8 * local_c8 + local_c4 * local_c4 + local_c0 * local_c0);
                uVar9 = uVar9 | (uint)(fVar19 < fVar20) << 0x1f | (uint)(fVar19 == fVar20) << 0x1e;
                in_fpscr = uVar9 | (uint)(NAN(fVar19) || NAN(fVar20)) << 0x1c;
                bVar2 = (byte)(uVar9 >> 0x18);
                if (!(bool)(bVar2 >> 6 & 1) && bVar2 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1)) {
                  fVar25 = fVar25 / fVar19;
                  local_c8 = local_c8 * fVar25;
                  local_c4 = local_c4 * fVar25;
                  local_c0 = local_c0 * fVar25;
                }
              }
            }
            if (*(int *)(*(int *)(param_2 + 0x20) + 4) == 0x3f800000) {
              func_004D838C(param_1,&local_c8,param_1[3],fVar15,fVar16);
            }
            else {
              local_74 = *param_1;
              fStack_70 = param_1[1];
              fStack_6c = param_1[2];
              func_004D838C(param_1,&local_c8,param_1[3],fVar15,fVar16);
              func_00115C70(&local_a4,param_1,&local_74);
              fVar16 = func_00115DC8(&local_a4);
              uVar9 = in_fpscr & 0xfffffff | (uint)(fVar16 < fVar20) << 0x1f |
                      (uint)(fVar16 == fVar20) << 0x1e;
              in_fpscr = uVar9 | (uint)(NAN(fVar16) || NAN(fVar20)) << 0x1c;
              bVar2 = (byte)(uVar9 >> 0x18);
              if (!(bool)(bVar2 >> 6 & 1) && bVar2 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1)) {
                local_d4 = local_c8;
                local_cc = local_c0;
                local_d0 = fVar20;
                func_00115DC8(&local_d4);
                iVar11 = func_0068C690(&local_d4);
                fVar15 = local_d4 * local_a4 + local_d0 * local_a0 + local_cc * local_9c;
                if (((uint)ALBW_AS_U32(fVar15) < (uint)ALBW_AS_U32(DAT_0037033c)) && ((int)ALBW_AS_U32(fVar15) < 0x3f800000)) {
                  fVar16 = SQRT(fVar22 - fVar15 * fVar15) * fVar16;
                  iVar12 = func_0068C690(&local_a4);
                  local_f0 = ALBW_AS_F32(((iVar11 + 0x40000000) - iVar12));
                  uVar9 = func_0058E2B8((int *)&local_f0);
                  if (uVar9 < 0x40000000) {
                    local_78 = -local_d4;
                    local_80 = local_cc;
                  }
                  else {
                    local_80 = -local_cc;
                    local_78 = local_d4;
                  }
                  local_7c = fVar20;
                  func_00115E10(&local_e0,param_1,&local_d4);
                  func_00115D70(&local_68,&local_80,fVar16 * DAT_00370340);
                  local_98 = local_68;
                  uStack_94 = uStack_64;
                  fStack_90 = local_60;
                  func_00115C54(param_1,param_1,&local_98);
                  func_00115E10(&local_b0,param_1,&local_d4);
                  in_fpscr = in_fpscr & 0xfffffff |
                             (uint)(fVar20 <=
                                   local_e0 * local_b0 + local_dc * local_ac + local_d8 * local_a8)
                             << 0x1d;
                  if (!SUB41(in_fpscr >> 0x1d,0)) {
                    fVar20 = param_1[1];
                    func_00115D70(&local_68,&local_d4,
                                  *param_1 * local_d4 + fVar20 * local_d0 + param_1[2] * local_cc);
                    *param_1 = local_68;
                    param_1[2] = local_60;
                    param_1[1] = fVar20;
                  }
                }
              }
            }
            if (*(int *)(*(int *)(param_2 + 0x20) + 4) == 0x3f800000) {
              fVar20 = *(float *)(iVar8 + 8);
            }
            else {
              fVar20 = *(float *)(iVar8 + 0xc);
            }
            param_1[3] = param_1[3] + (fVar20 - param_1[3]) * *(float *)(iVar8 + 0x10);
            if (*(int *)(*(int *)(param_2 + 0x20) + 4) == 0x3f800000) {
              uVar9 = func_0068C690(param_1);
              func_00115154(&local_f8,&local_f4,uVar9);
              fVar17 = SQRT(local_f8 * fVar21 * local_f8 * fVar21 +
                            local_f4 * fVar24 * local_f4 * fVar24);
            }
            if ((*(char *)((int)param_1 + 0x12) != '\0') &&
               (fVar20 = *param_1 * *param_1 + param_1[2] * param_1[2],
               in_fpscr = in_fpscr & 0xfffffff | (uint)(fVar20 == fVar17 * fVar17) << 0x1e |
                          (uint)(fVar17 * fVar17 <= fVar20) << 0x1d,
               bVar2 = (byte)(in_fpscr >> 0x18), !(bool)(bVar2 >> 5 & 1) || (bool)(bVar2 >> 6))) {
              *(undefined1 *)((int)param_1 + 0x12) = 0;
            }
          }
          func_0036F590(param_1);
          goto LAB_003702c8;
        }
      }
      else if (cVar3 == '\b') {
        if (cVar4 == '\0') goto LAB_0036fd38;
      }
      else if (bVar2 != 0) goto LAB_0036fd38;
      fVar16 = DAT_0036fedc;
      fVar21 = DAT_0036fecc;
      func_00115C70(param_1,param_3,*(float **)(param_2 + 4));
      fVar15 = param_1[1];
      uVar9 = in_fpscr & 0xfffffff;
      in_fpscr = uVar9 | (uint)(fVar23 <= fVar15) << 0x1d;
      fVar20 = fVar23;
      if ((SUB41(in_fpscr >> 0x1d,0)) &&
         (uVar9 = uVar9 | (uint)(fVar15 < fVar16) << 0x1f | (uint)(fVar15 == fVar16) << 0x1e,
         in_fpscr = uVar9 | (uint)(NAN(fVar15) || NAN(fVar16)) << 0x1c,
         bVar2 = (byte)(uVar9 >> 0x18), fVar20 = fVar15,
         !(bool)(bVar2 >> 6 & 1) && bVar2 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1))) {
        fVar20 = fVar16;
      }
      param_1[1] = fVar20;
      pfVar10 = (float *)func_005582E8((int)param_1);
      func_00115C54(&local_f0,pfVar10,param_1 + 0xd);
      func_00115C70(param_1,param_1,&local_f0);
      if (*(int *)(*(int *)(param_2 + 0x20) + 4) == 0x3f800000) {
        uVar9 = func_0068C690(param_1);
        func_00115154(&local_f8,&local_f4,uVar9);
        fVar17 = SQRT(local_f8 * fVar21 * local_f8 * fVar21 + local_f4 * fVar24 * local_f4 * fVar24)
        ;
      }
      func_004D8490(param_1,fVar17);
      *(undefined1 *)(param_1 + 5) = 1;
      goto LAB_003702c8;
    }
    *param_1 = fVar20;
    param_1[2] = fVar20;
    func_0036F590(param_1);
    param_1[3] = *(float *)(iVar8 + 4);
    *(undefined1 *)((int)param_1 + 0x16) = 1;
    if (*(char *)(param_1 + 4) == '\b') goto LAB_0036fcb8;
LAB_0036fcb0:
    uVar6 = 1;
  }
  *(undefined1 *)(param_1 + 5) = uVar6;
LAB_003702c8:
  pfVar10 = param_1 + 0xd;
  *(byte *)(param_1 + 4) = *param_2;
  *(undefined1 *)((int)param_1 + 0x11) = 0;
  *(undefined1 *)((int)param_1 + 0x15) = 0;
  fVar17 = func_002E0458();
  func_00115C70(&local_e8,&local_bc,pfVar10);
  fVar20 = SQRT(local_e8 * local_e8 + local_e4 * local_e4 + local_e0 * local_e0);
  uVar9 = in_fpscr & 0xfffffff | (uint)(fVar20 == fVar17) << 0x1e | (uint)(fVar17 <= fVar20) << 0x1d
  ;
  bVar2 = (byte)(uVar9 >> 0x18);
  if ((bool)(bVar2 >> 5 & 1) && !(bool)(bVar2 >> 6)) {
    fVar20 = fVar22 / fVar20;
    local_e8 = local_e8 * fVar20;
    local_e4 = local_e4 * fVar20;
    local_e0 = local_e0 * fVar20;
    func_00115DAC(pfVar10,&local_e8,pfVar10,fVar17);
  }
  else {
    *pfVar10 = local_bc;
    param_1[0xe] = fStack_b8;
    param_1[0xf] = fStack_b4;
  }
  fVar17 = DAT_00370494;
  if (*(short *)((int)param_1 + 0x1a) < 0x2d) {
    sVar1 = *(short *)((int)param_1 + 0x1a) + 1;
    *(short *)((int)param_1 + 0x1a) = sVar1;
    fVar20 = (float)VectorSignedToFloat((int)sVar1,(byte)(uVar9 >> 0x15) & 3);
    uVar18 = VectorFloatToUnsigned(fVar20 * fVar17 * DAT_00370498,3);
    iVar8 = DAT_003704a0 + (uVar18 >> 0x18) * 0x10;
    fVar17 = (float)VectorUnsignedToFloat(uVar18 & 0xffffff,(byte)(uVar9 >> 0x15) & 3);
    func_00115D70(&local_f4,param_1 + 7,
                  ((*(float *)(iVar8 + 8) + *(float *)(iVar8 + 0xc) * fVar17 * DAT_0037049c) -
                  fVar22) * fVar23);
    param_1[10] = local_f4;
    param_1[0xb] = local_f0;
    param_1[0xc] = fStack_ec;
  }
  return;
}

