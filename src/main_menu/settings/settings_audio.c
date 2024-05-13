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
#include "my.h"

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

static void draw_slider_line(game_data_t *game)
{
    init_slider_music(&game->slider, (sfVector2f){420.0f, 280.0f}, 420.0f, 643.0f);
    init_slider_ambient(&game->slider, (sfVector2f){420.0f, 340.0f}, 420.0f, 643.0f);
    init_slider_global(&game->slider, (sfVector2f){420.0f, 400.0f}, 420.0f, 643.0f);
}

static void draw_global_sound(game_data_t *game)
{
    sfRectangleShape *line = sfRectangleShape_create();
    sfVector2f line_pos = {427, 285};
    sfVector2f line_size = {85, 5};

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
    sfVector2f line_size = {20, 5};

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
    sfVector2f line_size = {130, 5};

    sfRectangleShape_setPosition(line, line_pos);
    sfRectangleShape_setSize(line, line_size);
    sfRectangleShape_setFillColor(line, sfWhite);
    sfRenderWindow_drawRectangleShape(game->window, line, NULL);
    sfRectangleShape_destroy(line);
}

void draw_everything_sound(game_data_t *game)
{
    basic_menu(game);
    draw_active_navbar_line(game, 290.0f, 270.0f);
    draw_settings_navbar(game);
    set_sound_text(game);
    draw_slider_line(game);
    draw_slider(&game->slider, game);
    update_slider_music(game, &game->slider);
    update_slider_ambient(game, &game->slider);
    update_slider_global(game, &game->slider);
}
