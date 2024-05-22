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
