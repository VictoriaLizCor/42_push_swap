# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iczarnie <iczarnie@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/24 20:27:15 by iczarnie          #+#    #+#              #
#    Updated: 2022/04/24 20:27:15 by iczarnie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
CC = gcc
SRC = main.c choosing_move.c from_libft.c p_operations.c \
		r_operations.c rr_operations.c s_operations.c \
		scoring.c sort3.c stack.c arrays.c \
		stack_sorting.c errors.c

OBJ = $(SRC:.c=.o)
$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $^ -o $@ 

all: $(NAME)
clean:
		$(RM) $(OBJ)
fclean: clean
		$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re