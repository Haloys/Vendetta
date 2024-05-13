/*
** EPITECH PROJECT, 2024
** Vendetta
** File description:
** Process player events
*/

#include <stdio.h>

#include "my_game.h"
#include "gameplay.h"

void process_playing_event(game_data_t *game, sfEvent *evt)
{
    if (evt->key.code == sfKeyT) {
        printf("T key pressed\n");
    }
    process_player_movement(game, &evt->key);
}
