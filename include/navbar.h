/*
** EPITECH PROJECT, 2024
** Vendetta / Header
** File description:
** Navbar
*/

#ifndef NAVBAR_H_
    #define NAVBAR_H_

#include "my_game.h"
#include "state.h"

#define NAVBAR_TEXT_COLOR sfColor_fromRGB(197, 197, 197)
#define NAVBAR_LINE_COLOR sfColor_fromRGBA(255, 255, 255, 76)
#define ACTIVE_NAVBAR_TEXT_COLOR sfColor_fromRGB(51, 217, 122)

typedef struct navbar_element_s {
    const char *label;
    sprite_id_t icon;
    sfVector2f position;
    sfVector2f size;
    state_t target_state;
} navbar_element_t;

typedef struct settings_navbar_element_s {
    const char *label;
    sfVector2f position;
    sfVector2f size;
} settings_navbar_element_t;

typedef struct text_draw_info_settings_s {
    sfVector2f text_position;
    sfColor hover_color;
} text_draw_info_settings_t;

static const navbar_element_t elements[] = {
    {"PLAY", SP_ICON_PLAY, {159, 42}, {80, 30}, MAIN_MENU},
    {"SETTINGS", SP_ICON_SETTINGS, {367, 42}, {155, 30}, SETTINGS_VIDEO},
    {"HELP", SP_ICON_HELP, {633, 42}, {80, 30}, HELP},
    {"QUIT", SP_ICON_QUIT, {827, 42}, {80, 30}, MAIN_MENU}
};

void handle_settings_click(game_data_t *game);
void draw_settings_navbar(game_data_t *game);
void basic_settings(game_data_t *game);

void handle_navbar_click(game_data_t *game, sfMouseButtonEvent mouse_event);
void draw_navbar(game_data_t *game);

#endif /* !NAVBAR_H_ */
