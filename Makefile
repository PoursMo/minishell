CC = gcc
SRCS = minishell.c	\

OBJSDIR = objects
OBJS = $(patsubst %.c,$(OBJSDIR)/%.o,$(SRCS))
LFLAGS = -lreadline
CFLAGS = -Wall -Wextra -Werror -Iheaders -Ilibft
NAME = minishell
LIBFT = libft/libft.a

all: $(NAME)

$(OBJSDIR)/%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(LFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(LIBFT):
	make -C libft
	@echo "\033[32mLIBFT COMPILED\033[0m"
	@echo ""

$(OBJS): $(OBJSDIR)

clean:
	rm -f $(OBJS)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

test: all
	./$(NAME)

re: fclean all
