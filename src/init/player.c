/*
** EPITECH PROJECT, 2024
** Vendetta
** File description:
** Main
*/

#include "my_game.h"

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

static void init_other_values(game_data_t *game)
{
    game->player->skill_tree = malloc(sizeof(skill_tree_t));
    game->player->skill_tree->armor_lvl = 0;
    game->player->skill_tree->attack_lvl = 0;
    game->player->skill_tree->health_lvl = 0;
    game->player->skill_tree->speed_lvl = 0;
    game->player->skill_points = 24;
    game->player->current_lvl = 15;
    game->player->current_xp = 0;
}

static int init_player_inventory(game_data_t *game)
{
    game->player->inventory = malloc(sizeof(inventory_t));
    if (game->player->inventory == NULL)
        return RET_FAIL;
    for (int i = 0; i < 29; i++) {
        game->player->inventory->slots[i].item = NULL;
        game->player->inventory->slots[i].quantity = 0;
        game->player->inventory->slots[i].weight = 0;
    }
    game->player->inventory->total_weight = 0;
    game->player->armor = 10;
    game->player->speed = 10;
    game->player->health = 10;
    game->player->attack = 10;
    game->player->max_health = 15;
    game->player->sprite_data = &SPRITES[SP_PLAYER_HAND];
    game->player->sprite = get_sprite(game, SP_PLAYER_HAND);
    game->player->clock = sfClock_create();
    game->player->anim_clock = sfClock_create();
    init_other_values(game);
    return RET_NONE;
}

int init_player(game_data_t *game)
{
    game->player = malloc(sizeof(player_data_t));
    if (game->player == NULL || init_player_inventory(game) == RET_FAIL)
        return RET_FAIL;
    init_map_pos(game);
    return RET_NONE;
}
