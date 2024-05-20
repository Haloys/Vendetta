/*
** EPITECH PROJECT, 2024
** Vendetta / Header
** File description:
** My Game
*/

#ifndef MINIGAME_H
    #define MINIGAME_H

    #include "my_game.h"

    #define RECT_WIDTH 1160
    #define RECT_HEIGHT 360
    #define SQUARE_SIZE 150
    #define NUM_SQUARES 14

typedef struct minigame_s {
    int numbers[NUM_SQUARES];
    int current_number;
    bool squares_clicked[NUM_SQUARES];
    sfClock *clock;
    bool game_over;
    bool show_message;
    sfClock *message_clock;
} minigame_t;

bool display_sequence_click(game_data_t *game);

#endif /* MINIGAME_H */
