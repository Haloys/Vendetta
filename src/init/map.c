/*
** EPITECH PROJECT, 2024
** Vendetta
** File description:
** Main
*/

#include <stdio.h>

#include "my_game.h"
#include "map.h"
#include "gameplay.h"

const map_config_t map_config[] = {
    {
        .map = SP_MAP_1,
        .cols_map = SP_COLS_MAP_1,
        .spawn_pos = {2195, 1669},
        .sp_map = NULL,
        .id = MAP_ONE,
        .portal = {3537, 1375, 3626, 1628}
    },
    {
        .map = SP_MAP_2,
        .cols_map = SP_COLS_MAP_2,
        .spawn_pos = {1566, 2157},
        .sp_map = NULL,
        .id = MAP_TWO,
        .portal = {1677, 1237, 1750, 1351}
    },
    {
        .map = SP_MAP_3,
        .cols_map = SP_COLS_MAP_3,
        .spawn_pos = {906, 2480},
        .sp_map = NULL,
        .id = MAP_THREE,
        .portal = {2989, 1139, 3100, 1259}
    }
};

bool is_in_portal(game_data_t *game)
{
    map_config_t map = game->map;
    sfVector2f pos = game->player->position;

    if (pos.x >= map.portal.x && pos.x <= map.portal.w
        && pos.y >= map.portal.y && pos.y <= map.portal.h)
        return true;
    return false;
}

int set_map(game_data_t *game, map_id_t map_id)
{
    map_config_t map = map_config[map_id];
    sfSprite *sp_cols_map = get_sprite(game, map.cols_map);

    printf("Setting map %d\n", map_id);
    game->map = map;
    game->map.sp_map = &SPRITES[map.map];
    game->player->position = map.spawn_pos;
    game->view_pos = map.spawn_pos;
    sfView_setCenter(game->game_view, game->player->position);
    if (sp_cols_map == NULL)
        return RET_FAIL;
    game->cols_map = sfTexture_copyToImage(sfSprite_getTexture(sp_cols_map));
    if (game->cols_map == NULL)
        return RET_FAIL;
    return RET_NONE;
}
