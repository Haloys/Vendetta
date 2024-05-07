##
## EPITECH PROJECT, 2024
## makefile
## File description:
## Makefile of the project
##


############
## COLORS ##
############


GREEN        = \033[0;32m
RESET         = \033[0m
BLUE          = \033[94m


###########
## BUILD ##
###########


CC          = gcc

MAKE        = make

BINARY_NAME = my_rpg

NAME_TEST   = unit_tests

CFLAGS      = -Wall -Wextra

CPPFLAGS    = -iquote ./include

LDFLAGS     = -L./lib

LDLIBS      = -lmy -lcsfml-audio -lcsfml-graphics -lcsfml-system -lcsfml-window -lm

LIB_PATH    = ./lib/my

SRC_MAIN    = ./src/main.c \

SRC_DIR     = ./src
BUILD_DIR   = ./build


#############
## SOURCES ##
#############


SRC_ENGINE        =   	engine/my_clock.c \
						engine/animation.c \
						engine/utils.c \
						engine/free_game.c \
						engine/entity/destroy.c \
						engine/entity/entity.c \
						engine/entity/hitboxes.c \
						engine/entity/plane.c \
						engine/fade_in_out.c \

SRC_FILES            =   	help.c \
							init.c \
							init_assets.c \
							list.c \
							process_loop.c \
							score_manager.c \
							music.c \
							events.c \

SRC_UI    =   	loading_screen/loading.c \
				main_menu/main_menu.c \
				main_menu/navbar.c \
				main_menu/settings.c \
				settings/settings_fps.c \
				settings/settings_screen.c \
				settings/settings_utils.c \
				main_menu/help.c \
				settings/settings_resolution.c \
				screne_loop/playing.c

SRC_EVENTS    =	  events/menu/mouse_button_pressed.c \
				  events/playing/mouse_button_pressed.c \

SRC =         $(addprefix $(SRC_DIR)/,$(SRC_ENGINE)) \
            $(addprefix $(SRC_DIR)/,$(SRC_FILES)) \
			$(addprefix $(SRC_DIR)/,$(SRC_EVENTS)) \
            $(addprefix $(SRC_DIR)/,$(SRC_UI))

OBJ =         $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC_MAIN)) \
              $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC))


###########
## RULES ##
###########


$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@printf "$(GREEN)[OK]$(RESET) $(BLUE)Building $<...$(RESET)\n"
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

all: $(BINARY_NAME)

build_lib:
	@printf "$(GREEN)[OK]$(RESET) $(BLUE)Building library...$(RESET)\n"
	@$(MAKE) -C $(LIB_PATH) --no-print-directory > /dev/null 2>&1

clean_lib:
	@printf "$(GREEN)[OK]$(RESET) $(BLUE)Cleaning library...$(RESET)\n"
	@$(MAKE) fclean -C $(LIB_PATH) > /dev/null 2>&1

re_lib:
	@printf "$(GREEN)[OK]$(RESET) $(BLUE)Rebuilding library...$(RESET)\n"
	@$(MAKE) re -C $(LIB_PATH) > /dev/null 2>&1

$(BINARY_NAME): build_lib $(OBJ)
	@printf "$(GREEN)[OK]$(RESET) $(BLUE)Linking project...$(RESET)\n"
	@$(CC) -o $(BINARY_NAME) $(OBJ) $(LDFLAGS) $(LDLIBS)
	@printf "$(GREEN)[OK]$(RESET) $(BLUE)Project built successfully$(RESET)\n"

clean:
	@printf "$(GREEN)[OK]$(RESET) $(BLUE)Cleaning project...$(RESET)\n"
	@$(RM) -r $(BUILD_DIR)

fclean: clean
	@printf "$(GREEN)[OK]$(RESET) $(BLUE)Removing project...$(RESET)\n"
	@$(RM) $(BINARY_NAME)

c_all: clean_lib fclean

re: fclean all

debug: CFLAGS += -g3
debug: re

tests_run: build_lib
	@$(CC) $(SRC) $(SRC_TESTS) -o $(NAME_TEST) $(CRITERION_FLAGS)
	@./$(NAME_TEST)

gcovr:
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches

.PHONY: all build_lib clean_lib re_lib clean fclean c_all re debug tests_run \
    gcovr