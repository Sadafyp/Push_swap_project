NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I.

SRCS        = main.c \
              parse_utils.c \
              op_push.c \
              op_swap.c \
              op_rotate.c \
              op_reverse_rotate.c \
              sort_simple.c \
              sort_utils.c \
              stack.c \
              stack.utils.c \
			  sort_large.c

OBJS        = $(SRCS:.c=.o)

LIBFT_DIR   = ./libft
PRINTF_DIR  = ./printf

LIBFT       = $(LIBFT_DIR)/libft.a
PRINTF      = $(PRINTF_DIR)/libftprintf.a
all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	@make -C $(PRINTF_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(PRINTF_DIR)
	rm -f $(OBJS)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(PRINTF_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
