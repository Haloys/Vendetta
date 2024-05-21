/*
** EPITECH PROJECT, 2024
** Vendetta / Header
** File description:
** Setup Dialogues
*/

#ifndef NOTIFICATIONS_H
    #define NOTIFICATIONS_H

    #include "my_game.h"

typedef struct notification {
    sfText *title;
    sfText *message;
    sfSprite *icon;
    sfClock *clock;
    float duration;
    struct notification *next;
} notification_t;

typedef struct notification_list {
    notification_t *head;
    int count;
} notification_list_t;

typedef struct display_params_s {
    game_data_t *game;
    sfRectangleShape *background;
    sfRectangleShape *line;
    sfVector2f relativepos;
} display_params_t;

typedef struct notification_params {
    const char *title;
    const char *message;
    int sprite_id;
    float duration;
} notification_params_t;

static const notification_params_t NOTIFICATION[] = {
    {"Short Duration", "This will last 2 seconds", SP_OBJECTIVE, 2.0},
    {"Medium Duration", "This will last 5 seconds", SP_OBJECTIVE, 5.0},
    {"Permanent", "This will last indefinitely", SP_OBJECTIVE, -1},
    {"Map Change", "Map change !", SP_OBJECTIVE, 5.0},
};

void init_notification_list(notification_list_t *list);

notification_t *create_notification(game_data_t *game,
    const notification_params_t *params);
void add_notification(notification_list_t *list, notification_t *notif);
void remove_notification(notification_list_t *list);

void display_notifications(game_data_t *game, notification_list_t *list);
void update_notifications(notification_list_t *list);
void trigger_notification(game_data_t *game, int dialog_index);

#endif /* NOTIFICATIONS_H */
