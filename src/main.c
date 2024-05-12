/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** my_radar project
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "my_game.h"
#include "my.h"

static int invalid_args(void)
{
    my_putstr("./my_rpg\n");
    my_putstr("retry with -h\n");
    return RET_FAIL;
}

static int start_game()
{
    game_data_t game = {
        .name = "Vendetta",
        .video_mode = { WINDOW_WIDTH, WINDOW_HEIGHT, 32 },
        .state = INVENTORY,
        .clock = sfClock_create(),
        .fps_clock = sfClock_create(),
        .help_text = sfText_create(),
        .speed = 1.0f,
    };

    srand(time(NULL));
    return init_game(&game);
}

int main(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "-h") == 0)
        return print_game_help();
    else if (ac != 1)
        return invalid_args();
    return start_game();
}
