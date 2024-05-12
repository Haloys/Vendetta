/*
** EPITECH PROJECT, 2024
** B-MUL-200-PAR-2-1-myrpg-maxence.bunel
** File description:
** main_menu
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#include "navbar.h"
#include "my.h"

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
        sfColor_fromRGB(0, 120, 255) : NAVBAR_TEXT_COLOR);
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

    if (!game->is_navbar_visible) {
        return;
    }
    for (size_t i = 0; i < sizeof(elements) / sizeof(elements[0]); i++) {
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
            game->state = clicked_element->target_state;
        }
    }
}

void draw_navbar(game_data_t *game)
{
    int navbar_element_count = sizeof(elements) / sizeof(navbar_element_t);

    game->is_navbar_visible = true;
    for (int i = 0; i < navbar_element_count; i++) {
        draw_navbar_element(game, &elements[i], i);
    }
    draw_navbar_line(game, 80.0f, 1294.0f);
}
