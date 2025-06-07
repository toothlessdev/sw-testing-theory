CC = gcc
CFLAGS = -Ilib -Wall -std=c11

# program 1

transition_test_p1: tests/program1/test-transition.c program1/model.c
	$(CC) $(CFLAGS) tests/program1/test-transition.c program1/model.c -o ./tests/program1/test-transition

run_transition_test_p1: transition_test_p1
	./tests/program1/test-transition

boundary_test_p1: tests/program1/test-boundary.c program1/model.c
	$(CC) $(CFLAGS) tests/program1/test-boundary.c program1/model.c -o ./tests/program1/test-boundary

run_boundary_test_p1: boundary_test_p1
	./tests/program1/test-boundary


clean:
	rm -f tests/program1/test
	rm -f tests/program2/test
