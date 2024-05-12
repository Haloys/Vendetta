/*
** EPITECH PROJECT, 2024
** B-MUL-200-PAR-2-1-myrpg-maxence.bunel [WSL: Ubuntu]
** File description:
** navbar
*/

#ifndef NAVBAR_H_
    #define NAVBAR_H_

#include "my_game.h"

static const navbar_element_t elements[] = {
    {"PLAY", SP_ICON_PLAY, {159, 42}, {80, 30}, MAIN_MENU},
    {"SETTINGS", SP_ICON_SETTINGS, {367, 42}, {155, 30}, SETTINGS_VIDEO},
    {"HELP", SP_ICON_HELP, {633, 42}, {80, 30}, HELP},
    {"QUIT", SP_ICON_QUIT, {827, 42}, {80, 30}, MAIN_MENU}
};

#endif /* !NAVBAR_H_ */
