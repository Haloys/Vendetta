/*
** EPITECH PROJECT, 2024
** Vendetta
** File description:
** Main
*/

#include <stdio.h>
#include <string.h>
#include <math.h>

#include "my_game.h"

static void set_link_int(char *links, path_node_t *node)
{
    char *token = NULL;

    token = strtok(links, ",");
    while (token != NULL) {
        node->links[node->link_count] = (path_link_t){
            .to = atoi(token),
            .parent = node->id,
            .visited = false,
            .valid = true,
            .cound = 0,
            .distance = 0,
            .line = NULL
        };
        ++node->link_count;
        if (node->link_count >= MAX_LINKS)
            break;
        token = strtok(NULL, ",");
    }
}

void set_path_distances(game_data_t *game)
{
    path_node_t *node = NULL;
    path_node_t *end = NULL;

    for (int i = 0; i < game->points_count; ++i) {
        node = &game->points[i];
        for (int j = 0; j < node->link_count; ++j) {
            end = &game->points[node->links[j].to];
            node->links[j].distance =
                sqrt(pow(node->position.x - end->position.x, 2) +
                pow(node->position.y - end->position.y, 2));
        }
    }
}

int init_path_finding(game_data_t *game)
{
    sfVector2i pos = {0, 0};
    char *links = NULL;
    FILE *file = fopen("database/path_finding/map_one.ven", "r");

    if (file == NULL)
        return RET_FAIL;
    while (fscanf(file, "%d %d %m[^\n]", &pos.x, &pos.y, &links) == 3) {
        printf("x: %d, y: %d, links: %s\n", pos.x, pos.y, links);
        game->points[game->points_count].id = game->points_count;
        game->points[game->points_count].position = (sfVector2f){pos.x, pos.y};
        game->points[game->points_count].radius = 10;
        game->points[game->points_count].radius_squared = 100;
        set_link_int(links, &game->points[game->points_count]);
        ++game->points_count;
        if (game->points_count >= MAX_POINTS)
            break;
    }
    set_path_distances(game);
    fclose(file);
    return 0;
}
