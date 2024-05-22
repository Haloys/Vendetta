/*
** EPITECH PROJECT, 2024
** Vendetta / Game Engine
** File description:
** Animation
*/

#include "my_game.h"
#include "gameplay.h"
#include "enemies.h"
#include "entity.h"
#include "utils.h"

bool bullet_touched_entity(game_data_t *game, bullet_t *bullet)
{
    element_t *tmp = game->enemies.start.next;
    enemy_t *enemy = NULL;
    rect_t rect = {0, 0, 0, 0};

    for (int i = 0; i < game->enemies.length; ++i) {
        enemy = (enemy_t *)tmp->data;
        rect = get_hitbox_rect(&enemy->position, PLAYER_HITBOX);
        if (is_rect(bullet->position.x, bullet->position.y, &rect))
            return true;
        tmp = tmp->next;
    }
    rect = get_hitbox_rect(&game->player->position, PLAYER_HITBOX);
    if (is_rect(bullet->position.x, bullet->position.y,
        &rect)) {
        game->player->health -= (bullet->damage
            - (game->player->armor * bullet->damage / 100));
        game->player->health = MAX(0, game->player->health);
        return true;
    }
    return false;
}

void update_bullet(game_data_t *game, bullet_t *bullet)
{
    bullet->position.x += bullet->direction.x * BULLET_MEDIUM_SPEED;
    bullet->position.y += bullet->direction.y * BULLET_MEDIUM_SPEED;
    sfSprite_setPosition(bullet->sprite, bullet->position);
    sfSprite_setRotation(bullet->sprite, bullet->rotation);
}
