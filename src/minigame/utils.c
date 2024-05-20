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

void setup_progress_shapes(game_data_t *game, sfTime elapsed,
    sfRectangleShape **progress_bar, sfRectangleShape **progress_fill)
{
    float progress = elapsed.microseconds / 1000000.0 / 13.0;
    sfVector2f progress_size = {PROGRESS_WIDTH * progress, PROGRESS_HEIGHT};
    sfVector2f progress_bar_pos = {(WINDOW_WIDTH - PROGRESS_WIDTH) / 2,
        (WINDOW_HEIGHT - RECT_HEIGHT) / 2 + RECT_HEIGHT + 20};

    if (game->minigame.game_won)
        progress = 1.0;
    *progress_bar = sfRectangleShape_create();
    *progress_fill = sfRectangleShape_create();
    sfRectangleShape_setSize(*progress_bar, (sfVector2f){PROGRESS_WIDTH,
        PROGRESS_HEIGHT});
    sfRectangleShape_setFillColor(*progress_bar, sfColor_fromRGBA(0, 0, 0, 0));
    sfRectangleShape_setOutlineColor(*progress_bar, PROGRESS_OUTLINE_COLOR);
    sfRectangleShape_setOutlineThickness(*progress_bar, 2);
    sfRectangleShape_setPosition(*progress_bar, progress_bar_pos);
    sfRectangleShape_setSize(*progress_fill, progress_size);
    sfRectangleShape_setFillColor(*progress_fill, PROGRESS_FILL_COLOR);
    sfRectangleShape_setPosition(*progress_fill, progress_bar_pos);
}

void draw_sequence_progress_bar(game_data_t *game, sfTime elapsed)
{
    sfRectangleShape *progress_bar;
    sfRectangleShape *progress_fill;

    setup_progress_shapes(game, elapsed, &progress_bar, &progress_fill);
    sfRenderWindow_drawRectangleShape(game->window, progress_bar, NULL);
    sfRenderWindow_drawRectangleShape(game->window, progress_fill, NULL);
    sfRectangleShape_destroy(progress_bar);
    sfRectangleShape_destroy(progress_fill);
}
