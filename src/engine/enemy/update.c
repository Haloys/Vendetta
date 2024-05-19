/*
** EPITECH PROJECT, 2024
** Vendetta / Game Engine
** File description:
** Animation
*/

#include <math.h>

#include "gameplay.h"
#include "enemies.h"

void update_enemy_pos_diretion(enemy_t *enemy, game_data_t *game)
{
    sfVector2f pos = sfSprite_getPosition(enemy->sprite);
    sfVector2f player_pos = game->player->position;
    float angle = atan2(player_pos.y - pos.y, player_pos.x - pos.x);
    float distance = sqrt(pow(player_pos.x - pos.x, 2) +
        pow(player_pos.y - pos.y, 2));

    if (distance < 200 && distance > 50) {
        enemy->position.x += cos(angle) * enemy->speed;
        enemy->position.y += sin(angle) * enemy->speed;
        enemy->rotation = (angle * 180 / PI) + 90;
        enemy->sprite = get_sprite(game, SP_ENEMY_EZ_SHOOTING);
        enemy->sprite_data = &SPRITES[SP_ENEMY_EZ_SHOOTING];
    } else {
        enemy->sprite = get_sprite(game, SP_ENEMY_EZ_IDLE);
        enemy->sprite_data = &SPRITES[SP_ENEMY_EZ_IDLE];
    }
}

void update_enemy_pos_sprite(enemy_t *enemy)
{
    sfSprite_setPosition(enemy->sprite, enemy->position);
    sfCircleShape_setPosition(enemy->area, enemy->position);
    sfCircleShape_setOrigin(enemy->area, (sfVector2f){200, 200});
    sfSprite_setRotation(enemy->sprite, enemy->rotation);
    sfRectangleShape_setPosition(enemy->health_bar,
        (sfVector2f){enemy->position.x - 50, enemy->position.y - 50});
}
