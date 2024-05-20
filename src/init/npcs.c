/*
** EPITECH PROJECT, 2024
** Vendetta
** File description:
** Main
*/

#include <string.h>

#include "my_game.h"
#include "game_npc.h"

static void free_npc(npc_t *npc)
{
    free(npc->text);
    free(npc->interact);
    free(npc);
}

static void npc_create_text(game_data_t *game, npc_t *npc)
{
    sfText_setString(npc->text, "Hello, I'm an NPC");
    sfText_setFont(npc->text, game->font);
    sfText_setCharacterSize(npc->text, 50);
    sfText_setString(npc->interact, "Press E to interact");
    sfText_setFont(npc->interact, game->font);
    sfText_setCharacterSize(npc->interact, 50);
}

static npc_t *create_npc(game_data_t *game)
{
    npc_t *npc = malloc(sizeof(npc_t));

    if (npc == NULL)
        return NULL;
    strcpy(npc->name, "FLAVIBOT");
    npc->sprite = get_sprite(game, SP_NPC_ONE);
    npc->sprite_data = &SPRITES[SP_NPC_ONE];
    npc->position = (sfVector2f){1980, 1260};
    npc->direction = (sfVector2f){0, 0};
    npc->clock = NULL;
    npc->rotation = 0;
    npc->map_id = MAP_ONE;
    npc->text = sfText_create();
    npc->interact = sfText_create();
    if (npc->text == NULL || npc->interact == NULL)
        return NULL;
    npc_create_text(game, npc);
    npc->callback_interact = npc_callback;
    return npc;
}

int init_npcs(game_data_t *game)
{
    list_init(&game->npcs, (void *)free_npc);
    list_add_element(&game->npcs, create_npc(game));
    return RET_NONE;
}
