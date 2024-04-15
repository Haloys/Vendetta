/*
** EPITECH PROJECT, 2024
** list
** File description:
** list manager
*/

#include <stdio.h>
#include <stdlib.h>
#include "game_utils.h"
#include "my.h"

int print_game_help(void)
{
    FILE *file = fopen("./help.game", "r");
    char *line = NULL;
    size_t len = 0;

    if (file == NULL)
        return RET_FAIL;
    while (getline(&line, &len, file) != -1)
        my_putstr(line);
    free(line);
    fclose(file);
    return RET_NONE;
}
