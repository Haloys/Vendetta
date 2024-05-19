/*
** EPITECH PROJECT, 2024
** B-MUL-200-PAR-2-1-myrpg-maxence.bunel [WSL: Ubuntu]
** File description:
** spend_tree
*/

#include "my_game.h"

static int get_tree_level(game_data_t *game, int id)
{
    skill_tree_t *tree = game->player->skill_tree;

    if (id == 0)
        return tree->health_lvl;
    if (id == 1)
        return tree->armor_lvl;
    if (id == 2)
        return tree->speed_lvl;
    if (id == 3)
        return tree->attack_lvl;
    return 0;
}

static int calc_spending_2(game_data_t *game, int i)
{
    skill_tree_t *tree = game->player->skill_tree;

    if ((i == 2 && get_tree_level(game, 0) < 3) ||
    (i == 5 && get_tree_level(game, 1) < 3) ||
    (i == 8 && get_tree_level(game, 2) < 3) ||
    (i == 11 && get_tree_level(game, 3) < 3)) {
        if ((tree->health_lvl == 1 && i == 2) ||
        (tree->armor_lvl == 1 && i == 5) || (tree->speed_lvl == 1 && i == 8) ||
        (tree->attack_lvl == 1 && i == 11))
            return 5;
        if ((tree->health_lvl == 2 && i == 2) ||
        (tree->armor_lvl == 2 && i == 5) || (tree->speed_lvl == 2 && i == 8) ||
        (tree->attack_lvl == 2 && i == 11))
            return 3;
        return 6;
    }
    return 0;
}

static int calc_spending(game_data_t *game, int i)
{
    skill_tree_t *tree = game->player->skill_tree;

    if ((i == 0 && get_tree_level(game, 0) == 0) ||
    (i == 3 && get_tree_level(game, 1) == 0) ||
    (i == 6 && get_tree_level(game, 2) == 0) ||
    (i == 9 && get_tree_level(game, 3) == 0))
        return 1;
    if ((i == 1 && get_tree_level(game, 0) < 2) ||
    (i == 4 && get_tree_level(game, 1) < 2) ||
    (i == 7 && get_tree_level(game, 2) < 2) ||
    (i == 10 && get_tree_level(game, 3) < 2)) {
        if ((tree->health_lvl == 1 && i == 1) ||
        (tree->armor_lvl == 1 && i == 4) || (tree->speed_lvl == 1 && i == 7) ||
        (tree->attack_lvl == 1 && i == 10))
            return 2;
        return 3;
    }
    return calc_spending_2(game, i);
}

static void check_and_spend(game_data_t *game, int i)
{
    int how_much_to_spend = calc_spending(game, i);

    if (game->player->skill_points >= how_much_to_spend) {
        game->player->skill_points -= how_much_to_spend;
        if (i == 0 || i == 1 || i == 2)
            game->player->skill_tree->health_lvl = i + 1;
        if (i == 3 || i == 4 || i == 5)
            game->player->skill_tree->armor_lvl = (i - 3) + 1;
        if (i == 6 || i == 7 || i == 8)
            game->player->skill_tree->speed_lvl = (i - 6) + 1;
        if (i == 9 || i == 10 || i == 11)
            game->player->skill_tree->attack_lvl = (i - 9) + 1;
        calculate_player_stats(game);
    }
}

void handle_click_tree(game_data_t *game, sfRectangleShape **grid)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);
    sfFloatRect rect;

    for (int i = 0; i < 12; i++) {
        rect = sfRectangleShape_getGlobalBounds(grid[i]);
        if (sfFloatRect_contains(&rect, mouse.x, mouse.y) &&
        sfMouse_isButtonPressed(sfMouseLeft)) {
            check_and_spend(game, i);
        }
    }
}
