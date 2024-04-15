/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** my_radar project
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_game.h"
#include "my.h"

static void process_loop_main_menu(game_data_t *game)
{

}

static void process_loop_update(game_data_t *game, float elapsed)
{
    switch (game->state) {
    case MAIN_MENU:
        process_loop_main_menu(game);
        break;
    case PLAYING:
        clock_update(&game->delay_clock, elapsed);
        if (game->opts.paused)
            elapsed = 0.f;
        process_loop_in_game(game, elapsed);
        break;
    case PAUSE:
        break;
    }
}


void process_game_loop(game_data_t *game)
{
    float elapsed = sfTime_asSeconds(sfClock_getElapsedTime(game->clock))
        * game->speed;

    sfRenderWindow_clear(game->window, sfBlack);
    process_events(game);
    sfRenderWindow_drawSprite(game->window, get_sprite(game, SP_BACKGROUND_2),
        NULL);
    process_loop_update(game, elapsed - game->last_update);
    game->last_update = elapsed;
    sfRenderWindow_display(game->window);
}
