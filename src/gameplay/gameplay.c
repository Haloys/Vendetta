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

static void door_callback(game_data_t *game, int i)
{
    if (is_key_pressed(game, Interact) && i % 2 == 0) {
        change_game_mode(game, SEQUENCE_CLICK);
    }
    if (is_key_pressed(game, Interact) && i % 2 == 1) {
        change_game_mode(game, BARHIT);
    }
}

static void change_map_if_needed(game_data_t *game)
{
    map_id_t map_id = game->map.id;

    if (is_in_portal(game, &game->map.portal))
        set_map(game, (map_id + 1) % 3, NULL);
    if (is_in_portal(game, &game->map.back_portal))
        set_backmap(game, (map_id - 1) % 3);
    for (int i = 0; i < game->map.door_count; i++) {
        if (door_checker(game, &game->player->position,
            &game->map.doors[i].rect, game->map.doors[i].item)) {
            door_callback(game, i);
            return;
        }
    }
}

static void update_gameplay(game_data_t *game)
{
    sfTime time = sfClock_getElapsedTime(game->player->clock);

    sfClock_restart(game->player->clock);
    update_player(game, time);
    sfRenderTexture_setView(game->debug_overlay, game->game_view);
    sfRenderWindow_setView(game->window, game->game_view);
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

static void display_debug(game_data_t *game)
{
    sfRenderTexture *debug_overlay = game->debug_overlay;
    sfSprite *sp_debug_overlay = sfSprite_create();
    sfVector2u size = sfRenderTexture_getSize(game->debug_overlay);
    sfView *backup = sfView_copy(sfRenderWindow_getView(game->window));
    sfView *view = sfView_createFromRect((sfFloatRect){0, 0, size.x, size.y});

    if (debug_overlay == NULL || backup == NULL || view == NULL)
        return;
    sfRenderTexture_display(debug_overlay);
    sfSprite_setTexture(sp_debug_overlay,
        sfRenderTexture_getTexture(debug_overlay), sfTrue);
    sfRenderWindow_setView(game->window, view);
    sfRenderWindow_drawSprite(game->window, sp_debug_overlay, NULL);
    sfRenderWindow_setView(game->window, backup);
    sfView_destroy(view);
    sfView_destroy(backup);
    sfSprite_destroy(sp_debug_overlay);
}

static void display_gameplay(game_data_t *game)
{
    display_map(game);
    display_enemies(game);
    display_npcs(game);
    display_items(game);
    display_entities(game);
    display_player(game);
    display_bullets(game);
    apply_shader(game);
    display_debug(game);
    display_overlay(game);
    display_notifications(game, &game->notifications);
}

void process_playing_gameplay(game_data_t *game)
{
    update_gameplay(game);
    display_gameplay(game);
    for (int i = 0; i < game->map.door_count; i++) {
        draw_doors(game, &game->map.doors[i], &game->map.doors[i].rect);
    }
}

bool can_entity_pass(game_data_t *game, int new_x, int new_y)
{
    return (!(is_black_color(get_pixel_color(game->cols_map, new_x, new_y))
        || can_pass_door(game, new_x, new_y) == false));
}
