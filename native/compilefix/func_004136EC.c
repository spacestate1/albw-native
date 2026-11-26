/* compilefix: USA 004136EC (EU 004136CC): step curve (t >= 0.5 gives 1, else 0).
 * The converted text was typed void: the value in s0 was dropped and the caller read whatever was on
 * the x87 stack (BOOT_LOG 179). Written from the ARM. */
#include "ghidra_types.h"

float func_004136EC(float t)
{
  union { float f; int i; } u = { t };
  return u.i >= 0x3f000000 ? 1.0f : 0.0f;
}
