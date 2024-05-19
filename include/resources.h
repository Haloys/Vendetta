/*
** EPITECH PROJECT, 2024
** Vendetta / Header
** File description:
** Resources
*/

#ifndef RESOURCES_H
    #define RESOURCES_H

    #include <SFML/Audio.h>

static const char *IMAGES[] = {
    "assets/images/loading_screen/bg_load1.png",
    "assets/images/loading_screen/bg_load2.png",
    "assets/images/loading_screen/bg_load3.png",
    "assets/images/loading_screen/flavibot.png",
    "assets/images/loading_screen/ora.png",
    "assets/images/loading_screen/tryade.png",
    "assets/images/loading_screen/vendetta.png",
    "assets/images/loading_screen/dev_1.png",
    "assets/images/loading_screen/dev_2.png",
    "assets/images/loading_screen/dev_3.png",
    "assets/images/loading_screen/dev_4.png",
    "assets/images/loading_screen/vendetta_t.png",
    "assets/images/main_menu/menu_bg.png",
    "assets/images/main_menu/vendetta_t.png",
    "assets/images/main_menu/icon_play.png",
    "assets/images/main_menu/icon_settings.png",
    "assets/images/main_menu/icon_help.png",
    "assets/images/main_menu/icon_quit.png",
    "assets/images/main_menu/arrow_r1.png",
    "assets/images/main_menu/arrow_l1.png",
    "assets/images/main_menu/arrow_r2.png",
    "assets/images/main_menu/arrow_l2.png",
    "assets/images/main_menu/arrow_r3.png",
    "assets/images/main_menu/arrow_l3.png",
    "assets/images/inventory/man.png",
    "assets/images/inventory/items/aidkit.png",
    "assets/images/inventory/items/armor.png",
    "assets/images/inventory/items/armor2.png",
    "assets/images/inventory/items/armor3.png",
    "assets/images/inventory/items/bandage.png",
    "assets/images/inventory/items/bone.png",
    "assets/images/inventory/items/cash.png",
    "assets/images/inventory/items/ephedrine.png",
    "assets/images/inventory/items/first_book.png",
    "assets/images/inventory/items/goldcoin.png",
    "assets/images/inventory/items/heroin.png",
    "assets/images/inventory/items/joint.png",
    "assets/images/inventory/items/keya.png",
    "assets/images/inventory/items/keyb.png",
    "assets/images/inventory/items/keyc.png",
    "assets/images/inventory/items/knife.png",
    "assets/images/inventory/items/lighter_blue.png",
    "assets/images/inventory/items/mask1.png",
    "assets/images/inventory/items/mask2.png",
    "assets/images/inventory/items/mask3.png",
    "assets/images/inventory/items/mask4.png",
    "assets/images/inventory/items/mk18.png",
    "assets/images/inventory/items/old_paper.png",
    "assets/images/inventory/items/oxy.png",
    "assets/images/inventory/items/pistolmk2.png",
    "assets/images/inventory/items/pumpshotgun.png",
    "assets/images/inventory/items/ring.png",
    "assets/images/inventory/items/rolex.png",
    "assets/images/inventory/items/second_book.png",
    "assets/images/inventory/items/shoes.png",
    "assets/images/inventory/items/shoes_blue.png",
    "assets/images/inventory/items/shoes_green.png",
    "assets/images/inventory/items/shoes_red.png",
    "assets/images/inventory/items/third_book.png",
    "assets/images/inventory/items/whiskey.png",
    "assets/images/inventory/stats.png",
    "assets/images/main_menu/help_dialogues.png",
    "assets/images/maps/map_1.jpg",
    "assets/images/maps/map_2.jpg",
    "assets/images/maps/map_3.jpg",
    "assets/images/maps/cols_map_1.png",
    "assets/images/maps/cols_map_2.png",
    "assets/images/maps/cols_map_3.png",
    "assets/images/player/hand_spritesheet.png",
    "assets/images/enemies/easy_idle.png",
    "assets/images/enemies/easy_shooting.png",
    "assets/images/main_menu/load_save_help.png",
    "assets/images/main_menu/save_1.png",
    "assets/images/main_menu/save_2.png",
    "assets/images/main_menu/save_3.png",
    "assets/images/main_menu/empty_slot.png",
    "assets/images/dialogues/lucia.png",
    "assets/images/icons/health.png",
    "assets/images/icons/armor.png",
    "assets/images/icons/attack.png",
    "assets/images/icons/speed.png",
    "assets/images/skill_tree/text.png",
    "assets/images/skill_tree/health_color.png",
    "assets/images/skill_tree/health_gray.png",
    "assets/images/skill_tree/shield_color.png",
    "assets/images/skill_tree/shield_gray.png",
    "assets/images/skill_tree/speed_color.png",
    "assets/images/skill_tree/speed_gray.png",
    "assets/images/skill_tree/attack_color.png",
    "assets/images/skill_tree/attack_gray.png",
};

    #define IMAGE_COUNT (sizeof(IMAGES) / sizeof(char *))

typedef enum texture_id_e {
    LOADING_1,
    LOADING_2,
    LOADING_3,
    FLAVIBOT,
    ORA,
    TRYADE,
    VENDETTA,
    DEV_1,
    DEV_2,
    DEV_3,
    DEV_4,
    VENDETTA_T,
    MAIN_BG,
    VENDETTA_MENU,
    ICON_PLAY,
    ICON_SETTINGS,
    ICON_HELP,
    ICON_QUIT,
    ARROW_R1,
    ARROW_L1,
    ARROW_R2,
    ARROW_L2,
    ARROW_R3,
    ARROW_L3,
    MAN_SKIN,
    AIDKIT,
    ARMOR,
    ARMOR2,
    ARMOR3,
    BANDAGE,
    BONE,
    CASH,
    EPHEDRINE,
    FIRST_BOOK,
    GOLDCOIN,
    HEROIN,
    JOINT,
    KEYA,
    KEYB,
    KEYC,
    KNIFE,
    LIGHTER_BLUE,
    MASK1,
    MASK2,
    MASK3,
    MASK4,
    MK18,
    OLD_PAPER,
    OXY,
    PISTOLMK2,
    PUMPSHOTGUN,
    RING,
    ROLEX,
    SECOND_BOOK,
    SHOES,
    SHOES_BLUE,
    SHOES_GREEN,
    SHOES_RED,
    THIRD_BOOK,
    WHISKEY,
    STATS,
    HELP_DIALOGUES,
    MAP_1,
    MAP_2,
    MAP_3,
    COLS_MAP_1,
    COLS_MAP_2,
    COLS_MAP_3,
    PLAYER_HAND,
    ENEMY_EZ_IDLE,
    ENEMY_EZ_SHOOTING,
    LOAD_SAVE_HELP,
    SAVE_1,
    SAVE_2,
    SAVE_3,
    EMPTY_SLOT,
    LUCIA,
    HEALTH_ICON,
    ARMOR_ICON,
    ATTACK_ICON,
    SPEED_ICON,
    TEXT_SKILL_TREE,
    HEALTH_COL,
    HEALTH_GRAY,
    ARMOR_COL,
    ARMOR_GRAY,
    SPEED_COL,
    SPEED_GRAY,
    ATTACK_COL,
    ATTACK_GRAY,
} texture_id_t;

typedef struct game_sprite_s {
    texture_id_t id;
    sfIntRect rect;
    float scale;
    sfVector2f position;
    sfVector2f origin;
    int rect_count;
} game_sprite_t;

static const game_sprite_t SPRITES[] = {
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
        .scale = 1,
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
        .scale = 1,
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
        .scale = 1,
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
        .rect_count = 1
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
        .rect_count = 1
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
        .rect_count = 1
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
        .id = LUCIA,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 1007,
            .height = 735
        },
        .scale = 1,
        .position = {1920, 345},
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
};

    #define SPRITE_COUNT (sizeof(SPRITES) / sizeof(game_sprite_t))

typedef enum sprite_id_e {
    SP_LOADING_1,
    SP_LOADING_2,
    SP_LOADING_3,
    SP_FLAVIBOT,
    SP_ORA,
    SP_TRYADE,
    SP_VENDETTA,
    SP_DEV_1,
    SP_DEV_2,
    SP_DEV_3,
    SP_DEV_4,
    SP_VENDETTA_T,
    SP_MAIN_BG,
    SP_VENDETTA_MENU,
    SP_ICON_PLAY,
    SP_ICON_SETTINGS,
    SP_ICON_HELP,
    SP_ICON_QUIT,
    SP_ARROW_R1,
    SP_ARROW_L1,
    SP_ARROW_R2,
    SP_ARROW_L2,
    SP_ARROW_R3,
    SP_ARROW_L3,
    SP_MAN_SKIN,
    SP_AIDKIT,
    SP_ARMOR,
    SP_ARMOR2,
    SP_ARMOR3,
    SP_BANDAGE,
    SP_BONE,
    SP_CASH,
    SP_EPHEDRINE,
    SP_FIRST_BOOK,
    SP_GOLDCOIN,
    SP_HEROIN,
    SP_JOINT,
    SP_KEYA,
    SP_KEYB,
    SP_KEYC,
    SP_KNIFE,
    SP_LIGHTER_BLUE,
    SP_MASK1,
    SP_MASK2,
    SP_MASK3,
    SP_MASK4,
    SP_MK18,
    SP_OLD_PAPER,
    SP_OXY,
    SP_PISTOLMK2,
    SP_PUMPSHOTGUN,
    SP_RING,
    SP_ROLEX,
    SP_SECOND_BOOK,
    SP_SHOES,
    SP_SHOES_BLUE,
    SP_SHOES_GREEN,
    SP_SHOES_RED,
    SP_THIRD_BOOK,
    SP_WHISKEY,
    SP_STATS,
    SP_HELP_DIALOGUES,
    SP_MAP_1,
    SP_MAP_2,
    SP_MAP_3,
    SP_COLS_MAP_1,
    SP_COLS_MAP_2,
    SP_COLS_MAP_3,
    SP_PLAYER_HAND,
    SP_ENEMY_EZ_IDLE,
    SP_ENEMY_EZ_SHOOTING,
    SP_LOAD_SAVE_HELP,
    SP_SAVE_1,
    SP_SAVE_2,
    SP_SAVE_3,
    SP_EMPTY_SLOT,
    SP_LUCIA,
    SP_HEALTH_ICON,
    SP_ARMOR_ICON,
    SP_ATTACK_ICON,
    SP_SPEED_ICON,
    SP_TEXT_SKILL_TREE,
    SP_HEALTH_COL,
    SP_HEALTH_GRAY,
    SP_ARMOR_COL,
    SP_ARMOR_GRAY,
    SP_SPEED_COL,
    SP_SPEED_GRAY,
    SP_ATTACK_COL,
    SP_ATTACK_GRAY,
} sprite_id_t;

typedef enum sound_id_e {
    S_HIT,
} sound_id_t;

typedef struct sound_s {
    sound_id_t id;
} sound_t;

static const sound_t SOUNDS[] = {
    {
        .id = S_HIT,
    },
};

    #define SOUND_COUNT (sizeof(SOUNDS) / sizeof(sound_t))

typedef enum music_id_e {
    M_LOADING,
} music_id_t;

typedef struct music_s {
    music_id_t id;
    float volume;
} music_t;

static const music_t MUSICS[] = {
    {
        .id = M_LOADING,
        .volume = 20
    }
};

    #define MUSIC_COUNT (sizeof(MUSICS) / sizeof(music_t))

#endif /* RESOURCES_H */
