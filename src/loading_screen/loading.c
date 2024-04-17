/*
** EPITECH PROJECT, 2024
** B-MUL-200-PAR-2-1-myrpg-maxence.bunel
** File description:
** loading
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "my_game.h"
#include "my.h"
#include "score.h"

void start_load_one(game_data_t *game)
{
    sprite_id_t elements[] = {SP_LOADING_1, SP_FLAVIBOT, SP_ORA, SP_TRYADE};
    int element_count = 4;
    sfText *text;
    sfVector2f text_pos = {700, 200};

    for (size_t i = 0; i < element_count; i++) {
        sfRenderWindow_drawSprite(game->window, get_sprite(game, elements[i]), NULL);
    }
    text = set_text(game, "POWERED BY", 38, text_pos);
    sfText_setLetterSpacing(text, 10.0f);
    sfText_setStyle(text, sfTextBold);
    sfRenderWindow_drawText(game->window, text, NULL);
    sfText_destroy(text);
}

void launch_loading(game_data_t *game)
{
    start_load_one(game);
}
