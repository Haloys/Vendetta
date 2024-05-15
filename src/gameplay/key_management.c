/*
** EPITECH PROJECT, 2024
** Vendetta
** File description:
** Process gameplay loop
*/

#include <math.h>

#include "my_game.h"
#include "gameplay.h"

void update_key(game_data_t *game, sfKeyCode code, int state)
{
    int mask = 0;
    int new_state = 0;

    for (int i = 0; i < KEYBINDS_COUNT; ++i) {
        if (KEYBINDS[i].code == code) {
            mask = 1 << KEYBINDS[i].key;
            new_state = state << KEYBINDS[i].key;
            game->key_change = (game->key_change & ~mask)
                | ((game->key_state & mask) ^ new_state);
            game->key_state = (game->key_state & ~mask) | new_state;
            return;
        }
    }
}

void normalize(sfVector2f *vector)
{
    float length = sqrtf(vector->x * vector->x + vector->y * vector->y);

    vector->x /= length;
    vector->y /= length;
}

float lerp_angle(float a, float b, float t)
{
    float difference = fmod(b - a, 360.f);

    return a + (fmodf(2 * difference, 360) - difference) * t;
}
