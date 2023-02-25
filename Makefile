# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 13:12:40 by hanmpark          #+#    #+#              #
#    Updated: 2023/02/25 18:49:06 by hanmpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PRESETS
NAME = so_long
EXEC = ./so_long
HDIR = inc/
HDIR_LIBFT = src/libft/inc/
LIBFT = src/libft/
PATH_BONUS = src/main/bonus/
PATH_MAN = src/main/mandatory/

# COLORS
DEF = \033[0m
BOLD = \033[1m
CUR = \033[3m
UL = \033[4m
UP = \033[A

GREEN = \033[32m
GRAY = \033[2;37m
MAGENTA = \033[35m

# SOURCES AND OBJECTS
SRCS_MAN = ${addprefix ${PATH_MAN}, main.c \
									map_init.c \
									map_check.c \
									game_init.c \
									hooks.c \
									render.c \
									move_check.c}

SRCS_BONUS = ${addprefix ${PATH_BONUS}, map_init_bonus.c \
										map_check_bonus.c \
										assign_textures_bonus.c \
										game_init_bonus.c \
										move_player_bonus.c \
										game_check_bonus.c \
										hooks_bonus.c \
										render_bonus.c \
										update_frame_bonus.c \
										move_enemy_bonus.c \
										print_tools_bonus.c \
										main_bonus.c \
										clear_textures_bonus.c}

ifdef BONUS
OBJS = ${SRCS_BONUS:.c=.o}
else
OBJS = ${SRCS_MAN:.c=.o}
endif

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

norminette:
	@echo "\n${BOLD}${UL}${MAGENTA}NORMINETTE${DEF}"
	@echo "\n${BOLD}${UL}${GREEN}<<< Checking for libft>>>${DEF}"
	@echo "${UL}${MAGENTA}norminette ${LIBFT}${DEF}"
	@norminette ${LIBFT}
	@echo "\n${BOLD}${UL}${GREEN}<<< Checking for main files >>>${DEF}"
	@echo "${UL}${MAGENTA}norminette ${MAIN_MAN}${DEF}"
	@norminette ${MAIN_MAN}
	@echo "\n${BOLD}${UL}${GREEN}<<< Checking for bonus files >>>${DEF}"
	@echo "${UL}${MAGENTA}norminette ${MAIN_BONUS}${DEF}"
	@norminette ${MAIN_BONUS}
	@echo "\n${BOLD}${UL}${GREEN}<<< Checking for header files >>>${DEF}"
	@echo "${UL}${MAGENTA}norminette ${HDIR}${DEF}"
	@norminette ${HDIR}
	@echo "\n${UL}${MAGENTA}norminette ${HDIR_LIBFT}${DEF}"
	@norminette ${HDIR_LIBFT}
	@echo ""

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

rebonus: fclean bonus

.PHONY: all clean fclean re