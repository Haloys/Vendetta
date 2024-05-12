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

static void process_loop_update(game_data_t *game)
{
    switch (game->state) {
    case LOADING_SCREEN:
        launch_loading(game);
        break;
    case MAIN_MENU:
        basic_play(game);
        break;
    case SETTINGS_VIDEO:
        basic_settings(game);
        break;
    case SETTINGS_CONTROLS:
        draw_settings_navbar(game);
        break;
    case SETTINGS_AUDIO:
        draw_settings_navbar(game);
        break;
    case HELP:
        basic_help(game);
        break;
    case PLAYING:
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
    sfRenderWindow_clear(game->window, sfBlack);
    process_events(game);
    process_loop_update(game);
    sfRenderWindow_display(game->window);
}
