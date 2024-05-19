/*
** EPITECH PROJECT, 2024
** Vendetta
** File description:
** Main
*/

#include "my_game.h"

void icon_loader(game_data_t *game)
{
    sfImage *icon = sfImage_createFromFile(ICON_PATH);
    sfVector2u size = sfImage_getSize(icon);
    const sfUint8 *pixels = sfImage_getPixelsPtr(icon);

    sfRenderWindow_setIcon(game->window, size.x, size.y, pixels);
    sfImage_destroy(icon);
}
