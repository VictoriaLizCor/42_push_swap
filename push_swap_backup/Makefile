# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/30 13:32:36 by lilizarr          #+#    #+#              #
#    Updated: 2023/01/22 11:40:54 by lilizarr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC =	push_swap.c				\
		check.c					\
		check_utils.c			\
		swap.c					\
		rotate.c				\
		reverse_rotate.c		\
		update.c				\
		pop_push.c				\
		sorting_algorithm.c		\
		push_swap_utils.c		\

OBJS_DIR = obj/
OBJS = $(addprefix $(OBJS_DIR), $(SRC:.c=.o))
#COM_OBJS = $(addprefix $(OBJS_DIR), %.o)
# libft library
LIBFT_DIR = lib/libft/
LIBFT = $(LIBFT_DIR)libft.a
FLAGS = -Wall -Wextra -Werror

all: make_libft $(OBJS_DIR) $(NAME)
# 
make_libft:
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJS)
#	mv $(LIBFT).a push_swap.a
#	ar -rcs push_swap.a $^
#	ar -t push_swap.a
	cc $(FLAGS) $^ $(LIBFT) -o $@

$(OBJS_DIR): 
	mkdir -p $@
#	echo -L$(LIBFT_DIR)

$(addprefix $(OBJS_DIR), %.o): %.c
	cc -c $(FLAGS) $^ -o $@ 

#-I$(LIBFT_DIR)
#-L/usr/lib -lmylibrary

	
clean:
	@echo "\n************  CLEAN LIBFT ************" 
	@make -C $(LIBFT_DIR) clean
	@echo "\n************  CLEAN ROOT  ************"
	rm -rf $(OBJS_DIR)

fclean:	clean
	@echo "\n************  FCLEAN LIBFT  ************"
	@make -C $(LIBFT_DIR) fclean
	@echo "\n************  FCLEAN ROOT   ************"
	rm -f $(NAME)

re: fclean all

test: $(NAME)
	@echo "******** RUNNING TEST [21 1 5]************"
	$(eval NUMBERS = -839 -1320 -1670 954 -115)
	./push_swap $(NUMBERS)
	@echo "********************"

testr3: $(NAME)
	@echo "******** RUNNING TEST [21 1 5]************"
	$(eval NUMBERS = $(shell seq -2000 2000 | sort -R | tail -n 3 | tr '\n' ' '))
	./push_swap $(NUMBERS)
	@echo "********************"

testr4: $(NAME)
	@echo "******** RUNNING TEST [21 1 5]************"
	$(eval NUMBERS = $(shell seq -2000 2000 | sort -R | tail -n 4 | tr '\n' ' '))
	./push_swap $(NUMBERS)
	@echo "********************"

testr5: $(NAME)
	@echo "******** RUNNING TEST [21 1 5]************"
	$(eval NUMBERS = $(shell seq -2000 2000 | sort -R | tail -n 5 | tr '\n' ' '))
	./push_swap $(NUMBERS)
	@echo "********************"

leaks:
	@echo "******** RUNNING TEST [21 1 5]************"
	$(eval NUMBERS = 21 1 5)
	leaks --atExit -- ./push_swap $(NUMBERS)
	@echo "********************"
	
random: $(NAME)
	@echo "******** RUNNING x:in:N RANDOM NUMBERS  || x = [-2000, 2000] || N = [1, 10]************"
	$(eval SIZE = $(shell seq 1 10 | sort -R | tail -n 1 | tr '\n' ' '))
	$(eval NUMBERS = $(shell seq -2000 2000 | sort -R | tail -n $(SIZE) | tr '\n' ' '))
	./push_swap $(NUMBERS)
	@echo "********************"

randoml: $(NAME)
	@echo "******** RUNNING x:in:N RANDOM NUMBERS  || x = [-2000, 2000] || N = [1, 10]************"
	$(eval SIZE = $(shell seq 1 10 | sort -R | tail -n 1 | tr '\n' ' '))
	$(eval NUMBERS = $(shell seq -2000 2000 | sort -R | tail -n $(SIZE) | tr '\n' ' '))
	leaks --atExit -- ./push_swap $(NUMBERS)
	@echo "********************"

randomb: $(NAME)
	@echo "******** RUNNING TEST ************"
	$(eval SIZE = $(shell seq 1 20 | sort -R | tail -n 1 | tr '\n' ' '))
	$(eval NUMBERS = $(shell seq -2000 2000 | sort -R | tail -n $(SIZE) | tr '\n' ' '))
	./push_swap $(NUMBERS)
	@echo "********************"

randombl: $(NAME)
	@echo "******** RUNNING TEST ************"
	$(eval SIZE = $(shell seq 1 20 | sort -R | tail -n 1 | tr '\n' ' '))
	$(eval NUMBERS = $(shell seq -2000 2000 | sort -R | tail -n $(SIZE) | tr '\n' ' '))
	leaks --atExit -- ./push_swap $(NUMBERS)
	@echo "********************"
#	$(eval NUMBERS = $(shell seq -2000 2000 | sort -R | tail -n 3 | tr '\n' ' '))
#	./push_swap $(shell seq -2000 2000 | sort -R | tail -n 3 | tr '\n' ' ')

.PHONY: all clean fclean re


#	@rm ./main_test/a.out
#seq -1000 2000 | sort -R | tail -n 3 | tr '\n' ' '
# pwd | grep -o '[^/]*$'
# pwd | awk -F / '{print $NF}'
# basename $(pwd)
# NUMBERS=$(echo $(seq -2000 2000 | sort -R | tail -n 3 | tr '\n' ' '))
# printf "$NUMBERS"
#  echo $NUMBERS