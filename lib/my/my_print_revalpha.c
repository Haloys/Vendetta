/*
** EPITECH PROJECT, 2024
** my_print_revalpha
** File description:
** my functions
*/

#include "my.h"

int my_print_revalpha(void)
{
    int i = 'z';

    while (i >= 'a') {
        my_putchar(i);
        --i;
    }
}
