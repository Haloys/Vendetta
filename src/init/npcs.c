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
        .name = "Mike",
        .sprite = SP_YELLOW_NPC,
        .default_position = {2325, 1812},
        .default_direction = {0, 0},
        .rotation_offset = 90,
        .default_rotation = 0,
        .map_id = MAP_ONE,
        .text = "Psst",
        .callback_interact = first_npc_callback
    },
    {
        .name = "Sasha",
        .sprite = SP_WHITE_NPC,
        .default_position = {1922, 655},
        .default_direction = {0, 0},
        .rotation_offset = 90,
        .default_rotation = 0,
        .map_id = MAP_ONE,
        .text = "Hey!",
        .callback_interact = second_npc_callback
    },
    {
        .name = "Trevor",
        .sprite = SP_GREEN_NPC,
        .default_position = {802, 733},
        .default_direction = {0, 0},
        .rotation_offset = 90,
        .default_rotation = 0,
        .map_id = MAP_TWO,
        .text = "Burp",
        .callback_interact = third_npc_callback
    },
    {
        .name = "Oleksandra",
        .sprite = SP_BLACK_NPC,
        .default_position = {1047, 352},
        .default_direction = {0, 0},
        .rotation_offset = 90,
        .default_rotation = 0,
        .map_id = MAP_TWO,
        .text = "Yo !",
        .callback_interact = fourth_npc_callback
    },
    {
        .name = "Marcus",
        .sprite = SP_RED_NPC,
        .default_position = {1331, 1635},
        .default_direction = {0, 0},
        .rotation_offset = 90,
        .default_rotation = 0,
        .map_id = MAP_THREE,
        .text = "Flee",
        .callback_interact = fifth_npc_callback
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
