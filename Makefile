CC = gcc
SRC = minishell.c
OBJ = $(OBJSDIR)/minishell.o
HEADERS = headers
LFLAG = -lreadline
CFLAGS = -Wall -Wextra -Werror -I$(HEADERS)
NAME = minishell
OBJSDIR = objects
OBJS = $(OBJSDIR)/*.o

all: $(NAME)

$(OBJS): $(OBJSDIR) $(SRC)
	$(CC) $(CFLAGS) -c $(SRC) -o $(OBJ)
# make -C test_module
# make -C folder2
# make -C folder3

$(OBJSDIR):
	mkdir $(OBJSDIR)

$(NAME): $(OBJS)
	$(CC) $(LFLAG) -o $(NAME) $(OBJS)

clean:
	rm -rf $(OBJSDIR)

fclean: clean
	rm -f $(NAME)

test: all
	./$(NAME)

re: fclean all
