/*
** EPITECH PROJECT, 2024
** Vendetta / Game Engine
** File description:
** Animation
*/

#include "my_game.h"
#include "gameplay.h"

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
