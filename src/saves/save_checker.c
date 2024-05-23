/*
** EPITECH PROJECT, 2024
** B-MUL-200-PAR-2-1-myrpg-maxence.bunel [WSL: Ubuntu]
** File description:
** save_checker
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

#include "my_game.h"
#include "saves.h"

const char *SAVES_NAMES[3] = {
    "database/save_1.ven",
    "database/save_2.ven",
    "database/save_3.ven"
};

void format_date(time_t rawtime, char *buffer, size_t buffer_size)
{
    struct tm *timeinfo = localtime(&rawtime);

    snprintf(buffer, buffer_size, "DATE : %02d-%02d-%04d",
    timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900);
}

int count_existing_saves(game_data_t *game)
{
    int count = 0;
    struct stat file_stat;

    for (int i = 0; i < 3; i++) {
        if (access(SAVES_NAMES[i], F_OK) != -1 &&
        stat(SAVES_NAMES[i], &file_stat) == 0) {
            format_date(file_stat.st_ctime,
            game->save_games[i].creation_date,
            sizeof(game->save_games[i].creation_date));
            count++;
            sprintf(game->save_games[i].save_name, "SAVE %d", i + 1);
            sprintf(game->save_games[i].save_path,
            "database/save_%d.ven", i + 1);
        }
    }
    game->validation_count = count;
    game->is_sprite_displayed = count > 0 ? true : false;
    return count;
}
