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

const int COLLIDE_POINTS = 11;
const float RAD = 20.f;
const float COLLIDE_ARC = DEG2RAD(90.f);
const float ANGLE_DIFF = COLLIDE_ARC / (COLLIDE_POINTS - 1);

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
    if (fabsf(player->rotation - player->target_rot) > EPSILON) {
        player->rotation = lerp_angle(player->rotation, player->target_rot,
            0.15f);
    }
}

static void check_bullet_player(game_data_t *game)
{
    float angle = 0;
    sfVector2f dir = {0, 0};
    int damage = 1 + game->player->attack / 5;

    if (game->clicked && game->is_passive == false
        && get_equiped_weapon(game) != NULL) {
        play_sound(game, S_AK47);
        angle = atan2f(game->mouse_pos.y - game->player->position.y,
            game->mouse_pos.x - game->player->position.x);
        dir = (sfVector2f){cosf(angle), sinf(angle)};
        list_add_element(&game->bullets, create_bullet(game,
            &(bullet_config_t){&game->player->position, &dir,
            game->player->target_rot + 90, damage, BULLET_MEDIUM_SPEED}));
    }
}

static sfVector2f detect_collision(game_data_t *game,
    const sfVector2f *pos, const sfVector2f *direction)
{
    float a = atan2f(direction->y, direction->x) - COLLIDE_ARC / 2.f;
    sfVector2f move = {0, 0};
    sfCircleShape *circle = sfCircleShape_create();
    sfVector2f rot = {0, 0};

    sfCircleShape_setRadius(circle, 6);
    sfCircleShape_setOrigin(circle, (sfVector2f){3, 3});
    for (int i = 0; i < COLLIDE_POINTS; ++i) {
        rot = (sfVector2f){pos->x + cosf(a) * RAD, pos->y + sinf(a) * RAD};
        sfCircleShape_setPosition(circle, rot);
        if (can_entity_pass(game, rot.x, rot.y)) {
            move = (sfVector2f){move.x + cosf(a), move.y + sinf(a)};
            sfCircleShape_setFillColor(circle, sfBlue);
        } else
            sfCircleShape_setFillColor(circle, sfRed);
        a += ANGLE_DIFF;
        sfRenderTexture_drawCircleShape(game->debug_overlay, circle, NULL);
    }
    sfCircleShape_destroy(circle);
    return move;
}

static void resolve_collision(game_data_t *game, sfVector2f *pos,
    sfVector2f const *dir, float speed)
{
    sfVector2f movement = detect_collision(game, pos, dir);

    normalize(&movement);
    if (fabsf(movement.x) > EPSILON || fabsf(movement.y) > EPSILON) {
        pos->x += movement.x * speed;
        pos->y += movement.y * speed;
    }
}

void update_player(game_data_t *game, sfTime time)
{
    float scale = sfTime_asSeconds(time) * game->player->pspeed;
    player_data_t *player = game->player;

    update_player_direction(game);
    if (is_key_down(game, Sprint))
        scale *= SPRINT_MUL;
    if (fabsf(player->direction.x) > EPSILON
        || fabsf(player->direction.y) > EPSILON)
        resolve_collision(game, &player->position, &player->direction, scale);
    update_player_direction_t(game);
    set_view(game, time);
    check_bullet_player(game);
}
