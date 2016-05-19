# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fviolin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/03 10:01:11 by fviolin           #+#    #+#              #
#    Updated: 2016/05/19 10:58:51 by fviolin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select

C_DIR = srcs
C_FILES = $(shell find $(C_DIR) -type f -follow -print | grep "\.c")

OBJ = $(C_FILES:.c=.o)
FLAGS = -Wall -Werror -Wextra
LIB = -L./libft -lft -ltermcap

$(NAME): $(OBJ)
	make -C ./libft
	gcc $(FLAGS) $(OBJ) $(LIB) -o $(NAME)

all: $(NAME)

%.o: %.c
	gcc $(FLAGS) -o $@ -c $<

clean :
	rm -f $(OBJ)
	make -C libft/ clean

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft

re: fclean all

.PHONY : all clean fclean re
