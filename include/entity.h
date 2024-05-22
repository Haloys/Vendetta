/*
** EPITECH PROJECT, 2024
** Vendetta / Header
** File description:
** Music
*/

#ifndef ENTITY_H_
    #define ENTITY_H_

    #include "my_game.h"

typedef struct item_entity_s {
    game_sprite_t const *sprite_data;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    float rotation;
    struct item_config_s *config;
} item_entity_t;

typedef struct item_config_s {
    char name[128];
    sprite_id_t sprite;
    sfVector2f default_position;
    float default_rotation;
    map_id_t map_id;
    int (*callback_interact)(game_data_t *game, struct item_entity_s *item);
} item_config_t;

extern const item_config_t item_config[];

    #define ENTITY_COUNT (sizeof(item_config) / sizeof(item_config[0]))

void draw_entity(game_data_t *game, item_entity_t *entity);
rect_t get_hitbox_rect(sfVector2f *pos, int size);
bool is_inside_circle_area(sfVector2f *pos, sfVector2f pos2, float min_radius,
    float max_radius);

#endif /* !ENTITY_H_ */
