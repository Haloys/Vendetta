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
    #define RADAR_SIZE 30

    #define PI 3.1415926535f

    #define SPRINT_MUL 1.5f

    #define PI_180 57.2957795131f
    #define ABS(x) x < 0 ? -x : x

    #define EPSILON 0.0001f

typedef enum keybinds_e {
    MoveUp,
    MoveRight,
    MoveDown,
    MoveLeft,
    Reset,
    Sprint,
    Echap
} keybinds_t;

typedef struct sf_to_keybind_s {
    sfKeyCode code;
    keybinds_t key;
} sf_to_keybind_t;

static const sf_to_keybind_t KEYBINDS[] = {
    {sfKeyUp, MoveUp},
    {sfKeyRight, MoveRight},
    {sfKeyDown, MoveDown},
    {sfKeyLeft, MoveLeft},
    {sfKeyZ, MoveUp},
    {sfKeyD, MoveRight},
    {sfKeyS, MoveDown},
    {sfKeyQ, MoveLeft},
    {sfKeyLShift, Sprint},
    {sfKeyR, Reset},
    {sfKeyEscape, Echap}
};

static const int KEYBINDS_COUNT = sizeof(KEYBINDS) / sizeof(sf_to_keybind_t);

void process_playing_gameplay(game_data_t *game);

void process_events(game_data_t *game);
void process_playing_event(game_data_t *game, sfEvent *evt);

void process_player_movement(game_data_t *game, sfKeyEvent *key);


// UTILS
sfColor get_pixel_color(sfImage *image, int x, int y);

// KEY MANAGEMENT
void update_key(game_data_t *game, sfKeyCode code, int state);
void normalize(sfVector2f *vector);
float lerp_angle(float a, float b, float t);
void update_player(game_data_t *game, sfTime time);
void update_player_direction(game_data_t *game);

// IS_KEY
bool is_key_down(game_data_t *game, keybinds_t key);

// MOVEMENT
void process_key_left(game_data_t *game, sfSprite *sp_map, float scale);
void process_key_right(game_data_t *game, sfSprite *sp_map, float scale);
void process_key_up(game_data_t *game, sfSprite *sp_map, float scale);
void process_key_down(game_data_t *game, sfSprite *sp_map, float scale);

#endif /* GAMEPLAY_H */
