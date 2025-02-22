/*
** EPITECH PROJECT, 2024
** Vendetta / Header
** File description:
** State
*/

#ifndef GAME_NPC_H
    #define GAME_NPC_H

    #include "my_game.h"

typedef struct npc_s {
    game_sprite_t const *sprite_data;
    sfSprite *sprite;
    sfTexture *texture;
    sfClock *clock;
    sfText *text;
    sfText *keybind_text;
    sfRectangleShape *square;
    sfVector2f position;
    sfVector2f direction;
    float rotation;
    char key[32];
    struct npc_config_s *config;
} npc_t;

typedef struct npc_config_s {
    char name[128];
    sprite_id_t sprite;
    sfVector2f default_position;
    sfVector2f default_direction;
    float rotation_offset;
    float default_rotation;
    map_id_t map_id;
    char *text;
    int (*callback_interact)(game_data_t *game, struct npc_s *npc);
} npc_config_t;

    #define NPC_COUNT (sizeof(npc_config) / sizeof(npc_config[0]))

extern const npc_config_t npc_config[];

// NPC
int first_npc_callback(game_data_t *game, npc_t *npc);
int second_npc_callback(game_data_t *game, npc_t *npc);
int third_npc_callback(game_data_t *game, npc_t *npc);
int fourth_npc_callback(game_data_t *game, npc_t *npc);
int fifth_npc_callback(game_data_t *game, npc_t *npc);

void draw_npc(game_data_t *game, npc_t *npc);
void update_npc(game_data_t *game, npc_t *npc);

int npc_callback(game_data_t *game, npc_t *npc);


#endif /* GAME_NPC_H */
