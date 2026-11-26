/* USA 00689F5C (EU 00689F34): sead curve handler data_00715240[kind](header, data, t) -> float, linear, keys spread evenly over 0..1.
 * The converted text was typed void, so it compiled to an empty function and 00691D68 returned
 * whatever was on the x87 stack (BOOT_LOG 179). Written from the ARM. */
#include <stdint.h>

float func_00689F5C(const uint8_t *h, const float *p, float t)
{
    if (t < 0.0f) return p[0];
    int n = h[3] - 1;
    float x = t * (float)n;
    int i = (int)x;
    if (i >= n) return p[i];
    return p[i] + (p[i + 1] - p[i]) * (x - (float)i);
}
