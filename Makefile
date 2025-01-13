CC = gcc
SRCS = minishell.c \
parsing/tokenization.c \
parsing/parsing_utils.c \
parsing/variable_expansion.c \
parsing/syntax_parsing.c \
parsing/quote_removal.c \
parsing/tester.c \
parsing/parsing.c \

OBJSDIR = objects
OBJS = $(SRCS:%.c=$(OBJSDIR)/%.o)
LFLAGS = -lreadline
CFLAGS = -Wall -Wextra -Werror -Iheaders -Ilibft -g
NAME = minishell
LIBFT = libft/libft.a

all: $(NAME)

$(OBJSDIR)/%.o : %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LIBFT) $(LFLAGS)

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
