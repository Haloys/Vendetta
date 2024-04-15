/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** my_radar project
*/

#include "my_game.h"

void free_entity_hitbox(game_data_t *game)
{
    element_t *e = game->planes.start.next;

    for (int i = 0; i < game->planes.length; i++) {
        sfRectangleShape_destroy(e->data.entity->hitbox);
        e = e->next;
    }
}

void free_entity_hitbox_tower(game_data_t *game)
{
    element_t *e = game->towers.start.next;

    for (int i = 0; i < game->towers.length; i++) {
        sfCircleShape_destroy(e->data.entity->circle);
        e = e->next;
    }
}
