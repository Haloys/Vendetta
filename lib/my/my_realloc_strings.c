/*
** EPITECH PROJECT, 2024
** my_realloc_strings
** File description:
** realloc an array of strings (char **)
*/

#include <stdlib.h>

char **my_realloc_strings(char **array, int size)
{
    char **new_array = malloc(sizeof(char *) * (size + 1));

    if (new_array == NULL)
        return NULL;
    for (int i = 0; i < size; ++i)
        new_array[i] = NULL;
    for (int i = 0; array[i] != NULL; ++i)
        new_array[i] = array[i];
    new_array[size] = NULL;
    free(array);
    return new_array;
}
