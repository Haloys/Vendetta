/*
** EPITECH PROJECT, 2024
** Vendetta / Game Engine
** File description:
** Free game data
*/

#include "my_game.h"
#include "entity.h"

void draw_entity(game_data_t *game, item_entity_t *entity)
{
    sfSprite_setPosition(entity->sprite, entity->position);
    sfRenderWindow_drawSprite(game->window, entity->sprite, NULL);
}
