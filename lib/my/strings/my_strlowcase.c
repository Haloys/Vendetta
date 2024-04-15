/*
** EPITECH PROJECT, 2024
** my_strlowcase.c
** File description:
** function de fou vraiment
*/

char *my_strlowcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32;
        }
        ++i;
    }
    return str;
}
