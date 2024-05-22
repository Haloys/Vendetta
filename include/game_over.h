/*
** EPITECH PROJECT, 2024
** Vendetta / Header
** File description:
** Clock
*/

#ifndef GAME_OVER_H
    #define GAME_OVER_H

    #include "my_game.h"

typedef struct game_over_elems_s {
    sfRectangleShape *quit_btn;
    sfRectangleShape *respawn_btn;
    sfText *quit_txt;
    sfText *respawn_txt;
} game_over_elems_t;

#endif /* !GAME_OVER_H */
