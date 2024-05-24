/*
** EPITECH PROJECT, 2024
** Vendetta
** File description:
** Main
*/

#include <stdio.h>
#include <string.h>
#include <time.h>

#include "my_game.h"
#include "utils.h"

static int invalid_args(void)
{
    dprintf(1, "./my_rpg\n");
    dprintf(1, "retry with -h\n");
    return RET_FAIL;
}

static int start_game(void)
{
    game_data_t game = {
        .name = "Vendetta",
        .video_mode = { WINDOW_WIDTH, WINDOW_HEIGHT, 32 },
        .clock = sfClock_create(),
        .fps_clock = sfClock_create(),
        .state = LOADING_SCREEN,
        .last_state = LOADING_SCREEN,
        .speed = 1.0f,
        .settings.sg_x = 243,
        .settings.sm_x = 243,
        .settings.sa_x = 243,
        .fps = 60,
        .is_passive = true,
        .is_first = true,
        .clicked = false,
        .main_quest_stage = 1,
    };

    srand(time(NULL));
    return init_game(&game);
}

static int handle_env(char **env)
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
    if (ac == 2 && strcmp(av[1], "-h") == 0)
        return print_game_help();
    else if (ac != 1)
        return invalid_args();
    return start_game();
}
