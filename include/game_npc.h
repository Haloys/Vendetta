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
    char name[128];
    game_sprite_t const *sprite_data;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    sfVector2f direction;
    sfClock *clock;
    float rotation;
    map_id_t map_id;
    sfText *text;
    sfText *interact;
    int (*callback_interact)(game_data_t *game, struct npc_s *enemy);
} npc_t;

void draw_npc(game_data_t *game, npc_t *npc);
void update_npc(game_data_t *game, npc_t *npc);

int npc_callback(game_data_t *game, npc_t *npc);


#endif /* GAME_NPC_H */
