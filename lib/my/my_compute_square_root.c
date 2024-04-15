/*
** EPITECH PROJECT, 2024
** my_compute_square_root
** File description:
** function
*/

int my_compute_square_root(int nb)
{
    int is_pair = !(nb % 2);
    int i = is_pair ? 0 : 1;

    if (nb < 1)
        return 0;
    if (nb == 1)
        return 1;
    while (i <= (nb / 2)) {
        if ((i * i) == nb) {
            return i;
        }
        i += 2;
    }
    return 0;
}
