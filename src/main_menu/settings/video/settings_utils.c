/*
** EPITECH PROJECT, 2024
** Vendetta / Main Menu / Settings
** File description:
** Settings Utils
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "my_game.h"
#include "gameplay.h"

static void draw_rect_reso(game_data_t *game, sfRectangleShape *rect, int i)
{
    if (i == game->settings.clicked_rect) {
        sfRectangleShape_setFillColor(rect,
            sfColor_fromRGBA(255, 255, 255, 20));
        sfRectangleShape_setOutlineThickness(rect, 2);
        sfRectangleShape_setOutlineColor(rect,
            sfColor_fromRGB(51, 217, 122));
    } else {
        sfRectangleShape_setFillColor(rect,
            sfColor_fromRGBA(255, 255, 255, 0));
    }
    sfRenderWindow_drawRectangleShape(game->window, rect, NULL);
    sfRectangleShape_destroy(rect);
}

void draw_reso_rectangle(game_data_t *game)
{
    sfRectangleShape *rect;
    sfVector2f rectangle_pos = {106, 260};
    sfVector2f rectangle_size = {664, 52};
    int nbr_rect = 3;

    for (int i = 0; i < nbr_rect; i++) {
        rect = sfRectangleShape_create();
        if (i > 0)
            rectangle_pos.y += 61;
        sfRectangleShape_setPosition(rect, rectangle_pos);
        sfRectangleShape_setSize(rect, rectangle_size);
        draw_rect_reso(game, rect, i);
    }
}

void set_utils_text(game_data_t *game)
{
    sfVector2f text_pos1 = {132, 272};
    sfVector2f text_pos2 = {132, 333};
    sfVector2f text_pos3 = {132, 394};
    sfText *text1;
    sfText *text2;
    sfText *text3;

    text1 = set_text(game, "Frames per second", 22, text_pos1);
    text2 = set_text(game, "Render resolution", 22, text_pos2);
    text3 = set_text(game, "Window mode", 22, text_pos3);
    sfRenderWindow_drawText(game->window, text1, NULL);
    sfRenderWindow_drawText(game->window, text2, NULL);
    sfRenderWindow_drawText(game->window, text3, NULL);
    sfText_destroy(text1);
    sfText_destroy(text2);
    sfText_destroy(text3);
    draw_reso_rectangle(game);
}

static void modify_parameters(game_data_t *game)
{
    if ((is_key_pressed(game, ArrowLeft) || is_key_pressed(game, ArrowRight))
        && game->settings.clicked_rect == 1 && game->state == SETTINGS_VIDEO
        && !game->settings.is_fullscreen) {
        if (game->video_mode.width == 1920) {
            game->video_mode = (sfVideoMode){1366, 768, 32};
        } else if (game->video_mode.width == 1600) {
            game->video_mode = (sfVideoMode){1920, 1080, 32};
        } else {
            game->video_mode = (sfVideoMode){1600, 900, 32};
        }
        sfRenderWindow_setSize(game->window, (sfVector2u){
            game->video_mode.width, game->video_mode.height
        });
    }
    if ((is_key_pressed(game, ArrowLeft) || is_key_pressed(game, ArrowRight))
        && game->settings.clicked_rect == 2
        && game->state == SETTINGS_VIDEO) {
        set_reso(game);
    }
}

void modify_screen(game_data_t *game)
{
    if (is_key_pressed(game, ArrowDown) && game->state == SETTINGS_VIDEO) {
        game->settings.clicked_rect++;
        game->settings.clicked_rect %= 3;
    }
    if (is_key_pressed(game, ArrowUp) && game->state == SETTINGS_VIDEO) {
        game->settings.clicked_rect--;
        if (game->settings.clicked_rect < 0)
            game->settings.clicked_rect = 2;
        game->settings.clicked_rect %= 3;
    }
    if (is_key_pressed(game, ArrowLeft) && game->settings.clicked_rect == 0
        && game->state == SETTINGS_VIDEO)
            game->fps -= 30;
    if (is_key_pressed(game, ArrowRight) && game->settings.clicked_rect == 0
        && game->state == SETTINGS_VIDEO)
            game->fps += 30;
    game->fps = CLAMP(game->fps, 30, 120);
    modify_parameters(game);
}
