CC = gcc
<<<<<<< HEAD
SRCS = minishell.c	\
=======
SRCS = minishell.c \
parsing/tokenization.c \
parsing/parsing_utils.c \
parsing/variable_expansion.c \
parsing/variable_expansion_size.c \
parsing/variable_expansion_utils.c \
parsing/syntax_errors.c \
parsing/quote_removal.c \
parsing/tester.c \
parsing/parsing.c \
utils/exit_code.c \
>>>>>>> parsing

OBJSDIR = objects
OBJS = $(SRCS:%.c=$(OBJSDIR)/%.o)
LFLAGS = -lreadline
<<<<<<< HEAD
CFLAGS = -Wall -Wextra -Werror -Iheaders -Ilibft
=======
CFLAGS = -Wall -Wextra -Werror -Iheaders -Ilibft -g
>>>>>>> parsing
NAME = minishell
LIBFT = libft/libft.a

all: $(NAME)

$(OBJSDIR)/%.o : %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(OBJS)
<<<<<<< HEAD
	$(CC) $(LFLAGS) -o $(NAME) $(OBJS) $(LIBFT)
=======
	$(CC) $(OBJS) -o $(NAME) $(LIBFT) $(LFLAGS)
>>>>>>> parsing

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
