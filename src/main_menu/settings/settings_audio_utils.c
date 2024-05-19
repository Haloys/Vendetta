/*
** EPITECH PROJECT, 2024
** B-MUL-200-PAR-2-1-myrpg-maxence.bunel
** File description:
** settings_audio
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "my_game.h"

static void change_volume(game_data_t *game, int sound)
{
    if (sound != 0) {
        if (game->clicked_rect_index == 0)
            game->sg_x += sound;
        if (game->clicked_rect_index == 1)
            game->sm_x += sound;
        if (game->clicked_rect_index == 2)
            game->sa_x += sound;
    }
}

void modify_sound(game_data_t *game)
{
    int sound = 0;

    if (is_key_pressed(game, MoveDown) && game->state == SETTINGS_AUDIO) {
        game->clicked_rect_index++;
        game->clicked_rect_index %= 3;
    }
    if (is_key_pressed(game, MoveLeft) && game->state == SETTINGS_AUDIO) {
        sound -= 5;
    }
    if (is_key_pressed(game, MoveRight) && game->state == SETTINGS_AUDIO) {
        sound += 5;
    }
    change_volume(game, sound);
    game->sm_x = CLAMP(game->sm_x, 0, 243);
    game->sg_x = CLAMP(game->sg_x, 0, 243);
    game->sa_x = CLAMP(game->sa_x, 0, 243);
}

void draw_tools(game_data_t *game, sfRectangleShape *rect, int i)
{
    if (i == game->clicked_rect_index) {
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
