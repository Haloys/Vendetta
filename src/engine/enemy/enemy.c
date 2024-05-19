/*
** EPITECH PROJECT, 2024
** Vendetta / Game Engine
** File description:
** Animation
*/

#include <math.h>

#include "my_game.h"
#include "gameplay.h"
#include "enemies.h"

void draw_enemy(game_data_t *game, enemy_t *enemy)
{
    sfRenderWindow_drawSprite(game->window, enemy->sprite, NULL);
    sfRenderWindow_drawCircleShape(game->window, enemy->area, NULL);
    sfRenderWindow_drawRectangleShape(game->window, enemy->health_bar, NULL);
}

static void update_spritesheet(enemy_t *enemy, sfTime time)
{
    sfIntRect rect = sfSprite_getTextureRect(enemy->sprite);

    if (sfTime_asMilliseconds(time) >= 70) {
        if (rect.left >= enemy->sprite_data->rect.width
            * (enemy->sprite_data->rect_count - 1))
            rect.left = 0;
        else
            rect.left += enemy->sprite_data->rect.width;
        sfClock_restart(enemy->clock);
    }
    sfSprite_setTextureRect(enemy->sprite, rect);
}

void update_enemy(game_data_t *game, enemy_t *enemy)
{
    sfTime time = sfClock_getElapsedTime(enemy->clock);

    update_enemy_pos_diretion(enemy, game);
    update_enemy_pos_sprite(enemy);
    update_spritesheet(enemy, time);
}
