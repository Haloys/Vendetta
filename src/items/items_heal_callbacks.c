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

int callback_interact_bandage(game_data_t *game, item_entity_t *item)
{
    play_sound(game, S_POTION_LOOT);
    insert_item_in_inventory(game, "bandage", 2);
    trigger_notification(game, 6);
    remove_item_from_list(game, item);
    return 0;
}

int callback_interact_aidkit(game_data_t *game, item_entity_t *item)
{
    insert_item_in_inventory(game, "aidkit", 1);
    trigger_notification(game, 8);
    remove_item_from_list(game, item);
    return 0;
}
