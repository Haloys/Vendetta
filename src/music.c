/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** my_radar project
*/

#include "my_game.h"

void start_music(game_assets_t *assets, music_id_t id)
{
    sfMusic_play(assets->music[id]);
    sfMusic_setVolume(assets->music[id], MUSICS[id].volume);
}
