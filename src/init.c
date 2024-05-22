/*
** EPITECH PROJECT, 2024
** Vendetta
** File description:
** Initialize the game
*/

#include <stdio.h>

#include "my_game.h"
#include "init_game.h"
#include "map.h"
#include "utils.h"
#include "path_finding.h"

static void init_parts(game_data_t *game)
{
    init_enemies(game);
    init_bullets(game);
    init_npcs(game);
    init_items(game);
    init_keybinds(game);
    init_path_finding(game);
}

static int init_partie_one(game_data_t *game)
{
    init_assets(game);
    if (init_player(game) == RET_FAIL || init_menu_view(game) == RET_FAIL
        || init_game_view(game) == RET_FAIL)
        return RET_FAIL;
    dprintf(1, "OK !\n");
    dprintf(1, "Loading window\n");
    game->window =
        sfRenderWindow_create(game->video_mode, game->name,
        sfResize | sfClose, NULL);
    if (game->window == NULL)
        return RET_FAIL;
    dprintf(1, "OK !\n");
    if (set_map(game, MAP_ONE) == RET_FAIL)
        return RET_FAIL;
    game->animation_clock = sfClock_create();
    init_parts(game);
    return RET_NONE;
}

static void start_game_loop(game_data_t *game)
{
    while (sfRenderWindow_isOpen(game->window))
        process_game_loop(game);
}

static int save_data(game_data_t *game)
{
    FILE *file = fopen("database/player.ven", "w");

    printf("Saving data\n");
    if (file == NULL)
        return RET_FAIL;
    fprintf(file, "player_pos %f %f\n", game->player->position.x,
        game->player->position.y);
    fprintf(file, "player_health %d\n", game->player->health);
    fprintf(file, "player_max_health %d\n", game->player->max_health);
    fprintf(file, "player_attack %d\n", game->player->attack);
    fprintf(file, "player_speed %d\n", game->player->speed);
    fprintf(file, "map_id %d\n", game->map.id);
    fclose(file);
    return RET_NONE;
}

static int open_save(game_data_t *game)
{
    FILE *file = fopen("player.ven", "r");

    if (file == NULL)
        return RET_FAIL;
    fscanf(file, "map_id %d\n", (int *)&(game->map.id));
    set_map(game, game->map.id);
    fscanf(file, "player_pos %f %f\n", &(game->player->position.x),
        &(game->player->position.y));
    fscanf(file, "player_health %d\n", &(game->player->health));
    fscanf(file, "player_max_health %d\n", &(game->player->max_health));
    fscanf(file, "player_attack %d\n", &(game->player->attack));
    fscanf(file, "player_speed %d\n", &(game->player->speed));
    fclose(file);
    return RET_NONE;
}

int init_game(game_data_t *game)
{
    if (init_partie_one(game) == RET_FAIL)
        return destroy_game_data(game, RET_FAIL);
    sfRenderWindow_setFramerateLimit(game->window, game->fps);
    icon_loader(game);
    open_save(game);
    dprintf(1, "Start game loop\n");
    start_game_loop(game);
    dprintf(1, "Game loop ended\n");
    save_data(game);
    return destroy_game_data(game, RET_NONE);
}
