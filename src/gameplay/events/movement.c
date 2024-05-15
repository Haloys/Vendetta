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

static float get_max_zoom(game_data_t *game, game_sprite_t *map)
{
    sfVector2f center = sfView_getCenter(game->view);

    return MIN(
        MIN(center.x / (WINDOW_WIDTH / 2),
            (map->rect.width - center.x) / (WINDOW_WIDTH / 2)),
        MIN(center.y / (WINDOW_HEIGHT / 2),
            (map->rect.height - center.y) / (WINDOW_HEIGHT / 2))
    );
}

static void set_zoom(game_data_t *game, game_sprite_t *map, sfTime time)
{
    float dif = 0;

    if (is_key_down(game, KeyPlus))
        game->target_zoom *= 1 + ZOOM_SPEED * sfTime_asSeconds(time);
    if (is_key_down(game, KeyMinus))
        game->target_zoom *= 1 - ZOOM_SPEED * sfTime_asSeconds(time);
    dif = (game->target_zoom - game->view_zoom) / 10.f;
    game->target_zoom = CLAMP(game->target_zoom, ZOOM_MIN,
        get_max_zoom(game, map));
    if (ABS(dif) > EPSILON) {
        game->view_zoom += dif;
        sfView_setSize(game->view, (sfVector2f){WINDOW_WIDTH * game->view_zoom,
            WINDOW_HEIGHT * game->view_zoom});
    }
}

static void set_view(game_data_t *game, player_data_t *player, sfTime time)
{
    sfVector2f size = {0, 0};

    sfRenderWindow_setView(game->window, game->view);
    set_zoom(game, &game->map, time);
    size = sfView_getSize(game->view);
    if (size.x / 2.f < player->position.x
        && player->position.x < game->map.rect.width - size.x / 2.f)
        game->view_pos.x += (player->position.x - game->view_pos.x) / 30.f;
    if (size.y / 2.f < player->position.y
        && player->position.y < game->map.rect.height - size.y / 2.f)
        game->view_pos.y += (player->position.y - game->view_pos.y) / 10.f;
    sfView_setCenter(game->view, game->view_pos);
}

static void update_player_direction(game_data_t *game)
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

static bool is_black_color(sfColor color)
{
    return color.r == 0 && color.g == 0 && color.b == 0;
}

void update_player(game_data_t *game, sfTime time)
{
    player_data_t *player = game->player;
    float scale = sfTime_asSeconds(time) * game->player->pspeed;

    update_player_direction(game);
    if (is_key_down(game, Sprint))
        scale *= SPRINT_MUL;
    player->direction.x *= scale;
    player->direction.y *= scale;
    if (!(is_black_color(get_pixel_color(game->cols_map, player->position.x
        + (player->direction.x * RADAR_SIZE), player->position.y))))
        player->position.x += player->direction.x;
    if (!(is_black_color(get_pixel_color(game->cols_map, player->position.x,
        player->position.y + (player->direction.y * RADAR_SIZE)))))
        player->position.y += player->direction.y;
    set_view(game, player, time);
    if (ABS(player->rotation - player->target_rot) > EPSILON) {
        player->rotation = lerp_angle(player->rotation, player->target_rot,
            0.25f);
    }
}
