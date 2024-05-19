/*
** EPITECH PROJECT, 2024
** B-MUL-200-PAR-2-1-myrpg-maxence.bunel
** File description:
** settings_controls
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "my_game.h"

const key_config_s key_config[] = {
    {
        .name = "Forward",
        .key_name = "Z",
        .key = MoveUp
    },
    {
        .name = "Backward",
        .key_name = "S",
        .key = MoveDown
    },
    {
        .name = "Left",
        .key_name = "Q",
        .key = MoveLeft
    },
    {
        .name = "Right",
        .key_name = "D",
        .key = sfKeyD
    },
    {
        .name = "Open inventory",
        .key_name = "I",
        .key = sfKeyI
    },
    {
        .name = "Toggle hostile mode",
        .key_name = "W",
        .key = sfKeyW
    },
    {
        .name = "Interact",
        .key_name = "E",
        .key = sfKeyE
    },
    {
        .name = "Open skill tree",
        .key_name = "Y",
        .key = sfKeyY
    },
    {
        .name = "Heal",
        .key_name = "A",
        .key = sfKeyA
    },
    {
        .name = "Pause",
        .key_name = "P",
        .key = sfKeyP
    }
};

static void set_control_text(game_data_t *game)
{
    sfVector2f text_pos1 = {132, 272};
    sfText *text1;
    int nbr_text = sizeof(key_config) / sizeof(key_config[0]);
    key_config_s *keys = key_config;

    for (int i = 0; i < nbr_text; i++) {
        text1 = set_text(game, keys[i].name, 22, text_pos1);
        sfRenderWindow_drawText(game->window, text1, NULL);
        sfText_destroy(text1);
        text_pos1.y += 61;
    }
}

static void set_keybind_text(game_data_t *game)
{
    sfVector2f text_pos1 = {598, 272};
    sfText *text1;
    int nbr_text = sizeof(key_config) / sizeof(key_config[0]);

    for (int i = 0; i < nbr_text; i++) {
        text1 = set_text(game, key_config[i].key_name, 22, text_pos1);
        sfRenderWindow_drawText(game->window, text1, NULL);
        sfText_destroy(text1);
        text_pos1.y += 61;
    }
}

void modify_control(game_data_t *game)
{
    if (is_key_pressed(game, MoveDown) && game->state == SETTINGS_CONTROLS) {
        game->clicked_control++;
        game->clicked_control %= 10;
    }
    if (is_key_pressed(game, MoveUp) && game->state == SETTINGS_CONTROLS) {
        if (game->clicked_control == 0)
            game->clicked_control = 10;
        game->clicked_control--;
        game->clicked_control %= 10;
    }
}

static void draw_tools_control(game_data_t *game, sfRectangleShape *rect,
    int i)
{
    if (i == game->clicked_control) {
        sfRectangleShape_setFillColor(rect,
            sfColor_fromRGBA(255, 255, 255, 20));
        sfRectangleShape_setOutlineThickness(rect, 2);
        sfRectangleShape_setOutlineColor(rect,
            sfColor_fromRGB(51, 217, 122));
    } else {
        sfRectangleShape_setFillColor(rect,
            sfColor_fromRGBA(255, 255, 255, 0));
    }
    sfRenderWindow_drawRectangleShape(game->window, rect, NULL);
    sfRectangleShape_destroy(rect);
}

static void draw_bg_control(game_data_t *game)
{
    sfRectangleShape *rect;
    sfVector2f rectangle_pos = {106, 260};
    sfVector2f rectangle_size = {664, 52};
    int nbr_rect = 10;

    for (int i = 0; i < nbr_rect; i++) {
        rect = sfRectangleShape_create();
        if (i > 0)
            rectangle_pos.y += 61;
        sfRectangleShape_setPosition(rect, rectangle_pos);
        sfRectangleShape_setSize(rect, rectangle_size);
        draw_tools_control(game, rect, i);
    }
}

void draw_everything_control(game_data_t *game)
{
    basic_menu(game);
    draw_active_navbar_line(game, 290.0f, 270.0f);
    draw_settings_navbar(game);
    set_control_text(game);
    modify_control(game);
    set_keybind_text(game);
    draw_bg_control(game);
}
