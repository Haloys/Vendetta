/*
** EPITECH PROJECT, 2024
** Vendetta / Header
** File description:
** Clock
*/

#ifndef GAME_KEYS_H
    #define GAME_KEYS_H

    #include <SFML/Graphics.h>

    #define KEYBINDS_COUNT 18

typedef enum keybinds_e {
    ArrowUp,
    ArrowRight,
    ArrowDown,
    ArrowLeft,
    Echap,
    Space,
    TestF13,
    // Below you'll find only editable keybinds
    MoveUp,
    MoveDown,
    MoveLeft,
    MoveRight,
    Inventory,
    KeyMinus,
    KeyPlus,
    Interact,
    Sprint,
    Reset,
    Hostile
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

void update_key(game_data_t *game, sfKeyCode code, bool state);


#endif /* GAME_KEYS_H */
