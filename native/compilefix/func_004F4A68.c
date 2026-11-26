/* compilefix: USA 004F4A68, the converted stage-2 text with y and z of the returned vector
 * (a vector returned in s0..s2 on ARM: BOOT_LOG 178). */
#include "ghidra_types.h"

extern int func_00100174(int *param_1);
extern float func_00115DC8(float *param_1);
extern int func_0014D9D8(int param_1,uint *param_2,int param_3);
extern int func_0035227C(int param_1,undefined4 param_2);
extern int func_00521018(int param_1);
extern int func_0052FBA0(int param_1,uint param_2);
extern float func_005445F8(int param_1);
extern int func_00588BE4(int param_1);
extern int func_005895C4(ushort *param_1,int param_2,int param_3);
extern uint DAT_004f4ea4;
extern int DAT_004f4ea8;
extern float DAT_004f4eac;
extern int *DAT_004f4eb0;
extern int *DAT_004f4eb4;
extern int *DAT_004f4eb8;
extern undefined4 DAT_004f4ebc;
extern uint *DAT_004f4ec0;
extern undefined4 *DAT_004f4ec4;
extern uint *DAT_004f4ec8;
extern undefined4 *DAT_004f4ecc;
extern float DAT_004f4ed0;
extern int DAT_004f4ed4;
extern int DAT_004f4fd4;
extern int DAT_004f4fd8;
extern uint DAT_004f4fdc;

float *albw_s012_get(void);   /* s0..s2 of a returned vector (native/runtime/vec3ret.c) */

// USA 004F4A68 <- EU 004F4A40 (Ghidra, non-matching)
// GLOBAL DAT_004f4ea4 uint
// GLOBAL DAT_004f4ea8 int
// GLOBAL DAT_004f4eac float
// GLOBAL DAT_004f4eb0 int *
// GLOBAL DAT_004f4eb4 int *
// GLOBAL DAT_004f4eb8 int *
// GLOBAL DAT_004f4ebc undefined4
// GLOBAL DAT_004f4ec0 uint *
// GLOBAL DAT_004f4ec4 undefined4 *
// GLOBAL DAT_004f4ec8 uint *
// GLOBAL DAT_004f4ecc undefined4 *
// GLOBAL DAT_004f4ed0 float
// GLOBAL DAT_004f4ed4 int
// GLOBAL DAT_004f4fd4 int
// GLOBAL DAT_004f4fd8 int
// GLOBAL DAT_004f4fdc uint

undefined4 func_004F4A68(int param_1,int param_2)

{
  bool bVar1;
  int *piVar2;
  undefined4 uVar3;
  bool bVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  float fVar11;
  float in_s1;
  float in_s2;
  
  bVar4 = DAT_004f4ea4 < *(uint *)(param_2 + 8);
  if ((*(uint *)(param_1 + 0x5a0) & 0x1000000) == 0) {
    if (bVar4) goto LAB_004f4a80;
  }
  else {
    if (!bVar4) {
      return 0;
    }
LAB_004f4a80:
    *(uint *)(param_1 + 0x5a0) = *(uint *)(param_1 + 0x5a0) | 0x800000;
  }
  uVar10 = *(ushort *)(param_2 + 0x20) & 0x1f;
  uVar8 = (*(ushort *)(param_2 + 0x20) & 0x7e0) >> 5;
  if (((*(char *)(param_1 + 0x8b6) == '\0') || (uVar8 != 0x13)) || (uVar10 != 4)) {
    func_0035227C(param_1 + 0x324,uVar8);
    if ((uVar10 == 6) && (uVar8 == 0xf || uVar8 == 0x18)) {
      bVar4 = func_00521018(param_1);
      func_0014D9D8(param_1,(uint *)(param_1 + 0x39c),param_2);
      if (bVar4) {
        return 1;
      }
      bVar4 = func_00521018(param_1);
      if (!bVar4) {
        return 1;
      }
      *(undefined4 *)(param_1 + 0x590) = *(undefined4 *)(param_2 + 4);
      *(undefined4 *)(param_1 + 0x594) = *(undefined4 *)(param_2 + 8);
      *(undefined4 *)(param_1 + 0x598) = *(undefined4 *)(param_2 + 0xc);
      func_00115DC8((float *)(param_1 + 0x590));
      return 1;
    }
  }
  else {
    if (*(char *)(param_1 + 0x7fc) == '\x02') {
      return 0;
    }
    func_0035227C(param_1 + 0x324,0x13);
  }
  piVar2 = DAT_004f4eb0;
  if (*(char *)(param_1 + 0x8b4) != '\0' && uVar10 != 6) {
    bVar4 = DAT_004f4ea8 == *(int *)(param_2 + 8);
    if (DAT_004f4ea8 <= *(int *)(param_2 + 8)) {
      bVar4 = *(char *)(param_1 + 0x848) == '\0';
    }
    if (((bVar4) && (*(char *)(param_1 + 0x7fc) != '\x02')) &&
       (((*(uint *)(param_1 + 0x5a4) & 0x400000) != 0 &&
        ((0x3f000000 < *(int *)(param_1 + 0x4c8) &&
         (in_s1 = *(float *)(param_2 + 0x14), in_s2 = DAT_004f4eac,
         *(float *)(param_1 + 0x36c) + DAT_004f4eac <= in_s1)))))) {
      return 0;
    }
  }
  if ((((*(char *)(param_1 + 0x849) != '\0') &&
       (iVar5 = func_0052FBA0(*DAT_004f4eb0 + 0x3dbbc,*(uint *)(param_2 + 0x28)), iVar5 != 0)) &&
      (iVar5 = func_00588BE4(iVar5), iVar5 == *DAT_004f4eb4)) &&
     (*(char *)(param_1 + 0x7fc) != '\x05')) {
    return 0;
  }
  if (((*(uint *)(param_1 + 0x5a0) & 0x100) == 0 && (*(uint *)(param_1 + 0x5a0) & 0x400) == 0) &&
     (puVar6 = (undefined4 *)func_0052FBA0(*piVar2 + 0x3dbbc,*(uint *)(param_2 + 0x28)),
     puVar6 != (undefined4 *)0x0)) {
    iVar5 = func_00588BE4((int)puVar6);
    if (iVar5 == *DAT_004f4eb8) {
      fVar11 = func_005445F8(puVar6);
      in_s1 = albw_s012_get()[1];
      in_s2 = albw_s012_get()[2];
      *(float *)(param_1 + 0x7a8) = fVar11;
      *(float *)(param_1 + 0x7ac) = in_s1;
      *(float *)(param_1 + 0x7b0) = in_s2;
    }
    else {
      iVar5 = func_005895C4((ushort *)(param_2 + 0x20),param_2 + 4,0);
      uVar3 = DAT_004f4ebc;
      if (iVar5 != 0) {
        if ((*(uint *)(param_1 + 0x5a0) & 0x100) == 0) {
          if (((*DAT_004f4ec0 & 1) == 0) && (iVar5 = func_00100174((int *)DAT_004f4ec0), iVar5 != 0)
             ) {
            *DAT_004f4ec4 = uVar3;
          }
          iVar5 = (**(code **)*puVar6)(puVar6,DAT_004f4ec4);
          puVar7 = (undefined4 *)0x0;
          if (iVar5 != 0) {
            puVar7 = puVar6;
          }
          if (puVar7 != (undefined4 *)0x0) {
            *(uint *)(param_1 + 0x5a0) = *(uint *)(param_1 + 0x5a0) | 0x100;
            *(undefined4 *)(param_1 + 0x770) = puVar7[0xf4];
            *(undefined4 *)(param_1 + 0x774) = puVar7[0xf5];
            *(undefined4 *)(param_1 + 0x778) = puVar7[0xf6];
          }
        }
        if ((*(uint *)(param_1 + 0x5a0) & 0x400) == 0) {
          if (((*DAT_004f4ec8 & 1) == 0) && (iVar5 = func_00100174((int *)DAT_004f4ec8), iVar5 != 0)
             ) {
            *DAT_004f4ecc = uVar3;
          }
          iVar5 = (**(code **)*puVar6)(puVar6,DAT_004f4ecc);
          if (iVar5 != 0) {
            *(uint *)(param_1 + 0x5a0) = *(uint *)(param_1 + 0x5a0) | 0x400;
          }
        }
      }
    }
  }
  if (uVar8 == 6) {
    if (uVar10 != 7) {
LAB_004f4e28:
      uVar9 = (uint)*(ushort *)(param_2 + 0x20);
      uVar8 = (uVar9 & 0x7e0) >> 5;
      if ((uVar9 & 0x1f) == 6) {
        bVar4 = true;
        if (uVar8 == 0xf || uVar8 == 0x18) {
          bVar1 = true;
          goto LAB_004f4e50;
        }
      }
      else if (uVar8 == 0x12) {
        bVar4 = true;
      }
      else {
        bVar4 = false;
      }
      bVar1 = false;
LAB_004f4e50:
      if ((*(char *)(param_1 + 0x657) != '\0' && bVar4) && (!bVar1)) {
        *(undefined1 *)(param_1 + 0x89e) = 1;
        return 0;
      }
      if (((uVar10 != 6) || (*(int *)(param_2 + 8) <= DAT_004f4fd4)) &&
         ((*(uint *)(param_1 + 0x58c) & 1 << (uVar9 & 0x1f)) != 0 && uVar10 != 7)) {
        if ((-1 < (int)(*(uint *)(param_1 + 0x5a0) << 0xd)) &&
           ((uint)(*(int *)(param_2 + 8) - DAT_004f4fd8) < DAT_004f4fdc)) {
          *(uint *)(param_1 + 0x5a0) = *(uint *)(param_1 + 0x5a0) | 0x40000;
        }
        bVar4 = func_00521018(param_1);
        func_0014D9D8(param_1,(uint *)(param_1 + 0x39c),param_2);
        if ((!bVar4) && (bVar4 = func_00521018(param_1), bVar4)) {
          *(undefined4 *)(param_1 + 0x590) = *(undefined4 *)(param_2 + 4);
          *(undefined4 *)(param_1 + 0x594) = *(undefined4 *)(param_2 + 8);
          *(undefined4 *)(param_1 + 0x598) = *(undefined4 *)(param_2 + 0xc);
          func_00115DC8((float *)(param_1 + 0x590));
        }
        iVar5 = func_005895C4((ushort *)(param_2 + 0x20),param_2 + 4,0);
        if ((iVar5 != 0 && uVar10 != 10) && uVar10 != 0xb) {
          *(uint *)(param_1 + 0x5a0) = *(uint *)(param_1 + 0x5a0) | 0x400000;
        }
        return 1;
      }
      return 0;
    }
    fVar11 = *(float *)(param_2 + 8);
    if (fVar11 <= DAT_004f4ed0) {
      fVar11 = -fVar11;
    }
    if ((int)ALBW_AS_U32(fVar11) <= DAT_004f4ed4) {
      return 0;
    }
    uVar8 = *(uint *)(param_1 + 0x5a0) | 4;
  }
  else if (uVar8 == 0xb) {
    fVar11 = *(float *)(param_2 + 8);
    if (fVar11 <= DAT_004f4ed0) {
      fVar11 = -fVar11;
    }
    if ((int)ALBW_AS_U32(fVar11) <= DAT_004f4ed4) goto LAB_004f4de0;
    uVar8 = *(uint *)(param_1 + 0x5a0) | 0x20;
  }
  else {
    if (uVar8 != 0xc) goto LAB_004f4e28;
    fVar11 = *(float *)(param_2 + 8);
    if (fVar11 <= DAT_004f4ed0) {
      fVar11 = -fVar11;
    }
    if ((int)ALBW_AS_U32(fVar11) <= DAT_004f4ed4) {
      return 0;
    }
    if (uVar10 == 7) {
      uVar8 = *(uint *)(param_1 + 0x5a0) | 0x4000;
    }
    else {
      uVar8 = *(uint *)(param_1 + 0x5a0) | 0x8000;
    }
  }
  *(uint *)(param_1 + 0x5a0) = uVar8;
LAB_004f4de0:
  func_0014D9D8(param_1,(uint *)(param_1 + 0x39c),param_2);
  return 1;
}

