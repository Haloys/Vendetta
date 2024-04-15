/*
** EPITECH PROJECT, 2024
** my_put_nbr
** File description:
** my functions
*/

#include "my.h"

int my_put_nbr(int nb, int count)
{
    long int nbr = nb;

    count += 1;
    if (nbr < 0) {
        my_putchar('-');
        nbr *= -1;
        count += 1;
    }
    if (nbr < 10) {
        my_putchar(nbr + '0');
    } else {
        count = my_put_nbr(nbr / 10, count);
        my_putchar(nbr % 10 + '0');
    }
    return count;
}
