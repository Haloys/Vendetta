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
#include "entity.h"
#include "utils.h"

void draw_enemy(game_data_t *game, enemy_t *enemy)
{
    sfRenderWindow_drawSprite(game->window, enemy->sprite, NULL);
    sfRenderWindow_drawCircleShape(game->window, enemy->area, NULL);
    sfRenderWindow_drawRectangleShape(game->window, enemy->health_bar, NULL);
}

static void process_enemy_shoot(game_data_t *game, enemy_t *enemy)
{
    if (!will_collide_wall(game, &enemy->position, &enemy->target)) {
        list_add_element(&game->bullets, create_bullet(game,
            &(bullet_config_t){&enemy->position, &enemy->target,
                enemy->rotation, enemy->config->attack, BULLET_NORMAL_SPEED}));
        sfClock_restart(enemy->shoot_clock);
    }
}

static void update_spritesheet(game_data_t *game, enemy_t *enemy)
{
    sfTime game_time = sfClock_getElapsedTime(game->clock);
    sfIntRect rect = {0};

    if (sfTime_asMilliseconds(game_time) % 6 == 0) {
        rect = sfSprite_getTextureRect(enemy->sprite);
        if (rect.left >= enemy->sprite_data->rect.width
            * (enemy->sprite_data->rect_count - 1))
            rect.left = 0;
        else
            rect.left += enemy->sprite_data->rect.width;
        sfSprite_setTextureRect(enemy->sprite, rect);
    }
    if (game->is_passive == false
        && sfTime_asSeconds(sfClock_getElapsedTime(enemy->shoot_clock))
        > enemy->config->attack_speed)
        process_enemy_shoot(game, enemy);
}

void update_enemy(game_data_t *game, enemy_t *enemy)
{
    sfTime time = sfClock_getElapsedTime(enemy->clock);

    update_enemy_pos_diretion(enemy, game, time);
    update_enemy_pos_sprite(game, enemy);
    update_spritesheet(game, enemy);
    sfClock_restart(enemy->clock);
}
