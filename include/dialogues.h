/*
** EPITECH PROJECT, 2024
** Vendetta / Header
** File description:
** Dialogues
*/

#ifndef DIALOGUES_H_
    #define DIALOGUES_H_

    #include "my_game.h"

    #define TEXT_SPEED 0.05f
    #define MAX_DIALOGUE_LENGTH 256
    #define NAME_X 798
    #define NAME_Y 110
    #define TEXT_X 798
    #define TEXT_Y 140
    #define NAME_FONT_SIZE 24
    #define TEXT_FONT_SIZE 20
    #define BOX_WIDTH 500
    #define BOX_HEIGHT 150
    #define BOX1_X 129
    #define BOX1_Y 445
    #define BOX2_Y 630
    #define BOX3_Y 815

typedef struct dialogue_s {
    char **lines;
    size_t line_count;
    size_t current_line;
    size_t current_char;
    float timer;
    sfClock *clock;
    sfText *text;
    sfText *name_text;
    bool finished;
} dialogue_t;

typedef struct choice_box_s {
    sfRectangleShape *box;
    sfText *text;
} choice_box_t;

typedef struct dialogues_params_s {
    const char *character_name;
    const char *initial_filename;
    const char **response_filenames;
    size_t response_count;
    const char **choice_filenames;
    sprite_id_t sprite_id;
} dialogue_params_t;

typedef struct choice_select_params_s {
    dialogue_t **response_dialogue;
    choice_box_t *boxes;
    dialogue_params_t *params;
    game_data_t *game;
    bool *choice_selected;
} choice_select_params_t;

typedef struct mouse_click_params_s {
    dialogue_t **response_dialogue;
    choice_box_t *boxes;
    dialogue_params_t *params;
    game_data_t *game;
    bool *choice_selected;
} mouse_click_params_t;

typedef struct dialogue_box_params_s {
    dialogue_t **dialogue;
    choice_box_t **boxes;
    char ***choice_texts;
    dialogue_params_t *params;
    game_data_t *game;
} dialogue_box_params_t;

typedef struct dialogue_data_s {
    dialogue_t **dialogue;
    dialogue_t **response_dialogue;
    bool *choice_selected;
    bool *space_pressed;
} dialogue_data_t;

dialogue_t *load_dialogue(const char *filename,
    const char *name, sfFont *font);

void show_full_text(dialogue_t *dialogue);
void process_dialogue(dialogue_t *dialogue, sfRenderWindow *window,
    bool *space_pressed);

void initialize_dialogue_and_boxes(dialogue_box_params_t *box_p);
void draw_choice_box(sfRenderWindow *window, choice_box_t *box);

#endif /* !DIALOGUES_H_ */
