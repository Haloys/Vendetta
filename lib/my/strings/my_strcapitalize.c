/*
** EPITECH PROJECT, 2024
** my_strcapitalize
** File description:
** function de fou vraiment
*/

char *my_strcapitalize(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if ((i == 0 || str[i - 1] == ' ' || str[i - 1] == '-'
            || str[i - 1] == '+') && str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
        }
        if (i != 0 && (str[i - 1] != '-' && str[i - 1] != '+'
            && str[i - 1] != ' ') && str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32;
        }
        ++i;
    }
    return str;
}
