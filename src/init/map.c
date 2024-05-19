/*
** EPITECH PROJECT, 2024
** Vendetta
** File description:
** Main
*/

#include "my_game.h"
#include "map.h"

const map_config_t map_config[] = {
    {
        .map = SP_MAP_1,
        .cols_map = SP_COLS_MAP_1,
        .spawn_pos = {2195, 1669},
        .sp_map = NULL,
        .id = MAP_ONE
    },
    {
        .map = SP_MAP_2,
        .cols_map = SP_COLS_MAP_2,
        .spawn_pos = {1566, 2157},
        .sp_map = NULL,
        .id = MAP_TWO
    },
    {
        .map = SP_MAP_3,
        .cols_map = SP_COLS_MAP_3,
        .spawn_pos = {906, 2480},
        .sp_map = NULL,
        .id = MAP_THREE
    }
};

int set_map(game_data_t *game, map_id_t map_id)
{
    map_config_t map = map_config[map_id];
    sfSprite *sp_cols_map = get_sprite(game, map.cols_map);

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
