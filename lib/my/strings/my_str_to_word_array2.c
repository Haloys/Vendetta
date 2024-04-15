/*
** EPITECH PROJECT, 2024
** my_str_to_word_array
** File description:
** crazy man :)
*/

#include <stdlib.h>
#include "../my.h"

static int count_word_by_delim(const char *str, const char *delimiters)
{
    char *copiedstr = malloc(sizeof(char) * my_strlen(str) + 1);
    int count = 0;

    if (copiedstr == NULL)
        return 0;
    copiedstr = my_strcpy(copiedstr, str);
    for (const char *token = my_strtok(copiedstr, delimiters);
        token != NULL; token = my_strtok(NULL, delimiters))
        (++count);
    free(copiedstr);
    return count;
}

char **my_str_to_word_array2(char *str, const char *delimiters)
{
    char *dead_str = my_strdup(str);
    int word_c = count_word_by_delim(dead_str, delimiters);
    char **dest = malloc(sizeof(char *) * (word_c + 1));
    int i = 0;

    if (dest == NULL || dead_str == NULL)
        return NULL;
    for (const char *token = my_strtok(dead_str, delimiters); token != NULL;
        token = my_strtok(NULL, delimiters)) {
        dest[i] = malloc(sizeof(char) * my_strlen(token) + 1);
        if (dest[i] == NULL)
            return NULL;
        dest[i] = my_strcpy(dest[i], token);
        ++i;
    }
    dest[word_c] = NULL;
    free(dead_str);
    return dest;
}
