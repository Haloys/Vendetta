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
        .spawn_pos_back = {3386, 1497},
        .sp_map = NULL,
        .id = MAP_ONE,
        .portal = {3537, 1375, 3626, 1628},
        .back_portal = {0, 0, 0, 0},
        .music = M_FIRST_MAP,
        .door_count = 4,
        .doors = {
            {.rect = {1730, 1634, 1837, 1659}},
            {.rect = {2114, 883, 2146, 994}},
            {.rect = {1075, 750, 1092, 856}},
            {.rect = {2893, 1385, 2916, 1622}}
        }
    },
    {
        .map = SP_MAP_2,
        .cols_map = SP_COLS_MAP_2,
        .spawn_pos = {1539, 2028},
        .spawn_pos_back = {1831, 1293},
        .sp_map = NULL,
        .id = MAP_TWO,
        .portal = {1677, 1237, 1750, 1351},
        .back_portal = {1418, 2102, 1711, 2157},
        .music = M_SECOND_MAP,
        .door_count = 1,
        .doors = {
            {.rect = {1775, 1246, 1793, 1343}},
        }
    },
    {
        .map = SP_MAP_3,
        .cols_map = SP_COLS_MAP_3,
        .spawn_pos = {940, 2380},
        .spawn_pos_back = {0, 0},
        .sp_map = NULL,
        .id = MAP_THREE,
        .portal = {2989, 1139, 3100, 1259},
        .back_portal = {687, 2445, 1138, 2507},
        .music = M_THIRD_MAP,
        .door_count = 3,
        .doors = {
            {.rect = {2053, 962, 2078, 1063}},
            {.rect = {2089, 1496, 2182, 1518}},
            {.rect = {2992, 1074, 3095, 1100}}
        }
    }
};

bool is_in_portal(game_data_t *game, rect_t *portal)
{
    sfVector2f pos = game->player->position;

    if (pos.x >= portal->x && pos.x <= portal->w
        && pos.y >= portal->y && pos.y <= portal->h)
        return true;
    return false;
}

bool door_checker(game_data_t *game, rect_t *door)
{
    sfVector2f pos = game->player->position;

    if (pos.x >= door->x && pos.x <= door->w
        && pos.y >= door->y && pos.y <= door->h)
        return true;
    return false;
}

int set_map(game_data_t *game, map_id_t map_id, sfVector2f *pos)
{
    map_config_t map = map_config[map_id];
    sfSprite *sp_cols_map = get_sprite(game, map.cols_map);

    if (game->map.id != map_id)
        trigger_notification(game, 1);
    printf("Setting map %d\n", map_id);
    sfMusic_stop(game->assets.music[game->map.music]);
    game->map = map;
    game->map.sp_map = &SPRITES[map.map];
    game->player->position = pos != NULL ? *pos : map.spawn_pos;
    game->view_pos = map.spawn_pos;
    sfView_setCenter(game->game_view, game->player->position);
    start_music(&game->assets, map.music);
    update_music_volumes(game);
    if (sp_cols_map == NULL)
        return RET_FAIL;
    game->cols_map = sfTexture_copyToImage(sfSprite_getTexture(sp_cols_map));
    if (game->cols_map == NULL)
        return RET_FAIL;
    return RET_NONE;
}

int set_backmap(game_data_t *game, map_id_t map_id)
{
    map_config_t map = map_config[map_id];
    sfSprite *sp_cols_map = get_sprite(game, map.cols_map);

    printf("Setting map %d\n", map_id);
    sfMusic_stop(game->assets.music[game->map.music]);
    game->map = map;
    game->map.sp_map = &SPRITES[map.map];
    game->player->position = map.spawn_pos_back;
    game->view_pos = map.spawn_pos_back;
    sfView_setCenter(game->game_view, game->player->position);
    start_music(&game->assets, map.music);
    update_music_volumes(game);
    if (sp_cols_map == NULL)
        return RET_FAIL;
    game->cols_map = sfTexture_copyToImage(sfSprite_getTexture(sp_cols_map));
    if (game->cols_map == NULL)
        return RET_FAIL;
    return RET_NONE;
}
