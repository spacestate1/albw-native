/* compilefix: asm-verified rewrite taken from native/route/alt/func_001312BC.c (route scout), preferred over
 * the compile-fixed Ghidra text this folder had (see README.md). */
/* USA 001312BC (EU 001312BC): TaskRender per-frame scene/camera update (called by the
 * TaskRender calc 0014B610 every frame): updates the 2x3 render-view objects at this+0x28D0
 * (vt+0x10, and vt+0x14 with their partner unless this+0x2C1F bit 0), builds the two eye/view
 * matrices from the main camera (vt+0x18 / vt+0x20, 0011558C), offsets them along their z axis
 * by this+0x29F4 (the stereo/parallax distance) and sets up the two views (003FB1D0) at
 * this+0x28F0 and this+0x296C, then either (param_2 or this+0x2C1F bit 1) hands the camera to
 * 0016AAAC and returns, or: computes the camera speed from the look-at point (30 units ahead,
 * this+0x29E8 history) into the 3D-depth factor this+0x29F4, runs the frustum test 00232D34,
 * walks the model list (PtrArray at this+0x5C, erasing dead entries into the free list +0x68)
 * submitting every visible model (004CEF4C, shadow/occlusion registration 002330A4 / 002333F4
 * or 002331F0 / 00233450, 004D033C draw), collects the draw-list nodes (this+0x288C list) into
 * the array at this+0x1870 under the lock this+0x2BC8, builds the projection matrix of the
 * render manager (*data_0070BB18)+0x50 from the camera's fovy (data_0070B960+0x1C) and
 * near/far, then 0016AAAC, 00503F50, and tail-calls 002709CC.
 * Route: TaskRender calc, every frame from the first rendered frame on (title screen included).
 * Bug: the converted Ghidra source did not compile (float/pointer confusions in the stack
 * temporaries), so the link has a tripwire stub: the first TaskRender calc stops the boot.
 * Also restored: the r2 argument of 002330A4 / 002333F4 / 002331F0 / 00233450 (= model+0x13C,
 * the value just tested >= 0; live-in of all four callees).  004D033C reads s2 which the ARM
 * leaves as dead scratch here (passed 0).
 * Verified instruction by instruction against EU 001312BC..00132194: the stack frame is kept at
 * the ARM sp offsets (matrices sp+8/sp+0x98 resp. sp+0x10/sp+0x40, 00115D70 results at
 * sp+0x54 / sp+0x94), the signed bit compare `cmp r2, #0x3F000000; movgt r0, #0` of the speed,
 * `bls` / `vmovge; bge` NaN behaviour of the speed curve (13 * (v - 0.12) / 0.38 + 2, clamps 2
 * and 15), the four list-walk variants (frustum flag x r8; the two "not visible" variants call
 * 004CEF4C and ignore its result), `ldrhi` unsigned element reads, the one-shot free-list push
 * before PtrArray::erase 0048C320(arr, i, 1) without i++, signed `bge` capacity test of the
 * collected nodes, vdiv order of the projection (tan = s/c; 1/tan; /1.6667).
 * Confidence: high (flow), medium (role names). */
#pragma STDC FP_CONTRACT OFF
#include "../route/route.h"
float albw_ws_factor(void);   /* render.c: widescreen factor (1 = off) */
float albw_view_zoom(void);   /* platform.c: zoom out (1 = off) */
#include <stdio.h>
#include <stdlib.h>

extern uint32_t data_00712468[], data_0070BB18[], data_007A9248[], data_0070B928[],
    data_0070B960[], data_0070B9E8[], data_0070BB80[];
int *func_0057D5C4(int *p);
void func_0011558C(float *out, float *in);
void func_003FB1D0(float *p1, int p2, int p3, float *p4, float *p5, float f0, float f1);
int func_00115D70(float *out, float *v, float s);
int func_00115CA8(float *out, float *m, float *v);
uint64_t func_00232D34(int p1, uint32_t *p2, int p3);
int func_0010C0B8(int p);
int func_0010EEE0(int p);
int func_0048C320(int *arr, int idx, int n);
uint8_t func_004CEF4C(int *p, int a);
int func_002330A4(int a, int b, uint32_t c);
int func_002333F4(int a, int b, uint32_t c);
int func_002331F0(int a, int b, uint32_t c);
void func_00233450(int a, int b, uint32_t c);
int func_004D033C(int p1, float *p2, float *p3, int p4, float f0, float f1, float f2);
void func_00233828(int p);
int func_003E183C(float *out_s, float *out_c, float a);
void func_0016AAAC(int p1, uint32_t p2, uint32_t p3);
int func_00503F50(int p);
int func_002709CC(int p);

#define F32(off) RF(sp, off, float)
#define U32(off) RF(sp, off, uint32_t)

typedef int (*vfn_i)(char *, int);
typedef void (*vfn_v)(char *);
typedef void (*vfn_vw)(char *, uint32_t);

static void update_views(char *sb)
{
    char *sl = sb + 0x28D0;
    for (int r6 = 0; r6 < 2; r6++) {
        uint32_t *e = (uint32_t *)(sl + r6 * 12);
        char *o = GPTR_TO(char, e[0]);
        RVFN(vfn_v, o, 0x10)(o);
        if ((RF(sb, 0x2C1F, uint8_t) & 1) == 0) {
            o = GPTR_TO(char, e[0]);
            RVFN(vfn_vw, o, 0x14)(o, e[1]);
        }
        o = GPTR_TO(char, e[1]);
        RVFN(vfn_v, o, 0x10)(o);
        o = GPTR_TO(char, e[2]);
        RVFN(vfn_v, o, 0x10)(o);
    }
}

static char *cam_get(char *cam, int which)          /* vt+0x18 */
{
    return GPTR_TO(char, RVFN(vfn_i, cam, 0x18)(cam, which));
}

static int cam_view(char *cam, int which)           /* 0057D5C4(vt+0x20(i)) */
{
    return (int)GPTR_OF(func_0057D5C4(GPTR_TO(int, RVFN(vfn_i, cam, 0x20)(cam, which))));
}

/* translation column += z column * k  (matrix at sp+m) */
static void push_along_z(char *sp, int m, int tmp_in, int tmp_out, float k)
{
    U32(tmp_in) = U32(m + 8);
    U32(tmp_in + 4) = U32(m + 0x18);
    U32(tmp_in + 8) = U32(m + 0x28);
    func_00115D70((float *)(sp + tmp_out), (float *)(sp + tmp_in), k);
    F32(m + 0xC) = F32(m + 0xC) + F32(tmp_out);
    F32(m + 0x1C) = F32(m + 0x1C) + F32(tmp_out + 4);
    F32(m + 0x2C) = F32(m + 0x2C) + F32(tmp_out + 8);
}

static void model_erase(char *sb, int32_t i)
{
    char *arr = sb + 0x5C;
    int32_t ip = i + 1;
    if (RF(arr, 0, int32_t) >= ip) {
        int32_t j = i;
        do {
            uint32_t node = GPTR_TO(uint32_t, RF(arr, 8, uint32_t))[j];
            j++;
            RF(GPTR_TO(char, node), 0, uint32_t) = RF(arr, 0xC, uint32_t); /* vldr/vstr: bit copy */
            RF(arr, 0xC, uint32_t) = node;
        } while (ip > j);
    }
    func_0048C320((int *)arr, i, 1);
}

static void collect_nodes(char *sb)
{
    char *r6 = sb + 0x1870;
    char *head = sb + 0x288C;
    char *n = RP(sb, 0x2890);
    while (n != head) {
        int32_t cnt = RF(r6, 0, int32_t), cap = RF(r6, 4, int32_t);
        uint32_t v = RF(n, 8, uint32_t);
        if (cnt < cap) {
            GPTR_TO(uint32_t, RF(r6, 8, uint32_t))[cnt] = v;
            RF(r6, 0, int32_t) = RF(r6, 0, int32_t) + 1;
        }
        n = RP(n, 4);
    }
}

/* the model submission loop; visible: frustum flag of 00232D34; shadow: r8 */
static void submit_models(char *sb, int visible, int shadow, float *mtx, float *pos, int mgr)
{
    int32_t r5 = 0;
    static int vt = -1; int n_tot = 0, n_ok = 0;
    if (vt < 0) vt = getenv("ALBW_VIS_TRACE") != NULL;
    if (RF(sb, 0x5C, int32_t) <= 0)
        return;
    do {
        char *e = (uint32_t)RF(sb, 0x5C, int32_t) > (uint32_t)r5
                      ? GPTR_TO(char, GPTR_TO(uint32_t, RF(sb, 0x64, uint32_t))[r5])
                      : 0;
        uint8_t dead = RF(e, 4, uint8_t);
        char *m = RP(e, 0);
        if (dead) {
            if (m)
                RF(m, 0x4C, uint32_t) = 0;
            model_erase(sb, r5);
        } else if (!m) {
            model_erase(sb, r5);
        } else {
            uint8_t ok = func_004CEF4C((int *)m, (int)RF(sb, 0x28CC, uint32_t));
            n_tot++; n_ok += ok != 0;
            if (visible && ok && RF(m, 0x13C, int32_t) >= 0 && (RF(m, 0x164, uint32_t) & 0x1000) == 0) {
                uint32_t fl = RF(m, 0x164, uint32_t), a = RF(m, 0x13C, uint32_t);
                if (fl & 0x2000000) {
                    if (shadow) func_002330A4(mgr, (int)GPTR_OF(m), a);
                    else func_002331F0(mgr, (int)GPTR_OF(m), a);
                } else if (fl & 0x4000000) {
                    if (shadow) func_002333F4(mgr, (int)GPTR_OF(m), a);
                    else func_00233450(mgr, (int)GPTR_OF(m), a);
                }
            }
            func_004D033C((int)GPTR_OF(m), mtx, pos, RF(sb, 0x2C1D, uint8_t) == 0 ? 1 : 0, 0.0f, 0.0f, 0.0f);
            r5++;
        }
    } while (RF(sb, 0x5C, int32_t) > r5);
    if (vt) { extern long g_plat_frames __attribute__((weak));
              fprintf(stderr, "vis: f=%ld visible=%d models %d ok %d\n", &g_plat_frames ? g_plat_frames : 0L, visible, n_tot, n_ok); }
}

int func_001312BC(char *sb, int param_2)
{
    _Alignas(8) char sp[0xD8];
    memset(sp, 0, sizeof sp);
    char *sl = sb + 0x28D0;
    char *fpp = sb + 0x2C00;
    float *view0 = (float *)(sb + 0x28F0), *view1 = (float *)(sb + 0x296C);
    float *depth = (float *)(sb + 0x2800 + 0x1F4);
    RF(sb, 0x2C1D, uint8_t) = RF(GPTR_TO(char, data_00712468[0]), 0x22, uint8_t);

    if (param_2 != 0 || (RF(sb, 0x2C1F, uint8_t) & 2) != 0) {
        update_views(sb);
        char *cam = RP(sl, 0);
        int v1 = cam_view(cam, 1), v0 = cam_view(cam, 0);
        func_0011558C((float *)(sp + 0x98), (float *)(cam_get(cam, 1) + 4));
        func_0011558C((float *)(sp + 8), (float *)(cam_get(cam, 0) + 4));
        RF(sb, 0x2969, uint8_t) = 4;
        func_003FB1D0(view0, v1, v0, (float *)(sp + 0x98), (float *)(sp + 8),
                      RF(fpp, 0x10, float), RF(fpp, 0x14, float));
        push_along_z(sp, 0x98, 0x48, 0x54, *depth);
        push_along_z(sp, 8, 0x48, 0x54, *depth);
        RF(sb, 0x29E5, uint8_t) = 4;
        func_003FB1D0(view1, v1, v0, (float *)(sp + 0x98), (float *)(sp + 8),
                      RF(fpp, 0x10, float), RF(fpp, 0x14, float));
        char *g0 = cam_get(RP(sl, 0), 0);
        char *g1 = cam_get(RP(sl, 0), 1);
        func_0016AAAC((int)data_0070BB18[0], GPTR_OF(g1 + 4), GPTR_OF(g0 + 4));
        return 0;
    }

    int moving = RF(fpp, 0x1B, uint8_t) != 0;
    update_views(sb);
    char *cam = RP(sl, 0);
    func_00115D70((float *)(sp + 0x30), (float *)data_007A9248, 30.0f);
    memcpy(sp + 0xC, sp + 0x30, 12);
    func_00115CA8((float *)(sp + 0x24), (float *)(cam + 0x120), (float *)(sp + 0xC));
    float *hist = (float *)(sb + 0x29E8);
    float s2 = F32(0x24);
    float dx = s2 - hist[0], dz = F32(0x2C) - hist[2], dy = F32(0x28) - hist[1];
    float d = dx * dx;
    d = d + dy * dy;
    d = d + dz * dz;
    float v = __builtin_sqrtf(d);
    int32_t vb;
    memcpy(&vb, &v, 4);
    int slow = 1;
    if (vb > 0x3F000000) {
        slow = 0;
    } else {
        float k = 2.0f;
        if (!(v <= 0.12f)) {          /* bls: taken for <= (not for NaN) */
            if (v >= 0.5f) {           /* vmovge; bge */
                k = 15.0f;
            } else {
                float t = 13.0f * (v - 0.12f);
                k = t / 0.38f + 2.0f;
            }
        }
        *depth = k;
    }
    hist[0] = s2;
    RF(hist, 4, uint32_t) = U32(0x28);
    RF(hist, 8, uint32_t) = U32(0x2C);
    int r8 = slow & moving;

    cam = RP(sl, 0);
    U32(0xC) = (uint32_t)cam_view(cam, 1);
    U32(0x7C) = (uint32_t)cam_view(cam, 0);
    func_0011558C((float *)(sp + 0x10), (float *)(cam_get(cam, 1) + 4));
    func_0011558C((float *)(sp + 0x40), (float *)(cam_get(cam, 0) + 4));
    RF(sb, 0x2969, uint8_t) = 4;
    func_003FB1D0(view0, (int)U32(0xC), (int)U32(0x7C), (float *)(sp + 0x10), (float *)(sp + 0x40),
                  RF(fpp, 0x10, float), RF(fpp, 0x14, float));
    push_along_z(sp, 0x10, 0x88, 0x94, *depth);
    push_along_z(sp, 0x40, 0x88, 0x94, *depth);
    RF(sb, 0x29E5, uint8_t) = 4;
    func_003FB1D0(view1, (int)U32(0xC), (int)U32(0x7C), (float *)(sp + 0x10), (float *)(sp + 0x40),
                  RF(fpp, 0x10, float), RF(fpp, 0x14, float));
    if (RF(fpp, 0x1A, uint8_t) == 0)
        RF(sb, 0x29E5, uint8_t) = 0;
    int visible = (uint32_t)func_00232D34((int)data_0070B928[0], (uint32_t *)view1, r8) != 0;
    RF(RP(sb, 0x28EC), 0x8C, uint8_t) = (uint8_t)r8;
    cam = RP(sl, 0);
    RF(sb, 0x28CC, int32_t) = RF(sb, 0x28CC, int32_t) + 1;
    float *mtx = (float *)(((RF(cam, 0x2C8, uint32_t) & 1) ? cam + 0x190 : cam + 0x10) + 4);
    float *pos = (float *)(cam + 0x120);
    int lock = (int)GPTR_OF(sb + 0x2BC8);
    RF(sb, 0x1870, uint32_t) = 0;
    int mgr = (int)data_0070B928[0];
    func_0010C0B8(lock);
    submit_models(sb, visible, r8, mtx, pos, mgr);
    collect_nodes(sb);
    func_0010EEE0(lock);

    if (visible & r8)
        func_00233828((int)data_0070B928[0]);
    RF(sb, 0x2C1B, uint8_t) = 1;
    char *pm = RP(GPTR_TO(char, data_0070BB18[0]), 0x50);
    RF(pm, 0x64, uint32_t) = RF(fpp, 0x10, uint32_t);
    RF(pm, 0x68, uint32_t) = RF(fpp, 0x14, uint32_t);
    RF(pm, 0, uint8_t) |= 1;
    RF(pm, 1, uint8_t) = 0;
    cam = RP(sl, 0);
    char *cm = (RF(cam, 0x2C8, uint32_t) & 1) ? cam + 0x190 : cam + 0x10;
    memcpy(pm + 0x34, cm + 4, 0x30);
    const char *g = (const char *)data_0070B960;
    float s19 = RF(g, 0x30, float), s20 = RF(g, 0x34, float);
    float s21 = RF(g, 0x38, float), s22 = RF(g, 0x3C, float);
    float a = RF(g, 0x1C, float) * 0.5f;
    a = a * 0x1.45f306p+5f; /* 0x4222F983 (128/pi) */
    func_003E183C((float *)(sp + 8), (float *)(sp + 0xC), a);
    float t = F32(8) / F32(0xC);
    float c = 1.0f / t;
    c = c / albw_view_zoom();   /* zoom out: the same wider view as the drawn one (view_projection.c) */
    float w = c / (1.66666663f * albw_ws_factor()); /* 0x3FD55555; widescreen: the wider top screen */
    float h = c * s20;
    w = w * s19;
    float *P = (float *)(pm + 4);
    P[0] = w; P[1] = 0.0f; P[2] = -s21; P[3] = 0.0f;
    P[4] = 0.0f; P[5] = h; P[6] = -s22; P[7] = 0.0f;
    P[8] = 0.0f; P[9] = 0.0f; P[10] = -1.0f; P[11] = 0.0f;
    char *g0 = cam_get(RP(sl, 0), 0);
    char *g1 = cam_get(RP(sl, 0), 1);
    func_0016AAAC((int)data_0070BB18[0], GPTR_OF(g1 + 4), GPTR_OF(g0 + 4));
    func_00503F50((int)data_0070B9E8[0]);
    return func_002709CC((int)data_0070BB80[0]);
}
