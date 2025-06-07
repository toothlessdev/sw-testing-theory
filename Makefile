CC = gcc
CFLAGS = -Ilib -Wall -std=c11

all: test_p1 test_p2

test_p1: tests/program1/test.c program1/model.c
	$(CC) $(CFLAGS) tests/program1/test.c program1/model.c -o ./tests/program1/test

test_p2: tests/program2/test.c program2/model.c
	$(CC) $(CFLAGS) tests/program2/test.c program2/model.c -o ./tests/program2/test

clean:
	rm -f tests/program1/test
	rm -f tests/program2/test
