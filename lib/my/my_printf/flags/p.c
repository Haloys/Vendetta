/*
** EPITECH PROJECT, 2024
** FLAG_P
** File description:
** print a pointer memory adress
*/

#include <unistd.h>
#include <stdarg.h>

static int convert_x(long long nb, int count)
{
    int to_print = nb % 16;

    if (nb == 0) {
        return count;
    }
    if (to_print > 9) {
        to_print += 'W';
    } else {
        to_print += '0';
    }
    nb /= 16;
    count = convert_x(nb, count + 1);
    write(1, &to_print, 1);
    return count;
}

int my_printf_flag_p(va_list *ap, int precision)
{
    long long nb = va_arg(*ap, long long);

    return convert_x(nb, 0);
}
