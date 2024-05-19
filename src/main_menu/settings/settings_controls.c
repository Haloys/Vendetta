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
#include "my.h"

static void set_control_text(game_data_t *game)
{
    sfVector2f text_pos1 = {132, 272};
    sfText *text1;
    char *str[] = {"Forward", "Backward", "Left", "Right", "Open inventory",
        "Toggle hostile mode", "Interact", "Open skill tree", "Heal", "Pause"};
    int nbr_text = 9;

    for (int i = 0; i < nbr_text; i++) {
        text1 = set_text(game, str[i], 22, text_pos1);
        sfRenderWindow_drawText(game->window, text1, NULL);
        sfText_destroy(text1);
        text_pos1.y += 61;
    }
}

static void set_keybind_text(game_data_t *game)
{
    sfVector2f text_pos1 = {598, 272};
    sfText *text1;
    char *str[] = {"Z", "S", "Q", "D", "I", "W", "E", "Y", "A", "P"};
    int nbr_text = 9;

    for (int i = 0; i < nbr_text; i++) {
        text1 = set_text(game, str[i], 22, text_pos1);
        sfRenderWindow_drawText(game->window, text1, NULL);
        sfText_destroy(text1);
        text_pos1.y += 61;
    }
}

void modify_control(game_data_t *game)
{
    if (is_key_pressed(game, MoveDown) && game->state == SETTINGS_CONTROLS) {
        game->clicked_control++;
        game->clicked_control %= 9;
    }
    if (is_key_pressed(game, MoveUp) && game->state == SETTINGS_CONTROLS) {
        if (game->clicked_control == 0)
            game->clicked_control = 9;
        game->clicked_control--;
        game->clicked_control %= 9;
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
    int nbr_rect = 9;

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
