/*
** EPITECH PROJECT, 2024
** my_strconcat
** File description:
** function de fou vraiment
*/

#include <stdlib.h>
#include <stdarg.h>
#include "../my.h"

static int get_total_strings_len(int count, va_list args)
{
    int len = 0;

    for (int i = 0; i < count; ++i)
        len += my_strlen(va_arg(args, char *));
    return len;
}

static void set_strings_to_result(int count, va_list args, char *result)
{
    int offset = 0;
    int str_len = 0;
    char *str = NULL;

    for (int i = 0; i < count; ++i) {
        str = va_arg(args, char *);
        str_len = my_strlen(str);
        for (int j = 0; j < str_len; ++j) {
            result[offset] = str[j];
            ++offset;
        }
    }
}

char *my_strconcat2(int count, ...)
{
    va_list args;
    char *result = NULL;
    int total_len = 0;

    va_start(args, count);
    total_len = get_total_strings_len(count, args);
    va_end(args);
    result = malloc(sizeof(char) * (total_len + 1));
    if (result == NULL)
        return NULL;
    va_start(args, count);
    set_strings_to_result(count, args, result);
    va_end(args);
    result[total_len] = '\0';
    return result;
}
