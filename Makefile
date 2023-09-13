# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 13:12:40 by hanmpark          #+#    #+#              #
#    Updated: 2023/09/14 00:59:19 by hanmpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PRESETS

# ---------------------------------- COLORS ---------------------------------- #
DEF = \033[0m
BOLD = \033[1m
CUR = \033[3m
UL = \033[4m
UP = \033[A

ORANGE = \033[38;5;216m
LBLUE = \033[38;5;153m
LYELLOW = \033[38;5;222m
BEIGE = \033[38;5;223m
LGREEN = \033[38;5;155m

# --------------------------------- SOURCES ---------------------------------- #
MAIN_PATH = ./src/main/
SRCS_MAN = ${addprefix ${MAIN_PATH}, main.c \
									map_init.c \
									map_check.c \
									game_init.c \
									hooks.c \
									render.c \
									move_check.c}

BONUS_PATH = ./src/bonus/
SRCS_BONUS = ${addprefix ${BONUS_PATH}, map_init_bonus.c \
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

# --------------------------------- OBJECTS ---------------------------------- #
OBJS_MAIN = ${SRCS_MAN:.c=.o}
OBJS_BONUS = ${SRCS_BONUS:.c=.o}

ifdef COMPILE_BONUS
	OBJS = ${OBJS_BONUS}
else
	OBJS = ${OBJS_MAIN}
endif

# --------------------------------- COMPILER --------------------------------- #
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LINKS = -framework OpenGL -framework Appkit
MLX = ./minilibx-mac/libmlx.a
ifdef DEBUG
	CFLAGS += -fsanitize=address -g
endif

HEADER_PATH = ./inc/main/
SRCS_COUNT = 0
SRCS_TOT = ${shell find ./src/main/ -type f -name '*.c' | wc -l}
SRCS_PRCT = ${shell expr 100 \* ${SRCS_COUNT} / ${SRCS_TOT}}
BAR =  ${shell expr 23 \* ${SRCS_COUNT} / ${SRCS_TOT}}

${MAIN_PATH}%.o: ${MAIN_PATH}%.c ${HEADER_PATH}
	@${eval SRCS_COUNT = ${shell expr ${SRCS_COUNT} + 1}}
	@${CC} ${CFLAGS} -c -I ${HEADER_PATH} $< -o ${<:.c=.o}
	@echo ""
	@echo " ${BOLD}${CUR}${BEIGE}-> Compiling ${DEF}${BOLD}${LYELLOW}[SO_LONG]${DEF}"
	@printf " ${BEIGE}   [${LGREEN}%-23.${BAR}s${BEIGE}] [%d/%d (%d%%)]${DEF}" "***********************" ${SRCS_COUNT} ${SRCS_TOT} ${SRCS_PRCT}
	@echo "${UP}${UP}${UP}"

HEADER_PATH_BONUS = ./inc/bonus/
SRCS_TOT_BONUS = ${shell find ./src/bonus/ -type f -name '*.c' | wc -l}
SRCS_PRCT_BONUS = ${shell expr 100 \* ${SRCS_COUNT} / ${SRCS_TOT_BONUS}}
BAR_BONUS = ${shell expr 23 \* ${SRCS_COUNT} / ${SRCS_TOT_BONUS}}

${BONUS_PATH}%.o: ${BONUS_PATH}%.c ${HEADER_PATH_BONUS}
	@${eval SRCS_COUNT = ${shell expr ${SRCS_COUNT} + 1}}
	@${CC} ${CFLAGS} -I ${HEADER_PATH_BONUS} -c $< -o ${<:.c=.o}
	@echo ""
	@echo " ${BOLD}${CUR}${BEIGE}-> Compiling ${DEF}${BOLD}${LYELLOW}[SO_LONG (BONUS)]${DEF}"
	@printf " ${BEIGE}   [${LGREEN}%-23.${BAR_BONUS}s${BEIGE}] [%d/%d (%d%%)]${DEF}" "***********************" ${SRCS_COUNT} ${SRCS_TOT_BONUS} ${SRCS_PRCT_BONUS}
	@echo "${UP}${UP}${UP}"

# ---------------------------------- RULES ----------------------------------- #
NAME = so_long
LIBFT_PATH = ./libft/
EXEC = ./so_long
PATH_ERROR = ./maps/error/

all: setmlx ${NAME}

${NAME}: ${OBJS}
	@echo "\n\n\n"
	@${MAKE} -C ${LIBFT_PATH}
	@${CC} ${FLAGS} ${OBJS} ${LIBFT_PATH}/libft.a ${MLX} ${LINKS} -o ${NAME}
	@echo "\n\n\n   ${BOLD}${CUR}${LYELLOW}SO_LONG COMPILED ✨${DEF}\n"

setmlx:
	@${MAKE} -C ./minilibx-mac/

bonus:
	@${MAKE} COMPILE_BONUS=1 all

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

debug:
	@echo "\n   ${BOLD}${UL}${MAGENTA}DEBUGGING MODE${DEF}"
	@${MAKE} DEBUG=1

clean:
	@rm -f ${OBJS_MAIN} ${OBJS_BONUS}
	@${MAKE} -C ${LIBFT_PATH} clean
	@echo "${ORANGE}${BOLD}\tCLEANING${DEF}"
	@echo "${LBLUE}${BOLD}${CUR} - Deleted object files${DEF}"

fclean: clean
	@rm -f ${LIBFT_PATH}libft.a ${NAME}
	@echo "${LBLUE}${BOLD}${CUR} - Deleted libft.a${DEF}"
	@echo "${LBLUE}${BOLD}${CUR} - Deleted ${NAME}${DEF}"

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re bonus rebonus debug test
