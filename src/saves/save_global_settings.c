/*
** EPITECH PROJECT, 2024
** B-MUL-200-PAR-2-1-myrpg-maxence.bunel [WSL: Ubuntu]
** File description:
** save_global_settings
*/

#include <stdio.h>

#include "my_game.h"
#include "saves.h"

static void save_video_settings(game_data_t *game, FILE *file)
{
    fprintf(file, "resolution=%dx%d\n", game->video_mode.width,
        game->video_mode.height);
    fprintf(file, "fps=%d\n", game->fps);
    fprintf(file, "fullscreen=%d\n", game->settings.is_fullscreen);
}

static void save_audio_settings(game_data_t *game, FILE *file)
{
    fprintf(file, "general_volume=%d\n", game->settings.sg_x);
    fprintf(file, "sound_volume=%d\n", game->settings.sa_x);
    fprintf(file, "music_volume=%d\n", game->settings.sm_x);
}

static void save_keybinds(game_data_t *game, FILE *file)
{
    fprintf(file, "MoveUp=%d\n", (int)game->keybinds[MoveUp].code);
    fprintf(file, "MoveDown=%d\n", game->keybinds[MoveDown].code);
    fprintf(file, "MoveLeft=%d\n", game->keybinds[MoveLeft].code);
    fprintf(file, "MoveRight=%d\n", game->keybinds[MoveRight].code);
    fprintf(file, "Inventory=%d\n", game->keybinds[Inventory].code);
    fprintf(file, "KeyMinus=%d\n", game->keybinds[KeyMinus].code);
    fprintf(file, "KeyPlus=%d\n", game->keybinds[KeyPlus].code);
    fprintf(file, "Interact=%d\n", game->keybinds[Interact].code);
    fprintf(file, "Sprint=%d\n", game->keybinds[Sprint].code);
    fprintf(file, "Reset=%d\n", game->keybinds[Reset].code);
    fprintf(file, "Hostile=%d\n", game->keybinds[Hostile].code);
}

static void get_base_values(game_data_t *game, unsigned long *base_val)
{
    *base_val += game->video_mode.width + game->video_mode.height;
    *base_val += game->fps;
    *base_val += game->settings.is_fullscreen;
    *base_val += game->settings.sg_x;
    *base_val += game->settings.sa_x;
    *base_val += game->settings.sm_x;
    *base_val += game->keybinds[MoveUp].code;
    *base_val += game->keybinds[MoveDown].code;
    *base_val += game->keybinds[MoveLeft].code;
    *base_val += game->keybinds[MoveRight].code;
    *base_val += game->keybinds[Inventory].code;
    *base_val += game->keybinds[KeyMinus].code;
    *base_val += game->keybinds[KeyPlus].code;
    *base_val += game->keybinds[Interact].code;
    *base_val += game->keybinds[Sprint].code;
    *base_val += game->keybinds[Reset].code;
    *base_val += game->keybinds[Hostile].code;
}

unsigned long hash_values(unsigned long base_val)
{
    unsigned long hash = 1484347;

    hash ^= base_val;
    hash = (hash << 5) + hash;
    hash += 136975;
    hash *= 9;
    return hash;
}

static void hash_save(game_data_t *game, FILE *file)
{
    unsigned long base_val = 0;
    unsigned long hash = 0;

    get_base_values(game, &base_val);
    hash = hash_values(base_val);
    fprintf(file, "hash=%ld\n", hash);
}

void save_global_settings(game_data_t *game)
{
    FILE *file = fopen("database/global_settings.ven", "w");

    if (!file)
        return;
    save_video_settings(game, file);
    save_audio_settings(game, file);
    save_keybinds(game, file);
    hash_save(game, file);
    fclose(file);
}
