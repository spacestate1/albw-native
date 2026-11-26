/* compilefix: USA 002E4AC4 (EU 002E4AA0): virtual +0x54 of an enemy: damage multiplier for a hit.
 * The converted text was typed void: the value in s0 was dropped and the caller read whatever was on
 * the x87 stack (BOOT_LOG 179). Written from the ARM. */
#include "ghidra_types.h"

extern int func_0055696C(int param_1,int param_2);
extern int func_0058A468(int param_1);
extern float DAT_002e4b18;
extern float DAT_002e4b1c;
extern int *DAT_002e4b20;
extern float DAT_002e4b24;

float func_002E4AC4(int self, int hit)
{
  int kind = *(signed char *)(hit + 0x21);
  if (kind == 13) {
    if ((uint)func_0055696C(*DAT_002e4b20, 12) >= 3)
      return DAT_002e4b24;
    int n = func_0058A468(self);
    return (float)n / ((float)*(ushort *)(hit + 0x30) * 3.0f);   /* EU 2E4B28: 3.0 */
  }
  if (kind == 2 || *(byte *)(hit + 0x23) == 3)
    return DAT_002e4b18;
  return DAT_002e4b1c;
}
