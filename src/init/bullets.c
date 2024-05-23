/*
** EPITECH PROJECT, 2024
** Vendetta
** File description:
** Main
*/

#include "my_game.h"
#include "enemies.h"

static void free_bullet(bullet_t *bullet)
{
    free(bullet);
}

bullet_t *create_bullet(game_data_t *game, bullet_config_t *config)
{
    bullet_t *bullet = malloc(sizeof(bullet_t));

    if (bullet == NULL)
        return NULL;
    bullet->sprite = get_sprite(game, SP_BULLET);
    sfSprite_setPosition(bullet->sprite, *config->pos);
    bullet->rotation = config->rotation;
    bullet->direction = *config->dir;
    bullet->position = *config->pos;
    bullet->damage = config->damage;
    bullet->speed = config->speed;
    for (int i = 0; i < 6; ++i)
        update_bullet(game, bullet);
    return bullet;
}

int init_bullets(game_data_t *game)
{
    list_init(&game->bullets, (void *)free_bullet);
    game->bullets_clock = sfClock_create();
    if (game->bullets_clock == NULL)
        return RET_FAIL;
    return RET_NONE;
}
