# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/26 16:12:37 by azbk              #+#    #+#              #
#    Updated: 2024/02/11 12:39:29 by emauduit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                COMPILATION                                   #
################################################################################

NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -g
CIFLAGS	= -Iincludes -I$(LIB_DIR)/includes
CCLIED	= -L$(LIB_DIR) -lft -lreadline
MAKEFLAGS += --no-print-directory


LIBFT = ./libft/libft.a
SRC_DIR = ./src

################################################################################
#                                  SOURCES                                     #
################################################################################

SRC := main.c \
		builtins/cd.c \
		builtins/pwd.c \
		\
		parsing/expand/expand.c \
		parsing/expand/find_count_len.c \
		parsing/expand/exp_quotes.c \
		parsing/expand/env.c \
		parsing/expand/singletone.c \
		\
		parsing/linked_list/lst_env.c \
		\
		parsing/error/error_handling.c \
		parsing/tools_suppr/tools.c

SRC := $(addprefix $(SRC_DIR)/, $(SRC))

################################################################################
#                                  OBJECTS / DEP                                #
################################################################################

OBJ_DIR = obj
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

DEPS := $(OBJ:.o=.d)
DEPS += ./libft/*.d

################################################################################
#                                  ASCII ART                                   #
################################################################################

PINK = \033[1;95m
RED = \033[0;91m
CYAN = \033[0;96m
MAGENTA = \033[1;35m
RESET = \033[0m

################################################################################
#                                  MAKEFILE                                    #
################################################################################

all: $(NAME) 
		
$(NAME): $(OBJ)
	@$(MAKE) -C ./libft 
	@$(CC) $(CFLAGS) $(CIFLAGS) $(OBJ) $(LIBFT) $(CCLIED) -o $(NAME)
	@echo "\n$(CYAN)$(NAME) compiled!$(RESET)"
	
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -MMD -MP -c $< -o $@ 
	@echo "$(MAGENTA)Compiling: $< $(DEF_COLOR)$(RESET)"

################################################################################
#                                  CLEAN / FCLEAN                              #
################################################################################


clean:
	@echo "\n$(RED)Removing: $(OBJ) $(OBJ_DIR) $(DEF_COLOR)$(RESET)\n"
	@$(MAKE) -C ./libft clean
	@rm -rf $(OBJ_DIR)
	@rm -f ./libft/*.d
	@rm -f libft/GNL/*.d	
	@rm -f libft/ft_printf/*.d
	@echo "$(RED)Dependencies have been removed.$(RESET)"
	@echo "$(RED)Obj directory has been removed.$(RESET)\n"

fclean: clean
	@$(MAKE) -C ./libft fclean
	@rm -f $(NAME)

re: fclean all

.EXTRA_PREREQS:= $(abspath $(lastword $(MAKEFILE_LIST)))
-include $(DEPS)