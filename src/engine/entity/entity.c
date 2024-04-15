/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** my_radar project
*/

#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "my_game.h"
#include "entity.h"
#include "plane.h"

plane_t *entity_create(sprite_id_t sprite_id)
{
    plane_t *plane = malloc(sizeof(plane_t));

    if (plane == NULL)
        return NULL;
    entity_init(plane, sprite_id);
    return plane;
}

void entity_set_sprite(plane_t *plane, sprite_id_t sprite_id)
{
    plane->sprite_id = sprite_id;
    plane->scale = SPRITES[plane->sprite_id].scale;
    plane->width = SPRITES[plane->sprite_id].rect.width * plane->scale;
    plane->height = SPRITES[plane->sprite_id].rect.height * plane->scale;
}

void entity_init(plane_t *plane, sprite_id_t sprite_id)
{
    plane->health = 0;
    plane->points = 10;
    plane->radius = 0;
    entity_set_sprite(plane, sprite_id);
    animated_sprite_init(&plane->a_sprite, plane->sprite_id);
    movement_init(&plane->move);
    plane->a_sprite.delay = 0.2;
    plane->a_sprite.sprite_count = 1;
    plane->move.velocity = (sfVector2f){ 0.f, 0.f };
    plane->move.position = (sfVector2f){ -plane->a_sprite.offset, 0 };
    plane->angle = 0;
}

void entity_draw(plane_t *plane, game_data_t *game)
{
    sfSprite *sprite = get_sprite(game, plane->sprite_id);

    sfSprite_setTextureRect(sprite, plane->a_sprite.rect);
    sfSprite_setScale(sprite, (sfVector2f){plane->scale, plane->scale});
    sfSprite_setPosition(sprite, plane->move.position);
    sfSprite_setOrigin(sprite, (sfVector2f){plane->width / plane->scale / 2.f,
        plane->height / plane->scale / 2.f});
    sfSprite_setRotation(sprite, plane->angle);
    sfRenderWindow_drawSprite(game->window, sprite, NULL);
}

void entity_update(game_data_t *game, plane_t *plane, float elapsed)
{
    animated_sprite_update(&plane->a_sprite, elapsed);
    movement_update(&plane->move, elapsed);
    set_entity_rect(plane);
    plane->lifetime -= elapsed;
    plane_in_control_areas(game, plane);
}
