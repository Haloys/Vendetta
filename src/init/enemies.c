/*
** EPITECH PROJECT, 2024
** Vendetta
** File description:
** Main
*/

#include "my_game.h"
#include "enemies.h"

static void free_enemy(enemy_t *enemy)
{
    sfRectangleShape_destroy(enemy->health_bar);
    sfCircleShape_destroy(enemy->area);
    sfClock_destroy(enemy->clock);
    free(enemy);
}

static void set_enemy_shapes(enemy_t *enemy)
{
    enemy->health_bar = sfRectangleShape_create();
    enemy->area = sfCircleShape_create();
    sfCircleShape_setRadius(enemy->area, 200);
    sfCircleShape_setFillColor(enemy->area, sfTransparent);
    sfCircleShape_setOutlineThickness(enemy->area, 1);
    sfCircleShape_setOutlineColor(enemy->area, sfBlue);
    sfRectangleShape_setSize(enemy->health_bar, (sfVector2f){100, 10});
    sfRectangleShape_setFillColor(enemy->health_bar, sfRed);
    sfRectangleShape_setOutlineThickness(enemy->health_bar, 1);
    sfRectangleShape_setOutlineColor(enemy->health_bar, sfBlack);
}

enemy_t *create_enemy(game_data_t *game)
{
    enemy_t *enemy = malloc(sizeof(enemy_t));

    if (enemy == NULL)
        return NULL;
    enemy->sprite = get_sprite(game, SP_ENEMY_EZ_IDLE);
    enemy->sprite_data = &SPRITES[SP_ENEMY_EZ_IDLE];
    enemy->position = (sfVector2f){1860, 1815};
    enemy->direction = (sfVector2f){0, 0};
    enemy->health = 100;
    enemy->speed = 1.3;
    enemy->attack = 10;
    enemy->armor = 0;
    enemy->max_health = 100;
    enemy->clock = sfClock_create();
    enemy->pspeed = 0;
    enemy->rotation = 0;
    enemy->target_rot = 0;
    enemy->map_id = MAP_ONE;
    set_enemy_shapes(enemy);
    return enemy;
}

int init_enemies(game_data_t *game)
{
    list_init(&game->enemies, (void *)free_enemy);
    list_add_element(&game->enemies, create_enemy(game));
    return RET_NONE;
}
