#ifndef M_NAME_TABLE_H
#define M_NAME_TABLE_H

#include "ultra64.h"
#include "m_collision_bg.h"

typedef struct NameTableOffsetTable {
    s32 type;
    mCoBG_unkStruct2 unk4;
} NameTableOffsetTable;

extern s16 move_obj_profile_table[];
extern s16 actor_profile_table[];
extern s16 props_profile_table[];
extern u8 npc_looks_table[];

s32 mNT_get_itemTableNo(u16 item);
u16 mNT_FishIdx2FishItemNo(s32 idx);
u16 bg_item_fg_sub(u16 item, s16 flag);
u16 bg_item_fg_sub_tree_grow(u16 item, s32 pastDays, s32 checkPlant);
u16 bg_item_fg_sub_dig2take_conv(u16 item);
NameTableOffsetTable* obj_hight_table_item0_nogrow(u16 item);

#define GET_NAME_ITEM_CATEGORY(f) (((f) & 0x0F00) >> 8)
#define GET_NAME_ITEM_TYPE(n) (((n) & 0xF000) >> 12)
#define GET_NAME_ITEM_INDEX(n) ((u16)(n) & 0xFF)

#define EMPTY_NO 0x0000

#define ITM_MONEY_START 0x2100
#define ITM_MONEY_1000 ITM_MONEY_START // 0x2100
#define ITM_MONEY_10000 (ITM_MONEY_1000 + 1) // 0x2101
#define ITM_MONEY_30000 (ITM_MONEY_10000 + 1) // 0x2102
#define ITM_MONEY_100 (ITM_MONEY_30000 + 1) // 0x2103
#define ITM_MONEY_END ITM_MONEY_100 // 0x2103

#define ITM_FOOD_START 0x2800
#define ITM_FOOD_APPLE ITM_FOOD_START
#define ITM_FOOD_CHERRY (ITM_FOOD_APPLE + 1)
#define ITM_FOOD_PEAR (ITM_FOOD_CHERRY + 1)
#define ITM_FOOD_PEACH (ITM_FOOD_PEAR + 1)
#define ITM_FOOD_ORANGE (ITM_FOOD_PEACH + 1)
#define ITM_FOOD_MUSHROOM (ITM_FOOD_ORANGE + 1)
#define ITM_FOOD_CANDY (ITM_FOOD_MUSHROOM + 1)
#define ITM_FOOD_COCONUT (ITM_FOOD_CANDY + 1)
#define ITM_FOOD_END 0x2808

/* begin environmental/nature objects */
#define ENV_START 0x0800
/* tree */
#define TREE_SAPLING ENV_START
#define TREE_S0 (TREE_SAPLING + 1)
#define TREE_S1 (TREE_S0 + 1)
#define TREE_S2 (TREE_S1 + 1)
#define TREE (TREE_S2 + 1) /* fully grown */
/* apple tree */
#define TREE_APPLE_SAPLING (TREE + 1)
#define TREE_APPLE_S0 (TREE_APPLE_SAPLING + 1)
#define TREE_APPLE_S1 (TREE_APPLE_S0 + 1)
#define TREE_APPLE_S2 (TREE_APPLE_S1 + 1)
#define TREE_APPLE_NOFRUIT_0 (TREE_APPLE_S2 + 1) /* fully grown, no fruit */
#define TREE_APPLE_NOFRUIT_1 (TREE_APPLE_NOFRUIT_0 + 1)
#define TREE_APPLE_NOFRUIT_2 (TREE_APPLE_NOFRUIT_1 + 1)
#define TREE_APPLE_FRUIT (TREE_APPLE_NOFRUIT_2 + 1)
/* orange tree */
#define TREE_ORANGE_SAPLING (TREE_APPLE_FRUIT + 1)
#define TREE_ORANGE_S0 (TREE_ORANGE_SAPLING + 1)
#define TREE_ORANGE_S1 (TREE_ORANGE_S0 + 1)
#define TREE_ORANGE_S2 (TREE_ORANGE_S1 + 1) /* fully grown, no fruit */
#define TREE_ORANGE_NOFRUIT_0 (TREE_ORANGE_S2 + 1)
#define TREE_ORANGE_NOFRUIT_1 (TREE_ORANGE_NOFRUIT_0 + 1)
#define TREE_ORANGE_NOFRUIT_2 (TREE_ORANGE_NOFRUIT_1 + 1)
#define TREE_ORANGE_FRUIT (TREE_ORANGE_NOFRUIT_2 + 1)
/* peach tree */
#define TREE_PEACH_SAPLING (TREE_ORANGE_FRUIT + 1)
#define TREE_PEACH_S0 (TREE_PEACH_SAPLING + 1)
#define TREE_PEACH_S1 (TREE_PEACH_S0 + 1)
#define TREE_PEACH_S2 (TREE_PEACH_S1 + 1)
#define TREE_PEACH_NOFRUIT_0 (TREE_PEACH_S2 + 1) /* fully grown, no fruit */
#define TREE_PEACH_NOFRUIT_1 (TREE_PEACH_NOFRUIT_0 + 1)
#define TREE_PEACH_NOFRUIT_2 (TREE_PEACH_NOFRUIT_1 + 1)
#define TREE_PEACH_FRUIT (TREE_PEACH_NOFRUIT_2 + 1)
/* pear tree */
#define TREE_PEAR_SAPLING (TREE_PEACH_FRUIT + 1)
#define TREE_PEAR_S0 (TREE_PEAR_SAPLING + 1)
#define TREE_PEAR_S1 (TREE_PEAR_S0 + 1)
#define TREE_PEAR_S2 (TREE_PEAR_S1 + 1)
#define TREE_PEAR_NOFRUIT_0 (TREE_PEAR_S2 + 1) /* fully grown, no fruit */
#define TREE_PEAR_NOFRUIT_1 (TREE_PEAR_NOFRUIT_0 + 1)
#define TREE_PEAR_NOFRUIT_2 (TREE_PEAR_NOFRUIT_1 + 1)
#define TREE_PEAR_FRUIT (TREE_PEAR_NOFRUIT_2 + 1)
/* cherry tree */
#define TREE_CHERRY_SAPLING (TREE_PEAR_FRUIT + 1)
#define TREE_CHERRY_S0 (TREE_CHERRY_SAPLING + 1)
#define TREE_CHERRY_S1 (TREE_CHERRY_S0 + 1)
#define TREE_CHERRY_S2 (TREE_CHERRY_S1 + 1)
#define TREE_CHERRY_NOFRUIT_0 (TREE_CHERRY_S2 + 1) /* fully grown, no fruit */
#define TREE_CHERRY_NOFRUIT_1 (TREE_CHERRY_NOFRUIT_0 + 1)
#define TREE_CHERRY_NOFRUIT_2 (TREE_CHERRY_NOFRUIT_1 + 1)
#define TREE_CHERRY_FRUIT (TREE_CHERRY_NOFRUIT_2 + 1)
/* money tree (1,000 Bells) */
#define TREE_1000BELLS_SAPLING (TREE_CHERRY_FRUIT + 1)
#define TREE_1000BELLS_S0 (TREE_1000BELLS_SAPLING + 1)
#define TREE_1000BELLS_S1 (TREE_1000BELLS_S0 + 1)
#define TREE_1000BELLS_S2 (TREE_1000BELLS_S1 + 1)
#define TREE_1000BELLS (TREE_1000BELLS_S2 + 1) /* fully grown w/ bells */
/* money tree (10,000 Bells) */
#define TREE_10000BELLS_SAPLING (TREE_1000BELLS + 1)
#define TREE_10000BELLS_S0 (TREE_10000BELLS_SAPLING + 1)
#define TREE_10000BELLS_S1 (TREE_10000BELLS_S0 + 1)
#define TREE_10000BELLS_S2 (TREE_10000BELLS_S1 + 1)
#define TREE_10000BELLS (TREE_10000BELLS_S2 + 1) /* fully grown w/ bells */
/* money tree (30,000 Bells) */
#define TREE_30000BELLS_SAPLING (TREE_10000BELLS + 1)
#define TREE_30000BELLS_S0 (TREE_30000BELLS_SAPLING + 1)
#define TREE_30000BELLS_S1 (TREE_30000BELLS_S0 + 1)
#define TREE_30000BELLS_S2 (TREE_30000BELLS_S1 + 1)
#define TREE_30000BELLS (TREE_30000BELLS_S2 + 1) /* fully grown w/ bells */
/* flower leaves (unused growth stage) */
#define FLOWER_LEAVES_PANSIES0 (TREE_30000BELLS + 1) /* white */
#define FLOWER_LEAVES_PANSIES1 (FLOWER_LEAVES_PANSIES0 + 1) /* purple */
#define FLOWER_LEAVES_PANSIES2 (FLOWER_LEAVES_PANSIES1 + 1) /* yellow */
#define FLOWER_LEAVES_COSMOS0 (FLOWER_LEAVES_PANSIES2 + 1) /* yellow */
#define FLOWER_LEAVES_COSMOS1 (FLOWER_LEAVES_COSMOS0 + 1) /* purple */
#define FLOWER_LEAVES_COSMOS2 (FLOWER_LEAVES_COSMOS1 + 1) /* blue */
#define FLOWER_LEAVES_TULIP0 (FLOWER_LEAVES_COSMOS2 + 1) /* red */
#define FLOWER_LEAVES_TULIP1 (FLOWER_LEAVES_TULIP0 + 1) /* white */
#define FLOWER_LEAVES_TULIP2 (FLOWER_LEAVES_TULIP1 + 1) /* yellow */
/* flowers */
#define FLOWER_PANSIES0 (FLOWER_LEAVES_TULIP2 + 1) /* white */
#define FLOWER_PANSIES1 (FLOWER_PANSIES0 + 1) /* purple */
#define FLOWER_PANSIES2 (FLOWER_PANSIES1 + 1) /* yellow */
#define FLOWER_COSMOS0 (FLOWER_PANSIES2 + 1) /* yellow */
#define FLOWER_COSMOS1 (FLOWER_COSMOS0 + 1) /* purple */
#define FLOWER_COSMOS2 (FLOWER_COSMOS1 + 1) /* blue */
#define FLOWER_TULIP0 (FLOWER_COSMOS2 + 1) /* red */
#define FLOWER_TULIP1 (FLOWER_TULIP0 + 1) /* white */
#define FLOWER_TULIP2 (FLOWER_TULIP1 + 1) /* yellow */
/* dead sapling */
#define DEAD_SAPLING (FLOWER_TULIP2 + 1)
/* money tree (100 Bells) */
#define TREE_100BELLS_SAPLING (DEAD_SAPLING + 1)
#define TREE_100BELLS_S0 (TREE_100BELLS_SAPLING + 1)
#define TREE_100BELLS_S1 (TREE_100BELLS_S0 + 1)
#define TREE_100BELLS_S2 (TREE_100BELLS_S1 + 1)
#define TREE_100BELLS (TREE_100BELLS_S2 + 1) /* fully grown w/ bells */
/* palm tree */
#define TREE_PALM_SAPLING (TREE_100BELLS + 1)
#define TREE_PALM_S0 (TREE_PALM_SAPLING + 1)
#define TREE_PALM_S1 (TREE_PALM_S0 + 1)
#define TREE_PALM_S2 (TREE_PALM_S1 + 1)
#define TREE_PALM_NOFRUIT_0 (TREE_PALM_S2 + 1) /* fully grown, no fruit */
#define TREE_PALM_NOFRUIT_1 (TREE_PALM_NOFRUIT_0 + 1)
#define TREE_PALM_NOFRUIT_2 (TREE_PALM_NOFRUIT_1 + 1)
#define TREE_PALM_FRUIT (TREE_PALM_NOFRUIT_2 + 1)
#define DEAD_PALM_SAPLING (TREE_PALM_FRUIT + 1)
/* cedar tree */
#define CEDAR_TREE_SAPLING (DEAD_PALM_SAPLING + 1)
#define CEDAR_TREE_S0 (CEDAR_TREE_SAPLING + 1)
#define CEDAR_TREE_S1 (CEDAR_TREE_S0 + 1)
#define CEDAR_TREE_S2 (CEDAR_TREE_S1 + 1)
#define CEDAR_TREE (CEDAR_TREE_S2 + 1) /* fully grown */
#define DEAD_CEDAR_SAPLING (CEDAR_TREE + 1)
/* gold tree */
#define GOLD_TREE_SAPLING (DEAD_CEDAR_SAPLING + 1)
#define GOLD_TREE_S0 (GOLD_TREE_SAPLING + 1)
#define GOLD_TREE_S1 (GOLD_TREE_S0 + 1)
#define GOLD_TREE_S2 (GOLD_TREE_S1 + 1)
#define GOLD_TREE_SHOVEL (GOLD_TREE_S2 + 1) /* fully grown w/ golden shovel */
#define GOLD_TREE (GOLD_TREE_SHOVEL + 1) /* fully grown */
#define DEAD_GOLD_SAPLING (GOLD_TREE + 1)
/* end of environmental objects */

#define SNOWMAN0 0xA008
#define SNOWMAN1 (SNOWMAN0 + 1)
#define SNOWMAN2 (SNOWMAN1 + 1)
#define SNOWMAN3 (SNOWMAN2 + 1)
#define SNOWMAN4 (SNOWMAN3 + 1)
#define SNOWMAN5 (SNOWMAN4 + 1)
#define SNOWMAN6 (SNOWMAN5 + 1)
#define SNOWMAN7 (SNOWMAN6 + 1)
#define SNOWMAN8 (SNOWMAN7 + 1)

#endif
