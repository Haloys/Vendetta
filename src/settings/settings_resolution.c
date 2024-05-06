/*
** EPITECH PROJECT, 2024
** B-MUL-200-PAR-2-1-myrpg-maxence.bunel
** File description:
** settings_resolution
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "my_game.h"
#include "my.h"
#include "score.h"

void set_reso_text(game_data_t *game)
{
    sfVector2f text_pos = {583, 395};
    sfText *text;

    if (game->is_fullscreen == true)
        text = set_text(game, "Full Screen", 22, text_pos);
    if (game->is_fullscreen == false)
        text = set_text(game, "Windowed", 22, text_pos);
    sfRenderWindow_drawText(game->window, text, NULL);
    sfText_destroy(text);
}

void set_reso(game_data_t *game)
{
    if (game->is_fullscreen == true) {
        game->is_fullscreen = false;
        return;
    }
    if (game->is_fullscreen == false) {
        game->is_fullscreen = true;
        return;
    }
}
