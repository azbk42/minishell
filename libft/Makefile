NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC =  ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_itoa.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_striteri.c ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_substr.c
BONUSSRC = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstnew.c ft_lstsize.c
SRC2 = GNL/get_next_line_utils.c GNL/get_next_line.c ft_printf/ft_printf.c ft_printf/ft_printf_utils.c


OBJS = ${SRC:.c=.o}
BONUSOBJS = ${BONUSSRC:.c=.o}
SRC2OBJS = ${SRC2:.c=.o}

GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
CYAN = \033[0;96m
END		= \033[0m

RM = rm -f

.c.o:
	@${CC} -c ${CFLAGS} -MMD -MP $< -o ${<:.c=.o}
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)$(END)"

${NAME}: ${OBJS} ${BONUSOBJS} ${SRC2OBJS}
	@ar rc ${NAME} ${OBJS} ${BONUSOBJS} ${SRC2OBJS}
	@echo "\n$(GREEN)libft compiled!$(END)"

all: ${NAME}

clean:
	@${RM} ${OBJS} ${BONUSOBJS} ${SRC2OBJS}
	@${RM} Libft/GNL/*.d
	@${RM} Libft/ft_printf/*.d

fclean: clean
	@${RM} ${NAME}

re: fclean all

-include $(DEPS)