/*
** EPITECH PROJECT, 2024
** Vendetta / Main Menu / Settings
** File description:
** Settings Utils
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "my_game.h"
#include "my.h"

void set_utils_text(game_data_t *game)
{
    sfVector2f text_pos1 = {132, 272};
    sfVector2f text_pos2 = {132, 333};
    sfVector2f text_pos3 = {132, 394};
    sfText *text1;
    sfText *text2;
    sfText *text3;

    text1 = set_text(game, "Frames per second", 22, text_pos1);
    text2 = set_text(game, "Render resolution", 22, text_pos2);
    text3 = set_text(game, "Window mode", 22, text_pos3);
    sfRenderWindow_drawText(game->window, text1, NULL);
    sfRenderWindow_drawText(game->window, text2, NULL);
    sfRenderWindow_drawText(game->window, text3, NULL);
    sfText_destroy(text1);
    sfText_destroy(text2);
    sfText_destroy(text3);
}
