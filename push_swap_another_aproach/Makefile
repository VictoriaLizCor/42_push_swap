# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/30 13:32:36 by lilizarr          #+#    #+#              #
#    Updated: 2023/03/09 12:21:36 by lilizarr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC =	push_swap.c				\
		check.c					\
		check_utils.c			\
		check_utils2.c			\
		swap.c					\
		rotate.c				\
		reverse_rotate.c		\
		update.c				\
		pop_push.c				\
		sort_utils.c			\
		sorting_algorithm.c		\
		push_swap_utils.c		\

OBJS_DIR = obj/
OBJS = $(addprefix $(OBJS_DIR), $(SRC:.c=.o))
#COM_OBJS = $(addprefix $(OBJS_DIR), %.o)
# libft library
LIBFT_DIR = lib/libft/
LIBFT = $(LIBFT_DIR)libft.a
FLAGS = -Wall -Wextra #-Werror

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
	./push_swap $(NUMBERS) | wc -l
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
	./push_swap $(NUMBERS) | wc -l
	@echo "********************"

testr6: $(NAME)
	@echo "******** RUNNING TEST [21 1 5]************"
	$(eval NUMBERS = $(shell seq -2000 2000 | sort -R | tail -n 6 | tr '\n' ' '))
	./push_swap $(NUMBERS)
	@echo "********************"

testr7: $(NAME)
	@echo "******** RUNNING TEST [21 1 5]************"
	$(eval NUMBERS = $(shell seq -2000 2000 | sort -R | tail -n 7 | tr '\n' ' '))
	./push_swap $(NUMBERS)
	@echo "********************"

testr8: $(NAME)
	@echo "******** RUNNING TEST [21 1 5]************"
	$(eval NUMBERS = $(shell seq -2000 2000 | sort -R | tail -n 8 | tr '\n' ' '))
	./push_swap $(NUMBERS)
	@echo "********************"
testr10: $(NAME)
	@echo "******** RUNNING TEST [21 1 5]************"
	$(eval NUMBERS = $(shell seq -2000 2000 | sort -R | tail -n 10 | tr '\n' ' '))
	./push_swap $(NUMBERS)
	@echo "********************"
t100: $(NAME)
	@echo "******** RUNNING TEST************"
	$(eval NUMBERS = $(shell seq -2000 2000 | sort -R | tail -n 100 | tr '\n' ' '))
	./push_swap $(NUMBERS)
	@./push_swap $(NUMBERS) | wc -l
	@echo "./push_swap $(NUMBERS) | wc -l"
	@echo "********************"

t500: $(NAME)
	@echo "******** RUNNING TEST************"
	$(eval NUMBERS = $(shell seq -2000 2000 | sort -R | tail -n 500 | tr '\n' ' '))
	./push_swap $(NUMBERS)
	@./push_swap $(NUMBERS) | wc -l
	@echo "./push_swap $(NUMBERS) | wc -l"
	@echo "********************"

leaks:
	@echo "******** RUNNING TEST [21 1 5]************"
	$(eval NUMBERS = 21 1 5)
	leaks --atExit -- ./push_swap $(NUMBERS)
	@echo "********************"
	
ran10: $(NAME)
	@echo "******** RUNNING x:in:N RANDOM NUMBERS  || x = [-2000, 2000] || N = [1, 10]************"
	$(eval SIZE = $(shell seq 1 10 | sort -R | tail -n 1 | tr '\n' ' '))
	$(eval NUMBERS = $(shell seq -2000 2000 | sort -R | tail -n $(SIZE) | tr '\n' ' '))
	./push_swap $(NUMBERS)
	@echo size $(SIZE)
	@echo "./push_swap $(NUMBERS) | wc -l"
	@echo "********************"

randoml: $(NAME)
	@echo "******** RUNNING x:in:N RANDOM NUMBERS  || x = [-2000, 2000] || N = [1, 10]************"
	$(eval SIZE = $(shell seq 1 10 | sort -R | tail -n 1 | tr '\n' ' '))
	$(eval NUMBERS = $(shell seq -2000 2000 | sort -R | tail -n $(SIZE) | tr '\n' ' '))
	leaks --atExit -- ./push_swap $(NUMBERS)
	@echo "********************"

ran30: $(NAME)
	@echo "******** RUNNING TEST ************"
	$(eval SIZE = $(shell seq 10 30 | sort -R | tail -n 1 | tr '\n' ' '))
	$(eval NUMBERS = $(shell seq -2000 2000 | sort -R | tail -n $(SIZE) | tr '\n' ' '))
	./push_swap $(NUMBERS)
	@./push_swap $(NUMBERS) | wc -l
	@echo size $(SIZE)
	@echo "./push_swap $(NUMBERS) | wc -l"
	@echo "********************"

ran50: $(NAME)
	@echo "******** RUNNING TEST ************"
	$(eval SIZE = $(shell seq 20 50 | sort -R | tail -n 1 | tr '\n' ' '))
	$(eval NUMBERS = $(shell seq -2000 2000 | sort -R | tail -n $(SIZE) | tr '\n' ' '))
	./push_swap $(NUMBERS)
	@./push_swap $(NUMBERS) | wc -l
	@echo size $(SIZE)
	@echo "./push_swap $(NUMBERS) | wc -l"
	@echo "********************"
	
ran500: $(NAME)
	@echo "******** RUNNING TEST ************"
	$(eval SIZE = $(shell seq 499 500 | sort -R | tail -n 1 | tr '\n' ' '))
	$(eval NUMBERS = $(shell seq -2000 2000 | sort -R | tail -n $(SIZE) | tr '\n' ' '))
	./push_swap $(NUMBERS)
	@echo size $(SIZE)
	@echo "./push_swap $(NUMBERS) | wc -l"
#	@echo "********************"

ranl500: $(NAME)
	@echo "******** RUNNING TEST ************"
	$(eval SIZE = $(shell seq 20 500 | sort -R | tail -n 1 | tr '\n' ' '))
	$(eval NUMBERS = $(shell seq -2000 2000 | sort -R | tail -n 200 | tr '\n' ' '))
	./push_swap $(NUMBERS)
	@echo size $(SIZE)
	@echo "./push_swap $(NUMBERS) | wc -l"
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

# printf "$NUMBERS"
# SIZE=$(seq 1 20 | sort -R | tail -n 1 | tr '\n' ' ')
# NUMBERS=$(seq -2000 2000 | sort -R | tail -n $(echo $SIZE) | tr '\n' ' ')
#  echo $NUMBERS
# ./test $(echo $NUMBERS)

