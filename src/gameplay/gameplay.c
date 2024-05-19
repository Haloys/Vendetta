/*
** EPITECH PROJECT, 2024
** Vendetta
** File description:
** Process gameplay loop
*/

#include "my_game.h"
#include "map.h"
#include "enemies.h"
#include "player.h"
#include "gameplay.h"

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
    display_map(game);
    display_player(game);
    display_enemies(game);
}
