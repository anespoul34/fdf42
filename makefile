#
#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anespoul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/02 11:58:05 by anespoul          #+#    #+#              #
#    Updated: 2016/03/21 13:40:05 by anespoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re norme

NAME = fdf

FLAGS = -lmlx -framework OpenGL -framework AppKit

SRC = fdf.c ./libft/libft.a ft_create_map.c ft_create_int_tab.c \
	  ft_color.c ft_line.c ft_row.c ft_check_isoline.c ft_check_isorow.c \
	  keycode.c list.c error.c

LIB =-L libft

all: $(NAME)

$(NAME):
	make -C libft/
	gcc -o $(NAME) $(SRC) $(FLAGS)

clean:
	make -C libft clean

fclean: clean
	make -C libft fclean
	rm -fv $(NAME)

re: fclean all

norme:
	norminette $(SRC)
