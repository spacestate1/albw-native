/* Debug tools (#included by platform.c): warp to a room and spawn an enemy, used by the Esc > Debug
 * menu (menu.c) and by the ALBW_ROUTE steps `scene` / `spawn`. These are the port's own tools; the
 * retail game has no debug menu.
 *
 * Warp: the game's own scene change, as an exit zone (005416A0) makes it: 004EF418(scene manager
 * *data_00709DF8, &{u8 course, s32 scene @+4 (from 0), u16 point @+8}, transition, 0); the scene
 * manager applies it (004EECD4: loads <Course><room>.szs and its stage). Entry points: the stage's
 * System objects ID 7, ARG[0] (World/Byaml/<Course><room>_stage.byaml).
 *
 * Spawn: runtime/debug_spawn.c. An actor's model is only there where the area loads its pack
 * (BOOT_LOG 151); spawning elsewhere crashes in the actor's constructor, so the menu lists the
 * enemies of the current area (debug_enemies.h) and the spawn checks the resource slots again. */
#include "debug_enemies.h"

int albw_debug_ready(const char *name);

/* the order of the game's course name table (EU 0x120398); rooms = stage files on the ROM (from 1);
 * label NULL: not offered in the menu */
typedef struct { const char *name, *label; int rooms; } DbgCourse;
static const DbgCourse dbg_courses[] = {
    {"FieldLight", "Hyrule field", 45}, {"FieldDark", "Lorule field", 40},   /* 41-43: not in the scene table */
    {"IndoorLight", "Hyrule indoors", 21}, {"IndoorDark", "Lorule indoors", 16},
    {"CaveLight", "Hyrule caves", 30}, {"CaveDark", "Lorule caves", 15},
    {"Dummy7", NULL, 0}, {"CrossBattle", "StreetPass battle", 5}, {"Demo", NULL, 10},
    {"DungeonEast", "Eastern Palace", 3}, {"DungeonWind", "House of Gales", 3},
    {"DungeonHera", "Tower of Hera", 1}, {"DungeonCastle", "Hyrule Castle", 7},
    {"DungeonDark", "Dark Palace", 3}, {"DungeonWater", "Swamp Palace", 3},
    {"DungeonDokuro", "Skull Woods", 2}, {"DungeonHagure", "Thieves' Hideout", 1},
    {"DungeonIce", "Ice Ruins", 1}, {"DungeonSand", "Desert Palace", 3},
    {"DungeonKame", "Turtle Rock", 3}, {"DungeonGanon", "Lorule Castle", 1},
    {"DungeonBoss", "Final boss", 1}, {"AttractionLight", "Hyrule minigames", 5},
    {"AttractionDark", "Lorule minigames", 3}};
#define DBG_COURSES ((int)(sizeof dbg_courses / sizeof *dbg_courses))

/* the current course (0..) and room (from 1); 0 when there is no scene yet */
static int dbg_area(int *course, int *room) {
    extern char data_00709DF8[];
    uint32_t mgr = *(uint32_t *)data_00709DF8;
    if (!mgr) return 0;
    int c = *(int8_t *)(uintptr_t)(mgr + 0x18);
    if (c < 0 || c >= DBG_COURSES) return 0;
    *course = c;
    *room = *(int32_t *)(uintptr_t)(mgr + 0x1C) + 1;
    return 1;
}

/* Link is in the world: the title and file select keep him parked at (1000, 1000, 1000) */
static int dbg_in_game(void) {
    const float *p = albw_debug_player_pos();
    int c, r;
    return p && !(p[0] == 1000.0f && p[1] == 1000.0f && p[2] == 1000.0f) && dbg_area(&c, &r);
}

static int dbg_warp(int course, int room, int point, int transition) {
    extern char data_00709DF8[];
    int func_004EF418(int mgr, uint8_t *loc, int transition, int flag);
    uint32_t mgr = *(uint32_t *)data_00709DF8;
    if (!mgr) return 0;
    _Alignas(4) uint8_t loc[12] = {0};
    loc[0] = (uint8_t)course;
    int scene0 = room - 1;   /* the game counts scenes from 0: DungeonEast3 = scene 2 */
    memcpy(loc + 4, &scene0, 4);
    uint16_t pt = (uint16_t)point;
    memcpy(loc + 8, &pt, 2);
    return func_004EF418((int)mgr, loc, transition, 0);
}

/* enemy k of those whose pack the area loads (k < 0: none); returns the count in *n */
static const char *dbg_enemy_here(int k, int *n) {
    int c, r, count = 0;
    const char *found = NULL;
    if (dbg_area(&c, &r)) {
        char key[48];
        snprintf(key, sizeof key, " %s%d ", dbg_courses[c].name, r);
        for (int i = 0; i < (int)(sizeof dbg_enemies / sizeof *dbg_enemies); i++)
            if (strstr(dbg_enemies[i].areas, key) || strstr(dbg_enemies[i].areas, " ActorCommon ")) {
                if (count == k) found = dbg_enemies[i].name;
                count++;
            }
    }
    if (n) *n = count;
    return found;
}

/* requests from the menu, carried out between frames (plat_poll) */
static int g_dbg_warp_course = -1, g_dbg_warp_room;
static const char *g_dbg_spawn_name;
static long g_dbg_spawn_at;
static int g_dbg_spawn_course, g_dbg_spawn_room;

static void dbg_request_warp(int course, int room) {
    g_dbg_warp_course = course;
    g_dbg_warp_room = room;
    g_dbg_spawn_name = NULL;
}

/* ask for the enemy's resources; 1 = it follows in 45 frames, 0 = its data is not in this area */
static int dbg_request_spawn(const char *name) {
    if (!dbg_area(&g_dbg_spawn_course, &g_dbg_spawn_room)) return 0;
    albw_debug_preload(name);
    if (!albw_debug_ready(name)) return 0;
    g_dbg_spawn_name = name;
    g_dbg_spawn_at = g_plat_frames + 45;
    return 1;
}

static void dbg_tick(void) {
    if (g_dbg_warp_course >= 0) {
        int ok = dbg_in_game() && dbg_warp(g_dbg_warp_course, g_dbg_warp_room, 0, 0);
        fprintf(stderr, "debug: warp to %s%d: %s\n", dbg_courses[g_dbg_warp_course].name, g_dbg_warp_room,
                ok ? "requested" : "refused");
        g_dbg_warp_course = -1;
    }
    if (g_dbg_spawn_name && (g_plat_frames >= g_dbg_spawn_at || g_plat_frames < g_dbg_spawn_at - 45)) {
        int c, r;   /* not after a room change (or a save state load): the resources went with it */
        if (g_plat_frames >= g_dbg_spawn_at && g_plat_frames < g_dbg_spawn_at + 45 && dbg_in_game() &&
            dbg_area(&c, &r) && c == g_dbg_spawn_course && r == g_dbg_spawn_room)
            albw_debug_spawn(g_dbg_spawn_name, 0, 2);
        else
            fprintf(stderr, "debug: spawn %s dropped (the room changed)\n", g_dbg_spawn_name);
        g_dbg_spawn_name = NULL;
    }
}
