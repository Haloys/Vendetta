/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** my_radar project
*/

#include <stdlib.h>
#include "my_game.h"
#include "my.h"

static int init_inventory(game_data_t *game)
{
    game->player_data = malloc(sizeof(player_data_t));
    game->player_data->inventory = malloc(sizeof(inventory_t));
    if (game->player_data == NULL || game->player_data->inventory == NULL)
        return RET_FAIL;
    for (int i = 0; i < 29; i++) {
        game->player_data->inventory->slots[i].item = NULL;
        game->player_data->inventory->slots[i].quantity = 0;
        game->player_data->inventory->slots[i].weight = 0;
    }
    game->player_data->inventory->total_weight = 0;
    game->player_data->armor = 10;
    game->player_data->speed = 10;
    game->player_data->health = 10;
    game->player_data->attack = 10;
    game->player_data->max_health = 15;
    return RET_NONE;
}

static int init_partie_one(game_data_t *game)
{
    init_assets(game);
    if (init_inventory(game) == RET_FAIL)
        return RET_FAIL;
    my_putstr("OK !\n");
    my_putstr("Loading window\n");
    game->window =
        sfRenderWindow_create(game->video_mode, game->name,
        sfResize | sfClose, NULL);
    if (game->window == NULL)
        return RET_FAIL;
    my_putstr("OK !\n");
    game->pixels = malloc(sizeof(sfUint8) * game->video_mode.width *
        game->video_mode.height * 4);
    if (game->pixels == NULL)
        return RET_FAIL;
    return RET_NONE;
}

static void icon_loader(game_data_t *game)
{
    sfImage *icon = sfImage_createFromFile(ICON_PATH);
    unsigned int width = sfImage_getSize(icon).x;
    unsigned int height = sfImage_getSize(icon).y;
    const sfUint8 *pixels = sfImage_getPixelsPtr(icon);

    sfRenderWindow_setIcon(game->window, width, height, pixels);
    sfImage_destroy(icon);
}

int init_game(game_data_t *game)
{
    if (init_partie_one(game) == RET_FAIL)
        return destroy_game_data(game, RET_FAIL);
    sfRenderWindow_setFramerateLimit(game->window, WINDOW_FPS);
    icon_loader(game);
    my_putstr("Start game loop\n");
    start_game_loop(game);
    return destroy_game_data(game, RET_NONE);
}

void start_game_loop(game_data_t *game)
{
    while (sfRenderWindow_isOpen(game->window))
        process_game_loop(game);
}
