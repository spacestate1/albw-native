/* compilefix: USA 0038C3F8 (EU 0038C3D4), Ghidra-derived (build/ghidra_analyzed4).
 * Failed to compile: use of undeclared identifier 's_'
 * Fixed (each an exact C form of the ARM operation; the rest is the converted Ghidra text):
 *  - Ghidra string label with punctuation (s_T<SE_..._ADDR + n) -> s_cf_<ADDR+n>, the same code-section address (checked: add rX,pc,#imm in the ARM) [3]
 *  - Ghidra NAN(x)/INFINITY -> __builtin_isnan(x) (vcmp unordered) / +inf [1]
 *  - Ghidra -NAN/NAN constant -> the exact words 0xFFFFFFFF/0x7FFFFFFF (mvn in the ARM) [1]
 *  - explicit casts at pointer-type mismatches (identity on the ARM) [4]
 *  - implicit float<->int conversions (Ghidra COPY between a float and an int-typed variable or
 *    pool word, e.g. `fVar = _DAT_xxx;`, `puVar[3] = fVar;`) made bit copies [5]
 * Confidence: high for the fixes (each class checked against the EU disassembly on sample sites, this function's sites checked);
 * the function body otherwise has the fidelity of the Ghidra output (bare `return;` exits of
 * functions retyped non-void return 0, as the converter does). */
#include "ghidra_types.h"
#define CF_MATHCONST
extern char s_cf_0038d4df[];
extern char s_cf_0038d4e0[];
extern char s_cf_0038d90f[];
#include "compilefix.h"

extern int func_00100174(int *param_1);
extern int func_00115C54(float *param_1,float *param_2,float *param_3);
extern int func_00115C70(float *param_1,float *param_2,float *param_3);
extern int func_00115D70(float *param_1,float *param_2,float fparam_0);
extern int func_00165E28(int param_1,undefined2 param_2);
extern int func_001DD48C(int param_1,int param_2,undefined4 param_3);
extern int func_001DDAF0(int param_1,int param_2);
extern int func_0022FA24(int param_1);
extern float func_00255494(int param_1,int param_2,undefined4 param_3,float fparam_0);
extern int func_002558A8(int param_1,int param_2);
extern int func_0026F748(int param_1,int param_2,int *param_3,undefined4 *param_4);
extern float func_0028D580(uint *param_1,int param_2,undefined1 param_3,undefined1 param_4,uint param_5);
extern int func_0028D7A4(int param_1,float fparam_0);
extern float func_002900EC(int param_1,int param_2);
extern int func_00290288(int param_1);
extern int func_00297298(int param_1,int param_2);
extern int func_002D404C(int param_1);
extern int func_002D455C(int *param_1,int param_2,byte param_3,int param_4);
extern int func_002D55D0(int param_1,uint param_2);
extern int func_002D55E8(int param_1);
extern int func_0033CFB0(undefined4 *param_1,float *param_2);
extern int func_0038BF34(int param_1,uint param_2);
extern int func_0038C284(int param_1,int param_2);
extern int func_0039F0F0(int param_1);
extern int func_003B59C8(int param_1);
extern int func_004356B4(int *param_1);
extern int func_004905E0(float fparam_0);
extern int func_004C6654(int param_1,uint param_2);
extern int func_004CBB0C(undefined4 *param_1,uint param_2,int param_3,undefined4 param_4);
extern int func_004CD094(undefined4 param_1,int param_2);
extern int func_004CDB2C(int param_1,int *param_2);
extern int func_004D80A4(float *param_1,uint param_2,float fparam_0);
extern int func_004E74E8(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,int param_4);
extern int func_004EA104(int param_1,int *param_2,int param_3);
extern int func_004EAF8C(int param_1,int *param_2,int param_3);
extern float func_00513D68(int param_1);
extern int func_00519E70(int param_1,undefined4 *param_2);
extern int func_0051AA44(int param_1);
extern int func_0051B1D0(int param_1,undefined1 param_2);
extern int func_0051D2CC(int *param_1,int param_2,float fparam_0);
extern int func_0052FBA0(int param_1,uint param_2);
extern int func_00537C14(int param_1,int param_2);
extern int func_0053ED3C(int param_1);
extern int func_0053ED74(int param_1);
extern float func_0053EDC8(int param_1);
extern int func_0053EDD8(int param_1);
extern float func_0053EE30(int param_1);
extern int func_0054CF24(int param_1);
extern int func_005826A4(int param_1,int *param_2,int *param_3,int *param_4);
extern int func_00587F74(int param_1,int *param_2,int param_3);
extern int func_0058D840(int param_1);
extern int func_0058DA24(int param_1);
extern float DAT_0038c77c;
extern float DAT_0038c780;
extern int DAT_0038c784;
extern uint *DAT_0038c788;
extern undefined4 *DAT_0038c78c;
extern undefined4 DAT_0038c790;
extern undefined4 DAT_0038c794;
extern int *DAT_0038c798;
extern int *DAT_0038c79c;
extern int DAT_0038c7a0;
extern undefined4 DAT_0038cb6c;
extern float DAT_0038cb70;
extern int DAT_0038cb74;
extern undefined4 DAT_0038cb78;
extern int *DAT_0038cb7c;
extern float DAT_0038cb80;
extern uint *DAT_0038cb84;
extern undefined4 *DAT_0038cb88;
extern int *DAT_0038d0e0;
extern float DAT_0038d0e4;
extern int *DAT_0038d0e8;
extern float DAT_0038d0ec;
extern int *DAT_0038d0f0;
extern float DAT_0038d4c8;
extern int *DAT_0038d4cc;
extern float DAT_0038d4d0;
extern float DAT_0038d4d4;
extern int DAT_0038d4d8;
extern undefined DAT_0038d4dc;
extern uint *DAT_0038d510;
extern undefined4 *DAT_0038d514;
extern float DAT_0038d8fc;
extern uint *DAT_0038d900;
extern undefined4 *DAT_0038d904;
extern undefined4 *DAT_0038d908;
extern undefined DAT_0038d90c;
extern int *DAT_0038d930;
extern int *DAT_0038dc68;
extern uint *DAT_0038dc6c;
extern undefined4 *DAT_0038dc70;
extern undefined4 DAT_0038dc74;
extern float DAT_0038dc78;
extern uint *DAT_0038dc7c;
extern undefined4 *DAT_0038dc80;
extern undefined4 DAT_0038dc84;
extern float DAT_0038dc88;
extern float DAT_0038de58;
extern float DAT_0038de5c;
extern char *DAT_0038de60;
extern float DAT_0038de64;
extern float DAT_0038de68;
extern char s_Common_0038d928[];
extern char s_SE_PV_USE_FRUIT_DORON_0038d4f8[];
extern char s_SE_S_WARP_BELL_MISS_0038d4b4[];
extern char s__cmn_special_milk_use_0038d90f[];
extern char s_cmn_messagebottle_use_0038dc50[];
extern undefined4 _DAT_0038d4dc;
extern undefined4 _DAT_0038d90c;

float *albw_s012_get(void);   /* s0..s2 of a returned vector (native/runtime/vec3ret.c) */

// USA 0038C3F8 <- EU 0038C3D4 (Ghidra, non-matching)
// GLOBAL DAT_0038c77c float
// GLOBAL DAT_0038c780 float
// GLOBAL DAT_0038c784 int
// GLOBAL DAT_0038c788 uint *
// GLOBAL DAT_0038c78c undefined4 *
// GLOBAL DAT_0038c790 undefined4
// GLOBAL DAT_0038c794 undefined4
// GLOBAL DAT_0038c798 int *
// GLOBAL DAT_0038c79c int *
// GLOBAL DAT_0038c7a0 int
// GLOBAL DAT_0038cb6c undefined4
// GLOBAL DAT_0038cb70 float
// GLOBAL DAT_0038cb74 int
// GLOBAL DAT_0038cb78 undefined4
// GLOBAL DAT_0038cb7c int *
// GLOBAL DAT_0038cb80 float
// GLOBAL DAT_0038cb84 uint *
// GLOBAL DAT_0038cb88 undefined4 *
// GLOBAL DAT_0038d0e0 int *
// GLOBAL DAT_0038d0e4 float
// GLOBAL DAT_0038d0e8 int *
// GLOBAL DAT_0038d0ec float
// GLOBAL DAT_0038d0f0 int *
// GLOBAL DAT_0038d4c8 float
// GLOBAL DAT_0038d4cc int *
// GLOBAL DAT_0038d4d0 float
// GLOBAL DAT_0038d4d4 float
// GLOBAL DAT_0038d4d8 int
// GLOBAL DAT_0038d4dc undefined
// GLOBAL DAT_0038d510 uint *
// GLOBAL DAT_0038d514 undefined4 *
// GLOBAL DAT_0038d8fc float
// GLOBAL DAT_0038d900 uint *
// GLOBAL DAT_0038d904 undefined4 *
// GLOBAL DAT_0038d908 undefined4 *
// GLOBAL DAT_0038d90c undefined
// GLOBAL DAT_0038d930 int *
// GLOBAL DAT_0038dc68 int *
// GLOBAL DAT_0038dc6c uint *
// GLOBAL DAT_0038dc70 undefined4 *
// GLOBAL DAT_0038dc74 undefined4
// GLOBAL DAT_0038dc78 float
// GLOBAL DAT_0038dc7c uint *
// GLOBAL DAT_0038dc80 undefined4 *
// GLOBAL DAT_0038dc84 undefined4
// GLOBAL DAT_0038dc88 float
// GLOBAL DAT_0038de58 float
// GLOBAL DAT_0038de5c float
// GLOBAL DAT_0038de60 char *
// GLOBAL DAT_0038de64 float
// GLOBAL DAT_0038de68 float
// GLOBAL s_cf_0038d90f string
// GLOBAL s_cf_0038d4df string
// GLOBAL s_Common_0038d928 string
// GLOBAL s_SE_PV_USE_FRUIT_DORON_0038d4f8 string
// GLOBAL s_SE_S_WARP_BELL_MISS_0038d4b4 string
// GLOBAL s_cmn_messagebottle_use_0038dc50 string

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 func_0038C3F8(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  bool bVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  float *pfVar6;
  int iVar7;
  uint uVar8;
  int *piVar9;
  int *piVar10;
  int iVar11;
  int iVar12;
  float in_s0;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  undefined4 uVar17;
  _Alignas(8) unsigned char albw_frame[0x90];
  #define local_8c (*(float *)(albw_frame + 0x4))
  #define local_88 (*(float *)(albw_frame + 0x8))
  #define local_84 (*(char * *)(albw_frame + 0xc))
  #define local_80 (*(int *)(albw_frame + 0x10))
  #define local_7c (*(undefined4 *)(albw_frame + 0x14))
  #define local_78 (*(int *)(albw_frame + 0x18))
  #define local_74 (*(float *)(albw_frame + 0x1c))
  #define local_70 (*(float *)(albw_frame + 0x20))
  #define local_6c (*(char * *)(albw_frame + 0x24))
  #define local_68 (*(float *)(albw_frame + 0x28))
  #define local_64 (*(undefined4 *)(albw_frame + 0x2c))
  #define local_5c (*(char * *)(albw_frame + 0x34))
  #define iStack_58 (*(int *)(albw_frame + 0x38))
  #define uStack_54 (*(undefined4 *)(albw_frame + 0x3c))
  #define local_50 (*(char * *)(albw_frame + 0x40))
  #define iStack_4c (*(int *)(albw_frame + 0x44))
  #define uStack_48 (*(undefined4 *)(albw_frame + 0x48))
  #define local_44 (*(char * *)(albw_frame + 0x4c))
  #define iStack_40 (*(int *)(albw_frame + 0x50))
  #define uStack_3c (*(undefined4 *)(albw_frame + 0x54))
  #define local_38 ((float *)(albw_frame + 0x58))
  fVar16 = DAT_0038d8fc;
  fVar14 = DAT_0038d0ec;
  fVar13 = DAT_0038d0e4;
  fVar15 = DAT_0038c780;
  switch(param_2) {
  case 0x9c:
    iVar7 = func_002D55E8(param_1);
    if (iVar7 != 0) {
      return 0;
    }
    func_0051D2CC(*(int **)(param_1 + 0x3c),*(int *)(param_1 + 0x58),DAT_0038c77c);
    fVar15 = DAT_0038c780;
    if (DAT_0038c780 < *(float *)(*(int *)(param_1 + 0x48) + 0x24)) {
      fVar13 = func_0053EDC8(*(int *)(param_1 + 0x4c) + 0x5c);
      fVar14 = func_0053EE30(*(int *)(param_1 + 0x4c) + 0x5c);
      if ((int)ALBW_AS_U32((fVar13 - fVar14)) <= DAT_0038c784) {
        puVar4 = *(undefined4 **)(param_1 + 0x14c);
        if (((*DAT_0038c788 & 1) == 0) && (iVar7 = func_00100174((int *)DAT_0038c788), iVar7 != 0))
        {
          *DAT_0038c78c = DAT_0038c790;
        }
        if ((puVar4 == (undefined4 *)0x0) ||
           (iVar7 = (**(code **)*puVar4)(puVar4,DAT_0038c78c), iVar7 == 0)) {
          puVar4 = (undefined4 *)0x0;
        }
        func_003B59C8((int)puVar4);
        func_0038C284(param_1,0);
        return func_002D55D0(param_1,1);
      }
    }
    iVar7 = func_0053EDD8(*(int *)(param_1 + 0x4c) + 0x3c);
    if (iVar7 == 0) {
      uVar8 = *(uint *)(*(int *)(param_1 + 0x2c) + 0x44);
      if ((9 < uVar8) && (uVar8 < 0xd)) {
        uVar17 = DAT_0038c794;
        iVar7 = func_0053ED74(*(int *)(param_1 + 0x4c));
        *(undefined4 *)(param_1 + 0x74) = *(undefined4 *)(iVar7 + 0xc);
        *(undefined4 *)(param_1 + 0x78) = *(undefined4 *)(iVar7 + 0x1c);
        *(undefined4 *)(param_1 + 0x7c) = *(undefined4 *)(iVar7 + 0x2c);
        *(undefined4 *)(param_1 + 200) = uVar17;
        func_004356B4((int *)(param_1 + 0x70));
        *(undefined1 *)(param_1 + 0xed) = 0xd;
        *(undefined1 *)(param_1 + 0xee) = 0;
        *(undefined1 *)(param_1 + 0xef) = 1;
        piVar3 = DAT_0038c798;
        if (*(int *)(*(int *)(param_1 + 0x28) + 0x464) == 3) {
          uVar8 = 0x10;
        }
        else {
          uVar8 = 2;
        }
        *(short *)(param_1 + 0xfc) = (short)uVar8;
        if (*(char *)(*piVar3 + 0x18) == '\a' || *(char *)(*piVar3 + 0x18) == '%') {
          *(short *)(param_1 + 0xfc) = (short)(uVar8 >> 1);
        }
        func_0038C284(param_1,1);
      }
      iVar7 = func_0053ED74(*(int *)(param_1 + 0x4c));
      local_88 = *(float *)(iVar7 + 0xc);
      local_84 = *(char **)(iVar7 + 0x1c);
      local_80 = *(int *)(iVar7 + 0x2c);
      local_78 = *(int *)(*(int *)(param_1 + 0x28) + 0x2cc);
      return func_0026F748(*(int *)(*DAT_0038c79c + 0xf9c),9,&local_78,(undefined4 *)(&local_88));
    }
    puVar4 = *(undefined4 **)(param_1 + 0x14c);
    if (((*DAT_0038c788 & 1) == 0) && (iVar7 = func_00100174((int *)DAT_0038c788), iVar7 != 0)) {
      *DAT_0038c78c = DAT_0038c790;
    }
    if ((puVar4 == (undefined4 *)0x0) ||
       (iVar7 = (**(code **)*puVar4)(puVar4,DAT_0038c78c), iVar7 == 0)) {
      puVar4 = (undefined4 *)0x0;
    }
    func_003B59C8((int)puVar4);
    *(undefined1 *)(puVar4 + 0xb) = 0;
    func_0038C284(param_1,0);
    if (fVar15 < *(float *)(*(int *)(param_1 + 0x48) + 0x24)) {
LAB_0038cec0:
      uVar8 = 1;
      goto LAB_0038c5e0;
    }
    goto LAB_0038cec8;
  case 0x9d:
    iVar7 = func_002D55E8(param_1);
    fVar15 = DAT_0038c780;
    if (iVar7 != 0) {
      return 0;
    }
    if (*(int *)(param_1 + 0x170) != 0) {
      *(int *)(param_1 + 0x170) = *(int *)(param_1 + 0x170) + -1;
    }
    if (fVar15 < *(float *)(*(int *)(param_1 + 0x48) + 0x24)) {
      fVar13 = func_0053EDC8(*(int *)(param_1 + 0x4c) + 0x5c);
      fVar14 = func_0053EE30(*(int *)(param_1 + 0x4c) + 0x5c);
      if ((int)ALBW_AS_U32((fVar13 - fVar14)) <= DAT_0038c7a0) {
        func_0038C284(param_1,0);
        return func_002D55D0(param_1,1);
      }
    }
    iVar7 = func_0053EDD8(*(int *)(param_1 + 0x4c) + 0x3c);
    if (iVar7 == 0) {
      if (*(int *)(param_1 + 0x170) != 0) {
        *(undefined4 *)(*(int *)(param_1 + 0x50) + 0x4d0) = DAT_0038cb6c;
        fVar13 = DAT_0038cb70;
        if (*(char *)(param_1 + 0x174) != '\0') {
          bVar1 = *(byte *)(*(int *)(param_1 + 0x50) + 0x324);
          if ((((bVar1 & 1) == 0) && ((bVar1 & 8) == 0)) &&
             (*(char *)(*(int *)(param_1 + 0x50) + 0x168) == '\0')) {
            *(float *)(*(int *)(param_1 + 0x34) + 4) = fVar15;
            func_0028D7A4(*(int *)(param_1 + 0x4c) + 0x5c,fVar13);
            func_0028D580((uint *)(*(int *)(param_1 + 0x4c) + 0x5c),10,1,1,6);
            if (*(int *)(param_1 + 0x170) == 0) {
              fVar13 = *(float *)(param_1 + 0x178) - *(float *)(*(int *)(param_1 + 0x30) + 4);
              if (fVar13 <= fVar15) {
                fVar13 = -fVar13;
              }
              if ((int)ALBW_AS_U32(fVar13) < DAT_0038cb74) {
                func_002D55D0(param_1,8);
              }
            }
          }
        }
LAB_0038c8d4:
        uVar17 = DAT_0038cb78;
        if (*(char *)(param_1 + 0x141) == '\0') {
          iVar7 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x150) + 4) + 0x24) + 0x14) +
                  *(int *)(param_1 + 0x160) * 0x30;
          *(undefined4 *)(param_1 + 0x74) = *(undefined4 *)(iVar7 + 0xc);
          *(undefined4 *)(param_1 + 0x78) = *(undefined4 *)(iVar7 + 0x1c);
          *(undefined4 *)(param_1 + 0x7c) = *(undefined4 *)(iVar7 + 0x2c);
          *(undefined4 *)(param_1 + 200) = uVar17;
          func_004356B4((int *)(param_1 + 0x70));
          *(uint *)(param_1 + 0x9c) = *(uint *)(param_1 + 0x9c) | 8;
          *(undefined1 *)(param_1 + 0xed) = 0xe;
          *(undefined1 *)(param_1 + 0xee) = 0;
          piVar3 = DAT_0038c798;
          if (*(int *)(*(int *)(param_1 + 0x28) + 0x468) == 3) {
            uVar8 = 0x10;
          }
          else {
            uVar8 = 2;
          }
          *(short *)(param_1 + 0xfc) = (short)uVar8;
          if (*(char *)(*piVar3 + 0x18) == '\a' || *(char *)(*piVar3 + 0x18) == '%') {
            *(short *)(param_1 + 0xfc) = (short)(uVar8 >> 1);
          }
          if (10 < *(uint *)(*(int *)(param_1 + 0x2c) + 0x44)) {
            return func_0038C284(param_1,1);
          }
        }
        return func_0038C284(param_1,0);
      }
      if (*(char *)(param_1 + 0x174) == '\0') goto LAB_0038c8d4;
    }
    func_0038C284(param_1,0);
    if (*(float *)(*(int *)(param_1 + 0x48) + 0x24) <= fVar15) {
LAB_0038c82c:
      uVar8 = 0;
      goto LAB_0038c830;
    }
    break;
  case 0x9e:
    if (*(int *)(param_1 + 0x168) == 3) {
      pfVar6 = *(float **)(param_1 + 0x34);
      *pfVar6 = DAT_0038c780;
      pfVar6[1] = fVar15;
      pfVar6[2] = fVar15;
      if (*(char *)(param_1 + 0x147) == '\0') {
        return 0;
      }
      iVar7 = *(int *)(*DAT_0038cb7c + 0x44);
      if ((iVar7 != 0) && (iVar7 == *(int *)(*(int *)(param_1 + 0x2c) + 100))) {
        iVar7 = func_002D55E8(param_1);
        if (iVar7 != 0) {
          return 0;
        }
        if (((*(char *)(*DAT_0038c798 + 0x18) != '\a') && (*(char *)(*DAT_0038c798 + 0x18) != '%'))
           || (*(int *)(param_1 + 0x168) == 3)) {
          func_0051D2CC(*(int **)(param_1 + 0x3c),0,DAT_0038cb80);
        }
        if (*(int *)(*(int *)(param_1 + 0x2c) + 0x44) == 0x14) {
          func_002558A8(*(int *)(param_1 + 0x28) + 0x40c,*(int *)(param_1 + 0x164) + 0x12);
          puVar4 = *(undefined4 **)(param_1 + 0x154);
          if (((*DAT_0038cb84 & 1) == 0) && (iVar7 = func_00100174((int *)DAT_0038cb84), iVar7 != 0)
             ) {
            *DAT_0038cb88 = DAT_0038c790;
          }
          if ((puVar4 == (undefined4 *)0x0) ||
             (iVar7 = (**(code **)*puVar4)(puVar4,DAT_0038cb88), iVar7 == 0)) {
            puVar4 = (undefined4 *)0x0;
          }
          func_0039F0F0((int)puVar4);
        }
        if ((*(int *)(param_1 + 0x168) == 3) && (*(int *)(*(int *)(param_1 + 0x2c) + 0x44) == 0x1b))
        {
          bVar2 = true;
        }
        else {
          bVar2 = false;
        }
        iVar7 = func_0053EDD8(*(int *)(param_1 + 0x4c) + 0x3c);
        if (iVar7 == 0 && !bVar2) {
          return 0;
        }
        goto switchD_0038cda0_caseD_3;
      }
      func_004CDB2C(*DAT_0038cb7c,*(int **)(*(int *)(param_1 + 0x2c) + 0x60));
      if (*(float *)(*(int *)(param_1 + 0x48) + 0x24) <= fVar15) goto LAB_0038c82c;
    }
    else {
      iVar7 = func_002D55E8(param_1);
      if (iVar7 != 0) {
        return 0;
      }
      if ((*(char *)(*DAT_0038c798 + 0x18) != '\a' && *(char *)(*DAT_0038c798 + 0x18) != '%') ||
         (*(int *)(param_1 + 0x168) == 3)) {
        func_0051D2CC(*(int **)(param_1 + 0x3c),0,DAT_0038cb80);
      }
      if (*(int *)(*(int *)(param_1 + 0x2c) + 0x44) == 0x14) {
        iVar7 = *(int *)(param_1 + 0x28);
        iVar12 = *(int *)(param_1 + 0x164);
        iVar11 = *(int *)(param_1 + 0x168);
        if (iVar11 == 8) {
          func_001DD48C(iVar7,4,1);
        }
        else if (iVar11 < 9) {
          if (iVar11 == 1) {
            func_001DD48C(iVar7,0x20,1);
            iVar11 = *DAT_0038d0e0;
            if (iVar11 != 0) {
              uVar8 = 0x1b;
              goto LAB_0038cce0;
            }
          }
          else if (iVar11 == 2) {
            func_001DD48C(iVar7,0x50,1);
            if (*DAT_0038d0e0 != 0) {
              func_004C6654(*DAT_0038d0e0,0x1c);
            }
          }
          else if (iVar11 == 4) {
            func_002D404C(iVar7);
          }
        }
        else {
          if (iVar11 == 0xc) {
            func_001DD48C(iVar7,0x14,1);
            iVar11 = *DAT_0038d0e0;
          }
          else {
            if (iVar11 != 0xd) goto LAB_0038cce4;
            func_001DD48C(iVar7,0x14,1);
            iVar11 = *DAT_0038d0e0;
          }
          if (iVar11 != 0) {
            uVar8 = 0x1f;
LAB_0038cce0:
            func_004C6654(iVar11,uVar8);
          }
        }
LAB_0038cce4:
        func_002558A8(iVar7 + 0x40c,iVar12 + 0x12);
        puVar4 = *(undefined4 **)(param_1 + 0x154);
        if (((*DAT_0038cb84 & 1) == 0) && (iVar7 = func_00100174((int *)DAT_0038cb84), iVar7 != 0))
        {
          *DAT_0038cb88 = DAT_0038c790;
        }
        if ((puVar4 == (undefined4 *)0x0) ||
           (iVar7 = (**(code **)*puVar4)(puVar4,DAT_0038cb88), iVar7 == 0)) {
          puVar4 = (undefined4 *)0x0;
        }
        func_0039F0F0((int)puVar4);
      }
      if ((*(int *)(param_1 + 0x168) == 3) && (*(int *)(*(int *)(param_1 + 0x2c) + 0x44) == 0x1b)) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
      iVar7 = func_0053EDD8(*(int *)(param_1 + 0x4c) + 0x3c);
      fVar15 = DAT_0038d0e4;
      if (iVar7 == 0 && !bVar2) {
        return 0;
      }
      switch(*(undefined4 *)(param_1 + 0x168)) {
      case 0:
      case 1:
      case 2:
      case 8:
      case 0xb:
      case 0xc:
      case 0xd:
        fVar13 = *(float *)(*(int *)(param_1 + 0x48) + 0x24);
        break;
      case 3:
switchD_0038cda0_caseD_3:
        return func_002D55D0(param_1,0x30);
      case 4:
        *(undefined1 *)(*(int *)(param_1 + 0x2c) + 0xb0) = 1;
        fVar13 = *(float *)(*(int *)(param_1 + 0x48) + 0x24);
        break;
      default:
        goto switchD_0038c3e8_default;
      }
      if (fVar13 <= fVar15) goto LAB_0038c82c;
    }
    break;
  case 0x9f:
    iVar7 = func_002D55E8(param_1);
    if (iVar7 != 0) {
      return 0;
    }
    iVar7 = func_0053EDD8(*(int *)(param_1 + 0x4c) + 0x3c);
    if (iVar7 == 0) {
      return 0;
    }
    func_002558A8(*(int *)(param_1 + 0x28) + 0x40c,*(int *)(param_1 + 0x164) + 0x12);
    local_8c = **(float **)(*DAT_0038d0e8 + 0x24);
    func_004E74E8(*(undefined4 **)(*DAT_0038d0e8 + 0x1c),(undefined4 *)(&local_8c),1,-1);
    if (DAT_0038d0e4 < *(float *)(*(int *)(param_1 + 0x48) + 0x24)) goto LAB_0038cec0;
LAB_0038cec8:
    uVar8 = 0;
LAB_0038c5e0:
    return func_002D55D0(param_1,uVar8);
  case 0xa0:
    iVar7 = func_002D55E8(param_1);
    if (iVar7 != 0) {
      return 0;
    }
    iVar7 = func_0053EDD8(*(int *)(param_1 + 0x4c) + 0x3c);
    if (iVar7 == 0) {
      return 0;
    }
    iVar12 = *(int *)(param_1 + 0x164) + 0x12;
    iVar11 = *(int *)(param_1 + 0x28) + 0x40c;
    iVar7 = func_00537C14(iVar11,iVar12);
    if (iVar7 == 7) {
      iVar7 = func_0053ED3C(*(int *)(param_1 + 0x4c));
      local_84 = *(char **)(iVar7 + 0xc);
      local_80 = *(int *)(iVar7 + 0x1c);
      local_7c = *(undefined4 *)(iVar7 + 0x2c);
      func_004CBB0C((undefined4 *)(&local_84),2,1,0);
    }
    else {
      iVar7 = func_0053ED3C(*(int *)(param_1 + 0x4c));
      local_84 = *(char **)(iVar7 + 0xc);
      local_80 = *(int *)(iVar7 + 0x1c);
      local_7c = *(undefined4 *)(iVar7 + 0x2c);
      func_004CBB0C((undefined4 *)(&local_84),2,0,0);
    }
    func_002558A8(iVar11,iVar12);
    if (*(float *)(*(int *)(param_1 + 0x48) + 0x24) <= DAT_0038d0e4) goto LAB_0038c82c;
    break;
  case 0xa1:
    pfVar6 = *(float **)(param_1 + 0x34);
    *pfVar6 = DAT_0038d0e4;
    pfVar6[1] = fVar13;
    pfVar6[2] = fVar13;
    func_0051D2CC(*(int **)(param_1 + 0x3c),0,DAT_0038d0ec);
    *(ushort *)(*DAT_0038d0f0 + 0x33e) = *(ushort *)(*DAT_0038d0f0 + 0x33e) | 4;
    return 0;
  case 0xa2:
    pfVar6 = *(float **)(param_1 + 0x34);
    *pfVar6 = DAT_0038d0e4;
    pfVar6[1] = fVar13;
    pfVar6[2] = fVar13;
    fVar15 = DAT_0038d0ec;
    if (*(char *)(param_1 + 0x147) == '\0') {
      return 0;
    }
    piVar3 = *(int **)(*(int *)(param_1 + 0x2c) + 0x74);
    piVar9 = *(int **)(*DAT_0038cb7c + 0x44);
    if ((piVar9 == (int *)0x0) || (piVar9 != piVar3)) {
      func_004CDB2C(*DAT_0038cb7c,piVar3);
      if (*(float *)(*(int *)(param_1 + 0x48) + 0x24) <= fVar13) goto LAB_0038c82c;
    }
    else {
      if (*(char *)(param_1 + 0x148) == '\0') {
        *(undefined1 *)(param_1 + 0x148) = 1;
        local_84 = s_SE_S_WARP_BELL_MISS_0038d4b4;
        local_88 = DAT_0038d4c8;
        return func_00587F74(*DAT_0038d4cc,(int *)&local_88,0);
      }
      pfVar6 = *(float **)(param_1 + 0x34);
      *pfVar6 = fVar13;
      pfVar6[1] = fVar13;
      pfVar6[2] = fVar13;
      func_0051D2CC(*(int **)(param_1 + 0x3c),0,fVar15);
      iVar7 = func_0053EDD8(*(int *)(param_1 + 0x4c) + 0x3c);
      if (iVar7 == 0) {
        return 0;
      }
      func_0022FA24(*(int *)(*(int *)(param_1 + 0x2c) + 0x74));
      if (*(float *)(*(int *)(param_1 + 0x48) + 0x24) <= fVar13) goto LAB_0038c82c;
    }
    break;
  case 0xa3:
    pfVar6 = *(float **)(param_1 + 0x34);
    *pfVar6 = DAT_0038d0e4;
    pfVar6[1] = fVar13;
    pfVar6[2] = fVar13;
    func_0051D2CC(*(int **)(param_1 + 0x3c),0,fVar14);
    if (*(int *)(*DAT_0038cb7c + 0x44) != 0) {
      return 0;
    }
    func_00290288(*(int *)(param_1 + 0x2c));
    if (*(float *)(*(int *)(param_1 + 0x48) + 0x24) <= fVar13) goto LAB_0038c82c;
    break;
  case 0xa4:
    iVar7 = func_002D55E8(param_1);
    if (iVar7 != 0) {
      return 0;
    }
    func_0051D2CC(*(int **)(param_1 + 0x3c),*(int *)(param_1 + 0x58),DAT_0038d4d0);
    fVar15 = func_0053EE30(*(int *)(param_1 + 0x4c) + 0x3c);
    fVar13 = func_0053EDC8(*(int *)(param_1 + 0x4c) + 0x3c);
    if ((int)fVar15 == (int)(fVar13 - DAT_0038d4d4)) {
      func_0038BF34(param_1,*(uint *)(param_1 + 0x58));
    }
    iVar7 = func_0053EDD8(*(int *)(param_1 + 0x4c) + 0x3c);
    if (iVar7 == 0) {
      return 0;
    }
    if (*(float *)(*(int *)(param_1 + 0x48) + 0x24) <= DAT_0038d0e4) goto LAB_0038c82c;
    break;
  case 0xa5:
    iVar7 = func_002D55E8(param_1);
    if (iVar7 != 0) {
      return 0;
    }
    fVar15 = DAT_0038d0e4;
    if (DAT_0038d0e4 < *(float *)(*(int *)(param_1 + 0x48) + 0x24)) {
      fVar13 = func_0053EDC8(*(int *)(param_1 + 0x4c) + 0x5c);
      fVar14 = func_0053EE30(*(int *)(param_1 + 0x4c) + 0x5c);
      if ((int)ALBW_AS_U32((fVar13 - fVar14)) <= DAT_0038d4d8) {
        if (*(float *)(*(int *)(param_1 + 0x48) + 0x24) <= fVar15) goto LAB_0038c82c;
        break;
      }
    }
    iVar7 = func_0053EDD8(*(int *)(param_1 + 0x4c) + 0x3c);
    if (iVar7 == 0) {
      return 0;
    }
    if (*(float *)(*(int *)(param_1 + 0x48) + 0x24) <= fVar15) goto LAB_0038c82c;
    break;
  case 0xa6:
    pfVar6 = *(float **)(param_1 + 0x34);
    *pfVar6 = DAT_0038d0e4;
    pfVar6[1] = fVar13;
    pfVar6[2] = fVar13;
    if (*(char *)(param_1 + 0x147) == '\0') {
      return 0;
    }
    piVar3 = *(int **)(*(int *)(param_1 + 0x2c) + 0x60);
    piVar9 = *(int **)(*DAT_0038cb7c + 0x44);
    if ((piVar9 != (int *)0x0) && (piVar9 == piVar3)) {
      iVar7 = func_002D55E8(param_1);
      if (iVar7 != 0) {
        return 0;
      }
      if ((*(char *)(*DAT_0038c798 + 0x18) != '\a') && (*(char *)(*DAT_0038c798 + 0x18) != '%')) {
        in_s0 = ALBW_AS_F32(_DAT_0038d4dc);
        func_0051D2CC(*(int **)(param_1 + 0x3c),0,ALBW_AS_F32(_DAT_0038d4dc));
      }
      piVar3 = DAT_0038d4cc;
      fVar15 = DAT_0038d4c8;
      if (*(int *)(*(int *)(param_1 + 0x2c) + 0x44) == 2) {
        local_84 = s_cf_0038d4e0;
        local_88 = DAT_0038d4c8;
        func_004EA104(*DAT_0038d4cc,(int *)&local_88,0);
        local_84 = s_SE_PV_USE_FRUIT_DORON_0038d4f8;
        local_88 = fVar15;
        func_004EAF8C(*piVar3,(int *)&local_88,0);
        puVar4 = *(undefined4 **)(param_1 + 0x158);
        if (((*DAT_0038d510 & 1) == 0) && (iVar7 = func_00100174((int *)DAT_0038d510), iVar7 != 0))
        {
          *DAT_0038d514 = DAT_0038c790;
        }
        if ((puVar4 == (undefined4 *)0x0) ||
           (iVar7 = (**(code **)*puVar4)(puVar4,DAT_0038d514), iVar7 == 0)) {
          puVar4 = (undefined4 *)0x0;
        }
        *(undefined1 *)(puVar4 + 7) = 0;
      }
      if (*(int *)(*(int *)(param_1 + 0x2c) + 0x44) == 0x1f) {
        puVar4 = *(undefined4 **)(param_1 + 0x158);
        if (((*DAT_0038d510 & 1) == 0) && (iVar7 = func_00100174((int *)DAT_0038d510), iVar7 != 0))
        {
          *DAT_0038d514 = DAT_0038c790;
        }
        if ((puVar4 == (undefined4 *)0x0) ||
           (iVar7 = (**(code **)*puVar4)(puVar4,DAT_0038d514), iVar7 == 0)) {
          puVar4 = (undefined4 *)0x0;
        }
        *(undefined1 *)(puVar4 + 7) = 1;
      }
      if (*(int *)(*(int *)(param_1 + 0x2c) + 0x44) == 0x37) {
        *(undefined1 *)(*(int *)(param_1 + 0x28) + 0x6bc) = 0;
        *(undefined1 *)(*(int *)(param_1 + 0x28) + 0x6c6) = 1;
        func_00297298(*DAT_0038d4cc,0xf);
      }
      if (*(int *)(*(int *)(param_1 + 0x2c) + 0x44) == 0x78) {
        *(undefined1 *)(param_1 + 0x142) = 1;
        func_00255494(*(int *)(param_1 + 0x28) + 0x40c,0x10,0,in_s0);
        return 0;
      }
      return 0;
    }
    func_004CDB2C(*DAT_0038cb7c,piVar3);
    if (*(float *)(*(int *)(param_1 + 0x48) + 0x24) <= fVar13) goto LAB_0038c82c;
    break;
  case 0xa7:
    iVar7 = func_002D55E8(param_1);
    if (iVar7 != 0) {
      return 0;
    }
    if ((*(char *)(*DAT_0038c798 + 0x18) != '\a') && (*(char *)(*DAT_0038c798 + 0x18) != '%')) {
      func_0051D2CC(*(int **)(param_1 + 0x3c),0,ALBW_AS_F32(_DAT_0038d4dc));
    }
    iVar7 = func_0053EDD8(*(int *)(param_1 + 0x4c) + 0x3c);
    fVar13 = *(float *)(*(int *)(param_1 + 0x48) + 0x24);
    fVar15 = DAT_0038d8fc;
    if (fVar13 <= DAT_0038d8fc) {
LAB_0038d624:
      if (iVar7 == 0) {
        if (*(int *)(*(int *)(param_1 + 0x2c) + 0x44) == 0x1f) {
          puVar4 = *(undefined4 **)(param_1 + 0x15c);
          if (((*DAT_0038d900 & 1) == 0) && (iVar7 = func_00100174((int *)DAT_0038d900), iVar7 != 0)
             ) {
            *DAT_0038d904 = DAT_0038c790;
          }
          if ((puVar4 == (undefined4 *)0x0) ||
             (iVar7 = (**(code **)*puVar4)(puVar4,DAT_0038d904), iVar7 == 0)) {
            puVar4 = (undefined4 *)0x0;
          }
          *(undefined1 *)(puVar4 + 7) = 1;
        }
        if (*(int *)(*(int *)(param_1 + 0x2c) + 0x44) == 0x27) {
          func_004CD094(*DAT_0038d908,0);
          piVar3 = (int *)func_001DDAF0(*(int *)(param_1 + 0x28),0x11);
          if (piVar3 != (int *)0x0) {
            func_002D455C(piVar3,-1,0,0);
          }
          func_00255494(*(int *)(param_1 + 0x28) + 0x40c,0x11,0,fVar13);
          return 0;
        }
        return 0;
      }
    }
    else {
      fVar13 = func_0053EDC8(*(int *)(param_1 + 0x4c) + 0x5c);
      fVar14 = func_0053EE30(*(int *)(param_1 + 0x4c) + 0x5c);
      fVar13 = fVar13 - fVar14;
      if (DAT_0038d4d8 < (int)ALBW_AS_U32(fVar13)) goto LAB_0038d624;
    }
    if (*(float *)(*(int *)(param_1 + 0x48) + 0x24) <= fVar15) goto LAB_0038c82c;
    break;
  case 0xa8:
    iVar7 = func_002D55E8(param_1);
    if (iVar7 != 0) {
      return 0;
    }
    if ((*(char *)(*DAT_0038c798 + 0x18) != '\a') && (*(char *)(*DAT_0038c798 + 0x18) != '%')) {
      func_0051D2CC(*(int **)(param_1 + 0x3c),0,ALBW_AS_F32(_DAT_0038d90c));
    }
    piVar3 = DAT_0038d0e0;
    if (*(char *)(*(int *)(param_1 + 0x2c) + 0xc5) != '\0') {
      return 0;
    }
    iVar7 = *(int *)(param_1 + 0x164) + 0x12;
    if (*DAT_0038d0e0 != 0) {
      func_004C6654(*DAT_0038d0e0,0x23);
    }
    if (*(int *)(param_1 + 0x168) == 9) {
      func_001DD48C(*(int *)(param_1 + 0x28),4,1);
      func_002558A8(*(int *)(param_1 + 0x28) + 0x40c,iVar7);
    }
    else {
      func_001DD48C(*(int *)(param_1 + 0x28),0xc,1);
      func_002558A8(*(int *)(param_1 + 0x28) + 0x40c,iVar7);
      if (*piVar3 != 0) {
        func_004C6654(*piVar3,0x24);
      }
    }
    if (*(float *)(*(int *)(param_1 + 0x48) + 0x24) <= DAT_0038d8fc) goto LAB_0038c82c;
    break;
  case 0xa9:
    pfVar6 = *(float **)(param_1 + 0x34);
    *pfVar6 = DAT_0038d8fc;
    pfVar6[1] = fVar16;
    pfVar6[2] = fVar16;
    piVar3 = DAT_0038d0f0;
    if (*(char *)(param_1 + 0x147) == '\0') {
      return 0;
    }
    piVar9 = *(int **)(*(int *)(param_1 + 0x2c) + 0x60);
    piVar10 = *(int **)(*DAT_0038cb7c + 0x44);
    if ((piVar10 == (int *)0x0) || (piVar10 != piVar9)) {
      func_004CDB2C(*DAT_0038cb7c,piVar9);
      if (*(float *)(*(int *)(param_1 + 0x48) + 0x24) <= fVar16) goto LAB_0038c82c;
    }
    else {
      if ((*(char *)(param_1 + 0x148) == '\0') ||
         (iVar7 = func_0058DA24(*DAT_0038d0f0), fVar15 = ALBW_AS_F32(_DAT_0038d90c), iVar7 != 0)) {
        *(undefined1 *)(param_1 + 0x148) = 1;
        if (*(int *)(param_1 + 0x168) == 0xb) {
          local_78 = 0;
          local_74 = CF_NAN_NEG;
          local_80 = 0;
          local_7c = 0;
          local_70 = DAT_0038d4c8;
          local_6c = s_cmn_messagebottle_use_0038dc50;
          local_88 = DAT_0038d4c8;
          local_84 = s_Common_0038d928;
          iVar7 = func_005826A4(*DAT_0038d930,&local_80,(int *)&local_88,(int *)&local_70);
          piVar3 = DAT_0038d0f0;
        }
        else {
          if (*(int *)(param_1 + 0x168) != 0xd) {
            return 0;
          }
          local_78 = 0;
          local_74 = CF_NAN_NEG;
          local_80 = 0;
          local_7c = 0;
          local_70 = DAT_0038d4c8;
          local_6c = s__cmn_special_milk_use_0038d90f + 1;
          local_88 = DAT_0038d4c8;
          local_84 = s_Common_0038d928;
          iVar7 = func_005826A4(*DAT_0038d930,&local_80,(int *)&local_88,(int *)&local_70);
          piVar3 = DAT_0038d0f0;
        }
        if (iVar7 == 1) {
          DAT_0038d0f0 = piVar3;
          func_0051B1D0(*piVar3,0);
          return func_00519E70(*piVar3,&local_80);
        }
        DAT_0038d0f0 = piVar3;
        return 0;
      }
      pfVar6 = *(float **)(param_1 + 0x34);
      *pfVar6 = fVar16;
      pfVar6[1] = fVar16;
      pfVar6[2] = fVar16;
      func_0051D2CC(*(int **)(param_1 + 0x3c),0,fVar15);
      iVar7 = func_0058D840(*piVar3);
      if (iVar7 == 0) {
        return 0;
      }
      func_0051AA44(*piVar3);
      func_00165E28(*(int *)(*(int *)(param_1 + 0x2c) + 0x60),0);
      if (*(float *)(*(int *)(param_1 + 0x48) + 0x24) <= fVar16) goto LAB_0038c82c;
    }
    break;
  case 0xaa:
    *(float *)(*(int *)(param_1 + 0x4c) + 0x100) = DAT_0038d8fc;
    puVar4 = (undefined4 *)func_0052FBA0(*DAT_0038dc68 + 0x3dbbc,*(uint *)(param_1 + 0x16c));
    if (((*DAT_0038dc6c & 1) == 0) && (iVar7 = func_00100174((int *)DAT_0038dc6c), iVar7 != 0)) {
      *DAT_0038dc70 = DAT_0038dc74;
    }
    if ((puVar4 == (undefined4 *)0x0) ||
       (iVar7 = (**(code **)*puVar4)(puVar4,DAT_0038dc70), iVar7 == 0)) {
      puVar4 = (undefined4 *)0x0;
    }
    if (puVar4 != (undefined4 *)0x0) {
      func_004D80A4(&local_74,puVar4[0xfa],DAT_0038dc78);
      local_70 = fVar16;
      if (((*DAT_0038dc7c & 1) == 0) && (iVar7 = func_00100174((int *)DAT_0038dc7c), iVar7 != 0)) {
        *DAT_0038dc80 = DAT_0038dc84;
      }
      iVar7 = (**(code **)*puVar4)(puVar4,DAT_0038dc80);
      puVar5 = (undefined4 *)0x0;
      if (iVar7 != 0) {
        puVar5 = puVar4;
      }
      if (puVar5 != (undefined4 *)0x0) {
        local_38[0] = func_00513D68((int)puVar5);
        local_38[1] = albw_s012_get()[1];
        local_38[2] = albw_s012_get()[2];
        func_00115D70((float *)&local_84,&local_74,DAT_0038dc88);
        local_44 = local_84;
        iStack_40 = local_80;
        uStack_3c = local_7c;
        func_00115C54((float *)&local_84,local_38,(float *)&local_44);
        /* the pull target = (x, +0x17C, z) of that sum: EU 38DB74 / 38DB78 keep x = [sp+12] and z =
         * [sp+20] in s17 / s18 and 38DCE4..38DCF0 store them at sp+40 / sp+48 (local_68 / +0x30) with y at
         * sp+44. The text lost the x / z stores: Link was pulled to (0, y, 0), the map's middle, when
         * picking up a Maiamai stuck on a wall (camera swept off; BOOT_LOG 195) */
        local_68 = *(float *)(albw_frame + 0xc);
        *(float *)(albw_frame + 0x30) = *(float *)(albw_frame + 0x14);
        uVar17 = *(undefined4 *)(param_1 + 0x17c);
        if (ALBW_AS_F32(local_6c) == fVar16 && local_74 == fVar16) {
          iVar7 = 0;
        }
        else if (ALBW_AS_F32(local_6c) < fVar16) {
          if (local_74 < fVar16) {
            if (local_74 < ALBW_AS_F32(local_6c)) {
              iVar7 = func_004905E0(ALBW_AS_F32(local_6c) / local_74);
              iVar7 = -0x40000000 - iVar7;
            }
            else {
              iVar7 = func_004905E0(local_74 / ALBW_AS_F32(local_6c));
              iVar7 = iVar7 + -0x80000000;
            }
          }
          else {
            fVar15 = -ALBW_AS_F32(local_6c);
            if (fVar15 < local_74) {
              iVar7 = func_004905E0(fVar15 / local_74);
              iVar7 = iVar7 + 0x40000000;
            }
            else {
              iVar7 = func_004905E0(local_74 / fVar15);
              iVar7 = -0x80000000 - iVar7;
            }
          }
        }
        else if (local_74 < fVar16) {
          local_74 = -local_74;
          if (ALBW_AS_F32(local_6c) < local_74) {
            iVar7 = func_004905E0(ALBW_AS_F32(local_6c) / local_74);
            iVar7 = iVar7 + -0x40000000;
          }
          else {
            iVar7 = func_004905E0(local_74 / ALBW_AS_F32(local_6c));
            iVar7 = -iVar7;
          }
        }
        else if (ALBW_AS_F32(local_6c) < local_74) {
          iVar7 = func_004905E0(ALBW_AS_F32(local_6c) / local_74);
          iVar7 = 0x40000000 - iVar7;
        }
        else {
          iVar7 = func_004905E0(local_74 / ALBW_AS_F32(local_6c));
        }
        fVar15 = DAT_0038de58;
        func_0051D2CC(*(int **)(param_1 + 0x3c),iVar7,DAT_0038de58);
        pfVar6 = *(float **)(param_1 + 0x30);
        local_64 = uVar17;
        func_00115C70((float *)&local_84,&local_68,pfVar6);
        local_5c = local_84;
        iStack_58 = local_80;
        uStack_54 = local_7c;
        func_00115D70((float *)&local_84,(float *)&local_5c,fVar15);
        local_50 = local_84;
        iStack_4c = local_80;
        uStack_48 = local_7c;
        func_00115C54(pfVar6,pfVar6,(float *)&local_50);
      }
    }
    iVar7 = func_0053EDD8(*(int *)(param_1 + 0x4c) + 0x3c);
    if (iVar7 == 0) {
      return 0;
    }
    if (*(float *)(*(int *)(param_1 + 0x48) + 0x24) <= fVar16) goto LAB_0038c82c;
    break;
  case 0xab:
    fVar15 = func_002900EC(*(int *)(param_1 + 0x2c),1);
    fVar15 = fVar15 * DAT_0038de5c;
    if (ALBW_AS_F32(DAT_0038de60) < fVar15) {
      if (NAN(*(float *)(*(int *)(param_1 + 0x48) + 0x28)) || NAN(ALBW_AS_F32(DAT_0038de60))) {
        fVar15 = -fVar15;
        pfVar6 = *(float **)(param_1 + 0x38);
      }
      else {
        pfVar6 = *(float **)(param_1 + 0x38);
      }
      *pfVar6 = fVar15;
    }
    iVar7 = func_0054CF24(*(int *)(param_1 + 0x48));
    if (iVar7 != 0) {
      return func_002D55D0(param_1,0xac);
    }
    return 0;
  case 0xac:
    if (*(int *)(*(int *)(param_1 + 0x2c) + 0x44) == 4) {
      local_8c = DAT_0038de64;
      if (*(char *)(*(int *)(param_1 + 0x28) + 0x5ac) == '\0') {
        local_8c = DAT_0038dc78;
      }
      local_88 = DAT_0038de68;
      local_84 = DAT_0038de60;
      func_0033CFB0(*(undefined4 **)(param_1 + 0x30),&local_8c);
    }
    if (*(int *)(*(int *)(param_1 + 0x2c) + 0x44) == 0x19) {
      return func_002D55D0(param_1,0);
    }
  default:
switchD_0038c3e8_default:
    return 0;
  }
  uVar8 = 1;
LAB_0038c830:
  return func_002D55D0(param_1,uVar8);
}

