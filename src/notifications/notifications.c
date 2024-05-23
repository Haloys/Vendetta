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

static void notif_draw(display_params_t *params, notification_t *notification)
{
    sfRenderWindow_drawRectangleShape(params->game->window, params->background,
        NULL);
    sfRenderWindow_drawRectangleShape(params->game->window,
        params->line, NULL);
    sfRenderWindow_drawSprite(params->game->window, notification->icon, NULL);
    sfRenderWindow_drawText(params->game->window, notification->title, NULL);
    sfRenderWindow_drawText(params->game->window, notification->message, NULL);
}

static void display_single_notification(game_data_t *game,
    display_params_t *params, notification_t *notification, int y_offset)
{
    float ratio = game->view_zoom;
    sfVector2f relativepos = params->relativepos;

    sfRectangleShape_setPosition(params->background, (sfVector2f)
        {relativepos.x, relativepos.y + (41 * ratio) + y_offset});
    sfRectangleShape_setPosition(params->line, (sfVector2f)
        {relativepos.x, relativepos.y + (186 * ratio) + y_offset});
    sfSprite_setPosition(notification->icon, (sfVector2f)
        {relativepos.x + (20 * ratio), relativepos.y + 60 * ratio + y_offset});
    sfText_setPosition(notification->title, (sfVector2f)
        {relativepos.x + (54 * ratio), relativepos.y + 55 * ratio + y_offset});
    sfText_setPosition(notification->message, (sfVector2f)
        {relativepos.x + (19 * ratio), relativepos.y +
        (105 * ratio) + y_offset});
    sfRectangleShape_setScale(params->line, (sfVector2f){ratio, ratio});
    sfRectangleShape_setScale(params->background, (sfVector2f){ratio, ratio});
    sfSprite_setScale(notification->icon, (sfVector2f){ratio, ratio});
    sfText_setScale(notification->title, (sfVector2f){ratio, ratio});
    sfText_setScale(notification->message, (sfVector2f){ratio, ratio});
    notif_draw(params, notification);
}

void display_notifications(game_data_t *game, notification_list_t *list)
{
    notification_t *current = list->head;
    int y_offset = 0;
    sfVector2f view_size = sfView_getSize(game->game_view);
    sfVector2f relativepos = {game->view_pos.x - view_size.x / 2,
        game->view_pos.y - view_size.y / 2};
    sfRectangleShape *background = sfRectangleShape_create();
    sfRectangleShape *line = sfRectangleShape_create();
    display_params_t params = {game, background, line, relativepos};

    sfRectangleShape_setSize(background, (sfVector2f){401, 150});
    sfRectangleShape_setFillColor(background, FILL_COLOR);
    sfRectangleShape_setSize(line, (sfVector2f){401, 5});
    sfRectangleShape_setFillColor(line, sfColor_fromRGB(51, 217, 122));
    while (current != NULL) {
        display_single_notification(game, &params, current, y_offset);
        y_offset += 200 * game->view_zoom;
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

    if (dialog_index < 0 || (size_t)dialog_index >= sizeof(NOTIFICATION) /
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
