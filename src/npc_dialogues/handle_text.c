/*
** EPITECH PROJECT, 2024
** Vendetta
** File description:
** Handle Text
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <wchar.h>

#include "my_game.h"
#include "dialogues.h"

void show_full_text(dialogue_t *dialogue)
{
    if (dialogue->finished || dialogue->current_line >= dialogue->line_count)
        return;
    dialogue->current_char =
        wcslen((wchar_t *)dialogue->lines[dialogue->current_line]);
}

static void update_dialogue(dialogue_t *dialogue)
{
    if (dialogue->finished || dialogue->current_line >= dialogue->line_count)
        return;
    dialogue->timer += sfTime_asSeconds(sfClock_restart(dialogue->clock));
    if (dialogue->timer >= TEXT_SPEED) {
        dialogue->timer = 0.0f;
        if (dialogue->lines[dialogue->current_line][dialogue->current_char]
                != '\0') {
            dialogue->current_char++;
        }
    }
}

static void draw_dialogue(sfRenderWindow *window, dialogue_t *dialogue)
{
    sfUint32 display_text[MAX_DIALOGUE_LENGTH];

    if (dialogue->current_line >= dialogue->line_count)
        return;
    for (size_t i = 0; i < dialogue->current_char; i++) {
        display_text[i] = dialogue->lines[dialogue->current_line][i];
    }
    display_text[dialogue->current_char] = '\0';
    sfText_setUnicodeString(dialogue->text, display_text);
    sfRenderWindow_drawText(window, dialogue->name_text, NULL);
    sfRenderWindow_drawText(window, dialogue->text, NULL);
}

static void next_line(dialogue_t *dialogue)
{
    if (dialogue->current_char <
            wcslen((wchar_t *)dialogue->lines[dialogue->current_line])) {
        show_full_text(dialogue);
        return;
    }
    if (dialogue->current_line >= dialogue->line_count - 1) {
        dialogue->finished = true;
        return;
    }
    dialogue->current_line++;
    dialogue->current_char = 0;
}

static void handle_dialogue_line(dialogue_t *dialogue)
{
    if (dialogue->current_char <
            wcslen((wchar_t *)dialogue->lines[dialogue->current_line])) {
        show_full_text(dialogue);
    } else {
        next_line(dialogue);
    }
}

static void handle_space_press(dialogue_t *dialogue, bool *space_pressed)
{
    if (!*space_pressed) {
        *space_pressed = true;
        handle_dialogue_line(dialogue);
    }
}

static void handle_key_press(dialogue_t *dialogue, bool *space_pressed)
{
    if (sfKeyboard_isKeyPressed(sfKeySpace)) {
        handle_space_press(dialogue, space_pressed);
    } else {
        *space_pressed = false;
    }
}

void process_dialogue(dialogue_t *dialogue, sfRenderWindow *window,
    bool *space_pressed)
{
    if (dialogue->finished) {
        show_full_text(dialogue);
        draw_dialogue(window, dialogue);
        return;
    }
    handle_key_press(dialogue, space_pressed);
    update_dialogue(dialogue);
    draw_dialogue(window, dialogue);
}
