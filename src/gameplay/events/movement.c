/*
** EPITECH PROJECT, 2024
** Vendetta
** File description:
** Process player events
*/

#include "my_game.h"
#include "gameplay.h"

static void process_key_left(game_data_t *game, sfSprite *sp, sfSprite *sp_map)
{
    sfVector2f pos = sfSprite_getPosition(sp);
    sfVector2f pos_map = sfSprite_getPosition(sp_map);

    if (game->player_data->pos_offset.x > 0
        || game->player_data->map_pos.x <= VIEW_WIDTH) {
        sfSprite_setPosition(sp, (sfVector2f){pos.x - 10, pos.y});
        game->player_data->pos_offset.x -= 10;
    } else {
        sfSprite_setPosition(sp_map, (sfVector2f){pos_map.x + 10, pos_map.y});
    }
    sfSprite_setRotation(sp, 180);
    game->player_data->map_pos.x -= 10;
}

static void process_key_right(game_data_t *game, sfSprite *sp,
    sfSprite *sp_map)
{
    sfVector2f pos = sfSprite_getPosition(sp);
    sfVector2f pos_map = sfSprite_getPosition(sp_map);

    if (game->player_data->pos_offset.x < 0
        || game->player_data->map_pos.x + VIEW_WIDTH >= 3640) {
        sfSprite_setPosition(sp, (sfVector2f){pos.x + 10, pos.y});
        game->player_data->pos_offset.x += 10;
    } else
        sfSprite_setPosition(sp_map, (sfVector2f){pos_map.x - 10, pos_map.y});
    sfSprite_setRotation(sp, 0);
    game->player_data->map_pos.x += 10;
}

static void process_key_up(game_data_t *game, sfSprite *sp, sfSprite *sp_map)
{
    sfVector2f pos = sfSprite_getPosition(sp);
    sfVector2f pos_map = sfSprite_getPosition(sp_map);

    if (game->player_data->pos_offset.y > 0
        || game->player_data->map_pos.y <= VIEW_HEIGHT) {
        sfSprite_setPosition(sp, (sfVector2f){pos.x, pos.y - 10});
        game->player_data->pos_offset.y -= 10;
    } else {
        sfSprite_setPosition(sp_map, (sfVector2f){pos_map.x, pos_map.y + 10});
    }
    game->player_data->map_pos.y -= 10;
    sfSprite_setRotation(sp, 270);
}

static void process_key_down(game_data_t *game, sfSprite *sp, sfSprite *sp_map)
{
    sfVector2f pos = sfSprite_getPosition(sp);
    sfVector2f pos_map = sfSprite_getPosition(sp_map);

    if (game->player_data->pos_offset.y < 0
        || game->player_data->map_pos.y + VIEW_HEIGHT >= 2660) {
        sfSprite_setPosition(sp, (sfVector2f){pos.x, pos.y + 10});
        game->player_data->pos_offset.y += 10;
    } else {
        sfSprite_setPosition(sp_map, (sfVector2f){pos_map.x, pos_map.y - 10});
    }
    game->player_data->map_pos.y += 10;
    sfSprite_setRotation(sp, 90);
}

void process_player_movement(game_data_t *game, sfKeyEvent *key)
{
    sfSprite *sp = get_sprite(game, SP_PLAYER_HAND);
    sfSprite *sp_map = get_sprite(game, SP_MAP_1);
    sfVector2f pos = sfSprite_getPosition(sp);
    sfVector2f pos_map = sfSprite_getPosition(sp_map);

    printf("offset x = %f, offset y = %f\n", game->player_data->pos_offset.x,
        game->player_data->pos_offset.y);
    if (key->code == sfKeyLeft)
        process_key_left(game, sp, sp_map);
    if (key->code == sfKeyRight)
        process_key_right(game, sp, sp_map);
    if (key->code == sfKeyUp)
        process_key_up(game, sp, sp_map);
    if (key->code == sfKeyDown)
        process_key_down(game, sp, sp_map);
    printf("pos.x = %f, pos.y = %f | pos_map.x = %f, pos_map.y = %f "
        "| map_pos.x = %f, map_pos.y = %f\n\n", pos.x, pos.y, pos_map.x,
    pos_map.y, game->player_data->map_pos.x, game->player_data->map_pos.y);
}
