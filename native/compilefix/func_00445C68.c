/* compilefix: USA 00445C68 (EU 00445C40), the converted stage-2 text.
 * Fixed (BOOT_LOG 184): the ARM compares the float's bits (vmov rX, sY; cmp), which the converted text
 * wrote as a conversion of the value to an integer. */
#include "ghidra_types.h"

extern int func_00232384(int param_1);
extern int func_002C0AB4(int param_1,float fparam_0);
extern int func_002C0AEC(int param_1);
extern int func_002C0B34(int param_1);
extern int func_002C0CF4(int param_1,float *param_2,int param_3);
extern int func_004562C8(int param_1,float fparam_0,float fparam_1,float fparam_2,float fparam_3);
extern int *DAT_00445e8c;
extern float DAT_00445e90;
extern float DAT_00445e94;
extern float DAT_00445e98;
extern float DAT_00445e9c;
extern float DAT_00445ea0;
extern float DAT_00445ea4;
extern int DAT_00445ea8;
extern float DAT_00445eac;
extern float DAT_00445eb0;

// USA 00445C68 <- EU 00445C40 (Ghidra, non-matching)
// GLOBAL DAT_00445e8c int *
// GLOBAL DAT_00445e90 float
// GLOBAL DAT_00445e94 float
// GLOBAL DAT_00445e98 float
// GLOBAL DAT_00445e9c float
// GLOBAL DAT_00445ea0 float
// GLOBAL DAT_00445ea4 float
// GLOBAL DAT_00445ea8 int
// GLOBAL DAT_00445eac float
// GLOBAL DAT_00445eb0 float

void func_00445C68(int param_1)

{
  uint uVar1;
  char cVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  float *pfVar8;
  uint uVar9;
  float fVar10;
  uint in_fpscr;
  uint uVar11;
  float in_s0;
  float fVar12;
  float in_s1;
  float in_s2;
  float in_s3;
  float fVar13;
  float fVar14;
  undefined8 uVar15;
  float fparam_0;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fparam_0_00;
  float fVar20;
  float fVar21;
  _Alignas(8) unsigned char albw_frame[0x60];
  #define local_60 (*(float *)(albw_frame + 0x0))
  #define local_5c (*(float *)(albw_frame + 0x4))
  func_00232384(param_1);
  uVar9 = 0;
  do {
    if (uVar9 < *(uint *)(param_1 + 0x1ac)) {
      iVar5 = *(int *)(*(int *)(param_1 + 0x1b4) + uVar9 * 4);
    }
    else {
      iVar5 = 0;
    }
    func_004562C8(iVar5,in_s0,in_s1,in_s2,in_s3);
    uVar9 = uVar9 + 1;
  } while ((int)uVar9 < 0x14);
  iVar5 = *(int *)(*(int *)(*DAT_00445e8c + 0x80) + 0x15c);
  if ((iVar5 != 0) && (*(char *)(param_1 + 0x295) != '\0')) {
    func_002C0AEC(iVar5);
    iVar4 = DAT_00445ea8;
    fVar3 = DAT_00445ea0;
    iVar6 = *(int *)(param_1 + 0x21c);
    fVar14 = *(float *)(iVar6 + 0x20);
    fVar13 = -*(float *)(iVar6 + 0x1c);
    uVar15 = *(undefined8 *)(iVar6 + 0x34);
    uVar9 = 0;
    fVar20 = ALBW_AS_F32(uVar15) - DAT_00445e94;
    local_60 = DAT_00445e90;
    local_5c = DAT_00445e90;
    iVar6 = DAT_00445ea8 + 0x3e0000;
    fVar10 = ALBW_AS_F32(((int)ALBW_AS_U32(DAT_00445ea0) - 0x3e0000));
    fparam_0 = DAT_00445e90;
    fVar16 = DAT_00445e9c;
    fVar17 = DAT_00445e98;
    fVar18 = DAT_00445ea4;
    fVar19 = DAT_00445eac;
    fparam_0_00 = DAT_00445e94;
    fVar21 = DAT_00445eb0;
    do {
      iVar7 = param_1 + 0x298;
      if (uVar9 < 0x1e) {
        iVar7 = param_1 + 0x298 + uVar9 * 0xc;
      }
      if (*(char *)(iVar7 + 8) != '\0') {
        pfVar8 = (float *)(param_1 + 0x298);
        if (uVar9 < 0x1e) {
          pfVar8 = (float *)(param_1 + 0x298 + uVar9 * 0xc);
        }
        iVar7 = param_1 + 0x298;
        fVar12 = fVar17 * *pfVar8 * ALBW_AS_F32(uVar15) - fVar13;
        uVar1 = in_fpscr & 0xfffffff | (uint)(fVar12 < fparam_0) << 0x1f;
        uVar11 = uVar1 | (uint)(NAN(fVar12) || NAN(fparam_0)) << 0x1c;
        if ((byte)(uVar1 >> 0x1f) == ((byte)(uVar11 >> 0x1c) & 1)) {
          fVar12 = fVar12 + fVar16;
        }
        else {
          fVar12 = fVar12 - fVar16;
        }
        if (uVar9 < 0x1e) {
          iVar7 = iVar7 + uVar9 * 0xc;
        }
        local_60 = (float)VectorSignedToFloat((int)fVar12,(byte)(uVar11 >> 0x15) & 3);
        fVar12 = fVar14 - fVar17 * *(float *)(iVar7 + 4) * ALBW_AS_F32(((ulonglong)uVar15 >> 0x20));
        uVar1 = in_fpscr & 0xfffffff | (uint)(fVar12 < fparam_0) << 0x1f;
        in_fpscr = uVar1 | (uint)(NAN(fVar12) || NAN(fparam_0)) << 0x1c;
        if ((byte)(uVar1 >> 0x1f) == ((byte)(in_fpscr >> 0x1c) & 1)) {
          fVar12 = fVar12 + fVar16;
        }
        else {
          fVar12 = fVar12 - fVar16;
        }
        local_5c = (float)VectorSignedToFloat((int)fVar12,(byte)(in_fpscr >> 0x15) & 3);
        if (((((uint)ALBW_AS_U32(local_60 + fVar18) < (uint)ALBW_AS_U32(fVar3)) && ((int)ALBW_AS_U32(local_60 + fVar18) < iVar4)) &&
            ((int)ALBW_AS_U32(local_5c + fVar19) < iVar6)) && ((uint)ALBW_AS_U32(local_5c + fVar19) < (uint)ALBW_AS_U32(fVar10))) {
          cVar2 = *(char *)(param_1 + 0x15c);
          if (cVar2 == '\x01' || cVar2 == '\x03') {
            func_002C0CF4(iVar5,&local_60,1);
            func_002C0CF4(iVar5,&local_60,0);
            func_002C0AB4(iVar5,fVar20 / fVar21);
          }
          else if (cVar2 == '\x02') {
            func_002C0CF4(iVar5,&local_60,1);
            func_002C0AB4(iVar5,fparam_0);
          }
          else {
            func_002C0CF4(iVar5,&local_60,0);
            func_002C0AB4(iVar5,fparam_0_00);
          }
        }
      }
      uVar9 = uVar9 + 1;
    } while ((int)uVar9 < 0x1e);
    func_002C0B34(iVar5);
    *(undefined1 *)(param_1 + 0x295) = 0;
  }
  return;
}

