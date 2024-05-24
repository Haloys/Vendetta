/*
** EPITECH PROJECT, 2024
** Vendetta
** File description:
** Process gameplay loop
*/

#include <stdio.h>
#include <math.h>
#include <string.h>

#include "my_game.h"
#include "map.h"
#include "enemies.h"
#include "player.h"
#include "gameplay.h"
#include "game_npc.h"
#include "utils.h"

static void doors_create_visual(game_data_t *game, door_t *door,
    sfRectangleShape *square, sfText *keybind_text)
{
    sfText_setFont(keybind_text, game->font);
    sfText_setCharacterSize(keybind_text, 22);
    strcpy(door->key, key_to_string(game->keybinds[Interact].code));
    sfText_setString(keybind_text, door->key);
    sfRectangleShape_setSize(square, (sfVector2f){40, 40});
    sfRectangleShape_setOutlineThickness(square, 2);
    if (get_item_quantity(game, door->item) > 0) {
        sfRectangleShape_setFillColor(square, FILL_COLOR);
        sfRectangleShape_setOutlineColor(square, BORDER_HOVER);
    } else {
        sfRectangleShape_setFillColor(square, RED_BTN_BG);
        sfRectangleShape_setOutlineColor(square, RED_BTN_OUTLINE);
    }
}

void draw_doors(game_data_t *game, door_t *door, rect_t *rect)
{
    sfVector2f player_pos = game->player->position;
    float distance = sqrt(pow(player_pos.x - door->rect.x, 2) +
        pow(player_pos.y - door->rect.y, 2));
    sfRectangleShape *square = NULL;
    sfText *keybind_text = NULL;

    if (distance > 90)
        return;
    square = sfRectangleShape_create();
    keybind_text = sfText_create();
    if (square == NULL || keybind_text == NULL)
        return;
    doors_create_visual(game, door, square, keybind_text);
    sfText_setPosition(keybind_text, (sfVector2f)
        {rect->x + 18, rect->y + 15});
    sfRectangleShape_setPosition(square, (sfVector2f)
        {rect->x + 7, rect->y + 6});
    sfRenderWindow_drawRectangleShape(game->window, square, NULL);
    sfRenderWindow_drawText(game->window, keybind_text, NULL);
    sfRectangleShape_destroy(square);
    sfText_destroy(keybind_text);
}
