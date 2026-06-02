# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anunes-o <anunes-o@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/27 13:12:50 by anunes-o          #+#    #+#              #
#    Updated: 2026/06/02 16:12:32 by anunes-o         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= philo
CC 		:= cc
CFLAGS 	:= -Wall -Wextra -Werror -I.

SRC_DIR := src

# **************************************************************************** #
#                               SOURCE			                              #
# **************************************************************************** #
SRC		:= main.c \
		$(SRC_DIR)/init.c \
		$(SRC_DIR)/parsing.c \
		$(SRC_DIR)/routines.c \
		$(SRC_DIR)/time_utils.c \
		$(SRC_DIR)/cleanup.c \
		$(SRC_DIR)/bon_appetit.c \
		$(SRC_DIR)/monitor.c \
		
OBJS	:= $(SRC:.c=.o)

# **************************************************************************** #
#                                 RULES		                              #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -lpthread -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

valgrind: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes ./philo 
	
.PHONY: all clean fclean re