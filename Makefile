CC = gcc
SRC = $(wildcard *.c)
CFLAGS = -Wall -Wextra -Werror -pedantic

all: $(SRC)
	$(CC) $(CFLAGS) $^

.PHONY: all
