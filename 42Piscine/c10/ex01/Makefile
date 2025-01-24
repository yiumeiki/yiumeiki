# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myiu <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/17 12:36:11 by myiu              #+#    #+#              #
#    Updated: 2024/07/18 20:21:25 by myiu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_cat

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_cat.c\
	ft_cat2.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
