/*
** EPITECH PROJECT, 2024
** fmy_printf_lag_s
** File description:
** print a string (char *)
*/

#include "../../my.h"
#include <stdarg.h>

int my_printf_flag_s(va_list *ap, int precision)
{
    return my_putstr_offset(va_arg(*ap, char *), precision);
}
