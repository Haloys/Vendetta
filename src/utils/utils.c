/*
** EPITECH PROJECT, 2024
** Vendetta
** File description:
** Initialize the game
*/

#include <stdio.h>

#include "my_game.h"

void change_game_mode(game_data_t *game, state_t new_mode)
{
    if (game->state != new_mode) {
        printf("Changing mode to %d\n", new_mode);
        sfView_setCenter(game->menu_view, (sfVector2f){WINDOW_WIDTH / 2,
            WINDOW_HEIGHT / 2});
        sfRenderWindow_setView(game->window, game->menu_view);
        game->state = new_mode;
    }
}
