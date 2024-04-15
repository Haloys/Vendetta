/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** my_radar project
*/

#include "my_game.h"
#include "my.h"
#include <stdlib.h>

static int load_textures(game_assets_t *assets)
{
    sfSprite *sprite = NULL;

    for (size_t i = 0; i < IMAGE_COUNT; ++i) {
        my_printf("Loading texture: %s\n", IMAGES[i]);
        assets->texture[i] = sfTexture_createFromFile(IMAGES[i], NULL);
        if (assets->texture[i] == NULL)
            return RET_FAIL;
        my_putstr("OK !\n");
    }
    for (size_t i = 0; i < SPRITE_COUNT; ++i) {
        my_printf("Loading sprite with id: %d\n", SPRITES[i].id);
        sprite = sfSprite_create();
        if (sprite == NULL)
            return RET_FAIL;
        sfSprite_setTexture(sprite, assets->texture[SPRITES[i].id], sfTrue);
        sfSprite_setTextureRect(sprite, SPRITES[i].rect);
        assets->sprite[i] = sprite;
        my_putstr("OK !\n");
    }
    return RET_NONE;
}

static int load_sounds(game_assets_t *assets)
{
    sfSoundBuffer *sound_buffer = NULL;

    for (size_t i = 0; i < SOUND_COUNT; ++i) {
        my_printf("Loading sound: %s\n", SOUND_L[i]);
        sound_buffer = sfSoundBuffer_createFromFile(SOUND_L[i]);
        if (sound_buffer == NULL)
            return RET_FAIL;
        assets->sound[i] = sound_buffer;
        my_putstr("OK !\n");
    }
    return RET_NONE;
}

static int load_musics(game_assets_t *assets)
{
    sfMusic *music = NULL;

    for (size_t i = 0; i < MUSIC_COUNT; ++i) {
        my_printf("Loading music: %s\n", MUSIC_L[i]);
        music = sfMusic_createFromFile(MUSIC_L[i]);
        if (music == NULL)
            return RET_FAIL;
        assets->music[i] = music;
        my_putstr("OK !\n");
    }
    return RET_NONE;
}

static int load_font(game_data_t *game)
{
    char path[] = "assets/fonts/Arial.ttf";
    sfFont *font = sfFont_createFromFile(path);

    my_printf("Loading font: %s\n", path);
    if (font == NULL)
        return EXIT_FAILURE;
    my_putstr("OK !\n");
    game->font = font;
    return RET_NONE;
}

int init_assets(game_data_t *game)
{
    load_font(game);
    load_textures(&game->assets);
    load_sounds(&game->assets);
    load_musics(&game->assets);
    return 0;
}
