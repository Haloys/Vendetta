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

static bool execute_enemy_touched(game_data_t *game, enemy_t *enemy,
    bullet_t *bullet, element_t *tmp)
{
    enemy->health -= bullet->damage;
    if (enemy->health <= 0)
        list_remove_element(&game->enemies, tmp->prev);
    return true;
}

static bool execute_player_touched(game_data_t *game, bullet_t *bullet)
{
    game->player->health -= (bullet->damage
        - (game->player->armor * bullet->damage / 100));
    game->player->health = MAX(0, game->player->health);
    return true;
}

bool bullet_touched_entity(game_data_t *game, bullet_t *bullet)
{
    element_t *tmp = game->enemies.start.next;
    enemy_t *enemy = NULL;
    rect_t rect = {0, 0, 0, 0};
    int saved_len = game->enemies.length;

    for (int i = 0; i < saved_len; ++i) {
        tmp = tmp->next;
        enemy = (enemy_t *)tmp->prev->data;
        rect = get_hitbox_rect(&enemy->position, PLAYER_HITBOX);
        if (is_rect(bullet->position.x, bullet->position.y, &rect))
            return execute_enemy_touched(game, enemy, bullet, tmp);
    }
    rect = get_hitbox_rect(&game->player->position, PLAYER_HITBOX);
    if (is_rect(bullet->position.x, bullet->position.y,
        &rect)) {
        return execute_player_touched(game, bullet);
    }
    return false;
}

void update_bullet(game_data_t *, bullet_t *bullet)
{
    bullet->position.x += bullet->direction.x * BULLET_MEDIUM_SPEED;
    bullet->position.y += bullet->direction.y * BULLET_MEDIUM_SPEED;
    sfSprite_setPosition(bullet->sprite, bullet->position);
    sfSprite_setRotation(bullet->sprite, bullet->rotation);
}
