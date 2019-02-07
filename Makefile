CC 	= gcc

NAME 	= libmy_malloc_$(shell uname).so

LNAME	= libmy_malloc.so

RM 	= rm -f

CFLAGS 	= -W -Wall -Werror

SRCS 	= $(wildcard *.c)

OBJS 	= $(SRCS:.c=.o)

all: 		malloc

%.o: 		%.c
		@echo "Compiling module" $@
		$(CC) -c $<

malloc:		$(OBJS)
		@echo "Linking objects into" $@
		$(CC) -o $@ $(CFLAGS) $(OBJS)

clean:
		$(RM) $(OBJS)

mrproper:	clean
		$(RM) malloc

rebuild:	mrproper all

.PHONY:		clean mrproper rebuild
