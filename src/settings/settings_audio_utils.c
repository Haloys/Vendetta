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

void init_slider_music(slider_t *slider, sfVector2f position, float min, float max)
{
    slider->min_music = min;
    slider->max_music = max;
    slider->pos_music = position;
    slider->bg_music = sfRectangleShape_create();
    sfRectangleShape_setSize(slider->bg_music, (sfVector2f){243.0f, 5.0f});
    sfRectangleShape_setFillColor(slider->bg_music,
        sfColor_fromRGB(180, 180, 180));
    sfRectangleShape_setPosition(slider->bg_music, position);
    slider->thumb_music = sfCircleShape_create();
    sfCircleShape_setRadius(slider->thumb_music, 5.0f);
    sfCircleShape_setFillColor(slider->thumb_music,
        sfColor_fromRGB(255, 255, 255));
    sfCircleShape_setPosition(slider->thumb_music, (sfVector2f)
        {position.x - 5.0f, position.y});
    slider->value_music = min;
}

void update_slider_music(game_data_t *const game, slider_t *slider)
{
    sfVector2f mouse_pos = game->mouse_pos;
    sfFloatRect thumb_bounds = sfCircleShape_getGlobalBounds(slider->thumb_music);
    sfFloatRect bg_bnd = sfRectangleShape_getGlobalBounds(slider->bg_music);
    float new_pos;
    float normalized_pos;

    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (sfFloatRect_contains(&thumb_bounds, mouse_pos.x, mouse_pos.y) ||
            sfFloatRect_contains(&bg_bnd, mouse_pos.x, mouse_pos.y)) {
            new_pos = mouse_pos.y - slider->pos_music.x;
            new_pos = fmax(0, fmin(new_pos, 243.0f));
            sfCircleShape_setPosition(slider->thumb_music,
            (sfVector2f){slider->pos_music.x - 5.0f,
                slider->pos_music.y + new_pos});
            normalized_pos = 1.0f - (new_pos / 243.0f);
            slider->value_music = slider->min_music +
                (slider->max_music - slider->min_music) * normalized_pos;
        }
    }
}

void init_slider_global(slider_t *slider, sfVector2f position, float min, float max)
{
    slider->min_global = min;
    slider->max_global = max;
    slider->pos_global = position;
    slider->bg_global = sfRectangleShape_create();
    sfRectangleShape_setSize(slider->bg_global, (sfVector2f){243.0f, 5.0f});
    sfRectangleShape_setFillColor(slider->bg_global,
        sfColor_fromRGB(180, 180, 180));
    sfRectangleShape_setPosition(slider->bg_global, position);
    slider->thumb_global = sfCircleShape_create();
    sfCircleShape_setRadius(slider->thumb_global, 5.0f);
    sfCircleShape_setFillColor(slider->thumb_global,
        sfColor_fromRGB(255, 255, 255));
    sfCircleShape_setPosition(slider->thumb_global, (sfVector2f)
        {position.x - 5.0f, position.y});
    slider->value_global = min;
}

void update_slider_global(game_data_t *const game, slider_t *slider)
{
    sfVector2f mouse_pos = game->mouse_pos;
    sfFloatRect thumb_bounds = sfCircleShape_getGlobalBounds(slider->thumb_global);
    sfFloatRect bg_bnd = sfRectangleShape_getGlobalBounds(slider->bg_global);
    float new_pos;
    float normalized_pos;

    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (sfFloatRect_contains(&thumb_bounds, mouse_pos.x, mouse_pos.y) ||
            sfFloatRect_contains(&bg_bnd, mouse_pos.x, mouse_pos.y)) {
            new_pos = mouse_pos.y - slider->pos_global.x;
            new_pos = fmax(0, fmin(new_pos, 243.0f));
            sfCircleShape_setPosition(slider->thumb_global,
            (sfVector2f){slider->pos_global.x - 5.0f,
                slider->pos_global.y + new_pos});
            normalized_pos = 1.0f - (new_pos / 243.0f);
            slider->value_global = slider->min_global +
                (slider->max_global - slider->min_global) * normalized_pos;
        }
    }
}

void draw_slider(slider_t *sl, game_data_t *game)
{
    sfRenderWindow_drawRectangleShape(game->window, sl->bg_music, NULL);
    sfRenderWindow_drawCircleShape(game->window, sl->thumb_music, NULL);
    sfRenderWindow_drawRectangleShape(game->window, sl->bg_global, NULL);
    sfRenderWindow_drawCircleShape(game->window, sl->thumb_global, NULL);
    sfRenderWindow_drawRectangleShape(game->window, sl->bg_ambient, NULL);
    sfRenderWindow_drawCircleShape(game->window, sl->thumb_ambient, NULL);
}
