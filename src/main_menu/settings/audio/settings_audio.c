/*
** EPITECH PROJECT, 2024
** B-MUL-200-PAR-2-1-myrpg-maxence.bunel
** File description:
** settings_audio
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "my_game.h"

static void set_sound_text(game_data_t *game)
{
    sfVector2f text_pos1 = {132, 272};
    sfVector2f text_pos2 = {132, 333};
    sfVector2f text_pos3 = {132, 394};
    sfText *text1;
    sfText *text2;
    sfText *text3;

    text1 = set_text(game, "Global sound", 22, text_pos1);
    text2 = set_text(game, "Music sound", 22, text_pos2);
    text3 = set_text(game, "Ambient sound", 22, text_pos3);
    sfRenderWindow_drawText(game->window, text1, NULL);
    sfRenderWindow_drawText(game->window, text2, NULL);
    sfRenderWindow_drawText(game->window, text3, NULL);
    sfText_destroy(text1);
    sfText_destroy(text2);
    sfText_destroy(text3);
}

static void draw_global_sound(game_data_t *game)
{
    sfRectangleShape *line = sfRectangleShape_create();
    sfVector2f line_pos = {427, 285};
    sfVector2f line_size = {game->settings.sg_x, 5};

    sfRectangleShape_setPosition(line, line_pos);
    sfRectangleShape_setSize(line, line_size);
    sfRectangleShape_setFillColor(line, sfWhite);
    sfRenderWindow_drawRectangleShape(game->window, line, NULL);
    sfRectangleShape_destroy(line);
}

static void draw_music_sound(game_data_t *game)
{
    sfRectangleShape *line = sfRectangleShape_create();
    sfVector2f line_pos = {427, 346};
    sfVector2f line_size = {game->settings.sm_x, 5};

    sfRectangleShape_setPosition(line, line_pos);
    sfRectangleShape_setSize(line, line_size);
    sfRectangleShape_setFillColor(line, sfWhite);
    sfRenderWindow_drawRectangleShape(game->window, line, NULL);
    sfRectangleShape_destroy(line);
}

static void draw_ambient_sound(game_data_t *game)
{
    sfRectangleShape *line = sfRectangleShape_create();
    sfVector2f line_pos = {427, 407};
    sfVector2f line_size = {game->settings.sa_x, 5};

    sfRectangleShape_setPosition(line, line_pos);
    sfRectangleShape_setSize(line, line_size);
    sfRectangleShape_setFillColor(line, sfWhite);
    sfRenderWindow_drawRectangleShape(game->window, line, NULL);
    sfRectangleShape_destroy(line);
}

static void draw_bg_line(game_data_t *game)
{
    sfRectangleShape *line;
    sfVector2f line_pos = {427, 285};
    sfVector2f line_size = {243, 5};
    int nbr_line = 3;

    for (int i = 0; i < nbr_line; i++) {
        line = sfRectangleShape_create();
        if (i > 0)
            line_pos.y += 61;
        sfRectangleShape_setPosition(line, line_pos);
        sfRectangleShape_setSize(line, line_size);
        sfRectangleShape_setFillColor(line, SQUARE_BG);
        sfRenderWindow_drawRectangleShape(game->window, line, NULL);
        sfRectangleShape_destroy(line);
    }
}

void draw_bg_rectangle(game_data_t *game)
{
    sfRectangleShape *rect;
    sfVector2f rectangle_pos = {106, 260};
    sfVector2f rectangle_size = {664, 52};
    int nbr_rect = 3;

    for (int i = 0; i < nbr_rect; i++) {
        rect = sfRectangleShape_create();
        if (i > 0)
            rectangle_pos.y += 61;
        sfRectangleShape_setPosition(rect, rectangle_pos);
        sfRectangleShape_setSize(rect, rectangle_size);
        draw_tools(game, rect, i);
    }
}

void draw_everything_sound(game_data_t *game)
{
    basic_menu(game);
    if (game->last_state == MAIN_MENU)
        draw_active_navbar_line(game, 290.0f, 270.0f);
    else
        draw_active_navbar_line(game, 905.0f, 262.0f);
    draw_settings_navbar(game);
    set_sound_text(game);
    modify_sound(game);
    draw_bg_rectangle(game);
    draw_bg_line(game);
    draw_global_sound(game);
    draw_music_sound(game);
    draw_ambient_sound(game);
}
