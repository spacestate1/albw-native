/* compilefix: USA 00583E90 (EU 00583E68): virtual +0x60, speed factor of the object Link pushes or carries (0.25 for two actor kinds, else 1);
 * a NaN here left Link at an invalid position.
 * The converted text was typed void: the value in s0 was dropped and the caller read whatever was on
 * the x87 stack (BOOT_LOG 179). Written from the ARM. */
#include "ghidra_types.h"

extern int func_00588BE4(int param_1);
extern int *DAT_00583ea8;
extern int *DAT_00583eac;
extern float DAT_00583eb0;
extern float DAT_00583eb4;

float func_00583E90(int self)
{
  if (func_00588BE4(self) == *DAT_00583ea8 || func_00588BE4(self) == *DAT_00583eac)
    return DAT_00583eb4;
  return DAT_00583eb0;
}
