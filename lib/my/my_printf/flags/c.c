/*
** EPITECH PROJECT, 2024
** my_printf_flag_c
** File description:
** print a char
*/

#include "../../my.h"
#include <stdarg.h>

int my_printf_flag_c(va_list *ap, int precision)
{
    my_putchar((char) va_arg(*ap, int));
    return 1;
}
