CC = gcc
MAINSRC = minishell.c
MAINOBJ = $(OBJSDIR)/minishell.o
LFLAGS = -lreadline
CFLAGS = -Wall -Wextra -Werror -Iheaders -Ilibft
NAME = minishell
OBJSDIR = objects
OBJS = $(OBJSDIR)/*.o
LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(MAINOBJ) $(OBJS)
	$(CC) $(LFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(LIBFT):
	make -C libft

$(MAINOBJ): $(MAINSRC) $(OBJSDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS): $(OBJSDIR)
	make -C parsing

$(OBJSDIR):
	mkdir $(OBJSDIR)

clean:
	rm -rf $(OBJSDIR)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

test: all
	./$(NAME)

re: fclean all
