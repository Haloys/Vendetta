/*
** EPITECH PROJECT, 2024
** Vendetta
** File description:
** Main
*/

#include <stdio.h>

#include "my_game.h"

static void set_default_keys(sf_to_keybind_t *keybinds)
{
    keybinds[0] = (sf_to_keybind_t){sfKeyUp, ArrowUp};
    keybinds[1] = (sf_to_keybind_t){sfKeyRight, ArrowRight};
    keybinds[2] = (sf_to_keybind_t){sfKeyDown, ArrowDown};
    keybinds[3] = (sf_to_keybind_t){sfKeyLeft, ArrowLeft};
    keybinds[4] = (sf_to_keybind_t){sfKeyEscape, Echap};
    keybinds[5] = (sf_to_keybind_t){sfKeySpace, Space};
    keybinds[6] = (sf_to_keybind_t){sfKeyP, TestF13};
    keybinds[7] = (sf_to_keybind_t){sfKeyZ, MoveUp};
    keybinds[8] = (sf_to_keybind_t){sfKeyS, MoveDown};
    keybinds[9] = (sf_to_keybind_t){sfKeyQ, MoveLeft};
    keybinds[10] = (sf_to_keybind_t){sfKeyD, MoveRight};
    keybinds[11] = (sf_to_keybind_t){sfKeyI, Inventory};
    keybinds[12] = (sf_to_keybind_t){sfKeySubtract, KeyMinus};
    keybinds[13] = (sf_to_keybind_t){sfKeyAdd, KeyPlus};
    keybinds[14] = (sf_to_keybind_t){sfKeyE, Interact};
    keybinds[15] = (sf_to_keybind_t){sfKeyLShift, Sprint};
    keybinds[16] = (sf_to_keybind_t){sfKeyR, Reset};
    keybinds[17] = (sf_to_keybind_t){sfKeyW, Hostile};
}

int init_keybinds(game_data_t *game)
{
    set_default_keys(game->keybinds);
    printf("Keybinds initialized\n");
    return 0;
}
