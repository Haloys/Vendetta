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
#include "setup_dialogues.h"
#include "utils.h"

void npc_dialogues(game_data_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
        change_game_mode(game, PLAYING);
        return;
    }
    handle_choice(game, &DIALOGUES[game->player->npc_id]);
}
