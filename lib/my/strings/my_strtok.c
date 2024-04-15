/*
** EPITECH PROJECT, 2024
** my_strupcase
** File description:
** function de fou vraiment
*/

#include <stddef.h>

static int is_delimiter(char c, const char *delimiters)
{
    if (c == '\0')
        return 0;
    for (int j = 0; delimiters[j] != '\0'; ++j)
        if (c == delimiters[j])
            return 1;
    return 0;
}

static int next_l(char *buff, const char *delimiters)
{
    int count = 0;

    for (int i = 0; buff[i] != '\0'; ++i)
        if (is_delimiter(buff[i], delimiters))
            break;
        else
            (++count);
    return count;
}

char *my_strtok(char *str, const char *delimiters)
{
    static char *buff;
    char *token = NULL;

    if (str != NULL)
        buff = str;
    else
        str = buff;
    while (is_delimiter(buff[0], delimiters))
        (++buff);
    if (buff[0] == '\0')
        return NULL;
    token = buff;
    buff += next_l(buff, delimiters);
    if (buff[0] != '\0') {
        buff[0] = '\0';
        ++buff;
    }
    return token;
}
