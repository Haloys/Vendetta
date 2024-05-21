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

void display_entities(game_data_t *game)
{
    element_t *tmp = game->entities.start.next;

    for (int i = 0; i < game->entities.length; ++i) {
        if (game->map.id == ((item_entity_t *)tmp->data)->config->map_id)
            draw_entity(game, (item_entity_t *)tmp->data);
        tmp = tmp->next;
    }
}

static void display_enemies(game_data_t *game)
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

static void display_npcs(game_data_t *game)
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

static void display_player(game_data_t *game)
{
    update_player_engine(game->player);
    sfRenderWindow_drawSprite(game->window, game->player->sprite, NULL);
}

static void display_map(game_data_t *game)
{
    sfSprite *sp_map = get_sprite(game, game->map.map);

    if (sp_map == NULL)
        return;
    sfRenderWindow_drawSprite(game->window, sp_map, NULL);
}

static void check_gameplay_keys(game_data_t *game)
{
    if (is_key_pressed(game, Inventory))
        change_game_mode(game, INVENTORY);
    if (is_key_pressed(game, Echap))
        change_game_mode(game, PAUSE);
    if (is_key_pressed(game, Interact))
        game->is_passive = !game->is_passive;
}

static void change_map_if_needed(game_data_t *game)
{
    map_id_t map_id = game->map.id;

    if (is_in_portal(game))
        set_map(game, (map_id + 1) % 3);
    if (is_in_backportal(game))
        set_backmap(game, (map_id - 1) % 3);
}

void process_playing_gameplay(game_data_t *game)
{
    sfTime time = sfClock_getElapsedTime(game->player->clock);
    map_id_t map_id = game->map.id;

    if (is_key_pressed(game, Reset)) {
        map_id = (map_id + 1) % 3;
        set_map(game, map_id);
    }
    sfRenderWindow_setView(game->window, game->game_view);
    sfClock_restart(game->player->clock);
    update_player(game, time);
    check_gameplay_keys(game);
    display_map(game);
    display_player(game);
    display_enemies(game);
    display_npcs(game);
    display_entities(game);
    apply_shader(game);
    display_overlay(game);
    change_map_if_needed(game);
}
