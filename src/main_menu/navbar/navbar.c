/*
** EPITECH PROJECT, 2024
** Vendetta / Main Menu / Navbar
** File description:
** Navbar
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#include "navbar.h"
#include "utils.h"

static void draw_navbar_line(game_data_t *game, float pos_x, float size_x)
{
    sfRectangleShape *line = sfRectangleShape_create();

    sfRectangleShape_setPosition(line, (sfVector2f){pos_x, 104.0f});
    sfRectangleShape_setSize(line, (sfVector2f){size_x, 2.0f});
    sfRectangleShape_setFillColor(line, NAVBAR_LINE_COLOR);
    sfRenderWindow_drawRectangleShape(game->window, line, NULL);
    sfRectangleShape_destroy(line);
}

static void handle_navbar_hover(game_data_t *game,
    const navbar_element_t *element, int i, sfText *text)
{
    game->hover_array[i] = (game->mouse_pos.x >= element->position.x &&
            game->mouse_pos.x <= element->position.x + element->size.x &&
            game->mouse_pos.y >= element->position.y &&
            game->mouse_pos.y <= element->position.y + element->size.y);
    sfText_setColor(text, game->hover_array[i] ?
        sfWhite : NAVBAR_TEXT_COLOR);
}

static void draw_navbar_element(game_data_t *game,
    const navbar_element_t *element, int i)
{
    sfRectangleShape *hover_area = sfRectangleShape_create();
    sfSprite *icon = get_sprite(game, element->icon);
    sfText *text = sfText_create();

    sfRectangleShape_setPosition(hover_area, element->position);
    sfRectangleShape_setSize(hover_area, element->size);
    sfRectangleShape_setFillColor(hover_area, sfColor_fromRGBA(0, 0, 0, 0));
    sfRenderWindow_drawSprite(game->window, icon, NULL);
    sfText_setString(text, element->label);
    sfText_setFont(text, game->font);
    sfText_setCharacterSize(text, 30);
    handle_navbar_hover(game, element, i, text);
    sfText_setPosition(text, element->position);
    sfRenderWindow_drawRectangleShape(game->window, hover_area, NULL);
    sfRenderWindow_drawText(game->window, text, NULL);
    sfText_destroy(text);
    sfRectangleShape_destroy(hover_area);
}

static const navbar_element_t *get_clicked_element(game_data_t *game,
    sfMouseButtonEvent mouse_event)
{
    const navbar_element_t *elem;
    const navbar_element_t *elements;
    size_t navbar_element_count = game->last_state == MAIN_MENU ? 4 : 5;

    if (!game->is_navbar_visible) {
        return NULL;
    }
    elements = game->last_state == MAIN_MENU ? HOME_ELEMENTS : GAME_ELEMENTS;
    for (size_t i = 0; i < navbar_element_count; i++) {
        elem = &elements[i];
        if (mouse_event.x >= elem->position.x &&
            mouse_event.x <= elem->position.x + elem->size.x &&
            mouse_event.y >= elem->position.y &&
            mouse_event.y <= elem->position.y + elem->size.y) {
            return elem;
        }
    }
    return NULL;
}

void handle_navbar_click(game_data_t *game, sfMouseButtonEvent mouse_event)
{
    const navbar_element_t *clicked_element =
        get_clicked_element(game, mouse_event);

    if (!game->is_navbar_visible)
        return;
    if (clicked_element) {
        if (strcmp(clicked_element->label, "QUIT") == 0) {
            sfRenderWindow_close(game->window);
        } else {
            change_game_mode(game, clicked_element->target_state);
        }
    }
}

void draw_navbar(game_data_t *game)
{
    navbar_element_t *elements = NULL;
    int navbar_element_count = 0;

    if (game->last_state == MAIN_MENU) {
        elements = (navbar_element_t *)HOME_ELEMENTS;
        navbar_element_count = 4;
    }
    if (game->last_state == INVENTORY || game->last_state == SKILL_TREE) {
        elements = (navbar_element_t *)GAME_ELEMENTS;
        navbar_element_count = 5;
    }
    game->is_navbar_visible = true;
    for (int i = 0; i < navbar_element_count; i++) {
        draw_navbar_element(game, &elements[i], i);
    }
    draw_navbar_line(game, 80.0f, 1294.0f);
}
