/*
** EPITECH PROJECT, 2024
** Vendetta / Header
** File description:
** Gameplay
*/

#ifndef GAMEPLAY_H
    #define GAMEPLAY_H

    #include "my_game.h"

void process_events(game_data_t *game);
void process_player_key_event(game_data_t *game, sfEvent *evt);

#endif /* GAMEPLAY_H */
