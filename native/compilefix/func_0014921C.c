/* compilefix: USA 0014921C (EU 0014921C): spawn the effect actor; returns it.
 * The matched C++ declares it void, but the ARM leaves func_004C4AF4's result in r0 and the caller
 * (003BB06C, the StreetPass Shadow Link's shot) uses it: on x86 it read the stack canary and
 * crashed in func_004A9120 (BOOT_LOG 176). */
#include "ghidra_types.h"

extern char ro_00693124[];
extern char data_00706E20[];
extern char data_0070C8E0[];
extern int func_0019B04C(uint id);
extern int func_002DFF7C(void *spawn_param);
extern int func_00581D60(int mgr, uint a, uint b, void *pos);
extern int func_004C4AF4(int mgr, int *spawn_param, int flag);

int func_0014921C(uint owner, const uint *pos, uint handle, uint strong)
{
  _Alignas(8) unsigned char p[0x2c4];
#define U32(off) (*(uint *)(p + (off)))
  U32(0x1c) = 0;
  U32(0x20) = 0;
  U32(0x24) = 0;
  U32(0x48) = 0;
  U32(0x4c) = 0;
  U32(0x2c0) = 0;
  func_002DFF7C(p);
  U32(0) = (uint)func_0019B04C(*(uint *)ro_00693124);
  U32(4) = pos[0];
  U32(8) = pos[1];
  U32(0xc) = pos[2];
  U32(0x20) = handle;
  /* r3 = &position inside the parameters; r1 / r2 = its y and z */
  *(ushort *)(p + 0x50) = (ushort)func_00581D60(*(int *)data_0070C8E0, U32(8), U32(0xc), p + 4);
  *(float *)(p + 0x44) = strong != 0 ? 1.0f : 0.0f;
  U32(0x4c) = owner;
  return func_004C4AF4(*(int *)data_00706E20, (int *)p, 0);
}
