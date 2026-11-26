/* compilefix: USA 00368CEC (EU 00368CC8), Ghidra-derived (build/ghidra_analyzed4).
 * Failed to compile: member reference base type 'uint' (aka 'unsigned int') is not a structure or union
 * Fixed (each an exact C form of the ARM operation; the rest is the converted Ghidra text):
 *  - arr[i]._O_S_ -> typed byte access at (char *)&arr[i] + O [1]
 *  - implicit float<->int conversions (Ghidra COPY between a float and an int-typed variable or
 *    pool word, e.g. `fVar = _DAT_xxx;`, `puVar[3] = fVar;`) made bit copies [2]
 * Confidence: high for the fixes (each class checked against the EU disassembly on sample sites);
 * the function body otherwise has the fidelity of the Ghidra output (bare `return;` exits of
 * functions retyped non-void return 0, as the converter does).
 * Fixed (BOOT_LOG 184): the ARM compares the float's bits (vmov rX, sY; cmp), which the converted text
 * wrote as a conversion of the value to an integer. */
#include "ghidra_types.h"
#include "compilefix.h"

extern int func_0010A464(undefined4 *param_1);
extern int func_0010E3C4(uint *param_1,uint *param_2,uint param_3);
extern int func_0025B810(int param_1,int param_2,float fparam_0);
extern int func_0025B874(undefined4 *param_1);
extern float func_0034C4C0(int param_1,uint param_2,int param_3,float fparam_0);
extern int func_0034C57C(int param_1,int param_2);
extern int func_00587B50(int param_1,int *param_2,int param_3);
extern int func_00587F74(int param_1,int *param_2,int param_3);
extern float DAT_00368ffc;
extern float DAT_00369000;
extern float DAT_00369004;
extern int DAT_00369008;
extern float DAT_0036900c;
extern float DAT_00369010;
extern int *DAT_0036903c;
extern undefined4 DAT_00369040;
extern undefined4 DAT_00369044;
extern float DAT_00369048;
extern int DAT_0036904c;
extern int DAT_00369350;
extern undefined1 DAT_00369374;
extern char s_SE_S_RUPEE_DOWN_00369364[];
extern char s_SE_S_RUPEE_DOWN_FIN_00369028[];
extern char s_SE_S_RUPEE_UP_00369354[];
extern char s_SE_S_RUPEE_UP_FIN_00369014[];

// USA 00368CEC <- EU 00368CC8 (Ghidra, non-matching)
// GLOBAL DAT_00368ffc float
// GLOBAL DAT_00369000 float
// GLOBAL DAT_00369004 float
// GLOBAL DAT_00369008 int
// GLOBAL DAT_0036900c float
// GLOBAL DAT_00369010 float
// GLOBAL DAT_0036903c int *
// GLOBAL DAT_00369040 undefined4
// GLOBAL DAT_00369044 undefined4
// GLOBAL DAT_00369048 float
// GLOBAL DAT_0036904c int
// GLOBAL DAT_00369350 int
// GLOBAL DAT_00369374 undefined1
// GLOBAL s_SE_S_RUPEE_DOWN_00369364 string
// GLOBAL s_SE_S_RUPEE_DOWN_FIN_00369028 string
// GLOBAL s_SE_S_RUPEE_UP_00369354 string
// GLOBAL s_SE_S_RUPEE_UP_FIN_00369014 string

undefined4 func_00368CEC(int param_1)

{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  byte bVar4;
  undefined1 *puVar5;
  int iVar6;
  uint *puVar7;
  int iVar8;
  float *pfVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  char *pcVar13;
  int *piVar14;
  undefined4 *puVar15;
  uint uVar16;
  uint uVar17;
  int iVar18;
  bool bVar19;
  uint in_fpscr;
  uint uVar20;
  float fVar21;
  float fVar22;
  undefined4 uVar23;
  int iVar24;
  undefined4 uVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  float fVar29;
  float fVar30;
  float fVar31;
  float fVar32;
  float fVar33;
  undefined4 uVar34;
  ulonglong uVar35;
  _Alignas(8) unsigned char albw_frame[0x150];
  #define local_150 (*(int *)(albw_frame + 0x0))
  #define local_14c (*(char * *)(albw_frame + 0x4))
  #define local_144 (*(int *)(albw_frame + 0xc))
  #define local_140 (*(uint * *)(albw_frame + 0x10))
  #define local_13c (*(int *)(albw_frame + 0x14))
  #define local_138 ((uint *)(albw_frame + 0x18))
  #define uStack_119 (*(undefined1 *)(albw_frame + 0x37))
  #define local_118 (*(int *)(albw_frame + 0x38))
  #define local_114 (*(uint * *)(albw_frame + 0x3c))
  #define auStack_f8 ((undefined1 *)(albw_frame + 0x58))
  #define auStack_b8 ((undefined4 *)(albw_frame + 0x98))
  #define auStack_98 ((undefined1 *)(albw_frame + 0xb8))
  #define local_58 (*(int *)(albw_frame + 0xf8))
  #define local_54 (*(uint * *)(albw_frame + 0xfc))
  fVar33 = DAT_00369000;
  fVar32 = DAT_00368ffc;
  iVar10 = *(int *)(param_1 + 0xc);
  fVar21 = *(float *)(param_1 + 0x10);
  fVar26 = (float)VectorSignedToFloat(iVar10,(byte)(in_fpscr >> 0x15) & 3);
  uVar17 = in_fpscr & 0xfffffff;
  if (fVar26 == fVar21) {
    return 0;
  }
  fVar27 = (float)VectorSignedToFloat(iVar10,(byte)(uVar17 >> 0x15) & 3);
  uVar16 = uVar17 | (uint)(fVar27 < fVar21) << 0x1f;
  bVar1 = SUB41(uVar16 >> 0x1f,0) == (NAN(fVar27) || NAN(fVar21));
  fVar26 = (float)VectorSignedToFloat(iVar10,(byte)(uVar16 >> 0x15) & 3);
  fVar26 = fVar26 - fVar21;
  uVar16 = uVar17 | (uint)(fVar26 < DAT_00369000) << 0x1f;
  if (fVar26 == DAT_00369000 || SUB41(uVar16 >> 0x1f,0) != (NAN(fVar26) || NAN(DAT_00369000))) {
    fVar26 = -fVar26;
  }
  fVar30 = (float)VectorSignedToFloat(*(int *)(param_1 + 0x20),(byte)(uVar16 >> 0x15) & 3);
  fVar26 = fVar26 / fVar30;
  uVar16 = uVar17 | (uint)(DAT_00368ffc < fVar26) << 0x1f;
  if (DAT_00368ffc != fVar26 && SUB41(uVar16 >> 0x1f,0) == (NAN(DAT_00368ffc) || NAN(fVar26))) {
    fVar26 = DAT_00368ffc;
  }
  fVar30 = (float)VectorSignedToFloat(iVar10,(byte)(uVar16 >> 0x15) & 3);
  uVar16 = uVar17 | (uint)(fVar21 < fVar30) << 0x1f;
  if (fVar30 <= fVar21) {
    if (fVar21 != fVar30 && SUB41(uVar16 >> 0x1f,0) == (NAN(fVar21) || NAN(fVar30))) {
      fVar26 = fVar21 - fVar26;
      if ((fVar26 <= fVar30) ||
         (uVar17 = uVar17 | (uint)(fVar26 < fVar21) << 0x1f,
         fVar26 != fVar21 && SUB41(uVar17 >> 0x1f,0) == (NAN(fVar26) || NAN(fVar21))))
      goto LAB_00368da8;
      goto LAB_00368db0;
    }
  }
  else {
    fVar26 = fVar21 + fVar26;
    if ((fVar30 <= fVar26) ||
       (uVar17 = uVar17 | (uint)(fVar21 < fVar26) << 0x1f,
       fVar21 != fVar26 && SUB41(uVar17 >> 0x1f,0) == (NAN(fVar21) || NAN(fVar26)))) {
LAB_00368da8:
      *(float *)(param_1 + 0x10) = fVar30;
      uVar16 = uVar17;
    }
    else {
LAB_00368db0:
      *(float *)(param_1 + 0x10) = fVar26;
      uVar16 = uVar17;
    }
  }
  iVar18 = DAT_00369008;
  fVar26 = DAT_00369004;
  iVar8 = *(int *)(param_1 + 0x20) + -1;
  uVar35 = (ulonglong)(uint)ALBW_AS_U32(DAT_00369004);
  *(int *)(param_1 + 0x20) = iVar8;
  iVar6 = DAT_0036904c;
  fVar30 = DAT_00369048;
  if (0 < iVar8) {
    fVar31 = *(float *)(param_1 + 0x10);
    fVar22 = (float)VectorSignedToFloat(iVar10,(byte)(uVar16 >> 0x15) & 3);
    fVar22 = fVar22 - fVar31;
    bVar19 = DAT_00369010 == fVar22;
    bVar2 = fVar22 <= DAT_00369010;
    uVar16 = uVar16 & 0xfffffff;
    if (!bVar2 || bVar19) {
      bVar19 = fVar22 == DAT_0036900c;
      bVar2 = DAT_0036900c <= fVar22;
    }
    if (bVar2 && !bVar19) {
      fVar26 = (float)VectorSignedToFloat(iVar10,(byte)(uVar16 >> 0x15) & 3);
      uVar17 = uVar16 | (uint)(fVar26 < fVar31) << 0x1f | (uint)(fVar26 == fVar31) << 0x1e;
      uVar20 = uVar17 | (uint)(NAN(fVar26) || NAN(fVar31)) << 0x1c;
      bVar4 = (byte)(uVar17 >> 0x18);
      iVar10 = (int)fVar31;
      fVar26 = (float)VectorSignedToFloat(iVar10,(byte)(uVar20 >> 0x15) & 3);
      if ((bool)(bVar4 >> 6 & 1) || bVar4 >> 7 != ((byte)(uVar20 >> 0x1c) & 1)) {
        uVar17 = uVar16 | (uint)(fVar26 == fVar31) << 0x1e;
        if ((!SUB41(uVar17 >> 0x1e,0)) &&
           (uVar17 = uVar16 | (uint)(fVar33 == fVar31) << 0x1e | (uint)(fVar31 <= fVar33) << 0x1d,
           bVar4 = (byte)(uVar17 >> 0x18), (bool)(bVar4 >> 5 & 1) && !(bool)(bVar4 >> 6))) {
          iVar10 = iVar10 + -1;
        }
      }
      else {
        uVar17 = uVar16 | (uint)(fVar26 == fVar31) << 0x1e;
        if ((!SUB41(uVar17 >> 0x1e,0)) &&
           (uVar17 = uVar16 | (uint)(fVar33 == fVar31) << 0x1e | (uint)(fVar31 <= fVar33) << 0x1d,
           bVar4 = (byte)(uVar17 >> 0x18), !(bool)(bVar4 >> 5 & 1) || (bool)(bVar4 >> 6))) {
          iVar10 = iVar10 + 1;
        }
      }
      uVar16 = 0;
      iVar8 = (int)ALBW_AS_U32(DAT_00369048) + 0x80000000;
      uVar23 = DAT_00369040;
      uVar34 = DAT_00369044;
      fVar26 = DAT_0036900c;
      do {
        iVar24 = (int)fVar31;
        iVar11 = (int)((ulonglong)((longlong)iVar6 * (longlong)iVar24) >> 0x20);
        iVar12 = (int)((ulonglong)((longlong)iVar6 * (longlong)iVar10) >> 0x20);
        iVar12 = (iVar12 >> 2) - (iVar12 >> 0x1f);
        iVar10 = iVar10 + iVar12 * -10;
        pcVar13 = (char *)(param_1 + 0x24);
        if (uVar16 < 3) {
          pcVar13 = pcVar13 + uVar16;
        }
        if (*pcVar13 == '\0') {
          if (iVar10 == 0) {
            piVar14 = (int *)(param_1 + 0x14);
            if (uVar16 < 3) {
              piVar14 = piVar14 + uVar16;
            }
            if (0x41000000 < *piVar14) {
              puVar15 = (undefined4 *)(param_1 + 0x14);
              if (uVar16 < 3) {
                puVar15 = puVar15 + uVar16;
              }
              *puVar15 = uVar23;
            }
          }
          else if (iVar10 == 9) {
            piVar14 = (int *)(param_1 + 0x14);
            if (uVar16 < 3) {
              piVar14 = piVar14 + uVar16;
            }
            if (*piVar14 < 0x40000000) {
              puVar15 = (undefined4 *)(param_1 + 0x14);
              if (uVar16 < 3) {
                puVar15 = puVar15 + uVar16;
              }
              *puVar15 = uVar34;
            }
          }
          pfVar9 = (float *)(param_1 + 0x14);
          if (uVar16 < 3) {
            pfVar9 = pfVar9 + uVar16;
          }
          fVar28 = *pfVar9;
          fVar22 = (float)VectorSignedToFloat(iVar10,(byte)(uVar17 >> 0x15) & 3);
          uVar20 = uVar17 & 0xfffffff;
          uVar3 = uVar20 | (uint)(fVar28 < fVar22) << 0x1f | (uint)(fVar28 == fVar22) << 0x1e |
                  (uint)(fVar22 <= fVar28) << 0x1d;
          uVar17 = uVar3 | (uint)(NAN(fVar28) || NAN(fVar22)) << 0x1c;
          bVar4 = (byte)(uVar3 >> 0x18);
          if ((bool)(bVar4 >> 5 & 1)) {
            if (!(bool)(bVar4 >> 6 & 1) && bVar4 >> 7 == ((byte)(uVar17 >> 0x1c) & 1)) {
              fVar29 = fVar28 - fVar32;
              uVar17 = uVar20 | (uint)(fVar29 == fVar22) << 0x1e | (uint)(fVar22 <= fVar29) << 0x1d;
              bVar4 = (byte)(uVar17 >> 0x18);
              if ((!(bool)(bVar4 >> 5 & 1) || (bool)(bVar4 >> 6)) ||
                 (uVar20 = uVar20 | (uint)(fVar29 < fVar28) << 0x1f |
                           (uint)(fVar29 == fVar28) << 0x1e,
                 uVar17 = uVar20 | (uint)(NAN(fVar29) || NAN(fVar28)) << 0x1c,
                 bVar4 = (byte)(uVar20 >> 0x18),
                 !(bool)(bVar4 >> 6 & 1) && bVar4 >> 7 == ((byte)(uVar17 >> 0x1c) & 1)))
              goto LAB_00369078;
              goto LAB_00369080;
            }
          }
          else {
            fVar29 = fVar28 + fVar32;
            uVar17 = uVar20 | (uint)(fVar22 == fVar29) << 0x1e | (uint)(fVar29 <= fVar22) << 0x1d;
            bVar4 = (byte)(uVar17 >> 0x18);
            if ((!(bool)(bVar4 >> 5 & 1) || (bool)(bVar4 >> 6)) ||
               (uVar20 = uVar20 | (uint)(fVar28 < fVar29) << 0x1f | (uint)(fVar28 == fVar29) << 0x1e
               , uVar17 = uVar20 | (uint)(NAN(fVar28) || NAN(fVar29)) << 0x1c,
               bVar4 = (byte)(uVar20 >> 0x18),
               !(bool)(bVar4 >> 6 & 1) && bVar4 >> 7 == ((byte)(uVar17 >> 0x1c) & 1))) {
LAB_00369078:
              *pfVar9 = fVar22;
            }
            else {
LAB_00369080:
              *pfVar9 = fVar29;
            }
          }
          pfVar9 = (float *)(param_1 + 0x14);
          if (uVar16 < 3) {
            pfVar9 = pfVar9 + uVar16;
          }
          fVar22 = (float)VectorSignedToFloat(iVar10,(byte)(uVar17 >> 0x15) & 3);
          if (((uint)ALBW_AS_U32(*pfVar9 - fVar22) <= (uint)ALBW_AS_U32(fVar30)) && ((int)ALBW_AS_U32(*pfVar9 - fVar22) <= iVar8))
          goto joined_r0x003690c0;
        }
        else {
          pcVar13 = (char *)(param_1 + 0x24);
          if (uVar16 < 3) {
            pcVar13 = pcVar13 + uVar16;
          }
          if (*pcVar13 == '\x01') {
            fVar22 = (float)VectorSignedToFloat(iVar24,(byte)(uVar17 >> 0x15) & 3);
            pfVar9 = (float *)(param_1 + 0x14);
            if (uVar16 < 3) {
              pfVar9 = pfVar9 + uVar16;
            }
            fVar28 = (float)VectorSignedToFloat(iVar24 + ((iVar11 >> 2) - (iVar11 >> 0x1f)) * -10,
                                                (byte)(uVar17 >> 0x15) & 3);
            *pfVar9 = fVar28 + (fVar31 - fVar22);
          }
          else {
joined_r0x003690c0:
            puVar15 = (undefined4 *)(param_1 + 0x14);
            if (uVar16 < 3) {
              puVar15 = (undefined4 *)(param_1 + 0x14 + uVar16 * 4);
            }
            uVar25 = ALBW_AS_U32(VectorSignedToFloat(iVar10,(byte)(uVar17 >> 0x15) & 3));
            *puVar15 = uVar25;
          }
        }
        pfVar9 = (float *)(param_1 + 0x14);
        if (uVar16 < 3) {
          pfVar9 = pfVar9 + uVar16;
        }
        fVar28 = *pfVar9;
        pfVar9 = (float *)(param_1 + 0x14);
        iVar10 = (int)fVar28;
        fVar22 = (float)VectorSignedToFloat(iVar10,(byte)(uVar17 >> 0x15) & 3);
        uVar20 = uVar17 & 0xfffffff;
        uVar17 = uVar20 | (uint)(fVar22 == fVar28) << 0x1e | (uint)(fVar28 <= fVar22) << 0x1d;
        bVar4 = (byte)(uVar17 >> 0x18);
        bVar19 = (bool)(bVar4 >> 6);
        if (!bVar19) {
          uVar17 = uVar20 | (uint)(fVar33 == fVar28) << 0x1e | (uint)(fVar28 <= fVar33) << 0x1d;
          bVar4 = (byte)(uVar17 >> 0x18);
          bVar19 = (bool)(bVar4 >> 6);
        }
        if ((bool)(bVar4 >> 5 & 1) && !bVar19) {
          iVar10 = iVar10 + -1;
        }
        if (uVar16 < 3) {
          pfVar9 = pfVar9 + uVar16;
        }
        fVar22 = (float)VectorSignedToFloat(iVar10,(byte)(uVar17 >> 0x15) & 3);
        func_0034C4C0(*(int *)(param_1 + 0x3c),uVar16,iVar10,*pfVar9 - fVar22);
        fVar22 = ALBW_AS_F32(uVar35);
        fVar31 = fVar31 * fVar26;
        uVar16 = uVar16 + 1;
        iVar10 = iVar12;
      } while ((int)uVar16 < 3);
      local_13c = 0x20;
      uStack_119 = 0;
      (*(undefined1 *)((char *)&local_138[0] + 0)) = 0;
      local_144 = DAT_00369350;
      if (fVar27 != fVar21 && bVar1) {
        local_54 = (uint *)s_SE_S_RUPEE_UP_00369354;
      }
      else {
        local_54 = (uint *)s_SE_S_RUPEE_DOWN_00369364;
      }
      local_58 = iVar18;
      local_140 = local_138;
      (**(code **)(iVar18 + 8))(&local_58);
      uVar17 = 0;
      do {
        if (*(char *)((int)local_54 + uVar17) == '\0') {
          if ((int)uVar17 < 0x40001) goto LAB_003691e8;
          break;
        }
        uVar17 = uVar17 + 1;
      } while ((int)uVar17 < 0x40001);
      uVar17 = 0;
LAB_003691e8:
      if (local_13c <= (int)uVar17) {
        uVar17 = local_13c - 1;
      }
      (**(code **)(local_58 + 8))(&local_58);
      func_0010E3C4(local_138,local_54,uVar17);
      puVar7 = local_140;
      *(undefined1 *)((int)local_138 + uVar17) = 0;
      if (*(char *)(param_1 + 0x24) != '\0') {
        local_114 = (uint *)&DAT_00369374;
        local_118 = iVar18;
        (**(code **)(local_144 + 8))();
        iVar10 = 0;
        do {
          if (*(char *)((int)local_140 + iVar10) == '\0') {
            if (iVar10 < 0x40001) goto LAB_00369278;
            break;
          }
          iVar10 = iVar10 + 1;
        } while (iVar10 < 0x40001);
        iVar10 = 0;
LAB_00369278:
        iVar18 = iVar10;
        if (iVar10 < 0) {
          iVar18 = 0;
        }
        (**(code **)(local_118 + 8))(&local_118);
        uVar17 = 0;
        do {
          if (*(char *)((int)local_114 + uVar17) == '\0') {
            if ((int)uVar17 < 0x40001) goto LAB_003692c8;
            break;
          }
          uVar17 = uVar17 + 1;
        } while ((int)uVar17 < 0x40001);
        uVar17 = 0;
LAB_003692c8:
        if (local_13c - iVar18 <= (int)uVar17) {
          uVar17 = (local_13c - iVar18) - 1;
        }
        if (0 < (int)uVar17) {
          (**(code **)(local_118 + 8))(&local_118);
          func_0010E3C4((uint *)((int)puVar7 + iVar18),local_114,uVar17);
          if (iVar10 < (int)(iVar18 + uVar17)) {
            *(undefined1 *)((int)puVar7 + iVar18 + uVar17) = 0;
          }
        }
      }
      func_0010A464(auStack_b8);
      func_00587B50(*DAT_0036903c,&local_144,(int)auStack_b8);
      func_0025B810((int)auStack_b8,0,fVar22);
      puVar5 = auStack_98;
      goto LAB_00369340;
    }
  }
  uVar23 = ALBW_AS_U32(VectorSignedToFloat(iVar10,(byte)(uVar16 >> 0x15) & 3));
  *(undefined4 *)(param_1 + 0x10) = uVar23;
  func_0034C57C(*(int *)(param_1 + 0x3c),iVar10);
  func_0010A464(&local_118);
  if (fVar27 != fVar21 && bVar1) {
    local_14c = s_SE_S_RUPEE_UP_FIN_00369014;
  }
  else {
    local_14c = s_SE_S_RUPEE_DOWN_FIN_00369028;
  }
  local_150 = iVar18;
  func_00587F74(*DAT_0036903c,&local_150,(int)&local_118);
  func_0025B810((int)&local_118,0,fVar26);
  puVar5 = auStack_f8;
LAB_00369340:
  return func_0025B874((undefined4 *)(puVar5 + -0x20));
}

