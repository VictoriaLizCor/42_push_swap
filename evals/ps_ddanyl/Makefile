# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 20:10:07 by dsas              #+#    #+#              #
#    Updated: 2023/01/27 16:10:40 by dsas             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compilation
NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
DEBUG = -fsanitize=address
LEAKS = leaks -atExit -- ./push-swap

BONUS = checker
BONUS_MAIN = checker.c

MAIN = push_swap.c

# Libraries
LIBFTPRINTF_A = libft/libft.a

# Paths
SRC_PATH = src/
OBJ_PATH = obj/
LIBFTPRINTF = libft

# Source and object files
SRCS =	input_checking/get_input.c \
		utils/node_utils.c \
		utils/node_find.c \
		utils/key_find.c \
		utils/lis.c \
		utils/operations.c \
		utils/stack_rotating.c \
		operations/push.c \
		operations/revrotate.c \
		operations/rotate.c \
		operations/swap.c \
		sorting/sort_big.c \
		sorting/sort_small.c \
		sorting/transfer.c \
		sorting/sort_small2.c

OBJ = $(SRCS:.c=.o)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

# Rules
all: $(NAME) bonus

$(OBJ_PATH):
	mkdir $(OBJ_PATH)
#$(DEBUG)
$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFTPRINTF) bonus
	mv $(LIBFTPRINTF_A) libft.a
	$(CC) $(CFLAGS) $(OBJ) $(MAIN) -L. -lft -o $(NAME)

bonus: $(BONUS)

$(BONUS): $(OBJ)
	$(MAKE) -C $(LIBFTPRINTF) bonus
	mv $(LIBFTPRINTF_A) libft.a
	@$(CC) $(CFLAGS) $^ $(BONUS_MAIN) -L. -lft -o $@

clean:
	rm -rf $(OBJ)
	rm -rf libft.a
	$(MAKE) clean -C $(LIBFTPRINTF)

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS)

re: fclean all

.PHONY: all clean fclean re
