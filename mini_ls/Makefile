NAME	= ft_mini_ls
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
SRCS	= ./main.c ./ft_mini_ls.c ./ft_mini_ls_sort.c
OBJS	= $(SRCS:.c=.o)


LIBFT_DIR	= ./libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBS = -L $(LIBFT_DIR) -lft
INCLUDE = -I. -I./$(LIBFT_DIR)


all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) $(LIBS) -o $(NAME)

$(LIBFT): $(LIBFT_DIR)/*.c
	$(MAKE) -C $(LIBFT_DIR)

%.o:%.c
		$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

clean:;         $(RM) *.o

fclean:clean;		$(RM) $(NAME)
					$(MAKE) -C $(LIBFT_DIR) clean

re:			fclean $(NAME)
			$(MAKE) -C $(LIBFT_DIR) fclean

.PHONY: re clean fclean all
