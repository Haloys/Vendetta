/*
** EPITECH PROJECT, 2024
** B-MUL-200-PAR-2-1-myrpg-maxence.bunel [WSL: Ubuntu]
** File description:
** inventory_utils
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "my_game.h"
#include "inventory.h"
#include "items.h"

void handle_hover(sfRectangleShape* square, sfVector2i mouse_pos)
{
    sfFloatRect bounds = sfRectangleShape_getGlobalBounds(square);

    if (sfFloatRect_contains(&bounds, mouse_pos.x, mouse_pos.y)) {
        sfRectangleShape_setOutlineColor(square, BORDER_HOVER);
    } else {
        sfRectangleShape_setOutlineColor(square, BORDER);
    }
}

sfRectangleShape *create_rectangle(game_data_t *game, sfVector2f pos,
    int sizex, int sizey)
{
    sfRectangleShape *rectangle = sfRectangleShape_create();

    sfRectangleShape_setPosition(rectangle, pos);
    sfRectangleShape_setSize(rectangle, (sfVector2f){sizex, sizey});
    sfRectangleShape_setFillColor(rectangle, SQUARE_BG);
    sfRectangleShape_setOutlineThickness(rectangle, 2);
    handle_hover(rectangle, sfMouse_getPositionRenderWindow(game->window));
    sfRenderWindow_drawRectangleShape(game->window, rectangle, NULL);
    return rectangle;
}

int is_valid_weight(game_data_t *game, float added_weight)
{
    if (game->player_data->inventory->total_weight + added_weight > 25) {
        return 0;
    }
    return 1;
}

void update_inventory_weight(game_data_t *game)
{
    game->player_data->inventory->total_weight = 0;
    for (int i = 0; i < 29; i++) {
        if (game->player_data->inventory->slots[i].item != NULL) {
            game->player_data->inventory->total_weight +=
                game->player_data->inventory->slots[i].weight;
        }
    }
}

item_t *get_item_by_name(char *item_name)
{
    for (size_t i = 0; i < ITEM_COUNT; i++) {
        if (strcmp(ITEMS[i].name, item_name) == 0) {
            return (&ITEMS[i]);
        }
    }
    return NULL;
}
