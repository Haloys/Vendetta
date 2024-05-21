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
    sfSprite_destroy(bullet->sprite);
    sfTexture_destroy(bullet->texture);
    sfClock_destroy(bullet->clock);
    free(bullet);
}

int init_bullets(game_data_t *game)
{
    list_init(&game->bullets, (void *)free_bullet);
    return RET_NONE;
}
