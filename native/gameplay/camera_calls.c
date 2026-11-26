/* Calls on the wall-painting camera, handed on through the camera manager (rewritten from the ARM code).
 *
 * On the console each of these is two or three instructions that load the object and jump, so every other
 * argument travels along untouched. The decompiled versions declared only the object, and the method at the
 * end received whatever lay in the argument slots (a boss room crashed in 0034E460; BOOT_LOG 186).
 *
 *     004ED4D4 (EU 004ED4AC) -> 001E8C2C -> method +0x28  0034E460 (camera, id, position, flag)
 *     004ED714 (EU 004ED6EC) -> 001E8C74 -> method +0x2C  0034F510 (camera, vector)
 *     004ED678 (EU 004ED650) -> 001E8C5C -> method +0x30  0034F508 (camera, value)
 *
 * Callers: 003232A8 and its neighbour (the first), 002E8400 (the other two). */
#include "gameplay.h"

/* manager -> +0x18 -> +0x1C8 -> +0xE34: the camera object; its first word is the table of methods */
static void *wall_camera(const void *manager) {
    const char *holder = gp_ptr(FLD(manager, 0x18, uint32_t));
    const char *scene = gp_ptr(FLD(holder, 0x1C8, uint32_t));
    return gp_ptr(FLD(scene, 0xE34, uint32_t));
}

static void *method(const void *camera, int offset) {
    const char *table = gp_ptr(*(const uint32_t *)camera);
    return gp_ptr(FLD(table, offset, uint32_t));
}

/* aim at `position` for the thing `id` (a negative id ends it; position is not read then) */
void func_004ED4D4(void *manager, int id, const float *position, int flag) {
    void *camera = wall_camera(manager);
    ((void (*)(void *, int, const float *, int))method(camera, 0x28))(camera, id, position, flag);
}

void func_004ED714(void *manager, const float *vector) {
    void *camera = wall_camera(manager);
    ((void (*)(void *, const float *))method(camera, 0x2C))(camera, vector);
}

void func_004ED678(void *manager, float value) {
    void *camera = wall_camera(manager);
    ((void (*)(void *, float))method(camera, 0x30))(camera, value);
}
