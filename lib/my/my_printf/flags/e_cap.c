/*
** EPITECH PROJECT, 2024
** my_printf_flag e
** File description:
** print in scinetific notation
*/

#include <unistd.h>
#include "../../my.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

static long long get_nb(double nb)
{
    int multiplier = 10;

    while (nb * multiplier != (int)(nb * multiplier)) {
        multiplier *= 10;
    }
    return (long long)(nb * multiplier);
}

static int len_dec(double nb)
{
    int multiplier = 10;
    int len = 0;

    while (nb * multiplier != (long long)(nb * multiplier)) {
        multiplier *= 10;
        len++;
    }
    return len;
}

static void put_end(int nb_dec)
{
    if (nb_dec < 10) {
        my_putchar('0');
    }
    my_put_nbr(nb_dec, 0);
}

static void display_e(char *to_print, int nb_dec, int nb_zero, char sign)
{
    my_putstr(to_print);
    while (nb_zero > 0) {
        my_putchar('0');
        nb_zero--;
    }
    my_putchar('E');
    my_putchar(sign);
    if (sign == '-') {
        put_end(nb_dec);
    } else {
        put_end(nb_dec);
    }
}

static int main_e(double nb, char sign, int precision, int is_one)
{
    long long i = get_nb(nb);
    int len = min(precision, len_nbr(i));
    int nb_zero = precision - len;
    int len_cpy = len;
    int nb_dec = len_dec(nb);
    char *to_print = malloc(sizeof(char) * (len + 3));

    if (is_one)
        nb_dec = 0;
    to_print[1] = '.';
    to_print[len + 1] = '\0';
    for (; len >= 0; len--) {
        if (len == 1)
            continue;
        to_print[len] = i % 10 + '0';
        i /= 10;
    }
    display_e(to_print, nb_dec, nb_zero, sign);
    return len_cpy;
}

int my_printf_flag_e_cap(va_list *ap, int precision)
{
    char sign = '+';
    int is_one = 0;
    double nb = va_arg(*ap, double);

    if (len_nbr((int)nb) == 1) {
        is_one = 1;
    }
    if (nb < 1 && nb >= 0) {
        sign = '-';
    }
    if (nb < 0) {
        nb = -nb;
        my_putchar('-');
    }
    if (precision == -1)
        precision = 6;
    return main_e(nb, sign, precision + 1, is_one);
}
