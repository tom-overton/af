#ifndef M_PLAY_H
#define M_PLAY_H

#include "m_collision_obj.h"
#include "m_event.h"
#include "m_submenu.h"
#include "ultra64.h"
#include "game.h"
#include "gfx.h"
#include "m_actor.h"
#include "m_kankyo.h"
#include "PreRender.h"
#include "unknown_structs.h"
#include "sys_matrix.h"
#include "unk.h"
#include "m_common_data.h"
#include "m_lib.h"
#include "m_view.h"
#include "m_lights.h"
#include "m_collision_bg.h"
#include "m_pause.h"
#include "m_fbdemo_fade.h"
#include "m_fbdemo_wipe1.h"
#include "m_fbdemo_triforce.h"
#include "m_scene.h"
#include "683030.h"

struct Actor;
struct ActorEntry;
struct Game_Play;
struct SceneDmaStatus;

typedef void (*Game_Play_unk_1C58)(struct Actor*);
typedef UNK_RET (*Game_Play_unk_2208)(struct Actor*, struct Game_Play*);

typedef void (*FBDemoInitProc)(void*);
typedef void (*FBDemoDestroyProc)(void*, struct Game_Play*);
typedef void (*FBDemoMoveProc)(void*, u8);
typedef void (*FBDemoDrawProc)(void*, Gfx**);
typedef void (*FBDemoStartUpProc)(void*);
typedef void (*FBDemoSetTypeProc)(void*, s32);
typedef void (*FBDemoSetColorProc)(void*, u32);
typedef void (*FBDemoUnkProc)(void);
typedef s32 (*FBDemoIsFinishProc)(void*);

typedef struct Game_PlayfbDemoInfo {
    /* 0x00 */ FBDemoInitProc init;
    /* 0x04 */ FBDemoDestroyProc destroy;
    /* 0x08 */ FBDemoMoveProc move;
    /* 0x0C */ FBDemoDrawProc draw;
    /* 0x10 */ FBDemoStartUpProc startUp;
    /* 0x14 */ FBDemoSetTypeProc setType;
    /* 0x18 */ FBDemoSetColorProc setColor;
    /* 0x1C */ FBDemoUnkProc unk_1C;
    /* 0x20 */ FBDemoIsFinishProc isFinish;
} Game_PlayfbDemoInfo; // size = 0x24

typedef union Game_Play_FBDemo {
    fbDemoWipe1 wipe1;
    fbDemoTriforce triforce;
    fbDemoFade fade;
} Game_Play_FBDemo; // size = 0x218

typedef struct Game_Play_Unk_1EE8 {
    /* 0x000 */ Game_Play_FBDemo fbdemo;
    /* 0x218 */ s32 wipeType;
    /* 0x21C */ Game_PlayfbDemoInfo fbdemoInfo;
} Game_Play_Unk_1EE8; // size = 0x240

typedef struct Game_Play {
    /* 0x0000 */ Game state;
    /* 0x00E0 */ s16 unk_00E0;
    /* 0x00E2 */ UNK_TYPE1 unk_00E2[0x2];
    /* 0x00E4 */ s8 unk_00E4;
    /* 0x00E5 */ s8 unk_00E5;
    /* 0x00E6 */ UNK_TYPE1 unk_00E6[0x2];
    /* 0x00E8 */ UNK_TYPE1 unk_00E8[0x24];
    /* 0x010C */ void* unk_010C;
    /* 0x0110 */ ObjectExchangeBank objectExchangeBank;
    /* 0x1938 */ View view;
    /* 0x1A60 */ Camera2 camera;
    /* 0x1B98 */ Kankyo kankyo;
    /* 0x1C60 */ Global_light glight;
    /* 0x1C70 */ Pause pause;
    /* 0x1C78 */ ActorInfo actorInfo;
    /* 0x1CBC */ Submenu submenu;
    /* 0x1DAC */ s8 unk_1DAC;
    /* 0x1DAD */ UNK_TYPE1 unk_1DAD[0x3];
    /* 0x1DB0 */ u8* groundTexPtrs[2];
    /* 0x1DB8 */ u8* groundPalPtrs[2];
    /* 0x1DC0 */ PreRender unk_1DC0;
    /* 0x1E10 */ DoorInfo sceneDoorInfo;
    /* 0x1E18 */ s32 unk_1E18;
    /* 0x1E1C */ MtxF viewProjectionMtxF;
    /* 0x1E5C */ MtxF billboardMtxF;
    /* 0x1E9C */ Mtx* unk_1E9C;
    /* 0x1EA0 */ u32 unk_1EA0;
    /* 0x1EA4 */ UNK_TYPE1 unk_1EA4[0x1];
    /* 0x1EA5 */ u8 unk_1EA5;
    /* 0x1EA6 */ u8 unk_1EA6;
    /* 0x1EA7 */ u8 unk_1EA7;
    /* 0x1EA8 */ struct ActorEntry* unk_1EA8;
    /* 0x1EAC */ struct ActorEntry* unk_1EAC;
    /* 0x1EB0 */ s16* unk_1EB0;
    /* 0x1EB4 */ s16* unk_1EB4;
    /* 0x1EB8 */ s32 unk_1EB8;
    /* 0x1EBC */ Event event;
    /* 0x1ECC */ UNK_TYPE1 unk_1ECC[0x14];
    /* 0x1EE0 */ u8 unk_1EE0;
    /* 0x1EE1 */ u8 unk_1EE1;
    /* 0x1EE2 */ u8 unk_1EE2;
    /* 0x1EE3 */ u8 unk_1EE3;
    /* 0x1EE4 */ UNK_TYPE1 unk_1EE4[0x4];
    /* 0x1EE8 */ Game_Play_Unk_1EE8 unk_1EE8;
    /* 0x2128 */ fbDemoFade unk_2128;
    /* 0x2138 */ CollisionCheck unk_2138;
    /* 0x2208 */ Game_Play_unk_2208 unk_2208;
    /* 0x220C */ s32 unk_220C;
    /* 0x2210 */ struct SceneDmaStatus* unk_2210;
    /* 0x2214 */ UNK_TYPE1 unk_2214[0x1FC];
} Game_Play; // size = 0x2410

void play_init(Game* game);
void play_cleanup(Game* game);

#endif
