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
    sfRectangleShape *quit_button;
    sfRectangleShape *respawn_button;
    sfText *quit_txt;
    sfText *respawn_txt;
} game_over_elems_t;

typedef struct button_data_s {
    sfVector2f button_size;
    sfVector2f position;
    sfRectangleShape **button;
    sfText **text;
} button_data_t;

#endif /* !GAME_OVER_H */
