/*
** EPITECH PROJECT, 2024
** Vendetta / Header
** File description:
** State
*/

#ifndef ENEMIES_H
    #define ENEMIES_H

    #include "my_game.h"

typedef enum enemy_attack_type_e {
    A_FIRST,
    A_PATH_FINDING,
} enemy_attack_type_t;

typedef struct enemy_s {
    char name[128];
    game_sprite_t const *sprite_data;
    sfSprite *sprite;
    sfVector2f position;
    sfVector2f direction;
    sfVector2f target;
    sfRectangleShape *health_bar;
    sfCircleShape *area;
    int health;
    int armor;
    sfClock *clock;
    sfClock *shoot_clock;
    float rotation;
    float disp_rotation;
    float target_rot;
    struct enemy_config_s *config;
    path_node_t *path;
} enemy_t;

typedef struct enemy_config_s {
    char name[128];
    game_sprite_t const *sprite_data;
    sprite_id_t sprite;
    sfVector2f default_position;
    int health;
    int speed;
    int attack;
    int armor;
    int max_health;
    int exp;
    bool is_boss;
    map_id_t map_id;
    float attack_speed;
    enemy_attack_type_t attack_type;
} enemy_config_t;

    #define ENEMY_COUNT (sizeof(ENEMIES_CONFIG) / sizeof(ENEMIES_CONFIG[0]))

extern const enemy_config_t ENEMIES_CONFIG[];

    #define BULLET_SLOW_SPEED 250
    #define BULLET_NORMAL_SPEED 400
    #define BULLET_MEDIUM_SPEED 600
    #define BULLET_FAST_SPEED 1000

    #define ENEMY_MOVE_SPEED 100


typedef struct bullet_config_s {
    sfVector2f *pos;
    sfVector2f *dir;
    float rotation;
    int damage;
    int speed;
} bullet_config_t;


typedef struct bullet_t {
    sfSprite *sprite;
    sfVector2f position;
    sfVector2f direction;
    int damage;
    int speed;
    float rotation;
    float target_rot;
} bullet_t;


// ENEMIES
void draw_enemy(game_data_t *game, enemy_t *enemy);
void update_enemy(game_data_t *game, enemy_t *enemy);


void update_enemy_pos_sprite(game_data_t *game, enemy_t *enemy);
void update_enemy_pos_diretion(enemy_t *enemy, game_data_t *game, sfTime time);

// BULLETS
void update_bullet(game_data_t *game, bullet_t *bullet);
bool bullet_touched_entity(game_data_t *game, bullet_t *bullet);

bullet_t *create_bullet(game_data_t *game, bullet_config_t *config);

void walk_to_nearest_point(enemy_t *enemy, game_data_t *game,
    sfTime time);

#endif /* ENEMIES_H */
