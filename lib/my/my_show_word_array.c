/*
** EPITECH PROJECT, 2024
** my_show_word_array
** File description:
** crazy man :)
*/

#include "my.h"

int my_show_word_array(char *const *tab)
{
    int i = 0;

    for (; tab[i]; ++i) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
    return i;
}
