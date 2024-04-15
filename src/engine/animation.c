/*
** EPITECH PROJECT, 2024
** animation
** File description:
** dd
*/

#include "animation.h"

void animated_sprite_init(animated_sprite_t *sprite, sprite_id_t sprite_id)
{
    clock_init(&sprite->clock);
    sprite->index = 0;
    sprite->sprite_count = 0;
    sprite->delay = 1;
    sprite->rect = SPRITES[sprite_id].rect;
    sprite->offset = sprite->rect.width;
}

void animated_sprite_update(animated_sprite_t *sprite, float elapsed)
{
    int index;
    int m = (sprite->sprite_count * 2) - 2;
    int x;

    if (sprite->sprite_count == 1)
        return;
    clock_update(&sprite->clock, elapsed);
    index = sprite->clock.elapsed / sprite->delay;
    x = index % m;
    if (x >= sprite->sprite_count)
        x = m - x;
    index = x;
    if (index != sprite->index) {
        sprite->index = index;
        sprite->rect.left = sprite->offset * index;
    }
}

void movement_init(movement_t *move)
{
    move->position = (sfVector2f){0, 0};
    move->velocity = (sfVector2f){0, 0};
}

void movement_update(movement_t *move, float elapsed)
{
    move->position.x += elapsed * move->velocity.x;
    move->position.y += elapsed * move->velocity.y;
}
