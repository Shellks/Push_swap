# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 13:36:18 by acarlott          #+#    #+#              #
#    Updated: 2023/03/09 13:58:00 by acarlott         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CFLAGS = -Wall -Wextra -Werror
CC = cc
HEADER = ./include

LIBFT_PATH = ./libft/
LIBFT_FILE = libft.a
LIBFT_LIB = $(addprefix ${LIBFT_PATH}, ${LIBFT_FILE})
LIB = ./libft/libft.a
PRINTF_PATH = ./printf/
PRINTF_FILE = libftprintf.a
PRINTF_LIB = $(addprefix ${PRINTF_PATH}, ${PRINTF_FILE})

SRCS = core/main.c \
	core/ft_push.c \
	core/ft_swap.c \
	core/ft_parse.c \
	core/ft_error.c \
	core/ft_rotate.c \
	core/ft_push_swap.c \
	core/pushswap_utils.c \
	
OBJS = ${SRCS:.c=.o}

./core/%.o:	./core/%.c Makefile ${HEADER}/push_swap.h ${LIBFT_LIB} ${PRINTF_LIB} 
	${CC} ${CFLAGS} -I${HEADER} -g -c $< -o $@ 

all : ${NAME}

${NAME} : ${OBJS} ${LIBFT_LIB} ${PRINTF_LIB}
	echo "\033[1;34m\nCreate: \033[1;33mpush_swap"
	${CC} ${CFLAGS} ${OBJS} ${LIBFT_LIB} ${PRINTF_LIB} -o ${NAME}
	echo "\033[1;32mSucces !\n"

$(LIBFT_LIB) : force
	make -C $(LIBFT_PATH)

$(PRINTF_LIB) : force
	make -C $(PRINTF_PATH)

force :

clean :
	echo "\033[1;31m\nClean: \033[1;36mAll *.o"
	${RM} ${OBJS}
	make clean -C ${LIBFT_PATH}
	make fclean -C ${PRINTF_PATH}
	echo "\033[1;32mDelete !\n"

fclean: clean
	echo "\033[1;31mClean: \033[1;36mAll *.a && executable"
	${RM} ${NAME}
	make fclean -C ${LIBFT_PATH}
	make fclean -C ${PRINTF_PATH}
	echo "\033[1;32mDelete !\n"

re : fclean all

.SILENT :

.PHONY: all clean fclean re force
