/*
** EPITECH PROJECT, 2024
** my_str_islower
** File description:
** function de fou
*/

int my_str_islower(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (!(str[i] >= 'a' && str[i] <= 'z')) {
            return 0;
        }
        ++i;
    }
    return 1;
}
