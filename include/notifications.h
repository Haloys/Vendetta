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
    {"Permanent", "This will last indefinitely", SP_OBJECTIVE, -1},
    {"Map Change", "Map change !", SP_OBJECTIVE, 5.0},
    {"New Item !", "You found Key A", SP_OBJECTIVE, 5.0},
    {"New Item !", "You found Key B", SP_OBJECTIVE, 5.0},
    {"New Item !", "You found Key C", SP_OBJECTIVE, 5.0},
    {"New Item !", "You found Knife", SP_OBJECTIVE, 5.0},
    {"New Item !", "You found Bandage", SP_OBJECTIVE, 5.0},
    {"New Item !", "You found Pistol", SP_OBJECTIVE, 5.0},
    {"New Item !", "You found Aidkit", SP_OBJECTIVE, 5.0},
    {"New Item !", "You found Rifle", SP_OBJECTIVE, 5.0},
    {"New Item !", "You found Shotgun", SP_OBJECTIVE, 5.0},
    {"Whaou !", "You found a chest", SP_OBJECTIVE, 5.0},
    {"Incredible", "You found a secret chest", SP_OBJECTIVE},
    {"Amazing", "You found a secret chest", SP_OBJECTIVE},
    {"Unbelievable, You found boss stash", SP_OBJECTIVE},
    {"Prodigious, You found a massive stash", SP_OBJECTIVE},
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
