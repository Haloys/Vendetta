/*
** EPITECH PROJECT, 2024
** Vendetta / Header
** File description:
** Resources
*/

#ifndef RESOURCES_H
    #define RESOURCES_H
    #define MAX_VOLUME 243
    #define SCALE_FACTOR 1.0f

    #include <SFML/Audio.h>

static const char *IMAGES[] = {
    "assets/images/loading_screen/bg_load1.jpg",
    "assets/images/loading_screen/bg_load2.jpg",
    "assets/images/loading_screen/bg_load3.jpg",
    "assets/images/loading_screen/flavibot.png",
    "assets/images/loading_screen/ora.png",
    "assets/images/loading_screen/tryade.png",
    "assets/images/loading_screen/vendetta.png",
    "assets/images/loading_screen/dev_1.png",
    "assets/images/loading_screen/dev_2.png",
    "assets/images/loading_screen/dev_3.png",
    "assets/images/loading_screen/dev_4.png",
    "assets/images/loading_screen/vendetta_t.png",
    "assets/images/main_menu/menu_bg.jpg",
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
    "assets/images/maps/map_1.png",
    "assets/images/maps/map_2.png",
    "assets/images/maps/map_3.png",
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
    "assets/images/main_menu/home.png",
    "assets/images/main_menu/icon_settings_2.png",
    "assets/images/main_menu/inventory.png",
    "assets/images/main_menu/skill.png",
    "assets/images/books/book_1.jpg",
    "assets/images/books/book_2.jpg",
    "assets/images/books/book_3.jpg",
    "assets/images/icons/health2.png",
    "assets/images/enemies/boss_idle.png",
    "assets/images/enemies/boss_shooting.png",
    "assets/images/enemies/hard_idle.png",
    "assets/images/enemies/hard_shooting.png",
    "assets/images/enemies/medium_idle.png",
    "assets/images/enemies/medium_shooting.png",
    "assets/images/player/gun_spritesheet.png",
    "assets/images/player/knife_spritesheet.png",
    "assets/images/player/rifle_spritesheet.png",
    "assets/images/player/shotgun_sprite.png",
    "assets/images/main_menu/chest.png",
    "assets/images/main_menu/sword.png",
    "assets/images/main_menu/potion.png",
    "assets/images/main_menu/key.png",
    "assets/images/npcs/black_npc_pic.png",
    "assets/images/npcs/black_npc.png",
    "assets/images/npcs/green_npc_pic.png",
    "assets/images/npcs/green_npc.png",
    "assets/images/npcs/red_npc_pic.png",
    "assets/images/npcs/red_npc.png",
    "assets/images/npcs/white_npc_pic.png",
    "assets/images/npcs/white_npc.png",
    "assets/images/npcs/yellow_npc_pic.png",
    "assets/images/npcs/yellow_npc.png",
    "assets/images/icons/objective.png",
    "assets/images/misc/bullet.png",
    "assets/images/main_menu/dead.png",
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
    HOME_ICON,
    SETTINGS_2,
    INVENTORY_ICON,
    SKILL_ICON,
    BOOK1,
    BOOK2,
    BOOK3,
    HEALTH2,
    BOSS_IDLE,
    BOSS_SHOOTING,
    HARD_IDLE,
    HARD_SHOOTING,
    MEDIUM_IDLE,
    MEDIUM_SHOOTING,
    PLAYER_GUN,
    PLAYER_KNIFE,
    PLAYER_RIFLE,
    PLAYER_SHOTGUN,
    CHEST_ICON,
    SWORD_ICON,
    POTION_ICON,
    KEY_ICON,
    BLACK_NPC_PIC,
    BLACK_NPC,
    GREEN_NPC_PIC,
    GREEN_NPC,
    RED_NPC_PIC,
    RED_NPC,
    WHITE_NPC_PIC,
    WHITE_NPC,
    YELLOW_NPC_PIC,
    YELLOW_NPC,
    OBJECTIVE,
    BULLET,
    DEAD,
} texture_id_t;

typedef struct game_sprite_s {
    texture_id_t id;
    sfIntRect rect;
    float scale;
    sfVector2f position;
    sfVector2f origin;
    int rect_count;
} game_sprite_t;


extern const game_sprite_t SPRITES[];
extern const int SPRITE_COUNT;

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
    SP_HOME_ICON,
    SP_SETTINGS_2,
    SP_INVENTORY_ICON,
    SP_SKILL_ICON,
    SP_BOOK1,
    SP_BOOK2,
    SP_BOOK3,
    SP_HEALTH2,
    SP_BOSS_IDLE,
    SP_BOSS_SHOOTING,
    SP_HARD_IDLE,
    SP_HARD_SHOOTING,
    SP_MEDIUM_IDLE,
    SP_MEDIUM_SHOOTING,
    SP_PLAYER_GUN,
    SP_PLAYER_KNIFE,
    SP_PLAYER_RIFLE,
    SP_PLAYER_SHOTGUN,
    SP_CHEST_ICON,
    SP_SWORD_ICON,
    SP_POTION_ICON,
    SP_KEY_ICON,
    SP_BLACK_NPC_PIC,
    SP_BLACK_NPC,
    SP_GREEN_NPC_PIC,
    SP_GREEN_NPC,
    SP_RED_NPC_PIC,
    SP_RED_NPC,
    SP_WHITE_NPC_PIC,
    SP_WHITE_NPC,
    SP_YELLOW_NPC_PIC,
    SP_YELLOW_NPC,
    SP_OBJECTIVE,
    SP_BULLET,
    SP_DEAD,
} sprite_id_t;

typedef enum sound_id_e {
    S_PLAYER_PUNCH,
    S_ENEMY_PISTOL,
    S_FIRST_BOOK,
    S_SECOND_BOOK,
    S_THIRD_BOOK,
    S_CHEST,
    S_CLICK_SOUND,
    S_FOOTSTEPS,
    S_KNIFE,
    S_MINIGUN,
    S_MISSILE,
    S_PUNCH,
    S_RIFLE,
    S_SHOTGUN,
    S_HIT,
    S_AK47,
    S_POTION_LOOT,
    S_KEYS_LOOT,
    S_VILLAGER_IDLE,
    S_VILLAGER_COMPLETE,
    S_PORTAL,
} sound_id_t;

typedef struct sound_s {
    sound_id_t id;
    float volume;
} sound_t;

static const sound_t SOUNDS[] = {
    {
        .id = S_PLAYER_PUNCH,
        .volume = 20
    },
    {
        .id = S_ENEMY_PISTOL,
        .volume = 20
    },
    {
        .id = S_FIRST_BOOK,
        .volume = 100
    },
    {
        .id = S_SECOND_BOOK,
        .volume = 100
    },
    {
        .id = S_THIRD_BOOK,
        .volume = 100
    },
    {
        .id = S_CHEST,
        .volume = 50
    },
    {
        .id = S_CLICK_SOUND,
        .volume = 50
    },
    {
        .id = S_FOOTSTEPS,
        .volume = 50
    },
    {
        .id = S_KNIFE,
        .volume = 50
    },
    {
        .id = S_MINIGUN,
        .volume = 50
    },
    {
        .id = S_MISSILE,
        .volume = 50
    },
    {
        .id = S_PUNCH,
        .volume = 50
    },
    {
        .id = S_RIFLE,
        .volume = 50
    },
    {
        .id = S_SHOTGUN,
        .volume = 50
    },
    {
        .id = S_HIT,
        .volume = 50
    },
    {
        .id = S_AK47,
        .volume = 50
    },
    {
        .id = S_POTION_LOOT,
        .volume = 50
    },
    {
        .id = S_KEYS_LOOT,
        .volume = 50
    },
    {
        .id = S_VILLAGER_IDLE,
        .volume = 50
    },
    {
        .id = S_VILLAGER_COMPLETE,
        .volume = 50
    },
    {
        .id = S_PORTAL,
        .volume = 50
    }
};

    #define SOUND_COUNT (sizeof(SOUNDS) / sizeof(sound_t))

typedef enum music_id_e {
    M_LOADING,
    M_FIRST_MAP,
    M_SECOND_MAP,
    M_THIRD_MAP,
    M_ENDING,
} music_id_t;

typedef struct music_s {
    music_id_t id;
    float volume;
} music_t;

static const music_t MUSICS[] = {
    {
        .id = M_LOADING,
        .volume = 20
    },
    {
        .id = M_FIRST_MAP,
        .volume = 20
    },
    {
        .id = M_SECOND_MAP,
        .volume = 20
    },
    {
        .id = M_THIRD_MAP,
        .volume = 20
    },
    {
        .id = M_ENDING,
        .volume = 20
    },
};

    #define MUSIC_COUNT (sizeof(MUSICS) / sizeof(music_t))

typedef enum shader_id_e {
    SH_MAIN_DARKNESS,
} shader_id_t;

typedef struct shader_s {
    shader_id_t id;
} shader_t;

extern const char *SHADER_PATHS[];
extern const int SHADER_PATHS_COUNT;
extern const shader_t SHADERS[];
extern const int SHADER_COUNT;

#endif /* RESOURCES_H */
