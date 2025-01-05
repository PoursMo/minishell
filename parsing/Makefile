CC = gcc
SRCS = parsing.c redirection.c
CFLAGS = -Wall -Wextra -Werror -I../headers -I../libft
OBJSDIR = ../objects
OBJS = $(SRCS:.c=.o)

all: $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $(OBJSDIR)/$@