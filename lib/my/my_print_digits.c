/*
** EPITECH PROJECT, 2024
** my_print_digits
** File description:
** my functions
*/

#include "my.h"

int my_print_digits(void)
{
    int i = '0';

    while (i <= '9') {
        my_putchar(i);
        ++i;
    }
}
