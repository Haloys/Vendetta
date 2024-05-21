/*
** EPITECH PROJECT, 2024
** Vendetta
** File description:
** Main
*/

#include <string.h>

#include "my_game.h"
#include "entity.h"

const item_config_t item_config[] = {
    {
        .name = "Key A",
        .sprite = SP_KEYA,
        .default_position = {1728, 1784},
        .default_rotation = 0,
        .map_id = MAP_ONE,
        .callback_interact = NULL
    },
    {
        .name = "Key B",
        .sprite = SP_KEYB,
        .default_position = {811, 620},
        .default_rotation = 0,
        .map_id = MAP_ONE,
        .callback_interact = NULL
    },
    {
        .name = "Key C",
        .sprite = SP_KEYC,
        .default_position = {2596, 597},
        .default_rotation = 0,
        .map_id = MAP_ONE,
        .callback_interact = NULL
    },
    {
        .name = "Sword",
        .sprite = SP_SWORD_ICON,
        .default_position = {1038, 1308},
        .default_rotation = 0,
        .map_id = MAP_ONE,
        .callback_interact = NULL
    },
    {
        .name = "Chest",
        .sprite = SP_CHEST_ICON,
        .default_position = {471, 1806},
        .default_rotation = 0,
        .map_id = MAP_ONE,
        .callback_interact = NULL
    },
    {
        .name = "Potion",
        .sprite = SP_POTION_ICON,
        .default_position = {1413, 1211},
        .default_rotation = 0,
        .map_id = MAP_ONE,
        .callback_interact = NULL
    },
    {
        .name = "Chest",
        .sprite = SP_CHEST_ICON,
        .default_position = {500, 748},
        .default_rotation = 0,
        .map_id = MAP_TWO,
        .callback_interact = NULL
    },
    {
        .name = "Chest",
        .sprite = SP_CHEST_ICON,
        .default_position = {1332, 636},
        .default_rotation = 0,
        .map_id = MAP_TWO,
        .callback_interact = NULL
    },
    {
        .name = "Chest",
        .sprite = SP_CHEST_ICON,
        .default_position = {1917, 846},
        .default_rotation = 0,
        .map_id = MAP_TWO,
        .callback_interact = NULL
    },
    {
        .name = "Sword",
        .sprite = SP_SWORD_ICON,
        .default_position = {2063, 1713},
        .default_rotation = 0,
        .map_id = MAP_TWO,
        .callback_interact = NULL
    },
    {
        .name = "Potion",
        .sprite = SP_POTION_ICON,
        .default_position = {801, 1753},
        .default_rotation = 0,
        .map_id = MAP_TWO,
        .callback_interact = NULL
    },
    {
        .name = "Oxycodone",
        .sprite = SP_OXY,
        .default_position = {820, 687},
        .default_rotation = 0,
        .map_id = MAP_TWO,
        .callback_interact = NULL
    },
    {
        .name = "Sword",
        .sprite = SP_SWORD_ICON,
        .default_position = {1106, 1106},
        .default_rotation = 0,
        .map_id = MAP_THREE,
        .callback_interact = NULL
    },
    {
        .name = "Sword",
        .sprite = SP_SWORD_ICON,
        .default_position = {499, 36},
        .default_rotation = 0,
        .map_id = MAP_THREE,
        .callback_interact = NULL
    },
    {
        .name = "Chest",
        .sprite = SP_CHEST_ICON,
        .default_position = {1948, 353},
        .default_rotation = 0,
        .map_id = MAP_THREE,
        .callback_interact = NULL
    },
    {
        .name = "Chest",
        .sprite = SP_CHEST_ICON,
        .default_position = {1893, 1182},
        .default_rotation = 0,
        .map_id = MAP_THREE,
        .callback_interact = NULL
    },
    {
        .name = "Chest",
        .sprite = SP_CHEST_ICON,
        .default_position = {3447, 1070},
        .default_rotation = 0,
        .map_id = MAP_THREE,
        .callback_interact = NULL
    },
    {
        .name = "Key A",
        .sprite = SP_KEYA,
        .default_position = {1369, 618},
        .default_rotation = 0,
        .map_id = MAP_THREE,
        .callback_interact = NULL
    },
    {
        .name = "Key B",
        .sprite = SP_KEYB,
        .default_position = {2296, 1284},
        .default_rotation = 0,
        .map_id = MAP_THREE,
        .callback_interact = NULL
    },
    {
        .name = "Potion",
        .sprite = SP_POTION_ICON,
        .default_position = {2250, 1909},
        .default_rotation = 0,
        .map_id = MAP_THREE,
        .callback_interact = NULL
    },
};

static void free_item(item_entity_t *item)
{
    free(item);
}

static item_entity_t *create_item(game_data_t *game, item_config_t *config)
{
    item_entity_t *item = malloc(sizeof(item_entity_t));

    if (item == NULL)
        return NULL;
    item->config = config;
    item->sprite_data = &SPRITES[config->sprite];
    item->sprite = get_sprite(game, item->config->sprite);
    item->position = config->default_position;
    item->rotation = config->default_rotation;
    return item;
}

int init_items(game_data_t *game)
{
    item_entity_t *item = NULL;

    list_init(&game->entities, (void *)free_item);
    for (size_t i = 0; i < ENTITY_COUNT; ++i) {
        item = create_item(game, (item_config_t *)&item_config[i]);
        if (item == NULL)
            return RET_FAIL;
        list_add_element(&game->entities, item);
    }
    return RET_NONE;
}
