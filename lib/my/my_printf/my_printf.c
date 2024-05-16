/*
** EPITECH PROJECT, 2024
** my_printf
** File description:
** my_printf with azeloup & flav-code
*/

#include <stdarg.h>
#include "../my.h"

function_t ope_flag[256] = {invalid_flag};
static const char lm[] = ".+-";

int invalid_flag(va_list *ap, int precision)
{
    return 0;
}

void init_flags_table(void)
{
    ope_flag['c'] = my_printf_flag_c;
    ope_flag['s'] = my_printf_flag_s;
    ope_flag['d'] = my_printf_flag_d_i;
    ope_flag['i'] = my_printf_flag_d_i;
    ope_flag['%'] = my_printf_flag_prc;
    ope_flag['x'] = my_printf_flag_x;
    ope_flag['X'] = my_printf_flag_x_cap;
    ope_flag['o'] = my_printf_flag_o;
    ope_flag['f'] = my_printf_flag_f;
    ope_flag['e'] = my_printf_flag_e;
    ope_flag['g'] = my_printf_flag_g;
    ope_flag['p'] = my_printf_flag_p;
    ope_flag['u'] = my_printf_flag_u;
    ope_flag['n'] = my_printf_flag_n;
    ope_flag['a'] = my_printf_flag_a;
    ope_flag['A'] = my_printf_flag_a_cap;
    ope_flag['E'] = my_printf_flag_e_cap;
    ope_flag['G'] = my_printf_flag_g_cap;
}

static int length_modif(const char *str, int *i, int *precision, int *offset)
{
    int position = *i + 1 + *offset;

    if (str[position] == '.') {
        *precision = my_getnbr_offset(str, *i + 2);
        *offset = my_get_nbr_length(*precision) + 1;
    }
    if (str[position] == '+' || str[position] == '#') {
        *offset += 1;
        *precision = 1;
    }
    if (str[position] == '-') {
        *offset += 1;
    }
    if (str[position] == ' ') {
        *offset += 1;
        *precision = 2;
    }
    return 0;
}

static int process(const char *str, int *i, int count, va_list *ap)
{
    int precision = -1;
    int offset = 0;

    for (int n = 0; lm[n]; ++n)
        length_modif(str, i, &precision, &offset);
    if (str[*i + 1] == 'n')
        precision = count;
    *i += offset;
    return (ope_flag[str[*i + 1]])(ap, precision);
}

int my_printf(const char *str, ...)
{
    va_list ap;
    int count = 0;

    init_flags_table();
    va_start(ap, str);
    for (int i = 0; str[i]; ++i) {
        if (str[i] == '%') {
            count += process(str, &i, count, &ap);
            ++i;
        } else {
            my_putchar(str[i]);
            ++count;
        }
    }
    va_end(ap);
    return count;
}
