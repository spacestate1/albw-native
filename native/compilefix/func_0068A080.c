/* USA 0068A080 (EU 0068A058): sead curve handler data_00715240[kind](header, data, t) -> float, Hermite, {time, value, tangent} keys, tangents per segment.
 * The converted text was typed void, so it compiled to an empty function and 00691D68 returned
 * whatever was on the x87 stack (BOOT_LOG 179). Written from the ARM. */
#include <stdint.h>

float func_0068A080(const uint8_t *h, const float *p, float t)
{
    if (p[0] >= t) return p[1];
    int count = (h[3] * 0xAB) >> 9;   /* floats / 3 */
    int last = (count - 1) * 3;
    if (p[last] <= t) return p[last + 1];
    for (int i = 0; i < count; i++) {
        const float *k = p + i * 3;
        if (!(k[3] > t)) continue;
        float dt = k[3] - k[0], f = (t - k[0]) / dt, f2 = f * f, f3 = f2 * f;
        float m0 = k[2], m1 = k[5];
        return k[1] * (2.0f * f3 - 3.0f * f2 + 1.0f) + k[4] * (-2.0f * f3 + 3.0f * f2) +
               m0 * (f3 - 2.0f * f2 + f) + m1 * (f3 - f2);
    }
    return 0.0f;
}
