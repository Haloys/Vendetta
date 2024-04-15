/*
** EPITECH PROJECT, 2024
** my_str_isalpha
** File description:
** function de fou
*/

int my_str_isalpha(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (!(str[i] >= 'a' && str[i] <= 'z'
            || str[i] >= 'A' && str[i] <= 'Z')) {
            return 0;
        }
        ++i;
    }
    return 1;
}
