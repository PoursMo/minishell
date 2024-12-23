CC = gcc
CFLAG = -Wall -Wextra -Werror
NAME = minishell
SRCS = *.c
# OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) $(CFLAG) -o $(NAME) $(SRCS)

# $(NAME): $(OBJS)
# 	$(CC) $(CFLAG) -o $(NAME) $(OBJS)

# %.o: %.c
# 	$(CC) $(CFLAG) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
