CC = gcc
SRCS = *.c
HEADERS = ../headers
CFLAGS = -Wall -Wextra -Werror -I$(HEADERS)
OBJSDIR = ../objects
OBJS = $(SRCS:.c=.o)

all: $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $(OBJSDIR)/$@

clean:
	rm -f $(OBJS)

re: clean all
