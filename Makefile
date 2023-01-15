# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 13:12:40 by hanmpark          #+#    #+#              #
#    Updated: 2023/01/14 23:05:13 by hanmpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PRESETS
NAME = so_long
HDIR = includes/
LIBFT = libft/

# SOURCES AND OBJECTS
SRCS = parsing.c main.c init_map.c

OBJS = ${SRCS:.c=.o}

# COMPILER
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3

%.o:%.c ${HDIR}
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

# RULES
all: ${NAME}

${NAME}: ${OBJS}
	@${MAKE} -C ${LIBFT}
	@${CC} ${FLAGS} ${OBJS} -o ${NAME} ${LIBFT}/libft.a

clean:
	@rm -rf ${OBJS}
	@${MAKE} clean -C ${LIBFT}
	@echo ".o files destroyed"

fclean: clean
	@rm -rf ${NAME}
	@rm -rf ${LIBFT}/libft.a

re: fclean all

.PHONY: all clean fclean re