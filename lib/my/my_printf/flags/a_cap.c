/*
** EPITECH PROJECT, 2024
** FLAG_A
** File description:
** print a double in hexa
*/

#include <unistd.h>
#include <stdio.h>
#include "../../my.h"
#include <stdarg.h>

static long long get_nb(double nb)
{
    int multiplier = 10;

    while (nb * multiplier != (int)(nb * multiplier)) {
        multiplier *= 10;
    }
    return (long long)(nb * multiplier);
}

static int to_round(double nb, int count, int precision, int to_print)
{
    if (count == precision - 1) {
        if ((int)(nb * 16) >= 5) {
            to_print += 1;
        }
    }
    return to_print;
}

static void print_hexa(int to_print)
{
    if (to_print > 9) {
        to_print += '7';
    } else {
        to_print += '0';
    }
    my_putchar(to_print);
}

static int convert_a(double nb, int count, int precision)
{
    int to_print;
    double km = 0;
    double tiny = 0.0000001;

    while (nb != 0 && count < precision) {
        nb *= 16.0;
        if (nb - km < tiny && nb - km > -tiny) {
            nb = km;
        } else
            km = nb;
        to_print = (int)nb;
        nb -= to_print;
        to_print = to_round(nb, count, precision, to_print);
        count++;
    }
    return count;
}

static double set_one(double *nb)
{
    int count = 0;

    while ((int)*nb != 1) {
        *nb /= 2;
        count++;
    }
    return count;
}

int my_printf_flag_a_cap(va_list *ap, int precision)
{
    int count;
    int last;
    double nb = va_arg(*ap, double);

    if (precision == -1)
        precision = 13;
    if (nb < 0) {
        nb = -nb;
        my_putchar('-');
    }
    last = set_one(&nb);
    nb -= 1;
    my_putstr("0X1.");
    count = convert_a(nb, 0, precision);
    my_putstr("P+");
    count += my_put_nbr(last, 0);
    return count + 6;
}
