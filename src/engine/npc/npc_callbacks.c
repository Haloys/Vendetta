/*
** EPITECH PROJECT, 2024
** B-MUL-200-PAR-2-1-myrpg-maxence.bunel [WSL: Ubuntu]
** File description:
** npc_callbacks
*/

#include <stdio.h>

#include "my_game.h"
#include "game_npc.h"
#include "gameplay.h"
#include "utils.h"

int first_npc_callback(game_data_t *game, npc_t *npc)
{
    printf("Interacting with %s\n", npc->config->name);
    game->player->npc_id = 0;
    insert_item_in_inventory(game, "first_book", 1);
    insert_item_in_inventory(game, "green_shoes", 1);
    change_game_mode(game, NPC_DIALOGUE);
    return 0;
}

int second_npc_callback(game_data_t *game, npc_t *npc)
{
    int qty = get_item_quantity(game, "goldcoin");

    printf("Interacting with %s\n", npc->config->name);
    if (qty >= 1) {
        remove_item_from_inventory_by_name(game, "goldcoin");
        insert_item_in_inventory(game, "rifle", 1);
    }
    game->player->npc_id = 1;
    change_game_mode(game, NPC_DIALOGUE);
    return 0;
}

int third_npc_callback(game_data_t *game, npc_t *npc)
{
    printf("Interacting with %s\n", npc->config->name);
    insert_item_in_inventory(game, "oxycodone", 1);
    game->player->npc_id = 2;
    change_game_mode(game, NPC_DIALOGUE);
    return 0;
}

int fourth_npc_callback(game_data_t *game, npc_t *npc)
{
    game->player->npc_id = 3;
    printf("Interacting with %s\n", npc->config->name);
    insert_item_in_inventory(game, "second_book", 1);
    insert_item_in_inventory(game, "keyc", 1);
    change_game_mode(game, NPC_DIALOGUE);
    return 0;
}

int fifth_npc_callback(game_data_t *game, npc_t *npc)
{
    printf("Interacting with %s\n", npc->config->name);
    insert_item_in_inventory(game, "armor2", 1);
    game->player->npc_id = 4;
    change_game_mode(game, NPC_DIALOGUE);
    return 0;
}
