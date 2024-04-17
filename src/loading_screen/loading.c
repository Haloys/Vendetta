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
    sfVector2f text_pos = {750, 200};

    for (size_t i = 0; i < element_count; i++) {
        sfRenderWindow_drawSprite(game->window, get_sprite(game, elements[i]), NULL);
    }
    text = set_text(game, "POWERED BY", 30, text_pos);
    sfText_setLetterSpacing(text, 10.0f);
    sfText_setStyle(text, sfTextBold);
    sfRenderWindow_drawText(game->window, text, NULL);
    sfText_destroy(text);
}

void start_load_two(game_data_t *game)
{
    sprite_id_t elements[] = {SP_LOADING_2, SP_DEV_1, SP_DEV_2, SP_DEV_3,
        SP_DEV_4};
    int element_count = 5;
    sfText *text;
    sfVector2f text_pos = {750, 200};

    for (size_t i = 0; i < element_count; i++) {
        sfRenderWindow_drawSprite(game->window, get_sprite(game, elements[i]), NULL);
    }
    text = set_text(game, "CREATED BY", 30, text_pos);
    sfText_setLetterSpacing(text, 10.0f);
    sfText_setStyle(text, sfTextBold);
    sfRenderWindow_drawText(game->window, text, NULL);
    sfText_destroy(text);
}

void start_load_third(game_data_t *game)
{
    sprite_id_t elements[] = {SP_LOADING_3, SP_VENDETTA_T};
    int element_count = 2;
    sfText *text;
    sfVector2f text_pos = {785, 153};

    for (size_t i = 0; i < element_count; i++) {
        sfRenderWindow_drawSprite(game->window, get_sprite(game, elements[i]), NULL);
    }
    text = set_text(game, "PRESENTS", 24, text_pos);
    sfText_setLetterSpacing(text, 14.5f);
    sfText_setStyle(text, sfTextBold);
    sfRenderWindow_drawText(game->window, text, NULL);
    sfText_destroy(text);
}

void launch_loading(game_data_t *game)
{
    start_load_third(game);
}
