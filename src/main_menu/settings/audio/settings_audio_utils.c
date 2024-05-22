/*
** EPITECH PROJECT, 2024
** B-MUL-200-PAR-2-1-myrpg-maxence.bunel
** File description:
** settings_audio
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "my_game.h"
#include "gameplay.h"

static void change_volume(game_data_t *game, int sound)
{
    if (sound != 0) {
        if (game->settings.clicked_rect_index == 0)
            game->settings.sg_x += sound;
        if (game->settings.clicked_rect_index == 1)
            game->settings.sm_x += sound;
        if (game->settings.clicked_rect_index == 2)
            game->settings.sa_x += sound;
    }
}

static void handle_movement_sound(game_data_t *game)
{
    if (is_key_pressed(game, ArrowDown) && game->state == SETTINGS_AUDIO) {
        game->settings.clicked_rect_index++;
        game->settings.clicked_rect_index %= 3;
    }
    if (is_key_pressed(game, ArrowUp) && game->state == SETTINGS_AUDIO) {
        game->settings.clicked_rect_index--;
        if (game->settings.clicked_rect_index < 0)
            game->settings.clicked_rect_index = 2;
        game->settings.clicked_rect_index %= 3;
    }
}

void update_music_volumes(game_data_t *game)
{
    int global_volume = game->settings.sg_x * SCALE_FACTOR;
    int music_volume = game->settings.sm_x * SCALE_FACTOR;
    int ambiant_volume = game->settings.sa_x * SCALE_FACTOR;

    for (size_t i = 0; i < sizeof(MUSICS) / sizeof(MUSICS[0]); i++) {
        MUSICS[i].volume = CLAMP(music_volume + global_volume, 0, 243);
        if (game->settings.sg_x == 0 || game->settings.sm_x == 0)
            MUSICS[i].volume = 0;
        sfMusic_setVolume(game->assets.music[MUSICS[i].id], MUSICS[i].volume);
    }
    for (size_t j = 0; j < sizeof(SOUNDS) / sizeof(SOUNDS[0]); j++) {
        SOUNDS[j].volume = CLAMP(ambiant_volume + global_volume, 0, 243);
        if (game->settings.sg_x == 0 || game->settings.sa_x == 0)
            SOUNDS[j].volume = 0;
        sfSound_setVolume(game->assets.sound[SOUNDS[j].id], SOUNDS[j].volume);
    }
}

void modify_sound(game_data_t *game)
{
    int sound = 0;

    handle_movement_sound(game);
    if (is_key_down(game, ArrowLeft) && game->state == SETTINGS_AUDIO) {
        sound -= 5;
        update_music_volumes(game);
    }
    if (is_key_down(game, ArrowRight) && game->state == SETTINGS_AUDIO) {
        sound += 5;
        update_music_volumes(game);
    }
    change_volume(game, sound);
    game->settings.sm_x = CLAMP(game->settings.sm_x, 0, 243);
    game->settings.sg_x = CLAMP(game->settings.sg_x, 0, 243);
    game->settings.sa_x = CLAMP(game->settings.sa_x, 0, 243);
}

void draw_tools(game_data_t *game, sfRectangleShape *rect, int i)
{
    if (i == game->settings.clicked_rect_index) {
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
