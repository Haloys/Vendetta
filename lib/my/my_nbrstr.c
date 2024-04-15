/*
** EPITECH PROJECT, 2024
** my_nbrstr
** File description:
** my functions
*/

#include "my.h"
#include <stdlib.h>

void convert_nbr(char *str, int nb, int *i)
{
    long int nbr = nb;

    if (nbr < 0) {
        str[*i] = '-';
        nbr *= -1;
        *i += 1;
    }
    if (nbr < 10) {
        str[*i] = nbr + '0';
        *i += 1;
    } else {
        convert_nbr(str, nbr / 10, i);
        str[*i] = nbr % 10 + '0';
        *i += 1;
    }
    str[*i] = '\0';
}

char *my_nbrstr(int nb)
{
    static char str[MAX_INTSTR_LENGTH + 1];
    int i = 0;

    convert_nbr(str, nb, &i);
    return str;
}
