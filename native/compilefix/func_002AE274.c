/* compilefix: USA 002AE274 (EU 002AE250), the converted stage-2 text.
 * Fixed (BOOT_LOG 184): the ARM copies this word between a float and an integer (no vcvt), which the
 * converted text wrote as a conversion of the value. */
#include "ghidra_types.h"

extern int func_00115C70(float *param_1,float *param_2,float *param_3);
extern int func_00115D70(float *param_1,float *param_2,float fparam_0);
extern float func_00115DC8(float *param_1);
extern int func_002ADFE4(int param_1,int param_2,undefined1 param_3,undefined4 param_4,int param_5);
extern int func_002AE780(int param_1);
extern int func_004F9728(int *param_1,undefined4 param_2,int param_3);
extern float func_004FB2F0(int param_1,float fparam_0);
extern int func_004FC78C(int param_1,undefined2 param_2);
extern float func_0058AA40(int param_1);
extern undefined8 func_0058AB74(int param_1);
extern float func_0058AC38(int param_1);
extern uint DAT_002ae42c;
extern int DAT_002ae430;
extern float DAT_002ae434;
extern float DAT_002ae438;

// USA 002AE274 <- EU 002AE250 (Ghidra, non-matching)
// GLOBAL DAT_002ae42c uint
// GLOBAL DAT_002ae430 int
// GLOBAL DAT_002ae434 float
// GLOBAL DAT_002ae438 float

/* WARNING: Variable defined which should be unmapped: objStack_30 */

void func_002AE274(int param_1)

{
  uint uVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  uint in_fpscr;
  float fVar5;
  float fparam_0;
  uint uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  _Alignas(8) unsigned char albw_frame[0x30];
  #define objStack_30 ((uint *)(albw_frame + 0x0))
  #define local_24 ((float *)(albw_frame + 0xc))
  #define local_1c (*(float *)(albw_frame + 0x14))
  func_002AE780(param_1);
  *(ushort *)(param_1 + 0x38) = *(ushort *)(param_1 + 0x38) & 0xfff7;
  *(uint *)(*(int *)(param_1 + 0x34) + 0x59c) =
       *(uint *)(*(int *)(param_1 + 0x34) + 0x59c) & 0xfffffff3;
  func_004FC78C(*(int *)(param_1 + 0x34),0);
  uVar6 = DAT_002ae42c;
  *(undefined1 *)(*(int *)(param_1 + 0x34) + 0x4dc) = 6;
  func_00115C70(local_24,(float *)(param_1 + 0x124),(float *)(*(int *)(param_1 + 0x34) + 0x3d0));
  objStack_30[0] = (uint)ALBW_AS_U32(local_24[0]);
  objStack_30[2] = (uint)ALBW_AS_U32(local_1c);
  objStack_30[1] = uVar6;
  if (DAT_002ae430 < (int)ALBW_AS_U32(SQRT(local_24[0] * local_24[0] + local_1c * local_1c))) {
    func_00115DC8((float *)objStack_30);
    func_00115D70((float *)objStack_30,(float *)objStack_30,DAT_002ae434);
  }
  *(uint *)(param_1 + 0x70) = objStack_30[0];
  *(uint *)(param_1 + 0x74) = uVar6;
  *(uint *)(param_1 + 0x78) = objStack_30[2];
  *(undefined4 *)(*(int *)(param_1 + 0x34) + 0x574) =
       *(undefined4 *)(*(int *)(param_1 + 0x34) + 0x898);
  uVar1 = *(uint *)(*(int *)(param_1 + 0x34) + 0x59c);
  *(uint *)(*(int *)(param_1 + 0x34) + 0x59c) = uVar1 & 0xfffffffb;
  *(uint *)(*(int *)(param_1 + 0x34) + 0x59c) = uVar1 & 0xfffffff3;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(uint *)(param_1 + 0x30) = uVar6;
  *(undefined4 *)(param_1 + 0x28) = 0;
  uVar7 = func_0058AB74(*(int *)(param_1 + 0x34));
  fVar5 = func_0058AA40(*(undefined4 *)(param_1 + 0x34));
  *(undefined1 *)(*(int *)(param_1 + 0x34) + 0x82a) = 0;
  objStack_30[0] = 0;
  func_002ADFE4(param_1,0x20,8,0,0);
  uVar8 = func_0058AB74(*(int *)(param_1 + 0x34));
  fparam_0 = func_0058AA40(*(undefined4 *)(param_1 + 0x34));
  bVar3 = *(char *)(*(int *)(param_1 + 0x34) + 0x82a) == '\0';
  bVar4 = (int)uVar7 == (int)uVar8;
  bVar2 = bVar3 && bVar4;
  if (bVar3 && bVar4) {
    in_fpscr = in_fpscr & 0xfffffff | (uint)(fVar5 == fparam_0) << 0x1e;
    bVar2 = SUB41(in_fpscr >> 0x1e,0);
  }
  if (!bVar2) {
    fVar5 = func_0058AC38(*(int *)(param_1 + 0x34));
    fparam_0 = ALBW_AS_F32(VectorFloatToUnsigned(fVar5,3));
    if ((uint)ALBW_AS_U32(*(float *)(param_1 + 0x2c)) < (uint)ALBW_AS_U32(fparam_0)) {
      *(float *)(param_1 + 0x2c) = fparam_0;
      if (fparam_0 == 0.0) {
        *(uint *)(param_1 + 0x30) = uVar6;
      }
      else {
        fparam_0 = (float)VectorUnsignedToFloat(ALBW_AS_U32(fparam_0),(byte)(in_fpscr >> 0x15) & 3);
        *(float *)(param_1 + 0x30) = DAT_002ae438 / fparam_0;
      }
      *(undefined4 *)(param_1 + 0x28) = 0;
      func_004F9728(*(int **)(param_1 + 0x34),6,(uint)*(byte *)(*(int **)(param_1 + 0x34) + 0x225));
      *(undefined1 *)(*(int *)(param_1 + 0x34) + 0x4dc) = 7;
    }
  }
  func_004FB2F0(*(int *)(param_1 + 0x34),fparam_0);
  return;
}

