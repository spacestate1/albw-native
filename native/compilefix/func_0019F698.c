/* compilefix: USA 0019F698 (EU 0019F698), Ghidra-derived (build/ghidra_analyzed4).
 * Failed to compile: use of undeclared identifier '_local_74'
 * Fixed (each an exact C form of the ARM operation; the rest is the converted Ghidra text):
 *  - _local_XX (Ghidra's 4-byte view of the stack slot local_XX) -> *(undefined4 *)&local_XX (same frame offset) [1]
 *  - explicit casts at pointer-type mismatches (identity on the ARM) [2]
 *  - explicit (T)(uintptr_t) casts at int<->pointer mismatches (identity on the 32-bit ARM) [2]
 * Confidence: high for the fixes (each class checked against the EU disassembly on sample sites, this function's sites checked);
 * the function body otherwise has the fidelity of the Ghidra output (bare `return;` exits of
 * functions retyped non-void return 0, as the converter does). */
#include "ghidra_types.h"
#include "compilefix.h"

extern int func_00150A84(int *param_1,int *param_2,int param_3);
extern int func_002917A4(int param_1,float *param_2,undefined4 param_3,float fparam_0);
extern int func_00291FE0(int param_1,float *param_2,float fparam_0);
extern int func_004A8F40(int param_1,int *param_2,uint param_3);
extern int func_004F9880(int param_1,int *param_2,undefined4 param_3,int param_4);
extern int func_004F997C(int param_1);
extern int func_004FC244(int *param_1,int *param_2,int param_3,undefined4 param_4,int param_5);
extern int func_004FC78C(int param_1,undefined2 param_2);
extern int func_0065A330(undefined4 *param_1,undefined1 param_2);
extern uint DAT_0019fa6c;
extern float DAT_0019fa70;
extern int DAT_0019fa74;
extern int DAT_0019fa78;
extern undefined4 DAT_0019fa7c;
extern int *DAT_0019fa80;
extern int *DAT_0019fa9c;
extern char s_SE_DegTail_DRIVE_UP_S_0019fa84[];
extern char s_SE_DegTail_V_DAMAGE_0019faec[];
extern char s_SE_DegTail_V_DIE_0019faa0[];

// USA 0019F698 <- EU 0019F698 (Ghidra, non-matching)
// GLOBAL DAT_0019fa6c uint
// GLOBAL DAT_0019fa70 float
// GLOBAL DAT_0019fa74 int
// GLOBAL DAT_0019fa78 int
// GLOBAL DAT_0019fa7c undefined4
// GLOBAL DAT_0019fa80 int *
// GLOBAL DAT_0019fa9c int *
// GLOBAL s_SE_DegTail_DRIVE_UP_S_0019fa84 string
// GLOBAL s_SE_DegTail_V_DAMAGE_0019faec string
// GLOBAL s_SE_DegTail_V_DIE_0019faa0 string

void func_0019F698(int *param_1,int *param_2)

{
  ushort uVar1;
  char cVar2;
  bool bVar3;
  byte bVar4;
  int *extraout_r1;
  int *extraout_r1_00;
  int *extraout_r1_01;
  int *extraout_r1_02;
  int iVar5;
  int *piVar6;
  uint in_fpscr;
  float fVar7;
  float fVar8;
  undefined4 uVar9;
  float fVar10;
  int iVar11;
  ulonglong uVar12;
  _Alignas(8) unsigned char albw_frame[0x90];
  #define local_88 (*(int *)(albw_frame + 0x8))
  #define local_84 (*(char * *)(albw_frame + 0xc))
  #define local_80 (*(int *)(albw_frame + 0x10))
  #define local_7c (*(char * *)(albw_frame + 0x14))
  #define local_78 (*(int *)(albw_frame + 0x18))
  #define local_74 (*(undefined2 *)(albw_frame + 0x1c))
  #define uStack_72 (*(ushort *)(albw_frame + 0x1e))
  #define local_70 (*(undefined4 *)(albw_frame + 0x20))
  #define local_6c (*(int *)(albw_frame + 0x24))
  #define local_68 (*(float *)(albw_frame + 0x28))
  #define local_64 (*(undefined1 *)(albw_frame + 0x2c))
  #define local_5c (*(int * *)(albw_frame + 0x34))
  #define local_58 (*(int *)(albw_frame + 0x38))
  #define local_50 (*(int * *)(albw_frame + 0x40))
  #define local_4c (*(int * *)(albw_frame + 0x44))
  #define local_48 (*(int * *)(albw_frame + 0x48))
  local_4c = param_1 + 0x240;
  cVar2 = (char)param_1[0x275];
  if ((((cVar2 != '\x03' && cVar2 != '\x04') && (cVar2 != '\x06')) &&
      (local_5c = param_1 + 0x10f, *(int *)param_1[0x10f] == 0)) && ((param_1[0x167] & 0x80U) != 0))
  {
    iVar5 = 0;
    uVar12 = (ulonglong)DAT_0019fa6c;
    local_58 = DAT_0019fa78;
    local_50 = param_1 + 0x140;
    local_48 = param_1 + 0x10c;
    bVar3 = false;
    fVar10 = DAT_0019fa70;
    iVar11 = DAT_0019fa74;
    do {
      piVar6 = param_1 + iVar5 * 0x12 + 0x284;
      fVar7 = ALBW_AS_F32(piVar6[0xf]);
      local_80 = piVar6[0x11];
      local_84 = (char *)0x0;
      local_7c = (char *)0x0;
      local_70 = 0xff;
      local_64 = 0;
      local_78 = param_1[0xb3];
      if (iVar5 == 3) {
        bVar3 = true;
      }
      (*(undefined4 *)&local_74) = CONCAT22((ushort)((uint)param_2 >> 0x10) | (ushort)((uint)DAT_0019fa7c >> 0x10),
                           (short)param_1[0x15]);
      if (bVar3) {
        local_6c = param_1[0x48b];
      }
      else {
        local_6c = param_1[0x48a];
      }
      local_68 = fVar7;
      func_004A8F40(*DAT_0019fa80,(int *)&local_84,param_1[0x161]);
      param_2 = (int *)param_1[0x10f];
      if (*param_2 != 0) {
        cVar2 = *(char *)((int)param_2 + 0x21);
        if (cVar2 == '\t' || cVar2 == '\n') {
          in_fpscr = in_fpscr & 0xfffffff | (uint)(ALBW_AS_F32(piVar6[10]) == fVar10) << 0x1e;
          bVar4 = (byte)(in_fpscr >> 0x18);
joined_r0x0019f834:
          if ((bool)(bVar4 >> 6)) {
            piVar6[10] = iVar11;
            *(undefined1 *)(piVar6 + 0xc) = 10;
          }
        }
        else if (iVar5 == 3) {
          if ((*(char *)((int)param_1 + 0x121d) == '\0') &&
             (uVar1 = *(ushort *)(param_2 + 0xc), uVar1 != 0)) {
            fVar7 = ((float (*)(int *, int))*(code **)(*param_1 + 0x54))(param_1, (int)param_2);   /* damage multiplier */
            fVar8 = (float)VectorUnsignedToFloat((uint)uVar1,(byte)(in_fpscr >> 0x15) & 3);
            uVar9 = VectorFloatToUnsigned(fVar7 * fVar8,3);
            func_004FC78C((int)param_1,(short)local_50[2] - (short)uVar9);
            *(undefined2 *)(param_1[0x10c] + 0x28) = 0;
            func_004FC244(param_1,(int *)*local_5c,8,1,1);
            *(undefined1 *)((int)param_1 + 0x121d) = 8;
            *(undefined2 *)(*local_48 + 0x28) = 0xe0;
            func_0065A330(param_1 + 0x274,3);
            local_88 = local_58;
            if ((short)local_50[2] < 1) {
              local_84 = s_SE_DegTail_V_DIE_0019faa0;
              func_00150A84(param_1,&local_88,0);
            }
            else {
              local_84 = s_SE_DegTail_V_DAMAGE_0019faec;
              func_00150A84(param_1,&local_88,0);
            }
            func_004F997C((int)param_1);
            param_2 = extraout_r1_02;
          }
        }
        else if (cVar2 == '\x05') {
          in_fpscr = in_fpscr & 0xfffffff | (uint)(ALBW_AS_F32(piVar6[10]) == fVar10) << 0x1e;
          if (SUB41(in_fpscr >> 0x1e,0)) {
            piVar6[10] = iVar11;
            *(undefined1 *)(piVar6 + 0xc) = 10;
            func_002917A4(*DAT_0019fa9c,(float *)(piVar6),0,ALBW_AS_F32(uVar12));
            func_004F9880((int)*(char *)(param_1[0x10f] + 0x21),param_1,(undefined4)(uintptr_t)(piVar6),0);
            func_004FC244(param_1,(int *)*local_5c,8,1,1);
            param_2 = extraout_r1_01;
          }
        }
        else {
          if (cVar2 != '\f') {
            if (cVar2 == '\x0e') {
              in_fpscr = in_fpscr & 0xfffffff | (uint)(ALBW_AS_F32(piVar6[10]) == fVar10) << 0x1e;
              if (SUB41(in_fpscr >> 0x1e,0)) {
                piVar6[10] = iVar11;
                *(undefined1 *)(piVar6 + 0xc) = 10;
                func_00291FE0(*DAT_0019fa9c,(float *)(piVar6),ALBW_AS_F32(uVar12));
                func_004F9880((int)*(char *)(param_1[0x10f] + 0x21),param_1,(undefined4)(uintptr_t)(piVar6),0);
                func_004FC244(param_1,(int *)*local_5c,8,1,1);
                param_2 = extraout_r1_00;
              }
              goto LAB_0019fad0;
            }
            if (cVar2 != '\x0f') {
              in_fpscr = in_fpscr & 0xfffffff | (uint)(ALBW_AS_F32(piVar6[10]) == fVar10) << 0x1e;
              bVar4 = (byte)(in_fpscr >> 0x18);
              goto joined_r0x0019f834;
            }
          }
          if ((*(char *)((int)param_1 + 0x121d) == '\0') && ((char)local_4c[0x35] == '\x02')) {
            piVar6[10] = iVar11;
            *(undefined1 *)(piVar6 + 0xc) = 10;
            *(undefined1 *)((int)param_1 + 0x1221) = 1;
            local_80 = local_58;
            local_7c = s_SE_DegTail_DRIVE_UP_S_0019fa84;
            func_00150A84(param_1,&local_80,0);
            func_0065A330(param_1 + 0x274,5);
            param_2 = extraout_r1;
          }
        }
      }
LAB_0019fad0:
      iVar5 = iVar5 + 1;
    } while (iVar5 != 4);
  }
  return;
}

