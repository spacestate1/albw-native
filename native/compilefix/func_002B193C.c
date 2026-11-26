/* compilefix: USA 002B193C, the converted stage-2 text with y and z of the hit direction
 * (a vector returned in s0..s2 on ARM: BOOT_LOG 178). */
#include "ghidra_types.h"

extern int func_00115C70(float *param_1,float *param_2,float *param_3);
extern int func_00115D70(float *param_1,float *param_2,float fparam_0);
extern float func_00115DC8(float *param_1);
extern int func_002AB2D8(ushort *param_1,int param_2);
extern int func_002ABEC8(int *param_1,int param_2);
extern int func_002ADFE4(int param_1,int param_2,undefined1 param_3,undefined4 param_4,int param_5);
extern int func_002AE780(int param_1);
extern int func_004904CC(float fparam_0,float fparam_1);
extern int func_004905E0(float fparam_0);
extern float func_004F944C(void);
extern int func_004F9728(int *param_1,undefined4 param_2,int param_3);
extern int func_004FABDC(int param_1,undefined4 param_2,uint param_3,int param_4);
extern float func_004FB2F0(int param_1,float fparam_0);
extern float func_004FBF58(int *param_1);
extern float func_0058AA40(int param_1);
extern undefined8 func_0058AB74(int param_1);
extern float fRam002b1d4c;
extern float DAT_002b1d50;
extern float DAT_002b1d54;
extern undefined4 DAT_002b1d58;
extern undefined4 DAT_002b1d5c;
extern int DAT_002b1d60;
extern float DAT_002b1d64;
extern int DAT_002b1d68;
extern float DAT_002b1d6c;
extern undefined4 DAT_002b1d70;
extern int DAT_002b1d74;

float *albw_s012_get(void);   /* s0..s2 of a returned vector (native/runtime/vec3ret.c) */

// USA 002B193C <- EU 002B1918 (Ghidra, non-matching)
// GLOBAL DAT_002b1d50 float
// GLOBAL DAT_002b1d54 float
// GLOBAL DAT_002b1d58 undefined4
// GLOBAL DAT_002b1d5c undefined4
// GLOBAL DAT_002b1d60 int
// GLOBAL DAT_002b1d64 float
// GLOBAL DAT_002b1d68 int
// GLOBAL DAT_002b1d6c float
// GLOBAL DAT_002b1d70 undefined4
// GLOBAL DAT_002b1d74 int
// GLOBAL EXT_00000008 undefined
// GLOBAL UNK_002b1d4c float

void func_002B193C(int param_1,int param_2,float fparam_0)

{
  char cVar1;
  byte bVar2;
  undefined4 uVar3;
  int *piVar4;
  float *pfVar5;
  uint uVar6;
  int iVar7;
  ushort uVar8;
  uint uVar9;
  int iVar10;
  bool bVar11;
  bool bVar12;
  bool bVar13;
  uint in_fpscr;
  uint uVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  undefined8 uVar19;
  float fVar20;
  undefined8 uVar21;
  undefined8 uVar22;
  _Alignas(8) unsigned char albw_frame[0x70];
  #define local_64 (*(uint *)(albw_frame + 0xc))
  #define local_60 (*(float *)(albw_frame + 0x10))
  #define local_5c (*(float *)(albw_frame + 0x14))
  #define local_58 (*(float *)(albw_frame + 0x18))
  #define local_54 (*(float *)(albw_frame + 0x1c))
  #define fStack_50 (*(float *)(albw_frame + 0x20))
  #define local_48 ((float *)(albw_frame + 0x28))
  #define local_40 (*(float *)(albw_frame + 0x30))
  fVar18 = fparam_0;
  func_002AE780(param_1);
  piVar4 = *(int **)(param_1 + 0x34);
  if (((char)piVar4[0x1ff] == '\x05') || ((char)piVar4[0x212] != '\0')) {
    bVar11 = true;
LAB_002b1954:
    bVar12 = false;
    if (param_2 == 0x14 || param_2 == 0x1e) goto LAB_002b1ad4;
    bVar13 = false;
  }
  else {
    bVar11 = false;
    if (param_2 != 0x14) goto LAB_002b1954;
    bVar12 = true;
LAB_002b1ad4:
    bVar13 = true;
  }
  local_64 = (uint)*(byte *)(param_1 + 0x247);
  (**(code **)(*piVar4 + 0x68))(piVar4,param_2,param_1 + 0xec);
  fStack_50 = *(float *)(param_1 + 0x24c);
  if (local_64 == 0) {
    local_64 = 1;
  }
  *(ushort *)(param_1 + 0x38) = *(ushort *)(param_1 + 0x38) | 1;
  fVar18 = fparam_0 * fVar18 * fStack_50;
  if (bVar13) {
    fVar18 = fRam002b1d4c;
  }
  *(uint *)(*(int *)(param_1 + 0x34) + 0x5a0) =
       *(uint *)(*(int *)(param_1 + 0x34) + 0x5a0) & 0xfffffffe;
  *(ushort *)(param_1 + 0x38) = *(ushort *)(param_1 + 0x38) & 0xfff7;
  local_54 = func_004FBF58(*(int **)(param_1 + 0x34));
  fStack_50 = albw_s012_get()[1];
  *(float *)(albw_frame + 0x24) = albw_s012_get()[2];
  func_00115D70((float *)(param_1 + 0x3c),&local_54,fVar18);
  fVar15 = DAT_002b1d50;
  if (!bVar13) {
    fVar15 = *(float *)(param_1 + 0x250);
  }
  fVar20 = DAT_002b1d50;
  pfVar5 = func_00115D70((float *)(param_1 + 0x20c),&local_54,fVar15);
  if (bVar13) {
    if (!bVar11) {
      pfVar5 = (float *)(uint)*(byte *)(param_1 + 0x110);
    }
    if (!bVar11 && pfVar5 == (float *)&SupervisorCall) {
      local_64 = 0;
      *(float *)(param_1 + 0x44) = fVar20;
      *(float *)(param_1 + 0x3c) = fVar20;
    }
    else {
      local_64 = 6;
    }
  }
  fVar15 = DAT_002b1d54;
  *(uint *)(param_1 + 0x1f8) = local_64;
  if (local_64 == 0) {
    *(float *)(param_1 + 0x1fc) = fVar20;
  }
  else {
    fVar16 = (float)VectorUnsignedToFloat(local_64,(byte)(in_fpscr >> 0x15) & 3);
    *(float *)(param_1 + 0x1fc) = fVar15 / fVar16;
  }
  *(undefined4 *)(param_1 + 500) = 0;
  uVar6 = (uint)*(byte *)(param_1 + 0x248);
  *(uint *)(param_1 + 0x204) = uVar6;
  if (uVar6 == 0) {
    *(float *)(param_1 + 0x208) = fVar20;
  }
  else {
    fVar16 = (float)VectorUnsignedToFloat(uVar6,(byte)(in_fpscr >> 0x15) & 3);
    *(float *)(param_1 + 0x208) = fVar15 / fVar16;
  }
  *(undefined4 *)(param_1 + 0x200) = 0;
  cVar1 = *(char *)(*(int *)(param_1 + 0x34) + 0x7fc);
  if ((cVar1 == '\0' || cVar1 == '\x05') || cVar1 == '\x01') {
    fVar16 = func_004F944C();
    *(float *)(param_1 + 0x40) = fVar16;
  }
  *(undefined1 *)(*(int *)(param_1 + 0x34) + 0x655) = *(undefined1 *)(param_1 + 0x249);
  func_002ABEC8(*(int **)(param_1 + 0x34),param_1 + 0xec);
  uVar3 = DAT_002b1d58;
  *(undefined4 *)(param_1 + 0x220) = 0x14;
  *(undefined4 *)(param_1 + 0x224) = uVar3;
  *(undefined4 *)(param_1 + 0x21c) = 0;
  *(undefined1 *)(param_1 + 0x228) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 1;
  *(float *)(param_1 + 0x30) = fVar15;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x54) = DAT_002b1d5c;
  iVar7 = *(int *)(*(int *)(param_1 + 0x34) + 0x40c);
  fVar17 = *(float *)(iVar7 + 0xf8);
  uVar19 = CONCAT44(*(undefined4 *)(iVar7 + 0xe0),*(undefined4 *)(iVar7 + 0xec));
  uVar6 = in_fpscr & 0xfffffff | (uint)(fVar17 < fVar20) << 0x1f | (uint)(fVar17 == fVar20) << 0x1e;
  uVar14 = uVar6 | (uint)(NAN(fVar17) || NAN(fVar20)) << 0x1c;
  bVar2 = (byte)(uVar6 >> 0x18);
  fVar16 = fVar17;
  if ((bool)(bVar2 >> 6 & 1) || bVar2 >> 7 != ((byte)(uVar14 >> 0x1c) & 1)) {
    fVar16 = -fVar17;
  }
  if ((int)ALBW_AS_U32((fVar15 - fVar16)) < 0x34000000) {
    iVar10 = 0;
    fVar16 = -*(float *)(iVar7 + 0xe4);
    fVar17 = -(fVar17 * *(float *)(iVar7 + 0xe8));
  }
  else {
    iVar10 = func_004904CC(*(float *)(iVar7 + 0xfc),*(float *)(iVar7 + 0x100));
    fVar17 = -fVar17;
    uVar14 = uVar14 & 0xfffffff | (uint)(fVar20 == fVar17) << 0x1e |
             (uint)(fVar17 <= fVar20) << 0x1d;
    bVar2 = (byte)(uVar14 >> 0x18);
    if ((bool)(bVar2 >> 5 & 1) && !(bool)(bVar2 >> 6)) {
      if ((uint)ALBW_AS_U32(DAT_002b1d64) < (uint)ALBW_AS_U32(fVar17)) {
        fVar17 = -SQRT(fVar15 - fVar17 * fVar17) / fVar17;
      }
      else {
        fVar17 = -fVar17 / SQRT(fVar15 - fVar17 * fVar17);
      }
      func_004905E0(fVar17);
    }
    else {
      fVar16 = SQRT(fVar15 - fVar17 * fVar17);
      if (DAT_002b1d60 < (int)ALBW_AS_U32(fVar17)) {
        func_004905E0(fVar16 / fVar17);
      }
      else {
        func_004905E0(fVar17 / fVar16);
      }
    }
    fVar17 = ALBW_AS_F32(((ulonglong)uVar19 >> 0x20));
    fVar16 = ALBW_AS_F32(uVar19);
  }
  func_004904CC(fVar16,fVar17);
  *(int *)(param_1 + 0x54) = iVar10;
  *(float *)(param_1 + 0x238) = fVar20;
  *(float *)(param_1 + 0x23c) = fVar20;
  *(float *)(param_1 + 0x240) = fVar20;
  if (bVar12) {
    func_00115C70(local_48,(float *)(param_1 + 0x124),(float *)(*(int *)(param_1 + 0x34) + 0x3d0));
    local_60 = local_48[0];
    local_58 = local_40;
    local_5c = fVar20;
    if (DAT_002b1d68 < (int)ALBW_AS_U32(SQRT(local_48[0] * local_48[0] + local_40 * local_40))) {
      func_00115DC8(&local_60);
      func_00115D70(&local_60,&local_60,DAT_002b1d6c);
    }
    *(float *)(param_1 + 0x238) = local_60;
    *(float *)(param_1 + 0x23c) = local_5c;
    *(float *)(param_1 + 0x240) = local_58;
    uVar6 = *(uint *)(*(int *)(param_1 + 0x34) + 0x59c);
    *(uint *)(*(int *)(param_1 + 0x34) + 0x59c) = uVar6 & 0xfffffffb;
    *(uint *)(*(int *)(param_1 + 0x34) + 0x59c) = uVar6 & 0xfffffff3;
  }
  uVar3 = DAT_002b1d70;
  *(undefined4 *)(param_1 + 0x230) = 4;
  *(undefined4 *)(param_1 + 0x234) = uVar3;
  *(undefined4 *)(param_1 + 0x22c) = 0;
  uVar21 = func_0058AB74(*(int *)(param_1 + 0x34));
  fVar16 = func_0058AA40(*(undefined4 *)(param_1 + 0x34));
  uVar19 = CONCAT44(fVar16,fVar18);
  if (bVar12) {
    iVar7 = (int)*(char *)(DAT_002b1d74 + *(int *)(param_1 + 0x34));
    if (-1 < iVar7) {
      func_004FABDC(*(int *)(param_1 + 0x34),iVar7,0,1);
    }
  }
  if (!(bool)(bVar13 ^ 1U)) {
    *(uint *)(*(int *)(param_1 + 0x34) + 0x5a0) =
         *(uint *)(*(int *)(param_1 + 0x34) + 0x5a0) | 0x800;
  }
  *(undefined1 *)(*(int *)(param_1 + 0x34) + 0x82a) = 0;
  func_002ADFE4(param_1,param_2,*(undefined1 *)(param_1 + 0x110),(int)*(char *)(param_1 + 0x111),0);
  uVar6 = *(uint *)(*(int *)(param_1 + 0x34) + 0x5a0) & 0xfffff7ff;
  *(uint *)(*(int *)(param_1 + 0x34) + 0x5a0) = uVar6;
  uVar9 = (uint)*(byte *)(*(int **)(param_1 + 0x34) + 0x225);
  if (uVar9 == 4) {
    uVar6 = (uint)*(byte *)(param_1 + 0x110);
  }
  if (uVar9 == 4 && uVar6 == 8) {
    func_004F9728(*(int **)(param_1 + 0x34),6,uVar9);
  }
  uVar22 = func_0058AB74(*(int *)(param_1 + 0x34));
  fVar18 = func_0058AA40(*(undefined4 *)(param_1 + 0x34));
  func_004FB2F0(*(int *)(param_1 + 0x34),fVar18);
  if (bVar12) {
    *(ushort *)(param_1 + 0x38) = *(ushort *)(param_1 + 0x38) & 0xffdf;
  }
  else {
    if ((*(ushort *)(param_1 + 0x38) & 0x20) == 0) {
      iVar7 = func_002AB2D8((ushort *)(param_1 + 0x254),(int)*(char *)(param_1 + 0x110));
      if ((iVar7 == 0) || (uVar6 = (uint)*(byte *)(param_1 + 0x248), uVar6 == 0)) goto LAB_002b1ee0;
      if (local_64 < uVar6) {
        uVar6 = local_64;
      }
      *(uint *)(param_1 + 0x204) = uVar6;
      if (uVar6 == 0) {
        *(float *)(param_1 + 0x208) = fVar20;
      }
      else {
        fVar16 = (float)VectorUnsignedToFloat(uVar6,(byte)(uVar14 >> 0x15) & 3);
        *(float *)(param_1 + 0x208) = fVar15 / fVar16;
      }
      *(undefined4 *)(param_1 + 0x200) = 0;
      uVar8 = *(ushort *)(param_1 + 0x38) | 0x20;
    }
    else {
      uVar6 = (uint)*(byte *)(param_1 + 0x248);
      if (local_64 < *(byte *)(param_1 + 0x248)) {
        uVar6 = local_64;
      }
      if (uVar6 != 0) {
        if (local_64 < uVar6) {
          uVar6 = local_64;
        }
        *(uint *)(param_1 + 0x204) = uVar6;
        if (uVar6 == 0) {
          *(float *)(param_1 + 0x208) = fVar20;
        }
        else {
          fVar16 = (float)VectorUnsignedToFloat(uVar6,(byte)(uVar14 >> 0x15) & 3);
          *(float *)(param_1 + 0x208) = fVar15 / fVar16;
        }
        *(undefined4 *)(param_1 + 0x200) = 0;
        goto LAB_002b1ee0;
      }
      uVar8 = *(ushort *)(param_1 + 0x38) & 0xffdf;
    }
    *(ushort *)(param_1 + 0x38) = uVar8;
  }
LAB_002b1ee0:
  if (ALBW_AS_F32(uVar19) == fVar20) {
    *(ushort *)(param_1 + 0x38) = *(ushort *)(param_1 + 0x38) & 0xffdf;
  }
  else {
    iVar7 = func_004904CC(-*(float *)(param_1 + 0x3c),-*(float *)(param_1 + 0x44));
    *(int *)(param_1 + 0x218) = iVar7;
    if (*(char *)(param_1 + 0x24a) != '\0') {
      *(int *)(param_1 + 0x218) = iVar7 + -0x80000000;
    }
  }
  if ((bool)(bVar13 ^ 1U)) {
    *(undefined1 *)(param_1 + 0x244) = 0xff;
    iVar7 = *(int *)(param_1 + 0x34);
    bVar12 = *(char *)(iVar7 + 0x82a) == '\0';
    bVar13 = (int)uVar21 == (int)uVar22;
    bVar11 = bVar12 && bVar13;
    if (bVar12 && bVar13) {
      bVar11 = ALBW_AS_F32(((ulonglong)uVar19 >> 0x20)) == fVar18;
    }
    if (((bVar11) ||
        (*(char *)(param_1 + 0x244) = (char)uVar22, (*(uint *)(iVar7 + 0x59c) & 0x40000000) == 0))
       && (-1 < *(char *)(param_1 + 0x245))) {
      *(undefined1 *)(param_1 + 0x244) = 0xff;
      func_004FABDC(iVar7,(int)*(char *)(param_1 + 0x245),0xffffffff,0);
    }
  }
  return;
}

