# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myiu <myiu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/26 17:35:28 by myiu              #+#    #+#              #
#    Updated: 2025/02/03 11:22:43 by myiu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAIN = push_swap.c

FILES = check_args.c lst_manage.c push.c swap.c rotate.c rev_rotate.c \
	set_stack.c calculate_value.c sort.c utils.c calculate_cost.c \
	move_node.c parsing_args.c

SRC = $(FILES) $(MAIN)
SRC_BONUS = $(FILES) \
	checker.c get_next_line.c get_next_line_utils.c

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
BONUS = checker
LIBFT = libft/libft.a
RM = rm -rf
INC = -I./inc

all : start $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

start :
	make -C libft all

clean :
	make -C libft clean
	$(RM) $(OBJ)
	$(RM) $(OBJ_BONUS)

fclean : clean
	make -C libft fclean
	$(RM) $(NAME)
	$(RM) $(BONUS)

re : fclean all

bonus : start $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) -o $(BONUS)


test2:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-100 -n 2))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test3:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-100 -n 3))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test6:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 6))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test100:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 100))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test500:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 500))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

.PHONY: all clean fclean re
