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

    #define MOVE_SPEED 10
    #define RADAR_SIZE 30

void process_playing_gameplay(game_data_t *game);

void process_events(game_data_t *game);
void process_playing_event(game_data_t *game, sfEvent *evt);

void process_player_movement(game_data_t *game, sfKeyEvent *key);


// UTILS
sfColor get_pixel_color(sfImage *image, int x, int y);

#endif /* GAMEPLAY_H */
