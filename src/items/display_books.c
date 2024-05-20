/*
** EPITECH PROJECT, 2024
** B-MUL-200-PAR-2-1-myrpg-maxence.bunel [WSL: Ubuntu]
** File description:
** display_books
*/

#include "my_game.h"
#include "utils.h"

void display_first_book(game_data_t *game)
{
    sfSprite *sprite = get_sprite(game, SP_BOOK1);

    sfRenderWindow_drawSprite(game->window, sprite, NULL);
    if (is_key_pressed(game, Space)) {
        insert_item_in_inventory(game, "first_book", 1);
        sfSound_stop(game->assets.sound[S_FIRST_BOOK]);
        change_game_mode(game, INVENTORY);
    }
}

void display_second_book(game_data_t *game)
{
    sfSprite *sprite = get_sprite(game, SP_BOOK2);

    sfRenderWindow_drawSprite(game->window, sprite, NULL);
    if (is_key_pressed(game, Space)) {
        insert_item_in_inventory(game, "second_book", 1);
        sfSound_stop(game->assets.sound[S_SECOND_BOOK]);
        change_game_mode(game, INVENTORY);
    }
}

void display_third_book(game_data_t *game)
{
    sfSprite *sprite = get_sprite(game, SP_BOOK3);

    sfRenderWindow_drawSprite(game->window, sprite, NULL);
    if (is_key_pressed(game, Space)) {
        insert_item_in_inventory(game, "third_book", 1);
        sfSound_stop(game->assets.sound[S_THIRD_BOOK]);
        change_game_mode(game, INVENTORY);
    }
}
