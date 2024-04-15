/*
** EPITECH PROJECT, 2024
** FLAG_U
** File description:
** print an unsigned int
*/

#include <unistd.h>
#include <stdarg.h>
#include "../../my.h"

int my_printf_flag_u(va_list *ap, int precision)
{
    unsigned int nb = va_arg(*ap, unsigned int);

    return my_put_nbr(nb, 0);
}
