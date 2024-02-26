CC = gcc
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

EXEC = main

CFLAGS = -Wall -Wextra -Werror -pedantic

all: $(EXEC)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)


clean:
	rm -f $(OBJ)

.PHONY: all clean
