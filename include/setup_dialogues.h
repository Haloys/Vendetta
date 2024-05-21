/*
** EPITECH PROJECT, 2024
** Vendetta / Header
** File description:
** Setup Dialogues
*/

#ifndef SETUP_DIALOGUES_H
    #define SETUP_DIALOGUES_H

    #include "dialogues.h"

static const char *lucia_response_filenames[] = {
    "database/dialogues/lucia/response1.txt",
    "database/dialogues/lucia/response2.txt",
    "database/dialogues/lucia/response3.txt"
};

static const char *lucia_choice_filenames[] = {
    "database/dialogues/lucia/choice1.txt",
    "database/dialogues/lucia/choice2.txt",
    "database/dialogues/lucia/choice3.txt"
};

static const dialogue_params_t DIALOGUES[] = {
    {
        .character_name = "Lucia :",
        .initial_filename = "database/dialogues/lucia/dialogues.txt",
        .response_filenames = lucia_response_filenames,
        .response_count = 3,
        .choice_filenames = lucia_choice_filenames,
        .sprite_id = SP_RED_NPC_PIC,
    },
};

#endif // SETUP_DIALOGUES_H
