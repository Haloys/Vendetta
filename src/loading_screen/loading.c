/*
** EPITECH PROJECT, 2024
** B-MUL-200-PAR-2-1-myrpg-maxence.bunel
** File description:
** loading
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "my_game.h"
#include "my.h"
#include "score.h"
#include "fade_in_out.h"

static int handle_loading_event(game_data_t *game)
{
    sfEvent event;
    int ret = 0;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        if (event.type == sfEvtClosed) {
            ret = 1;
            sfRenderWindow_close(game->window);
            return ret;
        }
    }
    return ret;
}

void start_load_one(game_data_t *game, sfRenderWindow *win, sfClock *clock)
{
    sprite_id_t elements[] = {SP_LOADING_1, SP_FLAVIBOT, SP_ORA, SP_TRYADE};
    int element_count = 4;
    sfSprite *sprites[element_count];
    sfVector2f text_pos = {750, 200};
    sfText *text = set_text(game, "POWERED BY", 30, text_pos);
    fade_in_out_params_t params = {
        win, sprites, element_count, text, clock, 2000, 6500, 6500 - 2000
    };

    for (int i = 0; i < element_count; i++) {
        sprites[i] = get_sprite(game, elements[i]);
    }
    sfText_setLetterSpacing(text, 10.0f);
    sfText_setStyle(text, sfTextBold);
    fade_in_out_all(&params);
    sfText_destroy(text);
}

void start_load_two(game_data_t *game, sfRenderWindow *window, sfClock *clock)
{
    sprite_id_t elements[] = {SP_LOADING_2, SP_DEV_1, SP_DEV_2,
        SP_DEV_3, SP_DEV_4};
    int element_count = sizeof(elements) / sizeof(sprite_id_t);
    sfSprite *sprites[element_count];
    sfVector2f text_pos = {750, 200};
    sfText *text = set_text(game, "CREATED BY", 30, text_pos);
    fade_in_out_params_t params = {
        window, sprites, element_count, text, clock, 3500, 6500, 6500 - 2000
    };

    for (int i = 0; i < element_count; i++) {
        sprites[i] = get_sprite(game, elements[i]);
    }
    sfText_setLetterSpacing(text, 10.0f);
    sfText_setStyle(text, sfTextBold);
    fade_in_out_all(&params);
    sfText_destroy(text);
}

void start_load_third(game_data_t *game, sfRenderWindow *window, sfClock *clock)
{
    sprite_id_t elements[] = {SP_LOADING_3, SP_VENDETTA_T};
    int element_count = sizeof(elements) / sizeof(sprite_id_t);
    sfSprite *sprites[element_count];
    sfVector2f text_pos = {785, 153};
    sfText *text = set_text(game, "PRESENTS", 24, text_pos);
    fade_in_params_t params = {
        window, sprites, element_count, text, clock, 3500
    };

    for (int i = 0; i < element_count; i++) {
        sprites[i] = get_sprite(game, elements[i]);
    }
    sfText_setLetterSpacing(text, 14.5f);
    sfText_setStyle(text, sfTextBold);
    fade_in_all(&params);
    sfText_destroy(text);
}

static void page_show(game_data_t *game, sfRenderWindow *window,
    sfClock *clock, int page)
{
    switch (page) {
        case 1:
            start_load_one(game, window, clock);
            break;
        case 2:
            start_load_two(game, window, clock);
            break;
        case 3:
            start_load_third(game, window, clock);
            break;
        case 4:
            game->state = MAIN_MENU;
            break;
    }
}

static int do_check(game_data_t *game, int ret)
{
    if (handle_loading_event(game) == 1) {
        ret = 1;
    }
    return ret;
}

void launch_loading(game_data_t *game)
{
    sfClock *clock = sfClock_create();
    sfRenderWindow *window = game->window;
    sfTime elapsed_time;
    int ret = 0;
    int a = 0;

    start_music(&game->assets, M_LOADING);
    for (int page = 1; page <= 4; page++) {
        if (ret == 1)
            break;
        sfClock_restart(clock);
        page_show(game, window, clock, page);
        sfRenderWindow_display(game->window);
        do {
            ret = do_check(game, ret);
            if (ret == 1)
                break;
            elapsed_time = sfClock_getElapsedTime(clock);
        } while (sfTime_asMilliseconds(elapsed_time) < 6500);
    }
    sfClock_destroy(clock);
}
