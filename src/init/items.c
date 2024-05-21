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
