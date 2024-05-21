/*
** EPITECH PROJECT, 2024
** Vendetta
** File description:
** Main
*/

#include <string.h>

#include "my_game.h"
#include "game_npc.h"

const npc_config_t npc_config[] = {
    {
        .name = "NPC 1",
        .sprite = SP_NPC_ONE,
        .default_position = {2325, 1812},
        .default_direction = {0, 0},
        .default_rotation = 0,
        .map_id = MAP_ONE,
        .text = "Hey!",
        .callback_interact = npc_callback
    },
    {
        .name = "NPC 2",
        .sprite = SP_NPC_ONE,
        .default_position = {1922, 655},
        .default_direction = {0, 0},
        .default_rotation = 0,
        .map_id = MAP_ONE,
        .text = "Hey!",
        .callback_interact = npc_callback
    },
    {
        .name = "NPC 3",
        .sprite = SP_NPC_ONE,
        .default_position = {2325, 1812},
        .default_direction = {0, 0},
        .default_rotation = 0,
        .map_id = MAP_ONE,
        .text = "Hey!",
        .callback_interact = npc_callback
    },
    {
        .name = "HALOYS",
        .sprite = SP_BLACK_NPC,
        .default_position = {453, 1500},
        .default_direction = {0, 0},
        .default_rotation = 0,
        .map_id = MAP_ONE,
        .text = "Hello, I'm HALOYS, I'am poor and I need money",
        .callback_interact = npc_callback
    },
    {
        .name = "NPC 3",
        .sprite = SP_YELLOW_NPC,
        .default_position = {1047, 352},
        .default_direction = {0, 0},
        .default_rotation = 0,
        .map_id = MAP_TWO,
        .text = "Hello, I'm NPC 3",
        .callback_interact = npc_callback
    },
    {
        .name = "NPC 3",
        .sprite = SP_NPC_ONE,
        .default_position = {802, 733},
        .default_direction = {0, 0},
        .default_rotation = 0,
        .map_id = MAP_TWO,
        .text = "Hello, I'm NPC 3",
        .callback_interact = npc_callback
    },
    {
        .name = "NPC 3",
        .sprite = SP_NPC_ONE,
        .default_position = {1331, 1635},
        .default_direction = {0, 0},
        .default_rotation = 0,
        .map_id = MAP_THREE,
        .text = "Hello, I'm NPC 3",
        .callback_interact = npc_callback
    }
};

static void free_npc(npc_t *npc)
{
    free(npc->text);
    free(npc);
}

static void npc_create_text(game_data_t *game, npc_t *npc)
{
    sfText_setString(npc->text, npc->config->text);
    sfText_setFont(npc->text, game->font);
    sfText_setCharacterSize(npc->text, 22);
    sfText_setString(npc->keybind_text, npc->key);
    sfText_setFont(npc->keybind_text, game->font);
    sfText_setCharacterSize(npc->keybind_text, 22);
    sfRectangleShape_setSize(npc->square, (sfVector2f){40, 40});
    sfRectangleShape_setFillColor(npc->square, FILL_COLOR);
    sfRectangleShape_setOutlineThickness(npc->square, 2);
    sfRectangleShape_setOutlineColor(npc->square, BORDER_HOVER);
}

static npc_t *create_npc(game_data_t *game, npc_config_t *config)
{
    npc_t *npc = malloc(sizeof(npc_t));

    if (npc == NULL)
        return NULL;
    npc->config = config;
    npc->sprite = get_sprite(game, config->sprite);
    npc->sprite_data = &SPRITES[config->sprite];
    npc->position = config->default_position;
    npc->direction = config->default_direction;
    npc->rotation = config->default_rotation;
    npc->clock = NULL;
    npc->text = sfText_create();
    npc->keybind_text = sfText_create();
    npc->square = sfRectangleShape_create();
    strcpy(npc->key, "E");
    if (npc->text == NULL || npc->square == NULL || npc->keybind_text == NULL)
        return NULL;
    npc_create_text(game, npc);
    return npc;
}

int init_npcs(game_data_t *game)
{
    npc_t *npc = NULL;

    list_init(&game->npcs, (void *)free_npc);
    for (size_t i = 0; i < NPC_COUNT; ++i) {
        npc = create_npc(game, (npc_config_t *)&npc_config[i]);
        if (npc == NULL)
            return RET_FAIL;
        list_add_element(&game->npcs, npc);
    }
    return RET_NONE;
}
