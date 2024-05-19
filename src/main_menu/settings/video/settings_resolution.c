/*
** EPITECH PROJECT, 2024
** Vendetta / Main Menu / Settings
** File description:
** Settings Resolution
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "my_game.h"
#include "my.h"

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
    if (game->is_fullscreen == false) {
        sfRenderWindow_destroy(game->window);
        game->window = sfRenderWindow_create(game->video_mode, game->name,
            sfFullscreen, NULL);
        game->is_fullscreen = true;
        return;
    }
    if (game->is_fullscreen == true) {
        sfRenderWindow_destroy(game->window);
        game->window = sfRenderWindow_create(game->video_mode, game->name,
            sfResize | sfClose, NULL);
        game->is_fullscreen = false;
        return;
    }
}
