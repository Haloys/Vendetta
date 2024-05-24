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

static void enemy_follow_player(enemy_t *enemy, game_data_t *game, sfTime time)
{
    float elapsed = sfTime_asSeconds(time);

    if (can_move_to_point(game, &enemy->position, &enemy->direction,
        &game->player->position) == false)
        return;
    enemy->disp_rotation = enemy->rotation;
    enemy->position.x += enemy->direction.x * ENEMY_MOVE_SPEED * elapsed;
    enemy->position.y += enemy->direction.y * ENEMY_MOVE_SPEED * elapsed;
}

static void process_attack(game_data_t *game, enemy_t *enemy, sfTime time)
{
    switch (enemy->config->attack_type) {
        case A_PATH_FINDING:
            walk_to_nearest_point(enemy, game, time);
            break;
        case A_FIRST:
        case A_EXPLOSION:
            enemy_follow_player(enemy, game, time);
            break;
        default:
            break;
    }
}

void update_enemy_pos_diretion(enemy_t *enemy, game_data_t *game, sfTime time)
{
    sfVector2f pos = enemy->position;
    sfVector2f player_pos = game->player->position;
    float angle = atan2(player_pos.y - pos.y, player_pos.x - pos.x);
    float distance = sqrt(pow(player_pos.x - pos.x, 2) +
        pow(player_pos.y - pos.y, 2));

    enemy->direction = (sfVector2f){cos(angle), sin(angle)};
    enemy->target = enemy->direction;
    enemy->rotation = (angle * 180 / PI) + 90;
    if (game->is_passive && distance > 100 && distance < 250)
        enemy->disp_rotation = enemy->rotation;
    if (game->is_passive == false && distance > 100 && (distance < 250
        || !will_collide_wall(game, &enemy->position, &enemy->direction))) {
        process_attack(game, enemy, time);
    }
}

void update_enemy_pos_sprite(game_data_t *game, enemy_t *enemy)
{
    sfSprite_setPosition(enemy->sprite, enemy->position);
    sfCircleShape_setPosition(enemy->area, enemy->position);
    sfCircleShape_setOrigin(enemy->area, (sfVector2f){250, 250});
    sfSprite_setRotation(enemy->sprite, enemy->disp_rotation);
    sfRectangleShape_setFillColor(enemy->health_bar, sfTransparent);
    sfRectangleShape_setOutlineThickness(enemy->health_bar, 2);
    sfRectangleShape_setOutlineColor(enemy->health_bar, sfBlack);
    sfRectangleShape_setSize(enemy->health_bar,
        (sfVector2f){100, 10});
    sfRectangleShape_setPosition(enemy->health_bar,
        (sfVector2f){enemy->position.x - 50, enemy->position.y - 50});
    sfRenderWindow_drawRectangleShape(game->window,
        enemy->health_bar, NULL);
    sfRectangleShape_setFillColor(enemy->health_bar, sfRed);
    sfRectangleShape_setOutlineThickness(enemy->health_bar, 0);
    sfRectangleShape_setSize(enemy->health_bar,
        (sfVector2f){enemy->health * 100 / enemy->config->max_health, 10});
    sfRectangleShape_setPosition(enemy->health_bar,
        (sfVector2f){enemy->position.x - 50, enemy->position.y - 50});
}
