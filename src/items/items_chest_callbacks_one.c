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
#include "items.h"

static void give_item_based_on_rarity(game_data_t *game, float random_value,
    int total_items, int *count)
{
    for (int j = 0; j < total_items; ++j) {
        if (random_value < ITEMS[j].rarity) {
            insert_item_in_inventory(game, ITEMS[j].name, 1);
            (*count)++;
            break;
        }
    }
}

void give_random_items(game_data_t *game, int min_items, int max_items)
{
    int num_items = min_items + rand() % (max_items - min_items + 1);
    int total_items = sizeof(ITEMS) / sizeof(ITEMS[0]);
    int count = 0;
    float random_value = 0;

    for (int i = 0; i < num_items; ++i) {
        random_value = (float)rand() / RAND_MAX;
        give_item_based_on_rarity(game, random_value, total_items, &count);
        if (count >= num_items) break;
    }
}

int callback_interact_chest_key(game_data_t *game, item_entity_t *item)
{
    give_random_items(game, 1, 3);
    insert_item_in_inventory(game, "keyb", 1);
    remove_item_from_list(game, item);
    return 0;
}

int callback_interact_chest_mask(game_data_t *game, item_entity_t *item)
{
    give_random_items(game, 2, 4);
    insert_item_in_inventory(game, "mask3", 1);
    remove_item_from_list(game, item);
    return 0;
}

int callback_interact_chest_armor(game_data_t *game, item_entity_t *item)
{
    give_random_items(game, 1, 3);
    insert_item_in_inventory(game, "armor", 1);
    remove_item_from_list(game, item);
    return 0;
}

int callback_interact_chest_shoes(game_data_t *game, item_entity_t *item)
{
    give_random_items(game, 2, 4);
    insert_item_in_inventory(game, "blue_shoes", 1);
    remove_item_from_list(game, item);
    return 0;
}
