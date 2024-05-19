/*
** EPITECH PROJECT, 2024
** Vendetta / Game Engine
** File description:
** Utils Two
*/

#include "my_game.h"

void basic_design(game_data_t *game)
{
    sprite_id_t elements[] = {SP_MAIN_BG};
    size_t element_count = 1;

    for (size_t i = 0; i < element_count; i++) {
        sfRenderWindow_drawSprite(game->window,
            get_sprite(game, elements[i]), NULL);
    }
}
