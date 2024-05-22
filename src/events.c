/*
** EPITECH PROJECT, 2024
** Vendetta / Events
** File description:
** Event Handling
*/

#include <stdio.h>

#include "my_game.h"
#include "gameplay.h"
#include "utils.h"

static void process_mouse_click_play(game_data_t *game)
{
    for (int i = 0; i < 3; i++) {
        if (game->state == MAIN_MENU && game->hover_slot_array[i]) {
            change_game_mode(game, PLAYING);
            game->player->is_playing = true;
            game->is_navbar_visible = false;
            break;
        }
    }
}

static void process_mouse_click_save(game_data_t *game)
{
    if (game->hover_save_button) {
        change_game_mode(game, SAVE);
    }
}

static void remap_event_coords(sfRenderWindow *window, int *x, int *y)
{
    sfVector2f coords = sfRenderWindow_mapPixelToCoords(window,
        (sfVector2i){*x, *y}, sfRenderWindow_getView(window));

    *x = coords.x;
    *y = coords.y;
}

static void window_resize_handler(game_data_t *game, sfSizeEvent *evt)
{
    sfView *view = game->state == PLAYING ? game->game_view :
        (sfView *)sfRenderWindow_getView(game->window);
    sfVector2f view_size = sfView_getSize(view);
    float window_ratio = evt->width / (float) evt->height;
    float view_ratio = view_size.x / view_size.y;
    float size_x = 1;
    float size_y = 1;
    float pos_x = 0;
    float pos_y = 0;

    if (!(window_ratio < view_ratio)) {
        size_x = view_ratio / window_ratio;
        pos_x = (1 - size_x) / 2.f;
    } else {
        size_y = window_ratio / view_ratio;
        pos_y = (1 - size_y) / 2.f;
    }
    sfView_setViewport(view, (sfFloatRect){pos_x, pos_y, size_x, size_y});
    sfRenderWindow_setView(game->window, view);
}

static void process_key_event(game_data_t *game, sfEvent *evt, bool pressed)
{
    update_key(game, evt->key.code, pressed);
    modify_screen(game);
}

static void process_mouse_move_event(game_data_t *game)
{
    set_hover_save_button(game);
    set_hover_game_slots(game);
}

static void process_mouse_button_pressed(game_data_t *game,
    sfMouseButtonEvent *evt)
{
    game->clicked = true;
    remap_event_coords(game->window, &evt->x, &evt->y);
    process_mouse_click_play(game);
    handle_navbar_click(game, *evt);
    handle_settings_click(game);
    process_mouse_click_save(game);
    printf("click x: %d, y: %d\n", evt->x, evt->y);
}

static void process_global_events(game_data_t *game, sfEvent *evt)
{
    switch (evt->type) {
    case sfEvtResized:
        window_resize_handler(game, &evt->size);
        break;
    case sfEvtClosed:
        sfRenderWindow_close(game->window);
        break;
    case sfEvtMouseButtonPressed:
        process_mouse_button_pressed(game, &evt->mouseButton);
        break;
    case sfEvtMouseMoved:
        process_mouse_move_event(game);
        break;
    case sfEvtKeyPressed:
    case sfEvtKeyReleased:
        process_key_event(game, evt, evt->type == sfEvtKeyPressed);
        break;
    default:
        break;
    }
}

void process_events(game_data_t *game)
{
    sfEvent evt = {0};

    game->clicked = false;
    reset_key_update(game);
    while (sfRenderWindow_pollEvent(game->window, &evt)) {
        process_global_events(game, &evt);
    }
    after_key_update(game);
}
