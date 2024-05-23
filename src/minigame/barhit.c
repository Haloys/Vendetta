/*
** EPITECH PROJECT, 2024
** Vendetta / Minigame
** File description:
** Sequence Click
*/

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#include "my_game.h"
#include "utils.h"

static void init_rectangles(barhit_t *barhit)
{
    barhit->outer_rect = sfRectangleShape_create();
    sfRectangleShape_setSize(barhit->outer_rect, (sfVector2f)
        {RECT_WIDTH, RECT_HEIGHT});
    sfRectangleShape_setFillColor(barhit->outer_rect, FILL_COLOR);
    sfRectangleShape_setOutlineColor(barhit->outer_rect, OUTLINE_COLOR);
    sfRectangleShape_setOutlineThickness(barhit->outer_rect, 5);
    sfRectangleShape_setPosition(barhit->outer_rect, (sfVector2f)
        {(WINDOW_WIDTH - RECT_WIDTH) / 2, (WINDOW_HEIGHT - RECT_HEIGHT) / 2});
    barhit->inner_rect = sfRectangleShape_create();
    sfRectangleShape_setSize(barhit->inner_rect, (sfVector2f)
        {I_RECT_WIDTH, RECT_HEIGHT});
    sfRectangleShape_setFillColor(barhit->inner_rect, sfBlack);
    sfRectangleShape_setPosition(barhit->inner_rect, (sfVector2f){
        (WINDOW_WIDTH - I_RECT_WIDTH) / 2, (WINDOW_HEIGHT - RECT_HEIGHT) / 2});
    barhit->bar = sfRectangleShape_create();
    sfRectangleShape_setSize(barhit->bar, (sfVector2f)
        {BAR_WIDTH, RECT_HEIGHT});
    sfRectangleShape_setFillColor(barhit->bar, sfWhite);
    sfRectangleShape_setPosition(barhit->bar, (sfVector2f){
        (WINDOW_WIDTH - BAR_WIDTH) / 2, (WINDOW_HEIGHT - RECT_HEIGHT) / 2});
}

static void init_barhit(barhit_t *barhit)
{
    init_rectangles(barhit);
    barhit->bar_pos = (WINDOW_WIDTH - BAR_WIDTH) / 2;
    barhit->bar_direction = 1;
    barhit->game_active = true;
    barhit->cooldown = 0;
}

static void update_cooldown(barhit_t *barhit, float seconds)
{
    barhit->cooldown -= seconds;
    if (barhit->cooldown < 0) {
        barhit->cooldown = 0;
        barhit->game_active = true;
        printf("Cooldown terminé. Reprise du mouvement de la barre.\n");
    } else {
        printf("Cooldown: %.2f secondes restantes\n", barhit->cooldown);
    }
}

static bool check_key_press(barhit_t *barhit)
{
    sfVector2f bar_pos;
    sfVector2f inner_pos;

    if (sfKeyboard_isKeyPressed(sfKeyL)) {
        bar_pos = sfRectangleShape_getPosition(barhit->bar);
        inner_pos = sfRectangleShape_getPosition(barhit->inner_rect);
        if (bar_pos.x >= inner_pos.x && bar_pos.x <=
            inner_pos.x + I_RECT_WIDTH) {
            barhit->game_active = false;
            printf("Minigame réussi!\n");
            return true;
        } else {
            barhit->cooldown = COOLDOWN_TIME;
            barhit->game_active = false;
            printf("Barre en cooldown.\n");
        }
    }
    return false;
}

static void update_bar_position(barhit_t *barhit, float seconds)
{
    barhit->bar_pos += BAR_SPEED * seconds * barhit->bar_direction;
    if (barhit->bar_pos <= (WINDOW_WIDTH - RECT_WIDTH) / 2 ||
        barhit->bar_pos >= (WINDOW_WIDTH + RECT_WIDTH) / 2 - BAR_WIDTH) {
        barhit->bar_direction *= -1;
    }
    sfRectangleShape_setPosition(barhit->bar, (sfVector2f){barhit->bar_pos,
        (WINDOW_HEIGHT - RECT_HEIGHT) / 2});
}

static void reset_barhit(game_data_t *game, barhit_t *barhit)
{
    init_barhit(barhit);
    sfClock_restart(game->clock);
}

static bool update_and_draw_barhit(game_data_t *game, barhit_t *barhit)
{
    sfTime time = sfClock_getElapsedTime(game->clock);
    float seconds = time.microseconds / 1000000.0f;

    if (barhit->cooldown > 0) {
        update_cooldown(barhit, seconds);
    }
    if (barhit->cooldown == 0 && barhit->game_active) {
        if (check_key_press(barhit)) {
            change_game_mode(game, PLAYING);
            reset_barhit(game, barhit);
            return true;
        }
    }
    if (barhit->game_active) {
        update_bar_position(barhit, seconds);
    }
    sfRenderWindow_drawRectangleShape(game->window, barhit->outer_rect, NULL);
    sfRenderWindow_drawRectangleShape(game->window, barhit->inner_rect, NULL);
    sfRenderWindow_drawRectangleShape(game->window, barhit->bar, NULL);
    sfClock_restart(game->clock);
    return false;
}

void display_barhit(game_data_t *game)
{
    static barhit_t barhit;
    static int initialized = 0;

    basic_design(game);
    if (!initialized) {
        init_barhit(&barhit);
        sfClock_restart(game->clock);
        initialized = 1;
    }
    update_and_draw_barhit(game, &barhit);
}

