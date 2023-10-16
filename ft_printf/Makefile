# **************************************************************************** #
#																			  #
#														 :::	  ::::::::	#
#	Makefile										   :+:	  :+:	:+:	#
#													 +:+ +:+		 +:+	  #
#	By: lboudjel <lboudjel@student.42.fr>		  +#+  +:+	   +#+		 #
#												 +#+#+#+#+#+   +#+			#
#	Created: 2023/05/12 17:19:55 by lboudjel		  #+#	#+#			  #
#	Updated: 2023/05/12 17:19:55 by lboudjel		 ###   ########.fr		#
#																			  #
# **************************************************************************** #

NAME			= libftprintf.a

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

SRCS			= ft_printf.c ft_len.c ft_put.c print_c.c print_p.c print_d_i.c print_s.c print_pourcent.c print_u.c print_x.c print_xx.c

OBJS			= $(SRCS:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS) 

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus