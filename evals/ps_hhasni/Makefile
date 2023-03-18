#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhasni <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/29 12:51:34 by hhasni            #+#    #+#              #
#    Updated: 2014/05/12 17:44:45 by hhasni           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		push_swap

CPATH =		./srcs/

HPATH =		-I ./includes/

SRCS =		main.c \
			ft_fill.c \
			ft_tools.c \
			ft_is.c \
			ft_ope.c \
			ft_putchar.c \
			ft_pushswap.c 

OBJS =		$(SRCS:.c=.o)

CC =		clang

CFLAGS =	-Wall -Wextra -Werror

RM =		rm -rf

all:		$(NAME)

$(NAME):	$(OBJS)
			@echo "\n\r\033[38;5;11m⌛  MAKE $(NAME) plz wait...\033[0m\033[K"
			@$(CC) -o $(NAME) $(CFLAGS) $(OBJS)
			@echo -en "\r\033[38;5;22m✅  MAKE $(NAME)\033[0m\033[K"

%.o:		$(CPATH)%.c
			@$(CC) -c $< $(CFLAGS) $(HPATH)

clean:
			@$(RM) $(OBJS)
			@echo -en "\r\033[38;5;124m❌  CLEAN $(NAME) \033[0m\033[K"

fclean:		clean
			@$(RM) $(NAME)
			@echo -en "\r\033[38;5;124m❌  FCLEAN $(NAME) \033[0m\033[K"

re:			fclean all
