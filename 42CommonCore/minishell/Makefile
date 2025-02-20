CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

SRC_DIR := ./src

BUILD_DIR:= ./build

SRC = $(SRC_DIR)/main.c \
	  $(SRC_DIR)/init.c \
	  $(SRC_DIR)/entries.c \
	  $(SRC_DIR)/prompt.c \
	  $(SRC_DIR)/env/env_list.c \
	  $(SRC_DIR)/env/envp.c \
	  $(SRC_DIR)/exec/exec.c \
	  $(SRC_DIR)/exec/exec_child.c \
	  $(SRC_DIR)/exec/exec_utils.c \
	  $(SRC_DIR)/builtins/cd.c \
	  $(SRC_DIR)/builtins/env.c \
	  $(SRC_DIR)/builtins/pwd.c \
	  $(SRC_DIR)/builtins/echo.c \
	  $(SRC_DIR)/builtins/exit.c \
	  $(SRC_DIR)/parsing/strip_quotes.c \
	  $(SRC_DIR)/parsing/pipes.c \
	  $(SRC_DIR)/parsing/parse_line.c \
	  $(SRC_DIR)/parsing/commands/commands.c \
	  $(SRC_DIR)/parsing/commands/parse_tree.c \
	  $(SRC_DIR)/parsing/commands/cmdlist_construct.c \
	  $(SRC_DIR)/parsing/commands/ptree_construct.c \
	  $(SRC_DIR)/parsing/tokenise/tokenise.c \
	  $(SRC_DIR)/parsing/tokenise/tokenise_utils.c \
	  $(SRC_DIR)/parsing/expansion/expansion.c \
	  $(SRC_DIR)/parsing/expansion/expansion_vars.c \
	  $(SRC_DIR)/parsing/expansion/expansion_tilde.c \
	  $(SRC_DIR)/parsing/expansion/expansion_wildcards.c \
	  $(SRC_DIR)/parsing/redirect/redirect.c \
	  $(SRC_DIR)/parsing/redirect/redirect_actions.c \
	  $(SRC_DIR)/parsing/redirect/heredoc.c \
	  $(SRC_DIR)/parsing/redirect/heredoc_utils.c \
	  $(SRC_DIR)/signals/signals.c \
	  $(SRC_DIR)/parsing/syntax.c \
	  $(SRC_DIR)/parsing/syntax_utils.c \

OBJ = $(patsubst $(SRC_DIR)/%,$(BUILD_DIR)/%,$(SRC:.c=.o))

NAME = minishell

LIBFT = libft/libft.a

mand: $(NAME)

all: mand

$(NAME): $(LIBFT) $(BUILD_DIR) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L ./libft -lft -lreadline

$(OBJ): $(BUILD_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(LIBFT):
	make -C libft/ bonus

$(BUILD_DIR):
	mkdir -p $@/builtins
	mkdir -p $@/parsing/tokenise
	mkdir -p $@/parsing/expansion
	mkdir -p $@/parsing/redirect
	mkdir -p $@/parsing/commands
	mkdir -p $@/exec
	mkdir -p $@/env
	mkdir -p $@/signals

clean:
	rm -rf ./build/
	make -C libft/ clean

fclean: clean
	rm -rf $(NAME)
	make -C libft/ fclean

re: fclean all
.PHONY: all clean fclean re mand bonus
