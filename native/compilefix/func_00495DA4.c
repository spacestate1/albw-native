/* compilefix: USA 00495DA4: a virtual forwarder whose tail call lost three of its four arguments
 * (BOOT_LOG 172). ARM: ldr r3,[r0]; ldr r12,[r3,#0x44]; ldr r3,=0x0079DFCC; bx r12 - r1 and r2 pass
 * through, r3 is the address of a game data object; Ghidra kept `this` only. */
#include "ghidra_types.h"

extern char data_0079DFCC[];

undefined4 func_00495DA4(int *param_1, int param_2, int param_3)
{
  return (**(code **)(*param_1 + 0x44))(param_1, param_2, param_3, (int)(uintptr_t)data_0079DFCC);
}
