/*
** EPITECH PROJECT, 2024
** Vendetta / Loading Screen
** File description:
** Loading Screen
*/

#include "my_game.h"
#include "fade_in_out.h"
#include "utils.h"
#include "ending_screen.h"

#include <unistd.h>
#include <stdio.h>
#include <string.h>

static char *read_line(FILE *file)
{
    char buffer[256];

    if (!fgets(buffer, sizeof(buffer), file)) {
        return NULL;
    }
    return strdup(buffer);
}

static FILE *open_file(const char *filename)
{
    FILE *file = fopen(filename, "r");

    return file;
}

static char **read_and_store_lines(FILE *file, char **lines, size_t *count)
{
    char *line = NULL;
    char **temp = NULL;

    while (1) {
        line = read_line(file);
        if (!line)
            break;
        temp = realloc(lines, sizeof(char *) * (*count + 1));
        if (!temp) {
            free(line);
            break;
        }
        lines = temp;
        lines[*count] = line;
        (*count)++;
    }
    return lines;
}

static char **cleanup_and_return(FILE *file, char **lines,
    size_t count, size_t *line_count)
{
    fclose(file);
    *line_count = count;
    return lines;
}

char **load_credits(const char *filename, size_t *line_count)
{
    FILE *file = open_file(filename);
    size_t count = 0;
    char **lines = NULL;

    if (!file)
        return NULL;
    lines = read_and_store_lines(file, NULL, &count);
    return cleanup_and_return(file, lines, count, line_count);
}
