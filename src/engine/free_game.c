/*
** EPITECH PROJECT, 2024
** animation
** File description:
** dd
*/

#include <stdlib.h>
#include "my_game.h"
#include "my.h"

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
    my_putstr("Destroy game data && free elements\n");
    destroy_game_elements(game);
    destroy_game_clocks(game);
    sfRenderWindow_destroy(game->window);
    sfFont_destroy(game->font);
    my_putstr("OK !\n");
    return code;
}
