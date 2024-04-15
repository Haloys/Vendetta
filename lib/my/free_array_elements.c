/*
** EPITECH PROJECT, 2024
** free_array_elements
** File description:
** free the elements of an array
*/

#include <stdlib.h>

int free_array_elements(char **array)
{
    for (int i = 0; array[i] != NULL; ++i)
        free(array[i]);
}
