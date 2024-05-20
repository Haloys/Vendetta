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

LDLIBS      = 	-lcsfml-audio -lcsfml-graphics -lcsfml-system \
				-lcsfml-window -lm

SRC_MAIN    = ./src/main.c \

SRC_DIR     = ./src
BUILD_DIR   = ./build


#############
## SOURCES ##
#############


SRC_ENGINE        =   	engine/my_clock.c \
						engine/animation.c \
						engine/utils.c \
						engine/utils_two.c \
						engine/free_game.c \
						engine/fade_in_out.c \
						engine/enemy/enemy.c \
						engine/enemy/update.c \
						engine/player/update.c \

SRC_FILES            =   	help.c \
							init.c \
							init_assets.c \
							process_loop.c \
							music.c \
							events.c \

SRC_UI    =   	loading_screen/loading.c \
				main_menu/main_menu.c \
				main_menu/hover_main_menu.c \
				main_menu/help/help_menu.c \
				main_menu/navbar/navbar.c \
				main_menu/navbar/navbar_settings.c \
				main_menu/settings/settings_fps.c \
				main_menu/settings/settings_screen.c \
				main_menu/settings/settings_utils.c \
				main_menu/settings/settings_resolution.c \
				main_menu/settings/settings_audio.c \
				main_menu/settings/settings_audio_utils.c \
				main_menu/save/save_ui.c \
				main_menu/save/save_text_type.c \
				main_menu/save/valid_save.c \


SRC_INVENTORY    =   	inventory/inventory.c \
						inventory/inventory_utils.c \
						inventory/inventory_management.c \
						inventory/display_items.c \
						inventory/handle_drag_drop.c \
						inventory/display_labels.c \

SRC_SKILL_TREE	=   	skill_tree/skill_tree.c \
						skill_tree/display_tree.c \
						skill_tree/spend_tree.c \

SRC_GAMEPLAY	=	gameplay/gameplay.c \
					gameplay/events/movement.c \
					gameplay/utils.c \
					gameplay/key_management.c \
					gameplay/is_key.c

SRC_INIT	=   	init/game_icon.c \
					init/map.c \
					init/player.c \
					init/view.c \
					init/enemies.c \

SRC_DIALOGUES =   	npc_dialogues/choice_box.c \
					npc_dialogues/load_dialogue.c \
					npc_dialogues/handle_text.c \
					npc_dialogues/dialogues_event.c \
					npc_dialogues/init_dialogue.c \
					npc_dialogues/utils.c \

SRC_MINIGAME =   	minigame/sequence_click.c \
					minigame/utils.c \
					minigame/barhit.c \

SRC_UTILS	=   	utils/utils.c \
					utils/list.c \

SRC =         $(addprefix $(SRC_DIR)/,$(SRC_ENGINE)) \
            $(addprefix $(SRC_DIR)/,$(SRC_FILES)) \
            $(addprefix $(SRC_DIR)/,$(SRC_UI)) \
			$(addprefix $(SRC_DIR)/,$(SRC_INVENTORY)) \
			$(addprefix $(SRC_DIR)/,$(SRC_GAMEPLAY)) \
			$(addprefix $(SRC_DIR)/,$(SRC_INIT)) \
			$(addprefix $(SRC_DIR)/,$(SRC_DIALOGUES)) \
			$(addprefix $(SRC_DIR)/,$(SRC_UTILS)) \
			$(addprefix $(SRC_DIR)/,$(SRC_SKILL_TREE)) \
			$(addprefix $(SRC_DIR)/,$(SRC_MINIGAME)) \

OBJ =		$(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC_MAIN)) \
			$(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC))


###########
## RULES ##
###########


$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@printf "$(GREEN)[OK]$(RESET) $(BLUE)Building $<...$(RESET)\n"
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

all: $(BINARY_NAME)

re_lib:
	@printf "$(GREEN)[OK]$(RESET) $(BLUE)Rebuilding library...$(RESET)\n"
	@$(MAKE) re -C $(LIB_PATH) > /dev/null 2>&1

$(BINARY_NAME): $(OBJ)
	@printf "$(GREEN)[OK]$(RESET) $(BLUE)Linking project...$(RESET)\n"
	@$(CC) -o $(BINARY_NAME) $(OBJ) $(LDFLAGS) $(LDLIBS)
	@printf "$(GREEN)[OK]$(RESET) $(BLUE)Project built successfully$(RESET)\n"

clean:
	@printf "$(GREEN)[OK]$(RESET) $(BLUE)Cleaning project...$(RESET)\n"
	@$(RM) -r $(BUILD_DIR)

fclean: clean
	@printf "$(GREEN)[OK]$(RESET) $(BLUE)Removing project...$(RESET)\n"
	@$(RM) $(BINARY_NAME)

c_all: fclean

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
