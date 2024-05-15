/*
** EPITECH PROJECT, 2024
** Vendetta / Header
** File description:
** Save
*/

#ifndef SAVE_H
    #define SAVE_H

    #include "my_game.h"

typedef struct game_ui_s {
    sfText* text;
    sfText* validate_text;
    sfText* cancel_text;
    sfRectangleShape* rect;
    sfRectangleShape* valid_b;
    sfRectangleShape* cancel_b;
    char input[200];
    size_t input_size;
} game_ui_t;

void basic_save(game_data_t *game);
void draw_load_save_texts(game_data_t *game);
void create_cancel_text(game_data_t *game, sfText **text);
void create_validate_text(game_data_t *game, sfText **text);
void create_validate_button(game_ui_t *game_ui);
void create_cancel_button(game_ui_t *game_ui);
void update_valid_button_color(game_data_t *game, game_ui_t *game_ui);
int is_file_valid(game_ui_t *game_ui);
void handle_valid_button_click(game_data_t *game, game_ui_t *game_ui);
void handle_cancel_button_click(game_data_t *game, game_ui_t *game_ui);

#endif /* SAVE_H */
