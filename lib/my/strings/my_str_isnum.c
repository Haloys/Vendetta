/*
** EPITECH PROJECT, 2024
** my_str_isnum
** File description:
** function de fou
*/

int my_str_isnum(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (!(str[i] >= '0' && str[i] <= '9')) {
            return 0;
        }
        ++i;
    }
    return 1;
}
