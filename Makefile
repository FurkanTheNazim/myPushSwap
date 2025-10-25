NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -I includes

SRCS = srcs/core/main.c \
       srcs/core/initializer.c \
       srcs/core/strategy_selector.c \
       srcs/parsing/parse_arguments.c \
       srcs/parsing/validate_numbers.c \
       srcs/parsing/normalize_input.c \
       srcs/structures/tower_create.c \
       srcs/structures/tower_destroy.c \
       srcs/structures/tower_utils.c \
       srcs/actions/action_swap.c \
       srcs/actions/action_push.c \
       srcs/actions/action_rotate.c \
       srcs/actions/action_reverse.c \
       srcs/algorithms/sort_tiny.c \
       srcs/algorithms/sort_small.c \
       srcs/algorithms/sort_radix.c \
       srcs/utils/error_handler.c \
       srcs/utils/bitwise_ops.c \
       srcs/utils/array_tools.c

OBJS = $(SRCS:.c=.o)

HEADERS = includes/pushswap.h includes/definitions.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
