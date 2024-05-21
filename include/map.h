/*
** EPITECH PROJECT, 2024
** Vendetta / Header
** File description:
** State
*/

#ifndef MAP_H
    #define MAP_H

    #include "my_game.h"

typedef enum map_id_s {
    MAP_ONE,
    MAP_TWO,
    MAP_THREE
} map_id_t;

typedef struct map_config_s {
    sprite_id_t map;
    sprite_id_t cols_map;
    sfVector2f spawn_pos;
    game_sprite_t const *sp_map;
    map_id_t id;
    rect_t portal;
} map_config_t;


int set_map(game_data_t *game, map_id_t map_id);
bool is_in_portal(game_data_t *game);


extern const map_config_t map_config[];

#endif /* MAP_H */
