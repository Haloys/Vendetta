/*
** EPITECH PROJECT, 2024
** flag e
** File description:
** print in scinetific notation
*/

#include <unistd.h>
#include "../../my.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

static int my_round(int nb, int precision, int is_round)
{
    int power = len_nbr(nb) - precision;
    int to_round = 0;

    if (power > 1) {
        if (!is_round)
            return nb / my_compute_power_rec(10, power);
        if ((nb / my_compute_power_rec(10, power - 1)) % 10 > 4)
            to_round = 1;
    }
    if (power >= 1)
        return nb / my_compute_power_rec(10, power) + to_round;
    else
        return nb;
}

static int my_put_nbr_to_str(long long nb, int len, int precis, int is_round)
{
    int len_print = min(len, precis);
    char *str = malloc(sizeof(char) * (len_print + 1));

    str[len_print + 1] = '\0';
    len_print -= 1;
    nb = my_round(nb, precis, is_round);
    for (; len_print > 0; len_print--) {
        str[len_print] = nb % 10 + '0';
        nb /= 10;
    }
    if (len_nbr(nb) > 1)
        str[0] = nb % 10 + '0';
    else
        str[0] = nb + '0';
    my_putstr(str);
    return min(len, precis);
}

static int call_f(double nb, int precision)
{
    long long i = (long long)nb;
    int nb_dec = len_dec_2(nb);
    int already_print;
    int is_round = 1;

    if (precision == 6)
        is_round = 0;
    nb *= my_compute_power_rec(10, nb_dec + 1);
    nb -= i * my_compute_power_rec(10, nb_dec + 1);
    already_print = my_put_nbr_to_str(i, len_nbr(i), precision, is_round);
    precision -= already_print;
    if (precision > 0) {
        my_putchar('.');
        my_put_nbr_to_str((long long)nb, len_nbr((long long)nb), precision,
        is_round);
    }
}

static void put_end(int nb_dec)
{
    if (nb_dec < 10) {
        my_putchar('0');
    }
    my_put_nbr(nb_dec, 0);
}

static void display_e(int count, char sign)
{
    my_putchar('e');
    my_putchar(sign);
    if (sign == '-') {
        put_end(count);
    } else {
        put_end(count);
    }
}

static int update(int *multiplier, int *count)
{
    *multiplier *= 10;
    *count += 1;
}

static int main_e(double nb, char sign, int precision)
{
    int count = 1;
    int multiplier = 10;

    if (sign == '+') {
        while (len_nbr((long long)nb / multiplier) != 1)
            update(&multiplier, &count);
        nb /= multiplier;
    } else {
        while (len_nbr((long long)nb * multiplier) != 1)
            update(&multiplier, &count);
        nb *= multiplier;
    }
    my_putchar((int)nb + '0');
    my_putchar('.');
    nb -= (int)nb;
    nb *= my_compute_power_rec(10, precision);
    my_put_nbr_to_str((long long)nb, len_nbr((long long)nb), precision - 2, 1);
    display_e(count, sign);
}

static int call_e(double nb, int precision)
{
    char sign = '+';

    if (nb < 1 && nb >= 0) {
        sign = '-';
    }
    if (nb < 0) {
        nb = -nb;
        my_putchar('-');
    }
    return main_e(nb, sign, precision + 1);
}

int my_printf_flag_g(va_list *ap, int precision)
{
    double nb = va_arg(*ap, double);
    int nb_dec = len_dec_2(nb) + 1;
    int len_left = len_nbr((long long)nb);

    if (nb < 0) {
        nb = -nb;
        my_putchar('-');
    }
    if (precision == -1)
        precision = 6;
    if (nb_dec > 4 || precision < len_left) {
        call_e(nb, precision);
    } else {
        call_f(nb, precision);
    }
}
