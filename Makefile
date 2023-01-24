# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 13:12:40 by hanmpark          #+#    #+#              #
#    Updated: 2023/01/24 15:16:07 by hanmpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PRESETS
NAME = so_long
HDIR = includes/
LIBFT = libft/

# SOURCES AND OBJECTS
SRCS = main.c init_map.c

OBJS = ${SRCS:.c=.o}

# COMPILER
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3

%.o:%.c ${HDIR}
	@${CC} ${CFLAGS} -c -I ./${H_DIR} $< -o ${<:.c=.o}

# RULES
all: ${NAME}

${NAME}: ${OBJS}
	@echo "\n\033[3m\033[2;37m\t- Compiling...\033[0m"
	@${MAKE} -C ${LIBFT}
	@${CC} ${FLAGS} ${OBJS} -o ${NAME} ${LIBFT}/libft.a
	@echo "\033[3m\033[1;32m   - Compiled -\033[0m"

clean:
	@echo "\n\033[3m\033[2;37m\t- Cleaning objects...\033[0m"
	@rm -rf ${OBJS}
	@${MAKE} clean -C ${LIBFT}

fclean: clean
	@echo "\033[3m\033[2;37m\t- Cleaning ${NAME}...\033[0m"
	@rm -rf ${NAME}
	@rm -rf ${LIBFT}/libft.a
	@echo "\033[3m\033[1;32m   - Cleaned -\033[0m"

re: fclean all

.PHONY: all clean fclean re