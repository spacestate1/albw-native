/* compilefix: USA 002EB18C (EU 002EB168): virtual +0x54 of a boss: damage multiplier for a hit.
 * The converted text was typed void: the value in s0 was dropped and the caller read whatever was on
 * the x87 stack (BOOT_LOG 179). Written from the ARM. */
#include "ghidra_types.h"

extern int func_0052FBA0(int param_1,uint param_2);
extern int func_00588BE4(int param_1);
extern int *DAT_002eb250;
extern int *DAT_002eb254;

float func_002EB18C(int self, int hit)
{
  if (*(char *)(self + 0xd3d) != '\0')
    return 0.0f;
  int kind = *(signed char *)(hit + 0x21);
  if (kind == 0) {
    int a = func_0052FBA0(*DAT_002eb250 + 0x3dbbc, *(uint *)(hit + 4));
    if (a == 0 || func_00588BE4(a) != *DAT_002eb254)
      return 0.0f;
    return 1.0f;
  }
  if (*(char *)(self + 0xd45) != '\x01')
    return 1.0f;
  if (*(int *)(self + 0xc20) - *(short *)(self + 0x508) >= 0x60)
    return 0.0f;
  if (*(char *)(self + 0x8cc) == '\x1f')
    return 100.0f;
  if (kind == 5) {
    uint v = (*(uint *)(hit + 0x38) & 0xc000000) >> 0x1a;
    if (v == 1)
      return 1.5f;
    if (v == 2)
      return 1.2f;
  }
  return 1.0f;
}
