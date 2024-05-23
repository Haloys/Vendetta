/*
** EPITECH PROJECT, 2024
** Vendetta / Game Engine
** File description:
** Animation
*/

#include <math.h>
#include <stdio.h>

#include "gameplay.h"
#include "enemies.h"
#include "entity.h"
#include "utils.h"

void update_enemy_pos_diretion(enemy_t *enemy, game_data_t *game, sfTime time)
{
    sfVector2f pos = sfSprite_getPosition(enemy->sprite);
    sfVector2f player_pos = game->player->position;
    float angle = atan2(player_pos.y - pos.y, player_pos.x - pos.x);
    float distance = sqrt(pow(player_pos.x - pos.x, 2) +
        pow(player_pos.y - pos.y, 2));

    enemy->direction = (sfVector2f){cos(angle), sin(angle)};
    enemy->target = enemy->direction;
    enemy->rotation = (angle * 180 / PI) + 90;
    if ((distance < 250 && distance > 50)
        || !will_collide_wall(game, &enemy->position, &enemy->direction)) {
        walk_to_nearest_point(enemy, game, time);
    }
}

void update_enemy_pos_sprite(enemy_t *enemy)
{
    sfSprite_setPosition(enemy->sprite, enemy->position);
    sfCircleShape_setPosition(enemy->area, enemy->position);
    sfCircleShape_setOrigin(enemy->area, (sfVector2f){250, 250});
    sfSprite_setRotation(enemy->sprite, enemy->disp_rotation);
    sfRectangleShape_setSize(enemy->health_bar,
        (sfVector2f){enemy->health, 10});
    sfRectangleShape_setPosition(enemy->health_bar,
        (sfVector2f){enemy->position.x - 50, enemy->position.y - 50});
}
