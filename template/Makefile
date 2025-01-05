CC = gcc
SRCS = *.c #explicitely name every source
CFLAGS = -Wall -Wextra -Werror -I../headers -I../libft
OBJSDIR = ../objects
OBJS = $(SRCS:.c=.o)

all: $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $(OBJSDIR)/$@
