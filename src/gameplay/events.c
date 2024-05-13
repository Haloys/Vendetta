/*
** EPITECH PROJECT, 2024
** Vendetta
** File description:
** Process player events
*/

#include "my_game.h"

void process_player_event(game_data_t *game, sfEvent *evt)
{
    sfSprite *sp = get_sprite(game, SP_PLAYER_HAND);
    sfVector2f pos = sfSprite_getPosition(sp);

    if (evt->key.code == sfKeyLeft) {
        sfSprite_setPosition(sp, (sfVector2f){pos.x - 10, pos.y});
        sfSprite_setRotation(sp, 180);
    }
    if (evt->key.code == sfKeyRight) {
        sfSprite_setPosition(sp, (sfVector2f){pos.x + 10, pos.y});
        sfSprite_setRotation(sp, 0);
    }
    if (evt->key.code == sfKeyUp) {
        sfSprite_setPosition(sp, (sfVector2f){pos.x, pos.y - 10});
        sfSprite_setRotation(sp, 270);
    }
    if (evt->key.code == sfKeyDown) {
        sfSprite_setPosition(sp, (sfVector2f){pos.x, pos.y + 10});
        sfSprite_setRotation(sp, 90);
    }

}
