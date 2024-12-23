CC = gcc
CFLAG = -Wall -Wextra -Werror
LFLAG = -lreadline
NAME = minishell
SRCS = *.c
# OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) $(CFLAG) -o $(NAME) $(SRCS) $(LFLAG)

# $(NAME): $(OBJS)
# 	$(CC) $(LFLAG) -o $(NAME) $(OBJS)

# %.o: %.c
# 	$(CC) $(CFLAG) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
