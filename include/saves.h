/*
** EPITECH PROJECT, 2024
** B-MUL-200-PAR-2-1-myrpg-maxence.bunel [WSL: Ubuntu]
** File description:
** saves
*/

#ifndef SAVES_H_
    #define SAVES_H_
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>

    #include "my_game.h"

typedef struct save_s {
    char name[64];
} save_t;



extern const save_t SAVES[];

    #define GLOBAL_SETTINGS_COUNT sizeof(SAVES) / sizeof(save_t)

#endif /* !SAVES_H_ */
