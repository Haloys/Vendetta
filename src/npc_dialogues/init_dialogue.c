/*
** EPITECH PROJECT, 2024
** Vendetta
** File description:
** Init Dialogue
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#include "my_game.h"
#include "dialogues.h"

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
