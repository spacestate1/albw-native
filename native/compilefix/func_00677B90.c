/* compilefix: USA 00677B90 (EU 00677B68), the converted stage-2 text.
 * Fixed (BOOT_LOG 184): the ARM copies this word between a float and an integer (no vcvt), which the
 * converted text wrote as a conversion of the value. */
#include "ghidra_types.h"

extern int func_00114E74(float *param_1,float *param_2,float *param_3);
extern int func_003E2134(void);
extern uint DAT_00677e68;

// USA 00677B90 <- EU 00677B68 (Ghidra, non-matching)
// GLOBAL DAT_00677e68 uint

void func_00677B90(int param_1,float *param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  float *pfVar6;
  float *pfVar7;
  int iVar8;
  uint *puVar9;
  int iVar10;
  int iVar11;
  uint *puVar12;
  int iVar13;
  int iVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  undefined4 uVar22;
  ulonglong in_d8;
  _Alignas(8) unsigned char albw_frame[0x80];
  #define local_80 (*(float *)(albw_frame + 0x0))
  #define fStack_7c (*(float *)(albw_frame + 0x4))
  #define fStack_78 (*(float *)(albw_frame + 0x8))
  #define local_74 (*(float *)(albw_frame + 0xc))
  #define local_70 (*(float *)(albw_frame + 0x10))
  #define fStack_6c (*(float *)(albw_frame + 0x14))
  #define fStack_68 (*(float *)(albw_frame + 0x18))
  #define local_64 (*(float *)(albw_frame + 0x1c))
  #define local_60 (*(float *)(albw_frame + 0x20))
  #define fStack_5c (*(float *)(albw_frame + 0x24))
  #define fStack_58 (*(float *)(albw_frame + 0x28))
  #define local_54 (*(float *)(albw_frame + 0x2c))
  #define local_4c (*(float * *)(albw_frame + 0x34))
  #define local_48 (*(float * *)(albw_frame + 0x38))
  #define iStack_30 (*(int *)(albw_frame + 0x50))
  #define local_2c (*(float * *)(albw_frame + 0x54))
  #define uStack_28 (*(undefined4 *)(albw_frame + 0x58))
  iVar8 = 0;
  iVar11 = *(int *)(param_1 + 8);
  iVar10 = *(int *)(param_1 + 0xc);
  iVar14 = *(int *)(param_1 + 0x14);
  if (0 < iVar11) {
    in_d8 = (ulonglong)DAT_00677e68;
  }
  iVar13 = *(int *)(param_1 + 0x1c);
  iStack_30 = param_1;
  local_2c = param_2;
  uStack_28 = param_3;
  if (0 < iVar11) {
    do {
      puVar9 = (uint *)(*(int *)(param_1 + 0xc) + iVar8 * 0x40);
      iVar1 = *(int *)(param_1 + 4);
      uVar5 = *puVar9 & 0xfffffffb;
      *puVar9 = uVar5;
      uVar2 = (uint)*(ushort *)(iVar1 + iVar8 * 2);
      if ((int)uVar2 < iVar11) {
        if (((~uVar5 & 2) == 0) || ((~*(uint *)(*(int *)(param_1 + 0xc) + uVar2 * 0x40) & 4) == 0))
        {
          puVar12 = (uint *)(iVar10 + iVar8 * 0x40);
          local_4c = (float *)(iVar13 + iVar8 * 0xc);
          uVar2 = (uint)*(ushort *)(*(int *)(param_1 + 4) + iVar8 * 2);
          pfVar7 = (float *)(iVar14 + iVar8 * 0x30);
          puVar3 = (uint *)(iVar10 + uVar2 * 0x40);
          local_48 = (float *)(iVar13 + uVar2 * 0xc);
          pfVar6 = (float *)(iVar14 + uVar2 * 0x30);
          *puVar12 = *puVar12 & 0x17ffffff | *puVar3 & (*puVar12 & 0x17ffffff) << 4 & 0xe8000000;
          if ((~*puVar3 & 0x28000000) == 0) {
            func_00114E74(pfVar7,pfVar6,(float *)(puVar12 + 4));
          }
          else {
            fVar15 = ALBW_AS_F32(puVar12[5]);
            fVar16 = ALBW_AS_F32(puVar12[6]);
            fVar17 = ALBW_AS_F32(puVar12[7]);
            fVar18 = ALBW_AS_F32(puVar12[8]);
            fVar19 = ALBW_AS_F32(puVar12[9]);
            fVar20 = ALBW_AS_F32(puVar12[10]);
            fVar21 = ALBW_AS_F32(puVar12[0xb]);
            *pfVar7 = ALBW_AS_F32(puVar12[4]);
            pfVar7[1] = fVar15;
            pfVar7[2] = fVar16;
            pfVar7[3] = fVar17;
            pfVar7[4] = fVar18;
            pfVar7[5] = fVar19;
            pfVar7[6] = fVar20;
            pfVar7[7] = fVar21;
            fVar15 = ALBW_AS_F32(puVar12[0xd]);
            fVar16 = ALBW_AS_F32(puVar12[0xe]);
            fVar17 = ALBW_AS_F32(puVar12[0xf]);
            pfVar7[8] = ALBW_AS_F32(puVar12[0xc]);
            pfVar7[9] = fVar15;
            pfVar7[10] = fVar16;
            pfVar7[0xb] = fVar17;
            fVar16 = ALBW_AS_F32(puVar3[3]);
            fVar15 = ALBW_AS_F32(puVar3[2]);
            pfVar7[3] = pfVar7[3] * ALBW_AS_F32(puVar3[1]);
            pfVar7[7] = fVar21 * fVar15;
            pfVar7[0xb] = fVar17 * fVar16;
            if ((*puVar3 & 4) == 0) {
              local_74 = pfVar6[3];
              local_64 = pfVar6[7];
              local_54 = pfVar6[0xb];
              fStack_58 = ALBW_AS_F32(in_d8);
              local_60 = fStack_58 / *local_48;
              local_80 = *pfVar6 * local_60;
              local_70 = pfVar6[4] * local_60;
              local_60 = pfVar6[8] * local_60;
              fStack_5c = fStack_58 / local_48[1];
              fStack_7c = pfVar6[1] * fStack_5c;
              fStack_6c = pfVar6[5] * fStack_5c;
              fStack_5c = pfVar6[9] * fStack_5c;
              fStack_58 = fStack_58 / local_48[2];
              fStack_78 = pfVar6[2] * fStack_58;
              fStack_68 = pfVar6[6] * fStack_58;
              fStack_58 = pfVar6[10] * fStack_58;
              pfVar6 = &local_80;
            }
            func_00114E74(pfVar7,pfVar6,pfVar7);
          }
          if ((~*puVar12 & 0x2800000) == 0) {
            fVar15 = local_48[1];
            fVar16 = local_48[2];
            *local_4c = *local_48;
            local_4c[1] = fVar15;
            local_4c[2] = fVar16;
          }
          else {
            *local_4c = *local_48 * ALBW_AS_F32(puVar12[1]);
            local_4c[1] = local_48[1] * ALBW_AS_F32(puVar12[2]);
            local_4c[2] = local_48[2] * ALBW_AS_F32(puVar12[3]);
          }
LAB_00677ec4:
          *puVar9 = *puVar9 & 0xfffffffd | 4;
        }
      }
      else if ((~uVar5 & 2) == 0) {
        puVar3 = (uint *)(iVar10 + iVar8 * 0x40);
        pfVar6 = (float *)(iVar14 + iVar8 * 0x30);
        if ((~*puVar3 & 0xc000000) == 0) {
          if (local_2c == (float *)0x0) {
            pfVar7 = (float *)func_003E2134();
            fVar15 = pfVar7[1];
            fVar16 = pfVar7[2];
            fVar17 = pfVar7[3];
            fVar18 = pfVar7[4];
            fVar19 = pfVar7[5];
            fVar20 = pfVar7[6];
            fVar21 = pfVar7[7];
            *pfVar6 = *pfVar7;
            pfVar6[1] = fVar15;
            pfVar6[2] = fVar16;
            pfVar6[3] = fVar17;
            pfVar6[4] = fVar18;
            pfVar6[5] = fVar19;
            pfVar6[6] = fVar20;
            pfVar6[7] = fVar21;
            fVar15 = pfVar7[8];
            fVar16 = pfVar7[9];
            fVar17 = pfVar7[10];
            pfVar6[0xb] = pfVar7[0xb];
            pfVar6[8] = fVar15;
            pfVar6[9] = fVar16;
            pfVar6[10] = fVar17;
          }
          else {
            fVar15 = local_2c[1];
            fVar16 = local_2c[2];
            fVar17 = local_2c[3];
            fVar18 = local_2c[4];
            fVar19 = local_2c[5];
            fVar20 = local_2c[6];
            fVar21 = local_2c[7];
            *pfVar6 = *local_2c;
            pfVar6[1] = fVar15;
            pfVar6[2] = fVar16;
            pfVar6[3] = fVar17;
            pfVar6[4] = fVar18;
            pfVar6[5] = fVar19;
            pfVar6[6] = fVar20;
            pfVar6[7] = fVar21;
            fVar15 = local_2c[8];
            fVar16 = local_2c[9];
            fVar17 = local_2c[10];
            pfVar6[0xb] = local_2c[0xb];
            pfVar6[8] = fVar15;
            pfVar6[9] = fVar16;
            pfVar6[10] = fVar17;
          }
        }
        else if (local_2c == (float *)0x0) {
          fVar15 = ALBW_AS_F32(puVar3[5]);
          fVar16 = ALBW_AS_F32(puVar3[6]);
          fVar17 = ALBW_AS_F32(puVar3[7]);
          fVar18 = ALBW_AS_F32(puVar3[8]);
          fVar19 = ALBW_AS_F32(puVar3[9]);
          fVar20 = ALBW_AS_F32(puVar3[10]);
          fVar21 = ALBW_AS_F32(puVar3[0xb]);
          *pfVar6 = ALBW_AS_F32(puVar3[4]);
          pfVar6[1] = fVar15;
          pfVar6[2] = fVar16;
          pfVar6[3] = fVar17;
          pfVar6[4] = fVar18;
          pfVar6[5] = fVar19;
          pfVar6[6] = fVar20;
          pfVar6[7] = fVar21;
          fVar15 = ALBW_AS_F32(puVar3[0xc]);
          fVar16 = ALBW_AS_F32(puVar3[0xd]);
          fVar17 = ALBW_AS_F32(puVar3[0xe]);
          pfVar6[0xb] = ALBW_AS_F32(puVar3[0xf]);
          pfVar6[8] = fVar15;
          pfVar6[9] = fVar16;
          pfVar6[10] = fVar17;
        }
        else {
          func_00114E74(pfVar6,local_2c,(float *)(puVar3 + 4));
        }
        puVar3 = (uint *)(iVar10 + iVar8 * 0x40);
        if ((~*puVar3 & 0x2800000) == 0) {
          puVar4 = (undefined4 *)(iVar13 + iVar8 * 0xc);
          uVar22 = (undefined4)in_d8;
          *puVar4 = uVar22;
          puVar4[1] = uVar22;
          puVar4[2] = uVar22;
        }
        else {
          puVar12 = (uint *)(iVar13 + iVar8 * 0xc);
          *puVar12 = puVar3[1];
          puVar12[1] = puVar3[2];
          puVar12[2] = puVar3[3];
        }
        goto LAB_00677ec4;
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < iVar11);
  }
  iVar11 = *(int *)(param_1 + 8);
  iVar8 = 0;
  if (0 < iVar11) {
    do {
      uVar2 = *(uint *)(iVar10 + iVar8 * 0x40);
      if (((~uVar2 & 0x28000000) != 0) && ((~uVar2 & 4) == 0)) {
        pfVar6 = (float *)(iVar14 + iVar8 * 0x30);
        pfVar7 = (float *)(iVar13 + iVar8 * 0xc);
        fVar16 = *pfVar7;
        fVar15 = pfVar7[1];
        fVar17 = pfVar7[2];
        *pfVar6 = *pfVar6 * fVar16;
        pfVar6[1] = pfVar6[1] * fVar15;
        pfVar6[2] = pfVar6[2] * fVar17;
        pfVar6[4] = pfVar6[4] * fVar16;
        pfVar6[5] = pfVar6[5] * fVar15;
        pfVar6[6] = pfVar6[6] * fVar17;
        pfVar6[10] = pfVar6[10] * fVar17;
        pfVar6[8] = pfVar6[8] * fVar16;
        pfVar6[9] = pfVar6[9] * fVar15;
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < iVar11);
  }
  return;
}

