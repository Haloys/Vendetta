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

static void check_gameplay_keys(game_data_t *game)
{
    if (is_key_pressed(game, Inventory) || is_key_pressed(game, Echap))
        change_game_mode(game, INVENTORY);
    if (is_key_pressed(game, Hostile))
        game->is_passive = !game->is_passive;
}

static void change_map_if_needed(game_data_t *game)
{
    map_id_t map_id = game->map.id;

    if (is_in_portal(game, &game->map.portal))
        set_map(game, (map_id + 1) % 3);
    if (is_in_portal(game, &game->map.back_portal))
        set_backmap(game, (map_id - 1) % 3);
    for (int i = 0; i < game->map.door_count; i++) {
        if (door_checker(game, &game->map.doors[i].rect))
            game->player->health--;
    }
}

static void update_gameplay(game_data_t *game)
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
    update_notifications(&game->notifications);
    change_map_if_needed(game);
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

static void display_gameplay(game_data_t *game)
{
    display_map(game);
    display_enemies(game);
    display_npcs(game);
    display_entities(game);
    display_player(game);
    display_bullets(game);
    if (game->map.id == MAP_ONE)
        display_paths(game);
    apply_shader(game);
    display_overlay(game);
    display_notifications(game, &game->notifications);
}

void process_playing_gameplay(game_data_t *game)
{
    update_gameplay(game);
    display_gameplay(game);
}
