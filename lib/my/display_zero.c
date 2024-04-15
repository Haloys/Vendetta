/*
** EPITECH PROJECT, 2024
** display_zero
** File description:
** function
*/

#include "my.h"

int display_zero(int nb_zero)
{
    while (nb_zero > 0) {
        my_putchar('0');
        nb_zero--;
    }
}
