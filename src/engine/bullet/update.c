/*
** EPITECH PROJECT, 2024
** Vendetta / Game Engine
** File description:
** Animation
*/

#include "my_game.h"
#include "gameplay.h"
#include "enemies.h"

void update_bullet(game_data_t *game, bullet_t *bullet)
{
    bullet->position.x += bullet->direction.x * BULLET_MEDIUM_SPEED;
    bullet->position.y += bullet->direction.y * BULLET_MEDIUM_SPEED;
    sfSprite_setPosition(bullet->sprite, bullet->position);
    sfSprite_setRotation(bullet->sprite, bullet->rotation);
}
