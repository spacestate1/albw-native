/* compilefix: USA 00493D8C (EU 00493D64), the converted stage-2 text.
 * Fixed (BOOT_LOG 184): the ARM compares the float's bits (vmov rX, sY; cmp), which the converted text
 * wrote as a conversion of the value to an integer. */
#include "ghidra_types.h"

extern int func_00100174(int *param_1);
extern int func_0048ED44(int param_1,int param_2);
extern float *DAT_00493e70;
extern float DAT_00493e74;
extern uint *DAT_00493e78;
extern undefined4 *DAT_00493e7c;
extern undefined4 DAT_00493e80;

// USA 00493D8C <- EU 00493D64 (Ghidra, non-matching)
// GLOBAL DAT_00493e70 float *
// GLOBAL DAT_00493e74 float
// GLOBAL DAT_00493e78 uint *
// GLOBAL DAT_00493e7c undefined4 *
// GLOBAL DAT_00493e80 undefined4

void func_00493D8C(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  uint in_fpscr;
  float fVar3;
  float fVar4;
  float fVar5;
  
  fVar3 = DAT_00493e70[1];
  if ((int)ALBW_AS_U32(DAT_00493e70[3]) < (int)ALBW_AS_U32(DAT_00493e70[2])) {
    fVar4 = (float)VectorSignedToFloat(ALBW_AS_U32(DAT_00493e70[3]),(byte)(in_fpscr >> 0x15) & 3);
    fVar5 = (float)VectorSignedToFloat(ALBW_AS_U32(DAT_00493e70[2]),(byte)(in_fpscr >> 0x15) & 3);
    fVar3 = ((fVar3 - *DAT_00493e70) * fVar4) / fVar5 + *DAT_00493e70;
  }
  if (*(char *)(param_1 + 9) == '\x01') {
    if (fVar3 == DAT_00493e74) {
      *(undefined1 *)(param_1 + 9) = 2;
      return;
    }
  }
  else if (*(char *)(param_1 + 9) == '\x02') {
    return;
  }
  if (*(char *)(param_1 + 8) == '\x01' && fVar3 == DAT_00493e74) {
    puVar2 = *(undefined4 **)(*(int *)(param_1 + 4) + 0x1c);
    if (((*DAT_00493e78 & 1) == 0) && (iVar1 = func_00100174((int *)DAT_00493e78), iVar1 != 0)) {
      *DAT_00493e7c = DAT_00493e80;
    }
    if ((puVar2 == (undefined4 *)0x0) ||
       (iVar1 = (**(code **)*puVar2)(puVar2,DAT_00493e7c), iVar1 == 0)) {
      puVar2 = (undefined4 *)0x0;
    }
    func_0048ED44((int)puVar2,0);
    *(undefined1 *)(param_1 + 8) = 2;
  }
  return;
}

