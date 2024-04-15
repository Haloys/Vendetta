/*
** EPITECH PROJECT, 2024
** my_strdup
** File description:
** crazy man
*/

#include <stdlib.h>

char *my_strdup(char const *src)
{
    char *str;
    int i = 0;

    while (src[i] != '\0') {
        ++i;
    }
    str = malloc(sizeof(char) * (i + 1));
    i = 0;
    while (src[i] != '\0') {
        str[i] = src[i];
        ++i;
    }
    str[i] = '\0';
    return str;
}
