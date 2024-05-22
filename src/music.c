/*
** EPITECH PROJECT, 2024
** Vendetta
** File description:
** Music
*/

#include "my_game.h"

void start_music(game_assets_t *assets, music_id_t id)
{
    sfMusic_play(assets->music[id]);
    sfMusic_setVolume(assets->music[id], MUSICS[id].volume);
    sfMusic_setLoop(assets->music[id], true);
}
