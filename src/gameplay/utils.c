/*
** EPITECH PROJECT, 2024
** Vendetta
** File description:
** Process gameplay loop
*/

#include "my_game.h"

sfColor get_pixel_color(sfImage *image, int x, int y)
{
    sfColor color = sfImage_getPixel(image, x, y);
    return color;
}
