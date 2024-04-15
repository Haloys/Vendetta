/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** my_radar project
*/

#include <stdio.h>
#include "my_game.h"
#include "my.h"

void p_mouse_button_pressed(game_data_t *game, sfMouseButtonEvent evt)
{
    my_printf("Mouse click playing => x: %d y: %d\n", evt.x, evt.y);
}
