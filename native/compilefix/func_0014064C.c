/* compilefix: USA 0014064C, the converted stage-2 text with its split tail rejoined (BOOT_LOG 172):
 * Ghidra made the shared tail at EU 00140A60 a function of its own (`func_00140A60(void)` reading the
 * caller's r4 / r7 / r8 / r9 and stack) and called it; it is the code at code_r0x00140a60 here
 * (EU 140974..140978 branch to it). Crash entering Hyrule cave 1 (iron balls). */
#include "ghidra_types.h"

extern int func_00115C54(float *param_1,float *param_2,float *param_3);
extern int func_00140A60(void);
extern int func_0014EEC8(int param_1,uint param_2,undefined4 *param_3,undefined4 param_4,float fparam_0);
extern int func_0014FA44(int param_1,int param_2,undefined4 param_3,undefined4 param_4,uint param_5, undefined4 param_6,int param_7);
extern int func_004356B4(int *param_1);
extern int func_0054D884(int param_1,uint param_2);
extern int func_00588BE4(int param_1);
extern int func_006824D4(int *param_1,float *param_2,undefined4 *param_3,float *param_4);
extern int *DAT_00140a48;
extern float DAT_00140a4c;
extern int DAT_00140a50;
extern float *DAT_00140a54;
extern float DAT_00140a58;
extern undefined4 DAT_00140a5c;

// USA 0014064C <- EU 0014064C (Ghidra, non-matching)
// GLOBAL DAT_00140a48 int *
// GLOBAL DAT_00140a4c float
// GLOBAL DAT_00140a50 int
// GLOBAL DAT_00140a54 float *
// GLOBAL DAT_00140a58 float
// GLOBAL DAT_00140a5c undefined4

undefined4 func_0014064C(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  bool bVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  undefined4 uVar8;
  _Alignas(8) unsigned char albw_frame[0x60];
  #define local_54 (*(float *)(albw_frame + 0xc))
  #define local_50 (*(float *)(albw_frame + 0x10))
  #define local_4c (*(float *)(albw_frame + 0x14))
  #define local_48 (*(float *)(albw_frame + 0x18))
  #define local_44 (*(float *)(albw_frame + 0x1c))
  #define local_40 (*(float *)(albw_frame + 0x20))
  #define local_3c (*(float *)(albw_frame + 0x24))
  #define local_38 (*(float *)(albw_frame + 0x28))
  #define local_34 (*(float *)(albw_frame + 0x2c))
  *(undefined4 *)(param_1 + 0x484) = *(undefined4 *)(param_1 + 0x3d0);
  *(undefined4 *)(param_1 + 0x488) = *(undefined4 *)(param_1 + 0x3d4);
  *(undefined4 *)(param_1 + 0x48c) = *(undefined4 *)(param_1 + 0x3d8);
  iVar1 = func_00588BE4(param_1);
  if ((iVar1 != *DAT_00140a48) ||
     (bVar4 = *(char *)(param_1 + 0x51f) == '\0', *(bool *)(param_1 + 0x51f) = bVar4, !bVar4)) {
    *(undefined4 *)(param_1 + 0x490) = *(undefined4 *)(param_1 + 0x3d0);
    *(undefined4 *)(param_1 + 0x494) = *(undefined4 *)(param_1 + 0x3d4);
    *(undefined4 *)(param_1 + 0x498) = *(undefined4 *)(param_1 + 0x3d8);
  }
  fVar6 = DAT_00140a4c;
  fVar5 = *(float *)(param_1 + 0x3e0) - *(float *)(*(int *)(param_1 + 0x42c) + 4);
  fVar7 = -*(float *)(*(int *)(param_1 + 0x42c) + 8);
  if (fVar5 < fVar7) {
    fVar5 = fVar7;
  }
  *(float *)(param_1 + 0x3e0) = fVar5;
  *(float *)(param_1 + 0x3d0) = *(float *)(param_1 + 0x3d0) + *(float *)(param_1 + 0x3dc);
  *(float *)(param_1 + 0x3d8) = *(float *)(param_1 + 0x3d8) + *(float *)(param_1 + 0x3e4);
  fVar5 = *(float *)(param_1 + 0x500) + fVar5;
  *(float *)(param_1 + 0x500) = fVar5;
  if (*(char *)(param_1 + 0x51f) != '\0') {
    *(float *)(param_1 + 0x3d4) = *(float *)(param_1 + 0x3d4) + fVar5;
    *(float *)(param_1 + 0x500) = fVar6;
    *(undefined1 *)(param_1 + 0x520) = 0;
  }
  if (*(int *)(param_1 + 0x41c) == 0) {
    return 0;
  }
  local_34 = *(float *)(DAT_00140a50 + 0x34c);
  local_48 = *(float *)(DAT_00140a50 + 0x338);
  local_44 = *(float *)(DAT_00140a50 + 0x33c);
  local_40 = *(float *)(DAT_00140a50 + 0x340);
  local_3c = *(float *)(DAT_00140a50 + 0x344);
  local_38 = *(float *)(DAT_00140a50 + 0x348);
  local_54 = *DAT_00140a54;
  local_50 = DAT_00140a54[1];
  local_4c = DAT_00140a54[2];
  iVar1 = func_0054D884(*(int *)(param_1 + 0x2d0) + 0x18,0);
  puVar3 = (undefined4 *)(*(int *)(param_1 + 0x410) + 0x80);
  func_006824D4(*(int **)(param_1 + 0x41c),(float *)(iVar1 + 4),puVar3,(float *)(param_1 + 0x3d0));
  if (*(int *)(param_1 + 0x428) != 0) {
    iVar2 = *(int *)(param_1 + 0x424);
    fVar5 = *(float *)(param_1 + 0x3d4) - DAT_00140a58;
    uVar8 = *(undefined4 *)(param_1 + 0x3d8);
    *(undefined4 *)(iVar2 + 4) = *(undefined4 *)(param_1 + 0x3d0);
    *(float *)(iVar2 + 8) = fVar5;
    *(undefined4 *)(iVar2 + 0xc) = uVar8;
    func_004356B4(*(int **)(param_1 + 0x424));
    *(undefined1 *)(*(int *)(param_1 + 0x428) + 0x44) = 0;
  }
  uVar8 = DAT_00140a5c;
  if (*(char *)(*(int *)(param_1 + 0x418) + 0x61) == '\0') {
    if ((*(char *)(param_1 + 0x464) != '\x04') && (*(char *)(param_1 + 0x464) != '\x01'))
    goto LAB_00140a80;
    if ((*(char *)(param_1 + 0x51f) == '\0') ||
       (iVar2 = func_0014EEC8(param_1,(uint)&local_54,(undefined4 *)(param_1 + 0x430),DAT_00140a5c,
                              *(float *)(param_1 + 0x43c)), iVar2 == 0)) goto code_r0x00140a60;
    if (local_54 < local_48) {
      local_48 = local_54;
    }
    if (local_50 < local_44) {
      local_44 = local_50;
    }
    if (local_4c < local_40) {
      local_40 = local_4c;
    }
    fVar6 = local_54;
    if (local_54 < local_3c) {
      fVar6 = local_3c;
    }
    fVar5 = local_50;
    if (local_50 < local_38) {
      fVar5 = local_38;
    }
    fVar7 = local_4c;
    local_3c = fVar6;
    local_38 = fVar5;
    if (local_34 <= local_4c) goto LAB_00140974;
  }
  else {
    iVar2 = func_0014FA44(param_1,(int)&local_54,*(undefined4 *)(param_1 + 0x41c),0,0x22,0,0);
    fVar5 = local_34;
    if (iVar2 != 0) {
      if (local_54 < local_48) {
        local_48 = local_54;
      }
      if (fVar6 < local_44) {
        local_44 = fVar6;
      }
      if (local_4c < local_40) {
        local_40 = local_4c;
      }
      if (local_54 < local_3c) {
        local_54 = local_3c;
      }
      if (local_38 <= fVar6) {
        local_38 = fVar6;
      }
      local_3c = local_54;
      fVar5 = local_4c;
      if (local_4c < local_34) {
        fVar5 = local_34;
      }
    }
    local_34 = fVar5;
    local_54 = fVar6;
    local_50 = fVar6;
    local_4c = fVar6;
    if ((*(char *)(param_1 + 0x51f) == '\0') ||
       (iVar2 = func_0014EEC8(param_1,(uint)&local_54,(undefined4 *)(param_1 + 0x430),uVar8,
                              *(float *)(param_1 + 0x43c)), iVar2 == 0)) {
code_r0x00140a60:
      func_00115C54((float *)(param_1 + 0x3d0),(float *)(param_1 + 0x3d0),&local_48);
      func_00115C54((float *)(param_1 + 0x3d0),(float *)(param_1 + 0x3d0),&local_3c);
LAB_00140a80:
      return func_006824D4(*(int **)(param_1 + 0x41c),(float *)(iVar1 + 4),puVar3,
                    (float *)(param_1 + 0x3d0));
    }
    if (local_54 < local_48) {
      local_48 = local_54;
    }
    if (local_50 < local_44) {
      local_44 = local_50;
    }
    if (local_4c < local_40) {
      local_40 = local_4c;
    }
    fVar6 = local_54;
    if (local_54 < local_3c) {
      fVar6 = local_3c;
    }
    fVar5 = local_50;
    if (local_50 < local_38) {
      fVar5 = local_38;
    }
    fVar7 = local_4c;
    local_3c = fVar6;
    local_38 = fVar5;
    if (local_34 <= local_4c) goto LAB_00140974;
  }
  fVar7 = local_34;
LAB_00140974:
  local_34 = fVar7;
  goto code_r0x00140a60;   /* the shared tail, EU 00140A60 */
}

