/* compilefix: USA 0024CDE4, the converted stage-2 text with y and z of the hit point
 * (a vector returned in s0..s2 on ARM: BOOT_LOG 178). */
#include "ghidra_types.h"

extern int func_00100174(int *param_1);
extern ulonglong func_00110710(uint param_1,uint param_2);
extern int func_0052FBA0(int param_1,uint param_2);
extern float func_0054F764(undefined4 *param_1,uint param_2,uint *param_3);
extern int func_0054FAC0(int param_1,uint param_2);
extern undefined DAT_0000000a;
extern int *DAT_0024cfe8;
extern uint *DAT_0024cfec;
extern undefined4 DAT_0024cff0;
extern undefined4 *DAT_0024cff4;
extern uint *DAT_0024cff8;
extern undefined4 *DAT_0024cffc;
extern int *DAT_0024d000;
extern float DAT_0024d004;
extern float DAT_0024d008;

float *albw_s012_get(void);   /* s0..s2 of a returned vector (native/runtime/vec3ret.c) */

// USA 0024CDE4 <- EU 0024CDE4 (Ghidra, non-matching)
// GLOBAL DAT_0000000a undefined
// GLOBAL DAT_0024cfe8 int *
// GLOBAL DAT_0024cfec uint *
// GLOBAL DAT_0024cff0 undefined4
// GLOBAL DAT_0024cff4 undefined4 *
// GLOBAL DAT_0024cff8 uint *
// GLOBAL DAT_0024cffc undefined4 *
// GLOBAL DAT_0024d000 int *
// GLOBAL DAT_0024d004 float
// GLOBAL DAT_0024d008 float

undefined4 func_0024CDE4(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  float *pfVar6;
  undefined4 uVar7;
  uint *puVar8;
  undefined4 *puVar9;
  uint uVar10;
  uint *puVar11;
  bool bVar12;
  uint in_fpscr;
  float in_s0;
  float fVar13;
  float in_s1;
  float in_s2;
  undefined8 uVar14;
  _Alignas(8) unsigned char albw_frame[0x30];
  #define local_28 (*(int *)(albw_frame + 0x8))
  #define local_24 (*(int *)(albw_frame + 0xc))
  puVar2 = (undefined4 *)func_0052FBA0(*DAT_0024cfe8 + 0x3dbbc,*(uint *)(param_2 + 0x4c));
  uVar1 = DAT_0024cff0;
  uVar7 = 0;
  if (puVar2 != (undefined4 *)0x0) {
    if (((*DAT_0024cfec & 1) == 0) && (iVar3 = func_00100174((int *)DAT_0024cfec), iVar3 != 0)) {
      *DAT_0024cff4 = uVar1;
    }
    iVar3 = (**(code **)*puVar2)(puVar2,DAT_0024cff4);
    puVar9 = puVar2;
    if (iVar3 == 0) {
      puVar9 = (undefined4 *)0x0;
    }
    if (((*DAT_0024cff8 & 1) == 0) && (iVar3 = func_00100174((int *)DAT_0024cff8), iVar3 != 0)) {
      *DAT_0024cffc = uVar1;
    }
    iVar3 = (**(code **)*puVar2)(puVar2,DAT_0024cffc);
    if (iVar3 == 0) {
      puVar2 = (undefined4 *)0x0;
    }
    uVar7 = 0;
    if (puVar9 != (undefined4 *)0x0 || puVar2 != (undefined4 *)0x0) {
      if (puVar9 == (undefined4 *)0x0) {
        puVar2 = puVar2 + 0x38c;
      }
      else {
        puVar2 = puVar9 + 0x26d;
      }
      bVar12 = param_3 != 0;
      if (bVar12) {
        local_28 = DAT_0024d000[1];
      }
      else {
        local_28 = *DAT_0024d000;
      }
      iVar3 = *(int *)(param_1 + 1000);
      if (bVar12) {
        in_s0 = DAT_0024d004;
      }
      piVar4 = DAT_0024d000;
      if (!bVar12) {
        in_s0 = (float)VectorUnsignedToFloat(*DAT_0024d000,(byte)(in_fpscr >> 0x15) & 3);
        in_s0 = in_s0 * DAT_0024d008;
        piVar4 = (int *)&DAT_0000000a;
        in_s1 = DAT_0024d008;
      }
      local_24 = (int)in_s0;
      if (bVar12) {
        uVar14 = func_00110710(piVar4[2],piVar4[1]);
        piVar4 = (int *)((int)uVar14 + 1);
      }
      *(int **)(param_1 + 0xa88) = piVar4;
      iVar5 = 0x20;
      if ((int)piVar4 < 0x21) {
        iVar5 = *(int *)(param_1 + 0xa88);
      }
      else {
        *(undefined4 *)(param_1 + 0xa88) = 0x20;
      }
      uVar10 = 0;
      if (0 < iVar5) {
        puVar11 = (uint *)(param_1 + 0x83c);
        do {
          piVar4 = &local_24;
          do {
            iVar5 = *piVar4;
            if (*(char *)(param_1 + 0xa84) != '\0') {
              iVar5 = -iVar5;
            }
            iVar3 = iVar3 + iVar5;
            puVar8 = puVar11;
            if (uVar10 < 0x20) {
              puVar8 = puVar11 + uVar10;
            }
            fVar13 = func_0054F764(puVar2,iVar3,puVar8);
            in_s1 = albw_s012_get()[1];
            in_s2 = albw_s012_get()[2];
            pfVar6 = (float *)(param_1 + 0x630);
            if (uVar10 < 0x20) {
              pfVar6 = (float *)(param_1 + 0x630 + uVar10 * 0xc);
            }
            puVar9 = (undefined4 *)(param_1 + 0x7b0);
            *pfVar6 = fVar13;
            pfVar6[1] = in_s1;
            pfVar6[2] = in_s2;
            puVar8 = puVar11;
            if (uVar10 < 0x20) {
              puVar9 = puVar9 + uVar10;
              puVar8 = puVar11 + uVar10;
            }
            uVar7 = func_0054FAC0((int)puVar2,*puVar8);
            *puVar9 = uVar7;
            uVar10 = uVar10 + 1;
            if (*(int *)(param_1 + 0xa88) <= (int)uVar10) goto LAB_0024cfdc;
            piVar4 = &local_28;
          } while (uVar10 != 0);
        } while( true );
      }
LAB_0024cfdc:
      uVar7 = 1;
    }
  }
  return uVar7;
}

