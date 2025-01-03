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

$(MAINOBJ): $(MAINSRC)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS): $(OBJSDIR)
# make -C test_module
# make -C folder2
# make -C folder3

$(OBJSDIR):
	mkdir $(OBJSDIR)

$(LIBFT):
	make -C libft

$(NAME): $(LIBFT) $(OBJS) $(MAINOBJ) 
	$(CC) $(LFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

clean:
	rm -rf $(OBJSDIR)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

test: all
	./$(NAME)

re: fclean all
