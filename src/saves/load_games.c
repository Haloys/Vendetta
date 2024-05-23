/*
** EPITECH PROJECT, 2024
** B-MUL-200-PAR-2-1-myrpg-maxence.bunel [WSL: Ubuntu]
** File description:
** load_games
*/

#include "my_game.h"
#include "utils.h"
#include "gameplay.h"

void set_shapes_params(sfRectangleShape *first_button,
    sfRectangleShape *second_button, sfRectangleShape *third_button)
{
    sfRectangleShape_setSize(first_button, (sfVector2f){452, 516});
    sfRectangleShape_setSize(second_button, (sfVector2f){452, 516});
    sfRectangleShape_setSize(third_button, (sfVector2f){452, 516});
    sfRectangleShape_setPosition(first_button, (sfVector2f){149, 241});
    sfRectangleShape_setPosition(second_button, (sfVector2f){727, 241});
    sfRectangleShape_setPosition(third_button, (sfVector2f){1321, 241});
}

int handle_click_first_button(game_data_t *game,
    sfRectangleShape *first_button)
{
    sfFloatRect first_button_bounds =
        sfRectangleShape_getGlobalBounds(first_button);

    if (sfFloatRect_contains(&first_button_bounds, game->mouse_pos.x,
        game->mouse_pos.y)) {
        game->player->save_number = 1;
        change_game_mode(game, PLAYING);
        game->player->is_playing = true;
        game->is_navbar_visible = false;
        load_game(game);
        return 1;
    }
    return 0;
}

int handle_click_second_button(game_data_t *game,
    sfRectangleShape *second_button)
{
    sfFloatRect second_button_bounds =
        sfRectangleShape_getGlobalBounds(second_button);

    if (sfFloatRect_contains(&second_button_bounds, game->mouse_pos.x,
        game->mouse_pos.y)) {
        game->player->save_number = 2;
        change_game_mode(game, PLAYING);
        game->player->is_playing = true;
        game->is_navbar_visible = false;
        load_game(game);
        return 1;
    }
    return 0;
}

int handle_click_third_button(game_data_t *game,
    sfRectangleShape *third_button)
{
    sfFloatRect third_button_bounds =
        sfRectangleShape_getGlobalBounds(third_button);

    if (sfFloatRect_contains(&third_button_bounds, game->mouse_pos.x,
        game->mouse_pos.y)) {
        game->player->save_number = 3;
        change_game_mode(game, PLAYING);
        game->player->is_playing = true;
        game->is_navbar_visible = false;
        load_game(game);
        return 1;
    }
    return 0;
}
