/* compilefix: USA 0067D700 (EU 0067D6D8), Ghidra-derived (build/ghidra_analyzed4).
 * Failed to compile: use of undeclared identifier 'NAN'
 * Fixed (each an exact C form of the ARM operation; the rest is the converted Ghidra text):
 *  - (T *)<float expr> -> (T *)CF_FBITS(expr): 32-bit copy of the float (vmov/vstr), never a conversion [1]
 *  - Ghidra NAN(x)/INFINITY -> __builtin_isnan(x) (vcmp unordered) / +inf [1]
 *  - Ghidra -NAN/NAN constant -> the exact words 0xFFFFFFFF/0x7FFFFFFF (mvn in the ARM) [1]
 *  - implicit float<->int conversions (Ghidra COPY between a float and an int-typed variable or
 *    pool word, e.g. `fVar = _DAT_xxx;`, `puVar[3] = fVar;`) made bit copies [1]
 * Confidence: high for the fixes (each class checked against the EU disassembly on sample sites, this function's sites checked);
 * the function body otherwise has the fidelity of the Ghidra output (bare `return;` exits of
 * functions retyped non-void return 0, as the converter does). */
#include "ghidra_types.h"
#define CF_MATHCONST
#include "compilefix.h"

extern float func_00590D4C(float fparam_0);
extern float DAT_0067da3c;
extern float DAT_0067da40;
extern float DAT_0067da44;
extern float DAT_0067da48;
extern float DAT_0067da4c;
extern float DAT_0067da50;
extern float DAT_0067da54;
extern float DAT_0067da58;
extern float DAT_0067da5c;
extern float DAT_0067da60;
extern float DAT_0067dcb4;

// USA 0067D700 <- EU 0067D6D8 (Ghidra, non-matching)
// GLOBAL DAT_0067da3c float
// GLOBAL DAT_0067da40 float
// GLOBAL DAT_0067da44 float
// GLOBAL DAT_0067da48 float
// GLOBAL DAT_0067da4c float
// GLOBAL DAT_0067da50 float
// GLOBAL DAT_0067da54 float
// GLOBAL DAT_0067da58 float
// GLOBAL DAT_0067da5c float
// GLOBAL DAT_0067da60 float
// GLOBAL DAT_0067dcb4 float

void func_0067D700(float *param_1,float *param_2,float fparam_0)

{
  uint uVar1;
  char cVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  byte bVar7;
  bool bVar8;
  float fVar9;
  ushort *puVar10;
  ushort *puVar11;
  float fVar12;
  bool bVar13;
  bool bVar14;
  uint in_fpscr;
  uint uVar15;
  float fVar16;
  float fVar17;
  int iVar18;
  uint uVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  
  fVar26 = DAT_0067da44;
  fVar16 = DAT_0067da3c;
  bVar8 = false;
  fVar12 = param_1[8];
  uVar1 = in_fpscr & 0xfffffff;
  uVar15 = uVar1 | (uint)(fparam_0 == DAT_0067da3c) << 0x1e |
           (uint)(DAT_0067da3c <= fparam_0) << 0x1d;
  puVar11 = (ushort *)((uint)*(ushort *)((int)param_1 + 0xe) * 6 + -6 + (int)ALBW_AS_U32(fVar12));
  uVar19 = (uint)(int)((fparam_0 / param_1[6]) * DAT_0067da40);   /* vcvt.s32: may be negative */
  bVar7 = (byte)(uVar15 >> 0x18);
  bVar13 = (bool)(bVar7 >> 6);
  bVar14 = false;
  if ((bool)(bVar7 >> 5 & 1)) {
    bVar14 = uVar19 <= *puVar11;
    bVar13 = *puVar11 == uVar19;
  }
  if (bVar14 && !bVar13) {
    param_2[1] = 0.0;
    fVar12 = fVar16;
  }
  else {
    uVar15 = uVar1 | (uint)(DAT_0067da3c <= fparam_0) << 0x1d;
    if (SUB41(uVar15 >> 0x1d,0)) {
      cVar2 = *(char *)((int)param_1 + 9);
    }
    else {
      cVar2 = *(char *)(param_1 + 2);
    }
    if (cVar2 == '\0') {
      uVar1 = uVar1 | (uint)(DAT_0067da3c <= fparam_0) << 0x1d;
      if (!SUB41(uVar1 >> 0x1d,0)) {
        uVar3 = *(ushort *)((int)ALBW_AS_U32(fVar12) + 2);
        fVar24 = param_1[4];
        fVar22 = param_1[5];
        param_2[1] = CF_NAN_NEG;
        *param_2 = fVar12;
        fVar26 = DAT_0067da48;
        fVar12 = (float)VectorUnsignedToFloat((uint)uVar3,(byte)(uVar1 >> 0x15) & 3);
        fVar25 = *param_1;
        param_2[4] = fVar22 + fVar12 * fVar24;
        param_2[5] = fVar16;
        param_2[6] = fVar16;
        param_2[7] = fVar16;
        param_2[2] = fVar26;
        param_2[3] = fVar25;
        return;
      }
      fVar22 = param_1[4];
      fVar26 = (float)VectorUnsignedToFloat((uint)*puVar11,(byte)(uVar1 >> 0x15) & 3);
      fVar25 = (float)VectorUnsignedToFloat((uint)puVar11[1],(byte)(uVar1 >> 0x15) & 3);
      fVar26 = fVar26 * DAT_0067da44 * param_1[6] + *param_1;
      fVar12 = param_1[5];
      param_2[1] = 1.4013e-45;
      *param_2 = 0.0;
      fVar24 = param_1[1];
      param_2[4] = fVar12 + fVar25 * fVar22;
      param_2[5] = fVar16;
      param_2[6] = fVar16;
      param_2[7] = fVar16;
      fVar16 = DAT_0067da4c;
      if (fVar24 < fVar26) {
        fVar26 = fVar24;
      }
      param_2[2] = fVar26;
      param_2[3] = fVar16;
      return;
    }
    fVar22 = DAT_0067da40;
    fVar12 = DAT_0067da3c;
    fVar16 = func_00590D4C(param_1[7] * fparam_0);
    fVar16 = ALBW_AS_F32((int)fVar16);
    param_2[1] = fVar16;
    if ((cVar2 == '\x02') && (((uint)ALBW_AS_U32(fVar16) & 1) != 0)) {
      bVar8 = true;
      fVar16 = (float)VectorSignedToFloat((int)ALBW_AS_U32(fVar16) + 1,(byte)(uVar15 >> 0x15) & 3);
      fVar16 = (param_1[1] - *param_1) * fVar16;
      fparam_0 = fVar16 - fparam_0;
    }
    else {
      fVar16 = (float)VectorSignedToFloat(ALBW_AS_U32(fVar16),(byte)(uVar15 >> 0x15) & 3);
      fVar16 = (param_1[1] - *param_1) * fVar16;
      fparam_0 = fparam_0 - fVar16;
    }
    uVar19 = (uint)((fparam_0 / param_1[6]) * fVar22);
  }
  fVar9 = DAT_0067da5c;
  fVar25 = DAT_0067da58;
  fVar24 = DAT_0067da54;
  fVar22 = DAT_0067da50;
  puVar11 = (ushort *)CF_FBITS(*param_2);
  if (puVar11 == (ushort *)0x0) {
    fVar17 = (float)VectorSignedToFloat(*(ushort *)((int)param_1 + 0xe) - 1,
                                        (byte)(uVar15 >> 0x15) & 3);
    iVar18 = VectorFloatToUnsigned(param_1[7] * fVar17 * fparam_0,3);
    puVar11 = (ushort *)((int)ALBW_AS_U32(param_1[8]) + iVar18 * 6);
  }
  if (bVar8) {
    puVar10 = puVar11;
    if (*puVar11 < uVar19) {
      do {
        puVar11 = puVar11 + 3;
      } while (*puVar11 < uVar19);
    }
    else {
      do {
        puVar11 = puVar10;
        puVar10 = puVar11 + -3;
      } while (uVar19 <= puVar11[-3]);
    }
    uVar3 = *puVar11;
    fVar20 = param_1[6];
    fVar21 = *param_1;
    uVar4 = puVar11[-3];
    *param_2 = ALBW_AS_F32((puVar11 + -3));
    cVar2 = *(char *)(param_1 + 3);
    fVar17 = (float)VectorUnsignedToFloat((uint)uVar3,(byte)(uVar15 >> 0x15) & 3);
    fVar23 = (float)VectorUnsignedToFloat((uint)uVar4,(byte)(uVar15 >> 0x15) & 3);
    fVar17 = (fVar21 - fVar17 * fVar26 * fVar20) + fVar16;
    fVar16 = (fVar21 - fVar23 * fVar26 * fVar20) + fVar16;
    if (cVar2 == '\0') {
      uVar3 = puVar11[1];
      fVar22 = param_1[4];
      fVar26 = param_1[5];
      param_2[2] = fVar17;
      param_2[3] = fVar16;
      fVar16 = (float)VectorUnsignedToFloat((uint)uVar3,(byte)(uVar15 >> 0x15) & 3);
      param_2[4] = fVar26 + fVar16 * fVar22;
      param_2[5] = fVar12;
      param_2[6] = fVar12;
      param_2[7] = fVar12;
      return;
    }
    if (cVar2 == '\x01') {
      uVar3 = puVar11[1];
      fVar22 = param_1[5];
      fVar24 = param_1[4];
      uVar4 = puVar11[-2];
      param_2[2] = fVar17;
      param_2[3] = fVar16;
      fVar26 = (float)VectorUnsignedToFloat((uint)uVar3,(byte)(uVar15 >> 0x15) & 3);
      fVar26 = fVar22 + fVar26 * fVar24;
      fVar25 = (float)VectorUnsignedToFloat((uint)uVar4,(byte)(uVar15 >> 0x15) & 3);
      param_2[4] = fVar26;
      param_2[5] = ((fVar22 + fVar25 * fVar24) - fVar26) / (fVar16 - fVar17);
      param_2[6] = fVar12;
      param_2[7] = fVar12;
      return;
    }
    if (cVar2 == '\x02') {
      uVar3 = puVar11[1];
      fVar12 = param_1[5];
      fVar20 = param_1[4];
      uVar4 = puVar11[-2];
      uVar5 = puVar11[2];
      uVar6 = puVar11[-1];
      param_2[2] = fVar17;
      param_2[3] = fVar16;
      fVar26 = (float)VectorUnsignedToFloat((uint)uVar3,(byte)(uVar15 >> 0x15) & 3);
      fVar27 = (float)VectorSignedToFloat((int)(short)uVar6,(byte)(uVar15 >> 0x15) & 3);
      fVar26 = fVar12 + fVar26 * fVar20;
      fVar21 = (float)VectorUnsignedToFloat((uint)uVar4,(byte)(uVar15 >> 0x15) & 3);
      param_2[4] = fVar26;
      fVar27 = fVar27 * DAT_0067da60;
      fVar23 = (float)VectorSignedToFloat((int)(short)uVar5,(byte)(uVar15 >> 0x15) & 3);
      fVar26 = fVar26 - (fVar12 + fVar21 * fVar20);
      fVar23 = fVar23 * DAT_0067da60;
      fVar16 = fVar16 - fVar17;
      param_2[5] = fVar23;
      fVar22 = fVar22 / fVar16;
      param_2[6] = ((fVar16 * fVar24 * fVar23 - fVar26 * fVar25) - fVar16 * fVar27) *
                   fVar22 * fVar22;
      param_2[7] = (fVar26 * fVar9 + fVar16 * fVar23 + fVar16 * fVar27) * fVar22 * fVar22 * fVar22;
      return;
    }
  }
  else {
    puVar10 = puVar11;
    if (uVar19 < *puVar11) {
      do {
        puVar11 = puVar11 + -3;
      } while (uVar19 < *puVar11);
    }
    else {
      do {
        puVar11 = puVar10;
        puVar10 = puVar11 + 3;
      } while (puVar11[3] <= uVar19);
    }
    fVar21 = (float)VectorUnsignedToFloat((uint)*puVar11,(byte)(uVar15 >> 0x15) & 3);
    fVar17 = param_1[6];
    fVar23 = (float)VectorUnsignedToFloat((uint)puVar11[3],(byte)(uVar15 >> 0x15) & 3);
    fVar20 = *param_1;
    *param_2 = ALBW_AS_F32((puVar11 + 3));
    cVar2 = *(char *)(param_1 + 3);
    fVar21 = fVar21 * fVar26 * fVar17 + fVar16 + fVar20;
    fVar20 = fVar23 * fVar26 * fVar17 + fVar16 + fVar20;
    if (cVar2 == '\0') {
      uVar3 = puVar11[1];
      fVar26 = param_1[4];
      fVar16 = param_1[5];
      param_2[2] = fVar21;
      param_2[5] = fVar12;
      param_2[6] = fVar12;
      param_2[7] = fVar12;
      fVar12 = (float)VectorUnsignedToFloat((uint)uVar3,(byte)(uVar15 >> 0x15) & 3);
      param_2[3] = fVar20;
      param_2[4] = fVar16 + fVar12 * fVar26;
      return;
    }
    if (cVar2 == '\x01') {
      uVar3 = puVar11[1];
      fVar26 = param_1[5];
      fVar22 = param_1[4];
      uVar4 = puVar11[4];
      param_2[2] = fVar21;
      param_2[6] = fVar12;
      param_2[7] = fVar12;
      fVar16 = (float)VectorUnsignedToFloat((uint)uVar3,(byte)(uVar15 >> 0x15) & 3);
      fVar16 = fVar26 + fVar16 * fVar22;
      fVar12 = (float)VectorUnsignedToFloat((uint)uVar4,(byte)(uVar15 >> 0x15) & 3);
      param_2[3] = fVar20;
      param_2[4] = fVar16;
      param_2[5] = ((fVar26 + fVar12 * fVar22) - fVar16) / (fVar20 - fVar21);
      return;
    }
    if (cVar2 == '\x02') {
      uVar3 = puVar11[1];
      fVar16 = param_1[5];
      fVar12 = param_1[4];
      uVar4 = puVar11[4];
      uVar5 = puVar11[2];
      uVar6 = puVar11[5];
      param_2[2] = fVar21;
      param_2[3] = fVar20;
      fVar26 = (float)VectorUnsignedToFloat((uint)uVar3,(byte)(uVar15 >> 0x15) & 3);
      fVar27 = (float)VectorSignedToFloat((int)(short)uVar6,(byte)(uVar15 >> 0x15) & 3);
      fVar26 = fVar16 + fVar26 * fVar12;
      fVar17 = (float)VectorUnsignedToFloat((uint)uVar4,(byte)(uVar15 >> 0x15) & 3);
      param_2[4] = fVar26;
      fVar27 = fVar27 * DAT_0067dcb4;
      fVar23 = (float)VectorSignedToFloat((int)(short)uVar5,(byte)(uVar15 >> 0x15) & 3);
      fVar26 = fVar26 - (fVar16 + fVar17 * fVar12);
      fVar23 = fVar23 * DAT_0067dcb4;
      fVar20 = fVar20 - fVar21;
      param_2[5] = fVar23;
      fVar22 = fVar22 / fVar20;
      param_2[6] = ((fVar20 * fVar24 * fVar23 - fVar26 * fVar25) - fVar20 * fVar27) *
                   fVar22 * fVar22;
      param_2[7] = (fVar26 * fVar9 + fVar20 * fVar23 + fVar20 * fVar27) * fVar22 * fVar22 * fVar22;
      return;
    }
  }
  return;
}

