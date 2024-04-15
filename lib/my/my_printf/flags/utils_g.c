/*
** EPITECH PROJECT, 2024
** UTILS_FOR_G
** File description:
** fonction that i use for g
*/

int get_nb_f(double nb, int precision)
{
    int len = 0;

    while (nb != (int)nb && precision > 0) {
        nb *= 10;
        len += 1;
        precision--;
    }
    return (int)nb;
}

int len_dec_2(double nb)
{
    int multiplier = 10;
    int len = 0;
    double tiny = 0.00000001;

    while (tiny >= nb * multiplier - (int)(nb * multiplier) <= tiny) {
        multiplier *= 10;
        len++;
    }
    return len;
}

/*
int get_nb_2(double nb)
{
    int multiplier = 10;

    while (nb * multiplier != (int)(nb * multiplier)) {
        multiplier *= 10;
    }
    return (int)(nb * multiplier);
}
*/
