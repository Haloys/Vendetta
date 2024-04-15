/*
** EPITECH PROJECT, 2024
** my_str_isupper
** File description:
** function de fou
*/

int my_str_isupper(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (!(str[i] >= 'A' && str[i] <= 'Z')) {
            return 0;
        }
        ++i;
    }
    return 1;
}
