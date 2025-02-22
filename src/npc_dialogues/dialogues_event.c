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

static void update_box_color(sfRectangleShape *box, sfBool mouse_over)
{
    if (mouse_over) {
        sfRectangleShape_setFillColor(box, HOVER_FILL_COLOR);
        sfRectangleShape_setOutlineColor(box, HOVER_OUTLINE_COLOR);
    } else {
        sfRectangleShape_setFillColor(box, FILL_COLOR);
        sfRectangleShape_setOutlineColor(box, OUTLINE_COLOR);
    }
}

static void handle_mouse_hover(mouse_click_params_t *click_p)
{
    sfFloatRect box_bounds;
    sfVector2f mouse_pos = click_p->game->mouse_pos;
    sfBool mouse_over;

    for (size_t i = 0; i < click_p->params->response_count; i++) {
        box_bounds = sfRectangleShape_getGlobalBounds(click_p->boxes[i].box);
        mouse_over = sfFloatRect_contains(&box_bounds,
            mouse_pos.x, mouse_pos.y);
        update_box_color(click_p->boxes[i].box, mouse_over);
    }
}

static void handle_mouse_click(mouse_click_params_t *click_p)
{
    sfFloatRect box_bounds;
    sfVector2f mouse_pos = click_p->game->mouse_pos;

    handle_mouse_hover(click_p);
    if (!sfMouse_isButtonPressed(sfMouseLeft))
        return;
    for (size_t i = 0; i < click_p->params->response_count; i++) {
        box_bounds = sfRectangleShape_getGlobalBounds(click_p->boxes[i].box);
        if (!sfFloatRect_contains(&box_bounds, mouse_pos.x, mouse_pos.y))
            continue;
        *click_p->response_dialogue =
            load_dialogue(click_p->params->response_filenames[i],
                click_p->params->character_name, click_p->game->font);
        if (!*click_p->response_dialogue)
            return;
        *click_p->choice_selected = true;
        break;
    }
}

static void draw_choice_box(sfRenderWindow *window, choice_box_t *box)
{
    sfRenderWindow_drawRectangleShape(window, box->box, NULL);
    sfRenderWindow_drawText(window, box->text, NULL);
}

static void handle_choice_selection(choice_select_params_t *select_p)
{
    mouse_click_params_t click_p;

    if (!*select_p->choice_selected) {
        for (size_t i = 0; i < select_p->params->response_count; i++) {
            draw_choice_box(select_p->game->window, &select_p->boxes[i]);
        }
        click_p.response_dialogue = select_p->response_dialogue;
        click_p.boxes = select_p->boxes;
        click_p.params = select_p->params;
        click_p.game = select_p->game;
        click_p.choice_selected = select_p->choice_selected;
        handle_mouse_click(&click_p);
    }
}

static void handle_initial_dialogue(game_data_t *game, dialogue_data_t *data)
{
    if (!*data->choice_selected)
        process_dialogue(*data->dialogue, game->window, data->space_pressed);
}

static void handle_response_dialogue(game_data_t *game, dialogue_data_t *data,
    choice_box_t *boxes, const dialogue_params_t *params)
{
    choice_select_params_t select_p = {data->response_dialogue,
        boxes, params, game, data->choice_selected};

    if ((*data->dialogue)->finished &&
        !*data->response_dialogue && !*data->choice_selected) {
        process_dialogue(*data->dialogue, game->window, data->space_pressed);
        handle_choice_selection(&select_p);
    }
    if (*data->response_dialogue)
        process_dialogue(*data->response_dialogue, game->window,
            data->space_pressed);
}

static void cleanup(dialogue_t **response_dialogue, char ***choice_texts,
    const dialogue_params_t *params)
{
    if (*response_dialogue && *choice_texts) {
        for (size_t i = 0; i < params->response_count; i++) {
            free((*choice_texts)[i]);
        }
        free(*choice_texts);
        *choice_texts = NULL;
    }
}

static void draw_dialogue_utils(game_data_t *game,
    const dialogue_params_t *params)
{
    sfText *help_prompt = set_text(game,
    "Press SPACE to continue\n\nPress ESC to exit", 20, (sfVector2f){20, 20});

    sfRenderWindow_drawSprite(game->window,
    get_sprite(game, params->sprite_id), NULL);
    sfRenderWindow_drawText(game->window, help_prompt, NULL);
    sfText_destroy(help_prompt);
}

void handle_choice(game_data_t *game, const dialogue_params_t *params,
    dialogue_state_t *state)
{
    dialogue_data_t dialogue_data = {&state->dialogue,
        &state->response_dialogue, &state->choice_selected,
            &state->space_pressed};
    dialogue_box_params_t box_p = {&state->dialogue, &state->boxes,
        &state->choice_texts, params, game};

    initialize_dialogue_and_boxes(&box_p);
    if (!state->dialogue || !state->boxes)
        return;
    basic_design(game);
    draw_dialogue_utils(game, params);
    handle_initial_dialogue(game, &dialogue_data);
    handle_response_dialogue(game, &dialogue_data, state->boxes, params);
    cleanup(&state->response_dialogue, &state->choice_texts, params);
}
