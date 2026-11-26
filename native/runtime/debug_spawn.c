/* Debug: spawn any actor by its profile name next to Link (ALBW_ROUTE `spawn NAME [DX DZ]`), and
 * Link's real position for the route autopilot.
 *
 * Profiles: 0019B51C registers every actor profile at start-up into the table data_00727C28
 * (0x280 entries, read by 0019B04C(id)); profile +4 = create function, +0x10 = name (char *).
 * Spawning as the game's own helper 00512030 does (EU 00512008..005120B4): SpawnParam (0x2C4
 * bytes) reset by 002DFF7C; +0 profile, +4 position, +0x18 = 0, +0x44 = 0.0f (its "param_3 == 0"
 * case), +0x4C = parent actor handle (0 = none), +0x50 = (s16)-1, +0x2C0 |= 1; then
 * 004C4AF4(*data_00706E20 = actor manager, &param, 0) -> the actor (NULL on failure).
 * Link's position: 00520FC0 (EU 00520F98) = *(*data_0070FB60 + 0x1C), a Vec3 *. */
#define _GNU_SOURCE
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

extern char data_0070FB60[], data_00706E20[];
extern long g_plat_frames;
int func_0019B04C(uint32_t id);
int func_002DFF7C(void *self);
int func_004C4AF4(int mgr, int *param, int flags);
void func_0019B064(int profile, int flag, uint32_t arg);
uint32_t func_002E01AC(uint32_t id);   /* number of resource slots of a profile id */
uint32_t func_002E0150(uint32_t id);   /* the profile's resource name list (ActorProfile data) */

const float *albw_debug_player_pos(void) {
    uint32_t root = *(uint32_t *)data_0070FB60;
    if (!root) return NULL;
    uint32_t p = *(uint32_t *)(uintptr_t)(root + 0x1C);
    return p ? (const float *)(uintptr_t)p : NULL;
}

int albw_debug_profile(const char *name) {
    for (uint32_t id = 0; id < 0x280; id++) {
        uint32_t prof = (uint32_t)func_0019B04C(id);
        if (!prof) continue;
        const char *n = (const char *)(uintptr_t)*(uint32_t *)(uintptr_t)(prof + 0x10);
        if (n && !strcmp(n, name)) return (int)id;
    }
    return -1;
}

/* The enemies spawned here, to take them out again when Link leaves the area (BOOT_LOG 174). The
 * overworld loads and releases areas as Link walks: the game removes an area's own actors before it
 * frees their data, but one made here belongs to no area, stayed alive and animated from freed
 * memory (crash a few steps over the border). Saved with save states, like the actors. */
#define SPAWNED_MAX 64
static struct { uint32_t actor, id, area; } g_spawned[SPAWNED_MAX];
static uint32_t area_key(void) {
    extern char data_00709DF8[];
    uint32_t mgr = *(uint32_t *)data_00709DF8;
    if (!mgr) return 0;
    return 1u << 31 | (uint32_t)*(uint8_t *)(uintptr_t)(mgr + 0x18) << 16 |
           (*(uint32_t *)(uintptr_t)(mgr + 0x1C) & 0xFFFF);
}
static void remember_spawn(uint32_t a) {
    for (int i = 0; i < SPAWNED_MAX; i++)
        if (!g_spawned[i].actor || g_spawned[i].actor == a) {
            g_spawned[i].actor = a;
            g_spawned[i].id = *(uint32_t *)(uintptr_t)(a + 4);
            g_spawned[i].area = area_key();
            return;
        }
}

/* 1 when every resource slot of the profile is filled: its pack is loaded here */
int albw_debug_ready(const char *name) {
    int id = albw_debug_profile(name);
    if (id < 0) return 0;
    uint32_t prof = (uint32_t)func_0019B04C((uint32_t)id);
    uint32_t n = func_002E01AC(*(uint32_t *)(uintptr_t)(prof + 8)) & 0xFF;
    for (uint32_t i = 0; i < n; i++)
        if (*(uint32_t *)(uintptr_t)(prof + 0x1C8 + i * 4) == 0) return 0;
    return 1;
}

void *albw_debug_spawn(const char *name, float dx, float dz) {
    const float *pp = albw_debug_player_pos();
    int id = albw_debug_profile(name);
    if (!pp || id < 0) {
        fprintf(stderr, "spawn: %s: %s\n", name, id < 0 ? "no such profile" : "no player");
        return NULL;
    }
    if (!albw_debug_ready(name)) {   /* creating it would read a missing model and crash */
        fprintf(stderr, "spawn: %s: its data is not loaded in this area\n", name);
        return NULL;
    }
    _Alignas(16) uint8_t sp[0x2D0];
    memset(sp, 0, sizeof sp);
    func_002DFF7C(sp);
    *(uint32_t *)(sp + 0) = (uint32_t)func_0019B04C((uint32_t)id);
    float pos[3] = { pp[0] + dx, pp[1], pp[2] + dz };
    memcpy(sp + 4, pos, 12);
    *(uint32_t *)(sp + 0x18) = 0;
    float zero = 0.0f;
    memcpy(sp + 0x44, &zero, 4);
    *(uint32_t *)(sp + 0x4C) = 0;
    *(int16_t *)(sp + 0x50) = -1;
    *(uint32_t *)(sp + 0x2C0) |= 1;
    int full = 1;
    for (int i = 0; i < SPAWNED_MAX; i++) if (!g_spawned[i].actor) full = 0;
    if (full) { fprintf(stderr, "spawn: %s: too many spawned already\n", name); return NULL; }
    int *a = (int *)(intptr_t)func_004C4AF4((int)*(uint32_t *)data_00706E20, (int *)sp, 0);
    fprintf(stderr, "spawn: %s (profile %d) at %.2f %.2f %.2f -> %p\n", name, id, pos[0], pos[1], pos[2], (void *)a);
    if (a) remember_spawn((uint32_t)(uintptr_t)a);
    return a;
}

/* request the profile's resources (Actor/<res>.bch in the World archive, 0019B064) before the
 * create: 004C4AF4 requests them too but creates in the same call, and an actor whose model is not
 * loaded yet reads NULL in its constructor (EnemySoldierGreen in Lorule Castle: 00533304).
 * Returns the number of empty resource slots left (0 = all requested / present). */
int albw_debug_preload(const char *name) {
    int id = albw_debug_profile(name);
    if (id < 0) { fprintf(stderr, "spawn: %s: no such profile\n", name); return -1; }
    uint32_t prof = (uint32_t)func_0019B04C((uint32_t)id);
    uint32_t n = func_002E01AC(*(uint32_t *)(uintptr_t)(prof + 8)) & 0xFF, empty = 0;
    for (uint32_t i = 0; i < n; i++)
        if (*(uint32_t *)(uintptr_t)(prof + 0x1C8 + i * 4) == 0) empty++;
    uint32_t lst = func_002E0150(*(uint32_t *)(uintptr_t)(prof + 8));
    fprintf(stderr, "spawn: %s: name list %#x", name, lst);
    if (lst) for (uint32_t i = 0; i < n; i++) {
        uint32_t sp = *(uint32_t *)(uintptr_t)(lst + i * 8 + 4);
        fprintf(stderr, " '%s'", sp ? (const char *)(uintptr_t)sp : "(null)");
    }
    fprintf(stderr, "\n");
    if (empty) func_0019B064((int)prof, 0, 0);
    fprintf(stderr, "spawn: %s: %u resource slot(s), %u requested; slots now", name, n, empty);
    for (uint32_t i = 0; i < n; i++) fprintf(stderr, " %#x", *(uint32_t *)(uintptr_t)(prof + 0x1C8 + i * 4));
    fprintf(stderr, "\n");
    return (int)empty;
}

/* list every registered profile name (ALBW_PROFILES=1, printed once by the route) */
void albw_debug_list_profiles(void) {
    for (uint32_t id = 0; id < 0x280; id++) {
        uint32_t prof = (uint32_t)func_0019B04C(id);
        if (!prof) continue;
        const char *n = (const char *)(uintptr_t)*(uint32_t *)(uintptr_t)(prof + 0x10);
        if (!n) continue;
        fprintf(stderr, "profile %d %s", (int)id, n);
        uint32_t k = func_002E01AC(*(uint32_t *)(uintptr_t)(prof + 8)) & 0xFF;
        uint32_t lst = func_002E0150(*(uint32_t *)(uintptr_t)(prof + 8));
        if (lst) for (uint32_t i = 0; i < k; i++) {
            uint32_t sp = *(uint32_t *)(uintptr_t)(lst + i * 8 + 4);
            if (sp) fprintf(stderr, " res=%s", (const char *)(uintptr_t)sp);
        }
        fprintf(stderr, "\n");
    }
}

/* list live actors: profile name and position (actor +0x2D0 profile, +0x3D0 position); walks the
 * actor manager's list (*data_00706E20 + 0x3DBBC) with the game's walker 0052FD7C */
void func_0052FD7C(void *list, void (*fn)(void *, uint32_t), uint32_t arg);
static void list_one(void *actor, uint32_t filter) {
    uint32_t a = (uint32_t)(uintptr_t)actor;
    uint32_t prof = *(uint32_t *)(uintptr_t)(a + 0x2D0);
    const char *n = prof ? (const char *)(uintptr_t)*(uint32_t *)(uintptr_t)(prof + 0x10) : "?";
    const float *p = (const float *)(uintptr_t)(a + 0x3D0);
    (void)filter;
    fprintf(stderr, "actor %#x %-24s %.2f %.2f %.2f\n", a, n ? n : "?", p[0], p[1], p[2]);
}
void albw_debug_list_actors(void) {
    uint32_t mgr = *(uint32_t *)data_00706E20;
    if (mgr) func_0052FD7C((void *)(uintptr_t)(mgr + 0x3DBBC), list_one, 0);
}

/* every frame: once the area is another one, flag the actors made in the old one for removal (the
 * byte +0x2D7 the actor manager acts on, as when an actor removes itself); only an actor that is
 * still listed with the same id */
static void reap_one(void *actor, uint32_t arg) {
    (void)arg;
    uint32_t a = (uint32_t)(uintptr_t)actor, key = area_key();
    for (int i = 0; i < SPAWNED_MAX; i++)
        if (g_spawned[i].actor == a && g_spawned[i].area != key && g_spawned[i].id == *(uint32_t *)(uintptr_t)(a + 4)) {
            *(uint8_t *)(uintptr_t)(a + 0x2D7) = 1;
            fprintf(stderr, "spawn: removed %#x (Link left its area)\n", a);
        }
}
void albw_debug_area_check(void) {
    uint32_t mgr = *(uint32_t *)data_00706E20, key = area_key();
    int stale = 0;
    for (int i = 0; i < SPAWNED_MAX; i++)
        if (g_spawned[i].actor && g_spawned[i].area != key) stale = 1;
    if (!stale || !mgr || !key) return;
    func_0052FD7C((void *)(uintptr_t)(mgr + 0x3DBBC), reap_one, 0);
    for (int i = 0; i < SPAWNED_MAX; i++)
        if (g_spawned[i].actor && g_spawned[i].area != key) g_spawned[i].actor = 0;
}

/* Start a scripted sequence by flowchart entry name (route step `event NAME`, debug).
 * The game requests an event through an event component's virtual +0x48 = 00503180
 * (component, owner actor or 0, &flag, sead::SafeString *entry): it queues the component with the
 * event manager (004CDDEC) and copies the entry name; the manager then starts it like any talk /
 * area event. This uses the first live actor that is such a component (AreaEventTalk and other
 * area-event actors); the entry's flowchart must be one the current area loads
 * (native/SCRIPTED_EVENTS.md, column "Loaded in"). Returns 1 when the request was accepted. */
int func_00503180(void *self, int owner, uint8_t *flag, void *entry);
extern char data_006F5988[], data_0070B728[];   /* SafeString vtable; event manager pointer */
static uint32_t g_event_comp;
static int is_event_vt(uint32_t vt) {
    /* a game vtable (generated data at 0x30000000..) whose +0x48 is the event request 00503180 */
    return vt >= 0x30000000u && vt < 0x30100000u &&
           *(uint32_t *)(uintptr_t)(vt + 0x48) == (uint32_t)(uintptr_t)func_00503180;
}
static void find_event_comp(void *actor, uint32_t arg) {
    (void)arg;
    uint32_t a = (uint32_t)(uintptr_t)actor;
    if (g_event_comp)
        return;
    /* the component is the actor itself or a member (AreaEventTalk, TagItemEvent +0x434) */
    for (uint32_t o = 0; o < 0xB00; o += 4) {
        if (is_event_vt(*(uint32_t *)(uintptr_t)(a + o))) {
            g_event_comp = a + o;
            if (getenv("ALBW_EVENT_DEBUG"))
                fprintf(stderr, "event: component at actor %#x + %#x\n", a, o);
            return;
        }
    }
}
int albw_debug_event(const char *name) {
    uint32_t mgr = *(uint32_t *)data_00706E20;
    if (!mgr) return 0;
    g_event_comp = 0;
    func_0052FD7C((void *)(uintptr_t)(mgr + 0x3DBBC), find_event_comp, 0);
    if (!g_event_comp) {
        fprintf(stderr, "event: no event component in this area\n");
        return 0;
    }
    static char buf[128];
    snprintf(buf, sizeof buf, "%s", name);
    static uint32_t str[2];               /* sead::SafeString { vtable, cstr } */
    str[0] = (uint32_t)(uintptr_t)data_006F5988;
    str[1] = (uint32_t)(uintptr_t)buf;
    uint8_t flag = 0;
    /* the manager accepts requests only inside its update (004CDBEC sets +0x10 around the event
     * calls); the route runs between frames, so raise it for this call */
    uint32_t em = *(uint32_t *)data_0070B728;
    uint8_t was = em ? *(uint8_t *)(uintptr_t)(em + 0x10) : 0;
    if (em) *(uint8_t *)(uintptr_t)(em + 0x10) = 1;
    int ok = func_00503180((void *)(uintptr_t)g_event_comp, 0, &flag, str);
    if (em) *(uint8_t *)(uintptr_t)(em + 0x10) = was;
    fprintf(stderr, "event: %s via component %#x: %s\n", name, g_event_comp, ok ? "requested" : "refused");
    return ok;
}

/* robust_pmf.h guard: a delegate whose target is not code (BOOT_LOG 160e). Logged, never fatal. */
void albw_delegate_bad(const char *dlg, const void *fn) {
    static int n;
    if (n++ >= 8) return;
    const uint32_t *w = (const uint32_t *)dlg;
    fprintf(stderr, "delegate: target %p is not code (dlg %p: %08x %08x %08x %08x, frame %ld, caller %p) - call skipped\n",
            fn, (const void *)dlg, w[0], w[1], w[2], w[3], g_plat_frames, __builtin_return_address(0));
}
