# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myiu <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/24 19:50:58 by myiu              #+#    #+#              #
#    Updated: 2024/07/25 15:22:18 by myiu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_tail

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_tail.c\
	str_functions.c

OBJS = $(SRCS:.c=.o)

HEADERS = ft.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
