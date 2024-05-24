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
#include "enemies.h"
#include "utils.h"
#include "map.h"

static float get_max_zoom(game_data_t *game, game_sprite_t const *map)
{
    sfVector2f center = game->player->position;

    return MIN(
        MIN(center.x / (WINDOW_WIDTH / 2),
            (map->rect.width - center.x) / (WINDOW_WIDTH / 2)),
        MIN(center.y / (WINDOW_HEIGHT / 2),
            (map->rect.height - center.y) / (WINDOW_HEIGHT / 2))
    );
}

static void change_zoom_key(game_data_t *game, sfTime time, min_max_t *zoom)
{
    if (game->target_zoom < zoom->max && is_key_down(game, KeyMinus))
        game->target_zoom *= 1 + ZOOM_SPEED * sfTime_asSeconds(time);
    if (game->target_zoom > zoom->min && is_key_down(game, KeyPlus))
        game->target_zoom *= 1 - ZOOM_SPEED * sfTime_asSeconds(time);
}

static void check_custom_zone(game_data_t *game, min_max_t *zoom,
    sfVector2f *position)
{
    for (int i = 0; i < game->map.zoom_count; ++i) {
        if (position->x >= game->map.zoom[i].zone.x1
            && position->x <= game->map.zoom[i].zone.x2
            && position->y >= game->map.zoom[i].zone.y1
            && position->y <= game->map.zoom[i].zone.y2) {
            zoom->min = game->map.zoom[i].min;
            zoom->max = game->map.zoom[i].max;
            position->x = game->map.zoom[i].pos.x > 0 ? game->map.zoom[i].pos.x
                : position->x;
            position->y = game->map.zoom[i].pos.y > 0 ? game->map.zoom[i].pos.y
                : position->y;
        }
    }
}

static int update_zoom_one(game_data_t *game, min_max_t *zoom,
    sfVector2f *size, sfVector2f *position)
{
    game_sprite_t const *map = game->map.sp_map;
    float diff = 0;

    diff = CLAMP(MIN(game->target_zoom, get_max_zoom(game, map)),
        zoom->min, zoom->max) - game->view_zoom;
    if (fabsf(diff) > EPSILON) {
        game->view_zoom += diff / 10.f;
        size->x = WINDOW_WIDTH * game->view_zoom;
        size->y = WINDOW_HEIGHT * game->view_zoom;
        sfView_setSize(game->game_view, *size);
    } else {
        *size = sfView_getSize(game->game_view);
    }
    sfView_setCenter(game->game_view, game->player->position);
    position->x -= size->x / 2.f;
    position->y -= size->y / 2.f;
    return diff;
}

static void set_view(game_data_t *game, sfTime time)
{
    game_sprite_t const *map = game->map.sp_map;
    sfVector2f position = game->player->position;
    min_max_t zoom = {ZOOM_MIN, ZOOM_MAX};
    sfVector2f size;
    float diff = 0;

    change_zoom_key(game, time, &zoom);
    check_custom_zone(game, &zoom, &position);
    diff = update_zoom_one(game, &zoom, &size, &position);
    diff = (CLAMP(position.x, 10.f, map->rect.width - size.x - 10)
        + size.x / 2.f) - game->view_pos.x;
    if (fabsf(diff) > EPSILON)
        game->view_pos.x += diff / 20.f;
    diff = (CLAMP(position.y, 10.f, map->rect.height - size.y - 10)
        + size.y / 2.f) - game->view_pos.y;
    if (fabsf(diff) > EPSILON)
        game->view_pos.y += diff / 10.f;
    sfView_setCenter(game->game_view, game->view_pos);
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
    player->direction = direction;
}

bool is_black_color(sfColor color)
{
    return color.r == 0 && color.g == 0 && color.b == 0;
}

static void update_player_direction_t(game_data_t *game)
{
    player_data_t *player = game->player;
    sfVector2f direction = {game->mouse_pos.x - player->position.x,
        game->mouse_pos.y - player->position.y};

    normalize(&direction);
    player->target_rot = fmodf(atan2f(direction.y, direction.x) * PI_180, 360);
    if (ABS(player->rotation - player->target_rot) > EPSILON) {
        player->rotation = lerp_angle(player->rotation, player->target_rot,
            0.15f);
    }
}

static void check_bullet_player(game_data_t *game)
{
    float angle = 0;
    sfVector2f dir = {0, 0};
    int damage = 1 + game->player->attack / 5;

    if (game->clicked && game->is_passive == false) {
        angle = atan2f(game->mouse_pos.y - game->player->position.y,
            game->mouse_pos.x - game->player->position.x);
        dir = (sfVector2f){cosf(angle), sinf(angle)};
        list_add_element(&game->bullets, create_bullet(game,
            &(bullet_config_t){&game->player->position, &dir,
            game->player->target_rot + 90, damage, BULLET_MEDIUM_SPEED}));
    }
}

void update_player(game_data_t *game, sfTime time)
{
    float scale = sfTime_asSeconds(time) * game->player->pspeed;
    player_data_t *player = game->player;

    update_player_direction(game);
    if (is_key_down(game, Sprint))
        scale *= SPRINT_MUL;
    normalize(&game->player->direction);
    player->direction.x *= scale;
    player->direction.y *= scale;
    if (!(is_black_color(get_pixel_color(game->cols_map, player->position.x
        + (player->direction.x * RADAR_SIZE), player->position.y))))
        player->position.x += player->direction.x;
    if (!(is_black_color(get_pixel_color(game->cols_map, player->position.x,
        player->position.y + (player->direction.y * RADAR_SIZE)))))
        player->position.y += player->direction.y;
    set_view(game, time);
    update_player_direction_t(game);
    check_bullet_player(game);
}
