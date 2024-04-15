/*
** EPITECH PROJECT, 2024
** my_putstr
** File description:
** my put str
*/

#include <unistd.h>
#include "my.h"

static int put_n_str(char const *str, unsigned int max_len)
{
    int strlen;

    if (max_len == 0)
        return 0;
    strlen = my_strlen(str);
    if (max_len > strlen)
        max_len = strlen;
    if (max_len)
        strlen = max_len;
    write(1, str, strlen);
    return strlen;
}

int my_putstr(char const *str)
{
    return put_n_str(str, -1);
}

int my_putstr_offset(char const *str, unsigned int max_len)
{
    return put_n_str(str, max_len);
}
