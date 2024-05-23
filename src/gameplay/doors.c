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

static void doors_create_visual(game_data_t *game, door_t *doors)
{
    doors->keybind_text = sfText_create();
    sfText_setFont(doors->keybind_text, game->font);
    sfText_setCharacterSize(doors->keybind_text, 22);
    strcpy(doors->key, key_to_string(game->keybinds[Interact].code));
    sfText_setString(doors->keybind_text, doors->key);
    doors->square = sfRectangleShape_create();
    sfRectangleShape_setSize(doors->square, (sfVector2f){40, 40});
    sfRectangleShape_setOutlineThickness(doors->square, 2);
    sfRectangleShape_setFillColor(doors->square, FILL_COLOR);
    sfRectangleShape_setOutlineColor(doors->square, BORDER_HOVER);
}

void draw_doors(game_data_t *game, door_t *doors, rect_t *door)
{
    sfVector2f player_pos = game->player->position;
    float distance = sqrt(pow(player_pos.x - doors->rect.x, 2) +
        pow(player_pos.y - doors->rect.y, 2));

    doors_create_visual(game, doors);
    if (distance < 100) {
        sfText_setPosition(doors->keybind_text, (sfVector2f)
            {door->x + 18, door->y + 18});
        sfRectangleShape_setPosition(doors->square, (sfVector2f)
            {door->x + 7, door->y + 18});
        sfRenderWindow_drawRectangleShape(game->window, doors->square, NULL);
        sfRenderWindow_drawText(game->window, doors->keybind_text, NULL);
    }
}
