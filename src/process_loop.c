/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** my_radar project
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_game.h"
#include "my.h"

static void process_loop_main_menu(game_data_t *game)
{
    return;
}

static void process_loop_update(game_data_t *game, float elapsed)
{
    switch (game->state) {
    case LOADING_SCREEN:
        launch_loading(game);
        break;
    case MAIN_MENU:
        basic_play(game);
        break;
    case SETTINGS:
        basic_settings(game);
        break;
    case HELP:
        basic_help(game);
        break;
    case PLAYING:
        clock_update(&game->delay_clock, elapsed);
        if (game->opts.paused)
            elapsed = 0.f;
        process_loop_in_game(game, elapsed);
        break;
    case INVENTORY:
        basic_inventory(game);
        break;
    case PAUSE:
        break;
    }
}

void set_mouse_pos(game_data_t *game)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f map_pos = sfRenderWindow_mapPixelToCoords(game->window,
        mouse_pos, sfRenderWindow_getView(game->window));

    game->mouse_pos = map_pos;
}

void process_game_loop(game_data_t *game)
{
    float elapsed = sfTime_asSeconds(sfClock_getElapsedTime(game->clock))
        * game->speed;

    sfRenderWindow_clear(game->window, sfBlack);
    process_events(game);
    process_loop_update(game, elapsed - game->last_update);
    game->last_update = elapsed;
    sfRenderWindow_display(game->window);
}
