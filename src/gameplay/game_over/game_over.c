/*
** EPITECH PROJECT, 2024
** Vendetta / Loading Screen
** File description:
** Loading Screen
*/

#include "my_game.h"
#include "fade_in_out.h"
#include "game_over.h"
#include "utils.h"

#include <unistd.h>
#include <stdio.h>
#include <string.h>

static void basic_game_over(game_data_t *game)
{
    sprite_id_t elements[] = {SP_DEAD};
    size_t element_count = 1;

    for (size_t i = 0; i < element_count; i++) {
        sfRenderWindow_drawSprite(game->window,
            get_sprite(game, elements[i]), NULL);
    }
}

static sfRectangleShape *create_rect(sfVector2f size, sfVector2f pos,
    sfColor fill, sfColor outline)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    if (rect == NULL)
        return NULL;
    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setPosition(rect, pos);
    sfRectangleShape_setOutlineThickness(rect, 2);
    sfRectangleShape_setFillColor(rect, fill);
    sfRectangleShape_setOutlineColor(rect, outline);
    return rect;
}

static void create_button(game_data_t *game, button_data_t *button_data,
    const char *button_text)
{
    sfVector2f text_position = {button_data->position.x +
        button_data->button_size.x / 2, button_data->position.y +
            button_data->button_size.y / 2};

    *(button_data->button) = create_rect(button_data->button_size,
        button_data->position, FILL_COLOR, OUTLINE_COLOR);
    *(button_data->text) = set_text_const(game, button_text, 30 *
        (WINDOW_WIDTH / 1920.0), text_position);
    sfText_setOrigin(*(button_data->text), (sfVector2f)
        {sfText_getLocalBounds(*(button_data->text)).width / 2,
            sfText_getLocalBounds(*(button_data->text)).height / 2 + 5});
}

static void create_game_over_elems(game_data_t *game, game_over_elems_t *elems)
{
    sfVector2f button_size = {(WINDOW_WIDTH / 1920.0) * 350,
        (WINDOW_HEIGHT / 1080.0) * 60};
    float space = (WINDOW_WIDTH / 1920.0) * 50;
    sfVector2f quit_position = {WINDOW_WIDTH / 2 - button_size.x - space / 2,
        WINDOW_HEIGHT / 2 - button_size.y / 2};
    sfVector2f respawn_position = {WINDOW_WIDTH / 2 + space / 2,
        WINDOW_HEIGHT / 2 - button_size.y / 2};
    button_data_t respawn_button_data = {button_size, respawn_position,
        &(elems->respawn_button), &(elems->respawn_txt)};
    button_data_t quit_button_data = {button_size, quit_position,
        &(elems->quit_button), &(elems->quit_txt)};

    create_button(game, &respawn_button_data, "RESPAWN");
    create_button(game, &quit_button_data, "QUIT");
}

static void set_btn_hover(sfRectangleShape *btn, bool hover)
{
    if (hover) {
        sfRectangleShape_setFillColor(btn, HOVER_FILL_COLOR);
        sfRectangleShape_setOutlineColor(btn, HOVER_OUTLINE_COLOR);
    } else {
        sfRectangleShape_setFillColor(btn, FILL_COLOR);
        sfRectangleShape_setOutlineColor(btn, OUTLINE_COLOR);
    }
}

static void handle_game_over_hover(game_data_t *game, game_over_elems_t *elems)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f mapped_pos = sfRenderWindow_mapPixelToCoords(game->window,
        mouse_pos, sfRenderWindow_getView(game->window));
    sfFloatRect quit_bounds =
        sfRectangleShape_getGlobalBounds(elems->quit_button);
    sfFloatRect respawn_bounds =
        sfRectangleShape_getGlobalBounds(elems->respawn_button);
    bool hover_quit = sfFloatRect_contains(&quit_bounds, mapped_pos.x,
        mapped_pos.y);
    bool hover_respawn = sfFloatRect_contains(&respawn_bounds, mapped_pos.x,
        mapped_pos.y);

    set_btn_hover(elems->quit_button, hover_quit);
    set_btn_hover(elems->respawn_button, hover_respawn);
}

static void handle_clicks(game_data_t *game, game_over_elems_t *elems)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f mapped_pos = sfRenderWindow_mapPixelToCoords(game->window,
        mouse_pos, sfRenderWindow_getView(game->window));
    sfFloatRect quit_bounds =
        sfRectangleShape_getGlobalBounds(elems->quit_button);
    sfFloatRect respawn_bounds =
        sfRectangleShape_getGlobalBounds(elems->respawn_button);

    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (sfFloatRect_contains(&quit_bounds, mapped_pos.x, mapped_pos.y)) {
            sfRenderWindow_close(game->window);
        }
        if (sfFloatRect_contains(&respawn_bounds, mapped_pos.x,
            mapped_pos.y)) {
            change_game_mode(game, PLAYING);
        }
    }
}

void display_game_over(game_data_t *game)
{
    game_over_elems_t elems;

    basic_design(game);
    basic_game_over(game);
    create_game_over_elems(game, &elems);
    handle_game_over_hover(game, &elems);
    sfRenderWindow_drawRectangleShape(game->window, elems.quit_button, NULL);
    sfRenderWindow_drawRectangleShape(game->window,
        elems.respawn_button, NULL);
    sfRenderWindow_drawText(game->window, elems.quit_txt, NULL);
    sfRenderWindow_drawText(game->window, elems.respawn_txt, NULL);
    handle_clicks(game, &elems);
    sfRectangleShape_destroy(elems.quit_button);
    sfRectangleShape_destroy(elems.respawn_button);
    sfText_destroy(elems.quit_txt);
    sfText_destroy(elems.respawn_txt);
}
