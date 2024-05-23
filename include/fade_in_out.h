/*
** EPITECH PROJECT, 2024
** Vendetta / Header
** File description:
** Fade In Out
*/

#ifndef FADE_IN_OUT_H_
    #define FADE_IN_OUT_H_

    #include "my_game.h"

typedef struct fade_in_params_s {
    sfRenderWindow *window;
    sfSprite **sprites;
    int sprite_count;
    sfText *text;
    sfClock *clock;
    int fade_duration_ms;
} fade_in_params_t;

typedef struct fade_in_out_params_s {
    sfRenderWindow *window;
    sfSprite **sprites;
    int sprite_count;
    sfText *text;
    sfClock *clock;
    int fade_duration_ms;
    int total_duration_ms;
    int fade_out_start_ms;
} fade_in_out_params_t;

void do_check(game_data_t *game, sfRenderWindow *window, int *ret);
void fade_in_all(game_data_t *game, fade_in_params_t *params, int *ret);
void fade_in_out_all(game_data_t *game, fade_in_out_params_t *params, int *ret);

#endif /* !FADE_IN_OUT_H_ */
