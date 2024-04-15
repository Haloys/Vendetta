/*
** EPITECH PROJECT, 2024
** utils
** File description:
** utils lol
*/

int is_alpha(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return 1;
    return 0;
}

int is_numeric(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}
