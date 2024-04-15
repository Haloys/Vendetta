/*
** EPITECH PROJECT, 2024
** my_strcmp
** File description:
** function de fou vraiment
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] == s2[i]) {
        if (s2[i] == '\0')
            return 0;
        ++i;
    }
    return (s1[i] - s2[i]);
}
