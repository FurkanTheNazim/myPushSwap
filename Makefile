NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -I includes -I libft

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = srcs/core/main.c \
       srcs/core/initializer.c \
       srcs/core/strategy_selector.c \
       srcs/parsing/parse_arguments.c \
       srcs/parsing/validate_numbers.c \
       srcs/parsing/normalize_input.c \
       srcs/structures/tower_create.c \
       srcs/structures/tower_utils.c \
       srcs/utils/error_handler.c

OBJS = $(SRCS:.c=.o)

HEADERS = includes/pushswap.h includes/definitions.h

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
