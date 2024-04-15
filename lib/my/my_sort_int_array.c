/*
** EPITECH PROJECT, 2024
** my_sort_int_array
** File description:
** function
*/

#include "my.h"

void process_sort_loop(int *array, int i, int size)
{
    int j = i + 1;

    while (j < size) {
        if (array[i] > array[j]) {
            my_swap(&array[i], &array[j]);
        }
        ++j;
    }
}

void my_sort_int_array(int *array, int size)
{
    int i = 0;

    while (i < size) {
        process_sort_loop(array, i, size);
        ++i;
    }
}
