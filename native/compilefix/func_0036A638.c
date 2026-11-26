/* compilefix: USA 0036A638 (EU 0036A614), the converted stage-2 text.
 * Fixed (BOOT_LOG 184): the ARM compares the float's bits (vmov rX, sY; cmp), which the converted text
 * wrote as a conversion of the value to an integer. */
// MAPFIX-INTEGRATED v1
#include "ghidra_types.h"

extern int func_0010A464(undefined4 *param_1);
extern undefined8 func_0010E3C4(uint *param_1,uint *param_2,uint param_3);
extern int func_0025B810(int param_1,int param_2,float fparam_0);
extern int func_0025B874(undefined4 *param_1);
extern void func_0034C4C0(int param_1,uint param_2,int param_3,float fparam_0);
extern int func_0034C57C(int param_1,int param_2);
extern int func_004994B0(int param_1,undefined4 param_2,uint param_3,undefined4 param_4,...);
extern int func_00533048(undefined4 param_1,int *param_2,undefined4 param_3);
extern float DAT_0036a8fc;
extern float DAT_0036a900;
extern float DAT_0036a904;
extern float DAT_0036a908;
extern undefined4 DAT_0036a90c;
extern undefined4 DAT_0036a910;
extern float DAT_0036a914;
extern int DAT_0036a918;
extern int DAT_0036ab9c;
extern int DAT_0036aba0;
extern undefined1 DAT_0036abc4;
extern float DAT_0036abcc;
extern char s_SE_S_RUPEE_DOWN_0036abb4[];
extern char s_SE_S_RUPEE_UP_0036aba4[];

// USA 0036A638 <- EU 0036A614 (Ghidra, non-matching)
// GLOBAL DAT_0036a8fc float
// GLOBAL DAT_0036a900 float
// GLOBAL DAT_0036a904 float
// GLOBAL DAT_0036a908 float
// GLOBAL DAT_0036a90c undefined4
// GLOBAL DAT_0036a910 undefined4
// GLOBAL DAT_0036a914 float
// GLOBAL DAT_0036a918 int
// GLOBAL DAT_0036ab9c int
// GLOBAL DAT_0036aba0 int
// GLOBAL DAT_0036abc4 undefined1
// GLOBAL DAT_0036abcc float
// GLOBAL s_SE_S_RUPEE_DOWN_0036abb4 string
// GLOBAL s_SE_S_RUPEE_UP_0036aba4 string

undefined4 func_0036A638(int param_1)

{
  byte bVar1;
  undefined1 *puVar2;
  int iVar3;
  float *pfVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  int *piVar9;
  undefined4 *puVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  bool bVar14;
  bool bVar15;
  uint in_fpscr;
  uint uVar16;
  uint uVar17;
  float fVar18;
  int iVar19;
  undefined4 uVar20;
  float fVar21;
  uint uVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  undefined4 uVar29;
  undefined4 uVar30;
  _Alignas(8) unsigned char albw_frame[0xe0];
  #define local_d8 (*(int *)(albw_frame + 0x8))
  #define local_d4 (*(undefined1 * *)(albw_frame + 0xc))
  #define local_d0 (*(int *)(albw_frame + 0x10))
  #define local_cc ((undefined1 *)(albw_frame + 0x14))
  #define uStack_ad (*(undefined1 *)(albw_frame + 0x33))
  #define auStack_a8 ((undefined4 *)(albw_frame + 0x38))
  #define local_48 (*(int *)(albw_frame + 0x98))
  #define local_44 (*(uint * *)(albw_frame + 0x9c))
  fVar28 = DAT_0036a900;
  fVar27 = DAT_0036a8fc;
  iVar5 = *(int *)(param_1 + 0x6c);
  fVar18 = *(float *)(param_1 + 0x74);
  fVar24 = (float)VectorSignedToFloat(iVar5,(byte)(in_fpscr >> 0x15) & 3);
  fVar24 = fVar24 - fVar18;
  uVar12 = in_fpscr & 0xfffffff;
  uVar17 = uVar12 | (uint)(fVar24 < DAT_0036a900) << 0x1f;
  if (fVar24 == DAT_0036a900 || SUB41(uVar17 >> 0x1f,0) != (NAN(fVar24) || NAN(DAT_0036a900))) {
    fVar24 = -fVar24;
  }
  fVar26 = (float)VectorSignedToFloat(*(int *)(param_1 + 0x70),(byte)(uVar17 >> 0x15) & 3);
  fVar24 = fVar24 / fVar26;
  uVar17 = uVar12 | (uint)(DAT_0036a8fc < fVar24) << 0x1f;
  fVar26 = DAT_0036a8fc;
  if (DAT_0036a8fc == fVar24 || SUB41(uVar17 >> 0x1f,0) != (NAN(DAT_0036a8fc) || NAN(fVar24))) {
    fVar26 = fVar24;
  }
  fVar24 = (float)VectorSignedToFloat(iVar5,(byte)(uVar17 >> 0x15) & 3);
  uVar17 = uVar12 | (uint)(fVar18 < fVar24) << 0x1f;
  if (fVar24 <= fVar18) {
    if (fVar18 == fVar24 || SUB41(uVar17 >> 0x1f,0) != (NAN(fVar18) || NAN(fVar24)))
    goto LAB_0036a6d4;
    fVar26 = fVar18 - fVar26;
    if ((fVar24 < fVar26) &&
       (uVar12 = uVar12 | (uint)(fVar26 < fVar18) << 0x1f,
       fVar26 == fVar18 || SUB41(uVar12 >> 0x1f,0) != (NAN(fVar26) || NAN(fVar18))))
    goto LAB_0036a6d0;
  }
  else {
    fVar26 = fVar18 + fVar26;
    if ((fVar26 < fVar24) &&
       (uVar12 = uVar12 | (uint)(fVar18 < fVar26) << 0x1f,
       fVar18 == fVar26 || SUB41(uVar12 >> 0x1f,0) != (NAN(fVar18) || NAN(fVar26)))) {
LAB_0036a6d0:
      *(float *)(param_1 + 0x74) = fVar26;
      uVar17 = uVar12;
      goto LAB_0036a6d4;
    }
  }
  *(float *)(param_1 + 0x74) = fVar24;
  uVar17 = uVar12;
LAB_0036a6d4:
  iVar3 = *(int *)(param_1 + 0x70) + -1;
  *(int *)(param_1 + 0x70) = iVar3;
  iVar13 = DAT_0036a918;
  fVar18 = DAT_0036a914;
  if (0 < iVar3) {
    fVar26 = *(float *)(param_1 + 0x74);
    fVar24 = (float)VectorSignedToFloat(iVar5,(byte)(uVar17 >> 0x15) & 3);
    fVar24 = fVar24 - fVar26;
    uVar12 = uVar17 & 0xfffffff | (uint)(DAT_0036a908 == fVar24) << 0x1e |
             (uint)(fVar24 <= DAT_0036a908) << 0x1d;
    bVar1 = (byte)(uVar12 >> 0x18);
    bVar14 = (bool)(bVar1 >> 6);
    bVar15 = (bool)(bVar1 >> 5 & 1);
    if (!bVar15 || bVar14) {
      uVar12 = uVar17 & 0xfffffff | (uint)(fVar24 == DAT_0036a904) << 0x1e |
               (uint)(DAT_0036a904 <= fVar24) << 0x1d;
      bVar1 = (byte)(uVar12 >> 0x18);
      bVar14 = (bool)(bVar1 >> 6);
      bVar15 = (bool)(bVar1 >> 5 & 1);
    }
    if (bVar15 && !bVar14) {
      fVar24 = (float)VectorSignedToFloat(iVar5,(byte)(uVar12 >> 0x15) & 3);
      uVar12 = uVar12 & 0xfffffff;
      uVar17 = uVar12 | (uint)(fVar24 < fVar26) << 0x1f | (uint)(fVar24 == fVar26) << 0x1e;
      uVar16 = uVar17 | (uint)(NAN(fVar24) || NAN(fVar26)) << 0x1c;
      bVar1 = (byte)(uVar17 >> 0x18);
      iVar5 = (int)fVar26;
      fVar24 = (float)VectorSignedToFloat(iVar5,(byte)(uVar16 >> 0x15) & 3);
      if ((bool)(bVar1 >> 6 & 1) || bVar1 >> 7 != ((byte)(uVar16 >> 0x1c) & 1)) {
        uVar17 = uVar12 | (uint)(fVar24 == fVar26) << 0x1e;
        if ((!SUB41(uVar17 >> 0x1e,0)) &&
           (uVar17 = uVar12 | (uint)(fVar28 == fVar26) << 0x1e | (uint)(fVar26 <= fVar28) << 0x1d,
           bVar1 = (byte)(uVar17 >> 0x18), (bool)(bVar1 >> 5 & 1) && !(bool)(bVar1 >> 6))) {
          iVar5 = iVar5 + -1;
        }
      }
      else {
        uVar17 = uVar12 | (uint)(fVar24 == fVar26) << 0x1e;
        if ((!SUB41(uVar17 >> 0x1e,0)) &&
           (uVar17 = uVar12 | (uint)(fVar28 == fVar26) << 0x1e | (uint)(fVar26 <= fVar28) << 0x1d,
           bVar1 = (byte)(uVar17 >> 0x18), !(bool)(bVar1 >> 5 & 1) || (bool)(bVar1 >> 6))) {
          iVar5 = iVar5 + 1;
        }
      }
      uVar12 = 0;
      iVar3 = (int)ALBW_AS_U32(DAT_0036a914) + 0x80000000;
      uVar29 = DAT_0036a90c;
      uVar30 = DAT_0036a910;
      fVar24 = DAT_0036a904;
      do {
        iVar19 = (int)fVar26;
        iVar6 = (int)((ulonglong)((longlong)iVar13 * (longlong)iVar19) >> 0x20);
        iVar7 = (int)((ulonglong)((longlong)iVar13 * (longlong)iVar5) >> 0x20);
        iVar11 = iVar7 >> 2;
        iVar7 = iVar11 - (iVar7 >> 0x1f);
        iVar5 = iVar5 + iVar7 * -10;
        pcVar8 = (char *)(param_1 + 0x79);
        if (uVar12 < 4) {
          pcVar8 = pcVar8 + uVar12;
        }
        if (*pcVar8 == '\0') {
          if (iVar5 == 0) {
            piVar9 = (int *)(param_1 + 0x80);
            if (uVar12 < 4) {
              piVar9 = piVar9 + uVar12;
            }
            if (0x41000000 < *piVar9) {
              puVar10 = (undefined4 *)(param_1 + 0x80);
              if (uVar12 < 4) {
                puVar10 = puVar10 + uVar12;
              }
              *puVar10 = uVar29;
            }
          }
          else if (iVar5 == 9) {
            piVar9 = (int *)(param_1 + 0x80);
            if (uVar12 < 4) {
              piVar9 = piVar9 + uVar12;
            }
            if (*piVar9 < 0x40000000) {
              puVar10 = (undefined4 *)(param_1 + 0x80);
              if (uVar12 < 4) {
                puVar10 = puVar10 + uVar12;
              }
              *puVar10 = uVar30;
            }
          }
          pfVar4 = (float *)(param_1 + 0x80);
          if (uVar12 < 4) {
            pfVar4 = pfVar4 + uVar12;
          }
          fVar23 = *pfVar4;
          fVar21 = (float)VectorSignedToFloat(iVar5,(byte)(uVar17 >> 0x15) & 3);
          uVar16 = uVar17 & 0xfffffff;
          uVar22 = uVar16 | (uint)(fVar23 < fVar21) << 0x1f | (uint)(fVar23 == fVar21) << 0x1e |
                   (uint)(fVar21 <= fVar23) << 0x1d;
          uVar17 = uVar22 | (uint)(NAN(fVar23) || NAN(fVar21)) << 0x1c;
          bVar1 = (byte)(uVar22 >> 0x18);
          if ((bool)(bVar1 >> 5 & 1)) {
            if (!(bool)(bVar1 >> 6 & 1) && bVar1 >> 7 == ((byte)(uVar17 >> 0x1c) & 1)) {
              fVar25 = fVar23 - fVar27;
              uVar17 = uVar16 | (uint)(fVar25 == fVar21) << 0x1e | (uint)(fVar21 <= fVar25) << 0x1d;
              bVar1 = (byte)(uVar17 >> 0x18);
              if ((!(bool)(bVar1 >> 5 & 1) || (bool)(bVar1 >> 6)) ||
                 (uVar16 = uVar16 | (uint)(fVar25 < fVar23) << 0x1f |
                           (uint)(fVar25 == fVar23) << 0x1e,
                 uVar17 = uVar16 | (uint)(NAN(fVar25) || NAN(fVar23)) << 0x1c,
                 bVar1 = (byte)(uVar16 >> 0x18),
                 !(bool)(bVar1 >> 6 & 1) && bVar1 >> 7 == ((byte)(uVar17 >> 0x1c) & 1)))
              goto LAB_0036a8f4;
              goto LAB_0036a91c;
            }
          }
          else {
            fVar25 = fVar23 + fVar27;
            uVar17 = uVar16 | (uint)(fVar21 == fVar25) << 0x1e | (uint)(fVar25 <= fVar21) << 0x1d;
            bVar1 = (byte)(uVar17 >> 0x18);
            if ((!(bool)(bVar1 >> 5 & 1) || (bool)(bVar1 >> 6)) ||
               (uVar16 = uVar16 | (uint)(fVar23 < fVar25) << 0x1f | (uint)(fVar23 == fVar25) << 0x1e
               , uVar17 = uVar16 | (uint)(NAN(fVar23) || NAN(fVar25)) << 0x1c,
               bVar1 = (byte)(uVar16 >> 0x18),
               !(bool)(bVar1 >> 6 & 1) && bVar1 >> 7 == ((byte)(uVar17 >> 0x1c) & 1))) {
LAB_0036a8f4:
              *pfVar4 = fVar21;
            }
            else {
LAB_0036a91c:
              *pfVar4 = fVar25;
            }
          }
          pfVar4 = (float *)(param_1 + 0x80);
          if (uVar12 < 4) {
            pfVar4 = pfVar4 + uVar12;
          }
          fVar21 = (float)VectorSignedToFloat(iVar5,(byte)(uVar17 >> 0x15) & 3);
          if (((uint)ALBW_AS_U32(*pfVar4 - fVar21) <= (uint)ALBW_AS_U32(fVar18)) && ((int)ALBW_AS_U32(*pfVar4 - fVar21) <= iVar3))
          goto joined_r0x0036a95c;
        }
        else {
          pcVar8 = (char *)(param_1 + 0x79);
          if (uVar12 < 4) {
            pcVar8 = pcVar8 + uVar12;
          }
          if (*pcVar8 == '\x01') {
            fVar21 = (float)VectorSignedToFloat(iVar19,(byte)(uVar17 >> 0x15) & 3);
            pfVar4 = (float *)(param_1 + 0x80);
            if (uVar12 < 4) {
              pfVar4 = pfVar4 + uVar12;
            }
            fVar23 = (float)VectorSignedToFloat(iVar19 + ((iVar6 >> 2) - (iVar6 >> 0x1f)) * -10,
                                                (byte)(uVar17 >> 0x15) & 3);
            *pfVar4 = fVar23 + (fVar26 - fVar21);
          }
          else {
joined_r0x0036a95c:
            puVar10 = (undefined4 *)(param_1 + 0x80);
            if (uVar12 < 4) {
              puVar10 = (undefined4 *)(param_1 + 0x80 + uVar12 * 4);
            }
            uVar20 = ALBW_AS_U32(VectorSignedToFloat(iVar5,(byte)(uVar17 >> 0x15) & 3));
            *puVar10 = uVar20;
          }
        }
        pfVar4 = (float *)(param_1 + 0x80);
        if (uVar12 < 4) {
          pfVar4 = pfVar4 + uVar12;
        }
        fVar21 = *pfVar4;
        pfVar4 = (float *)(param_1 + 0x80);
        uVar22 = (uint)fVar21;
        fVar23 = (float)VectorSignedToFloat(uVar22,(byte)(uVar17 >> 0x15) & 3);
        uVar16 = uVar17 & 0xfffffff;
        uVar17 = uVar16 | (uint)(fVar23 == fVar21) << 0x1e | (uint)(fVar21 <= fVar23) << 0x1d;
        bVar1 = (byte)(uVar17 >> 0x18);
        bVar14 = (bool)(bVar1 >> 6);
        if (!bVar14) {
          uVar17 = uVar16 | (uint)(fVar28 == fVar21) << 0x1e | (uint)(fVar21 <= fVar28) << 0x1d;
          bVar1 = (byte)(uVar17 >> 0x18);
          bVar14 = (bool)(bVar1 >> 6);
        }
        if ((bool)(bVar1 >> 5 & 1) && !bVar14) {
          uVar22 = uVar22 - 1;
        }
        if (uVar12 < 4) {
          pfVar4 = pfVar4 + uVar12;
        }
        fVar21 = (float)VectorSignedToFloat(uVar22,(byte)(uVar17 >> 0x15) & 3);
        func_0034C4C0(*(int *)(param_1 + 0x60),uVar12,uVar22,*pfVar4 - fVar21);
        iVar6 = DAT_0036ab9c;
        fVar26 = fVar26 * fVar24;
        uVar12 = uVar12 + 1;
        iVar5 = iVar7;
      } while ((int)uVar12 < 4);
      local_d4 = local_cc;
      local_d0 = 0x20;
      uStack_ad = 0;
      local_cc[0] = 0;
      local_d8 = DAT_0036aba0;
      if (*(int *)(param_1 + 0x6c) < *(int *)(param_1 + 0x68)) {
        func_004994B0((int)&local_d8,s_SE_S_RUPEE_UP_0036aba4,uVar22,iVar11);
      }
      else {
        func_004994B0((int)&local_d8,s_SE_S_RUPEE_DOWN_0036abb4,uVar22,iVar11);
      }
      puVar2 = local_d4;
      if (*(char *)(param_1 + 0x79) != '\0') {
        local_48 = iVar6;
        local_44 = (uint *)&DAT_0036abc4;
        (**(code **)(local_d8 + 8))(&local_d8);
        iVar5 = 0;
        do {
          if (local_d4[iVar5] == '\0') {
            if (iVar5 < 0x40001) goto LAB_0036aabc;
            break;
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 < 0x40001);
        iVar5 = 0;
LAB_0036aabc:
        iVar13 = iVar5;
        if (iVar5 < 0) {
          iVar13 = 0;
        }
        (**(code **)(local_48 + 8))(&local_48);
        uVar12 = 0;
        do {
          if (*(char *)((int)local_44 + uVar12) == '\0') {
            if ((int)uVar12 < 0x40001) goto LAB_0036ab0c;
            break;
          }
          uVar12 = uVar12 + 1;
        } while ((int)uVar12 < 0x40001);
        uVar12 = 0;
LAB_0036ab0c:
        if (local_d0 - iVar13 <= (int)uVar12) {
          uVar12 = (local_d0 - iVar13) - 1;
        }
        if (0 < (int)uVar12) {
          (**(code **)(local_48 + 8))(&local_48);
          func_0010E3C4((uint *)(puVar2 + iVar13),local_44,uVar12);
          if (iVar5 < (int)(iVar13 + uVar12)) {
            puVar2[iVar13 + uVar12] = 0;
          }
        }
      }
      func_0010A464(auStack_a8);
      func_00533048(param_1,&local_d8,auStack_a8);
      func_0025B810((int)auStack_a8,0,DAT_0036abcc);
      *(undefined1 *)(param_1 + 0x90) = 1;
      func_0025B874(auStack_a8);
      return 0;
    }
  }
  func_0034C57C(*(int *)(param_1 + 0x60),iVar5);
  return 1;
}

