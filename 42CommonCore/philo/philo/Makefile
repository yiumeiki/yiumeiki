# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myiu <myiu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/30 09:37:13 by myiu              #+#    #+#              #
#    Updated: 2025/02/06 13:25:22 by myiu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc

CFLAGS = -Wall -Werror -Wextra #-pthread -fsanitize=thread

CFILES = philo.c initalise.c helper.c thread.c

OBJECTS = $(CFILES:.c=.o)

all: $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJECTS)
	@$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
