/*
** EPITECH PROJECT, 2024
** my_printf_flag_d_i
** File description:
** print a char
*/

#include "../../my.h"
#include <stdarg.h>

int my_printf_flag_d_i(va_list *ap, int precision)
{
    int nbr = va_arg(*ap, int);
    int count = 0;

    if (nbr >= 0) {
        if (precision == 1) {
            my_putchar('+');
            ++count;
        }
        if (precision == 2) {
            my_putchar(' ');
            ++count;
        }
    }
    count += my_put_nbr(nbr, 0);
    return count;
}
