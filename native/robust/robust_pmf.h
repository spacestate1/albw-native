/* Shared bodies of the class-B "pointer-to-member" templates T2, T3 and T4 (template ids and
 * member lists: tools/b_templates.json; T1 = state-machine changeState is in robust_sm.h).
 *
 * Template identification (normalisation rule used by tools/b_templates.json): take the Ghidra
 * body of build/ghidra_analyzed2/func_<USA>.c from the first "\n{", drop C block comments,
 * replace every identifier matching \b(DAT|PTR|FUN|func|LAB|s)_\w+ by X and every 0x[0-9a-f]+
 * by N, collapse whitespace. Functions with an identical normalised body form one template.
 * T2 and T3 are then split by the EU disassembly (addresses/pool offsets masked) into register-
 * allocation variants, ids T2_argsN / T3_argsN: armcc only keeps r1..rN untouched up to the tail
 * `bx` when they are the delegate's arguments, so N = number of leading argument registers
 * (r1, r2, r3) never written in the template = the delegate's arity (T2: 209 x 1, 7 x 2, 1 x 0;
 * T3: 38 x 0, 22 x 1, 24 x 2). Within each variant the disassembly is identical. All 303 T1 and
 * all 51 T4 instances have one disassembly shape; T4 instances all use the same offsets
 * (+0x960 state machine, +0x988 flag) and the same callee 003931EC.
 *
 * Delegate layout (sead::Delegate-style, 32-bit game layout): +0 vtable, +4 object,
 * +8 albw_pmf { ptr, adj }. */
#ifndef ALBW_ROBUST_PMF_H
#define ALBW_ROBUST_PMF_H
#include "robust.h"

/* T2_argsN: R Delegate::invoke(a1..aN) const, tail call through the PMF.
 *   if (!obj || !pmf valid) return 0; return fn(obj + (adj>>1), a1..aN);
 * At the tail `bx` r0 = adjusted object, r1..rN are the caller's (never written by the
 * template), the remaining argument registers and ip are scratch (target, object/vtable, adj).
 * The target's r0 is returned as is (tail call). Arguments are forwarded as opaque words. */
typedef uint32_t (*albw_dlg_r0)(char *self);
typedef uint32_t (*albw_dlg_r1)(char *self, uintptr_t a1);
typedef uint32_t (*albw_dlg_r2)(char *self, uintptr_t a1, uintptr_t a2);
/* T3_argsN: the same for void delegates (no return value). */
typedef void (*albw_dlg_v0)(char *self);
typedef void (*albw_dlg_v1)(char *self, uintptr_t a1);
typedef void (*albw_dlg_v2)(char *self, uintptr_t a1, uintptr_t a2);

/* Port guard (BOOT_LOG 160e): a delegate whose target is not code (overwritten with floats such as
 * 1.0f / 1.3f by a sound-object use-after-free, OPEN) would jump into data. A valid game never has a
 * non-code target here, so the check only fires on corruption: the call is skipped and logged
 * (first 8 times). Code = this executable's text (the game and the port are one binary). */
void albw_delegate_bad(const char *dlg, const void *fn);   /* native/runtime/debug_spawn.c */
extern uintptr_t albw_code_lo, albw_code_hi;                /* the executable's PF_X segment (runtime/crash.c) */
void albw_code_range_init(void);
static inline int albw_code_ptr(const void *p) {
    if (!albw_code_hi) albw_code_range_init();
    return (uintptr_t)p >= albw_code_lo && (uintptr_t)p < albw_code_hi;
}
/* the adjusted object and target of a delegate, or NULL when invoke() does nothing */
void albw_x87_guard(const char *where, void *ra);
void albw_x87_clear(void);
/* a delegate is called through an int / void pointer type: a float its target returns stays in
 * x87 st(0) and must be dropped (native/runtime/x87guard.c, BOOT_LOG 160h) */
static inline __attribute__((always_inline)) void albw_x87_settle(void) {
#if defined(__i386__)
    uint16_t sw;
    __asm__ volatile("fnstsw %0" : "=am"(sw));
    if (sw & 0x3800) albw_x87_clear();
#endif
}
static inline __attribute__((always_inline)) void *albw_delegate_target(char *dlg, char **self_out) {
    albw_x87_guard("delegate call", __builtin_return_address(0));
    char *obj = FLD(dlg, 0x04, char * ALBW_GP);
    if (obj == 0)
        return 0;
    const albw_pmf *m = (const albw_pmf *)AT(dlg, 0x08);
    if (!albw_pmf_valid(m))
        return 0;
    *self_out = albw_pmf_this(m, obj);
    void *fn = albw_pmf_fn(m, *self_out);
    if (!albw_code_ptr(fn)) {
        albw_delegate_bad(dlg, fn);
        return 0;
    }
    return fn;
}
static inline uint32_t albw_delegate_invoke_r0(char *dlg) {
    char *self; void *fn = albw_delegate_target(dlg, &self);
    uint32_t r = fn ? ((albw_dlg_r0)fn)(self) : 0;
    albw_x87_settle();
    return r;
}
static inline uint32_t albw_delegate_invoke_r1(char *dlg, uintptr_t a1) {
    char *self; void *fn = albw_delegate_target(dlg, &self);
    uint32_t r = fn ? ((albw_dlg_r1)fn)(self, a1) : 0;
    albw_x87_settle();
    return r;
}
static inline uint32_t albw_delegate_invoke_r2(char *dlg, uintptr_t a1, uintptr_t a2) {
    char *self; void *fn = albw_delegate_target(dlg, &self);
    uint32_t r = fn ? ((albw_dlg_r2)fn)(self, a1, a2) : 0;
    albw_x87_settle();
    return r;
}
static inline void albw_delegate_invoke_v0(char *dlg) {
    char *self; void *fn = albw_delegate_target(dlg, &self);
    if (fn) ((albw_dlg_v0)fn)(self);
    albw_x87_settle();
}
static inline void albw_delegate_invoke_v1(char *dlg, uintptr_t a1) {
    char *self; void *fn = albw_delegate_target(dlg, &self);
    if (fn) ((albw_dlg_v1)fn)(self, a1);
    albw_x87_settle();
}
static inline void albw_delegate_invoke_v2(char *dlg, uintptr_t a1, uintptr_t a2) {
    char *self; void *fn = albw_delegate_target(dlg, &self);
    if (fn) ((albw_dlg_v2)fn)(self, a1, a2);
    albw_x87_settle();
}

/* T4: owner->changeStateIfDifferent(newState, flag) for a state machine embedded at owner+0x960
 * (same layout as T1: +0x04 s8 current, +0x14 owner, +0x18 enter albw_pmf[], +0x20 exit
 * albw_pmf[]):
 *   if ((s8)sm->cur == newState) return;   (compared with the full r1 register)
 *   owner->u8[0x988] = flag;
 *   if (cur != -1 && exit[cur] valid) exit[cur](self, newState);
 *   003931EC(sm, (s8)newState);             (set state, reset counter, play state animation)
 *   if (enter[cur] valid) enter[cur](self); (tail call, only r0 live) */
void func_003931EC(void *sm, int32_t newState);
typedef void (*albw_sm_exit_fn)(char *self, int32_t newState);
typedef void (*albw_sm_enter_fn)(char *self);
static inline void albw_owner_sm_change_state_if_different(char *owner, int32_t newState, uint8_t flag) {
    char *sm = owner + 0x960;
    if (FLD(sm, 0x04, int8_t) == newState)
        return;
    FLD(owner, 0x988, uint8_t) = flag;
    int8_t cur = FLD(sm, 0x04, int8_t);
    if (cur != -1) {
        const albw_pmf *m = FLD(sm, 0x20, albw_pmf * ALBW_GP) + cur;
        if (albw_pmf_valid(m)) {
            char *self = albw_pmf_this(m, FLD(sm, 0x14, char * ALBW_GP));
            ((albw_sm_exit_fn)albw_pmf_fn(m, self))(self, newState);
        }
    }
    func_003931EC(sm, (int8_t)newState);
    const albw_pmf *m = FLD(owner, 0x978, albw_pmf * ALBW_GP) + FLD(sm, 0x04, int8_t);
    if (albw_pmf_valid(m)) {
        char *self = albw_pmf_this(m, FLD(sm, 0x14, char * ALBW_GP));
        ((albw_sm_enter_fn)albw_pmf_fn(m, self))(self);
    }
}

#endif
