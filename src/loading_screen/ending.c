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

static char **load_credits(const char *filename, size_t *line_count)
{
    FILE *file = NULL;
    char **lines = NULL;
    size_t count = 0;

    file = open_file(filename);
    if (!file)
        return NULL;
    lines = read_and_store_lines(file, lines, &count);
    return cleanup_and_return(file, lines, count, line_count);
}

static void free_credits(char **credits, size_t line_count)
{
    for (size_t i = 0; i < line_count; i++) {
        free(credits[i]);
    }
    free(credits);
}

static void display_credits(sfRenderWindow *window, credits_data_t *data)
{
    sfText *text = sfText_create();

    sfText_setFont(text, data->font);
    sfText_setCharacterSize(text, 30);
    for (size_t i = 0; i < data->line_count; i++) {
        sfText_setString(text, data->credits[i]);
        sfText_setPosition(text, (sfVector2f)
            {50, data->y_offset + (float)i * 40});
        sfRenderWindow_drawText(window, text, NULL);
    }
    sfText_destroy(text);
}

static void update_credits_position(ending_screen_t *ending)
{
    ending->y_offset -= 4.5f;
    if (ending->y_offset + (float)ending->line_count * 40 < 0) {
        ending->state = 1;
        ending->end_wait_time = time(NULL) + 2;
    }
}

static void check_end_wait_time(ending_screen_t *ending, game_data_t *game)
{
    if (time(NULL) >= ending->end_wait_time) {
        change_game_mode(game, MAIN_MENU);
        free_credits(ending->credits, ending->line_count);
        ending->credits = NULL;
        ending->line_count = 0;
        ending->y_offset = 600;
        ending->state = 0;
    }
}

void display_ending_screen(game_data_t *game)
{
    static ending_screen_t ending = {NULL, 0, 600, 0, 0};
    credits_data_t data = {
        .credits = ending.credits,
        .line_count = ending.line_count,
        .y_offset = ending.y_offset,
        .font = game->font
    };

    if (!ending.credits) {
        ending.credits = load_credits("database/credits/credits.txt",
            &ending.line_count);
        if (!ending.credits)
            return;
    }
    if (ending.state == 0) {
        basic_design(game);
        display_credits(game->window, &data);
        update_credits_position(&ending);
    } else if (ending.state == 1)
        check_end_wait_time(&ending, game);
}
