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

void update_player(game_data_t *game, sfTime time)
{
    player_data_t *player = game->player;
    sfSprite *sp_map = get_sprite(game, SP_MAP_1);
    float scale = sfTime_asSeconds(time) * game->player->pspeed;

    update_player_direction(game);
    if (is_key_down(game, Sprint))
        scale *= SPRINT_MUL;
    if (is_key_down(game, MoveUp))
        process_key_up(game, sp_map, scale);
    if (is_key_down(game, MoveDown))
        process_key_down(game, sp_map, scale);
    if (is_key_down(game, MoveRight))
        process_key_right(game, sp_map, scale);
    if (is_key_down(game, MoveLeft))
        process_key_left(game, sp_map, scale);
    if (ABS(player->rotation - player->target_rot) > EPSILON) {
        player->rotation = lerp_angle(player->rotation, player->target_rot,
            0.25f);
    }
}
