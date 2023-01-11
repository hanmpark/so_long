# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 16:40:47 by hanmpark          #+#    #+#              #
#    Updated: 2023/01/05 11:58:45 by hanmpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#################### PRESETTINGS ####################
H_DIR			= includes/
LIBFT_DIR		= sources/libft/
FTPRINTF_DIR	= sources/ft_printf/
GNL_DIR			= sources/get_next_line/
NAME			= libft.a

# Default
_END	=	\x1b[0m
_BOLD	=	\x1b[1m
_CYAN	=	\x1b[36m

# Backgrounds
_IRED		=	\x1b[41m
_IGREEN		=	\x1b[42m
_IPURPLE	=	\x1b[45m

#################### SOURCES AND OBJECTS ####################
SRCS_LIBFT	=	ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
					ft_isdigit.c ft_isprint.c ft_memcpy.c ft_memset.c \
					ft_strlen.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
					ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
					ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
					ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
					ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
					ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
					ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c \
					ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
					ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
					ft_lstiter.c ft_lstmap.c

SRCS_FTPRINTF	=	def_flags.c format_hexa.c ft_printf.c print_basic.c \
						print_hexa.c specifier_filter.c treat_charflags.c \
						treat_intflags.c

SRCS_GNL		=	get_next_line_utils.c get_next_line.c

SRCS		=	${addprefix ${LIBFT_DIR}, ${SRCS_LIBFT}} \
				${addprefix ${FTPRINTF_DIR}, ${SRCS_FTPRINTF}} \
				${addprefix ${GNL_DIR}, ${SRCS_GNL}}

OBJS		=	${SRCS:.c=.o}

#################### COMPILER ####################
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

%.o:%.c		${H_FILE}
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

#################### RULES ####################
all:		${NAME}

${NAME}:	${OBJS}
	@echo "\n${_BOLD}${_CYAN}==================== C O M P I L I N G ====================${_END}\n"
	@ar rc ${NAME} ${OBJS}
	@ranlib ${NAME}
	@echo "${_BOLD}${_IGREEN}Compiled without encountering any problem${_END}\n"

clean:
	@echo "${_BOLD}${_CYAN}==================== C L E A N I N G ====================${_END}\n"
	rm -f ${OBJS}
	@echo "${_BOLD}${_IPURPLE}.o files destroyed${_END}"

fclean:	clean
	rm -f ${NAME}
	@echo "${_BOLD}${_IRED}.a file destroyed${_END}"

re:		fclean all

.PHONY: all clean fclean re bonus