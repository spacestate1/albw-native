/* Single-screen bottom-screen selector (included by platform.c; BOOT_LOG 160ab).
 *
 * In single-screen mode the bottom screen (map, Items, Gear) is shown in place of the top one and
 * there is no mouse on a controller: the D-pad (or a circle-pad flick) moves a selector between the
 * page's touch targets and A taps the one under it. The selector is the user's grid-selector
 * graphic (native/platform/assets/grid-selector.png, embedded by selector_img.h) drawn as an
 * overlay on the bottom screen's image, not a pointer. The page is recognised every frame from pixels
 * of the bottom screen: Gear (red frame), Items (the greige rim of its grid), a dungeon map (blue-grey
 * frame), the world map (orange scroll top left; with the bell button bottom left once Link has the
 * bell: its yellow icon), else another page with
 * controls of its own (the bell's warp menu), where the D-pad and A go to the game. Targets are in 3DS bottom
 * screen pixels (320 x 240, origin top left), measured on the game's pages. */
#include "selector_img.h"

/* the platform blit with a texture sub-rectangle (uvr = u0, v0, du, dv) */
static const char *SEL_VS =
    "#version 330 core\n"
    "uniform vec4 rect; uniform vec4 uvr; out vec2 uv;\n"
    "void main(){ vec2 p = vec2(gl_VertexID & 1, gl_VertexID >> 1); uv = uvr.xy + p * uvr.zw;\n"
    "  gl_Position = vec4(rect.xy + p * rect.zw, 0, 1); }\n";

typedef struct { int16_t x, y, w, h; uint8_t native; } SelTarget;   /* centre, size; native: the game draws its own cursor there */

static const SelTarget SEL_MAP[] = {
    {22, 20, 40, 40},                        /* + (pins) */
    {22, 72, 40, 40},                        /* Maiamai Map icon (once Link has the map; Mother Maiamai asks for a tap) */
    {22, 142, 36, 40},                       /* pin counter */
    {288, 135, 46, 46},                      /* Y item slot */
    {80, 226, 156, 26}, {240, 226, 156, 26}, /* Gear / Items tabs */
};
/* the map page once Link has the bell (Irene's weather-vane warp): a bell button bottom left, the
   Gear / Items tabs move right and get narrower */
static const SelTarget SEL_MAP_BELL[] = {
    {22, 20, 40, 40},                        /* + (pins) */
    {22, 72, 40, 40},                        /* Maiamai Map icon (once Link has the map; Mother Maiamai asks for a tap) */
    {22, 142, 36, 40},                       /* pin counter */
    {288, 135, 46, 46},                      /* Y item slot */
    {28, 226, 52, 26},                       /* bell */
    {124, 226, 124, 26}, {255, 226, 128, 26}, /* Gear / Items tabs */
};
/* a dungeon's map: floor buttons on the left instead of the pins; wide Gear / Items tabs */
static const SelTarget SEL_DUNGEON[] = {
    {35, 54, 62, 34}, {35, 97, 62, 34}, {35, 139, 62, 34},   /* floors */
    {288, 138, 46, 46},                                       /* Y item slot */
    {80, 226, 156, 26}, {240, 226, 156, 26},                  /* Gear / Items tabs */
};
static const SelTarget SEL_ITEMS[] = {
    {33, 27, 46, 44, 1}, {80, 27, 46, 44, 1}, {127, 27, 46, 44, 1}, {174, 27, 46, 44, 1}, {221, 27, 46, 44, 1},
    {33, 72, 46, 44, 1}, {80, 72, 46, 44, 1}, {127, 72, 46, 44, 1}, {174, 72, 46, 44, 1}, {221, 72, 46, 44, 1},
    {33, 117, 46, 44, 1}, {80, 117, 46, 44, 1}, {127, 117, 46, 44, 1}, {174, 117, 46, 44, 1}, {221, 117, 46, 44, 1},
    {33, 162, 46, 44, 1}, {80, 162, 46, 44, 1}, {127, 162, 46, 44, 1}, {174, 162, 46, 44, 1}, {221, 162, 46, 44, 1},
    {285, 135, 50, 50},                      /* Y item slot */
    {160, 226, 300, 26},                     /* Close */
};
static const SelTarget SEL_GEAR[] = {
    {37, 40, 40, 40}, {82, 40, 40, 40}, {125, 40, 40, 40},                       /* sword, tunic, - */
    {37, 92, 40, 40}, {80, 92, 40, 40}, {122, 92, 40, 40},                       /* rings */
    {37, 133, 40, 40}, {80, 133, 40, 40}, {122, 133, 40, 40},
    {232, 26, 30, 32}, {185, 40, 30, 32}, {285, 40, 30, 32}, {232, 63, 30, 30},  /* pendants etc. */
    {169, 95, 28, 32}, {208, 101, 30, 30}, {256, 101, 30, 30}, {298, 95, 28, 32},
    {202, 140, 30, 32}, {262, 140, 30, 32},
    {33, 178, 40, 36},                                                            /* heart */
    {85, 178, 40, 24}, {127, 178, 40, 24}, {165, 178, 40, 24}, {205, 178, 40, 24}, {245, 178, 40, 24}, {285, 178, 40, 24},
    {160, 226, 300, 26},                                                          /* Close */
};
/* the world map dimmed by a cutscene with only the Maiamai Map icon lit (Mother Maiamai: "tap the Maiamai
   Map icon on your Touch Screen"): that icon is the one target */
static const SelTarget SEL_MAIAMAI[] = {
    {22, 72, 40, 40},
};
enum { SEL_PAGE_MAP, SEL_PAGE_ITEMS, SEL_PAGE_GEAR, SEL_PAGE_MAP_BELL, SEL_PAGE_DUNGEON, SEL_PAGE_MAIAMAI,
       SEL_PAGE_OTHER /* a page with controls of its own (the bell's warp menu): input passes through */ };
static const struct { const SelTarget *t; int n; } SEL_PAGES[6] = {
    {SEL_MAP, (int)(sizeof SEL_MAP / sizeof *SEL_MAP)},
    {SEL_ITEMS, (int)(sizeof SEL_ITEMS / sizeof *SEL_ITEMS)},
    {SEL_GEAR, (int)(sizeof SEL_GEAR / sizeof *SEL_GEAR)},
    {SEL_MAP_BELL, (int)(sizeof SEL_MAP_BELL / sizeof *SEL_MAP_BELL)},
    {SEL_DUNGEON, (int)(sizeof SEL_DUNGEON / sizeof *SEL_DUNGEON)},
    {SEL_MAIAMAI, (int)(sizeof SEL_MAIAMAI / sizeof *SEL_MAIAMAI)},
};

static int g_sel_page, g_sel_idx, g_sel_on;
static int g_sel_warp, g_sel_warp_ok;      /* the bell's warp map is up / its "A OK" button is offered */
static int g_sel_close_in;                 /* frames until the bottom screen is put away (warp confirmed) */
static int g_sel_x = 160, g_sel_y = 120;   /* last selected centre (kept across pages) */
static int g_sel_touch;                    /* A held: touch at the target */
static int g_sel_autotap;                  /* frames of a tap when moving onto a native-cursor target */
static int g_sel_arrive;                   /* frames until the Items page, just opened, gets that tap */
static uint32_t g_sel_prev;
static GLuint g_sel_tex;

static int sel_active(void) { return g_layout_cfg.single_screen && g_layout_cfg.show_bottom && !g_ss_front; }

static int sel_nearest(int page, int x, int y) {
    const SelTarget *t = SEL_PAGES[page].t;
    int best = 0;
    long bd = -1;
    for (int i = 0; i < SEL_PAGES[page].n; i++) {
        long dx = t[i].x - x, dy = t[i].y - y, d = dx * dx + dy * dy;
        if (bd < 0 || d < bd) { bd = d; best = i; }
    }
    return best;
}

/* the target nearest in direction (dx, dy): ahead along that axis, the side offset counted double */
static int sel_step(int page, int cur, int dx, int dy) {
    const SelTarget *t = SEL_PAGES[page].t;
    int best = cur;
    long bs = -1;
    for (int i = 0; i < SEL_PAGES[page].n; i++) {
        if (i == cur) continue;
        long ax = t[i].x - t[cur].x, ay = t[i].y - t[cur].y;
        long along = ax * dx + ay * dy, side = dx ? ay : ax;
        if (along <= 4 || along * 17 < (side < 0 ? -side : side) * 10) continue;   /* ~60 degree cone */
        long s = along + 2 * (side < 0 ? -side : side);
        if (bs < 0 || s < bs) { bs = s; best = i; }
    }
    return best;
}

/* plat_poll: D-pad / circle-pad flicks move, A taps (both taken from the game while active) */
static void sel_input(PlatInput *pin) {
    if (!sel_active()) {
        g_sel_on = 0;
        g_sel_touch = 0;
        g_sel_prev = pin->held;
        return;
    }
    if (g_sel_close_in > 0 && --g_sel_close_in == 0 && g_layout_cfg.show_bottom) {
        g_sel_warp = g_sel_warp_ok = 0;
        plat_single_screen_flip();   /* the warp was confirmed: show the scene (Irene arriving) */
        g_sel_prev = pin->held;
        return;
    }
    if (g_sel_page == SEL_PAGE_OTHER) {   /* the game's own menu (bell warp list): D-pad and A are its */
        /* the warp map with a destination picked: A (or a tap on "A OK") confirms the warp; the game keeps
         * the warp map on the bottom screen while Irene flies in, so put the panel away after it (user) */
        uint32_t edge = pin->held & ~g_sel_prev;
        int tap_ok = pin->touch && pin->touch_x >= 200 && pin->touch_y >= 212;
        if (g_sel_warp && g_sel_warp_ok && ((edge & KEY_A) || tap_ok) && !g_sel_close_in) {
            g_sel_close_in = 3;
            if (getenv("ALBW_SEL_TRACE")) fprintf(stderr, "selector: f=%ld warp confirmed: bottom screen closes\n", g_plat_frames);
        }
        g_sel_on = 0;
        g_sel_touch = 0;
        g_sel_prev = pin->held;
        return;
    }
    if (!g_sel_on) { g_sel_on = 1; g_sel_idx = sel_nearest(g_sel_page, g_sel_x, g_sel_y); }
    const uint32_t up = KEY_DUP | KEY_CPAD_UP, down = KEY_DDOWN | KEY_CPAD_DOWN;
    const uint32_t left = KEY_DLEFT | KEY_CPAD_LEFT, right = KEY_DRIGHT | KEY_CPAD_RIGHT;
    uint32_t held = pin->held, edge = held & ~g_sel_prev;
    g_sel_prev = held;
    int n = SEL_PAGES[g_sel_page].n;
    if (g_sel_idx >= n) g_sel_idx = n - 1;
    int dx = (edge & right) ? 1 : (edge & left) ? -1 : 0;
    int dy = (edge & down) ? 1 : (edge & up) ? -1 : 0;
    int was = g_sel_idx;
    if (dx) g_sel_idx = sel_step(g_sel_page, g_sel_idx, dx, 0);
    if (dy) g_sel_idx = sel_step(g_sel_page, g_sel_idx, 0, dy);
    /* the game draws its own cursor on these (Items grid): select by a short tap so it follows */
    if (g_sel_idx != was && SEL_PAGES[g_sel_page].t[g_sel_idx].native) g_sel_autotap = 4;
    /* the Items page has just opened with the game's cursor elsewhere: the same tap, once the page has
       faded in, brings it here (two cursors were shown). A move or A meanwhile makes it unnecessary. */
    if (g_sel_arrive > 0) {
        if (g_sel_page != SEL_PAGE_ITEMS || g_sel_idx != was || (held & KEY_A)) g_sel_arrive = 0;
        else if (--g_sel_arrive == 0 && SEL_PAGES[g_sel_page].t[g_sel_idx].native) g_sel_autotap = 4;
    }
    const SelTarget *t = &SEL_PAGES[g_sel_page].t[g_sel_idx];
    g_sel_x = t->x;
    g_sel_y = t->y;
    {   /* ALBW_SEL_TRACE=1: page / target changes and taps */
        static int lp = -1, li = -1, la;
        int tap = (held & KEY_A) != 0;
        if ((lp != g_sel_page || li != g_sel_idx || la != tap) && getenv("ALBW_SEL_TRACE"))
            fprintf(stderr, "selector: page %s target %d at %d,%d%s\n", g_sel_page == SEL_PAGE_GEAR ? "gear" : g_sel_page == SEL_PAGE_ITEMS ? "items" : g_sel_page == SEL_PAGE_DUNGEON ? "dungeon" : g_sel_page == SEL_PAGE_MAP_BELL ? "map+bell" : g_sel_page == SEL_PAGE_MAIAMAI ? "maiamai" : "map",
                    g_sel_idx, t->x, t->y, tap ? " TAP" : "");
        lp = g_sel_page; li = g_sel_idx; la = tap;
    }
    g_sel_touch = (held & KEY_A) != 0;
    if (g_sel_autotap > 0) g_sel_autotap--;
    if (g_sel_touch || g_sel_autotap > 0) {
        pin->touch = 1;
        pin->touch_x = t->x;
        pin->touch_y = t->y;
        held |= KEY_TOUCH;
    }
    pin->held = held & ~(up | down | left | right | KEY_A);
    pin->cpad_x = pin->cpad_y = 0;
}

/* the greige of the Items panel's rim (about 178, 155, 114): the dungeon map there is blue-grey, the world
   map orange, the Gear page red */
static int sel_is_items_rim(const uint8_t *p) { return p[0] > 150 && p[0] < 210 && p[1] > 130 && p[1] < 185 && p[2] > 85 && p[2] < 145; }

/* plat_composite (the screens were just drawn into the window): recognise the page from the bottom
 * screen's target, draw the selector over the bottom screen's place in the window.
 * Not in render_scanout / plat_end_frame: save states resume inside those (their code must stay). */
static __attribute__((noinline)) void sel_composite(const Layout *l) {
    if (!sel_active() || !l->visible[SCREEN_BOTTOM]) return;
    const Target *bt = &screens[SCREEN_BOTTOM];
    int w = bt->w, h = bt->h;
    if (w <= 0 || h <= 0) return;
    {   /* every frame: the screen has just come up, or its page has just changed, and the selector takes that
           page's place and size at once (looking every 10th frame left the old page's size on screen) */
        glBindFramebuffer(0x8CA8 /* GL_READ_FRAMEBUFFER */, bt->fbo);
        uint8_t a[4] = {0}, b[3][4] = {{0}}, c[4] = {0}, d[4] = {0};   /* d: top-left corner */
        glReadPixels(300 * w / 320, h - 1 - 60 * h / 240, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, a);
        /* the Items grid's panel, its rim below the last row: no item is drawn there (the middle of the grid,
           checked before, is a bottle's cell in some games: the page was not recognised). The X / Y bubble of
           the game's cursor reaches the rim, so two of three spots count */
        int rim = 0;
        for (int i = 0; i < 3; i++) {
            static const int x[3] = {80, 130, 176};
            glReadPixels(x[i] * w / 320, h - 1 - 196 * h / 240, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, b[i]);
            rim += sel_is_items_rim(b[i]);
        }
        glReadPixels(28 * w / 320, h - 1 - 226 * h / 240, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, c);   /* bell icon: pure yellow */
        glReadPixels(5 * w / 320, h - 1 - 5 * h / 240, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, d);   /* map frame colour */
        uint8_t mi[4] = {0};   /* the Maiamai Map icon's gold (about 230, 146, 3 lit) */
        glReadPixels(22 * w / 320, h - 1 - 72 * h / 240, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, mi);
        uint8_t ws[3][4] = {{0}};   /* the bell's warp map: the scroll rolled at x 40, dark wood left of it; "A OK" text */
        glReadPixels(40 * w / 320, h - 1 - 120 * h / 240, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, ws[0]);
        glReadPixels(25 * w / 320, h - 1 - 120 * h / 240, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, ws[1]);
        int ok_dark = 0;
        {   /* the "A OK" label: a block over it (x 244..263, y 221..230), dark letters counted (only wood otherwise) */
            static uint8_t blk[64 * 32 * 4];
            int bx = 244 * w / 320, by = h - 1 - 230 * h / 240, bw = 20 * w / 320, bh = 10 * h / 240;
            if (bw > 64) bw = 64;
            if (bh > 32) bh = 32;
            if (bw > 0 && bh > 0) {
                glReadPixels(bx, by, bw, bh, GL_RGBA, GL_UNSIGNED_BYTE, blk);
                for (int i = 0; i < bw * bh; i++) ok_dark += blk[i * 4] < 120;
            }
            (void)ws[2];
        }
        glBindFramebuffer(0x8CA8 /* GL_READ_FRAMEBUFFER */, 0);
        int world_map = d[0] > 200 && d[1] > 140 && d[2] < 110;   /* the orange scroll top left */
        /* the world map's bell button: its icon at full brightness means it is there. It is taken to be gone
           only when the wood of a Gear tab stays in its place for half a second; anything else (the buttons
           fading in as the page opens, a button held down, the warp menu's Cancel bar passing) leaves the map
           with the layout it had */
        static int bell, wood_frames;
        if (world_map && c[0] > 230 && c[1] > 190 && c[2] < 60) bell = 1, wood_frames = 0;
        else if (!world_map || !(c[0] > 150 && c[2] > 25)) wood_frames = 0;
        else if (++wood_frames >= 30) bell = 0;
        int page = (a[0] > 90 && a[1] < 45) ? SEL_PAGE_GEAR
                 : rim >= 2 ? SEL_PAGE_ITEMS
                 : (d[2] > 140 && d[2] > d[0] + 10) ? SEL_PAGE_DUNGEON          /* blue-grey dungeon frame */
                 : !world_map && d[0] > 70 && d[0] < 170 && d[1] > 45 && d[1] < 125 && d[2] < 60 &&
                   mi[0] > 190 && mi[1] > 100 && mi[1] < 185 && mi[2] < 50 ? SEL_PAGE_MAIAMAI   /* dimmed map scroll (about 108, 82, 29), icon lit */
                 : !world_map ? SEL_PAGE_OTHER                                    /* no orange map scroll: warp menu */
                 : bell ? SEL_PAGE_MAP_BELL : SEL_PAGE_MAP;
        {   /* warp map: dark wood top left (about 72, 47, 19) and left of the scroll, the scroll's orange at x 40 */
            int dark = d[0] > 50 && d[0] < 100 && d[1] > 30 && d[1] < 65 && d[2] < 35 && ws[1][0] < 100 && ws[1][2] < 35;
            int warp = page == SEL_PAGE_OTHER && dark && ws[0][0] > 200 && ws[0][1] > 140 && ws[0][1] < 210 && ws[0][2] < 100;
            int ok = warp && ok_dark >= 4;   /* dark letters of "A OK" (wood there otherwise: about 181) */
            if ((warp != g_sel_warp || ok != g_sel_warp_ok) && getenv("ALBW_SEL_TRACE"))
                fprintf(stderr, "selector: f=%ld warp map %d, OK offered %d\n", g_plat_frames, warp, ok);
            g_sel_warp = warp;
            g_sel_warp_ok = ok;
        }
        if (page != g_sel_page && getenv("ALBW_SEL_TRACE")) {
            extern long g_plat_frames;
            fprintf(stderr, "selector: f=%ld sees page %d (was %d)\n", g_plat_frames, page, g_sel_page);
        }
        if (page != g_sel_page && page == SEL_PAGE_OTHER) {
            g_sel_page = page;
        } else if (page != g_sel_page) {
            g_sel_page = page;
            g_sel_idx = sel_nearest(page, g_sel_x, g_sel_y);
            const SelTarget *t = &SEL_PAGES[page].t[g_sel_idx];
            g_sel_x = t->x;
            g_sel_y = t->y;
            g_sel_arrive = page == SEL_PAGE_ITEMS ? 20 : 0;
        }
    }
    if (g_sel_page == SEL_PAGE_OTHER) return;   /* the game's own menu: no selector */
    if (!g_sel_tex) {
        glGenTextures(1, &g_sel_tex);
        glBindTexture(GL_TEXTURE_2D, g_sel_tex);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, SELECTOR_W, SELECTOR_H, 0, GL_RGBA, GL_UNSIGNED_BYTE, SELECTOR_RGBA);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    }
    const SelTarget *t = &SEL_PAGES[g_sel_page].t[g_sel_idx < SEL_PAGES[g_sel_page].n ? g_sel_idx : 0];
    if (t->native) {
        /* the game's bracket marks the selected Items cell (only cells holding an item): its
         * bottom-right corner is light just outside the cell (x + 27, y + 19). Shown -> no
         * selector of ours; an empty cell -> ours */
        uint8_t c[4] = {0};
        glBindFramebuffer(0x8CA8 /* GL_READ_FRAMEBUFFER */, bt->fbo);
        glReadPixels((t->x + 27) * w / 320, h - 1 - (t->y + 19) * h / 240, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, c);
        glBindFramebuffer(0x8CA8 /* GL_READ_FRAMEBUFFER */, 0);
        if (c[0] > 210 && c[2] > 155) return;
    }
    static GLuint prog;
    if (!prog) prog = gl_program(SEL_VS, BLIT_FS);
    float pad = g_sel_touch ? 2.0f : 5.0f;   /* closes in a little while A is held */
    float x0 = t->x - t->w * 0.5f - pad, y0 = t->y - t->h * 0.5f - pad;
    float rw = t->w + 2 * pad, rh = t->h + 2 * pad;
    /* four corners of the graphic at a fixed size (not stretched with the target's shape) */
    float cs = 14.0f;
    if (cs > rw * 0.5f) cs = rw * 0.5f;
    if (cs > rh * 0.5f) cs = rh * 0.5f;
    float sr[4];
    layout_rect_ndc(l, SCREEN_BOTTOM, sr);   /* x, y (bottom left), w, h of the bottom screen */
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glUseProgram(prog);
    GLint lr = glGetUniformLocation(prog, "rect"), lu = glGetUniformLocation(prog, "uvr");
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, g_sel_tex);
    glBindVertexArray(blit_vao);
    for (int qy = 0; qy < 2; qy++)          /* 0 bottom, 1 top (window up) */
        for (int qx = 0; qx < 2; qx++) {
            float px = qx ? x0 + rw - cs : x0;                 /* 3DS pixels, y down */
            float py = qy ? y0 : y0 + rh - cs;
            const float r4[4] = {sr[0] + px / 320.0f * sr[2], sr[1] + (1.0f - (py + cs) / 240.0f) * sr[3],
                                 cs / 320.0f * sr[2], cs / 240.0f * sr[3]};
            /* image quadrant (texture rows top first): u from qx, v from bottom (1) or top (0.5) */
            const float uv[4] = {qx * 0.5f, qy ? 0.5f : 1.0f, 0.5f, -0.5f};
            glUniform4fv(lr, 1, r4);
            glUniform4fv(lu, 1, uv);
            glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
        }
    glDisable(GL_BLEND);
}
