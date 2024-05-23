/*
** EPITECH PROJECT, 2024
** B-MUL-200-PAR-2-1-myrpg-maxence.bunel [WSL: Ubuntu]
** File description:
** save_player
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "my_game.h"

static unsigned long get_hash(game_data_t *game, player_data_t *player)
{
    unsigned long hash = 0;

    for (int i = 0; i < 29; i++) {
        if (player->inventory->slots[i].item != NULL) {
            hash += strlen(player->inventory->slots[i].item->name);
            hash += player->inventory->slots[i].quantity;
        }
    }
    hash += player->health;
    hash += player->current_lvl;
    hash += player->current_xp;
    hash += player->skill_points;
    hash += player->skill_tree->armor_lvl;
    hash += player->skill_tree->attack_lvl;
    hash += player->skill_tree->health_lvl;
    hash += player->skill_tree->speed_lvl;
    hash += game->map.id;
    return hash;
}

static void write_inventory(game_data_t *game, FILE *file)
{
    player_data_t *player = game->player;

    for (int i = 0; i < 29; i++) {
        if (player->inventory->slots[i].item != NULL) {
            fprintf(file, "item=%d:%s:%d\n", i,
            player->inventory->slots[i].item->name,
            player->inventory->slots[i].quantity);
        }
        if (player->inventory->slots[i].item == NULL)
            fprintf(file, "item=%d:NULL:0\n", i);
    }
}

static void write_data(game_data_t *game, FILE *file)
{
    player_data_t *player = game->player;
    unsigned long hash = hash_values(get_hash(game, player));

    fprintf(file, "health=%d\n", player->health);
    fprintf(file, "position=%f:%f\n", player->position.x, player->position.y);
    fprintf(file, "current_lvl=%d\n", player->current_lvl);
    fprintf(file, "current_xp=%d\n", player->current_xp);
    fprintf(file, "skill_points=%d\n", player->skill_points);
    fprintf(file, "armor_lvl=%d\n", player->skill_tree->armor_lvl);
    fprintf(file, "attack_lvl=%d\n", player->skill_tree->attack_lvl);
    fprintf(file, "health_lvl=%d\n", player->skill_tree->health_lvl);
    fprintf(file, "speed_lvl=%d\n", player->skill_tree->speed_lvl);
    fprintf(file, "map_id=%d\n", game->map.id);
    fprintf(file, "hash=%ld\n", hash);
}

int save_game(game_data_t *game)
{
    FILE *file = NULL;

    if (game->player->save_number == -1)
        return 1;
    if (game->player->save_number == 1)
        file = fopen("database/save_1.ven", "w");
    if (game->player->save_number == 2)
        file = fopen("database/save_2.ven", "w");
    if (game->player->save_number == 3)
        file = fopen("database/save_3.ven", "w");
    if (!file)
        return 1;
    write_inventory(game, file);
    write_data(game, file);
    fclose(file);
    return 0;
}

int verify_file_hash(char *base_value)
{
    FILE *file = fopen(base_value, "r");
    unsigned long base_hash = get_hash_values_from_file(file);
    unsigned long hash = hash_values(base_hash);
    unsigned long file_hash = 0;
    char buffer[64] = {0};

    if (!file)
        return 1;
    fscanf(file, "%s\n", buffer);
    sscanf(buffer, "hash=%ld", &file_hash);
    if (file_hash != hash) {
        dprintf(1, "The save authentification has failed\n");
        fclose(file);
        return 1;
    }
    dprintf(1, "The save authentification has succeeded\n");
    fclose(file);
    return 0;
}
