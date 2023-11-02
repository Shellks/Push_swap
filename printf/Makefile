# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 20:46:37 by acarlott          #+#    #+#              #
#    Updated: 2023/03/09 11:20:32 by acarlott         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS = -Wall -Werror -Wextra
CC = cc
HEADER = ./include
AR = ar rcs

SRCS = core/ft_check_convert.c \
		core/ft_putstr.c\
		core/ft_printf.c \
		core/ft_printchar.c \
		core/ft_putnbr_int.c \
		core/ft_putnbr_base.c \
		core/ft_print_memory.c \
		core/ft_putnbr_unsigned.c \

OBJS = ${SRCS:.c=.o}

./core/%.o:	./core/%.c ${HEADER}/printf.h
	${CC} ${CFLAGS} -I${HEADER} -g -c $< -o $@ 

all: ${NAME}

${NAME}: ${OBJS}
	${AR} ${NAME} ${OBJS}

clean :
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re : clean all

# .SILENT :

.PHONY: all clean fclean re bonus
