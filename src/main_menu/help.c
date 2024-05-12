/*
** EPITECH PROJECT, 2024
** B-MUL-200-PAR-2-1-myrpg-maxence.bunel
** File description:
** main_menu
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "my_game.h"
#include "my.h"


void basic_help(game_data_t *game)
{
    basic_menu(game);
    draw_active_navbar_line(game, 560.0f, 200.0f);
}
