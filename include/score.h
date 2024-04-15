/*
** EPITECH PROJECT, 2024
** my_score.h
** File description:
** dd
*/

#ifndef SCORE_H
    #define SCORE_H

    #include "my_game.h"

int get_highest_score(void);
void save_highest_score(int highest_score);
void set_score(game_data_t *game, int new_points);

#endif /* SCORE_H */
