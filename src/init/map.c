/*
** EPITECH PROJECT, 2024
** Vendetta
** File description:
** Main
*/

#include <stdio.h>
#include <string.h>

#include "my_game.h"
#include "map.h"
#include "gameplay.h"
#include "setup_notifications.h"

const map_config_t map_config[] = {
    {
        .map = SP_MAP_1,
        .cols_map = SP_COLS_MAP_1,
        .spawn_pos = {2202, 1404},
        .spawn_pos_back = {3386, 1497},
        .sp_map = NULL,
        .id = MAP_ONE,
        .portal = {3537, 1375, 3626, 1628},
        .back_portal = {0, 0, 0, 0},
        .music = M_FIRST_MAP,
        .zoom = {
            {
                .zone = {1644, 1645, 1883, 1838},
                .min = 0.3,
                .max = 0.3,
                .pos = {1770, 1735}
            },
            {
                .zone = {415, 1573, 734, 1985},
                .min = 0.4,
                .max = 0.4,
                .pos = {645, 1800}
            },
            {
                .zone = {256, 600, 1081, 937},
                .min = 0.4,
                .max = 0.4,
                .pos = {810, 770}
            },
            {
                .zone = {2156, 565, 2900, 1281},
                .min = 0.5,
                .max = 0.5,
                .pos = {0, 0}
            },
            {
                .zone = {726, 957, 1088, 1211},
                .min = 0.5,
                .max = 0.5,
                .pos = {915, 1079}
            },
            {
                .zone = {2283, 1513, 2552, 1858},
                .min = 0.5,
                .max = 0.5,
                .pos = {2409, 1699}
            }
        },
        .zoom_count = 6,
        .door_count = 4,
        .doors = {
            {.rect = {1730, 1634, 1837, 1659}, .item = "keya"},
            {.rect = {2114, 883, 2146, 994}, .item = "keyc"},
            {.rect = {1075, 750, 1092, 856}, .item = "keyb"},
            {.rect = {2893, 1385, 2916, 1622}, .item = "keyc"}
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
        .zoom = {{}},
        .zoom_count = 0,
        .door_count = 1,
        .doors = {
            {.rect = {1775, 1246, 1793, 1343}, .item = "keyc"},
        }
    },
    {
        .map = SP_MAP_3,
        .cols_map = SP_COLS_MAP_3,
        .spawn_pos = {940, 2380},
        .spawn_pos_back = {0, 0},
        .sp_map = NULL,
        .id = MAP_THREE,
        .portal = {0, 0, 0, 0},
        .back_portal = {687, 2445, 1138, 2507},
        .music = M_THIRD_MAP,
        .zoom = {
            {
                .zone = {631, 1292, 1693, 2505},
                .min = 0.5,
                .max = 0.5,
                .pos = {0, 0}
            },
            {
                .zone = {2069, 878, 2761, 1490},
                .min = 0.5,
                .max = 0.5,
                .pos = {0, 0}
            },
            {
                .zone = {1857, 1158, 2276, 1500},
                .min = 0.5,
                .max = 0.5,
                .pos = {0, 0}
            },
            {
                .zone = {2906, 1084, 3186, 1366},
                .min = 0.5,
                .max = 0.5,
                .pos = {0, 0}
            }
        },
        .zoom_count = 4,
        .door_count = 3,
        .doors = {
            {.rect = {2053, 962, 2078, 1063}, .item = "keya"},
            {.rect = {2089, 1496, 2182, 1518}, .item = "keyb"},
            {.rect = {2992, 1074, 3095, 1100}, .item = "keyc"}
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

static void handle_map_unlock_notifications(game_data_t *game, map_id_t map_id)
{
    if (!game->map_unlocked[map_id]) {
        switch (map_id) {
            case MAP_ONE:
                trigger_notification(game, 23);
                break;
            case MAP_TWO:
                trigger_notification(game, 21);
                break;
            case MAP_THREE:
                trigger_notification(game, 22);
                break;
        }
        game->map_unlocked[map_id] = true;
    }
}

bool door_checker(game_data_t *game, sfVector2f *pos, rect_t *door, char *item)
{
    if (pos->x >= door->x && pos->x <= door->w
        && pos->y >= door->y && pos->y <= door->h
        && get_item_quantity(game, item) > 0) {
        return true;
    }
    return false;
}

static int set_map_data(game_data_t *game, map_id_t map_id)
{
    map_config_t map = map_config[map_id];
    sfSprite *sp_cols_map = get_sprite(game, map.cols_map);

    if (game->map.id != map_id) {
        trigger_notification(game, 1);
        handle_map_unlock_notifications(game, map_id);
    }
    printf("Setting map %d\n", map_id);
    game->map = map;
    game->map.sp_map = &SPRITES[map.map];
    if (sp_cols_map == NULL)
        return RET_FAIL;
    game->cols_map = sfTexture_copyToImage(sfSprite_getTexture(sp_cols_map));
    if (game->cols_map == NULL)
        return RET_FAIL;
    return RET_NONE;
}

static void set_player_music_data(game_data_t *game, map_id_t map_id,
    sfVector2f *pos)
{
    map_config_t map = map_config[map_id];

    game->player->position = pos != NULL ? *pos : map.spawn_pos;
    game->view_pos = map.spawn_pos;
    sfView_setCenter(game->game_view, game->player->position);
    sfMusic_stop(game->assets.music[M_FIRST_MAP]);
    sfMusic_stop(game->assets.music[M_SECOND_MAP]);
    sfMusic_stop(game->assets.music[M_THIRD_MAP]);
    start_music(&game->assets, map.music);
    update_music_volumes(game);
}

static void trigger_notification_based_on_stage(game_data_t *game)
{
    switch (game->main_quest_stage) {
        case 1:
            trigger_notification(game, 24);
            break;
        case 2:
            trigger_notification(game, 25);
            break;
        case 3:
            trigger_notification(game, 26);
            break;
    }
}

void handle_main_notifications(game_data_t *game, map_id_t map_id)
{
    static const char *main_notif_titles[] = {
        "The start of a vendetta",
        "Finding the mysterious lady",
        "Your Vendetta"
    };

    for (int i = 0; i < 3; i++) {
        remove_notification_by_title(&game->notifications,
            main_notif_titles[i]);
    }
    if (map_id == MAP_TWO && game->main_quest_stage < 2) {
        game->main_quest_stage = 2;
    } else if (map_id == MAP_THREE && game->main_quest_stage < 3) {
        game->main_quest_stage = 3;
    }
    trigger_notification_based_on_stage(game);
}

int set_map(game_data_t *game, map_id_t map_id, sfVector2f *pos)
{
    int map_data_status = set_map_data(game, map_id);

    if (map_data_status != RET_NONE)
        return map_data_status;
    set_player_music_data(game, map_id, pos);
    handle_main_notifications(game, map_id);
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
    handle_main_notifications(game, map_id);
    return RET_NONE;
}
