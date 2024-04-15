/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** my_radar project
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "my_game.h"
#include "my.h"

int get_highest_score(void)
{
    FILE *file = fopen(SCORE_FILE_PATH, "r");
    struct stat sb;
    char *buff;

    my_putstr("Initialize highest_score\n");
    if (file == NULL)
        return 0;
    stat(SCORE_FILE_PATH, &sb);
    buff = malloc(sb.st_size + 1);
    if (read(3, buff, sb.st_size) == -1)
        return 0;
    buff[sb.st_size] = '\0';
    fclose(file);
    my_putstr("OK !\n");
    return my_getnbr(buff);
}

void save_highest_score(int highest_score)
{
    FILE *fp = fopen(SCORE_FILE_PATH, "w");
    char *buff = malloc(sizeof(char) * (12 + 1));

    buff = my_nbrstr(highest_score);
    fwrite(buff, 1, my_strlen(buff), fp);
}

void set_score(game_data_t *game, int new_points)
{
    game->score += new_points;
    if (game->score > game->highest_score) {
        game->highest_score = game->score;
        save_highest_score(game->highest_score);
    }
}
