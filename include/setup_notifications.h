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
    {"Map Change", "Map change !", SP_OBJECTIVE, 7.0},
    {"New Item !", "You found Key A", SP_OBJECTIVE, 10.0},
    {"New Item !", "You found Key B", SP_OBJECTIVE, 10.0},
    {"New Item !", "You found Key C", SP_OBJECTIVE, 10.0},
    {"New Item !", "You found Knife", SP_OBJECTIVE, 10.0},
    {"New Item !", "You found Bandage", SP_OBJECTIVE, 10.0},
    {"New Item !", "You found Pistol", SP_OBJECTIVE, 10.0},
    {"New Item !", "You found Aidkit", SP_OBJECTIVE, 10.0},
    {"New Item !", "You found Rifle", SP_OBJECTIVE, 10.0},
    {"New Item !", "You found Shotgun", SP_OBJECTIVE, 10.0},
    {"Whaou !", "You found a chest", SP_OBJECTIVE, 10.0},
    {"Incredible", "You found a secret chest", SP_OBJECTIVE, 10.0},
    {"Amazing", "You found a secret chest", SP_OBJECTIVE, 10.0},
    {"Unbelievable", "You found boss stash", SP_OBJECTIVE, 10.0},
    {"Prodigious", "You found a massive stash", SP_OBJECTIVE, 10.0},
    {"Oxycodone ?", "Trevor gave you some oxycodone, would\n"
                "it be a good idea to take it?", SP_OBJECTIVE, 30.0},
    {"New key !", "Oleksandra has given you a key! Will you,\n"
        "go to the bottom of the cementery to,\n"
            "stop this organisation!", SP_OBJECTIVE, 30.0},
    {"Nice shoes !", "Mike gave you some nice green shoes !\n"
        "Would  it be useful to equip them by,\n"
            "opening the inventory?", SP_OBJECTIVE, 30.0},
    {"That some protection !", "Mike has given you a suit of\n"
        "armour that could be more than useful\n"
            "for this vendetta!", SP_OBJECTIVE, 30.0},
    {"Goldcoin", "You found a goldcoin", SP_OBJECTIVE, 30.0},
    {"Map 2 Unlocked", "You have unlocked Map 2!", SP_OBJECTIVE, 15.0},
    {"Map 3 Unlocked", "You have unlocked Map 3!", SP_OBJECTIVE, 15.0},
    {"Welcome", "You woke up !", SP_OBJECTIVE, 30.0},
    {"The start of a vendetta", "Escape from prison, recover\n"
        "all the keys and take your revenge.", SP_OBJECTIVE, -1},
    {"Finding the mysterious lady", "After this magnificent escape, find\n"
        "the informant who will give you access to\n"
            "the Sylens lair.", SP_OBJECTIVE, -1},
    {"Your Vendetta", "Face your worst enemy, and achieve\n"
        "your vendetta\n", SP_OBJECTIVE, -1},
};

#endif /* SETUP_NOTIFICATIONS_H */
