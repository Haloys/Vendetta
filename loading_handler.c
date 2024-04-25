/*
** EPITECH PROJECT, 2023
** B-MUL-100-PAR-1-1-myradar-maxence.bunel
** File description:
** loading_handler
*/

#include <SFML/Audio.h>
#include "../../include/my.h"
#include "../../include/my_radar.h"
#include "../../include/planes.h"
#include "../../include/towers.h"
#include "../../include/utils.h"
#include "../../include/background.h"
#include "../../include/logos.h"

static sfSprite *load_and_display_epilogo(game_t *game)
{
    sfVector2f epi_pos = {717.0, 481.0};
    sfSprite *epi_logo = load_sprite(LOGOS[EPITECH], 486, 118, epi_pos);

    if (epi_logo != NULL) {
        sfRenderWindow_drawSprite(game->game_window, epi_logo, NULL);
        sfRenderWindow_display(game->game_window);
    }
    return epi_logo;
}

static void display_game_logo(game_t *game, sfSprite *back)
{
    sfVector2f game_pos = {718.0, 385.0};
    sfSprite *game_logo = load_sprite(LOGOS[GAME_LOGO], 483, 310, game_pos);

    sfRenderWindow_clear(game->game_window, sfBlack);
    sfRenderWindow_drawSprite(game->game_window, back, NULL);
    sfRenderWindow_drawSprite(game->game_window, game_logo, NULL);
    sfRenderWindow_display(game->game_window);
}

static void display_logos(game_t *game, sfSprite *back)
{
    static int epi_logo_destroyed = FALSE;
    sfSprite *epi_logo = NULL;
    sfSprite *game_logo = NULL;
    sfTime elapsed_time = sfClock_getElapsedTime(game->game_clock);

    if (epi_logo_destroyed == FALSE && sfTime_asSeconds(elapsed_time) <= 0.16)
        epi_logo = load_and_display_epilogo(game);
    if (epi_logo_destroyed == FALSE && (sfTime_asSeconds(elapsed_time) >= 6.0
    && sfTime_asSeconds(elapsed_time) <= 6.1)) {
        sfSprite_destroy(epi_logo);
        epi_logo_destroyed = TRUE;
        display_game_logo(game, back);
    }
    if (sfTime_asSeconds(elapsed_time) == 11.8)
        sfSprite_destroy(game_logo);
}

static void play_loading_sound(game_t *game)
{
    static sfSound *sound = NULL;
    sfTime elapsed_time = sfClock_getElapsedTime(game->game_clock);
    static int done = 0;

    if (sound == NULL)
        sound = create_sound("src/assets/sounds/intro.ogg");
    if (done == 0) {
        sfSound_setVolume(sound, 60.0);
        play_sound(sound, game);
        done = 1;
    }
    if (sfTime_asSeconds(elapsed_time) == 11.8) {
        sfSound_destroy(sound);
    }
}

void init_loading(game_t *game, int *done)
{
    sfSprite *back = load_background(BACKGROUNDS[LOADING_BG], 1920, 1080);
    sfEvent event;
    int res = 5;

    *done = TRUE;
    sfRenderWindow_drawSprite(game->game_window, back, NULL);
    sfRenderWindow_display(game->game_window);
    sfClock_restart(game->game_clock);
    while (sfTime_asSeconds(
        sfClock_getElapsedTime(game->game_clock)) < 11.8 && res == 5) {
        play_loading_sound(game);
        display_logos(game, back);
        sfSleep(sfMilliseconds(16));
        while (sfRenderWindow_pollEvent(game->game_window, &event))
            res = (event.type == sfEvtClosed) ?
            (sfRenderWindow_close(game->game_window), 0) : 5;
    }
    sfSprite_destroy(back);
    *done = FALSE;
    game->status = HOME;
}
