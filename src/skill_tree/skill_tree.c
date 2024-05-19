/*
** EPITECH PROJECT, 2024
** B-MUL-200-PAR-2-1-myrpg-maxence.bunel [WSL: Ubuntu]
** File description:
** skill_tree
*/

#include "my_game.h"

static void draw_basic_texts(game_data_t *game, sfText *text,
    sfText *level_txt, sfText *pts_txt)
{
    sfRenderWindow_drawText(game->window, level_txt, NULL);
    sfRenderWindow_drawText(game->window, text, NULL);
    sfRenderWindow_drawText(game->window, pts_txt, NULL);
    sfText_destroy(text);
    sfText_destroy(level_txt);
    sfText_destroy(pts_txt);
}

static void draw_base_design(game_data_t *game)
{
    char *lvl = NULL;
    char *pts = NULL;
    sfText *text = set_text(game, "EXPERIENCE", 30, (sfVector2f){222, 162});
    sfText *level_txt = NULL;
    sfText *pts_txt = NULL;

    asprintf(&lvl, "LEVEL  %d", game->player->current_lvl);
    asprintf(&pts, "AVAILABLE SKILL POINTS : %d", game->player->skill_points);
    level_txt = game->player->current_lvl >= 10 ? set_text(game, lvl, 20,
    (sfVector2f){723, 167}) : set_text(game, lvl, 20, (sfVector2f){733, 167});
    pts_txt = set_text(game, pts, 25, (sfVector2f){1336, 172});
    sfRenderWindow_drawSprite(game->window,
        get_sprite(game, SP_MAIN_BG), NULL);
    sfRenderWindow_drawSprite(game->window,
        get_sprite(game, SP_TEXT_SKILL_TREE), NULL);
    draw_basic_texts(game, text, level_txt, pts_txt);
    free(lvl);
    free(pts);
}

void add_xp(game_data_t *game, int xp)
{
    int remaining_to_add = 0;

    if (game->player->current_lvl == 15)
        return;
    game->player->current_xp += xp;
    if (game->player->current_xp >=
    LEVELS[game->player->current_lvl - 1].xp_needed) {
        remaining_to_add = game->player->current_xp -
        LEVELS[game->player->current_lvl - 1].xp_needed;
        game->player->current_xp = remaining_to_add;
        game->player->skill_points +=
        LEVELS[game->player->current_lvl - 1].skill_points;
        game->player->current_lvl++;
    }
}

static void draw_progress_bar(game_data_t *game)
{
    sfRectangleShape *exp_bg = sfRectangleShape_create();
    sfRectangleShape *exp_bar = sfRectangleShape_create();
    int width = game->player->current_lvl == 15 ? 600 :
    game->player->current_xp * 600 /
    LEVELS[game->player->current_lvl - 1].xp_needed;

    sfRectangleShape_setPosition(exp_bg, (sfVector2f){223, 210});
    sfRectangleShape_setPosition(exp_bar, (sfVector2f){223, 210});
    sfRectangleShape_setSize(exp_bg, (sfVector2f){600, 10});
    sfRectangleShape_setSize(exp_bar, (sfVector2f){width, 10});
    sfRectangleShape_setFillColor(exp_bg, SQUARE_BG);
    sfRectangleShape_setFillColor(exp_bar, BORDER_HOVER);
    sfRenderWindow_drawRectangleShape(game->window, exp_bg, NULL);
    sfRenderWindow_drawRectangleShape(game->window, exp_bar, NULL);
    sfRectangleShape_destroy(exp_bg);
    sfRectangleShape_destroy(exp_bar);
}

void display_skill_tree(game_data_t *game)
{
    sfRectangleShape **grid = malloc(sizeof(sfRectangleShape *) * 12);
    sfRectangleShape **lines = malloc(sizeof(sfRectangleShape *) * 8);

    draw_base_design(game);
    draw_progress_bar(game);
    draw_squares(game, &grid);
    draw_lines(game, &lines);
    display_icons(game);
    handle_click_tree(game, grid);
    for (int i = 0; i < 12; i++)
        sfRectangleShape_destroy(grid[i]);
}
