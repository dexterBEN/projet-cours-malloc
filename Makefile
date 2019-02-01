CC=gcc

RM=rm -f

CFLAGS = -W -Wall -Wextra -Werror

SRCS = $(wildcard *.c)

OBJS = $(SRCS:.c=.o)

all: malloc

%.o: %.c
	@echo "Compiling module" $@
	$(CC) -c $<

malloc: $(OBJS)
	@echo "Linking objects into" $@
	$(CC) -o $@ $(CFLAGS) $(OBJS)

clean:
	$(RM) $(OBJS)

mrproper: clean
	$(RM) malloc

rebuild: mrproper all

.PHONY: clean mrproper rebuild
