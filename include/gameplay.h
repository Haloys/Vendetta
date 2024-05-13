/*
** EPITECH PROJECT, 2024
** Vendetta / Header
** File description:
** Gameplay
*/

#ifndef GAMEPLAY_H
    #define GAMEPLAY_H

    #include "my_game.h"


    #define VIEW_WIDTH WINDOW_WIDTH / 2
    #define VIEW_HEIGHT WINDOW_HEIGHT / 2

void process_playing_gameplay(game_data_t *game);

void process_events(game_data_t *game);
void process_playing_event(game_data_t *game, sfEvent *evt);

void process_player_movement(game_data_t *game, sfKeyEvent *key);

#endif /* GAMEPLAY_H */
