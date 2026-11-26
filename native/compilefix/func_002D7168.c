/* compilefix: USA 002D7168, the linked Ghidra text (ghidra_analyzed5_v4) with a lost stack store restored: the sound
 * name object {vtable, char *} was built with the vtable only (strlen of leftover stack data: BOOT_LOG 167).
 * The string "SE_PL_EVENT_SWORD_UP_AFTER_TRIFORCE" is the one the ARM code stores next to the vtable.
 * Also restored: three 3-float copies whose middle word (the height) was dropped (BOOT_LOG 177). */
#include "ghidra_types.h"

extern int func_00100174(int *param_1);
extern int func_00115C54(float *param_1,float *param_2,float *param_3);
extern int func_00115C70(float *param_1,float *param_2,float *param_3);
extern int func_00115D70(float *param_1,float *param_2,float fparam_0);
extern int func_0019C330(int param_1);
extern int func_001DC3C4(int param_1,undefined4 param_2,int param_3);
extern int func_001DC844(int param_1,int param_2);
extern int func_001DE2B0(int param_1,int param_2);
extern int func_001DE330(int param_1,int param_2);
extern int func_0028C8EC(int param_1,undefined4 param_2,undefined4 param_3,int *param_4);
extern undefined4 func_0028D580(uint *param_1,int param_2,undefined1 param_3,undefined1 param_4,uint param_5);
extern int func_002904EC(int param_1);
extern int func_002919DC(int param_1);
extern int func_00297298(int param_1,int param_2);
extern int func_002FD11C(int *param_1,int param_2);
extern int func_003879AC(int param_1,float *param_2);
extern int func_004A1B9C(int *param_1,int param_2,uint *param_3);
extern int func_004EA104(int param_1,int *param_2,int param_3);
extern int func_004EB178(int param_1);
extern int func_0052FBA0(int param_1,uint param_2);
extern float func_0053EE20(int param_1);
extern float func_005469FC(int param_1,int param_2);
extern int func_00581B9C(int param_1);
extern int func_00582250(int param_1);
extern int func_00587F74(int param_1,int *param_2,int param_3);
extern int func_0068C690(float *param_1);
extern undefined DAT_002d74d4;
extern float DAT_002d74f0;
extern int *DAT_002d74f4;
extern float DAT_002d7510;
extern int *DAT_002d7ac8;
extern int *DAT_002d7acc;
extern uint *DAT_002d7ad0;
extern undefined4 *DAT_002d7ad4;
extern undefined4 DAT_002d7ad8;
extern uint *DAT_002d7adc;
extern undefined4 *DAT_002d7ae0;
extern undefined4 DAT_002d7ae4;
extern float DAT_002d7ae8;
extern undefined4 DAT_002d7aec;
extern uint *DAT_002d8038;
extern undefined4 *DAT_002d803c;
extern uint *DAT_002d8040;
extern undefined4 *DAT_002d8044;
extern undefined4 DAT_002d8048;
extern uint *DAT_002d804c;
extern undefined4 *DAT_002d8050;
extern undefined DAT_002d8054;
extern int *DAT_002d8070;
extern float *DAT_002d8074;
extern float DAT_002d8078;
extern char s_SE_PL_EVENT_SWORD_UP_002d74f8[];
extern char s_SE_PL_EVENT_SWORD_UP_AFTER_TRIFO_002d7a88[];
extern char s_TriForceGetPose_002d7ab8[];
extern char s_TriForceGet_002d7aac[];
extern char s__SE_PL_EVENT_TRIFORCE_UP_002d74d7[];
extern char s__SE_S_WARP_HOLE_SAGE_IN_002d8057[];
extern undefined4 _DAT_002d74d4;
extern undefined4 _DAT_002d8054;

// USA 002D7168 <- EU 002D7144 (Ghidra, non-matching)
// GLOBAL DAT_002d74d4 undefined
// GLOBAL DAT_002d74f0 float
// GLOBAL DAT_002d74f4 int *
// GLOBAL DAT_002d7510 float
// GLOBAL DAT_002d7ac8 int *
// GLOBAL DAT_002d7acc int *
// GLOBAL DAT_002d7ad0 uint *
// GLOBAL DAT_002d7ad4 undefined4 *
// GLOBAL DAT_002d7ad8 undefined4
// GLOBAL DAT_002d7adc uint *
// GLOBAL DAT_002d7ae0 undefined4 *
// GLOBAL DAT_002d7ae4 undefined4
// GLOBAL DAT_002d7ae8 float
// GLOBAL DAT_002d7aec undefined4
// GLOBAL DAT_002d8038 uint *
// GLOBAL DAT_002d803c undefined4 *
// GLOBAL DAT_002d8040 uint *
// GLOBAL DAT_002d8044 undefined4 *
// GLOBAL DAT_002d8048 undefined4
// GLOBAL DAT_002d804c uint *
// GLOBAL DAT_002d8050 undefined4 *
// GLOBAL DAT_002d8054 undefined
// GLOBAL DAT_002d8070 int *
// GLOBAL DAT_002d8074 float *
// GLOBAL DAT_002d8078 float
// GLOBAL s_SE_PL_EVENT_SWORD_UP_002d74f8 string
// GLOBAL s_SE_PL_EVENT_SWORD_UP_AFTER_TRIFO_002d7a88 string
// GLOBAL s_TriForceGetPose_002d7ab8 string
// GLOBAL s_TriForceGet_002d7aac string

/* WARNING: Variable defined which should be unmapped: objStack_48 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 func_002D7168(int param_1,short *param_2,undefined4 param_3,int *param_4)

{
  byte bVar1;
  char cVar2;
  short sVar3;
  undefined1 uVar4;
  uint *puVar5;
  int *piVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int *piVar10;
  float *pfVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  float fVar15;
  _Alignas(8) unsigned char albw_frame[0x50];
  #define objStack_48 ((uint *)(albw_frame + 0x8))
  #define local_40 (*(float *)(albw_frame + 0x10))
  #define local_3c (*(char * *)(albw_frame + 0x14))
  #define local_38 (*(float *)(albw_frame + 0x18))
  #define local_34 (*(char * *)(albw_frame + 0x1c))
  #define local_30 (*(float *)(albw_frame + 0x20))
  #define local_2c (*(char * *)(albw_frame + 0x24))
  #define local_28 (*(float *)(albw_frame + 0x28))
  #define local_24 (*(float *)(albw_frame + 0x2c))
  #define local_20 (*(float *)(albw_frame + 0x30))
  *(undefined4 *)(*(int *)(param_1 + 0x4c) + 0x100) = _DAT_002d74d4;
  fVar15 = DAT_002d8078;
  pfVar11 = DAT_002d8074;
  uVar8 = DAT_002d7aec;
  switch(param_2[1]) {
  case 0x7e:
    *(undefined4 *)(param_1 + 0x58) = **(undefined4 **)(param_1 + 0x3c);
    if (*param_2 == 0x90) {
      func_001DC844(*(int *)(param_1 + 0x28),0);
    }
    iVar13 = (int)param_2[4];
    if (iVar13 == 0x89) {
      iVar13 = *(int *)(param_1 + 0x4c);
      objStack_48[0] = 6;
      func_0028D580((uint *)(iVar13 + 0x3c),0x89,1,1,6);
      piVar10 = (int *)0x1;
      objStack_48[0] = 6;
      uVar8 = 1;
      func_0028D580((uint *)(iVar13 + 0x5c),0x89,1,1,6);
      *(undefined1 *)(param_1 + 0xfd) = 1;
      func_0028C8EC(*(int *)(param_1 + 0x4c),3,uVar8,piVar10);
      piVar10 = DAT_002d74f4;
      local_38 = DAT_002d74f0;
      local_34 = s_SE_PL_EVENT_SWORD_UP_AFTER_TRIFO_002d7a88;
      func_004EA104(*DAT_002d74f4,(int *)&local_38,0);
      func_00297298(*piVar10,0xf);
      if ((char)param_2[6] != '\0') {
        func_002919DC(*(int *)(param_1 + 0x2c));
      }
      iVar13 = *(int *)(*(int *)(param_1 + 0x28) + 0x344);
      if (iVar13 != 0) {
        func_004A1B9C((int *)objStack_48,iVar13,(uint *)s_TriForceGet_002d7aac);
      }
      iVar13 = *(int *)(*(int *)(param_1 + 0x28) + 0x344);
      if (iVar13 != 0) {
        func_004A1B9C((int *)objStack_48,iVar13,(uint *)s_TriForceGetPose_002d7ab8);
      }
      return 0;
    }
    if (iVar13 < 0x8a) {
      if (iVar13 == 0x72) {
        if (((*(uint *)(*(int *)(param_1 + 0x50) + 0x328) & 0x80) == 0) ||
           (*(char *)(*(int *)(param_1 + 0x50) + 0x33c) != '\f')) {
          iVar13 = *(int *)(param_1 + 0x4c);
          objStack_48[0] = 0x18;
          func_0028D580((uint *)(iVar13 + 0x3c),0x72,1,1,0x18);
          objStack_48[0] = 0x18;
          func_0028D580((uint *)(iVar13 + 0x5c),0x72,1,1,0x18);
          uVar4 = 0;
        }
        else {
          iVar13 = *(int *)(param_1 + 0x4c);
          objStack_48[0] = 0x18;
          func_0028D580((uint *)(iVar13 + 0x3c),99,1,1,0x18);
          objStack_48[0] = 0x18;
          func_0028D580((uint *)(iVar13 + 0x5c),99,1,1,0x18);
          uVar4 = 1;
        }
        *(undefined1 *)(param_1 + 0xfd) = uVar4;
        if ((char)param_2[6] != '\0') {
          func_002919DC(*(int *)(param_1 + 0x2c));
        }
        *(float *)(*(int *)(param_1 + 0x4c) + 0x100) = DAT_002d7510;
        return 0;
      }
      if (0x71 < iVar13) {
        if (iVar13 == 0x73) {
          local_2c = s_SE_PL_EVENT_SWORD_UP_002d74f8;
          local_30 = DAT_002d74f0;
          uVar8 = 0;
          func_004EA104(*DAT_002d74f4,(int *)&local_30,0);
          func_0028C8EC(*(int *)(param_1 + 0x4c),3,uVar8,param_4);
          iVar13 = *(int *)(param_1 + 0x4c);
          objStack_48[0] = 6;
          func_0028D580((uint *)(iVar13 + 0x3c),0x73,1,1,6);
          objStack_48[0] = 6;
          func_0028D580((uint *)(iVar13 + 0x5c),0x73,1,1,6);
          *(undefined1 *)(param_1 + 0xfd) = 0;
          if ((char)param_2[6] != '\0') {
            func_002919DC(*(int *)(param_1 + 0x2c));
          }
          local_28 = DAT_002d7510;
          local_24 = DAT_002d7510;
          local_20 = DAT_002d7510;
          return func_001DC3C4(*(int *)(param_1 + 0x28),&local_28,1);
        }
        if (iVar13 != 0x74) {
          return 0;
        }
        iVar13 = *(int *)(param_1 + 0x4c);
        objStack_48[0] = 6;
        func_0028D580((uint *)(iVar13 + 0x3c),0x74,1,0,6);
        objStack_48[0] = 6;
        func_0028D580((uint *)(iVar13 + 0x5c),0x74,1,0,6);
        *(undefined1 *)(param_1 + 0xfd) = 0;
        if (**(int **)(param_1 + 0x44) == 0) {
          return 0;
        }
        objStack_48[0] = 6;
        return func_0028D580((uint *)(*(int *)(param_1 + 0x4c) + 0x3c),0x59,1,1,6);
      }
      if (iVar13 != 0) {
        if (iVar13 == 0x53) {
          iVar13 = *(int *)(param_1 + 0x4c);
          objStack_48[0] = 6;
          func_0028D580((uint *)(iVar13 + 0x3c),0x53,1,0,6);
          objStack_48[0] = 6;
          func_0028D580((uint *)(iVar13 + 0x5c),0x53,1,0,6);
          *(undefined1 *)(param_1 + 0xfd) = 2;
          *(undefined1 *)(*(int *)(param_1 + 0x50) + 0x166) = 0;
          return 0;
        }
        if (iVar13 != 0x70) {
          return 0;
        }
        iVar13 = *(int *)(param_1 + 0x4c);
        objStack_48[0] = 6;
        func_0028D580((uint *)(iVar13 + 0x3c),0x70,1,1,6);
        piVar10 = (int *)0x1;
        objStack_48[0] = 6;
        uVar8 = 1;
        func_0028D580((uint *)(iVar13 + 0x5c),0x70,1,1,6);
        *(undefined1 *)(param_1 + 0xfd) = 1;
        func_0028C8EC(*(int *)(param_1 + 0x4c),1,uVar8,piVar10);
        local_34 = s__SE_PL_EVENT_TRIFORCE_UP_002d74d7 + 1;
        local_38 = DAT_002d74f0;
        func_004EA104(*DAT_002d74f4,(int *)&local_38,0);
        if ((char)param_2[6] != '\0') {
          func_002919DC(*(int *)(param_1 + 0x2c));
        }
        *(int *)(param_1 + 0x58) = **(int **)(param_1 + 0x3c) + -0x80000000;
        return 0;
      }
      iVar13 = *(int *)(param_1 + 0x4c);
      objStack_48[0] = 0x19;
      func_0028D580((uint *)(iVar13 + 0x3c),0,1,1,0x19);
      objStack_48[0] = 0x19;
      func_0028D580((uint *)(iVar13 + 0x5c),0,1,1,0x19);
      *(undefined1 *)(param_1 + 0xfd) = 1;
      if ((char)param_2[6] == '\0') {
        return 0;
      }
    }
    else {
      if (iVar13 == 0xaa) {
        iVar13 = *(int *)(param_1 + 0x4c);
        objStack_48[0] = 6;
        func_0028D580((uint *)(iVar13 + 0x3c),0xaa,1,1,6);
        objStack_48[0] = 6;
        func_0028D580((uint *)(iVar13 + 0x5c),0xaa,1,1,6);
        *(undefined1 *)(param_1 + 0xfd) = 0;
        return 0;
      }
      if (iVar13 < 0xab) {
        if (iVar13 != 0x8f && iVar13 != 0x90) {
          if (iVar13 != 0x9b) {
            return 0;
          }
          iVar13 = *(int *)(param_1 + 0x4c);
          objStack_48[0] = 6;
          func_0028D580((uint *)(iVar13 + 0x3c),0x9b,1,1,6);
          objStack_48[0] = 6;
          func_0028D580((uint *)(iVar13 + 0x5c),0x9b,1,1,6);
          *(undefined1 *)(param_1 + 0xfd) = 3;
          *(undefined2 *)(param_1 + 0xfe) = 0x9c;
          if ((char)param_2[6] == '\0') {
            return 0;
          }
          goto LAB_002d77a4;
        }
      }
      else {
        if (iVar13 == 0xab) {
          iVar13 = *(int *)(param_1 + 0x4c);
          objStack_48[0] = 6;
          func_0028D580((uint *)(iVar13 + 0x3c),0xab,1,1,6);
          objStack_48[0] = 6;
          func_0028D580((uint *)(iVar13 + 0x5c),0xab,1,1,6);
          *(undefined1 *)(param_1 + 0xfd) = 0;
          *(undefined1 *)(*(int *)(param_1 + 0x50) + 0x166) = 0;
          *(undefined1 *)(*(int *)(param_1 + 0x28) + 0x6c6) = 1;
          return 0;
        }
        if (iVar13 != 0xaf) {
          return 0;
        }
      }
      iVar14 = *(int *)(param_1 + 0x4c);
      objStack_48[0] = 6;
      func_0028D580((uint *)(iVar14 + 0x3c),iVar13,1,1,6);
      objStack_48[0] = 6;
      func_0028D580((uint *)(iVar14 + 0x5c),iVar13,1,1,6);
      *(undefined1 *)(param_1 + 0xfd) = 1;
      if ((char)param_2[6] == '\0') {
        return 0;
      }
    }
LAB_002d77a4:
    return func_002919DC(*(int *)(param_1 + 0x2c));
  case 0x7f:
    bVar1 = *(byte *)(param_2 + 5);
    iVar13 = *DAT_002d7ac8;
    iVar14 = func_00581B9C(iVar13);
    if ((iVar14 == 1) && (puVar5 = (uint *)func_00582250(iVar13), (uint)bVar1 < *puVar5)) {
      iVar13 = *(int *)(puVar5[2] + (uint)bVar1 * 4);
    }
    else {
      iVar13 = 0;
    }
    *(int *)(param_1 + 0x70) = iVar13;
    *(undefined1 *)(param_1 + 0x74) = *(undefined1 *)((int)param_2 + 0xb);
    if (iVar13 != 0) {
      piVar10 = *(int **)(iVar13 + 0x28);
      if (piVar10 != (int *)0x0) {
        iVar13 = *(int *)(iVar13 + 0x20);
      }
      if (piVar10 != (int *)0x0 && iVar13 != 0) {
        iVar13 = *piVar10;
      }
      else {
        iVar13 = 0;
      }
      *(undefined4 *)(param_1 + 0x80) = *(undefined4 *)(iVar13 + 0x18);
      *(undefined4 *)(param_1 + 0x84) = *(undefined4 *)(iVar13 + 0x1c);
      *(undefined4 *)(param_1 + 0x88) = *(undefined4 *)(iVar13 + 0x20);
      fVar15 = func_005469FC(param_1,*(int *)(param_1 + 0x70));
      *(float *)(param_1 + 0x8c) = fVar15;
    }
    *(undefined1 *)(param_1 + 0x78) = 0;
    *(undefined4 *)(param_1 + 0x7c) = 0;
    return 0;
  case 0x80:
    *(undefined4 *)(param_1 + 0x90) = *(undefined4 *)(param_2 + 8);
    return 0;
  case 0x81:
    *(undefined4 *)(param_1 + 0x90) = *(undefined4 *)(param_2 + 8);
    *(undefined1 *)(param_1 + 0x76) = 0;
    return 0;
  case 0x82:
    uVar12 = *(uint *)(param_2 + 8);
    *(uint *)(param_1 + 0x90) = uVar12;
    *(undefined1 *)(param_1 + 0x76) = 0;
    puVar7 = (undefined4 *)func_0052FBA0(*DAT_002d7acc + 0x3dbbc,uVar12);
    if (((*DAT_002d7ad0 & 1) == 0) && (iVar13 = func_00100174((int *)DAT_002d7ad0), iVar13 != 0)) {
      *DAT_002d7ad4 = DAT_002d7ad8;
    }
    if ((puVar7 == (undefined4 *)0x0) ||
       (iVar13 = (**(code **)*puVar7)(puVar7,DAT_002d7ad4), iVar13 == 0)) {
      puVar7 = (undefined4 *)0x0;
    }
    if (puVar7 != (undefined4 *)0x0) {
      func_00115C70((float *)&local_3c,(float *)(puVar7 + 0xf4),*(float **)(param_1 + 0x30));
      objStack_48[0] = (uint)local_3c;
      objStack_48[1] = (uint)ALBW_AS_U32(local_38);   /* y: the converted text lost this copy (BOOT_LOG 177) */
      local_40 = ALBW_AS_F32(local_34);
      iVar13 = func_0068C690((float *)objStack_48);
      *(int *)(param_1 + 0x58) = iVar13 + -0x80000000;
      return 0;
    }
    break;
  case 0x83:
    *(undefined1 *)(param_1 + 0x75) = 0;
    piVar10 = DAT_002d7acc;
    *(undefined4 *)(param_1 + 0x90) = *(undefined4 *)(param_2 + 8);
    puVar7 = *(undefined4 **)(param_1 + 0x30);
    uVar8 = *puVar7;
    uVar9 = puVar7[1];
    *(undefined4 *)(param_1 + 0x9c) = puVar7[2];
    *(undefined4 *)(param_1 + 0x94) = uVar8;
    *(undefined4 *)(param_1 + 0x98) = uVar9;
    puVar7 = (undefined4 *)func_0052FBA0(*piVar10 + 0x3dbbc,*(uint *)(param_1 + 0x90));
    if (((*DAT_002d7adc & 1) == 0) && (iVar13 = func_00100174((int *)DAT_002d7adc), iVar13 != 0)) {
      *DAT_002d7ae0 = DAT_002d7ae4;
    }
    if ((puVar7 == (undefined4 *)0x0) ||
       (iVar13 = (**(code **)*puVar7)(puVar7,DAT_002d7ae0), iVar13 == 0)) {
      puVar7 = (undefined4 *)0x0;
    }
    if (puVar7 != (undefined4 *)0x0) {
      uVar8 = puVar7[0xf5];
      uVar9 = puVar7[0xf6];
      *(undefined4 *)(param_1 + 0x94) = puVar7[0xf4];
      *(undefined4 *)(param_1 + 0x98) = uVar8;
      *(undefined4 *)(param_1 + 0x9c) = uVar9;
    }
    *(float *)(param_1 + 0x9c) = *(float *)(param_1 + 0x9c) + DAT_002d7ae8;
    uVar8 = DAT_002d7aec;
    puVar7 = *(undefined4 **)(param_1 + 0x34);
    *puVar7 = DAT_002d7aec;
    puVar7[1] = uVar8;
    puVar7[2] = uVar8;
    *(undefined4 *)(param_1 + 0xa0) = 0;
    func_001DE2B0(*(int *)(param_1 + 0x28),1);
    func_001DE330(*(int *)(param_1 + 0x28),1);
    piVar6 = (int *)func_0052FBA0(*piVar10 + 0x3dbbc,*(uint *)(param_1 + 0x90));
    if (((*DAT_002d8038 & 1) == 0) && (iVar13 = func_00100174((int *)DAT_002d8038), iVar13 != 0)) {
      *DAT_002d803c = DAT_002d7ad8;
    }
    if ((piVar6 == (int *)0x0) || (iVar13 = (**(code **)*piVar6)(piVar6,DAT_002d803c), iVar13 == 0))
    {
      piVar6 = (int *)0x0;
    }
    if (piVar6 != (int *)0x0) {
      (**(code **)(*piVar6 + 0x4c))(piVar6);
    }
    puVar7 = (undefined4 *)func_0052FBA0(*piVar10 + 0x3dbbc,*(uint *)(param_1 + 0x90));
    if (((*DAT_002d8040 & 1) == 0) && (iVar13 = func_00100174((int *)DAT_002d8040), iVar13 != 0)) {
      *DAT_002d8044 = DAT_002d8048;
    }
    if ((puVar7 == (undefined4 *)0x0) ||
       (iVar13 = (**(code **)*puVar7)(puVar7,DAT_002d8044), iVar13 == 0)) {
      puVar7 = (undefined4 *)0x0;
    }
    *(bool *)(param_1 + 0xf9) = puVar7 != (undefined4 *)0x0;
    *(undefined1 *)(param_1 + 0xfa) = 0;
    if (puVar7 != (undefined4 *)0x0) {
      *(bool *)(param_1 + 0xfa) = *(char *)(puVar7 + 0x11e) == '\x01';
    }
    *(undefined1 *)(param_1 + 0xfc) = 1;
    return 0;
  case 0x84:
  case 0x88:
    *(float *)(*(int *)(param_1 + 0x30) + 8) =
         *(float *)(*(int *)(param_1 + 0x30) + 8) + DAT_002d7ae8;
    func_004EB178(*DAT_002d74f4);
    return func_001DE2B0(*(int *)(param_1 + 0x28),1);
  case 0x85:
    puVar7 = *(undefined4 **)(param_1 + 0x34);
    *puVar7 = DAT_002d7aec;
    puVar7[1] = uVar8;
    puVar7[2] = uVar8;
    *(undefined4 *)(param_1 + 0x90) = *(undefined4 *)(param_2 + 8);
    fVar15 = func_0053EE20(*(int *)(param_1 + 0x4c) + 0x3c);
    *(float *)(param_1 + 0xa4) = fVar15;
    *(undefined4 *)(param_1 + 0xa0) = 0;
    func_001DE2B0(*(int *)(param_1 + 0x28),1);
    func_001DE330(*(int *)(param_1 + 0x28),1);
    cVar2 = *(char *)((int)param_2 + 0xd);
    *(char *)(param_1 + 0xf8) = cVar2;
    if (cVar2 != '\0') {
      *(undefined4 *)(param_1 + 0xf4) = *(undefined4 *)(param_2 + 10);
    }
    puVar7 = (undefined4 *)func_0052FBA0(*DAT_002d7acc + 0x3dbbc,*(uint *)(param_1 + 0x90));
    if (((*DAT_002d804c & 1) == 0) && (iVar13 = func_00100174((int *)DAT_002d804c), iVar13 != 0)) {
      *DAT_002d8050 = DAT_002d7ad8;
    }
    if ((puVar7 == (undefined4 *)0x0) ||
       (iVar13 = (**(code **)*puVar7)(puVar7,DAT_002d8050), iVar13 == 0)) {
      puVar7 = (undefined4 *)0x0;
    }
    if (puVar7 != (undefined4 *)0x0) {
      func_0019C330((int)puVar7);
    }
    *(undefined1 *)(param_1 + 0xfb) = 1;
    return 0;
  case 0x86:
    *(undefined4 *)(param_1 + 0xa0) = 0;
    fVar15 = ALBW_AS_F32(_DAT_002d8054);
    *(undefined1 *)(*(int *)(param_1 + 0x28) + 0x6bc) = 1;
    **(undefined4 **)(param_1 + 0x3c) = *(undefined4 *)(param_1 + 0xb4);
    pfVar11 = *(float **)(param_1 + 0x30);
    func_00115D70(&local_38,(float *)(param_1 + 0xa8),fVar15);
    objStack_48[0] = (uint)ALBW_AS_U32(local_38);
    objStack_48[1] = (uint)(uintptr_t)local_34;   /* y (BOOT_LOG 177) */
    local_40 = local_30;
    func_00115C70(pfVar11,pfVar11,(float *)objStack_48);
    return func_004EB178(*DAT_002d74f4);
  case 0x87:
    *(undefined1 *)(param_1 + 0x75) = 0;
    *(undefined4 *)(param_1 + 0x90) = 0;
    *(float *)(*(int *)(param_1 + 0x30) + 8) =
         *(float *)(*(int *)(param_1 + 0x30) + 8) + DAT_002d7ae8;
    uVar8 = DAT_002d7aec;
    puVar7 = *(undefined4 **)(param_1 + 0x34);
    *puVar7 = DAT_002d7aec;
    puVar7[1] = uVar8;
    puVar7[2] = uVar8;
    *(undefined4 *)(param_1 + 0xa0) = 0;
    func_001DE2B0(*(int *)(param_1 + 0x28),1);
    func_001DE330(*(int *)(param_1 + 0x28),1);
    local_3c = s__SE_S_WARP_HOLE_SAGE_IN_002d8057 + 1;
    local_40 = DAT_002d74f0;
    return func_00587F74(*DAT_002d74f4,(int *)&local_40,0);
  case 0x89:
    puVar7 = *(undefined4 **)(param_1 + 0x30);
    *(undefined4 *)(param_1 + 0x100) = *puVar7;
    *(undefined4 *)(param_1 + 0x104) = puVar7[1];
    *(undefined4 *)(param_1 + 0x108) = puVar7[2];
    *(undefined4 *)(param_1 + 0x90) = *(undefined4 *)(param_2 + 8);
    puVar7 = *(undefined4 **)(param_1 + 0x30);
    uVar8 = *puVar7;
    piVar10 = (int *)puVar7[1];
    *(undefined4 *)(param_1 + 0x114) = puVar7[2];
    *(undefined4 *)(param_1 + 0x10c) = uVar8;
    *(int **)(param_1 + 0x110) = piVar10;
    func_0028C8EC(*(int *)(param_1 + 0x4c),0,uVar8,piVar10);
    uVar8 = DAT_002d7aec;
    puVar7 = *(undefined4 **)(param_1 + 0x34);
    *puVar7 = DAT_002d7aec;
    puVar7[1] = uVar8;
    puVar7[2] = uVar8;
    return 0;
  case 0x8c:
    puVar7 = *(undefined4 **)(param_1 + 0x30);
    *(undefined4 *)(param_1 + 0x100) = *puVar7;
    *(undefined4 *)(param_1 + 0x104) = puVar7[1];
    *(undefined4 *)(param_1 + 0x108) = puVar7[2];
    *(undefined4 *)(param_1 + 0x90) = *(undefined4 *)(param_2 + 8);
    iVar14 = *DAT_002d8070;
    iVar13 = *(int *)(param_1 + 0x28);
    func_00115D70(&local_28,pfVar11,fVar15);
    objStack_48[0] = (uint)ALBW_AS_U32(local_28);
    objStack_48[1] = (uint)ALBW_AS_U32(local_24);   /* y (BOOT_LOG 177) */
    local_40 = local_20;
    func_00115C54(&local_28,(float *)(iVar13 + 0x3d0),(float *)objStack_48);
    uVar12 = 0;
    local_38 = local_28;
    local_34 = (char *)ALBW_PTR_BITS(local_24);
    local_30 = local_20;
    if (0 < *(int *)(iVar14 + 0x90)) {
      do {
        if (uVar12 < *(uint *)(iVar14 + 0x90)) {
          iVar13 = *(int *)(*(int *)(iVar14 + 0x98) + uVar12 * 4);
        }
        else {
          iVar13 = 0;
        }
        if (*(int *)(iVar13 + 0x20) != 0) {
          func_003879AC(*(int *)(iVar13 + 0x20),&local_38);
        }
        if (*(int *)(iVar13 + 0x24) != 0) {
          func_003879AC(*(int *)(iVar13 + 0x24),&local_38);
        }
        uVar12 = uVar12 + 1;
      } while ((int)uVar12 < *(int *)(iVar14 + 0x90));
    }
    piVar10 = *(int **)(*(int *)(param_1 + 0x2c) + 0x70);
    if (piVar10 != (int *)0x0) {
      func_002FD11C(piVar10,1);
    }
    return 0;
  case 0x8d:
    *(undefined1 *)(param_1 + 0x77) = 0;
    return 0;
  case 0x8e:
    sVar3 = param_2[4];
    *(short *)(param_1 + 0x124) = sVar3;
    iVar13 = *(int *)(param_1 + 0x4c);
    objStack_48[0] = 6;
    func_0028D580((uint *)(iVar13 + 0x3c),(int)sVar3,1,1,6);
    piVar10 = (int *)0x1;
    objStack_48[0] = 6;
    uVar8 = 1;
    func_0028D580((uint *)(iVar13 + 0x5c),(int)sVar3,1,1,6);
    *(undefined1 *)(param_1 + 0xfd) = 0;
    sVar3 = *(short *)(param_1 + 0x124);
    if (sVar3 == 0x89) {
      objStack_48[0] = (uint)ALBW_AS_U32(DAT_002d74f0);
    objStack_48[1] = (uint)(uintptr_t)"SE_PL_EVENT_SWORD_UP_AFTER_TRIFORCE";   /* the name: the converted text lost this store */
      uVar8 = 0;
      func_004EA104(*DAT_002d74f4,(int *)objStack_48,0);
      return func_0028C8EC(*(int *)(param_1 + 0x4c),3,uVar8,piVar10);
    }
    if (sVar3 == 0x93) {
      func_0028C8EC(*(int *)(param_1 + 0x4c),4,uVar8,piVar10);
      return func_002904EC(*(int *)(param_1 + 0x2c));
    }
    if (sVar3 == 0x94) {
      func_0028C8EC(*(int *)(param_1 + 0x4c),5,uVar8,piVar10);
      return func_002904EC(*(int *)(param_1 + 0x2c));
    }
    break;
  case 0x8f:
    *(undefined1 *)(param_1 + 300) = 0;
    *(undefined4 *)(param_1 + 0x94) = *(undefined4 *)(param_2 + 0xc);
    *(undefined4 *)(param_1 + 0x98) = *(undefined4 *)(param_2 + 0xe);
    *(undefined4 *)(param_1 + 0x9c) = *(undefined4 *)(param_2 + 0x10);
    *(undefined4 *)(param_1 + 0x58) = *(undefined4 *)(param_2 + 0x12);
    *(undefined4 *)(param_1 + 0x128) = 0xffffffff;
    return 0;
  case 0x90:
    return func_001DC844(*(int *)(param_1 + 0x28),1);
  }
  return 0;
}

