# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/30 23:15:27 by pandalaf          #+#    #+#              #
#    Updated: 2022/11/03 23:04:00 by pandalaf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Target output
NAME := push_swap
BONUS_NAME := checker
# Compiler options
CC := cc
CFLAGS := -Wall -Werror -Wextra
COPTIONS :=
# Libft location
LIBFT := libft.a
LIBFT_PATH := libft/
LIBFT_FULL = $(addprefix $(LIBFT_PATH), $(LIBFT))
# Sources identification
SRC_DIR := src/
SRC_FILES := pushswap.c input.c checkers.c error.c memory.c numbers.c \
				indiv_checkers.c stack_functions.c node_functions.c \
				stack_operations.c stack_special.c operations_pushswap.c \
				operations_rotate.c operations_reverse_rotate.c stack_search.c \
				algo_preparation.c algo_execution.c algo_sort.c 
SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))
# Bonus sources identification
BSRC_DIR := src/bonus/
BSRC_FILES := checker.c operations_checker_pushswap.c \
				operations_checker_rotate.c operations_checker_reverse_rotate.c
BSRCS = $(addprefix $(BSRC_DIR), $(BSRC_FILES))

# Make desired targets
all: $(NAME)

# Make target executable
$(NAME): $(SRCS) $(LIBFT_FULL)
	$(CC) $(COPTIONS) $(CFLAGS) -o $(NAME) $(SRCS) $(LIBFT_FULL)

# Make bonus executable
bonus: $(BONUS_NAME)

# Make checker executable (bonus)
$(BONUS_NAME): $(BSRCS) $(filter-out src/pushswap.c, $(SRCS)) $(LIBFT_FULL)
	$(CC) $(COPTIONS) $(CFLAGS) -o $(BONUS_NAME) $(BSRCS) \
	$(filter-out src/pushswap.c, $(SRCS)) $(LIBFT_FULL)

# Make Libft archive
$(LIBFT_FULL): $(LIBFT_PATH)
	make -C $(LIBFT_PATH) bonus

# Clean intermediate files
clean:
	make -C $(LIBFT_PATH) clean

# Clean all non-source files
fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	make -C $(LIBFT_PATH) fclean

# Clean everything and make again
re: fclean all

# Make sure these aren't treated as filenames
.PHONY: all bonus clean fclean re
