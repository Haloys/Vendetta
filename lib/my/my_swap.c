/*
** EPITECH PROJECT, 2024
** my_swap
** File description:
** swap function
*/

void my_swap(int *a, int *b)
{
    int c = *a;

    *a = *b;
    *b = c;
}
