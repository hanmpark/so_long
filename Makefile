# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 13:12:40 by hanmpark          #+#    #+#              #
#    Updated: 2023/02/26 22:43:29 by hanmpark         ###   ########.fr        #
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
PATH_ERROR = maps/error/

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

OBJS_MAN = ${SRCS_MAN:.c=.o}
OBJS_BONUS = ${SRCS_BONUS:.c=.o}

ifdef BONUS
OBJS = ${OBJS_BONUS}
else
OBJS = ${OBJS_MAN}
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
	@echo "\n${BOLD}${UL}${GREEN}<<< Checking for libft >>>${DEF}"
	@echo "${UL}${MAGENTA}norminette ${LIBFT}${DEF}"
	@norminette ${LIBFT} || true
	@echo "\n${BOLD}${UL}${GREEN}<<< Checking for main files >>>${DEF}"
	@echo "${UL}${MAGENTA}norminette ${PATH_MAN}${DEF}"
	@norminette ${PATH_MAN} || true
	@echo "\n${BOLD}${UL}${GREEN}<<< Checking for bonus files >>>${DEF}"
	@echo "${UL}${MAGENTA}norminette ${PATH_BONUS}${DEF}"
	@norminette ${PATH_BONUS} || true
	@echo "\n${BOLD}${UL}${GREEN}<<< Checking for header files >>>${DEF}"
	@echo "${UL}${MAGENTA}norminette ${HDIR}${DEF}"
	@norminette ${HDIR} || true
	@echo "\n${UL}${MAGENTA}norminette ${HDIR_LIBFT}${DEF}"
	@norminette ${HDIR_LIBFT} || true
	@echo ""

test: ${NAME}
	@echo "\n${BOLD}${UL}${MAGENTA}TESTING ERROR MAPS${DEF}"
	@echo "\n${BOLD}${UL}${GREEN}<<< ELEMENTS IN MAP >>>${DEF}"
	@echo "${CUR}${GRAY}elements_duplicate_exit.ber${DEF}"
	@${EXEC} ${PATH_ERROR}elements_duplicate_exit.ber || true
	@echo "\n${CUR}${GRAY}elements_duplicate_player.ber${DEF}"
	@${EXEC} ${PATH_ERROR}elements_duplicate_player.ber || true
	@echo "\n${CUR}${GRAY}elements_number.ber${DEF}"
	@${EXEC} ${PATH_ERROR}elements_number.ber || true
	@echo "\n${CUR}${GRAY}elements_wrong.ber${DEF}"
	@${EXEC} ${PATH_ERROR}elements_wrong.ber || true
	@echo "\n${BOLD}${UL}${GREEN}<<< MAP'S FORMAT >>>${DEF}"
	@echo "${CUR}${GRAY}format_error_edge.ber${DEF}"
	@${EXEC} ${PATH_ERROR}format_error_edge.ber || true
	@echo "\n${CUR}${GRAY}format_error_wall0.ber${DEF}"
	@${EXEC} ${PATH_ERROR}format_error_wall0.ber || true
	@echo "\n${CUR}${GRAY}format_error_wall1.ber${DEF}"
	@${EXEC} ${PATH_ERROR}format_error_wall1.ber || true
	@echo "\n${BOLD}${UL}${GREEN}<<< INVALID MAP >>>${DEF}"
	@echo "${CUR}${GRAY}invalid_map_coin.ber${DEF}"
	@${EXEC} ${PATH_ERROR}invalid_map_coin.ber || true
	@echo "\n${CUR}${GRAY}invalid_map_exit.ber${DEF}"
	@${EXEC} ${PATH_ERROR}invalid_map_exit.ber || true
	@echo "\n${CUR}${GRAY}invalid_map_player.ber${DEF}"
	@${EXEC} ${PATH_ERROR}invalid_map_player.ber || true
	@echo "\n${BOLD}${UL}${GREEN}<<< .BER >>>${DEF}"
	@echo "${CUR}${GRAY}valid_ber${DEF}"
	@${EXEC} ${PATH_ERROR}valid_ber || true
	@echo "\n${CUR}${GRAY}valid_ber.be${DEF}"
	@${EXEC} ${PATH_ERROR}valid_ber.be || true
	@echo ""

debug: ${OBJS}
	@echo "\n   ${BOLD}${UL}${MAGENTA}DEBUGGING MODE${DEF}"
	@${MAKE} DEBUG=1

clean:
	@echo "\n${CUR}${GRAY}\t- Removing object files${DEF}"
	@rm -rf ${OBJS_MAN} ${OBJS_BONUS}
	@${MAKE} -C ${LIBFT} clean

fclean: clean
	@echo "${CUR}${GRAY}\t- Removing ${BOLD}${NAME}${DEF}"
	@rm -rf ${NAME}
	@rm -rf ${LIBFT}/libft.a
	@echo "   ${CUR}${BOLD}${UL}${GREEN}- Cleaned -${DEF}\n"

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re bonus rebonus norminette debug test
