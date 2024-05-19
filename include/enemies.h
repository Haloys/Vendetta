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
    sfRectangleShape *health_bar;
    sfCircleShape *area;
    int health;
    int speed;
    int attack;
    int armor;
    int max_health;
    sfClock *clock;
    float pspeed;
    float rotation;
    float target_rot;
    map_id_t map_id;
} enemy_t;

void draw_enemy(game_data_t *game, enemy_t *enemy);
void update_enemy(game_data_t *game, enemy_t *enemy);


void update_enemy_pos_sprite(enemy_t *enemy);
void update_enemy_pos_diretion(enemy_t *enemy, game_data_t *game);

#endif /* ENEMIES_H */
