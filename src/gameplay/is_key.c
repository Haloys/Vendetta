/*
** EPITECH PROJECT, 2024
** Vendetta
** File description:
** Process gameplay loop
*/

#include <math.h>

#include "my_game.h"
#include "gameplay.h"

bool is_key_down(game_data_t *game, keybinds_t key)
{
    return (1 << key) & game->key_state;
}

bool is_key_pressed(game_data_t *game, keybinds_t key)
{
    return (1 << key) & game->key_change & game->key_state;
}

void reset_key_update(game_data_t *game)
{
    game->key_update = 0;
}

void after_key_update(game_data_t *game)
{
    game->key_change &= game->key_update;
}
