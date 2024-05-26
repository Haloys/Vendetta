/*
** EPITECH PROJECT, 2024
** Vendetta
** File description:
** Notifications
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>

#include "my_game.h"
#include "notifications.h"

void init_notification_list(notification_list_t *list)
{
    list->head = NULL;
    list->count = 0;
}

notification_t *create_notification(game_data_t *game,
    const notification_params_t *params)
{
    notification_t *notif = malloc(sizeof(notification_t));

    if (notif == NULL)
        return NULL;
    notif->title = sfText_create();
    notif->message = sfText_create();
    notif->icon = get_sprite(game, params->sprite_id);
    notif->clock = sfClock_create();
    notif->duration = params->duration;
    notif->next = NULL;
    sfText_setString(notif->title, params->title);
    sfText_setFont(notif->title, game->font);
    sfText_setCharacterSize(notif->title, 24);
    sfText_setPosition(notif->title, (sfVector2f){54, 55});
    sfText_setString(notif->message, params->message);
    sfText_setFont(notif->message, game->font);
    sfText_setCharacterSize(notif->message, 18);
    sfText_setPosition(notif->message, (sfVector2f){19, 105});
    return notif;
}

void add_notification(notification_list_t *list, notification_t *notif)
{
    notif->next = list->head;
    list->head = notif;
    list->count++;
}

void remove_notification(notification_list_t *list)
{
    notification_t *temp = list->head;

    if (list->head == NULL)
        return;
    list->head = list->head->next;
    sfText_destroy(temp->title);
    sfText_destroy(temp->message);
    sfClock_destroy(temp->clock);
    free(temp);
    list->count--;
}
