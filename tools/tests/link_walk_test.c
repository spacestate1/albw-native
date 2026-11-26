/* Old against new: native/gameplay/link_walk.c and the two files it replaced, on the same random inputs.
 * Run tools/tests/link_walk_test.sh (it takes the old versions from git).
 *
 * The game objects are plain memory with the pointers filled in; the game functions both versions call are
 * stand-ins that write a log. After each pair of runs every object, the return value, the globals and the
 * log must be identical, bit for bit. */
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float old_002D5ADC(int walk, float time_step);
float old_002900EC(uint32_t player, int as_painting);
float func_002D5ADC(int walk, float time_step);
float func_002900EC(uint32_t player, int as_painting);

/* ---- the world */
static struct World {
    uint32_t walk[0x64 / 4];
    uint32_t body[0x5B4 / 4];
    uint32_t player[0x4C / 4];
    uint32_t tuning[0x28 / 4];
    uint32_t slot[0x48 / 4];
    uint32_t handle;
    uint32_t velocity[3];
    uint32_t heading;
    uint32_t faces_left;
    uint32_t stick[0x30 / 4];
    uint32_t turn[0x340 / 4];
    uint32_t actor[4];
    uint32_t vtable[0x64 / 4];
} w;
static uint8_t manager[0x3DBC0];

uint32_t data_00706E20, data_007260CC, data_007260D0;
uint8_t data_006F6314[4] = {0x11, 0x22, 0x33, 0x44};
/* the European release's values */
float DAT_002d5c30 = 0.09f, DAT_002d5c34 = 0.25f, DAT_002d5c3c = 0.0f, DAT_002d5c40, DAT_002d5c48;
int DAT_002d5c38 = 0x3dbeab36, DAT_002d5c44 = 0x3c978d50;

/* ---- stand-ins, each leaving a trace */
static uint32_t trace[64];
static int ntrace;
static void note(uint32_t v) { if (ntrace < 64) trace[ntrace++] = v; }
static uint32_t bits(float f) { uint32_t u; memcpy(&u, &f, 4); return u; }
static float flt(uint32_t u) { float f; memcpy(&f, &u, 4); return f; }
static int actor_is_kind, actor_missing;
static float actor_factor;

int func_0054C998(int stick, int heading) {
    note(1); note((uint32_t)stick); note((uint32_t)heading);
    const uint32_t *s = (const uint32_t *)(uintptr_t)stick;
    return flt(s[0x24 / 4]) > 0.0f ? (int)(s[0x2C / 4] + 0x01000000u) : heading;
}
int func_0051D2CC(int *angle, int target, float share) {
    note(2); note((uint32_t)(uintptr_t)angle); note((uint32_t)target); note(bits(share));
    float d = (float)(int)((uint32_t)target - (uint32_t)*angle) * share;
    *angle = (int)((uint32_t)*angle + (uint32_t)(int)d);
    return 0;
}
float func_00115154(float *s, float *c, uint32_t angle) {
    note(3); note(angle);
    float a = (float)angle * (6.28318530718f / 4294967296.0f);
    *s = sinf(a);
    *c = cosf(a);
    return 0.0f;
}
int func_0052FBA0(int list, uint32_t handle) {
    note(4); note((uint32_t)list); note(handle);
    return actor_missing ? 0 : (int)(uintptr_t)w.actor;
}
int func_00100174(uint32_t *guard) {
    note(5);
    if (*guard & 1) return 0;
    *guard |= 1;
    return 1;
}
static int is_kind(void *a, uint32_t *id) { note(6); note((uint32_t)(uintptr_t)a); note(*id); return actor_is_kind; }
static float speed_factor(void *a) { note(7); note((uint32_t)(uintptr_t)a); return actor_factor; }

/* ---- random worlds */
static uint32_t rnd_state = 12345;
static uint32_t rnd(void) {
    rnd_state ^= rnd_state << 13;
    rnd_state ^= rnd_state >> 17;
    rnd_state ^= rnd_state << 5;
    return rnd_state;
}
static float pick(const float *v, int n) { return rnd() % 8 ? v[rnd() % n] : flt(rnd()); }
#define PICK(...) pick((const float[]){__VA_ARGS__}, (int)(sizeof((const float[]){__VA_ARGS__}) / 4))
#define P(x) ((uint32_t)(uintptr_t)(x))

static void make_world(void) {
    uint32_t *all = (uint32_t *)&w;
    for (size_t i = 0; i < sizeof w / 4; i++) all[i] = rnd();
    w.walk[0x28 / 4] = P(w.body);
    w.walk[0x2C / 4] = P(w.player);
    w.walk[0x38 / 4] = P(w.velocity);
    w.walk[0x3C / 4] = P(&w.heading);
    w.walk[0x40 / 4] = P(&w.faces_left);
    w.walk[0x48 / 4] = P(w.stick);
    w.walk[0x50 / 4] = P(w.turn);
    w.walk[0x60 / 4] = bits(PICK(0.0f, 0.0001f, 0.018f, 0.0181f, 0.0185f, 0.02f, -0.1f));
    w.body[0x5B0 / 4] = bits(rnd() & 1 ? 1.0f : PICK(0.0f, 0.5f, 0.999f, 1.001f, -1.0f));
    w.player[0x14 / 4] = P(w.tuning);
    w.player[0x48 / 4] = P(w.slot);
    w.tuning[0x24 / 4] = bits(PICK(0.0f, 0.5f, 0.97f, 0.98f, 1.0f, 1.09f, 2.0f, -1.0f));
    w.slot[0x44 / 4] = P(&w.handle);
    if (rnd() % 3 == 0) w.handle = 0;
    w.stick[0x24 / 4] = bits(PICK(0.0f, 0.3f, 1.0f, -1.0f));
    w.stick[0x28 / 4] = bits(PICK(0.0f, -0.0f, 1.0f, -1.0f, 0.01f, -0.01f));
    if (rnd() & 1) w.turn[0x328 / 4] |= 2;
    ((uint8_t *)w.turn)[0x33C] = rnd() & 1 ? 9 : (uint8_t)rnd();
    w.actor[0] = P(w.vtable);
    w.vtable[0] = P(is_kind);
    w.vtable[0x60 / 4] = P(speed_factor);
    actor_is_kind = rnd() % 4 != 0;
    actor_missing = rnd() % 6 == 0;
    actor_factor = PICK(0.25f, 1.0f, 0.0f, 2.0f);
    data_00706E20 = P(manager);
    *(uint32_t *)(manager + 0x3DBBC) = rnd();
    data_007260CC = rnd() & 1;
    data_007260D0 = rnd();
}

/* ---- one comparison */
struct Result { struct World w; uint32_t ret, g1, g2, trace[64]; int ntrace; };
static void run(struct Result *r, int old, int whole, float dt, int painting) {
    ntrace = 0;
    memset(trace, 0, sizeof trace);
    float f = whole ? (old ? old_002D5ADC : func_002D5ADC)((int)P(w.walk), dt)
                    : (old ? old_002900EC : func_002900EC)(P(w.player), painting);
    r->w = w; r->ret = bits(f); r->g1 = data_007260CC; r->g2 = data_007260D0; r->ntrace = ntrace;
    memcpy(r->trace, trace, sizeof trace);
}

int main(int argc, char **argv) {
    long rounds = argc > 1 ? atol(argv[1]) : 2000000;
    DAT_002d5c40 = flt(0x39d1b717);
    DAT_002d5c48 = flt(0x3c978d50);
    static struct Result a, b;
    long painted = 0, with_actor = 0, built = 0;
    for (long i = 0; i < rounds; i++) {
        make_world();
        struct World start = w;
        uint32_t g1 = data_007260CC, g2 = data_007260D0;
        int whole = i % 4 != 0, painting = rnd() & 1;
        float dt = PICK(1.0f, 0.5f, 2.0f, 0.0f, -1.0f);
        run(&a, 1, whole, dt, painting);
        w = start; data_007260CC = g1; data_007260D0 = g2;
        run(&b, 0, whole, dt, painting);
        if (memcmp(&a, &b, sizeof a)) {
            printf("DIFFERENT at round %ld (%s): return %08x / %08x, calls %d / %d\n", i,
                   whole ? "walk_update" : "base speed", a.ret, b.ret, a.ntrace, b.ntrace);
            const uint32_t *x = (const uint32_t *)&a, *y = (const uint32_t *)&b;
            for (size_t k = 0; k < sizeof a / 4; k++)
                if (x[k] != y[k])
                    printf("  word %zu of the result (world %zu words, then return, 2 globals, trace): %08x / %08x\n",
                           k, sizeof w / 4, x[k], y[k]);
            return 1;
        }
        painted += whole && start.body[0x5B0 / 4] != bits(1.0f);
        for (int k = 0; k < a.ntrace; k++) with_actor += a.trace[k] == 7;
        built += whole && flt(a.w.walk[0x60 / 4]) > 0.0f;
    }
    printf("identical in %ld rounds (%ld as a painting, %ld reached an actor's speed factor, %ld with momentum)\n",
           rounds, painted, with_actor, built);
    return 0;
}
