/*
** EPITECH PROJECT, 2024
** Vendetta / Header
** File description:
** State
*/

#ifndef ENEMIES_H
    #define ENEMIES_H

    #include "my_game.h"

typedef struct enemy_s {
    char name[128];
    game_sprite_t const *sprite_data;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    sfVector2f direction;
    sfVector2f target;
    sfRectangleShape *health_bar;
    sfCircleShape *area;
    int health;
    int speed;
    int attack;
    int armor;
    int max_health;
    sfClock *clock;
    float rotation;
    float disp_rotation;
    float target_rot;
    map_id_t map_id;
} enemy_t;

    #define BULLET_SLOW_SPEED 5
    #define BULLET_MEDIUM_SPEED 10
    #define BULLET_FAST_SPEED 15

    #define ENEMY_MOVE_SPEED 100

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


void update_enemy_pos_sprite(enemy_t *enemy);
void update_enemy_pos_diretion(enemy_t *enemy, game_data_t *game);

// BULLETS
void update_bullet(game_data_t *game, bullet_t *bullet);
bool bullet_touched_entity(game_data_t *game, bullet_t *bullet);

bullet_t *create_bullet(game_data_t *game, sfVector2f *pos, sfVector2f *dir,
    float rotation);

#endif /* ENEMIES_H */
