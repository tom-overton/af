#include "ac_dump.h"
#include "m_actor_dlftbls.h"
#include "m_object.h"
#include "overlays/gamestates/ovl_play/m_play.h"
#include "m_demo.h"
#include "m_player_lib.h"
#include "overlays/actors/player_actor/m_player.h"
#include "m_field_info.h"
#include "code_variables.h"
#include "m_rcp.h"
#include "macros.h"
#include "m_collision_bg.h"

#include "objects/object_00D5E000/obj_s_dump/obj_s_dump.h"
#include "objects/object_00D5E000/obj_w_dump/obj_w_dump.h"

#define THIS ((Dump*)thisx)

void aDUM_actor_ct(Actor* thisx, Game_Play* game_play);
void aDUM_actor_dt(Actor* thisx, Game_Play* game_play);
void aDUM_actor_init(Actor* thisx, Game_Play* game_play);
void aDUM_actor_draw(Actor* thisx, Game_Play* game_play);

ActorProfile Dump_Profile = {
    /* */ ACTOR_DUMP,
    /* */ ACTOR_PART_0,
    /* */ ACTOR_FLAG_10 | ACTOR_FLAG_20,
    /* */ 0x583A,
    /* */ GAMEPLAY_KEEP,
    /* */ sizeof(Dump),
    /* */ aDUM_actor_ct,
    /* */ aDUM_actor_dt,
    /* */ aDUM_actor_init,
    /* */ aDUM_actor_draw,
    /* */ NULL,
};

u8 aDUM_shadow_vtx_fix_flg_table[48] = {
    1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1,
    1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1,
};

extern Vtx obj_dump_shadow_v[];
extern Gfx obj_dump_shadowT_model[];

ShadowData aDUM_shadow_data = {
    48, aDUM_shadow_vtx_fix_flg_table, 60.0f, obj_dump_shadow_v, obj_dump_shadowT_model,
};

void aDUM_set_bgOffset(Dump* this, s32 arg1);
void aDUM_setup_action(Dump* this, s32 processIndex);

void aDUM_actor_ct(Actor* thisx, UNUSED Game_Play* game_play) {
    Dump* this = THIS;

    aDUM_set_bgOffset(this, 1);
    aDUM_setup_action(this, DUM_PROCESS_WAIT);
    this->structureActor.actor.world.pos.x -= 40.0f;
}

void aDUM_actor_dt(Actor* thisx, UNUSED Game_Play* game_play) {
    Dump* this = THIS;

    common_data.clip.structureClip->removeInstanceProc(common_data.clip.structureClip->objectSegmentTable,
                                                       ARRAY_COUNT(common_data.clip.structureClip->objectSegmentTable),
                                                       STRUCTURE_TYPE_DUMP, &this->structureActor.actor);
    common_data.clip.structureClip->removeInstanceProc(common_data.clip.structureClip->paletteSegmentTable,
                                                       ARRAY_COUNT(common_data.clip.structureClip->paletteSegmentTable),
                                                       STRUCTURE_PALETTE_DUMP, &this->structureActor.actor);
    common_data.clip.structureClip->removeInstanceProc(common_data.clip.structureClip->shadowSegmentTable,
                                                       ARRAY_COUNT(common_data.clip.structureClip->shadowSegmentTable),
                                                       STRUCTURE_TYPE_DUMP, &this->structureActor.actor);
    this->structureActor.actor.world.pos.x += 40.0f;
}

void aDUM_set_bgOffset_sub(Dump* this, s32 x, s32 z, s16 mode) {
    static s32 flag_tbl[6][6] = {
        { 1, 1, 0, 0, 1, 1 }, { 1, 0, 0, 0, 0, 1 }, { 1, 0, 0, 0, 0, 1 },
        { 1, 0, 0, 0, 0, 1 }, { 1, 0, 0, 0, 0, 1 }, { 1, 1, 1, 1, 1, 1 },
    };
    xyz_t pos;

    pos.x = this->structureActor.actor.home.pos.x - x * 40;
    pos.y = this->structureActor.actor.home.pos.y;
    pos.z = this->structureActor.actor.home.pos.z - z * 40;

    if (flag_tbl[z][x]) {
        mCoBG_SetPlussOffset(pos, mode, 100);
    }
}

void aDUM_set_bgOffset(Dump* this, s32 arg1) {
    s32 i;
    s16 mode = arg1 ? 4 : 4;

    for (i = 0; i < 6; i++) {
        aDUM_set_bgOffset_sub(this, 0, i, mode);
        aDUM_set_bgOffset_sub(this, 1, i, mode);
        aDUM_set_bgOffset_sub(this, 2, i, mode);
        aDUM_set_bgOffset_sub(this, 3, i, mode);
        aDUM_set_bgOffset_sub(this, 4, i, mode);
        aDUM_set_bgOffset_sub(this, 5, i, mode);
    }
}

void aDUM_set_talk_info(UNUSED Actor* thisx) {
    Color_RGBA8 color;

    mDemo_Set_msg_num(0x136A);
    mDemo_Set_talk_display_name(0);
    mDemo_Set_camera(1);
    mPlib_Set_able_hand_all_item_in_demo(1);
    mDemo_Set_ListenAble();
    color.r = 185;
    color.g = 60;
    color.b = 40;
    color.a = 255;
    mDemo_Set_talk_window_color(&color);
}

void aDUM_wait(Dump* this, Game_Play* game_play) {
    Player* player = get_player_actor_withoutCheck(game_play);
    xyz_t actorPos;
    s32 yaw;

    xyz_t_move(&actorPos, &this->structureActor.actor.world.pos);
    if ((mDemo_Check(7, &this->structureActor.actor) != 1) && (player != NULL) && (mDemo_Get_talk_actor() == NULL) &&
        (actorPos.z <= player->actor.world.pos.z)) {
        yaw = ABS(this->structureActor.actor.yawTowardsPlayer);

        if (yaw < 0x2000) {
            mDemo_Request(7, &this->structureActor.actor, aDUM_set_talk_info);
        }
    }
}

void aDUM_setup_action(Dump* this, s32 processIndex) {
    static DumpActionFunc process[] = { aDUM_wait };

    this->structureActor.process = process[processIndex];
    this->structureActor.unk_2B4 = processIndex;
}

void aDUM_actor_move(Actor* thisx, Game_Play* game_play) {
    UNUSED UNK_TYPE1 pad[0x4];
    Dump* this = THIS;
    Player* player = get_player_actor_withoutCheck(game_play);
    s32 xBlock;
    s32 zBlock;
    s32 playerXBlock;
    s32 playerZBlock;

    mFI_Wpos2BlockNum(&xBlock, &zBlock, this->structureActor.actor.world.pos);
    mFI_Wpos2BlockNum(&playerXBlock, &playerZBlock, player->actor.world.pos);
    if ((mDemo_Check(1, &player->actor) == 0) && (mDemo_Check(5, &player->actor) == 0) &&
        ((xBlock != playerXBlock) || (zBlock != playerZBlock))) {
        Actor_delete(&this->structureActor.actor);
    } else {
        ((DumpActionFunc)this->structureActor.process)(this, game_play);
    }
}

void aDUM_actor_init(Actor* thisx, Game_Play* game_play) {
    Dump* this = THIS;

    mFI_SetFG_common(0xF101, this->structureActor.actor.home.pos, 0);
    aDUM_actor_move(&this->structureActor.actor, game_play);
    this->structureActor.actor.update = aDUM_actor_move;
}

void aDUM_actor_draw(UNUSED Actor* thisx, Game_Play* game_play) {
    static Gfx* model[2] = {
        dump_s_DL_model,
        dump_w_DL_model,
    };

    GraphicsContext* gfxCtx = game_play->state.gfxCtx;
    s32 object;
    u16* palette;
    s32 type = (common_data.time.season == WINTER) ? 1 : 0;
    Mtx* mtx;

    object = common_data.clip.structureClip->getObjectSegment(STRUCTURE_TYPE_DUMP);
    palette = common_data.clip.structureClip->getPalSegment(STRUCTURE_PALETTE_DUMP);
    _texture_z_light_fog_prim_npc(gfxCtx);

    OPEN_POLY_OPA_DISP(gfxCtx);
    gSPSegment(__polyOpa++, 0x08, palette);
    SegmentBaseAddress[6] = (uintptr_t)OS_PHYSICAL_TO_K0(object);
    gSPSegment(__polyOpa++, 0x06, object);

    Matrix_translate(-6000.0f, 0.0f, -10000.0f, 1);
    mtx = _Matrix_to_Mtx_new(gfxCtx);
    if (mtx != NULL) {
        gSPMatrix(__polyOpa++, mtx, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(__polyOpa++, model[type]);
        CLOSE_POLY_OPA_DISP(gfxCtx);
    }
    common_data.clip.unk_074->unk_04(game_play, &aDUM_shadow_data, 40);
}
