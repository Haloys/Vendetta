/*
** EPITECH PROJECT, 2024
** Vendetta / Header
** File description:
** State
*/

#ifndef STATE_H
    #define STATE_H

    #include "my_game.h"
    #include "main_menu.h"

    #define STATE_COUNT sizeof(process_state) / sizeof(process_state[0])

typedef enum state_e {
    LOADING_SCREEN,
    MAIN_MENU,
    SETTINGS_VIDEO,
    SETTINGS_CONTROLS,
    SETTINGS_AUDIO,
    HELP,
    PLAYING,
    INVENTORY,
    SAVE,
    NPC_DIALOGUE,
    SKILL_TREE,
    SEQUENCE_CLICK,
    BARHIT,
    BOOK_1,
    BOOK_2,
    BOOK_3,
    ENDING_SCREEN,
    GAME_OVER,
    PAUSE,
} state_t;

typedef void (*process_state_t)(game_data_t *game);

extern const process_state_t process_state[];

#endif /* STATE_H */
