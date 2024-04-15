/*
** EPITECH PROJECT, 2024
** my_compute_power_it
** File description:
** function
*/

int is_overflow_2(int nbr)
{
    int temp = nbr * 10;

    if (temp / 10 != nbr)
        return 1;
    return 0;
}

int my_compute_power_rec(int nb, int p)
{
    if (p == 0)
        return 1;
    if (p < 0 || is_overflow_2(nb))
        return 0;
    if (p == 1)
        return nb;
    return nb * my_compute_power_rec(nb, p - 1);
}
