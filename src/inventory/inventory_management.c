/*
** EPITECH PROJECT, 2024
** B-MUL-200-PAR-2-1-myrpg-maxence.bunel [WSL: Ubuntu]
** File description:
** inventory_management
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "my_game.h"
#include "inventory.h"
#include "items.h"

int insert_existing_item(game_data_t *game, char *item_name, int qty, int i)
{
    inventory_slot_t *slot = &game->player_data->inventory->slots[i];

    if (slot->item != NULL && strcmp(slot->item->name, item_name) == 0) {
        if (is_valid_weight(game, slot->item->weight * qty) == 0) {
            return 0;
        }
        slot->quantity += qty;
        slot->weight = slot->item->weight * slot->quantity;
        update_inventory_weight(game);
        return 1;
    }
    return 0;
}

void remove_item_from_inventory(game_data_t *game, int slot_id)
{
    inventory_slot_t *slot = &game->player_data->inventory->slots[slot_id];

    if (slot->item != NULL) {
        slot->item = NULL;
        slot->quantity = 0;
        slot->weight = 0;
        update_inventory_weight(game);
    }
}

void swap_items(game_data_t *game, int slot1, int slot2)
{
    inventory_slot_t *slot = &game->player_data->inventory->slots[slot1];
    inventory_slot_t *slot_bis = &game->player_data->inventory->slots[slot2];
    inventory_slot_t tmp = {0};

    tmp = *slot;
    *slot = *slot_bis;
    *slot_bis = tmp;
}

void insert_item_in_inventory(game_data_t *game, char *item_name, int qty)
{
    inventory_slot_t *slot = NULL;
    for (int i = 0; i < 25; i++) {
        if (insert_existing_item(game, item_name, qty, i) == 1) {
            return;
        }
    }
    for (int j = 0; j < 25; j++) {
        slot = &game->player_data->inventory->slots[j];
        if (slot->item == NULL) {
            slot->item = get_item_by_name(game, item_name);
            slot->quantity = qty;
            slot->weight = slot->item->weight * qty;
            update_inventory_weight(game);
            return;
        }
    }
}

void equip_item(game_data_t *game, int slot_id)
{
    inventory_slot_t *slot = &game->player_data->inventory->slots[slot_id];

    if (slot->item->is_equipable == false) {
        return;
    }
    if (slot->item->type == ITEM_HELMET) {
        swap_items(game, 25, slot_id);
    }
    if (slot->item->type == ITEM_ARMOR) {
        swap_items(game, 26, slot_id);
    }
    if (slot->item->type == ITEM_SHOES) {
        swap_items(game, 27, slot_id);
    }
    if (slot->item->type == ITEM_WEAPON) {
        swap_items(game, 28, slot_id);
    }
}

void init_inventory(game_data_t *game)
{
    game->player_data = malloc(sizeof(player_data_t));
    game->player_data->inventory = malloc(sizeof(inventory_t));
    for (int i = 0; i < 29; i++) {
        game->player_data->inventory->slots[i].item = NULL;
        game->player_data->inventory->slots[i].quantity = 0;
        game->player_data->inventory->slots[i].weight = 0;
    }
    game->player_data->inventory->total_weight = 0;
}

void test_inventory_and_print(game_data_t *game)
{
    static int done = 0;
    if (done == 0) {
        done = 1;
    } else {
        return;
    }
    init_inventory(game);
    insert_item_in_inventory(game, "whiskey", 1);
    insert_item_in_inventory(game, "pistol", 1);
    insert_item_in_inventory(game, "oxycodone", 1);
    insert_item_in_inventory(game, "rifle", 1);
    insert_item_in_inventory(game, "mask3", 1);
    insert_item_in_inventory(game, "whiskey", 1);
    swap_items(game, 0, 1);
    equip_item(game, 0);

    for (int i = 0; i < 29; i++) {
        if (game->player_data->inventory->slots[i].item != NULL) {
            dprintf(1, "Number : %d\n", i);
            printf("Item: %s\n", game->player_data->inventory->slots[i].item->name);
            printf("Quantity: %d\n", game->player_data->inventory->slots[i].quantity);
            printf("Weight: %f\n", game->player_data->inventory->slots[i].weight);
        }
    }
}
