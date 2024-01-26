# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azbk <azbk@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/26 16:12:37 by azbk              #+#    #+#              #
#    Updated: 2024/01/26 17:02:06 by azbk             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                COMPILATION                                   #
################################################################################

NAME = minishell

CC		= @cc
CFLAGS	= -g3 -Wall -Wextra -Werror
CIFLAGS	= -Iincludes -I$(LIB_DIR)/includes
CCLIED	= -L$(LIB_DIR) -lft -lreadline
DEPFLAGS = -MMD -MP
MAKE	= @make --no-print-directory

################################################################################
#                                  ASCII ART                                   #
################################################################################

RED	= \033[1;36m
RED		= \033[1;31m
WHITE	= \033[1;37m
END		= \033[0m

################################################################################
#                                  SOURCES                                     #
################################################################################

PARSE_DIR	= parse
EXEC_DIR	= exec
BUILT_DIR	= builtins
UTILS_DIR	= utils
SIGNAL_DIR	= signal
ENV_DIR		= env
FREE_DIR	= free
SRC = src

SRC_FILES	=	$(addprefix src/builtins/, \
				cd.c		pwd.c) \
				\
				src/main.c

################################################################################
#                                  OBJETS                                      #
################################################################################

OBJS_DIR	= obj
OBJS		= $(SRC_FILES:%.c=$(OBJS_DIR)/%.o)
DEPS_DIR    = deps
DEPS		= $(SRC_FILES:%.c=$(DEPS_DIR)/%.d)


################################################################################
#                               OTHER LIBRARY                                  #
################################################################################

LIB_DIR = libft


################################################################################
#                                  MAKEFILE                                    #
################################################################################


all : $(NAME)

$(NAME) : $(OBJS_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(CIFLAGS) $(OBJS) $(CCLIED) -o $(NAME)

$(OBJS_DIR) :
	@printf "$(RED)\n%20s Compilation de la librairie $(END)$(WHITE)$(LIB_DIR)...\n"
	$(MAKE) -C $(LIB_DIR)
	@printf "$(RED)%18s Compilation de la librairie $(END)$(WHITE)$(LIB_DIR) terminée$(END)\n\n"
	@sleep 0.7
	@printf "$(RED)%20s Création des dossiers content les $(END)$(WHITE).o : \n"
	@sleep 0.2
	@printf "$(RED)%24s Création du dossier $(END)$(WHITE)$(OBJS_DIR)...\n"
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)/$(SRC)
	@sleep 0.2
	@printf "$(RED)%20s Création du dossier $(END)$(WHITE)$(OBJS_DIR)/$(SRC)/$(BUILT_DIR)...\n"
	@mkdir -p $(OBJS_DIR)/$(SRC)/$(BUILT_DIR)
	@sleep 0.2
	@printf "$(RED)%20s Création des dossiers $(END)$(WHITE)objets terminée$(END)\n\n"
	@sleep 0.9
	@printf "$(RED)%24s Compilation de $(END)$(WHITE)$(NAME)...\n"
	@sleep 0.2
	@printf "$(RED)%21s Compilation de $(END)$(WHITE)$(NAME) terminée$(END)\n\n"

$(OBJS) : $(OBJS_DIR)/%.o : %.c | $(DEPS_DIR)
	@mkdir -p $(dir $(DEPS_DIR)/$*)
	$(CC) $(CFLAGS) $(DEPFLAGS) -MT $@ -MF $(DEPS_DIR)/$*.d $(CIFLAGS) -c $< -o $@


$(DEPS_DIR) :
	@mkdir -p $(DEPS_DIR)

clean :
	@printf "%s\n\n" "_____________________________________________________________"
	@printf "$(RED)%19s Nettoyage en cours...$(END)\n"
	@printf "%s\n" "_____________________________________________________________"
	$(MAKE) clean -C $(LIB_DIR)
	@rm -rf $(OBJS_DIR)
	@rm -rf $(DEPS_DIR)
	@printf "\n$(RED)%5sSuppression des objets de la librairie : $(END)$(WHITE)$(LIB_DIR) [📚]$(END)\n"
	@printf "$(RED)%13s Suppression du dossier : $(END)$(WHITE)$(OBJS_DIR) [✅]$(END)\n"
	@printf "$(RED)%13s Suppression du dossier : $(END)$(WHITE)$(DEPS_DIR) [✅]$(END)\n"
	@printf "%s\n\n" "_____________________________________________________________"

	
fclean: clean
	$(MAKE) fclean -C $(LIB_DIR)
	@rm -rf $(NAME)
	@printf "$(RED)%7s Suppression de l'exécutable : $(END)$(WHITE)$(NAME) [💾]$(END)\n\n"
	
re : fclean all

-include $(DEPS)
.PHONY: all clean fclean re

