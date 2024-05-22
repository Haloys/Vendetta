/*
** EPITECH PROJECT, 2024
** Vendetta / Header
** File description:
** State
*/

#ifndef UTILS_H
    #define UTILS_H

    #include "my_game.h"

void change_game_mode(game_data_t *game, state_t new_mode);
bool is_rect(int x, int y, rect_t *rect);

#endif /* UTILS_H */
