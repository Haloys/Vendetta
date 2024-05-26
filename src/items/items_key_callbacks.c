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

int callback_interact_key_a(game_data_t *game, item_entity_t *item)
{
    play_sound(game, S_KEYS_LOOT);
    insert_item_in_inventory(game, "keya", 1);
    trigger_notification(game, 2);
    remove_item_from_list(game, item);
    return 0;
}

int callback_interact_key_b(game_data_t *game, item_entity_t *item)
{
    play_sound(game, S_KEYS_LOOT);
    insert_item_in_inventory(game, "keyb", 1);
    trigger_notification(game, 3);
    remove_item_from_list(game, item);
    return 0;
}

int callback_interact_key_c(game_data_t *game, item_entity_t *item)
{
    play_sound(game, S_KEYS_LOOT);
    insert_item_in_inventory(game, "keyc", 1);
    trigger_notification(game, 4);
    remove_item_from_list(game, item);
    return 0;
}
