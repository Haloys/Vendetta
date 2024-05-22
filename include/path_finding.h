/*
** EPITECH PROJECT, 2024
** Vendetta / Header
** File description:
** Animation
*/

#ifndef PATH_FINDING_H
    #define PATH_FINDING_H

    #include <SFML/Graphics.h>

    #define POINTS_COUNT 4
    #define MAX_POINTS 100
    #define MAX_LINKS 4

typedef struct path_link_s {
    int to;
    int parent;
    bool visited;
    bool valid;
    int cound;
    float distance;
    sfRectangleShape *line;
} path_link_t;

typedef struct path_node_s {
    int id;
    sfCircleShape *circle;
    sfVector2f position;
    float radius;
    float radius_squared;
    int link_count;
    path_link_t links[MAX_LINKS];
} path_node_t;


int init_path_finding(game_data_t *game);

#endif /* PATH_FINDING_H */
