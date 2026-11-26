/* native/gameplay/view_projection.c against the file it replaced (taken from git), on random cameras:
 * at zoom 100 % the matrix, the return value and the "rebuild this one" marks must be identical bit for
 * bit; zoomed out, the two scale entries must shrink by the zoom and nothing else may change; bottom-screen
 * and square cameras must not change at all. Run tools/tests/view_projection_test.sh. */
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int old_0057F6C0(int projection, float *matrix);
void old_view_refresh(void);
int func_0057F6C0(int projection, float *matrix);
void albw_view_refresh(void);

static float ws = 1.0f, zoom = 1.0f;
float albw_ws_factor(void) { return ws; }
float albw_view_zoom(void) { return zoom; }
float DAT_0057f790 = 2.0f, DAT_0057f794 = 0.5f, DAT_0057f798 = 1.0f, DAT_0057f79c = 0.0f, DAT_0057f7a0 = -1.0f;

static uint32_t state = 2468;
static uint32_t rnd(void) { state ^= state << 13; state ^= state >> 17; state ^= state << 5; return state; }
static float between(float a, float b) { return a + (b - a) * (float)(rnd() % 1000001) / 1000000.0f; }

enum { N = 40 };
static uint32_t cam_old[N][0xB8 / 4], cam_new[N][0xB8 / 4];
static const uint32_t vtable = 0x006E0000;

static void put(uint32_t *c, int off, float v) { memcpy((char *)c + off, &v, 4); }

static int make_camera(int k) {
    uint32_t *c = cam_old[k];
    for (int i = 0; i < 0xB8 / 4; i++) c[i] = rnd();
    c[0] = vtable;
    ((uint8_t *)c)[4] = 0;
    float near = between(0.05f, 10.0f);
    int top = rnd() % 3 != 0;
    put(c, 0x94, near);
    put(c, 0x98, near + between(1.0f, 5000.0f));
    put(c, 0xA8, between(0.05f, 2.0f));
    put(c, 0xAC, top ? 400.0f / 240.0f : (rnd() & 1 ? 320.0f / 240.0f : 1.0f));
    put(c, 0xB0, rnd() & 1 ? 0.0f : between(-0.5f, 0.5f));
    put(c, 0xB4, rnd() & 1 ? 0.0f : between(-0.5f, 0.5f));
    memcpy(cam_new[k], c, sizeof cam_old[k]);
    return top;
}

#define FAIL(...) do { printf("FAILED at round %ld: ", i); printf(__VA_ARGS__); printf("\n"); return 1; } while (0)

int main(int argc, char **argv) {
    long rounds = argc > 1 ? atol(argv[1]) : 2000000;
    int top[N] = {0};
    for (int k = 0; k < N; k++) top[k] = make_camera(k);
    long same = 0, zoomed = 0, marks = 0;
    for (long i = 0; i < rounds; i++) {
        int k = rnd() % N;
        if (rnd() % 50 == 0) top[k] = make_camera(k);
        if (rnd() % 97 == 0) ws = rnd() & 1 ? 427.0f / 400.0f : 1.0f;
        float m_old[16], m_new[16];

        zoom = 1.0f;
        int r_old = old_0057F6C0((int)(uintptr_t)cam_old[k], m_old);
        int r_new = func_0057F6C0((int)(uintptr_t)cam_new[k], m_new);
        if (memcmp(m_old, m_new, sizeof m_old)) FAIL("matrix at 100 %% differs");
        if (r_old != (int)(uintptr_t)cam_old[k] || r_new != (int)(uintptr_t)cam_new[k]) FAIL("return value");
        same++;

        if (rnd() % 61 == 0) {   /* widescreen toggled: both must mark the same cameras */
            for (int j = 0; j < N; j++) ((uint8_t *)cam_old[j])[4] = ((uint8_t *)cam_new[j])[4] = 0;
            ws = ws == 1.0f ? 427.0f / 400.0f : 1.0f;
            old_view_refresh();
            albw_view_refresh();
            for (int j = 0; j < N; j++) {
                if (((uint8_t *)cam_old[j])[4] != ((uint8_t *)cam_new[j])[4]) FAIL("mark of camera %d differs", j);
                marks += ((uint8_t *)cam_new[j])[4];
            }
        }

        zoom = between(1.0f, 2.0f);
        float m_zoom[16];
        func_0057F6C0((int)(uintptr_t)cam_new[k], m_zoom);
        for (int e = 0; e < 16; e++) {
            float want = m_new[e] / (top[k] && (e == 0 || e == 5) ? zoom : 1.0f);
            /* the ws factor may have been toggled between the two builds */
            if (e == 0 && top[k]) continue;
            if (e == 2 && top[k]) { if (fabsf(m_zoom[e] - m_new[e]) > 1e-4f) FAIL("centre x moved"); continue; }
            if (fabsf(m_zoom[e] - want) > 1e-4f * (1.0f + fabsf(want))) FAIL("entry %d zoomed: %g, expected %g", e, m_zoom[e], want);
        }
        if (top[k]) {
            float p_aspect = 400.0f / 240.0f * ws;
            if (fabsf(m_zoom[5] / m_zoom[0] - p_aspect) > 1e-3f) FAIL("shape of the zoomed view");
            uint8_t *dirty = &((uint8_t *)cam_new[k])[4];
            *dirty = 0;
            albw_view_refresh();
            if (*dirty) FAIL("marked although nothing changed");
            zoom = zoom > 1.5f ? zoom - 0.25f : zoom + 0.25f;
            albw_view_refresh();
            if (!*dirty) FAIL("not marked after a zoom change");
            zoomed++;
        }
        zoom = 1.0f;   /* leave this camera built alike in both, for the next comparison of marks */
        old_0057F6C0((int)(uintptr_t)cam_old[k], m_old);
        func_0057F6C0((int)(uintptr_t)cam_new[k], m_zoom);
    }
    printf("passed: %ld identical at 100 %%, %ld zoomed top-screen builds checked, %ld rebuild marks compared\n", same, zoomed, marks);
    return 0;
}
