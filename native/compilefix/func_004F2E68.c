/* compilefix: USA 004F2E68 (EU 004F2E40): virtual +0x54 of an enemy: damage multiplier for a hit, by the actor kind.
 * The converted text was typed void: the value in s0 was dropped and the caller read whatever was on
 * the x87 stack (BOOT_LOG 179). Written from the ARM. */
#include "ghidra_types.h"

extern int func_0055696C(int param_1,int param_2);
extern int func_00588BE4(int param_1);
extern int func_0058A1F4(int param_1);
extern int func_0058A468(int param_1);
extern int *DAT_004f2f24;
extern float DAT_004f2f28;
extern uint *DAT_004f2f2c;
extern float DAT_004f2f30;
extern float DAT_004f2f34;
extern int *DAT_004f2f38;

float func_004F2E68(int self, int hit)
{
  if (func_00588BE4(self) == *DAT_004f2f24) {
    if (func_0058A1F4(self) != 0 && *(byte *)(hit + 0x21) == 8)
      return DAT_004f2f28;
    return DAT_004f2f34;
  }
  if ((uint)func_00588BE4(self) != *DAT_004f2f2c)
    return DAT_004f2f34;
  int kind = *(signed char *)(hit + 0x21);
  if (kind == 2 || *(byte *)(hit + 0x23) == 3)
    return DAT_004f2f30;
  if (kind != 13)
    return DAT_004f2f34;
  if ((uint)func_0055696C(*DAT_004f2f38, 12) >= 3)
    return DAT_004f2f28;
  int n = func_0058A468(self);
  return (float)n / ((float)*(ushort *)(hit + 0x30) * 2.0f);   /* EU 4F2F3C: 2.0 */
}
