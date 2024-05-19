/*
** EPITECH PROJECT, 2024
** Vendetta / Game Engine
** File description:
** Animation
*/

#include "my_game.h"
#include "gameplay.h"

static void update_spritesheet(player_data_t *player)
{
    sfTime time = sfClock_getElapsedTime(player->anim_clock);
    sfIntRect rect = sfSprite_getTextureRect(player->sprite);

    if (sfTime_asMilliseconds(time) >= 70) {
        if (rect.left >= 2780 - player->sprite_data->rect.width)
            rect.left = 0;
        else
            rect.left += player->sprite_data->rect.width;
        sfClock_restart(player->anim_clock);
    }
    sfSprite_setTextureRect(player->sprite, rect);
}

void update_player_engine(player_data_t *player)
{
    sfSprite_setPosition(player->sprite, player->position);
    sfSprite_setRotation(player->sprite, player->rotation);
    update_spritesheet(player);
}
