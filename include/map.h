/*
** EPITECH PROJECT, 2024
** Vendetta / Header
** File description:
** State
*/

#ifndef MAP_H
    #define MAP_H

    #include "my_game.h"

    #define MAX_DOORS 4

typedef enum map_id_s {
    MAP_ONE,
    MAP_TWO,
    MAP_THREE
} map_id_t;

typedef struct door_s {
    rect_t rect;
} door_t;

typedef struct map_config_s {
    sprite_id_t map;
    sprite_id_t cols_map;
    sfVector2f spawn_pos;
    sfVector2f spawn_pos_back;
    game_sprite_t const *sp_map;
    map_id_t id;
    rect_t portal;
    rect_t back_portal;
    music_id_t music;
    door_t doors[MAX_DOORS];
    int door_count;
} map_config_t;

int set_map(game_data_t *game, map_id_t map_id, sfVector2f *pos);
int set_backmap(game_data_t *game, map_id_t map_id);
bool is_in_portal(game_data_t *game, rect_t *portal);
bool door_checker(game_data_t *game, rect_t *door);

extern const map_config_t map_config[];

#endif /* MAP_H */
