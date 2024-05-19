/*
** EPITECH PROJECT, 2024
** Vendetta
** File description:
** Initialize the game
*/

#include "my_game.h"

void change_game_mode(game_data_t *game, state_t new_mode)
{
    game->state = new_mode;
}
