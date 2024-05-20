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
    keybinds[0] = (sf_to_keybind_t){sfKeyUp, MoveUp};
    keybinds[1] = (sf_to_keybind_t){sfKeyRight, MoveRight};
    keybinds[2] = (sf_to_keybind_t){sfKeyDown, MoveDown};
    keybinds[3] = (sf_to_keybind_t){sfKeyLeft, MoveLeft};
    keybinds[4] = (sf_to_keybind_t){sfKeyZ, MoveUp};
    keybinds[5] = (sf_to_keybind_t){sfKeyD, MoveRight};
    keybinds[6] = (sf_to_keybind_t){sfKeyS, MoveDown};
    keybinds[7] = (sf_to_keybind_t){sfKeyQ, MoveLeft};
    keybinds[8] = (sf_to_keybind_t){sfKeyLShift, Sprint};
    keybinds[9] = (sf_to_keybind_t){sfKeyR, Reset};
    keybinds[10] = (sf_to_keybind_t){sfKeyEscape, Echap};
    keybinds[11] = (sf_to_keybind_t){sfKeyAdd, KeyPlus};
    keybinds[12] = (sf_to_keybind_t){sfKeySubtract, KeyMinus};
    keybinds[13] = (sf_to_keybind_t){sfKeyE, Interact};
    keybinds[14] = (sf_to_keybind_t){sfKeyI, Inventory};
    keybinds[15] = (sf_to_keybind_t){sfKeySpace, Space};
}

int init_keybinds(game_data_t *game)
{
    set_default_keys(game->keybinds);
    printf("Keybinds initialized\n");
    return 0;
}
