/* compilefix: USA 001D7348 (EU 001D7348), the converted stage-2 text.
 * Fixed (BOOT_LOG 184): the ARM copies this word between a float and an integer (no vcvt), which the
 * converted text wrote as a conversion of the value. */
#include "ghidra_types.h"

extern int func_00150A84(int *param_1,int *param_2,int param_3);
extern float DAT_001d74b8;
extern float DAT_001d74bc;
extern float DAT_001d74c0;
extern float DAT_001d74c4;
extern int DAT_001d74c8;
extern undefined DAT_001d74cc;
extern int DAT_001d74e4;
extern char s_ASE_Rupee_BOUND_KU_001d74ce[];
extern undefined4 _DAT_001d74cc;

// USA 001D7348 <- EU 001D7348 (Ghidra, non-matching)
// GLOBAL DAT_001d74b8 float
// GLOBAL DAT_001d74bc float
// GLOBAL DAT_001d74c0 float
// GLOBAL DAT_001d74c4 float
// GLOBAL DAT_001d74c8 int
// GLOBAL DAT_001d74cc undefined
// GLOBAL DAT_001d74e4 int
// GLOBAL s_ASE_Rupee_BOUND_KU_001d74ce string

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 func_001D7348(int *param_1)

{
  int iVar1;
  float *pfVar2;
  uint uVar3;
  uint uVar4;
  uint in_fpscr;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  _Alignas(8) unsigned char albw_frame[0x20];
  #define local_18 (*(int *)(albw_frame + 0x8))
  #define local_14 (*(char * *)(albw_frame + 0xc))
  if ((char)param_1[0x14f] == '\0') {
    uVar4 = param_1[0x13f];
    if (uVar4 <= (uint)param_1[0x13e]) {
      *(undefined1 *)(param_1 + 0x14f) = 1;
      local_14 = s_ASE_Rupee_BOUND_KU_001d74ce + 2;
      local_18 = DAT_001d74e4;
      return func_00150A84(param_1,&local_18,0);
    }
    uVar3 = param_1[0x13e] + 1;
    param_1[0x13e] = uVar3;
    fVar7 = DAT_001d74b8;
    iVar1 = uVar4 - uVar3;
    if (iVar1 < 2) {
      iVar1 = 1;
    }
    fVar8 = (float)VectorSignedToFloat(iVar1,(byte)(in_fpscr >> 0x15) & 3);
    param_1[0xf4] =
         (int)ALBW_AS_U32((ALBW_AS_F32(param_1[0xf4]) +
              (ALBW_AS_F32(param_1[0x14c]) - ALBW_AS_F32(param_1[0xf4])) * (DAT_001d74b8 / fVar8)));
    fVar8 = DAT_001d74bc;
    fVar9 = (float)VectorSignedToFloat(iVar1,(byte)(in_fpscr >> 0x15) & 3);
    fVar5 = ALBW_AS_F32(param_1[0x14e]) - ALBW_AS_F32(param_1[0xf6]);
    fVar6 = fVar5;
    if (uVar4 == 0 || uVar3 == 0) {
      fVar6 = DAT_001d74bc;
    }
    param_1[0xf6] = (int)ALBW_AS_U32(ALBW_AS_F32(param_1[0xf6]) + fVar5 * (fVar7 / fVar9));
    if ((uVar4 != 0 && uVar3 != 0) && (fVar6 = fVar7, uVar3 < uVar4)) {
      fVar6 = (float)VectorUnsignedToFloat(uVar3,(byte)(in_fpscr >> 0x15) & 3);
      fVar6 = fVar6 * ALBW_AS_F32(param_1[0x140]);
    }
    if (uVar4 != 0 && uVar3 != 0) {
      fVar8 = fVar7;
    }
    pfVar2 = (float *)(DAT_001d74c8 + ((uint)(int)(fVar6 * DAT_001d74c0) >> 0x18) * 0x10);
    fVar7 = (float)VectorUnsignedToFloat
                             ((int)(fVar6 * DAT_001d74c0) & 0xffffff,(byte)(in_fpscr >> 0x15) & 3);
    if ((uVar4 != 0 && uVar3 != 0) && uVar3 < uVar4) {
      fVar8 = (float)VectorUnsignedToFloat(uVar3,(byte)(in_fpscr >> 0x15) & 3);
      fVar8 = fVar8 * ALBW_AS_F32(param_1[0x140]);
    }
    param_1[0xf5] =
         (int)ALBW_AS_U32(((ALBW_AS_F32(param_1[0x150]) + (*pfVar2 + pfVar2[1] * fVar7 * DAT_001d74c4) * ALBW_AS_F32(_DAT_001d74cc)
               ) - ALBW_AS_F32(param_1[0x151]) * fVar8));
  }
  return 0;
}

