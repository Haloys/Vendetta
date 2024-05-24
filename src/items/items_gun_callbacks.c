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
#include "setup_notifications.h"

int callback_interact_pistol(game_data_t *game, item_entity_t *item)
{
    insert_item_in_inventory(game, "pistol", 1);
    trigger_notification(game, 7);
    remove_item_from_list(game, item);
    return 0;
}

int callback_interact_rifle(game_data_t *game, item_entity_t *item)
{
    insert_item_in_inventory(game, "rifle", 1);
    trigger_notification(game, 9);
    remove_item_from_list(game, item);
    return 0;
}

int callback_interact_shotgun(game_data_t *game, item_entity_t *item)
{
    insert_item_in_inventory(game, "shotgun", 1);
    trigger_notification(game, 10);
    remove_item_from_list(game, item);
    return 0;
}
