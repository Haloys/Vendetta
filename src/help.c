/*
** EPITECH PROJECT, 2024
** Vendetta
** File description:
** Help
*/

#include <stdio.h>
#include <stdlib.h>

#include "game_utils.h"

int print_game_help(void)
{
    FILE *file = fopen("./help.game", "r");
    char *line = NULL;
    size_t len = 0;

    if (file == NULL)
        return RET_FAIL;
    while (getline(&line, &len, file) != -1)
        dprintf(1, "%s", line);
    free(line);
    fclose(file);
    return RET_NONE;
}
