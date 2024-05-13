/*
** EPITECH PROJECT, 2024
** Vendetta / Inventory
** File description:
** Handle Drag And Drop
*/

#include "inventory.h"
#include "my_game.h"

static void compare_actions(game_data_t *game, int i, int is_dragging)
{
    if (i == 29 || i == 30) {
        use_or_trash(game, i, is_dragging);
    } else {
        swap_items(game, i, is_dragging);
    }
}

static void select_sprite(game_data_t *game, int *is_dragging,
    sfSprite **sprite, sfRectangleShape **grid)
{
    sfFloatRect rect = {0};
    sfVector2i pos = sfMouse_getPositionRenderWindow(game->window);

    for (size_t i = 0; i < 29; i++) {
        rect = sfRectangleShape_getGlobalBounds(grid[i]);
        if (sfFloatRect_contains(&rect, pos.x, pos.y) &&
        game->player_data->inventory->slots[i].item != NULL) {
            *is_dragging = i;
            *sprite = get_sprite(game,
                game->player_data->inventory->slots[i].item->sprite_id);
        }
    }
}

static void move_sprite(game_data_t *game, int is_dragging,
    sfRectangleShape **grid)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(game->window);
    sfFloatRect rect = {0};

    for (size_t i = 0; i < 31; i++) {
        rect = sfRectangleShape_getGlobalBounds(grid[i]);
        if (sfFloatRect_contains(&rect, pos.x, pos.y)) {
            compare_actions(game, i, is_dragging);
            calculate_player_stats(game);
            update_inventory_weight(game);
        }
    }
}

void handle_drag_and_drop(game_data_t *game, sfRectangleShape **grid)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(game->window);
    static int is_dragging = -1;
    static sfSprite *sprite = NULL;

    if (sfMouse_isButtonPressed(sfMouseLeft) && is_dragging == -1) {
        select_sprite(game, &is_dragging, &sprite, grid);
    }
    if (is_dragging > -1) {
        sfSprite_setPosition(sprite, (sfVector2f){pos.x - 25, pos.y - 25});
        sfRenderWindow_drawSprite(game->window, sprite, NULL);
    }
    if (!sfMouse_isButtonPressed(sfMouseLeft) && is_dragging > -1) {
        move_sprite(game, is_dragging, grid);
        sprite = NULL;
        is_dragging = -1;
    }
}
