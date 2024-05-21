/*
** EPITECH PROJECT, 2024
** B-MUL-200-PAR-2-1-myrpg-maxence.bunel
** File description:
** settings_controls
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "gameplay.h"

key_config_t key_config[] = {
    {
        .name = "Forward",
        .key_name = "Z",
        .key = MoveUp
    },
    {
        .name = "Backward",
        .key_name = "S",
        .key = MoveDown
    },
    {
        .name = "Left",
        .key_name = "Q",
        .key = MoveLeft
    },
    {
        .name = "Right",
        .key_name = "D",
        .key = MoveRight
    },
    {
        .name = "Open inventory",
        .key_name = "I",
        .key = Inventory
    },
    {
        .name = "Zoom In",
        .key_name = "Add",
        .key = KeyPlus
    },
    {
        .name = "Zoom Out",
        .key_name = "Substract",
        .key = KeyMinus
    },
    {
        .name = "Interact",
        .key_name = "E",
        .key = Interact
    },
    {
        .name = "Sprint",
        .key_name = "Left Shift",
        .key = Sprint
    },
    {
        .name = "Reset",
        .key_name = "R",
        .key = Reset
    }
};

static const key_mapping_t key_mapping[] = {
    {sfKeyA, "A"}, {sfKeyB, "B"}, {sfKeyC, "C"}, {sfKeyD, "D"}, {sfKeyE, "E"},
    {sfKeyF, "F"}, {sfKeyG, "G"}, {sfKeyH, "H"}, {sfKeyI, "I"}, {sfKeyJ, "J"},
    {sfKeyK, "K"}, {sfKeyL, "L"}, {sfKeyM, "M"}, {sfKeyN, "N"}, {sfKeyO, "O"},
    {sfKeyP, "P"}, {sfKeyQ, "Q"}, {sfKeyR, "R"}, {sfKeyS, "S"}, {sfKeyT, "T"},
    {sfKeyU, "U"}, {sfKeyV, "V"}, {sfKeyW, "W"}, {sfKeyX, "X"}, {sfKeyY, "Y"},
    {sfKeyZ, "Z"}, {sfKeyNum0, "0"}, {sfKeyNum1, "1"}, {sfKeyNum2, "2"},
    {sfKeyNum3, "3"}, {sfKeyNum4, "4"}, {sfKeyNum5, "5"}, {sfKeyNum6, "6"},
    {sfKeyNum7, "7"}, {sfKeyNum8, "8"}, {sfKeyNum9, "9"},
    {sfKeyEscape, "Escape"}, {sfKeyLControl, "Left Control"},
    {sfKeyLShift, "Left Shift"}, {sfKeyLAlt, "Left Alt"},
    {sfKeyLSystem, "Left System"}, {sfKeyRControl, "Right Control"},
    {sfKeyRShift, "Right Shift"}, {sfKeyRAlt, "Right Alt"},
    {sfKeyRSystem, "Right System"}, {sfKeyMenu, "Menu"}, {sfKeyLBracket, "["},
    {sfKeyRBracket, "]"}, {sfKeySemicolon, ";"}, {sfKeyComma, ","},
    {sfKeyPeriod, "."}, {sfKeyQuote, "'"}, {sfKeySlash, "/"},
    {sfKeyBackslash, "\\"}, {sfKeyTilde, "~"}, {sfKeyEqual, "="},
    {sfKeyHyphen, "-"}, {sfKeySpace, "Space"}, {sfKeyEnter, "Enter"},
    {sfKeyBackspace, "Backspace"}, {sfKeyTab, "Tab"}, {sfKeyPageUp, "Page Up"},
    {sfKeyPageDown, "Page Down"}, {sfKeyEnd, "End"}, {sfKeyHome, "Home"},
    {sfKeyInsert, "Insert"}, {sfKeyDelete, "Delete"}, {sfKeyAdd, "Add"},
    {sfKeySubtract, "Subtract"}, {sfKeyMultiply, "Multiply"},
    {sfKeyDivide, "Divide"}, {sfKeyLeft, "Left Arrow"},
    {sfKeyRight, "Right Arrow"}, {sfKeyUp, "Up Arrow"},
    {sfKeyDown, "Down Arrow"}, {sfKeyNumpad0, "Numpad 0"},
    {sfKeyNumpad1, "Numpad 1"}, {sfKeyNumpad2, "Numpad 2"},
    {sfKeyNumpad3, "Numpad 3"}, {sfKeyNumpad4, "Numpad 4"},
    {sfKeyNumpad5, "Numpad 5"}, {sfKeyNumpad6, "Numpad 6"},
    {sfKeyNumpad7, "Numpad 7"}, {sfKeyNumpad8, "Numpad 8"},
    {sfKeyNumpad9, "Numpad 9"}, {sfKeyF1, "F1"}, {sfKeyF2, "F2"},
    {sfKeyF3, "F3"}, {sfKeyF4, "F4"}, {sfKeyF5, "F5"},
    {sfKeyF6, "F6"}, {sfKeyF7, "F7"}, {sfKeyF8, "F8"}, {sfKeyF9, "F9"},
    {sfKeyF10, "F10"}, {sfKeyF11, "F11"}, {sfKeyF12, "F12"},
    {sfKeyF13, "F13"}, {sfKeyF14, "F14"}, {sfKeyF15, "F15"},
    {sfKeyPause, "Pause"}
};

static void set_control_text(game_data_t *game)
{
    sfVector2f text_pos1 = {132, 272};
    sfVector2f text_pos2 = {598, 272};
    sfText *text1;
    sfText *text2;
    int nbr_text = sizeof(key_config) / sizeof(key_config[0]);
    key_config_t *keys = key_config;

    for (int i = 0; i < nbr_text; i++) {
        text1 = set_text(game, keys[i].name, 22, text_pos1);
        text2 = set_text(game, keys[i].key_name, 22, text_pos2);
        sfRenderWindow_drawText(game->window, text1, NULL);
        sfRenderWindow_drawText(game->window, text2, NULL);
        sfText_destroy(text1);
        sfText_destroy(text2);
        text_pos1.y += 61;
        text_pos2.y += 61;
    }
}

void modify_control(game_data_t *game)
{
    if (is_key_pressed(game, ArrowDown) && game->state == SETTINGS_CONTROLS) {
        game->settings.clicked_control++;
        game->settings.clicked_control %= 10;
    }
    if (is_key_pressed(game, ArrowUp) && game->state == SETTINGS_CONTROLS) {
        if (game->settings.clicked_control == 0)
            game->settings.clicked_control = 10;
        game->settings.clicked_control--;
        game->settings.clicked_control %= 10;
    }
}

static void draw_bg_control(game_data_t *game)
{
    sfRectangleShape *rect;
    sfVector2f rectangle_pos = {106, 260};
    sfVector2f rectangle_size = {664, 52};
    int nbr_rect = 10;

    for (int i = 0; i < nbr_rect; i++) {
        rect = sfRectangleShape_create();
        if (i > 0)
            rectangle_pos.y += 61;
        sfRectangleShape_setPosition(rect, rectangle_pos);
        sfRectangleShape_setSize(rect, rectangle_size);
        draw_tools_control(game, rect, i);
    }
}

char *key_to_string(sfKeyCode key)
{
    static const int key_count = sizeof(key_mapping) / sizeof(key_mapping[0]);

    for (int i = 0; i < key_count; ++i) {
        if (key_mapping[i].code == key)
            return (char *)key_mapping[i].name;
    }
    return "Unknown";
}

void settings_update_key(game_data_t *game, sfKeyCode code)
{
    for (int i = 0; i < KEYBINDS_COUNT; ++i) {
        if (game->keybinds[i].key
            == key_config[game->settings.clicked_control].key) {
            game->keybinds[i].code = code;
            key_config[game->settings.clicked_control].key_name =
                key_to_string(code);
            return;
        }
    }
}

keycode_t get_pressed_key(void)
{
    for (sfKeyCode key = sfKeyA; key <= sfKeyPause; (sfKeyCode)++key) {
        if (sfKeyboard_isKeyPressed(key))
            return key;
    }
    return sfKeyUnknown;
}

static bool is_key_already_bound(game_data_t *game, sfKeyCode key)
{
    for (int i = 0; i < KEYBINDS_COUNT; ++i) {
        if (game->keybinds[i].code == key)
            return true;
    }
    return false;
}

static void handle_key_rebinding(game_data_t *game)
{
    sfKeyCode new_key = get_pressed_key();

    if (new_key != sfKeyUnknown && new_key != sfKeyUp
        && new_key != sfKeyDown) {
        if (!is_key_already_bound(game, new_key))
            settings_update_key(game, new_key);
    }
}

void draw_everything_control(game_data_t *game)
{
    basic_menu(game);
    if (game->last_state == MAIN_MENU)
        draw_active_navbar_line(game, 290.0f, 270.0f);
    else
        draw_active_navbar_line(game, 905.0f, 262.0f);
    draw_settings_navbar(game);
    modify_control(game);
    handle_key_rebinding(game);
    set_control_text(game);
    draw_bg_control(game);
}
