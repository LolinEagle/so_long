# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frrusso <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/14 11:23:26 by frrusso           #+#    #+#              #
#    Updated: 2022/03/14 11:23:40 by frrusso          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror -lm
LIBFT	= ../libft/libft.a
NAME	= so_long
SRCS	= main.c so_long.c
OBJS	= ${SRCS:.c=.o}
MLXH	= -I /usr/local/include
MLXS	= -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:${OBJS}
	${MAKE} -C ../libft
	${CC} -o ${NAME} ${CFLAGS} ${MLXH} ${OBJS} ${LIBFT} ${MLXS}

all:${NAME}

clean:
	${MAKE} clean -C ../libft
	${RM} ${OBJS}

fclean:clean
	${MAKE} fclean -C ../libft
	${RM} ${NAME}

re:fclean all

.PHONY: all clean fclean re
