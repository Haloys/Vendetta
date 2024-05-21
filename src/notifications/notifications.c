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

static void display_single_notification(display_params_t *params,
    notification_t *notification, int y_offset)
{
    sfRectangleShape_setPosition(params->background, (sfVector2f)
        {params->relativepos.x, params->relativepos.y + 41 + y_offset});
    sfRectangleShape_setPosition(params->line, (sfVector2f)
        {params->relativepos.x, params->relativepos.y + 186 + y_offset});
    sfRenderWindow_drawRectangleShape(params->game->window, params->background,
        NULL);
    sfRenderWindow_drawRectangleShape(params->game->window,
        params->line, NULL);
    sfSprite_setPosition(notification->icon, (sfVector2f)
        {params->relativepos.x + 20, params->relativepos.y + 60 + y_offset});
    sfText_setPosition(notification->title, (sfVector2f)
        {params->relativepos.x + 54, params->relativepos.y + 55 + y_offset});
    sfText_setPosition(notification->message, (sfVector2f)
        {params->relativepos.x + 19, params->relativepos.y + 105 + y_offset});
    sfRenderWindow_drawSprite(params->game->window, notification->icon, NULL);
    sfRenderWindow_drawText(params->game->window, notification->title, NULL);
    sfRenderWindow_drawText(params->game->window, notification->message, NULL);
}

void display_notifications(game_data_t *game, notification_list_t *list)
{
    notification_t *current = list->head;
    int y_offset = 0;
    sfVector2f view_pos = sfView_getCenter(game->game_view);
    sfVector2f relativepos = {view_pos.x - (WINDOW_WIDTH / 2),
        view_pos.y - (WINDOW_HEIGHT / 2)};
    sfRectangleShape *background = sfRectangleShape_create();
    sfRectangleShape *line = sfRectangleShape_create();
    display_params_t params = {game, background, line, relativepos};

    sfRectangleShape_setSize(background, (sfVector2f){401, 150});
    sfRectangleShape_setFillColor(background, FILL_COLOR);
    sfRectangleShape_setSize(line, (sfVector2f){401, 5});
    sfRectangleShape_setFillColor(line, sfColor_fromRGB(51, 217, 122));
    while (current != NULL) {
        display_single_notification(&params, current, y_offset);
        y_offset += 200;
        current = current->next;
    }
    sfRectangleShape_destroy(background);
    sfRectangleShape_destroy(line);
}

static bool should_remove_notification(notification_t *notif)
{
    float elapsed = sfClock_getElapsedTime(notif->clock).microseconds /
        1000000.0;

    return (notif->duration != -1 && elapsed > notif->duration);
}

static void remove_notification_at(notification_list_t *list,
    notification_t *prev, notification_t *current)
{
    if (prev == NULL) {
        list->head = current->next;
    } else {
        prev->next = current->next;
    }
    sfText_destroy(current->title);
    sfText_destroy(current->message);
    sfClock_destroy(current->clock);
    free(current);
    list->count--;
}

void update_notifications(notification_list_t *list)
{
    notification_t *current = list->head;
    notification_t *prev = NULL;

    while (current != NULL) {
        if (should_remove_notification(current)) {
            remove_notification_at(list, prev, current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

void trigger_notification(game_data_t *game, int dialog_index)
{
    notification_t *notif;
    notification_t *current = NULL;
    const notification_params_t *params = NULL;

    if (dialog_index < 0 || dialog_index >= sizeof(NOTIFICATION) /
        sizeof(NOTIFICATION[0]))
        return;
    params = &NOTIFICATION[dialog_index];
    current = game->notifications.head;
    while (current != NULL) {
        if (strcmp(sfText_getString(current->title), params->title) == 0 &&
            strcmp(sfText_getString(current->message), params->message) == 0) {
            return;
        }
        current = current->next;
    }
    if (game->notifications.count >= 5)
        remove_notification(&game->notifications);
    notif = create_notification(game, params);
    add_notification(&game->notifications, notif);
}
