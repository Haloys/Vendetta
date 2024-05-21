/*
** EPITECH PROJECT, 2024
** Vendetta
** File description:
** Dialogue Event
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#include "my_game.h"
#include "dialogues.h"

static void free_dialogue(dialogue_t *dialogue)
{
    if (!dialogue)
        return;
    for (size_t i = 0; i < dialogue->line_count; i++)
        free(dialogue->lines[i]);
    free(dialogue->lines);
    if (dialogue->clock)
        sfClock_destroy(dialogue->clock);
    if (dialogue->text)
        sfText_destroy(dialogue->text);
    if (dialogue->name_text)
        sfText_destroy(dialogue->name_text);
    free(dialogue);
}

static void reset_dialogues(dialogue_t **dialogue,
    dialogue_t **response_dialogue)
{
    if (*dialogue) {
        free_dialogue(*dialogue);
        *dialogue = NULL;
    }
    if (*response_dialogue) {
        free_dialogue(*response_dialogue);
        *response_dialogue = NULL;
    }
}

static void reset_choice_boxes(choice_box_t **boxes, char ***choice_texts,
    size_t response_count)
{
    if (*boxes) {
        for (size_t i = 0; i < response_count; i++) {
            sfRectangleShape_destroy((*boxes)[i].box);
            sfText_destroy((*boxes)[i].text);
        }
        free(*boxes);
        *boxes = NULL;
    }
    if (*choice_texts) {
        for (size_t i = 0; i < response_count; i++) {
            free((*choice_texts)[i]);
        }
        free(*choice_texts);
        *choice_texts = NULL;
    }
}

void reset_dialogue_state(dialogue_state_t *state,
    const dialogue_params_t *params)
{
    reset_dialogues(&state->dialogue, &state->response_dialogue);
    reset_choice_boxes(&state->boxes, &state->choice_texts,
        params->response_count);
    state->space_pressed = false;
    state->choice_selected = false;
}
