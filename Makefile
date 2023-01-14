# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 13:12:40 by hanmpark          #+#    #+#              #
#    Updated: 2023/01/14 14:27:57 by hanmpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PRESETS
HDIR = includes/
NAME = so_long.a
LIBFT = libft/

# SOURCES AND OBJECTS
SRCS = parsing.c main.c init_map.c

OBJS = ${SRCS:.c=.o}

# COMPILER
CC = gcc
CFLAGS = -Wall -Wextra -Werror

%.o:%.c ${HDIR}
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

# RULES
all: ${NAME}

${NAME}: ${OBJS}
	@${MAKE} -C ${LIBFT}
	@cp ${LIBFT}/libft.a ${NAME}
	@ar rc ${NAME} ${OBJS}
	@ranlib ${NAME}

clean:
	@rm -f ${OBJS}
	@${MAKE} clean -C ${LIBFT}
	@echo ".o files destroyed"
	
fclean: clean
	@rm -f ${NAME}
	@rm -f ${LIBFT}/libft.a
	@echo ".a files destroyed"

re: fclean all

.PHONY: all clean fclean re