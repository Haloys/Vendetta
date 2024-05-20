/*
** EPITECH PROJECT, 2024
** Vendetta / Minigame
** File description:
** Sequence Click
*/

#include "my_game.h"

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

static void shuffle_numbers(int *numbers, int size)
{
    int j = 0;
    int temp = 0;

    for (int i = size - 1; i > 0; --i) {
        j = rand() % (i + 1);
        temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }
}

static void draw_rectangle(game_data_t *game, sfRectangleShape *rect)
{
    sfRectangleShape_setSize(rect, (sfVector2f){RECT_WIDTH, RECT_HEIGHT});
    sfRectangleShape_setFillColor(rect, FILL_COLOR);
    sfRectangleShape_setOutlineColor(rect, OUTLINE_COLOR);
    sfRectangleShape_setPosition(rect, (sfVector2f)
        {(WINDOW_WIDTH - RECT_WIDTH) / 2, (WINDOW_HEIGHT - RECT_HEIGHT) / 2});
    sfRenderWindow_drawRectangleShape(game->window, rect, NULL);
}

static void draw_square(game_data_t *game, sfRectangleShape *square, int i)
{
    sfVector2f position;

    sfRectangleShape_setSize(square, (sfVector2f){SQUARE_SIZE, SQUARE_SIZE});
    sfRectangleShape_setFillColor(square, game->minigame.squares_clicked[i] ?
        HOVER_FILL_COLOR : FILL_COLOR);
    sfRectangleShape_setOutlineColor(square, game->minigame.squares_clicked[i]
        ? HOVER_OUTLINE_COLOR : OUTLINE_COLOR);
    sfRectangleShape_setOutlineThickness(square, 2);
    position.x = (WINDOW_WIDTH - RECT_WIDTH) / 2 + (i % 7) *
        (SQUARE_SIZE + 10) + 25;
    position.y = (WINDOW_HEIGHT - RECT_HEIGHT) / 2 + (i / 7) *
        (SQUARE_SIZE + 10) + 25;
    sfRectangleShape_setPosition(square, position);
    sfRenderWindow_drawRectangleShape(game->window, square, NULL);
}

static void draw_number(game_data_t *game, sfVector2f position, int number)
{
    char number_str[3];
    sfText *number_text = sfText_create();
    sfVector2f text_pos = {position.x + 15, position.y + 10};

    snprintf(number_str, sizeof(number_str), "%d", number);
    sfText_setString(number_text, number_str);
    sfText_setFont(number_text, game->font);
    sfText_setCharacterSize(number_text, 20);
    sfText_setFillColor(number_text, sfColor_fromRGB(0, 0, 0));
    sfText_setPosition(number_text, text_pos);
    sfRenderWindow_drawText(game->window, number_text, NULL);
    sfText_destroy(number_text);
}

static void draw_rect_with_squares(game_data_t *game)
{
    sfRectangleShape *rect;
    sfRectangleShape *square;
    sfVector2f position;

    rect = sfRectangleShape_create();
    draw_rectangle(game, rect);
    for (int i = 0; i < NUM_SQUARES; ++i) {
        square = sfRectangleShape_create();
        draw_square(game, square, i);
        position.x = (WINDOW_WIDTH - RECT_WIDTH) / 2 + (i % 7) *
            (SQUARE_SIZE + 10) + 25;
        position.y = (WINDOW_HEIGHT - RECT_HEIGHT) / 2 + (i / 7) *
            (SQUARE_SIZE + 10) + 25;
        draw_number(game, position, game->minigame.numbers[i]);
        sfRectangleShape_destroy(square);
    }
    sfRectangleShape_destroy(rect);
}

static void handle_square_click(game_data_t *game, sfVector2f pos)
{
    sfVector2f square_pos;
    sfFloatRect square_bounds;
    bool is_within_bounds;
    bool valid_nbr;

    for (int i = 0; i < NUM_SQUARES; ++i) {
        square_pos.x = (WINDOW_WIDTH - RECT_WIDTH) / 2 + (i % 7) *
            (SQUARE_SIZE + 10) + 25;
        square_pos.y = (WINDOW_HEIGHT - RECT_HEIGHT) / 2 + (i / 7) *
            (SQUARE_SIZE + 10) + 25;
        square_bounds = (sfFloatRect){square_pos.x,
            square_pos.y, SQUARE_SIZE, SQUARE_SIZE};
        is_within_bounds = sfFloatRect_contains(&square_bounds, pos.x, pos.y);
        valid_nbr = game->minigame.numbers[i] == game->minigame.current_number;
        if (is_within_bounds && valid_nbr) {
            game->minigame.current_number++;
            game->minigame.squares_clicked[i] = true;
            break;
        }
    }
}

static void handle_click(game_data_t *game)
{
    sfVector2i pixel_pos;
    sfVector2f pos;

    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        pixel_pos = sfMouse_getPositionRenderWindow(game->window);
        pos = sfRenderWindow_mapPixelToCoords(game->window, pixel_pos, NULL);
        handle_square_click(game, pos);
    }
}

static void reset_minigame(game_data_t *game)
{
    for (int i = 0; i < NUM_SQUARES; ++i) {
        game->minigame.squares_clicked[i] = false;
    }
    game->minigame.current_number = 0;
    game->minigame.game_won = false;
    sfClock_restart(game->minigame.clock);
}

static void initialize_minigame(game_data_t *game)
{
    if (game->minigame.current_number == 0) {
        srand(time(NULL));
        for (int i = 0; i < NUM_SQUARES; ++i) {
            game->minigame.numbers[i] = i + 1;
            game->minigame.squares_clicked[i] = false;
        }
        shuffle_numbers(game->minigame.numbers, NUM_SQUARES);
        game->minigame.current_number = 1;
        game->minigame.clock = sfClock_create();
        game->minigame.game_won = false;
    }
}

bool display_sequence_click(game_data_t *game)
{
    sfTime elapsed;

    basic_design(game);
    initialize_minigame(game);
    elapsed = sfClock_getElapsedTime(game->minigame.clock);
    if (elapsed.microseconds / 1000000.0 > 13.0 && !game->minigame.game_won &&
        game->minigame.current_number != NUM_SQUARES + 1)
            reset_minigame(game);
    draw_rect_with_squares(game);
    draw_sequence_progress_bar(game, elapsed);
    handle_click(game);
    if (game->minigame.current_number == NUM_SQUARES + 1) {
        game->minigame.game_won = true;
        return true;
    }
    return false;
}
