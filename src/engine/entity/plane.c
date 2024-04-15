/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** my_radar project
*/

#include <math.h>
#include "entity.h"
#include "plane.h"

void entity_init_plane(data_t *d)
{
    float dx = d->x2 - d->x1;
    float dy = d->y2 - d->y1;
    float l = sqrt(dx * dx + dy * dy);

    d->entity->move.velocity.x = d->speed * dx / l;
    d->entity->move.velocity.y = d->speed * dy / l;
    d->entity->lifetime = l / d->speed;
    d->entity->angle = atan2f(dy, dx) * PI_RAD;
    set_entity_hitbox_plane(d->entity);
}

inline int is_plane_active(data_t *data, game_data_t *game)
{
    return game->delay_clock.elapsed >= data->delay;
}

inline rect_t get_rect(plane_t *ent)
{
    return (rect_t){ent->move.position.x - ent->width / 2,
        ent->move.position.y - ent->height / 2, ent->width, ent->height};
}

inline int p_in_control_area(c_rect_t *c, rect_t *sq)
{
    float dist_sup_left = sqrt(pow(sq->x - c->x, 2) + pow(sq->y - c->y, 2));
    float dist_inf_right =
        sqrt(pow(sq->x + sq->w - c->x, 2) + pow(sq->y + sq->h - c->y, 2));

    return dist_sup_left <= c->r && dist_inf_right <= c->r;
}

int plane_in_control_areas(game_data_t *game, plane_t *ent)
{
    element_t *e = game->towers.start.next;
    c_rect_t cercle_rect;

    for (int i = 0; i < game->towers.length; i++) {
        cercle_rect = (c_rect_t){e->data.entity->move.position.x,
            e->data.entity->move.position.y, e->data.radius};
        ent->in_tarea = p_in_control_area(&cercle_rect, &ent->rect) ? 1 : 0;
        if (ent->in_tarea == 1)
            return 1;
        e = e->next;
    }
    return 0;
}
