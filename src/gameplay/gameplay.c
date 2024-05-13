/*
** EPITECH PROJECT, 2024
** Vendetta
** File description:
** Process gameplay loop
*/

#include "my_game.h"

void display_player(game_data_t *game)
{
    const sfSprite *player = get_sprite(game, SP_PLAYER_HAND);

    sfRenderWindow_drawSprite(game->window, player, NULL);
}

void process_playing_gameplay(game_data_t *game)
{
    const sfSprite *map = get_sprite(game, SP_MAP_1);

    sfRenderWindow_drawSprite(game->window, map, NULL);
    display_player(game);
}
