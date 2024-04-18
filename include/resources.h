/*
** EPITECH PROJECT, 2024
** resources.h
** File description:
** dd
*/

#ifndef RESOURCES_H
    #define RESOURCES_H

    #include <SFML/Audio.h>

static const char *SCORE_FILE_PATH = "./database/highest_score";

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
};

static const char *SOUND_L[] = {
    // "assets/sounds/hitmarker.ogg",
    "assets/sounds/oui.ogg",
};

static const char *MUSIC_L[] = {
    "assets/musics/loading_music.ogg",
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
    VENDETTA_T
} texture_id_t;

typedef struct game_sprite_s {
    texture_id_t id;
    sfIntRect rect;
    float scale;
    sfVector2f position;
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
        .position = {0, 0}
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
        .position = {0, 0}
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
        .position = {0, 0}
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
        .position = {1097, 452}
    },
    {
        .id = ORA,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 300,
            .height = 300
        },
        .scale = 1,
        .position = {810, 634}
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
        .position = {404, 411}
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
        .position = {0, 0}
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
        .position = {410, 388}
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
        .position = {1089, 388}
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
        .position = {410, 618}
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
        .position = {1089, 618}
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
        .position = {784, 339}
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
    SP_VENDETTA_T
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
        .volume = 70
    }
};

    #define MUSIC_COUNT (sizeof(MUSICS) / sizeof(music_t))

#endif /* RESOURCES_H */
