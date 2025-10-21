# Noms
NAME = Base
OBJ_DIR = obj

# Repertorys
SRCS_DIR = src/
INCS_DIR = include/

# Libraries


# Compilation
CC = c++
WFLAGS = -g3 -std=c++98
CFLAGS  = $(WFLAGS) -I$(INCS_DIR) -O3
DEPFLAGS = -MMD -MP

# Debug flags
CFLAGS += -DNO_DEBUG_CONSTRUCTORS

# Affichage
GREEN = \033[32m
YELLOW = \033[33m
CYAN = \033[36m
RESET = \033[0m
CLEAR = \033[2K\r


# Sources
COMMON_SRC = Base.cpp main.cpp
COMMON_SRCS = $(addprefix $(SRCS_DIR), $(COMMON_SRC))
OBJ_FILES = $(patsubst $(SRCS_DIR)%.cpp,$(OBJ_DIR)/%.o,$(COMMON_SRCS))
DEP_FILES = $(OBJ_FILES:.o=.d)

all: $(NAME)

# Inclusion des dépendances
-include $(DEP_FILES)


$(OBJ_DIR):
	@printf "$(CYAN)Création dossier obj$(RESET)"
	@mkdir -p $(OBJ_DIR)
	@printf " $(GREEN)OK$(RESET)\n"

$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.cpp | $(OBJ_DIR)
	@printf "$(YELLOW)Compilation $<...$(RESET)"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@
	@printf "$(CLEAR)$(GREEN)✓ Compiled $<$(RESET)\n"

$(NAME): $(OBJ_FILES)
	@printf "$(YELLOW)Linking...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ_FILES)  -o $(NAME)
	@printf "$(CLEAR)$(GREEN)✓ $(NAME) created!$(RESET)\n"

clean:
	@printf "$(YELLOW)cleaning up obj...$(RESET)"
	@rm -rf $(OBJ_DIR)
	@printf "$(CLEAR)$(GREEN)✓ Objects cleaned!$(RESET)\n"

fclean: clean
	@printf "$(YELLOW) Deleteing $(NAME)...$(RESET)"
	@rm -f $(NAME)
	@printf "$(CLEAR)$(GREEN)✓ $(NAME) delete!$(RESET)\n"

re: fclean all

.PHONY: all macos clean fclean re
