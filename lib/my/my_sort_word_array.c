/*
** EPITECH PROJECT, 2024
** my_sort_word_array
** File description:
** function
*/

static void process_sort(char **array, int i, const int len)
{
    int j = i;
    char *temp;

    while (j < len - 1) {
        if (array[j][0] > array[j + 1][0]) {
            temp = array[j];
            array[j] = array[j + 1];
            array[j + 1] = temp;
        }
        ++j;
    }
}

static int array_len(char **array)
{
    int i = 0;

    while (array[i]) {
        ++i;
    }
    return i;
}

int my_sort_word_array(char **tab)
{
    int len = array_len(tab);

    for (int i = 0; i < len; ++i) {
        process_sort(tab, i, len);
    }
    return 0;
}
