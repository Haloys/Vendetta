/*
** EPITECH PROJECT, 2024
** Vendetta
** File description:
** Initialize the game
*/

#include "my_game.h"
#include "my.h"

static int init_view(game_data_t *game)
{
    game->view_zoom = 1;
    game->target_zoom = 1;
    game->view = sfView_createFromRect(
        (sfFloatRect){0, 0, WINDOW_WIDTH, WINDOW_HEIGHT});
    if (game->view == NULL)
        return RET_FAIL;
    return RET_NONE;
}

static int init_map_pos(game_data_t *game)
{
    sfSprite *sp = get_sprite(game, SP_PLAYER_HAND);
    sfSprite *sp_cols_map = get_sprite(game, SP_COLS_MAP_1);
    sfVector2f pos = {0, 0};

    game->player->clock = sfClock_create();
    if (sp == NULL || sp_cols_map == NULL || game->player->clock == NULL)
        return RET_FAIL;
    pos = sfSprite_getPosition(sp);
    game->player->pspeed = PLAYER_MOVE_SPEED;
    game->player->direction = (sfVector2f){0, 0};
    game->player->position = pos;
    game->key_state = 0;
    game->key_change = 0;
    game->cols_map = sfTexture_copyToImage(sfSprite_getTexture(sp_cols_map));
    if (game->cols_map == NULL)
        return RET_FAIL;
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

static int init_inventory(game_data_t *game)
{
    game->player = malloc(sizeof(player_data_t));
    game->player->inventory = malloc(sizeof(inventory_t));
    if (game->player == NULL || game->player->inventory == NULL)
        return RET_FAIL;
    for (int i = 0; i < 29; i++) {
        game->player->inventory->slots[i].item = NULL;
        game->player->inventory->slots[i].quantity = 0;
        game->player->inventory->slots[i].weight = 0;
        game->player->inventory->slots[i].is_selected = false;
    }
    game->player->inventory->total_weight = 0;
    game->player->armor = 10;
    game->player->speed = 10;
    game->player->health = 10;
    game->player->attack = 10;
    game->player->max_health = 15;
    init_other_values(game);
    init_map_pos(game);
    game->map = SPRITES[SP_MAP_1];
    return RET_NONE;
}

static int init_partie_one(game_data_t *game)
{
    init_assets(game);
    if (init_inventory(game) == RET_FAIL || init_view(game) == RET_FAIL)
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

static void start_game_loop(game_data_t *game)
{
    while (sfRenderWindow_isOpen(game->window))
        process_game_loop(game);
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
