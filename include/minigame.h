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
    #define PROGRESS_WIDTH 600
    #define PROGRESS_HEIGHT 20

    #define I_RECT_WIDTH 30
    #define BAR_WIDTH 5
    #define BAR_SPEED 500.0f
    #define COOLDOWN_TIME 0.5f

    #define PROGRESS_FILL_COLOR sfColor_fromRGBA(0, 128, 255, 200)
    #define PROGRESS_OUTLINE_COLOR sfColor_fromRGBA(0, 0, 0, 255)

typedef struct minigame_s {
    int numbers[NUM_SQUARES];
    int current_number;
    bool squares_clicked[NUM_SQUARES];
    sfClock *clock;
    bool game_won;
} minigame_t;

typedef struct barhit_s {
    sfRectangleShape *outer_rect;
    sfRectangleShape *inner_rect;
    sfRectangleShape *bar;
    float bar_pos;
    int bar_direction;
    bool game_active;
    float cooldown;
} barhit_t;

void draw_sequence_progress_bar(game_data_t *game, sfTime elapsed);

bool display_sequence_click(game_data_t *game);
bool another_game(game_data_t *game);

#endif /* MINIGAME_H */
