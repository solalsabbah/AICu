#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rfautier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/23 20:54:38 by rfautier          #+#    #+#              #
#    Updated: 2018/02/03 17:26:16 by ssabbah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = alum1

SRC_NAME =	main.c\
			get_next_line.c\
			solve.c\
			get_next_file.c\
			ft_strsplitwhitespace.c

SRC_PATH = .
OBJ_PATH = .
CC = gcc
CFLAGS = -Wall -Wextra
CPPFLAGS = -I. -I./libft/ -I./ft_printf/includes/
LDFLAGS = -Llibft -Lft_printf
LDLIBS = -lft ./ft_printf/libftprintf.a
OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: library $(NAME)

$(NAME): $(OBJ)
	$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@

library:
	make -C ./libft
	make -C ./ft_printf

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

.PHONY: all, clean, fclean, re, library

clean:
		/bin/rm -f $(OBJ)
		make clean -C ./libft
		make clean -C ./ft_printf
fclean: clean
		/bin/rm -f $(NAME)
		make fclean -C ./libft
		make fclean -C ./ft_printf

re: fclean all
