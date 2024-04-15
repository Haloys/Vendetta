##
## EPITECH PROJECT, 2024
## makefile
## File description:
## Build lib & copy libmy.a to the root
##

NAME	=	libmy.a

FOLDER_MY_PRINTF	=	./my_printf/my_printf.c \
						./my_printf/flags/c.c \
						./my_printf/flags/s.c \
						./my_printf/flags/d_i.c \
						./my_printf/flags/prc.c \
						./my_printf/flags/x.c \
						./my_printf/flags/x_cap.c \
						./my_printf/flags/o.c \
						./my_printf/flags/f.c \
						./my_printf/flags/e.c \
						./my_printf/flags/utils_g.c \
						./my_printf/flags/g.c \
						./my_printf/flags/p.c \
						./my_printf/flags/u.c \
						./my_printf/flags/n.c \
						./my_printf/flags/a.c \
						./my_printf/flags/a_cap.c \
						./my_printf/flags/e_cap.c \
						./my_printf/flags/g_cap.c

FOLDER_STRINGS	=	./strings/my_char_isalpha.c \
					./strings/my_str_isalpha.c \
					./strings/my_str_islower.c \
					./strings/my_str_isnum.c \
					./strings/my_str_isprintable.c \
					./strings/my_str_isupper.c \
					./strings/my_str_to_word_array.c \
					./strings/my_str_to_word_array2.c \
					./strings/my_strcapitalize.c \
					./strings/my_strcat.c	\
					./strings/my_strcmp.c \
					./strings/my_strconcat.c \
					./strings/my_strconcat2.c \
					./strings/my_strcpy.c \
					./strings/my_strdup.c \
					./strings/my_strlen.c \
					./strings/my_strlowcase.c \
					./strings/my_strncat.c \
					./strings/my_strncmp.c \
					./strings/my_strncpy.c \
					./strings/my_strstr.c \
					./strings/my_strtok.c \
					./strings/my_strupcase.c

SRC	=	${FOLDER_MY_PRINTF} \
		${FOLDER_STRINGS} \
		free_array_elements.c \
		my_compute_power_rec.c \
		my_compute_square_root.c \
		my_find_prime_sup.c \
		my_get_array_len.c \
		my_getnbr.c \
		my_memcpy.c \
		my_isneg.c \
		my_nbrstr.c \
		my_is_prime.c \
		my_print_alpha.c \
		my_print_digits.c \
		my_print_revalpha.c \
		my_putchar.c \
		my_put_nbr.c \
		my_get_nbr_length.c \
		my_putstr.c \
		my_realloc_strings.c \
		my_revstr.c \
		my_showmem.c \
		my_showstr.c \
		my_show_word_array.c \
		my_sort_int_array.c \
		my_swap.c \
		display_zero.c \
		len_nbr.c \
		min.c \
		utils.c

CFLAGS	=	\

OBJ	=	$(SRC:.c=.o)

INCLUDE_PATH	=	../../include/

all:	$(NAME)

$(NAME):	$(OBJ)
	@ar rc $(NAME) $(OBJ) ${CFLAGS}
	@cp $(NAME) ../
	@mkdir -p ${INCLUDE_PATH}
	@cp my.h ${INCLUDE_PATH}

clean:
	@rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re:	fclean all

debug:	CFLAGS += -g3
debug:	re

.PHONY: all clean fclean re debug
