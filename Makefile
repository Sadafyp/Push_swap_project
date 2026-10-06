NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I.

SRCS        = main.c \
			  config.c \
              parse_utils.c \
              op_push.c \
              op_swap.c \
              op_rotate.c \
              op_reverse_rotate.c \
              sort_simple.c \
              sort_utils.c \
              stack.c \
              stack_utils.c \
			  sort_complex.c \
			  disorder.c \
			  sort_medium.c \
			  bench.c

OBJS        = $(SRCS:.c=.o)

LIBFT_DIR   = ./libft

LIBFT       = $(LIBFT_DIR)/libft.a
all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C $(LIBFT_DIR)
	rm -f $(OBJS)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
