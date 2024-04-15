/*
** EPITECH PROJECT, 2024
** my_find_prime_sup
** File description:
** function
*/

#include "my.h"

int my_find_prime_sup(int nb)
{
    int i = nb;

    while (!my_is_prime(i)) {
        ++i;
    }
    return i;
}
