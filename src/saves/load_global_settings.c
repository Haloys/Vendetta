/*
** EPITECH PROJECT, 2024
** B-MUL-200-PAR-2-1-myrpg-maxence.bunel [WSL: Ubuntu]
** File description:
** load_global_settings
*/

#include "saves.h"
#include "utils.h"

const save_t SAVES[] = {
    {
        .name = "fps",
    },
    {
        .name = "fullscreen",
    },
    {
        .name = "general_volume",
    },
    {
        .name = "sound_volume",
    },
    {
        .name = "music_volume",
    },
    {
        .name = "MoveUp",
    },
    {
        .name = "MoveDown",
    },
    {
        .name = "MoveLeft",
    },
    {
        .name = "MoveRight",
    },
    {
        .name = "Inventory",
    },
    {
        .name = "KeyMinus",
    },
    {
        .name = "KeyPlus",
    },
    {
        .name = "Interact",
    },
    {
        .name = "Sprint",
    },
    {
        .name = "Reset",
    },
    {
        .name = "Hostile",
    },
};

static int get_file_value(FILE *file)
{
    unsigned long values = 0;
    int tmp_values = 0;
    int tmp_values_2 = 0;
    char tmp_str[64] = {0};

    fscanf(file, "resolution=%dx%d\n", &tmp_values, &tmp_values_2);
    values += tmp_values + tmp_values_2;
    for (size_t i = 0; i < GLOBAL_SETTINGS_COUNT; i++) {
        strcpy(tmp_str, SAVES[i].name);
        strcat(tmp_str, "=%d\n");
        fscanf(file, tmp_str, &tmp_values);
        values += tmp_values;
    }
    return values;
}

int verify_hash(FILE *file)
{
    unsigned long base_val = get_file_value(file);
    unsigned long hash = hash_values(base_val);
    unsigned long file_hash = 0;

    fscanf(file, "hash=%ld\n", &file_hash);
    if (hash != file_hash) {
        dprintf(1, "Hash verification failed\n");
        fclose(file);
        return 0;
    } else {
        dprintf(1, "Hash verification success\n");
    }
    return 1;
}

static void load_video_settings(game_data_t *game, FILE *file)
{
    int tmp_values = 0;
    int tmp_values_2 = 0;

    fscanf(file, "resolution=%dx%d\n", &tmp_values, &tmp_values_2);
    game->video_mode.width = tmp_values;
    game->video_mode.height = tmp_values_2;
    fscanf(file, "fps=%d\n", &game->fps);
    fscanf(file, "fullscreen=%d\n", &tmp_values);
    game->settings.is_fullscreen = tmp_values;
}

static void load_sound_settings(game_data_t *game, FILE *file)
{
    int tmp_values = 0;

    fscanf(file, "general_volume=%d\n", &tmp_values);
    game->settings.sg_x = tmp_values;
    fscanf(file, "sound_volume=%d\n", &tmp_values);
    game->settings.sm_x = tmp_values;
    fscanf(file, "music_volume=%d\n", &tmp_values);
    game->settings.sa_x = tmp_values;
}

static void load_keybinds_settings_2(game_data_t *game, FILE *file)
{
    int tmp_values = 0;

    fscanf(file, "KeyPlus=%d\n", &tmp_values);
    game->keybinds[KeyPlus].code = tmp_values;
    fscanf(file, "Interact=%d\n", &tmp_values);
    game->keybinds[Interact].code = tmp_values;
    fscanf(file, "Sprint=%d\n", &tmp_values);
    game->keybinds[Sprint].code = tmp_values;
    fscanf(file, "Reset=%d\n", &tmp_values);
    game->keybinds[Reset].code = tmp_values;
    fscanf(file, "Hostile=%d\n", &tmp_values);
    game->keybinds[Hostile].code = tmp_values;
}

static void load_keybinds_settings(game_data_t *game, FILE *file)
{
    int tmp_values = 0;

    fscanf(file, "MoveUp=%d\n", &tmp_values);
    game->keybinds[MoveUp].code = tmp_values;
    fscanf(file, "MoveDown=%d\n", &tmp_values);
    game->keybinds[MoveDown].code = tmp_values;
    fscanf(file, "MoveLeft=%d\n", &tmp_values);
    game->keybinds[MoveLeft].code = tmp_values;
    fscanf(file, "MoveRight=%d\n", &tmp_values);
    game->keybinds[MoveRight].code = tmp_values;
    fscanf(file, "Inventory=%d\n", &tmp_values);
    game->keybinds[Inventory].code = tmp_values;
    fscanf(file, "KeyMinus=%d\n", &tmp_values);
    game->keybinds[KeyMinus].code = tmp_values;
    load_keybinds_settings_2(game, file);
}

void load_global_settings(game_data_t *game)
{
    FILE *file = fopen("database/global_settings.ven", "r");

    if (!file)
        return;
    load_video_settings(game, file);
    load_sound_settings(game, file);
    load_keybinds_settings(game, file);
    fclose(file);
}

void load_settings(game_data_t *game)
{
    FILE *file = fopen("database/global_settings.ven", "r");

    if (!file)
        return;
    if (verify_hash(file) == 0)
        return;
    fclose(file);
    load_global_settings(game);
}
