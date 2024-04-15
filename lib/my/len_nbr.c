/*
** EPITECH PROJECT, 2024
** len_nbr
** File description:
** my put str
*/

int len_nbr(long long nb)
{
    int len = 0;

    while (nb != 0) {
        len++;
        nb /= 10;
    }
    return len;
}
