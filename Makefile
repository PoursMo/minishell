CC = gcc
SRCS = minishell.c	\
	signals/signals.c	\
    parsing/tokenization.c \
    parsing/parsing_utils.c \
    parsing/variable_expansion.c \
    parsing/variable_expansion_size.c \
    parsing/variable_expansion_utils.c \
    parsing/syntax_errors.c \
    parsing/quote_removal.c \
    parsing/parsing.c \
    utils/exit_code.c \
    utils/utils.c \
	utils/minishell_env.c \
	utils/std_streams.c \
    execution/redirection.c \
    execution/execution.c \
    execution/command_checking.c \
    execution/execution_pipeline.c \
    execution/execution_utils.c \
    execution/execution2.c \
    builtins/ft_echo.c \
	builtins/change_directory.c \
	builtins/get_pwd.c \
	builtins/export_var/export_var.c \
	builtins/export_var/export_var_utils.c \
	builtins/export_var/export_var_utils2.c \
	builtins/export_var/export_var_utils3.c \
	builtins/export_var/remove_var.c \
	builtins/export_var/new_environ.c \
	builtins/exit_w_status.c \
	builtins/my_get_env.c \
	builtins/builtins_sorter/echo_sorter.c \
	builtins/builtins_sorter/cd_sorter.c \
	builtins/builtins_sorter/export_sorter.c \
	builtins/builtins_sorter/unset_sorter.c \
	builtins/builtins_sorter/env_sorter.c \
	history/minishell_history.c

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
	@./$(NAME)

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all --suppressions=ignore_readline_leaks.supp ./minishell

test_wsl: ${LIBFT} ${OBJS}
	$(CC) -o $(NAME) $(OBJS) $(LIBFT)  $(LFLAGS)
	./$(NAME)


re: fclean all
