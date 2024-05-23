/*
** EPITECH PROJECT, 2024
** Vendetta
** File description:
** Main
*/

#include "my_game.h"
#include "enemies.h"

const enemy_config_t ENEMIES_CONFIG[] = {
    {
        .name = "Easy enemy",
        .sprite_data = &SPRITES[SP_ENEMY_EZ_IDLE],
        .sprite = SP_ENEMY_EZ_IDLE,
        .default_position = {2000, 2060},
        .health = 100,
        .speed = ENEMY_MOVE_SPEED + 75,
        .attack = 10,
        .armor = 0,
        .max_health = 100,
        .map_id = MAP_ONE,
    },
    {
        .name = "Medium enemy",
        .sprite_data = &SPRITES[SP_MEDIUM_IDLE],
        .sprite = SP_MEDIUM_IDLE,
        .default_position = {1223, 1469},
        .health = 200,
        .speed = ENEMY_MOVE_SPEED,
        .attack = 20,
        .armor = 10,
        .max_health = 200,
        .map_id = MAP_ONE,
    },
};

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
    if (enemy->health_bar == NULL || enemy->area == NULL)
        return;
    sfCircleShape_setRadius(enemy->area, 250);
    sfCircleShape_setFillColor(enemy->area, sfTransparent);
    sfCircleShape_setOutlineThickness(enemy->area, 1);
    sfCircleShape_setOutlineColor(enemy->area, sfBlue);
    sfRectangleShape_setSize(enemy->health_bar, (sfVector2f){100, 10});
    sfRectangleShape_setFillColor(enemy->health_bar, sfRed);
    sfRectangleShape_setOutlineThickness(enemy->health_bar, 1);
    sfRectangleShape_setOutlineColor(enemy->health_bar, sfBlack);
}

static enemy_t *create_enemy(game_data_t *game, enemy_config_t *config)
{
    enemy_t *enemy = malloc(sizeof(enemy_t));

    if (enemy == NULL)
        return NULL;
    enemy->config = config;
    enemy->sprite = get_sprite(game, config->sprite);
    enemy->sprite_data = enemy->config->sprite_data;
    enemy->position = enemy->config->default_position;
    enemy->direction = (sfVector2f){0, 0};
    enemy->target = (sfVector2f){0, 0};
    enemy->health = enemy->config->health;
    enemy->armor = enemy->config->armor;
    enemy->clock = sfClock_create();
    enemy->shoot_clock = sfClock_create();
    enemy->rotation = 0;
    enemy->disp_rotation = 0;
    enemy->target_rot = 0;
    enemy->path = NULL;
    set_enemy_shapes(enemy);
    return enemy;
}

int init_enemies(game_data_t *game)
{
    enemy_t *enemy = NULL;

    list_init(&game->enemies, (void *)free_enemy);
    for (size_t i = 0; i < ENEMY_COUNT; ++i) {
        enemy = create_enemy(game, (enemy_config_t *)&ENEMIES_CONFIG[i]);
        if (enemy == NULL)
            return RET_FAIL;
        list_add_element(&game->enemies, enemy);
    }
    return RET_NONE;
}
