/* compilefix: USA 00590B1C (EU 00590AF4), Ghidra-derived (build/ghidra_analyzed4).
 * Failed to compile: use of undeclared identifier 'INFINITY'
 * Fixed (each an exact C form of the ARM operation; the rest is the converted Ghidra text):
 *  - Ghidra NAN(x)/INFINITY -> __builtin_isnan(x) (vcmp unordered) / +inf [1]
 *  - the three pc-relative table addresses (literal + pc, EU 590BE4..590C18) were raw 3DS addresses
 *    (crash reading 0x6C387C: Ice Gimos rooms, BOOT_LOG 172) -> the tables' data symbols
 *  - 2^k is built as a bit pattern (vcvt.u32 into the register vmul then reads as a float), and the
 *    quadrant index converts signed (vcvt.s32); checked against the host expf
 * Confidence: high for the fixes (each class checked against the EU disassembly on sample sites);
 * the function body otherwise has the fidelity of the Ghidra output (bare `return;` exits of
 * functions retyped non-void return 0, as the converter does). */
#include "ghidra_types.h"
#define CF_MATHCONST
#include "compilefix.h"

extern int func_00100986(undefined4 param_1);
extern int func_0058FBFC(uint param_1);
extern float func_005919B4(void);
extern uint DAT_00590cd8;
extern float DAT_00590cdc;
extern uint DAT_00590ce0;
extern float DAT_00590ce4;
extern float DAT_00590ce8;
extern float DAT_00590cec;
extern float DAT_00590cf0;
extern float DAT_00590cf4;
extern float DAT_00590cf8;
extern float DAT_00590cfc;
extern float DAT_00590d00;
extern float DAT_00590d04;
extern float DAT_00590d08;
extern float DAT_00590d0c;
extern int DAT_00590d10;
extern int DAT_00590d14;
extern int DAT_00590d18;
extern float DAT_00590d1c;
extern float DAT_00590d20;

// USA 00590B1C <- EU 00590AF4 (Ghidra, non-matching)
// GLOBAL DAT_00590cd8 uint
// GLOBAL DAT_00590cdc float
// GLOBAL DAT_00590ce0 uint
// GLOBAL DAT_00590ce4 float
// GLOBAL DAT_00590ce8 float
// GLOBAL DAT_00590cec float
// GLOBAL DAT_00590cf0 float
// GLOBAL DAT_00590cf4 float
// GLOBAL DAT_00590cf8 float
// GLOBAL DAT_00590cfc float
// GLOBAL DAT_00590d00 float
// GLOBAL DAT_00590d04 float
// GLOBAL DAT_00590d08 float
// GLOBAL DAT_00590d0c float
// GLOBAL DAT_00590d10 int
// GLOBAL DAT_00590d14 int
// GLOBAL DAT_00590d18 int
// GLOBAL DAT_00590d1c float
// GLOBAL DAT_00590d20 float

extern char data_006C385C[], data_006C386C[], data_006C387C[];

float func_00590B1C(float fparam_0)

{
  int iVar1;
  bool bVar2;
  uint uVar3;
  uint in_fpscr;
  float fVar4;
  uint uVar5;
  float fVar6;
  
  bVar2 = false;
  if (DAT_00590cd8 < (int)ALBW_AS_U32(fparam_0) * 2 + 0x99000000U) {
    if ((~(uint)ALBW_AS_U32(fparam_0) << 1) >> 0x18 == 0) {
      fVar4 = DAT_00590ce8;
      if (fparam_0 != -INFINITY) {
        fVar4 = fparam_0 + fparam_0;
      }
      return fVar4;
    }
    if ((uint)((int)ALBW_AS_U32(fparam_0) * 2) < 0x67000000) {
      return DAT_00590cdc;
    }
    if (DAT_00590ce0 < (uint)((int)ALBW_AS_U32(fparam_0) << 1)) {
      func_00100986(2);
      if (((uint)ALBW_AS_U32(fparam_0) & 0x80000000) != 0) {
        fVar4 = func_005919B4();
        return fVar4;
      }
      return DAT_00590ce4 * DAT_00590ce4;
    }
    bVar2 = true;
  }
  fVar4 = DAT_00590cf0;
  if (((uint)ALBW_AS_U32(fparam_0) & 0x80000000) == 0) {
    fVar4 = DAT_00590cf4;
  }
  uVar5 = (uint)(int)(fVar4 + fparam_0 * DAT_00590cec);   /* vcvt.s32: negative for x < 0 */
  uVar3 = uVar5 & 3;
  fVar4 = (float)VectorSignedToFloat(uVar5,(byte)(in_fpscr >> 0x15) & 3);
  fVar4 = (fparam_0 - fVar4 * DAT_00590cf8) - fVar4 * DAT_00590cfc;
  iVar1 = (int)uVar5 >> 2;
  fVar4 = *(float *)(data_006C386C + uVar3 * 4) +
          *(float *)(data_006C387C + uVar3 * 4) *
          (DAT_00590d0c + fVar4 * (DAT_00590d08 + fVar4 * (DAT_00590d04 + fVar4 * DAT_00590d00))) *
          fVar4 + *(float *)(data_006C385C + uVar3 * 4);
  if (!bVar2) {
    fVar6 = (float)VectorSignedToFloat(iVar1,(byte)(in_fpscr >> 0x15) & 3);
    fVar6 = ALBW_AS_F32(VectorFloatToUnsigned(DAT_00590d20 + fVar6 * DAT_00590d1c,3));   /* the bits of 2^k */
    return fVar6 * fVar4;
  }
  fVar4 = ALBW_AS_F32(((iVar1 - iVar1 / 2) * 0x800000 + 0x3f800000)) *
          ALBW_AS_F32(((iVar1 / 2) * 0x800000 + 0x3f800000)) * fVar4;
  if (fVar4 == 0.0) {
    func_00100986(2);
    fVar4 = func_005919B4();
    return fVar4;
  }
  if (fVar4 != INFINITY) {
    uVar3 = func_0058FBFC((uint)ALBW_AS_U32(fVar4));
    if (uVar3 == 4) {
      func_005919B4();
    }
    return fVar4;
  }
  func_00100986(2);
  return DAT_00590ce4 * DAT_00590ce4;
}

