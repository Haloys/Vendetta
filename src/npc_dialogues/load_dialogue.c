/*
** EPITECH PROJECT, 2024
** Vendetta
** File description:
** Load Dialogue
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#include "my_game.h"
#include "dialogues.h"

static bool init_sfml_objects(dialogue_t *dialogue,
    const char *name, sfFont *font)
{
    dialogue->clock = sfClock_create();
    dialogue->text = sfText_create();
    dialogue->name_text = sfText_create();
    if (!dialogue->clock || !dialogue->text || !dialogue->name_text)
        return false;
    sfText_setFont(dialogue->text, font);
    sfText_setCharacterSize(dialogue->text, 26);
    sfText_setPosition(dialogue->text, (sfVector2f){TEXT_X, TEXT_Y});
    sfText_setFont(dialogue->name_text, font);
    sfText_setCharacterSize(dialogue->name_text, NAME_FONT_SIZE);
    sfText_setColor(dialogue->name_text, sfColor_fromRGB(197, 197, 197));
    sfText_setPosition(dialogue->name_text, (sfVector2f){NAME_X, NAME_Y});
    sfText_setString(dialogue->name_text, name);
    return true;
}

static dialogue_t *init_dialogue(const char *name, sfFont *font)
{
    dialogue_t *dialogue = malloc(sizeof(dialogue_t));

    if (!dialogue)
        return NULL;
    dialogue->lines = NULL;
    dialogue->line_count = 0;
    dialogue->current_line = 0;
    dialogue->current_char = 0;
    dialogue->timer = 0.0f;
    dialogue->finished = false;
    if (!init_sfml_objects(dialogue, name, font)) {
        free(dialogue);
        return NULL;
    }
    return dialogue;
}

static void transform_line(char *line)
{
    for (char *p = line; *p; p++) {
        if (*p == ';') {
            *p = '\n';
        }
    }
}

static bool load_lines(dialogue_t *dialogue, FILE *file)
{
    char buffer[MAX_DIALOGUE_LENGTH];

    while (fgets(buffer, MAX_DIALOGUE_LENGTH, file)) {
        transform_line(buffer);
        dialogue->line_count++;
        dialogue->lines = realloc(dialogue->lines,
            dialogue->line_count * sizeof(sfUint32*));
        if (!dialogue->lines)
            return false;
        dialogue->lines[dialogue->line_count - 1] = utf8_to_utf32(buffer);
        if (!dialogue->lines[dialogue->line_count - 1])
            return false;
    }
    return true;
}

dialogue_t *load_dialogue(const char *filename, const char *name, sfFont *font)
{
    FILE *file = fopen(filename, "r");
    dialogue_t *dialogue = init_dialogue(name, font);

    if (!file)
        return NULL;
    if (!dialogue) {
        fclose(file);
        return NULL;
    }
    if (!load_lines(dialogue, file)) {
        free(dialogue->lines);
        free(dialogue);
        fclose(file);
        return NULL;
    }
    fclose(file);
    return dialogue;
}
