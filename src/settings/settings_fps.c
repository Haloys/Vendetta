/*
** EPITECH PROJECT, 2024
** B-MUL-200-PAR-2-1-myrpg-maxence.bunel
** File description:
** settings_fps
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "my_game.h"
#include "my.h"

void load_arrow(game_data_t *game)
{
    sprite_id_t elements[] = {SP_ARROW_R1, SP_ARROW_L1, SP_ARROW_R2,
        SP_ARROW_L2, SP_ARROW_R3, SP_ARROW_L3};
    int element_count = 6;

    for (int i = 0; i < element_count; i++) {
        sfRenderWindow_drawSprite(game->window,
            get_sprite(game, elements[i]), NULL);
    }
}

void set_fps_text(game_data_t *game)
{
    sfVector2f text_pos = {621, 273};
    sfText *text;
    char buffer[10];

    sprintf(buffer, "%d", game->fps);
    text = set_text(game, buffer, 22, text_pos);
    sfRenderWindow_drawText(game->window, text, NULL);
    sfText_destroy(text);
}

void arrow_r_fps(game_data_t *game)
{
    if (game->fps == 30)
        game->fps = 60;
    if (game->fps == 60)
        game->fps = 90;
    if (game->fps == 90)
        game->fps = 120;
    if (game->fps == 120)
        game->fps = 144;
    if (game->fps == 144)
        game->fps = 30;
}

void arrow_l_fps(game_data_t *game)
{
    if (game->fps == 30)
        game->fps = 144;
    if (game->fps == 60)
        game->fps = 30;
    if (game->fps == 90)
        game->fps = 60;
    if (game->fps == 120)
        game->fps = 90;
    if (game->fps == 144)
        game->fps = 120;
}
