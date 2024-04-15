/*
** EPITECH PROJECT, 2024
** my_strcat
** File description:
** function de fou
*/

char *my_strcat(char *dest, char const *src)
{
    int dest_offset = my_strlen(dest);
    int i = 0;

    while (src[i] != '\0') {
        dest[dest_offset + i] = src[i];
        ++i;
    }
    dest[dest_offset + i] = '\0';
    return dest;
}
