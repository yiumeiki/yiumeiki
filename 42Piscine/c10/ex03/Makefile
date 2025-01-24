# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myiu <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/17 17:29:40 by myiu              #+#    #+#              #
#    Updated: 2024/07/22 20:57:26 by myiu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_hexdump

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCS = ft_hexdump.c\
	ft_needed.c\
	ft_more.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
