/*
** EPITECH PROJECT, 2024
** Vendetta / Header
** File description:
** Ending Screen
*/

#ifndef ENDING_SCREEN_H
    #define ENDING_SCREEN_H

    #include <time.h>
    #include <stdlib.h>

typedef struct {
    char **credits;
    size_t line_count;
    float y_offset;
    int state;
    time_t end_wait_time;
} ending_screen_t;

typedef struct {
    char **credits;
    size_t line_count;
    float y_offset;
    sfFont *font;
} credits_data_t;

void display_ending_screen(game_data_t *game);

#endif /* !ENDING_SCREEN_H */
