# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/30 13:32:36 by lilizarr          #+#    #+#              #
#    Updated: 2023/01/04 17:40:21 by lilizarr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
# ft_printf library
SRC =	push_swap.c				\

OBJS_DIR = ./obj/
OBJS = $(addprefix $(OBJS_DIR), $(SRC:.c=.o))

# libft library
LIBFT_DIR = lib/libft/
LIBFT = $(LIBFT_DIR)libft
FLAGS = -Wall -Wextra -Werror

all: $(LIBFT) $(OBJS_DIR) $(NAME)

$(NAME): $(OBJS)
	mv $(LIBFT).a push_swap.a
	ar -rcs push_swap.a $^
	ar -t push_swap.a
	cc $(FLAGS) -o $@ $^ push_swap.a

$(LIBFT):
	make -C $(LIBFT_DIR)

$(OBJS_DIR): 
	mkdir -p $@
#	echo -L$(LIBFT_DIR)

$(addprefix $(OBJS_DIR), %.o): %.c
	cc -c $(FLAGS) $^ -o $@ 
#-I$(LIBFT_DIR)
#-L/usr/lib -lmylibrary

clean:
	@echo "******** CLEAN LIBFT ************"
	make -C $(LIBFT_DIR) clean
	@echo "******** CLEAN ROOT ************"
	rm -rf $(OBJS_DIR)

fclean:	clean
	@echo "************ FCLEAN LIBFT ************"
	make -C $(LIBFT_DIR) fclean
	@echo "************ FCLEAN ROOT ************"
	rm -f $(NAME)

re: fclean all

test: re
	@echo "******** RUN TEST ************"
	@gcc ./main_test/main.c libftprintf.a
	@mv a.out ./main_test/a.out
	./main_test/a.out
	@echo "********************"
	leaks --atExit -- ./main_test/a.out
#	@rm ./main_test/a.out
#seq -1000 2000 | sort -R | tail -n 3 | tr '\n' ' '
# pwd | grep -o '[^/]*$'
# pwd | awk -F / '{print $NF}'
# basename $(pwd)
.PHONY: all clean fclean re