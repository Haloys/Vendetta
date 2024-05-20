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

key_config_s key_config[] = {
    {
        .name = "Forward",
        .key_name = "Z",
        .key = sfKeyZ
    },
    {
        .name = "Backward",
        .key_name = "S",
        .key = sfKeyS
    },
    {
        .name = "Left",
        .key_name = "Q",
        .key = sfKeyQ
    },
    {
        .name = "Right",
        .key_name = "D",
        .key = sfKeyD
    },
    {
        .name = "Open inventory",
        .key_name = "I",
        .key = sfKeyI
    },
    {
        .name = "Toggle hostile mode",
        .key_name = "W",
        .key = sfKeyW
    },
    {
        .name = "Interact",
        .key_name = "E",
        .key = sfKeyE
    },
    {
        .name = "Open skill tree",
        .key_name = "Y",
        .key = sfKeyY
    },
    {
        .name = "Heal",
        .key_name = "A",
        .key = sfKeyA
    },
    {
        .name = "Pause",
        .key_name = "P",
        .key = sfKeyP
    }
};

static const key_mapping_t keyMappings[] = {
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
    key_config_s *keys = key_config;

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
    if (is_key_pressed(game, MoveDown) && game->state == SETTINGS_CONTROLS) {
        game->clicked_control++;
        game->clicked_control %= 10;
    }
    if (is_key_pressed(game, MoveUp) && game->state == SETTINGS_CONTROLS) {
        if (game->clicked_control == 0)
            game->clicked_control = 10;
        game->clicked_control--;
        game->clicked_control %= 10;
    }
}

static void draw_tools_control(game_data_t *game, sfRectangleShape *rect,
    int i)
{
    if (i == game->clicked_control) {
        sfRectangleShape_setFillColor(rect,
            sfColor_fromRGBA(255, 255, 255, 20));
        sfRectangleShape_setOutlineThickness(rect, 2);
        sfRectangleShape_setOutlineColor(rect,
            sfColor_fromRGB(51, 217, 122));
    } else {
        sfRectangleShape_setFillColor(rect,
            sfColor_fromRGBA(255, 255, 255, 0));
    }
    sfRenderWindow_drawRectangleShape(game->window, rect, NULL);
    sfRectangleShape_destroy(rect);
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

char *sfKeyToString(sfKeyCode key) {
    static const int key_count = sizeof(keyMappings) / sizeof(keyMappings[0]);

    for (int i = 0; i < key_count; ++i) {
        if (keyMappings[i].code == key) {
            return keyMappings[i].name;
        }
    }
    return "Unknown";
}

sfKeyCode get_pressed_key()
{
    for (sfKeyCode key = sfKeyA; key <= sfKeyPause;
        key = (sfKeyCode)(key + 1)) {
        if (sfKeyboard_isKeyPressed(key)) {
            return key;
        }
    }
    return sfKeyUnknown;
}

static void update_keybinding(int index, sfKeyCode new_key)
{
    if (key_config[index].key != new_key) {
        key_config[index].key = new_key;
        key_config[index].key_name = sfKeyToString(new_key);
    }
}

static void handle_key_rebinding(game_data_t *game)
{
    static int rebinding = -1;
    sfKeyCode new_key = get_pressed_key();

    if (new_key != sfKeyUnknown && new_key != sfKeyUp &&
        new_key != sfKeyDown) {
        rebinding = game->clicked_control;
        update_keybinding(rebinding, new_key);
        rebinding = -1;
    }
    set_control_text(game);
}

void draw_everything_control(game_data_t *game)
{
    basic_menu(game);
    draw_active_navbar_line(game, 290.0f, 270.0f);
    draw_settings_navbar(game);
    modify_control(game);
    handle_key_rebinding(game);
    draw_bg_control(game);
}
