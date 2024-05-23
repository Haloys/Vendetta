/*
** EPITECH PROJECT, 2024
** Vendetta / Header
** File description:
** Setup Dialogues
*/

#ifndef SETUP_NOTIFICATIONS_H
    #define SETUP_NOTIFICATIONS_H

    #include "notifications.h"

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
    {"Incredible", "You found a secret chest", SP_OBJECTIVE, 5.0},
    {"Amazing", "You found a secret chest", SP_OBJECTIVE, 5.0},
    {"Unbelievable", "You found boss stash", SP_OBJECTIVE, 5.0},
    {"Prodigious", "You found a massive stash", SP_OBJECTIVE, 5.0},
};

#endif /* SETUP_NOTIFICATIONS_H */
