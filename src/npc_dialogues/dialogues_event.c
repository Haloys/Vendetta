/*
** EPITECH PROJECT, 2024
** Vendetta
** File description:
** Text Box
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
        sfRectangleShape_setFillColor(box, FILL_COLOR);
        sfRectangleShape_setOutlineColor(box, OUTLINE_COLOR);
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

    set_mouse_pos(click_p->game);
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
    choice_box_t *boxes, dialogue_params_t *params)
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

void cleanup(dialogue_t **response_dialogue, char ***choice_texts,
    dialogue_params_t *params)
{
    if (*response_dialogue && *choice_texts) {
        for (size_t i = 0; i < params->response_count; i++) {
            free((*choice_texts)[i]);
        }
        free(*choice_texts);
        *choice_texts = NULL;
    }
}

void handle_choice(game_data_t *game, dialogue_params_t *params)
{
    static dialogue_t *dialogue = NULL;
    static dialogue_t *response_dialogue = NULL;
    static choice_box_t *boxes = NULL;
    static bool space_pressed = false;
    static bool choice_selected = false;
    static char **choice_texts = NULL;
    dialogue_data_t dialogue_data = {&dialogue, &response_dialogue,
        &choice_selected, &space_pressed};
    dialogue_box_params_t box_p = {&dialogue, &boxes, &choice_texts,
        params, game};

    initialize_dialogue_and_boxes(&box_p);
    if (!dialogue || !boxes)
        return;
    basic_design(game);
    sfRenderWindow_drawSprite(game->window, get_sprite(game,
        params->sprite_id), NULL);
    handle_initial_dialogue(game, &dialogue_data);
    handle_response_dialogue(game, &dialogue_data, boxes, params);
    cleanup(&response_dialogue, &choice_texts, params);
}

void init_lucia(game_data_t *game)
{
    const char *response_filenames[] = {
        "database/dialogues/lucia/response1.txt",
        "database/dialogues/lucia/response2.txt",
        "database/dialogues/lucia/response3.txt"
    };
    const char *choice_filenames[] = {
        "database/dialogues/lucia/choice1.txt",
        "database/dialogues/lucia/choice2.txt",
        "database/dialogues/lucia/choice3.txt"
    };
    dialogue_params_t params = {
        .character_name = "Lucia :",
        .initial_filename = "database/dialogues/lucia/dialogues.txt",
        .response_filenames = response_filenames,
        .response_count = 3,
        .choice_filenames = choice_filenames,
        .sprite_id = SP_LUCIA
    };

    handle_choice(game, &params);
}

void npc_dialogues(game_data_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
        game->state = PLAYING;
        return;
    }
    init_lucia(game);
}
