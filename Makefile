# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amargy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/01 13:26:43 by amargy            #+#    #+#              #
#    Updated: 2019/09/01 21:00:20 by amargy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 	fillit

SRCS = 	main.c \
		valid.c \
		put_figure_in_structure.c \
		square_size.c \
		solution.c \

OBJS = 	main.o \
		valid.o \
		put_figure_in_structure.o \
		square_size.o \
		solution.o \

FLAGS = -Wall -Wextra -Werror

LIB = make -C libft/

H_DIR = ./

LIB_DIR = ./libft/

all: $(NAME)

$(NAME):
	$(LIB)
	gcc -c $(SRCS) -I $(H_DIR) -I $(LIB_DIR) $(FLAGS)
	gcc $(OBJS) -o $(NAME) -L $(LIB_DIR) -lft

clean:
	rm -f $(OBJS)
	make clean -C $(LIB_DIR)

fclean:
	rm -f $(NAME)
	rm -f $(OBJS)
	make fclean -C $(LIB_DIR)

re: fclean all
