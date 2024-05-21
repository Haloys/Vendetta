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
    ending->y_offset -= ending->ending_speed;
    if (ending->y_offset + (float)ending->line_count * 40 < 0) {
        ending->state = (ending->state == 0) ? 1 : 3;
        if (ending->state == 1) {
            ending->end_wait_time = time(NULL);
        }
    }
}

static void free_and_reload_credits(ending_screen_t *ending)
{
    free_credits(ending->credits, ending->line_count);
    ending->credits = load_credits("database/credits/additional_credits.txt",
        &ending->line_count);
    ending->y_offset = 600;
    ending->state = 2;
    ending->ending_speed = 1.0f;
}

static void check_end_wait_time(ending_screen_t *ending, game_data_t *game)
{
    if (time(NULL) >= ending->end_wait_time) {
        if (ending->state == 1) {
            printf("Segmentation Fault (core dumped)\n");
            sfRenderWindow_close(game->window);
            sleep(5);
            free_and_reload_credits(ending);
            game->window = sfRenderWindow_create(game->video_mode, game->name,
                sfResize | sfClose, NULL);
        }
        if (ending->state == 3)
            change_game_mode(game, MAIN_MENU);
    }
}

static void handle_display_state(ending_screen_t *ending,
    game_data_t *game, credits_data_t *data)
{
    if (ending->state == 0 || ending->state == 2) {
        basic_design(game);
        display_credits(game->window, data);
        update_credits_position(ending);
    } else if (ending->state == 1 || ending->state == 3) {
        check_end_wait_time(ending, game);
    }
}

void display_ending_screen(game_data_t *game)
{
    static ending_screen_t ending = {NULL, 0, 600, 0, 0, 40.0f};
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
    handle_display_state(&ending, game, &data);
}
