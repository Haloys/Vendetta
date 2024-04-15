/*
** EPITECH PROJECT, 2024
** my_is_prime
** File description:
** function de fou
*/

int my_is_prime(int nb)
{
    int i = 2;

    if (nb < 2)
        return 0;
    if (nb == 2)
        return 1;
    while (i <= nb / 2) {
        if (!(nb % i)) {
            return 0;
        }
        ++i;
    }
    return 1;
}
