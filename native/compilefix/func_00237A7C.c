/* compilefix: USA 00237A7C, the converted stage-2 text with the animation request of 0016898C restored
 * (BOOT_LOG 172: lost stack stores): EU 237C68..237CCC (the grass holes) */
#include "ghidra_types.h"

extern int func_0010983C(undefined4 param_1,undefined4 param_2);
extern int func_0010B380(undefined4 *param_1,int param_2,int *param_3,undefined4 param_4);
extern int func_0010DB90(void);
extern int func_0014DF18(int param_1,undefined4 param_2,int param_3,uint param_4,undefined1 param_5, undefined1 param_6);
extern int func_0014E904(int param_1,int param_2,int param_3);
extern int func_0016898C(int param_1,uint *param_2);
extern int func_00168E9C(int *param_1,int param_2,int *param_3);
extern int func_00169608(uint *param_1,uint param_2,int *param_3,int param_4);
extern int func_0016A02C(int param_1,int param_2,int *param_3,int param_4);
extern int func_0036D0C8(int *param_1,int param_2);
extern int func_004CEAF0(int param_1);
extern int func_004D7EB0(float *param_1,uint param_2,uint param_3,float *param_4);
extern undefined4 *DAT_00237d88;
extern undefined4 DAT_00237d8c;
extern undefined4 DAT_00237d90;
extern undefined4 DAT_00237d94;
extern int DAT_00237d98;
extern char s_GrassHole_00237d9c[];

// USA 00237A7C <- EU 00237A7C (Ghidra, non-matching)
// GLOBAL DAT_00237d88 undefined4 *
// GLOBAL DAT_00237d8c undefined4
// GLOBAL DAT_00237d90 undefined4
// GLOBAL DAT_00237d94 undefined4
// GLOBAL DAT_00237d98 int
// GLOBAL s_GrassHole_00237d9c string

undefined4 func_00237A7C(int param_1)

{
  _Alignas(8) unsigned char albw_frame[0xb0]; /* entry_sp - 0xb0 .. entry_sp + 0x0 */
#define stack0xffffff58 (*(undefined4 *)(albw_frame + 0x8))
  int iVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  int *piVar9;
  int *piVar10;
  uint in_fpscr;
  float fVar11;
  #define local_4c (*(int *)(albw_frame + 0x64))
  #define local_40 (*(int *)(albw_frame + 0x70))
  #define local_3c (*(char * *)(albw_frame + 0x74))
  #define local_38 (*(int *)(albw_frame + 0x78))
  if (*(int *)(param_1 + 0x478) < 1) {
    return 0;
  }
  func_0010B380((undefined4 *)(param_1 + 0x64c),*(int *)(param_1 + 0x478),(int *)0x0,4);
  piVar2 = (int *)func_0010DB90();
  func_0036D0C8((int *)(param_1 + 0x680),0);
  if (*(int *)(param_1 + 0x680) == 0) {
    local_4c = 1;
  }
  else {
    local_4c = func_0010983C(*DAT_00237d88,*(int *)(param_1 + 0x680));
  }
  iVar1 = DAT_00237d98;
  piVar9 = *(int **)(param_1 + 0x480);
  uVar8 = 0xffffffff;
  piVar3 = piVar9 + *(int *)(param_1 + 0x478);
  if (piVar9 != piVar3) {
    piVar10 = (int *)(param_1 + 0x658);
    do {
      uVar8 = uVar8 + 1;
      uVar4 = (**(code **)(*piVar2 + 0x3c))(piVar2,4);
      if (uVar4 < 0x400) break;
      piVar5 = func_0014DF18(*(int *)(param_1 + 0x2d0),1,1,0,0,0);
      if (piVar5 != (int *)0x0) {
        iVar6 = *piVar9;
        piVar5[0x59] = piVar5[0x59] | 0x40000000;
        func_004D7EB0((float *)(piVar5 + 0x20),*(uint *)(iVar6 + 0x1c),*(uint *)(iVar6 + 0x20),
                      (float *)(iVar6 + 4));
        iVar6 = *piVar9;
        piVar5[0x59] = piVar5[0x59] | 0x40000000;
        piVar5[0x1d] = *(int *)(iVar6 + 0x10);
        piVar5[0x1e] = *(int *)(iVar6 + 0x14);
        piVar5[0x1f] = *(int *)(iVar6 + 0x18);
        func_004CEAF0((int)piVar5);
        (**(code **)(*piVar5 + 0x10))(piVar5,0x24);
        local_38 = *(int *)(*(int *)(param_1 + 0x2d0) + 0x1cc);
        iVar6 = func_0014E904(param_1,1,0);
        piVar7 = piVar10;
        if (uVar8 < 10) {
          piVar7 = piVar10 + uVar8;
        }
        *piVar7 = iVar6;
        iVar6 = (int)*(short *)(*piVar9 + 0x2e);
        local_40 = iVar1;
        if (1 < iVar6) {
          iVar6 = 0;
        }
        local_3c = s_GrassHole_00237d9c;
        piVar7 = piVar10;
        if (uVar8 < 10) {
          piVar7 = piVar10 + uVar8;
        }
        func_00169608((uint *)*piVar7,0,&local_40,local_38);
        piVar7 = piVar10;
        if (uVar8 < 10) {
          piVar7 = piVar10 + uVar8;
        }
        func_0016A02C(*piVar7,-1,(int *)0xffffffff,0);
        piVar7 = piVar10;
        if (uVar8 < 10) {
          piVar7 = piVar10 + uVar8;
        }

  /* request {count 1, capacity 3, entries -> +0xC}; entry {anim 0, 0.0, 1.0, -1.0, 1.0, flag -1}; +0x54 = 10, +0x58 = 0 */
  {
    uint32_t *rq = (uint32_t *)&stack0xffffff58;
    rq[0] = 1; rq[1] = 3; rq[2] = (uint32_t)(uintptr_t)(rq + 3); rq[3] = 0;
    rq[4] = 0x00000000u; rq[5] = 0x3F800000u; rq[6] = 0xBF800000u; rq[7] = 0x3F800000u;
    *(uint8_t *)(rq + 8) = 0xFF; rq[0x15] = 10; *(uint8_t *)(rq + 0x16) = 0;
  }
        func_0016898C(*piVar7,(uint *)&stack0xffffff58);
        piVar7 = piVar10;
        if (uVar8 < 10) {
          piVar7 = piVar10 + uVar8;
        }
        fVar11 = (float)VectorSignedToFloat(iVar6,(byte)(in_fpscr >> 0x15) & 3);
        iVar6 = *(int *)(*piVar7 + 0x14);
        in_fpscr = in_fpscr & 0xfffffff | (uint)(*(float *)(iVar6 + 8) == fVar11) << 0x1e;
        if (!SUB41(in_fpscr >> 0x1e,0)) {
          *(float *)(iVar6 + 8) = fVar11;
          *(undefined1 *)(iVar6 + 0x26) = 1;
        }
        piVar7 = piVar10;
        if (uVar8 < 10) {
          piVar7 = piVar10 + uVar8;
        }
        func_00168E9C((int *)*piVar7,(int)piVar5,(int *)0x0);
        if (*(int *)(param_1 + 0x64c) < *(int *)(param_1 + 0x650)) {
          *(int **)(*(int *)(param_1 + 0x654) + *(int *)(param_1 + 0x64c) * 4) = piVar5;
          *(int *)(param_1 + 0x64c) = *(int *)(param_1 + 0x64c) + 1;
        }
      }
      piVar9 = piVar9 + 1;
    } while (piVar9 != piVar3);
  }
  if (local_4c != 1) {
    return func_0010983C(*DAT_00237d88,local_4c);
  }
  return 0;
}

