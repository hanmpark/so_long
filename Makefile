# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 13:12:40 by hanmpark          #+#    #+#              #
#    Updated: 2023/02/24 18:45:49 by hanmpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PRESETS
NAME = so_long
HDIR = inc/
LIBFT = src/libft/
MAIN_BONUS = src/main/bonus/
MAIN_MAN = src/main/mandatory/

# SOURCES AND OBJECTS
FILES_MAN = main.c map_init.c map_check.c game_init.c hooks.c render.c move_check.c

FILES_BONUS = map_init_bonus.c map_check_bonus.c assign_textures_bonus.c game_init_bonus.c \
			move_player_bonus.c game_check_bonus.c hooks_bonus.c render_bonus.c \
			update_frame_bonus.c move_enemy_bonus.c print_tools_bonus.c main_bonus.c \
			clear_textures_bonus.c

SRCS_MAN = ${addprefix ${MAIN_MAN}, ${FILES_MAN}}
SRCS_BONUS = ${addprefix ${MAIN_BONUS}, ${FILES_BONUS}}

ifdef BONUS
OBJS = ${SRCS_BONUS:.c=.o}
else
OBJS = ${SRCS_MAN:.c=.o}
endif

# PRETTY
DEF = \033[0m
BOLD = \033[1m
UBOLD = \033[21m
CUR = \033[3m
UL = \033[4m

GREEN = \033[32m
GRAY = \033[2;37m
MAGENTA = \033[35m

# COMPILER
CC = gcc
FLAGS = -Wall -Wextra -Werror
LINKS = -lmlx -framework OpenGL -framework Appkit
ifdef DEBUG
FLAGS += -fsanitize=address -g3
endif

%.o:%.c ${HDIR}
	@${CC} ${FLAGS} -c -I ./${HDIR} $< -o ${<:.c=.o}

# RULES
all: ${NAME}

${NAME}: ${OBJS}
	@echo "\n${CUR}${GRAY}\t- Compiling...${DEF}"
	@${MAKE} -C ${LIBFT}
	@${CC} ${FLAGS} ${LINKS} ${LIBFT}/libft.a ${OBJS} -o ${NAME}
	@echo "${CUR}${GRAY}\t- Created ${BOLD}${NAME}${DEF}"
	@echo "   ${CUR}${BOLD}${UL}${GREEN}- Compiled -${DEF}\n"

bonus:
	@${MAKE} BONUS=1

debug: ${OBJS}
	@echo "\n   ${BOLD}${UL}${MAGENTA}DEBUGGING MODE${DEF}"
	@${MAKE} DEBUG=1

clean:
	@echo "\n${CUR}${GRAY}\t- Removing object files${DEF}"
	@rm -rf ${OBJS}
	@${MAKE} -C ${LIBFT} clean

fclean: clean
	@echo "${CUR}${GRAY}\t- Removing ${BOLD}${NAME}${DEF}"
	@rm -rf ${NAME}
	@rm -rf ${LIBFT}/libft.a
	@echo "   ${CUR}${BOLD}${UL}${GREEN}- Cleaned -${DEF}\n"

re: fclean all

.PHONY: all clean fclean re