/* Link's walking: how fast he moves this frame, and in which direction.
 *
 * Two functions of the game, rewritten by hand from the ARM code with named fields. The game calls them
 * by address, so the entry points at the bottom keep those names:
 *
 *     002D5ADC (EU 002D5AB8)   walk_update      one frame of walking: heading and velocity
 *     002900EC (EU 00290114)   walk_base_speed  the speed before momentum
 *
 * How a frame of walking works:
 *   1. The stick gives the heading Link should face. On the ground he turns towards it gradually; as a
 *      painting on a wall he takes it at once.
 *   2. The base speed depends on whether he is a painting, on a per-player scale, and on an actor he is
 *      linked to (one he pushes or carries, for example), which can slow him down.
 *   3. While the base speed is high enough, a little extra speed ("momentum") builds up to a cap.
 *   4. On the ground the distance is split along x and z by the heading. On a wall only left or right
 *      exists, chosen by the sign of the stick.
 *
 * Distances are world units per frame at a time step of 1. Angles are 32-bit: a full turn is 2^32, so
 * differences wrap by themselves.
 *
 * The layouts below hold only the fields this file uses; the offsets are those of the game and are
 * checked at compile time. Names describe how the fields are used here. Fields whose purpose is not
 * known beyond that say so. Checked against the previous version by tools/tests/link_walk_test.c.
 */
#include <stddef.h>
#include "gameplay.h"

/* ------------------------------------------------------------------ game data used here */
typedef uint32_t GamePtr;   /* a pointer stored in game data: always 4 bytes (gameplay.h, gp_ptr) */
typedef uint32_t Angle;     /* 2^32 = one full turn */

/* the stick, as the player code sees it */
typedef struct {
    uint8_t unused0[0x24];
    float tilt;              /* +0x24  how far it is pushed; 0 = centred */
    float x;                 /* +0x28  left (< 0) / right (> 0) */
    Angle angle;             /* +0x2C  direction pushed, relative to the screen */
} Stick;

/* what can change the way Link turns */
typedef struct {
    uint8_t unused0[0x328];
    uint32_t flags;          /* +0x328 */
    uint8_t unused1[0x33C - 0x32C];
    uint8_t mode;            /* +0x33C */
} TurnState;
#define TURN_SLOW_FLAG 0x2   /* with TURN_SLOW_MODE: turn slowly (which action this is, is not known) */
#define TURN_SLOW_MODE 9

/* the part of the player that holds the painting state */
typedef struct {
    uint8_t unused0[0x5B0];
    float body_blend;        /* +0x5B0  exactly 1.0 while Link is a normal, solid body */
} PlayerBody;

/* one walking controller */
typedef struct {
    uint8_t unused0[0x28];
    GamePtr body;            /* +0x28  PlayerBody */
    GamePtr player;          /* +0x2C  Player (for the base speed) */
    uint8_t unused1[0x38 - 0x30];
    GamePtr velocity;        /* +0x38  float x, y, z: where the result goes (y is left alone) */
    GamePtr heading;         /* +0x3C  Angle: the way Link faces */
    GamePtr faces_left;      /* +0x40  uint8_t, painting only: 1 = walking left */
    uint8_t unused2[0x48 - 0x44];
    GamePtr stick;           /* +0x48  Stick */
    uint8_t unused3[0x50 - 0x4C];
    GamePtr turn_state;      /* +0x50  TurnState */
    uint8_t unused4[0x5C - 0x54];
    Angle wanted_heading;    /* +0x5C  what the stick asked for this frame */
    float momentum;          /* +0x60  extra speed built up while moving fast */
} WalkController;

/* the player, as the speed calculation sees it */
typedef struct {
    uint8_t unused0[0x14];
    GamePtr tuning;          /* +0x14  object with the speed scale at +0x24 */
    uint8_t unused1[0x48 - 0x18];
    GamePtr link_slot;       /* +0x48  object whose +0x44 points at the linked actor's handle */
} Player;

_Static_assert(offsetof(Stick, angle) == 0x2C, "Stick layout");
_Static_assert(offsetof(TurnState, mode) == 0x33C, "TurnState layout");
_Static_assert(offsetof(PlayerBody, body_blend) == 0x5B0, "PlayerBody layout");
_Static_assert(offsetof(WalkController, turn_state) == 0x50, "WalkController layout");
_Static_assert(offsetof(WalkController, momentum) == 0x60, "WalkController layout");
_Static_assert(offsetof(Player, link_slot) == 0x48, "Player layout");

/* ------------------------------------------------------------------ tuning values
 * The base speeds are constants of the code; the rest are read from the game's data (the values in
 * comments are the European release's). */
#define SPEED_ON_GROUND  0.095f
#define SPEED_AS_PAINTING 0.0855f
extern float DAT_002d5c30;   /* turn share per frame, slow turning       (0.09)    */
extern float DAT_002d5c34;   /* turn share per frame, normal             (0.25)    */
extern int DAT_002d5c38;     /* momentum builds above this speed         (0.0931, compared as bits) */
extern float DAT_002d5c3c;   /* zero                                               */
extern float DAT_002d5c40;   /* momentum gained per frame                (0.0004)  */
extern int DAT_002d5c44;     /* momentum cap                             (0.0185, compared as bits) */
extern float DAT_002d5c48;   /* momentum cap, the value stored           (0.0185)  */

/* ------------------------------------------------------------------ game functions used */
int func_0054C998(int stick, int heading_now);                 /* heading the stick asks for */
int func_0051D2CC(int *angle, int target, float share);        /* angle += (target - angle) * share */
float func_00115154(float *sin_out, float *cos_out, uint32_t angle);
int func_0052FBA0(int actor_list, uint32_t handle);            /* actor of a handle, or 0 */
int func_00100174(uint32_t *guard);                            /* run-once guard */
extern uint32_t data_00706E20;                                 /* the actor manager */
extern uint32_t data_007260CC;                                 /* guard of the class id below */
extern uint32_t data_007260D0;                                 /* class id: actors that set a speed */
extern uint8_t data_006F6314[];
#define ACTOR_LIST_OFFSET 0x3DBBC

/* ------------------------------------------------------------------ base speed */

/* The linked actor of the player, if there is one and it is of the kind that sets Link's speed. */
static void *linked_speed_actor(const Player *player) {
    const char *slot = gp_ptr(player->link_slot);
    uint32_t handle = *(const uint32_t *)gp_ptr(FLD(slot, 0x44, GamePtr));
    if (handle == 0)
        return NULL;

    const char *manager = gp_ptr(data_00706E20);
    const char *actor_list = manager + ACTOR_LIST_OFFSET;   /* part of the manager, not a pointer in it */
    void *actor = gp_ptr((uint32_t)func_0052FBA0((int)gp_u32(actor_list), handle));

    /* the class id is set up on first use, as the game's own code does it */
    if ((data_007260CC & 1) == 0 && func_00100174(&data_007260CC) != 0)
        data_007260D0 = gp_u32(data_006F6314);

    if (actor == NULL)
        return NULL;
    /* virtual +0x00: "are you of this class?" */
    const char *vtable = gp_ptr(*(GamePtr *)actor);
    int (*is_kind)(void *, uint32_t *) = (int (*)(void *, uint32_t *))gp_ptr(FLD(vtable, 0x00, GamePtr));
    return is_kind(actor, &data_007260D0) ? actor : NULL;
}

/* World units per frame, before momentum. */
static float walk_base_speed(const Player *player, int as_painting) {
    const char *tuning = gp_ptr(player->tuning);
    float scale = FLD(tuning, 0x24, float);
    float speed = (as_painting ? SPEED_AS_PAINTING : SPEED_ON_GROUND) * scale;

    void *actor = linked_speed_actor(player);
    if (actor != NULL) {
        /* virtual +0x60: the actor's speed factor (for example 0.25; 00583E90) */
        const char *vtable = gp_ptr(*(GamePtr *)actor);
        float (*speed_factor)(void *) = (float (*)(void *))gp_ptr(FLD(vtable, 0x60, GamePtr));
        speed = speed_factor(actor) * speed;
    }
    return speed;
}

/* ------------------------------------------------------------------ one frame of walking */

/* Face the way the stick asks: gradually on the ground, at once as a painting.
 * Returns the heading asked for, which the velocity follows even while Link is still turning. */
static Angle walk_turn(WalkController *walk, int as_painting) {
    Angle *heading = gp_ptr(walk->heading);
    Angle wanted = (Angle)func_0054C998((int)walk->stick, (int)*heading);
    walk->wanted_heading = wanted;

    if (as_painting) {
        *heading = wanted;
    }
    else {
        const TurnState *turn = gp_ptr(walk->turn_state);
        int slow = (turn->flags & TURN_SLOW_FLAG) && turn->mode == TURN_SLOW_MODE;
        func_0051D2CC((int *)heading, (int)wanted, slow ? DAT_002d5c30 : DAT_002d5c34);
    }
    return wanted;
}

/* Build up (or drop) the extra speed. The comparisons are on the bit patterns, as in the ARM code;
 * for the positive values here that orders them like the numbers. */
static float walk_momentum(WalkController *walk, float base_speed) {
    if (gp_f2i_bits(base_speed) > DAT_002d5c38) {
        walk->momentum += DAT_002d5c40;
        if (gp_f2i_bits(walk->momentum) > DAT_002d5c44)
            walk->momentum = DAT_002d5c48;
    }
    else {
        walk->momentum = DAT_002d5c3c;
    }
    return walk->momentum;
}

/* On the ground: the distance along the heading, split into x and z. */
static void walk_on_ground(const WalkController *walk, Angle heading, float distance) {
    float along_x, along_z;
    func_00115154(&along_x, &along_z, heading);
    float *velocity = gp_ptr(walk->velocity);
    velocity[0] = distance * along_x;
    velocity[2] = distance * along_z;
}

/* As a painting: only along the wall. A centred stick leaves speed and facing as they were. */
static void walk_along_wall(const WalkController *walk, float distance) {
    if (!(distance > DAT_002d5c3c))
        return;
    const Stick *stick = gp_ptr(walk->stick);
    uint8_t *faces_left = gp_ptr(walk->faces_left);
    float *velocity = gp_ptr(walk->velocity);
    if (stick->x > 0.0f) {
        *faces_left = 0;
        velocity[0] = distance;
    }
    else if (stick->x < 0.0f) {
        *faces_left = 1;
        velocity[0] = -distance;
    }
}

/* One frame: turn, work out the speed, write the velocity. Returns the distance covered. */
static float walk_update(WalkController *walk, float time_step) {
    const PlayerBody *body = gp_ptr(walk->body);
    int as_painting = gp_f2u(body->body_blend) != gp_f2u(1.0f);

    Angle wanted = walk_turn(walk, as_painting);
    float base_speed = walk_base_speed(gp_ptr(walk->player), as_painting);
    float momentum = walk_momentum(walk, base_speed);
    float distance = (momentum + base_speed) * time_step;

    if (as_painting)
        walk_along_wall(walk, distance);
    else
        walk_on_ground(walk, wanted, distance);
    return distance;
}

/* ------------------------------------------------------------------ the entry points the game calls */

float func_002D5ADC(int walk_controller, float time_step) {
    return walk_update(gp_ptr((uint32_t)walk_controller), time_step);
}

/* also called by the player's item actions (0038C3F8) */
float func_002900EC(uint32_t player, int as_painting) {
    return walk_base_speed(gp_ptr(player), as_painting);
}
