/* compilefix: USA 004FA13C (EU 004FA114): hit direction from a hit record: returns 004FA174's vector (the matched C++ popped it and
 * its caller 002B1760 read an empty x87 stack).
 * The converted text was typed void: the value in s0 was dropped and the caller read whatever was on
 * the x87 stack (BOOT_LOG 179). Written from the ARM. */
#include "ghidra_types.h"

float func_004FA174(float *param_1,int param_2,int param_3,uint in_r3,float *param_4,int param_5,int param_6);

float func_004FA13C(float *pos, int rec)
{
  return func_004FA174(pos, rec, 0x10, *(byte *)(rec + 0x20), (float *)(rec + 0x14), *(signed char *)(rec + 0x21),
                       *(uint *)(rec + 0x38) >> 0x1c);
}
