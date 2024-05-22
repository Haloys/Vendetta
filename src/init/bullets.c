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

bullet_t *create_bullet(game_data_t *game, sfVector2f *pos, sfVector2f *dir,
    float rotation)
{
    bullet_t *bullet = malloc(sizeof(bullet_t));

    if (bullet == NULL)
        return NULL;
    bullet->sprite = get_sprite(game, SP_BULLET);
    sfSprite_setPosition(bullet->sprite, *pos);
    bullet->rotation = rotation;
    bullet->direction = *dir;
    bullet->position = *pos;
    return bullet;
}

int init_bullets(game_data_t *game)
{
    list_init(&game->bullets, (void *)free_bullet);
    return RET_NONE;
}
