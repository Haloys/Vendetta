##
## EPITECH PROJECT, 2024
## makefile
## File description:
## Makefile of the project
##

BINARY_NAME	=	my_rpg

NAME_TEST	=	unit_tests

CFLAGS	=	-Wall -Wextra -Wno-unused-variable

CPPFLAGS	=	-iquote./include

LDFLAGS	=	-L./lib

LDLIBS	=	-lmy -lcsfml-audio -lcsfml-graphics -lcsfml-system -lcsfml-window \
			-lm

LIB_PATH	=	./lib/my

SRC_MAIN	=	./src/main.c \

SRC	=	./src/help.c \
		./src/init.c \
		./src/init_assets.c \
		./src/list.c \
		./src/process_loop.c \
		./src/engine/my_clock.c \
		./src/engine/animation.c \
		./src/engine/utils.c \
		./src/engine/free_game.c \
		./src/engine/entity/destroy.c \
		./src/engine/entity/entity.c \
		./src/engine/entity/hitboxes.c \
		./src/engine/entity/plane.c \
		./src/engine/fade_in_out.c \
		./src/score_manager.c \
		./src/music.c \
		./src/events.c \
		./src/events/menu/mouse_button_pressed.c \
		./src/events/playing/mouse_button_pressed.c \
		./src/loading_screen/loading.c \
		./src/main_menu/main_menu.c \
		./src/main_menu/navbar.c \
		./src/main_menu/settings.c \
		./src/settings/settings_fps.c \
		./src/settings/settings_screen.c \
		./src/main_menu/help.c \
		./src/screne_loop/playing.c

SRC_TESTS	=	\

CRITERION_FLAGS	=	$(CFLAGS) ${LDFLAGS} ${LDLIBS} --coverage -lcriterion

OBJ	=	$(SRC_MAIN:.c=.o) $(SRC:.c=.o)

all:	$(BINARY_NAME)

build_lib:
	make -C ${LIB_PATH}

clean_lib:
	make fclean -C ${LIB_PATH}

$(BINARY_NAME):	build_lib $(OBJ)
	$(CC) -o $(BINARY_NAME) ${OBJ} ${LDFLAGS} ${LDLIBS}
	touch ./database/highest_score

clean:
	${RM} $(OBJ)

fclean:	clean
	${RM} $(BINARY_NAME)

c_all: clean_lib fclean

re:	fclean all

debug:	CFLAGS += -g3
debug:	re

tests_run:	build_lib
	${CC} ${SRC} $(SRC_TESTS) -o ${NAME_TEST} ${CRITERION_FLAGS}
	./${NAME_TEST}

gcovr:
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches

.PHONY:	all build_lib clean_lib clean fclean c_all re debug tests_run gcovr
