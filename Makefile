# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbellona <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/24 16:32:39 by lbellona          #+#    #+#              #
#    Updated: 2019/01/08 00:42:43 by lbellona         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = fillit.c\
	solve_map.c\
	map_f.c\
	validation.c

NAME = fillit
WWW = -Wall -Wextra -Werror
INCLUDES = fillit.h

all: $(NAME)

$(NAME):
	make -C ./libft/
	gcc $(WWW) $(SOURCES) -I ./libft/ -L libft -lft -o $(NAME)

clean:
	make -C ./libft/ clean

fclean: clean
	make -C ./libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all
