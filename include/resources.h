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
    "assets/images/game_bg.png",
    "assets/images/game_bg_2.png",
    "assets/images/menu.png",
    "assets/images/crosshair.png",
};

static const char *SOUND_L[] = {
    "assets/sounds/hitmarker.ogg",
    "assets/sounds/oui.ogg",
};

static const char *MUSIC_L[] = {
    "assets/musics/chrono_trigger.ogg",
};

    #define IMAGE_COUNT (sizeof(IMAGES) / sizeof(char *))

typedef enum texture_id_e {
    BACKGROUND,
    BACKGROUND_2,
    MENU,
    CROSSHAIR
} texture_id_t;

typedef struct game_sprite_s {
    texture_id_t id;
    sfIntRect rect;
    float scale;
} game_sprite_t;

static const game_sprite_t SPRITES[] = {
    {
        .id = BACKGROUND,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 1980,
            .height = 1080
        },
        .scale = 1
    },
    {
        .id = BACKGROUND_2,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 1980,
            .height = 1080
        },
        .scale = 1
    },
    {
        .id = MENU,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 1980,
            .height = 1080
        },
        .scale = 1
    },
    {
        .id = CROSSHAIR,
        .rect = {
            .left = 0,
            .top = 0,
            .width = 512,
            .height = 512
        },
        .scale = 1
    }
};

    #define SPRITE_COUNT (sizeof(SPRITES) / sizeof(game_sprite_t))

typedef enum sprite_id_e {
    SP_BACKGROUND,
    SP_BACKGROUND_2,
    SP_MENU,
    SP_PLANE,
    SP_TOWER,
    SP_CROSSHAIR
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
    M_CHRONO,
} music_id_t;

typedef struct music_s {
    music_id_t id;
    float volume;
} music_t;

static const music_t MUSICS[] = {
    {
        .id = M_CHRONO,
        .volume = 5
    }
};

    #define MUSIC_COUNT (sizeof(MUSICS) / sizeof(music_t))

#endif /* RESOURCES_H */
