/*
** EPITECH PROJECT, 2024
** my_printf_flag_n
** File description:
** put the count var into the va_list
*/

#include <stdarg.h>

int my_printf_flag_n(va_list *ap, int count)
{
    *(va_arg(*ap, int *)) = count;
    return 0;
}
