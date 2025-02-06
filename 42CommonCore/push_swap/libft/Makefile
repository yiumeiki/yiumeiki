# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myiu <myiu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/26 17:35:28 by myiu              #+#    #+#              #
#    Updated: 2025/02/01 18:40:55 by myiu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_atoi.c ft_strchr.c ft_strlen.c ft_strncmp.c ft_strnstr.c \
	ft_memset.c ft_putstr_fd.c ft_calloc.c ft_bzero.c ft_split.c \
	ft_strdup.c

OBJS = ${SRCS:.c=.o}
NAME = libft.a
RM = rm -f
CC = cc
CFLAGS = -Wall -Wextra -Werror
INC = -I../inc

all : ${NAME}

${NAME} : ${OBJS}
	ar rc ${NAME} ${OBJS}

%.o : %.c
	${CC} ${CFLAGS} $(INC) -c $< -o ${<:.c=.o}

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all
