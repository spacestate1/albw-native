/* USA 00689E6C (EU 00689E44): sead curve handler data_00715240[kind](header, data, t) -> float, Hermite, {value, tangent} pairs spread evenly over 0..1.
 * The converted text was typed void, so it compiled to an empty function and 00691D68 returned
 * whatever was on the x87 stack (BOOT_LOG 179). Written from the ARM. */
#include <stdint.h>

float func_00689E6C(const uint8_t *h, const float *p, float t)
{
    if (h[3] & 1) return 0.0f;
    if (t < 0.0f) return p[0];
    int n = (h[3] >> 1) - 1;
    float x = t * (float)n;
    int i = (int)x;
    if (i >= n) return p[i * 2];
    float f = x - (float)i, f2 = f * f, f3 = f2 * f;
    const float *k = p + i * 2;
    return k[0] * (2.0f * f3 - 3.0f * f2 + 1.0f) + k[2] * (-2.0f * f3 + 3.0f * f2) +
           k[1] * (f3 - 2.0f * f2 + f) + k[3] * (f3 - f2);
}
