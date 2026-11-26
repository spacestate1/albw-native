/* The top screen's view: how much of the world the camera shows.
 *
 * 0057F6C0 (EU 0057F698) builds the projection matrix of a perspective camera (the engine's
 * sead::PerspectiveProjection). It is the game's function rewritten from the ARM code with named fields,
 * plus the two ways the port can show more of the world:
 *
 *     widescreen   the top screen is wider, so the view is widened to match (more at the sides)
 *     zoom out     the view angle is opened in both directions, so everything is drawn smaller and
 *                  more of it fits (Esc > Video > Zoom out, PageUp / PageDown)
 *
 * Only cameras with the top screen's shape are changed; the bottom screen and square render targets keep
 * the original view. The same two factors are applied to the matrix used to decide what to draw
 * (001312BC), and the culling frustum is built from this matrix (003FB1D0), so what enters the wider view
 * is drawn.
 *
 * The matrix is only rebuilt while the projection is marked dirty, so each top-screen projection is
 * remembered with the view it was built for; albw_view_refresh (every frame) marks the ones that no
 * longer match. This also covers loading a save state made with other settings.
 *
 * Checked against the previous version by tools/tests/view_projection_test.sh.
 */
#include <stddef.h>
#include "gameplay.h"

float albw_ws_factor(void);     /* render.c: how much wider the top screen is (1 = not widescreen) */
float albw_view_zoom(void);     /* platform.c: 1 = the game's own view, 2 = twice as much each way */

/* the fields of the projection object used here */
typedef struct {
    uint32_t vtable;            /* +0x00 */
    uint8_t matrix_dirty;       /* +0x04  set: the matrix is rebuilt at its next use */
    uint8_t unused0[0x94 - 0x05];
    float near_distance;        /* +0x94  to the near clip plane */
    float far_distance;         /* +0x98  to the far clip plane */
    uint8_t unused1[0xA8 - 0x9C];
    float tan_half_fovy;        /* +0xA8  tangent of half the vertical view angle */
    float aspect;               /* +0xAC  width / height */
    float offset_x;             /* +0xB0  shift of the view, as a share of its width ... */
    float offset_y;             /* +0xB4  ... and of its height */
} PerspectiveProjection;

_Static_assert(offsetof(PerspectiveProjection, near_distance) == 0x94, "PerspectiveProjection layout");
_Static_assert(offsetof(PerspectiveProjection, tan_half_fovy) == 0xA8, "PerspectiveProjection layout");
_Static_assert(offsetof(PerspectiveProjection, offset_y) == 0xB4, "PerspectiveProjection layout");

/* ------------------------------------------------------------------ which projections need a rebuild */

#define REMEMBERED 64
/* game state: saved and restored with the game memory these records describe */
static struct { uint32_t projection, vtable; float view; } g_ws_proj[REMEMBERED];

/* one number for a combination of settings (the widening is between 1 and 2) */
static float current_view(void) { return albw_ws_factor() + albw_view_zoom() * 8.0f; }

static int still_there(int i) {
    return g_ws_proj[i].projection && *(uint32_t *)gp_ptr(g_ws_proj[i].projection) == g_ws_proj[i].vtable;
}

static void remember(const PerspectiveProjection *p) {
    int free_slot = -1;
    for (int i = 0; i < REMEMBERED; i++) {
        if (g_ws_proj[i].projection == gp_u32(p)) {
            free_slot = i;
            break;
        }
        if (free_slot < 0 && !still_there(i))
            free_slot = i;
    }
    if (free_slot < 0)
        return;
    g_ws_proj[free_slot].projection = gp_u32(p);
    g_ws_proj[free_slot].vtable = p->vtable;
    g_ws_proj[free_slot].view = current_view();
}

void albw_view_refresh(void) {
    float view = current_view();
    for (int i = 0; i < REMEMBERED; i++) {
        if (!g_ws_proj[i].projection)
            continue;
        if (!still_there(i))
            g_ws_proj[i].projection = 0;
        else if (g_ws_proj[i].view != view)
            ((PerspectiveProjection *)gp_ptr(g_ws_proj[i].projection))->matrix_dirty = 1;
    }
}

/* ------------------------------------------------------------------ the matrix */

/* 400 x 240, with room for rounding */
static int has_top_screen_shape(float aspect) { return aspect > 1.66f && aspect < 1.672f; }

/* A 4 x 4 perspective matrix, row by row, from the edges of the near plane. */
static void write_matrix(float *m, float near_distance, float far_distance,
                         float left, float right, float bottom, float top) {
    float per_width = 1.0f / (right - left);
    float per_height = 1.0f / (top - bottom);
    float per_depth = 1.0f / (far_distance - near_distance);

    m[0] = near_distance * per_width * 2.0f;
    m[1] = 0.0f;
    m[2] = (right + left) * per_width;
    m[3] = 0.0f;

    m[4] = 0.0f;
    m[5] = near_distance * per_height * 2.0f;
    m[6] = (top + bottom) * per_height;
    m[7] = 0.0f;

    m[8] = 0.0f;
    m[9] = 0.0f;
    m[10] = -(far_distance * per_depth);
    m[11] = -(far_distance * near_distance * per_depth);

    m[12] = 0.0f;
    m[13] = 0.0f;
    m[14] = -1.0f;
    m[15] = 0.0f;
}

static void build_projection(PerspectiveProjection *p, float *matrix) {
    /* the size of the view where it crosses the near plane */
    float height = p->near_distance * p->tan_half_fovy * 2.0f;
    float aspect = p->aspect;

    if (has_top_screen_shape(aspect)) {
        remember(p);
        height *= albw_view_zoom();
        aspect *= albw_ws_factor();
    }
    float width = height * aspect;

    float centre_x = p->offset_x * width;
    float centre_y = p->offset_y * height;
    write_matrix(matrix, p->near_distance, p->far_distance,
                 centre_x - width * 0.5f, centre_x + width * 0.5f,
                 centre_y - height * 0.5f, centre_y + height * 0.5f);
}

/* ------------------------------------------------------------------ the entry point the game calls */

int func_0057F6C0(int projection, float *matrix) {
    build_projection(gp_ptr((uint32_t)projection), matrix);
    return projection;
}
