/*
** EPITECH PROJECT, 2024
** entity.h
** File description:
** dd
*/

#ifndef ENTITY_H
    #define ENTITY_H

    #include "my_game.h"

    #define PI_RAD 57.2957795131

rect_t get_rect(plane_t *ent);

void set_entity_hitbox_tower(data_t *data);
void draw_entity_hitbox_tower(data_t *data, game_data_t *game);

void set_entity_hitbox_plane(plane_t *entity);
void draw_entity_hitbox_plane(plane_t *entity, game_data_t *game);

void free_entity_hitbox(game_data_t *game);
void free_entity_hitbox_tower(game_data_t *game);

void entity_set_sprite(plane_t *plane, sprite_id_t sprite_id);

void set_entity_rect(plane_t *ent);

#endif /* ENTITY_H */
