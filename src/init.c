/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** my_radar project
*/

#include <stdlib.h>
#include "my_game.h"
#include "my.h"

static int init_partie_one(game_data_t *game, char **av)
{
    init_assets(game);
    my_putstr("OK !\n");
    my_putstr("Loading window\n");
    game->window =
        sfRenderWindow_create(game->video_mode, game->name,
        sfResize | sfClose, NULL);
    if (game->window == NULL)
        return RET_FAIL;
    my_putstr("OK !\n");
    game->pixels = malloc(sizeof(sfUint8) * game->video_mode.width *
        game->video_mode.height * 4);
    if (game->pixels == NULL)
        return RET_FAIL;
    return RET_NONE;
}

int init_game(game_data_t *game, char **av)
{
    if (init_partie_one(game, av) == RET_FAIL)
        return destroy_game_data(game, RET_FAIL);
    sfRenderWindow_setFramerateLimit(game->window, WINDOW_FPS);
    my_putstr("Start game loop\n");
    start_game_loop(game);
    return destroy_game_data(game, RET_NONE);
}

void start_game_loop(game_data_t *game)
{
    while (sfRenderWindow_isOpen(game->window))
        process_game_loop(game);
}
