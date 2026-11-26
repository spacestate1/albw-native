/* compilefix: USA 00530F44 (EU 00530F1C): virtual +0x58 (hit direction, a vector in s0..s2, published like the base 0058A7E8, x bits
 * returned in r0 as there): away from its home point when far from it, else the vector of the hit record.
 * The converted text was typed void: the value in s0 was dropped and the caller read whatever was on
 * the x87 stack (BOOT_LOG 179). Written from the ARM. */
#include "ghidra_types.h"

#include <math.h>
extern int func_00115C54(float *param_1,float *param_2,float *param_3);
extern int func_00115D70(float *param_1,float *param_2,float fparam_0);
extern float func_00115DC8(float *param_1);
extern float *DAT_0053104c;
float *albw_s012_get(void);

uint32_t func_00530F44(int self, int id, int hit)
{
  const float *h = (const float *)(hit + 0xc);
  float r[3] = { h[0], h[1], h[2] };
  if (*(char *)(self + 0xba4) == '\0' && id == 0x12) {
    float dx = *(float *)(self + 0x3d0) - *(float *)(self + 0x900);
    float dz = *(float *)(self + 0x3d8) - *(float *)(self + 0x908);
    if (sqrtf(dx * dx + dz * dz) > 6.0f) {   /* EU 531040 */
      float v[3] = { DAT_0053104c[0], DAT_0053104c[1], DAT_0053104c[2] };
      if (dz <= dx) {
        if (dx < -dz) v[2] = -1.0f; else v[0] = 1.0f;
      }
      else {
        if (dx < -dz) v[0] = -1.0f; else v[2] = 1.0f;
      }
      float s[3], sum[3];
      func_00115D70(s, v, 2.0f);
      func_00115C54(sum, (float *)(hit + 0xc), s);
      r[0] = sum[0];
      r[1] = 0.0f;
      r[2] = sum[2];
      func_00115DC8(r);
    }
  }
  float *out = albw_s012_get();
  out[0] = r[0];
  out[1] = r[1];
  out[2] = r[2];
  union { float f; uint32_t u; } x = { r[0] };
  return x.u;
}
