/*
** EPITECH PROJECT, 2024
** Vendetta
** File description:
** Music
*/

#include "my_game.h"
#include "resources.h"

const char *SHADER_PATHS[] = {
    "shaders/darkness.frag",
};

const int SHADER_PATHS_COUNT = sizeof(SHADER_PATHS) / sizeof(char *);

const shader_t SHADERS[] = {
    {
        .id = SH_MAIN_DARKNESS
    },
};

const int SHADER_COUNT = sizeof(SHADERS) / sizeof(shader_t);
