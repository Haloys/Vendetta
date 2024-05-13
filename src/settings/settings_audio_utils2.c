/*
** EPITECH PROJECT, 2024
** B-MUL-200-PAR-2-1-myrpg-maxence.bunel
** File description:
** settings_audio
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "my_game.h"
#include "my.h"

void init_slider_ambient(slider_t *slider, sfVector2f position, float min, float max)
{
    slider->min_ambient = min;
    slider->max_ambient = max;
    slider->pos_ambient = position;
    slider->bg_ambient = sfRectangleShape_create();
    sfRectangleShape_setSize(slider->bg_ambient, (sfVector2f){243.0f, 5.0f});
    sfRectangleShape_setFillColor(slider->bg_ambient,
        sfColor_fromRGB(180, 180, 180));
    sfRectangleShape_setPosition(slider->bg_ambient, position);
    slider->thumb_ambient = sfCircleShape_create();
    sfCircleShape_setRadius(slider->thumb_ambient, 5.0f);
    sfCircleShape_setFillColor(slider->thumb_ambient,
        sfColor_fromRGB(255, 255, 255));
    sfCircleShape_setPosition(slider->thumb_ambient, (sfVector2f)
        {position.x - 5.0f, position.y});
    slider->value_ambient = min;
}

void update_slider_ambient(game_data_t *const game, slider_t *slider)
{
    sfVector2f mouse_pos = game->mouse_pos;
    sfFloatRect thumb_bounds = sfCircleShape_getGlobalBounds(slider->thumb_ambient);
    sfFloatRect bg_bnd = sfRectangleShape_getGlobalBounds(slider->bg_ambient);
    float new_pos;
    float normalized_pos;

    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (sfFloatRect_contains(&thumb_bounds, mouse_pos.x, mouse_pos.y) ||
            sfFloatRect_contains(&bg_bnd, mouse_pos.x, mouse_pos.y)) {
            new_pos = mouse_pos.y - slider->pos_ambient.x;
            new_pos = fmax(0, fmin(new_pos, 243.0f));
            sfCircleShape_setPosition(slider->thumb_ambient,
            (sfVector2f){slider->pos_ambient.x - 5.0f,
                slider->pos_ambient.y + new_pos});
            normalized_pos = 1.0f - (new_pos / 243.0f);
            slider->value_ambient = slider->min_ambient +
                (slider->max_ambient - slider->min_ambient) * normalized_pos;
        }
    }
}
