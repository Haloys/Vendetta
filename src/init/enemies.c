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
        .health = 50,
        .speed = ENEMY_MOVE_SPEED + 75,
        .attack = 1,
        .armor = 0,
        .max_health = 50,
        .exp = 100,
        .is_boss = false,
        .map_id = MAP_ONE,
        .attack_type = A_FIRST,
        .attack_speed = 0.5f,
        .bullet_speed = BULLET_NORMAL_SPEED,
    },
    {
        .name = "Easy enemy",
        .sprite_data = &SPRITES[SP_ENEMY_EZ_IDLE],
        .sprite = SP_ENEMY_EZ_IDLE,
        .default_position = {1223, 1469},
        .health = 50,
        .speed = ENEMY_MOVE_SPEED,
        .attack = 1,
        .armor = 0,
        .max_health = 50,
        .exp = 100,
        .is_boss = false,
        .map_id = MAP_ONE,
        .attack_type = A_FIRST,
        .attack_speed = 0.5f,
        .bullet_speed = BULLET_NORMAL_SPEED,
    },
    {
        .name = "Easy enemy",
        .sprite_data = &SPRITES[SP_ENEMY_EZ_IDLE],
        .sprite = SP_ENEMY_EZ_IDLE,
        .default_position = {930, 1826},
        .health = 50,
        .speed = ENEMY_MOVE_SPEED,
        .attack = 1,
        .armor = 0,
        .max_health = 50,
        .exp = 100,
        .is_boss = false,
        .map_id = MAP_ONE,
        .attack_type = A_FIRST,
        .attack_speed = 0.5f,
        .bullet_speed = BULLET_NORMAL_SPEED,
    },
    {
        .name = "Easy enemy",
        .sprite_data = &SPRITES[SP_ENEMY_EZ_IDLE],
        .sprite = SP_ENEMY_EZ_IDLE,
        .default_position = {1876, 990},
        .health = 50,
        .speed = ENEMY_MOVE_SPEED,
        .attack = 1,
        .armor = 0,
        .max_health = 50,
        .exp = 100,
        .is_boss = false,
        .map_id = MAP_ONE,
        .attack_type = A_FIRST,
        .attack_speed = 0.5f,
        .bullet_speed = BULLET_NORMAL_SPEED,
    },
    {
        .name = "Easy enemy",
        .sprite_data = &SPRITES[SP_ENEMY_EZ_IDLE],
        .sprite = SP_ENEMY_EZ_IDLE,
        .default_position = {1071, 1076},
        .health = 50,
        .speed = ENEMY_MOVE_SPEED,
        .attack = 1,
        .armor = 0,
        .max_health = 50,
        .exp = 100,
        .is_boss = false,
        .map_id = MAP_ONE,
        .attack_type = A_FIRST,
        .attack_speed = 0.5f,
        .bullet_speed = BULLET_NORMAL_SPEED,
    },
    {
        .name = "Easy enemy",
        .sprite_data = &SPRITES[SP_ENEMY_EZ_IDLE],
        .sprite = SP_ENEMY_EZ_IDLE,
        .default_position = {1370, 699},
        .health = 50,
        .speed = ENEMY_MOVE_SPEED,
        .attack = 1,
        .armor = 0,
        .max_health = 50,
        .exp = 100,
        .is_boss = false,
        .map_id = MAP_ONE,
        .attack_type = A_FIRST,
        .attack_speed = 0.5f,
        .bullet_speed = BULLET_NORMAL_SPEED
    },
    {
        .name = "Medium enemy",
        .sprite_data = &SPRITES[SP_MEDIUM_IDLE],
        .sprite = SP_MEDIUM_IDLE,
        .default_position = {2751, 1519},
        .health = 150,
        .speed = ENEMY_MOVE_SPEED,
        .attack = 2,
        .armor = 0,
        .max_health = 150,
        .exp = 200,
        .is_boss = false,
        .map_id = MAP_ONE,
        .attack_type = A_FIRST,
        .attack_speed = 0.5f,
        .bullet_speed = BULLET_NORMAL_SPEED
    },
    {
        .name = "Easy enemy",
        .sprite_data = &SPRITES[SP_ENEMY_EZ_IDLE],
        .sprite = SP_ENEMY_EZ_IDLE,
        .default_position = {957, 1758},
        .health = 50,
        .speed = ENEMY_MOVE_SPEED,
        .attack = 1,
        .armor = 0,
        .max_health = 50,
        .exp = 100,
        .is_boss = false,
        .map_id = MAP_TWO,
        .attack_type = A_FIRST,
        .attack_speed = 0.5f,
        .bullet_speed = BULLET_NORMAL_SPEED,
    },
    {
        .name = "Medium enemy",
        .sprite_data = &SPRITES[SP_MEDIUM_IDLE],
        .sprite = SP_MEDIUM_IDLE,
        .default_position = {1839, 1723},
        .health = 150,
        .speed = ENEMY_MOVE_SPEED,
        .attack = 2,
        .armor = 0,
        .max_health = 150,
        .exp = 200,
        .is_boss = false,
        .map_id = MAP_TWO,
        .attack_type = A_FIRST,
        .attack_speed = 0.5f,
        .bullet_speed = BULLET_NORMAL_SPEED,
    },
    {
        .name = "Hard enemy",
        .sprite_data = &SPRITES[SP_HARD_IDLE],
        .sprite = SP_HARD_IDLE,
        .default_position = {1522, 1153},
        .health = 250,
        .speed = ENEMY_MOVE_SPEED,
        .attack = 1,
        .armor = 0,
        .max_health = 250,
        .exp = 450,
        .is_boss = false,
        .map_id = MAP_TWO,
        .attack_type = A_FIRST,
        .attack_speed = 0.17f,
        .bullet_speed = 275,
    },
    {
        .name = "Medium enemy",
        .sprite_data = &SPRITES[SP_MEDIUM_IDLE],
        .sprite = SP_MEDIUM_IDLE,
        .default_position = {766, 1211},
        .health = 150,
        .speed = ENEMY_MOVE_SPEED,
        .attack = 2,
        .armor = 0,
        .max_health = 150,
        .exp = 200,
        .is_boss = false,
        .map_id = MAP_TWO,
        .attack_type = A_FIRST,
        .attack_speed = 0.5f,
        .bullet_speed = BULLET_NORMAL_SPEED,
    },
    {
        .name = "Medium enemy",
        .sprite_data = &SPRITES[SP_MEDIUM_IDLE],
        .sprite = SP_MEDIUM_IDLE,
        .default_position = {1080, 661},
        .health = 150,
        .speed = ENEMY_MOVE_SPEED,
        .attack = 2,
        .armor = 0,
        .max_health = 150,
        .exp = 200,
        .is_boss = false,
        .map_id = MAP_TWO,
        .attack_type = A_FIRST,
        .attack_speed = 0.5f,
        .bullet_speed = BULLET_NORMAL_SPEED,
    },
    {
        .name = "Hard enemy",
        .sprite_data = &SPRITES[SP_HARD_IDLE],
        .sprite = SP_HARD_IDLE,
        .default_position = {529, 513},
        .health = 250,
        .speed = ENEMY_MOVE_SPEED,
        .attack = 1,
        .armor = 0,
        .max_health = 250,
        .exp = 450,
        .is_boss = false,
        .map_id = MAP_TWO,
        .attack_type = A_FIRST,
        .attack_speed = 0.17f,
        .bullet_speed = 250,
    },
    {
        .name = "Medium enemy",
        .sprite_data = &SPRITES[SP_MEDIUM_IDLE],
        .sprite = SP_MEDIUM_IDLE,
        .default_position = {1321, 1229},
        .health = 150,
        .speed = ENEMY_MOVE_SPEED,
        .attack = 2,
        .armor = 0,
        .max_health = 150,
        .exp = 200,
        .is_boss = false,
        .map_id = MAP_THREE,
        .attack_type = A_FIRST,
        .attack_speed = 0.5f,
        .bullet_speed = BULLET_NORMAL_SPEED,
    },
    {
        .name = "Hard enemy",
        .sprite_data = &SPRITES[SP_HARD_IDLE],
        .sprite = SP_HARD_IDLE,
        .default_position = {1124, 759},
        .health = 250,
        .speed = ENEMY_MOVE_SPEED,
        .attack = 1,
        .armor = 0,
        .max_health = 250,
        .exp = 450,
        .is_boss = false,
        .map_id = MAP_THREE,
        .attack_type = A_FIRST,
        .attack_speed = 0.17f,
        .bullet_speed = 250,
    },
    {
        .name = "Medium enemy",
        .sprite_data = &SPRITES[SP_MEDIUM_IDLE],
        .sprite = SP_MEDIUM_IDLE,
        .default_position = {523, 655},
        .health = 150,
        .speed = ENEMY_MOVE_SPEED,
        .attack = 2,
        .armor = 0,
        .max_health = 150,
        .exp = 200,
        .is_boss = false,
        .map_id = MAP_THREE,
        .attack_type = A_FIRST,
        .attack_speed = 0.5f,
        .bullet_speed = BULLET_NORMAL_SPEED,
    },
    {
        .name = "Hard enemy",
        .sprite_data = &SPRITES[SP_HARD_IDLE],
        .sprite = SP_HARD_IDLE,
        .default_position = {1940, 543},
        .health = 250,
        .speed = ENEMY_MOVE_SPEED,
        .attack = 1,
        .armor = 0,
        .max_health = 250,
        .exp = 450,
        .is_boss = false,
        .map_id = MAP_THREE,
        .attack_type = A_FIRST,
        .attack_speed = 0.17f,
        .bullet_speed = 275,
    },
    {
        .name = "Hard enemy",
        .sprite_data = &SPRITES[SP_HARD_IDLE],
        .sprite = SP_HARD_IDLE,
        .default_position = {2817, 762},
        .health = 250,
        .speed = ENEMY_MOVE_SPEED,
        .attack = 1,
        .armor = 0,
        .max_health = 250,
        .exp = 450,
        .is_boss = false,
        .map_id = MAP_THREE,
        .attack_type = A_FIRST,
        .attack_speed = 0.17f,
        .bullet_speed = 275,
    },
    {
        .name = "Medium enemy",
        .sprite_data = &SPRITES[SP_MEDIUM_IDLE],
        .sprite = SP_MEDIUM_IDLE,
        .default_position = {2534, 1215},
        .health = 150,
        .speed = ENEMY_MOVE_SPEED,
        .attack = 2,
        .armor = 0,
        .max_health = 150,
        .exp = 200,
        .is_boss = false,
        .map_id = MAP_THREE,
        .attack_type = A_FIRST,
        .attack_speed = 0.5f,
        .bullet_speed = BULLET_NORMAL_SPEED,
    },
    {
        .name = "Hard enemy",
        .sprite_data = &SPRITES[SP_HARD_IDLE],
        .sprite = SP_HARD_IDLE,
        .default_position = {2251, 1850},
        .health = 250,
        .speed = ENEMY_MOVE_SPEED,
        .attack = 1,
        .armor = 0,
        .max_health = 250,
        .exp = 450,
        .is_boss = false,
        .map_id = MAP_THREE,
        .attack_type = A_FIRST,
        .attack_speed = 0.17f,
        .bullet_speed = 275,
    },
    {
        .name = "Hard enemy",
        .sprite_data = &SPRITES[SP_HARD_IDLE],
        .sprite = SP_HARD_IDLE,
        .default_position = {1983, 1316},
        .health = 250,
        .speed = ENEMY_MOVE_SPEED,
        .attack = 1,
        .armor = 0,
        .max_health = 250,
        .exp = 450,
        .is_boss = false,
        .map_id = MAP_THREE,
        .attack_type = A_FIRST,
        .attack_speed = 0.17f,
        .bullet_speed = 275,
    },
    {
        .name = "Boss enemy",
        .sprite_data = &SPRITES[SP_BOSS_IDLE],
        .sprite = SP_BOSS_IDLE,
        .default_position = {3045, 1195},
        .health = 700,
        .speed = ENEMY_MOVE_SPEED,
        .attack = 8,
        .armor = 0,
        .max_health = 550,
        .exp = 5000,
        .is_boss = true,
        .map_id = MAP_THREE,
        .attack_type = A_FIRST,
        .attack_speed = 0.8f,
        .bullet_speed = 500,
    }
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
