/*
** EPITECH PROJECT, 2024
** Vendetta / Main Menu
** File description:
** Hover Main Menu
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "my_game.h"

void set_hover_save_button(game_data_t *game)
{
    if (game->state == MAIN_MENU) {
        if (game->validation_count >= 3) {
            game->hover_save_button = false;
        } else {
            game->hover_save_button = (game->mouse_pos.x >= 147 &&
            game->mouse_pos.x <= 382 &&
            game->mouse_pos.y >= 148 && game->mouse_pos.y <= 198);
        }
    }
}

void set_hover_game_slots(game_data_t *game)
{
    if (game->state == MAIN_MENU) {
        game->hover_slot_array[0] = (game->mouse_pos.x >= 147 &&
        game->mouse_pos.x <= 599 &&
        game->mouse_pos.y >= 241 && game->mouse_pos.y <= 870);
        game->hover_slot_array[1] = (game->mouse_pos.x >= 734 &&
        game->mouse_pos.x <= 1186 &&
        game->mouse_pos.y >= 241 && game->mouse_pos.y <= 870);
        game->hover_slot_array[2] = (game->mouse_pos.x >= 1321 &&
        game->mouse_pos.x <= 1773 &&
        game->mouse_pos.y >= 241 && game->mouse_pos.y <= 870);
    }
}

void determine_button_colors(game_data_t *game, sfColor *fill_color,
    sfColor *outline_color)
{
    if (game->hover_save_button) {
        *fill_color = sfColor_fromRGBA(51, 217, 122, 128);
        *outline_color = sfColor_fromRGBA(51, 217, 122, 255);
    } else if (game->validation_count >= 3) {
        *fill_color = sfColor_fromRGBA(242, 115, 132, 51);
        *outline_color = sfColor_fromRGBA(242, 115, 132, 128);
    } else {
        *fill_color = sfColor_fromRGBA(51, 217, 122, 51);
        *outline_color = sfColor_fromRGBA(51, 217, 122, 128);
    }
}
