/*
** EPITECH PROJECT, 2024
** my_str_to_word_array
** File description:
** crazy man :)
*/

#include <stdlib.h>
#include "../my.h"

int is_an(char c)
{
    if (!c)
        return 0;
    if (is_alpha(c) || is_numeric(c))
        return 1;
    return 0;
}

static int count_words(const char *str)
{
    int i = 0;
    int count = 0;

    while (str[i]) {
        if (is_an(str[i]) && !is_an(str[i + 1])) {
            ++count;
        }
        ++i;
    }
    return count;
}

static int get_word_len(const char *str, int j)
{
    while (is_an(str[j]))
            ++j;
    return j;
}

void increment_v(int *j, int *k)
{
    ++(*j);
    ++(*k);
}

char **my_str_to_word_array(char const *str)
{
    int words = count_words(str);
    char **dest = malloc(sizeof(char *) * (words + 1) + 1);
    int j = 0;
    int k = 0;

    for (int i = 0; i < words; ++i) {
        if (!is_an(str[j])) {
            ++j;
            continue;
        }
        dest[i] = malloc(sizeof(char) * get_word_len(str, j) + 1);
        while (is_an(str[j])) {
            dest[i][k] = str[j];
            increment_v(&j, &k);
        }
        dest[i][k] = '\0';
        k = 0;
    }
    dest[words] = '\0';
    return dest;
}
