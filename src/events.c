/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** my_radar project
*/

#include "my_game.h"

static void process_menu_events(game_data_t *game, sfEvent *event)
{
    if (event->type == sfEvtMouseButtonPressed) {
        m_mouse_button_pressed(game, event->mouseButton);
    }
}

static void process_in_game_events(game_data_t *game, sfEvent *event)
{
    if (event->type == sfEvtMouseButtonPressed)
        p_mouse_button_pressed(game, event->mouseButton);
}

static void remap_event_coords(sfRenderWindow *window, int *x, int *y)
{
    sfVector2f coords = sfRenderWindow_mapPixelToCoords(window,
        (sfVector2i){*x, *y}, sfRenderWindow_getView(window));

    *x = coords.x;
    *y = coords.y;
}

/* Source:
* https://github.com/SFML/SFML/wiki/Source%3A-Letterbox-effect-using-a-view
*/
static void window_resize_handler(sfRenderWindow *window, sfSizeEvent *evt)
{
    sfView *view = sfRenderWindow_getView(window);
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
    sfRenderWindow_setView(window, view);
}

static void process_key_event(game_data_t *game, sfEvent *evt)
{
    if (evt->key.code == sfKeyS) {
        set_screen_size(game);
        sfRenderWindow_setSize(game->window, (sfVector2u) {
            game->video_mode.width, game->video_mode.height
        });
    }
    if (evt->key.code == sfKeyQ)
        arrow_l_fps(game);
    if (evt->key.code == sfKeyP) {
        set_reso(game);
    }
    if (evt->key.code == sfKeyLeft) {
        if (game->speed > 0.1f)
            game->speed -= 0.1f;
    }
    if (evt->key.code == sfKeyRight) {
        if (game->speed < 2.0f)
            game->speed += 0.1f;
    }
}

static void process_mouse_move_event(game_data_t *game, sfMouseMoveEvent mouseEvent)
{
    set_mouse_pos(game);
    game->hover_save_button = (game->mouse_pos.x >= 147 && game->mouse_pos.x <= 382 &&
    game->mouse_pos.y >= 148 && game->mouse_pos.y <= 198);
    game->hover_slot_array[0] = (game->mouse_pos.x >= 147 && game->mouse_pos.x <= 599 &&
    game->mouse_pos.y >= 241 && game->mouse_pos.y <= 870);
    game->hover_slot_array[1] = (game->mouse_pos.x >= 734 && game->mouse_pos.x <= 1186 &&
    game->mouse_pos.y >= 241 && game->mouse_pos.y <= 870);
    game->hover_slot_array[2] = (game->mouse_pos.x >= 1321 && game->mouse_pos.x <= 1773 &&
    game->mouse_pos.y >= 241 && game->mouse_pos.y <= 870);
}

static void process_global_events(game_data_t *game, sfEvent *evt)
{
    if (evt->type == sfEvtResized) {
        window_resize_handler(game->window, &evt->size);
        return;
    }
    if (evt->type == sfEvtClosed) {
        sfRenderWindow_close(game->window);
        return;
    }
    if (evt->type == sfEvtMouseButtonPressed) {
        remap_event_coords(game->window, &evt->mouseButton.x,
            &evt->mouseButton.y);
        handle_navbar_click(game, evt->mouseButton);
        handle_settings_click(game);
        return;
    }
    if (evt->type == sfEvtMouseMoved) {
        process_mouse_move_event(game, evt->mouseMove);
        return;
    }
    if (evt->type == sfEvtKeyPressed)
        process_key_event(game, evt);
}

static void annalyse_event(game_data_t *game, sfEvent *evt)
{
    process_global_events(game, evt);
    if (game->state == MAIN_MENU)
        process_menu_events(game, evt);
    else if (game->state == PLAYING)
        process_in_game_events(game, evt);
}

void process_events(game_data_t *game)
{
    sfEvent evt;

    while (sfRenderWindow_pollEvent(game->window, &evt)) {
        annalyse_event(game, &evt);
    }
}
