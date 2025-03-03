NAME := push_swap
ifdef BONUS
  NAME := checker
endif

NAME_BONUS := checker

SRC:= $(addprefix $(SRC_DIR), tools.c pars.c list.c tools_pars.c algo.c algo_tools.c tools2.c  utils.c kr_tools.c kr_utils.c)
ifdef BONUS
	SRC:= $(SRC) $(addprefix $(SRC_DIR), checker_init.c checker_tools.c)
else	
	SRC:= $(SRC) $(addprefix $(SRC_DIR), init.c)
endif
OBJ_DIR:= .obj/
OBJ:= $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
DEPS:= $(OBJ:%.o=%.d)

CC:= cc
CCFLAGS:= -Wextra -Wall -Werror 
CPPFLAGS = -MMD -MP
SRC_DIR:= src/
INCLUDES:= include/ 	

LIBFT_DIR := libft/
LIBFT := $(LIBFT_DIR)libft.a 
LIBFT_FLAG := -L $(LIBFT_DIR) $(LIBFT)
LIBFT_DEPS := $(LIBFT_DIR)Makefile

HEADERS:= -I $(INCLUDES) -I $(LIBFT_DIR)

all: welcome $(NAME)

$(NAME):  $(LIBFT) $(OBJ)
	$(CC) $(CCFLAGS) $(OBJ) $(LIBFT_FLAG) -o $(NAME)
	@echo "👨‍🍳 Cooking up binary goodness: $(BLUE)$(CC) $(CCFLAGS) $(OBJ) $(LIBFT_FLAG) -o $(NAME)$(DEF_COLOR)"
	@echo "$(GREEN)🧝‍♂️ Un lutin a aidé à compiler $(NAME)! Joyeux Noël ! 🧝‍♂️$(DEF_COLOR)"
	
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@echo "🛠️  $(MAGENTA)Compiling: $< $(DEF_COLOR)"
	$(CC) $(CCFLAGS) $(CPPFLAGS) $(HEADERS) -o $@ -c $<

$(LIBFT): libft

libft:
	$(MAKE) -C $(LIBFT_DIR)



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

bonus:
	$(MAKE) BONUS=1 all
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
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME) $(NAME_BONUS)
re: fclean all

info:
	@echo "OBJ": $(OBJ)
	@echo "DEPS": $(DEPS)

-include $(DEPS)

.PHONY: all clean fclean re libft