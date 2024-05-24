/*
** EPITECH PROJECT, 2024
** Vendetta
** File description:
** Main
*/

#include "my_game.h"
#include "gameplay.h"

static int init_map_pos(game_data_t *game)
{
    sfSprite *sp = get_sprite(game, SP_PLAYER_HAND);

    if (sp == NULL || game->player->clock == NULL)
        return RET_FAIL;
    game->player->pspeed = PLAYER_MOVE_SPEED;
    game->player->direction = (sfVector2f){0, 0};
    game->key_state = 0;
    game->key_change = 0;
    game->key_update = 0;
    return RET_NONE;
}

static void init_other_values(player_data_t *player)
{
    player->save_number = -1;
    player->skill_tree = malloc(sizeof(skill_tree_t));
    if (player->skill_tree == NULL)
        return;
    player->skill_tree->armor_lvl = 0;
    player->skill_tree->attack_lvl = 0;
    player->skill_tree->health_lvl = 0;
    player->skill_tree->speed_lvl = 0;
    player->skill_points = 0;
    player->current_lvl = 1;
    player->current_xp = 0;
    for (int i = 0; i < 29; i++) {
        player->inventory->slots[i].item = NULL;
        player->inventory->slots[i].quantity = 0;
        player->inventory->slots[i].weight = 0;
        player->inventory->slots[i].is_selected = false;
    }
    player->is_playing = false;
    player->path = NULL;
    player->target_rot = 0;
}

static int init_player_inventory(game_data_t *game, player_data_t *player)
{
    player->inventory = malloc(sizeof(inventory_t));
    if (player->inventory == NULL)
        return RET_FAIL;
    player->inventory->total_weight = 0;
    player->armor = 10;
    player->speed = 10;
    player->health = 40;
    player->attack = 10;
    player->max_health = 40;
    player->sprite_data = &SPRITES[SP_PLAYER_HAND];
    player->sprite = get_sprite(game, SP_PLAYER_HAND);
    player->clock = sfClock_create();
    player->anim_clock = sfClock_create();
    player->rotation = 0;
    init_other_values(player);
    return RET_NONE;
}

int init_player(game_data_t *game)
{
    game->player = malloc(sizeof(player_data_t));
    if (game->player == NULL
        || init_player_inventory(game, game->player) == RET_FAIL)
        return RET_FAIL;
    init_map_pos(game);
    return RET_NONE;
}
