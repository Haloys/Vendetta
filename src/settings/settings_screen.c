/*
** EPITECH PROJECT, 2024
** B-MUL-200-PAR-2-1-myrpg-maxence.bunel
** File description:
** settings_screen
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "my_game.h"
#include "my.h"
#include "score.h"

void set_screen_text(game_data_t *game)
{
    sfVector2f text_pos = {621, 271};
    sfText *text;
    char buffer[10];

    sprintf(buffer, "%d", game->fps);
    text = set_text(game, buffer, 26, text_pos);
    sfRenderWindow_drawText(game->window, text, NULL);
    sfText_destroy(text);
}