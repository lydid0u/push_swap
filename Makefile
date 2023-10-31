NAME	= push_swap

CC			  = clang

CFLAGS  = -Wall -Wextra -Werror -g3

RM			  = rm -f

PRINTF		= ft_printf

FT_PRINTF	= ft_printf/libftprintf.a

SRC	 = ./command/push.c ./command/swap.c ./command/rotate.c ./command/reverse_rotate.c parsing.c ft_split.c \
 		free.c push_swap.c utils.c sort_3_4_5.c sort_rest.c utils_lists.c set_up_algo.c \

OBJ	= ${SRC:.c=.o}

all : ${NAME}

${NAME} : ${OBJ}
	${MAKE} -C ${PRINTF}
	${CC} ${OBJ} -o ${NAME} ${FT_PRINTF}

clean :
	${RM} ${OBJ}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re