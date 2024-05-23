/*
** EPITECH PROJECT, 2024
** Vendetta / Header
** File description:
** Music
*/

#ifndef ENTITY_H_
    #define ENTITY_H_

    #include "my_game.h"

    #define MAX_ITEMS 6

typedef struct item_entity_s {
    game_sprite_t const *sprite_data;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    float rotation;
    struct item_config_s *config;
    sfText *keybind_text;
    sfRectangleShape *square;
    char key[20];
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
bool will_collide_wall(game_data_t *game, sfVector2f *pos,
    sfVector2f *dir);

int list_remove_element_by_id(list_t *list, int id);
void remove_item_from_list(game_data_t *game, item_entity_t *item);
void display_items(game_data_t *game);
void give_random_items(game_data_t *game, int min_items, int max_items);

int callback_interact_key_a(game_data_t *game, item_entity_t *item);
int callback_interact_key_b(game_data_t *game, item_entity_t *item);
int callback_interact_key_c(game_data_t *game, item_entity_t *item);
int callback_interact_knife(game_data_t *game, item_entity_t *item);
int callback_interact_bandage(game_data_t *game, item_entity_t *item);
int callback_interact_pistol(game_data_t *game, item_entity_t *item);
int callback_interact_aidkit(game_data_t *game, item_entity_t *item);
int callback_interact_rifle(game_data_t *game, item_entity_t *item);
int callback_interact_shotgun(game_data_t *game, item_entity_t *item);

int callback_interact_chest_key(game_data_t *game, item_entity_t *item);
int callback_interact_chest_mask(game_data_t *game, item_entity_t *item);
int callback_interact_chest_armor(game_data_t *game, item_entity_t *item);
int callback_interact_chest_shoes(game_data_t *game, item_entity_t *item);

int callback_interact_chest_inside(game_data_t *game, item_entity_t *item);
int callback_interact_chest_beach(game_data_t *game, item_entity_t *item);
int callback_interact_chest_boss(game_data_t *game, item_entity_t *item);

bool can_move_to_point(game_data_t *game, sfVector2f *pos, sfVector2f *dir,
    sfVector2f *target);


#endif /* !ENTITY_H_ */
