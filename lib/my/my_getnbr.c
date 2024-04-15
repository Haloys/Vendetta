/*
** EPITECH PROJECT, 2024
** my_getnbr
** File description:
** function
*/

int is_nbr(char n)
{
    if (n >= '0' && n <= '9') {
        return 1;
    }
    return 0;
}

long long is_big(long long nbr)
{
    if (nbr > 2147483647 || nbr < -2147483648) {
        return (1);
    }
    return (0);
}

long long convert(int negative, long long n)
{
    return ((negative % 2) == 1 ? n * -1 : n);
}

static int getnbr(char const *str, int offset)
{
    int negative = 0;
    long long nbr = 0;
    int i = offset;
    int check_sign = 1;
    int loop = 1;

    while (loop && str[i] != '\0') {
        if (check_sign && str[i] == '-')
            ++negative;
        if (str[i] != '-' && str[i] != '+' && !is_nbr(str[i]))
            loop = 0;
        if (is_nbr(str[i])) {
            nbr = nbr * 10 + (str[i] - '0');
            check_sign = 0;
        }
        if (is_big(convert(negative, nbr)))
            return (0);
        ++i;
    }
    return convert(negative, nbr);
}

int my_getnbr(char const *str)
{
    return getnbr(str, 0);
}

int my_getnbr_offset(char const *str, int offset)
{
    return getnbr(str, offset);
}
