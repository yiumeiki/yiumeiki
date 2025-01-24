NAME = rush-02

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = dict_conversion.c\
	dict_parser.c\
	number_format.c\
	str_ft.c\
	main.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

VGFLAGS = --leak-check=full -s --show-reachable=no --track-origins=yes --keep-stacktraces=alloc-and-free --error-limit=no --num-callers=40 --show-leak-kinds=all

grind:
	Valgrind $(VGFLAGS) ./$(OBJS)1
