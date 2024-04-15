/*
** EPITECH PROJECT, 2024
** my_printf_flag_f
** File description:
** put double
*/

#include "../../my.h"
#include <stdio.h>

static int get_nb(double nb, int precision)
{
    int len = 0;

    while (nb != (int)nb && precision > 0) {
        nb *= 10;
        len += 1;
        precision--;
    }
    return (int)nb;
}

static int len_dec(double nb)
{
    int len = 0;

    while (nb != (int)nb) {
        nb *= 10;
        len += 1;
    }
    return len;
}

int my_put_float(int nb, int len)
{
    long int nbr = nb;

    if (nbr < 0) {
        my_putchar('-');
        nbr *= -1;
    }
    if (nbr < 10) {
        my_putchar(nbr + '0');
    } else {
        my_put_float(nbr / 10, len - 1);
        my_putchar(nbr % 10 + '0');
        if (len == 0) {
            my_putchar('.');
        }
    }
    return 0;
}

static int main_f(double nb, int precision)
{
    int i = get_nb(nb, precision);
    int len = len_nbr(i);
    int nb_point = len - len_dec(nb);
    int nb_zero = precision - nb_point;

    my_put_float(i, nb_point);
    display_zero(nb_zero);
}

int my_printf_flag_f(va_list *ap, int precision)
{
    double nb = va_arg(*ap, double);

    main_f(nb, precision);
}
