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
SRCS	= $(addprefix src/, ft_bonus.c ft_graphical.c ft_init.c ft_main.c \
			ft_map_is_ok.c ft_map.c ft_move.c ft_move_ennemie.c main.c so_long.c)
OBJS	= ${SRCS:.c=.o}
DEPS	= ${SRCS:.c=.d}
MLXH	= -I /usr/local/include
MLXS	= -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit
INCDIR	= $(addprefix -I, libmlx /usr/include includes libft)
LIBDIR	= $(addprefix -L, libmlx /usr/lib libft)
CFLAGS	= -Wall -Wextra -Werror -g
LIBINC	= -lXext -lX11 -lm -lz -lmlx -lft
LIBMLX	= libmlx/libmlx.a
LIBFT	= libft/libft.a

%.o:%.c
	${CC} ${CFLAGS} -MMD -c $< -o $@ ${INCDIR}

${NAME}:${OBJS}
	make -s -C libmlx
	make -s -C libft
	${CC} ${CFLAGS} ${OBJS} ${LIBDIR} ${LIBINC} -o ${NAME}

all:${NAME}

clean:
	make -s -C libft clean
	${RM} ${OBJS} ${DEPS}

fclean:clean
	make -s -C libmlx clean
	make -s -C libft fclean
	${RM} ${NAME}

re:fclean all

mac:${LIBFT} ${OBJS}
	${CC} -o ${NAME} ${CFLAGS} ${MLXH} ${OBJS} ${LIBFT} ${MLXS}

-include ${DEPS}

.PHONY: all clean fclean re mac
