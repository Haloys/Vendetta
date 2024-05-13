/*
** EPITECH PROJECT, 2024
** Vendetta / Header
** File description:
** My Header
*/

#include <stdarg.h>

#ifndef MY_H_
    #define MY_H_

    #include <stddef.h>
    #define MAX_INTSTR_LENGTH 12

void *my_memcpy(void *dest, const void *src, size_t size);
int my_char_isalpha(char c);
int free_array_elements(char **array);
void my_putchar(char c);
char *my_strstr(char *str, char const *to_find);
int my_isneg(int nb);
int my_strcmp(char const *s1, char const *s2);
int my_put_nbr(int nb, int count);
int my_strncmp(char const *s1, char const *s2, int n);
void my_swap(int *a, int *b);
char *my_strupcase(char *str);
int my_putstr(char const *str);
int my_putstr_offset(char const *str, unsigned int max_len);
char *my_strlowcase(char *str);
int my_strlen(char const *str);
char *my_strcapitalize(char *str);
int my_getnbr(char const *str);
int my_getnbr_offset(char const *str, int offset);
int my_get_nbr_length(int nb);
int my_str_isalpha(char const *str);
void my_sort_int_array(int *tab, int size);
int my_str_isnum(char const *str);
int my_compute_power_rec(int nb, int power);
int my_str_islower(char const *str);
int my_compute_square_root(int nb);
int my_str_isupper(char const *str);
int my_is_prime(int nb);
int my_str_isprintable(char const *str);
int my_find_prime_sup(int nb);
int my_get_array_len(char **array);
int my_showstr(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_showmem(char const *str, int size);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcat(char *dest, char const *src);
char **my_realloc_strings(char **array, int size);
char *my_revstr(char *str);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strconcat(char *str, char *str_bis);
char *my_strconcat2(int count, ...);

char *my_nbrstr(int nbr);

int is_overflow_2(int);
void convert(void);
int is_big(int);
int is_nbr(char);
int my_print_alpha(void);
int my_print_digits(void);
int my_print_revalpha(void);
void set_length(void);
int my_show_word_array(char *const *tab);
int is_alpha(char c);
int is_numeric(char c);
char **my_str_to_word_array(char const *str);
char **my_str_to_word_array2(char *str, const char *delimiters);
int is_an(char c);
char *my_strdup(char const *src);
int len_nbr(long long nb);
int len_dec_2(double nb);
int get_nb_f(double nb, int precision);
int min(int a, int b);
int display_zero(int nb_zero);
char *my_strtok(char *str, const char *delimiters);


typedef int (*function) (va_list *, int);
int my_printf(const char *str, ...);
int invalid_flag(va_list *ap, int precision);
int my_printf_flag_c(va_list *ap, int precision);
int my_printf_flag_s(va_list *ap, int precision);
int my_printf_flag_d_i(va_list *ap, int precision);
int my_printf_flag_prc(va_list *ap, int precision);
int my_printf_flag_x(va_list *ap, int precision);
int my_printf_flag_x_cap(va_list *ap, int precision);
int my_printf_flag_o(va_list *ap, int precision);
int my_printf_flag_f(va_list *ap, int precision);
int my_printf_flag_e(va_list *ap, int precision);
int my_printf_flag_g(va_list *ap, int precision);
int my_printf_flag_p(va_list *ap, int precision);
int my_printf_flag_u(va_list *ap, int precision);
int my_printf_flag_n(va_list *ap, int count);
int my_printf_flag_a(va_list *ap, int precision);
int my_printf_flag_a_cap(va_list *ap, int precision);
int my_printf_flag_e_cap(va_list *ap, int precision);
int my_printf_flag_g_cap(va_list *ap, int precision);


#endif /* MY_H_ */
