/*
** EPITECH PROJECT, 2024
** my_strconcat
** File description:
** function de fou vraiment
*/

#include <stdlib.h>
#include "../my.h"

char *my_strconcat(char *str, char *str_bis)
{
    int str_l = my_strlen(str);
    int str_bis_l = my_strlen(str_bis);
    int offset = 0;
    char *dir = malloc(sizeof(char) * (str_l + str_bis_l + 1));

    for (int i = 0; offset < str_l; ++i) {
        dir[offset] = str[i];
        ++offset;
    }
    for (int i = 0; i < str_bis_l; ++i) {
        dir[offset] = str_bis[i];
        ++offset;
    }
    dir[offset] = '\0';
    return dir;
}
