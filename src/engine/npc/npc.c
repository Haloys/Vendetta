/*
** EPITECH PROJECT, 2024
** Vendetta / Game Engine
** File description:
** Animation
*/

#include <math.h>
#include <string.h>
#include <stdio.h>

#include "my_game.h"
#include "game_npc.h"
#include "gameplay.h"
#include "utils.h"

void draw_npc(game_data_t *game, npc_t *npc)
{
    sfSprite_setRotation(npc->sprite, npc->rotation);
    sfSprite_setPosition(npc->sprite, npc->position);
    strcpy(npc->key, key_to_string(game->keybinds[Interact].code));
    sfText_setString(npc->keybind_text, npc->key);
    sfText_setPosition(npc->text, (sfVector2f){npc->position.x - 20,
        npc->position.y - 70});
    sfRectangleShape_setPosition(npc->square,
        (sfVector2f){npc->position.x - 17, npc->position.y - 120});
    sfText_setPosition(npc->keybind_text, (sfVector2f){npc->position.x - 4,
        npc->position.y - 113});
    sfRenderWindow_drawSprite(game->window, npc->sprite, NULL);
}

static void npc_update_animation(npc_t *npc, sfTime time)
{
    sfIntRect rect = {0};

    if (sfTime_asMilliseconds(time) % 10 == 0) {
        rect = sfSprite_getTextureRect(npc->sprite);
        if (rect.left >= npc->sprite_data->rect.width
            * (npc->sprite_data->rect_count - 1))
            rect.left = 0;
        else
            rect.left += npc->sprite_data->rect.width;
        sfSprite_setTextureRect(npc->sprite, rect);
    }
}

void update_npc(game_data_t *game, npc_t *npc)
{
    sfTime time = sfClock_getElapsedTime(game->clock);
    sfVector2f pos = npc->position;
    sfVector2f player_pos = game->player->position;
    float angle = atan2(player_pos.y - pos.y, player_pos.x - pos.x);
    float distance = sqrt(pow(player_pos.x - pos.x, 2) +
        pow(player_pos.y - pos.y, 2));

    npc_update_animation(npc, time);
    if (distance < 130 && distance > 20) {
        npc->rotation = (angle * 180 / PI) + npc->config->rotation_offset;
        sfSprite_setRotation(npc->sprite, npc->rotation);
        sfRenderWindow_drawText(game->window, npc->text, NULL);
        sfRenderWindow_drawRectangleShape(game->window, npc->square, NULL);
        sfRenderWindow_drawText(game->window, npc->keybind_text, NULL);
        if (is_key_pressed(game, Interact))
            npc->config->callback_interact(game, npc);
    }
}
