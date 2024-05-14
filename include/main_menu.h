/*
** EPITECH PROJECT, 2024
** Vendetta / Header
** File description:
** Main Menu
*/

#ifndef MAIN_MENU_H_
    #define MAIN_MENU_H_

    #include "my_game.h"

void basic_help(game_data_t *game);
void draw_help_texts(game_data_t *game);

void basic_menu(game_data_t *game);
void draw_active_navbar_line(game_data_t *game,
    float pos_x, float size_x);
void setup_game_slots(game_data_t *game);
void basic_play(game_data_t *game);
void set_hover_save_button(game_data_t *game);
void set_hover_game_slots(game_data_t *game);

#endif /* !MAIN_MENU_H_ */
