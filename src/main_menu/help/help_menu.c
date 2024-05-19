/*
** EPITECH PROJECT, 2024
** Vendetta / Main Menu / Help Menu
** File description:
** Help
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "my_game.h"
#include "main_menu.h"

void draw_help_texts(game_data_t *game)
{
    sprite_id_t elements[] = {SP_DIALOGUES};
    int element_count = 1;
    sfSprite *sprites[element_count];

    for (int i = 0; i < element_count; i++) {
        sprites[i] = get_sprite(game, elements[i]);
    }
    for (int i = 0; i < element_count; i++) {
        sfRenderWindow_drawSprite(game->window, sprites[i], NULL);
    }
}

void basic_help(game_data_t *game)
{
    basic_menu(game);
    draw_help_texts(game);
    draw_active_navbar_line(game, 560.0f, 200.0f);
}
