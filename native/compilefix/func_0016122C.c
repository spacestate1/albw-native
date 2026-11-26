/* compilefix: USA 0016122C, the converted stage-2 text with y and z of the returned direction
 * (a vector returned in s0..s2 on ARM: BOOT_LOG 178). */
#include "ghidra_types.h"

extern int func_00111A64(uint *param_1);
extern int func_00115C54(float *param_1,float *param_2,float *param_3);
extern int func_0015B580(int param_1,uint param_2);
extern int func_0015B650(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);
extern int func_0015FB88(int param_1,int param_2);
extern int func_00160430(int param_1,undefined1 param_2);
extern int func_00160484(undefined4 *param_1);
extern int func_00161178(undefined4 *param_1);
extern float func_0032EF0C(float *param_1,float *param_2);
extern int func_004F8964(float *param_1,int param_2,float fparam_0);
extern float func_004F898C(void);
extern int func_00520FC0(void);
extern int func_00520FD4(void);
extern int func_00521F10(int param_1,float *param_2);
extern int func_0054FA10(int param_1,uint param_2);
extern int func_0054FBC4(int param_1,float *param_2,float *param_3);
extern int func_005500FC(float *param_1,float *param_2,int param_3);
extern int func_0058A7D4(void);
extern int func_0065836C(undefined4 *param_1,undefined1 param_2);
extern int *DAT_00161688;
extern int DAT_0016168c;
extern float DAT_00161690;
extern float DAT_00161694;
extern int DAT_00161698;
extern int *DAT_0016169c;

float *albw_s012_get(void);   /* s0..s2 of a returned vector (native/runtime/vec3ret.c) */

// USA 0016122C <- EU 00161230 (Ghidra, non-matching)
// GLOBAL DAT_00161688 int *
// GLOBAL DAT_0016168c int
// GLOBAL DAT_00161690 float
// GLOBAL DAT_00161694 float
// GLOBAL DAT_00161698 int
// GLOBAL DAT_0016169c int *

undefined4 func_0016122C(undefined4 *param_1)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  float *pfVar7;
  uint *puVar8;
  undefined4 *puVar9;
  undefined4 extraout_r1;
  undefined1 uVar10;
  uint in_fpscr;
  float fVar11;
  float in_s2;
  _Alignas(8) unsigned char albw_frame[0x70];
  #define local_68 (*(float *)(albw_frame + 0x8))
  #define uStack_64 (*(undefined4 *)(albw_frame + 0xc))
  #define local_60 (*(float *)(albw_frame + 0x10))
  #define local_5c (*(float *)(albw_frame + 0x14))
  #define uStack_58 (*(undefined4 *)(albw_frame + 0x18))
  #define uStack_54 (*(undefined4 *)(albw_frame + 0x1c))
  #define local_50 (*(float *)(albw_frame + 0x20))
  #define local_44 (*(float *)(albw_frame + 0x2c))
  #define local_40 (*(float *)(albw_frame + 0x30))
  #define uStack_3c (*(undefined4 *)(albw_frame + 0x34))
  #define uStack_38 (*(undefined4 *)(albw_frame + 0x38))
  #define local_34 (*(float *)(albw_frame + 0x3c))
  #define fStack_30 (*(float *)(albw_frame + 0x40))
  #define local_2c (*(float *)(albw_frame + 0x44))
  #define local_28 (*(float *)(albw_frame + 0x48))
  #define uStack_24 (*(undefined4 *)(albw_frame + 0x4c))
  #define uStack_20 (*(undefined4 *)(albw_frame + 0x50))
  iVar3 = *DAT_00161688;
  iVar4 = 0;
  if (iVar3 != 0) {
    iVar4 = *(int *)(iVar3 + 0x44);
  }
  if (iVar3 != 0 && iVar4 != 0) {
    return 0;
  }
  uVar5 = (int)*(short *)((int)param_1 + 0x2e) & 0xff;
  if (((uVar5 < 4) && (1 < uVar5)) && (-1 < (int)(uVar5 - 2))) {
    return 0;
  }
  if (-1 < (int)param_1[0x3e6]) {
    puVar6 = func_00161178(param_1);
    if ((puVar6 != (undefined4 *)0x0) && (*(char *)(puVar6 + 0x230) != '\x16')) {
      func_0065836C(puVar6 + 0x22f,4);
    }
    func_00160430((int)param_1,4);
    param_1[0x3e6] = 0xffffffff;
    return 0;
  }
  if (((((int)*(short *)((int)param_1 + 0x2e) & 0xffU) != 0) &&
      (*(char *)(param_1 + 0x230) != '\x02')) &&
     (iVar4 = func_0015FB88((int)param_1,0x16), iVar4 != 0)) {
    puVar6 = func_00161178(param_1);
    if ((puVar6 == (undefined4 *)0x0) || (*(char *)(puVar6 + 0x230) == '\x16')) goto LAB_00161334;
    puVar6 = puVar6 + 0x22f;
LAB_00161330:
    func_0065836C(puVar6,4);
LAB_00161334:
    return func_00160430((int)param_1,4);
  }
  if (((*(ushort *)((int)param_1 + 0x2e) & 0xff) == 0) &&
     (iVar4 = func_00160484(param_1), iVar4 != 0)) {
    return 0;
  }
  uVar5 = func_0054FBC4((int)(param_1 + 0x26d),(float *)(param_1 + 0xf4),(float *)0x0);
  pfVar7 = (float *)func_0054FA10((int)(param_1 + 0x26d),uVar5);
  local_34 = *pfVar7;
  fStack_30 = pfVar7[1];
  local_2c = pfVar7[2];
  pfVar7 = (float *)(param_1 + 0xf4);
  func_00115C54(&local_28,pfVar7,&local_34);
  local_40 = local_28;
  uStack_3c = uStack_24;
  uStack_38 = uStack_20;
  local_68 = *pfVar7;
  uStack_64 = param_1[0xf5];
  local_60 = ALBW_AS_F32(param_1[0xf6]);
  local_5c = local_28;
  uStack_58 = uStack_24;
  uStack_54 = uStack_20;
  local_50 = func_0032EF0C(pfVar7,&local_40);
  *(float *)(albw_frame + 0x24) = albw_s012_get()[1];
  *(float *)(albw_frame + 0x28) = albw_s012_get()[2];
  in_s2 = albw_s012_get()[2];
  iVar4 = DAT_0016168c;
  fVar11 = -(local_50 * local_68) + -(in_s2 * local_60);
  local_44 = fVar11;
  pfVar7 = (float *)func_00520FC0();
  iVar3 = func_005500FC(&local_68,pfVar7,iVar4);
  iVar4 = func_0015B650(param_1,extraout_r1,iVar4,uStack_20);
  if (iVar4 != 0) {
    puVar8 = (uint *)func_0058A7D4();
    uVar5 = func_00111A64(puVar8);
    iVar4 = (int)((ulonglong)uVar5 * 0x1e >> 0x20) + 0x14;
    if (iVar4 == 0) {
      fVar11 = DAT_00161690;
    }
    param_1[0x23c] = iVar4;
    if (iVar4 == 0) {
      param_1[0x23d] = ALBW_AS_U32(fVar11);
    }
    else {
      fVar11 = (float)VectorUnsignedToFloat(iVar4,(byte)(in_fpscr >> 0x15) & 3);
      param_1[0x23d] = ALBW_AS_U32(DAT_00161694 / fVar11);
    }
    param_1[0x23b] = 0;
    goto code_r0x00161484;
  }
  if ((uint)param_1[0x23c] <= (uint)param_1[0x23b]) {
    puVar6 = param_1 + 0x22f;
    if ((*(ushort *)((int)param_1 + 0x2e) & 0xff) == 0) {
      uVar10 = 0xe;
      if (*(char *)(param_1 + 0x387) != '\0') {
        uVar10 = 0x10;
        *(undefined1 *)(param_1 + 0x387) = 0;
        goto LAB_00161580;
      }
      if (iVar3 == 0) {
        puVar8 = (uint *)func_0058A7D4();
        uVar5 = func_00111A64(puVar8);
        uVar5 = (uint)((ulonglong)uVar5 * 100 >> 0x20);
        if (uVar5 < 0x19) goto LAB_00161580;
        if (uVar5 < 0x4b) goto LAB_00161574;
      }
      else {
        puVar8 = (uint *)func_0058A7D4();
        uVar5 = func_00111A64(puVar8);
        uVar5 = (uint)((ulonglong)uVar5 * 100 >> 0x20);
        if (uVar5 < 0x3c) goto LAB_00161580;
        if (uVar5 < 0x50) {
LAB_00161574:
          uVar10 = 0xc;
          goto LAB_00161580;
        }
      }
      uVar10 = 0x10;
LAB_00161580:
      return func_0065836C(puVar6,uVar10);
    }
    if (*(char *)(param_1 + 0x246) == '\0') {
      iVar4 = func_0015FB88((int)param_1,3);
      if (iVar4 != 0) goto LAB_00161330;
    }
    else {
      iVar4 = func_0015FB88((int)param_1,3);
      if (iVar4 != 0) {
        bVar1 = func_00520FD4();
        if (!bVar1) {
          pfVar7 = (float *)func_00520FC0();
          puVar9 = func_00161178(param_1);
          cVar2 = func_00521F10((int)puVar9,pfVar7);
          if (cVar2 != '\0') {
LAB_001615ec:
            uVar10 = 0xe;
            goto LAB_00161620;
          }
          uVar5 = 0;
          do {
            puVar9 = func_0015B580((int)param_1,uVar5);
            if ((puVar9 != (undefined4 *)0x0) &&
               (cVar2 = func_00521F10((int)puVar9,pfVar7), cVar2 != '\0')) goto LAB_001615ec;
            uVar5 = uVar5 + 1;
          } while (uVar5 < 2);
        }
        puVar8 = (uint *)func_0058A7D4();
        uVar5 = func_00111A64(puVar8);
        uVar10 = (undefined1)*(undefined4 *)(DAT_00161698 + (int)((ulonglong)uVar5 * 2 >> 0x20) * 4)
        ;
LAB_00161620:
        *(byte *)((int)param_1 + 0x91a) = (byte)*(undefined4 *)(*DAT_0016169c + 0x10) & 1;
        func_0065836C(puVar6,uVar10);
        return func_00160430((int)param_1,uVar10);
      }
    }
  }
  if ((uint)param_1[0x23b] < (uint)param_1[0x23c]) {
    param_1[0x23b] = param_1[0x23b] + 1;
  }
code_r0x00161484:
  fVar11 = func_004F898C();
  return func_004F8964((float *)(param_1 + 0xf8),1,fVar11);
}

