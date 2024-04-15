/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** my_radar project
*/

#include "my_game.h"
#include "my.h"
#include <stdio.h>

void m_mouse_button_pressed(game_data_t *game, sfMouseButtonEvent evt)
{
    my_printf("Mouse click menu => x: %d y: %d\n", evt.x, evt.y);
    // if (evt.x >= 735 && evt.x <= 1185 && evt.y >= 465 && evt.y <= 615) {
    //     my_printf("State -> PLAYING\n");
    //     game->state = PLAYING;
    //     game->time = sfClock_create();
    //     clock_init(&game->delay_clock);
    // }
    // if (evt.x >= 735 && evt.x <= 1185 && evt.y >= 687 && evt.y <= 837) {
    //     sfRenderWindow_close(game->window);
    // }
}
