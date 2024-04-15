/*
** EPITECH PROJECT, 2024
** my_strncmp
** File description:
** function de fou vraiment
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    if (n < 1)
        return 0;
    while (s1[i] == s2[i] && i < (n - 1)) {
        if (s2[i] == '\0')
            return 0;
        ++i;
    }
    return s1[i] - s2[i];
}
