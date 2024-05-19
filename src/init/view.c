/*
** EPITECH PROJECT, 2024
** Vendetta
** File description:
** Main
*/

#include "my_game.h"

int init_game_view(game_data_t *game)
{
    game->game_view = sfView_createFromRect(
        (sfFloatRect){0, 0, WINDOW_WIDTH, WINDOW_HEIGHT});
    if (game->game_view == NULL)
        return RET_FAIL;
    game->view_zoom = 1;
    game->target_zoom = 1;
    return RET_NONE;
}

int init_menu_view(game_data_t *game)
{
    game->menu_view = sfView_createFromRect(
        (sfFloatRect){0, 0, WINDOW_WIDTH, WINDOW_HEIGHT});
    if (game->menu_view == NULL)
        return RET_FAIL;
    return RET_NONE;
}
