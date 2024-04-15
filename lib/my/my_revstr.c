/*
** EPITECH PROJECT, 2024
** my_revstr.c
** File description:
** function de fou
*/

char *my_revstr(char *str)
{
    int i = 0;
    int str_len = 0;
    char temp;

    while (str[str_len] != '\0') {
        ++str_len;
    }
    while (i < (str_len / 2)) {
        temp = str[i];
        str[i] = str[str_len - 1 - i];
        str[str_len - 1 - i] = temp;
        ++i;
    }
    return str;
}
