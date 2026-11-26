/* compilefix: USA 005528F0 (EU 005528C8), Ghidra-derived (build/ghidra_analyzed4).
 * Failed to compile: operand of type 'float' cannot be cast to a pointer type
 * Fixed (each an exact C form of the ARM operation; the rest is the converted Ghidra text):
 *  - (T *)<float expr> -> (T *)CF_FBITS(expr): 32-bit copy of the float (vmov/vstr), never a conversion [1]
 *  - explicit casts at pointer-type mismatches (identity on the ARM) [1]
 * Confidence: high for the fixes (each class checked against the EU disassembly on sample sites);
 * the function body otherwise has the fidelity of the Ghidra output (bare `return;` exits of
 * functions retyped non-void return 0, as the converter does). */
#include "ghidra_types.h"
#include "compilefix.h"

extern int func_00100174(int *param_1);
extern int func_00115C70(float *param_1,float *param_2,float *param_3);
extern float func_00115DC8(float *param_1);
extern int func_004D7F70(float *param_1,uint param_2);
extern int func_0052FBA0(int param_1,uint param_2);
extern float func_0054F764(undefined4 *param_1,uint param_2,uint *param_3);
extern int func_0054FA10(int param_1,uint param_2);
extern int func_0068C690(float *param_1);
extern int *DAT_00552b38;
extern float DAT_00552b3c;
extern uint *DAT_00552b40;
extern undefined4 *DAT_00552b44;
extern undefined4 DAT_00552b48;
extern float DAT_00552b4c;
extern float DAT_00552b50;
extern float DAT_00552b54;
extern float DAT_00552b58;

float *albw_s012_get(void);   /* s0..s2 of a returned vector (native/runtime/vec3ret.c) */

// USA 005528F0 <- EU 005528C8 (Ghidra, non-matching)
// GLOBAL DAT_00552b38 int *
// GLOBAL DAT_00552b3c float
// GLOBAL DAT_00552b40 uint *
// GLOBAL DAT_00552b44 undefined4 *
// GLOBAL DAT_00552b48 undefined4
// GLOBAL DAT_00552b4c float
// GLOBAL DAT_00552b50 float
// GLOBAL DAT_00552b54 float
// GLOBAL DAT_00552b58 float

undefined4 func_005528F0(int param_1,float *param_2,float *param_3,float *param_4,float fparam_0)

{
  float *pfVar1;
  int iVar2;
  float *pfVar3;
  bool bVar4;
  float fVar5;
  float fVar6;
  float in_s1;
  float in_s2;
  float fVar7;
  _Alignas(8) unsigned char albw_frame[0x60];
  #define local_5c ((uint *)(albw_frame + 0x4))
  #define local_50 (*(float *)(albw_frame + 0x10))
  #define local_4c (*(undefined4 *)(albw_frame + 0x14))
  #define fStack_48 (*(float *)(albw_frame + 0x18))
  #define local_44 (*(float *)(albw_frame + 0x1c))
  #define local_40 (*(float *)(albw_frame + 0x20))
  #define local_3c (*(undefined4 *)(albw_frame + 0x24))
  #define local_38 ((float *)(albw_frame + 0x28))
  #define local_30 (*(undefined4 *)(albw_frame + 0x30))
  pfVar1 = (float *)func_0052FBA0(*DAT_00552b38 + 0x3dbbc,*(uint *)(param_1 + 0x4f8));
  fVar7 = DAT_00552b3c;
  if (pfVar1 != (float *)0x0) {
    if (((*DAT_00552b40 & 1) == 0) && (iVar2 = func_00100174((int *)DAT_00552b40), iVar2 != 0)) {
      *DAT_00552b44 = DAT_00552b48;
    }
    iVar2 = (**(code **)CF_FBITS(*pfVar1))(pfVar1,DAT_00552b44);
    if (iVar2 == 0) {
      pfVar1 = (float *)0x0;
    }
    bVar4 = pfVar1 == (float *)0x0;
    if (!bVar4) {
      pfVar1 = pfVar1 + 0x38c;
      bVar4 = pfVar1 == (float *)0x0;
    }
    if (!bVar4) {
      fVar5 = *(float *)(param_1 + 0x3dc);
      local_50 = *pfVar1;
      fStack_48 = pfVar1[2];
      local_4c = *(undefined4 *)(param_1 + 0x448);
      fVar6 = fVar7;
      func_00115C70(local_38,(float *)(param_1 + 0x444),&local_50);
      local_44 = local_38[0];
      local_3c = local_30;
      local_40 = fVar6;
      func_00115DC8(&local_44);
      if (fVar5 <= fVar7) {
        func_004D7F70(&local_44,(int)(fparam_0 * DAT_00552b50));
      }
      else {
        func_004D7F70(&local_44,(int)(fparam_0 * DAT_00552b4c));
      }
      iVar2 = func_0068C690(&local_44);
      local_5c[0] = 0;
      fVar6 = func_0054F764((undefined4 *)(pfVar1),iVar2,local_5c);
      in_s1 = albw_s012_get()[1];
      in_s2 = albw_s012_get()[2];
      if (param_2 != (float *)0x0) {
        *param_2 = fVar6;
        param_2[1] = in_s1;
        param_2[2] = in_s2;
        param_2[1] = *(float *)(param_1 + 0x448) + DAT_00552b54;
      }
      if (param_3 != (float *)0x0) {
        pfVar3 = (float *)func_0054FA10((int)pfVar1,local_5c[0]);
        *param_3 = *pfVar3;
        param_3[1] = pfVar3[1];
        param_3[2] = pfVar3[2];
      }
      if (param_4 == (float *)0x0) {
        return 0;
      }
      pfVar1 = (float *)func_0054FA10((int)pfVar1,local_5c[0]);
      *param_4 = *pfVar1;
      param_4[1] = pfVar1[1];
      param_4[2] = pfVar1[2];
      if (fVar7 < fVar5) {
        return func_004D7F70(param_4,0x40000000);
      }
      return func_004D7F70(param_4,0xc0000000);
    }
  }
  if (param_2 != (float *)0x0) {
    *param_2 = *(float *)(param_1 + 0x444);
    param_2[1] = *(float *)(param_1 + 0x448);
    param_2[2] = *(float *)(param_1 + 0x44c);
  }
  fVar6 = DAT_00552b58;
  if (param_3 != (float *)0x0) {
    *param_3 = fVar7;
    param_3[1] = fVar7;
    param_3[2] = fVar6;
  }
  if (param_4 == (float *)0x0) {
    return 0;
  }
  *param_4 = fVar6;
  param_4[1] = fVar7;
  param_4[2] = fVar7;
  return 0;
}

