/*
** EPITECH PROJECT, 2024
** Vendetta / Game Engine
** File description:
** Animation
*/

#include <math.h>
#include <stdio.h>

#include "gameplay.h"
#include "enemies.h"
#include "entity.h"
#include "utils.h"

static path_node_t *get_node_by_id(game_data_t *game, int id)
{
    return &game->points[id];
}

static path_node_t *get_nearest_node(game_data_t *game, sfVector2f *pos)
{
    path_node_t *node = NULL;
    float distance = 0;
    int lowest = 999999;
    int save_node_id = -1;
    float angle = 0;

    for (int i = 0; i < game->points_count; ++i) {
        node = &game->points[i];
        distance = sqrt(pow(pos->x - node->position.x, 2) +
            pow(pos->y - node->position.y, 2));
        angle = atan2(node->position.y - pos->y, node->position.x - pos->x);
        if (can_move_to_point(game, pos, &(sfVector2f){cos(angle), sin(angle)},
            &node->position) && distance < lowest) {
            lowest = distance;
            save_node_id = node->id;
        }
    }
    return save_node_id == -1 ? NULL : get_node_by_id(game, save_node_id);
}

static path_node_t *find_node_to_player(game_data_t *game,
    path_node_t *current, path_node_t *end, int depth)
{
    path_node_t *node = NULL;

    if (current->id == end->id)
        return current;
    for (int i = 0; i < current->link_count; ++i) {
        node = &game->points[current->links[i].to];
        if (node == NULL || current->links[i].visited)
            continue;
        current->links[i].visited = true;
        if (node->id == end->id) {
            current->links[i].valid = true;
            current->links[i].distance = depth;
            return node;
        }
        node = find_node_to_player(game, node, end, depth + 1);
        if (node != NULL)
            return node;
    }
    return NULL;
}

static path_node_t *get_next_node_to_player_valid(game_data_t *game,
    path_node_t *start)
{
    path_node_t *node = NULL;

    for (int i = 0; i < start->link_count; ++i) {
        node = &game->points[start->links[i].to];
        if (node == NULL || !start->links[i].valid || node->id == start->id)
            continue;
        return node;
    }
    return NULL;
}

static path_node_t *get_next_node_to_player(game_data_t *game,
    path_node_t *start, path_node_t *end)
{
    path_node_t *node = NULL;

    for (int i = 0; i < game->points_count; ++i) {
        for (int j = 0; j < game->points[i].link_count; ++j) {
            game->points[i].links[j].visited = false;
            game->points[i].links[j].valid = false;
            game->points[i].links[j].distance = -1;
        }
    }
    node = find_node_to_player(game, start, end, 0);
    if (node == NULL)
        return NULL;
    node = get_next_node_to_player_valid(game, start);
    if (node == NULL)
        return NULL;
    return node;
}

static void process_no_next_node(game_data_t *game, path_node_t *node,
    enemy_t *enemy, sfTime time)
{
    rect_t rect = {0};
    float angle = 0;

    angle = atan2(node->position.y - enemy->position.y,
        node->position.x - enemy->position.x);
    rect = get_hitbox_rect(&node->position, 5);
    if (will_collide_wall(game, &enemy->position, &enemy->direction)
    || is_rect(enemy->position.x, enemy->position.y, &rect))
        return;
    enemy->direction = (sfVector2f){cos(angle), sin(angle)};
    enemy->position.x += enemy->direction.x * sfTime_asSeconds(time)
        * enemy->config->speed;
    enemy->position.y += enemy->direction.y * sfTime_asSeconds(time)
        * enemy->config->speed;
}

static void process_next_node(game_data_t *game, path_node_t *next_node,
    enemy_t *enemy, sfTime time)
{
    float angle = 0;

    enemy->path = next_node;
    printf("next_node %d\n", next_node->id);
    angle = atan2(next_node->position.y - enemy->position.y,
        next_node->position.x - enemy->position.x);
    enemy->direction = (sfVector2f){cos(angle), sin(angle)};
    if (will_collide_wall(game, &enemy->position, &enemy->direction))
        return;
    enemy->position.x += enemy->direction.x * sfTime_asSeconds(time)
        * enemy->config->speed;
    enemy->position.y += enemy->direction.y * sfTime_asSeconds(time)
        * enemy->config->speed;
}

void walk_to_nearest_point(enemy_t *enemy, game_data_t *game,
    sfTime time)
{
    path_node_t *next_node = NULL;
    path_node_t *node = get_nearest_node(game, &enemy->position);
    path_node_t *player_node = get_nearest_node(game, &game->player->position);

    if (can_move_to_point(game, &enemy->position, &enemy->direction,
        &game->player->position))
        enemy->disp_rotation = enemy->rotation;
    if (node == NULL || player_node == NULL)
        return;
    next_node = get_next_node_to_player(game, node, player_node);
    if (next_node == NULL) {
        process_no_next_node(game, node, enemy, time);
        return;
    }
    process_next_node(game, next_node, enemy, time);
}
