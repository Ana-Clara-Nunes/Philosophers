# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anunes-o <anunes-o@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/27 13:12:50 by anunes-o          #+#    #+#              #
#    Updated: 2026/05/28 17:05:54 by anunes-o         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= philo
CC 		:= cc
CFLAGS 	:= -Wall -Wextra -Werror

SRC_DIR := src

SRC 	:= $(SRC_DIR)

/* ************************************************************************** */
/*                               SOURCE			                              */
/* ************************************************************************** */
SRC		:= main.c
		$(SRC)/init.c \
		$(SRC)/pasing.c \
		$(SRC)/routines.c \
		$(SRC)/time_utils.c \
		$(SRC)/cleanup.c \
		
OBJS	:= $(SRC:.c=.o)

/* ************************************************************************** */
/*                                 RULES		                              */
/* ************************************************************************** */

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -lpthread -o $(NAME)

clean:
	rm -f $(OBJS)
	$(MAKE) -C clean --no-print-directory

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean --no-print-directory

re: fclean all

.PHONY: all clean fclean re