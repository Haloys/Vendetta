/*
** EPITECH PROJECT, 2024
** Vendetta / Game Engine
** File description:
** Free game data
*/

#include <math.h>
#include <stdio.h>

#include "my_game.h"
#include "entity.h"

void draw_entity(game_data_t *game, item_entity_t *entity)
{
    sfVector2f pos = entity->position;
    sfVector2f player_pos = game->player->position;
    float distance = sqrt(pow(player_pos.x - pos.x, 2) +
        pow(player_pos.y - pos.y, 2));

    if (distance < 100 && entity->config->callback_interact != NULL) {
        if (is_key_pressed(game, Interact)) {
            printf("Pickup %s\n", entity->config->name);
            entity->config->callback_interact(game, entity);
        }
    }
    sfSprite_setPosition(entity->sprite, entity->position);
    sfRenderWindow_drawSprite(game->window, entity->sprite, NULL);
}
