/* compilefix: USA 002E7F48 (EU 002E7F24), Ghidra-derived (build/ghidra_analyzed4).
 * Failed to compile: use of undeclared identifier 's_'
 * Fixed (each an exact C form of the ARM operation; the rest is the converted Ghidra text):
 *  - Ghidra string label with punctuation (s_T<SE_..._ADDR + n) -> s_cf_<ADDR+n>, the same code-section address (checked: add rX,pc,#imm in the ARM) [2]
 *  - call to a callee the dump names FUN_<EU> (mapped to func_<USA> without a declaration; implicit int(...) would promote float args): extern prototype from the callee's Ghidra signature [1]
 * Confidence: high for the fixes (each class checked against the EU disassembly on sample sites);
 * the function body otherwise has the fidelity of the Ghidra output (bare `return;` exits of
 * functions retyped non-void return 0, as the converter does). */
#include "ghidra_types.h"
extern char s_cf_002e82bf[];
extern char s_cf_002e82c0[];
#include "compilefix.h"
/* callee named FUN_<EU> in the dump: prototype from its own Ghidra signature */
extern undefined4 func_0036BE78(int param_1);

extern int func_00115C70(float *param_1,float *param_2,float *param_3);
extern float func_00115DC8(float *param_1);
extern int func_002F3468(int param_1,int param_2);
extern int func_002F4E50(int param_1,int param_2);
extern int func_002F618C(int param_1,float fparam_0);
extern int func_0036B758(int param_1);
extern float func_003E19E8(float fparam_0,float fparam_1,float fparam_2,float fparam_3,float fparam_4);
extern float func_0049216C(float *param_1,uint *param_2,float *param_3);
extern int func_004A1B9C(int *param_1,int param_2,uint *param_3);
extern int func_004A2D1C(int param_1,float *param_2);
extern int func_004D8054(float *param_1,uint param_2,float fparam_0);
extern float func_0054F764(undefined4 *param_1,uint param_2,uint *param_3);
extern int func_00588C14(int param_1,int param_2,uint param_3);
extern float func_006640EC(undefined4 *param_1,undefined1 param_2,float fparam_0);
extern int func_0068A560(float *param_1,float *param_2,float *param_3,float fparam_0);
extern int func_0068C690(float *param_1);
extern float DAT_002e82b0;
extern float DAT_002e82b4;
extern float DAT_002e82b8;
extern undefined DAT_002e82bc;
extern float DAT_002e82c8;
extern undefined4 _DAT_002e82bc;

float *albw_s012_get(void);   /* s0..s2 of a returned vector (native/runtime/vec3ret.c) */

// USA 002E7F48 <- EU 002E7F24 (Ghidra, non-matching)
// GLOBAL DAT_002e82b0 float
// GLOBAL DAT_002e82b4 float
// GLOBAL DAT_002e82b8 float
// GLOBAL DAT_002e82bc undefined
// GLOBAL DAT_002e82c8 float
// GLOBAL s_cf_002e82bf string

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 func_002E7F48(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  uint in_fpscr;
  float in_s0;
  float fVar10;
  float fVar11;
  float fVar12;
  float fparam_0;
  float fVar13;
  _Alignas(8) unsigned char albw_frame[0xa0];
  #define local_98 (*(float *)(albw_frame + 0x8))
  #define iStack_94 (*(int *)(albw_frame + 0xc))
  #define local_90 (*(undefined4 *)(albw_frame + 0x10))
  #define afStack_88 ((float *)(albw_frame + 0x18))
  #define local_4c (*(float *)(albw_frame + 0x54))
  #define local_48 (*(float *)(albw_frame + 0x58))
  #define fStack_44 (*(float *)(albw_frame + 0x5c))
  #define local_40 (*(float *)(albw_frame + 0x60))
  #define local_3c (*(float *)(albw_frame + 0x64))
  #define local_38 (*(undefined4 *)(albw_frame + 0x68))
  #define local_34 (*(float *)(albw_frame + 0x6c))
  #define local_30 (*(undefined4 *)(albw_frame + 0x70))
  #define uStack_2c (*(undefined4 *)(albw_frame + 0x74))
  #define local_28 ((uint *)(albw_frame + 0x78))
  iVar3 = func_0036BE78(param_1 + 0x964);
  fVar11 = DAT_002e82b4;
  fVar12 = DAT_002e82b0;
  iVar5 = *(int *)(param_1 + 0xb7c);
  if (iVar5 != 0) {
    if (iVar5 == 1) {
      if (*(uint *)(param_1 + 0xb0c) < *(uint *)(param_1 + 0xb10)) {
        *(uint *)(param_1 + 0xb0c) = *(uint *)(param_1 + 0xb0c) + 1;
        return 0;
      }
      *(int *)(param_1 + 0xb7c) = 2;
      func_0036B758(param_1 + 0x964);
      if (*(short *)(param_1 + 0x36) != 0) {
        func_00588C14(param_1,0,1);
      }
      if (1 < *(byte *)(param_1 + 0xd48)) {
        return func_002F4E50(param_1,1);
      }
      return func_002F3468(param_1,1);
    }
    if (iVar5 != 2) {
      return 0;
    }
    if (iVar3 == 0) {
      return 0;
    }
    cVar1 = *(char *)(param_1 + 0xd48);
    if (cVar1 == '\0') {
      uVar4 = 0x15;
    }
    else {
      if (cVar1 != '\x01') {
        if (cVar1 != '\x02') {
          return 0;
        }
        func_006640EC((undefined4 *)(param_1 + 0x8c8),0x17,in_s0);
        return 0;
      }
      uVar4 = 0x16;
    }
    func_006640EC((undefined4 *)(param_1 + 0x8c8),uVar4,in_s0);
    return 0;
  }
  uVar6 = *(uint *)(param_1 + 0x1258);
  bVar9 = uVar6 < *(uint *)(param_1 + 0x125c);
  if (bVar9) {
    *(uint *)(param_1 + 0x1258) = uVar6 + 1;
  }
  uVar6 = *(uint *)(param_1 + 0x1258);
  fVar10 = fVar11;
  if ((*(uint *)(param_1 + 0x125c) != 0 && uVar6 != 0) &&
     (fVar10 = fVar12, uVar6 < *(uint *)(param_1 + 0x125c))) {
    fVar10 = (float)VectorUnsignedToFloat(uVar6,(byte)(in_fpscr >> 0x15) & 3);
    fVar10 = fVar10 * *(float *)(param_1 + 0x1260);
  }
  fparam_0 = fVar11;
  fVar13 = fVar12;
  fVar10 = func_003E19E8(fVar11,fVar11,fVar12,DAT_002e82b8,fVar10);
  func_0068A560((float *)(param_1 + 0x3d0),(float *)(param_1 + 0xe00),(float *)(param_1 + 0xbe4),
                fVar10);
  if (uVar6 == 0x14) {
    iVar3 = *(int *)(param_1 + 0x125c) - *(int *)(param_1 + 0x1258);
    *(int *)(param_1 + 0xba0) = iVar3;
    if (iVar3 == 0) {
      *(float *)(param_1 + 0xba4) = fparam_0;
    }
    else {
      fVar11 = (float)VectorUnsignedToFloat(iVar3,(byte)(in_fpscr >> 0x15) & 3);
      fVar11 = fVar13 / fVar11;
      *(float *)(param_1 + 0xba4) = fVar11;
    }
    *(uint *)(param_1 + 0xb9c) = 0;
  }
  else if ((int)uVar6 < 0x14) goto LAB_002e80a0;
  uVar7 = *(uint *)(param_1 + 0xb9c);
  uVar8 = *(uint *)(param_1 + 0xba0);
  if (uVar7 < uVar8) {
    uVar7 = uVar7 + 1;
    *(uint *)(param_1 + 0xb9c) = uVar7;
  }
  if (uVar8 != 0) {
    uVar7 = *(uint *)(param_1 + 0xb9c);
  }
  fVar10 = fparam_0;
  if ((uVar8 != 0 && uVar7 != 0) && (fVar10 = fVar13, uVar7 < uVar8)) {
    fVar11 = *(float *)(param_1 + 0xba4);
    fVar10 = (float)VectorUnsignedToFloat(uVar7,(byte)(in_fpscr >> 0x15) & 3);
    fVar10 = fVar10 * fVar11;
  }
  func_002F618C(param_1,fVar13 - fVar10);
LAB_002e80a0:
  if (uVar6 == 10) {
    *(undefined1 *)(param_1 + 0xe0e) = 1;
    local_34 = *(float *)(param_1 + 0xe30);
    uStack_2c = *(undefined4 *)(param_1 + 0xe38);
    local_30 = *(undefined4 *)(param_1 + 0xde0);
    func_00115C70(&local_98,(float *)(param_1 + 0x3d0),&local_34);
    local_40 = local_98;
    local_38 = local_90;
    local_3c = fparam_0;
    func_00115DC8(&local_40);
    iVar3 = func_0068C690(&local_40);
    local_28[0] = 0;
    local_4c = func_0054F764((undefined4 *)(param_1 + 0xe30),iVar3,local_28);
    local_48 = albw_s012_get()[1];
    fStack_44 = albw_s012_get()[2];
    if ((*(int *)(param_1 + 0x344) != 0) &&
       (func_004A1B9C((int *)&local_98,*(int *)(param_1 + 0x344),(uint *)(s_cf_002e82c0)),
       iVar3 = iStack_94, fVar12 = local_98, local_98 != 0.0)) {
      local_48 = *(float *)(param_1 + 0xc);
      func_004D8054(&local_4c,*(uint *)(param_1 + 1000),fparam_0);
      iStack_94 = *(undefined4 *)(param_1 + 1000);
      local_98 = DAT_002e82c8;
      local_90 = 0;
      func_0049216C(afStack_88,(uint *)&local_98,&local_4c);
      if (fVar12 != 0.0) {
        if (*(int *)((int)ALBW_AS_U32(fVar12) + 0x1c) == iVar3) {
          func_004A2D1C((int)ALBW_AS_U32(fVar12),afStack_88);
        }
        return 0;
      }
    }
  }
  else if (!bVar9) {
    *(float *)(param_1 + 0x3dc) = fparam_0;
    *(float *)(param_1 + 0x3e0) = fparam_0;
    *(float *)(param_1 + 0x3e4) = fparam_0;
    uVar2 = _DAT_002e82bc;
    *(uint *)(param_1 + 0x59c) = *(uint *)(param_1 + 0x59c) & 0xfffffff8;
    *(undefined4 *)(param_1 + 0xb10) = 0x3c;
    *(undefined4 *)(param_1 + 0xb14) = uVar2;
    *(undefined4 *)(param_1 + 0xb0c) = 0;
    *(int *)(param_1 + 0xb7c) = *(int *)(param_1 + 0xb7c) + 1;
    return 0;
  }
  return 0;
}

