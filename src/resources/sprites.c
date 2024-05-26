/*
** EPITECH PROJECT, 2024
** Vendetta
** File description:
** Music
*/

#include "my_game.h"
#include "resources.h"

const game_sprite_t SPRITES[] = {
    {
        .id = LOADING_1,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 1980,
            .height = 1080
        },
        .scale = 1,
        .position = {0, 0},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = LOADING_2,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 1980,
            .height = 1080
        },
        .scale = 1,
        .position = {0, 0},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = LOADING_3,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 1980,
            .height = 1080
        },
        .scale = 1,
        .position = {0, 0},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = FLAVIBOT,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 418,
            .height = 81
        },
        .scale = 1,
        .position = {1097, 452},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = ORA,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 196,
            .height = 146
        },
        .scale = 1,
        .position = {862, 718},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = TRYADE,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 482,
            .height = 162
        },
        .scale = 1,
        .position = {404, 411},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = VENDETTA,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 351,
            .height = 292
        },
        .scale = 1,
        .position = {0, 0},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = DEV_1,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 472,
            .height = 74
        },
        .scale = 1,
        .position = {410, 388},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = DEV_2,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 389,
            .height = 74
        },
        .scale = 1,
        .position = {1089, 388},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = DEV_3,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 439,
            .height = 74
        },
        .scale = 1,
        .position = {410, 618},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = DEV_4,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 421,
            .height = 80
        },
        .scale = 1,
        .position = {1089, 618},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = VENDETTA_T,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 351,
            .height = 402
        },
        .scale = 1,
        .position = {784, 339},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = MAIN_BG,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 1920,
            .height = 1080
        },
        .scale = 1,
        .position = {0, 0},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = VENDETTA_MENU,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 202,
            .height = 91
        },
        .scale = 1,
        .position = {1704, 34},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = ICON_PLAY,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 19,
            .height = 21
        },
        .scale = 1,
        .position = {113, 52},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = ICON_SETTINGS,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 22,
            .height = 22
        },
        .scale = 1,
        .position = {325, 52},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = ICON_HELP,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 21,
            .height = 21
        },
        .scale = 1,
        .position = {594, 52},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = ICON_QUIT,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 19,
            .height = 19
        },
        .scale = 1,
        .position = {788, 52},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = ARROW_R1,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 12,
            .height = 21
        },
        .scale = 1,
        .position = {745, 277},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = ARROW_L1,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 12,
            .height = 21
        },
        .scale = 1,
        .position = {521, 277},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = ARROW_R2,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 12,
            .height = 21
        },
        .scale = 1,
        .position = {745, 338},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = ARROW_L2,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 12,
            .height = 21
        },
        .scale = 1,
        .position = {521, 338},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = ARROW_R3,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 12,
            .height = 21
        },
        .scale = 1,
        .position = {745, 399},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = ARROW_L3,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 12,
            .height = 21
        },
        .scale = 1,
        .position = {521, 399},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = MAN_SKIN,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 637,
            .height = 610
        },
        .scale = 1,
        .position = {760, 280},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = AIDKIT,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 60,
            .height = 60
        },
        .scale = 1,
        .position = {0, 0},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = ARMOR,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 60,
            .height = 60
        },
        .scale = 1,
        .position = {0, 0},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = ARMOR2,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 60,
            .height = 60
        },
        .scale = 1,
        .position = {0, 0},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = ARMOR3,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 60,
            .height = 60
        },
        .scale = 1,
        .position = {0, 0},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = BANDAGE,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 60,
            .height = 60
        },
        .scale = 1,
        .position = {0, 0},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = BONE,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 60,
            .height = 60
        },
        .scale = 1,
        .position = {0, 0},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = CASH,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 60,
            .height = 60
        },
        .scale = 1,
        .position = {0, 0},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = EPHEDRINE,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 60,
            .height = 60
        },
        .scale = 1,
        .position = {0, 0},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = FIRST_BOOK,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 60,
            .height = 60
        },
        .scale = 1,
        .position = {0, 0},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = GOLDCOIN,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 60,
            .height = 60
        },
        .scale = 1,
        .position = {0, 0},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = HEROIN,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 60,
            .height = 60
        },
        .scale = 1,
        .position = {0, 0},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = JOINT,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 60,
            .height = 60
        },
        .scale = 1,
        .position = {0, 0},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = KEYA,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 60,
            .height = 60
        },
        .scale = 0.8,
        .position = {0, 0},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = KEYB,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 60,
            .height = 60
        },
        .scale = 0.8,
        .position = {0, 0},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = KEYC,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 60,
            .height = 60
        },
        .scale = 0.8,
        .position = {0, 0},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = KNIFE,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 60,
            .height = 60
        },
        .scale = 1,
        .position = {0, 0},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = LIGHTER_BLUE,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 60,
            .height = 60
        },
        .scale = 1,
        .position = {0, 0},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = MASK1,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 60,
            .height = 60
        },
        .scale = 1,
        .position = {0, 0},
        .rect_count = 1
    },
    {
        .id = MASK2,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 60,
            .height = 60
        },
        .scale = 1,
        .position = {0, 0},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = MASK3,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 60,
            .height = 60
        },
        .scale = 1,
        .position = {0, 0},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = MASK4,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 60,
            .height = 60
        },
        .scale = 1,
        .position = {0, 0},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = MK18,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 60,
            .height = 60
        },
        .scale = 1,
        .position = {0, 0},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = OLD_PAPER,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 60,
            .height = 60
        },
        .scale = 1,
        .position = {0, 0},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = OXY,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 60,
            .height = 60
        },
        .scale = 1,
        .position = {0, 0},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = PISTOLMK2,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 60,
            .height = 60
        },
        .scale = 1,
        .position = {0, 0},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = PUMPSHOTGUN,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 60,
            .height = 60
        },
        .scale = 1,
        .position = {0, 0},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = RING,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 60,
            .height = 60
        },
        .scale = 1,
        .position = {0, 0},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = ROLEX,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 60,
            .height = 60
        },
        .scale = 1,
        .position = {0, 0},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = SECOND_BOOK,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 60,
            .height = 60
        },
        .scale = 1,
        .position = {0, 0},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = SHOES,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 60,
            .height = 60
        },
        .scale = 1,
        .position = {0, 0},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = SHOES_BLUE,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 60,
            .height = 60
        },
        .scale = 1,
        .position = {0, 0},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = SHOES_GREEN,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 60,
            .height = 60
        },
        .scale = 1,
        .position = {0, 0},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = SHOES_RED,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 60,
            .height = 60
        },
        .scale = 1,
        .position = {0, 0},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = THIRD_BOOK,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 60,
            .height = 60
        },
        .scale = 1,
        .position = {0, 0},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = WHISKEY,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 60,
            .height = 60
        },
        .scale = 1,
        .position = {0, 0},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = STATS,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 319,
            .height = 317
        },
        .scale = 1,
        .position = {1385, 575},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = HELP_DIALOGUES,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 1184,
            .height = 675
        },
        .scale = 1,
        .position = {22, 203},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = MAP_1,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 3640,
            .height = 2660
        },
        .scale = 1,
        .position = {0, 0},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = MAP_2,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 2590,
            .height = 2170
        },
        .scale = 1,
        .position = {0, 0},
        .origin = {0, 0},
        .rect_count = 1
    },
        {
        .id = MAP_3,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 4060,
            .height = 2520
        },
        .scale = 1,
        .position = {0, 0},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = COLS_MAP_1,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 3640,
            .height = 2660
        },
        .scale = 1,
        .position = {0, 0},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = COLS_MAP_2,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 2590,
            .height = 2170
        },
        .scale = 1,
        .position = {0, 0},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = COLS_MAP_3,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 4060,
            .height = 2520
        },
        .scale = 1,
        .position = {0, 0},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = PLAYER_HAND,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 139,
            .height = 110
        },
        .scale = 0.65,
        .position = {0, 0},
        .origin = {55, 55},
        .rect_count = 20
    },
    {
        .id = ENEMY_EZ_IDLE,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 89,
            .height = 110
        },
        .scale = 1,
        .position = {0, 0},
        .origin = {44.5, 55},
        .rect_count = 16
    },
        {
        .id = ENEMY_EZ_SHOOTING,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 89,
            .height = 110
        },
        .scale = 1,
        .position = {0, 0},
        .origin = {44.5, 55},
        .rect_count = 8
    },
    {
        .id = LOAD_SAVE_HELP,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 990,
            .height = 97
        },
        .scale = 1,
        .position = {428, 300},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = SAVE_1,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 452,
            .height = 516
        },
        .scale = 1,
        .position = {149, 241},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = SAVE_2,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 452,
            .height = 516
        },
        .scale = 1,
        .position = {727, 241},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = SAVE_3,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 452,
            .height = 516
        },
        .scale = 1,
        .position = {1321, 241},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = EMPTY_SLOT,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 291,
            .height = 354
        },
        .scale = 1,
        .position = {0, 0},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = HEALTH_ICON,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 14,
            .height = 14
        },
        .scale = 1,
        .position = {0, 0},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = ARMOR_ICON,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 12,
            .height = 14
        },
        .scale = 1,
        .position = {0, 0},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = ATTACK_ICON,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 18,
            .height = 10
        },
        .scale = 1,
        .position = {0, 0},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = SPEED_ICON,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 11,
            .height = 15
        },
        .scale = 1,
        .position = {0, 0},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = TEXT_SKILL_TREE,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 1741,
            .height = 103
        },
        .scale = 1,
        .position = {80, 265},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = HEALTH_COL,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 70,
            .height = 70
        },
        .scale = 1,
        .position = {80, 265},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = HEALTH_GRAY,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 70,
            .height = 70
        },
        .scale = 1,
        .position = {80, 265},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = ARMOR_COL,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 59,
            .height = 70
        },
        .scale = 1,
        .position = {80, 265},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = ARMOR_GRAY,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 59,
            .height = 70
        },
        .scale = 1,
        .position = {80, 265},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = SPEED_COL,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 52,
            .height = 70
        },
        .scale = 1,
        .position = {80, 265},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = SPEED_GRAY,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 52,
            .height = 70
        },
        .scale = 1,
        .position = {80, 265},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = ATTACK_COL,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 59,
            .height = 35
        },
        .scale = 1,
        .position = {80, 265},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = ATTACK_GRAY,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 59,
            .height = 35
        },
        .scale = 1,
        .position = {80, 265},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = HOME_ICON,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 25,
            .height = 22
        },
        .scale = 1,
        .position = {1205, 51},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = SETTINGS_2,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 22,
            .height = 22
        },
        .scale = 1,
        .position = {940, 51},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = INVENTORY_ICON,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 26,
            .height = 22
        },
        .scale = 1,
        .position = {351, 51},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = SKILL_ICON,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 25,
            .height = 22
        },
        .scale = 1,
        .position = {657, 51},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = BOOK1,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 1920,
            .height = 1080
        },
        .scale = 1,
        .position = {0, 0},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = BOOK2,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 1920,
            .height = 1080
        },
        .scale = 1,
        .position = {0, 0},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = BOOK3,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 1920,
            .height = 1080
        },
        .scale = 1,
        .position = {0, 0},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = HEALTH2,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 30,
            .height = 30
        },
        .scale = 1,
        .position = {0, 0},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = BOSS_IDLE,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 89,
            .height = 110
        },
        .scale = 1,
        .position = {0, 0},
        .origin = {44.5, 55},
        .rect_count = 16
    },
    {
        .id = BOSS_SHOOTING,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 89,
            .height = 110
        },
        .scale = 1,
        .position = {0, 0},
        .origin = {44.5, 55},
        .rect_count = 8
    },
    {
        .id = HARD_IDLE,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 89,
            .height = 110
        },
        .scale = 1,
        .position = {0, 0},
        .origin = {44.5, 55},
        .rect_count = 16
    },
    {
        .id = HARD_SHOOTING,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 89,
            .height = 110
        },
        .scale = 1,
        .position = {0, 0},
        .origin = {44.5, 55},
        .rect_count = 8
    },
    {
        .id = MEDIUM_IDLE,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 89,
            .height = 110
        },
        .scale = 1,
        .position = {0, 0},
        .origin = {44.5, 55},
        .rect_count = 16
    },
    {
        .id = MEDIUM_SHOOTING,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 89,
            .height = 110
        },
        .scale = 1,
        .position = {0, 0},
        .origin = {44.5, 55},
        .rect_count = 8
    },
    {
        .id = PLAYER_GUN,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 128,
            .height = 108
        },
        .scale = 0.65,
        .position = {0, 0},
        .origin = {64, 54},
        .rect_count = 3
    },
    {
        .id = PLAYER_KNIFE,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 139,
            .height = 110
        },
        .scale = 0.65,
        .position = {0, 0},
        .origin = {69.5, 55},
        .rect_count = 20
    },
    {
        .id = PLAYER_RIFLE,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 156,
            .height = 103
        },
        .scale = 0.65,
        .position = {0, 0},
        .origin = {78, 51.5},
        .rect_count = 3
    },
    {
        .id = PLAYER_SHOTGUN,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 156,
            .height = 103
        },
        .scale = 0.65,
        .position = {0, 0},
        .origin = {68, 51.5},
        .rect_count = 3
    },
    {
        .id = CHEST_ICON,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 33,
            .height = 33
        },
        .scale = 1,
        .position = {0, 0},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = SWORD_ICON,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 33,
            .height = 33
        },
        .scale = 1,
        .position = {0, 0},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = POTION_ICON,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 32,
            .height = 32
        },
        .scale = 1.2,
        .position = {0, 0},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = KEY_ICON,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 31,
            .height = 15
        },
        .scale = 1,
        .position = {0, 0},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = BLACK_NPC_PIC,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 385,
            .height = 751
        },
        .scale = 1,
        .position = {1451, 329},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = BLACK_NPC,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 139,
            .height = 110
        },
        .scale = 0.65,
        .position = {0, 0},
        .origin = {69.5, 55},
        .rect_count = 20
    },
    {
        .id = GREEN_NPC_PIC,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 366,
            .height = 751
        },
        .scale = 1,
        .position = {1451, 329},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = GREEN_NPC,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 139,
            .height = 110
        },
        .scale = 0.65,
        .position = {0, 0},
        .origin = {69.5, 55},
        .rect_count = 20
    },
    {
        .id = RED_NPC_PIC,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 375,
            .height = 772
        },
        .scale = 1,
        .position = {1451, 308},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = RED_NPC,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 139,
            .height = 110
        },
        .scale = 0.65,
        .position = {0, 0},
        .origin = {69.5, 55},
        .rect_count = 20
    },
    {
        .id = WHITE_NPC_PIC,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 669,
            .height = 718
        },
        .scale = 1,
        .position = {1212, 363},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = WHITE_NPC,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 139,
            .height = 110
        },
        .scale = 0.65,
        .position = {0, 0},
        .origin = {69.5, 55},
        .rect_count = 20
    },
    {
        .id = YELLOW_NPC_PIC,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 366,
            .height = 751
        },
        .scale = 1,
        .position = {1435, 329},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = YELLOW_NPC,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 139,
            .height = 110
        },
        .scale = 0.65,
        .position = {0, 0},
        .origin = {69.5, 55},
        .rect_count = 20
    },
    {
        .id = OBJECTIVE,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 21,
            .height = 21
        },
        .scale = 1,
        .position = {0, 0},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = BULLET,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 14,
            .height = 38
        },
        .scale = 1,
        .position = {0, 0},
        .origin = {0, 0},
        .rect_count = 1
    },
    {
        .id = DEAD,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 722,
            .height = 173
        },
        .scale = 1,
        .position = {599, 200},
        .origin = {0, 0},
        .rect_count = 1
    }
};

const int SPRITE_COUNT = sizeof(SPRITES) / sizeof(game_sprite_t);
