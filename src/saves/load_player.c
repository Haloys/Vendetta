/*
** EPITECH PROJECT, 2024
** B-MUL-200-PAR-2-1-myrpg-maxence.bunel [WSL: Ubuntu]
** File description:
** load_player
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "my_game.h"

static unsigned long get_next_hash_values_2(unsigned long hash, FILE *file)
{
    char buffer[64] = {0};
    int temp = 0;

    fscanf(file, "%s\n", buffer);
    sscanf(buffer, "armor_lvl=%d", &temp);
    hash += temp;
    fscanf(file, "%s\n", buffer);
    sscanf(buffer, "attack_lvl=%d", &temp);
    hash += temp;
    fscanf(file, "%s\n", buffer);
    sscanf(buffer, "health_lvl=%d", &temp);
    hash += temp;
    fscanf(file, "%s\n", buffer);
    sscanf(buffer, "speed_lvl=%d", &temp);
    hash += temp;
    fscanf(file, "%s\n", buffer);
    sscanf(buffer, "map_id=%d", &temp);
    hash += temp;
    return hash;
}

static unsigned long get_next_hash_values(unsigned long hash, FILE *file)
{
    char buffer[64] = {0};
    int temp = 0;
    float x = 0;
    float y = 0;

    fscanf(file, "%s\n", buffer);
    sscanf(buffer, "position=%f:%f", &x, &y);
    fscanf(file, "%s\n", buffer);
    sscanf(buffer, "current_lvl=%d", &temp);
    hash += temp;
    fscanf(file, "%s\n", buffer);
    sscanf(buffer, "current_xp=%d", &temp);
    hash += temp;
    fscanf(file, "%s\n", buffer);
    sscanf(buffer, "skill_points=%d", &temp);
    hash += temp;
    return get_next_hash_values_2(hash, file);
}

unsigned long get_hash_values_from_file(FILE *file)
{
    unsigned long hash = 0;
    char buffer[64] = {0};
    char item[64] = {0};
    int temp = 0;
    int qty = 0;

    for (int i = 0; i < 29; i++) {
        fscanf(file, "%s\n", buffer);
        sscanf(buffer, "item=%d:%[^:]:%d", &temp, item, &qty);
        if (strcmp(item, "NULL") == 0) {
            continue;
        }
        hash += strlen(item);
        hash += qty;
    }
    fscanf(file, "%s\n", buffer);
    sscanf(buffer, "health=%d", &temp);
    hash += temp;
    return get_next_hash_values(hash, file);
}

static int verify_file_hash(char *base_value)
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

void read_inventory(game_data_t *game, FILE *file)
{
    char buffer[64] = {0};
    char item[64] = {0};
    int temp = 0;
    int qty = 0;

    for (int i = 0; i < 29; i++) {
        fscanf(file, "%s\n", buffer);
        if (strstr(buffer, "item=") != NULL) {
            sscanf(buffer, "item=%d:%[^:]:%d", &temp, item, &qty);
            insert_item_at_specific_slot(game, item, qty, temp);
        }
    }
}

static void read_continue(game_data_t *game, FILE *file)
{
    char buffer[32] = {0};
    int temp = 0;

    fscanf(file, "%s\n", buffer);
    sscanf(buffer, "current_xp=%d", &game->player->current_xp);
    fscanf(file, "%s\n", buffer);
    sscanf(buffer, "skill_points=%d", &game->player->skill_points);
    fscanf(file, "%s\n", buffer);
    sscanf(buffer, "armor_lvl=%d", &game->player->skill_tree->armor_lvl);
    fscanf(file, "%s\n", buffer);
    sscanf(buffer, "attack_lvl=%d", &game->player->skill_tree->attack_lvl);
    fscanf(file, "%s\n", buffer);
    sscanf(buffer, "health_lvl=%d", &game->player->skill_tree->health_lvl);
    fscanf(file, "%s\n", buffer);
    sscanf(buffer, "speed_lvl=%d", &game->player->skill_tree->speed_lvl);
    fscanf(file, "%s\n", buffer);
    sscanf(buffer, "map_id=%d", &temp);
    set_map(game, temp, &game->player->position);
    calculate_player_stats(game);
}

static void read_save_data(game_data_t *game, FILE *file)
{
    char buffer[32] = {0};
    float x = 0;
    float y = 0;

    fscanf(file, "%s\n", buffer);
    sscanf(buffer, "health=%d", &game->player->health);
    fscanf(file, "%s\n", buffer);
    sscanf(buffer, "position=%f:%f", &x, &y);
    game->player->position = (sfVector2f){x, y};
    fscanf(file, "%s\n", buffer);
    sscanf(buffer, "current_lvl=%d", &game->player->current_lvl);
    read_continue(game, file);
}

int load_game(game_data_t *game)
{
    FILE *file = NULL;
    char buffer[64] = {0};

    if (game->player->save_number == -1)
        return 1;
    if (game->player->save_number == 1)
        strcpy(buffer, "database/save_1.ven");
    if (game->player->save_number == 2)
        strcpy(buffer, "database/save_2.ven");
    if (game->player->save_number == 3)
        strcpy(buffer, "database/save_3.ven");
    if (verify_file_hash(buffer) == 1)
        return 1;
    file = fopen(buffer, "r");
    read_inventory(game, file);
    read_save_data(game, file);
    fclose(file);
    return 0;
}
