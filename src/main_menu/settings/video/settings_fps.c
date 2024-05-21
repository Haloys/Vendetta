/*
** EPITECH PROJECT, 2024
** Vendetta / Main Menu / Settings
** File description:
** Settings Fps
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "my_game.h"

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
