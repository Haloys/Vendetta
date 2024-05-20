/*
** EPITECH PROJECT, 2024
** Vendetta
** File description:
** Process gameplay loop
*/

#include "my_game.h"

sfColor get_pixel_color(sfImage *image, int x, int y)
{
    if (x < 0 || y < 0 || x >= sfImage_getSize(image).x
        || y >= sfImage_getSize(image).y)
        return sfColor_fromRGB(0, 0, 0);
    return sfImage_getPixel(image, x, y);
}
