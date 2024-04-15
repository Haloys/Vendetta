/*
** EPITECH PROJECT, 2024
** my_print_alpha
** File description:
** my functions
*/

#include "my.h"

int my_print_alpha(void)
{
    int i = 'a';

    while (i <= 'z') {
        my_putchar(i);
        ++i;
    }
}
