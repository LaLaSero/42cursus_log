NAME = push_swap
SRCS = push_swap_srcs/main.c push_swap_srcs/check_args.c push_swap_srcs/lst_funcs.c push_swap_srcs/radix_sort.c
SRCS += push_swap_srcs/sort_small_numbers.c push_swap_srcs/swap_rules.c push_swap_srcs/init_stack.c push_swap_srcs/push_swap.c
INCLUDE = includes
CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)
LIBFT = libft/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C libft

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

%.o: %.c $(INCLUDE)
	$(CC) -c $(CFLAGS) -o $@ $< -I $(INCLUDE)

clean:
	rm -f $(OBJS)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
