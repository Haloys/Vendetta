/*
** EPITECH PROJECT, 2024
** Vendetta / Header
** File description:
** Game Utils
*/

#ifndef INIT_GAME_H
    #define INIT_GAME_H

    #include "my_game.h"
    #include "map.h"

int init_player(game_data_t *game);

void icon_loader(game_data_t *game);

int init_game_view(game_data_t *game);
int init_menu_view(game_data_t *game);

// ENEMIES
int init_enemies(game_data_t *game);

// KEYS
int init_keybinds(game_data_t *game);

#endif /* INIT_GAME_H */
