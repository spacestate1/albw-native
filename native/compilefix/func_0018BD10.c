/* compilefix: USA 0018BD10 (EU 0018BD10), the converted stage-2 text.
 * Fixed (BOOT_LOG 184): the ARM copies this word between a float and an integer (no vcvt), which the
 * converted text wrote as a conversion of the value. */
#include "ghidra_types.h"

extern int func_00115D70(float *param_1,float *param_2,float fparam_0);
extern float func_00115DC8(float *param_1);
extern int func_00115E10(float *param_1,float *param_2,float *param_3);
extern int func_00150A84(int *param_1,int *param_2,int param_3);
extern int func_0018B064(uint param_1);
extern int func_0018B58C(int param_1);
extern int func_0018BC14(int param_1);
extern int func_003929C4(int *param_1);
extern int func_004A1B9C(int *param_1,int param_2,uint *param_3);
extern int func_004A2E80(int param_1,float *param_2,float fparam_0);
extern int func_00520EE4(int param_1);
extern int func_00521018(int param_1);
extern int func_0052107C(int param_1);
extern float DAT_0018c024;
extern float DAT_0018c028;
extern float DAT_0018c058;
extern float DAT_0018c05c;
extern int DAT_0018c060;
extern int DAT_0018c218;
extern int DAT_0018c21c;
extern char s_33s_IntoLavaUpSide_0018c044[];
extern char s_SE_FireBall_FALL_WATER_0018c02c[];

// USA 0018BD10 <- EU 0018BD10 (Ghidra, non-matching)
// GLOBAL DAT_0018c024 float
// GLOBAL DAT_0018c028 float
// GLOBAL DAT_0018c058 float
// GLOBAL DAT_0018c05c float
// GLOBAL DAT_0018c060 int
// GLOBAL DAT_0018c218 int
// GLOBAL DAT_0018c21c int
// GLOBAL s_SE_FireBall_FALL_WATER_0018c02c string

void func_0018BD10(int *param_1)

{
  float fVar1;
  bool bVar2;
  char cVar3;
  short sVar4;
  int iVar5;
  float fVar6;
  bool bVar7;
  float fVar8;
  float fVar9;
  _Alignas(8) unsigned char albw_frame[0xd0];
  #define local_c8 (*(float *)(albw_frame + 0x8))
  #define local_c4 (*(char * *)(albw_frame + 0xc))
  #define local_c0 (*(float *)(albw_frame + 0x10))
  #define local_ac (*(float *)(albw_frame + 0x24))
  #define local_a8 (*(char * *)(albw_frame + 0x28))
  #define local_a4 (*(float *)(albw_frame + 0x2c))
  #define local_a0 (*(float *)(albw_frame + 0x30))
  #define local_9c (*(float *)(albw_frame + 0x34))
  #define local_98 (*(float *)(albw_frame + 0x38))
  #define local_90 (*(float *)(albw_frame + 0x40))
  #define local_8c (*(float *)(albw_frame + 0x44))
  #define local_88 (*(float *)(albw_frame + 0x48))
  #define local_84 (*(int *)(albw_frame + 0x4c))
  #define local_80 (*(undefined4 *)(albw_frame + 0x50))
  #define local_7c (*(undefined4 *)(albw_frame + 0x54))
  #define local_78 (*(char * *)(albw_frame + 0x58))
  #define local_74 (*(int *)(albw_frame + 0x5c))
  #define local_70 (*(undefined4 *)(albw_frame + 0x60))
  #define local_6c (*(undefined4 *)(albw_frame + 0x64))
  #define local_68 (*(float *)(albw_frame + 0x68))
  #define local_64 (*(int *)(albw_frame + 0x6c))
  #define local_60 (*(float *)(albw_frame + 0x70))
  #define local_5c (*(undefined4 *)(albw_frame + 0x74))
  #define local_58 (*(undefined4 *)(albw_frame + 0x78))
  #define local_4c (*(float *)(albw_frame + 0x84))
  #define local_48 (*(undefined4 *)(albw_frame + 0x88))
  #define local_44 (*(undefined4 *)(albw_frame + 0x8c))
  #define local_40 (*(float *)(albw_frame + 0x90))
  #define local_3c (*(char * *)(albw_frame + 0x94))
  #define local_38 (*(float *)(albw_frame + 0x98))
  #define uStack_34 (*(undefined4 *)(albw_frame + 0x9c))
  #define uStack_30 (*(undefined4 *)(albw_frame + 0xa0))
  func_0018B58C((int)param_1);
  fVar9 = DAT_0018c024;
  if (*(char *)((int)param_1 + 0x4ed) != '\0') {
    iVar5 = func_003929C4(param_1 + 0x144);
    if (iVar5 != 0) {
      *(undefined1 *)((int)param_1 + 0x2d7) = 1;
    }
    return;
  }
  *(undefined1 *)((int)param_1 + 0x4ee) = 0;
  *(undefined1 *)((int)param_1 + 0x4f2) = 0;
  func_0018B064((uint)param_1);
  fVar1 = DAT_0018c028;
  if ((*(char *)((int)param_1 + 0x4ef) == '\0') || (bVar2 = func_0052107C((int)param_1), !bVar2)) {
    if (((char)param_1[0x13c] == '\0') || (bVar2 = func_0052107C((int)param_1), !bVar2)) {
      bVar2 = false;
      if (ALBW_AS_F32(param_1[0x13d]) == fVar9) {
        bVar2 = ALBW_AS_F32(param_1[0x13e]) == fVar9;
      }
      bVar7 = false;
      if (bVar2) {
        bVar7 = ALBW_AS_F32(param_1[0x13f]) == fVar9;
      }
      if (bVar7) {
        cVar3 = *(char *)((int)param_1 + 0x4ed);
        bVar2 = cVar3 == '\0';
        if (bVar2) {
          cVar3 = *(char *)((int)param_1 + 0x2d7);
        }
        if ((bVar2 && cVar3 == '\0') &&
           (((*(char *)((int)param_1 + 0x4ee) != '\0' &&
             (bVar2 = func_00521018((int)param_1), bVar2)) ||
            ((*(char *)((int)param_1 + 0x4f1) != '\0' &&
             (iVar5 = func_00520EE4((int)param_1), iVar5 == 0)))))) {
          func_0018BC14((int)param_1);
        }
      }
      else {
        if (param_1[0x13e] < (int)(*(undefined4 *)((char *)&s_33s_IntoLavaUpSide_0018c044 + 0))) {
          if (param_1[0xd1] == 0) {
            fVar6 = 0.0;
            fVar8 = 0.0;
          }
          else {
            func_004A1B9C((int *)&local_90,param_1[0xd1],(uint *)(s_33s_IntoLavaUpSide_0018c044 + 4)
                         );
            fVar6 = local_90;
            fVar8 = local_8c;
          }
          func_00115D70(&local_c8,(float *)(param_1 + 0x13d),DAT_0018c058);
          local_ac = local_c8;
          local_a8 = local_c4;
          local_a4 = local_c0;
          if ((fVar6 != 0.0) && (*(float *)((int)ALBW_AS_U32(fVar6) + 0x1c) == fVar8)) {
            local_9c = DAT_0018c05c;
            fVar8 = local_c8 * fVar9 + ALBW_AS_F32(local_c4) * DAT_0018c05c + local_c0 * fVar9;
            if (fVar8 <= fVar9) {
              fVar8 = -fVar8;
            }
            local_a0 = fVar9;
            if (DAT_0018c060 < (int)ALBW_AS_U32(fVar8)) {
              local_a0 = DAT_0018c05c;
              local_9c = fVar9;
            }
            fVar8 = DAT_0018c05c;
            local_98 = fVar9;
            func_00115E10(&local_38,&local_a0,&local_ac);
            local_4c = local_38;
            local_48 = uStack_34;
            local_44 = uStack_30;
            func_00115DC8(&local_4c);
            func_00115E10(&local_38,&local_ac,&local_4c);
            local_60 = local_38;
            local_5c = uStack_34;
            local_58 = uStack_30;
            func_00115DC8(&local_60);
            local_90 = local_4c;
            local_80 = local_48;
            local_70 = local_44;
            local_8c = local_60;
            local_7c = local_5c;
            local_6c = local_58;
            local_88 = local_ac;
            local_78 = local_a8;
            local_68 = local_a4;
            local_84 = param_1[0x140];
            local_74 = param_1[0x141];
            local_64 = param_1[0x142];
            func_004A2E80((int)ALBW_AS_U32(fVar6),&local_90,fVar8);
          }
        }
        else {
          (**(code **)(param_1[200] + 0x3c))(param_1 + 200);
        }
        local_3c = s_SE_FireBall_FALL_WATER_0018c02c;
        local_40 = fVar1;
        func_00150A84(param_1,(int *)&local_40,0);
        *(undefined1 *)((int)param_1 + 0x2d7) = 1;
      }
    }
    else {
      (**(code **)(param_1[200] + 0x3c))(param_1 + 200);
      local_c4 = s_SE_FireBall_FALL_WATER_0018c02c;
      local_c8 = fVar1;
      func_00150A84(param_1,(int *)&local_c8,0);
      *(undefined1 *)((int)param_1 + 0x2d7) = 1;
    }
  }
  else {
    (**(code **)(param_1[200] + 0x38))(param_1 + 200);
    local_c4 = s_SE_FireBall_FALL_WATER_0018c02c;
    local_c8 = fVar1;
    func_00150A84(param_1,(int *)&local_c8,0);
    *(undefined1 *)((int)param_1 + 0x2d7) = 1;
  }
  if (((*(char *)((int)param_1 + 0x539) != '\0') && (*(char *)((int)param_1 + 0x2d7) == '\0')) &&
     (DAT_0018c218 <=
      (int)ALBW_AS_U32(((ALBW_AS_F32(param_1[0xf4]) - ALBW_AS_F32(param_1[0x14b])) *
            (ALBW_AS_F32(param_1[0xf4]) - ALBW_AS_F32(param_1[0x14b])) +
           (ALBW_AS_F32(param_1[0xf6]) - ALBW_AS_F32(param_1[0x14d])) *
           (ALBW_AS_F32(param_1[0xf6]) - ALBW_AS_F32(param_1[0x14d])))))) {
    func_0018BC14((int)param_1);
  }
  cVar3 = *(char *)((int)param_1 + 0x53a);
  bVar2 = cVar3 == '\0';
  if (bVar2) {
    cVar3 = *(char *)((int)param_1 + 0x4ed);
  }
  if (bVar2 && cVar3 == '\0') {
    if (((ALBW_AS_F32(param_1[0xda]) == ALBW_AS_F32(param_1[0xf4])) &&
        (ALBW_AS_F32(param_1[0xdb]) == ALBW_AS_F32(param_1[0xf5]))) &&
       (ALBW_AS_F32(param_1[0xdc]) == ALBW_AS_F32(param_1[0xf6]))) {
      cVar3 = (char)param_1[0x14f] + '\x01';
      *(char *)(param_1 + 0x14f) = cVar3;
      if ('\x02' < cVar3) {
        func_0018BC14((int)param_1);
      }
    }
    else {
      *(undefined1 *)(param_1 + 0x14f) = 0;
    }
    if ((int)ALBW_AS_U32(((ALBW_AS_F32(param_1[0xf4]) - ALBW_AS_F32(param_1[0xda])) *
              (ALBW_AS_F32(param_1[0xf4]) - ALBW_AS_F32(param_1[0xda])) +
             (ALBW_AS_F32(param_1[0xf6]) - ALBW_AS_F32(param_1[0xdc])) *
             (ALBW_AS_F32(param_1[0xf6]) - ALBW_AS_F32(param_1[0xdc])))) < DAT_0018c21c) {
      if ((ALBW_AS_F32(param_1[0xdb]) <= ALBW_AS_F32(param_1[0xf5])) &&
         (sVar4 = *(short *)((int)param_1 + 0x53e) + 1, *(short *)((int)param_1 + 0x53e) = sVar4,
         0x59 < sVar4)) {
        func_0018BC14((int)param_1);
      }
      goto LAB_0018c124;
    }
  }
  else {
    *(undefined1 *)(param_1 + 0x14f) = 0;
  }
  *(undefined2 *)((int)param_1 + 0x53e) = 0;
LAB_0018c124:
  param_1[0x14a] = param_1[0x14a] + 1;
  return;
}

