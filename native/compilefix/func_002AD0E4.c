/* compilefix: USA 002AD0E4 (EU 002AD0C0), the converted stage-2 text.
 * Fixed (BOOT_LOG 184): the ARM copies this word between a float and an integer (no vcvt), which the
 * converted text wrote as a conversion of the value. */
#include "ghidra_types.h"

extern int func_00100174(int *param_1);
extern int func_00115C54(float *param_1,float *param_2,float *param_3);
extern int func_00115D88(float *param_1,float *param_2,float fparam_0);
extern float func_00115DC8(float *param_1);
extern int func_002AB248(undefined4 *param_1,float *param_2,undefined1 param_3);
extern int func_00392E48(undefined4 *param_1,int param_2,undefined4 *param_3,undefined1 param_4);
extern int func_004D80A4(float *param_1,uint param_2,float fparam_0);
extern int func_004F5494(undefined4 *param_1);
extern int func_004F5520(undefined4 *param_1);
extern int func_006624F4(undefined4 *param_1,undefined1 param_2);
extern float DAT_002ad45c;
extern uint *DAT_002ad460;
extern undefined4 *DAT_002ad464;
extern undefined4 DAT_002ad468;
extern undefined4 DAT_002ad46c;
extern undefined4 DAT_002ad470;
extern undefined4 DAT_002ad474;
extern int DAT_002ad478;
extern float DAT_002ad47c;
extern float DAT_002ad480;
extern float *DAT_002ad484;

// USA 002AD0E4 <- EU 002AD0C0 (Ghidra, non-matching)
// PARAM param_5 Stack[0x0]:4 int
// GLOBAL DAT_002ad45c float
// GLOBAL DAT_002ad460 uint *
// GLOBAL DAT_002ad464 undefined4 *
// GLOBAL DAT_002ad468 undefined4
// GLOBAL DAT_002ad46c undefined4
// GLOBAL DAT_002ad470 undefined4
// GLOBAL DAT_002ad474 undefined4
// GLOBAL DAT_002ad478 int
// GLOBAL DAT_002ad47c float
// GLOBAL DAT_002ad480 float
// GLOBAL DAT_002ad484 float *

undefined4
func_002AD0E4(undefined4 *param_1,int param_2,float *param_3,undefined1 param_4,int param_5)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  byte bVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int extraout_r1;
  int extraout_r1_00;
  undefined1 uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  bool bVar13;
  uint in_fpscr;
  float fparam_0;
  float fVar14;
  longlong lVar15;
  float fVar16;
  undefined4 uVar17;
  ulonglong uVar18;
  _Alignas(8) unsigned char albw_frame[0xb0];
  #define local_a4 (*(float *)(albw_frame + 0xc))
  #define local_a0 (*(float *)(albw_frame + 0x10))
  #define local_9c (*(float *)(albw_frame + 0x14))
  #define local_98 (*(float *)(albw_frame + 0x18))
  #define local_94 (*(float *)(albw_frame + 0x1c))
  #define local_90 (*(float *)(albw_frame + 0x20))
  #define local_8c (*(float *)(albw_frame + 0x24))
  #define local_88 (*(float *)(albw_frame + 0x28))
  #define local_84 (*(float *)(albw_frame + 0x2c))
  #define local_80 (*(float *)(albw_frame + 0x30))
  #define fStack_7c (*(float *)(albw_frame + 0x34))
  #define local_78 (*(float *)(albw_frame + 0x38))
  #define local_64 (*(int *)(albw_frame + 0x4c))
  #define local_60 (*(int *)(albw_frame + 0x50))
  #define local_5c (*(float *)(albw_frame + 0x54))
  #define uStack_58 (*(undefined4 *)(albw_frame + 0x58))
  #define uStack_54 (*(undefined4 *)(albw_frame + 0x5c))
  #define local_50 (*(float *)(albw_frame + 0x60))
  #define uStack_4c (*(undefined4 *)(albw_frame + 0x64))
  #define uStack_48 (*(undefined4 *)(albw_frame + 0x68))
  #define local_44 (*(int *)(albw_frame + 0x6c))
  #define local_3c ((float *)(albw_frame + 0x74))
  if (*(byte *)(param_1 + 1) - 0x15 < 8) {
    return 0;
  }
  if (*(char *)(param_1[0xd] + 0x7fc) != '\0' && *(char *)(param_1[0xd] + 0x7fc) != '\x05') {
    return 0;
  }
  lVar15 = (ulonglong)(uint)ALBW_AS_U32(DAT_002ad45c) << 0x20;
  local_3c[0] = DAT_002ad45c;
  if (param_3 == (float *)0x0) {
    iVar6 = param_1[0xd];
    local_84 = *(float *)(iVar6 + 0x3d8);
    local_8c = *(float *)(iVar6 + 0x3d0);
    local_88 = *(float *)(iVar6 + 0x3d4);
  }
  else {
    local_8c = *param_3;
    local_88 = param_3[1];
    local_84 = param_3[2];
  }
  uVar5 = func_002AB248(&local_8c,local_3c,param_4);
  puVar2 = DAT_002ad464;
  fVar16 = ALBW_AS_F32(((ulonglong)lVar15 >> 0x20));
  if (uVar5 == 4) {
    return 0;
  }
  local_60 = extraout_r1;
  if (param_5 != 0) {
    if (((*DAT_002ad460 & 1) == 0) &&
       (iVar6 = func_00100174((int *)DAT_002ad460), uVar3 = DAT_002ad46c, iVar6 != 0)) {
      *puVar2 = DAT_002ad468;
      uVar17 = (undefined4)((ulonglong)lVar15 >> 0x20);
      puVar2[1] = uVar17;
      puVar2[2] = uVar3;
      uVar3 = DAT_002ad474;
      puVar2[3] = DAT_002ad470;
      puVar2[4] = uVar17;
      puVar2[5] = uVar3;
    }
    uVar10 = 0;
    do {
      func_00115C54(&local_80,&local_8c,(float *)(puVar2 + uVar10 * 3));
      local_a0 = local_80;
      local_9c = fStack_7c;
      local_98 = local_78;
      local_94 = ALBW_AS_F32(((ulonglong)lVar15 >> 0x20));
      uVar7 = func_00392E48(&local_a0,0,&local_94,param_4);
      fVar16 = ALBW_AS_F32(((ulonglong)lVar15 >> 0x20));
      if (4 < uVar7) {
        uVar7 = 4;
      }
      if (uVar7 != uVar5) {
        return 0;
      }
      uVar10 = uVar10 + 1;
      local_60 = extraout_r1_00;
    } while (uVar10 < 2);
  }
  if (uVar5 == 1) {
    local_64 = 1;
LAB_002ad244:
    if (uVar5 == 3) {
      local_60 = 1;
    }
    local_44 = 0;
    if (uVar5 == 3) goto LAB_002ad25c;
  }
  else {
    local_64 = 0;
    if (uVar5 != 2) goto LAB_002ad244;
    local_44 = 1;
  }
  local_60 = 0;
LAB_002ad25c:
  iVar6 = param_1[0xd];
  if ((*(short *)(DAT_002ad478 + iVar6) < 1) && (*(char *)(iVar6 + 0x7fc) != '\x05')) {
    *(undefined1 *)(iVar6 + 0x4dc) = 9;
    func_004F5494(param_1 + 0x3b);
    func_006624F4(param_1,0);
  }
  else {
    uVar18 = (ulonglong)(uint)ALBW_AS_U32(*(float *)(iVar6 + 0x4c4));
    fVar14 = DAT_002ad47c;
    if (local_64 == 0) {
      fVar14 = DAT_002ad480;
    }
    local_80 = *DAT_002ad484;
    fStack_7c = DAT_002ad484[1];
    local_78 = DAT_002ad484[2];
    fVar14 = *(float *)(iVar6 + 0x4c4) * fVar14;
    iVar6 = 0;
    if (local_64 != 0) {
      uVar10 = 8;
      iVar12 = 0x20000000;
    }
    else {
      uVar10 = 4;
      iVar12 = 0x40000000;
    }
    uVar7 = 0;
    uVar11 = 0;
    if (uVar10 != 0) {
      do {
        func_004D80A4(&local_9c,uVar7,ALBW_AS_F32(uVar18));
        local_98 = fVar16;
        func_00115C54(&local_50,&local_8c,&local_9c);
        local_5c = local_50;
        uStack_58 = uStack_4c;
        uStack_54 = uStack_48;
        local_a0 = fVar16;
        uVar8 = func_00392E48(&local_5c,0,&local_a0,0);
        if (4 < uVar8) {
          uVar8 = 4;
        }
        if (uVar8 == uVar5) {
          iVar6 = iVar6 + 1;
          local_80 = local_80 + local_9c;
          local_78 = local_78 + local_94;
        }
        uVar11 = uVar11 + 1;
        uVar7 = uVar7 + iVar12;
      } while (uVar11 < uVar10);
      if (iVar6 != 0) {
        fparam_0 = (float)VectorUnsignedToFloat(iVar6,(byte)(in_fpscr >> 0x15) & 3);
        func_00115D88(&local_98,&local_80,fparam_0);
        local_a4 = local_98;
        local_9c = local_90;
        local_a0 = fVar16;
        func_00115DC8(&local_a4);
        local_a4 = local_a4 * fVar14;
        local_9c = local_9c * fVar14;
        local_8c = local_8c + local_a4;
        local_84 = local_84 + local_9c;
      }
    }
    param_1[0x70] = ALBW_AS_U32(local_3c[0]);
    param_1[0x6d] = ALBW_AS_U32(local_8c);
    param_1[0x6e] = ALBW_AS_U32(local_88);
    param_1[0x6f] = ALBW_AS_U32(local_84);
    if (local_64 == 0) {
      if (local_60 == 0) {
        if (local_44 == 0) {
          if (param_2 == 0) {
            uVar9 = 0x16;
          }
          else {
            uVar9 = 0x15;
          }
        }
        else if (param_2 == 0) {
          uVar9 = 0x1a;
        }
        else {
          uVar9 = 0x19;
        }
      }
      else if (param_2 == 0) {
        uVar9 = 0x1c;
      }
      else {
        uVar9 = 0x1b;
      }
    }
    else if (param_2 == 0) {
      uVar9 = 0x18;
    }
    else {
      uVar9 = 0x17;
    }
    cVar1 = *(char *)(param_1[0xd] + 0x7fc);
    bVar13 = cVar1 == '\x05';
    if (bVar13) {
      cVar1 = *(char *)(param_1 + 1);
    }
    if (bVar13 && cVar1 == '\0') {
      func_004F5520(&local_80);
      bVar4 = (**(code **)(*(int *)param_1[0xd] + 0x5c))((int *)param_1[0xd],uVar9,&local_80);
      if (7 < bVar4 - 0x15) {
        return 0;
      }
      func_006624F4(param_1,bVar4);
      return 1;
    }
    func_006624F4(param_1,uVar9);
  }
  return 1;
}

