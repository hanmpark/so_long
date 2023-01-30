# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 13:12:40 by hanmpark          #+#    #+#              #
#    Updated: 2023/01/30 16:25:10 by hanmpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PRESETS
NAME = so_long
HDIR = includes/
LIBFT = libft/
CC = gcc
MLXDIR = mlx/
MLX = -L${MLXDIR} -lmlx
LINKS = -framework OpenGL -framework Appkit

# Static library is a collection of object files, while dynamic or shared library \
is a collection of functions compiled and stored in an executable \
with purpose of being linked by other programs at run-time.
DYLIB = libmlx.dylib

# SOURCES AND OBJECTS
SRCS = main.c map_init.c map_check.c

OBJS = ${SRCS:.c=.o}

# COMPILER
ifdef DEBUG
FLAGS += fsanitize=address -g3
endif

%.o:%.c ${HDIR}
	${CC} ${CFLAGS} -c -I ./${HDIR} $< -o ${<:.c=.o}

# RULES
all: ${NAME}

${NAME}: ${OBJS} ${MLX}
	@echo "\n\033[3m\033[2;37m\t- Compiling...\033[0m"
	@make -C ${LIBFT}
	@${CC} ${CFLAGS} ${LIBFT}/libft.a ${OBJS} ${MLX} ${LINKS} -o ${NAME}
	@echo "\033[3m\033[1;32m   - Compiled -\033[0m"

${MLX}:
	@make -C ${MLXDIR}
	@cp -rf ${MLXDIR}/${DYLIB} .

debug: ${OBJS}
	@echo "debug"
	@${MAKE} DEBUG=1

clean:
	@echo "\n\033[3m\033[2;37m\t- Cleaning objects...\033[0m"
	@rm -rf ${OBJS}
	@make -C ${LIBFT} clean
	@make -C ${MLXDIR} clean

fclean: clean
	@echo "\033[3m\033[2;37m\t- Cleaning ${NAME}...\033[0m"
	@rm -rf ${NAME}
	@rm -rf ${DYLIB}
	@rm -rf ${LIBFT}/libft.a
	@echo "\033[3m\033[1;32m   - Cleaned -\033[0m"

re: fclean all

.PHONY: all clean fclean re