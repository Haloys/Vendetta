/*
** EPITECH PROJECT, 2024
** my_put_char
** File description:
** function de fou
*/

#include <unistd.h>

void my_putchar(char *c)
{
    write(1, &c, 1);
}
