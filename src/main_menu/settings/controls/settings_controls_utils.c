/*
** EPITECH PROJECT, 2024
** B-MUL-200-PAR-2-1-myrpg-maxence.bunel
** File description:
** settings_controls_utils
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "gameplay.h"

void draw_tools_control(game_data_t *game, sfRectangleShape *rect,
    int i)
{
    if (i == game->settings.clicked_control) {
        sfRectangleShape_setFillColor(rect,
            sfColor_fromRGBA(255, 255, 255, 20));
        sfRectangleShape_setOutlineThickness(rect, 2);
        sfRectangleShape_setOutlineColor(rect,
            sfColor_fromRGB(51, 217, 122));
    } else {
        sfRectangleShape_setFillColor(rect,
            sfColor_fromRGBA(255, 255, 255, 0));
    }
    sfRenderWindow_drawRectangleShape(game->window, rect, NULL);
    sfRectangleShape_destroy(rect);
}
