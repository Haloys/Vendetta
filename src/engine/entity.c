/*
** EPITECH PROJECT, 2024
** Vendetta / Game Engine
** File description:
** Animation
*/

#include <math.h>

#include "my_game.h"
#include "gameplay.h"
#include "utils.h"

rect_t get_hitbox_rect(sfVector2f *pos, int size)
{
    return (rect_t){pos->x - size, pos->y - size, size * 2, size * 2};
}

bool is_inside_circle_area(sfVector2f *pos, sfVector2f pos2, float min_radius,
    float max_radius)
{
    float distance = sqrt(pow(pos->x - pos2.x, 2) + pow(pos->y - pos2.y, 2));

    if (distance < max_radius && distance > min_radius)
        return true;
    return false;
}

bool will_collide_wall(game_data_t *game, sfVector2f *pos,
    sfVector2f *dir)
{
    sfVector2f pos_f = {pos->x, pos->y};
    rect_t rect = {0, 0, 0, 0};

    while (true) {
        if (is_black_color(
            get_pixel_color(game->cols_map, pos_f.x, pos_f.y)))
            return true;
        pos_f.x += dir->x;
        pos_f.y += dir->y;
        rect = get_hitbox_rect(&pos_f, PLAYER_HITBOX);
        if (is_rect(game->player->position.x, game->player->position.y, &rect))
            break;
    }
    return false;
}
