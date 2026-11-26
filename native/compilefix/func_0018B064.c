/* compilefix: USA 0018B064 (EU 0018B064), Ghidra-derived (build/ghidra_analyzed4).
 * Failed to compile: operand of type 'float' cannot be cast to a pointer type
 * Fixed (each an exact C form of the ARM operation; the rest is the converted Ghidra text):
 *  - (T *)<float expr> -> (T *)CF_FBITS(expr): 32-bit copy of the float (vmov/vstr), never a conversion [3]
 *  - explicit casts at pointer-type mismatches (identity on the ARM) [1]
 * Confidence: high for the fixes (each class checked against the EU disassembly on sample sites);
 * the function body otherwise has the fidelity of the Ghidra output (bare `return;` exits of
 * functions retyped non-void return 0, as the converter does).
 * Fixed (BOOT_LOG 184): the ARM compares the float's bits (vmov rX, sY; cmp), which the converted text
 * wrote as a conversion of the value to an integer. */
#include "ghidra_types.h"
#include "../include/ghidra_concat44.h"
#include "compilefix.h"

extern int func_00110D44(undefined4 *param_1,byte *param_2,uint param_3);
extern int func_00115C54(float *param_1,float *param_2,float *param_3);
extern int func_00115C70(float *param_1,float *param_2,float *param_3);
extern int func_0014F0B0(int param_1);
extern int func_00393164(int *param_1);
extern int func_004A7620(int param_1,uint *param_2,uint param_3);
extern int func_004A8030(int param_1,int *param_2,uint param_3);
extern int func_00520EE4(int param_1);
extern int func_0052107C(int param_1);
extern uint DAT_0018b37c;
extern undefined4 DAT_0018b380;
extern undefined4 *DAT_0018b384;
extern int DAT_0018b388;
extern undefined4 DAT_0018b38c;
extern float DAT_0018b390;
extern float DAT_0018b394;
extern float DAT_0018b398;
extern undefined4 DAT_0018b39c;
extern undefined4 DAT_0018b3a0;
extern undefined4 DAT_0018b3a4;
extern int *DAT_0018b3a8;
extern float DAT_0018b3ac;
extern int DAT_0018b3b0;
extern int DAT_0018b588;

// USA 0018B064 <- EU 0018B064 (Ghidra, non-matching)
// GLOBAL DAT_0018b37c uint
// GLOBAL DAT_0018b380 undefined4
// GLOBAL DAT_0018b384 undefined4 *
// GLOBAL DAT_0018b388 int
// GLOBAL DAT_0018b38c undefined4
// GLOBAL DAT_0018b390 float
// GLOBAL DAT_0018b394 float
// GLOBAL DAT_0018b398 float
// GLOBAL DAT_0018b39c undefined4
// GLOBAL DAT_0018b3a0 undefined4
// GLOBAL DAT_0018b3a4 undefined4
// GLOBAL DAT_0018b3a8 int *
// GLOBAL DAT_0018b3ac float
// GLOBAL DAT_0018b3b0 int
// GLOBAL DAT_0018b588 int

void func_0018B064(uint param_1)

{
  uint uVar1;
  char cVar2;
  byte bVar3;
  undefined4 uVar4;
  int *piVar5;
  char cVar6;
  int iVar7;
  uint extraout_r1;
  bool bVar8;
  uint in_fpscr;
  uint uVar9;
  float fVar10;
  float fVar11;
  undefined1 *puVar12;
  float fVar13;
  undefined4 uVar14;
  undefined8 uVar15;
  ulonglong uVar16;
  _Alignas(8) unsigned char albw_frame[0x140];
  #define local_138 (*(undefined4 *)(albw_frame + 0x8))
  #define local_134 (*(float *)(albw_frame + 0xc))
  #define uStack_130 (*(undefined4 *)(albw_frame + 0x10))
  #define local_12c (*(undefined4 * *)(albw_frame + 0x14))
  #define local_128 (*(undefined4 * *)(albw_frame + 0x18))
  #define local_120 (*(undefined4 *)(albw_frame + 0x20))
  #define local_118 (*(undefined4 *)(albw_frame + 0x28))
  #define local_110 (*(int *)(albw_frame + 0x30))
  #define local_10c (*(float * *)(albw_frame + 0x34))
  #define local_100 (*(float *)(albw_frame + 0x40))
  #define local_fc (*(undefined4 *)(albw_frame + 0x44))
  #define uStack_f8 (*(undefined4 *)(albw_frame + 0x48))
  #define uStack_f4 (*(undefined4 *)(albw_frame + 0x4c))
  #define local_f0 (*(undefined4 *)(albw_frame + 0x50))
  #define local_ec (*(undefined4 *)(albw_frame + 0x54))
  #define local_e8 (*(float *)(albw_frame + 0x58))
  #define local_e4 ((byte *)(albw_frame + 0x5c))
  #define local_d4 (*(uint *)(albw_frame + 0x6c))
  #define local_d0 (*(undefined4 *)(albw_frame + 0x70))
  #define uStack_cc (*(undefined4 *)(albw_frame + 0x74))
  #define local_c8 (*(undefined4 *)(albw_frame + 0x78))
  #define local_c4 (*(undefined4 *)(albw_frame + 0x7c))
  #define local_c0 (*(undefined4 *)(albw_frame + 0x80))
  #define local_bc (*(undefined1 *)(albw_frame + 0x84))
  #define local_bb (*(undefined1 *)(albw_frame + 0x85))
  #define local_b8 (*(undefined1 * *)(albw_frame + 0x88))
  #define local_b4 (*(undefined4 * *)(albw_frame + 0x8c))
  #define local_b0 (*(float *)(albw_frame + 0x90))
  #define local_ac (*(undefined4 *)(albw_frame + 0x94))
  #define local_a8 (*(uint *)(albw_frame + 0x98))
  #define local_a4 (*(undefined4 *)(albw_frame + 0x9c))
  #define uStack_a0 (*(undefined4 *)(albw_frame + 0xa0))
  #define local_9c (*(undefined1 * *)(albw_frame + 0xa4))
  #define local_98 (*(int *)(albw_frame + 0xa8))
  #define local_94 (*(float *)(albw_frame + 0xac))
  #define local_90 (*(undefined1 *)(albw_frame + 0xb0))
  #define local_8f (*(undefined1 *)(albw_frame + 0xb1))
  #define local_88 (*(undefined4 *)(albw_frame + 0xb8))
  #define local_84 (*(uint *)(albw_frame + 0xbc))
  #define local_80 (*(undefined4 *)(albw_frame + 0xc0))
  #define uStack_7c (*(undefined4 *)(albw_frame + 0xc4))
  #define local_78 (*(float *)(albw_frame + 0xc8))
  #define local_74 (*(float *)(albw_frame + 0xcc))
  #define local_70 (*(float *)(albw_frame + 0xd0))
  #define local_5c (*(float *)(albw_frame + 0xe4))
  #define uStack_58 (*(undefined4 *)(albw_frame + 0xe8))
  #define uStack_54 (*(undefined4 *)(albw_frame + 0xec))
  #define local_50 (*(undefined4 *)(albw_frame + 0xf0))
  #define local_4c (*(uint *)(albw_frame + 0xf4))
  #define local_48 (*(undefined4 *)(albw_frame + 0xf8))
  #define local_44 (*(undefined4 *)(albw_frame + 0xfc))
  local_d4 = param_1 & 0xffff0000 | DAT_0018b37c;
  local_e4[0] = 0;
  local_e4[1] = 0;
  local_e4[2] = 0;
  local_e4[3] = 0;
  local_e4[4] = 0;
  local_e4[5] = 0;
  local_e4[6] = 0;
  local_e4[7] = 0;
  local_e4[8] = 0;
  local_e4[9] = 0;
  local_e4[10] = 0;
  local_e4[0xb] = 0;
  local_e4[0xc] = 0;
  local_e4[0xd] = 0;
  local_e4[0xe] = 0;
  local_e4[0xf] = 0;
  local_d0 = 0xff;
  uStack_cc = 0;
  local_c8 = 0;
  local_c4 = 0;
  local_c0 = DAT_0018b380;
  local_bc = 0;
  local_bb = 1;
  uVar14 = DAT_0018b380;
  func_00110D44((undefined4 *)(&local_12c),local_e4,0x2a);
  uVar4 = DAT_0018b38c;
  local_fc = *DAT_0018b384;
  uStack_f8 = DAT_0018b384[1];
  uStack_f4 = DAT_0018b384[2];
  uVar15 = CONCAT44(DAT_0018b390,uVar14);
  local_5c = *(float *)(param_1 + 0x368);
  uStack_58 = *(undefined4 *)(param_1 + 0x36c);
  uStack_54 = *(undefined4 *)(param_1 + 0x370);
  uVar16 = CONCAT44(DAT_0018b394,DAT_0018b398);
  local_78 = *(float *)(param_1 + 0x3d0);
  local_74 = *(float *)(param_1 + 0x3d4);
  local_70 = *(float *)(param_1 + 0x3d8);
  local_f0 = *(undefined4 *)(param_1 + 0x3d0);
  local_ec = *(undefined4 *)(param_1 + 0x3d4);
  local_e8 = *(float *)(param_1 + 0x3d8);
  local_80 = *(undefined4 *)(DAT_0018b388 + 0x10);
  uStack_7c = *(undefined4 *)(DAT_0018b388 + 0x14);
  local_88 = DAT_0018b38c;
  local_128 = &local_88;
  local_10c = &local_5c;
  local_12c = &local_f0;
  fVar10 = (float)VectorSignedToFloat(*(undefined4 *)(param_1 + 0x528),(byte)(in_fpscr >> 0x15) & 3)
  ;
  local_100 = DAT_0018b390;
  if ((int)ALBW_AS_U32(fVar10 * DAT_0018b390) < 0x3f800000) {
    local_100 = (DAT_0018b398 + fVar10 * DAT_0018b390 * DAT_0018b394) * DAT_0018b390;
  }
  local_120 = *(undefined4 *)(param_1 + 0x2cc);
  local_118 = DAT_0018b39c;
  local_110 = param_1 + 0x3d0;
  local_84 = param_1;
  func_0014F0B0(param_1);
  iVar7 = func_004A7620(*DAT_0018b3a8,(uint *)&local_12c,0xf);
  if (iVar7 == 0) goto LAB_0018b2c4;
  *(undefined4 *)(param_1 + 0x3d0) = local_f0;
  *(undefined4 *)(param_1 + 0x3d4) = local_ec;
  *(float *)(param_1 + 0x3d8) = local_e8;
  uVar9 = in_fpscr & 0xfffffff;
  in_fpscr = uVar9 | (uint)(local_78 == *(float *)(param_1 + 0x3d0)) << 0x1e;
  if (SUB41(in_fpscr >> 0x1e,0)) {
    in_fpscr = uVar9 | (uint)(local_74 == *(float *)(param_1 + 0x3d4)) << 0x1e;
    bVar8 = false;
    if (SUB41(in_fpscr >> 0x1e,0)) {
      in_fpscr = uVar9 | (uint)(local_70 == local_e8) << 0x1e;
      bVar8 = SUB41(in_fpscr >> 0x1e,0);
    }
    if (!bVar8) goto LAB_0018b220;
    bVar8 = true;
  }
  else {
LAB_0018b220:
    bVar8 = false;
  }
  if (!bVar8) {
    func_00115C70((float *)&local_b8,(float *)(param_1 + 0x3d0),&local_5c);
    fVar10 = *(float *)(param_1 + 0x3dc);
    fVar11 = ALBW_AS_F32(uVar15);
    uVar9 = in_fpscr & 0xfffffff;
    uVar1 = uVar9 | (uint)(fVar10 * ALBW_AS_F32(local_b8) == fVar11) << 0x1e;
    if (fVar10 * ALBW_AS_F32(local_b8) < fVar11 || SUB41(uVar1 >> 0x1e,0)) {
      *(float *)(param_1 + 0x3dc) = fVar11;
      uVar9 = uVar1;
    }
    else {
      puVar12 = local_b8;
      if (ALBW_AS_F32(local_b8) <= fVar11) {
        puVar12 = (undefined1 *)CF_FBITS(-ALBW_AS_F32(local_b8));
      }
      if (fVar10 <= fVar11) {
        fVar10 = -fVar10;
      }
      if (ALBW_AS_F32(puVar12) < fVar10) {
        *(undefined1 **)(param_1 + 0x3dc) = local_b8;
      }
    }
    fVar10 = *(float *)(param_1 + 0x3e4);
    in_fpscr = uVar9 & 0xfffffff | (uint)(fVar10 * local_b0 == fVar11) << 0x1e |
               (uint)(fVar11 <= fVar10 * local_b0) << 0x1d;
    bVar3 = (byte)(in_fpscr >> 0x18);
    if (!(bool)(bVar3 >> 5 & 1) || (bool)(bVar3 >> 6)) {
      *(float *)(param_1 + 0x3e4) = fVar11;
    }
    else {
      fVar13 = local_b0;
      if (local_b0 <= fVar11) {
        fVar13 = -local_b0;
      }
      if (fVar10 <= fVar11) {
        fVar10 = -fVar10;
      }
      in_fpscr = uVar9 & 0xfffffff | (uint)(fVar10 <= fVar13) << 0x1d;
      if (!SUB41(in_fpscr >> 0x1d,0)) {
        *(float *)(param_1 + 0x3e4) = local_b0;
      }
    }
  }
LAB_0018b2c4:
  if (*(char *)(param_1 + 0x4f2) != '\0') {
    func_00115C70((float *)&local_b8,(float *)(param_1 + 0x3d0),&local_78);
    fVar10 = SQRT(ALBW_AS_F32(local_b8) * ALBW_AS_F32(local_b8) + ALBW_AS_F32(local_b4) * ALBW_AS_F32(local_b4) +
                  local_b0 * local_b0);
    if (0x3e000000 < (int)ALBW_AS_U32(fVar10)) {
      fVar11 = ALBW_AS_F32(uVar15);
      uVar9 = in_fpscr & 0xfffffff | (uint)(fVar10 < fVar11) << 0x1f |
              (uint)(fVar10 == fVar11) << 0x1e;
      in_fpscr = uVar9 | (uint)(NAN(fVar10) || NAN(fVar11)) << 0x1c;
      bVar3 = (byte)(uVar9 >> 0x18);
      if (!(bool)(bVar3 >> 6 & 1) && bVar3 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1)) {
        fVar10 = DAT_0018b3ac / fVar10;
        local_b4 = (undefined4 *)CF_FBITS((ALBW_AS_F32(local_b4) * fVar10));
        local_b0 = local_b0 * fVar10;
        local_b8 = (undefined1 *)CF_FBITS((ALBW_AS_F32(local_b8) * fVar10));
      }
      func_00115C54((float *)(param_1 + 0x3d0),&local_78,(float *)&local_b8);
    }
  }
  fVar10 = *(float *)(param_1 + 0x3d4);
  cVar2 = *(char *)(param_1 + 0x53b);
  if ((int)ALBW_AS_U32((*(float *)(param_1 + 0x524) - fVar10)) < DAT_0018b3b0) {
    cVar6 = func_0052107C(param_1);
    piVar5 = DAT_0018b3a8;
    bVar8 = !(bool)cVar6;
    if (bVar8) {
      cVar6 = *(char *)(param_1 + 0x4ee);
    }
    if (bVar8 && cVar6 == '\0') {
      *(undefined1 *)(param_1 + 0x4f1) = 0;
    }
    else {
      local_a8 = extraout_r1 & 0xffff0000 | DAT_0018b37c;
      local_b0 = 0.0;
      uStack_a0 = 0;
      local_94 = ALBW_AS_F32(uVar15);
      local_90 = 0;
      local_8f = 1;
      local_48 = *(undefined4 *)(DAT_0018b388 + 0x18);
      local_44 = *(undefined4 *)(DAT_0018b388 + 0x1c);
      local_50 = uVar4;
      local_b4 = &local_50;
      local_138 = *(undefined4 *)(param_1 + 0x3d0);
      uStack_130 = *(undefined4 *)(param_1 + 0x3d8);
      fVar11 = (float)VectorSignedToFloat(*(undefined4 *)(param_1 + 0x528),
                                          (byte)(in_fpscr >> 0x15) & 3);
      fVar13 = ALBW_AS_F32(((ulonglong)uVar15 >> 0x20));
      fVar11 = fVar11 * fVar13;
      if ((int)ALBW_AS_U32(fVar11) < 0x3f800000) {
        uVar16 = (ulonglong)(uint)ALBW_AS_U32((ALBW_AS_F32(uVar16) + fVar11 * ALBW_AS_F32((uVar16 >> 0x20))));
      }
      if (0x3f7fffff < (int)ALBW_AS_U32(fVar11)) {
        fVar10 = fVar13;
      }
      if ((int)ALBW_AS_U32(fVar11) < 0x3f800000) {
        fVar10 = ALBW_AS_F32(uVar16) * fVar13;
      }
      local_134 = *(float *)(param_1 + 0x3d4) -
                  fVar10 / (*(float *)(DAT_0018b588 + 0x208) +
                           *(float *)(DAT_0018b588 + 0x20c) * local_94);
      local_ac = *(undefined4 *)(param_1 + 0x2cc);
      local_a4 = DAT_0018b39c;
      *(undefined1 *)(param_1 + 0x4f1) = 0;
      local_b8 = (undefined1 *)&local_138;
      local_9c = (undefined1 *)&local_138;
      local_98 = param_1 + 0x3d0;
      local_4c = param_1;
      func_004A8030(*piVar5,(int *)&local_b8,0xf);
      fVar10 = ALBW_AS_F32(((ulonglong)uVar15 >> 0x20));
      if (*(char *)(param_1 + 0x4f1) == '\0') {
        *(undefined4 *)(param_1 + 0x3d0) = local_f0;
        *(undefined4 *)(param_1 + 0x3d4) = local_ec;
        *(float *)(param_1 + 0x3d8) = local_e8;
        *(undefined1 *)(param_1 + 0x4ee) = 0;
        bVar8 = func_0052107C(param_1);
        if (((bVar8) && (*(char *)(param_1 + 0x4ed) == '\0')) &&
           (cVar6 = *(char *)(param_1 + 0x53b) + '\x01', *(char *)(param_1 + 0x53b) = cVar6,
           '\x02' < cVar6)) {
          *(undefined1 *)(param_1 + 0x4f1) = 1;
        }
      }
      else {
        if (*(char *)(param_1 + 0x4f2) != '\0') {
          *(undefined4 *)(param_1 + 0x3d0) = local_f0;
          *(undefined4 *)(param_1 + 0x3d4) = local_ec;
          *(float *)(param_1 + 0x3d8) = local_e8;
        }
        iVar7 = func_00520EE4(param_1);
        if ((iVar7 == 0) && (*(float *)(param_1 + 0x3d4) - fVar10 < local_134)) {
          *(float *)(param_1 + 0x3d4) = local_134 + fVar10;
        }
      }
    }
  }
  else {
    func_00393164((int *)(param_1 + 0x510));
    *(undefined1 *)(param_1 + 0x4ed) = 1;
  }
  if (*(char *)(param_1 + 0x53b) == cVar2) {
    *(undefined1 *)(param_1 + 0x53b) = 0;
  }
  return;
}

