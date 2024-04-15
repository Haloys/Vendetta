/*
** EPITECH PROJECT, 2024
** min
** File description:
** function
*/

#include <stddef.h>

void *my_memcpy(void *dest, const void *src, size_t size)
{
    char *cdest = dest;
    const char *csrc = src;

    for (size_t i = 0; i < size; ++i)
        cdest[i] = csrc[i];
    return dest;
}
