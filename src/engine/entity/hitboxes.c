/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** my_radar project
*/

#include "my_game.h"
#include "plane.h"
#include "entity.h"

void set_entity_hitbox_tower(data_t *data)
{
    data->entity->circle = sfCircleShape_create();
    if (data->entity->circle == NULL)
        return;
    sfCircleShape_setRadius(data->entity->circle, data->radius);
    sfCircleShape_setOutlineThickness(data->entity->circle, 2.5);
    sfCircleShape_setOutlineColor(data->entity->circle, sfBlue);
    sfCircleShape_setFillColor(data->entity->circle,
        sfColor_fromRGBA(255, 255, 255, 64));
}

void draw_entity_hitbox_tower(data_t *data, game_data_t *game)
{
    sfCircleShape_setOrigin(data->entity->circle,
        (sfVector2f){data->entity->width / 2, data->entity->height / 2});
    sfCircleShape_setPosition(data->entity->circle,
        (sfVector2f){data->entity->move.position.x
        + (data->entity->width / 2) - (data->radius),
        data->entity->move.position.y + (data->entity->height / 2)
        - (data->radius) });
    sfRenderWindow_drawCircleShape(game->window, data->entity->circle, NULL);
}

void set_entity_hitbox_plane(plane_t *entity)
{
    entity->hitbox = sfRectangleShape_create();
    if (entity->hitbox == NULL)
        return;
    sfRectangleShape_setSize(entity->hitbox,
        (sfVector2f){entity->width, entity->height});
    sfRectangleShape_setOrigin(entity->hitbox,
        (sfVector2f){entity->width / 2, entity->height / 2});
    sfRectangleShape_setFillColor(entity->hitbox, sfTransparent);
    sfRectangleShape_setOutlineThickness(entity->hitbox, 2);
}

void draw_entity_hitbox_plane(plane_t *entity, game_data_t *game)
{
    sfRectangleShape_setOutlineColor(entity->hitbox,
        entity->in_tarea ? sfGreen : sfRed);
    sfRectangleShape_setPosition(entity->hitbox, entity->move.position);
    sfRenderWindow_drawRectangleShape(game->window, entity->hitbox, NULL);
}

inline void set_entity_rect(plane_t *ent)
{
    ent->rect = (rect_t){ent->move.position.x - ent->width / 2,
        ent->move.position.y - ent->height / 2, ent->width, ent->height};
}
