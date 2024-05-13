/*
** EPITECH PROJECT, 2024
** Vendetta / Loading Screen
** File description:
** Loading Screen
*/

#include "my_game.h"
#include "my.h"
#include "fade_in_out.h"

static int handle_loading_event(sfRenderWindow *window)
{
    sfEvent event;
    int ret = 0;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            ret = 1;
            sfRenderWindow_close(window);
            return ret;
        }
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeySpace) {
            ret = 1;
            return ret;
        }
    }
    return ret;
}

void start_load_one(game_data_t *game, sfRenderWindow *win, sfClock *clock,
    int *ret)
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
    fade_in_out_all(&params, ret);
    sfText_destroy(text);
}

void start_load_two(game_data_t *game, sfRenderWindow *window, sfClock *clock,
    int *ret)
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
    fade_in_out_all(&params, ret);
    sfText_destroy(text);
}

void start_load_third(game_data_t *game, sfRenderWindow *window, sfClock *clck,
    int *ret)
{
    sprite_id_t elements[] = {SP_LOADING_3, SP_VENDETTA_T};
    int element_count = sizeof(elements) / sizeof(sprite_id_t);
    sfSprite *sprites[element_count];
    sfVector2f text_pos = {785, 153};
    sfText *text = set_text(game, "PRESENTS", 24, text_pos);
    fade_in_params_t params = {
        window, sprites, element_count, text, clck, 3500
    };

    for (int i = 0; i < element_count; i++) {
        sprites[i] = get_sprite(game, elements[i]);
    }
    sfText_setLetterSpacing(text, 14.5f);
    sfText_setStyle(text, sfTextBold);
    fade_in_all(&params, ret);
    sfText_destroy(text);
}

static void page_show(game_data_t *game, sfClock *clock, int page, int *ret)
{
    switch (page) {
        case 1:
            start_load_one(game, game->window, clock, ret);
            break;
        case 2:
            start_load_two(game, game->window, clock, ret);
            break;
        case 3:
            start_load_third(game, game->window, clock, ret);
            break;
        case 4:
            game->state = MAIN_MENU;
            break;
    }
}

int do_check(sfRenderWindow *window, int ret)
{
    if (handle_loading_event(window) == 1) {
        ret = 1;
    }
    return ret;
}

void launch_loading(game_data_t *game)
{
    sfClock *clock = sfClock_create();
    sfTime elapsed_time;
    int ret = 0;

    start_music(&game->assets, M_LOADING);
    for (int page = 1; page <= 4; page++) {
        sfClock_restart(clock);
        page_show(game, clock, page, &ret);
        sfRenderWindow_display(game->window);
        do {
            ret = do_check(game->window, ret);
            if (ret == 1) {
                game->state = MAIN_MENU;
                sfClock_destroy(clock);
                return;
            }
            elapsed_time = sfClock_getElapsedTime(clock);
        } while (sfTime_asMilliseconds(elapsed_time) < 6500);
    }
    sfClock_destroy(clock);
}
