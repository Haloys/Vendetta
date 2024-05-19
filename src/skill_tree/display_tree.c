/*
** EPITECH PROJECT, 2024
** B-MUL-200-PAR-2-1-myrpg-maxence.bunel [WSL: Ubuntu]
** File description:
** display_tree
*/

#include "my_game.h"

static void mod_col(skill_tree_t *tree, sfRectangleShape *square, int val)
{
    if ((tree->health_lvl >= 1 && val == 0) || (tree->health_lvl >= 2 &&
    val == 1) || (tree->health_lvl >= 3 && val == 2))
        sfRectangleShape_setOutlineColor(square, RED);
    if ((tree->armor_lvl >= 1 && val == 3) || (tree->armor_lvl >= 2 &&
    val == 4) || (tree->armor_lvl >= 3 && val == 5))
        sfRectangleShape_setOutlineColor(square, BLUE);
    if ((tree->speed_lvl >= 1 && val == 6) || (tree->speed_lvl >= 2 &&
    val == 7) || (tree->speed_lvl >= 3 && val == 8))
        sfRectangleShape_setOutlineColor(square, YELLOW);
    if ((tree->attack_lvl >= 1 && val == 9) || (tree->attack_lvl >= 2 &&
    val == 10) || (tree->attack_lvl >= 3 && val == 11))
        sfRectangleShape_setOutlineColor(square, GREEN);
}

static void handle_hover_tree(sfRectangleShape *square, sfVector2i mouse,
    int val)
{
    sfFloatRect rect = sfRectangleShape_getGlobalBounds(square);
    sfColor color;

    color = BORDER;
    if (sfFloatRect_contains(&rect, mouse.x, mouse.y)) {
        sfRectangleShape_setOutlineThickness(square, 2);
        if (val < 3)
            color = RED;
        if (val < 6 && val > 2)
            color = BLUE;
        if (val < 9 && val > 5)
            color = YELLOW;
        if (val < 12 && val > 8)
            color = GREEN;
    }
    sfRectangleShape_setOutlineColor(square, color);
}

void draw_squares(game_data_t *game, sfRectangleShape ***grid)
{
    sfVector2f pos = {205, 415};
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            (*grid)[i * 3 + j] = sfRectangleShape_create();
            sfRectangleShape_setPosition((*grid)[i * 3 + j],
            (sfVector2f){pos.x + i * (SIZE + 340), pos.y + j * (SIZE + 80)});
            sfRectangleShape_setSize((*grid)[i * 3 + j], (sfVector2f) {
                140, 140
            });
            sfRectangleShape_setOutlineThickness((*grid)[i * 3 + j], 2);
            sfRectangleShape_setFillColor((*grid)[i * 3 + j], SQUARE_BG);
            handle_hover_tree((*grid)[i * 3 + j], mouse, i * 3 + j);
            mod_col(game->player->skill_tree, (*grid)[i * 3 + j], i * 3 + j);
            sfRenderWindow_drawRectangleShape(game->window,
                (*grid)[i * 3 + j], NULL);
        }
    }
}

static void change_color(skill_tree_t *tree, sfRectangleShape *line, int val)
{
    sfRectangleShape_setFillColor(line, BORDER);
    if ((tree->health_lvl >= 2 && val == 0) || (tree->health_lvl >= 3 &&
    val == 4))
        sfRectangleShape_setFillColor(line, RED);
    if ((tree->armor_lvl >= 2 && val == 1) || (tree->armor_lvl >= 3 &&
    val == 5))
        sfRectangleShape_setFillColor(line, BLUE);
    if ((tree->speed_lvl >= 2 && val == 2) || (tree->speed_lvl >= 3 &&
    val == 6))
        sfRectangleShape_setFillColor(line, YELLOW);
    if ((tree->attack_lvl >= 2 && val == 3) || (tree->attack_lvl >= 3 &&
    val == 7))
        sfRectangleShape_setFillColor(line, GREEN);
}

void draw_lines(game_data_t *game, sfRectangleShape ***lines)
{
    sfVector2f pos = {275, 557};
    sfVector2f pos2 = {275, 747};

    for (int i = 0; i < 8; i++) {
        (*lines)[i] = sfRectangleShape_create();
        if (i < 4)
            sfRectangleShape_setPosition((*lines)[i],
            (sfVector2f){pos.x + i * 450, pos.y});
        else
            sfRectangleShape_setPosition((*lines)[i],
            (sfVector2f){pos2.x + (i - 4) * 450, pos2.y});
        sfRectangleShape_setSize((*lines)[i], (sfVector2f) {2, 46});
        change_color(game->player->skill_tree, (*lines)[i], i);
        sfRenderWindow_drawRectangleShape(game->window, (*lines)[i], NULL);
    }
}

static void display_icons_sprites_2(game_data_t *game, skill_tree_t *tree,
    sfVector2f pos, int i)
{
    if ((i == 6 || i == 7 || i == 8)) {
        pos.y += 1;
        sfSprite_setPosition(get_sprite(game, tree->speed_lvl >= (i - 6) + 1 ?
        SP_SPEED_COL : SP_SPEED_GRAY), pos);
        sfRenderWindow_drawSprite(game->window, get_sprite(game,
        tree->speed_lvl >= (i - 6) + 1 ? SP_SPEED_COL : SP_SPEED_GRAY), NULL);
    }
    if ((i == 9 || i == 10 || i == 11)) {
        pos.x -= 10;
        pos.y += 16;
        sfSprite_setPosition(get_sprite(game, tree->attack_lvl >= (i - 9) + 1 ?
        SP_ATTACK_COL : SP_ATTACK_GRAY), pos);
        sfRenderWindow_drawSprite(game->window, get_sprite(game,
        tree->attack_lvl >= (i - 9) + 1 ?
        SP_ATTACK_COL : SP_ATTACK_GRAY), NULL);
    }
}

static void display_icons_sprites(game_data_t *game, skill_tree_t *tree,
    sfVector2f pos, int i)
{
    if ((i == 0 || i == 1 || i == 2)) {
        sfSprite_setPosition(get_sprite(game, tree->health_lvl >= i + 1 ?
        SP_HEALTH_COL : SP_HEALTH_GRAY), pos);
        sfRenderWindow_drawSprite(game->window, get_sprite(game,
        tree->health_lvl >= i + 1 ? SP_HEALTH_COL : SP_HEALTH_GRAY), NULL);
    }
    if ((i == 3 || i == 4 || i == 5)) {
        sfSprite_setPosition(get_sprite(game, tree->armor_lvl >= (i - 3) + 1 ?
        SP_ARMOR_COL : SP_ARMOR_GRAY), pos);
        sfRenderWindow_drawSprite(game->window, get_sprite(game,
        tree->armor_lvl >= (i - 3) + 1 ? SP_ARMOR_COL : SP_ARMOR_GRAY), NULL);
    }
    display_icons_sprites_2(game, tree, pos, i);
}

void display_icons(game_data_t *game)
{
    sfVector2f pos = {245, 455};

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            pos = (sfVector2f){241 + i * (SIZE + 345), 450 + j * (SIZE + 80)};
            display_icons_sprites(game, game->player->skill_tree,
            pos, i * 3 + j);
        }
    }
}
