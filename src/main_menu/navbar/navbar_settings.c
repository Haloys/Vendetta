/*
** EPITECH PROJECT, 2024
** Vendetta / Main Menu / Navbar
** File description:
** Navbar Settings
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#include "my_game.h"
#include "main_menu.h"
#include "utils.h"

static sfVector2f get_text_position(const settings_navbar_element_t
    *element, sfText *text)
{
    sfVector2f text_size = {sfText_getLocalBounds(text).width,
        sfText_getLocalBounds(text).height};

    return (sfVector2f){
        element->position.x + (element->size.x - text_size.x) / 2,
        element->position.y + (element->size.y - text_size.y) / 2
    };
}

static sfColor get_hover_color(game_data_t *game,
    const settings_navbar_element_t *element)
{
    bool is_hovered = game->mouse_pos.x >= element->position.x &&
        game->mouse_pos.x <= element->position.x + element->size.x &&
        game->mouse_pos.y >= element->position.y &&
        game->mouse_pos.y <= element->position.y + element->size.y;
    bool is_active = false;

    if ((strcmp(element->label, "Video") == 0 &&
        game->state == SETTINGS_VIDEO) ||
        (strcmp(element->label, "Controls") == 0 &&
        game->state == SETTINGS_CONTROLS) ||
        (strcmp(element->label, "Audio") == 0 &&
        game->state == SETTINGS_AUDIO)) {
        is_active = true;
    }
    return is_hovered || is_active ? sfColor_fromRGBA(51, 217, 122, 20)
    : sfColor_fromRGBA(255, 255, 255, 0);
}

static text_draw_info_settings_t get_text_draw_info(game_data_t *game,
    const settings_navbar_element_t *element, sfText *text)
{
    text_draw_info_settings_t info;

    info.text_position = get_text_position(element, text);
    info.hover_color = get_hover_color(game, element);
    return info;
}

static void draw_hover_area(game_data_t *game,
    const settings_navbar_element_t *element, sfColor hover_color)
{
    sfRectangleShape *hover_area;
    sfVector2f hover_pos = {element->position.x, element->position.y + 5};

    hover_area = sfRectangleShape_create();
    sfRectangleShape_setPosition(hover_area, hover_pos);
    sfRectangleShape_setSize(hover_area, element->size);
    sfRectangleShape_setFillColor(hover_area, hover_color);
    sfRectangleShape_setOutlineThickness(hover_area,
    hover_color.a > 0 ? 2.0 : 0.0);
    sfRectangleShape_setOutlineColor(hover_area,
    sfColor_fromRGBA(51, 217, 122, 50));
    sfRenderWindow_drawRectangleShape(game->window, hover_area, NULL);
    sfRectangleShape_destroy(hover_area);
}

static void draw_text(game_data_t *game,
    const settings_navbar_element_t *element, sfVector2f text_position)
{
    sfText *text = set_text_const(game, element->label, 20, text_position);

    sfRenderWindow_drawText(game->window, text, NULL);
    sfText_destroy(text);
}

static void draw_settings_element(game_data_t *game,
    const settings_navbar_element_t *element)
{
    sfText *text = set_text_const(game, element->label, 20, element->position);
    text_draw_info_settings_t draw_info =
        get_text_draw_info(game, element, text);

    draw_hover_area(game, element, draw_info.hover_color);
    draw_text(game, element, draw_info.text_position);
}

static int get_clicked_element_index(game_data_t *game)
{
    const settings_navbar_element_t elements[] = {
        {"Video", {115, 140}, {153, 52}},
        {"Controls", {335, 140}, {153, 52}},
        {"Audio", {535, 140}, {153, 52}}
    };
    int elements_count = sizeof(elements) /
        sizeof(settings_navbar_element_t);

    for (int i = 0; i < elements_count; i++) {
        if ((game->state == SETTINGS_VIDEO || game->state == SETTINGS_CONTROLS
            || game->state == SETTINGS_AUDIO) &&
            game->mouse_pos.x >= elements[i].position.x &&
            game->mouse_pos.x <= elements[i].position.x +
            elements[i].size.x && game->mouse_pos.y >= elements[i].position.y
            && game->mouse_pos.y <= elements[i].position.y +
            elements[i].size.y) {
            return i;
        }
    }
    return -1;
}

void handle_settings_click(game_data_t *game)
{
    int clicked_element_index = get_clicked_element_index(game);

    if (clicked_element_index != -1) {
        switch (clicked_element_index) {
        case 0:
            change_game_mode(game, SETTINGS_VIDEO);
            break;
        case 1:
            change_game_mode(game, SETTINGS_CONTROLS);
            break;
        case 2:
            change_game_mode(game, SETTINGS_AUDIO);
            break;
        }
    }
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
    if (game->last_state == MAIN_MENU)
        draw_active_navbar_line(game, 290.0f, 270.0f);
    else
        draw_active_navbar_line(game, 905.0f, 262.0f);
    draw_settings_navbar(game);
    load_arrow(game);
    set_fps_text(game);
    set_screen_text(game);
    set_reso_text(game);
    set_utils_text(game);
}
