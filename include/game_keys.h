/*
** EPITECH PROJECT, 2024
** Vendetta / Header
** File description:
** Clock
*/

#ifndef GAME_KEYS_H
    #define GAME_KEYS_H

    #include <SFML/Graphics.h>

    #define KEYBINDS_COUNT 15

typedef enum keybinds_e {
    MoveUp,
    MoveRight,
    MoveDown,
    MoveLeft,
    Reset,
    Sprint,
    Echap,
    KeyPlus,
    KeyMinus,
    Interact,
    Inventory
} keybinds_t;

typedef struct sf_to_keybind_s {
    sfKeyCode code;
    keybinds_t key;
} sf_to_keybind_t;

// IS_KEY
bool is_key_down(game_data_t *game, keybinds_t key);
bool is_key_pressed(game_data_t *game, keybinds_t key);
void reset_key_update(game_data_t *game);
void after_key_update(game_data_t *game);

void update_key(game_data_t *game, sfKeyCode code, int state);


#endif /* GAME_KEYS_H */
