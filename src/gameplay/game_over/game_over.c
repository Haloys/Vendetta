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

static void create_game_over_elems(game_data_t *game, game_over_elems_t *elems)
{
    sfVector2f b_si = {350, 60};
    float space = 50;
    sfVector2f q_pos = {game->video_mode.width / 2 - b_si.x - space / 2,
        game->video_mode.height / 2 - b_si.y / 2};
    sfVector2f r_pos = {game->video_mode.width / 2 + space / 2,
        game->video_mode.height / 2 - b_si.y / 2};
    sfVector2f qt_pos = {q_pos.x + b_si.x / 2, q_pos.y + b_si.y / 2};
    sfVector2f rt_pos = {r_pos.x + b_si.x / 2, r_pos.y + b_si.y / 2};

    elems->respawn_btn = create_rect(b_si, r_pos, FILL_COLOR, OUTLINE_COLOR);
    elems->quit_btn = create_rect(b_si, q_pos, FILL_COLOR, OUTLINE_COLOR);
    elems->quit_txt = set_text(game, "QUIT", 30, qt_pos);
    elems->respawn_txt = set_text(game, "RESPAWN", 30, rt_pos);
    sfText_setOrigin(elems->quit_txt, (sfVector2f)
        {sfText_getLocalBounds(elems->quit_txt).width / 2,
            sfText_getLocalBounds(elems->quit_txt).height / 2 + 5});
    sfText_setOrigin(elems->respawn_txt, (sfVector2f)
        {sfText_getLocalBounds(elems->respawn_txt).width / 2,
            sfText_getLocalBounds(elems->respawn_txt).height / 2 + 5});
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
        sfRectangleShape_getGlobalBounds(elems->quit_btn);
    sfFloatRect respawn_bounds =
        sfRectangleShape_getGlobalBounds(elems->respawn_btn);
    bool hover_quit = sfFloatRect_contains(&quit_bounds, mapped_pos.x,
        mapped_pos.y);
    bool hover_respawn = sfFloatRect_contains(&respawn_bounds, mapped_pos.x,
        mapped_pos.y);

    set_btn_hover(elems->quit_btn, hover_quit);
    set_btn_hover(elems->respawn_btn, hover_respawn);
}

static void handle_clicks(game_data_t *game, game_over_elems_t *elems)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f mapped_pos = sfRenderWindow_mapPixelToCoords(game->window,
        mouse_pos, sfRenderWindow_getView(game->window));
    sfFloatRect quit_bounds =
        sfRectangleShape_getGlobalBounds(elems->quit_btn);
    sfFloatRect respawn_bounds =
        sfRectangleShape_getGlobalBounds(elems->respawn_btn);

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
    sfRenderWindow_drawRectangleShape(game->window, elems.quit_btn, NULL);
    sfRenderWindow_drawRectangleShape(game->window, elems.respawn_btn, NULL);
    sfRenderWindow_drawText(game->window, elems.quit_txt, NULL);
    sfRenderWindow_drawText(game->window, elems.respawn_txt, NULL);
    handle_clicks(game, &elems);
    sfRectangleShape_destroy(elems.quit_btn);
    sfRectangleShape_destroy(elems.respawn_btn);
    sfText_destroy(elems.quit_txt);
    sfText_destroy(elems.respawn_txt);
}
