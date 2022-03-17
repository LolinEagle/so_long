# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frrusso <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/17 17:31:14 by frrusso           #+#    #+#              #
#    Updated: 2022/03/17 17:31:23 by frrusso          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
RM		= rm -f
NAME	= so_long
SRCS	= $(addprefix ./src/, main.c so_long.c map.c)
OBJS	= ${SRCS:.c=.o}
DEPS	= ${SRCS:.c=.d}
INCDIR	= $(addprefix -I, mlx_linux /usr/include includes libft)
LIBDIR	= $(addprefix -L, mlx_linux /usr/lib libft)
CFLAGS	= -Wall -Wextra -Werror -g
LIBINC	= -lXext -lX11 -lm -lz -lmlx -lft
LIBMLX	= mlx_linux/libmlx.a
LIBFT	= libft/libft.q

%.o: %.c
	${CC} ${CFLAGS} -MMD -c $< -o $@ ${INCDIR}

${LIBMLX}:
	make -s -C mlx_linux

${LIBFT}:
	make -s -C libft

${NAME}: ${LIBMLX} ${LIBFT} ${OBJS}
	${CC} ${CFLAGS} ${OBJS} ${LIBDIR} ${LIBINC} -o ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJS} ${DEPS}
	make -C libft clean

fclean: clean
	${RM} ${NAME}
	make -s -C mlx_linux clean
	make -C libft fclean

re: fclean all

-include ${DEPS}

.PHONY: all clean fclean re
