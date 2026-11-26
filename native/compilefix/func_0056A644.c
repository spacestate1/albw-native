/* compilefix: USA 0056A644 (EU 0056A61C), the converted stage-2 text.
 * Fixed (BOOT_LOG 184): the ARM copies this word between a float and an integer (no vcvt), which the
 * converted text wrote as a conversion of the value. */
#include "ghidra_types.h"

extern float DAT_0056a68c;

// USA 0056A644 <- EU 0056A61C (Ghidra, non-matching)
// GLOBAL DAT_0056a68c float

float func_0056A644(int param_1)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  bVar1 = false;
  iVar2 = 0;
  uVar3 = 0;
  iVar4 = 4;
  do {
    if (((*(uint *)(param_1 + 4) & 1 << (uVar3 & 0xff)) != 0) && (iVar2 = iVar2 + 1, uVar3 == 3)) {
      bVar1 = true;
    }
    iVar4 = iVar4 + -1;
    uVar3 = uVar3 + 1;
  } while (iVar4 != 0);
  if ((bVar1) && (iVar2 != 0)) {
    return ALBW_AS_F32(((uint *)(param_1 + 4))[iVar2]);
  }
  return DAT_0056a68c;
}

