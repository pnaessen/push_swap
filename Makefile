NAME := push_swap

SRC:= $(addprefix $(SRC_DIR), init.c tools.c pars.c list.c tools_pars.c algo.c)
OBJ_DIR:= .obj/
OBJ:= $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
DEPS:= $(OBJ:%.o=%.d)

CC:= cc
CCFLAGS:= -Wextra -Wall -Werror 
CPPFLAGS = -MMD -MP
SRC_DIR:= src/
INCLUDES:= include/

HEADERS:= -I $(INCLUDES)

all: welcome $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CCFLAGS) $(OBJ) -o $(NAME)
	@echo "👨‍🍳 Cooking up binary goodness: $(BLUE)$(CC) $(CCFLAGS) $(OBJ)  -o $(NAME)$(DEF_COLOR)"
	@echo "$(GREEN)🧝‍♂️ Un lutin a aidé à compiler $(NAME)! Joyeux Noël ! 🧝‍♂️$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@echo "🛠️  $(MAGENTA)Compiling: $< $(DEF_COLOR)"
	$(CC) $(CCFLAGS) $(CPPFLAGS) $(HEADERS) -o $@ -c $<

-include $(DEPS)
# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

welcome:
	@echo "🚀 $(CYAN)Starting compilation of $(NAME)... Hold on to your bits! $(DEF_COLOR)"

clean:
	@echo "🧹 $(YELLOW)Cleaning object files...$(DEF_COLOR)"
	rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(RED)"
	@echo "        . . . . . . . . . ."
	@echo "      .     *     *     *"
	@echo "   .       *       *       ."
	@echo "         *   BOOM!   *"
	@echo "      .       *       *       ."
	@echo "    *     *     *     *     *"
	@echo "      ' . . . . . . . . '"
	@echo "$(DEF_COLOR)"
	@echo "$(RED)🧨🧨🧨🧨🧨💥 $(NAME) remove 💥🧨🧨🧨🧨🧨 $(DEF_COLOR)"
	rm -f $(NAME)

re: fclean all


# explosion:
#	@echo "$(RED)💥 Animation d'explosion...$(DEF_COLOR)"
#	@bash -c ' \
	for i in {1..5}; do \
		clear; \
		echo "        *        "; \
		echo "       ***       "; \
		echo "      *****      "; \
		echo "     *******     "; \
		echo "    *********    "; \
		sleep 0.5; \
	done; \
	clear; \
	echo "(Il n\'y a rien ici)"; \
	'
info:
	@echo "OBJ": $(OBJ)
	@echo "DEPS": $(DEPS)

.PHONY: all clean fclean re