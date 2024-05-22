/*
** EPITECH PROJECT, 2024
** Vendetta / Game Engine
** File description:
** Animation
*/

#include <math.h>
#include <stdio.h>

#include "my_game.h"
#include "gameplay.h"
#include "enemies.h"

void draw_enemy(game_data_t *game, enemy_t *enemy)
{
    sfRenderWindow_drawSprite(game->window, enemy->sprite, NULL);
    sfRenderWindow_drawCircleShape(game->window, enemy->area, NULL);
    sfRenderWindow_drawRectangleShape(game->window, enemy->health_bar, NULL);
}

static void update_spritesheet(game_data_t *game, enemy_t *enemy, sfTime time)
{
    sfIntRect rect = {0};

    if (sfTime_asMilliseconds(time) % 6 == 0) {
        rect = sfSprite_getTextureRect(enemy->sprite);
        if (rect.left >= enemy->sprite_data->rect.width
            * (enemy->sprite_data->rect_count - 1))
            rect.left = 0;
        else
            rect.left += enemy->sprite_data->rect.width;
        sfSprite_setTextureRect(enemy->sprite, rect);
    }
    if (fmodf(sfTime_asMilliseconds(time), 50) == 0) {
        printf("Enemy shoot\n");
        list_add_element(&game->bullets, create_bullet(game,
            &enemy->position, &enemy->direction, enemy->rotation));
    }
}

void update_enemy(game_data_t *game, enemy_t *enemy)
{
    sfTime time = sfClock_getElapsedTime(enemy->clock);

    update_enemy_pos_diretion(enemy, game);
    update_enemy_pos_sprite(enemy);
    update_spritesheet(game, enemy, time);
}
