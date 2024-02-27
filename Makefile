CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic

all: $(SRC)
	$(CC) $(CFLAGS) $^

.PHONY: all
