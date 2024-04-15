/*
** EPITECH PROJECT, 2024
** my_strstr
** File description:
** function de fou
*/

#include <stdio.h>
#include "../my.h"

char *my_strstr(char *str, char const *to_find)
{
    int ti = 0;
    int len = my_strlen(to_find);
    int final_index = -1;

    if (len == 0)
        return str;
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] != to_find[ti])
            ti = 0;
        else
            ++ti;
        if (len == ti)
            final_index = i - (len - 1);
    }
    return (final_index == -1) ? (NULL) : &str[final_index];
}
