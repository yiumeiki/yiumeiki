# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myiu <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/09 21:03:58 by myiu              #+#    #+#              #
#    Updated: 2024/09/09 21:03:59 by myiu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_NAME		=	server
CLIENT_NAME		=	client

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
RM				=	rm
RM_FLAGS		=	-rf

CLIENT_SRC		=	function.c client.c
SERVER_SRC		=	function.c server.c
CLIENT_BOUNS	=	function.c client_bonus.c
SERVER_BOUNS	=	function.c server_bonus.c

CLIENT_OBJS		=	$(CLIENT_SRC:.c=.o)
SERVER_OBJS		=	$(SERVER_SRC:.c=.o)
CLIENT_BOUNS_OBJS	=	$(CLIENT_BOUNS:.c=.o)
SERVER_BOUNS_OBJS	=	$(SERVER_BOUNS:.c=.o)


.c.o: 
				@$(CC) $(CFLAGS) -c $< -o $@

all:			mandatory

mandatory:		$(SERVER_OBJS) $(CLIENT_OBJS) 
				@$(CC) $(CFLAGS) $(SERVER_OBJS) -o $(SERVER_NAME)
				@$(CC) $(CFLAGS) $(CLIENT_OBJS) -o $(CLIENT_NAME)

bonus:			$(SERVER_BOUNS_OBJS) $(CLIENT_BOUNS_OBJS)
				@$(CC) $(CFLAGS) $(SERVER_BOUNS_OBJS) -o $(SERVER_NAME)
				@$(CC) $(CFLAGS) $(CLIENT_BOUNS_OBJS) -o $(CLIENT_NAME)

clean:
			@$(RM) $(RM_FLAGS) $(SERVER_OBJS) $(CLIENT_OBJS) $(SERVER_BOUNS_OBJS) $(CLIENT_BOUNS_OBJS)

fclean:		clean
			@$(RM) $(RM_FLAGS) $(SERVER_NAME) $(CLIENT_NAME)

re:			fclean all

.PHONY:		all bonus clean fclean re