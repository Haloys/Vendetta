/*
** EPITECH PROJECT, 2024
** B-MUL-200-PAR-2-1-myrpg-maxence.bunel
** File description:
** main_menu
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "my_game.h"
#include "my.h"
#include "score.h"

static text_draw_info_settings_t get_text_draw_info(game_data_t *game,
    const settings_navbar_element_t *element, sfText *text)
{
    text_draw_info_settings_t info;
    sfVector2f text_size = {sfText_getLocalBounds(text).width,
        sfText_getLocalBounds(text).height};
    bool is_hovered;

    info.text_position = (sfVector2f){
        element->position.x + (element->size.x - text_size.x) / 2,
        element->position.y + (element->size.y - text_size.y) / 2
    };
    is_hovered = game->mouse_x >= element->position.x &&
        game->mouse_x <= element->position.x + element->size.x &&
        game->mouse_y >= element->position.y &&
        game->mouse_y <= element->position.y + element->size.y;
    info.hover_color = is_hovered ? sfColor_fromRGBA(51, 217, 122, 51)
    : sfColor_fromRGBA(255, 255, 255, 0);
    return info;
}

static void draw_settings_element(game_data_t *game,
    const settings_navbar_element_t *element)
{
    sfText *text = sfText_create();
    text_draw_info_settings_t draw_info;
    sfRectangleShape *hover_area;

    sfText_setString(text, element->label);
    sfText_setFont(text, game->font);
    sfText_setCharacterSize(text, 20);
    draw_info = get_text_draw_info(game, element, text);
    sfText_setPosition(text, draw_info.text_position);
    hover_area = sfRectangleShape_create();
    sfRectangleShape_setPosition(hover_area, element->position);
    sfRectangleShape_setSize(hover_area, element->size);
    sfRectangleShape_setFillColor(hover_area, draw_info.hover_color);
    sfRenderWindow_drawRectangleShape(game->window, hover_area, NULL);
    sfRenderWindow_drawText(game->window, text, NULL);
    sfText_destroy(text);
    sfRectangleShape_destroy(hover_area);
}

void draw_settings_navbar(game_data_t *game)
{
    const settings_navbar_element_t elements[] = {
        {"Video", {115, 140}, {153, 52}},
        {"Controls", {335, 140}, {153, 52}},
        {"Audio", {535, 140}, {153, 52}}
    };
    int elements_count = sizeof(elements) / sizeof(settings_navbar_element_t);

    for (int i = 0; i < elements_count; i++) {
        draw_settings_element(game, &elements[i]);
    }
}

void basic_settings(game_data_t *game)
{
    basic_menu(game);
    draw_active_navbar_line(game, 290.0f, 270.0f);
    draw_settings_navbar(game);
    load_arrow(game);
    set_fps_text(game);
}
