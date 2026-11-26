/* USA 004F70A8 <- EU 004F7080: EnemyBase::calcDamage() -> bool   (80 caller files: every
 * EnemyBase subclass's calc). hp = (s16)self[0x508], cfg = self[0x59C], st = self[0x5A0],
 * dmg = self[0x43C] (damage info: +0 attacker, +0x21 s8 type, +0x30 u16 amount),
 * ride = self[0x510], gate = *data_00709DF8 (event/cutscene state).
 *
 *   self[0x656] = self[0x657]; self[0x657] = 0; 004F6B28(self);
 *   if (cfg & 0x3000) {                                            (dying / dead)
 *       if ((!gate || (u32)((s8)gate[0x18] - 0x18) > 2) && self[0x4DC] != 0 && != 9)
 *            004F499C(self, 1 & ~(cfg >> 13)); else 004F499C(self, 0);
 *       return 0; }
 *   0034CA24(dmg); hp0_dead = hp <= 0; hit = 0;
 *   if (st & 0x180000) { st &= ~0x180000;
 *       if ((cfg & 0x80 || ride[4]) && self[0x3A0] && (k = (u8)self[0x3A0][0x2E]))
 *           { 004FBD44(self, dmg, k == 2, (old st >> 20) & 1); hit = 1; self[0x4B5] = 0; goto hp; } }
 *   self[0x4B5] = 0;
 *   if (!self[0x89C] && ((cfg & 0x80 && !ride[4] && self[0x664] >= self[0x668] (unsigned))
 *                        || 00542B24(ride))) {
 *       collision damage queries 0014E2A0(self, c, self[0x440], self[0x584], self[0x444], t),
 *       c = self[0x430] (t = self[0x3A0], self[0x4B4] = 0) and, for st & 8 first / else only
 *       when *dmg == 0, c = self[0x434] if nonzero (t = self[0x4AC] ?: self[0x3A0],
 *       self[0x4B4] = 1); self[0x4B0] = t before each call;   hit = 1; }
 *   hp: if (hp <= 0) { if (self[0x438]) { [0] = 0; [4] = -FLT_MAX; } st &= ~0x2000000; }
 *   if (hit && *dmg) {
 *       if (cfg & 0x20000000 && (t = (s8)dmg[0x21]) is 9 or 10 && self[0x3A0] && t < 0x13 (u)
 *           && (u8)*(u16 *)(self[0x3A0] + 0xE + (t < 0x12 ? 2t : 0)) == 2) dmg[0x30] += 4;
 *       if ((n = (u16)dmg[0x30])) { m = self->vt[0x54](self) (float damage multiplier);
 *           f = m * (float)n; d = vcvt.u32(f) & 0xFFFF; if (!d && f != 0 (NaN: !=)) d = 1;
 *           dmg[0x30] = d; hp = (s16)(hp - d); if (hp < -0x40) hp = -0x40; } }
 *   if (!(gate && gate[0x18] == 9 && gate[0x1C] == 2)) { st &= ~0x40;
 *       if (!00521100(self, &v) && !ride[4] &&
 *           bits(00581B58(*data_0070C8E0, (s16)self[0x54], v)) > bits(3.0f)) st |= 0x40; }
 *   if (!ride[4] && hp > 0) {
 *       if (self[0x5A4] & 0x40) { if (!(cfg & 0x3000)) { self[0x780] = 0xFF;
 *           004F8660(self, 0, 0, 0); cfg |= 0x2000; return 0; } }
 *       else if (00520EE4(self) && !self[0x7FC] && 00588BE4(self) != *data_006938FC
 *                && 00588BE4(self) != *data_00693900) { self[0x4DC] = 0;
 *           if (!(cfg & 0x3000)) { self[0x780] = 0xFF; 004F8660(self, 0, 0, 0);
 *               cfg |= 0x2000; hp = 0; return 0; } } }
 *   if (!hp0_dead) 004F8998(self, 1, 0);
 *   if ((002B2018(ride) || cfg & 0x4000 || st & 0x10000000) && cfg & 0x8000) self[0x657] = 1;
 *   return 1
 *
 * Ghidra vs ARM (round-2 conversion), real bugs:
 *  1. the damage multiplier returned in s0 by the virtual vt[0x54] is lost: Ghidra multiplies
 *     an undefined / stale `in_s0` (the -FLT_MAX constant when the hp <= 0 block ran) -> the
 *     damage applied to every enemy is garbage (0, 1 or 0xFFFF);
 *  2. the u16 amount -> float conversion takes its rounding mode from an undefined in_fpscr
 *     (harmless) and the f != 0 test compares against a constant re-read;
 *  3. the out-parameter of 00521100 (sp+0) is passed to 00581B58 as `in_stack_ffffffd8`, a
 *     separate never-written local in the conversion (not the frame slot 00521100 writes);
 *  4. type 9 skips the self[0x3A0] null check (`t == 9 || (t == 10 && p)` precedence):
 *     null dereference natively when the enemy has no model data.
 * Verified insn by insn, EU 004F7080-004F75F8. Confidence: high (flow), medium (names). */
#include "hot.h"
#pragma STDC FP_CONTRACT OFF

extern char data_00709DF8[], data_0070C8E0[], data_006938FC[], data_00693900[];

int func_004F6B28(int self);
int func_004F499C(int self, int x);
int func_0034CA24(uint32_t *dmg);
int func_004FBD44(uint32_t *self, uint32_t *dmg, int a, int b);
int func_00542B24(int ride);
uint32_t func_0014E2A0(char *self, uint32_t c, uint32_t a3, uint32_t a4, uint32_t a5, int t);
int func_005210AC(int self, int *out);
float func_00581B58(int mgr, int a, int b);
int func_00520EE4(int self);
int func_00588BE4(int self);
int func_004F8660(int *self, int a, int b, int c);
int func_004F8998(int *self, int a, char *b);
int func_002B2018(int *ride);

typedef float (*vmul_t)(void *self, void *hit);

#define HP(self) FLD(self, 0x508, int16_t)

static void dmg_query(char *self, uint32_t c, uint32_t t, uint8_t second)
{
    W(self, 0x4B0) = t;
    FLD(self, 0x4B4, uint8_t) = second;
    func_0014E2A0(self, c, W(self, 0x440), W(self, 0x584), W(self, 0x444), (int)t);
}

static void query_second(char *self)
{
    uint32_t t = W(self, 0x4AC);
    if (t == 0)
        t = W(self, 0x3A0);
    dmg_query(self, W(self, 0x434), t, 1);
}

int func_004F70A8(uint32_t self_w)
{
    char *self = P(self_w);
    int32_t v = 0;   /* sp+0: 00521100's out word */

    FLD(self, 0x656, uint8_t) = FLD(self, 0x657, uint8_t);
    FLD(self, 0x657, uint8_t) = 0;
    func_004F6B28((int)self_w);
    uint32_t cfg = W(self, 0x59C);
    if (cfg & 0x3000) {
        uint32_t g = W(data_00709DF8, 0);
        if ((g == 0 || (uint32_t)((int32_t)FLD(P(g), 0x18, int8_t) - 0x18) > 2) &&
            FLD(self, 0x4DC, uint8_t) != 0 && FLD(self, 0x4DC, uint8_t) != 9)
            func_004F499C((int)self_w, (int)(1u & ~(cfg >> 13)));
        else
            func_004F499C((int)self_w, 0);
        return 0;
    }
    func_0034CA24((uint32_t *)P(W(self, 0x43C)));
    int hp0_dead = HP(self) <= 0;
    int hit = 0;
    uint32_t st = W(self, 0x5A0);
    if (st & 0x180000) {
        uint32_t b = (st & 0x100000) >> 20;
        W(self, 0x5A0) = st & ~0x180000u;
        uint32_t m;
        uint32_t k;
        if (((W(self, 0x59C) & 0x80) || FLD(P(W(self, 0x510)), 4, uint8_t) != 0) &&
            (m = W(self, 0x3A0)) != 0 && (k = FLD(P(m), 0x2E, uint16_t) & 0xFF) != 0) {
            func_004FBD44((uint32_t *)self, (uint32_t *)P(W(self, 0x43C)), k == 2, (int)b);
            hit = 1;
            FLD(self, 0x4B5, uint8_t) = 0;
            goto hp;
        }
    }
    FLD(self, 0x4B5, uint8_t) = 0;
    if (FLD(self, 0x89C, uint8_t) == 0) {
        int go;
        if ((W(self, 0x59C) & 0x80) && FLD(P(W(self, 0x510)), 4, uint8_t) == 0 &&
            W(self, 0x664) >= W(self, 0x668))
            go = 1;
        else
            go = func_00542B24((int)W(self, 0x510)) != 0;
        if (go) {
            if (W(self, 0x5A0) & 8) {
                if (W(self, 0x434) != 0)
                    query_second(self);
                if (W(P(W(self, 0x43C)), 0) == 0)
                    dmg_query(self, W(self, 0x430), W(self, 0x3A0), 0);
            } else {
                dmg_query(self, W(self, 0x430), W(self, 0x3A0), 0);
                if (W(P(W(self, 0x43C)), 0) == 0 && W(self, 0x434) != 0)
                    query_second(self);
            }
            hit = 1;
        }
    }
hp:
    if (HP(self) <= 0) {
        uint32_t o = W(self, 0x438);
        if (o != 0) {
            W(P(o), 0) = 0;
            W(P(o), 4) = 0xFF7FFFFFu;   /* -FLT_MAX */
        }
        W(self, 0x5A0) &= ~0x2000000u;
    }
    if (hit && W(P(W(self, 0x43C)), 0) != 0) {
        char *d = P(W(self, 0x43C));
        if (W(self, 0x59C) & 0x20000000) {
            int32_t t = FLD(d, 0x21, int8_t);
            uint32_t m = W(self, 0x3A0);
            if ((t == 9 || t == 10) && m != 0 && (uint32_t)t < 0x13) {
                char *p = P(m) + 0xE;
                if ((uint32_t)t < 0x12)
                    p += (uint32_t)t * 2;
                if ((FLD(p, 0, uint16_t) & 0xFF) == 2)
                    FLD(d, 0x30, uint16_t) = (uint16_t)(FLD(d, 0x30, uint16_t) + 4);
            }
        }
        d = P(W(self, 0x43C));
        uint32_t n = FLD(d, 0x30, uint16_t);
        if (n != 0) {
            float mul = GFN(vmul_t, W(P(W(self, 0)), 0x54))(self, d);   /* r1 = the hit record (BOOT_LOG 179) */
            float f = mul * (float)n;
            uint32_t a = gp_vcvt_u32(f) & 0xFFFF;
            if (a == 0 && !VCMP_EQ(f, 0.0f))
                a = 1;
            FLD(P(W(self, 0x43C)), 0x30, uint16_t) = (uint16_t)a;
            int16_t h = (int16_t)(uint16_t)((uint32_t)FLD(self, 0x508, uint16_t) - a);
            HP(self) = h;
            if (h < -0x40)
                HP(self) = -0x40;
        }
    }
    {
        uint32_t g = W(data_00709DF8, 0);
        if (!(g != 0 && FLD(P(g), 0x18, uint8_t) == 9 && W(P(g), 0x1C) == 2)) {
            W(self, 0x5A0) &= ~0x40u;
            if (func_005210AC((int)self_w, &v) == 0 && FLD(P(W(self, 0x510)), 4, uint8_t) == 0) {
                float r = func_00581B58((int)W(data_0070C8E0, 0), FLD(self, 0x54, int16_t), v);
                if (gp_f2i_bits(r) > 0x40400000)
                    W(self, 0x5A0) |= 0x40;
            }
        }
    }
    if (FLD(P(W(self, 0x510)), 4, uint8_t) == 0 && HP(self) > 0) {
        if (W(self, 0x5A4) & 0x40) {
            if (!(W(self, 0x59C) & 0x3000)) {
                FLD(self, 0x780, uint8_t) = 0xFF;
                func_004F8660((int *)self, 0, 0, 0);
                W(self, 0x59C) |= 0x2000;
                return 0;
            }
        } else if (func_00520EE4((int)self_w) != 0 && FLD(self, 0x7FC, uint8_t) == 0 &&
                   func_00588BE4((int)self_w) != (int)W(data_006938FC, 0) &&
                   func_00588BE4((int)self_w) != (int)W(data_00693900, 0)) {
            FLD(self, 0x4DC, uint8_t) = 0;
            if (!(W(self, 0x59C) & 0x3000)) {
                FLD(self, 0x780, uint8_t) = 0xFF;
                func_004F8660((int *)self, 0, 0, 0);
                W(self, 0x59C) |= 0x2000;
                HP(self) = 0;
                return 0;
            }
        }
    }
    if (!hp0_dead)
        func_004F8998((int *)self, 1, 0);
    if ((func_002B2018((int *)P(W(self, 0x510))) != 0 || (W(self, 0x59C) & 0x4000) ||
         (W(self, 0x5A0) & 0x10000000)) &&
        (W(self, 0x59C) & 0x8000))
        FLD(self, 0x657, uint8_t) = 1;
    return 1;
}
