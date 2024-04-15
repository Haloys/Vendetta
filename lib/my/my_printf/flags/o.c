/*
** EPITECH PROJECT, 2024
** my_printf_flag_o
** File description:
** convertit en hexa ou en octale
*/

#include <unistd.h>
#include <stdarg.h>
#include "../../my.h"

int convert_o(unsigned int nb, int count)
{
    int to_print = nb % 8;

    if (nb == 0) {
        return count;
    }
    if (to_print > 9) {
        to_print += 'W';
    } else {
        to_print += '0';
    }
    nb /= 8;
    count = convert_o(nb, count + 1);
    write(1, &to_print, 1);
    return count;
}

int my_printf_flag_o(va_list *ap, int precision)
{
    unsigned int nb = va_arg(*ap, unsigned int);
    int count = 0;

    if (precision == 1 || nb == 0) {
        my_putchar('0');
        ++count;
    }
    count += convert_o(nb, 0);
    return count;
}
