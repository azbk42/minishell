################################################################################
#                                  COMPILATION                                 #
################################################################################

NAME = minishell

CC = cc
CFLAGS = -Wall -Werror -Wextra
MAKEFLAGS += --no-print-directory

################################################################################
#                                  DIRECTORY                                   #
################################################################################

LIBFT = ./Libft/libft.a
SRC_DIR = ./src
OBJ_DIR = obj
DEPS_DIR = deps
BUILTIN = builtin

################################################################################
#                                  SOURCES                                     #
################################################################################

SRC := $(addprefix $(BUILTIN)/, \
			cd.c) \
		\
		main.c
SRC := $(addprefix $(SRC_DIR)/, $(SRC))

################################################################################
#                                 	ASCII ART                                  #
################################################################################

YELLOW = \033[1;93m
RED = \033[0;91m
CYAN = \033[0;96m
MAGENTA = \033[1;35m
WHITE	= \033[1;37m
GREEN = \033[0;92m
BLINK	= \033[5m

################################################################################
#                                 	OBJECT                                     #
################################################################################

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(DEPS_DIR)
	@echo "$(MAGENTA)Compiling: $< $(DEF_COLOR)$(END)"
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -MMD -MP -c $< -o $@
	@mkdir -p $(DEPS_DIR)/$(*D)
	@mv $(@:.o=.d) $(DEPS_DIR)/$(*D)/

OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

################################################################################
#                                  ALL / NAME                                  #
################################################################################

all: $(NAME)
		
$(NAME): $(OBJ)
	@$(MAKE) -C ./Libft 
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) -lreadline -lhistory

################################################################################
#                                  DEPENDANCIES                                #
################################################################################

DEPS := $(OBJ:$(OBJ_DIR)/%.o=$(DEPS_DIR)/%.d)
DEPS += ./Libft/*.d

$(DEPS_DIR):
	@mkdir -p $(DEPS_DIR)

################################################################################
#                                  RULES                                       #
################################################################################

norminette:
	norminette $(SRC_DIR)
	norminette Libft/
	norminette ./includes/

################################################################################
#                                  CLEAN FCLEAN RE                             #
################################################################################
clean:
	@echo "$(CYAN)Removing: $(OBJ) $(OBJ_DIR) $(DEF_COLOR)"
	@$(MAKE) -C ./Libft clean
	@rm -rf $(OBJ_DIR)
	@rm -rf $(DEPS_DIR)
	@rm -f ./Libft/*.d
	@rm -f Libft/GNL/*.d	
	@rm -f Libft/ft_printf/*.d

fclean: clean
	@$(MAKE) -C ./Libft fclean
	@rm -f $(NAME)
	@echo "$(RED)libft.a remove$(DEF_COLOR)"
	@echo "$(RED)$(NAME) remove$(DEF_COLOR)"

re: fclean all

################################################################################
#                                  OTHERS                                      #
################################################################################

.EXTRA_PREREQS:= $(abspath $(lastword $(MAKEFILE_LIST)))
-include $(DEPS)
