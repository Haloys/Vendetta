/*
** EPITECH PROJECT, 2024
** Vendetta
** File description:
** Process gameplay loop
*/

#include "my_game.h"
#include "map.h"

static void display_player(game_data_t *game)
{
    sfSprite *sp_player = get_sprite(game, SP_PLAYER_HAND);

    if (sp_player == NULL)
        return;
    sfSprite_setPosition(sp_player, game->player->position);
    sfSprite_setRotation(sp_player, game->player->rotation);
    sfRenderWindow_drawSprite(game->window, sp_player, NULL);
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
}
