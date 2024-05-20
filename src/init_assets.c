/*
** EPITECH PROJECT, 2024
** Vendetta
** File description:
** Initialize Assets
*/

#include <stdio.h>

#include "my_game.h"
#include "music.h"

static void set_sprite_attribut(sfSprite *sprite, game_sprite_t SPRITE)
{
    sfSprite_setTextureRect(sprite, SPRITE.rect);
    sfSprite_setPosition(sprite, SPRITE.position);
    sfSprite_setScale(sprite, (sfVector2f){SPRITE.scale, SPRITE.scale});
    sfSprite_setOrigin(sprite, SPRITE.origin);
}

static int load_textures(game_assets_t *assets)
{
    sfSprite *sprite = NULL;

    for (size_t i = 0; i < IMAGE_COUNT; ++i) {
        dprintf(1, "Loading texture: %s\n", IMAGES[i]);
        assets->texture[i] = sfTexture_createFromFile(IMAGES[i], NULL);
        if (assets->texture[i] == NULL)
            continue;
        dprintf(1, "OK !\n");
    }
    for (size_t i = 0; i < SPRITE_COUNT; ++i) {
        dprintf(1, "Loading sprite with id: %d\n", SPRITES[i].id);
        sprite = sfSprite_create();
        if (sprite == NULL)
            continue;
        sfSprite_setTexture(sprite, assets->texture[SPRITES[i].id], sfTrue);
        set_sprite_attribut(sprite, SPRITES[i]);
        assets->sprite[i] = sprite;
        dprintf(1, "OK !\n");
    }
    return RET_NONE;
}

static int load_sounds(game_assets_t *assets)
{
    sfSoundBuffer *sound_buffer = NULL;
    sfSound *sound = NULL;

    for (size_t i = 0; i < SOUND_COUNT; ++i) {
        dprintf(1, "Loading sound: %s\n", SOUND_L[i]);
        sound_buffer = sfSoundBuffer_createFromFile(SOUND_L[i]);
        if (sound_buffer == NULL)
            continue;
        assets->sound_buff[i] = sound_buffer;
        sound = sfSound_create();
        if (sound == NULL)
            continue;
        sfSound_setBuffer(sound, sound_buffer);
        sfSound_setVolume(sound, SOUNDS[i].volume);
        assets->sound[i] = sound;
        dprintf(1, "OK !\n");
    }
    return RET_NONE;
}

static int load_musics(game_assets_t *assets)
{
    sfMusic *music = NULL;

    for (size_t i = 0; i < MUSIC_COUNT; ++i) {
        dprintf(1, "Loading music: %s\n", MUSIC_L[i]);
        music = sfMusic_createFromFile(MUSIC_L[i]);
        if (music == NULL)
            continue;
        assets->music[i] = music;
        dprintf(1, "OK !\n");
    }
    return RET_NONE;
}

static int load_font(game_data_t *game)
{
    char path[] = "assets/fonts/MullerRegular.ttf";
    sfFont *font = sfFont_createFromFile(path);

    dprintf(1, "Loading font: %s\n", path);
    if (font == NULL)
        return EXIT_FAILURE;
    dprintf(1, "OK !\n");
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
