/*
** EPITECH PROJECT, 2024
** Vendetta
** File description:
** Main
*/

#include <string.h>

#include "my_game.h"
#include "entity.h"
#include "math.h"

const item_config_t item_config[] = {
    {
        .name = "Key A",
        .sprite = SP_KEYA,
        .default_position = {1728, 1784},
        .default_rotation = 0,
        .map_id = MAP_ONE,
        .callback_interact = callback_interact_key_a
    },
    {
        .name = "Key C",
        .sprite = SP_KEYC,
        .default_position = {811, 620},
        .default_rotation = 0,
        .map_id = MAP_ONE,
        .callback_interact = callback_interact_key_c
    },
    {
        .name = "Key C",
        .sprite = SP_KEYC,
        .default_position = {2596, 597},
        .default_rotation = 0,
        .map_id = MAP_ONE,
        .callback_interact = callback_interact_key_c
    },
    {
        .name = "Bandage",
        .sprite = SP_POTION_ICON,
        .default_position = {1070, 1316},
        .default_rotation = 0,
        .map_id = MAP_ONE,
        .callback_interact = callback_interact_bandage
    },
    {
        .name = "Chest",
        .sprite = SP_CHEST_ICON,
        .default_position = {839, 1161},
        .map_id = MAP_ONE,
        .callback_interact = callback_interact_chest_random
    },
    {
        .name = "Chest",
        .sprite = SP_CHEST_ICON,
        .default_position = {471, 1806},
        .default_rotation = 0,
        .map_id = MAP_ONE,
        .callback_interact = callback_interact_chest_key
    },
    {
        .name = "Bandage",
        .sprite = SP_POTION_ICON,
        .default_position = {1383, 1192},
        .default_rotation = 0,
        .map_id = MAP_ONE,
        .callback_interact = callback_interact_bandage
    },
    {
        .name = "Chest",
        .sprite = SP_CHEST_ICON,
        .default_position = {500, 748},
        .default_rotation = 0,
        .map_id = MAP_TWO,
        .callback_interact = callback_interact_chest_shoes
    },
    {
        .name = "Chest",
        .sprite = SP_CHEST_ICON,
        .default_position = {1332, 636},
        .default_rotation = 0,
        .map_id = MAP_TWO,
        .callback_interact = callback_interact_chest_armor
    },
    {
        .name = "Chest",
        .sprite = SP_CHEST_ICON,
        .default_position = {1917, 846},
        .default_rotation = 0,
        .map_id = MAP_TWO,
        .callback_interact = callback_interact_chest_mask
    },
    {
        .name = "Pistol",
        .sprite = SP_SWORD_ICON,
        .default_position = {2063, 1713},
        .default_rotation = 0,
        .map_id = MAP_TWO,
        .callback_interact = callback_interact_pistol
    },
    {
        .name = "Aidkit",
        .sprite = SP_POTION_ICON,
        .default_position = {801, 1753},
        .default_rotation = 0,
        .map_id = MAP_TWO,
        .callback_interact = callback_interact_aidkit
    },
    {
        .name = "Rifle",
        .sprite = SP_SWORD_ICON,
        .default_position = {1106, 1106},
        .default_rotation = 0,
        .map_id = MAP_THREE,
        .callback_interact = callback_interact_rifle
    },
    {
        .name = "Shotgun",
        .sprite = SP_SWORD_ICON,
        .default_position = {499, 36},
        .default_rotation = 0,
        .map_id = MAP_THREE,
        .callback_interact = callback_interact_shotgun
    },
    {
        .name = "Chest",
        .sprite = SP_CHEST_ICON,
        .default_position = {1948, 353},
        .default_rotation = 0,
        .map_id = MAP_THREE,
        .callback_interact = callback_interact_chest_beach
    },
    {
        .name = "Chest",
        .sprite = SP_CHEST_ICON,
        .default_position = {1893, 1182},
        .default_rotation = 0,
        .map_id = MAP_THREE,
        .callback_interact = callback_interact_chest_inside
    },
    {
        .name = "Chest",
        .sprite = SP_CHEST_ICON,
        .default_position = {3447, 1070},
        .default_rotation = 0,
        .map_id = MAP_THREE,
        .callback_interact = callback_interact_chest_boss
    },
    {
        .name = "Key A",
        .sprite = SP_KEYA,
        .default_position = {1369, 618},
        .default_rotation = 0,
        .map_id = MAP_THREE,
        .callback_interact = callback_interact_key_a
    },
    {
        .name = "Key B",
        .sprite = SP_KEYB,
        .default_position = {2296, 1284},
        .default_rotation = 0,
        .map_id = MAP_THREE,
        .callback_interact = callback_interact_key_b
    },
    {
        .name = "Aidkit",
        .sprite = SP_POTION_ICON,
        .default_position = {2250, 1909},
        .default_rotation = 0,
        .map_id = MAP_THREE,
        .callback_interact = callback_interact_aidkit
    },
    {
        .name = "Aidkit",
        .sprite = SP_POTION_ICON,
        .default_position = {405, 959},
        .default_rotation = 0,
        .map_id = MAP_THREE,
        .callback_interact = callback_interact_aidkit
    },
};

static void free_item(item_entity_t *item)
{
    free(item);
}

static void item_create_visuals(game_data_t *game, item_entity_t *item)
{
    item->keybind_text = sfText_create();
    sfText_setFont(item->keybind_text, game->font);
    sfText_setCharacterSize(item->keybind_text, 22);
    strcpy(item->key, key_to_string(game->keybinds[Interact].code));
    sfText_setString(item->keybind_text, item->key);
    item->square = sfRectangleShape_create();
    sfRectangleShape_setSize(item->square, (sfVector2f){40, 40});
    sfRectangleShape_setFillColor(item->square, FILL_COLOR);
    sfRectangleShape_setOutlineThickness(item->square, 2);
    sfRectangleShape_setOutlineColor(item->square, BORDER_HOVER);
}

static void draw_item(game_data_t *game, item_entity_t *item)
{
    sfVector2f player_pos = game->player->position;
    float distance = sqrt(pow(player_pos.x - item->position.x, 2) +
        pow(player_pos.y - item->position.y, 2));

    sfSprite_setPosition(item->sprite, item->position);
    sfRenderWindow_drawSprite(game->window, item->sprite, NULL);
    sfSprite_setRotation(item->sprite, item->rotation);
    if (distance < 130) {
        sfText_setPosition(item->keybind_text, (sfVector2f)
            {item->position.x + 18, item->position.y - 43});
        sfRectangleShape_setPosition(item->square, (sfVector2f)
            {item->position.x + 7, item->position.y - 50});
        sfRenderWindow_drawRectangleShape(game->window, item->square, NULL);
        sfRenderWindow_drawText(game->window, item->keybind_text, NULL);
        if (is_key_pressed(game, Interact)) {
            item->config->callback_interact(game, item);
        }
    }
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
    item_create_visuals(game, item);
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

void display_items(game_data_t *game)
{
    element_t *current = game->entities.start.next;
    item_entity_t *item = NULL;

    while (current != &game->entities.end) {
        item = (item_entity_t *)current->data;
        if (game->map.id == item->config->map_id) {
            draw_item(game, item);
        }
        current = current->next;
    }
}
