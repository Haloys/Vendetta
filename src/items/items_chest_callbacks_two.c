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
#include "setup_notifications.h"

int callback_interact_chest_inside(game_data_t *game, item_entity_t *item)
{
    give_random_items(game, 3, 6);
    insert_item_in_inventory(game, "armor2", 1);
    insert_item_in_inventory(game, "keyc", 1);
    trigger_notification(game, 14);
    remove_item_from_list(game, item);
    return 0;
}

int callback_interact_chest_beach(game_data_t *game, item_entity_t *item)
{
    give_random_items(game, 3, 6);
    insert_item_in_inventory(game, "mask2", 1);
    trigger_notification(game, 11);
    remove_item_from_list(game, item);
    return 0;
}

int callback_interact_chest_boss(game_data_t *game, item_entity_t *item)
{
    give_random_items(game, 3, 6);
    insert_item_in_inventory(game, "shoes", 1);
    insert_item_in_inventory(game, "armor3", 1);
    trigger_notification(game, 15);
    remove_item_from_list(game, item);
    return 0;
}

int callback_interact_chest_random(game_data_t *game, item_entity_t *item)
{
    give_random_items(game, 2, 5);
    trigger_notification(game, 11);
    remove_item_from_list(game, item);
    return 0;
}
