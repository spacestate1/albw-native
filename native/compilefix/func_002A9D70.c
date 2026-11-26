/* compilefix: USA 002A9D70 (EU 002A9D4C): virtual +0x54 of an enemy: damage multiplier for a hit (hit[0x21] = kind).
 * The converted text was typed void: the value in s0 was dropped and the caller read whatever was on
 * the x87 stack (BOOT_LOG 179). Written from the ARM. */
#include "ghidra_types.h"

extern bool func_005427C4(int param_1,int param_2);
extern int func_0058A1F4(int param_1);

float func_002A9D70(int self, int hit)
{
  int kind = *(signed char *)(hit + 0x21);
  if (func_0058A1F4(self) != 0)
    return kind == 8 ? 100.0f : 1.0f;
  if (kind == 2)
    return func_005427C4(self, 0) ? 1.0f : 0.0f;
  switch (kind) {
  case 0: case 5: case 6: case 7: case 8: case 9: case 10: case 13: case 14: case 15:
    return 0.0f;
  default:
    return 1.0f;
  }
}
