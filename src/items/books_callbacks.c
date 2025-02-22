/*
** EPITECH PROJECT, 2024
** B-MUL-200-PAR-2-1-myrpg-maxence.bunel [WSL: Ubuntu]
** File description:
** books_callbacks
*/

#include "my_game.h"
#include "gameplay.h"
#include "utils.h"

void first_book_callback(game_data_t *game)
{
    for (size_t i = 0; i < sizeof(MUSICS) / sizeof(MUSICS[0]); i++) {
        sfMusic_setVolume(game->assets.music[MUSICS[i].id], 2);
    }
    play_sound(game, S_FIRST_BOOK);
    change_game_mode(game, BOOK_1);
}

void second_book_callback(game_data_t *game)
{
    for (size_t i = 0; i < sizeof(MUSICS) / sizeof(MUSICS[0]); i++) {
        sfMusic_setVolume(game->assets.music[MUSICS[i].id], 2);
    }
    play_sound(game, S_SECOND_BOOK);
    change_game_mode(game, BOOK_2);
}

void third_book_callback(game_data_t *game)
{
    for (size_t i = 0; i < sizeof(MUSICS) / sizeof(MUSICS[0]); i++) {
        sfMusic_setVolume(game->assets.music[MUSICS[i].id], 2);
    }
    play_sound(game, S_THIRD_BOOK);
    change_game_mode(game, BOOK_3);
}
