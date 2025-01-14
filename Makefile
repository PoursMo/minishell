CC = gcc
SRCS = minishell.c	\
		builtins/ft_echo.c \
		builtins/change_directory.c \
		builtins/get_pwd.c

OBJSDIR = objects
OBJS = $(SRCS:%.c=$(OBJSDIR)/%.o)
LFLAGS = -lreadline
CFLAGS = -Wall -Wextra -Werror -Iheaders -Ilibft
NAME = minishell
LIBFT = libft/libft.a

all: $(NAME)

$(OBJSDIR)/%.o : %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(LFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(LIBFT):
	make -C libft
	@echo "\033[32mLIBFT COMPILED\033[0m"
	@echo ""

clean:
	rm -rf $(OBJSDIR)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

test: all
	./$(NAME)

re: fclean all
