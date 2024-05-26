/*
** EPITECH PROJECT, 2024
** Vendetta / Main Menu / Save
** File description:
** Valid Save
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "my_game.h"
#include "save.h"
#include "saves.h"
#include "utils.h"

int is_file_valid(game_ui_t *game_ui)
{
    if (strstr(game_ui->input, ".ven") != NULL) {
        if (access(game_ui->input, F_OK) != -1) {
            return 1;
        }
    }
    return 0;
}

void update_valid_button_color(game_data_t *game, game_ui_t *game_ui)
{
    (void)game;
    if (is_file_valid(game_ui)) {
        sfRectangleShape_setFillColor(game_ui->valid_b,
            sfColor_fromRGBA(0, 255, 0, 51));
    } else {
        sfRectangleShape_setFillColor(game_ui->valid_b,
            sfColor_fromRGBA(255, 0, 0, 51));
    }
}

int save_file(game_data_t *game, char *file_name)
{
    for (int i = 0; i < 3; i++) {
        if (access(SAVES_NAMES[i], F_OK) == -1) {
            rename(file_name, SAVES_NAMES[i]);
            game->validation_count++;
            game->is_sprite_displayed = true;
        }
    }
    return 0;
}

void handle_valid_button_click(game_data_t *game, game_ui_t *game_ui)
{
    sfFloatRect valid_bounds =
        sfRectangleShape_getGlobalBounds(game_ui->valid_b);

    if (sfFloatRect_contains(&valid_bounds, game->mouse_pos.x,
        game->mouse_pos.y)) {
        printf("Text entered: %s\n", game_ui->input);
        if (is_file_valid(game_ui)) {
            change_game_mode(game, MAIN_MENU);
            save_file(game, game_ui->input);
        }
    }
}

void handle_cancel_button_click(game_data_t *game, game_ui_t *game_ui)
{
    sfFloatRect cancel_bounds =
        sfRectangleShape_getGlobalBounds(game_ui->cancel_b);

    if (sfFloatRect_contains(&cancel_bounds,
        game->mouse_pos.x, game->mouse_pos.y)) {
        play_sound(game, S_CLICK_SOUND);
        change_game_mode(game, MAIN_MENU);
    }
}
