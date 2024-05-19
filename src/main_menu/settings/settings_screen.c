/*
** EPITECH PROJECT, 2024
** Vendetta / Main Menu / Settings
** File description:
** Settings Screen
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "my_game.h"

void set_screen_text(game_data_t *game)
{
    sfVector2f text_pos = {570, 335};
    sfText *text;

    if (game->video_mode.width == 1920)
        text = set_text(game, "1920 x 1080p", 22, text_pos);
    if (game->video_mode.width == 1600)
        text = set_text(game, "1600 x 900p", 22, text_pos);
    if (game->video_mode.width == 1366)
        text = set_text(game, "1366 x 768p", 22, text_pos);
    sfRenderWindow_drawText(game->window, text, NULL);
    sfText_destroy(text);
}

void set_screen_size(game_data_t *game)
{
    if (game->video_mode.width == 1920) {
        game->video_mode = (sfVideoMode){1600, 900, 32};
        return;
    }
    if (game->video_mode.width == 1600) {
        game->video_mode = (sfVideoMode){1366, 768, 32};
        return;
    }
    if (game->video_mode.width == 1366) {
        game->video_mode = (sfVideoMode){1920, 1080, 32};
        return;
    }
}
