/*
** EPITECH PROJECT, 2024
** B-MUL-200-PAR-2-1-myrpg-maxence.bunel [WSL: Ubuntu]
** File description:
** inventory_utils_items
*/

#include <string.h>

#include "my_game.h"
#include "inventory.h"

int remove_item_from_inventory_by_name(game_data_t *game, char *item_name)
{
    inventory_slot_t *slot = NULL;

    for (int i = 0; i < 25; i++) {
        slot = &game->player->inventory->slots[i];
        if (slot->item != NULL && strcmp(slot->item->name, item_name) == 0) {
            slot->item = NULL;
            slot->quantity = 0;
            slot->weight = 0;
            update_inventory_weight(game);
            return 1;
        }
    }
    return 0;
}

int get_item_quantity(game_data_t *game, char *item_name)
{
    inventory_slot_t *slot = NULL;

    for (int i = 0; i < 25; i++) {
        slot = &game->player->inventory->slots[i];
        if (slot->item != NULL && strcmp(slot->item->name, item_name) == 0) {
            return slot->quantity;
        }
    }
    return 0;
}

char *get_equiped_weapon(game_data_t *game)
{
    if (game->player->inventory->slots[28].item != NULL) {
        return game->player->inventory->slots[28].item->name;
    }
    return NULL;
}
