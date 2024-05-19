/*
** EPITECH PROJECT, 2024
** Vendetta
** File description:
** Choice Box
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>

#include "my_game.h"
#include "dialogues.h"

static sfRectangleShape *create_box(float x, float y)
{
    sfRectangleShape *box = sfRectangleShape_create();

    if (!box)
        return NULL;
    sfRectangleShape_setSize(box, (sfVector2f){BOX_WIDTH, BOX_HEIGHT});
    sfRectangleShape_setPosition(box, (sfVector2f){x, y});
    sfRectangleShape_setFillColor(box, FILL_COLOR);
    sfRectangleShape_setOutlineColor(box, OUTLINE_COLOR);
    sfRectangleShape_setOutlineThickness(box, 1.0f);
    return box;
}

static choice_box_t create_choice_box(float x, float y,
    sfFont *font, const char *text)
{
    choice_box_t box;
    sfUint32 *utf32text;

    box.box = create_box(x, y);
    if (!box.box)
        return box;
    box.text = sfText_create();
    if (!box.text) {
        sfRectangleShape_destroy(box.box);
        return box;
    }
    sfText_setFont(box.text, font);
    sfText_setCharacterSize(box.text, TEXT_FONT_SIZE);
    sfText_setPosition(box.text, (sfVector2f){x + 30, y + 30});
    utf32text = utf8_to_utf32(text);
    if (utf32text) {
        sfText_setUnicodeString(box.text, utf32text);
        free(utf32text);
    }
    return box;
}

static void free_choice_texts(char ***choice_texts, size_t count)
{
    for (size_t i = 0; i < count; i++) {
        free((*choice_texts)[i]);
    }
    free(*choice_texts);
}

static void destroy_boxes(choice_box_t **boxes, size_t count)
{
    for (size_t j = 0; j < count; j++) {
        sfRectangleShape_destroy((*boxes)[j].box);
        sfText_destroy((*boxes)[j].text);
    }
    free(*boxes);
}

static void initialize_box(choice_box_t **boxes, char ***choice_texts,
    size_t i, game_data_t *game)
{
    float y_pos = BOX1_Y + i * (BOX2_Y - BOX1_Y);

    (*boxes)[i] = create_choice_box(BOX1_X, y_pos,
        game->font, (*choice_texts)[i]);
    if (!(*boxes)[i].box || !(*boxes)[i].text) {
        destroy_boxes(boxes, i);
        free_choice_texts(choice_texts, i);
        return;
    }
}

static char *read_all_from_file(const char *filename)
{
    FILE *file = fopen(filename, "r");
    char *buffer;
    size_t len;

    if (!file)
        return strdup("Error loading choice");
    fseek(file, 0, SEEK_END);
    len = ftell(file);
    fseek(file, 0, SEEK_SET);
    buffer = malloc(len + 1);
    if (buffer) {
        fread(buffer, 1, len, file);
        buffer[len] = '\0';
    }
    fclose(file);
    return buffer;
}

static char **load_choice_texts(const char **choice_filenames, size_t count)
{
    char **choice_texts = malloc(count * sizeof(char *));

    if (!choice_texts)
        return NULL;
    for (size_t i = 0; i < count; i++) {
        choice_texts[i] = read_all_from_file(choice_filenames[i]);
        if (!choice_texts[i])
            choice_texts[i] = strdup("Error loading choice");
    }
    return choice_texts;
}

static void initialize_boxes(choice_box_t **boxes, char ***choice_texts,
    dialogue_params_t *params, game_data_t *game)
{
    *choice_texts = load_choice_texts(params->choice_filenames,
        params->response_count);
    if (!*choice_texts)
        return;
    *boxes = malloc(params->response_count * sizeof(choice_box_t));
    if (!*boxes) {
        free_choice_texts(choice_texts, params->response_count);
        return;
    }
    for (size_t i = 0; i < params->response_count; i++) {
        initialize_box(boxes, choice_texts, i, game);
    }
}

static void initialize_dialogue(dialogue_t **dialogue,
    dialogue_params_t *params, game_data_t *game)
{
    *dialogue = load_dialogue(params->initial_filename,
        params->character_name, game->font);
}

void initialize_dialogue_and_boxes(dialogue_box_params_t *box_p)
{
    if (!*box_p->dialogue) {
        initialize_dialogue(box_p->dialogue, box_p->params, box_p->game);
        if (!*box_p->dialogue)
            return;
    }
    if (!*box_p->boxes) {
        initialize_boxes(box_p->boxes,
            box_p->choice_texts, box_p->params, box_p->game);
        if (!*box_p->boxes)
            return;
    }
}
