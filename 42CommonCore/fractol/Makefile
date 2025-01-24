# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myiu <myiu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/09 13:14:18 by myiu              #+#    #+#              #
#    Updated: 2024/12/16 12:41:31 by myiu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = cc

CFLAGS = -Wall -Wextra -Werror -Iincludes -Iminilibx-linux

# Minilibx
MLX_PATH	= minilibx-linux/
MLX_NAME	= libmlx_Linux.a
MLX			= $(MLX_PATH)$(MLX_NAME)

LIBFLAGS = -lXext -lX11 -lm -lbsd
	
SRCS = fractol.c mandelbrot.c helper.c julia.c burning.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(MLX):
	@make -sC $(MLX_PATH)
	
$(NAME): $(OBJS) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(MLX) -o $(NAME) $(LIBFLAGS)


clean:
	rm -f $(OBJS)
	@make clean -C $(MLX_PATH)
	
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean
