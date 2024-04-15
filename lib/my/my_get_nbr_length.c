/*
** EPITECH PROJECT, 2024
** my_get_nbr_length
** File description:
** my functions
*/

#include "my.h"

static int get_length(int nb, int count)
{
    long int nbr = nb;

    count += 1;
    if (nbr < 0) {
        nbr *= -1;
    }
    if (nbr < 10) {
    } else {
        count = get_length(nbr / 10, count);
    }
    return count;
}

int my_get_nbr_length(int nb)
{
    return get_length(nb, 0);
}
