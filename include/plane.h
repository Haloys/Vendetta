/*
** EPITECH PROJECT, 2024
** entity.h
** File description:
** dd
*/

#ifndef PLANE_H
    #define PLANE_H

    #include "my_game.h"

int p_in_control_area(c_rect_t *c, rect_t *sq);
int plane_in_control_areas(game_data_t *game, plane_t *ent);

#endif /* PLANE_H */
