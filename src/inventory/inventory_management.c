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

static int insert_existing_item(game_data_t *game, char *name, int qty, int i)
{
    inventory_slot_t *slot = &game->player_data->inventory->slots[i];

    if (slot->item != NULL && strcmp(slot->item->name, name) == 0 &&
    slot->item->is_stackable == true) {
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

static void remove_item_from_inventory(game_data_t *game, int slot_id)
{
    inventory_slot_t *slot = &game->player_data->inventory->slots[slot_id];

    if (slot->item != NULL) {
        slot->item = NULL;
        slot->quantity = 0;
        slot->weight = 0;
        update_inventory_weight(game);
    }
}

static void use_item(game_data_t *game, int slot_id)
{
    inventory_slot_t *slot = &game->player_data->inventory->slots[slot_id];

    if (slot->item != NULL && slot->item->is_usable == true) {
        slot->quantity--;
        slot->weight = slot->item->weight * slot->quantity;
        if (slot->item->effect != NULL) {
            slot->item->effect(game);
        } else {
            game->player_data->armor += slot->item->armor;
            game->player_data->speed += slot->item->speed;
            game->player_data->health = game->player_data->health +
            slot->item->health > game->player_data->max_health ?
            game->player_data->max_health : game->player_data->health +
            slot->item->health;
            game->player_data->attack += slot->item->damage;
        }
        if (slot->quantity == 0) {
            remove_item_from_inventory(game, slot_id);
        }
    }
}

void calculate_player_stats(game_data_t *game)
{
    game->player_data->armor = 10;
    game->player_data->speed = 10;
    game->player_data->max_health = 15;
    game->player_data->attack = 10;
    for (size_t i = 25; i < 29; i++) {
        if (game->player_data->inventory->slots[i].item != NULL) {
            game->player_data->armor +=
            game->player_data->inventory->slots[i].item->armor;
            game->player_data->speed +=
            game->player_data->inventory->slots[i].item->speed;
            game->player_data->max_health +=
            game->player_data->inventory->slots[i].item->health;
            game->player_data->attack +=
            game->player_data->inventory->slots[i].item->damage;
        }
    }
}

void use_or_trash(game_data_t *game, int slot_id, int item_id)
{
    inventory_slot_t *slot = &game->player_data->inventory->slots[item_id];

    if (slot->item != NULL) {
        if (slot_id == 29) {
            use_item(game, item_id);
        }
        if (slot_id == 30) {
            remove_item_from_inventory(game, item_id);
        }
    }
}

void swap_items(game_data_t *game, int dest, int src)
{
    inventory_slot_t *slot = &game->player_data->inventory->slots[dest];
    inventory_slot_t *slot_bis = &game->player_data->inventory->slots[src];
    inventory_slot_t tmp = {0};

    if ((dest == 25 && slot_bis->item->type != ITEM_HELMET) ||
    (slot->item != NULL && src == 25 && slot->item->type != ITEM_HELMET))
        return;
    if ((dest == 26 && slot_bis->item->type != ITEM_ARMOR) ||
    (slot->item != NULL && src == 26 && slot->item->type != ITEM_ARMOR))
        return;
    if ((dest == 27 && slot_bis->item->type != ITEM_SHOES) ||
    (slot->item != NULL && src == 27 && slot->item->type != ITEM_SHOES))
        return;
    if ((dest == 28 && slot_bis->item->type != ITEM_WEAPON) ||
    (slot->item != NULL && src == 28 && slot->item->type != ITEM_WEAPON))
        return;
    tmp = *slot;
    *slot = *slot_bis;
    *slot_bis = tmp;
}

void insert_item_in_inventory(game_data_t *game, char *item_name, int qty)
{
    inventory_slot_t *slot = NULL;
    int count = qty;

    for (int i = 0; i < 25; i++) {
        if (insert_existing_item(game, item_name, qty, i) == 1)
            return;
    }
    for (int j = 0; j < 25 && count > 0; j++) {
        slot = &game->player_data->inventory->slots[j];
        if (slot->item == NULL &&
        is_valid_weight(game,
        get_item_by_name(item_name)->weight * qty) == 1) {
            slot->item = get_item_by_name(item_name);
            slot->quantity = 1;
            slot->weight = slot->item->weight;
            count--;
            update_inventory_weight(game);
            continue;
        }
    }
}
