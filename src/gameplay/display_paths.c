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

static void set_paths_circles(game_data_t *game, sfCircleShape *circle, int i)
{
    sfCircleShape_setFillColor(circle, sfRed);
    sfCircleShape_setRadius(circle, 10);
    sfCircleShape_setOrigin(circle, (sfVector2f){10, 10});
    sfCircleShape_setPosition(circle, game->points[i].position);
}

static void set_paths_text(game_data_t *game, sfText *text, int i)
{
    char buffer[33] = {0};

    sprintf(buffer, "%d", i);
    sfText_setString(text, buffer);
    sfText_setCharacterSize(text, 20);
    sfText_setFont(text, game->font);
    sfText_setPosition(text, (sfVector2f){game->points[i].position.x - 8,
        game->points[i].position.y - 40});
}

static void set_paths_lines(game_data_t *game, sfVertexArray *vertex, int i)
{
    path_link_t *tmp = NULL;

    sfVertexArray_setPrimitiveType(vertex, sfLinesStrip);
    for (int j = 0; j < game->points[i].link_count; ++j) {
        sfVertexArray_append(vertex, (sfVertex){game->points[i].position,
            sfBlue});
        tmp = &game->points[i].links[j];
        sfVertexArray_append(vertex, (sfVertex){
            game->points[tmp->to].position, sfGreen});
        sfRenderWindow_drawVertexArray(game->window, vertex, NULL);
        sfVertexArray_clear(vertex);
    }
}

void display_paths(game_data_t *game)
{
    sfCircleShape *circle = sfCircleShape_create();
    sfText *text = sfText_create();
    sfVertexArray *vertex = sfVertexArray_create();

    if (circle == NULL || text == NULL)
        return;
    for (int i = 0; i < game->points_count; ++i) {
        set_paths_lines(game, vertex, i);
        sfRenderWindow_drawVertexArray(game->window, vertex, NULL);
        sfVertexArray_clear(vertex);
    }
    for (int i = 0; i < game->points_count; ++i) {
        set_paths_text(game, text, i);
        set_paths_circles(game, circle, i);
        sfRenderWindow_drawCircleShape(game->window, circle, NULL);
        sfRenderWindow_drawText(game->window, text, NULL);
    }
    sfCircleShape_destroy(circle);
    sfText_destroy(text);
}
