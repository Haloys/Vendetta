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
