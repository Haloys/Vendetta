/*
** EPITECH PROJECT, 2024
** Vendetta / Header
** File description:
** Setup Dialogues
*/

#ifndef SETUP_DIALOGUES_H
    #define SETUP_DIALOGUES_H

    #include "dialogues.h"

static const char *mike_response_filenames[] = {
    "database/dialogues/mike/response1.txt",
    "database/dialogues/mike/response2.txt",
    "database/dialogues/mike/response3.txt"
};

static const char *mike_choice_filenames[] = {
    "database/dialogues/mike/choice1.txt",
    "database/dialogues/mike/choice2.txt",
    "database/dialogues/mike/choice3.txt"
};

static const char *sasha_response_filenames[] = {
    "database/dialogues/sasha/response1.txt",
    "database/dialogues/sasha/response2.txt",
    "database/dialogues/sasha/response3.txt"
};

static const char *sasha_choice_filenames[] = {
    "database/dialogues/sasha/choice1.txt",
    "database/dialogues/sasha/choice2.txt",
    "database/dialogues/sasha/choice3.txt"
};

static const char *trevor_response_filenames[] = {
    "database/dialogues/trevor/response1.txt",
    "database/dialogues/trevor/response2.txt",
    "database/dialogues/trevor/response3.txt"
};

static const char *trevor_choice_filenames[] = {
    "database/dialogues/trevor/choice1.txt",
    "database/dialogues/trevor/choice2.txt",
    "database/dialogues/trevor/choice3.txt"
};

static const char *oleksandra_response_filenames[] = {
    "database/dialogues/oleksandra/response1.txt",
    "database/dialogues/oleksandra/response2.txt",
    "database/dialogues/oleksandra/response3.txt"
};

static const char *oleksandra_choice_filenames[] = {
    "database/dialogues/oleksandra/choice1.txt",
    "database/dialogues/oleksandra/choice2.txt",
    "database/dialogues/oleksandra/choice3.txt"
};

static const char *marcus_response_filenames[] = {
    "database/dialogues/marcus/response1.txt",
    "database/dialogues/marcus/response2.txt",
    "database/dialogues/marcus/response3.txt"
};

static const char *marcus_choice_filenames[] = {
    "database/dialogues/marcus/choice1.txt",
    "database/dialogues/marcus/choice2.txt",
    "database/dialogues/marcus/choice3.txt"
};

static const dialogue_params_t DIALOGUES[] = {
    {
        .character_name = "Mike :",
        .initial_filename = "database/dialogues/mike/dialogues.txt",
        .response_filenames = mike_response_filenames,
        .response_count = 3,
        .choice_filenames = mike_choice_filenames,
        .sprite_id = SP_YELLOW_NPC_PIC,
    },
    {
        .character_name = "Sasha :",
        .initial_filename = "database/dialogues/sasha/dialogues.txt",
        .response_filenames = sasha_response_filenames,
        .response_count = 3,
        .choice_filenames = sasha_choice_filenames,
        .sprite_id = SP_WHITE_NPC_PIC,
    },
    {
        .character_name = "Trevor :",
        .initial_filename = "database/dialogues/trevor/dialogues.txt",
        .response_filenames = trevor_response_filenames,
        .response_count = 3,
        .choice_filenames = trevor_choice_filenames,
        .sprite_id = SP_GREEN_NPC_PIC,
    },
    {
        .character_name = "Oleksandra :",
        .initial_filename = "database/dialogues/oleksandra/dialogues.txt",
        .response_filenames = oleksandra_response_filenames,
        .response_count = 3,
        .choice_filenames = oleksandra_choice_filenames,
        .sprite_id = SP_BLACK_NPC_PIC,
    },
    {
        .character_name = "Marcus :",
        .initial_filename = "database/dialogues/marcus/dialogues.txt",
        .response_filenames = marcus_response_filenames,
        .response_count = 3,
        .choice_filenames = marcus_choice_filenames,
        .sprite_id = SP_RED_NPC_PIC,
    }
};

#endif // SETUP_DIALOGUES_H
