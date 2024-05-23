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
#include "setup_notifications.h"

void trigger_npc_notification(game_data_t *game, int npc_id,
    int *notification_given, int notification_id)
{
    if (game->player->npc_id == npc_id && *notification_given == 0) {
        trigger_notification(game, notification_id);
        dprintf(2, "Notification triggered\n");
        *notification_given = 1;
    }
}

void npc_dialogues(game_data_t *game)
{
    static dialogue_state_t state = {0};
    static int notification_given[5] = {0};

    if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
        change_game_mode(game, PLAYING);
        reset_dialogue_state(&state, &DIALOGUES[game->player->npc_id]);
        trigger_npc_notification(game, 0, &notification_given[0], 18);
        trigger_npc_notification(game, 2, &notification_given[2], 16);
        trigger_npc_notification(game, 3, &notification_given[3], 17);
        trigger_npc_notification(game, 4, &notification_given[4], 19);
        return;
    }
    handle_choice(game, &DIALOGUES[game->player->npc_id], &state);
}
