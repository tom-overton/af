#ifndef M_RANDOM_FIELD_H
#define M_RANDOM_FIELD_H

#include "ultra64.h"

#define RANDOM_FIELD_DIRECT_ERROR 100

typedef enum RandomFieldDirection {
  /* 0 */ RANDOM_FIELD_DIRECT_NORTH,
  /* 1 */ RANDOM_FIELD_DIRECT_WEST,
  /* 2 */ RANDOM_FIELD_DIRECT_SOUTH,
  /* 3 */ RANDOM_FIELD_DIRECT_EAST,

  /* 4 */ RANDOM_FIELD_DIRECT_NUM
} RandomFieldDirection;

typedef struct RandomFieldGate {
  /* 0x00 */ s32 ut0;
  /* 0x04 */ s32 ut1;
} RandomFieldGate;

#define mRF_BLOCKKIND_NONE (0 << 0)
#define mRF_BLOCKKIND_PLAYER (1 << 0) // Player houses
#define mRF_BLOCKKIND_SHOP (1 << 1)
#define mRF_BLOCKKIND_SHRINE (1 << 2)
#define mRF_BLOCKKIND_POLICE (1 << 3)
#define mRF_BLOCKKIND_POSTOFFICE (1 << 4)
#define mRF_BLOCKKIND_STATION (1 << 5)
#define mRF_BLOCKKIND_CLIFF (1 << 6)
#define mRF_BLOCKKIND_RIVER (1 << 7)
#define mRF_BLOCKKIND_WATERFALL (1 << 8)
#define mRF_BLOCKKIND_BRIDGE (1 << 9)
#define mRF_BLOCKKIND_RAILROAD (1 << 10)
#define mRF_BLOCKKIND_MARINE (1 << 11) // Beach
#define mRF_BLOCKKIND_BORDER (1 << 12)
#define mRF_BLOCKKIND_TUNNEL (1 << 13)
#define mRF_BLOCKKIND_SLOPE (1 << 14)
#define mRF_BLOCKKIND_POOL (1 << 15) // The large pond, not the small pools
#define mRF_BLOCKKIND_DUMP (1 << 16)
#define mRF_BLOCKKIND_RIVER0 (1 << 17) // Flows south
#define mRF_BLOCKKIND_RIVER1 (1 << 18) // Flows east
#define mRF_BLOCKKIND_RIVER2 (1 << 19) // Flows west
#define mRF_BLOCKKIND_RIVER3 (1 << 20) // Flows south then east
#define mRF_BLOCKKIND_RIVER4 (1 << 21) // Flows east then south
#define mRF_BLOCKKIND_RIVER5 (1 << 22) // Flows south then west
#define mRF_BLOCKKIND_RIVER6 (1 << 23) // Flows west then south
#define mRF_BLOCKKIND_CLIFF0 (1 << 24) // Cliff that goes horizontally in an arc across entire block
#define mRF_BLOCKKIND_CLIFF1 (1 << 25) // Bottom part of cliff which juts out, valley on right
#define mRF_BLOCKKIND_CLIFF2 (1 << 26) // Cliff that goes vertically across entire block, valley on right
#define mRF_BLOCKKIND_CLIFF3 (1 << 27) // Top part of cliff which juts out, valley on right
#define mRF_BLOCKKIND_CLIFF4 (1 << 28) // Top part of cliff which juts out, valley on left
#define mRF_BLOCKKIND_CLIFF5 (1 << 29) // Cliff that goes vertically across entire block, valley on left
#define mRF_BLOCKKIND_CLIFF6 (1 << 30) // Bottom part of cliff that juts out, valley on left
#define mRF_BLOCKKIND_31 (1 << 31) // Not used in `mRF_block_info`

// void func_800BCBA0_jp();
// void func_800BCBDC_jp();
// void func_800BCC20_jp();
// void func_800BCC30_jp();
// void func_800BCC40_jp();
// void func_800BCCFC_jp();
s32 mRF_Type2BlockInfo(u8 type);
// void func_800BCDFC_jp();
// void func_800BCE80_jp();
// void func_800BCEA4_jp();
// void func_800BCF64_jp();
// void func_800BCFA4_jp();
RandomFieldGate* mRF_BlockTypeDirect2GateData(s32*, u8, s32);
// void func_800BD02C_jp();
// void func_800BD1E4_jp();

#endif
