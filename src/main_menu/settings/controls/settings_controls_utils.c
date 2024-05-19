/*
** EPITECH PROJECT, 2024
** B-MUL-200-PAR-2-1-myrpg-maxence.bunel
** File description:
** settings_controls_utils
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "my_game.h"
#include "my.h"

sfKeyCode get_pressed_key(int key)
{
    for (key = sfKeyA; key <= sfKeyZ; key++) {
        if (sfKeyboard_isKeyPressed(key)) {
            return (sfKeyCode)key;
        }
    }
    return sfKeyUnknown;
}
