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
#include "path_finding.h"

static void init_parts(game_data_t *game)
{
    init_enemies(game);
    init_bullets(game);
    init_npcs(game);
    init_items(game);
    init_keybinds(game);
    init_path_finding(game);
}

static int load_window(game_data_t *game)
{
    dprintf(1, "Loading window\n");
    if (game->settings.is_fullscreen == true)
        game->window =
        sfRenderWindow_create(game->video_mode, game->name, sfFullscreen, NULL);
    else
        game->window = sfRenderWindow_create(game->video_mode, game->name,
        sfResize | sfClose, NULL);
    if (game->window == NULL)
        return RET_FAIL;
    return RET_NONE;
}

static int init_partie_one(game_data_t *game)
{
    init_assets(game);
    if (init_player(game) == RET_FAIL || init_menu_view(game) == RET_FAIL
        || init_game_view(game) == RET_FAIL)
        return RET_FAIL;
    dprintf(1, "OK !\n");
    if (load_window(game) == RET_FAIL)
        return RET_FAIL;
    if (set_map(game, MAP_ONE) == RET_FAIL)
        return RET_FAIL;
    game->animation_clock = sfClock_create();
    init_parts(game);
    return RET_NONE;
}

static void start_game_loop(game_data_t *game)
{
    while (sfRenderWindow_isOpen(game->window))
        process_game_loop(game);
}

int init_game(game_data_t *game)
{
    init_keybinds(game);
    load_settings(game);
    if (init_partie_one(game) == RET_FAIL)
        return destroy_game_data(game, RET_FAIL);
    sfRenderWindow_setFramerateLimit(game->window, game->fps);
    icon_loader(game);
    dprintf(1, "sa_x = %d\n", game->settings.sa_x);
    dprintf(1, "Start game loop\n");
    start_game_loop(game);
    dprintf(1, "Game loop ended\n");
    dprintf(1, "sa_x = %d\n", game->settings.sa_x);
    save_global_settings(game);
    return destroy_game_data(game, RET_NONE);
}
