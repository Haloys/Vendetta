/*
** EPITECH PROJECT, 2024
** Vendetta
** File description:
** Process gameplay loop
*/

#include <stdio.h>

#include "my_game.h"
#include "map.h"
#include "enemies.h"
#include "player.h"
#include "gameplay.h"
#include "game_npc.h"
#include "utils.h"
#include "entity.h"

void display_bullets(game_data_t *game)
{
    element_t *tmp = game->bullets.start.next;
    bullet_t *bullet = NULL;
    int saved_len = game->bullets.length;

    for (int i = 0; i < saved_len; ++i) {
        tmp = tmp->next;
        bullet = (bullet_t *)tmp->prev->data;
        update_bullet(game, bullet);
        if (is_black_color(get_pixel_color(game->cols_map, bullet->position.x,
            bullet->position.y)) || bullet_touched_entity(game, bullet)) {
            list_remove_element(&game->bullets, tmp->prev);
            continue;
        }
        sfRenderWindow_drawSprite(game->window,
            bullet->sprite, NULL);
    }
}

void display_entities(game_data_t *game)
{
    element_t *tmp = game->entities.start.next;

    for (int i = 0; i < game->entities.length; ++i) {
        if (game->map.id == ((item_entity_t *)tmp->data)->config->map_id)
            draw_entity(game, (item_entity_t *)tmp->data);
        tmp = tmp->next;
    }
}

void display_enemies(game_data_t *game)
{
    element_t *tmp = game->enemies.start.next;

    for (int i = 0; i < game->enemies.length; ++i) {
        if (game->map.id == ((enemy_t *)tmp->data)->map_id) {
            update_enemy(game, (enemy_t *)tmp->data);
            draw_enemy(game, (enemy_t *)tmp->data);
        }
        tmp = tmp->next;
    }
}

void display_npcs(game_data_t *game)
{
    element_t *tmp = game->npcs.start.next;

    for (int i = 0; i < game->npcs.length; ++i) {
        if (game->map.id == ((npc_t *)tmp->data)->config->map_id) {
            update_npc(game, (npc_t *)tmp->data);
            draw_npc(game, (npc_t *)tmp->data);
        }
        tmp = tmp->next;
    }
}

static void set_path(game_data_t *game, sfCircleShape *circle, sfText *text,
    int i)
{
    char buffer[33] = {0};

    sprintf(buffer, "%d", i);
    sfCircleShape_setFillColor(circle, sfRed);
    sfCircleShape_setRadius(circle, 10);
    sfCircleShape_setOrigin(circle, (sfVector2f){10, 10});
    sfCircleShape_setPosition(circle, game->points[i].position);
    sfRenderWindow_drawCircleShape(game->window, circle, NULL);
    sfText_setString(text, buffer);
    sfText_setFont(text, game->font);
    sfText_setCharacterSize(text, 20);
    sfText_setPosition(text, (sfVector2f){game->points[i].position.x - 8,
        game->points[i].position.y - 40});
    sfRenderWindow_drawText(game->window, text, NULL);
}

void display_paths(game_data_t *game)
{
    sfCircleShape *circle = sfCircleShape_create();
    sfText *text = sfText_create();

    if (circle == NULL || text == NULL)
        return;
    for (int i = 0; i < game->points_count; ++i)
        set_path(game, circle, text, i);
    sfCircleShape_destroy(circle);
    sfText_destroy(text);
}
