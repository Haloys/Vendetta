/*
** EPITECH PROJECT, 2024
** my_char_isalpha
** File description:
** function de fou
*/

int my_char_isalpha(char c)
{
    if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
        return 1;
    return 0;
}
