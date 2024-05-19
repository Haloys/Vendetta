/*
** EPITECH PROJECT, 2024
** Vendetta / Game Engine
** File description:
** Free game data
*/

#include <stdio.h>

#include "my_game.h"

static void destroy_game_elements(game_data_t *game)
{
    for (size_t i = 0; i < IMAGE_COUNT; ++i)
        sfTexture_destroy(game->assets.texture[i]);
    for (size_t i = 0; i < SPRITE_COUNT; ++i)
        sfSprite_destroy(game->assets.sprite[i]);
    for (size_t i = 0; i < SOUND_COUNT; ++i)
        sfSoundBuffer_destroy(game->assets.sound[i]);
    for (size_t i = 0; i < MUSIC_COUNT; ++i)
        sfMusic_destroy(game->assets.music[i]);
}

static void destroy_game_clocks(game_data_t *game)
{
    sfClock_destroy(game->clock);
    sfClock_destroy(game->fps_clock);
    sfClock_destroy(game->time);
}

int destroy_game_data(game_data_t *game, int code)
{
    dprintf(1, "Destroy game data && free elements\n");
    destroy_game_elements(game);
    destroy_game_clocks(game);
    sfRenderWindow_destroy(game->window);
    sfFont_destroy(game->font);
    dprintf(1, "OK !\n");
    return code;
}
