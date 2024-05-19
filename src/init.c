/*
** EPITECH PROJECT, 2024
** Vendetta
** File description:
** Initialize the game
*/

#include <stdio.h>

#include "my_game.h"
#include "init_game.h"
#include "map.h"
#include "utils.h"

static int init_partie_one(game_data_t *game)
{
    init_assets(game);
    if (init_player(game) == RET_FAIL || init_menu_view(game) == RET_FAIL
        || init_game_view(game) == RET_FAIL)
        return RET_FAIL;
    dprintf(1, "OK !\n");
    dprintf(1, "Loading window\n");
    game->window =
        sfRenderWindow_create(game->video_mode, game->name,
        sfResize | sfClose, NULL);
    if (game->window == NULL)
        return RET_FAIL;
    dprintf(1, "OK !\n");
    if (set_map(game, MAP_ONE) == RET_FAIL)
        return RET_FAIL;
    init_enemies(game);
    game->animation_clock = sfClock_create();
    return RET_NONE;
}

static void start_game_loop(game_data_t *game)
{
    while (sfRenderWindow_isOpen(game->window))
        process_game_loop(game);
}

int init_game(game_data_t *game)
{
    if (init_partie_one(game) == RET_FAIL)
        return destroy_game_data(game, RET_FAIL);
    sfRenderWindow_setFramerateLimit(game->window, WINDOW_FPS);
    icon_loader(game);
    dprintf(1, "Start game loop\n");
    start_game_loop(game);
    return destroy_game_data(game, RET_NONE);
}
