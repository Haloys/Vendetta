/*
** EPITECH PROJECT, 2024
** Vendetta
** File description:
** Process player events
*/

#include <stdio.h>
#include <math.h>

#include "my_game.h"
#include "gameplay.h"

void process_key_left(game_data_t *game, sfSprite *sp_map, float scale)
{
    float speed = game->player->direction.x * scale;
    sfVector2f pos_map = sfSprite_getPosition(sp_map);
    sfSprite *sp_cols_map = get_sprite(game, SP_COLS_MAP_1);
    sfColor color = get_pixel_color(game->cols_map,
        game->player->map_pos.x - RADAR_SIZE, game->player->map_pos.y);

    if (color.r == 0)
        return;
    if (game->player->pos_offset.x > 0
        || game->player->map_pos.x <= VIEW_WIDTH) {
        game->player->pos_offset.x += speed;
        game->player->position.x += speed;
    } else {
        sfSprite_setPosition(sp_map,
            (sfVector2f){pos_map.x - speed, pos_map.y});
        sfSprite_setPosition(sp_cols_map,
            (sfVector2f){pos_map.x - speed, pos_map.y});
    }
    game->player->map_pos.x += speed;
}

void process_key_right(game_data_t *game, sfSprite *sp_map, float scale)
{
    float speed = game->player->direction.x * scale;
    sfVector2f pos_map = sfSprite_getPosition(sp_map);
    sfSprite *sp_cols_map = get_sprite(game, SP_COLS_MAP_1);
    sfColor color = get_pixel_color(game->cols_map,
        game->player->map_pos.x + RADAR_SIZE, game->player->map_pos.y);

    if (color.r == 0)
        return;
    if (game->player->pos_offset.x < 0
        || game->player->map_pos.x + VIEW_WIDTH >= 3640) {
        game->player->pos_offset.x += speed;
        game->player->position.x += speed;
    } else {
        sfSprite_setPosition(sp_map,
            (sfVector2f){pos_map.x - speed, pos_map.y});
        sfSprite_setPosition(sp_cols_map,
            (sfVector2f){pos_map.x - speed, pos_map.y});
    }
    game->player->map_pos.x += speed;
}

void process_key_up(game_data_t *game, sfSprite *sp_map, float scale)
{
    float speed = game->player->direction.y * scale;
    sfVector2f pos_map = sfSprite_getPosition(sp_map);
    sfSprite *sp_cols_map = get_sprite(game, SP_COLS_MAP_1);
    sfColor color = get_pixel_color(game->cols_map, game->player->map_pos.x,
        game->player->map_pos.y - RADAR_SIZE);

    if (color.r == 0)
        return;
    if (game->player->pos_offset.y > 0
        || game->player->map_pos.y <= VIEW_HEIGHT) {
        game->player->pos_offset.y += speed;
        game->player->position.y += speed;
    } else {
        sfSprite_setPosition(sp_map,
            (sfVector2f){pos_map.x, pos_map.y - speed});
        sfSprite_setPosition(sp_cols_map,
            (sfVector2f){pos_map.x, pos_map.y - speed});
    }
    game->player->map_pos.y += speed;
}

void process_key_down(game_data_t *game, sfSprite *sp_map, float scale)
{
    float speed = game->player->direction.y * scale;
    sfVector2f pos_map = sfSprite_getPosition(sp_map);
    sfSprite *sp_cols_map = get_sprite(game, SP_COLS_MAP_1);
    sfColor color = get_pixel_color(game->cols_map, game->player->map_pos.x,
        game->player->map_pos.y + RADAR_SIZE);

    if (color.r == 0)
        return;
    if (game->player->pos_offset.y < 0
        || game->player->map_pos.y + VIEW_HEIGHT >= 2660) {
        game->player->pos_offset.y += speed;
        game->player->position.y += speed;
    } else {
        sfSprite_setPosition(sp_map,
            (sfVector2f){pos_map.x, pos_map.y - speed});
        sfSprite_setPosition(sp_cols_map,
            (sfVector2f){pos_map.x, pos_map.y - speed});
    }
    game->player->map_pos.y += speed;
}

void update_player_direction(game_data_t *game)
{
    player_data_t *player = game->player;
    sfVector2f direction = {0, 0};

    if (is_key_down(game, MoveUp))
        direction.y -= 1;
    if (is_key_down(game, MoveDown))
        direction.y += 1;
    if (is_key_down(game, MoveRight))
        direction.x += 1;
    if (is_key_down(game, MoveLeft))
        direction.x -= 1;
    if (direction.x != 0 || direction.y != 0) {
        player->target_rot = fmodf(atan2f(direction.y, direction.x)
            * PI_180, 360);
        normalize(&direction);
    } else
        player->target_rot = lerp_angle(player->rotation, player->target_rot,
            0.25f);
    player->direction = direction;
}
