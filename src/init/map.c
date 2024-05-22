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
            {.rect = {2144, 890, 2123, 992}},
            {.rect = {1073, 852, 1092, 751}},
            {.rect = {2911, 1385, 2895, 1628}}
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
            {.rect = {1775, 1345, 1795, 1240}},
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
            {.rect = {2071, 960, 2055, 1064}},
            {.rect = {2086, 1494, 2185, 1515}},
            {.rect = {2993, 1076, 3097, 1093}}
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

int set_map(game_data_t *game, map_id_t map_id)
{
    map_config_t map = map_config[map_id];
    sfSprite *sp_cols_map = get_sprite(game, map.cols_map);

    if (game->map.id != map_id)
        trigger_notification(game, 1);
    printf("Setting map %d\n", map_id);
    sfMusic_stop(game->assets.music[game->map.music]);
    game->map = map;
    game->map.sp_map = &SPRITES[map.map];
    game->player->position = map.spawn_pos;
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
