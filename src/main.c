/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** my_radar project
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "my_game.h"
#include "my.h"
#include "score.h"

static int invalid_args(void)
{
    my_putstr("./my_rpg\n");
    my_putstr("retry with -h\n");
    return RET_FAIL;
}

static int start_game(char **av)
{
    game_data_t game = {
        .name = "Vendetta",
        .video_mode = { WINDOW_WIDTH, WINDOW_HEIGHT, 32 },
        .state = MAIN_MENU,
        .clock = sfClock_create(),
        .score = 0,
        .target_miss = 0,
        .is_fullscreen = false,
        .highest_score = get_highest_score(),
        .crash = 0,
        .success = 0,
        .fps = 60,
        .opts = { 0, 1, 1, 0 },
        .fps_clock = sfClock_create(),
        .help_text = sfText_create(),
        .speed = 1.0f,
    };

    srand(time(NULL));
    return init_game(&game, av);
}

int handle_env(char **env)
{
    if (env == NULL || env[0] == NULL) {
        dprintf(2, "Environment is empty, please restart your computer.\n");
        return RET_FAIL;
    }
    for (int i = 0; env[i] != NULL; i++) {
        if (strncmp(env[i], "DISPLAY", 7) == 0) {
            return RET_NONE;
        }
    }
    dprintf(2, "Missing DISPLAY variable, please restart your computer.\n");
    return RET_FAIL;
}

int main(int ac, char **av, char **env)
{
    if (handle_env(env) == RET_FAIL)
        return RET_FAIL;
    if (ac == 2 && my_strcmp(av[1], "-h") == 0)
        return print_game_help();
    else if (ac != 1)
        return invalid_args();
    return start_game(av);
}
