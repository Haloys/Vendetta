/*
** EPITECH PROJECT, 2024
** Vendetta / Header
** File description:
** Animation
*/

#ifndef ANIMATION_H
    #define ANIMATION_H

    #include <SFML/System/Vector2.h>
    #include <SFML/Graphics/Sprite.h>

    #include "my_clock.h"
    #include "resources.h"

typedef struct movement_s {
    sfVector2f position;
    sfVector2f velocity;
} movement_t;

typedef struct animated_sprite_s {
    my_clock_t clock;
    int sprite_count;
    int index;
    float delay;
    int offset;
    sfIntRect rect;
} animated_sprite_t;

void animated_sprite_init(animated_sprite_t *sprite, sprite_id_t sprite_id);
void animated_sprite_update(animated_sprite_t *sprite, float elapsed);

void movement_init(movement_t *move);
void movement_update(movement_t *move, float elapsed);

#endif /* ANIMATION_H */
