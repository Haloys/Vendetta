/*
** EPITECH PROJECT, 2024
** Vendetta / Game Engine
** File description:
** Animation
*/

#include <string.h>

#include "my_game.h"
#include "gameplay.h"

static void update_spritesheet(player_data_t *player)
{
    sfTime time = sfClock_getElapsedTime(player->anim_clock);
    sfIntRect rect = sfSprite_getTextureRect(player->sprite);

    if (sfTime_asMilliseconds(time) >= 70) {
        if (rect.left >= player->sprite_data->rect.width
            * (player->sprite_data->rect_count - 1))
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

static void check_weapon(game_data_t *game, char *weapon)
{
    if (strcmp(weapon, "knife") == 0) {
        game->player->sprite_data = &SPRITES[SP_PLAYER_KNIFE];
        game->player->sprite = get_sprite(game, SP_PLAYER_KNIFE);
    }
    if (strcmp(weapon, "pistol") == 0) {
        game->player->sprite_data = &SPRITES[SP_PLAYER_GUN];
        game->player->sprite = get_sprite(game, SP_PLAYER_GUN);
    }
    if (strcmp(weapon, "rifle") == 0) {
        game->player->sprite_data = &SPRITES[SP_PLAYER_RIFLE];
        game->player->sprite = get_sprite(game, SP_PLAYER_RIFLE);
    }
    if (strcmp(weapon, "shotgun") == 0) {
        game->player->sprite_data = &SPRITES[SP_PLAYER_SHOTGUN];
        game->player->sprite = get_sprite(game, SP_PLAYER_SHOTGUN);
    }
}

void update_player_skin(game_data_t *game)
{
    char *weapon = get_equiped_weapon(game);

    if (weapon == NULL) {
        game->player->sprite_data = &SPRITES[SP_PLAYER_HAND];
        game->player->sprite = get_sprite(game, SP_PLAYER_HAND);
        return;
    }
    check_weapon(game, weapon);
}
