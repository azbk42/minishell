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

PINK = \033[1;95m
RED = \033[0;91m
CYAN = \033[0;96m
MAGENTA = \033[1;35m
WHITE	= \033[1;37m
GREEN = \033[0;92m
RESET = \033[0m
BLINK	= \033[5m

################################################################################
#                                 	OBJECT                                     #
################################################################################

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(DEPS_DIR)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -MMD -MP -c $< -o $@
	@mkdir -p $(DEPS_DIR)/$(*D)
	@mv $(@:.o=.d) $(DEPS_DIR)/$(*D)/
	@echo "$(CYAN)Compiling: $< $(RESET)"

OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

################################################################################
#                                  ALL / NAME                                  #
################################################################################

all: $(DEPS_DIR) $(NAME)
	@printf "$(GREEN)%18s Compilation de la librairie: $(END)$(BLINK)$(WHITE)libft.a terminée$(END)\n\n"
	@sleep 0.5
	@printf "$(CYAN)%18s Compilation du programme: $(END)$(BLINK)$(WHITE)$(NAME) terminée$(END)\n\n"
	@sleep 0.5
		
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
	@printf "$(RED)%24s Création du dossier $(END)$(WHITE)$(DEPS_DIR)...\n\n"
	@printf "$(RED)%20s all $(END)$(WHITE).d$(END)$(RED) files have been created in $(END)$(WHITE)$(DEPS_DIR) \n"


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
	@$(MAKE) -C ./Libft clean
	@rm -rf $(OBJ_DIR)
	@rm -rf $(DEPS_DIR)
	@rm -f ./Libft/*.d
	@rm -f Libft/GNL/*.d	
	@rm -f Libft/ft_printf/*.d

fclean: clean
	@$(MAKE) -C ./Libft fclean
	@rm -f $(NAME)
	@echo "$(RED)libft.a remove$(RESET)"
	@echo "$(RED)$(NAME) remove$(RESET)"

re: fclean all

################################################################################
#                                  OTHERS                                      #
################################################################################

.EXTRA_PREREQS:= $(abspath $(lastword $(MAKEFILE_LIST)))
-include $(DEPS)
