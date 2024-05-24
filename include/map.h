/*
** EPITECH PROJECT, 2024
** Vendetta / Header
** File description:
** State
*/

#ifndef MAP_H
    #define MAP_H

    #include "my_game.h"

    #define MAX_ZOOM_CONFIG 10
    #define MAX_DOORS 4

typedef enum map_id_s {
    MAP_ONE,
    MAP_TWO,
    MAP_THREE
} map_id_t;

typedef struct rect_2_s {
    int x1;
    int y1;
    int x2;
    int y2;
} rect_2_t;

typedef struct zoom_config_s {
    rect_2_t zone;
    float min;
    float max;
    sfVector2f pos;
} zoom_config_t;

typedef struct door_s {
    rect_t rect;
    char *item;
    sfVector2f position;
    char key[32];
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
    zoom_config_t zoom[MAX_ZOOM_CONFIG];
    int zoom_count;
    door_t doors[MAX_DOORS];
    int door_count;
} map_config_t;

int set_map(game_data_t *game, map_id_t map_id, sfVector2f *pos);
int set_backmap(game_data_t *game, map_id_t map_id);
bool is_in_portal(game_data_t *game, rect_t *portal);
bool door_checker(game_data_t *game, rect_t *door, char *item);
void draw_doors(game_data_t *game, door_t *doors, rect_t *door);

extern const map_config_t map_config[];

#endif /* MAP_H */
