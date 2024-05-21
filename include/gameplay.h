/*
** EPITECH PROJECT, 2024
** Vendetta / Header
** File description:
** Gameplay
*/

#ifndef GAMEPLAY_H
    #define GAMEPLAY_H

    #include "my_game.h"

    #define VIEW_WIDTH WINDOW_WIDTH / 2
    #define VIEW_HEIGHT WINDOW_HEIGHT / 2

    #define PLAYER_MOVE_SPEED 150.f
    #define RADAR_SIZE 10.f

    #define ZOOM_SPEED 1.01f
    #define ZOOM_MIN 0.5f
    #define ZOOM_MAX 2.5f

    #define MIN(a, b) (b < a ? b : a)
    #define MAX(a, b) (b > a ? b : a)
    #define CLAMP(a, b, c) (MIN(MAX(a, b), c))

    #define PI 3.1415926535f

    #define SPRINT_MUL 1.5f

    #define PI_180 57.2957795131f
    #define ABS(x) x < 0 ? -x : x

    #define EPSILON 0.0001f

void process_playing_gameplay(game_data_t *game);

void process_events(game_data_t *game);
void process_playing_event(game_data_t *game, sfEvent *evt);

void process_player_movement(game_data_t *game, sfKeyEvent *key);

typedef struct key_config_s {
    char *name;
    char *key_name;
    keybinds_t key;
} key_config_t;

extern key_config_t key_config[];

typedef struct {
    sfKeyCode code;
    char *name;
} key_mapping_t;

typedef sfKeyCode keycode_t;

// UTILS
sfColor get_pixel_color(sfImage *image, int x, int y);

void normalize(sfVector2f *vector);
float lerp_angle(float a, float b, float t);
void update_player(game_data_t *game, sfTime time);


#endif /* GAMEPLAY_H */
